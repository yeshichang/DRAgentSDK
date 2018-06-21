//
//  DRAgentAdvertView.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/4/12.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DRAgentEnumHeader.h"
#import "DRAgentMessageAdDelegate.h"

@class DRAgentAdvertDataModel;

/*!
 *  @brief 信息流类型广告的核心类，所有信息流类型广告继承于该类
 *  @discussion 使用时不要直接使用该类，请使用对应信息流广告类型的类
 */
@interface DRAgentMessageView : UIView

#pragma mark *** API ***

/*!
 @brief MessageThreeImages 代理
 */
@property (nonatomic, weak, nullable) id <DRAgentMessageAdDelegate> delegate;

/*!
 @brief  广告数据model
 */
@property (nonatomic, strong, nonnull) DRAgentAdvertDataModel *advertDataModel;

/*!
 @brief 使用广告的类型
 @discussion 设置SDK已封装好的View(threeMessageView messageFlowView)
 */
@property (nonatomic, assign) IAdDataType messageViewType;

/**
 @brief 初始化
 @discussion 默认初始化为(messageThreeImageType)，使用该初始化方法初始化的是信息流三小图
 @param frame frame
 @return 广告View
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame;

/**
 @brief 初始化
 @param frame frame
 @param messageViewType SDK已封装好的View(threeMessageView messageFlowView)
 @return 广告View
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame
                       messageViewType:(IAdDataType)messageViewType;

/**
 @brief 初始化

 @param frame frame
 @param messageViewType SDK已封装好的View(threeMessageView messageFlowView)
 @param delegate delegate
 @return 广告View
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame
                       messageViewType:(IAdDataType)messageViewType
                              delegate:(id _Nullable)delegate NS_DESIGNATED_INITIALIZER;
- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithCoder:(NSCoder *_Nonnull)aDecoder NS_UNAVAILABLE;

/*!
 @brief 信息流小图文大图文三小图自身高度
 @param messageViewType 广告类型 (信息流大图文或者信息流小图文或者三小图)
 @param width 自身宽度  ->注意:一定要和初始化宽度保持一致
 @return 返回高度
 */
+ (CGFloat)getMessageViewHeightWithType:(IAdDataType)messageViewType
                                  width:(CGFloat)width;

@end

// ************************************ 华丽的分割线 ********************************** //

/*!
 *  @brief 信息流三小图广告类
 */
@interface DRAgentMessageThreeImagesView : DRAgentMessageView

/*!
 @brief MessageThreeImages 代理
 */
@property (nonatomic, weak, nullable) id <DRAgentMessageThreeImagesAdDelegate> delegate;

/**
 @brief             初始化
 @param frame       三小图位置尺寸
 @param delegate    代理
 @return            三小图广告View
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame delegate:(id _Nullable)delegate __deprecated_msg("方法过期，请用initWithFrame:(CGRect)frame messageViewType:(IAdDataType)messageViewType delegate:(id _Nullable)delegate代替");

/*!
 @brief  信息流小图自身高度
 @param  width  宽度 ->注意:一定要和初始化宽度保持一致
 */
+ (CGFloat)getMessageThreeImagesViewHeight:(CGFloat)width __deprecated_msg("方法过期，请用getMessageViewHeightWithType:(IAdDataType)messageViewType width:(CGFloat)width代替");

@end

// ************************************ 华丽的分割线 ********************************** //

/*!
 *  @brief 信息流大小图文广告类
 */
@interface DRAgentMessageFlowView : DRAgentMessageView

/*!
 @brief MessageFlow 代理
 */
@property (nonatomic, weak, nullable) id <DRAgentMessageFlowAdDelegate> delegate;

/*!
 @brief 信息流大小图文的类型
 @discussion 必须传入(信息流大图文或者信息流小图文)
 */
@property (nonatomic, assign) IAdDataType messageFlowViewType __deprecated_msg("属性过期，请用messageViewType代替");

/*!
 @brief  初始化
 @param  messageFlowViewType  信息流View类型 (信息流大图文或者信息流小图文)
 @return 图文广告View
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame
                   messageFlowViewType:(IAdDataType)messageFlowViewType __deprecated_msg("方法过期，请用initWithFrame:(CGRect)frame messageViewType:(IAdDataType)messageViewType代替");

/*!
 @brief  初始化
 @param  messageFlowViewType  信息流View类型 (信息流大图文或者信息流小图文)
 @param  delegate             代理
 @return 图文广告View
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame
                   messageFlowViewType:(IAdDataType)messageFlowViewType
                              delegate:(id _Nullable)delegate __deprecated_msg("方法过期，请用initWithFrame:(CGRect)frame messageViewType:(IAdDataType)messageViewType delegate:(id _Nullable)delegate代替");

/*!
 @brief 信息流小图文大图文自身高度
 @param adDataType 广告类型 (信息流大图文或者信息流小图文)
 @param width 自身宽度  ->注意:一定要和初始化宽度保持一致
 @return 返回高度
 */
+ (CGFloat)getMessageFlowViewHeightWithType:(IAdDataType)adDataType
                                      width:(CGFloat)width __deprecated_msg("方法过期，请用getMessageViewHeightWithType:(IAdDataType)messageViewType width:(CGFloat)width代替");

@end
