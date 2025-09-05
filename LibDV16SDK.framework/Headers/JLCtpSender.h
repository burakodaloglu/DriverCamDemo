//
//  JLCtpSender.h
//  DV16Project
//
//  Created by jieliapp on 2017/5/8.
//  Copyright © 2017年 Zhuhia Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JLCtpSender : NSObject


/**
 超时时间
 */
@property (nonatomic,assign)NSTimeInterval  jlTimeOut;
@property (nonatomic,readonly)BOOL            isConnect;
+ (instancetype)sharedInstanced;


/**
 创建一个udp通讯socket
 //UDP 通讯不建议做心跳包，因为协议的原因，丢包时心跳丢失。
 @return udp object
 */
-(instancetype)initWithUdpCmd;

/**
 重置心跳包发送间隔以及超时时间
 （超时时间是指，在手机发出心跳包到收到回复之间的时间段，如果超过设置时间还没回复则视为超时断开）
 @param sendTime 心跳包间隔
 @param heartTimeOut 超时时间
 @param feq 允许超时次数（1~10）默认为1次
 @param type 心跳包发送方式：YES：TCP  NO：UDP
 */
-(void)dvReSetHeartSend:(NSTimeInterval )sendTime WithTimeOut:(NSTimeInterval)heartTimeOut TimeOutFrequency:(NSInteger)feq WithType:(BOOL)type;
/**
 自定义发送心跳接口
 本接口会停掉自动发送心跳，需要根据开发者自定义规则去发送心跳包
 */
-(void)dvDidSendHeartBeat;

/**
 停止默认的心跳发送（不可在收到接入命令DV_APP_ACCESS之前调用，不然会失效）
 */
-(void)dvDidStopSendHeartBeat;

/**
 连接tcp服务器
 
 @param host 地址
 @param port 端口
 */
- (void)didConnectToAddress:(NSString *)host withPort:(NSInteger)port;



/**
 断开连接
 */
- (void)desConnectedCTP;



/**
 连接成功之后，APP需要发起访问请求，设备才会主动发送状态过来
 */
-(void)appAccessInfoRequest;


/**
 根据topic查询对应的状态
 
 @param topic Topic
 */
-(void)checkDeviceStatusWithTopic:(NSString *)topic;

#pragma mark <- 设置 ->
/**
 设备按键声音
 
 @param status 开关
 */
-(void)dvKeyVoiceSetWith:(BOOL)status;

/**
 设置设备自动关机
 
 @param status 参数：0：off，1：3m，2：5m，3：10m
 */
-(void)dvAffterAutoShoudown:(int)status;

/**
 设置屏幕保护
 
 @param pro 参数：0: off,1:30s 2:1m 3:2m
 */
-(void)dvScreenProtect:(int)pro;

/**
 设置设备语言
 
 @param status 参数：1:简体中文,2:繁体中文 3:日文 4:韩文  5:英文 6:法文 7：德语  8：意大利语 9：荷兰语 10 葡萄牙语
 */
-(void)dvLangagueSetWith:(int)status;


/**
 设置设备TV模式
 
 @param status 参数：0:pal,1:ntsc
 */
-(void)dvTvModelSetWith:(int)status;


/**
 设置设备格式化
 
 */
-(void)dvFormateWithStatus;


/**
 设置设备录像参数
 
 @param type 视频格式：0：JPEG，1：H264
 @param height 分辨率高
 @param width 分辨率宽
 @param fps 帧数
 @param rate 音频采样率
 @param around 前后视：0：前视  1：后视
 */
-(void)dvVideoParamSetWithFormate:(int)type Height:(int)height Width:(int)width Fps:(int)fps Rate:(int) rate Around:(int) around;

/**
 手机控制设备启动/关闭录像。
 
 @param status 状态(0：关闭， 1：打开)
 */
- (void)dvVideoControlWithStatus:(int)status;

/**
 设置双路录像
 
 @param status 状态(0：off， 1：on)
 */
- (void)dvVideoDoubleWithStatus:(int)status;

/**
 设置循环录像
 
 @param status  状态(0:关闭,1:3m, 2:5m, 3:10m) (m :分钟)
 */
