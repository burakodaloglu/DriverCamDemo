//
//  JLCtpCaChe.h
//  DV16Project
//
//  Created by jieliapp on 2017/5/11.
//  Copyright © 2017年 Zhuhia Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    RT_STREAM,      //打开前置
    PU_STREAM,      //打开后置
    NO_STREAM,      //没有打开
} REAL_TIME_STREAM;

@interface JLCtpCaChe : NSObject


/**
 //设备UUID
 */
@property (nonatomic, strong)NSString       *devUUID;

/**
 //SD卡状态(NO:offline,YES:online)
 */
@property (nonatomic, assign)BOOL           SD_Status;

/**
 //是否在录像模式
 */
@property (nonatomic, assign)BOOL           isREC_Status;

/**
 //设备按键声音（NO：off，YES：on）
 */
@property (nonatomic, assign)BOOL           Key_voice;

/**
 //实时对讲状态;
 */
@property (nonatomic, assign)BOOL           intercomStatus;

/**
 //实时流媒体类型（0：jpeg ，1：h264）
 */
@property (nonatomic, assign)NSInteger      videoStreamType;

/**
 录像信息：VIDEO_PARAM
 */
@property (nonatomic, strong)NSDictionary   *videoMsgDict;


/**
 后拉信息：PULL_VIDEO_PARAM
 */
@property (nonatomic, strong)NSDictionary   *pullVideoMsgDict;

/**
 实时流播放信息(前置)
 */
@property (nonatomic, strong)NSDictionary   *realTimeMsgDict;


/**
 实时流播放信息（后置）
 */
@property (nonatomic, strong)NSDictionary   *pullStreamMsgDict;

/**
 前置摄像头的播放状态
 */
@property (nonatomic, assign)BOOL           realTimeStreamStatus;

/**
 后置摄像头的播放状态
 */
@property (nonatomic, assign)BOOL           pullStreamStatus;

/**
 //TF_Card 剩下容量
 */
@property (nonatomic, strong)NSDictionary   *tfCapDict;

/**
 //设置录音相关设置
 */
@property (nonatomic, strong)NSDictionary   *videoMicDict;

/**
 //停车监控相关设置
 */
@property (nonatomic, strong)NSDictionary   *videoPartDict;

/**
 //录像日期标签
 */
@property (nonatomic, strong)NSDictionary   *videoDateDict;

/**
 //照片日期标签
 */
@property (nonatomic, strong)NSDictionary   *photoDateDict;

/**
 //开机音效
 */
@property (nonatomic, strong)NSDictionary   *boardVoiceDict;

/**
 //重力感应（碰撞感应灵敏度）
 */
@property (nonatomic, strong)NSDictionary   *graSenDict;

/**
 //后拉实时流状态支持
 */
@property (nonatomic, assign)BOOL           pullVideoStatus;


/**
 //后拉摄像头支持参数
 */
@property (nonatomic, strong)NSDictionary   *pullVideoDict;

/**
 //当前实时流的模式、状态
 */
@property (nonatomic, assign)REAL_TIME_STREAM streamTypeStatus;


/**
 当前实时流的模式：YES：前置    NO：后置 (默认为前置模式)
 */
@property (nonatomic, assign)BOOL             rtspStreamType;


/**
 当前固件拍照分辨率等级 （0:vga, 1:1.3M, 2:2M ,3:3M ,4:5M, 5:8M, 6:10M, 7:12M)
 */
@property (nonatomic, assign)int              dv_photoPres;

/**
 当前固件拍摄图像质量等级 （0：标清 1：高清 2：超清）
 */
@property (nonatomic, assign)int              dv_photoQuality;

/**
 前视实时流分辨率
 dvRtf: 状态(1080：1080P， 720：720P   480:VGA)
 */
@property (nonatomic, assign)int    dvRtf;

/**
 后视实时流分辨率
 dvRtb: 状态(0：1080P， 1：720P 2:VGA)
 */
@property (nonatomic, assign)int    dvRtb;

/**
 回放播放状态(0:播放  1：暂停  2:停止)
 */
@property (nonatomic, assign)int    dvTimeAxisPlayState;


/// 回放时的速率（0：原速, 1：2倍速, 2：4倍速, 3：8倍速, 4：16倍速, 5:32倍速, 6:64倍速）
@property (nonatomic, assign)int    dvTimeAxisPlaySpeed;


/// AP 模式下的密码
@property (nonatomic, strong)NSString *ap_password;


/// AP 模式下的ssid
@property (nonatomic, strong)NSString *ap_ssid;


/// wifi 频道状态(0:2.4G  1:5G )
@property (nonatomic, assign)int wifimode;

/// 设备当前语言
@property (nonatomic,strong)NSString *langagueStr;

+(instancetype)sharedInstance;

+(void)attempDealloc;

@end
