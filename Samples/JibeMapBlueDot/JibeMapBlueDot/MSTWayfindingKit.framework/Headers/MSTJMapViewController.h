//
//  Created by Cuong Ta on 2017-10-30.
//  Copyright © 2017 Mist. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JMapCoreKit/JMapCoreKit.h>
#import <JMapControllerKit/JMapController.h>
#import "MSTMapBaseViewController.h"



/**
 * The state of wayfinding.
 */
typedef NS_ENUM(NSInteger, MSTJMapWayfindingState) {
    MSTJMapWayfindingStateStopped    = 1 << 0,
    MSTJMapWayfindingStateArrived    = 1 << 1,
    MSTJMapWayfindingStateSetup      = 1 << 2,
    MSTJMapWayfindingStateWillStarted    = 1 << 3,
    MSTJMapWayfindingStateDidStarted = 1 << 4,
};

/**
 * Definition for the arrival result
 */
typedef struct MSTArrivalResult {
    BOOL hasArrived;
    NSUInteger distanceRemaining;
    NSTimeInterval timeRemaining;
} MSTArrivalResult;

@protocol MSTJMapViewControllerDelegate;

@interface MSTJMapViewController : MSTMapBaseViewController

@property (nonatomic, weak) id <MSTWidgetDelegate> widgetDelegate;

@property (nonatomic, weak) id <MSTJMapViewControllerDelegate> jibestreamDelegate;

/**
 * Enable to show all amenities on the map
 */
@property (nonatomic, assign) BOOL showAllAmenities;

/**
 * Enable to show all path types on the map
 */
@property (nonatomic, assign) BOOL showAllPathTypes;

/**
 * Specify the dot should be on the path
 */
@property (nonatomic, assign) BOOL snapToPath;

/**
 * Specify the dot should be on the waypoints
 */
@property (nonatomic, assign) BOOL snapToWaypoint;

/**
 * Specify the user location should be centered
 */
@property (nonatomic, assign) BOOL centerUserLocation;

/**
 * Specify the color for the map widget
 */
@property (nonatomic, copy) NSDictionary *theme;

@property (nonatomic, strong) NSNumber *rateByFoot;

/**
 * Enable verbose output of the code
 */
@property (nonatomic, assign) BOOL enableVerboseMode;

@property (nonatomic, strong) NSNumber *arrivalDistance;

+ (MSTJMapViewController *)getNewInstance;

/**
 * Fetches the destination on the current map.
 */
-(NSArray <JMapDestination *> *)getDestinationOnCurrentMap;

/**
 * Fetches destination by external ID
 * @param extID The external ID
 */
-(NSArray <JMapDestination *> *)getDestinationsByExtID:(NSString *)extID;

/**
 * Fetches all the destinations on the venue
 */
-(NSArray <JMapDestination *> *)getAllDestinations;

#pragma mark - Navigation

/**
 * Start the current navigation
 * @param destinationWaypoint <JMapWaypoint> The destination waypoint
 */
-(void)navigateToDestination:(JMapWaypoint *)destinationWaypoint;

/**
 * Start the current navigation
 * @param destinationWaypoint <JMapWaypoint> The destination waypoint
 */
-(void)navigateSilentlyToDestination:(JMapWaypoint *)destinationWaypoint;


/**
 * Stop the current navigation
 */
-(void)stopNavigation;

/**
 * Get nearest waypoint to any CGPoint
 * @param point <JMapWaypoint> The CGPoint
 */
-(JMapWaypoint *)getNearestWaypoint:(CGPoint)point;

/**
 * Get nearest waypoint to any CGPoint on the specified map id
 * @param point <JMapWaypoint> The CGPoint
 */
-(JMapWaypoint *)getNearestWaypoint:(CGPoint)point onMapWithMistMapId:(NSString *)mapId;

/**
 * check of the moving view using key
 */
-(BOOL)isMovingViewPresentWith:(NSString *)key;

