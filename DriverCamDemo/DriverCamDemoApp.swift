//
//  DriverCamDemoApp.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import SwiftUI
import Swinject

@main
struct DriverCamDemoApp: App {
    
    private func resolve<T>(_ type: T.Type) -> T {
        return Assembler.shared.resolver.resolve(T.self)!
    }
    
    var body: some Scene {
        WindowGroup {
            resolve(CameraDashboardView.self)
        }
    }
}
