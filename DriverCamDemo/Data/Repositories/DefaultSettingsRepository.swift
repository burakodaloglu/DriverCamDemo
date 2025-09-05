//
//  DefaultSettingsRepository.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

class DefaultSettingsRepository: SettingsRepository {
    private let sdkWrapper: NovatekSDKWrapper

    init(sdkWrapper: NovatekSDKWrapper) {
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

    func updateSetting(settingId: String, newOptionIndex: Int) async throws {
        try await sdkWrapper.sendCommand(cmdId: settingId, parNum: newOptionIndex)
    }

    func syncTime() async throws { try await sdkWrapper.synchronizeTime() }
    func formatSDCard() async throws { try await sdkWrapper.formatSDCard() }
    func resetWifi() async throws { try await sdkWrapper.resetWiFi() }
    func factoryReset() async throws { try await sdkWrapper.factoryReset() }

    func setWifiCredentials(ssid: String, password: String) async throws {
        try await sdkWrapper.sendCommand(cmdId: "3003", str: ssid)
        try await sdkWrapper.sendCommand(cmdId: "3004", str: password)
        try await sdkWrapper.resetWiFi()
    }

    func getSDCardCapacity() async throws -> (total: Int, free: Int) {
        return (0, 0)
    }

    private func parseSettingsFrom(rawData: [Any]) -> [CameraSetting] {
        print("Parsing raw settings data...")
        return []
    }
}
