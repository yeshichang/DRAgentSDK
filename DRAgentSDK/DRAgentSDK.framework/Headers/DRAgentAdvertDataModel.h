//
//  DRAgentAdvertDataModel.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2017
//  Copyright © 2017年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DRAgentAdvertDataImageModel;
@interface DRAgentAdvertDataModel : NSObject

/** 广告名字 */
@property (nonatomic, copy) NSString *title;

/** 广告id */
@property (nonatomic, copy) NSString *planid;

/** 广告图片数组 */
@property (nonatomic, strong) NSArray<DRAgentAdvertDataImageModel *> *imagesDataArray;

/** 跳入链接 */
@property (nonatomic, copy) NSString *gotourl;

/** 点弹 */
@property (nonatomic, copy) NSString *pnum;

/** 广告类型 */
@property (nonatomic, copy) NSString *adstypeid;

/** 暗弹 */
@property (nonatomic ,copy) NSString *dktips;

@end
