//
//  NSDictionary+QueryString.m
//  Pods
//
//  Created by Justin Schneck on 8/17/15.
//
//

#import "NSDictionary+QueryString.h"
#import "NSString+URLEncoding.h"

NS_ASSUME_NONNULL_BEGIN

@implementation NSDictionary (QueryString)

+ (NSDictionary *)dictionaryWithQueryString:(NSString *)queryString {
    NSMutableDictionary *dictionary = [NSMutableDictionary dictionary];
    NSArray *pairs = [queryString componentsSeparatedByString:@"&"];
    
    for (NSString *pair in pairs)
    {
        NSArray *elements = [pair componentsSeparatedByString:@"="];
        if (elements.count == 2)
        {
            NSString *key = [elements[0] stringValue];
            NSString *value = [elements[1] stringValue];
            NSString *decodedKey = [key URLDecodedString];
            NSString *decodedValue = [value URLDecodedString];
            
            if (![key isEqualToString:decodedKey]) {
                key = decodedKey;
            }
            
            if (![value isEqualToString:decodedValue]) {
                value = decodedValue;
            }
            
            [dictionary setObject:value forKey:key];
        }
    }
    
    return [NSDictionary dictionaryWithDictionary:dictionary];
}

- (NSString *)queryStringValue {
    NSMutableArray *pairs = [NSMutableArray array];
    for (NSString *key in [self keyEnumerator]) {
        id value = [self objectForKey:key];
        NSString *stringValue;
        if ([value isKindOfClass:[NSString class]]) {
            stringValue = value;
        } else if ([value respondsToSelector:@selector(stringValue)]) {
            stringValue = [value stringValue];
        } else {
            stringValue = [value description];
        }
        NSString *escapedValue = [value URLEncodedString];
        [pairs addObject:[NSString stringWithFormat:@"%@=%@", key, escapedValue]];
    }

    return [pairs componentsJoinedByString:@"&"];
}

@end

NS_ASSUME_NONNULL_END
