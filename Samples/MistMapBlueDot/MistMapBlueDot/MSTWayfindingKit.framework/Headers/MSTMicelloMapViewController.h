//
//  WebViewController.h
//  Mist
//  Copyright © 2016 Mist. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import "MSTMapBaseViewController.h"

@protocol MSTMicelloMapDelegate;

@interface MSTMicelloMapViewController : MSTMapBaseViewController <UIWebViewDelegate,UISearchBarDelegate,MFMailComposeViewControllerDelegate> {
    __weak IBOutlet UIView *hoverView;
    __weak IBOutlet UISearchBar *searchBar;
    __weak IBOutlet NSLayoutConstraint *webviewTopConstraint;
    __weak IBOutlet UIView *levelView;
    __weak IBOutlet UIButton *flrBtn1;
    __weak IBOutlet UIButton *flrBtn3;
    __weak IBOutlet UIButton *flrBrn5;
    __weak IBOutlet UIView *levelBorderView;
}

@property (nonatomic,assign) BOOL  isMicellorLeafletMap;
@property (nonatomic,strong) NSArray *micelloCalculationArray;
@property (nonatomic,strong) NSDictionary *latLongWayFindingJson;
@property (nonatomic,strong) NSDictionary *vbDictionary;
@property (nonatomic,weak)  id <MSTMicelloMapDelegate> micelloDelegate;
@property (nonatomic, copy) NSMutableDictionary *virtualBeacons;
@property (nonatomic, assign) MSTDotConfiguration dotConfiguration;
@property (nonatomic, weak) id <MSTWidgetDelegate> widgetDelegate;


/**
 Get new instance of the MSTMicelloMapViewController object.

 @return Instance of MSTMicelloMapViewController.
 */
+ (MSTMicelloMapViewController *)getNewInstance;


/**
 Set the value of useDR flag.

 @param val BOOL.
 */
-(void) setUseDRFlag:(BOOL) val;

@end

/**
 A protocol defining method that close button has been tapped on the Micello map.
 */
@protocol MSTMicelloMapDelegate <NSObject>

/**
 Cloe button was tapped.
 */
-(void)didClickCloseBtn;

@end
