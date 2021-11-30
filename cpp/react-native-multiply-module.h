// class "interface" of the generated code. This has to be copied over from
// `../lib/cpp-generated/NativeModules.h`


#include "NativeModules.h"

#include <jsi/jsilib.h>
#include <jsi/jsi.h>


namespace facebook {
namespace react {

class NativeMultiply : public MultiplyModuleCxxSpecJSI {
    using MultiplyModuleCxxSpecJSI::MultiplyModuleCxxSpecJSI;
public:
    double multiply(jsi::Runtime &rt, double a, double b);
};

} // namespace react
} // namespace facebook
