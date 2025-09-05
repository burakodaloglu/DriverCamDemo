//
//  ConnectCameraUseCase.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

class ConnectCameraUseCase {
    private let repository: CameraControlRepository

    init(repository: CameraControlRepository) {
        self.repository = repository
    }

    func execute() async {
        await repository.connect()
    }
}
