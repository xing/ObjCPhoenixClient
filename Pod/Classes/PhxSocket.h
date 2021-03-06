//
//  PhxSocket.h
//  Pods
//
//  Created by Justin Schneck on 5/1/15.
//
//

#import <Foundation/Foundation.h>
#import "PhxTypes.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PhxSocketDelegate <NSObject>

- (void)phxSocketDidOpen;
- (void)phxSocketDidClose:(id)event;
- (void)phxSocketDidReceiveError:(id)error;

@end

@class PhxChannel;

@interface PhxSocket : NSObject

@property (nonatomic, weak) id<PhxSocketDelegate> delegate;
@property (nonatomic) BOOL reconnectOnError;
@property (nonatomic, readonly) NSTimeInterval heartbeatInterval;
@property (nonatomic) NSTimeInterval reconnectInterval;

- (instancetype)initWithURL:(NSURL*)url;
- (instancetype)initWithURL:(NSURL*)url heartbeatInterval:(NSTimeInterval)interval;

- (void)connect;
- (void)connectWithParams:(nullable NSDictionary*)params;
- (void)disconnect;
- (void)reconnect;

- (void)onOpen:(OnOpen)callback;
- (void)onClose:(OnClose)callback;
- (void)onError:(OnError)callback;

- (void)onMessage:(OnMessage)callback;

- (BOOL)isConnected;

- (NSString*)makeRef;

- (SocketState)socketState;

- (void)push:(NSDictionary*)data;

@end

NS_ASSUME_NONNULL_END
