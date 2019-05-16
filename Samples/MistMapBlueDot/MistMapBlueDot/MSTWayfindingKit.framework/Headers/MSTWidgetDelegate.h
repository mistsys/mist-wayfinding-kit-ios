//
//  MSTWidgetDelegate.h
//  MicelloWidgetDemo
//
//  Created by Cuong Ta on 9/21/17.
//  Copyright © 2017 Mist. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


/**
 A protocol defining methods that send callbacks from the MSTCentralManager object to the class implementing this protocol.
 */
@protocol MSTWidgetDelegate <NSObject>

/**
 * Callback to accept the map configuration
 */
-(NSDictionary *)retrieveBootstrapInfoForWidgetMap:(id)widget;

/**
 * Callback to inform the parent that the map has been dismissed. This is a good callback to disconnect.
 */
-(void)mapDidDismissed;

@optional


/**
 MistSDK did connect.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param isConnected This value indicates whether the MistSDK is connected or not.
 */
-(void)viewController:(UIViewController *)vc didConnect:(BOOL)isConnected;


/**
 MistSDK did receive virtual beacons.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param virtualBeacons List of virtual beacons for current map.
 */
-(void)viewController:(UIViewController *)vc didReceivedVirtualBeacons:(NSArray *)virtualBeacons;

/**
 MistSDK did receive virtual beacons.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param virtualBeacons Object containing list of virtual beacons for current map.
 */
-(void)viewController:(UIViewController *)vc didReceiveVirtualBeacons:(NSDictionary *)virtualBeacons;

/**
 MistSDK will update relative location of the user.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param relativeLocation MSTPoint indicating current mist location
 @param maps List of maps. Last object contains current map
 @param dateUpdated Timestamp that the location update occured
 */
-(void)viewController:(UIViewController *)vc willUpdateRelativeLocation:(MSTPoint *)relativeLocation inMaps:(NSArray *)maps at:(NSDate *)dateUpdated;

/**
 MistSDK will update location of the user.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param location MSTPoint indicating current mist location.
 @param maps List of maps. Last object contains current map
 @param locationSource Source of location updates (Mist/DR)
 @param dateUpdated Timestamp that the location update occured
 */
-(void)viewController:(UIViewController *)vc willUpdateLocation: (CLLocationCoordinate2D) location inMaps: (NSArray *) maps withSource: (SourceType) locationSource  at: (NSDate *) dateUpdated;

/**
 MistSDK did update location of the user.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param cloudPoint Current location of the user.
 @param maps List of maps. Last object contains current map.
 @param dateUpdated Timestamp that the location update occured.
 */
-(void)viewController:(UIViewController *)vc didUpdateRelativeLocation:(MSTPoint *)cloudPoint inMaps:(NSArray *)maps at:(NSDate *)dateUpdated;

/**
 MistSDK did update second estimate

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param estimate Current estimated point.
 @param maps List of maps.
 @param dateUpdated Timestamp that the second estimate was made.
 */
-(void)viewController:(UIViewController *)vc didUpdateSecondEstimate:(MSTPoint *)estimate inMaps:(NSArray *)maps at:(NSDate *)dateUpdated;

/**
 MistSDK did update location.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param location Current location.
 @param maps List of maps.
 @param locationSource Source of map Mist/DR.
 @param dateUpdated Timestamp of update.
 */
-(void)viewController:(UIViewController *)vc didUpdateLocation: (CLLocationCoordinate2D) location inMaps: (NSArray *) maps withSource: (SourceType) locationSource  at: (NSDate *) dateUpdated;

/**
 MistSDK beacons sent.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param beacons List of beacons.
 */
-(void)viewController:(UIViewController *)vc beaconsSent:(NSMutableArray *)beacons;

/**
 MistSDK send overall number of outstanding requests.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param unansweredRequestsCount number of unanswered requests.
 */
-(void)viewController:(UIViewController *)vc overallOutstandingRequestsCount:(long) unansweredRequestsCount;

/**
 MistSDK time since request was sent with index.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param time Time request was sent.
 @param index Sequence of the request.
 */
-(void)viewController:(UIViewController *)vc time:(double)time sinceSentForCounter:(NSString *)index;

/**
 MistSDK updated PLE.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param ple Integer
 @param intercept
 @param maps array of map objects
 @param dateUpdated date that ple was updated.
 */
-(void)viewController:(UIViewController *)vc didUpdatePle:(NSInteger)ple andIntercept:(NSInteger)intercept inMaps:(NSArray *)maps at:(NSDate *)dateUpdated;

