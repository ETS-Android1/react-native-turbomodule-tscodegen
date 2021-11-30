#import "MultiplyModule.h"
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

// Entry point for registering this module
- (void)setBridge:(RCTBridge *)bridge {
  _bridge = bridge;
  
  LOG("JSI Module initialization in setBridge()");

  // Do not do anything if we can't access the bridge
  // e.g. Chrome Debugger mode
  RCTCxxBridge *cxxBridge = (RCTCxxBridge *)self.bridge;
  if (!cxxBridge.runtime) {
    return;
  }
  
  // get the jsCallinvoker
  jsi::Runtime* jsiRuntime = (jsi::Runtime *)cxxBridge.runtime;
  auto callInvoker = bridge.jsCallInvoker;
  
  // installs the turbomodule
  utils::installTurboModule(*jsiRuntime, callInvoker);
}

@end
