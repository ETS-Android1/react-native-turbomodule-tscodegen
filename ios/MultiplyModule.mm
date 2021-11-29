#import "MultiplyModule.h"
#import "react-native-multiply-module.h"

#include "TurboUtilsModule.h"
#include "Logging.h"

#import <React/RCTBridge+Private.h>
#import <React/RCTUtils.h>
#import <ReactCommon/RCTTurboModuleManager.h>
#import <jsi/jsi.h>
#import <memory>

using namespace facebook;

@implementation MultiplyModule
@synthesize bridge=_bridge;
@synthesize methodQueue = _methodQueue;

RCT_EXPORT_MODULE()

+ (BOOL)requiresMainQueueSetup {
  return YES;
}

- (void)setBridge:(RCTBridge *)bridge {
  _bridge = bridge;
  
  LOG("JSI Module initialization in setBridge()");

  RCTCxxBridge *cxxBridge = (RCTCxxBridge *)self.bridge;
  if (!cxxBridge.runtime) {
    return;
  }
  
  jsi::Runtime* jsiRuntime = (jsi::Runtime *)cxxBridge.runtime;
  auto callInvoker = bridge.jsCallInvoker;
  
  // init turbo module
  turboutils::installTurboModule(*jsiRuntime, callInvoker);
}

@end
