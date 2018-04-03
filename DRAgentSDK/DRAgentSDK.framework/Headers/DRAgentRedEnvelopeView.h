//
//  DRAgentRedEnvelopeView.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017/11/7.
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//
// 

#import <UIKit/UIKit.h>
#import "DRAgentEnumHeader.h"
#import "DRAgentRedEnvelopeAdDelegate.h"

@interface DRAgentRedEnvelopeView : UIView

/*!
 @brief         RedEnvelope 代理
 */
@property (nonatomic, weak, nullable) id <DRAgentRedEnvelopeAdDelegate> delegate;

/*!
 @brief         关闭按钮
 @discussion    默认:展示YES
 */
@property (nonatomic, assign) BOOL isShowCloseButton;

/*!
 @brief         动画
 @discussion    默认:开启YES
 */
@property (nonatomic, assign) BOOL isAnimation;

/*!
 @brief         关闭按钮字体颜色 默认:[UIColor grayColor]
 @discussion    默认:[UIColor grayColor]
 */
@property (nonatomic, strong, nonnull) UIColor *closeButtonTitleColor;

/*!
 @brief         关闭按钮字体大小
 @discussion    默认:[UIFont systemFontOfSize:10]
 */
@property (nonatomic, strong, nonnull) UIFont *closeButtonTitleFont;

@end
