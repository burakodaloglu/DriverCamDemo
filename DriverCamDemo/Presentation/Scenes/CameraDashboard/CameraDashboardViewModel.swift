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

    private let cameraControlRepo: CameraControlRepository
    private var cancellables = Set<AnyCancellable>()
    
    init(connectUseCase: ConnectCameraUseCase, toggleRecordingUseCase: ToggleRecordingUseCase, cameraControlRepo: CameraControlRepository) {
        self.cameraControlRepo = cameraControlRepo
        subscribeToPublishers()
    }
    
    private func subscribeToPublishers() {
        // Bağlantı durumunu dinle
        cameraControlRepo.connectionState
            .sink { [weak self] state in
                self?.connectionStatus = state
                
                switch state {
                case .connected:
                    // Bağlantı başarılıysa, kameraya "yayını aç" komutu gönder.
                    self?.requestLiveStream()
                case .disconnected, .failed:
                    // Bağlantı koptuysa, video URL'ini temizle.
                    self?.streamUrl = nil
                default:
                    break
                }
            }
            .store(in: &cancellables)
        
        // --- YENİ EKLENDİ ---
        // Kameradan "yayın hazır" sinyali geldiğinde dinle.
        cameraControlRepo.streamReadyPublisher
            .sink { [weak self] in
                // Sinyal geldiğinde, video URL'ini alarak oynatıcıyı başlat.
                self?.startPlayer()
            }
            .store(in: &cancellables)
        
        cameraControlRepo.isRecording
            .assign(to: &$isRecording)
    }
    
    private func requestLiveStream() {
        Task {
            await cameraControlRepo.openLiveStream()
        }
    }
    
    private func startPlayer() {
        Task {
            self.streamUrl = try? await cameraControlRepo.getStreamURL()
        }
    }
    
    func wifiButtonTapped() {
        Task {
            switch connectionStatus {
            case .disconnected, .failed:
                await cameraControlRepo.connect()
            case .connected:
                await cameraControlRepo.disconnect()
            case .connecting:
                break
            }
        }
    }
    
    func recordButtonTapped(){
        Task {
            if isRecording {
                try await cameraControlRepo.stopRecording()
            } else {
                try await cameraControlRepo.startRecording()
            }
        }
    }
}
