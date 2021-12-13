import type { Spec } from './turboModule'

// TODO: we need to do some proper initialization
//       iOS every other reload does not work
//       Maybe we need to add a timeout?
//       Or just try it 3 times.

declare var _turboModule: Spec

export const turboModule = _turboModule as Spec

export type TurboModuleType = Spec
