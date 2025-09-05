//
//  JLCollisionHandler.h
//  DVRunning16
//
//  Created by jieliapp on 2017/8/9.
//  Copyright © 2017年 Zhuhia Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JLCollisionHandler : NSObject



@property(nonatomic,assign)BOOL     collisionStatus;

+(instancetype)sharedInstance;



+(void)destoryCollisionHandler;

/**
 紧急文件保存的文件路径(前置)
 
 @param path 文件路径
 @param dict @{@"w":@"640",@"h":@"480"}
 */
-(void)jlSaveCollisionFileWithPath:(NSString *)path withDict:(NSDictionary *)dict;

/**
 紧急文件保存的文件路径（后置）
 
 @param path 文件路径
 @param dict @{@"w":@"640",@"h":@"480"}
 */
-(void)jlSavePostCollisionFileWithPath:(NSString *)path withDict:(NSDictionary *)dict;


/**
 *      每次保存完紧急视频数据，会通过通知：DV_URGENT_VIDEO_OK 
 *      nsobject: path
 *
 **/

@end
