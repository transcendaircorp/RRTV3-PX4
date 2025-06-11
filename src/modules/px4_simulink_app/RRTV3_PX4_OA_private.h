//
// File: RRTV3_PX4_OA_private.h
//
// Code generated for Simulink model 'RRTV3_PX4_OA'.
//
// Model version                  : 10.106
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Jun 11 09:52:11 2025
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
