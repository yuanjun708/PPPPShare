//
//  PPPPShareManager.h
//  demoSDK
//
//  Created by Balalaika on 2019/12/24.
//  Copyright © 2019 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PPPPPlatformConfig.h"
#import "PPPPMessageObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface PPPPShareManager : NSObject

+ (instancetype)defaultManager;

/**
 appkey
 */
@property(nonatomic,strong)NSString* PPPPAppkey;
@property(nonatomic,strong)NSString* PPPPAppSecret;

/**
*  初始化平台
*
*  @param application 平台类型 @see PPPPPlatformType
*  @param launchOptions       第三方平台的appKey
*/
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/**
 *  设置平台的appkey
 *
 *  @param platformType 平台类型 @see PPPPPlatformType
 *  @param appKey       第三方平台的appKey
 *  @param appSecret    第三方平台的appSecret
 *  @param redirectURL  redirectURL
 */
- (BOOL)setPlaform:(PPPPPlatformType)platformType
            appKey:(NSString *)appKey
         appSecret:(NSString *)appSecret
       redirectURL:(NSString *)redirectURL;


/**
 *  设置分享平台
 *
 *  @param platformType  平台类型 @see PPPPPlatformType
 *  @param messageObject  分享的content @see PPPPMessageObject
 *  @param currentViewController 用于弹出类似邮件分享、短信分享等这样的系统页面
 *  @param completion   回调
 *  @discuss currentViewController 只正对sms,email等平台需要传入viewcontroller的平台，其他不需要的平台可以传入nil
 */
- (void)shareToPlatform:(PPPPPlatformType)platformType
          messageObject:(PPPPMessageObject *)messageObject
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
- (BOOL)handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

/**
 *  获得从sso或者web端回调到本app的回调
 *
 *  @param url     第三方sdk的打开本app的回调的url
 *  @param options 回调的参数
 *
 *  @return 是否处理  YES代表处理成功，NO代表不处理
 *
 */
- (BOOL)handleOpenURL:(NSURL *)url options:(NSDictionary*)options;

/**
*  获得从sso或者web端回调到本app的回调
*
*  @param url     第三方sdk的打开本app的回调的url
*  @param options 回调的参数
*
*  @return 是否处理  YES代表处理成功，NO代表不处理
*
*/
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

/**
 *  平台是否安装
 *
 *  @param platformType 平台类型 @see PPPPPlatformType
 *  @return YES 代表安装，NO 代表未安装
 */
- (BOOL)isInstall:(PPPPPlatformType)platformType;

/**
 *  当前平台是否支持分享
 *
 *  @param platformType 平台类型 @see PPPPPlatformType
 *
 *  @return YES代表支持，NO代表不支持
 */
- (BOOL)isSupport:(PPPPPlatformType)platformType;


@end

NS_ASSUME_NONNULL_END
