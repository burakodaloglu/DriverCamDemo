//
//  CameraSetting.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

enum SettingCategory {
    case video, system, advanced, network
}

struct CameraSetting: Identifiable, Hashable {
    let id: String
    let name: String
    let category: SettingCategory
    let options: [SettingOption]
    var currentOptionIndex: Int?
    let description: String?
}

struct SettingOption: Identifiable, Hashable {
    var id: Int { index }
    let name: String
    let index: Int 
}
