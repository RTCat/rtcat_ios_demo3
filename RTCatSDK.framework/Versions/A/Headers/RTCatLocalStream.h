//
//  LocalStream.h
//  RTCatSDK
//
//  Created by cong chen on 9/7/16.
//  Copyright © 2016 cong chen. All rights reserved.
//


#import "RTCatAbstractStream.h"


/**
 *  摄像头
 */
typedef NS_ENUM(NSUInteger, RTCatCameraFacing) {
    /**
     *  前置摄像头
     */
    RTCAT_CAMERA_FRONT = 0,
    /**
     *  后置摄像头
     */
    RTCAT_CAMERA_BACK
};


/**
 *  本地流
 */
@interface RTCatLocalStream:RTCatAbstractStream


/**
 *  切换摄像头
 */
-(void)switchCamera;

@end
