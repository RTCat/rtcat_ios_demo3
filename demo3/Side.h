//
//  Side.h
//  demo3
//
//  Created by spacetime on 10/31/16.
//  Copyright © 2016 spacetime. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RTCatSDK/RTCatVideoPlayer.h>

@interface Side : NSObject
@property(weak,nonatomic) NSString *token;
@property(strong) RTCatVideoPlayer *videoPlayer;//must strong
@property int pos;

-(id)initWithParas:(NSString*)token videoPlayer:(RTCatVideoPlayer*)videoPlayer pos:(int)pos;
@end
