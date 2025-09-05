//
//  FileListViewModel.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import Foundation

@MainActor
class FileListViewModel: ObservableObject {
    @Published var files: [CameraFile] = []
    @Published var isLoading = false
    @Published var errorMessage: String?
    
    private let fileRepository: FileRepository
    
    init(fileRepository: FileRepository) {
        self.fileRepository = fileRepository
    }
    
    func loadFiles() async {
        isLoading = true
        errorMessage = nil
        do {
            self.files = try await fileRepository.getFileList()
        } catch {
            self.errorMessage = "Dosyalar yüklenemedi."
        }
        isLoading = false
    }
}
