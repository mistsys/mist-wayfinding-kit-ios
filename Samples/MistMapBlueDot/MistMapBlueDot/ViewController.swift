//
//  ViewController.swift
//  MistMapBlueDot
//
//  Created by Dinkar Kumar on 22/04/19.
//  Copyright © 2019 Mist. All rights reserved.
//

import UIKit
import MSTWayfindingKit
import MistSDK
class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        MSTMapOrgCredentialsManager.enrollDevice(withToken: "YOUR_ORG_SECRET_TOKEN", onComplete: { (response, error) in
            if(error == nil){
                if let mapVC = MSTFloorplanPageViewController.getNewInstance() as MSTFloorplanPageViewController?{
                    self.present(mapVC, animated: false, completion: nil)
                }
            }
        })
    }
}

