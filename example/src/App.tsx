import * as React from 'react';
import { StyleSheet, Text, View } from 'react-native';
import { MyUtilsTurbo } from 'react-native-multiply-module';

export default function App() {
  return (
    <View style={styles.container}>
      <Text>Result: {MyUtilsTurbo.multiply(10230, 210000)}</Text>
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
