//
//  Side.m
//  demo3
//
//  Created by spacetime on 10/31/16.
//  Copyright © 2016 spacetime. All rights reserved.
//

#import "Side.h"

@implementation Side

-(id)initWithParas:(NSString *)token videoPlayer:(RTCatVideoPlayer *)videoPlayer pos:(int)pos{
    if(self = [super init]){
        self.token = token;
        self.videoPlayer = videoPlayer;
        self.pos = pos;
    }
    return self;
}


@end
