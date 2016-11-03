//
//  ViewController.m
//  demo3
//
//  Created by spacetime on 10/28/16.
//  Copyright © 2016 spacetime. All rights reserved.
//

#import "ViewController.h"
#import <RTCatSDK/RTCatVideoPlayer.h>
#import <RTCatSDK/RTCatLocalStream.h>
#import <RTCatSDK/RTCatRemoteStream.h>
#import <RTCatSDK/RTCatAbstractStream.h>
#import <RTCatSDK/RTCat.h>
#import <RTCatSDK/RTCatSender.h>
#import <RTCatSDK/RTCatReceiver.h>
#import "Side.h"

@interface ViewController(PlayerDelegate)<RTCatVideoPlayerDelegate>

@end

@interface ViewController(SessionDelegate)<RTCatSessionDelegate>

@end

@interface ViewController(ReceiverDelegate)<RTCatReceiverDelegate>

@end

@interface ViewController(SenderDelegate)<RTCatSenderDelegate>

@end

@interface ViewController (){
    NSMutableArray *sides;
    RTCat *_cat;
    RTCatSession *_session;
    RTCatLocalStream *localStream;
    NSString *tokenId;
}


@end

int poses[4] = {0,0,0,0};


@implementation ViewController
- (void)viewDidLoad {
    [super viewDidLoad];
    sides = [NSMutableArray array];
    
    _cat = [RTCat shareInstance];
    
    localStream = [_cat createStreamWithVideo:true audio:true];
    
    [self getToken];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (void)playStream:(NSString*)token stream:(RTCatAbstractStream*)stream{
    int pos = -1;
    for(int i = 0;i < 4;i++){
        if(poses[i] == 0){
            pos = i;
            poses[i] = 1;
            break;
        }
    }
    if(pos < 0) {
        NSLog(@"there is no place to play stream");
        return;
    }
    
    
    NSLog(@"stream view play stream from %@ on pos %d",token,pos);
    
    CGSize size = self.view.bounds.size;
    
    NSLog(@"stream view size %f %f",size.width,size.width);
    
    CGRect rect;
    
    switch (pos) {
        case 0:
            rect = CGRectMake(0, 0, size.width/2, size.height/2);
            break;
        case 1:
            rect = CGRectMake(size.width/2, 0, size.width/2, size.height/2);
            break;
        case 2:
            rect = CGRectMake(0, size.height/2, size.width/2, size.height/2);
            break;
        case 3:
            rect = CGRectMake(size.width/2, size.height/2, size.width/2, size.height/2);
            break;
        default:
            break;
    }
    
    RTCatVideoPlayer *player = [[RTCatVideoPlayer alloc] initWithFrame:rect];
    
    
    player.delegate = self;
    Side *side = [[Side alloc] initWithParas:token videoPlayer:player pos:pos];

    [sides addObject:side];
    
    
    
    [self.view addSubview:player.view];
    [stream playWithPlayer:player];
}


- (void)getToken{
    NSString *sessionId = @"";
    NSString *apiKey = @"";
    NSString *apiSecret = @"";
    NSString *url = [NSString stringWithFormat:@"https://api.realtimecat.com/v0.3/sessions/%@/tokens",sessionId];
    
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:[NSURL URLWithString:url]];
    
    [request setHTTPMethod:@"POST"];
    [request setValue:@"application/x-www-form-urlencoded" forHTTPHeaderField:@"Content-Type"];
    
    [request setValue:apiKey forHTTPHeaderField:@"X-RTCAT-APIKEY"];
    [request setValue:apiSecret forHTTPHeaderField:@"X-RTCAT-SECRET"];
    
    NSString *dataString = [NSString stringWithFormat:@"session_id=%@&type=%@",sessionId,@"pub"];
    NSData *data = [dataString dataUsingEncoding:NSASCIIStringEncoding allowLossyConversion:YES];
    NSString *postLength = [NSString stringWithFormat:@"%lu",(unsigned long)[data length]];
    [request setValue:postLength forHTTPHeaderField:@"Content-Length"];
    [request setHTTPBody:data];
    
    
    NSURLConnection *conn = [[NSURLConnection alloc] initWithRequest:request delegate:self];
    
    if(conn) {
        NSLog(@"Connection Successful");
    } else {
        NSLog(@"Connection could not be made");
    }

}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData*)data{
    NSError *error = nil;
    id object = [NSJSONSerialization
                 JSONObjectWithData:data
                 options:0
                 error:&error];
    
    if([object isKindOfClass:[NSDictionary class]]){
        
        NSDictionary *results = object;
        tokenId = [results objectForKey:@"uuid"];
        NSLog(@"my token is %@",tokenId);
        
        
        [self playStream:tokenId stream:localStream];
        _session = [_cat createSessionWithToken:tokenId];
        [_session addDelegate:self];
        [_session connect];
    }
    else{
    }
    
    
}


- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error{
    NSLog(@"error %@",[error localizedDescription]);
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection{
    
}





@end



//session delegate
@implementation ViewController(SessionDelegate)

-(void)sessionIn:(NSString *)token{
    NSLog(@"%@ is in",token);
    
    //TODO 限制人数
    [_session sendStream:localStream to:token data:false attr:@{
                                                            @"test":@"test"}];
}

-(void) sessionOut:(NSString *)token{
    
    NSLog(@"%@ is out",token);

    for (Side *side in sides) {
        
        if([side.token isEqualToString:token]){
         
            dispatch_async(dispatch_get_main_queue(), ^{
                NSLog(@"remove videoPlayer %@",side.videoPlayer);
                [side.videoPlayer.view removeFromSuperview];
            });
            poses[side.pos] = 0;
            
            [sides removeObject:side];
            NSLog(@"stream view remove player %d",side.pos);
            break;
        }
    }
    
}

-(void)sessionConnected:(NSArray *)tokens{
    NSLog(@"connected");
    
    [_session sendStream:localStream data:false attr:@{
                                                   @"test":@"test"} ];
}

-(void)sessionClose{
    
}

-(void)sessionError:(NSError *)error{
    NSLog(@"session error -> %@",error);
}

-(void)sessionLocal:(RTCatSender *)sender{
    sender.delegate = self;
}

-(void)sessionRemote:(RTCatReceiver *)receiver{
    receiver.delegate = self;
    [receiver response];
}

-(void)sessionMessage:(NSString *)message from:(NSString *)tokenId{
}

@end

@implementation ViewController(ReceiverDelegate)
-(void)receiverClose:(RTCatReceiver *)receiver{
    
}

-(void)receiver:(RTCatReceiver *)receiver Stream:(RTCatRemoteStream *)stream{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self playStream:[receiver getSenderToken] stream:stream];
    });
    
    
}

-(void)receiver:(RTCatReceiver *)receiver Error:(NSError *)error{
    
}

-(void)receiver:(RTCatReceiver *)receiver Message:(NSString *)message{
    
}

-(void)receiver:(RTCatReceiver *)receiver Log:(NSDictionary *)log{
    
}

-(void)receiver:(RTCatReceiver *)receiver FilePath:(NSString *)filePath{
    
}
@end

@implementation ViewController(SenderDelegate)

-(void)senderClose:(RTCatSender *)sender{
    
}

-(void)sender:(RTCatSender *)sender error:(NSError *)error{
    
}


-(void)sender:(RTCatSender *)sender Log:(NSDictionary *)log{
    
}

@end

@implementation  ViewController(PlayerDelegate)

-(void)didChangeVideoSize:(RTCatVideoPlayer *)videoPlayer Size:(CGSize)size{
    CGRect bounds = videoPlayer.bounds;
    
    
    float A_W = bounds.size.width;
    float A_H = bounds.size.height;
    
    float B_W = size.width;
    float B_H = size.height;
    
    float W,H;
    
    if(A_W/A_H < B_W/B_H){ //定宽
        W = A_W;
        H = W * B_H/B_W;
    }else{ //定高
        H = A_H;
        W = H * B_W/B_H;
    }
    
    bounds.size.width = W;
    bounds.size.height = H;
    
    videoPlayer.view.frame = bounds;
    videoPlayer.view.center = CGPointMake(CGRectGetMidX(bounds), CGRectGetMidY(bounds));
    
    [self.view setNeedsLayout];
}

@end




