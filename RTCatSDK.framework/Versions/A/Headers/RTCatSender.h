//
//  Sender.h
//  RTCatSDK
//
//  Created by cong chen on 9/8/16.
//  Copyright © 2016 cong chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCatPeer.h"

/**
 *  Sender(发送器)
 */
@interface RTCatSender : RTCatPeer
@end

/**
 *  Sender delegate
 */
@protocol RTCatSenderDelegate <NSObject>

/**
 *  发送器关闭
 *
 *  @param sender 发送器本身
 */
-(void)senderClose:(RTCatSender *)sender;

/**
 *  发送器出错
 *
 *  @param sender 发送器本身
 *  @param error  发送器错误
 */
-(void)sender:(RTCatSender *)sender error:(NSError *)error;


/**
 *  发送器 日志
 *
 *  @param sender 发送器本身
 *  @param log    发送器日志
 */
-(void)sender:(RTCatSender *)sender Log:(NSDictionary *)log;


@end


@interface RTCatSender()
@property (nonatomic, strong) id <RTCatSenderDelegate> delegate;

/**
 *  获得发送器属性
 *
 *  @return 发送器属性
 */
-(NSDictionary *)getAttr;

/**
 *  获得发送器编号
 *
 *  @return 发送器编号
 */
-(NSString *)getId;

/**
 *  发送消息
 *
 *  @param message 要发送的消息
 */
-(void)sendMessage:(NSString *)message;


/**
 *  获得发送器对应 Receiver tokenID
 *
 *  @return tokenId
 */
-(NSString *)getReceiverToken;

/**
 *  关闭发送器
 */

-(void)sendFile:(NSString*)filePath;

-(void)close;

@end
