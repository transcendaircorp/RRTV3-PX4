//
// File: RRTV3_PX4_OA_private.h
//
// Code generated for Simulink model 'RRTV3_PX4_OA'.
//
// Model version                  : 10.127
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Thu Jul  3 14:04:39 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RRTV3_PX4_OA_private_h_
#define RRTV3_PX4_OA_private_h_
#include "rtwtypes.h"
#include "RRTV3_PX4_OA_types.h"
#include "RRTV3_PX4_OA.h"
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void ScaledPressure2_Start_wrapper(void);
SFB_EXTERN_C void ScaledPressure2_Outputs_wrapper(const int16_T *u0);
SFB_EXTERN_C void ScaledPressure2_Terminate_wrapper(void);

#undef SFB_EXTERN_C

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);

#endif                                 // RRTV3_PX4_OA_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
