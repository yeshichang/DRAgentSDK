//
//  DRAgentMessageFlowAdDelegate.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/1/22.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DRAgentMessageFlowView;
@protocol DRAgentMessageFlowAdDelegate <NSObject>

@optional

#pragma mark *** 点击 ***

/*!
 @brief 图文广告点击
 @param messageFlowView messageFlowView
 @param adverType 广告类型
 */
- (void)adMessageFlowDidClick:(DRAgentMessageFlowView *)messageFlowView adverType:(IAdDataType)adverType;

/*!
 @brief webView点击返回 注:(有落地页，跳入webView，从webView返回广告控制器页面)
 @param messageFlowView messageFlowView
 */
- (void)adMessageFlowWebViewReturn:(DRAgentMessageFlowView *)messageFlowView;

/*!
 @brief storekit中点击完成返回 注:(没有落地页，直接跳转storeVC，从storeVC返回广告控制器页面)
 @param messageFlowView messageFlowView
 */
- (void)adMessageFlowStoreProductViewControllerReturn:(DRAgentMessageFlowView *)messageFlowView;

@end
