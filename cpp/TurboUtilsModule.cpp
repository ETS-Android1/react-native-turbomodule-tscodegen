#include <jsi/jsilib.h>

#include "TurboUtilsModule.h"
#include "Logging.h"

#include "react-native-multiply-module.h"

namespace turboutils
{
  void installTurboModule(jsi::Runtime& runtime, std::shared_ptr<react::CallInvoker> jsCallInvoker) {

      std::shared_ptr<NativeMultiply> nativeModule =
              std::make_shared<NativeMultiply>(jsCallInvoker);

      // register UtilsTurboModule instance as global._myUtilsTurboModule
      runtime.global().setProperty(
              runtime,
              "_myUtilsTurboModule",
              jsi::Object::createFromHostObject(runtime, nativeModule));
  }
} // namespace turboutils
