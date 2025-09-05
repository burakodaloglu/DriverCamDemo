//
//  VideoPlayerView.swift
//  DriverCamDemo
//
//  Created by Burak KODALOGLU on 5.09.2025.
//

import SwiftUI
import Foundation

struct VideoPlayerView: UIViewRepresentable {
    @Binding var streamUrl: URL?
    
    func makeUIView(context: Context) -> UIView {
        return UIView()
    }

    func updateUIView(_ uiView: UIView, context: Context) {

        if let player = context.coordinator.player, player.isPreparedToPlay {
            return
        }
        
        guard let url = streamUrl else { return }
        
        let options = IJKFFOptions.byDefault()
        let player = IJKFFMoviePlayerController(contentURL: url, with: options)
        
        player?.view.frame = uiView.bounds
        player?.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        
        uiView.addSubview(player!.view)
        
        context.coordinator.player = player
        player?.prepareToPlay()
        player?.play()
    }

    func makeCoordinator() -> Coordinator {
        Coordinator(self)
    }

    class Coordinator: NSObject {
        var parent: VideoPlayerView
        var player: IJKFFMoviePlayerController?

        init(_ parent: VideoPlayerView) {
            self.parent = parent
        }
        
        deinit {
            player?.shutdown()
            player?.view.removeFromSuperview()
        }
    }
}
