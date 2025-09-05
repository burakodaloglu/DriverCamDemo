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
    }
    
    // MARK: - Notification Handlers
    @objc private func didConnect(notification: NSNotification) {
        print("SDK BAĞLANDI (Bildirim yoluyla)")
        connectionStateSubject.send(.connected)
        
        sdk?.appAccessInfoRequest()
    }
    
    @objc private func didDisconnect(notification: NSNotification) {
        print("SDK BAĞLANTISI KESİLDİ (Bildirim yoluyla)")
        connectionStateSubject.send(.disconnected)
    }

    // MARK: - SDK Functions
    func connectToDevice() {
        connectionStateSubject.send(.connecting)
        let deviceIP = "192.168.1.1" // Varsayılan IP
        let port: Int = 3333       // Varsayılan Port (Int32 olmalı)
        
        sdk?.didConnect(toAddress: deviceIP, withPort: port)
    }

    func sendCommand(cmdId: String, parNum: Int = -1, str: String? = nil) async throws {
        // Not: Bu SDK'nın sendCmd metodu bir callback içermiyor, bu yüzden async/await yapısı
        // burada tam olarak gerekli olmayabilir, ama projenin yapısını korumak için kullanıyoruz.
        // PDF'te belirtilen `dv...` ile başlayan fonksiyonları doğrudan çağıracağız.
        
        // Örnek: Kayıt başlatma/durdurma
        if cmdId == "2001" { // Bu komut ID'si senin projenin varsayımı, SDK'da farklı olabilir
            sdk?.dvVideoControl(withStatus: Int32(parNum))
        }
        
        // Diğer komutlar için de benzer şekilde özel fonksiyonlar çağrılabilir.
        // [[JLCtpSender sharedInstanced] dvPhotoControl];
    }
    
    func getStreamURL() async -> URL? {
        // Örnek projedeki `JLMediaPlayerView.m` dosyasına göre RTSP URL'i kullanılıyor.
        let streamPath = "rtsp://192.168.1.1/MJPEG_STREAM"
        return URL(string: streamPath)
    }

    // Repository'lerin ihtiyaç duyduğu diğer fonksiyonlar (Boş olarak eklendi)
    func getFileList() async throws -> [CameraFile] { return [] }
    func getAllSettings() async throws -> [Any] { return [] }
    func getCurrentStatus() async throws -> [String: Any] { return [:] }
    func synchronizeTime() async throws { }
    func formatSDCard() async throws { sdk?.dvFormateWithStatus() }
    func parseGPSData(from localVideoUrl: URL) async -> [CLLocationCoordinate2D] { return [] }
    func uploadFirmware(from localUrl: URL, progress: @escaping (Double) -> Void) async throws { }
    func confirmUpdate() async throws { }
    func resetWiFi() async throws { sdk?.dvCloseDeviceWiFi() }
    func factoryReset() async throws { sdk?.dvMakeDeviceReset() }
}
