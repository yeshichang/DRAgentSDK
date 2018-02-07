//
//  DRAgentAdvertDataModel.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DRAgentAdvertDataImageModel;

/**
 广告数据model
 */
@interface DRAgentAdvertDataModel : NSObject

/// 广告名字
@property (nonatomic, copy) NSString *title;

/// 广告id
@property (nonatomic, copy) NSString *planid;

/// 广告图片数组
@property (nonatomic, copy) NSArray <DRAgentAdvertDataImageModel *> *imagesDataArray;

/// 跳入链接
@property (nonatomic, copy) NSString *gotourl;

/// 点弹
@property (nonatomic, strong) NSNumber *pnum;

/// 广告类型
@property (nonatomic, copy) NSString *adstypeid;

/// 暗弹
@property (nonatomic, strong) NSNumber *dktips;

@end

/**
 广告数据图片model
 */
@interface DRAgentAdvertDataImageModel : NSObject

/// 图片TJ
@property (nonatomic, copy) NSString *imageTJ;

/// 图片地址
@property (nonatomic, copy) NSString *imgurl;

@end
