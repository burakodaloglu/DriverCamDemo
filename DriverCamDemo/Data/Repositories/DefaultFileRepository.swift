//
//  DefaultFileRepository.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation
import CoreLocation

class DefaultFileRepository: FileRepository {
    private let sdkWrapper: NovatekSDKWrapper

    init(sdkWrapper: NovatekSDKWrapper) {
        self.sdkWrapper = sdkWrapper
    }

    func getFileList() async throws -> [CameraFile] {
        return try await sdkWrapper.getFileList()
    }

    func downloadFile(file: CameraFile, progress: @escaping (Double) -> Void) async throws -> URL {
        throw URLError(.cancelled)
    }

    func deleteFile(file: CameraFile) async throws {
        //try await sdkWrapper.sendCommand(cmdId: "4003", str: file.remotePath)
    }

    func parseGPSData(from localVideoUrl: URL) async -> [CLLocationCoordinate2D] {
        return await sdkWrapper.parseGPSData(from: localVideoUrl)
    }
}
