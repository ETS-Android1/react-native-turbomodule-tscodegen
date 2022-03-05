/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "TurboModuleProvider.h"
#import "../cpp/react-native-multiply-module.h"

#import <React/CoreModulesPlugins.h>

// NOTE: This entire file should be codegen'ed.

namespace facebook {
namespace react {

Class TurboModuleClassProvider(const char *name) {
  return RCTCoreModulesClassProvider(name);
}

std::shared_ptr<TurboModule> TurboModuleProvider(const std::string &name, std::shared_ptr<JSCallInvoker> jsInvoker) {
  if (name == "MultiplyModule") {
    return std::make_shared<NativeMultiply>(jsInvoker);
  }
  return nullptr;
  }
}

} // namespace react
} // namespace facebook
