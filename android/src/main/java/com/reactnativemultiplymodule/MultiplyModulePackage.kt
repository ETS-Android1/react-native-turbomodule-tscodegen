package com.reactnativemultiplymodule

import com.facebook.react.ReactPackage
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.uimanager.ViewManager

class MultiplyModulePackage: ReactPackage {
  override fun createNativeModules(reactContext: ReactApplicationContext)
    = listOf(MultiplyModuleModule(reactContext))

  override fun createViewManagers(reactContext: ReactApplicationContext): List<ViewManager<*, *>>
    = emptyList()
}
