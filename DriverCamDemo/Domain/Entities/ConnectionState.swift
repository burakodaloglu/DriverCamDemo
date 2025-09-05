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