-(void)dvVideoLoopWithStatus:(int)status;


/**
 设置夜视增强
 
 @param status 状态(0：关闭， 1：打开)
 */
-(void)dvVideoNightVersionWithStatus:(int)status;


/**
 设置视频曝光补偿
 
 @param status 状态：(0:+2 1:+5/3 2:+4/3  3:+1 4:+2/3 5:+1/3 6:0 7:-1/3 8:-2/3 9:-1 10:-4/3 11:-5/3 12:-2 )
 */
-(void)dvVideoExposureWithStatus:(int)status;


/**
 设置移动侦测
 
 @param status 状态(0：关闭， 1：打开)
 */
-(void)dvVideoMoveCheckWithStatus:(int)status;

/**
 设置录音设置
 
 @param status 状态(0：关闭， 1：打开)
 */
-(void)dvVideoRecordMicSetWith:(int)status;
/**
 设置视频日期标签
 
 @param status 状态(0：关闭， 1：打开)
 */
-(void)dvVideoDateSetWithStatus:(int)status;

/**
 设备车牌设置
 
 @param status 状态(0：关闭， 1：打开)
 */
-(void)dvVideoCarNumberSetWith:(int)status;

/**
 设置重力感应
 
 @param status 状态(0:关闭,1:low, 2:med, 3:hig)
 */
-(void)dvGravitySensorWith:(int)status;

/**
 设置停车监控
 
 @param status 状态(0：关闭， 1：打开)
 */
-(void)dvParkingGuardWithStatus:(int)status;

/**
 设置间隔录影
 
 @param status 状态(0:关闭,1:100ms, 2:200ms, 3:500ms)
 */
-(void)dvVideoIntervalWithStatus:(int)status;

/**
 设置拍照分辨率
 
 @param formate 拍照分辨率（0:vga, 1:1.3M, 2:2M ,3:3M ,4:5M, 5:8M, 6:10M, 7:12M)
 */
-(void)dvPhotoResolutionWithFormate:(int)formate;

/**
 拍照命令，当设备拍照完成后，会返回照片文件名给APP。
 */
-(void)dvPhotoControl;
/**
 设置定时拍照时间
 
 @param status 定时拍照选项(0：关 1：定时2秒 2：定时5秒 3：定时10秒)
 */
-(void)dvPhotoSetSelfTimerWithStatus:(int)status;
/**
 连拍设置
 
 @param Index 连拍张数(0：关  1：3张  2: 5张  3：10张)(备注2 3 没实现)
 */
-(void)dvPhotoBurstShotWithIndex:(int)Index;


/**
 设置图像质量
 
 @param Index 质量(0：lo  1：md  2: hi  )
 */
-(void)dvPhotoQualitySetWithIndex:(int)Index;

/**
 设置图像锐度
 
 @param Index 锐度(0：lo  1：md  2: hi  )
 */
-(void)dvPhotoShrpnessSetWithIndex:(int)Index;


/**
 设置图像白平衡
 
 @param Index 白平衡(0:自动  1:日光  2:阴天  3:钨丝灯  4:荧光灯)
 */
-(void)dvPhotoWhileBlanceWithIndex:(int)Index;

/**
 设置图像ISO
 
 @param Index iso(0:自动  1:100  2:200  3:400 )
 */
-(void)dvPhotoISOsetWithIndex:(int)Index;


/**
 设置图像曝光补偿
 
 @param Index 曝光参数 (0:+2 1:+5/3 2:+4/3  3:+1 4:+2/3 5:+1/3 6:0 7:-1/3 8:-2/3 9:-1 10:-4/3 11:-5/3 12:-2 )
 */
-(void)dvPhotoExposureWithIndex:(int)Index;

/**
 设置防手抖
 
 @param status 状态(0: off  1: on )
 */
-(void)dvAntiTremorSetWithStatus:(int)status;

/**
 设置照片日期标签
 
 @param status 状态(0: off  1: on )
 */
-(void)dvPhotoDateShowWithStatus:(int)status;

