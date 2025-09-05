//
//  FirmwareRepository.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

protocol FirmwareRepository {
    func getCurrentFirmwareVersion() async throws -> String
    func checkServerForUpdate(currentVersion: String, deviceInfo: CameraInfo) async throws -> FirmwareInfo?
    func uploadFirmware(from localUrl: URL, progress: @escaping (Double) -> Void) async throws
    func confirmUpdate() async throws
}
