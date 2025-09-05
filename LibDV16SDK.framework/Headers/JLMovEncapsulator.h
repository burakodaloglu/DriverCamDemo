//
//  JLMovEncapsulator.h
//  DVRunning16
//
//  Created by jieliapp on 2017/7/26.
//  Copyright © 2017年 Zhuhia Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JLMovEncapsulator : NSObject



+(instancetype) sharedInstanced;

/**
 修改合成参数
 
 @param dict 参数字典
 |----------------------|------------------------------|
 dict[@"audioType"]     | 音频类型，DV16设备这边是1
 dict[@"audioChannel"]  | 采样通道, DV16设备这边是1
 dict[@"audioBits"]     | 采样位深，DV16设备这边是16
 dict[@"audioRate"]     | 采样率，DV16设备这边是8000，
 dict[@"width"]         | 宽度
 dict[@"height"]        | 高度
 dict[@"ipInterval"]    | 每隔多少P帧有一个I帧
 dict[@"audioInterval"] | 每隔多少视频帧插入一帧音频帧
 dict[@"videoRate"]     | 帧率
 */
-(void)jlinitWithConfigurations:(NSDictionary *)dict;

/**
 创建保存的文件路径
 
 @param savePath 文件路径：E:Document/test.mov
 @return 创建结果
 */
-(BOOL)jlcreateWithPath:(NSString *)savePath;


/**
 写入数据
 
 @param data 音视频数据
 @param type 0：音频类型 1：视频类型
 */
-(void)jlWirteDataToEncapsulator:(NSData *)data WithType:(NSInteger )type;

/**
 设置音频参数
 
 @param jsampleRate 采样率
 @param jchannel 声道数
 @param jaudioFormat 位宽
 @return 状态
 */
-(BOOL)jlSetAudioTrack:(int)jsampleRate Channel:(int)jchannel AudioFormat:(int)jaudioFormat;

/**
 关闭文件
 */
-(void)jlClose;

/**
 保存录像文件的时长
 
 @param duration 时长
 */
-(void)jlsetDuration:(int)duration;

@end
