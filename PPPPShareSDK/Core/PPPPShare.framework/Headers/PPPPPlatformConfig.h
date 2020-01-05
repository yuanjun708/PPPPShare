//
//  PPPPPlatformConfig.h
//  demoSDK
//
//  Created by Balalaika on 2019/12/25.
//  Copyright © 2019 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Facebook
 */
extern NSString *const  PPPPPlatformNameFacebook;

/**
 Twitter
 */
extern NSString *const  PPPPPlatformNameTwitter;

/**
 分享到Instragram
 */
extern NSString *const  PPPPPlatformNameInstagram;

/**
 分享到Whatsapp
 */
extern NSString *const  PPPPPlatformNameWhatsapp;

/**
 *  google+
 */
extern NSString *const  PPPPPlatformNameGooglePlus;

/**
 *  FaceBookMessenger
 */
extern NSString *const  PPPPPlatformNameFaceBookMessenger;


/**
 *  授权，分享，UserProfile等操作的回调
 *
 *  @param result 表示回调的结果
 *  @param error  表示回调的错误码
 */
typedef void (^PPPPRequestCompletionHandler)(id result,NSError *error);

/**
 *  授权，分享，UserProfile等操作的回调
 *
 *  @param shareResponse 表示回调的结果
 *  @param error  表示回调的错误码
 */
typedef void (^PPPPShareCompletionHandler)(id shareResponse,NSError *error);

/**
 *  授权，分享，UserProfile等操作的回调
 *
 *  @param authResponse 表示回调的结果
 *  @param error  表示回调的错误码
 */
typedef void (^PPPPAuthCompletionHandler)(id authResponse,NSError *error);

/**
 *  授权，分享，UserProfile等操作的回调
 *
 *  @param userInfoResponse 表示回调的结果
 *  @param error  表示回调的错误码
 */
typedef void (^PPPPGetUserInfoCompletionHandler)(id userInfoResponse,NSError *error);



/**
 *  U-Share返回错误类型
 */
typedef NS_ENUM(NSInteger, PPPPPlatformErrorType) {
    PPPPPlatformErrorType_Unknow            = 2000,            // 未知错误
    PPPPPlatformErrorType_NotSupport        = 2001,            // 不支持（url scheme 没配置，或者没有配置-ObjC， 或则SDK版本不支持或则客户端版本不支持）
    PPPPPlatformErrorType_AuthorizeFailed   = 2002,            // 授权失败
    PPPPPlatformErrorType_ShareFailed       = 2003,            // 分享失败
    PPPPPlatformErrorType_RequestForUserProfileFailed = 2004,  // 请求用户信息失败
    PPPPPlatformErrorType_ShareDataNil      = 2005,             // 分享内容为空
    PPPPPlatformErrorType_ShareDataTypeIllegal = 2006,          // 分享内容不支持
    PPPPPlatformErrorType_CheckUrlSchemaFail = 2007,            // schemaurl fail
    PPPPPlatformErrorType_NotInstall        = 2008,             // 应用未安装
    PPPPPlatformErrorType_Cancel            = 2009,             // 取消操作
    PPPPPlatformErrorType_NotNetWork        = 2010,             // 网络异常
    PPPPPlatformErrorType_SourceError       = 2011,             // 第三方错误
    
    PPPPPlatformErrorType_ProtocolNotOverride = 2013,   // 对应的    PPPPPlatformProvider的方法没有实现
    PPPPPlatformErrorType_NotUsingHttps      = 2014,   // 没有用https的请求,@see PPPPGlobal isUsingHttpsWhenShareContent
    
};

/** The domain name used for the PPPPPlatformErrorType */
extern NSString* const PPPPPlatformErrorDomain;




//平台的类型
typedef NS_ENUM(NSInteger,PPPPPlatformType)
{
    PPPPPlatformType_UnKnown            = -2,
    //预定义的平台
    PPPPPlatformType_Predefine_Begin    = -1,
    PPPPPlatformType_Facebook           = 16,//Facebook
    PPPPPlatformType_Twitter            = 17,//Twitter
    PPPPPlatformType_Instagram          = 25,//Instagram
    PPPPPlatformType_Whatsapp           = 26,//Whatsapp
    PPPPPlatformType_GooglePlus         = 30,//Google+
    PPPPPlatformType_FaceBookMessenger  = 34,//FaceBookMessenger
    
    PPPPPlatformType_Predefine_end      = 999,
    
    //用户自定义的平台
    PPPPPlatformType_UserDefine_Begin = 1000,
    PPPPPlatformType_UserDefine_End = 2000,
};



//通过图片名称读取 里的平台icon
#define PPPPPlatformIconWithName(name) [NSString stringWithFormat:@"",name]

////通过图片名称读取 中的图片
#define PPPPButtonImageWithName(name) [NSString stringWithFormat:@"",name]
//

/** 本地化 */
#define UMLocalizedString(key,defaultValue) NSLocalizedStringWithDefaultValue(key,@"PPPPLocalizable", [NSBundle mainBundle], defaultValue, nil)

NS_ASSUME_NONNULL_BEGIN

@interface PPPPPlatformConfig : NSObject

@end

NS_ASSUME_NONNULL_END
