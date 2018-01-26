//
//  DRAgentBannerView.h
//  Test_DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DRAgentEnumHeader.h"
#import "DRAgentBannerAdDelegate.h"

@interface DRAgentBannerView : UIView

#pragma mark *** API ***

/**
 关闭按钮是否展示 默认为YES展示
 */
@property (nonatomic,assign) BOOL  isShowCloseButton;

/**
 Banner 代理
 */
@property (nonatomic ,weak) id <DRAgentBannerAdDelegate> delegate;

/**
 初始化BannerView
 
 @param frame               banner尺寸frame
 @param adDataType          banner广告类型 (横幅广告  小横幅广告)
 @return                    该类BannerView
 */
- (instancetype)initWithFrame:(CGRect)frame AdDataType:(IAdDataType)adDataType;

/**
 加载Banner数据
 */
- (void)loadBannerRequest;

/**
 通过banner宽度获取其的高度
 
 @param adDataType          banner广告类型 (横幅广告  小横幅广告)
 @param width               banner宽度 ->注意:一定要和初始化宽度保持一致
 @return                    banner高度
 */
+ (CGFloat)getBannerViewHeightWithType:(IAdDataType)adDataType
                                 width:(CGFloat)width;


#pragma mark *** 定时器轮播使用 ***

/*
 *    使用Banner广告的轮播效果要注意几点：
 *    在视图显示成功的时候开启定时器
 *    页面消失(在内存中销毁，push modal dealloc等)一定要关闭定时器，目的:
 * 1、关闭定时器,以防8秒每次请求数据
 * 2、再次进入重新加载bannerView 打开定时器
 * 3、避免内存泄漏
 */

/**
 打开定时器
 */
- (void)resumeTimer;

/**
 关闭定时器
 */
- (void)cancelTimer;

@end
