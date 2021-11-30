import { TurboModule, TurboModuleRegistry } from 'react-native-tscodegen-types'

// General interface for the package. Our generated cpp wrapper will be based on this
export interface Spec extends TurboModule {
  multiply(a: number, b: number): number
}

// We MUST export this accoridng to tscodegen. We are ignoring it however.
export default TurboModuleRegistry.getEnforcing<Spec>('MultiplyModule') as Spec
