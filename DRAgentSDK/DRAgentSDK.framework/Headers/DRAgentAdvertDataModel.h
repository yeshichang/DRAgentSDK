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

/// 广告内容
@property (nonatomic, copy, null_unspecified)   NSString *content;

/// 广告id
@property (nonatomic, copy, null_unspecified)   NSString *planid;

/// 广告图片数组
@property (nonatomic, copy, null_unspecified)   NSArray<DRAgentAdvertDataImageModel *> *imagesDataArray;

/// 跳入链接
@property (nonatomic, copy, null_unspecified)   NSString *gotourl;

/// 广告类型
@property (nonatomic, copy, null_unspecified)   NSString *adstypeid;

/// 是否有落地页
@property (nonatomic, strong, null_unspecified) NSNumber *is_link;

/// 配置参数
@property (nonatomic, strong, null_unspecified) NSNumber *pnum;
@property (nonatomic, strong, null_unspecified) NSNumber *extrate;
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


// ************************************ 华丽的分割线 ********************************** //

/** 激励视频广告数据model */
@interface DRAgentExcitingVideoDataModel : NSObject <NSCoding>

/// 视频标题
@property (nonatomic, copy, null_unspecified)   NSString *title;
/// 视频内容
@property (nonatomic, copy, null_unspecified)   NSString *content;
/// 图片地址
@property (nonatomic, copy, null_unspecified)   NSString *imgurl;
/// 视频地址
@property (nonatomic, copy, null_unspecified)   NSString *videourl;
/// 广告id
@property (nonatomic, copy, null_unspecified)   NSString *planid;
/// 跳入链接
@property (nonatomic, copy, null_unspecified)   NSString *gotourl;

@property (nonatomic, strong, null_unspecified) NSNumber *pnum;
@property (nonatomic, strong, null_unspecified) NSNumber *extrate;
@property (nonatomic, copy, null_unspecified)   NSString *adstypeid;
@property (nonatomic, strong, null_unspecified) NSNumber *dktips;
@property (nonatomic, copy, null_unspecified)   NSString *getImageTJ;
@property (nonatomic, strong, null_unspecified) NSNumber *is_link;
@property (nonatomic, copy, null_unspecified)   NSString *weight;
@property (nonatomic, copy, null_unspecified)   NSString *actype;
@property (nonatomic, copy, null_unspecified)   NSNumber *errrate;

@end

