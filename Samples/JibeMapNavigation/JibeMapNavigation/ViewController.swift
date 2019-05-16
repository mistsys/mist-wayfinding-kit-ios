//
//  ViewController.swift
//  JibeMapNavigation
//
//  Created by Dinkar Kumar on 22/04/19.
//  Copyright © 2019 Mist. All rights reserved.
//

import UIKit
import MSTWayfindingKit
import MistSDK
class ViewController: UIViewController {
    @IBOutlet weak var navigate: UIButton!
    @IBOutlet weak var stop: UIButton!
    weak var mapVC:MSTJMapViewController!
    override func viewDidLoad() {
        super.viewDidLoad()
        MSTMapOrgCredentialsManager.enrollDevice(withToken: "YOUR_ORG_SECRET_TOKEN", onComplete: { (response, error) in
            if(error == nil){
            if  let map = MSTJMapViewController.getNewInstance() as MSTJMapViewController? {
                // running it on main thread as working with view like adding the jmap as subview of current view controller and moving the navigate and stop button to front after adding the map
                DispatchQueue.main.async {
                    self.mapVC = map
                    self.addChildViewController(self.mapVC)
                    self.view.addSubview(self.mapVC.view)
                    self.mapVC.view.frame = self.view.frame
                    self.mapVC.view.center = self.view.center
                    // to move these button to front
                    self.view.bringSubview(toFront: self.navigate)
                    self.view.bringSubview(toFront: self.stop)
                    self.mapVC.disableTaponElement() // disable tap pn navigation if you want to navigate programatically, this should be after the Map code is added as child/subview
                }
            }
        }
        })
    }
    
    // 2500 is used as random x,y coordinate, which is in pixels of map image used and then we are gettting the nearest waypoint to draw the destination.
    @IBAction func onNavigate(_ sender: Any) {
        self.mapVC.navigateSilently(toDestination: self.mapVC.getNearestWaypoint(CGPoint.init(x: 2500, y: 2500)))
    }
    
    @IBAction func onStop(_ sender: Any) {
        self.mapVC.stopNavigation()
    }
}