/**
 * Disable the tap on the jmap elements
 */
-(void)disableTaponElement;

/**
 * Enable the tap on the jmap elements
 */
-(void)enableTaponElement;

/**
 * reverse the path drawn animation
 */
-(void)reversePathDrawnAnimation;
#pragma mark - Canvas

/**
 * Set zoom level for the map
 */
-(void)setZoomLevel:(float)zoomlevel;
/**
 * Reset zoom level for the map
 */
-(void)resetZoomLevel;
/**
 * Pan the map to this location. User centering will be disabled.
 */
-(void)focusAtLocation:(CGPoint)point;

/**
 * Pan the map to this location. User centering will be disabled.
 */
-(void)focusAtLocation:(CGPoint)point onMapWithMistMapId:(NSString *)mapId;

/**
 * This will fit the path in the viewable area
 */
-(void)fitPathInViewBound;

/**
 * Get the user's current location
 */
-(CGPoint)getUserCurrentLocation;

/**
 * Calculate the distance the user is from the waypoint
 */
-(NSUInteger )getDistanceFromWaypoint:(JMapWaypoint *)waypoint;

/**
 * Calculate the distance the between two the waypoint
 */
-(NSUInteger )getDistanceFrom:(JMapWaypoint *)startWaypoint to:(JMapWaypoint *)endWaypoint;

/*Get jibestream point from MSTPoint*/
-(CGPoint) getLocationFromMSTPoint:(CGPoint) point;

/**
 Place a custom view at a specify location in meters
 * @param view The custom view to place onto the map
 * @param point The point in meters used to place onto the map
 */
-(void)addCustomView:(UIView *)view atLocation:(CGPoint)point;

/**
 * Remove a custom view at a specify location in meters
 * @param view The custom view to remove from the map
 */
-(void)removeCustomView:(UIView *)view;

/**
 * Place a custom view at a specify location in meters on the current map
 * @param view The custom view to place onto the map
 * @param point The point in meters used to place onto the map
 */
-(void)addMovingView:(nonnull UIView *)view forKey:(nonnull NSString *)key atLocation:(CGPoint)point andTag:(int)tag;

/**
 * Place a custom view at a specify location in meters on the specified map
 * @param view The custom view to place onto the map
 * @param point The point in meters used to place onto the map
 * @param mapId map id on which we need to add the moving view 
 */
-(void)addMovingView:(nonnull UIView *)view forKey:(nonnull NSString *)key atLocation:(CGPoint)point onMapWithMistMapId:(NSString *)mapId andTag:(int)tag;

/**
 * Update a custom view at a specify location in meters on the current map
 * @param view The custom view to place onto the map
 * @param point The point in meters used to place onto the map
 */
-(void)updateMovingView:(nullable UIView *)view forKey:(nonnull NSString *)key forDuration:(NSTimeInterval)duration atLocation:(CGPoint)point;

/**
 * Update a custom view at a specify location in meters on the specified map
 * @param view The custom view to place onto the map
 * @param point The point in meters used to place onto the map
 */
-(void)updateMovingView:(nullable UIView *)view forKey:(nonnull NSString *)key forDuration:(NSTimeInterval)duration atLocation:(CGPoint)point onMapWithMistMapId:(NSString *)mapId;

/**
 * Remove a moving object from the current map;
 * @param key The identifier of the moving object
 */
-(void)removeMovingViewForKey:(nonnull NSString *)key;

/**
 * Remove all moving object from the current map with tag;
 * @param tag The tag of the moving object
 */
-(void)removeAllMovingViewWithTag:(int)tag;

/**
 * Remove all moving views on the current map
 */
-(void)removeAllMovingViews;

/**
 * Show a popup message at point
 * @param point The point in meters used to place onto the map
 */
-(void)showPopupWithMessage:(nonnull NSString *)message withImage:(nullable UIImage *)image atLocation:(CGPoint)point;

