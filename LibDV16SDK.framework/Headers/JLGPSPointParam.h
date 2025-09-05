//
//  JLGPSPointParam.h
//  LibDV16SDK
//
//  Created by Ezio on 2018/4/16.
//  Copyright © 2018 Zhuhia Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JLGPSPointParam : NSObject

/**
 位置精度
 */
@property(nonatomic,assign)float pdop;

/**
 水平精度
 */
@property(nonatomic,assign)float hdop;

/**
 //垂直精度
 */
@property(nonatomic,assign)float vdop;

/**
 //纬度
 */
@property(nonatomic,assign)float lat;

/**
 //经度
 */
@property(nonatomic,assign)float lon;

/**
 //海拔高度
 */
@property(nonatomic,assign)float elv;

/**
 //速度
 */
@property(nonatomic,assign)float speed;

/**
 //航向
 */
@property(nonatomic,assign)float direct;

/**
 //磁变度
 */
@property(nonatomic,assign)float declinat;


@end
