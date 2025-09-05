//
//  JLtcpSenderManager.h
//  LibDV16SDK
//
//  Created by Ezio on 2018/12/27.
//  Copyright © 2018 Zhuhai Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JLtcpSenderManager : NSObject

+(instancetype)sharedInstance;

/**
 连接设备服务器

 @param host 目标地址
 @param port 目标端口
 */
-(void)didConnectToHost:(NSString *)host WithPort:(int)port;

/**
 数据发送

 @param baseData 数据内容
 */
-(void)didSendData:(NSData *)baseData;

/**
 断开连接
 */
-(void)disConnect;

@end

NS_ASSUME_NONNULL_END
