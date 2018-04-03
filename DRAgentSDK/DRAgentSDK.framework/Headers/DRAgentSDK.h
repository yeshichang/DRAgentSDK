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

#import <DRAgentSDK/DRAgent.h>

#import <DRAgentSDK/DRAgentEnumHeader.h>
#import <DRAgentSDK/DRAgentAdvertDataModel.h>

#import <DRAgentSDK/DRAgentLoader.h>
#import <DRAgentSDK/DRAgentLoaderAdDelegate.h>

#import <DRAgentSDK/DRAgentSplash.h>
#import <DRAgentSDK/DRAgentSplashAdDelegate.h>

#import <DRAgentSDK/DRAgentBannerView.h>
#import <DRAgentSDK/DRAgentBannerAdDelegate.h>

#import <DRAgentSDK/DRAgentMessageThreeImagesView.h>
#import <DRAgentSDK/DRAgentMessageThreeImagesAdDelegate.h>

#import <DRAgentSDK/DRAgentMessageFlowView.h>
#import <DRAgentSDK/DRAgentMessageFlowAdDelegate.h>

#import <DRAgentSDK/DRAgentRedEnvelopeView.h>
#import <DRAgentSDK/DRAgentRedEnvelopeAdDelegate.h>


