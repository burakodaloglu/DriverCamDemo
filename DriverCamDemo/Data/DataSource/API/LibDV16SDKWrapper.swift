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

    let connectionStateSubject = CurrentValueSubject<ConnectionState, Never>(.disconnected)
    let sdCardStatusSubject = CurrentValueSubject<SdCardStatus, Never>(.notInserted)
    let isRecordingSubject = CurrentValueSubject<Bool, Never>(false)

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
    }
    
    // MARK: - Notification Handlers
    @objc private func didConnect(notification: NSNotification) {
        print("SDK BAĞLANTI BİLDİRİMİ: Bağlandı!")
        connectionStateSubject.send(.connected)
        sdk?.appAccessInfoRequest()
    }
    
    @objc private func didDisconnect(notification: NSNotification) {
        print("SDK BAĞLANTI BİLDİRİMİ: Bağlantı kesildi.")
        connectionStateSubject.send(.disconnected)
    }
    
    @objc private func recordingStatusChanged(_ notification: NSNotification) {
        guard let info = notification.object as? [String: Any],
              let param = info["param"] as? [String: Any],
              let statusString = param["status"] as? String,
              let status = Int(statusString) else {
            return
        }
        let isCurrentlyRecording = (status == 1)
        print("SDK BİLDİRİMİ: Kayıt Durumu Değişti -> \(isCurrentlyRecording)")
        self.isRecordingSubject.send(isCurrentlyRecording)
    }

    // MARK: - SDK Functions
    func connectToDevice() {
        connectionStateSubject.send(.connecting)
        let deviceIP = "192.168.1.1"
        let port: Int = 3333
        sdk?.didConnect(toAddress: deviceIP, withPort: port)
    }

    func getStreamURL() async -> URL? {
        let streamPath = "rtsp://192.168.1.1/MJPEG_STREAM"
        return URL(string: streamPath)
    }
    
    func startRecording() {
        sdk?.dvVideoControl(withStatus: 1)
    }

    func stopRecording() {
        sdk?.dvVideoControl(withStatus: 0)
    }
    
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
    
    func disconnectFromDevice() {
        print("SDK -> Bağlantı Kesiliyor...")
        sdk?.desConnectedCTP()
    }

    func getFileList() async throws -> [CameraFile] { return [] }
    func getAllSettings() async throws -> [Any] { return [] }
    func getCurrentStatus() async throws -> [String: Any] { return [:] }
    func parseGPSData(from localVideoUrl: URL) async -> [CLLocationCoordinate2D] { return [] }
    func uploadFirmware(from localUrl: URL, progress: @escaping (Double) -> Void) async throws { }
    func confirmUpdate() async throws { }
}
