//
//  DRAgentAdvertDataModel.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DRAgentAdvertDataImageModel;

#pragma mark *** 广告数据model ***

/** 广告数据model*/
@interface DRAgentAdvertDataModel : NSObject

/// 广告名字
@property (nonatomic, copy, null_unspecified)   NSString *title;

/// 广告id
@property (nonatomic, copy, null_unspecified)   NSString *planid;

/// 广告图片数组
@property (nonatomic, copy, null_unspecified)   NSArray<DRAgentAdvertDataImageModel *> *imagesDataArray;

/// 跳入链接
@property (nonatomic, copy, null_unspecified)   NSString *gotourl;

/// 点弹
@property (nonatomic, strong, null_unspecified) NSNumber *pnum;

/// 广告类型
@property (nonatomic, copy, null_unspecified)   NSString *adstypeid;

/// 是否有落地页
@property (nonatomic, strong, null_unspecified) NSNumber *is_link;

/// 暗弹
@property (nonatomic, strong, null_unspecified) NSNumber *dktips;
@property (nonatomic, copy, null_unspecified)   NSString *actype;

@end


#pragma mark *** 广告数据图片model ***

/** 广告数据图片model*/
@interface DRAgentAdvertDataImageModel : NSObject

/// 图片TJ
@property (nonatomic, copy, null_unspecified) NSString *imageTJ;

/// 图片地址
@property (nonatomic, copy, null_unspecified) NSString *imgurl;

@end
