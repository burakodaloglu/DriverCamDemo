//
//  SettingsViewModel.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

@MainActor
class SettingsViewModel: ObservableObject {
    @Published var settings: [CameraSetting] = []
    @Published var isLoading = false
    @Published var errorMessage: String?

    private let manageSettingsUseCase: ManageSettingsUseCase
    private let settingsRepository: SettingsRepository

    init(manageSettingsUseCase: ManageSettingsUseCase, settingsRepository: SettingsRepository) {
        self.manageSettingsUseCase = manageSettingsUseCase
        self.settingsRepository = settingsRepository
    }

    func loadSettings() async {
        isLoading = true
        errorMessage = nil
        do {
            settings = try await manageSettingsUseCase.getAllSettingsWithCurrentValues()
        } catch {
            errorMessage = "Ayarlar yüklenemedi: \(error.localizedDescription)"
        }
        isLoading = false
    }

    func updateSetting(settingId: String, newIndex: Int) async {
        do {
            try await manageSettingsUseCase.updateSetting(settingId: settingId, newOptionIndex: newIndex)
            await loadSettings() 
        } catch {
            errorMessage = "Ayar güncellenemedi."
        }
    }

    func syncTime() async {
        do {
            try await settingsRepository.syncTime()
        } catch {
            errorMessage = "Saat senkronize edilemedi."
        }
    }

    func formatSDCard() async {
        do {
            try await settingsRepository.formatSDCard()
        } catch {
            errorMessage = "SD kart formatlanamadı."
        }
    }
}
