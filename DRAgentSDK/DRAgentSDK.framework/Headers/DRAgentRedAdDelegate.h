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
 @brief 红包被点击，跳转webView
 @param redView redView
 */
- (void)adRedDidClick:(DRAgentRedView *_Nonnull)redView;

@end

// ************************************ 华丽的分割线 ********************************** //

/*!
 *  @brief 红包广告类协议
 */
@protocol DRAgentRedEnvelopeAdDelegate <DRAgentRedAdDelegate>

@optional
#pragma mark *** 展示 点击 ***

/*!
 @brief 红包图片广告关闭按钮被点击
 @param redEnvelopeView redEnvelopeView
 */
- (void)adRedEnvelopeDidClickCloseButton:(DRAgentRedEnvelopeView *_Nonnull)redEnvelopeView;

/*!
 @brief (webView页面里面)红包广告展示     注意: 实在webView页面里面
 @discussion 成功状态：error = nil;  失败状态有error信息
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
 @brief webView点击返回 (从webView返回广告控制器页面)
 @param redEnvelopeView redEnvelopeView
 */
- (void)adRedEnvelopeWebViewReturn:(DRAgentRedEnvelopeView *_Nonnull)redEnvelopeView;

@end

// ************************************ 华丽的分割线 ********************************** //

/*!
 *  @brief 红包视频广告类协议
 */
@protocol DRAgentRedVideoAdDelegate <DRAgentRedAdDelegate>

@optional
#pragma mark *** 数据 ***

/*!
 @brief (在添加视频红包的主界面)视频红包图标加载展示成功或者失败   注意: 是在添加视频红包的主界面
 @discussion 成功状态：error = nil;  失败状态有error信息
 @param redVideoView redVideoView
 @param error 错误error
 */
- (void)adRedVideoImageIconLoadingFinished:(DRAgentRedVideoView *_Nonnull)redVideoView
                         reciveAdWithError:(NSError *_Nullable)error;

/*!
 @brief 视频红包图标加载成功后回调图标标题
 @discussion [可选]广告数据渲染完毕，可自行添加UILabel显示icon标题。
                自定义配置这个标题
 @param iconTitle 图标标题
 */
- (void)adRedVideoImageIconLoadingFinished:(NSString *)iconTitle;

/*!
 @brief 加载视频数据成功或者失败   注意: 是视频数据加载 (当点击红包present 出来视频控制器时 会走该回调)
 @discussion 成功状态：error = nil;  失败状态有error信息
 @param redVideoView redVideoView
 @param error 错误error
 */
- (void)adRedVideoDataLoadingFinished:(DRAgentRedVideoView *)redVideoView
                    reciveAdWithError:(NSError *)error;

#pragma mark *** 展示 点击 ***

/*!
 @brief 视频展示播放 (当播放视频是 会走该回调)
 @param redVideoView redVideoView
 @param currectIndex currectIndex
 */
- (void)adRedVideoShowVideoPlay:(DRAgentRedVideoView *)redVideoView currentIndex:(NSInteger)currectIndex;

/*!
 @brief 视频广告点击下载 (当点击视频中下载按钮 会走该回调)
 @param redVideoView redVideoView
 */
- (void)adRedVideoDidClickDownButton:(DRAgentRedVideoView *)redVideoView;

@end
