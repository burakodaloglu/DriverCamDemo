//
//  DefaultCameraControlRepository.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation
import Combine

class DefaultCameraControlRepository: CameraControlRepository {
    private let sdkWrapper: NovatekSDKWrapper

    init(sdkWrapper: NovatekSDKWrapper) {
        self.sdkWrapper = sdkWrapper
    }

    var connectionState: AnyPublisher<ConnectionState, Never> { sdkWrapper.connectionStateSubject.eraseToAnyPublisher() }
    var sdCardStatus: AnyPublisher<SdCardStatus, Never> { sdkWrapper.sdCardStatusSubject.eraseToAnyPublisher() }
    var isRecording: AnyPublisher<Bool, Never> { sdkWrapper.isRecordingSubject.eraseToAnyPublisher() }

    func connect() async {
        await sdkWrapper.connectToDevice()
    }

    func getCameraInfo() async -> CameraInfo? {
        // --- SDK CALL ---
        return CameraInfo(macAddress: "AA:BB:CC:DD:EE", deviceId: "12345", serialNumber: "SN98765", firmwareVersion: "1.0.1")
    }

    func startRecording() async throws {
        try await sdkWrapper.sendCommand(cmdId: "2001", parNum: 1)
    }

    func stopRecording() async throws {
        try await sdkWrapper.sendCommand(cmdId: "2001", parNum: 0)
    }

    func takeSnapshot() async throws {
        try await sdkWrapper.sendCommand(cmdId: "2017")
    }

    func switchToMode(_ mode: CameraMode) async throws {
        let parNum: Int
        switch mode {
        case .photo: parNum = 0
        case .video: parNum = 1
        case .playback: parNum = 2
        }
        try await sdkWrapper.sendCommand(cmdId: "3001", parNum: parNum)
    }

    func getStreamURL() async throws -> URL? {
        return await sdkWrapper.getStreamURL()
    }
}
