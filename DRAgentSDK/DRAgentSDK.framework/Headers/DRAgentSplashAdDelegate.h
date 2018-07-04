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

#pragma mark *** dataSource ***

/*!
 @brief 开屏广告子视图
 @discussion 实现此代理方法,这些视图将会被自动添加在广告视图上,frame相对于window
 @param agentSplash agentSplash
 @return 子视图的数组
 */
- (NSArray <UIView *>*_Nonnull)adSplashSubViews:(DRAgentSplash *_Nonnull)agentSplash;

/**
 @brief 开屏广告启动背景，若启动图不是在launch image里面添加的请设置启动背景防止露白
 @discussion 可以设置开屏图片来作为开屏加载时的默认图片
 @param agentSplash agentSplash
 @return image
 */
- (UIImage *_Nonnull)adSplashbackgroundImage:(DRAgentSplash *_Nonnull)agentSplash;

#pragma mark *** 数据 ***

/*!
 @brief 开屏广告数据加载缓存成功
 @param agentSplash agentSplash
 @param adverType 广告类型
 */
- (void)adSplashDidFinishLoading:(DRAgentSplash *_Nonnull)agentSplash adverType:(IAdNativeType)adverType;

/*!    
 @brief 开屏广告数据加载缓存失败
 @param agentSplash agentSplash
 @param error 错误error
 */
- (void)adSplash:(DRAgentSplash *_Nonnull)agentSplash didFailToReceiveAdWithError:(NSError *_Nonnull)error;

#pragma mark *** 展示 点击 ***

/*!
 @brief 开屏广告展示
 @param agentSplash agentSplash
 @param adverType 广告类型
 */
- (void)adSplashshowed:(DRAgentSplash *_Nonnull)agentSplash adverType:(IAdDataType)adverType __deprecated_msg("代理方法过期，请用adSplashShowed:(DRAgentSplash *_Nonnull)agentSplash adverType:(IAdDataType)adverType didFailToReceiveAdWithError:(NSError *_Nonnull)error代替");

/*!
 @brief 开屏广告展示 (成功或者失败)
 @param agentSplash agentSplash
 @param adverType 广告类型
 @param error 错误error
 */
- (void)adSplashShowed:(DRAgentSplash *_Nonnull)agentSplash adverType:(IAdNativeType)adverType didFailToReceiveAdWithError:(NSError *_Nullable)error;

/**!
 @brief 开屏广告点击
 @param agentSplash agentSplash
 @param adverType 广告类型
 */
- (void)adSplashDidClick:(DRAgentSplash *_Nonnull)agentSplash adverType:(IAdNativeType)adverType;

#pragma mark *** 返回 回调 ***

/*!
 @brief 广告视图消失 (返回主控制器)
 @param agentSplash agentSplash
 */
- (void)adSplashscreenDismiss:(DRAgentSplash *_Nonnull)agentSplash;

/*!
 @brief webView点击返回 注:(有落地页，跳入webView，从webView返回广告控制器页面)
 @param agentSplash agentSplash
 */
- (void)adSplashWebViewReturn:(DRAgentSplash *_Nonnull)agentSplash;

/*!
 @brief storekit中点击完成返回 注:(没有落地页，直接跳转storeVC，从storeVC返回广告控制器页面)
 @param agentSplash agentSplash
 */
- (void)adSplashStoreProductViewControllerReturn:(DRAgentSplash *_Nonnull)agentSplash __deprecated_msg("代理方法过期，产品升级方法已无效");

#pragma clang diagnostic pop

@end
