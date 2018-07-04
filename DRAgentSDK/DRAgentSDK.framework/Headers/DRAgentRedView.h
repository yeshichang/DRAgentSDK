//
//  DRAgentRedView.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/4/9.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DRAgentRedAdDelegate.h"

/*!
 *  @brief 红包类型广告的核心类，所有红包类型广告继承于该类
 *  @discussion 使用时不要直接使用该类，请使用对应红包广告类型的类
 */
@interface DRAgentRedView : UIView

/// DRAgentRedView 代理
@property (nonatomic, weak, nullable) id <DRAgentRedAdDelegate> delegate;

/**
 @brief 初始化红包View
 @param frame frame
 @param delegate 代理
 @return 该类红包View
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame delegate:(id _Nullable)delegate NS_DESIGNATED_INITIALIZER;
- (instancetype _Nonnull)initWithCoder:(NSCoder *_Nonnull)aDecoder NS_UNAVAILABLE;

@end

// ************************************ 华丽的分割线 ********************************** //

/*!
 *  @brief 红包广告类
 */
@interface DRAgentRedEnvelopeView : DRAgentRedView

/// RedEnvelope 代理
@property (nonatomic, weak, nullable) id <DRAgentRedEnvelopeAdDelegate> delegate;

/// 动画 默认:开启YES
@property (nonatomic, assign) BOOL isAnimation;

/// 关闭按钮 默认:展示YES
@property (nonatomic, assign) BOOL isShowCloseButton;

/*!
 @brief         关闭按钮字体颜色 默认:[UIColor grayColor]
 @discussion    默认:[UIColor grayColor]
 */
@property (nonatomic, strong, nonnull) UIColor *closeButtonTitleColor;

/*!
 @brief         关闭按钮字体大小
 @discussion    默认:[UIFont systemFontOfSize:13]
 */
@property (nonatomic, strong, nonnull) UIFont *closeButtonTitleFont;


@end

// ************************************ 华丽的分割线 ********************************** //

/*!
 *  @brief 红包视频广告类
 */
@interface DRAgentRedVideoView : DRAgentRedView

@property (nonatomic, weak, nullable) id <DRAgentRedVideoAdDelegate> delegate;

/*!
 * @brief  切换红包标识icon图标
 * @discussion  可根据需求设置时间段内控制更换icon图标(icon更换为随机)
 */
- (void)replaceRedVideoViewImage;

/*!
 * @brief  手动调起视频红包按钮进入视频广告界面
 * @discussion  在需求界面可以通过其他事件去调起点击视频红包 加载 并弹出视频界面 (和点击红包按钮为同一事件)
 */
- (void)clickRedVideoViewAction;

@end



