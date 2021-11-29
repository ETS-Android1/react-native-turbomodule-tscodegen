#ifndef TURBOUTILSMODULE_H
#define TURBOUTILSMODULE_H

#include <jsi/jsi.h>

#ifdef __ANDROID__
  #include <TurboModule.h>
#else
  #include <ReactCommon/TurboModule.h>
#endif

namespace turboutils {
  using namespace facebook;
  using namespace react;

  /****** TURBO MODULE STUFF BELOW *******/
  void installTurboModule(jsi::Runtime& runtime,
                          std::shared_ptr<react::CallInvoker> jsCallInvoker);
}

#endif /* TURBOUTILSMODULE_H */
