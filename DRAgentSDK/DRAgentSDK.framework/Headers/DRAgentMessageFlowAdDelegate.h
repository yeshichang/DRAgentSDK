//
//  DRAgentMessageFlowAdDelegate.h
//  DRAgentSDK
//
//  Created by mac on 2018/1/22.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DRAgentMessageFlowView;
@protocol DRAgentMessageFlowAdDelegate <NSObject>

@optional

#pragma mark *** 点击 ***
/**
 图文广告点击
 
 @param messageFlowView messageFlowView
 @param adverType 广告类型
 */
- (void)adMessageFlowDidClick:(DRAgentMessageFlowView *)messageFlowView adverType:(IAdDataType)adverType;

/**
 webView点击返回 (从webView返回广告控制器页面)
 
 @param messageFlowView messageFlowView
 */
- (void)adMessageFlowWebViewReturn:(DRAgentMessageFlowView *)messageFlowView;

@end