/**
 * Hide the popup message
 */
-(void)hidePopup;

#pragma mark -

-(void)showFloors;

//-(void)hideFloors;

/**
 * Shows the destinations
 */
-(void)searchTapped;

/**
 * Center the map around the user's location and switched to the user's map.
 */
-(void)centerTapped;

/**
 * Center the map around the user's location and doesn't switched to the user's map.
 */
-(void)performCenterUserLocation;

@end

@protocol MSTJMapViewControllerDelegate <NSObject>

@optional

// When the map is rendered and ready.
-(void)viewController:(MSTJMapViewController *)vc mapIsReady:(JMapMap*)map;

// When there's any error from the map.
-(void)viewControllerMapErrorEncountered:(MSTJMapViewController *)vc withError:(JMapError *)error;

// When the Search button is tapped
//-(void)viewControllerMapSearchTapped:(MSTJMapViewController *)vc;

// When the Center button is tapped
//-(void)viewControllerMapCenterTapped:(MSTJMapViewController *)vc;

// When the Info button is tapped
-(void)viewControllerMapInfoTapped:(MSTJMapViewController *)vc;

/**
 * Delegate to inform the caller if there's any errors while navigating to destination.
 * @param vc The viewController that's currently performing the task
 * @param info The reason why the navigation cannot be performed
 */
-(void)viewController:(MSTJMapViewController *)vc navigateToDestinationWithError:(NSString *)info;

/**
 * Delegate to request to navigation to the destination.
 * @param vc The viewController that's currently performing the task
 * @param waypoint The destination point to navigate.
 */
-(BOOL)viewController:(MSTJMapViewController *)vc shouldNavigateToDestination:(JMapWaypoint *)waypoint withDetails:(NSString *)info;

/**
 * Delegate to inform the caller that navigation will happen shortly
 * @param vc The viewController that's currently performing the task
 * @param waypoint The destination point to navigate.
 */
-(void)viewController:(MSTJMapViewController *)vc willNavigateToDestination:(JMapWaypoint *)waypoint;

/**
 * Delegate to inform the caller that navigation has happened
 * @param vc The viewController that's currently performing the task
 * @param waypoint The destination point to navigate.
 */
-(void)viewController:(MSTJMapViewController *)vc didNavigateToDestination:(JMapWaypoint *)waypoint;

/**
 * Delegate to inform the caller the type of navigation
 * @param vc The viewController that's currently performing the task
 * @param waypoint The destination point to navigate.
 */
-(void)viewController:(MSTJMapViewController *)vc navigateToDestination:(JMapWaypoint *)waypoint withDetails:(NSString *)info;

/**
 * Delegate to inform the caller with the navigation update like distance and time remaining
 * @param vc The viewController that's currently performing the task
 * @param mstArrivalResult the result of the navigation going on, it has the update about the distance/time remaining
 */
-(void)viewController:(MSTJMapViewController *)vc navigatationUpdate:(MSTArrivalResult *)mstArrivalResult;
/**
 * Delegate to inform the wayfinding state has changed.
 * @param vc The viewController that's currently performing the task
 * @param state MSTJMapWayfindingState The wayfinding state.
 */
-(void)viewController:(MSTJMapViewController *)vc wayfindingStateChanged:(MSTJMapWayfindingState)state;

/**
 * Delegate to inform the caller navigation HUD will be shown.
 * @param vc The viewController that's currently performing the task
 */
-(void)viewControllerWillShowNavigationMenu:(MSTJMapViewController *)vc;

/**
 * Delegate to inform the caller navigation HUD will be hidden.
 * @param vc The viewController that's currently performing the task
 */
-(void)viewControllerWillHideNavigationMenu:(MSTJMapViewController *)vc;

-(NSString *)getJibestreamSDKVersion;

/**
 * Set the useDR flag from app client
 */
-(void) setUseDRFlag:(BOOL) val;

@end
