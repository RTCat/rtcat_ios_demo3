//
//  VideoPlayer.h
//  RTCatSDK
//
//  Created by cong chen on 9/7/16.
//  Copyright © 2016 cong chen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>



/**
 * 视频播放器
 */
@interface RTCatVideoPlayer: NSObject
@end


@protocol RTCatVideoPlayerDelegate <NSObject>
/**
 *  播放器Size调整
 *
 *  @param videoPlayer RTCatVideoPlayer
 *
 */
- (void)didChangeVideoSize:(RTCatVideoPlayer*)videoPlayer Size:(CGSize)size;

@end

@interface RTCatVideoPlayer()

/**
 *  初始化播放器
 *
 *  @param frame CGRect
 *
 *  @return RTCatVideoPlayer
 */
-(instancetype)initWithFrame:(CGRect)frame;

/**
 *  播放器的 video
 */
@property (nonatomic, strong) UIView *view;
/**
 *  播放器的 delegate
 */
@property (nonatomic, strong) id<RTCatVideoPlayerDelegate> delegate;
@property (nonatomic,assign,readonly) CGRect bounds;

@end
