import * as React from 'react';

import { StyleSheet, View, Text } from 'react-native';
import spec from 'react-native-multiply-module';

export default function App() {
  console.log(spec);
  return (
    <View style={styles.container}>
      <Text>Result: {spec.multiply(10, 20)}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
