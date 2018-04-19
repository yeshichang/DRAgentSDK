//
//  DRAgentSDK.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017/9/22.
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#import <UIKit/UIKit.h>

#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_8_0
#error The DRAgentSDK requires a deployment target of iOS 8.0 or later.
#endif

//! Project version number for DRAgentSDK.
FOUNDATION_EXPORT double DRAgentSDKVersionNumber;

//! Project version string for DRAgentSDK.
FOUNDATION_EXPORT const unsigned char DRAgentSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <DRAgentSDK/PublicHeader.h>

/** DRAgentSDK 注册appkey，配置UI ...API */
#import <DRAgentSDK/DRAgent.h>

/** DRAgentSDK 公共配置，返回数据model ...API */
#import <DRAgentSDK/DRAgentEnumHeader.h>
#import <DRAgentSDK/DRAgentAdvertDataModel.h>

/** DRAgentSDK 数据请求类，所有原生广告和信息流广告 获取数据 ...API */
#import <DRAgentSDK/DRAgentLoader.h>
#import <DRAgentSDK/DRAgentLoaderAdDelegate.h>

/** DRAgentSDK 开屏广告 ...API */
#import <DRAgentSDK/DRAgentSplash.h>
#import <DRAgentSDK/DRAgentSplashAdDelegate.h>

/** DRAgentSDK banner横幅广告 ...API */
#import <DRAgentSDK/DRAgentBannerView.h>
#import <DRAgentSDK/DRAgentBannerAdDelegate.h>

/** DRAgentSDK 信息流广告View ...API */
#import <DRAgentSDK/DRAgentMessageView.h>
#import <DRAgentSDK/DRAgentMessageAdDelegate.h>

/** DRAgentSDK 红包广告View ...API */
#import <DRAgentSDK/DRAgentRedView.h>
#import <DRAgentSDK/DRAgentRedAdDelegate.h>


