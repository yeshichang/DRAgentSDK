//
//  DRAgentEnumHeader.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#ifndef DRAgentEnumHeader_h
#define DRAgentEnumHeader_h

/// 广告请求成功
#define kDRAgentSDKErrorCodeAdvertSuccess               0

/// 加密值比对失败
#define kDRAgentSDKErrorCodeEncryptFaild                1

/// 应用Appkey不规范
#define kDRAgentSDKErrorCodeAppkeyError                 2

/// 应用Appkey不存在
#define kDRAgentSDKErrorCodeAppkeyNonentity             3

/// 请求广告不是客户端的量
#define kDRAgentSDKErrorCodeNoClientAdvert              5

/// 应用下没有该类型的广告
#define kDRAgentSDKErrorCodeNoTypeAdvert                6

/// 开发者账号不存在或者异常
#define kDRAgentSDKErrorCodeUserException               7

/// 开发者的应用不存在或者异常
#define kDRAgentSDKErrorCodeAbnormalityApp              8

/// 开发者对应的应用不存在或者异常
#define kDRAgentSDKErrorCodeNoMatchAPP                  9

/// 广告被限制限制平台
#define kDRAgentSDKErrorCodeRestrictedPlatform          10

/// 广告被限制会员
#define kDRAgentSDKErrorCodeRestrictedMembership        11

/// 广告被限制站点
#define kDRAgentSDKErrorCodeRestrictedSite              12

/// 广告被限制分类
#define kDRAgentSDKErrorCodeRestrictedClass             13

/// 经过弹出概率之后没有广告
#define kDRAgentSDKErrorCodePOPNoAdvertising            14

/// 经过弹出概率之后没有广告
#define kDRAgentSDKErrorCodeFilterNOAdvertsing          15

/// 广告被限制流量端口
#define kDRAgentSDKErrorCodeLimitFlowPort               16

/// 广告限制运营商
#define kDRAgentSDKErrorCodeLimitFlowOperator           17

/// 请求的广告类型不存在
#define kDRAgentSDKErrorCodeTypeNoExistence             19

/// 广告被限制地区
#define kDRAgentSDKErrorCodeRestrictedArea              22

/// 应用下被限制地区
#define kDRAgentSDKErrorCodeAPPRestrictedArea           23

typedef NS_ENUM (NSInteger, IAdSuccessBack)
{
    OnSuccess = 0,          // 广告加载成功
    OnError,                // 广告失败
    OnClick,                // 点击广告
};

typedef NS_ENUM (NSInteger, IAdDataType)
{
    IAdDataTypeFullScreen,                // 全屏
    IAdDataTypeBannerLow,                 // 横幅(banner)低
    IAdDataTypeBanner,                    // 横幅(banner)
    IAdDataTypeMessageFlowThreeImages,    // 信息流三小图
    IAdDataTypeMessageFlowSmallImage,     // 信息流广告小图
    IAdDataTypeMessageFlowBigImage,       // 信息流广告大图
    IAdDataTypeRedEnvelope,               // 红包
};

// 自行添加错误码
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
    DRAgentSDKErrorCodeRestrictedArea           =       kDRAgentSDKErrorCodeRestrictedArea,
    DRAgentSDKErrorCodeAPPRestrictedArea        =       kDRAgentSDKErrorCodeAPPRestrictedArea,
};

#endif /* DRAgentEnumHeader_h */
