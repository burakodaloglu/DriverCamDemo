//
//  CameraControlRepository.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation
import Combine

enum CameraMode {
    case photo, video, playback
}

protocol CameraControlRepository {
    var connectionState: AnyPublisher<ConnectionState, Never> { get }
    var sdCardStatus: AnyPublisher<SdCardStatus, Never> { get }
    var isRecording: AnyPublisher<Bool, Never> { get }

    func connect() async
    func getCameraInfo() async -> CameraInfo?
    func startRecording() async throws
    func stopRecording() async throws
    func takeSnapshot() async throws

    // YENİ EKLENDİ
    func switchToMode(_ mode: CameraMode) async throws
    func getStreamURL() async throws -> URL?
    func disconnect() async
}
