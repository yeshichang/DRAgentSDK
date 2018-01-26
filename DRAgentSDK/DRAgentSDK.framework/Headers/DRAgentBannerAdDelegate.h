//
//  DRAgentBannerAdDelegate.h
//  DRAgentSDK
//
//  Created by mac on 2018/1/22.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DRAgentBannerView;
@protocol DRAgentBannerAdDelegate <NSObject>

@required

#pragma mark *** 数据 ***
/**
 Banner广告数据加载成功
 
 @param bannerView bannerView
 @param adverType 广告类型
 */
- (void)adBannerDidFinishLoading:(DRAgentBannerView *)bannerView adverType:(IAdDataType)adverType;

/**
 Banner广告数据加载失败
 
 @param bannerView bannerView
 @param error 错误error
 */
- (void)adBanner:(DRAgentBannerView *)bannerView didFailToReceiveAdWithError:(NSError *)error;

@optional

#pragma mark *** 点击 ***
/**
 Banner广告点击

 @param bannerView bannerView
 @param adverType 广告类型
 */
- (void)adBannerDidClick:(DRAgentBannerView *)bannerView adverType:(IAdDataType)adverType;

/**
 Banner广告关闭按钮被点击

 @param bannerView bannerView
 */
- (void)adBannerDidClickCloseButton:(DRAgentBannerView *)bannerView;

/**
 webView点击返回 (从webView返回广告控制器页面)

 @param bannerView bannerView
 */
- (void)adBannerWebViewReturn:(DRAgentBannerView *)bannerView;

@end