/**
 设置开机音效
 
 @param status 状态(0: off  1: on )
 */
-(void)dvBoardVoiceSwitch:(int)status;

/**
 快速预览设置
 
 @param Index sca( 0: off  1:2s 2:5s)
 */
-(void)dvPhotoPreviewFasterWithIndex:(int)Index;

/**
 色彩设置
 
 @param Index Color ( 0: off  1:黑白 2:陈旧)
 */
-(void)dvPhoneColorSetWithIndex:(int)Index;

/**
 设置默认设置
 
 @param status 参数：0:no,1:yes
 */
- (void)dvDefaulteSetWithStatus:(int)status;

/**
 查询剩余录像时间
 */
-(void)dvGetLastVideoTime;
/**
 查询剩余拍照张数
 */
-(void)dvGetLastPhotoNumber;
/**
 数字变焦
 
 @param type 方式（0：缩小  1：放大）
 @param multiple 放大倍数（大于等于1）
 */
-(void)dvDigitalZoomSetWith:(int)type Multiple:(float)multiple;
/**
 日期时间
 
 @param dateStr 必须严格按照格式：yyyy-MM-dd-HH-mm-ss
 */
- (void)dvDateTimeSet:(NSString *)dateStr;

/**
 设置 AP 账号信息
 
 @param ssid AP模式SSID
 @param psw AP模式PWD
 @param status 是否立即生效（0：否  1：是）
 */
-(void)dvSetAPssidInfoWith:(NSString *)ssid Password:(NSString *)psw onStatus:(int)status;
/**
 设置 STA 账号信息
 
 @param ssid 路由器的SSID
 @param psw  路由器的PWD
 @param status 是否保存路由器信息（0：否  1：是）
 */
-(void)dvSetSTAssidInfoWith:(NSString *)ssid password:(NSString *)psw onStatus:(int)status;
/**
 关闭WiFi热点
 */
-(void)dvCloseDeviceWiFi;
/**
 复位
 */
-(void)dvMakeDeviceReset;
/**
 固件升级
 */
-(void)dvFirmwareUpdateReq;
/**
 重力感应检测命令
 */
-(void)dvGravitysensorCheck;
/**
 碰撞截取命令
 */
-(void)dvCollisionInterception;

/**
 开启循环保存文件
 **
 保存当前录像文件、开启下一个录像文件
 */
-(void)dvSaveTheFileInALoop;

/**
 获取TFCard剩余容量
 */
-(void)dvCheckDeviceTFCap;

/**
 设置的实时对讲功能
 
 @param status 状态(0：关闭， 1：打开)
 */
-(void)dvIntercomControl:(int)status;

/**
 发命令让小机断开CTP连接
 */
-(void)dvCutOffCtpAisle;

/**
 文件加解锁设置
 
 @param status 1：加锁   0：解锁
 @param path 小机文件路径
 
 */
-(void)dvVideoFileLockControl:(int)status WithPath:(NSString *)path;


/**
 自定义命令

 @param dict 自定义内容
 @param topic 自定义Topic
 */
-(void)dvGenericCommandWith:(NSDictionary *)dict Topic:(NSString *)topic;


#pragma mark <- 实时流控制 ->

/**
 打开主摄像头实时流
 
 @param format 实时流格式
 @param width 实时流宽度
 @param height 实时流高度
 @param fps 实时流帧率
 @param rate 音频采样率
 */
-(void)dvRealTimeStreamFrontWebcamOpen:(int)format Width:(int)width Height:(int)height Fps:(int)fps Rate:(int)rate;

/**
 关闭主摄像头实时流
 */
- (void)dvRealTimeStreamFrontWebcamClose;

/**
 打开后拉实时流
 
 @param format 实时流格式
 @param width 实时流宽度
 @param height 实时流高度
 @param fps 实时流帧率
 @param rate 音频采样率
 */
-(void)dvRealTimeStreamPullWebcamOpen:(int)format Width:(int)width Height:(int)height Fps:(int)fps Rate:(int)rate;

/**
 关闭后拉实时流
 */
- (void)dvRealTimeStreamPullWebcamClose;



