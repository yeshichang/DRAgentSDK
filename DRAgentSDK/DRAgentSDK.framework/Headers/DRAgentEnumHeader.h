//
//  DRAgentEnumHeader.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#ifndef DRAgentEnumHeader_h
#define DRAgentEnumHeader_h


#define DRAgentSDK_ISGIFTypeWithData(data)\
({\
BOOL result = NO;\
if(!data) result = NO;\
uint8_t c;\
[data getBytes:&c length:1];\
if(c == 0x47) result = YES;\
(result);\
})

#define DRAgentSDK_ISVideoTypeWithPath(path)\
({\
BOOL result = NO;\
if([path hasSuffix:@".mp4"])  result =  YES;\
(result);\
})

#define DRAgentSDK_DataWithFileName(name)\
({\
NSData *data = nil;\
NSString *path = [[NSBundle mainBundle] pathForResource:name ofType:nil];\
if([[NSFileManager defaultManager] fileExistsAtPath:path]){\
data = [NSData dataWithContentsOfFile:path];\
}\
(data);\
})

#define DRAgentSDK_DISPATCH_SOURCE_CANCEL_SAFE(time) if(time)\
{\
dispatch_source_cancel(time);\
time = nil;\
}

#define DRAgentSDK_REMOVE_FROM_SUPERVIEW_SAFE(view) if(view)\
{\
[view removeFromSuperview];\
view = nil;\
}

#define DRAgentISStringEmpty(str) (([str isKindOfClass:[NSNull class]] || str == nil || [str length]<=0)? YES : NO )

#define DRAgentISURLString(string)  ([string hasPrefix:@"https://"] || [string hasPrefix:@"http://"]) ? YES:NO

#define DRAgent_Device_Is_iPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)

#define DRAgentSDK_StatusBarHeight [[UIApplication sharedApplication] statusBarFrame].size.height
#define DRAgentSDK_NavBarHeight 44.0
#define DRAgentSDK_TopHeight (DRAgentSDK_StatusBarHeight + DRAgentSDK_NavBarHeight)
#define DRAgentSDK_TabBarHeight ([[UIApplication sharedApplication] statusBarFrame].size.height>20?83:49)

#define DRAgentSDK_RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]



/// DRAgentSDK  错误码
#define kDRAgentSDKErrorCodeAdvertSuccess               0
#define kDRAgentSDKErrorCodeEncryptFaild                1
#define kDRAgentSDKErrorCodeAppkeyError                 2
#define kDRAgentSDKErrorCodeAppkeyNonentity             3
#define kDRAgentSDKErrorCodeNoClientAdvert              5
#define kDRAgentSDKErrorCodeNoTypeAdvert                6
#define kDRAgentSDKErrorCodeUserException               7
#define kDRAgentSDKErrorCodeAbnormalityApp              8
#define kDRAgentSDKErrorCodeNoMatchAPP                  9
#define kDRAgentSDKErrorCodeRestrictedPlatform          10
#define kDRAgentSDKErrorCodeRestrictedMembership        11
#define kDRAgentSDKErrorCodeRestrictedSite              12
#define kDRAgentSDKErrorCodeRestrictedClass             13
#define kDRAgentSDKErrorCodePOPNoAdvertising            14
#define kDRAgentSDKErrorCodeFilterNOAdvertsing          15
#define kDRAgentSDKErrorCodeLimitFlowPort               16
#define kDRAgentSDKErrorCodeLimitFlowOperator           17
#define kDRAgentSDKErrorCodeTypeNoExistence             19
#define kDRAgentSDKErrorCodeAPPABCRestrictedArea        21
#define kDRAgentSDKErrorCodeRestrictedArea              22
#define kDRAgentSDKErrorCodeAPPRestrictedArea           23


/**
 横幅广告类型

 - IAdBannerTypeBanner: 横幅广告
 - IAdBannerTypeBannerLow: 小横幅广告
 - IAdBannerTypeVideoBanner: 视频横幅广告
 */
typedef NS_ENUM (NSInteger, IAdBannerType)
{
    IAdBannerTypeBanner         =   1,
    IAdBannerTypeLowBanner      =   2,
    IAdBannerTypeVideoBanner    =   3,
};

/**
 原生广告类型

 - IAdNativeTypeMessageFlowThreeImages: 信息流三小图
 - IAdNativeTypeMessageFlowSmallImage: 信息流广告小图
 - IAdNativeTypeMessageFlowSmallImageVertical: 信息流广告小图竖图(仅适用于原生广告)
 - IAdNativeTypeMessageFlowBigImage: 信息流广告大图
 - IAdNativeTypeMessageFlowBigImageVertical: 信息流广告大图竖图(仅适用于原生广告)
 - IAdNativeTypeSmallImage: 小图文
 - IAdNativeTypeSmallImageVertical: 小图文竖
 - IAdNativeTypeSmallImageVertical: 小图文170*100
 */
typedef NS_ENUM (NSInteger, IAdNativeType)
{
    IAdNativeTypeMessageFlowThreeImages             =   4,
    IAdNativeTypeMessageFlowSmallImage              =   5,
    IAdNativeTypeMessageFlowSmallImageVertical      =   6,
    IAdNativeTypeMessageFlowBigImage                =   7,
    IAdNativeTypeMessageFlowBigImageVertical        =   8,
    IAdNativeTypeSmallImage                         =   9,
    IAdNativeTypeSmallImageVertical                 =   10,
    IAdNativeTypeSmallImage170_100                  =   103,
};

