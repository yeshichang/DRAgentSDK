//
//  DRAgentMessageFlowView.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DRAgentEnumHeader.h"
#import "DRAgentMessageFlowAdDelegate.h"

@class DRAgentAdvertDataModel;
@interface DRAgentMessageFlowView : UIView

/*!
 @brief MessageFlow 代理
 */
@property (nonatomic, weak, nullable) id <DRAgentMessageFlowAdDelegate> delegate;

/*!
 @brief 信息流大小图文的类型
 @discusstion 必须传入(信息流大图文或者信息流小图文)
 */
@property (nonatomic, assign) IAdDataType messageFlowViewType;

/*!
 @brief  初始化
 @param  messageFlowViewType  信息流View类型 (信息流大图文或者信息流小图文)
 @return 图文广告View
 */
- (instancetype _Nonnull)initWithFrame:(CGRect)frame
          messageFlowViewType:(IAdDataType)messageFlowViewType NS_DESIGNATED_INITIALIZER;
- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithCoder:(NSCoder *_Nonnull)aDecoder NS_UNAVAILABLE;

/*!
 @brief  广告数据model
 */
@property (nonatomic, strong, nonnull) DRAgentAdvertDataModel *advertDataModel;

/*!
 @brief 信息流小图文大图文自身高度
 @param adDataType 广告类型 (信息流大图文或者信息流小图文)
 @param width 自身宽度  ->注意:一定要和初始化宽度保持一致
 @return 返回高度
 */
+ (CGFloat)getMessageFlowViewHeightWithType:(IAdDataType)adDataType
                                      width:(CGFloat)width;

@end
