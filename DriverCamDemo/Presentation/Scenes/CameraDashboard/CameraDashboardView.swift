//
//  CameraDashboardView.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 20.08.2025.
//

import SwiftUI

struct CameraDashboardView: View {
    @StateObject private var viewModel: CameraDashboardViewModel
    @StateObject private var coordinator = AppCoordinator()
    
    init(viewModel: CameraDashboardViewModel) {
        _viewModel = StateObject(wrappedValue: viewModel)
    }
    
    var body: some View {
        NavigationStack(path: $coordinator.path) {
            content
                .navigationTitle("Sürücü Kamerası")
                .navigationBarTitleDisplayMode(.inline)
                .toolbar { navigationToolbar }
                .navigationDestination(for: AppCoordinator.Page.self) { page in
                    coordinator.build(page: page)
                }
                .onAppear { 
                    viewModel.onViewAppear()
                }
        }
    }
    
    private var content: some View {
        ZStack {
            Color(uiColor: .systemGray6).edgesIgnoringSafeArea(.all)
            VStack {
                VideoPlayerView(streamUrl: $viewModel.streamUrl) 
                    .aspectRatio(16/9, contentMode: .fit)
                    .cornerRadius(12)
                    .padding()

                Spacer()
                bottomControls
            }
        }
    }

    
    private var bottomControls: some View {
        VStack(spacing: 15) {
            Text(viewModel.connectionStatus.description)
                .font(.headline)
                .foregroundColor(viewModel.connectionStatus == .connected ? .green : .primary)
            
            HStack(spacing: 40) {
                Button(action: viewModel.connectButtonTapped) {
                    Image(systemName: "wifi")
                        .font(.largeTitle)
                }
                .disabled(viewModel.connectionStatus == .connecting || viewModel.connectionStatus == .connected)
                
                Button(action: viewModel.recordButtonTapped) {
                    Image(systemName: viewModel.isRecording ? "stop.circle.fill" : "record.circle")
                        .font(.system(size: 60))
                        .foregroundColor(viewModel.isRecording ? .red : .primary)
                }
            }
        }
        .padding(.bottom, 30)
    }
    
    @ToolbarContentBuilder
    private var navigationToolbar: some ToolbarContent {
        ToolbarItem(placement: .navigationBarLeading) {
            Button(action: { coordinator.goTo(.settings) }) { Image(systemName: "gear") }
        }
        ToolbarItem(placement: .navigationBarTrailing) {
            Button(action: { coordinator.goTo(.fileList) }) { Image(systemName: "folder") }
        }
    }
}

// ConnectionState extension'ı aynı kalır.
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
