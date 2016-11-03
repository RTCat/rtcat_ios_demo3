//
//  Receiver.h
//  RTCatSDK
//
//  Created by cong chen on 9/8/16.
//  Copyright © 2016 cong chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCatPeer.h"
#import "RTCatRemoteStream.h"

/**
 *  Receiver(接收器)
 */
@interface RTCatReceiver : RTCatPeer
@end

/**
 * Receiver Delegate
 */
@protocol RTCatReceiverDelegate <NSObject>

/**
 *  接收器收到远程流
 *
 *  @param receiver 接收器本身
 *  @param stream   远程流对象
 */
-(void)receiver:(RTCatReceiver *)receiver Stream:(RTCatRemoteStream *)stream;

/**
 *  接收器收到消息
 *
 *  @param receiver 接收器本身
 *  @param message   消息
 */
-(void)receiver:(RTCatReceiver *)receiver Message:(NSString *)message;

/**
 *  接收器收到错误
 *
 *  @param receiver 接收器本身
 *  @param error   错误
 */
-(void)receiver:(RTCatReceiver *)receiver Error:(NSError *)error;

/**
 *  接收器关闭
 *
 *  @param receiver 接收器本身
 */
-(void)receiverClose:(RTCatReceiver *)receiver;


/**
 *  接收器日志
 *
 *  @param receiver 接收器本身
 *  @param log      接收器日志
 */
-(void)receiver:(RTCatReceiver *)receiver Log:(NSDictionary *)log;



-(void)receiver:(RTCatReceiver *)receiver FilePath:(NSString *)filePath;
@end


@interface RTCatReceiver()
@property (nonatomic, strong) id <RTCatReceiverDelegate> delegate;
/**
 *  获得接收器属性
 *
 *  @return 接收器属性
 */
-(NSDictionary *)getAttr;

/**
 *  获得接收器编号
 *
 *  @return 接收器编号
 */
-(NSString *)getId;

/**
 *  获得接收器对应 Sender tokenID
 *
 *  @return tokenId
 */
-(NSString *)getSenderToken;

/**
 *  关闭接收器
 */
-(void)close;

/**
 *  回复 Sender
 */
-(void)response;

@end
