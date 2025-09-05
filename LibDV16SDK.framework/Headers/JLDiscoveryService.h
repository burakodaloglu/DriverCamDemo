//
//  JLDiscoveryService.h
//  LibDV16SDK
//
//  Created by jieliapp on 2017/10/18.
//  Copyright © 2017年 Zhuhia Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>



@protocol JLDiscoveryServiceDelegate <NSObject>

@optional

-(void)didReciveData:(NSDictionary *)dict fromAddress:(NSString *)address;

@end

@interface JLDiscoveryService : NSObject

@property(nonatomic,strong) id<JLDiscoveryServiceDelegate> delegate;


+(instancetype)sharedInstanced;


/// 设置广播地址以及端口
/// @param addr 地址
/// @param port 端口(默认填写3889)
-(void)setBrowcaseAddress:(NSString *)addr port:(NSInteger)port;

/**
 *  设置搜索结果的delegate
 *
 *  @param delegate ECSearchDelegate
 */
-(void)setDelegate:(id<JLDiscoveryServiceDelegate>)delegate;

/**
 开启服务发现

 @param msg 服务发现内容
 @param setTime 搜索间隔
 */
-(void)jlDiscoverServiceDevice:(NSString *)msg withTime:(NSTimeInterval) setTime;

/**
 停止搜索
 */
-(void)jlStopSendSearchUDP;
/**
 停止搜索_1
 */
-(void)jlStopSendSearchUDP_1;

/**
 停止接收服务
 */
-(void)jlDisReciveUDP;

@end
