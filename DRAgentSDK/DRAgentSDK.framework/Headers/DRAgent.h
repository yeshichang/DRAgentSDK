//
//  DRAgent.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DRAgent : NSObject

/**
 @brief  初始化单例
 */
+ (DRAgent *)sharedInstance;

/**
 @brief  获取SDK版本号
 */
+ (NSString *)getDRAgentSDK_version;

/**
 @brief  设置应用的日志输出的开关（默认关闭）
 @param value 是否开启标志，注意App发布时请关闭日志输出
 */
+ (void)setLogEnabled:(BOOL)value;

/**
 @param appkey 应用程序appkey，需要向开发者后台申请
 */
- (void)registerApp:(NSString *)appkey;


/*!
 @brief      当前视图控制器导航
 @discussion 谨用:如果rootViewController(根视图控制器)父类不是UITabbarController或UINavigationController,必须设置当前显示广告界面的视图控制器导航
     [DRAgent sharedInstance].pushWebViewNavigationController =self.navigationController
 */
@property(nonatomic, strong)UINavigationController * pushWebViewNavigationController;


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
