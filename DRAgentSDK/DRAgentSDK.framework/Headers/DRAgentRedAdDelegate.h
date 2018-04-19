//
//  DRAgentRedAdDelegate.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/4/10.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DRAgentEnumHeader.h"

@class DRAgentRedView;
@class DRAgentRedEnvelopeView;
@class DRAgentRedVideoView;

/*!
 *  @brief 红包类型广告的核心类协议
 */
@protocol DRAgentRedAdDelegate <NSObject>

@optional

/*!
 @brief 红包广告关闭按钮被点击
 @param redView redView
 */
- (void)adRedDidClickCloseButton:(DRAgentRedView *_Nonnull)redView;

/*!
 @brief 红包被点击，跳转webView
 @param redView redView
 */
- (void)adRedDidClick:(DRAgentRedView *_Nonnull)redView;

/*!
 @brief webView点击返回 (从webView返回广告控制器页面)
 @param redView redView
 */
- (void)adRedWebViewReturn:(DRAgentRedView *_Nonnull)redView;

@end

// ************************************ 华丽的分割线 ********************************** //

/*!
 *  @brief 红包广告类协议
 */
@protocol DRAgentRedEnvelopeAdDelegate <DRAgentRedAdDelegate>

@optional
#pragma mark *** 展示 点击 ***

/*!
 @brief (webView页面里面)红包广告展示     注意: 实在webView页面里面
 @param redEnvelopeView redEnvelopeView
 @param adverType 广告类型
 @param error 错误error
 */
- (void)adRedEnvelopeshowed:(DRAgentRedEnvelopeView *_Nonnull)redEnvelopeView
                  adverType:(IAdDataType)adverType
         receiveAdWithError:(NSError *_Nullable)error;

/*!
 @brief (webView页面里面)红包广告点击     注意: 实在webView页面里面
 @param redEnvelopeView redEnvelopeView
 @param adverType 广告类型
 */
- (void)adRedEnvelopeDidClick:(DRAgentRedEnvelopeView *_Nonnull)redEnvelopeView adverType:(IAdDataType)adverType;

/*!
 @brief 红包广告关闭按钮被点击
 @param redEnvelopeView redEnvelopeView
 */
- (void)adRedEnvelopeDidClickCloseButton:(DRAgentRedEnvelopeView *_Nonnull)redEnvelopeView __deprecated_msg("代理方法过期，请用adRedDidClickCloseButton:(DRAgentRedView *_Nonnull)redView代替");

/*!
 @brief webView点击返回 (从webView返回广告控制器页面)
 @param redEnvelopeView redEnvelopeView
 */
- (void)adRedEnvelopeWebViewReturn:(DRAgentRedEnvelopeView *_Nonnull)redEnvelopeView __deprecated_msg("代理方法过期，请用adRedWebViewReturn:(DRAgentRedView *_Nonnull)redView代替");

@end

// ************************************ 华丽的分割线 ********************************** //

/*!
 *  @brief 红包视频广告类协议
 */
@protocol DRAgentRedVideoAdDelegate <DRAgentRedAdDelegate>

@optional
#pragma mark *** 数据 ***

/*!
 @brief (在添加视频红包的主界面)视频红包加载展示成功或者失败   注意: 是在添加视频红包的主界面
 @param redVideoView redVideoView
 @param error 错误error
 */
- (void)adRedVideoDidFinshedLoading:(DRAgentRedVideoView *_Nonnull)redVideoView
                  reciveAdWithError:(NSError *_Nullable)error;

@end
