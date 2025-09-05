//
//  JLIntercomer.h
//  DVRunning16
//
//  Created by jieliapp on 2017/8/15.
//  Copyright © 2017年 Zhuhia Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#define kNumberAudioQueueBuffers 3  //定义了三个缓冲区
#define kDefaultBufferDurationSeconds 0.1279   //调整这个值使得录音的缓冲区大小为2048bytes
#define kDefaultSampleRate 8000   //定义采样率为8000

@interface JLIntercomer : NSObject

@property (nonatomic,assign)AudioStreamBasicDescription audioFormat;
@property (nonatomic,assign)BOOL  recorderStatus;

+(instancetype)sharedInstanced;

/**
 开始录音
 */
- (void)startRecorder;


/**
 开始录音

 @param sampleRate 采样率
 @param channel 通道数
 */
- (void)startRecorder:(int)sampleRate WithChannel:(int)channel;

/**
 停止录音
 */
- (void)stopRecorder;

/**
 重置audioFormat

 @param audioFormat format
 */
-(void)setAudioFormat:(AudioStreamBasicDescription)audioFormat;

@end
