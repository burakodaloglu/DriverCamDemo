//
//  JLMediaStreamManager.h
//  DV16Flying
//
//  Created by jieliapp on 2017/6/15.
//  Copyright © 2017年 Zhuhia Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class JLMediaStreamManager;
typedef void(^streamConnect)(BOOL status);

/**
 / 本类中有视频数据（裸流）和音频数据（pcm）返回给上层应用使用
 / 上层应用中可通过接受通知：DV_PCM_DATA  //NSDictionary{ @media:JLMediaStreamManager @"data":PCM裸流数据 }
 /                      DV_VIDEO_DATA_STREAM  //NSDictionary{ @media:JLMediaStreamManager @"data":视频数据（裸流）
 / 由于网络原因或者其他原因导致的数据接收模块初始化失败会通过通知返回错误信息
 /  DV_REAL_STREAM_ERROR 后接错误信息NSObject
 */


typedef enum : NSUInteger {
    MEDIA_FRONT,        //前视
    MEDIA_POST,         //后视
} MEDIA_TYPE_WEBCAM;


@protocol JLMediaStreamDelegate <NSObject>

@optional
/// 回调pcm数据
/// @param manager 媒体对象
/// @param data pcm数据
-(void)jlmediaStream:(JLMediaStreamManager *)manager PcmData:(NSData *)data;

/// 回调264数据
/// @param manager 媒体对象
/// @param data 264数据
-(void)jlmediaStream:(JLMediaStreamManager *)manager H264AndJpegData:(NSData *)data;

/// 回调状态信息
/// @param manager 媒体对象
/// @param status 状态
-(void)jlmedia:(JLMediaStreamManager *)manager StatusChange:(int)status;

/// 错误回调
/// @param manager 媒体对象
/// @param error 错误内容代码
/// @param msg 错误内容描述
-(void)jlmediaStream:(JLMediaStreamManager *)manager Error:(int)error withMsg:(NSString *)msg;

/// 回调媒体信息包
/// @param manager 媒体对象
/// @param data 数据内容
/// @param type 数据类型
/// @param seq 序列号
/// @param ts 时间戳
-(void)jlmediaStream:(JLMediaStreamManager *)manager Media:(NSData *)data type:(uint32_t)type sequence:(uint32_t)seq timeStamp:(uint32_t)ts;

@end


@interface JLMediaStreamManager : NSObject

@property(nonatomic,assign)int vPort;//video port
@property(nonatomic,assign)int aPort;//audio port
@property(nonatomic,assign)int sPort;//service port
@property(nonatomic,assign)int lPort;//local port
@property(nonatomic,strong)NSString *dest_ip;
@property(nonatomic,weak)id <JLMediaStreamDelegate> delegate;


+(instancetype)sharedInstance;




/**
 设置ffplayer使用UDP打开实时流
 (传输状态变更通知：DV_REALSTREAM_STATUS)
 对应状态如下：
 //    RTS_STATE_IDLE = 0,
 //    RTS_STATE_PREPARE = 1,
 //    RTS_STATE_PLAYING = 2,
 //    RTS_STATE_PAUSE = 4,
 //    RTS_STATE_STOP = 5,

 @param type 前视/后视
 @param fps 视频帧率
 @param rate 音频采样率
 @param size 视频宽高
 @param streamType 实时流的类型 0:jpeg  1:h264
 */
-(void)jlCreatePlayerWithType:(MEDIA_TYPE_WEBCAM) type SetFps:(uint32_t)fps SetRate:(uint32_t) rate SetFrame:(CGSize)size StreamType:(NSInteger) streamType;


/**
 这是用于TCP播放时打开FFPlayer的实时流
（ 传输状态变更通知：DV_REALSTREAM_STATUS)

 @param fps 视频帧率
 @param rate 音频采样率
 @param size 视频宽高
 @param streamType 实时流类型 0:jpeg   1:h264
 */
-(void)jlCreateTCPPlayerWithFps:(uint32_t)fps SetRate:(uint32_t)rate SetFrame:(CGSize)size StreamType:(NSInteger) streamType;
/**
 这是用于TCP播放时打开FFPlayer的实时流
（ 传输状态变更通知：DV_REALSTREAM_STATUS)

 @param fps 视频帧率
 @param rate 音频采样率
 @param size 视频宽高
 @param streamType 实时流类型 0:jpeg   1:h264
 @param block 数据链路连接状态回调
 */
-(void)jlCreateTCPPlayerWithFps:(uint32_t)fps SetRate:(uint32_t)rate SetFrame:(CGSize)size StreamType:(NSInteger) streamType Result:(streamConnect)block;
/**
 音频开关
 
 @param state 状态
 */
-(void)jlMediaStreamAudioSwtich:(BOOL)state;

/**
 视频开关
 
 @param state 状态
 */
-(void)jlMediaStreamVideoSwitch:(BOOL)state;

/**
 设置使用设备时间戳
 默认为使用设备时间戳
 @param state YES == 设备时间戳 NO == 手机计算的时间戳
 */
-(void)jlMediaStreamTimetampSwitch:(BOOL)state;

/**
 是否发送rtp
 
 @param status 0 = 发送 ；1 = 不发送
 */
-(void)shouldSendRtp:(int)status;


//销毁
-(void)destoryPlayerManager;



@end
