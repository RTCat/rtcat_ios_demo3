//
//  AbstractStream.h
//  RTCatSDK
//
//  Created by cong chen on 9/9/16.
//  Copyright © 2016 cong chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCatVideoPlayer.h"

/**
 *  抽象流
 */
@interface RTCatAbstractStream : NSObject

/**
 *  禁用音频
 */
-(void)disableAudio;
/**
 *  禁用视频
 */
-(void)disableVideo;

/**
 *  打开音频
 */
-(void)enableAudio;

/**
 *  打开视频
 */
-(void)enableVideo;

/**
 *  切换音频
 */
-(void)toggleAudio;

/**
 *  切换视频
 */
-(void)toggleVideo;

/**
 *  流是否含有音频
 *
 *  @return bool
 */
-(BOOL)hasAudio;

/**
 *  流是否含有视频
 *
 *  @return bool
 */
-(BOOL)hasVideo;

/**
 *  获得流的 id
 *
 *  @return id
 */
-(NSString *)getId;

/**
 *  播放音频
 *
 *  @param player 播放器
 */
-(void)playWithPlayer:(RTCatVideoPlayer *)player;

@end
