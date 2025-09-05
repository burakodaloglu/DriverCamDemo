//
//  Assembler.swift
//  Assembler
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation
import Swinject

extension Assembler {
    static let shared: Assembler = {
        let container = Container()
        let assembler = Assembler([
            AppAssembly()
        ], container: container)
        return assembler
    }(              )
}
