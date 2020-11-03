//
//  RCTCamera.h
//  RNOpenAlpr
//
//  Created by Evan Rosenfeld on 2/24/17.
//  Copyright © 2017 CarDash. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
//#import <React/RCTBridge.h>
//#import <React/RCTEventDispatcher.h>
//#import <React/RCTUtils.h>
//#import <React/RCTLog.h>
//#import <React/UIView+React.h>
#import <AVFoundation/AVFoundation.h>

#import "ComBduyngTiopenalprALPRCamera.h"
#import "PlateResult.h"

@class ComBduyngTiopenalprALPRCamera;

@interface ALPRCamera : UIView

//@property (nonatomic, copy) RCTBubblingEventBlock onPlateRecognized;
//
- (id)initWithManager:(ComBduyngTiopenalprALPRCamera*)manager;

- (void) setPlateOutlineColor:(NSString *)color;
- (void)setShowPlateOutline:(BOOL)enabled;
- (void)setTouchToFocus:(BOOL)enabled;

- (void) updatePlateBorder:(PlateResult *)result orientation:(UIDeviceOrientation)orientation;
@end
