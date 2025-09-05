//
//  SettingsRepository.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

protocol SettingsRepository {
    func getAllSettings() async throws -> [CameraSetting]
    func getCurrentSettingValues() async throws -> [String: Int]
    func updateSetting(settingId: String, newOptionIndex: Int) async throws
    func syncTime() async throws
    func formatSDCard() async throws
    func setWifiCredentials(ssid: String, password: String) async throws
    func resetWifi() async throws
    func factoryReset() async throws
    func getSDCardCapacity() async throws -> (total: Int, free: Int)
}
