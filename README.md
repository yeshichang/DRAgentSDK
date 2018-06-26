# DRAgentSDK使用说明  
## 概述
欢迎使用洛米广告平台。通过本文档，您可以在几分钟之内轻松完成移动广告的集成过程。
***注：在您阅读此文档时，我们假定您已经具备了基础的iOS 应用开发经  验，并能够理解相关基础概念，SDK支持iOS8及以上iOS版本。***
- 申请APPkey，在[洛米官方网站](http://www.luomi.com/)网站中注册成为开发者并创建一款应用，您将获得一个appkey，用于标识您的应用。
- 下载并导入SDK
1、通过Cocoapods 下载地址： SDK1.8.4版本开始支持pod管理：
·`pod 'DRAgentSDK'`引用时`#import<DRAgentSDK/DRAgentSDK.h>`
如果项目支持cocoapods管理，请使用cocoapods导入SDK，能获取最新的SDK，方便管理。
2、 通过[官方平台](http://www.luomi.com/document.php)下载SDK以及demo和对接文档。下载最新版的LMAgentSDK.framework.zip后解压得到`DRAgentSDK.framework `添加到项目中

![image.jpeg](https://upload-images.jianshu.io/upload_images/2917199-49b19377fd5451e4.jpeg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
然后添加资源库 `DRAgentSDKBundle.bundle`

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

- 在 AppDelegate.m中 入口方法:
`- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions`  中, 初始化中设置开启开屏广告 
- 在入口方法中先设置根试图在此` [self.window makeKeyAndVisible] `方法下面添加开屏广告。**如若不在此方法下，开屏广告将不会出现**
```
DRAgentSplash *splash = [[DRAgentSplash alloc] initWithFrame:[UIScreen mainScreen].bounds];
// 设置拉取广告时间(超时则取消开屏广告，视为广告展示失败)
splash.fetchDelay = 3;
// 设置开屏广告当有视频播放时是否静音(默认YES不静音)
splash.muted = YES;
// 设置代理
splash.delegate = self;
// 加载开屏广告
[splash loadSplashRequest];
```
- 高级使用，*以下为开屏广告的回调代理。*
```
- (void)adSplashDidFinishLoading:(DRAgentSplash *)agentSplash adverType:(IAdDataType)adverType {
    NSLog(@"开屏广告数据 成功");
}
- (void)adSplash:(DRAgentSplash *)agentSplash didFailToReceiveAdWithError:(NSError *)error {
    NSLog(@"开屏广告数据 失败  = %@",error);
}
- (void)adSplashShowed:(DRAgentSplash *)agentSplash adverType:(IAdDataType)adverType didFailToReceiveAdWithError:(NSError *)error {
    if (!error) {
        NSLog(@"开屏广告展示广告");
    } else {
        NSLog(@"开屏广告展示失败 = %@",error);
    }
}
- (void)adSplashDidClick:(DRAgentSplash *)agentSplash adverType:(IAdDataType)adverType {
    NSLog(@"开屏广告点击广告");
}
- (void)adSplashscreenDismiss:(DRAgentSplash *)agentSplash {
    NSLog(@"开屏广告视图消失");
}
- (void)adSplashWebViewReturn:(DRAgentSplash *)agentSplash {
    NSLog(@"从广告webView返回");
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
typedef NS_ENUM (NSInteger, IAdDataType)
{
    IAdDataTypeFullScreen,                      	// 开屏(不适用于原生广告)
    IAdDataTypeBannerLow,                       	// 小横幅(不适用于原生广告)
    IAdDataTypeBanner,                          	// 横幅(不适用于原生广告)
    IAdDataTypeMessageFlowThreeImages,          	// 信息流三小图(适用于原生广告)
    IAdDataTypeMessageFlowSmallImage,           	// 信息流广告小图(适用于原生广告)
    IAdDataTypeMessageFlowSmallImageVertical,    // 信息流广告小图竖图(仅适用于原生广告)
    IAdDataTypeMessageFlowBigImage,             	// 信息流广告大图(适用于原生广告)
    IAdDataTypeMessageFlowBigImageVertical,      // 信息流广告大图竖图(仅适用于原生广告)
    IAdDataTypeRedEnvelope,                      // 红包广告(不适用于原生广告)
    IAdDataTypeRedVideo,					 	                  // 视频广告(不适用于原生广告)
    IAdDataTypeSmallImage						                  // 小图文(仅适用于原生广告)
};
```
- 广告初始、加载数据、跳转点击
```
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
- (void)adLoaderDidFinishLoading:(DRAgentLoader *)adLoader adverType:(IAdDataType)adverType advertDataModel:(DRAgentAdvertDataModel *)advertDataModel;
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
拿到数据，创建广告View，绑定数据，添加到展示广告的视图上，这里使用SDK封装好的信息流三小图View `DRAgentMessageThreeImagesView`
```
// 创建信息流三小图
CGFloat width = [UIScreen mainScreen].bounds.size.width;
_messageThreeImagesView = [[DRAgentMessageThreeImagesView alloc] initWithFrame:CGRectMake(0, 0, width, [DRAgentMessageThreeImagesView getMessageViewHeightWithType:IAdDataTypeMessageFlowThreeImages width:width]) messageViewType:IAdDataTypeMessageFlowThreeImages delegate:self];
[self.contentView addSubview:_messageThreeImagesView];
```
- 高级使用，*以下为三小图广告的回调代理。*
```
- (void)adMessageDidClick:(DRAgentMessageView *_Nonnull)messageView adverType:(IAdDataType)adverType {
    NSLog(@"信息流三小图 点击");
}
- (void)adMessageWebViewReturn:(DRAgentMessageView *_Nonnull)messageView {
    NSLog(@"webView返回");
}
```
**详细请看demo中`Message_ThreeImgsViewController`**
#### (2)、信息流大小图文
类似信息流三小图，这里不再重复书写。
**详细请看demo中`Message_SmallImgViewController`|`Message_BigImgViewController `**
#### (3)、小图文CPV

![IMG_0D7188D78D79-1.jpeg](https://upload-images.jianshu.io/upload_images/2917199-13a4b0a6e112ad19.jpeg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

类似信息流三小图，这里不再重复书写。
**详细请看demo中`CustomSmallImgViewController`**

### 3、横幅(Banner)广告
横幅广告分为横幅广告和小横幅广告，使用`DRAgentBannerView`实例出横幅类对象的View，添加到广告展示的页面。使用小横幅广告的话，type传为`IAdDataTypeBannerLow`，代码如下简写。
```
- (DRAgentBannerView *)bannerView {
    if (_bannerView == nil) {
        CGFloat bannerHeight = [DRAgentBannerView getBannerViewHeightWithType:IAdDataTypeBanner width:kScreenWidth];
        _bannerView = [[DRAgentBannerView alloc] initWithFrame:CGRectMake(0, kTopHeight, [UIScreen mainScreen].bounds.size.width, bannerHeight) bannerViewType:IAdDataTypeBanner delegate:self];
        [self addText:bannerHeight];
    }
    return _bannerView;
}
// 加载Banner广告
[self.bannerView loadBannerRequest];
```
- 高级使用，*以下为横幅广告的回调代理。*
```
- (void)adBannerDidFinishLoading:(DRAgentBannerView *)bannerView adverType:(IAdDataType)adverType {
    NSLog(@"加载banner广告成功");
    [self.view addSubview:_bannerView];
}
- (void)adBanner:(DRAgentBannerView *)bannerView didFailToReceiveAdWithError:(NSError *)error {
    NSLog(@"加载banner广告失败  error-->%@",error);
}
- (void)adBannerDidClick:(DRAgentBannerView *)bannerView adverType:(IAdDataType)adverType {
    NSLog(@"banner广告点击");
}
- (void)adBannerDidClickCloseButton:(DRAgentBannerView *)bannerView {
    NSLog(@"banner广告关闭按钮回调");
    [bannerView cancelTimer];
    [bannerView removeFromSuperview];
}
- (void)adBannerWebViewReturn:(DRAgentBannerView *)bannerView {
    NSLog(@"banner广告从广告webView返回");
}
```
***
如果使用横幅广告的轮播功能。*在视图显示成功方法里开启轮播，在视图消失方法中和返回pop中关闭轮播，关闭定时器，以防每次请求数据 再次进入重新加载bannerView，避免内存泄漏。*
**详细请看demo中BannerViewController和LowBannerViewController**

### 4、视频广告

![video.gif](https://upload-images.jianshu.io/upload_images/2917199-5d0cce27a216ae9f.gif?imageMogr2/auto-orient/strip)

视频广告是以一个icon图标作为跳转入口加载视频广告，首先初始化视频广告icon添加展示广告页面。代码如下简写。
```
{
DRAgentRedVideoView *redVideoView = [[DRAgentRedVideoView alloc] initWithFrame:CGRectMake(kScreenWidth - 120, 100, 100, 125) delegate:self]; 
[self.view addSubview:redVideoView];
}
```
- 高级使用，*以下为视频广告的回调代理。*
```
- (void)adRedDidClick:(DRAgentRedView *)redView {
    NSLog(@"红包icon被点击");
}
- (void)adRedVideoDataLoadingFinished:(DRAgentRedVideoView *)redVideoView reciveAdWithError:(NSError *)error {
    if (!error) {
        NSLog(@"红包数据加载成功");
    } else {
        NSLog(@"红包数据加载失败 = %@",error);
    }
}
- (void)adRedVideoImageIconLoadingFinished:(DRAgentRedVideoView *)redVideoView reciveAdWithError:(NSError *)error {
    if (!error) {
        NSLog(@"红包图标数据加载成功");
    } else {
        NSLog(@"红包图标数据加载失败 = %@",error);
    }
}
- (void)adRedVideoShowVideoPlay:(DRAgentRedVideoView *)redVideoView currentIndex:(NSInteger)currectIndex {
    NSLog(@"视频广告展示播放 -- %ld",(long)currectIndex);
}
- (void)adRedVideoDidClickDownButton:(DRAgentRedVideoView *)redVideoView {
    NSLog(@"视频广告点击下载按钮");
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
