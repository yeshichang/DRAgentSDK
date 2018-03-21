//
//  DRAgentSplashAdDelegate.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/1/23.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DRAgentEnumHeader.h"

@class DRAgentSplash;
@protocol DRAgentSplashAdDelegate <NSObject>

@optional

#pragma mark *** 数据 ***

/*!
 @brief 开屏广告数据加载缓存成功
 @param agentSplash agentSplash
 @param adverType 广告类型
 */
- (void)adSplashDidFinishLoading:(DRAgentSplash *)agentSplash adverType:(IAdDataType)adverType;

/*!
 @brief 开屏广告数据加载缓存失败
 @param agentSplash agentSplash
 @param error 错误error
 */
- (void)adSplash:(DRAgentSplash *)agentSplash didFailToReceiveAdWithError:(NSError *)error;

#pragma mark *** 展示 点击 ***

/*!
 @brief 开屏广告展示
 @param agentSplash agentSplash
 @param adverType 广告类型
 */
- (void)adSplashshowed:(DRAgentSplash *)agentSplash adverType:(IAdDataType)adverType;

/**!
 @brief 开屏广告点击
 @param agentSplash agentSplash
 @param adverType 广告类型
 */
- (void)adSplashDidClick:(DRAgentSplash *)agentSplash adverType:(IAdDataType)adverType;

#pragma mark *** 返回 回调 ***

/*!
 @brief 广告视图消失 (返回主控制器)
 @param agentSplash agentSplash
 */
- (void)adSplashscreenDismiss:(DRAgentSplash *)agentSplash;

/*!
 @brief webView点击返回 注:(有落地页，跳入webView，从webView返回广告控制器页面)
 @param agentSplash agentSplash
 */
- (void)adSplashWebViewReturn:(DRAgentSplash *)agentSplash;

/*!
 @brief storekit中点击完成返回 注:(没有落地页，直接跳转storeVC，从storeVC返回广告控制器页面)
 @param agentSplash agentSplash
 */
- (void)adSplashStoreProductViewControllerReturn:(DRAgentSplash *)agentSplash;

@end
