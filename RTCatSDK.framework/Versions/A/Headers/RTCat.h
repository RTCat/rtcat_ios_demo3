//
//  RTCat.h
//  RTCatSDK
//
//  Created by cong chen on 9/7/16.
//  Copyright © 2016 cong chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCatLocalStream.h"
#import "RTCatSession.h"

/**
 *  当前 iOS SDK 支持的编码
 */
typedef NS_ENUM(NSUInteger, RTCatSupportCodec) {
    /**
     *  h264      
     */
    RTCAT_CODEC_H264   = 0,
    /**
     *  vp8 (默认)
     */
    RTCAT_CODEC_VP8,
    
};




/**
 *  RTCatSDK iOS SDK入口,用于创建 Session 和 Stream
 */
@interface RTCat : NSObject

/**
 *  单例模式创建 RTCat 对象
 *
 *  @return RTCat 对象
 */
+ (RTCat *)shareInstance;

/**
 *  回收 RTCat
 */
+ (void)release;

/**
 *  创建 Stream
 *
 *  @param video Stream 是否包含视频
 *  @param audio Stream 是否包含音频
 *
 *  @return 本地流对象
 */
-(RTCatLocalStream *)createStreamWithVideo:(BOOL)video audio:(BOOL)audio;


/**
 *  创建 Stream
 *
 *  @param video  是否包含视频
 *  @param audio  是否包含音频
 *  @param facing 摄像头朝向
 *  @param fps    fps
 *  @param height 视频高度
 *  @param width  视频宽度
 *
 *  @return 本地流对象
 */
-(RTCatLocalStream *)createStreamWithVideo:(BOOL)video audio:(BOOL)audio facing:(RTCatCameraFacing)facing fps:(unsigned int)fps
                                    height:(unsigned int)height width:(unsigned int)width;

/**
 *  创建 Session
 *
 *  @param token 连接Session的Token
 *
 *  @return Session对象
 */
-(RTCatSession *)createSessionWithToken:(NSString *)token;

/**
 *  创建 Session
 *
 *  @param token 连接Session的Token
 *  @param url   私有云地址
 *  @param type  Session类型
 *
 *  @return Session对象
 */
-(RTCatSession *)createSessionWithToken:(NSString *)token url:(NSString *)url type:(RTCatSessionType)type;


/**
 *  切换音频输出设备
 */
- (void)switchAudioOutputDevice;


-(void)setDefaultCodec:(RTCatSupportCodec )codec;

@end
