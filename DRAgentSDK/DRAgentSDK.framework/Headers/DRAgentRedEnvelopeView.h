//
//  DRAgentRedEnvelopeView.h
//  DRAgentSDK
//
//  Created by ShaoYueZhang on 2017/11/7.
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//
// 

#import <UIKit/UIKit.h>
#import "DRAgentEnumHeader.h"

@interface DRAgentRedEnvelopeView : UIView

/* 关闭按钮 默认:展示YES */
@property (nonatomic,assign)BOOL isShowCloseButton;

/* 动画 默认:开启YES */
@property (nonatomic,assign)BOOL isAnimation;

/* 关闭按钮字体颜色 默认:[UIColor grayColor]  */
@property (nonatomic,strong)UIColor  * closeButtonTitleColor;

/* 关闭按钮字体大小 默认:[UIFont systemFontOfSize:10] */
@property (nonatomic,strong)UIFont  * closeButtonTitleFont;


/* 回调结果 */
@property (nonatomic,copy) void(^redEnvelopeAdvertResultCallback)(IAdSuccessBack successBack,NSString * result);

/* 关闭回调 */
@property (nonatomic ,copy) void(^redEnvelopeAdvertCloseClickCallback)(void);



@end
