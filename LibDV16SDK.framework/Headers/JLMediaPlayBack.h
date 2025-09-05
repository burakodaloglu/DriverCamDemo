//
//  JLMediaPlayBack.h
//  DV16Flying
//
//  Created by jieliapp on 2017/6/20.
//  Copyright © 2017年 Zhuhia Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JLGPSPointParam;
@class JLMediaPlayBack;

@protocol jlMediaPlayBackDelegate <NSObject>

@optional
/**
 音频数据

 @param data PCM
 */
-(void)jlmediaPlayBack:(JLMediaPlayBack *)playback PcmData:(NSData *)data;

/**
 视频数据

 @param data 视频数据（jpeg or h264）
 */
-(void)jlmediaPlayBack:(JLMediaPlayBack *)playback H264AndJpegData:(NSData *)data;

/**
 时间包数据

 @param timeStr 时间包
 */
-(void)jlmediaPlayBack:(JLMediaPlayBack *)playback TimeRts:(NSString *)timeStr;

/**
 GPS点对象返回

 @param param GPS点对象
 */
-(void)jlmediaPlayBack:(JLMediaPlayBack *)playback DevGpsType:(JLGPSPointParam *)param;

/**
 当不支持GPS点的时候返回
 */
-(void)jlmediaPlayBackGpsNoSupport:(JLMediaPlayBack *)playback;

/**
 缓冲状态返回

 @param status 状态
 */
-(void)jlmediaPlayBack:(JLMediaPlayBack *)playback NoBuffer:(int)status;

/**
 播放完所有的文件
 */
-(void)jlmediaPlayBackEndAllFile:(JLMediaPlayBack *)playback ;

/**
 播放完一个文件
 */
-(void)jlmediaPlayBackEndOneFile:(JLMediaPlayBack *)playback;


/// 返回媒体数据的内容
/// @param playback 媒体对象
/// @param data 媒体数据包
/// @param type 类型
/// @param seq seq
/// @param ts 时间戳
-(void)jlmediaPlayBack:(JLMediaPlayBack *)playback MediaData:(NSData *)data type:(uint32_t)type sequence:(uint32_t)seq timeStamp:(uint32_t)ts;

/**
 错误信息返回

 @param code 错误代码
 @param msg 错误字符串
 */
-(void)jlmediaPlayBack:(JLMediaPlayBack *)playback Error:(int)code WithMsg:(NSString *)msg;

/**
 媒体信息包

 @param dict 媒体信息字典
 */
-(void)jlmediaPlayBack:(JLMediaPlayBack *)playback MediaPack:(NSDictionary *)dict;

/**
 回放状态返回

 @param status 状态
 RTS_STATE_IDLE = 0,
 RTS_STATE_PREPARE = 1,
 RTS_STATE_PLAYING = 2,
 RTS_STATE_PAUSE = 4,
 RTS_STATE_END = 5,
 */
-(void)jlmediaPlayBack:(JLMediaPlayBack *)playback Status:(int)status;

@end

@interface JLMediaPlayBack : NSObject


@property(nonatomic,assign)BOOL  ppStatus;
@property(nonatomic,assign)int vPort;
@property(nonatomic,assign)int aPort;
@property(nonatomic,assign)int sPort;
@property(nonatomic,strong)NSString *dest_ip;
@property(nonatomic,weak)id<jlMediaPlayBackDelegate> delegate;

+(instancetype)sharedInstance;

/**
 开始接收回放数据
 @param streamType 回放流媒体的类型 0：jpeg  1：h264
 */
-(void)jlMediaPlayBackStart:(NSInteger) streamType;


/**
 开始接收回放数据

 @param streamType 回放流媒体的类型 0：jpeg  1：h264
 @param mode 用于播放或下载：0：回放   1：下载
 */
-(void)jlMediaPlayBackStart:(NSInteger) streamType withMode:(int)mode;

/**
 停止接收回放数据
 */
-(void)jlMediaPlayBackOver;


/**
 检测是否在播放状态

 @return 状态
 */
-(BOOL)isPlaying;


/**
 检测是否在暂停状态

 @return 状态
 */
-(BOOL)isPause;


/**
 进行播放
 */
-(void)jlMediaPlayBackToPlay;


/**
 进行暂停
 */
-(void)jlMediaPlayBackToPause;

/**
 音频开关
 
 @param state 状态
 */
-(void)jlMediaPlayBackAudioSwtich:(BOOL)state;
/**
 视频开关
 
 @param state 状态
 */
-(void)jlMediaPlayBackVideoSwitch:(BOOL)state;

/**
 设置是否缓冲
 （当快播时需要设为不缓冲）
 @param buffer state
 */
-(void)jlMediaPlayisBuffer:(BOOL)buffer;


/**
 设置缓冲队列的大小

 @param size size
 */
-(void)jlMediaPlayerQueueSize:(uint16_t)size;



/*
 *  播放状态通过通知：ON_STATE_CHANGE 返回
 *   RTS_STATE_IDLE = 0,
 *   RTS_STATE_PREPARE = 1,
 *   RTS_STATE_PLAYING = 2,
 *   RTS_STATE_PAUSE = 4,
 *   RTS_STATE_END = 5,
 *
 *  错误通知返回：
 *
 **/

@end
