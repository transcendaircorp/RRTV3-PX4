#ifndef _SCALEDPRESSURE2_CGEN_WRAPPER_H_
#define _SCALEDPRESSURE2_CGEN_WRAPPER_H_
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void ScaledPressure2_Outputs_wrapper_cgen(const int16_T *u0);

#undef SFB_EXTERN_C
#endif
