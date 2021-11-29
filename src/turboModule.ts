import type { TurboModule } from 'react-native-tscodegen-types';

export interface Spec extends TurboModule {
  multiply(a: number, b: number): number;
}
