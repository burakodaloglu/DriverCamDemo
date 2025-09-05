//
//  JLDV16SDK.h
//  DV16Project
//
//  Created by jieliapp on 2017/5/8.
//  Copyright © 2017年 Zhuhai Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>


//打印开关
#define logTarget 1
#define dv16logs(...) if(logTarget == 1) NSLog(__VA_ARGS__)


#pragma mark <- 错误列表 ->
//错误列表
#define ENONE               0      // 无错误
#define E_SDCARD            1      // SD卡错误
#define E_SD_OFFLINE        2      // SD卡离线
#define E_ACCESS_RFU        3      // 拒绝访问
#define E_REQUEST           4      // 请求错误
#define E_VER_UMATCH        5      // 版本不匹配
#define E_NO_TOPIC          6      // Topic未实现
#define E_IN_USB            7      // 正处于USB模式
#define E_IN_VIDEO          8      // 正在录像
#define E_IN_BROWSE         9      // 正在浏览模式
#define E_IN_PARKING        10     // 正在停车
#define E_OPEN_FILE         11     // 打开文件失败
#define E_SYS_EXCEP         12     // 系统异常
#define E_NET_ERR           14     // 网络异常
#define CTP_PULL_OFFLINE    15     //后拉不在线
#define CTP_PULL_NOSUPPORT  16     //后拉不支持
#define CTP_RT_OPEN_FAIL    17     //实时流打开失败

#pragma mark <- 流媒体头部 ->

#define PCM_TYPE_AUDIO               1      //音频数据
#define JPEG_TYPE_VIDEO              2      //视频jpg格式
#define H264_TYPE_VIDEO              3      //视频h264格式
#define PREVIEW_TYPE                 4      //预览图
#define DATE_TIME_TYPE               5      //用于时间同步包
#define MEDIA_INFO_TYPE              6      // 视频媒体信息
#define PLAY_OVER_TYPE               7      //结束包

