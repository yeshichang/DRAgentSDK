//
//  DRAgentLoader.h
//  DRAgentSDK
//
//  Created by DRAgentSDK on 2018/1/22.
//  Copyright © 2018年 DRAgentSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DRAgentEnumHeader.h"
#import "DRAgentLoaderAdDelegate.h"

@class DRAgentAdvertDataModel;
@interface DRAgentLoader : NSObject

/*!
 @brief 加载数据类代理
 */
@property (nonatomic, weak, nullable) id <DRAgentLoaderAdDelegate> delegate;

/*!
 @brief 初始化加载数据类
 @param advertType 广告类型
 @return 加载数据类
 */
- (instancetype _Nullable)initWithIAdDataType:(IAdDataType)advertType NS_DESIGNATED_INITIALIZER;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/*!
 @brief 获取广告数据(原生广告)
 */
- (void)loadNativeRequest;

/*!
 @brief  跳入网页视图
 @param  advertDataModel  广告数据model
 @param  index 索引(除此信息流三小图<IAdDataTypeMessageFlowThreeImages>以外,默认传入0)
 */
- (void)pushDRAgentWebView:(DRAgentAdvertDataModel *_Nonnull)advertDataModel
                 withIndex:(NSInteger)index;

@end
