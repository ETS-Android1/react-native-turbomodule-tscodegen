import type { Spec } from './turboModule'

declare var _myUtilsTurboModule: Spec

export const turboModule = _myUtilsTurboModule as Spec
export type TurboModuleType = Spec
