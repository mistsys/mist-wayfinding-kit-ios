//
//  MSTMapOrgCredentialsManager.h
//  MSTWayfindingKit
//
//  Created by Ajay Gantayet on 12/12/18.
//  Copyright © 2018 Mist. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MistSDK/MSTOrgCredentialsManager.h>

@protocol MSTMapOrgCredentialsManagerDelegate;

@interface MSTMapOrgCredentialsManager : NSObject

@property (nonatomic, weak) id<MSTMapOrgCredentialsManagerDelegate> delegate;

/**
 *  This method will enroll the device using the invite code provided, and returns the token and secret in the callback.
 *
 *  @param sdkToken the hash key that begins with D,S or P.
 *  @param callback  the callback with the response
 */
+(void)enrollDeviceWithToken:(NSString *)sdkToken onComplete:(void(^)(NSDictionary *response, NSError *error))callback;

/**
 *  This method will enroll the device using the invite code provided, and returns the token and secret in the callback.
 *
 *  @param tokenLink the decoded QR code or very link
 *  @param callback  the callback with the response
 */
+(void)enrollDeviceWithLink:(NSString *)tokenLink onComplete:(void(^)(NSDictionary *response, NSError *error))callback;

/**
 * This method will get the organization ID for the invite code provided
 */

+(NSString *)getOrgId;

@end

@protocol MSTMapOrgCredentialsManagerDelegate <NSObject>

@required
- (void)manager: (MSTMapOrgCredentialsManager *) manager didReceiveSecretInformation: (NSDictionary *) secretInformation;

@end
