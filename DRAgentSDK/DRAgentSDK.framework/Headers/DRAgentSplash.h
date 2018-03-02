//
//  DRAgentSplash.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/1/23.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DRAgentEnumHeader.h"
#import "DRAgentSplashAdDelegate.h"

@interface DRAgentSplash : NSObject

@property (nonatomic, weak, nullable) id <DRAgentSplashAdDelegate> delegate;

/*!
 @brief      显示倒计时按钮
 @discussion 默认值为YES
 */
@property (nonatomic, assign) BOOL showSplashscreenAdvertCountdown;

/**
 尺寸
 */
@property (nonatomic, assign) CGRect splashFrame;

/**
 初始化开屏广告类

 @param splashFrame 开屏广告尺寸
 @return 开屏广告类
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)splashFrame;

/**
 加载开屏广告
 */
- (void)loadSplashRequest;

@end
