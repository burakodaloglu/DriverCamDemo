//
//  ToggleRecordingUseCase.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

class ToggleRecordingUseCase {
    private let repository: CameraControlRepository

    init(repository: CameraControlRepository) {
        self.repository = repository
    }

    func execute(isRecording: Bool) async throws {
        if isRecording {
            try await repository.stopRecording()
        } else {
            try await repository.startRecording()
        }
    }
}
