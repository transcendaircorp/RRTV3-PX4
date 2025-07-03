#include <string.h>
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "ScaledPressure2_cgen_wrapper.h"
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void ScaledPressure2_Outputs_wrapper(const int16_T *u0);
void ScaledPressure2_Outputs_wrapper_cgen(const int16_T *u0)
{
  ScaledPressure2_Outputs_wrapper(u0);
}

#undef SFB_EXTERN_C
