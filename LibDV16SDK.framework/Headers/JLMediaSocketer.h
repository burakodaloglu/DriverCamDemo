//
//  JLMediaSocketer.h
//  DV16Flying
//
//  Created by jieliapp on 2017/6/10.
//  Copyright © 2017年 Zhuhia Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol JLMediaSocketerDelegate <NSObject>
@optional
/// 收到来自设备的回复数据
/// @param type 数据类型
/// @param data 数据内容
-(void)jlMediaSockerDidReceive:(int)type withData:(NSData *)data;

@end

@interface JLMediaSocketer : NSObject
@property(nonatomic,weak)id <JLMediaSocketerDelegate> delegate;

+(instancetype)sharedInstance;

/**
 开始接收数据 （获取多个视频文件封面图）

 @param fileArray 文件列表
 
 数据接收完之后，通过通知：DV_MEDIADOWNLOAD_OK 回调 
 dict<key,value> //key:iData   Value:Data(需要放到解码库中才可以获取缩略图)
 dict<key,value> //key:MediaDate Value:date(对应日期)
 dict<key,value> //key:width   Value:照片宽度
 dict<key,value> //key:height  Value:照片高度
 dict<key,value> //key:file    Value:照片名称
 
 */
-(void)startToReceiveMediaData:(NSArray *)fileArray;


/**
 开始接收预览图数据 （获取一个视频的多个预览图）

 数据接收完之后，通过通知：DV_MEDIASPHOTO_GET 回调
 数据接收全部完成之后，通过通知：DV_MEDIASPHOTO_FINISH 回调
 
 dict<key,value> //key:iData   Value:Data(需要放到解码库中才可以获取缩略图)
 dict<key,value> //key:MediaDate Value:date(对应日期)
 dict<key,value> //key:width   Value:照片宽度
 dict<key,value> //key:height  Value:照片高度
 dict<key,value> //key:file    Value:照片名称
 
 @param number 预览图个数
 */
-(void)startToReceiveMediasDataForOne:(NSInteger)number;


/**
 停止接收数据
 */
-(void)stopToReceiveMediaData;

@end
