// class "interface" of the generated code. This has to be copied over from
// `../lib/cpp-generated/NativeModules.h`

#include <ReactCommon/TurboModule.h>
#include <jsi/jsilib.h>
#include <jsi/jsi.h>
#include "NativeModules.h"

namespace facebook {
namespace react {

class NativeMultiply : public MultiplyModuleCxxSpecJSI {
public:
    NativeMultiply(std::shared_ptr<CallInvoker> jsInvoker); 
    double multiply(jsi::Runtime &rt, double a, double b);
};

} // namespace react
} // namespace facebook