#pragma mark <- topic说明 ->
//topic说明
#define DV_APP_ACCESS      @"APP_ACCESS"            //APP访问
#define DV_KEEP_ALIVE      @"CTP_KEEP_ALIVE"        //心跳包
#define DV_KEEP_INTERVAL   @"KEEP_ALIVE_INTERVAL"   //心跳间隔时间
#define DV_SD_STATUS       @"SD_STATUS"             //SD卡状态
#define DV_BAT_STATUS      @"BAT_STATUS"            //电池状态
#define DV_UUID            @"UUID"                  //设备UUID
#define DV_KEY_VOICE       @"KEY_VOICE"             //按键声音
#define DV_LIGHT_FRE       @"LIGHT_FRE"             //光源频率
#define DV_AUTO_SHUTDOWN   @"AUTO_SHUTDOWN"         //自动关机
#define DV_SCREEN_PRO      @"SCREEN_PRO"            //屏幕保护
#define DV_LANGUAGE        @"LANGUAGE"              //语言设置
#define DV_TV_MODE         @"TV_MODE"               //TV模式
#define DV_FORMAT          @"FORMAT"                //格式化
#define DV_SYSTEM_DEFAULT  @"SYSTEM_DEFAULT"        //默认设置
#define DV_VIDEO_PARAM     @"VIDEO_PARAM"           //录像参数(前视)
#define DV_PULL_VIDEO_PARAM @"PULL_VIDEO_PARAM"     //录像参数(后视)
#define DV_VIDEO_CTRL      @"VIDEO_CTRL"            //录像控制
#define DV_VIDEO_FINISH    @"VIDEO_FINISH"          //录像完成
#define DV_DOUBLE_VIDEO    @"DOUBLE_VIDEO"          //双路录像
#define DV_VIDEO_LOOP      @"VIDEO_LOOP"            //循环录像
#define DV_VIDEO_WDR       @"VIDEO_WDR"             //夜视增强
#define DV_VIDEO_EXP       @"VIDEO_EXP"             //曝光补偿
#define DV_MOVE_CHECK      @"MOVE_CHECK"            //移动侦测
#define DV_VIDEO_MIC       @"VIDEO_MIC"             //录音设置
#define DV_VIDEO_DATE      @"VIDEO_DATE"            //视频日期标签
#define DV_VIDEO_CAR_NUM   @"VIDEO_CAR_NUM"         //车牌设置
#define DV_GRA_SEN         @"GRA_SEN"               //重力感应
#define DV_VIDEO_PAR_CAR   @"VIDEO_PAR_CAR"         //停车监控
#define DV_VIDEO_INV       @"VIDEO_INV"             //间隔录影
#define DV_PHOTO_RESO      @"PHOTO_RESO"            //拍照分辨率
#define DV_PHOTO_CTRL      @"PHOTO_CTRL"            //拍照控制
#define DV_SELF_TIMER      @"SELF_TIMER"            //设置定时拍照时间
#define DV_BURST_SHOT      @"BURST_SHOT"            //连拍
#define DV_PHOTO_QUALITY   @"PHOTO_QUALITY"         //图像质量
#define DV_PHOTO_SHARPNESS @"PHOTO_SHARPNESS"       //图像锐度
#define DV_WHITE_BALANCE   @"WHITE_BALANCE"         //图像白平衡
#define DV_PHOTO_ISO       @"PHOTO_ISO"             //图像ISO
#define DV_PHOTO_EXP       @"PHOTO_EXP"             //曝光补偿
#define DV_ANTI_TREMOR     @"ANTI_TREMOR"           //防手抖
#define DV_PHOTO_DATE      @"PHOTO_DATE"            //图片日期标签
#define DV_BOARD_VOICE     @"BOARD_VOICE"           //开机音效
#define DV_FAST_SCA        @"FAST_SCA"              //快速预览
#define DV_PHOTO_COLOR     @"PHOTO_COLOR"           //色彩设置
#define DV_LAST_VIDEO_TIME @"LAST_VIDEO_TIME"       //剩余录像时间
#define DV_LAST_PHOTO_NUMS @"LAST_PHOTO_NUMS"       //剩余拍照数
#define DV_DIGITAL_ZOOM    @"DIGITAL_ZOOM"          //数字变焦
#define DV_DATE_TIME       @"DATE_TIME"             //日期时间
#define DV_AP_SSID_INFO    @"AP_SSID_INFO"          //AP账号信息
#define DV_STA_SSID_INFO   @"STA_SSID_INFO"         //STA账号信息
#define DV_CLOSE_WIFI      @"CLOSE_WIFI"            //关闭WIFI热点
#define DV_RESET           @"RESET"                 //复位
#define DV_FIRMWARE_UPDATE @"FIRMWARE_UPDATE"       //固件升级
#define DV_GEN_CHK         @"GEN_CHK"               //重力感应检测命令
#define DV_VIDEO_BUNMPING  @"VIDEO_BUMPING"         //碰撞截取命令
#define DV_TF_CAP          @"TF_CAP"                //TF_Card 容量
#define DV_RT_TALK_CTL     @"RT_TALK_CTL"           //设置实时对讲
#define DV_FILE_LOCK       @"FILE_LOCK"             //文件加锁、解锁设置
#define DV_RTF_RES         @"RTF_RES"               //前置实时流分辨率
#define DV_RTB_RES         @"RTB_RES"               //后置实时流分辨率
#define DV_APP_VIDEO_REC   @"APP_VIDEO_REC"         //设备主动请求APP录像（无卡录影）
#define DV_APP_TAKE_PHOTO  @"APP_TAKE_PHOTO"        //设备主动请求APP拍照（无卡拍照）
#define DV_CTP_CLI_DISCONNECT    @"CTP_CLI_DISCONNECT"    //关闭TCP连接
#define DV_VIDEO_CYC_SAVEFILE    @"VIDEO_CYC_SAVEFILE"    //循环保存文件
#define DV_NET_OTA_SINGLE        @"NET_OTA_SINGLE"        //请求设备进行单备份升级
#define DV_GENERIC_CMD           @"GENERIC_CMD"           //自定义命令

///设备WiFi模组相关
#define DV_WIFI_MODE             @"WIFI_MODE"             //获取WIFI模组支持频道和设置频道
#define DV_WIFI_RUN_MODE         @"WIFI_RUN_MODE"         //获取WIFI模组当前正在运行频道


///飞控命令（选配）需要设备支持
#define DV_WIND_VELOCITY                @"WIND_VELOCITY"                //获取风速等级
#define DV_DEVICE_DIRECTION_CONTROL     @"DEVICE_DIRECTION_CONTROL"     //控制设备飞行方向

