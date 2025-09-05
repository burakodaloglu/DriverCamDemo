//
//  SettingsView.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import SwiftUI

struct SettingsView: View {
    @StateObject private var viewModel: SettingsViewModel

    init(viewModel: SettingsViewModel) {
        _viewModel = StateObject(wrappedValue: viewModel)
    }

    var body: some View {
        List {
            if viewModel.isLoading {
                ProgressView()
            } else {
                ForEach(viewModel.settings) { setting in
                    Section(header: Text(setting.name)) {
                        SettingRowView(setting: setting) { newIndex in
                            Task {
                                await viewModel.updateSetting(settingId: setting.id, newIndex: newIndex)
                            }
                        }
                    }
                }

                Section(header: Text("Sistem İşlemleri")) {
                    Button("Saati Senkronize Et") {
                        Task { await viewModel.syncTime() }
                    }

                    Button("SD Kartı Formatla", role: .destructive) {
                        Task { await viewModel.formatSDCard() }
                    }
                }
            }
        }
        .navigationTitle("Cihaz Ayarları")
        .task { await viewModel.loadSettings() }
        .alert("Hata", isPresented: .constant(viewModel.errorMessage != nil), actions: {
            Button("Tamam", role: .cancel) { viewModel.errorMessage = nil }
        }, message: {
            Text(viewModel.errorMessage ?? "")
        })
    }
}

struct SettingRowView: View {
    let setting: CameraSetting
    let onSelectionChanged: (Int) -> Void

    @State private var selectedIndex: Int

    init(setting: CameraSetting, onSelectionChanged: @escaping (Int) -> Void) {
        self.setting = setting
        self.onSelectionChanged = onSelectionChanged
        self._selectedIndex = State(initialValue: setting.currentOptionIndex ?? 0)
    }

    var body: some View {
        Picker(setting.name, selection: $selectedIndex) {
            ForEach(setting.options) { option in
                Text(option.name).tag(option.index)
            }
        }
        .pickerStyle(.segmented)
        .onChange(of: selectedIndex) { newIndex in
            onSelectionChanged(newIndex)
        }
    }
}
