//
//  DRAgentSplash.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/1/23.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DRAgentSplashAdDelegate.h"

@interface DRAgentSplash : NSObject

@property (nonatomic, weak, nullable) id <DRAgentSplashAdDelegate> delegate;

/*!
 @brief      显示倒计时按钮
 @discussion 默认值为YES
 */
@property (nonatomic, assign) BOOL showSplashscreenAdvertCountdown __deprecated_msg("该属性已经过期");

/*!
 @brief      当开屏广告为视频时，是否播放声音
 @discussion 默认值为YES，播放音频
 */
@property (nonatomic, assign) BOOL muted;

/*!
 @brief 尺寸
 */
@property (nonatomic, assign) CGRect splashFrame;

/**
 @brief 拉取广告超时时间，默认为3秒  [1 ~ +∞]  如需设置最好设置3秒以上提高广告展示几率
 @discussion 拉取广告超时时间，开发者调用loadSplashRequest方法以后会立即展示启动页图片，然后在该超时时间内，如果广告拉 取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
 */
@property (nonatomic, assign) NSTimeInterval fetchDelay;

/*!
 @brief 初始化开屏广告类
 @param splashFrame 开屏广告尺寸
 @return 开屏广告类
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)splashFrame;

/*!
 @brief 初始化开屏广告类
 @param splashFrame 开屏广告尺寸
 @param delegate 代理
 @return 开屏广告类
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)splashFrame delegate:(id _Nullable)delegate NS_DESIGNATED_INITIALIZER;
- (instancetype _Nonnull)init NS_UNAVAILABLE;

/*!
 @brief 加载开屏广告
 */
- (void)loadSplashRequest;

@end
