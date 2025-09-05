//
//  FileListView.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import SwiftUI
import SDWebImageSwiftUI

struct FileListView: View {
    @StateObject private var viewModel: FileListViewModel
    
    init(viewModel: FileListViewModel) {
        _viewModel = StateObject(wrappedValue: viewModel)
    }
    
    var body: some View {
        Group {
            if viewModel.isLoading {
                ProgressView()
            } else {
                List(viewModel.files) { file in
                    FileRowView(file: file)
                }
            }
        }
        .navigationTitle("Kayıtlı Dosyalar")
        .task {
            await viewModel.loadFiles()
        }
    }
}

struct FileRowView: View {
    let file: CameraFile
    
    var body: some View {
        HStack {
            WebImage(url: file.thumbnailUrl)
                .resizable()
                .scaledToFit()
                .frame(width: 80, height: 60)
                .cornerRadius(8)
            
            VStack(alignment: .leading) {
                Text(file.name).font(.headline).lineLimit(1)
                Text("\(file.creationDate, style: .date)")
            }
        }
    }
}
