# DRAgentSDK使用说明  
## 概述
欢迎使用洛米广告平台。通过本文档，您可以在几分钟之内轻松完成移动广告的集成过程。
***注：在您阅读此文档时，我们假定您已经具备了基础的iOS应用开发经验，并能够理解相关基础概念，SDK支持iOS8及以上iOS版本。***
- 申请APPkey，在[洛米官方网站](http://www.luomi.com/)网站中注册成为开发者并创建一款应用，您将获得一个appkey，用于标识您的应用。
- 下载并导入SDK

>1、通过Cocoapods 下载地址： SDK1.8.4版本开始支持pod管理：
`pod 'DRAgentSDK'`引用时`#import<DRAgentSDK/DRAgentSDK.h>`
如果项目支持cocoapods管理，请使用cocoapods导入SDK，能获取最新的SDK，方便管理。
***
>2、 通过[官方平台](http://www.luomi.com/document.php)下载SDK以及demo和对接文档。下载最新版的LMAgentSDK.framework.zip后解压得到`DRAgentSDK.framework `添加到项目中，然后添加资源库 `DRAgentSDKBundle.bundle`

![image.jpeg](https://upload-images.jianshu.io/upload_images/2917199-49b19377fd5451e4.jpeg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.jpeg](https://upload-images.jianshu.io/upload_images/2917199-486adbe547346fd5.jpeg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 配置other linker flags添加-ObjC

![image.png](https://upload-images.jianshu.io/upload_images/2917199-a140937d1f3ac2d4.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 配置HTTP
SDK中用到HTTP请求，苹果在iOS9推出支持HTTP请求时求配置info.plist文件。
- 配置定位
若项目中本身已经配置，可忽略。若项目需求中没用到定位权限且不使用限制地区投放功能，可不配置，***但是必须在`DRAgent`类中的定位属性设置为NO***
```
/*!
 @brief      SDK中开启定位功能，必须设置在注册AppKey代码上面
 @discussion 默认为开启，根据自己应用情况设置定位功能(注意：若关闭定位无法使用对地区限制投放功能)
 */
@property (nonatomic, assign) BOOL openLocation;
```
## 代码使用
### 1、开屏广告

![splash.gif](https://upload-images.jianshu.io/upload_images/2917199-213917edae4770c5.gif?imageMogr2/auto-orient/strip)

- 开屏广告在App启动时展示的广告，具有超强的视觉冲击力，平台开屏广告支持视频广告、GIF图、和图片三种形式，其中开屏尺寸默认都使用全屏尺寸`[UIScreen mainScreen].bounds`，其中注意一下两点：  
    1）：开屏广告在下来数据时会使用到App工程的启动图，而获得这个启动图是在launch image里面的开屏图片，若不是，则需要用开屏广告的代理(`datasource`)里面传入image为默认image，防止露白。  
    2）：若使用logo添加在开屏底部，则需要使用开屏广告的代理(`datasource`)里面传入相应的View，View的frame对应的是window，则可以展示对应的logo，或者其他视图。

- 在 AppDelegate.m中 入口方法:`- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions`中，
初始化中设置开启开屏广告 
```
/// 加载开屏广告
- (void)luomi_splashShow {
    DRAgentSplash *splash = [[DRAgentSplash alloc] initWithFrame:[UIScreen mainScreen].bounds];
    // 设置拉取广告时间(超时则取消开屏广告，视为广告展示失败)
    splash.fetchDelay = 3;
    // 设置开屏广告当有视频播放时是否静音(默认YES不静音)
    splash.muted = YES;
    // 设置代理
    splash.delegate = self;
    // 加载开屏广告
    [splash loadSplashRequest];
    // 强引用加载类，防止释放无法加载广告
    _splash = splash;
}
```
- 高级使用，*以下为开屏广告的回调代理。*
```
/*!
 @brief 开屏广告子视图
 @discussion 实现此代理方法,这些视图将会被自动添加在广告视图上,frame相对于window
 @param agentSplash agentSplash
 @return 子视图的数组
 */
//- (NSArray<UIView *> *)adSplashSubViews:(DRAgentSplash *)agentSplash {
//    UIImageView *imageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"image"]];
//    imageView.frame = CGRectMake(0, kScreenHeight- 100, kScreenWidth, 100);
//    return @[imageView];
//}

/**
 @brief 开屏广告启动背景，若启动图不是在launch image里面添加的请设置启动背景防止露白
 @discussion 可以设置开屏图片来作为开屏加载时的默认图片
 @param agentSplash agentSplash
 @return image
 */
//- (UIImage *)adSplashbackgroundImage:(DRAgentSplash *)agentSplash {
//    return [UIImage imageNamed:@"ffff"];
//}

/*
 * 开屏广告展示
 */
- (void)adSplashShowed:(DRAgentSplash *)agentSplash adverType:(IAdNativeType)adverType didFailToReceiveAdWithError:(NSError *)error {
    if (!error) {
        NSLog(@"开屏广告展示广告");
    } else {
        NSLog(@"开屏广告展示失败 = %@",error);
    }
}
/*
 * 开屏广告数据 成功
 */
- (void)adSplashDidFinishLoading:(DRAgentSplash *)agentSplash adverType:(IAdNativeType)adverType {
    NSLog(@"%s",__FUNCTION__);
}
/*
 * 开屏广告数据 失败
 */
- (void)adSplash:(DRAgentSplash *)agentSplash didFailToReceiveAdWithError:(NSError *)error {
    NSLog(@"%s",__FUNCTION__);
}
/*
 * 开屏广告点击广告
 */
- (void)adSplashDidClick:(DRAgentSplash *)agentSplash adverType:(IAdNativeType)adverType {
    NSLog(@"%s",__FUNCTION__);
}
/*
 * 开屏广告视图消失
 */
- (void)adSplashscreenDismiss:(DRAgentSplash *)agentSplash {
    NSLog(@"%s",__FUNCTION__);
    _splash = nil;
}
/*
 * 广告webView 返回
 */
- (void)adSplashWebViewReturn:(DRAgentSplash *)agentSplash {
    NSLog(@"%s",__FUNCTION__);
}
```
### 2、原生广告

原生广告用于信息流广告，小图文cpv广告。
首先实例化数据请求类`DRAgentLoader`的对象，请求广告数。实现代理方法拿到数据后，自定义构建广告View添加到要展示广告的前端页面上，在广告页面中添加手势或点击事件，在点击事件中调用SDK的原生广告点击跳转方法`- (void)clickNativeAd:(id _Nonnull)dataModel;`
**其中，SDK有封装定义好的信息流三小图View`DRAgentMessageThreeImagesView`和信息流大小图文的View`DRAgentMessageFlowView`，可以直接拿到View直接使用，且不用实现跳转方法。使用封装好的自定义信息流View自定义程度不高。**
***
下面请看下原生广告的基本使用
- 广告数据类型IAdDataType
```
/**
 原生广告类型

 - IAdNativeTypeMessageFlowThreeImages: 信息流三小图
 - IAdNativeTypeMessageFlowSmallImage: 信息流广告小图
 - IAdNativeTypeMessageFlowSmallImageVertical: 信息流广告小图竖图(仅适用于原生广告)
 - IAdNativeTypeMessageFlowBigImage: 信息流广告大图
 - IAdNativeTypeMessageFlowBigImageVertical: 信息流广告大图竖图(仅适用于原生广告)
 - IAdNativeTypeSmallImage: 小图文
 - IAdNativeTypeSmallImageVertical: 小图文竖
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
};
```
- 广告初始化、加载数据、跳转点击
```
/*!
 @brief 初始化加载数据类
 @param advertType 广告类型
 @return 加载数据类
 */
- (instancetype _Nullable)initWithIAdDataType:(IAdNativeType)advertType NS_DESIGNATED_INITIALIZER;
- (instancetype _Nullable)init NS_UNAVAILABLE;
/*!
 @brief 获取广告数据(原生广告)
 */
- (void)loadNativeRequest;
/*!
 @brief  广告点击调用方法
 @discussion 当用户点击广告时，开发者需调用本方法，系统会弹出内嵌浏览器、或AppStore展现广告目标页面
 @param dataModel 用户点击的广告数据对象
 */
- (void)clickNativeAd:(id _Nonnull)dataModel;
```
- 代理方法必须实现，*以下为原生广告加载类的回调代理。*
```
@required
/**
 广告数据加载成功
 @param adLoader 加载数据类
 @param adverType 广告类型
 @param advertDataModel 广告数据模型 (model)
 */
- (void)adLoaderDidFinishLoading:(DRAgentLoader *)adLoader adverType:(IAdNativeType)adverType advertDataModel:(DRAgentAdvertDataModel *)advertDataModel;
/**
 广告数据加载失败
 @param adLoader 加载数据类
 @param error 错误error
 */
- (void)adLoader:(DRAgentLoader *)adLoader didFailToReceiveAdWithError:(NSError *)error;
@optional
/**
 webView点击返回 (从webView返回广告控制器页面)
 @param adLoader 加载数据类
 */
- (void)adLoaderWebViewReturn:(DRAgentLoader *)adLoader;
```
#### (1)、 信息流三小图
拿到数据，创建广告View，绑定数据，添加到展示广告的视图上，example：这里使用SDK封装好的信息流三小图View `DRAgentMessageThreeImagesView`
```
// 创建信息流三小图
{
    CGFloat width = [UIScreen mainScreen].bounds.size.width;
    CGFloat height = [DRAgentMessageThreeImagesView getMessageViewHeightWithType:MESSAGEVIEWTYPE_ThreeImages width:width];
    _messageThreeImagesView = [[DRAgentMessageThreeImagesView alloc] initWithFrame:CGRectMake(0, 0, width, height) messageViewType:MESSAGEVIEWTYPE_ThreeImages delegate:self];
    [self.contentView addSubview:_messageThreeImagesView]; 
}
```
- 高级使用，*以下为三小图广告的回调代理。*
```
/*
 * 信息流三小图 点击
 */
- (void)adMessageDidClick:(DRAgentMessageView *)messageView adverType:(MESSAGEVIEWTYPE)adverType {
    NSLog(@"%s",__FUNCTION__);
}
/*
 * webView返回
 */
- (void)adMessageWebViewReturn:(DRAgentMessageView *)messageView {
    NSLog(@"%s",__FUNCTION__);
}
```
**详细请看demo中`Message_ThreeImgsViewController`**
#### (2)、信息流大小图文
类似信息流三小图，这里不再重复书写。
**详细请看demo中`Message_SmallImgViewController`|`Message_BigImgViewController `**
#### (3)、小图文CPV

![image.png](https://upload-images.jianshu.io/upload_images/2917199-ef019e8c7eb5e750.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

类似信息流三小图，这里不再重复书写。
**详细请看demo中`CustomSmallImgViewController`**

### 3、横幅(Banner)广告

![img.png](https://upload-images.jianshu.io/upload_images/2917199-a3c8fca5acd36715.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

横幅广告有三种类型分别是：
```
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
```

横幅广告分为横幅广告、小横幅广告、视频横幅，使用`DRAgentBannerView`实例出横幅类对象的View，添加到广告展示的页面。使用小横幅广告的话，type传为`IAdBannerTypeLowBanner`，使用视频横幅广告的话，type传为`IAdBannerTypeVideoBanner`，代码如下简写。
```
- (DRAgentBannerView *)bannerView {
    if (_bannerView == nil) {
        CGFloat bannerHeight = [DRAgentBannerView getBannerViewHeightWithType:IAdBannerTypeBanner width:kScreenWidth];
        _bannerView = [[DRAgentBannerView alloc] initWithFrame:CGRectMake(0, kTopHeight, kScreenWidth, bannerHeight) bannerViewType:IAdBannerTypeBanner delegate:self];
        [self addText:bannerHeight];
    }
    return _bannerView;
}
// 加载Banner广告
[self.bannerView loadBannerRequest];
```
- 高级使用，*以下为横幅广告的回调代理。*
```
/*
 * banner广告成功
 */
- (void)adBannerDidFinishLoading:(DRAgentBannerView *)bannerView adverType:(IAdBannerType)adverType  {
    NSLog(@"%s",__FUNCTION__);
    [self.view addSubview:bannerView];
}
/*
 * banner广告失败
 */
- (void)adBanner:(DRAgentBannerView *)bannerView didFailToReceiveAdWithError:(NSError *)error {
    NSLog(@"banner广告 失败  code-->%ld",(long)error.code);
}
/*
 * banner广告点击
 */
- (void)adBannerDidClick:(DRAgentBannerView *)bannerView adverType:(IAdBannerType)adverType {
    NSLog(@"%s",__FUNCTION__);
}
/*
 * 关闭按钮回调
 */
- (void)adBannerDidClickCloseButton:(DRAgentBannerView *)bannerView {
    NSLog(@"%s",__FUNCTION__);
}
/*
 * webView返回
 */
- (void)adBannerWebViewReturn:(DRAgentBannerView *)bannerView {
    NSLog(@"%s",__FUNCTION__);
}
```
***
如果使用横幅广告的轮播功能。*在视图显示成功方法里开启轮播，在视图消失方法中和返回pop中关闭轮播，关闭定时器，以防每次请求数据 再次进入重新加载bannerView，避免内存泄漏。新版本已取消轮播功能。*
**详细请看demo中BannerViewController、LowBannerViewController、VideoBannerViewController**

### 4、视频广告

![video.gif](https://upload-images.jianshu.io/upload_images/2917199-5d0cce27a216ae9f.gif?imageMogr2/auto-orient/strip)

视频广告是以一个icon图标作为跳转入口加载视频广告，首先初始化视频广告icon添加展示广告页面。代码如下简写。
```
{
    DRAgentRedVideoView *redVideoView = [[DRAgentRedVideoView alloc] initWithFrame:CGRectMake(kScreenWidth - 120, 100, 100, 125) delegate:self]; 
    self.redVideoView = redVideoView;
}
```
- 高级使用，*以下为视频广告的回调代理。*
```
/*
 * 红包图标数据加载
 */
- (void)adRedVideoImageIconLoadingFinished:(DRAgentRedVideoView *)redVideoView reciveAdWithError:(NSError *)error {
    if (!error) {
        NSLog(@"红包图标数据加载成功");
        [self.view addSubview:redVideoView];
        // redVideoViewLabel
        CGFloat x = redVideoView.frame.origin.x;
        CGFloat y = redVideoView.frame.origin.y + redVideoView.frame.size.height;
        CGFloat width = redVideoView.frame.size.width;
        CGFloat height = 30;
        self.redVideoViewLabel.frame = CGRectMake(x, y, width, height);
        [self.view addSubview:self.redVideoViewLabel];
        
        // 添加时间控制切换icon图标
        // _timer = [NSTimer scheduledTimerWithTimeInterval:10 target:self selector:@selector(loadRequestTimers) userInfo:nil repeats:YES];

    } else {
        NSLog(@"红包图标数据加载失败 = %@",error);
    }
}
/*
 * 红包数据中title数据
 */
- (void)adRedVideoImageIconLoadingFinished:(NSString *)iconTitle {
    if (iconTitle) {
        self.redVideoViewLabel.text = iconTitle;
    }
}
/*
 * 红包icon被点击
 */
- (void)adRedDidClick:(DRAgentRedView *)redView {
    NSLog(@"%s",__FUNCTION__);
}
/*
 * 红包视频广告数据加载
 */
- (void)adRedVideoDataLoadingFinished:(DRAgentRedVideoView *)redVideoView reciveAdWithError:(NSError *)error {
    if (!error) {
        NSLog(@"红包数据加载成功");
    } else {
        NSLog(@"红包数据加载失败 = %@",error);
    }
}
/*
 * 视频广告展示播放
 */
- (void)adRedVideoShowVideoPlay:(DRAgentRedVideoView *)redVideoView currentIndex:(NSInteger)currectIndex {
    NSLog(@"视频广告展示播放 -- %ld",(long)currectIndex);
}
/*
 * 视频广告点击下载按钮
 */
- (void)adRedVideoDidClickDownButton:(DRAgentRedVideoView *)redVideoView {
    NSLog(@"%s",__FUNCTION__);
}
```
***详细请看demo中`RedVideoViewController`***

## 注意事项
- 设置Enable Bitcode 为NO
![image.png](https://upload-images.jianshu.io/upload_images/2917199-d6efc571457bf780.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 项目上传App Store
1、广告标识符
SDK中用到了广告标识符(IDFA),在提交APP的时候要注意选择(如图)
![image.png](https://upload-images.jianshu.io/upload_images/2917199-719a3b007c5ab9a4.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
如果你使用了广告,请选择1和4 关于一篇广告标识符用途的选择的博客      [广告标识符用途](http://blog.csdn.net/napianlvye1992/article/details/50496846)

- 详细请看DRAgentSDKDemo
## 常见错误
- 使用xcode9以下版本开发应用，请联系平台技术人员。
- 若在使用cocoapods的`pod search`搜不到`DRAgentSDK`或者不是最新版本，请更新下pod本地搜索索引`pod setup`


