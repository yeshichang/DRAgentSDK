//
//  DRAgentMessageThreeImagesAdDelegate.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/1/22.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DRAgentMessageThreeImagesView;
@protocol DRAgentMessageThreeImagesAdDelegate <NSObject>

@optional

#pragma mark *** 点击 ***

/*!
 @brief 三小图广告点击
 @param messageThreeImagesView messageThreeImagesView
 @param adverType 广告类型
 */
- (void)adMessageThreeImagesDidClick:(DRAgentMessageThreeImagesView *)messageThreeImagesView
                           adverType:(IAdDataType)adverType;

/*!
 @brief webView点击返回 注:(有落地页，跳入webView，从webView返回广告控制器页面)
 @param messageThreeImagesView messageThreeImagesView
 */
- (void)adMessageThreeImagesWebViewReturn:(DRAgentMessageThreeImagesView *)messageThreeImagesView;

/*!
 @brief storekit中点击完成返回 注:(没有落地页，直接跳转storeVC，从storeVC返回广告控制器页面)
 @param messageThreeImagesView messageThreeImagesView
 */
- (void)adMessageThreeImagesStoreProductViewControllerReturn:(DRAgentMessageThreeImagesView *)messageThreeImagesView;

@end
