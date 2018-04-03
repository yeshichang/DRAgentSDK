//
//  DRAgentMessageThreeImagesView.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DRAgentEnumHeader.h"
#import "DRAgentMessageThreeImagesAdDelegate.h"

@class DRAgentAdvertDataModel;
@interface DRAgentMessageThreeImagesView : UIView

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
- (instancetype _Nonnull)initWithFrame:(CGRect)frame delegate:(id _Nullable)delegate NS_DESIGNATED_INITIALIZER;
- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithCoder:(NSCoder *_Nonnull)aDecoder NS_UNAVAILABLE;

/*!
 @brief  广告数据model
 */
@property (nonatomic, strong, nonnull) DRAgentAdvertDataModel *advertDataModel;

/*!
 @brief  信息流小图自身高度
 @param  width  宽度 ->注意:一定要和初始化宽度保持一致
 */
+ (CGFloat)getMessageThreeImagesViewHeight:(CGFloat)width;

@end