/**
后拉实时流状态检测
 */
-(void)dvRealTimeStreamPullStatusCheck;


/**
 打开、关闭对讲模式
 
 @param status YES：打开 NO：关闭（关闭时，参数全部置零）
 @param formate 音频格式（0：PCM，1：WAV，2：MP3）
 @param rate 采样率
 @param width 采样位宽（0:8bit，1:16bit)
 @param channel 声道（0：单声道，1：立体声）
 @param port 网络端口号
 */
- (void)dvOpenIntercomModeControl:(BOOL)status withFormat:(int) formate WithRate:(int)rate Width:(int)width Channel:(int)channel Port:(int)port;




#pragma mark <- 文件浏览及文件操作相关 ->
/**
 进入/退出浏览模式
 
 @param Index 状态（0：进入 1：退出）
 */
- (void)dvInOrExitBrowsMode:(int)Index;


/**
 媒体文件列表获取
 
 @param index (0：前视 1：后视)
 @param type (0:空 1:全部 2:视频 3:图片)
 */
-(void)dvGetDeviceMediaListWith:(int)index type:(int)type;



/**
 浏览缩略图
 获取设备媒体文件的多张缩略图
 @param path 起始文件名
 @param offset1 起始文件偏移时间
 @param timeinv 缩略图间隔，只获取一个预览图此参数必须为0（单位为：ms）
 @param num 缩略图张数
 */
-(void)dvBrowseThumbnails:(NSString *)path tOffset:(NSString *)offset1 Timeinv:(NSString *)timeinv number:(int)num;

/**
 浏览缩略图控制
 
 @param status  0 向前滑动 1 向后滑动
 */
-(void)dvBrowseThumbnailsControl:(NSString *)status;

/**
 多文件封面图
 获取设备多个媒体文件的封面图。
 @param mutiArray @[文件对象_0,文件对象_1,文件对象_2,....]
 */
-(void)dvGetMultiFileCoverMap:(NSArray *)mutiArray;


/**
 文件删除
 删除指定文件或所有文件。
 (如果全删除，可以使用格式化：DV_FORMAT)
 @param mutiArray @[“DCIMA/JPG00008.JPG”，“DCIMA/JPG00002.JPG”,...]
 */
-(void)dvDeleteFileFor:(NSArray *)mutiArray;



#pragma mark <- 时间轴播放 ->
/**
 时间轴播放
 
 @param dict 参数字典
 
 path: 起始播放文件名
 
 offset: 起始播放文件偏移时间(单位:毫秒)
 
 type: 视频编码格式（0：JPEG， 1：H264）
 
 fps: 视频帧率
 
 w: 视频宽
 
 h: 视频高
 
 */
-(void)dvTimeAxisPlay:(NSDictionary *)dict;

/**
 时间轴播放控制
 
 @param status 状态（0：播放，1：暂停，2：停止）
 */
-(void)dvTimeAxisPlayControl:(int)status;


/**
 时间轴快速播放
 设置时间轴快速播放的倍速等级。
 @param level 等级（0：原速, 1：2倍速, 2：4倍速, 3：8倍速, 4：16倍速, 5:32倍速, 6:64倍速）
 */
-(void)dvTimeaxisFastPlay:(int)level;

/**
时间轴播放码流
控制时间轴播放的码流。
@param status 方式（0：加大码流  1：减小码流）
*/
-(void)dvTimeAxisPlayStream:(int)status;

/**
 功能描述
 打开手机投影功能
 
 @param dict w,h,fps
 w:图片宽度,APP根据设备描述文档提供的屏幕大小有选择性的发给设备
 h:图片长度
 fps:帧率
 */
-(void)dvAppSetProjectionStart:(NSDictionary *)dict;

/**
 
 功能描述
 关闭手机投影功能
 
 */
-(void)dvAppSetProjectionClose;


/// 设置WiFi模组
/// @param status 状态（0：2.4G   1：5G）
-(void)dvConfigWifiMode:(NSInteger)status;

/// 获取WiFi模组当前正在运行频道
-(void)dvGetWifiRunningMode;





@end
