//
//  DRAgentRedEnvelopeAdDelegate.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/1/22.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DRAgentRedEnvelopeView;
@protocol DRAgentRedEnvelopeAdDelegate <NSObject>

@optional
#pragma mark *** 展示 点击 ***

/**
 红包广告展示
 
 @param redEnvelopeView redEnvelopeView
 @param adverType 广告类型
 @param error 错误error
 */
- (void)adRedEnvelopeshowed:(DRAgentRedEnvelopeView *)redEnvelopeView
                  adverType:(IAdDataType)adverType
         receiveAdWithError:(NSError *)error;

/**
 红包广告点击
 
 @param redEnvelopeView redEnvelopeView
 @param adverType 广告类型
 */
- (void)adRedEnvelopeDidClick:(DRAgentRedEnvelopeView *)redEnvelopeView adverType:(IAdDataType)adverType;

/**
 红包广告关闭按钮被点击
 
 @param redEnvelopeView redEnvelopeView
 */
- (void)adRedEnvelopeDidClickCloseButton:(DRAgentRedEnvelopeView *)redEnvelopeView;

/**
 webView点击返回 (从webView返回广告控制器页面)

 @param redEnvelopeView redEnvelopeView
 */
- (void)adRedEnvelopeWebViewReturn:(DRAgentRedEnvelopeView *)redEnvelopeView;

@end