/**
 封装好的信息流View枚举(在原生广告接收数据成功后初始化信息流View即可快速创建信息流View)

 - MESSAGEVIEWTYPE_ThreeImages: 信息流三小图View
 - MESSAGEVIEWTYPE_SmallImage: 信息流小图View
 - MESSAGEVIEWTYPE_BigImage: 信息流大图View
 */
typedef NS_ENUM (NSInteger, MESSAGEVIEWTYPE) {
    MESSAGEVIEWTYPE_ThreeImages         =   4,
    MESSAGEVIEWTYPE_SmallImage          =   5,
    MESSAGEVIEWTYPE_BigImage            =   7,
};

/**
 广告类型

 - IAdDataTypeFullScreen: 全屏
 - IAdDataTypeBannerLow: 横幅(banner)低
 - IAdDataTypeBanner: 横幅(banner)
 - IAdDataTypeMessageFlowThreeImages: 信息流三小图
 - IAdDataTypeMessageFlowSmallImage: 信息流广告小图
 - IAdDataTypeMessageFlowSmallImageVertical: 信息流广告小图竖图(仅适用于原生广告)
 - IAdDataTypeMessageFlowBigImage: 信息流广告大图
 - IAdDataTypeMessageFlowBigImageVertical: 信息流广告大图竖图(仅适用于原生广告)
 - IAdDataTypeRedEnvelope: 红包广告
 - IAdDataTypeRedVideo: 红包视频广告
 - IAdDataTypeSmallImage: 小图文
 - IAdDataTypeSmallImageVertical 小图文竖
 */
typedef NS_ENUM (NSInteger, IAdDataType)
{
    IAdDataTypeFullScreen                           =   100,
    IAdDataTypeBannerLow                            =   2,
    IAdDataTypeBanner                               =   1,
    IAdDataTypeMessageFlowThreeImages               =   4,
    IAdDataTypeMessageFlowSmallImage                =   5,
    IAdDataTypeMessageFlowSmallImageVertical        =   6,
    IAdDataTypeMessageFlowBigImage                  =   7,
    IAdDataTypeMessageFlowBigImageVertical          =   8,
    IAdDataTypeRedEnvelope                          =   101,
    IAdDataTypeRedVideo                             =   102,
    IAdDataTypeSmallImage                           =   9,
    IAdDataTypeSmallImageVertical                   =   10,
} __deprecated_msg("此区分广告类型枚举已过期，请接入相应广告枚举类型");



typedef NS_ENUM (NSInteger, DRAgentSDKErrorCode)
{
    DRAgentSDKErrorCodeAdvertSuccess            =       kDRAgentSDKErrorCodeAdvertSuccess,
    DRAgentSDKErrorCodeEncryptFaild             =       kDRAgentSDKErrorCodeEncryptFaild,
    DRAgentSDKErrorCodeAppkeyError              =       kDRAgentSDKErrorCodeAppkeyError,
    DRAgentSDKErrorCodeAppkeyNonentity          =       kDRAgentSDKErrorCodeAppkeyNonentity,
    DRAgentSDKErrorCodeNoClientAdvert           =       kDRAgentSDKErrorCodeNoClientAdvert,
    DRAgentSDKErrorCodeNoTypeAdvert             =       kDRAgentSDKErrorCodeNoTypeAdvert,
    DRAgentSDKErrorCodeUserException            =       kDRAgentSDKErrorCodeUserException,
    DRAgentSDKErrorCodeAbnormalityApp           =       kDRAgentSDKErrorCodeAbnormalityApp,
    DRAgentSDKErrorCodeNoMatchAPP               =       kDRAgentSDKErrorCodeNoMatchAPP,
    DRAgentSDKErrorCodeRestrictedPlatform       =       kDRAgentSDKErrorCodeRestrictedPlatform,
    DRAgentSDKErrorCodeRestrictedMembership     =       kDRAgentSDKErrorCodeRestrictedMembership,
    DRAgentSDKErrorCodeRestrictedSite           =       kDRAgentSDKErrorCodeRestrictedSite,
    DRAgentSDKErrorCodeRestrictedClass          =       kDRAgentSDKErrorCodeRestrictedClass,
    DRAgentSDKErrorCodePOPNoAdvertising         =       kDRAgentSDKErrorCodePOPNoAdvertising,
    DRAgentSDKErrorCodeFilterNOAdvertsing       =       kDRAgentSDKErrorCodeFilterNOAdvertsing,
    DRAgentSDKErrorCodeLimitFlowPort            =       kDRAgentSDKErrorCodeLimitFlowPort,
    DRAgentSDKErrorCodeLimitFlowOperator        =       kDRAgentSDKErrorCodeLimitFlowOperator,
    DRAgentSDKErrorCodeTypeNoExistence          =       kDRAgentSDKErrorCodeTypeNoExistence,
    DRAgentSDKErrorCodeAPPABCRestrictedArea     =       kDRAgentSDKErrorCodeAPPABCRestrictedArea,
    DRAgentSDKErrorCodeRestrictedArea           =       kDRAgentSDKErrorCodeRestrictedArea,
    DRAgentSDKErrorCodeAPPRestrictedArea        =       kDRAgentSDKErrorCodeAPPRestrictedArea,
};

#endif /* DRAgentEnumHeader_h */
