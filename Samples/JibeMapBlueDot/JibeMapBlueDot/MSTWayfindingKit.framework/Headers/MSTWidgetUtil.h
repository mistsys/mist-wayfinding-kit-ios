//
//  MSTWidgetUtil.h
//  MSTWidget
//
//  Created by Cuong Ta on 10/3/17.
//  Copyright © 2017 Mist. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface MSTWidgetUtil : NSObject

// Purges the SDK credentials
+(void)purgeSettingsWithCompletion:(void(^)(void))callback;

// Updates the SDK credentials
+(void)updateSettings:(NSDictionary *)settings withCompletion:(void (^)(void))callback;

// Fetches the SDK credentials
+(NSMutableDictionary *)currentSettings;



@end
