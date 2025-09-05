//
//  DefaultCameraControlRepository.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation
import Combine

class DefaultCameraControlRepository: CameraControlRepository {
    private let sdkWrapper: LibDV16SDKWrapper

    init(sdkWrapper: LibDV16SDKWrapper) {
        self.sdkWrapper = sdkWrapper
    }

    var connectionState: AnyPublisher<ConnectionState, Never> { sdkWrapper.connectionStateSubject.eraseToAnyPublisher() }
    var sdCardStatus: AnyPublisher<SdCardStatus, Never> { sdkWrapper.sdCardStatusSubject.eraseToAnyPublisher() }
    var isRecording: AnyPublisher<Bool, Never> { sdkWrapper.isRecordingSubject.eraseToAnyPublisher() }

    func connect() async {
        await sdkWrapper.connectToDevice()
    }

    func getCameraInfo() async -> CameraInfo? {
        return CameraInfo(macAddress: "AA:BB:CC:DD:EE", deviceId: "12345", serialNumber: "SN98765", firmwareVersion: "1.0.1")
    }

    // --- DEĞİŞTİ ---
    // Artık genel sendCommand yerine doğrudan ilgili fonksiyonu çağırıyoruz.
    func startRecording() async throws {
        await sdkWrapper.startRecording()
    }

    // --- DEĞİŞTİ ---
    func stopRecording() async throws {
        await sdkWrapper.stopRecording()
    }

    func takeSnapshot() async throws {
        // Bu fonksiyonu şimdilik boş bırakabilir veya ilgili SDK komutunu ekleyebilirsiniz.
        // Örnek: sdkWrapper.sdk?.dvPhotoControl()
    }

    func switchToMode(_ mode: CameraMode) async throws {
        // Bu fonksiyonu şimdilik boş bırakabilir veya ilgili SDK komutunu ekleyebilirsiniz.
    }

    func getStreamURL() async throws -> URL? {
        return await sdkWrapper.getStreamURL()
    }
    func disconnect() async {
       await sdkWrapper.disconnectFromDevice()
    }
}
