//
//  FileRepository.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation
import CoreLocation

protocol FileRepository {
    func getFileList() async throws -> [CameraFile]
    func downloadFile(file: CameraFile, progress: @escaping (Double) -> Void) async throws -> URL
    func deleteFile(file: CameraFile) async throws

    func parseGPSData(from localVideoUrl: URL) async -> [CLLocationCoordinate2D]
}
