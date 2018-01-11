//
//  DRAgentBannerView.h
//  Test_DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DRAgentEnumHeader.h"

@interface DRAgentBannerView : UIView

/* 回调结果 */
@property (nonatomic,copy) void(^bannerViewAdvertResultCallback)(IAdSuccessBack successBack,NSString * result);

/* 关闭回调 */
@property (nonatomic,copy) void(^bannerViewAdvertCloseClickCallback)(void);

/* 关闭按钮是否展示 默认为YES展示*/
@property (nonatomic,assign) BOOL  isShowCloseButton;

/**
 */
-(instancetype)initWithFrame:(CGRect)frame AdDataType:(IAdDataType)adDataType;

/* 打开定时器 */
-(void)resumeTimer;

/* 关闭定时器 */
-(void)cancelTimer;

@end
