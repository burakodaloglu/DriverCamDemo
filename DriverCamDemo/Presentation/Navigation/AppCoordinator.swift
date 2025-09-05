//
//  AppCoordinator.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import SwiftUI
import Swinject

class AppCoordinator: ObservableObject {
    @Published var path = NavigationPath()
    
    enum Page: String, Hashable {
        case fileList
        case settings
    }
    
    func goTo(_ page: Page) {
        path.append(page)
    }
    
    @ViewBuilder
    func build(page: Page) -> some View {
        switch page {
        case .fileList:
            resolve(FileListView.self)
        case .settings:
            resolve(SettingsView.self)
        }
    }
    
    private func resolve<T>(_ type: T.Type) -> T {
        return Assembler.shared.resolver.resolve(T.self)!
    }
}
