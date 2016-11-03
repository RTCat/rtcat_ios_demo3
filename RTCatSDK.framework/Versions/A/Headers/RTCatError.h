//
//  RTCatError.h
//  RTCatSDK
//
//  Created by cong chen on 10/20/16.
//  Copyright © 2016 cong chen. All rights reserved.
//


#ifndef RTCATError_h
#define RTCATError_h

#define RTC_EXPORT __attribute__((visibility("default")))
#define RTC_EXTERN extern RTC_EXPORT

/**
 *  RTCat Error
 */
typedef NS_ENUM(NSInteger, RTCatError) {
    /**
     * 未知错误
     */
    RTCAT_ERROR_UNKNOWN = -757,
    /**
     *  无效 Token 错误
     */
    RTCAT_ERROR_SESSION_INVALID_TOKEN,
    /**
     * token 已被使用
     */
    RTCAT_ERROR_SESSION_TOKEN_USED,
    /**
     * session 类型和 token 不匹配
     */
    RTCAT_ERROR_SESSION_TYPE_MISMATCH,
    /**
     * session 类型 不支持
     */
    RTCAT_ERROR_SESSION_TYPE_SUPPORTLESS,
    /**
     * sender 内部错误
     */
    RTCAT_ERROR_SENDER_INTERNAL_ERROR,
    /**
     * receiver 内部错误
     */
    RTCAT_ERROR_RECEIVER_INTERNAL_ERROR,
    
};

RTC_EXTERN NSString *const RTCAT_ERROR_DOMAIN_SESSION;
RTC_EXTERN NSString *const RTCAT_ERROR_DOMAIN_SENDER;
RTC_EXTERN NSString *const RTCAT_ERROR_DOMAIN_RECEIVER;

RTC_EXTERN NSString * const RTCAT_ERROR_UNKNOWN_DESP;
RTC_EXTERN NSString * const RTCAT_ERROR_SESSION_INVALID_DESP;
RTC_EXTERN NSString * const RTCAT_ERROR_SESSION_TOKEN_USED_DESP;
RTC_EXTERN NSString * const RTCAT_ERROR_SESSION_TYPE_MISMATCH_DESP;
RTC_EXTERN NSString * const RTCAT_ERROR_SESSION_TYPE_SUPPORTLESS_DESP;

RTC_EXTERN NSString * const RTCAT_ERROR_SENDER_INTERNAL_ERROR_DESP;
RTC_EXTERN NSString * const RTCAT_ERROR_RECEIVER_INTERNAL_ERROR_DESP;


#endif /* RTCATError_h */

