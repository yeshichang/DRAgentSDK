//
//  DRAgent.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DRAgent : NSObject

#pragma mark *** DRAgentSDK 注册 ***

/*!
 @brief  初始化单例
 */
+ (instancetype _Nonnull)sharedInstance;

/*!
 @brief        注册AppKey，应用启动时需要先注册AppKey
 @param appkey 应用程序appkey，需要向开发者后台申请
 */
- (void)registerApp:(NSString *_Nonnull)appkey;


#pragma mark *** DRAgentSDK UI配置 ***

/*!
 @brief      当前视图控制器导航
 @discussion 谨用:如果rootViewController(根视图控制器)父类不是UITabbarController或UINavigationController,设置当前显示广告界面的视图控制器导航
     [DRAgent sharedInstance].pushWebViewNavigationController = self.navigationController
 */
@property (nonatomic, strong, nullable) UINavigationController *pushWebViewNavigationController;

/*!
 @brief      SDK中全局的网页视图减去的高度
 @discussion 默认为0
 */
@property (nonatomic, assign) CGFloat webViewSubtractHeight;

/*!
 @brief      SDK中全局的导航背景色颜色
 @discussion 默认为自身APP导航颜色   谨用: 从页面返回后会修改APP导航颜色，返回后需要修改本身导航颜色
 */
@property (nonatomic, strong, nonnull) UIColor *globalNavigationBarTintColor;

/*!
 @brief      SDK中全局的导航title字体颜色
 @discussion 默认为[UIColor whiteColor]
 */
@property (nonatomic, strong, nonnull) UIColor *globalNavigationBarTitleColor __deprecated_msg("属性过期，请用globalNavigationBarTitleTextAttributes代替，完成更多想要效果");

/*!
 @brief      SDK中全局的导航title富文本属性配置
 @discussion 默认为自身APP导航title
 */
@property (nonatomic, copy, nonnull) NSDictionary<NSAttributedStringKey, id> *globalNavigationBarTitleTextAttributes;

/*!
 @brief      SDK中全局的网页进度条颜色
 @discussion 默认为[UIColor darkGrayColor]
 */
@property (nonatomic, strong, nonnull) UIColor *globalProgressTintColor;


#pragma mark *** DRAgentSDK 功能设置 ***

/*!
 @brief      SDK中开启定位功能，必须设置在注册AppKey代码上面
 @discussion 默认为开启，根据自己应用情况设置定位功能(注意：若关闭定位无法使用对地区限制投放功能)
 */
@property (nonatomic, assign) BOOL openLocation;

/*!
 @brief     获取SDK版本号
 @return    SDK版本号
 */
+ (nonnull NSString *)getDRAgentSDK_version;

/*!
 @brief       设置应用的日志输出的开关（默认关闭）
 @param value 是否开启标志，注意App发布时请关闭日志输出
 */
+ (void)setLogEnabled:(BOOL)value;

/// 当应用在收到内存警告时可对缓存进行清理,或者应用清理disk内存时调用下列方法
/*!
 @brief 清除DRAgentSDK图片内存缓存
 */
- (void)clearDRAgentSDKMemory;

/*!
 @brief 清除DRAgentSDK图片磁盘缓存
 */
- (void)clearDRAgentSDKDisk;

@end
