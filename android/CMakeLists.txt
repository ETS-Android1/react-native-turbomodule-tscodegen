cmake_minimum_required(VERSION 3.4.1)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 14)

set(build_DIR ${CMAKE_SOURCE_DIR}/build)

# the name for our library
set(PACKAGE_NAME "my_turbo_utils")  

include_directories(
        ../lib/cpp-generated
        ../cpp
        ../node_modules/react-native/React
        ../node_modules/react-native/React/Base
        ../node_modules/react-native/ReactCommon
        ../node_modules/react-native/ReactCommon/jsi
        ../node_modules/react-native/ReactCommon/callinvoker
        ../node_modules/react-native/ReactCommon/jsiexecutor/jsireact
        ../node_modules/react-native/ReactCommon/react/nativemodule
        ../node_modules/react-native/ReactCommon/react/nativemodule/core
        ../node_modules/react-native/ReactCommon/react/nativemodule/core/ReactCommon
        ../node_modules/react-native/ReactAndroid/src/main/java/com/facebook/react/turbomodule/core/jni/ReactCommon
)

# find fbjni package
find_package(fbjni REQUIRED CONFIG)

# create library "my_turbo_utils"
add_library(
        ${PACKAGE_NAME}
        SHARED
        ../node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
        ../node_modules/react-native/ReactAndroid/src/main/java/com/facebook/react/turbomodule/core/jni/ReactCommon/CallInvokerHolder.cpp
        ../node_modules/react-native/ReactCommon/react/nativemodule/core/ReactCommon/TurboModule.cpp
        ../cpp/TurboUtilsModule.cpp
        ../cpp/react-native-multiply-module.cpp
        cpp-adapter.cpp
)

# link fbjni and logger to my_turbo_utils
target_link_libraries(
        ${PACKAGE_NAME} 
        fbjni::fbjni 
        android 
        log
)

# A workaround to avoid runtime error:
# E/SoLoader: couldn't find DSO to load: libturbomodulejsijni.so
add_library(
        turbomodulejsijni
        # Sets the library as a shared library.
        SHARED
        # an empty cpp file
        ../cpp/empty.cpp
)

