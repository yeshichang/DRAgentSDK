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

/*！
 @brief 广告数据加载成功
 @param adLoader 加载数据类
 @param adverType 广告类型
 @param advertDataModel 广告数据模型 (model)
 */
- (void)adLoaderDidFinishLoading:(DRAgentLoader *)adLoader adverType:(IAdDataType)adverType advertDataModel:(DRAgentAdvertDataModel *)advertDataModel;

/*！
 @brief 广告数据加载失败
 @param adLoader 加载数据类
 @param error 错误error
 */
- (void)adLoader:(DRAgentLoader *)adLoader didFailToReceiveAdWithError:(NSError *)error;

@optional

/*！
 @brief webView点击返回 注:(有落地页，跳入webView，从webView返回广告控制器页面)
 @param adLoader 加载数据类
 */
- (void)adLoaderWebViewReturn:(DRAgentLoader *)adLoader;

/*!
 @brief storekit中点击完成返回 注:(没有落地页，直接跳转storeVC，从storeVC返回广告控制器页面)
 @param adLoader adLoader
 */
- (void)adLoaderStoreProductViewControllerReturn:(DRAgentLoader *)adLoader;

@end

