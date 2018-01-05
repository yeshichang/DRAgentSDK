//
//  DRAgent.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DRAgentEnumHeader.h"

@class DRAgentBannerView;
@class DRAgentAdvertDataModel;
@interface DRAgent : NSObject

/**
 @brief  初始化单例
 */
+ (DRAgent*)sharedInstance;

/**
 @brief  获取SDK版本号
 */
+ (NSString*)getDRAgentSDK_version;

/**
 @brief  设置应用的日志输出的开关（默认关闭）
 @param value 是否开启标志，注意App发布时请关闭日志输出
 */
+ (void)setLogEnabled:(BOOL)value;


/**
 @param appkey 应用程序appkey，需要向开发者后台申请
 */
- (void)registerApp:(NSString *)appkey;


/**
 @brief  获取广告数据(原生广告)
 @param  advertType   广告类型
 @param  advertDataResultCallback 回调结果
 */
- (void)getDRAgentAdvertData:(IAdDataType)advertType
                     result:(void(^)(DRAgentAdvertDataModel * advertDataModel,IAdSuccessBack successBack,NSString *result))advertDataResultCallback;


/**
 @brief  开屏广告
 @param  advertFrame  广告尺寸大小
 @param  splashscreenAdvertResultCallback 回调结果
 @param  splashscreenRecutnCallback       网页视图返回点击回调
 */
- (void)showSplashscreenAdvertWithFrame:(CGRect)advertFrame
                                result:(void(^)(IAdSuccessBack successBack,NSString * result))splashscreenAdvertResultCallback
                 webViewReturnCallback:(void(^)(void))splashscreenRecutnCallback;

/*!
 @brief      当前视图控制器导航
 @discussion 谨用:如果rootViewController(根视图控制器)父类不是UITabbarController或UINavigationController,必须设置当前显示广告界面的视图控制器导航
     [DRAgent sharedInstance].pushWebViewNavigationController =self.navigationController
 */
@property(nonatomic, strong)UINavigationController * pushWebViewNavigationController;


/*!
 @brief      显示倒计时按钮
 @discussion 默认值为YES
 */
@property(nonatomic, assign)BOOL  showSplashscreenAdvertCountdown;


/**
 通过banner宽度获取其的高度

 @param adDataType 类型
 @param width banner宽度
 @return banner高度
 */
- (CGFloat)getBannerViewHeightWithType:(IAdDataType)adDataType width:(CGFloat)width;

/**
 @brief  横幅(Banner)广告
 @param  adDataType  类型
 @param  rect   尺寸大小
 return  DRAgentBannerView
 */
- (DRAgentBannerView*)showBannerViewWithType:(IAdDataType)adDataType frame:(CGRect)rect;


/**
 @brief  跳入网页视图
 @param  advertDataModel  广告数据model
 @param  index 索引(除此信息流三小图<IAdDataTypeMessageFlowThreeImages>以外,默认传入0)
 */
- (void)pushDRAgentWebView:(DRAgentAdvertDataModel *)advertDataModel
                withIndex:(NSInteger)index;


/*!
 @brief      SDK中全局的网页视图减去的高度
 @discussion 默认为0
 */
@property(nonatomic, assign) CGFloat  webViewSubtractHeight;


/*!
 @brief      SDK中全局的导航背景色颜色
 @discussion 默认为自身APP导航颜色
 */
@property(nonatomic, strong) UIColor * globalNavigationBarTintColor;

/*!
 @brief      SDK中全局的导航title字体颜色
 @discussion 默认为[UIColor whiteColor]
 */
@property(nonatomic, strong) UIColor * globalNavigationBarTitleColor;

@end
