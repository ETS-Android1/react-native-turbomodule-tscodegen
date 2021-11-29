#include "react-native-multiply-module.h"

using namespace facebook;
using namespace react;

double NativeMultiply::multiply(jsi::Runtime &rt, double a, double b) {
    return a * b;
}
