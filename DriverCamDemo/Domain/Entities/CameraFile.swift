//
//  FileType.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

enum FileType {
    case video, lockedVideo, photo
}

struct CameraFile: Identifiable, Hashable {
    let id = UUID()
    let name: String
    let sizeInBytes: Int
    let creationDate: Date
    let thumbnailUrl: URL?
    let remoteUrl: URL
    let type: FileType
}
