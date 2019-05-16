//
//  FloorplanPageViewController.h
//  Mist
//
//  Created by Cuong Ta on 1/18/16.
//  Copyright © 2016 Mist. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MistSDK/MistSDK.h>
#import "MistManager.h"
#import "MSTWidgetDelegate.h"
#import "MSTMapBaseViewController.h"

@protocol MSTFloorplanPageViewControllerDelegate;


/**
 This object represents a mis map.
 */
@interface MSTFloorplanPageViewController : MSTMapBaseViewController
@property (nonatomic, strong) MSTPoint *currentPoint;
@property (nonatomic, weak) id <MSTWidgetDelegate> widgetDelegate;
@property (nonatomic, weak) id <MSTFloorplanPageViewControllerDelegate> mapDelegate;


/**
 Returns Instance of MSTFloorplanPageViewController class

 @return Singleton object for MSTFloorplanPageViewController class.
 */
+ (MSTFloorplanPageViewController *)getNewInstance;

#pragma mark - Canvas


/**
 Draw blue dot style dots at given points

 @param points Array of points (x,y)
 */
-(void)drawCustomerDots:(NSArray *)points;

/**
 Pan the map to this location. User centering will be disabled.

 @param point Coordinate on the map.
 */
-(void)focusAtLocation:(CGPoint)point;

/**
 Get the user's current location/

 @return User's current location
 */
-(CGPoint)getUserCurrentLocation;

/**
 Get the user's current floor location

 @return User's current floor location
 */
-(CGPoint)getUserCurrentFloorLocation;

/**
 Place a custom view at a specify location in meters

 @param view The custom view to place onto the map
 @param point The point in meters used to place onto the map
 */
-(void)addCustomView:(UIView *)view atLocation:(CGPoint)point;

/**
 Remove a custom view at a specify location in meters

 @param view The custom view to remove from the map
 */
-(void)removeCustomView:(UIView *)view;

/**
 Place a custom view at a specify location in meters on the current map

 @param view The custom view to place onto the map
 @param key The key to refer to the custom view.
 @param point The point in meters used to place onto the map
 */
-(void)addMovingView:(nonnull UIView *)view forKey:(nonnull NSString *)key atLocation:(CGPoint)point;

/**
 Update a custom view at a specify location in meters on the current map

 @param view The custom view to place onto the map.
 @param key The key to refer to the custom view.
 @param duration Duration in which the view will move from it's current location to new location.
 @param point New location to which the view has to move to.
 */
-(void)updateMovingView:(nullable UIView *)view forKey:(nonnull NSString *)key forDuration:(NSTimeInterval)duration atLocation:(CGPoint)point;

/**
 Remove a moving object from the current map;

 @param key The identifier of the moving object
 */
-(void)removeMovingViewForKey:(nonnull NSString *)key;

/**
 Remove all moving views on the current map
 */
-(void)removeAllMovingViews;

/**
 Show a popup message at point

 @param message Message to be shown in popup.
 @param image Image to be used in popup.
 @param point The point in meters used to place onto the map.
 */
-(void)showPopupWithMessage:(nonnull NSString *)message withImage:(nullable UIImage *)image atLocation:(CGPoint)point;

/**
 Hide the popup message
 */
-(void)hidePopup;

/**
 Scale up point as per the map loaded

 @param point Point to be scaled up
 @return Updated point after scaling.
 */
-(CGPoint) scaleUpPoint:(CGPoint) point;

/*Convert meters on a particular map to the actual CGPoint on the screen*/

/**
 Convert meters on a particular map to the actual CGPoint on the screen

 @param point Point in meters.
 @return Updated point in pixels.
 */
-(CGPoint) convertMetersToPixels:(CGPoint) point;

/**
 Scale up the point according to the map that has currently been loaded,
 and then convert the meters to pixels

 @param point Point in meters
 @return Scaled up point in pixels.
 */
-(CGPoint) scaleUpAndConvertMetersToPixels:(CGPoint) point;

/**
 Convert the pixels on the map view to meter values for that correspinding map

 @param point Point in pixels
 @return Point in meters.
 */
-(CGPoint) convertPixelsToMeters:(CGPoint) point;

/**
 Get list of virtual beacon objects for current map.

 @param point Point on the map from which we need the distance of virtual beacons.
 @return List of virtual beacon objects with distance param representing how far away it is from given point
 */
-(NSMutableArray *) getVBDistance: (MSTPoint *)point;

#pragma mark - Conversion --------------------------

/**
 Get the floor position using the absolute position where top left is 0,0.
This will convert any Mist position to UI position.
 
 @param position Point in meters
 @return Point in pixels
 */
-(CGPoint)getFloorPositionWithAbsolutePosition:(CGPoint)position;

/**
 Set the useDR flag from app client:

 @param val Value of dr flag. Can be true/false
 */
-(void) setUseDRFlag:(BOOL) val;

/**
 Remove any transforms and

 @param viewToBeReset Instance of the view to be reset.
 */
-(void)resetSubView:(UIView *)viewToBeReset;

-(void)rescaleSubview:(UIView *)obj;

#pragma mark -

@end

/**
 A protocol defining method that map is ready
 */
@protocol MSTFloorplanPageViewControllerDelegate <NSObject>

/**
 Informs when the map is ready to be presented.

 @param vc The Mist floor plan viewcontroller.
 @param map The Mist Map object.
 */
-(void)floorViewController:(MSTFloorplanPageViewController *)vc mapIsReady:(MSTMap *)map;

@end;

