import * as React from 'react'
import { Text, View, StyleSheet } from 'react-native'
import { turboModule } from 'react-native-multiply-module'

export default function App() {
  return (
    <View style={styles.container}>
      <Text>Result: {turboModule.multiply(10230, 210000)}</Text>
    </View>
  )
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
})
