//
//  MSTMapBaseViewController.h
//  MSTWidget
//
//  Created by Cuong Ta on 9/22/17.
//  Copyright © 2017 Mist. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MistSDK/MistSDK.h>
#import "MSTWidgetDelegate.h"

typedef NS_OPTIONS(NSUInteger, MSTDotConfiguration) {
    MSTDotConfigurationBluedot = 0,
    MSTDotConfigurationSTPdot = 1 << 0
};


/**
 This class is the base class for all maps.
 */
@interface MSTMapBaseViewController : UIViewController

/**
 * The map the user is currently on.
 */
@property (nonatomic, strong) MSTMap *currentUserMap;


/**
 This method initializes the MistSDK and starts the location updates.
 */
-(void)startEnv;


/**
 Did connect.

 @param isConnected Bool indicating the connection state.
 */
-(void)didConnect:(BOOL)isConnected;

/**
 Did receive virtual beacons

 @param virtualBeacons List of virtual beacons for current map.
 */
-(void)didReceivedVirtualBeacons:(NSArray *)virtualBeacons;

/**
 Did receive virtual beacons
 
 @param virtualBeacons Object containing list of virtual beacons for current map.
 */
-(void)didReceiveVirtualBeacons:(NSDictionary *)virtualBeacons;

/**
 Will update relative location of the user.

 @param relativeLocation MSTPoint indicating current mist location
 @param maps List of maps. Last object contains current map
 @param dateUpdated Timestamp that the location update occured
 */
-(void)willUpdateRelativeLocation:(MSTPoint *)relativeLocation inMaps:(NSArray *)maps at:(NSDate *)dateUpdated;

/**
 Will update location of the user.

 @param location MSTPoint indicating current mist location.
 @param maps List of maps. Last object contains current map.
 @param locationSource Source of location updates (Mist/DR)
 @param dateUpdated Timestamp that the location update occured
 */
-(void)willUpdateLocation: (CLLocationCoordinate2D) location inMaps: (NSArray *) maps withSource: (SourceType) locationSource  at: (NSDate *) dateUpdated;


/**
 Did update relative location of the user.

 @param cloudPoint Current location of the user.
 @param maps List of maps. Last object contains current map.
 @param dateUpdated Timestamp that the location update occured.
 */
-(void)didUpdateRelativeLocation:(MSTPoint *)cloudPoint inMaps:(NSArray *)maps at:(NSDate *)dateUpdated;

//DR related changes:

/**
 SDK will update map.

 @param map Map object.
 @param dateUpdated Timestamp of map update.
 */
-(void)willUpdateMap: (MSTMap *)map at: (NSDate *)dateUpdated;

/**
 DR did update map.

 @param map Map object.
 @param dateUpdated Timestamp of the update.
 */
-(void)didUpdateDRMap:(MSTMap *)map at:(NSDate *)dateUpdated;

/**
 Did update DR relative location.

 @param drInfo Object containing the location update data.
 @param maps List of maps. Last object contains current map.
 @param dateUpdated Timestamp of location update.
 */
-(void)didUpdateDRRelativeLocation:(NSDictionary *)drInfo inMaps:(NSArray *)maps at:(NSDate *)dateUpdated;

/**
 Did update dr and backend relative location

 @param drInfo Object containing the DR and Backend location updates.
 @param maps List of maps. Last object contains current map.
 @param dateUpdated Timestamp of update.
 */
-(void)didUpdateDRBackendRelativeLocation: (NSDictionary *)drInfo inMaps: (NSArray *)maps at: (NSDate *)dateUpdated;

/**
 Did update Dr heading.

 @param drInfo Obejct containing the heading values.
 */
-(void)didUpdateDRHeading:(NSDictionary *)drInfo;

/**
 Did update second estimate

 @param estimate Current estimated point.
 @param maps List of maps.
 @param dateUpdated Timestamp that the second estimate was made.
 */
-(void)didUpdateSecondEstimate:(MSTPoint *)estimate inMaps:(NSArray *)maps at:(NSDate *)dateUpdated;

/**
 Did update location.

 @param location Current location.
 @param maps List of maps.
 @param locationSource Source of map Mist/DR.
 @param dateUpdated Timestamp of update.
 */
-(void)didUpdateLocation: (CLLocationCoordinate2D) location inMaps: (NSArray *) maps withSource: (SourceType) locationSource  at: (NSDate *) dateUpdated;

-(void)didUpdatePle:(NSInteger)ple andIntercept:(NSInteger)intercept inMaps:(NSArray *)maps at:(NSDate *)dateUpdated;

/**
 Backend did update map.

 @param map Map object
 @param dateUpdated Timestamp if map update.
 */
-(void)didUpdateMap:(MSTMap *)map at:(NSDate *)dateUpdated;

/**
 Did update heading.

 @param headingInfo Object containing heading info.
 */
-(void)didUpdateHeading:(CLHeading *)headingInfo;

/**
 Did range beacons in region.

 @param beacons List of MSTBeacon objects.
 @param region Object of MSTBeaconRegion type.
 */
-(void)didRangeBeacons:(NSArray<MSTBeacon *> *)beacons inRegion:(MSTBeaconRegion *)region;

/**
 Did range beacons.

 @param beacons List of beacons.
 @param region CLRegion object.
 @param dateUpdated Timestamp of update.
 */
-(void)didRangeBeacons:(NSArray *)beacons inRegion: (CLRegion *) region  at: (NSDate *) dateUpdated;

/**
 Did update LE heading.

 @param leInfo Object containing the backend heading.
 */
-(void)didUpdateLEHeading: (NSDictionary *) leInfo;

-(void)restartScan:(NSString *)message;

-(CGPoint) convertMSTPointToMapPoint:(CGPoint) point;

#pragma mark - Navigation

@end
