//
//  DRAgentLoaderAdDelegate.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/1/22.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DRAgentEnumHeader.h"

@class DRAgentLoader;
@class DRAgentAdvertDataModel;
@protocol DRAgentLoaderAdDelegate <NSObject>

@required

/**
 广告数据加载成功

 @param adLoader 加载数据类
 @param adverType 广告类型
 @param advertDataModel 广告数据模型 (model)
 */
- (void)adLoaderDidFinishLoading:(DRAgentLoader *)adLoader adverType:(IAdDataType)adverType advertDataModel:(DRAgentAdvertDataModel *)advertDataModel;

/**
 广告数据加载失败

 @param adLoader 加载数据类
 @param error 错误error
 */
- (void)adLoader:(DRAgentLoader *)adLoader didFailToReceiveAdWithError:(NSError *)error;

@end

