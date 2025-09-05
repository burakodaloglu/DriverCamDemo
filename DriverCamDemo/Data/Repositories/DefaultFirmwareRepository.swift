//
//  DefaultFirmwareRepository.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

class DefaultFirmwareRepository: FirmwareRepository {
    private let sdkWrapper: NovatekSDKWrapper
    private let networkService: NetworkService

    init(sdkWrapper: NovatekSDKWrapper, networkService: NetworkService) {
        self.sdkWrapper = sdkWrapper
        self.networkService = networkService
    }

    func getCurrentFirmwareVersion() async throws -> String {
        return "1.0.0"
    }

    func checkServerForUpdate(currentVersion: String, deviceInfo: CameraInfo) async throws -> FirmwareInfo? {
        return nil
    }

    func uploadFirmware(from localUrl: URL, progress: @escaping (Double) -> Void) async throws {
        try await sdkWrapper.uploadFirmware(from: localUrl, progress: progress)
    }

    func confirmUpdate() async throws {
        try await sdkWrapper.confirmUpdate()
    }
}