/**
 //TBD

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param interval Time interval of request
 */
-(void)viewController:(UIViewController *)vc requestOutTimeInt:(NSTimeInterval)interval;

/**
Request historic time

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param timeIntsHistoric //TBD
 */
-(void)viewController:(UIViewController *)vc requestInTimeIntsHistoric:(NSDictionary *)timeIntsHistoric;

/**
 LE updated map.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param map Map object from the backend.
 @param dateUpdated timestamp of the update.
 */
-(void)viewController:(UIViewController *)vc didUpdateMap:(MSTMap *)map at:(NSDate *)dateUpdated;

/**
MistSDK on starting the RF recording.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param recordingId Recording ID string
 @param isSuccess Did recording start successfully.
 @param message Message associated with the API.
 */
-(void)viewController:(UIViewController *)vc onStartRFRecordingResponse:(NSString *)recordingId withIsSuccess:(BOOL)isSuccess andMessage:(NSDictionary *) message;

/**
 MistSDK on stopping the RF recording.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param isSuccess Value of whether the stop API was called successfully.
 @param message
 */
-(void)viewController:(UIViewController *)vc onStopRFRecordingResponse:(BOOL)isSuccess withMessage:(NSDictionary *) message;

/**
 MistSDK did update heading.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param headingInformation Object containing the heading information.
 */
-(void)viewController:(UIViewController *)vc didUpdateHeading:(CLHeading *)headingInformation;

/**
 MistSDK did range beacons in region.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param beacons List of MSTBeacon objects.
 @param region Object of MSTBeaconRegion type.
 */
-(void)viewController:(UIViewController *)vc didRangeBeacons:(NSArray<MSTBeacon *> *)beacons inRegion:(MSTBeaconRegion *)region;

/**
 MistSDK did range beacons.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param beacons List of beacons.
 @param region CLRegion object.
 @param dateUpdated timestamp of update.
 */
-(void)viewController:(UIViewController *)vc didRangeBeacons:(NSArray *)beacons inRegion: (CLRegion *) region  at: (NSDate *) dateUpdated;

/**
 MistSDK did update LE Heading.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param leInfo Object containing the LE heading.
 */
-(void)viewController:(UIViewController *)vc didUpdateLEHeading: (NSDictionary *) leInfo;

/**
 

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param message
 */
-(void)viewController:(UIViewController *)vc restartScan:(NSString *)message;

/**
 MistSDK did update total number fo requests and responses.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param totalRequests Total number of API requests.
 @param totalResponses Total number of API responses.
 @param date Time stamp of update.
 */
-(void)viewController:(UIViewController *)vc didUpdateTotalRequests:(long)totalRequests andTotalResponses: (long)totalResponses atDate: (NSDate *) date;

/**
 MistSDK did receive notification message.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param payload Notification (Zone/Virtual beacon) object.
 */
-(void)viewController:(UIViewController *)vc didReceiveNotificationMessage:(NSDictionary *)payload;

/**
 MistSDK backend will update map.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param map Map object.
 @param dateUpdated Timestamp of map update.
 */
-(void)viewController:(UIViewController *)vc willUpdateMap: (MSTMap *)map at: (NSDate *)dateUpdated;

/**
 MistSDK did update DR relative location.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param drInfo Object containing the location update data.
 @param maps List of maps. Last object contains current map.
 @param dateUpdated Timestamp of location update.
 */
-(void)viewController:(UIViewController *)vc didUpdateDRRelativeLocation:(NSDictionary *)drInfo inMaps:(NSArray *)maps at:(NSDate *)dateUpdated;

/**
 MistSDK DR did update map.
 
 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param map Map object.
 @param dateUpdated Timestamp of the update.
 */
-(void)viewController:(UIViewController *)vc didUpdateDRMap:(MSTMap *)map at:(NSDate *)dateUpdated;

/**
 MistSDK did update dr and backend relative location

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param drInfo Object containing the DR and Backend location updates.
 @param maps List of maps. Last object contains current map.
 @param dateUpdated Timestamp of update.
 */
-(void)viewController:(UIViewController *)vc didUpdateDRBackendRelativeLocation: (NSDictionary *)drInfo inMaps: (NSArray *)maps at: (NSDate *)dateUpdated;

/**
 MistSDK did update Dr heading.

 @param vc Map viewcontroller object (Mist/Micello/Jibestream).
 @param drInfo Obejct containing the heading values.
 */
-(void)viewController:(UIViewController *)vc didUpdateDRHeading:(NSDictionary *)drInfo;

@end
