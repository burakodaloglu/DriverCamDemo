//
//  LibDV16SDKWrapper.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 5.09.2025.
//

import Foundation
import Combine
import CoreLocation

@MainActor
class LibDV16SDKWrapper: NSObject {
    static let shared = LibDV16SDKWrapper()

    let streamReadyPublisher = PassthroughSubject<Void, Never>()
    let connectionStateSubject = CurrentValueSubject<ConnectionState, Never>(.disconnected)
    let isRecordingSubject = CurrentValueSubject<Bool, Never>(false)
    let sdCardStatusSubject = CurrentValueSubject<SdCardStatus, Never>(.notInserted)

    private let sdk = JLCtpSender.sharedInstanced()

    private override init() {
        super.init()
        setupSDK()
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }

    private func setupSDK() {
        NotificationCenter.default.addObserver(self, selector: #selector(didConnect), name: NSNotification.Name(DV_TCP_CONNECTED), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(didDisconnect), name: NSNotification.Name(DV_TCP_DISCONNECTED), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(recordingStatusChanged(_:)), name: NSNotification.Name(DV_VIDEO_CTRL), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(streamDidOpen), name: NSNotification.Name(DV_OPEN_RT_STREAM), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(receivedKeepAliveInterval(_:)), name: NSNotification.Name(DV_KEEP_INTERVAL), object: nil)

    }
    
    // MARK: - Notification Handlers
    @objc private func didConnect(notification: NSNotification) {
        connectionStateSubject.send(.connected)
        sdk?.appAccessInfoRequest()
    }
    
    @objc private func didDisconnect(notification: NSNotification) {
        connectionStateSubject.send(.disconnected)
    }
    
    @objc private func recordingStatusChanged(_ notification: NSNotification) {
        guard let info = notification.object as? [String: Any],
              let param = info["param"] as? [String: Any],
              let statusString = param["status"] as? String,
              let status = Int(statusString) else { return }
        let isCurrentlyRecording = (status == 1)
        self.isRecordingSubject.send(isCurrentlyRecording)
    }
    
    @objc private func receivedKeepAliveInterval(_ notification: NSNotification) {
        guard let info = notification.object as? [String: Any],
              let param = info["param"] as? [String: Any],
              let timeout = param["timeout"] as? TimeInterval else {
            return
        }
        
        // PDF Sayfa 72: Kameranın istediği timeout değerini kullanarak SDK'nın heartbeat mekanizmasını ayarla.
        // Timeout / 1000 (milisaniyeden saniyeye çevir) / 5 -> Önerilen gönderme sıklığı
        let sendInterval = (timeout / 1000) / 5.0
        print("SDK BİLDİRİMİ: Heartbeat ayarlanıyor. Timeout: \(timeout/1000)s, Gönderme Sıklığı: \(sendInterval)s")
        sdk?.dvReSetHeartSend(sendInterval, withTimeOut: timeout / 1000, timeOutFrequency: 3, withType: true)
    }

    // MARK: - SDK Functions
    func connectToDevice() async {
        let deviceIP = "192.168.1.1"
        let port: Int = 3333
        sdk?.didConnect(toAddress: deviceIP, withPort: port)
    }
    
    func disconnectFromDevice() async {
        sdk?.desConnectedCTP()
    }

    @objc private func streamDidOpen() {
        print("SDK BİLDİRİMİ: Canlı yayın şimdi hazır!")
        streamReadyPublisher.send()
    }
    
    func openLiveStream() async {
        print("SDK -> Canlı yayın başlatma komutu gönderiliyor...")
        sdk?.dvRealTimeStreamFrontWebcamOpen(0, width: 640, height: 480, fps: 30, rate: 8000)
    }
    
    func getStreamURL() -> URL? {
         let streamPath = "rtsp://192.168.1.1/MJPEG_STREAM"
         return URL(string: streamPath)
     }
    
    func startRecording() { sdk?.dvVideoControl(withStatus: 1) }
    func stopRecording() { sdk?.dvVideoControl(withStatus: 0) }
    
    func updateSetting(topic: String, value: Int) {
        let paramDict = ["key_0": "\(value)"]
        let commandDict: [AnyHashable: Any] = ["op": "PUT", "param": paramDict]
        sdk?.dvGenericCommand(with: commandDict, topic: topic)
    }

    func setWifiCredentials(ssid: String, password: String) {
        sdk?.dvSetSTAssidInfo(with: ssid, password: password, onStatus: 1)
    }
    
    func synchronizeTime() {
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = "yyyy-MM-dd-HH-mm-ss"
        let nowString = dateFormatter.string(from: Date())
        sdk?.dvDateTimeSet(nowString)
    }

    func formatSDCard() {
        sdk?.dvFormateWithStatus()
    }
    
    func resetWiFi() {
        sdk?.dvCloseDeviceWiFi()
    }

    func factoryReset() {
        sdk?.dvMakeDeviceReset()
    }

    // Gerekli diğer boş fonksiyonlar
    func getFileList() async throws -> [CameraFile] { return [] }
    func getAllSettings() async throws -> [Any] { return [] }
    func getCurrentStatus() async throws -> [String: Any] { return [:] }
    func parseGPSData(from localVideoUrl: URL) async -> [CLLocationCoordinate2D] { return [] }
    func uploadFirmware(from localUrl: URL, progress: @escaping (Double) -> Void) async throws { }
    func confirmUpdate() async throws { }
}
