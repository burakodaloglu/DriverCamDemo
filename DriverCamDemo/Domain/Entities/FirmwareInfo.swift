//
//  FirmwareInfo.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

struct FirmwareInfo :Decodable{
    let hasUpdate: Bool
    let newVersion: String
    let downloadUrl: URL
    let releaseNotes: String
}
