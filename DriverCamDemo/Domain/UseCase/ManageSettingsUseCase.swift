//
//  ManageSettingsUseCase.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

class ManageSettingsUseCase {
    private let repository: SettingsRepository

    init(repository: SettingsRepository) {
        self.repository = repository
    }

    func getAllSettingsWithCurrentValues() async throws -> [CameraSetting] {
        var settings = try await repository.getAllSettings()
        let currentValues = try await repository.getCurrentSettingValues()

        for i in 0..<settings.count {
            if let currentValue = currentValues[settings[i].id] {
                settings[i].currentOptionIndex = currentValue
            }
        }
        return settings
    }

    func updateSetting(settingId: String, newOptionIndex: Int) async throws {
        try await repository.updateSetting(settingId: settingId, newOptionIndex: newOptionIndex)
    }
}
