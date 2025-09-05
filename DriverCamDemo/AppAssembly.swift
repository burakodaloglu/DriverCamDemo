//
//  AppAssembly.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation
import Swinject

class AppAssembly: Assembly {
    func assemble(container: Container) {
        
        // MARK: - Data Layer
        container.register(LibDV16SDKWrapper.self) { _ in LibDV16SDKWrapper.shared }.inObjectScope(.container)
        
        container.register(NetworkService.self) { _ in DefaultNetworkService() }
        
        container.register(CameraControlRepository.self) { r in
            DefaultCameraControlRepository(sdkWrapper: r.resolve(LibDV16SDKWrapper.self)!)
        }
        container.register(FileRepository.self) { r in
            DefaultFileRepository(sdkWrapper: r.resolve(LibDV16SDKWrapper.self)!)
        }
        container.register(SettingsRepository.self) { r in
            DefaultSettingsRepository(sdkWrapper: r.resolve(LibDV16SDKWrapper.self)!)
        }
        container.register(FirmwareRepository.self) { r in
            DefaultFirmwareRepository(
                sdkWrapper: r.resolve(LibDV16SDKWrapper.self)!,
                networkService: r.resolve(NetworkService.self)!
            )
        }
        
        // MARK: - Domain Layer (UseCases)
        container.register(ConnectCameraUseCase.self) { r in
            ConnectCameraUseCase(repository: r.resolve(CameraControlRepository.self)!)
        }
        container.register(ToggleRecordingUseCase.self) { r in
            ToggleRecordingUseCase(repository: r.resolve(CameraControlRepository.self)!)
        }
        container.register(ManageSettingsUseCase.self) { r in
            ManageSettingsUseCase(repository: r.resolve(SettingsRepository.self)!)
        }
        
        // MARK: - Presentation Layer (ViewModels)
        container.register(CameraDashboardViewModel.self) { @MainActor r in
            CameraDashboardViewModel(
                connectUseCase: r.resolve(ConnectCameraUseCase.self)!,
                toggleRecordingUseCase: r.resolve(ToggleRecordingUseCase.self)!,
                cameraControlRepo: r.resolve(CameraControlRepository.self)!
            )
        }
        container.register(FileListViewModel.self) { @MainActor r in
            FileListViewModel(fileRepository: r.resolve(FileRepository.self)!)
        }
        container.register(SettingsViewModel.self) { @MainActor r in
            SettingsViewModel(
                manageSettingsUseCase: r.resolve(ManageSettingsUseCase.self)!,
                settingsRepository: r.resolve(SettingsRepository.self)!
            )
        }

        // MARK: - Presentation Layer (Views)
        container.register(CameraDashboardView.self) { r in
            CameraDashboardView(viewModel: r.resolve(CameraDashboardViewModel.self)!)
        }
        container.register(FileListView.self) { r in
            FileListView(viewModel: r.resolve(FileListViewModel.self)!)
        }
        container.register(SettingsView.self) { r in
            SettingsView(viewModel: r.resolve(SettingsViewModel.self)!)
        }
    }
}
