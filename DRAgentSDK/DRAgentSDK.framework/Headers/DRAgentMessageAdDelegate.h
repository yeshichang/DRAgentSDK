//
//  DRAgentMessageAdDelegate.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/4/17.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DRAgentMessageView;
@class DRAgentMessageThreeImagesView;
@class DRAgentMessageFlowView;
@protocol DRAgentMessageAdDelegate <NSObject>

@optional

#pragma mark *** 点击 ***

/*!
 @brief 信息流广告点击
 @param messageView messageView
 @param adverType 广告类型
 */
- (void)adMessageDidClick:(DRAgentMessageView *_Nonnull)messageView adverType:(MESSAGEVIEWTYPE)adverType;

/*!
 @brief webView点击返回 注:(有落地页，跳入webView，从webView返回广告控制器页面)
 @param messageView messageView
 */
- (void)adMessageWebViewReturn:(DRAgentMessageView *_Nonnull)messageView;

/*!
 @brief storekit中点击完成返回 注:(没有落地页，直接跳转storeVC，从storeVC返回广告控制器页面)
 @param messageView messageView
 */
- (void)adMessageStoreProductViewControllerReturn:(DRAgentMessageView *_Nonnull)messageView __deprecated_msg("代理方法过期，产品升级方法已无效");

@end

@protocol DRAgentMessageThreeImagesAdDelegate <DRAgentMessageAdDelegate>

@optional

#pragma mark *** 点击 ***

/*!
 @brief 三小图广告点击
 @param messageThreeImagesView messageThreeImagesView
 @param adverType 广告类型
 */
- (void)adMessageThreeImagesDidClick:(DRAgentMessageThreeImagesView *_Nonnull)messageThreeImagesView
                           adverType:(MESSAGEVIEWTYPE)adverType __deprecated_msg("代理方法过期，请用adMessageDidClick:(DRAgentMessageView *_Nonnull)messageView adverType:(IAdDataType)adverType代替");

/*!
 @brief webView点击返回 注:(有落地页，跳入webView，从webView返回广告控制器页面)
 @param messageThreeImagesView messageThreeImagesView
 */
- (void)adMessageThreeImagesWebViewReturn:(DRAgentMessageThreeImagesView *_Nonnull)messageThreeImagesView __deprecated_msg("代理方法过期，请用adMessageWebViewReturn:(DRAgentMessageView *_Nonnull)messageView代替");

/*!
 @brief storekit中点击完成返回 注:(没有落地页，直接跳转storeVC，从storeVC返回广告控制器页面)
 @param messageThreeImagesView messageThreeImagesView
 */
- (void)adMessageThreeImagesStoreProductViewControllerReturn:(DRAgentMessageThreeImagesView *_Nonnull)messageThreeImagesView __deprecated_msg("代理方法过期，请用adMessageStoreProductViewControllerReturn:(DRAgentMessageView *_Nonnull)messageView代替");

@end

@protocol DRAgentMessageFlowAdDelegate <DRAgentMessageAdDelegate>

@optional

#pragma mark *** 点击 ***

/*!
 @brief 图文广告点击
 @param messageFlowView messageFlowView
 @param adverType 广告类型
 */
- (void)adMessageFlowDidClick:(DRAgentMessageFlowView *_Nonnull)messageFlowView adverType:(MESSAGEVIEWTYPE)adverType __deprecated_msg("代理方法过期，请用adMessageDidClick:(DRAgentMessageView *_Nonnull)messageView adverType:(IAdDataType)adverType");

/*!
 @brief webView点击返回 注:(有落地页，跳入webView，从webView返回广告控制器页面)
 @param messageFlowView messageFlowView
 */
- (void)adMessageFlowWebViewReturn:(DRAgentMessageFlowView *_Nonnull)messageFlowView __deprecated_msg("代理方法过期，请用adMessageWebViewReturn:(DRAgentMessageView *_Nonnull)messageView代替");

/*!
 @brief storekit中点击完成返回 注:(没有落地页，直接跳转storeVC，从storeVC返回广告控制器页面)
 @param messageFlowView messageFlowView
 */
- (void)adMessageFlowStoreProductViewControllerReturn:(DRAgentMessageFlowView *_Nonnull)messageFlowView __deprecated_msg("代理方法过期，请用adMessageStoreProductViewControllerReturn:(DRAgentMessageView *_Nonnull)messageView代替");

@end
