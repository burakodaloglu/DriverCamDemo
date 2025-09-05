//
//  JLudpSenderManager.h
//  LibDV16SDK
//
//  Created by Ezio on 2018/11/27.
//  Copyright © 2018 Zhuhai Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JLudpSenderManager : NSObject

+(instancetype)sharedInstanced;

/**
 发送图片数据

 @param baseData 图片数据
 */
-(void)didSendData:(NSData *)baseData;


/**
 发送音频数据

 @param baseData 音频数据
 */
-(void)didSendAudioData:(NSData *)baseData;

@end

NS_ASSUME_NONNULL_END
