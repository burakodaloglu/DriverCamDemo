//
//  JLAVIObject.h
//  LibDV16SDK
//
//  Created by Ezio on 2018/8/23.
//  Copyright © 2018 Zhuhai Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JLAVIObject : NSObject

/**
 *  按固定的时间长度分开录制AVI。（单位：毫秒；置0失效）
 */
@property(nonatomic,assign)UInt32 avi_time;

/**
 *  按固定的文件大小分开录制AVI。（单位：毫秒；置0失效）
 */
@property(nonatomic,assign)UInt32 avi_size;

/**
 *  帧率
 */
@property(nonatomic,assign)UInt32 avi_fps;

/**
 *  屏幕宽
 */
@property(nonatomic,assign)UInt32 avi_width;

/**
 *  屏幕高
 */
@property(nonatomic,assign)UInt32 avi_high;

/**
 *  采样率
 */
@property(nonatomic,assign)UInt32 avi_Rate;

/**
 *  采样位数
 */
@property(nonatomic,assign)UInt32 avi_Number;

/**
 *  声道数
 */
@property(nonatomic,assign)UInt32 avi_channels;

/**
 *  音效开关
 */
@property(nonatomic,assign)BOOL avi_isVoice;


@end
