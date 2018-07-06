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

/*!
 @brief 关闭按钮是否展示 默认为YES展示
 */
@property (nonatomic, assign) BOOL isShowCloseButton __deprecated_msg("属性过期");

/*!
 @brief Banner 代理
 */
@property (nonatomic, weak, nullable) id <DRAgentBannerAdDelegate> delegate;

/*!
 @brief Banner的类型
 */
@property (nonatomic, assign) IAdBannerType bannerViewType;

/*!
 @brief 初始化BannerView
 @param frame               banner尺寸frame
 @param adDataType          banner广告类型
 @return                    该类BannerView
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame
                            AdDataType:(IAdBannerType)adDataType __deprecated_msg("方法过期，请用initWithFrame:(CGRect)frame bannerViewType:(IAdDataType)bannerViewType代替");

/*!
 @brief 初始化BannerView
 @param frame               banner尺寸frame
 @param bannerViewType      banner广告类型
 @return                    该类BannerView
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame
                        bannerViewType:(IAdBannerType)bannerViewType;

/*!
 @brief 初始化BannerView
 @param frame               banner尺寸frame
 @param bannerViewType      banner广告类型
 @param delegate            代理
 @return                    该类BannerView
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame
                        bannerViewType:(IAdBannerType)bannerViewType
                              delegate:(id _Nullable)delegate NS_DESIGNATED_INITIALIZER;
- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithCoder:(NSCoder *_Nonnull)aDecoder NS_UNAVAILABLE;

/*!
 @brief 加载Banner数据
 */
- (void)loadBannerRequest;

/*!
 @brief 通过banner宽度获取其的高度
 @param adDataType          banner广告类型 
 @param width               banner宽度 ->注意:一定要和初始化宽度保持一致
 @return                    banner高度
 */
+ (CGFloat)getBannerViewHeightWithType:(IAdBannerType)adDataType
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

/*!
 @brief 打开定时器
 */
- (void)resumeTimer __deprecated_msg("方法过期，取消轮播功能");

/*!
 @brief 关闭定时器
 */
- (void)cancelTimer __deprecated_msg("方法过期，取消轮播功能");

@end
