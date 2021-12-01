// Here we implement our methods that are generated by tscodegen.
// Every function gets the JSI runtime. For most methods we do not
// need this.

#include "react-native-multiply-module.h"

using namespace facebook;
using namespace react;

std::shared_ptr<MultiplyModuleCxxSpecJSI> Create(std::shared_ptr<CallInvoker> jsInvoker) {
    return std::shared_ptr<MultiplyModuleCxxSpecJSI>(new MultiplyModuleCxxSpecJSI(jsInvoker));
}

double NativeMultiply::multiply(jsi::Runtime &rt, double a, double b) {
    return a * b;
}
