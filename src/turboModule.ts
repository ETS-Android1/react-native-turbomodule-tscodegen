import { TurboModule, TurboModuleRegistry } from 'react-native-tscodegen-types';

export interface Spec extends TurboModule {
  multiply(a: number, b: number): number;
}

export default TurboModuleRegistry.getEnforcing<Spec>('MultiplyModule') as Spec;
