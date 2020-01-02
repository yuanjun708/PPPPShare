//
//  PPPPPlatformProvider.h
//  demoSDK
//
//  Created by Balalaika on 2020/1/1.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PPPPMessageObject;

NS_ASSUME_NONNULL_BEGIN

@protocol PPPPPlatformProvider <NSObject>

@optional
/**
 *  当前UMSocialPlatformProvider对应操作的UMSocialPlatformType
 *  @discuss 当前很多平台对应多个平台类型，出现一对多的关系
 *  例如：QQ提供UMSocialPlatformType_Qzone 和 UMSocialPlatformType_QQ,用户点击分享或者认证的时候，需要区分用户分享或者认证的对应的哪个平台
 */
@property(nonatomic,assign)PPPPPlatformType socialPlatformType;

/**
*  初始化平台
*
*  @param launchOptions       第三方平台的appKey
*/
- (BOOL)ppppSocial_application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/**
 *  设置平台的appkey
 *
 *  @param appKey       第三方平台的appKey
 *  @param appSecret    第三方平台的appSecret
 *  @param redirectURL  redirectURL
 */
- (BOOL)ppppSocial_setAppKey:(NSString *)appKey
         appSecret:(NSString *)appSecret
       redirectURL:(NSString *)redirectURL;


/**
 *  设置分享平台
 *
 *  @param messageObject  分享的content @see PPPPMessageObject
 *  @param currentViewController 用于弹出类似邮件分享、短信分享等这样的系统页面
 *  @param completion   回调
 *  @discuss currentViewController 只正对sms,email等平台需要传入viewcontroller的平台，其他不需要的平台可以传入nil
 */
- (void)ppppSocial_shareMessageObject:(PPPPMessageObject *)messageObject
  currentViewController:(id)currentViewController
             completion:(PPPPRequestCompletionHandler)completion;


/**
 *  获得从sso或者web端回调到本app的回调
 *
 *  @param url               第三方sdk的打开本app的回调的url
 *  @param sourceApplication 回调的源程序
 *  @param annotation        annotation
 *
 *  @return 是否处理  YES代表处理成功，NO代表不处理
 *
 *  @note 此函数在6.3版本加入
 */
- (BOOL)ppppSocial_handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
- (BOOL)ppppSocial_handleOpenURL:(NSURL *)url options:(NSDictionary*)options;
- (BOOL)ppppSocial_application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

/**
 *  平台是否安装
 *
 *  @return YES 代表安装，NO 代表未安装
 */
- (BOOL)ppppSocial_isInstall;

/**
 *  当前平台是否支持分享
 *
 *  @return YES代表支持，NO代表不支持
 */
- (BOOL)ppppSocial_isSupport;

@end

NS_ASSUME_NONNULL_END