//实时流模块
#define DV_OPEN_PULL_RT_STREAM   @"OPEN_PULL_RT_STREAM"   //打开后拉实时流
#define DV_CLOSE_PULL_RT_STREAM  @"CLOSE_PULL_RT_STREAM"  //关闭后拉实时流
#define DV_OPEN_RT_STREAM        @"OPEN_RT_STREAM"        //打开主摄像实时流
#define DV_CLOSE_RT_STREAM       @"CLOSE_RT_STREAM"       //关闭主摄像实时流
#define DV_PULL_VIDEO_STATUS     @"PULL_VIDEO_STATUS"     //后拉实时流状态检测
#define DV_REAL_STREAM_ERROR     @"REAL_STREAM_ERROR"     //实时流中返回的错误
#define DV_REAL_DROP_FRAME       @"REAL_DROP_FRAME"       //实时流中个丢帧的错误返回




#define DV_OPEN_PHONE_MODE       @"OPEN_PHONE_MODE"       //打开对讲模式
#define DV_CLOSE_PHONE_MODE      @"CLOSE_PHONE_MODE"      //关闭对讲模式

#define DV_BROWSE_MODE               @"BROWSE_MODE"              //浏览模式
#define DV_FORWARD_MEDIA_FILES_LIST  @"FORWARD_MEDIA_FILES_LIST" //前视媒体文件列表
#define DV_BEHIND_MEDIA_FILES_LIST   @"BEHIND_MEDIA_FILES_LIST"  //后视媒体文件列表
#define DV_THUMBNAILS                @"THUMBNAILS"               //浏览缩略图
#define DV_THUMBNAILS_CTRL           @"THUMBNAILS_CTRL"          //浏览缩略图控制
#define DV_MULTI_COVER_FIGURE        @"MULTI_COVER_FIGURE"       //多文件封面图
#define DV_FILES_DELETE              @"FILES_DELETE"             //文件删除

#define DV_TIME_AXIS_PLAY            @"TIME_AXIS_PLAY"           //时间轴播放
#define DV_TIME_AXIS_PLAY_CTRL       @"TIME_AXIS_PLAY_CTRL"      //时间轴播放控制
#define DV_TIME_AXIS_FAST_PLAY       @"TIME_AXIS_FAST_PLAY"      //时间轴快速播放
#define DV_TIME_AXIS_PLAY_STREAM     @"TIME_AXIS_PLAY_STREAM"    //时间轴播放码流

#pragma mark<- 缩略图 ->
#define DV_MEDIADOWNLOAD_OK          @"MEDIADOWNLOAD_OK"         //视频缩略图数据下载完毕通知
#define DV_ALL_MEDIADOWN_OK          @"MEDIADOWNLOAD_ALL_OK"     //下载的缩略图全部Over
#define DV_AVI_MEDIAIMAGE_OK         @"AVI_MEDIAIMAGE_OK"        //本地AVI文件录制完成后的缩略图通知

#pragma mark<- 视频多张预览图 ->
#define DV_MEDIASPHOTO_GET           @"MEIDASPHOTOS_GET"         //获取到单个视频的某一张预览图
#define DV_MEDIASPHOTO_FINISH        @"MEIDASPHOTOS_FINISH"      //所需要预览图已全部获取完毕

#define DV_SUMMARY_NOTE                 @"DV_SUMMARY_NOTE_SEND"       //

