//
//  NovatekSDKWrapper.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation
import Combine
import CoreLocation
// import LDWiFiDeviceSDK

@MainActor
class NovatekSDKWrapper {
    static let shared = NovatekSDKWrapper()

    let connectionStateSubject = CurrentValueSubject<ConnectionState, Never>(.disconnected)
    let sdCardStatusSubject = CurrentValueSubject<SdCardStatus, Never>(.notInserted)
    let isRecordingSubject = CurrentValueSubject<Bool, Never>(false)

    private init() {
        // --- SDK SETUP ---
        // NTKSocketManager.shareSocketManger().delegate = self
    }

    func connectToDevice() {
        connectionStateSubject.send(.connecting)
        // --- SDK CALL ---
        //ConnectClass.shareConnect().ld_connectDevice { type, deviceInfo in ... }
        DispatchQueue.main.asyncAfter(deadline: .now() + 1) { self.connectionStateSubject.send(.connected) }
    }

    func sendCommand(cmdId: String, parNum: Int = -1, str: String? = nil) async throws {
        print("SDK WRAPPER -> CMD: \(cmdId), PAR: \(parNum), STR: \(str ?? "nil")")
        // --- SDK CALL (GENERIC) ---
        // return try await withCheckedThrowingContinuation { continuation in
        //     NTKViewModel.shareNtkInstance().ntk_sendCMD(withCMDId: cmdId, andParNum: parNum, andStr: str) { response in
        //          if let status = response?["Status"] as? String, status == "0" {
        //              continuation.resume()
        //          } else {
        //              continuation.resume(throwing: SDKError.commandFailed(response))
        //          }
        //     } orFail: { error in
        //          continuation.resume(throwing: error ?? SDKError.unknown)
        //     }
        // }
        try await Task.sleep(nanoseconds: 300_000_000) // 0.3 saniye bekle
    }

    func getStreamURL() async -> URL? {
        // --- SDK CALL ---
        // NTKViewModel.shareNtkInstance().ntk_getStreamLink { response in ... }
        return URL(string: "rtsp://192.168.1.254/xxx.mov")
    }

    func getFileList() async throws -> [CameraFile] {
        // --- SDK CALL ---
        //NTKViewModel.shareNtkInstance().ntk_getTFCardFile { respose in ... }
        try await Task.sleep(nanoseconds: 1_000_000_000)
        return [ /* ... Simülasyon verisi ... */ ]
    }

    func uploadFirmware(from localUrl: URL, progress: @escaping (Double) -> Void) async throws {
        // --- SDK CALL ---
        // NTKViewModel.shareNtkInstance().ntk_uploadFirmwareToDevice(...)
        // progress closure'ını periyodik olarak güncelle.
    }

    func confirmUpdate() async throws {
         // --- SDK CALL ---
        // NTKViewModel.shareNtkInstance().ntk_confirmUpgradeFirmware(...)
    }

    func parseGPSData(from localVideoUrl: URL) async -> [CLLocationCoordinate2D] {
        // --- SDK CALL ---
        // return await withCheckedContinuation { continuation in
        //     LDGpsParserManager.default().ld_parsingGpsInfoOfLocalVideo(withFilePath: localVideoUrl.path) { responseArr in
        //         // responseArr'ı [CLLocationCoordinate2D]'ye çevir
        //         continuation.resume(returning: coordinates)
        //     } parsingFailureCallback: {
        //         continuation.resume(returning: [])
        //     }
        // }
        return []
    }
    
    func getAllSettings() async throws -> [Any] {
        print("SDK WRAPPER: Tüm ayar listesi çekiliyor...")
        // --- SDK CALL ---
        // return try await withCheckedThrowingContinuation { continuation in
        //     NTKViewModel.shareNtkInstance().ntk_getAllItemList { response in ... }
        // }
        // Simülasyon verisi
        let simulatedData: [String: Any] = [
            "Item": [
                ["Cmd": "2002", "Name": "VIDEO_RESOLUTION", "MenuList": ["Option": [["Id": "1080P", "Index": 0], ["Id": "2K", "Index": 1]]]],
                ["Cmd": "2007", "Name": "MOVIE_AUDIO", "MenuList": ["Option": [["Id": "OFF", "Index": 0], ["Id": "ON", "Index": 1]]]]
            ]
        ]
        return [simulatedData]
    }

    func getCurrentStatus() async throws -> [String: Any] {
        print("SDK WRAPPER: Mevcut durumlar çekiliyor...")
        // --- SDK CALL ---
        // return try await withCheckedThrowingContinuation { continuation in
        //     NTKViewModel.shareNtkInstance().ntk_getAllCurStatus { response in ... }
        // }
        return ["2002": 1, "2007": 1] // Simülasyon
    }

    func synchronizeTime() async throws {
        print("SDK WRAPPER: Zaman senkronize ediliyor...")
        // --- SDK CALL ---
        //NTKViewModel.shareNtkInstance().ntk_synchronizationTime { ... }
    }

    func formatSDCard() async throws {
        print("SDK WRAPPER: SD Kart formatlanıyor...")
        // --- SDK CALL ---
        //NTKViewModel.shareNtkInstance().ntk_formatTF { ... }
    }

    func factoryReset() async throws {
        print("SDK WRAPPER: Fabrika ayarlarına dönülüyor...")
        // --- SDK CALL ---
        // NTKViewModel.shareNtkInstance().ntk_factory { ... }
    }

    func resetWiFi() async throws {
        print("SDK WRAPPER: WiFi sıfırlanıyor...")
        // --- SDK CALL ---
        // NTKViewModel.shareNtkInstance().ntk_resetWiFiData { ... }
    }

    func getWiFiInfo() async throws -> (ssid: String, password: String) {
        print("SDK WRAPPER: WiFi bilgileri alınıyor...")
        // --- SDK CALL ---
        // NTKViewModel.shareNtkInstance().ntk_getWiFiData { ... }
        return ("SIMULATED_WIFI", "12345678")
    }
    
}

// extension NovatekSDKWrapper: NTKSocketManagerDelegate {
//     func ntk_socketManagerRespose(withData dataDict: [AnyHashable : Any]!) {
//         // Gelen socket verisini parse edip ilgili Publisher'ları güncelle
//         // if dataDict["DeviceStatus"] == "record on" { isRecordingSubject.send(true) }
//     }
// }
