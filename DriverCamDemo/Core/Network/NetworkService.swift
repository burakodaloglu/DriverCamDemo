//
//  NetworkService.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation
import Alamofire

protocol NetworkService {
    func checkForFirmwareUpdate(currentVersion: String) async throws -> FirmwareInfo
}

struct DefaultNetworkService: NetworkService {
    func checkForFirmwareUpdate(currentVersion: String) async throws -> FirmwareInfo {
        let url = "https://api.dumanarge.com/firmware/check"
        let parameters = ["version": currentVersion]
        
        return try await AF.request(url, method: .get, parameters: parameters)
            .validate()
            .serializingDecodable(FirmwareInfo.self)
            .value
    }
}