#define DV_PCM_DATA                     @"MEDIA_PCM_DATA"         //PCM 数据通知
#define DV_VIDEO_DATA_STREAM            @"MEDIA_VIDEO_DATA"       //H264数据或者JPEG数据（固件决定）
#define DV_VIDEO_IMAGE_STREAM           @"GET_UIIMAGE_IJKPLAYER"  //获取当前这一刻的视频图像：UIImage（计划在后续版本中去掉，获取方法IJKMediaPlayback.h 的 thumbnailImageAtCurrentTime）
#define DV_PCM_DATA_B                   @"MEDIAPCM_BLACK"         //回放时的 PCM 数据
#define DV_VIDEO_DATA_B                 @"MEDIAVIDEO_BLACK"       //回放时的 视频 数据
#define DV_STATES_DATA_B                @"MEDIA_STATES_DATA_B"    //缓冲不足时的返回,NSObject：1=缓存不足，2 = 结束缓冲（有足够的播放数据）3 = 没有缓冲
#define DV_DATE_TIME_B                  @"MEDIADATE_DATE"         //回放时的时间戳 NSString
#define DV_MAP_GPS                      @"MAP_GPS_DATA"           //视频对应GPS数据 Object: JLGPSPointParam
#define DV_MAP_NO_GPS                   @"MAP_GPS_NO_DATA"        //视频对应没有GPS数据
#define DV_MEDIA_INFO_B                 @"MEDIA_INFO_B"           //即将播放的媒体文件的信息
#define DV_FILE_PLAYBACK_FINISH         @"FILE_PLAYBACK_FINISH"   //当前回放着的文件已经缓冲完毕
#define DV_ONE_FILE_PLAYBACK_FINISH     @"ONE_FILE_PLAY_FINISH"   //某一个文件回放完毕通知
#define DV_RECIVE_TIMEOUT               @"RECIVE_TIME_OUT"        //回放文件时超时
#define DV_PLAYBACK_ERROR               @"PLAYBACK_ERROR_NOTE"    //回放时错误通知(后面带错误类型NSDictionary类型)
#define DV_APP_SET_PROJECTION           @"NET_SCR"     //设置手机投影功能
#define DV_DEV_REQ_PROJECTION           @"DEV_REQ_PROJECTION"     //设备请求APP设置手机投影功能,该命令是设备主动发给APP
#define DV_REALSTREAM_STATUS            @"REALSTREAM_STATUS"      //传输状态变更通知


#define DV_PLAYBLACK_OVER               @"MEDIA_PLAYBLACK_OVER"   //收到回放数据最后一包，准备结束回放视频
#define DV_URGENT_VIDEO_OK              @"URGENT_VIDEO_OK"        //录制紧急视频完成后的通知
#define DV_BANDWIDTH                    @"BANDWIDTH"              //带宽
#define DV_UX_REPORT                    @"UX_REPORT_LOSE"         //丢包统计

#pragma mark <- TCP管理 ->
//tcp 地址管理
#define DV_TCP_ADDRESS     [[JLDV16SDK shareInstanced] tcpIp] //@"192.168.1.1"   //TCP 地址//""192.168.9.169//@"192.168.9.137" //
#define DV_TCP_DEFORE_A    @"192.168.1.1"
#define DV_TCP_PORT        3333             //TCP 端口
#define DV_TCP_STREAM      2229             //TCP 实时流端口
#define DV_PLAYBLACK_PORT  2223             //回看 端口
#define DV_HTTP_PORT       8080             //Http 端口
#define DV_SOCKETER_PORT   2226             //Media tcp下载端口
#define DV_COLLISION_PORT  2229             //碰撞截取下载端口
#define DV_PCM_PORT        2231             //PCM数据发送端口
#define DV_UDP_PORT        2228             //UDP数据发送端口
#define DV_UDP_JPG_PORT    2230             //手机投屏的端口
#define DV_TCP_PULL_PORT   2233             //双路TCP后拉端口
#define DV_SINGLE_OTA      3335             //单备份OTA升级端口

#pragma mark <- 服务发现 ->
#define DV_DISCOVERY_PORT  3889              //服务发现端口
#define DV_MSSDP_PORT      3889              //服务发现端口2
#define DV_DISCOVERY_MSG   @"MSSDP_SEARCH"   //服务发现信息内容
#define DV_DISCOVERY_NOTI  @"MSSDP_NOTIFY"    //服务发现回调


//tcp连接信息
#define DV_TCP_CONNECTED            @"TCP_CONNECTED"       //TCP 连接成功
#define DV_TCP_DISCONNECTED         @"TCP_DISCONNECTED"    //TCP 断开连接
#define DV_TCP_TIMEOUT              @"TCP_TIMEOUT"         //TCP 超时
#define DV_TCP_STREAM_CONNECTED     @"ECTCPCONNECT_OK"     //TCP Stream 连接成功
#define DV_TCP_STREAM_DISCONNECTED  @"DV_TCP_STREAM_DISCONNECTED" //TCP Stream 断开连接

//AppInfo
#define APP_SDK_VERSION     @"2.5.9"                        //SDK版本
#define APP_DV_VERSION      [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

//APP状态管理通知
#define APP_DV_UNACTIVE    @"SCREEN_WILL_UN_ACTIVE"         //变得不活跃
#define APP_DV_BEACTIVE    @"SCREEN_WILL_BE_ACTIVE"         //变得活跃



@interface JLDV16SDK : NSObject

@property(nonatomic,strong)NSString *tcpIp;

+(instancetype)shareInstanced;

- (void)redirectNSLogToDocumentFolder;

@end

