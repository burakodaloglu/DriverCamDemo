//
//  DefaultSettingsRepository.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

class DefaultSettingsRepository: SettingsRepository {
    private let sdkWrapper: LibDV16SDKWrapper

    init(sdkWrapper: LibDV16SDKWrapper) {
        self.sdkWrapper = sdkWrapper
    }

    func getAllSettings() async throws -> [CameraSetting] {
        let rawData = try await sdkWrapper.getAllSettings()
        return parseSettingsFrom(rawData: rawData)
    }

    func getCurrentSettingValues() async throws -> [String : Int] {
        let statusDict = try await sdkWrapper.getCurrentStatus()
        return statusDict.compactMapValues { $0 as? Int }
    }

    // --- DEĞİŞTİ ---
    func updateSetting(settingId: String, newOptionIndex: Int) async throws {
        // Artık `sendCommand` yerine `updateSetting` fonksiyonunu çağırıyoruz.
       await sdkWrapper.updateSetting(topic: settingId, value: newOptionIndex)
    }

    // --- DEĞİŞTİ ---
    func syncTime() async throws {
        await  sdkWrapper.synchronizeTime()
    }
    
    // --- DEĞİŞTİ ---
    func formatSDCard() async throws {
        await sdkWrapper.formatSDCard()
    }
    
    // --- DEĞİŞTİ ---
    func resetWifi() async throws {
        await sdkWrapper.resetWiFi()
    }
    
    // --- DEĞİŞTİ ---
    func factoryReset() async throws {
        await sdkWrapper.factoryReset()
    }
    
    // --- DEĞİŞTİ ---
    func setWifiCredentials(ssid: String, password: String) async throws {
        await sdkWrapper.setWifiCredentials(ssid: ssid, password: password)
    }

    func getSDCardCapacity() async throws -> (total: Int, free: Int) {
        return (0, 0)
    }

    private func parseSettingsFrom(rawData: [Any]) -> [CameraSetting] {
        print("Parsing raw settings data...")
        return []
    }
}
