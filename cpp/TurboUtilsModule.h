#include <jsi/jsi.h>

#ifdef __ANDROID__
  #include <TurboModule.h>
#else
  #include <ReactCommon/TurboModule.h>
#endif

namespace utils {
  using namespace facebook;
  using namespace react;

  /****** TURBO MODULE STUFF BELOW *******/
  void installTurboModule(jsi::Runtime& runtime,
                          std::shared_ptr<CallInvoker> jsCallInvoker);
}
