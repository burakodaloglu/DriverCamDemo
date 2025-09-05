//
//  CameraDashboardViewModel.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation
import Combine

@MainActor
class CameraDashboardViewModel: ObservableObject {
    @Published var connectionStatus: ConnectionState = .disconnected
    @Published var isRecording: Bool = false
    @Published var streamUrl: URL? 

    private let connectUseCase: ConnectCameraUseCase
    private let toggleRecordingUseCase: ToggleRecordingUseCase
    private let cameraControlRepo: CameraControlRepository
    
    private var cancellables = Set<AnyCancellable>()
    
    init(connectUseCase: ConnectCameraUseCase, toggleRecordingUseCase: ToggleRecordingUseCase, cameraControlRepo: CameraControlRepository) {
        self.connectUseCase = connectUseCase
        self.toggleRecordingUseCase = toggleRecordingUseCase
        self.cameraControlRepo = cameraControlRepo
        subscribeToPublishers()
    }
    
    private func subscribeToPublishers() {
        cameraControlRepo.connectionState
            .assign(to: &$connectionStatus)
        
        cameraControlRepo.isRecording
            .assign(to: &$isRecording)
    }
    
    func onViewAppear() {
        Task {
            self.streamUrl = try? await cameraControlRepo.getStreamURL()
        }
    }
    
    func connectButtonTapped() {
        Task {
            await connectUseCase.execute()
        }
    }
    
    func wifiButtonTapped() {
            Task {
                switch connectionStatus {
                case .disconnected, .failed:
                    await connectUseCase.execute()
                case .connected:
                    await cameraControlRepo.disconnect()
                case .connecting:
                    break
                }
            }
        }
    
    func recordButtonTapped(){
        Task {
            try await toggleRecordingUseCase.execute(isRecording: self.isRecording)
        }
    }
}
