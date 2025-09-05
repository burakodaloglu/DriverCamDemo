//
//  JLOTASingleWay.h
//  LibDV16SDK
//
//  Created by EzioChan on 2022/8/26.
//  Copyright © 2022 Zhuhai Jieli Technology. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, JLOTAStatus) {
    ///请求总包信息
    JLOTAStatusInfo         = 0 << 0,
    ///传输完成
    JLOTAStatusOK           = 1 << 0,
    ///升级错误
    JLOTAStatusErr          = 1 << 1,
    ///传输中
    JLOTAStatusTransport    = 1 << 2,
    ///停止状态
    JLOTAStatusStop         = 1 << 3,
    ///同一个文件
    JLOTAStatusSameFile     = 1 << 4,
};




@protocol JLOTAProtocol <NSObject>

-(void)updateStatus:(JLOTAStatus)status Progress:(float)progress Error:(NSError* _Nullable)err;

@end

@interface JLOTASingleWay : NSObject

@property(nonatomic,strong,readonly)NSData *bfuData;
@property(nonatomic,weak)id<JLOTAProtocol> delegate;

/// 开始OTA单备份升级
/// @param path 升级文件存放路径
/// @param step 升级阶段，从描述文件中获取，字段为“ota_step”
-(void)startOta:(NSString *)path withStep:(NSInteger)step;

/// 中断OTA单备份升级
/// @param stopBlock stopBlock description
-(void)stopOta:(void(^)(BOOL status))stopBlock;

/// 取消OTA升级
-(void)cancelOta;

/// 销毁对象
-(void)destroy;

@end

NS_ASSUME_NONNULL_END
