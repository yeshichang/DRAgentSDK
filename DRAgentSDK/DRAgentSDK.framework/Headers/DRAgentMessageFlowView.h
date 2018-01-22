//
//  DRAgentMessageFlowView.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DRAgentEnumHeader.h"

@class DRAgentAdvertDataModel;
@interface DRAgentMessageFlowView : UIView

/**
 @brief  初始化
 @param  messageFlowViewType  信息流View类型
 @param  messageFlowResultCallback 回调结果
 */
- (instancetype)initWithFrame:(CGRect)frame
         messageFlowViewType:(IAdMessageFlowViewType)messageFlowViewType
                 clickResult:(void(^)(IAdSuccessBack successBack,NSString *result))messageFlowResultCallback;

/**
 @brief  广告数据model
 */
@property (nonatomic,strong)DRAgentAdvertDataModel * advertDataModel;


/**
 @brief  信息流小图自身高度
 @param  width  宽度 ->注意:一定要和初始化宽度保持一致
 */
+ (CGFloat)getMessageFlowViewSmallImageHeight:(CGFloat)width;


/**
 @brief  信息流大图自身高度
 @param  width  宽度 ->注意:一定要和初始化宽度保持一致
 */
+ (CGFloat)getMessageFlowViewBigImageHeight:(CGFloat)width;

@end
