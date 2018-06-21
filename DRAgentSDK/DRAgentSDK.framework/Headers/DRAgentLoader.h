//
//  DRAgentLoader.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/1/22.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DRAgentEnumHeader.h"
#import "DRAgentLoaderAdDelegate.h"

@class DRAgentAdvertDataModel;

/**
 原生广告请求类
 */
@interface DRAgentLoader : NSObject

/*!
 @brief 加载数据类代理
 */
@property (nonatomic, weak, nullable) id <DRAgentLoaderAdDelegate> delegate;

/*!
 @brief 初始化加载数据类
 @param advertType 广告类型
 @return 加载数据类
 */
- (instancetype _Nullable)initWithIAdDataType:(IAdDataType)advertType;

/*!
 @brief 初始化加载数据类
 @param advertType 广告类型
 @param delegate 代理
 @return 加载数据类
 */
- (instancetype _Nullable)initWithIAdDataType:(IAdDataType)advertType delegate:(id _Nullable)delegate;

/*!
 @brief 获取广告数据(原生广告)
 */
- (void)loadNativeRequest;

/*!
 @brief  广告点击调用方法
 @discussion 当用户点击广告时，开发者需调用本方法，系统会弹出内嵌浏览器、或AppStore展现广告目标页面
 @param dataModel 用户点击的广告数据对象
 */
- (void)clickNativeAd:(id _Nonnull)dataModel;

/*!
 @brief  跳入网页视图
 @param  advertDataModel  广告数据model
 @param  index 索引(除此信息流三小图<IAdDataTypeMessageFlowThreeImages>以外,默认传入0)
 @discussion 三小图广告传入点击三小图点击哪张图片（绑定图片tag值，0  1  2）
 */
- (void)pushDRAgentWebView:(DRAgentAdvertDataModel *_Nonnull)advertDataModel
                 withIndex:(NSInteger)index __deprecated_msg("方法过期，请用clickNativeAd:(DRAgentAdvertDataModel *_Nonnull)advertDataModel代替");

@end

// ************************************ 华丽的分割线 ********************************** //

/**
 激励视频广告原生广告请求类
 */
@interface DRAgentExcitingVideoLoader: DRAgentLoader

/**
 DRAgentExcitingVideoLoaderAdDelegate
 */
@property (nonatomic, weak) id <DRAgentExcitingVideoLoaderAdDelegate>videoDelegate;

/*!
 @brief 初始化激励视频广告加载类
 @param videoDelegate videoDelegate
 @return 加载类
 */
- (instancetype _Nullable)initWithDelegate:(id <DRAgentExcitingVideoLoaderAdDelegate>_Nullable)videoDelegate;

/*!
 @brief 获取激励视频广告数据(原生广告)
 */
- (void)loadNativeExcitingVideoRequest;

/*!
 @brief      广告数据渲染完毕即将展示时调用方法
 @discussion [必选]广告数据渲染完毕，即将展示时需调用本方法。
 @param dataModel       广告渲染的数据对象
 @param view            渲染出的广告结果页面
 */
- (void)attachNativeExcitingVideoAd:(id _Nonnull)dataModel toView:(UIView *)view;


#pragma mark - NS_UNAVAILABLE
- (instancetype)initWithIAdDataType:(IAdDataType)advertType delegate:(id)delegate NS_UNAVAILABLE;
- (instancetype)initWithIAdDataType:(IAdDataType)advertType NS_UNAVAILABLE;
- (void)loadNativeRequest NS_UNAVAILABLE;

@end
