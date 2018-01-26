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

/**
 MessageThreeImages 代理
 */
@property (nonatomic ,weak) id <DRAgentMessageThreeImagesAdDelegate> delegate;

/**
 @brief  初始化
 */
- (instancetype)initWithFrame:(CGRect)frame;

/**
 @brief  广告数据model
 */
@property (nonatomic, strong) DRAgentAdvertDataModel * advertDataModel;

/**
 @brief  信息流小图自身高度
 @param  width  宽度 ->注意:一定要和初始化宽度保持一致
 */
+ (CGFloat)getMessageThreeImagesViewHeight:(CGFloat)width;

@end
