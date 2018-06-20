//
//  DRAgentEnumHeader.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#ifndef DRAgentEnumHeader_h
#define DRAgentEnumHeader_h

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
 广告成功失败类型枚举

 - OnSuccess: 成功
 - OnError: 失败
 - OnClick: 点击
 */
typedef NS_ENUM (NSInteger, IAdSuccessBack)
{
    OnSuccess = 0,
    OnError   = 1,
    OnClick   = 2,
};

/**
 广告类型枚举

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
 */
typedef NS_ENUM (NSInteger, IAdDataType)
{
    IAdDataTypeFullScreen,
    IAdDataTypeBannerLow,
    IAdDataTypeBanner,
    IAdDataTypeMessageFlowThreeImages,
    IAdDataTypeMessageFlowSmallImage,
    IAdDataTypeMessageFlowSmallImageVertical,
    IAdDataTypeMessageFlowBigImage,
    IAdDataTypeMessageFlowBigImageVertical,
    IAdDataTypeRedEnvelope,
    IAdDataTypeRedVideo,
    IAdDataTypeSmallImage
};

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
