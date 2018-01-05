//
//  DRAgentEnumHeader.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#ifndef DRAgentEnumHeader_h
#define DRAgentEnumHeader_h

typedef enum : NSUInteger {
    OnSuccess =0,  // 广告加载成功
    OnError,       // 广告失败
    OnClick,       // 点击广告
} IAdSuccessBack;


typedef enum : NSUInteger {
    IAdMessageFlowViewTypeSmallImage =0,  // 信息流广告小图
    IAdMessageFlowViewTypeBigImage,       // 信息流广告大图
} IAdMessageFlowViewType;


typedef enum : NSUInteger {
    IAdDataTypeFullScreen,                // 全屏
    IAdDataTypeBannerLow,                 // 横幅(banner)低
    IAdDataTypeBanner,                    // 横幅(banner)
    IAdDataTypeMessageFlowThreeImages,    // 信息流三小图
    IAdDataTypeMessageFlowSmallImage,     // 信息流广告小图
    IAdDataTypeMessageFlowBigImage,       // 信息流广告大图
    IAdDataTypeRedEnvelope,               // 红包
} IAdDataType;



#endif /* DRAgentEnumHeader_h */
