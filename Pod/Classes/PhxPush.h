//
//  PhxPush.h
//  Pods
//
//  Created by Justin Schneck on 5/1/15.
//
//

#import <Foundation/Foundation.h>
#import "PhxTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class PhxChannel;

@interface PhxPush : NSObject

@property (nonatomic, strong, readonly) NSString *event;
@property (nonatomic, strong, readonly) NSDictionary *payload;

- (instancetype)initWithChannel:(PhxChannel*)channel
                          event:(NSString*)event
                        payload:(NSDictionary*)payload;

- (void)send;

- (PhxPush *)onReceive:(NSString *)status callback:(OnMessage)callback;
- (PhxPush *)after:(NSTimeInterval)timeInterval callback:(After)callback;

@end

NS_ASSUME_NONNULL_END