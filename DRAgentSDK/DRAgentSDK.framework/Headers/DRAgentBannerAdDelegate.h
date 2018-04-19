//
//  DRAgentBannerAdDelegate.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/1/22.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DRAgentBannerView;
@protocol DRAgentBannerAdDelegate <NSObject>

@required

#pragma mark *** 数据 ***

/*!
 @brief Banner广告数据加载成功
 @param bannerView bannerView
 @param adverType 广告类型
 */
- (void)adBannerDidFinishLoading:(DRAgentBannerView *_Nonnull)bannerView adverType:(IAdDataType)adverType;

/*!
 @brief Banner广告数据加载失败
 @param bannerView bannerView
 @param error 错误error
 */
- (void)adBanner:(DRAgentBannerView *_Nonnull)bannerView didFailToReceiveAdWithError:(NSError *_Nonnull)error;

@optional

#pragma mark *** 点击 ***

/*!
 @brief Banner广告点击
 @param bannerView bannerView
 @param adverType 广告类型
 */
- (void)adBannerDidClick:(DRAgentBannerView *_Nonnull)bannerView adverType:(IAdDataType)adverType;

/*!
 @brief Banner广告关闭按钮被点击
 @param bannerView bannerView
 */
- (void)adBannerDidClickCloseButton:(DRAgentBannerView *_Nonnull)bannerView;

/*!
 @brief webView点击返回 注:(有落地页，跳入webView，从webView返回广告控制器页面)
 @param bannerView bannerView
 */
- (void)adBannerWebViewReturn:(DRAgentBannerView *_Nonnull)bannerView;

/*!
 @brief storekit中点击完成返回 注:(没有落地页，直接跳转storeVC，从storeVC返回广告控制器页面)
 @param bannerView bannerView
 */
- (void)adBannerStoreProductViewControllerReturn:(DRAgentBannerView *_Nonnull)bannerView;

@end
