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
    
    func connectButtonTapped() {
        Task {
            await connectUseCase.execute()
        }
    }
    
    func recordButtonTapped(){
        Task {
            try await toggleRecordingUseCase.execute(isRecording: self.isRecording)
        }
    }
}
