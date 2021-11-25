#import "MultiplyModule.h"
#import "../lib/cpp-generated/NativeModules.h"
#import "../cpp/react-native-multiply-module.h"

#import <cxxreact/CxxModule.h>

using namespace facebook;

// ObjC++ wrapper.
@implementation MultiplyModule

RCT_EXPORT_MODULE();

- (std::shared_ptr<react::TurboModule>)getTurboModuleWithJsInvoker:(std::shared_ptr<react::CallInvoker>)jsInvoker
{
  return std::make_shared<MultiplyModuleCxxSpecJSI>(jsInvoker);
}

- (std::unique_ptr<xplat::module::CxxModule>)createModule
{
  return nullptr;
}

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
  return nullptr;
}

@end

