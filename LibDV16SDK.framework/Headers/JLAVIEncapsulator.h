//
//  JLAVIEncapsulator.h
//  LibDV16SDK
//
//  Created by Ezio on 2018/8/23.
//  Copyright © 2018 Zhuhai Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JLAVIObject;
@interface JLAVIEncapsulator : NSObject

+(instancetype)sharedInstance;
/**
 配置录制参数

 @param aviObject JLAVIObject
 @param filePath path
 */
-(void)aviInitWithConfigurations:(JLAVIObject *)aviObject WithPath:(NSString *)filePath;
/**
 写入数据
 
 @param data 音视频数据
 @param type 0：音频类型 1：视频类型
 */
-(void)aviWirteDataToEncapsulator:(NSData *)data WithType:(NSInteger )type;

/**
 暂停录制
 */
-(void)aviDidPauseAVI;

/**
 继续录制
 */
-(void)aviDidContinueAVI;

/**
 结束录制
 */
-(void)aviDidFinish;

@end
