//
//  ConnectionState.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

enum ConnectionState: Equatable {
    case disconnected
    case connecting
    case connected
    case failed(String)
}

extension ConnectionState {
    var description: String {
        switch self {
        case .disconnected:
            return "Bağlı Değil"
        case .connecting:
            return "Bağlanılıyor..."
        case .connected:
            return "Bağlandı"
        case .failed(let error):
            return "Hata: \(error)"
        }
    }
}


enum RecordingState {
    case stopped
    case recording
}

enum SdCardStatus {
    case notInserted
    case inserted
    case locked
    case error(String)
}
