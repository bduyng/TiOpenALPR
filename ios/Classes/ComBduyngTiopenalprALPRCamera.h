//
//  ComBduyngTiopenalprALPRCamera.h
//  TiOpenALPR
//
//  Created by Duy Bao Nguyen on 9/21/20.
//

#import "TiUIView.h"
#import <AVFoundation/AVFoundation.h>
#import "ALPRCamera.h"

#ifdef __cplusplus
#include "opencv2/highgui/highgui.hpp"
#import <opencv2/videoio/cap_ios.h>
using namespace cv;
#endif

@class ALPRCamera;

typedef NS_ENUM(NSInteger, ALPRCameraAspect) {
    ALPRCameraAspectFill = 0,
    ALPRCameraAspectFit = 1,
    ALPRCameraAspectStretch = 2
};

typedef NS_ENUM(NSInteger, ALPRCameraCaptureSessionPreset) {
    ALPRCameraCaptureSessionPresetLow = 0,
    ALPRCameraCaptureSessionPresetMedium = 1,
    ALPRCameraCaptureSessionPresetHigh = 2,
    ALPRCameraCaptureSessionPresetPhoto = 3,
    ALPRCameraCaptureSessionPreset480p = 4,
    ALPRCameraCaptureSessionPreset720p = 5,
    ALPRCameraCaptureSessionPreset1080p = 6
};

typedef NS_ENUM(NSInteger, ALPRCameraTorchMode) {
    ALPRCameraTorchModeOff = AVCaptureTorchModeOff,
    ALPRCameraTorchModeOn = AVCaptureTorchModeOn,
    ALPRCameraTorchModeAuto = AVCaptureTorchModeAuto
};

NS_ASSUME_NONNULL_BEGIN

@interface ComBduyngTiopenalprALPRCamera : TiUIView <AVCaptureVideoDataOutputSampleBufferDelegate> {
  @private
  TiDimension width;
  TiDimension height;
  CGFloat autoHeight;
  CGFloat autoWidth;
  CGFloat zoomBegin;
  CGFloat zoomMax;
}

@property (nonatomic, strong) dispatch_queue_t sessionQueue;
@property (nonatomic, strong) AVCaptureSession *session;
@property (nonatomic, strong) AVCaptureDeviceInput *videoCaptureDeviceInput;
@property (nonatomic, strong) id runtimeErrorHandlingObserver;
@property (nonatomic, assign) NSInteger presetCamera;
@property (nonatomic, strong) AVCaptureVideoPreviewLayer *previewLayer;

@property (nonatomic, strong) ALPRCamera *camera;


- (void)initializeCaptureSessionInput:(NSString*)type;
- (void)startSession;
- (void)stopSession;
- (void)focusAtThePoint:(CGPoint) atPoint;

@end

NS_ASSUME_NONNULL_END
