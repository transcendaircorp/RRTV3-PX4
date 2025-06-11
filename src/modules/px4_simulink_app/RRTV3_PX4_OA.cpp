//
// File: RRTV3_PX4_OA.cpp
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
#include "RRTV3_PX4_OA.h"
#include "rtwtypes.h"
#include "RRTV3_PX4_OA_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include "RRTV3_PX4_OA_private.h"
#include <string.h>
#include <float.h>
#include "rt_defines.h"

// Block signals (default storage)
B_RRTV3_PX4_OA_T RRTV3_PX4_OA_B;

// Block states (default storage)
DW_RRTV3_PX4_OA_T RRTV3_PX4_OA_DW;

// Real-time model
RT_MODEL_RRTV3_PX4_OA_T RRTV3_PX4_OA_M_ = RT_MODEL_RRTV3_PX4_OA_T();
RT_MODEL_RRTV3_PX4_OA_T *const RRTV3_PX4_OA_M = &RRTV3_PX4_OA_M_;

// Forward declaration for local functions
static real_T RRTV3_PX4_OA_mod(real_T x);
static real_T RRTV3_PX4_OA_rt_remd_snf(real_T u0, real_T u1);
static void RRTV3_PX4_OA_sind(real_T *x);
static void RRTV3_PX4_OA_cosd(real_T *x);
static void RRTV3_PX4_OA_diff(const real_T x[20], real_T y[19]);
static void RRTV3_PX4_OA_minimum(const real_T x[20], real_T *ex, int32_T *idx);
static void RRTV3_PX4_OA_GetToAltitude(const captured_var_RRTV3_PX4_OA_T
  *conv_m_to_ft, const captured_var_RRTV3_PX4_OA_T *conv_ms_to_fpm, real_T
  AltCmd_ft, real_T FPMCmd, real_T alt_m, real_T *vvcmd, real_T *comp_flag);
static void RRTV3_PX4_OA_AUTOFLIGHT(const real_T Params[67], const real_T d_inc
  [20], const real_T NAV[9], const real_T States[13], real_T b_clock, const
  real_T mem_in[22], const real_T Integrated[10], real_T AUTOFLIGHT_CMDS[15],
  real_T AF_MODES[7], real_T mem_out[22]);
static void RRTV3_PX4_ProcessInceptorInputs(const real_T Params[67], const
  real_T d_inc[20], const real_T States[13], const real_T AUTOFLIGHT[15], const
  real_T Integrated[10], const real_T mem_in[8], real_T VVCmdVec[2], real_T
  *AccCmd, real_T *VelCmd_kt, real_T *FPACmd, real_T *BankCmd, real_T
  *YawRateCmd, real_T TBI[10], real_T mem[8]);
static void RRTV3_PX4_OA_FFMPitchControl(real_T KTIV, real_T KTPV, real_T K_TRIM,
  real_T K_PITCHFF, real_T th_c, real_T VVCmd, real_T VertAccCmd_g, real_T
  HorzAccCmd_g, real_T VV, real_T horz_acc, real_T F, real_T pitch_shadow,
  real_T specified_rate, real_T spd_pri, real_T *pitch_cmd, real_T
  *pitch_cmd_rate);
static void RRTV3_PX4_OA_TCS_RRTV(real_T AccCmd, const real_T VVCmd[2], real_T
  VCmdkt, const real_T TCSGains[10], const real_T TCSParams[35], const real_T
  WingParams[6], const real_T PRIORITY[6], const real_T Integrated[5], const
  real_T memory_in[2], const real_T States[5], real_T *PitchCmd, real_T *TWCmd,
  real_T *WingCmd, real_T *TAICmd, real_T Debug[2], real_T TBI[5], real_T
  memory_out[2]);
static void RRTV3_PX4_OA_PWM_setupImpl_p(px4_internal_block_PWM_RRTV3__T *obj,
  boolean_T armPWM, boolean_T forceFailsafe);
static void RRTV3_PX4_OA_PWM_setupImpl(px4_internal_block_PWM_RRTV3__T *obj,
  boolean_T armPWM, boolean_T forceFailsafe);
static void rate_monotonic_scheduler(void);
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void RRTV3_PX4_OA_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(RRTV3_PX4_OA_M, 1));
}

//
//         This function updates active task flag for each subrate
//         and rate transition flags for tasks that exchange data.
//         The function assumes rate-monotonic multitasking scheduler.
//         The function must be called at model base rate so that
//         the generated code self-manages all its subrates and rate
//         transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // To ensure a deterministic data transfer between two rates,
  //  data is transferred at the priority of a fast task and the frequency
  //  of the slow task.  The following flags indicate when the data transfer
  //  happens.  That is, a rate interaction flag is set true when both rates
  //  will run, and false otherwise.


  // tid 0 shares data with slower tid rate: 1
  RRTV3_PX4_OA_M->Timing.RateInteraction.TID0_1 =
    (RRTV3_PX4_OA_M->Timing.TaskCounters.TID[1] == 0);

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (RRTV3_PX4_OA_M->Timing.TaskCounters.TID[1])++;
  if ((RRTV3_PX4_OA_M->Timing.TaskCounters.TID[1]) > 2) {// Sample time: [0.06s, 0.0s] 
    RRTV3_PX4_OA_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Function for MATLAB Function: '<S6>/LinVel Bus + INS'
static real_T RRTV3_PX4_OA_mod(real_T x)
{
  real_T r;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 360.0);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += 360.0;
    }
  }

  return r;
}

static real_T RRTV3_PX4_OA_rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      RRTV3_PX4_OA_B.q = ceil(u1);
    } else {
      RRTV3_PX4_OA_B.q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != RRTV3_PX4_OA_B.q)) {
      RRTV3_PX4_OA_B.q = fabs(u0 / u1);
      if (!(fabs(RRTV3_PX4_OA_B.q - floor(RRTV3_PX4_OA_B.q + 0.5)) > DBL_EPSILON
            * RRTV3_PX4_OA_B.q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S13>/MATLAB Function'
static void RRTV3_PX4_OA_sind(real_T *x)
{
  int8_T n;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    RRTV3_PX4_OA_B.b_x_m = RRTV3_PX4_OA_rt_remd_snf(*x, 360.0);
    RRTV3_PX4_OA_B.absx_n = fabs(RRTV3_PX4_OA_B.b_x_m);
    if (RRTV3_PX4_OA_B.absx_n > 180.0) {
      if (RRTV3_PX4_OA_B.b_x_m > 0.0) {
        RRTV3_PX4_OA_B.b_x_m -= 360.0;
      } else {
        RRTV3_PX4_OA_B.b_x_m += 360.0;
      }

      RRTV3_PX4_OA_B.absx_n = fabs(RRTV3_PX4_OA_B.b_x_m);
    }

    if (RRTV3_PX4_OA_B.absx_n <= 45.0) {
      RRTV3_PX4_OA_B.b_x_m *= 0.017453292519943295;
      n = 0;
    } else if (RRTV3_PX4_OA_B.absx_n <= 135.0) {
      if (RRTV3_PX4_OA_B.b_x_m > 0.0) {
        RRTV3_PX4_OA_B.b_x_m = (RRTV3_PX4_OA_B.b_x_m - 90.0) *
          0.017453292519943295;
        n = 1;
      } else {
        RRTV3_PX4_OA_B.b_x_m = (RRTV3_PX4_OA_B.b_x_m + 90.0) *
          0.017453292519943295;
        n = -1;
      }
    } else if (RRTV3_PX4_OA_B.b_x_m > 0.0) {
      RRTV3_PX4_OA_B.b_x_m = (RRTV3_PX4_OA_B.b_x_m - 180.0) *
        0.017453292519943295;
      n = 2;
    } else {
      RRTV3_PX4_OA_B.b_x_m = (RRTV3_PX4_OA_B.b_x_m + 180.0) *
        0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = sin(RRTV3_PX4_OA_B.b_x_m);
      break;

     case 1:
      *x = cos(RRTV3_PX4_OA_B.b_x_m);
      break;

     case -1:
      *x = -cos(RRTV3_PX4_OA_B.b_x_m);
      break;

     default:
      *x = -sin(RRTV3_PX4_OA_B.b_x_m);
      break;
    }
  }
}

// Function for MATLAB Function: '<S12>/MATLAB Function'
static void RRTV3_PX4_OA_cosd(real_T *x)
{
  int8_T n;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    RRTV3_PX4_OA_B.b_x = RRTV3_PX4_OA_rt_remd_snf(*x, 360.0);
    RRTV3_PX4_OA_B.absx = fabs(RRTV3_PX4_OA_B.b_x);
    if (RRTV3_PX4_OA_B.absx > 180.0) {
      if (RRTV3_PX4_OA_B.b_x > 0.0) {
        RRTV3_PX4_OA_B.b_x -= 360.0;
      } else {
        RRTV3_PX4_OA_B.b_x += 360.0;
      }

      RRTV3_PX4_OA_B.absx = fabs(RRTV3_PX4_OA_B.b_x);
    }

    if (RRTV3_PX4_OA_B.absx <= 45.0) {
      RRTV3_PX4_OA_B.b_x *= 0.017453292519943295;
      n = 0;
    } else if (RRTV3_PX4_OA_B.absx <= 135.0) {
      if (RRTV3_PX4_OA_B.b_x > 0.0) {
        RRTV3_PX4_OA_B.b_x = (RRTV3_PX4_OA_B.b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        RRTV3_PX4_OA_B.b_x = (RRTV3_PX4_OA_B.b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (RRTV3_PX4_OA_B.b_x > 0.0) {
      RRTV3_PX4_OA_B.b_x = (RRTV3_PX4_OA_B.b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      RRTV3_PX4_OA_B.b_x = (RRTV3_PX4_OA_B.b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = cos(RRTV3_PX4_OA_B.b_x);
      break;

     case 1:
      *x = -sin(RRTV3_PX4_OA_B.b_x);
      break;

     case -1:
      *x = sin(RRTV3_PX4_OA_B.b_x);
      break;

     default:
      *x = -cos(RRTV3_PX4_OA_B.b_x);
      break;
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

// Function for MATLAB Function: '<S42>/MATLAB Function1'
static void RRTV3_PX4_OA_diff(const real_T x[20], real_T y[19])
{
  real_T work;
  work = x[0];
  for (int32_T m = 0; m < 19; m++) {
    real_T tmp2;
    tmp2 = work;
    work = x[m + 1];
    y[m] = work - tmp2;
  }
}

// Function for MATLAB Function: '<S42>/MATLAB Function1'
static void RRTV3_PX4_OA_minimum(const real_T x[20], real_T *ex, int32_T *idx)
{
  int32_T b_idx;
  int32_T k;
  if (!rtIsNaN(x[0])) {
    b_idx = 1;
  } else {
    boolean_T exitg1;
    b_idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 21)) {
      if (!rtIsNaN(x[k - 1])) {
        b_idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_idx == 0) {
    *ex = x[0];
    *idx = 1;
  } else {
    *ex = x[b_idx - 1];
    *idx = b_idx;
    for (k = b_idx + 1; k < 21; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (*ex > x_0) {
        *ex = x_0;
        *idx = k;
      }
    }
  }
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static void RRTV3_PX4_OA_GetToAltitude(const captured_var_RRTV3_PX4_OA_T
  *conv_m_to_ft, const captured_var_RRTV3_PX4_OA_T *conv_ms_to_fpm, real_T
  AltCmd_ft, real_T FPMCmd, real_T alt_m, real_T *vvcmd, real_T *comp_flag)
{
  *comp_flag = 0.0;
  RRTV3_PX4_OA_B.alt_ft = alt_m * conv_m_to_ft->contents;
  RRTV3_PX4_OA_B.dalt_ft = AltCmd_ft - RRTV3_PX4_OA_B.alt_ft;
  RRTV3_PX4_OA_B.u1_g = fabs(RRTV3_PX4_OA_B.dalt_ft) / (FPMCmd / 20.0);
  if (rtIsNaN(RRTV3_PX4_OA_B.dalt_ft)) {
    RRTV3_PX4_OA_B.dalt_ft = (rtNaN);
  } else if (RRTV3_PX4_OA_B.dalt_ft < 0.0) {
    RRTV3_PX4_OA_B.dalt_ft = -1.0;
  } else {
    RRTV3_PX4_OA_B.dalt_ft = (RRTV3_PX4_OA_B.dalt_ft > 0.0);
  }

  if ((RRTV3_PX4_OA_B.u1_g >= 1.0) || rtIsNaN(RRTV3_PX4_OA_B.u1_g)) {
    RRTV3_PX4_OA_B.u1_g = 1.0;
  }

  *vvcmd = FPMCmd * RRTV3_PX4_OA_B.dalt_ft * RRTV3_PX4_OA_B.u1_g /
    conv_ms_to_fpm->contents;
  if (fabs(RRTV3_PX4_OA_B.alt_ft - AltCmd_ft) < 2.0) {
    *vvcmd = 0.0;
    *comp_flag = 1.0;
  }
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static void RRTV3_PX4_OA_AUTOFLIGHT(const real_T Params[67], const real_T d_inc
  [20], const real_T NAV[9], const real_T States[13], real_T b_clock, const
  real_T mem_in[22], const real_T Integrated[10], real_T AUTOFLIGHT_CMDS[15],
  real_T AF_MODES[7], real_T mem_out[22])
{
  int32_T AXN_pressed;
  int32_T DXN_pressed;
  int32_T FAPMODE;
  int32_T LDG_pressed;
  int32_T LowSpeedLNAV;
  int32_T M1_pressed;
  int32_T M2_pressed;
  int32_T M3_pressed;
  int32_T M4_pressed;
  int32_T M5_pressed;
  int32_T NAV_pressed;
  int32_T PERFORM_LNAV;
  int32_T PERFORM_SPD;
  int32_T PERFORM_VNAV;
  int32_T TKO_pressed;
  AUTOFLIGHT_CMDS[0] = 0.0;
  AUTOFLIGHT_CMDS[1] = 0.0;
  AUTOFLIGHT_CMDS[2] = 0.0;
  AUTOFLIGHT_CMDS[3] = 0.0;
  AUTOFLIGHT_CMDS[4] = 0.0;
  AUTOFLIGHT_CMDS[5] = 0.0;
  RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft = Params[64];
  RRTV3_PX4_OA_B.TKOMODE = mem_in[0];
  RRTV3_PX4_OA_B.DXNMODE = mem_in[1];
  RRTV3_PX4_OA_B.NAVMODE = mem_in[2];
  RRTV3_PX4_OA_B.AXNMODE = mem_in[3];
  RRTV3_PX4_OA_B.LDGMODE = mem_in[4];
  RRTV3_PX4_OA_B.PROGMANEUVER = mem_in[6];
  RRTV3_PX4_OA_B.sequencer = mem_in[18];
  mem_out[20] = mem_in[20];
  RRTV3_PX4_OA_B.stopwatch_active = mem_in[19];
  RRTV3_PX4_OA_B.conv_ms_to_fpm.contents = 196.79999999999998;
  RRTV3_PX4_OA_B.conv_m_to_ft.contents = 3.28;
  RRTV3_PX4_OA_B.VCS_ms_tmp = States[4] * 0.51444;
  RRTV3_PX4_OA_B.VREF_FWD_ms = States[5] / 0.51444;
  RRTV3_PX4_OA_B.hAGL_ft_c = States[10] * 3.28;
  RRTV3_PX4_OA_B.HDG_f = States[2] * 180.0 / 3.1415926535897931;
  TKO_pressed = 0;
  DXN_pressed = 0;
  NAV_pressed = 0;
  AXN_pressed = 0;
  LDG_pressed = 0;
  M1_pressed = 0;
  M2_pressed = 0;
  M3_pressed = 0;
  M4_pressed = 0;
  M5_pressed = 0;
  if (mem_in[17] == 1.0) {
    if (d_inc[4] != mem_in[7]) {
      TKO_pressed = 1;
    }

    if (d_inc[5] != mem_in[8]) {
      DXN_pressed = 1;
    }

    if (d_inc[6] != mem_in[9]) {
      NAV_pressed = 1;
    }

    if (d_inc[7] != mem_in[10]) {
      AXN_pressed = 1;
    }

    if (d_inc[8] != mem_in[11]) {
      LDG_pressed = 1;
    }

    if (d_inc[9] != mem_in[12]) {
      M1_pressed = 1;
    }

    if (d_inc[10] != mem_in[13]) {
      M2_pressed = 1;
    }

    if (d_inc[11] != mem_in[14]) {
      M3_pressed = 1;
    }

    if (d_inc[12] != mem_in[15]) {
      M4_pressed = 1;
    }

    if (d_inc[13] != mem_in[16]) {
      M5_pressed = 1;
    }
  }

  PERFORM_LNAV = 0;
  PERFORM_VNAV = 0;
  PERFORM_SPD = 0;
  FAPMODE = 0;
  LowSpeedLNAV = 0;
  if ((mem_in[2] == 1.0) && (NAV_pressed == 1)) {
    RRTV3_PX4_OA_B.NAVMODE = 0.0;
    RRTV3_PX4_OA_B.PROGMANEUVER = 0.0;
    RRTV3_PX4_OA_B.TKOMODE = 0.0;
    RRTV3_PX4_OA_B.LDGMODE = 0.0;
    NAV_pressed = 0;
  }

  if ((RRTV3_PX4_OA_B.NAVMODE == 0.0) && (RRTV3_PX4_OA_B.PROGMANEUVER == 0.0) &&
      (NAV_pressed == 1)) {
    RRTV3_PX4_OA_B.NAVMODE = 0.5;
    NAV_pressed = 0;
  }

  if ((RRTV3_PX4_OA_B.NAVMODE == 0.5) && (RRTV3_PX4_OA_B.PROGMANEUVER == 0.0)) {
    if (M1_pressed != 0) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 1.0;
      M1_pressed = 0;
      RRTV3_PX4_OA_B.NAVMODE = 0.75;
    }

    if (M2_pressed != 0) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 2.0;
      M2_pressed = 0;
      RRTV3_PX4_OA_B.NAVMODE = 0.75;
    }

    if (M3_pressed != 0) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 3.0;
      M3_pressed = 0;
      RRTV3_PX4_OA_B.NAVMODE = 0.75;
    }

    if (M4_pressed != 0) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 4.0;
      M4_pressed = 0;
      RRTV3_PX4_OA_B.NAVMODE = 0.75;
    }

    if (M5_pressed != 0) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 5.0;
      M5_pressed = 0;
      RRTV3_PX4_OA_B.NAVMODE = 0.75;
    }
  }

  if (((RRTV3_PX4_OA_B.PROGMANEUVER == 1.0) && (M1_pressed != 0)) ||
      ((RRTV3_PX4_OA_B.PROGMANEUVER == 2.0) && (M2_pressed != 0)) ||
      ((RRTV3_PX4_OA_B.PROGMANEUVER == 3.0) && (M3_pressed != 0)) ||
      ((RRTV3_PX4_OA_B.PROGMANEUVER == 4.0) && (M4_pressed != 0)) ||
      ((RRTV3_PX4_OA_B.PROGMANEUVER == 5.0) && (M5_pressed != 0))) {
    RRTV3_PX4_OA_B.PROGMANEUVER = 0.0;
    RRTV3_PX4_OA_B.NAVMODE = 0.0;
    NAV_pressed = 0;
    M1_pressed = 0;
    M2_pressed = 0;
    M3_pressed = 0;
    M4_pressed = 0;
    M5_pressed = 0;
  }

  if ((RRTV3_PX4_OA_B.NAVMODE == 0.5) && (RRTV3_PX4_OA_B.PROGMANEUVER == 0.0) &&
      (NAV_pressed != 0)) {
    RRTV3_PX4_OA_B.NAVMODE = 0.0;
    NAV_pressed = 0;
  }

  if ((RRTV3_PX4_OA_B.NAVMODE == 0.75) && (NAV_pressed == 1)) {
    RRTV3_PX4_OA_B.NAVMODE = 1.0;
    if ((!(RRTV3_PX4_OA_B.hAGL_ft_c >= Params[64] - 2.0)) && (NAV[3] == 1.0)) {
      RRTV3_PX4_OA_B.TKOMODE = 1.0;
    }
  }

  if ((RRTV3_PX4_OA_B.NAVMODE == 1.0) && (States[12] > 0.0) &&
      (RRTV3_PX4_OA_B.TKOMODE == 0.0)) {
    RRTV3_PX4_OA_B.NAVMODE = 0.0;
    RRTV3_PX4_OA_B.PROGMANEUVER = 0.0;
  }

  if (RRTV3_PX4_OA_B.NAVMODE == 1.0) {
    if (RRTV3_PX4_OA_B.TKOMODE != 1.0) {
      PERFORM_LNAV = 1;
      PERFORM_VNAV = 1;
      PERFORM_SPD = 1;
    }

    if (RRTV3_PX4_OA_B.TKOMODE == 1.0) {
      LowSpeedLNAV = 1;
      PERFORM_LNAV = 1;
      RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft = NAV[8] * 3.28;
    }

    if (NAV[3] == 0.0) {
      if (NAV[2] > 10.0) {
        RRTV3_PX4_OA_B.NAVMODE = 0.0;
        PERFORM_LNAV = 0;
        PERFORM_VNAV = 0;
        PERFORM_SPD = 0;
      }

      if ((NAV[2] <= 10.0) && (RRTV3_PX4_OA_B.LDGMODE == 0.0)) {
        PERFORM_LNAV = 0;
        PERFORM_VNAV = 0;
        PERFORM_SPD = 0;
        FAPMODE = 1;
      }
    }

    if ((FAPMODE == 1) && ((fabs(NAV[6]) < 2.0) && (sqrt(States[4] * States[4] +
           RRTV3_PX4_OA_B.VREF_FWD_ms * RRTV3_PX4_OA_B.VREF_FWD_ms) < Params[61])))
    {
      FAPMODE = 0;
      RRTV3_PX4_OA_B.LDGMODE = 1.0;
      PERFORM_LNAV = 0;
      PERFORM_VNAV = 0;
      PERFORM_SPD = 0;
    }

    if (RRTV3_PX4_OA_B.LDGMODE == 1.0) {
      PERFORM_LNAV = 0;
      PERFORM_VNAV = 0;
      PERFORM_SPD = 0;
      AUTOFLIGHT_CMDS[5] = -10.0 * Integrated[6];
    }
  }

  NAV_pressed = 0;
  if ((States[4] < 2.0) && (fabs(NAV[0]) > 3.0)) {
    NAV_pressed = 1;
    LowSpeedLNAV = 1;
  }

  if (RRTV3_PX4_OA_B.TKOMODE == 1.0) {
    NAV_pressed = 1;
  }

  if (PERFORM_LNAV == 1) {
    if (LowSpeedLNAV == 0) {
      AUTOFLIGHT_CMDS[2] = NAV[0];
      RRTV3_PX4_OA_B.FPMCmd_g = NAV[0];
      RRTV3_PX4_OA_sind(&RRTV3_PX4_OA_B.FPMCmd_g);
      if ((RRTV3_PX4_OA_B.VCS_ms_tmp <= 10.0) || rtIsNaN
          (RRTV3_PX4_OA_B.VCS_ms_tmp)) {
        RRTV3_PX4_OA_B.VREF_FWD_ms = 10.0;
      } else {
        RRTV3_PX4_OA_B.VREF_FWD_ms = RRTV3_PX4_OA_B.VCS_ms_tmp;
      }

      AUTOFLIGHT_CMDS[4] = 9.81 / RRTV3_PX4_OA_B.VREF_FWD_ms *
        57.295779513082323 * RRTV3_PX4_OA_B.FPMCmd_g;
    } else {
      RRTV3_PX4_OA_B.dy = NAV[0] - 0.0 * States[3] * 180.0 / 3.1415926535897931;
      if ((Params[25] <= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        RRTV3_PX4_OA_B.dy = Params[25];
      }

      if ((-Params[25] >= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        AUTOFLIGHT_CMDS[4] = -Params[25];
      } else {
        AUTOFLIGHT_CMDS[4] = RRTV3_PX4_OA_B.dy;
      }
    }
  }

  if (PERFORM_VNAV == 1) {
    RRTV3_PX4_OA_B.VREF_FWD_ms = NAV[1];
    RRTV3_PX4_OA_sind(&RRTV3_PX4_OA_B.VREF_FWD_ms);
    RRTV3_PX4_OA_B.VREF_FWD_ms = RRTV3_PX4_OA_B.VCS_ms_tmp *
      RRTV3_PX4_OA_B.VREF_FWD_ms * 196.79999999999998;
    if (NAV[7] == 1.0) {
      RRTV3_PX4_OA_B.VREF_FWD_ms = (NAV[1] * 3.28 - RRTV3_PX4_OA_B.hAGL_ft_c) *
        Params[36] + Integrated[7] * Params[37];
    }

    if ((Params[16] <= RRTV3_PX4_OA_B.VREF_FWD_ms) || rtIsNaN
        (RRTV3_PX4_OA_B.VREF_FWD_ms)) {
      RRTV3_PX4_OA_B.VREF_FWD_ms = Params[16];
    }

    if ((-Params[16] >= RRTV3_PX4_OA_B.VREF_FWD_ms) || rtIsNaN
        (RRTV3_PX4_OA_B.VREF_FWD_ms)) {
      RRTV3_PX4_OA_B.VREF_FWD_ms = -Params[16];
    }

    AUTOFLIGHT_CMDS[0] = RRTV3_PX4_OA_B.VREF_FWD_ms / 196.79999999999998;
  }

  if ((PERFORM_SPD == 1) && (NAV_pressed == 0)) {
    AUTOFLIGHT_CMDS[5] = (NAV[2] - Integrated[6]) / 3.0;
    RRTV3_PX4_OA_B.dy = Params[34] * 0.51444 * (Integrated[6] - States[4]);
    if ((Params[31] <= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
      RRTV3_PX4_OA_B.dy = Params[31];
    }

    if ((-Params[31] >= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
      AUTOFLIGHT_CMDS[1] = -Params[31];
    } else {
      AUTOFLIGHT_CMDS[1] = RRTV3_PX4_OA_B.dy;
    }

    RRTV3_PX4_OA_B.VREF_FWD_ms = fabs(NAV[2]);
    if ((RRTV3_PX4_OA_B.VREF_FWD_ms < 1.0) && (RRTV3_PX4_OA_B.VREF_FWD_ms > 0.0))
    {
      AUTOFLIGHT_CMDS[1] = NAV[2];
      AUTOFLIGHT_CMDS[5] = NAV[2] * 9.81 * 1.9438612860586268;
    }
  }

  if ((RRTV3_PX4_OA_B.TKOMODE == 1.0) && (TKO_pressed == 1) &&
      (RRTV3_PX4_OA_B.NAVMODE == 0.0)) {
    RRTV3_PX4_OA_B.TKOMODE = 0.0;
    TKO_pressed = 0;
  }

  if ((RRTV3_PX4_OA_B.TKOMODE == 1.0) && (Integrated[1] < -3.0 * Params[15])) {
    RRTV3_PX4_OA_B.TKOMODE = 0.0;
  }

  RRTV3_PX4_OA_B.VREF_FWD_ms = fabs(States[4]);
  if ((RRTV3_PX4_OA_B.TKOMODE == 0.0) && (TKO_pressed == 1) &&
      (RRTV3_PX4_OA_B.NAVMODE == 0.0) && ((RRTV3_PX4_OA_B.VREF_FWD_ms < Params
        [61]) && (RRTV3_PX4_OA_B.hAGL_ft_c <=
                  RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft))) {
    RRTV3_PX4_OA_B.TKOMODE = 1.0;
  }

  if ((RRTV3_PX4_OA_B.TKOMODE == 1.0) && (fabs(RRTV3_PX4_OA_B.hAGL_ft_c -
        RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft) < 2.0)) {
    RRTV3_PX4_OA_B.TKOMODE = 0.0;
  }

  if (RRTV3_PX4_OA_B.TKOMODE == 1.0) {
    RRTV3_PX4_OA_B.FPMCmd_g = Params[63];
    if (RRTV3_PX4_OA_B.hAGL_ft_c > 10.0) {
      RRTV3_PX4_OA_B.FPMCmd_g = (RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft -
        RRTV3_PX4_OA_B.hAGL_ft_c) * Params[65];
      if ((Params[62] <= RRTV3_PX4_OA_B.FPMCmd_g) || rtIsNaN
          (RRTV3_PX4_OA_B.FPMCmd_g)) {
        RRTV3_PX4_OA_B.FPMCmd_g = Params[62];
      }
    }

    AUTOFLIGHT_CMDS[0] = RRTV3_PX4_OA_B.FPMCmd_g / 196.79999999999998;
  }

  if ((RRTV3_PX4_OA_B.LDGMODE == 1.0) && (LDG_pressed == 1) &&
      (RRTV3_PX4_OA_B.NAVMODE == 0.0)) {
    RRTV3_PX4_OA_B.LDGMODE = 0.0;
    LDG_pressed = 0;
  }

  if ((RRTV3_PX4_OA_B.LDGMODE == 0.0) && (LDG_pressed == 1) &&
      (RRTV3_PX4_OA_B.NAVMODE == 0.0) && (RRTV3_PX4_OA_B.VREF_FWD_ms < Params[61]))
  {
    RRTV3_PX4_OA_B.LDGMODE = 1.0;
  }

  if ((RRTV3_PX4_OA_B.LDGMODE == 1.0) && (Integrated[1] > 3.0 * Params[15])) {
    RRTV3_PX4_OA_B.LDGMODE = 0.0;
  }

  if ((RRTV3_PX4_OA_B.LDGMODE == 1.0) && (States[12] > 0.0)) {
    RRTV3_PX4_OA_B.LDGMODE = 0.0;
  }

  if (RRTV3_PX4_OA_B.LDGMODE == 1.0) {
    RRTV3_PX4_OA_B.dy = -50.0 - 10.0 * RRTV3_PX4_OA_B.hAGL_ft_c;
    if ((-Params[62] >= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
      RRTV3_PX4_OA_B.dy = -Params[62];
    }

    AUTOFLIGHT_CMDS[0] = RRTV3_PX4_OA_B.dy / 196.79999999999998;
    if (States[12] > 0.0) {
      AUTOFLIGHT_CMDS[0] = 0.0;
    }

    if (RRTV3_PX4_OA_B.VREF_FWD_ms > Params[61]) {
      AUTOFLIGHT_CMDS[0] = 0.0;
    }
  }

  if ((mem_in[1] == 1.0) && (DXN_pressed == 1)) {
    RRTV3_PX4_OA_B.DXNMODE = 0.5;
  }

  if ((RRTV3_PX4_OA_B.DXNMODE == 1.0) && (Integrated[3] < -3.0 * Params[30])) {
    RRTV3_PX4_OA_B.DXNMODE = 0.5;
  }

  if ((RRTV3_PX4_OA_B.DXNMODE == 1.0) && (fabs(States[4] - Params[66]) < 2.0)) {
    RRTV3_PX4_OA_B.DXNMODE = 0.0;
    DXN_pressed = 0;
  }

  if ((RRTV3_PX4_OA_B.DXNMODE == 0.0) && (DXN_pressed == 1) && (States[12] ==
       0.0) && (Params[66] - States[4] > 5.0)) {
    RRTV3_PX4_OA_B.DXNMODE = 1.0;
  }

  if (RRTV3_PX4_OA_B.DXNMODE == 1.0) {
    AUTOFLIGHT_CMDS[5] = (Params[66] - Integrated[6]) * 3.0;
    RRTV3_PX4_OA_B.dy = Params[34] * 0.51444 * (Params[66] - States[4]);
    if ((Params[31] <= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
      RRTV3_PX4_OA_B.dy = Params[31];
    }

    if ((-Params[31] >= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
      AUTOFLIGHT_CMDS[1] = -Params[31];
    } else {
      AUTOFLIGHT_CMDS[1] = RRTV3_PX4_OA_B.dy;
    }
  }

  if (RRTV3_PX4_OA_B.DXNMODE == 0.5) {
    RRTV3_PX4_OA_B.FPMCmd_g = States[4] - Integrated[6];
    AUTOFLIGHT_CMDS[5] = RRTV3_PX4_OA_B.FPMCmd_g * 3.0;
    if (fabs(RRTV3_PX4_OA_B.FPMCmd_g) < 3.0) {
      RRTV3_PX4_OA_B.DXNMODE = 0.0;
    }

    AUTOFLIGHT_CMDS[1] = 0.0;
  }

  if ((mem_in[3] == 1.0) && (AXN_pressed == 1)) {
    RRTV3_PX4_OA_B.AXNMODE = 0.5;
  }

  if ((RRTV3_PX4_OA_B.AXNMODE == 1.0) && (Integrated[3] > 3.0 * Params[30])) {
    RRTV3_PX4_OA_B.AXNMODE = 0.5;
  }

  if ((RRTV3_PX4_OA_B.AXNMODE == 1.0) && (RRTV3_PX4_OA_B.VREF_FWD_ms < 2.0)) {
    RRTV3_PX4_OA_B.AXNMODE = 0.0;
    AXN_pressed = 0;
  }

  if ((RRTV3_PX4_OA_B.AXNMODE == 0.0) && (AXN_pressed == 1) && (States[12] ==
       0.0)) {
    RRTV3_PX4_OA_B.AXNMODE = 1.0;
  }

  if (RRTV3_PX4_OA_B.AXNMODE != 0.0) {
    AUTOFLIGHT_CMDS[5] = (0.0 - Integrated[6]) * 3.0;
    RRTV3_PX4_OA_B.dy = Params[34] * 0.51444 * (0.0 - States[4]);
    if ((Params[31] <= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
      RRTV3_PX4_OA_B.dy = Params[31];
    }

    if ((-Params[31] >= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
      AUTOFLIGHT_CMDS[1] = -Params[31];
    } else {
      AUTOFLIGHT_CMDS[1] = RRTV3_PX4_OA_B.dy;
    }
  }

  if (RRTV3_PX4_OA_B.AXNMODE == 0.5) {
    RRTV3_PX4_OA_B.FPMCmd_g = States[4] - Integrated[6];
    AUTOFLIGHT_CMDS[5] = RRTV3_PX4_OA_B.FPMCmd_g * 3.0;
    if (fabs(RRTV3_PX4_OA_B.FPMCmd_g) < 3.0) {
      RRTV3_PX4_OA_B.AXNMODE = 0.0;
    }

    AUTOFLIGHT_CMDS[1] = 0.0;
  }

  if (FAPMODE == 1) {
    RRTV3_PX4_OA_B.FPMCmd_g = States[7] * 3.1415926535897931 / 180.0;
    RRTV3_PX4_OA_B.VREF_FWD_ms = cos(RRTV3_PX4_OA_B.FPMCmd_g) / 6.378137E+6;
    RRTV3_PX4_OA_B.FPMCmd_g = sin(RRTV3_PX4_OA_B.FPMCmd_g) / 6.3567523E+6;
    RRTV3_PX4_OA_B.VREF_FWD_ms = 1.0 / sqrt(RRTV3_PX4_OA_B.VREF_FWD_ms *
      RRTV3_PX4_OA_B.VREF_FWD_ms + RRTV3_PX4_OA_B.FPMCmd_g *
      RRTV3_PX4_OA_B.FPMCmd_g) + States[10];
    RRTV3_PX4_OA_B.FPMCmd_g = (NAV[4] - States[7]) * 0.017453292519943295 *
      RRTV3_PX4_OA_B.VREF_FWD_ms;
    RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft = States[7];
    RRTV3_PX4_OA_cosd(&RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft);
    RRTV3_PX4_OA_B.dy = (NAV[5] - States[8]) * 0.017453292519943295 *
      (RRTV3_PX4_OA_B.VREF_FWD_ms * RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft);
    RRTV3_PX4_OA_B.dist = sqrt(RRTV3_PX4_OA_B.FPMCmd_g * RRTV3_PX4_OA_B.FPMCmd_g
      + RRTV3_PX4_OA_B.dy * RRTV3_PX4_OA_B.dy);
    RRTV3_PX4_OA_B.FwdAftPosnErr_tmp = RRTV3_PX4_OA_B.HDG_f;
    RRTV3_PX4_OA_sind(&RRTV3_PX4_OA_B.FwdAftPosnErr_tmp);
    RRTV3_PX4_OA_cosd(&RRTV3_PX4_OA_B.HDG_f);
    RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft = 0.1 * RRTV3_PX4_OA_B.dist;
    if ((RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft >= 1.0) || rtIsNaN
        (RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft)) {
      RRTV3_PX4_OA_B.VREF_FWD_ms = 1.0;
      RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft = 1.0;
    } else {
      RRTV3_PX4_OA_B.VREF_FWD_ms = RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft;
    }

    RRTV3_PX4_OA_B.VREF_FWD_ms = (RRTV3_PX4_OA_B.FPMCmd_g * RRTV3_PX4_OA_B.HDG_f
      + RRTV3_PX4_OA_B.dy * RRTV3_PX4_OA_B.FwdAftPosnErr_tmp) *
      (RRTV3_PX4_OA_B.VREF_FWD_ms + 0.5) / RRTV3_PX4_OA_B.dist;
    RRTV3_PX4_OA_B.HDG_f = ((-RRTV3_PX4_OA_B.FPMCmd_g *
      RRTV3_PX4_OA_B.FwdAftPosnErr_tmp + RRTV3_PX4_OA_B.dy *
      RRTV3_PX4_OA_B.HDG_f) * (RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft + 0.5) /
      RRTV3_PX4_OA_B.dist - States[5]) * 1.9438612860586268;
    RRTV3_PX4_OA_B.dy = Params[9] * RRTV3_PX4_OA_B.HDG_f + Integrated[4];
    if ((RRTV3_PX4_OA_B.dy <= -10.0) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
      RRTV3_PX4_OA_B.dy = -10.0;
    }

    if (RRTV3_PX4_OA_B.dy >= 10.0) {
      AUTOFLIGHT_CMDS[2] = 10.0;
    } else {
      AUTOFLIGHT_CMDS[2] = RRTV3_PX4_OA_B.dy;
    }

    AUTOFLIGHT_CMDS[3] = Params[10] * RRTV3_PX4_OA_B.HDG_f;
    RRTV3_PX4_OA_B.dy = (RRTV3_PX4_OA_B.VREF_FWD_ms - RRTV3_PX4_OA_B.VCS_ms_tmp)
      * Params[34];
    if ((RRTV3_PX4_OA_B.dy <= -0.1) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
      RRTV3_PX4_OA_B.dy = -0.1;
    }

    if (RRTV3_PX4_OA_B.dy >= 0.1) {
      AUTOFLIGHT_CMDS[1] = 0.1;
    } else {
      AUTOFLIGHT_CMDS[1] = RRTV3_PX4_OA_B.dy;
    }

    AUTOFLIGHT_CMDS[5] = (RRTV3_PX4_OA_B.VREF_FWD_ms - Integrated[6] * 0.51444) *
      10.0;
  }

  if ((RRTV3_PX4_OA_B.PROGMANEUVER == 0.0) && (States[12] > 0.0) && (d_inc[18]
       != 0.0)) {
    if (M1_pressed == 1) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 1.0;
      RRTV3_PX4_OA_B.sequencer = 1.0;
      M1_pressed = 0;
    }

    if (M2_pressed == 1) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 2.0;
      RRTV3_PX4_OA_B.sequencer = 1.0;
      M2_pressed = 0;
    }

    if (M3_pressed == 1) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 3.0;
      RRTV3_PX4_OA_B.sequencer = 1.0;
      M3_pressed = 0;
    }

    if (M4_pressed == 1) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 4.0;
      RRTV3_PX4_OA_B.sequencer = 1.0;
      M4_pressed = 0;
    }

    if (M5_pressed == 1) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 5.0;
      RRTV3_PX4_OA_B.sequencer = 1.0;
      M5_pressed = 0;
    }
  }

  if ((M1_pressed != 0) || (M2_pressed != 0) || (M3_pressed != 0) || (M4_pressed
       != 0) || (M5_pressed != 0)) {
    if (RRTV3_PX4_OA_B.PROGMANEUVER != 0.0) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 0.0;
      RRTV3_PX4_OA_B.sequencer = 1.0;
    }

    RRTV3_PX4_OA_B.TKOMODE = 0.0;
    RRTV3_PX4_OA_B.LDGMODE = 0.0;
  }

  if ((d_inc[18] == 1.0) && ((RRTV3_PX4_OA_B.PROGMANEUVER > 0.0) &&
       (RRTV3_PX4_OA_B.NAVMODE == 0.0))) {
    DXN_pressed = 0;
    RRTV3_PX4_OA_B.FPMCmd_g = 0.0;
    if (RRTV3_PX4_OA_B.PROGMANEUVER == 1.0) {
      DXN_pressed = 20;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER == 2.0) {
      DXN_pressed = 40;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER == 3.0) {
      DXN_pressed = 60;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER == 4.0) {
      DXN_pressed = 80;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER == 5.0) {
      DXN_pressed = 100;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
    }

    if (RRTV3_PX4_OA_B.sequencer == 1.0) {
      RRTV3_PX4_OA_B.TKOMODE = 1.0;
      if (RRTV3_PX4_OA_B.hAGL_ft_c > 5.0) {
        RRTV3_PX4_OA_B.TKOMODE = 0.0;
        RRTV3_PX4_OA_B.sequencer = 2.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 2.0) {
      RRTV3_PX4_OA_B.stopwatch_active = 1.0;
      if (mem_in[21] > 5.0) {
        RRTV3_PX4_OA_B.stopwatch_active = 0.0;
        RRTV3_PX4_OA_B.sequencer = 3.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 3.0) {
      RRTV3_PX4_OA_GetToAltitude(&RRTV3_PX4_OA_B.conv_m_to_ft,
        &RRTV3_PX4_OA_B.conv_ms_to_fpm, static_cast<real_T>(DXN_pressed),
        RRTV3_PX4_OA_B.FPMCmd_g, States[10], &AUTOFLIGHT_CMDS[0],
        &RRTV3_PX4_OA_B.VCS_ms_tmp);
      if (RRTV3_PX4_OA_B.VCS_ms_tmp == 1.0) {
        RRTV3_PX4_OA_B.sequencer = 4.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 4.0) {
      RRTV3_PX4_OA_B.stopwatch_active = 1.0;
      if (mem_in[21] > 5.0) {
        RRTV3_PX4_OA_B.stopwatch_active = 0.0;
        RRTV3_PX4_OA_B.sequencer = 5.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 5.0) {
      RRTV3_PX4_OA_B.LDGMODE = 1.0;
    }

    if ((RRTV3_PX4_OA_B.LDGMODE == 1.0) && (RRTV3_PX4_OA_B.sequencer == 5.0) &&
        (States[12] > 0.0)) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 0.0;
      RRTV3_PX4_OA_B.LDGMODE = 0.0;
    }
  }

  if ((d_inc[18] == 2.0) && ((RRTV3_PX4_OA_B.PROGMANEUVER > 0.0) &&
       (RRTV3_PX4_OA_B.NAVMODE == 0.0))) {
    DXN_pressed = 0;
    RRTV3_PX4_OA_B.FPMCmd_g = 0.0;
    TKO_pressed = 0;
    if (RRTV3_PX4_OA_B.PROGMANEUVER == 1.0) {
      DXN_pressed = 20;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
      TKO_pressed = 10;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER == 2.0) {
      DXN_pressed = 50;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
      TKO_pressed = 20;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER == 3.0) {
      DXN_pressed = 50;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
      TKO_pressed = 30;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER == 4.0) {
      DXN_pressed = 80;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
      TKO_pressed = 45;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER == 5.0) {
      DXN_pressed = 80;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
      TKO_pressed = 50;
    }

    if (RRTV3_PX4_OA_B.sequencer == 1.0) {
      RRTV3_PX4_OA_B.TKOMODE = 1.0;
      if (RRTV3_PX4_OA_B.hAGL_ft_c > 5.0) {
        RRTV3_PX4_OA_B.TKOMODE = 0.0;
        RRTV3_PX4_OA_B.sequencer = 2.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 2.0) {
      RRTV3_PX4_OA_B.stopwatch_active = 1.0;
      if (mem_in[21] > 5.0) {
        RRTV3_PX4_OA_B.stopwatch_active = 0.0;
        RRTV3_PX4_OA_B.sequencer = 3.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 3.0) {
      RRTV3_PX4_OA_GetToAltitude(&RRTV3_PX4_OA_B.conv_m_to_ft,
        &RRTV3_PX4_OA_B.conv_ms_to_fpm, static_cast<real_T>(DXN_pressed),
        RRTV3_PX4_OA_B.FPMCmd_g, States[10], &AUTOFLIGHT_CMDS[0],
        &RRTV3_PX4_OA_B.VCS_ms_tmp);
      if (RRTV3_PX4_OA_B.VCS_ms_tmp == 1.0) {
        RRTV3_PX4_OA_B.sequencer = 4.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 4.0) {
      AUTOFLIGHT_CMDS[5] = (static_cast<real_T>(TKO_pressed) - Integrated[6]) *
        3.0;
      RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft = static_cast<real_T>(TKO_pressed)
        - States[4];
      RRTV3_PX4_OA_B.dy = Params[34] * 0.51444 *
        RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft;
      if ((Params[31] <= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        RRTV3_PX4_OA_B.dy = Params[31];
      }

      if ((-Params[31] >= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        AUTOFLIGHT_CMDS[1] = -Params[31];
      } else {
        AUTOFLIGHT_CMDS[1] = RRTV3_PX4_OA_B.dy;
      }

      if (fabs(RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft) < 1.0) {
        RRTV3_PX4_OA_B.sequencer = 5.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 5.0) {
      RRTV3_PX4_OA_B.stopwatch_active = 1.0;
      if (mem_in[21] > 5.0) {
        RRTV3_PX4_OA_B.stopwatch_active = 0.0;
        RRTV3_PX4_OA_B.sequencer = 6.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 6.0) {
      AUTOFLIGHT_CMDS[5] = (0.0 - Integrated[6]) * 3.0;
      RRTV3_PX4_OA_B.dy = Params[34] * 0.51444 * (0.0 - States[4]);
      if ((Params[31] <= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        RRTV3_PX4_OA_B.dy = Params[31];
      }

      if ((-Params[31] >= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        AUTOFLIGHT_CMDS[1] = -Params[31];
      } else {
        AUTOFLIGHT_CMDS[1] = RRTV3_PX4_OA_B.dy;
      }

      if (fabs(0.0 - States[4]) < 1.0) {
        RRTV3_PX4_OA_B.sequencer = 7.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 7.0) {
      RRTV3_PX4_OA_B.LDGMODE = 1.0;
    }

    if ((RRTV3_PX4_OA_B.LDGMODE == 1.0) && (RRTV3_PX4_OA_B.sequencer == 7.0) &&
        (States[12] > 0.0)) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 0.0;
      RRTV3_PX4_OA_B.LDGMODE = 0.0;
    }
  }

  if ((d_inc[18] == 3.0) && ((RRTV3_PX4_OA_B.PROGMANEUVER > 0.0) &&
       (RRTV3_PX4_OA_B.NAVMODE == 0.0))) {
    DXN_pressed = 0;
    AXN_pressed = 0;
    RRTV3_PX4_OA_B.FPMCmd_g = 0.0;
    TKO_pressed = 0;
    if (RRTV3_PX4_OA_B.PROGMANEUVER == 1.0) {
      DXN_pressed = 70;
      AXN_pressed = 80;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
      TKO_pressed = 45;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER != 1.0) {
      RRTV3_PX4_OA_B.sequencer = 0.0;
    }

    if (RRTV3_PX4_OA_B.sequencer == 1.0) {
      RRTV3_PX4_OA_B.TKOMODE = 1.0;
      if (RRTV3_PX4_OA_B.hAGL_ft_c > 5.0) {
        RRTV3_PX4_OA_B.TKOMODE = 0.0;
        RRTV3_PX4_OA_B.sequencer = 2.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 2.0) {
      RRTV3_PX4_OA_B.stopwatch_active = 1.0;
      if (mem_in[21] > 5.0) {
        RRTV3_PX4_OA_B.stopwatch_active = 0.0;
        RRTV3_PX4_OA_B.sequencer = 3.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 3.0) {
      RRTV3_PX4_OA_GetToAltitude(&RRTV3_PX4_OA_B.conv_m_to_ft,
        &RRTV3_PX4_OA_B.conv_ms_to_fpm, static_cast<real_T>(DXN_pressed),
        RRTV3_PX4_OA_B.FPMCmd_g, States[10], &AUTOFLIGHT_CMDS[0],
        &RRTV3_PX4_OA_B.VCS_ms_tmp);
      if (RRTV3_PX4_OA_B.VCS_ms_tmp == 1.0) {
        RRTV3_PX4_OA_B.sequencer = 4.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 4.0) {
      RRTV3_PX4_OA_GetToAltitude(&RRTV3_PX4_OA_B.conv_m_to_ft,
        &RRTV3_PX4_OA_B.conv_ms_to_fpm, static_cast<real_T>(AXN_pressed),
        RRTV3_PX4_OA_B.FPMCmd_g, States[10], &AUTOFLIGHT_CMDS[0],
        &RRTV3_PX4_OA_B.VCS_ms_tmp);
      DXN_pressed = 0;
      AUTOFLIGHT_CMDS[5] = (static_cast<real_T>(TKO_pressed) - Integrated[6]) *
        3.0;
      RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft = static_cast<real_T>(TKO_pressed)
        - States[4];
      RRTV3_PX4_OA_B.dy = Params[34] * 0.51444 *
        RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft;
      if ((Params[31] <= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        RRTV3_PX4_OA_B.dy = Params[31];
      }

      if ((-Params[31] >= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        AUTOFLIGHT_CMDS[1] = -Params[31];
      } else {
        AUTOFLIGHT_CMDS[1] = RRTV3_PX4_OA_B.dy;
      }

      if (fabs(RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft) < 1.0) {
        DXN_pressed = 1;
      }

      if ((DXN_pressed == 1) && (RRTV3_PX4_OA_B.VCS_ms_tmp == 1.0)) {
        RRTV3_PX4_OA_B.sequencer = 5.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 5.0) {
      RRTV3_PX4_OA_B.stopwatch_active = 1.0;
      if (mem_in[21] > 5.0) {
        RRTV3_PX4_OA_B.stopwatch_active = 0.0;
        RRTV3_PX4_OA_B.sequencer = 6.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 6.0) {
      AUTOFLIGHT_CMDS[5] = (0.0 - Integrated[6]) * 3.0;
      RRTV3_PX4_OA_B.dy = Params[34] * 0.51444 * (0.0 - States[4]);
      if ((Params[31] <= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        RRTV3_PX4_OA_B.dy = Params[31];
      }

      if ((-Params[31] >= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        AUTOFLIGHT_CMDS[1] = -Params[31];
      } else {
        AUTOFLIGHT_CMDS[1] = RRTV3_PX4_OA_B.dy;
      }

      if (fabs(0.0 - States[4]) < 1.0) {
        RRTV3_PX4_OA_B.sequencer = 7.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 7.0) {
      RRTV3_PX4_OA_B.LDGMODE = 1.0;
    }

    if ((RRTV3_PX4_OA_B.LDGMODE == 1.0) && (RRTV3_PX4_OA_B.sequencer == 7.0) &&
        (States[12] > 0.0)) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 0.0;
      RRTV3_PX4_OA_B.LDGMODE = 0.0;
    }
  }

  if ((d_inc[18] == 4.0) && ((RRTV3_PX4_OA_B.PROGMANEUVER > 0.0) &&
       (RRTV3_PX4_OA_B.NAVMODE == 0.0))) {
    DXN_pressed = 0;
    RRTV3_PX4_OA_B.FPMCmd_g = 0.0;
    TKO_pressed = 0;
    if (RRTV3_PX4_OA_B.PROGMANEUVER == 1.0) {
      DXN_pressed = 100;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
      TKO_pressed = 45;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER == 2.0) {
      DXN_pressed = 100;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
      TKO_pressed = 50;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER == 3.0) {
      DXN_pressed = 100;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
      TKO_pressed = 55;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER == 4.0) {
      DXN_pressed = 100;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
      TKO_pressed = 60;
    }

    if (RRTV3_PX4_OA_B.PROGMANEUVER == 5.0) {
      DXN_pressed = 100;
      RRTV3_PX4_OA_B.FPMCmd_g = 200.0;
      TKO_pressed = 65;
    }

    if (RRTV3_PX4_OA_B.sequencer == 1.0) {
      RRTV3_PX4_OA_B.TKOMODE = 1.0;
      if (RRTV3_PX4_OA_B.hAGL_ft_c > 5.0) {
        RRTV3_PX4_OA_B.TKOMODE = 0.0;
        RRTV3_PX4_OA_B.sequencer = 2.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 2.0) {
      RRTV3_PX4_OA_B.stopwatch_active = 1.0;
      if (mem_in[21] > 5.0) {
        RRTV3_PX4_OA_B.stopwatch_active = 0.0;
        RRTV3_PX4_OA_B.sequencer = 3.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 3.0) {
      RRTV3_PX4_OA_GetToAltitude(&RRTV3_PX4_OA_B.conv_m_to_ft,
        &RRTV3_PX4_OA_B.conv_ms_to_fpm, static_cast<real_T>(DXN_pressed),
        RRTV3_PX4_OA_B.FPMCmd_g, States[10], &AUTOFLIGHT_CMDS[0],
        &RRTV3_PX4_OA_B.hAGL_ft_c);
      if (RRTV3_PX4_OA_B.hAGL_ft_c == 1.0) {
        RRTV3_PX4_OA_B.sequencer = 4.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 4.0) {
      AUTOFLIGHT_CMDS[5] = (static_cast<real_T>(TKO_pressed) - Integrated[6]) *
        3.0;
      RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft = static_cast<real_T>(TKO_pressed)
        - States[4];
      RRTV3_PX4_OA_B.dy = Params[34] * 0.51444 *
        RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft;
      if ((Params[31] <= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        RRTV3_PX4_OA_B.dy = Params[31];
      }

      if ((-Params[31] >= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        AUTOFLIGHT_CMDS[1] = -Params[31];
      } else {
        AUTOFLIGHT_CMDS[1] = RRTV3_PX4_OA_B.dy;
      }

      if (fabs(RRTV3_PX4_OA_B.AutoTakeoffLevelOffAGL_ft) < 1.0) {
        RRTV3_PX4_OA_B.sequencer = 5.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 5.0) {
      RRTV3_PX4_OA_B.stopwatch_active = 1.0;
      if (mem_in[21] > 5.0) {
        RRTV3_PX4_OA_B.stopwatch_active = 0.0;
        RRTV3_PX4_OA_B.sequencer = 6.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 6.0) {
      TKO_pressed = 0;
      AUTOFLIGHT_CMDS[5] = (0.0 - Integrated[6]) * 3.0;
      RRTV3_PX4_OA_B.dy = Params[34] * 0.51444 * (0.0 - States[4]);
      if ((Params[31] <= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        RRTV3_PX4_OA_B.dy = Params[31];
      }

      if ((-Params[31] >= RRTV3_PX4_OA_B.dy) || rtIsNaN(RRTV3_PX4_OA_B.dy)) {
        AUTOFLIGHT_CMDS[1] = -Params[31];
      } else {
        AUTOFLIGHT_CMDS[1] = RRTV3_PX4_OA_B.dy;
      }

      if (fabs(0.0 - States[4]) < 1.0) {
        TKO_pressed = 1;
      }

      RRTV3_PX4_OA_GetToAltitude(&RRTV3_PX4_OA_B.conv_m_to_ft,
        &RRTV3_PX4_OA_B.conv_ms_to_fpm, 20.0, RRTV3_PX4_OA_B.FPMCmd_g, States[10],
        &AUTOFLIGHT_CMDS[0], &RRTV3_PX4_OA_B.hAGL_ft_c);
      if ((TKO_pressed == 1) && (RRTV3_PX4_OA_B.hAGL_ft_c == 1.0)) {
        RRTV3_PX4_OA_B.sequencer = 7.0;
      }
    }

    if (RRTV3_PX4_OA_B.sequencer == 7.0) {
      RRTV3_PX4_OA_B.LDGMODE = 1.0;
    }

    if ((RRTV3_PX4_OA_B.LDGMODE == 1.0) && (RRTV3_PX4_OA_B.sequencer == 7.0) &&
        (States[12] > 0.0)) {
      RRTV3_PX4_OA_B.PROGMANEUVER = 0.0;
      RRTV3_PX4_OA_B.LDGMODE = 0.0;
    }
  }

  if (RRTV3_PX4_OA_B.stopwatch_active != mem_in[19]) {
    mem_out[20] = b_clock;
  }

  AF_MODES[2] = RRTV3_PX4_OA_B.NAVMODE;
  if (RRTV3_PX4_OA_B.NAVMODE == 0.5) {
    AF_MODES[2] = 2.0;
  }

  if (RRTV3_PX4_OA_B.NAVMODE == 0.75) {
    AF_MODES[2] = 3.0;
  }

  AUTOFLIGHT_CMDS[6] = RRTV3_PX4_OA_B.TKOMODE;
  AUTOFLIGHT_CMDS[7] = RRTV3_PX4_OA_B.DXNMODE;
  AUTOFLIGHT_CMDS[8] = RRTV3_PX4_OA_B.NAVMODE;
  AUTOFLIGHT_CMDS[9] = RRTV3_PX4_OA_B.AXNMODE;
  AUTOFLIGHT_CMDS[10] = RRTV3_PX4_OA_B.LDGMODE;
  AUTOFLIGHT_CMDS[11] = FAPMODE;
  AUTOFLIGHT_CMDS[12] = RRTV3_PX4_OA_B.PROGMANEUVER;
  AUTOFLIGHT_CMDS[13] = NAV[4];
  AUTOFLIGHT_CMDS[14] = NAV[5];
  AF_MODES[0] = RRTV3_PX4_OA_B.TKOMODE;
  AF_MODES[1] = RRTV3_PX4_OA_B.DXNMODE;
  AF_MODES[3] = RRTV3_PX4_OA_B.AXNMODE;
  AF_MODES[4] = RRTV3_PX4_OA_B.LDGMODE;
  AF_MODES[5] = FAPMODE;
  AF_MODES[6] = RRTV3_PX4_OA_B.PROGMANEUVER;
  mem_out[0] = RRTV3_PX4_OA_B.TKOMODE;
  mem_out[1] = RRTV3_PX4_OA_B.DXNMODE;
  mem_out[2] = RRTV3_PX4_OA_B.NAVMODE;
  mem_out[3] = RRTV3_PX4_OA_B.AXNMODE;
  mem_out[4] = RRTV3_PX4_OA_B.LDGMODE;
  mem_out[5] = FAPMODE;
  mem_out[6] = RRTV3_PX4_OA_B.PROGMANEUVER;
  memcpy(&mem_out[7], &d_inc[4], 10U * sizeof(real_T));
  mem_out[17] = 1.0;
  mem_out[18] = RRTV3_PX4_OA_B.sequencer;
  mem_out[19] = RRTV3_PX4_OA_B.stopwatch_active;
  if (mem_in[19] != 0.0) {
    mem_out[21] = b_clock - mem_in[20];
  } else {
    mem_out[21] = 0.0;
  }
}

// Function for MATLAB Function: '<S13>/MATLAB Function'
static void RRTV3_PX4_ProcessInceptorInputs(const real_T Params[67], const
  real_T d_inc[20], const real_T States[13], const real_T AUTOFLIGHT[15], const
  real_T Integrated[10], const real_T mem_in[8], real_T VVCmdVec[2], real_T
  *AccCmd, real_T *VelCmd_kt, real_T *FPACmd, real_T *BankCmd, real_T
  *YawRateCmd, real_T TBI[10], real_T mem[8])
{
  int32_T DirectBankCmdGen;
  *FPACmd = Integrated[5];
  *VelCmd_kt = Integrated[6];
  RRTV3_PX4_OA_B.DIRHOLD = mem_in[0];
  RRTV3_PX4_OA_B.HDG_mem = mem_in[1];
  RRTV3_PX4_OA_B.TRK_mem = mem_in[2];
  RRTV3_PX4_OA_B.POSNHOLD = mem_in[3];
  RRTV3_PX4_OA_B.LatDeg_mem = mem_in[4];
  RRTV3_PX4_OA_B.LongDeg_mem = mem_in[5];
  mem[6] = mem_in[6];
  RRTV3_PX4_OA_B.LatDeg_ref = 0.0;
  RRTV3_PX4_OA_B.LongDeg_ref = 0.0;
  RRTV3_PX4_OA_B.BankRateCmd = 0.0;
  RRTV3_PX4_OA_B.HeightError = 0.0;
  RRTV3_PX4_OA_B.LeftRightPosnErr = 0.0;
  RRTV3_PX4_OA_B.FwdAftPosnErr = 0.0;
  DirectBankCmdGen = 0;
  RRTV3_PX4_OA_B.DihedralEffect = 0.0;
  *BankCmd = 0.0;
  RRTV3_PX4_OA_B.Vfwd_ms_tmp = States[4] * 0.51444;
  RRTV3_PX4_OA_B.LatVel_kt = States[5] / 0.51444;
  RRTV3_PX4_OA_B.BANK = States[0] * 180.0 / 3.1415926535897931;
  RRTV3_PX4_OA_B.FPM = States[9] * 60.0 * 3.28;
  RRTV3_PX4_OA_B.hAGL_ft = States[10] * 3.28;
  RRTV3_PX4_OA_B.TurnRate = States[3] * 180.0 / 3.1415926535897931;
  RRTV3_PX4_OA_B.HDG_p = States[2] * 180.0 / 3.1415926535897931;
  RRTV3_PX4_OA_B.TRK = States[11] * 180.0 / 3.1415926535897931;
  RRTV3_PX4_OA_B.dHDG = fabs(d_inc[0]) - Params[2];
  if (rtIsNaN(d_inc[0])) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = (rtNaN);
  } else if (d_inc[0] < 0.0) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = -1.0;
  } else {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = (d_inc[0] > 0.0);
  }

  if ((RRTV3_PX4_OA_B.dHDG <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.dHDG)) {
    RRTV3_PX4_OA_B.dHDG = 0.0;
  }

  RRTV3_PX4_OA_B.d_lat_inc = RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 *
    RRTV3_PX4_OA_B.dHDG / (1.0 - Params[2]);
  RRTV3_PX4_OA_B.dHDG = fabs(d_inc[1]) - Params[15];
  if (rtIsNaN(d_inc[1])) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = (rtNaN);
  } else if (d_inc[1] < 0.0) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = -1.0;
  } else {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = (d_inc[1] > 0.0);
  }

  if ((RRTV3_PX4_OA_B.dHDG <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.dHDG)) {
    RRTV3_PX4_OA_B.dHDG = 0.0;
  }

  RRTV3_PX4_OA_B.d_lon_inc = RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 *
    RRTV3_PX4_OA_B.dHDG / (1.0 - Params[15]);
  RRTV3_PX4_OA_B.dHDG = fabs(d_inc[2]) - Params[24];
  if (rtIsNaN(d_inc[2])) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = (rtNaN);
  } else if (d_inc[2] < 0.0) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = -1.0;
  } else {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = (d_inc[2] > 0.0);
  }

  if ((RRTV3_PX4_OA_B.dHDG <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.dHDG)) {
    RRTV3_PX4_OA_B.dHDG = 0.0;
  }

  RRTV3_PX4_OA_B.d_dir_inc = RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 *
    RRTV3_PX4_OA_B.dHDG / (1.0 - Params[24]);
  RRTV3_PX4_OA_B.dHDG = fabs(d_inc[3]) - Params[30];
  if (rtIsNaN(d_inc[3])) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = (rtNaN);
  } else if (d_inc[3] < 0.0) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = -1.0;
  } else {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = (d_inc[3] > 0.0);
  }

  if ((RRTV3_PX4_OA_B.dHDG <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.dHDG)) {
    RRTV3_PX4_OA_B.dHDG = 0.0;
  }

  RRTV3_PX4_OA_B.d_acc_inc = RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 *
    RRTV3_PX4_OA_B.dHDG / (1.0 - Params[30]);
  RRTV3_PX4_OA_B.dHDG = (States[4] - Params[11]) / (Params[12] - Params[11]);
  if ((RRTV3_PX4_OA_B.dHDG <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.dHDG)) {
    RRTV3_PX4_OA_B.dHDG = 0.0;
  }

  if (RRTV3_PX4_OA_B.dHDG >= 1.0) {
    RRTV3_PX4_OA_B.dHDG = 1.0;
  }

  if (Params[0] == 1.0) {
    *BankCmd = (1.0 - (1.0 - RRTV3_PX4_OA_B.dHDG)) * (Integrated[0] * Params[5])
      + (1.0 - RRTV3_PX4_OA_B.dHDG) * (Integrated[0] * Params[4]);
    DirectBankCmdGen = 1;
  }

  if (Params[0] == 2.0) {
    RRTV3_PX4_OA_B.LatVelErr = Integrated[0] * Params[3] -
      RRTV3_PX4_OA_B.LatVel_kt;
    RRTV3_PX4_OA_B.BankRateCmd = (1.0 - RRTV3_PX4_OA_B.dHDG) * Params[10] *
      RRTV3_PX4_OA_B.LatVelErr;
    RRTV3_PX4_OA_B.LatVelErr = Params[9] * RRTV3_PX4_OA_B.LatVelErr +
      Integrated[4];
    if ((Params[4] <= RRTV3_PX4_OA_B.LatVelErr) || rtIsNaN
        (RRTV3_PX4_OA_B.LatVelErr)) {
      RRTV3_PX4_OA_B.LatVelErr = Params[4];
    }

    if ((-Params[4] >= RRTV3_PX4_OA_B.LatVelErr) || rtIsNaN
        (RRTV3_PX4_OA_B.LatVelErr)) {
      RRTV3_PX4_OA_B.LatVelErr = -Params[4];
    }

    *BankCmd = (1.0 - (1.0 - RRTV3_PX4_OA_B.dHDG)) * (Integrated[0] * Params[5])
      + (1.0 - RRTV3_PX4_OA_B.dHDG) * RRTV3_PX4_OA_B.LatVelErr;
    if (1.0 - RRTV3_PX4_OA_B.dHDG == 0.0) {
      DirectBankCmdGen = 1;
    }
  }

  if (Params[0] == 3.0) {
    if (1.0 - RRTV3_PX4_OA_B.dHDG == 0.0) {
      RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = fabs(RRTV3_PX4_OA_B.BANK);
      if (RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 > 45.0) {
        if (rtIsNaN(RRTV3_PX4_OA_B.BANK)) {
          RRTV3_PX4_OA_B.BankRateCmd = (rtNaN);
        } else if (RRTV3_PX4_OA_B.BANK < 0.0) {
          RRTV3_PX4_OA_B.BankRateCmd = -1.0;
        } else {
          RRTV3_PX4_OA_B.BankRateCmd = (RRTV3_PX4_OA_B.BANK > 0.0);
        }

        RRTV3_PX4_OA_B.DihedralEffect = -Params[8] * RRTV3_PX4_OA_B.BankRateCmd *
          (RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 - 45.0);
      }
    }

    if (fabs(RRTV3_PX4_OA_B.BANK) < 5.0) {
      RRTV3_PX4_OA_B.DihedralEffect = -Params[7] * RRTV3_PX4_OA_B.BANK;
    }

    if (States[4] <= Params[66]) {
      RRTV3_PX4_OA_B.DihedralEffect = -Params[7] * RRTV3_PX4_OA_B.BANK;
    }

    RRTV3_PX4_OA_B.BankRateCmd = Integrated[0] * Params[6] +
      RRTV3_PX4_OA_B.DihedralEffect;
    if ((Integrated[4] >= Params[5]) && ((RRTV3_PX4_OA_B.BankRateCmd >= 0.0) ||
         rtIsNaN(RRTV3_PX4_OA_B.BankRateCmd))) {
      RRTV3_PX4_OA_B.BankRateCmd = 0.0;
    }

    if ((Integrated[4] <= -Params[5]) && ((RRTV3_PX4_OA_B.BankRateCmd <= 0.0) ||
         rtIsNaN(RRTV3_PX4_OA_B.BankRateCmd))) {
      RRTV3_PX4_OA_B.BankRateCmd = 0.0;
    }

    RRTV3_PX4_OA_B.LatVelErr = (Integrated[0] * Params[3] -
      RRTV3_PX4_OA_B.LatVel_kt) * Params[9] + Integrated[4];
    if ((Params[4] <= RRTV3_PX4_OA_B.LatVelErr) || rtIsNaN
        (RRTV3_PX4_OA_B.LatVelErr)) {
      RRTV3_PX4_OA_B.LatVelErr = Params[4];
    }

    if ((-Params[4] >= RRTV3_PX4_OA_B.LatVelErr) || rtIsNaN
        (RRTV3_PX4_OA_B.LatVelErr)) {
      RRTV3_PX4_OA_B.LatVelErr = -Params[4];
    }

    *BankCmd = (1.0 - (1.0 - RRTV3_PX4_OA_B.dHDG)) * Integrated[4] + (1.0 -
      RRTV3_PX4_OA_B.dHDG) * RRTV3_PX4_OA_B.LatVelErr;
    if (1.0 - RRTV3_PX4_OA_B.dHDG == 1.0) {
      DirectBankCmdGen = 1;
    }

    if (1.0 - RRTV3_PX4_OA_B.dHDG == 0.0) {
      DirectBankCmdGen = 0;
    }
  }

  RRTV3_PX4_OA_B.LatVelErr = 1.0;
  if (Params[13] == 2.0) {
    RRTV3_PX4_OA_B.LatVelErr = (States[4] - Params[21]) / fabs(Params[22] -
      Params[21]);
    if ((RRTV3_PX4_OA_B.LatVelErr <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.LatVelErr))
    {
      RRTV3_PX4_OA_B.LatVelErr = 0.0;
    }

    if (RRTV3_PX4_OA_B.LatVelErr >= 1.0) {
      RRTV3_PX4_OA_B.LatVelErr = 1.0;
    }

    RRTV3_PX4_OA_B.LatVelErr = 1.0 - RRTV3_PX4_OA_B.LatVelErr;
  }

  RRTV3_PX4_OA_B.DihedralEffect = 9.81 / States[4] * 57.295779513082323;
  RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 = (Params[19] - 1.0) *
    RRTV3_PX4_OA_B.DihedralEffect;
  RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = (Params[20] - 1.0) *
    RRTV3_PX4_OA_B.DihedralEffect;
  RRTV3_PX4_OA_B.DihedralEffect = (1.0 - RRTV3_PX4_OA_B.LatVelErr) * Params[18] *
    Integrated[1];
  if ((RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 <=
       RRTV3_PX4_OA_B.DihedralEffect) || rtIsNaN(RRTV3_PX4_OA_B.DihedralEffect))
  {
    RRTV3_PX4_OA_B.DihedralEffect = RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1;
  }

  if ((RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 >=
       RRTV3_PX4_OA_B.DihedralEffect) || rtIsNaN(RRTV3_PX4_OA_B.DihedralEffect))
  {
    RRTV3_PX4_OA_B.DihedralEffect = RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0;
  }

  if (RRTV3_PX4_OA_B.LatVelErr == 1.0) {
    RRTV3_PX4_OA_B.DihedralEffect = -Integrated[5];
  }

  if ((Integrated[5] > Params[17]) && (RRTV3_PX4_OA_B.DihedralEffect > 0.0)) {
    RRTV3_PX4_OA_B.DihedralEffect = 0.0;
  }

  if ((Integrated[5] < -Params[17]) && (RRTV3_PX4_OA_B.DihedralEffect < 0.0)) {
    RRTV3_PX4_OA_B.DihedralEffect = 0.0;
  }

  RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 = Integrated[5];
  RRTV3_PX4_OA_sind(&RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0);
  RRTV3_PX4_OA_B.LatVelErr = RRTV3_PX4_OA_B.LatVelErr * Params[16] * Integrated
    [1] / 196.79999999999998 * RRTV3_PX4_OA_B.LatVelErr + (1.0 -
    RRTV3_PX4_OA_B.LatVelErr) * (States[4] *
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0);
  RRTV3_PX4_OA_B.FPMCmd = RRTV3_PX4_OA_B.LatVelErr * 60.0 * 3.28;
  RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 = Integrated[5];
  RRTV3_PX4_OA_cosd(&RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0);
  VVCmdVec[1] = States[4] * RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 *
    RRTV3_PX4_OA_B.DihedralEffect;
  RRTV3_PX4_OA_B.DissipationGain = *BankCmd;
  RRTV3_PX4_OA_sind(&RRTV3_PX4_OA_B.DissipationGain);
  RRTV3_PX4_OA_B.u1_tmp = fabs(RRTV3_PX4_OA_B.Vfwd_ms_tmp);
  if ((RRTV3_PX4_OA_B.u1_tmp <= 5.0) || rtIsNaN(RRTV3_PX4_OA_B.u1_tmp)) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = 5.0;
  } else {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = RRTV3_PX4_OA_B.u1_tmp;
  }

  *YawRateCmd = 9.81 / RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 *
    57.295779513082323 * RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 *
    RRTV3_PX4_OA_B.DissipationGain * (1.0 - (1.0 - RRTV3_PX4_OA_B.dHDG)) + (1.0
    - RRTV3_PX4_OA_B.dHDG) * (Integrated[2] * Params[25]);
  RRTV3_PX4_OA_B.dHDG = (States[4] - Params[32]) / (Params[33] - Params[32]);
  if ((RRTV3_PX4_OA_B.dHDG <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.dHDG)) {
    RRTV3_PX4_OA_B.dHDG = 0.0;
  }

  if (RRTV3_PX4_OA_B.dHDG >= 1.0) {
    RRTV3_PX4_OA_B.dHDG = 1.0;
  }

  RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 = 1.0 - RRTV3_PX4_OA_B.dHDG;
  RRTV3_PX4_OA_B.DissipationGain = Params[31] / (0.51444 * Params[33]);
  RRTV3_PX4_OA_B.dHDG = RRTV3_PX4_OA_B.DissipationGain * RRTV3_PX4_OA_B.u1_tmp;
  if ((Params[31] <= RRTV3_PX4_OA_B.dHDG) || rtIsNaN(RRTV3_PX4_OA_B.dHDG)) {
    RRTV3_PX4_OA_B.dHDG = Params[31];
  }

  if (rtIsNaN(RRTV3_PX4_OA_B.Vfwd_ms_tmp)) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = (rtNaN);
  } else if (RRTV3_PX4_OA_B.Vfwd_ms_tmp < 0.0) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = -1.0;
  } else {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = (RRTV3_PX4_OA_B.Vfwd_ms_tmp >
      0.0);
  }

  RRTV3_PX4_OA_B.u1_tmp = Integrated[3] * Params[31];
  RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = RRTV3_PX4_OA_B.u1_tmp -
    RRTV3_PX4_OA_B.dHDG * RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1;
  RRTV3_PX4_OA_B.DissipationGain = Params[31] / RRTV3_PX4_OA_B.DissipationGain *
    1.9438612860586268 * Integrated[3] - Integrated[6];
  if (States[12] > 0.0) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 = 1.0;
    RRTV3_PX4_OA_B.DissipationGain = (States[4] - Integrated[6]) * 5.0;
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = RRTV3_PX4_OA_B.u1_tmp;
  }

  RRTV3_PX4_OA_B.dHDG = Params[34] * 0.51444 * (Integrated[6] - States[4]);
  if ((Params[31] <= RRTV3_PX4_OA_B.dHDG) || rtIsNaN(RRTV3_PX4_OA_B.dHDG)) {
    RRTV3_PX4_OA_B.dHDG = Params[31];
  }

  if ((-Params[31] >= RRTV3_PX4_OA_B.dHDG) || rtIsNaN(RRTV3_PX4_OA_B.dHDG)) {
    RRTV3_PX4_OA_B.dHDG = -Params[31];
  }

  *AccCmd = (1.0 - RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0) *
    RRTV3_PX4_OA_B.dHDG + RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 *
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1;
  RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 = Params[31] * 9.81 * Integrated
    [3] * 1.9438612860586268 * (1.0 -
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0) +
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 *
    RRTV3_PX4_OA_B.DissipationGain;
  if ((Integrated[6] >= 50.0) && ((RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 >=
        0.0) || rtIsNaN(RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0))) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 = 0.0;
  }

  if ((Integrated[6] <= -3.0) && ((RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 <=
        0.0) || rtIsNaN(RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0))) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 = 0.0;
  }

  mem[7] = mem_in[7];
  if (Params[35] == 1.0) {
    if (mem_in[6] == 1.0) {
      RRTV3_PX4_OA_B.HeightError = mem_in[7] - RRTV3_PX4_OA_B.hAGL_ft;
      RRTV3_PX4_OA_B.FPMCmd = Params[36] * RRTV3_PX4_OA_B.HeightError +
        Integrated[7] * Params[37];
      if ((Params[16] <= RRTV3_PX4_OA_B.FPMCmd) || rtIsNaN(RRTV3_PX4_OA_B.FPMCmd))
      {
        RRTV3_PX4_OA_B.FPMCmd = Params[16];
      }

      if ((-Params[16] >= RRTV3_PX4_OA_B.FPMCmd) || rtIsNaN
          (RRTV3_PX4_OA_B.FPMCmd)) {
        RRTV3_PX4_OA_B.FPMCmd = -Params[16];
      }

      RRTV3_PX4_OA_B.LatVelErr = RRTV3_PX4_OA_B.FPMCmd / 196.79999999999998;
      RRTV3_PX4_OA_B.DihedralEffect = -Integrated[5];
    }

    if (mem_in[6] == 0.0) {
      mem[7] = RRTV3_PX4_OA_B.hAGL_ft;
      RRTV3_PX4_OA_B.HeightError = -Integrated[7];
      if ((RRTV3_PX4_OA_B.d_lon_inc == 0.0) && (fabs(RRTV3_PX4_OA_B.FPMCmd) <
           Params[40])) {
        RRTV3_PX4_OA_B.LatVelErr = -0.1 * States[9];
        if (fabs(RRTV3_PX4_OA_B.FPM) < Params[39]) {
          mem[7] = Params[38] * RRTV3_PX4_OA_B.FPM / 60.0 +
            RRTV3_PX4_OA_B.hAGL_ft;
          mem[6] = 1.0;
        }
      }
    }

    if ((RRTV3_PX4_OA_B.d_lon_inc != 0.0) || (States[12] > 0.0)) {
      mem[7] = RRTV3_PX4_OA_B.hAGL_ft;
      mem[6] = 0.0;
    }
  }

  if (mem_in[0] == 0.0) {
    if ((RRTV3_PX4_OA_B.d_dir_inc == 0.0) && (fabs(RRTV3_PX4_OA_B.TurnRate) <
         Params[42]) && (fabs(States[4]) < Params[46]) && (Params[41] == 1.0)) {
      RRTV3_PX4_OA_B.DIRHOLD = 1.0;
      RRTV3_PX4_OA_B.HDG_mem = Params[43] * RRTV3_PX4_OA_B.TurnRate +
        RRTV3_PX4_OA_B.HDG_p;
    }

    if ((RRTV3_PX4_OA_B.d_lat_inc == 0.0) && (fabs(RRTV3_PX4_OA_B.BANK) <
         Params[48]) && (fabs(States[4]) > Params[51]) && (Params[47] == 1.0)) {
      RRTV3_PX4_OA_B.DIRHOLD = 2.0;
      RRTV3_PX4_OA_B.TRK_mem = RRTV3_PX4_OA_B.TRK;
    }

    if (RRTV3_PX4_OA_B.DIRHOLD == 0.0) {
      RRTV3_PX4_OA_B.HDG_mem = RRTV3_PX4_OA_B.HDG_p;
      RRTV3_PX4_OA_B.TRK_mem = RRTV3_PX4_OA_B.TRK;
    }
  }

  if (RRTV3_PX4_OA_B.DIRHOLD == 1.0) {
    if (RRTV3_PX4_OA_B.d_dir_inc != 0.0) {
      RRTV3_PX4_OA_B.DIRHOLD = 0.0;
    }

    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = fabs(States[4]);
    if (RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 > Params[46]) {
      if ((RRTV3_PX4_OA_B.DIRHOLD == 1.0) && (RRTV3_PX4_OA_B.d_dir_inc == 0.0) &&
          (RRTV3_PX4_OA_B.d_lat_inc == 0.0)) {
        if (RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 > Params[46]) {
          if (Params[47] == 1.0) {
            RRTV3_PX4_OA_B.DIRHOLD = 2.0;
            RRTV3_PX4_OA_B.TRK_mem = RRTV3_PX4_OA_B.HDG_mem;
          } else {
            RRTV3_PX4_OA_B.DIRHOLD = 0.0;
          }
        } else {
          RRTV3_PX4_OA_B.DIRHOLD = 0.0;
        }
      } else {
        RRTV3_PX4_OA_B.DIRHOLD = 0.0;
      }
    }
  }

  if (RRTV3_PX4_OA_B.DIRHOLD == 2.0) {
    if (RRTV3_PX4_OA_B.d_lat_inc != 0.0) {
      RRTV3_PX4_OA_B.DIRHOLD = 0.0;
    }

    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 = fabs(States[4]);
    if (RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 < Params[51]) {
      if ((RRTV3_PX4_OA_B.DIRHOLD == 2.0) && (RRTV3_PX4_OA_B.d_dir_inc == 0.0) &&
          (RRTV3_PX4_OA_B.d_lat_inc == 0.0)) {
        if (RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_1 < Params[51]) {
          RRTV3_PX4_OA_B.DIRHOLD = (Params[41] == 1.0);
        } else {
          RRTV3_PX4_OA_B.DIRHOLD = 0.0;
        }
      } else {
        RRTV3_PX4_OA_B.DIRHOLD = 0.0;
      }
    }

    if (RRTV3_PX4_OA_B.DIRHOLD == 2.0) {
      RRTV3_PX4_OA_B.HDG_mem = RRTV3_PX4_OA_B.HDG_p;
    }
  }

  if (RRTV3_PX4_OA_B.DIRHOLD == 1.0) {
    RRTV3_PX4_OA_B.dHDG = RRTV3_PX4_OA_B.HDG_mem - RRTV3_PX4_OA_B.HDG_p;
    if (RRTV3_PX4_OA_B.dHDG > 180.0) {
      RRTV3_PX4_OA_B.dHDG -= 360.0;
    }

    if (RRTV3_PX4_OA_B.dHDG < -180.0) {
      RRTV3_PX4_OA_B.dHDG += 360.0;
    }

    *YawRateCmd = Params[44] * RRTV3_PX4_OA_B.dHDG - Params[45] *
      RRTV3_PX4_OA_B.TurnRate;
    if ((Params[25] <= *YawRateCmd) || rtIsNaN(*YawRateCmd)) {
      *YawRateCmd = Params[25];
    }

    if ((-Params[25] >= *YawRateCmd) || rtIsNaN(*YawRateCmd)) {
      *YawRateCmd = -Params[25];
    }
  }

  if ((Params[47] == 1.0) && (RRTV3_PX4_OA_B.DIRHOLD == 2.0)) {
    RRTV3_PX4_OA_B.TurnRate = RRTV3_PX4_OA_B.TRK_mem - RRTV3_PX4_OA_B.TRK;
    if (RRTV3_PX4_OA_B.TurnRate > 180.0) {
      RRTV3_PX4_OA_B.TurnRate -= 360.0;
    }

    if (RRTV3_PX4_OA_B.TurnRate < -180.0) {
      RRTV3_PX4_OA_B.TurnRate += 360.0;
    }

    RRTV3_PX4_OA_B.BankRateCmd = Params[50] * RRTV3_PX4_OA_B.TurnRate;
    *BankCmd = Params[49] * RRTV3_PX4_OA_B.TurnRate + Integrated[4];
    if ((*BankCmd >= 5.0) || rtIsNaN(*BankCmd)) {
      *BankCmd = 5.0;
    }

    if (*BankCmd <= -5.0) {
      *BankCmd = -5.0;
    }

    DirectBankCmdGen = 0;
  }

  RRTV3_PX4_OA_B.dHDG = States[7] * 3.1415926535897931 / 180.0;
  RRTV3_PX4_OA_B.TurnRate = cos(RRTV3_PX4_OA_B.dHDG) / 6.378137E+6;
  RRTV3_PX4_OA_B.dHDG = sin(RRTV3_PX4_OA_B.dHDG) / 6.3567523E+6;
  RRTV3_PX4_OA_B.TurnRate = 1.0 / sqrt(RRTV3_PX4_OA_B.TurnRate *
    RRTV3_PX4_OA_B.TurnRate + RRTV3_PX4_OA_B.dHDG * RRTV3_PX4_OA_B.dHDG) +
    States[10];
  RRTV3_PX4_OA_B.dHDG = States[7];
  RRTV3_PX4_OA_cosd(&RRTV3_PX4_OA_B.dHDG);
  RRTV3_PX4_OA_B.dHDG *= RRTV3_PX4_OA_B.TurnRate;
  if (Params[52] == 1.0) {
    RRTV3_PX4_OA_B.LatDeg_ref = States[7];
    RRTV3_PX4_OA_B.LongDeg_ref = States[8];
    if (mem_in[3] == 0.0) {
      RRTV3_PX4_OA_B.FwdAftPosnErr = -Integrated[8] * 10.0;
      RRTV3_PX4_OA_B.LongDeg_ref = RRTV3_PX4_OA_B.HDG_p;
      RRTV3_PX4_OA_sind(&RRTV3_PX4_OA_B.LongDeg_ref);
      RRTV3_PX4_OA_B.LongDeg_mem = RRTV3_PX4_OA_B.HDG_p;
      RRTV3_PX4_OA_cosd(&RRTV3_PX4_OA_B.LongDeg_mem);
      RRTV3_PX4_OA_B.LatDeg_ref = (RRTV3_PX4_OA_B.Vfwd_ms_tmp *
        RRTV3_PX4_OA_B.LongDeg_mem - States[5] * RRTV3_PX4_OA_B.LongDeg_ref) *
        Params[60] * 57.295779513082323 / RRTV3_PX4_OA_B.TurnRate + States[7];
      RRTV3_PX4_OA_B.LongDeg_ref = (RRTV3_PX4_OA_B.Vfwd_ms_tmp *
        RRTV3_PX4_OA_B.LongDeg_ref + States[5] * RRTV3_PX4_OA_B.LongDeg_mem) *
        Params[60] * 57.295779513082323 / RRTV3_PX4_OA_B.dHDG + States[8];
      if ((AUTOFLIGHT[8] == 1.0) && (AUTOFLIGHT[6] == 0.0)) {
        RRTV3_PX4_OA_B.LatDeg_ref = AUTOFLIGHT[13];
        RRTV3_PX4_OA_B.LongDeg_ref = AUTOFLIGHT[14];
      }

      RRTV3_PX4_OA_B.LatDeg_mem = RRTV3_PX4_OA_B.LatDeg_ref;
      RRTV3_PX4_OA_B.LongDeg_mem = RRTV3_PX4_OA_B.LongDeg_ref;
    }

    if (mem_in[3] == 1.0) {
      RRTV3_PX4_OA_B.LatDeg_ref = RRTV3_PX4_OA_B.LatDeg_mem;
      RRTV3_PX4_OA_B.LongDeg_ref = RRTV3_PX4_OA_B.LongDeg_mem;
      RRTV3_PX4_OA_B.LeftRightPosnErr = (RRTV3_PX4_OA_B.LatDeg_mem - States[7]) *
        0.017453292519943295 * RRTV3_PX4_OA_B.TurnRate;
      RRTV3_PX4_OA_B.LongDeg_mem = (RRTV3_PX4_OA_B.LongDeg_mem - States[8]) *
        0.017453292519943295 * RRTV3_PX4_OA_B.dHDG;
      RRTV3_PX4_OA_B.BankRateCmd = RRTV3_PX4_OA_B.HDG_p;
      RRTV3_PX4_OA_sind(&RRTV3_PX4_OA_B.BankRateCmd);
      RRTV3_PX4_OA_B.LatDeg_mem = RRTV3_PX4_OA_B.HDG_p;
      RRTV3_PX4_OA_cosd(&RRTV3_PX4_OA_B.LatDeg_mem);
      RRTV3_PX4_OA_B.FwdAftPosnErr = RRTV3_PX4_OA_B.LeftRightPosnErr *
        RRTV3_PX4_OA_B.LatDeg_mem + RRTV3_PX4_OA_B.LongDeg_mem *
        RRTV3_PX4_OA_B.BankRateCmd;
      RRTV3_PX4_OA_B.LeftRightPosnErr = -RRTV3_PX4_OA_B.LeftRightPosnErr *
        RRTV3_PX4_OA_B.BankRateCmd + RRTV3_PX4_OA_B.LongDeg_mem *
        RRTV3_PX4_OA_B.LatDeg_mem;
      *AccCmd = ((Params[56] * RRTV3_PX4_OA_B.FwdAftPosnErr + Integrated[8] *
                  Params[57]) - Params[58] * RRTV3_PX4_OA_B.Vfwd_ms_tmp) *
        3.1415926535897931 / 180.0;
      if ((!(*AccCmd <= Params[31])) && (!rtIsNaN(Params[31]))) {
        *AccCmd = Params[31];
      }

      if ((-Params[31] >= *AccCmd) || rtIsNaN(*AccCmd)) {
        *AccCmd = -Params[31];
      }

      *BankCmd = (Params[53] * RRTV3_PX4_OA_B.LeftRightPosnErr + Integrated[4])
        - States[5] * Params[55];
      if ((!(*BankCmd <= Params[4])) && (!rtIsNaN(Params[4]))) {
        *BankCmd = Params[4];
      }

      if ((-Params[4] >= *BankCmd) || rtIsNaN(*BankCmd)) {
        *BankCmd = -Params[4];
      }

      RRTV3_PX4_OA_B.BankRateCmd = Params[54] * RRTV3_PX4_OA_B.LeftRightPosnErr;
      DirectBankCmdGen = 0;
    }

    if ((RRTV3_PX4_OA_B.d_lat_inc != 0.0) || (RRTV3_PX4_OA_B.d_acc_inc != 0.0))
    {
      RRTV3_PX4_OA_B.POSNHOLD = 0.0;
    } else if (Integrated[6] > Params[59]) {
      RRTV3_PX4_OA_B.POSNHOLD = 0.0;
    }

    if ((RRTV3_PX4_OA_B.POSNHOLD == 0.0) && (RRTV3_PX4_OA_B.d_lat_inc == 0.0) &&
        (RRTV3_PX4_OA_B.d_acc_inc == 0.0) && (sqrt(States[4] * States[4] +
          RRTV3_PX4_OA_B.LatVel_kt * RRTV3_PX4_OA_B.LatVel_kt) <= Params[59])) {
      RRTV3_PX4_OA_B.POSNHOLD = 1.0;
    }
  }

  if (AUTOFLIGHT[8] == 1.0) {
    mem[6] = 0.0;
    RRTV3_PX4_OA_B.DIRHOLD = 0.0;
    DirectBankCmdGen = 1;
    if (AUTOFLIGHT[11] == 1.0) {
      DirectBankCmdGen = 0;
      mem[6] = 1.0;
    }

    if (RRTV3_PX4_OA_B.POSNHOLD == 1.0) {
      DirectBankCmdGen = 0;
    }
  }

  if (AUTOFLIGHT[6] == 1.0) {
    mem[6] = 0.0;
    RRTV3_PX4_OA_B.POSNHOLD = 0.0;
    if (RRTV3_PX4_OA_B.hAGL_ft > 3.0) {
      RRTV3_PX4_OA_B.POSNHOLD = 1.0;
    }
  }

  if (AUTOFLIGHT[10] == 1.0) {
    mem[6] = 0.0;
  }

  if (AUTOFLIGHT[7] > 0.0) {
    RRTV3_PX4_OA_B.POSNHOLD = 0.0;
  }

  if (AUTOFLIGHT[11] == 1.0) {
    RRTV3_PX4_OA_B.DIRHOLD = 1.0;
    RRTV3_PX4_OA_B.POSNHOLD = 0.0;
    RRTV3_PX4_OA_B.LatDeg_ref = AUTOFLIGHT[13];
    RRTV3_PX4_OA_B.LongDeg_ref = AUTOFLIGHT[14];
    DirectBankCmdGen = 0;
    RRTV3_PX4_OA_B.BankRateCmd = AUTOFLIGHT[3];
  }

  if ((AUTOFLIGHT[12] > 0.0) && (AUTOFLIGHT[8] == 0.0)) {
    if (fabs(AUTOFLIGHT[0]) > 0.05) {
      mem[6] = 0.0;
    }

    if (fabs(AUTOFLIGHT[1]) > 0.02) {
      RRTV3_PX4_OA_B.POSNHOLD = 0.0;
    }

    if (fabs(AUTOFLIGHT[4]) > 1.0) {
      RRTV3_PX4_OA_B.DIRHOLD = 0.0;
      RRTV3_PX4_OA_B.HDG_mem = RRTV3_PX4_OA_B.HDG_p;
      RRTV3_PX4_OA_B.TRK_mem = RRTV3_PX4_OA_B.TRK;
    }
  }

  if (d_inc[16] == 1.0) {
    RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 = 0.0 - Integrated[6];
    if (States[4] < Params[61]) {
      RRTV3_PX4_OA_B.POSNHOLD = 1.0;
      mem[6] = 0.0;
      mem[7] = 2.0 * RRTV3_PX4_OA_B.FPM / 60.0 + RRTV3_PX4_OA_B.hAGL_ft;
      RRTV3_PX4_OA_B.dHDG = (-5.0 - RRTV3_PX4_OA_B.hAGL_ft) * Params[36];
      if ((-Params[62] >= RRTV3_PX4_OA_B.dHDG) || rtIsNaN(RRTV3_PX4_OA_B.dHDG))
      {
        RRTV3_PX4_OA_B.dHDG = -Params[62];
      }

      RRTV3_PX4_OA_B.LatVelErr = RRTV3_PX4_OA_B.dHDG / 196.79999999999998;
      if (States[12] > 0.0) {
        RRTV3_PX4_OA_B.LatVelErr = -1.0;
      }
    }
  }

  if (fabs(AUTOFLIGHT[2]) > 0.001) {
    if (RRTV3_PX4_OA_B.d_lat_inc == 0.0) {
      *BankCmd = AUTOFLIGHT[2];
      RRTV3_PX4_OA_B.BankRateCmd = AUTOFLIGHT[3];
    }

    if (RRTV3_PX4_OA_B.d_lat_inc != 0.0) {
      *BankCmd += AUTOFLIGHT[2];
      RRTV3_PX4_OA_B.BankRateCmd += AUTOFLIGHT[3];
    }
  }

  if (fabs(AUTOFLIGHT[0]) > 0.0001) {
    if (RRTV3_PX4_OA_B.d_lon_inc == 0.0) {
      RRTV3_PX4_OA_B.LatVelErr = AUTOFLIGHT[0];
    }

    if (RRTV3_PX4_OA_B.d_lon_inc != 0.0) {
      RRTV3_PX4_OA_B.LatVelErr += AUTOFLIGHT[0];
    }
  }

  if (fabs(AUTOFLIGHT[4]) > 0.0001) {
    if (RRTV3_PX4_OA_B.d_dir_inc == 0.0) {
      *YawRateCmd = AUTOFLIGHT[4];
    }

    if (RRTV3_PX4_OA_B.d_dir_inc != 0.0) {
      *YawRateCmd += AUTOFLIGHT[4];
    }
  }

  if (fabs(AUTOFLIGHT[1]) > 0.0001) {
    if (RRTV3_PX4_OA_B.d_acc_inc == 0.0) {
      *AccCmd = AUTOFLIGHT[1];
    }

    if (RRTV3_PX4_OA_B.d_acc_inc != 0.0) {
      *AccCmd += AUTOFLIGHT[1];
    }
  }

  if (AUTOFLIGHT[5] != 0.0) {
    if (RRTV3_PX4_OA_B.d_acc_inc == 0.0) {
      RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 = AUTOFLIGHT[5];
    }

    if (RRTV3_PX4_OA_B.d_acc_inc != 0.0) {
      RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0 += AUTOFLIGHT[5];
    }
  }

  VVCmdVec[0] = RRTV3_PX4_OA_B.LatVelErr;
  if (DirectBankCmdGen == 1) {
    RRTV3_PX4_OA_B.BankRateCmd = (RRTV3_PX4_OA_B.BANK - Integrated[4]) * 10.0;
  }

  if (States[12] > 0.0) {
    RRTV3_PX4_OA_B.BankRateCmd = 0.0;
    *BankCmd = 0.0;
    *YawRateCmd = 0.0;
    RRTV3_PX4_OA_B.DIRHOLD = 0.0;
    mem[6] = 0.0;
    mem[7] = RRTV3_PX4_OA_B.hAGL_ft;
    RRTV3_PX4_OA_B.POSNHOLD = 0.0;
    RRTV3_PX4_OA_B.FwdAftPosnErr = -Integrated[8];
    RRTV3_PX4_OA_B.HeightError = -Integrated[7];
    RRTV3_PX4_OA_B.LatDeg_ref = States[7];
    RRTV3_PX4_OA_B.LongDeg_ref = States[8];
  }

  mem[0] = RRTV3_PX4_OA_B.DIRHOLD;
  mem[1] = RRTV3_PX4_OA_B.HDG_mem;
  mem[2] = RRTV3_PX4_OA_B.TRK_mem;
  mem[3] = RRTV3_PX4_OA_B.POSNHOLD;
  mem[4] = RRTV3_PX4_OA_B.LatDeg_ref;
  mem[5] = RRTV3_PX4_OA_B.LongDeg_ref;
  TBI[0] = (RRTV3_PX4_OA_B.d_lat_inc - Integrated[0]) / Params[1];
  TBI[1] = (RRTV3_PX4_OA_B.d_lon_inc - Integrated[1]) / Params[14];
  TBI[2] = (RRTV3_PX4_OA_B.d_dir_inc - Integrated[2]) / Params[23];
  TBI[3] = (RRTV3_PX4_OA_B.d_acc_inc - Integrated[3]) / Params[29];
  TBI[4] = RRTV3_PX4_OA_B.BankRateCmd;
  TBI[5] = RRTV3_PX4_OA_B.DihedralEffect;
  TBI[6] = RRTV3_PX4_OA_B.FPARateLoadFactorLimits_idx_0;
  TBI[7] = RRTV3_PX4_OA_B.HeightError;
  TBI[8] = RRTV3_PX4_OA_B.FwdAftPosnErr;
  TBI[9] = RRTV3_PX4_OA_B.LeftRightPosnErr;
}

// Function for MATLAB Function: '<S12>/MATLAB Function'
static void RRTV3_PX4_OA_FFMPitchControl(real_T KTIV, real_T KTPV, real_T K_TRIM,
  real_T K_PITCHFF, real_T th_c, real_T VVCmd, real_T VertAccCmd_g, real_T
  HorzAccCmd_g, real_T VV, real_T horz_acc, real_T F, real_T pitch_shadow,
  real_T specified_rate, real_T spd_pri, real_T *pitch_cmd, real_T
  *pitch_cmd_rate)
{
  real_T pitch_cmd_rate_1;
  pitch_cmd_rate_1 = 57.295779513082323 * KTIV * (VVCmd - VV) * F;
  if (spd_pri != 0.0) {
    pitch_cmd_rate_1 = -57.295779513082323 * KTIV * (HorzAccCmd_g - horz_acc);
  }

  *pitch_cmd_rate = (-K_TRIM * horz_acc + pitch_cmd_rate_1) + specified_rate;
  pitch_cmd_rate_1 = th_c;
  if (spd_pri != 0.0) {
    pitch_cmd_rate_1 = 57.295779513082323 * KTPV * horz_acc;
  }

  *pitch_cmd = ((-57.295779513082323 * KTPV * VV * F + K_PITCHFF * VertAccCmd_g)
                + pitch_cmd_rate_1) + pitch_shadow;
}

// Function for MATLAB Function: '<S12>/MATLAB Function'
static void RRTV3_PX4_OA_TCS_RRTV(real_T AccCmd, const real_T VVCmd[2], real_T
  VCmdkt, const real_T TCSGains[10], const real_T TCSParams[35], const real_T
  WingParams[6], const real_T PRIORITY[6], const real_T Integrated[5], const
  real_T memory_in[2], const real_T States[5], real_T *PitchCmd, real_T *TWCmd,
  real_T *WingCmd, real_T *TAICmd, real_T Debug[2], real_T TBI[5], real_T
  memory_out[2])
{
  real_T FwdAccErr;
  real_T TBI_tmp;
  real_T TWH_Cmd;
  real_T VertAccCmd_g;
  real_T d;
  real_T mode_out;
  *PitchCmd = 0.0;
  *TWCmd = 0.0;
  TBI[2] = 0.0;
  RRTV3_PX4_OA_B.TWCmd_ShadowRate = 0.0;
  RRTV3_PX4_OA_B.WingCmd_Rate = 0.0;
  RRTV3_PX4_OA_B.Acc = States[1] / 9.81;
  RRTV3_PX4_OA_B.Va2 = TCSParams[3] / 2.0;
  RRTV3_PX4_OA_B.F = 1.0 / (States[2] * 0.51444);
  RRTV3_PX4_OA_B.zeta_a = 1.0 / (RRTV3_PX4_OA_B.Va2 - (TCSParams[3] - 5.0)) *
    (States[2] - RRTV3_PX4_OA_B.Va2) + 1.0;
  if (!(RRTV3_PX4_OA_B.zeta_a <= 1.0)) {
    RRTV3_PX4_OA_B.zeta_a = 1.0;
  }

  if (RRTV3_PX4_OA_B.zeta_a <= 0.0) {
    RRTV3_PX4_OA_B.zeta_a = 0.0;
  }

  RRTV3_PX4_OA_B.Va2 = 1.0 / (TCSParams[1] - TCSParams[0]) * (States[2] -
    TCSParams[1]) + 1.0;
  if (!(RRTV3_PX4_OA_B.Va2 <= 1.0)) {
    RRTV3_PX4_OA_B.Va2 = 1.0;
  }

  mode_out = 1.0 / (TCSParams[3] - TCSParams[2]) * (States[2] - TCSParams[3]) +
    1.0;
  if (!(mode_out <= 1.0)) {
    mode_out = 1.0;
  }

  if (RRTV3_PX4_OA_B.Va2 <= 0.0) {
    RRTV3_PX4_OA_B.Va2 = 0.0;
  }

  if (mode_out <= 0.0) {
    mode_out = 0.0;
  }

  RRTV3_PX4_OA_B.DeckLev = RRTV3_PX4_OA_B.Va2 + mode_out;
  RRTV3_PX4_OA_B.KFFA = (1.0 - States[2] / TCSParams[0]) * 57.295779513082323;
  if (RRTV3_PX4_OA_B.KFFA < 0.0) {
    RRTV3_PX4_OA_B.KFFA = 0.0;
  }

  RRTV3_PX4_OA_B.KFFA *= TCSParams[16];
  RRTV3_PX4_OA_B.Va2 = States[4];
  RRTV3_PX4_OA_cosd(&RRTV3_PX4_OA_B.Va2);
  mode_out = States[4];
  RRTV3_PX4_OA_cosd(&mode_out);
  RRTV3_PX4_OA_B.th_c = 57.295779513082323 * TCSGains[4] * RRTV3_PX4_OA_B.Va2 *
    (1.0 / mode_out - 1.0) * RRTV3_PX4_OA_B.zeta_a;
  RRTV3_PX4_OA_B.Va2 = memory_in[1];
  mode_out = memory_in[0];
  FwdAccErr = VCmdkt - States[2];
  if (FwdAccErr >= TCSParams[15]) {
    RRTV3_PX4_OA_B.Va2 = 1.0;
  }

  if (FwdAccErr <= -TCSParams[15]) {
    RRTV3_PX4_OA_B.Va2 = -1.0;
  }

  FwdAccErr = AccCmd - RRTV3_PX4_OA_B.Acc;
  VertAccCmd_g = VVCmd[0] / TCSParams[12] / 9.81;
  if (PRIORITY[0] != 0.0) {
    AccCmd = TCSGains[8] / 9.81 * (PRIORITY[4] - States[2]) * 0.51444;
    FwdAccErr = AccCmd - RRTV3_PX4_OA_B.Acc;
    if ((PRIORITY[2] != 0.0) && (!(FwdAccErr <= 0.0))) {
      FwdAccErr = 0.0;
    }

    if ((PRIORITY[3] != 0.0) && (!(FwdAccErr >= 0.0))) {
      FwdAccErr = 0.0;
    }
  }

  FwdAccErr *= TCSGains[0];
  TBI_tmp = VVCmd[0] - States[0];
  TBI[1] = TBI_tmp / TCSParams[12] / 9.81 * TCSGains[2];
  TWH_Cmd = Integrated[0] - TCSGains[1] * RRTV3_PX4_OA_B.Acc;
  if ((TWH_Cmd <= -0.2) || rtIsNaN(TWH_Cmd)) {
    TWH_Cmd = -0.2;
  }

  d = States[4];
  RRTV3_PX4_OA_cosd(&d);
  RRTV3_PX4_OA_B.zeta_a = (Integrated[1] - States[0] / TCSParams[12] / 9.81 *
    TCSGains[3]) + (1.0 / d - 1.0) * (1.0 - RRTV3_PX4_OA_B.zeta_a);
  if ((RRTV3_PX4_OA_B.zeta_a <= 0.01) || rtIsNaN(RRTV3_PX4_OA_B.zeta_a)) {
    RRTV3_PX4_OA_B.zeta_a = 0.01;
  }

  *TAICmd = 57.295779513082323 * rt_atan2d_snf(RRTV3_PX4_OA_B.zeta_a, TWH_Cmd);
  if ((memory_in[0] == 1.0) && (RRTV3_PX4_OA_B.DeckLev > TCSParams[4]) &&
      (RRTV3_PX4_OA_B.Va2 == 1.0) && (States[3] == 0.0)) {
    mode_out = 2.0;
  }

  if ((memory_in[0] == 2.0) && (VCmdkt > TCSParams[2]) && (Integrated[4] <=
       TCSParams[24])) {
    mode_out = 3.0;
  }

  if ((memory_in[0] == 3.0) && (Integrated[4] <= TCSParams[25]) && (VCmdkt >
       TCSParams[3])) {
    mode_out = 4.0;
  }

  if ((memory_in[0] == 4.0) && (RRTV3_PX4_OA_B.DeckLev < TCSParams[7]) &&
      (VCmdkt < TCSParams[3])) {
    mode_out = 3.0;
  }

  if ((memory_in[0] == 3.0) && (Integrated[4] > TCSParams[26]) && (VCmdkt <
       TCSParams[3])) {
    mode_out = 2.0;
  }

  if ((memory_in[0] == 2.0) && (RRTV3_PX4_OA_B.DeckLev < TCSParams[9]) &&
      (VCmdkt < TCSParams[1]) && (Integrated[4] > TCSParams[27])) {
    mode_out = 1.0;
  }

  if (States[3] > 0.0) {
    mode_out = 1.0;
  }

  if (memory_in[0] == 1.0) {
    *PitchCmd = (-RRTV3_PX4_OA_B.KFFA * AccCmd + *TAICmd) - Integrated[4];
    TBI[2] = (*PitchCmd - Integrated[2]) * TCSParams[14];
    *TWCmd = sqrt(TWH_Cmd * TWH_Cmd + RRTV3_PX4_OA_B.zeta_a *
                  RRTV3_PX4_OA_B.zeta_a);
    RRTV3_PX4_OA_B.TWCmd_ShadowRate = (*TWCmd - Integrated[3]) * TCSParams[14];
    RRTV3_PX4_OA_B.WingCmd_Rate = TCSParams[32] * *PitchCmd;
    if ((TCSParams[28] <= RRTV3_PX4_OA_B.WingCmd_Rate) || rtIsNaN
        (RRTV3_PX4_OA_B.WingCmd_Rate)) {
      RRTV3_PX4_OA_B.WingCmd_Rate = TCSParams[28];
    }

    if ((-TCSParams[28] >= RRTV3_PX4_OA_B.WingCmd_Rate) || rtIsNaN
        (RRTV3_PX4_OA_B.WingCmd_Rate)) {
      RRTV3_PX4_OA_B.WingCmd_Rate = -TCSParams[28];
    }

    if (States[3] > 0.0) {
      RRTV3_PX4_OA_B.WingCmd_Rate = 0.0;
    }
  }

  if (memory_in[0] == 2.0) {
    TBI[2] = (RRTV3_PX4_OA_B.th_c - Integrated[2]) * TCSParams[13];
    if ((*TAICmd >= 70.0) && (RRTV3_PX4_OA_B.Va2 == -1.0)) {
      TBI[2] = (TCSParams[21] - Integrated[2]) * TCSParams[13];
    }

    *PitchCmd = Integrated[2];
    RRTV3_PX4_OA_B.TWCmd_ShadowRate = sqrt(TWH_Cmd * TWH_Cmd +
      RRTV3_PX4_OA_B.zeta_a * RRTV3_PX4_OA_B.zeta_a);
    if ((TCSParams[22] <= RRTV3_PX4_OA_B.TWCmd_ShadowRate) || rtIsNaN
        (RRTV3_PX4_OA_B.TWCmd_ShadowRate)) {
      RRTV3_PX4_OA_B.TWCmd_ShadowRate = TCSParams[22];
    }

    RRTV3_PX4_OA_B.TWCmd_ShadowRate = 1.0 / TCSParams[31] *
      (RRTV3_PX4_OA_B.TWCmd_ShadowRate - Integrated[3]);
    *TWCmd = Integrated[3];
    if ((*TAICmd <= 0.0) || rtIsNaN(*TAICmd)) {
      RRTV3_PX4_OA_B.WingCmd_Rate = 0.0;
    } else {
      RRTV3_PX4_OA_B.WingCmd_Rate = *TAICmd;
    }

    if (WingParams[0] <= RRTV3_PX4_OA_B.WingCmd_Rate) {
      RRTV3_PX4_OA_B.WingCmd_Rate = WingParams[0];
    }

    RRTV3_PX4_OA_B.WingCmd_Rate = 1.0 / TCSParams[31] *
      (RRTV3_PX4_OA_B.WingCmd_Rate - Integrated[4]);
  }

  if (memory_in[0] == 3.0) {
    if (VCmdkt > TCSParams[2]) {
      RRTV3_PX4_OA_B.WingCmd_Rate = (WingParams[1] - Integrated[4]) / TCSParams
        [31];
      if ((!(RRTV3_PX4_OA_B.WingCmd_Rate >= -TCSParams[33])) && (!rtIsNaN
           (-TCSParams[33]))) {
        RRTV3_PX4_OA_B.WingCmd_Rate = -TCSParams[33];
      }

      if ((TCSParams[33] <= RRTV3_PX4_OA_B.WingCmd_Rate) || rtIsNaN
          (RRTV3_PX4_OA_B.WingCmd_Rate)) {
        RRTV3_PX4_OA_B.WingCmd_Rate = TCSParams[33];
      }

      TBI[1] = -Integrated[1];
      *TWCmd = TWH_Cmd;
      RRTV3_PX4_OA_B.TWCmd_ShadowRate = (TWH_Cmd - Integrated[3]) * TCSParams[14];
    }

    if (VCmdkt < TCSParams[3]) {
      RRTV3_PX4_OA_B.WingCmd_Rate = ((TCSParams[26] + 5.0) - Integrated[4]) /
        TCSParams[31];
      if ((!(RRTV3_PX4_OA_B.WingCmd_Rate >= -TCSParams[34])) && (!rtIsNaN
           (-TCSParams[34]))) {
        RRTV3_PX4_OA_B.WingCmd_Rate = -TCSParams[34];
      }

      if ((TCSParams[34] <= RRTV3_PX4_OA_B.WingCmd_Rate) || rtIsNaN
          (RRTV3_PX4_OA_B.WingCmd_Rate)) {
        RRTV3_PX4_OA_B.WingCmd_Rate = TCSParams[34];
      }

      *TWCmd = sqrt(TWH_Cmd * TWH_Cmd + RRTV3_PX4_OA_B.zeta_a *
                    RRTV3_PX4_OA_B.zeta_a);
      RRTV3_PX4_OA_B.TWCmd_ShadowRate = (*TWCmd - Integrated[3]) * TCSParams[14];
    }

    RRTV3_PX4_OA_FFMPitchControl(TCSGains[2], TCSGains[3], TCSGains[5],
      TCSGains[6], RRTV3_PX4_OA_B.th_c, VVCmd[0], VertAccCmd_g, AccCmd, States[0],
      RRTV3_PX4_OA_B.Acc, RRTV3_PX4_OA_B.F, Integrated[2], 0.0, PRIORITY[0],
      PitchCmd, &TBI[2]);
  }

  if (memory_in[0] == 4.0) {
    RRTV3_PX4_OA_FFMPitchControl(TCSGains[2], TCSGains[3], TCSGains[5],
      TCSGains[6], RRTV3_PX4_OA_B.th_c, VVCmd[0], VertAccCmd_g, AccCmd, States[0],
      RRTV3_PX4_OA_B.Acc, RRTV3_PX4_OA_B.F, Integrated[2], 0.0, PRIORITY[0],
      PitchCmd, &TBI[2]);
    RRTV3_PX4_OA_B.TWCmd_ShadowRate = (TBI_tmp * RRTV3_PX4_OA_B.F + (AccCmd -
      RRTV3_PX4_OA_B.Acc)) * TCSGains[0];
    *TWCmd = Integrated[3] - (RRTV3_PX4_OA_B.F * States[0] + RRTV3_PX4_OA_B.Acc)
      * TCSGains[1];
    if ((*TWCmd <= 0.01) && ((RRTV3_PX4_OA_B.TWCmd_ShadowRate <= 0.0) || rtIsNaN
         (RRTV3_PX4_OA_B.TWCmd_ShadowRate))) {
      RRTV3_PX4_OA_B.TWCmd_ShadowRate = 0.0;
    }

    if ((*TWCmd >= 2.0) && ((RRTV3_PX4_OA_B.TWCmd_ShadowRate >= 0.0) || rtIsNaN
                            (RRTV3_PX4_OA_B.TWCmd_ShadowRate))) {
      RRTV3_PX4_OA_B.TWCmd_ShadowRate = 0.0;
    }

    FwdAccErr = (*TWCmd - TWH_Cmd) * TCSParams[14];
    TBI[1] = -Integrated[1];
    RRTV3_PX4_OA_B.WingCmd_Rate = (WingParams[1] - Integrated[4]) * 0.5;
    *TAICmd = Integrated[4] + *PitchCmd;
  }

  if (States[3] > 0.0) {
    if (VVCmd[0] < 0.1) {
      RRTV3_PX4_OA_B.TWCmd_ShadowRate = (TCSParams[10] - Integrated[3]) *
        TCSParams[14];
      TBI[1] = (TCSParams[10] - Integrated[1]) * TCSParams[14];
      FwdAccErr = -TCSParams[14] * Integrated[0];
      TBI[2] = -TCSParams[14] * Integrated[2];
      *PitchCmd = Integrated[2];
    }

    if (VVCmd[0] >= 0.1) {
      TBI[2] = -TCSParams[14] * Integrated[2];
      *PitchCmd = Integrated[2];
      FwdAccErr = -TCSParams[14] * Integrated[0];
      if (Integrated[1] < 0.95 * TCSParams[11]) {
        TBI[1] = (TCSParams[11] - Integrated[1]) * TCSParams[18];
      }

      if (Integrated[1] >= 0.95 * TCSParams[11]) {
        RRTV3_PX4_OA_B.TWCmd_ShadowRate = VVCmd[0] * TCSParams[17] + TCSParams
          [11];
        TBI[1] = (RRTV3_PX4_OA_B.TWCmd_ShadowRate - Integrated[1]) * TCSParams
          [18];
        RRTV3_PX4_OA_B.TWCmd_ShadowRate = (RRTV3_PX4_OA_B.TWCmd_ShadowRate -
          Integrated[3]) * TCSParams[14];
      }
    }
  }

  if (fabs(PRIORITY[5]) > 0.0) {
    TBI[2] = (PRIORITY[5] - Integrated[2]) * TCSParams[14];
    *PitchCmd = Integrated[2];
  }

  if ((!(*PitchCmd <= TCSParams[19])) && (!rtIsNaN(TCSParams[19]))) {
    *PitchCmd = TCSParams[19];
  }

  if ((TCSParams[20] >= *PitchCmd) || rtIsNaN(*PitchCmd)) {
    *PitchCmd = TCSParams[20];
  }

  if (WingParams[4] == 0.0) {
    RRTV3_PX4_OA_B.WingCmd_Rate = (WingParams[5] - Integrated[4]) / TCSParams[31];
    if (WingParams[5] >= 80.0) {
      mode_out = 1.0;
      FwdAccErr = -Integrated[0];
    }

    if (WingParams[5] < 80.0) {
      if (WingParams[5] > 30.0) {
        mode_out = 2.0;
        FwdAccErr = -Integrated[0];
      } else if (WingParams[5] > 10.0) {
        mode_out = 3.0;
        RRTV3_PX4_OA_B.Va2 = 1.0;
      } else {
        mode_out = 4.0;
      }
    }
  }

  if (Integrated[4] <= WingParams[1]) {
    if ((RRTV3_PX4_OA_B.WingCmd_Rate <= 0.0) || rtIsNaN
        (RRTV3_PX4_OA_B.WingCmd_Rate)) {
      RRTV3_PX4_OA_B.WingCmd_Rate = 0.0;
    }

    if ((memory_in[0] <= 2.0) && ((FwdAccErr >= 0.0) || rtIsNaN(FwdAccErr))) {
      FwdAccErr = 0.0;
    }
  }

  if ((Integrated[4] >= WingParams[0]) && (memory_in[0] <= 2.0) &&
      ((RRTV3_PX4_OA_B.WingCmd_Rate >= 0.0) || rtIsNaN
       (RRTV3_PX4_OA_B.WingCmd_Rate))) {
    RRTV3_PX4_OA_B.WingCmd_Rate = 0.0;
  }

  if ((mode_out == 1.0) && (*TAICmd <= TCSParams[20] + 90.0) && ((FwdAccErr >=
        0.0) || rtIsNaN(FwdAccErr))) {
    FwdAccErr = 0.0;
  }

  if ((mode_out == 2.0) && (Integrated[0] < -0.05) && ((FwdAccErr <= 0.0) ||
       rtIsNaN(FwdAccErr))) {
    FwdAccErr = 0.0;
  }

  if (Integrated[3] >= TCSParams[22] - 0.01) {
    if ((FwdAccErr >= 0.0) || rtIsNaN(FwdAccErr)) {
      FwdAccErr = 0.0;
    }

    if ((RRTV3_PX4_OA_B.TWCmd_ShadowRate >= 0.0) || rtIsNaN
        (RRTV3_PX4_OA_B.TWCmd_ShadowRate)) {
      RRTV3_PX4_OA_B.TWCmd_ShadowRate = 0.0;
    }
  }

  *WingCmd = Integrated[4];
  memory_out[0] = mode_out;
  memory_out[1] = RRTV3_PX4_OA_B.Va2;
  TBI[0] = FwdAccErr;
  TBI[3] = RRTV3_PX4_OA_B.TWCmd_ShadowRate;
  if ((WingParams[3] >= RRTV3_PX4_OA_B.WingCmd_Rate) || rtIsNaN
      (RRTV3_PX4_OA_B.WingCmd_Rate)) {
    RRTV3_PX4_OA_B.WingCmd_Rate = WingParams[3];
  }

  if ((WingParams[2] <= RRTV3_PX4_OA_B.WingCmd_Rate) || rtIsNaN
      (RRTV3_PX4_OA_B.WingCmd_Rate)) {
    TBI[4] = WingParams[2];
  } else {
    TBI[4] = RRTV3_PX4_OA_B.WingCmd_Rate;
  }

  Debug[0] = Integrated[1];
  Debug[1] = Integrated[0];
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void RRTV3_PX4_OA_PWM_setupImpl_p(px4_internal_block_PWM_RRTV3__T *obj,
  boolean_T armPWM, boolean_T forceFailsafe)
{
  obj->isMain = false;
  pwm_open(&obj->actuatorAdvertiseObj, &obj->armAdvertiseObj);
  obj->servoCount = 8;
  if (armPWM) {
    pwm_arm(&obj->armAdvertiseObj);
    obj->isArmed = true;
  } else {
    pwm_disarm(&obj->armAdvertiseObj);
    obj->isArmed = false;
  }

  obj->channelMask = 63;
  if (obj->isMain) {
    if (forceFailsafe) {
      pwm_disarm(&obj->armAdvertiseObj);
    } else {
      pwm_arm(&obj->armAdvertiseObj);
    }
  }
}

static void RRTV3_PX4_OA_PWM_setupImpl(px4_internal_block_PWM_RRTV3__T *obj,
  boolean_T armPWM, boolean_T forceFailsafe)
{
  obj->isMain = true;
  pwm_open(&obj->actuatorAdvertiseObj, &obj->armAdvertiseObj);
  obj->servoCount = 8;
  if (armPWM) {
    pwm_arm(&obj->armAdvertiseObj);
    obj->isArmed = true;
  } else {
    pwm_disarm(&obj->armAdvertiseObj);
    obj->isArmed = false;
  }

  obj->channelMask = 15;
  if (obj->isMain) {
    if (forceFailsafe) {
      pwm_disarm(&obj->armAdvertiseObj);
    } else {
      pwm_arm(&obj->armAdvertiseObj);
    }
  }
}

// Model step function for TID0
void RRTV3_PX4_OA_step0(void)          // Sample time: [0.02s, 0.0s]
{
  int8_T n;
  boolean_T b_varargout_1;
  boolean_T exitg1;

  {                                    // Sample time: [0.02s, 0.0s]
    rate_monotonic_scheduler();
  }

  // MATLABSystem: '<S85>/SourceBlock'
  b_varargout_1 = uORB_read_step(RRTV3_PX4_OA_DW.obj_go.orbMetadataObj,
    &RRTV3_PX4_OA_DW.obj_go.eventStructObj, &RRTV3_PX4_OA_B.r1, false, 1.0);

  // Outputs for Enabled SubSystem: '<S85>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S88>/Enable'

  // Start for MATLABSystem: '<S85>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S88>/In1'
    RRTV3_PX4_OA_B.In1_f = RRTV3_PX4_OA_B.r1;
  }

  // End of Outputs for SubSystem: '<S85>/Enabled Subsystem'

  // DataTypeConversion: '<S79>/Cast To Double'
  for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 18; RRTV3_PX4_OA_B.i++) {
    RRTV3_PX4_OA_B.CastToDouble[RRTV3_PX4_OA_B.i] =
      RRTV3_PX4_OA_B.In1_f.channels[RRTV3_PX4_OA_B.i];
  }

  // End of DataTypeConversion: '<S79>/Cast To Double'

  // Signum: '<S79>/Sign' incorporates:
  //   Signum: '<S79>/Sign1'

  b_varargout_1 = rtIsNaN(RRTV3_PX4_OA_B.CastToDouble[9]);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.LatRad = (rtNaN);
  } else if (RRTV3_PX4_OA_B.CastToDouble[9] < 0.0) {
    RRTV3_PX4_OA_B.LatRad = -1.0;
  } else {
    RRTV3_PX4_OA_B.LatRad = (RRTV3_PX4_OA_B.CastToDouble[9] > 0.0);
  }

  // Product: '<S79>/Divide' incorporates:
  //   Signum: '<S79>/Sign'

  RRTV3_PX4_OA_B.Arm = RRTV3_PX4_OA_B.LatRad * RRTV3_PX4_OA_B.CastToDouble[9] /
    RRTV3_PX4_OA_B.CastToDouble[9];

  // Signum: '<S79>/Sign1'
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.LatRad = (rtNaN);
  } else if (RRTV3_PX4_OA_B.CastToDouble[9] < 0.0) {
    RRTV3_PX4_OA_B.LatRad = -1.0;
  } else {
    RRTV3_PX4_OA_B.LatRad = (RRTV3_PX4_OA_B.CastToDouble[9] > 0.0);
  }

  // Product: '<S79>/Divide1' incorporates:
  //   Signum: '<S79>/Sign1'

  RRTV3_PX4_OA_B.Kill = RRTV3_PX4_OA_B.LatRad * RRTV3_PX4_OA_B.CastToDouble[9] /
    RRTV3_PX4_OA_B.CastToDouble[9];

  // Signum: '<S79>/Sign2'
  if (rtIsNaN(RRTV3_PX4_OA_B.CastToDouble[5])) {
    RRTV3_PX4_OA_B.ControlLevel = (rtNaN);
  } else if (RRTV3_PX4_OA_B.CastToDouble[5] < 0.0) {
    RRTV3_PX4_OA_B.ControlLevel = -1.0;
  } else {
    RRTV3_PX4_OA_B.ControlLevel = (RRTV3_PX4_OA_B.CastToDouble[5] > 0.0);
  }

  // End of Signum: '<S79>/Sign2'

  // MATLAB Function: '<S4>/Control Level Determination'
  RRTV3_PX4_OA_B.Control_Level = 1;
  RRTV3_PX4_OA_B.Arm_i = 0;
  RRTV3_PX4_OA_B.Kill_p = 1;
  if (RRTV3_PX4_OA_B.Arm == -1.0) {
    RRTV3_PX4_OA_B.Arm_i = 1;
  }

  if (RRTV3_PX4_OA_B.Arm == 1.0) {
    RRTV3_PX4_OA_B.Arm_i = 0;
  }

  if (RRTV3_PX4_OA_B.Kill == -1.0) {
    RRTV3_PX4_OA_B.Kill_p = 0;
  }

  if (RRTV3_PX4_OA_B.Kill == 1.0) {
    RRTV3_PX4_OA_B.Kill_p = 1;
  }

  if (RRTV3_PX4_OA_B.ControlLevel == 1.0) {
    RRTV3_PX4_OA_B.Control_Level = 2;
  }

  if (RRTV3_PX4_OA_B.ControlLevel == 0.0) {
    RRTV3_PX4_OA_B.Control_Level = 3;
  }

  if (RRTV3_PX4_OA_B.ControlLevel == -1.0) {
    RRTV3_PX4_OA_B.Control_Level = 4;
  }

  // Signum: '<S79>/Sign3'
  if (rtIsNaN(RRTV3_PX4_OA_B.CastToDouble[6])) {
    RRTV3_PX4_OA_B.LatRad = (rtNaN);
  } else if (RRTV3_PX4_OA_B.CastToDouble[6] < 0.0) {
    RRTV3_PX4_OA_B.LatRad = -1.0;
  } else {
    RRTV3_PX4_OA_B.LatRad = (RRTV3_PX4_OA_B.CastToDouble[6] > 0.0);
  }

  // MATLAB Function: '<S4>/Control Level Determination' incorporates:
  //   Product: '<S79>/Divide3'
  //   Signum: '<S79>/Sign3'

  if (RRTV3_PX4_OA_B.LatRad * RRTV3_PX4_OA_B.CastToDouble[6] /
      RRTV3_PX4_OA_B.CastToDouble[6] == 1.0) {
    RRTV3_PX4_OA_B.Control_Level = 1;
  }

  // MATLABSystem: '<S84>/SourceBlock'
  b_varargout_1 = uORB_read_step(RRTV3_PX4_OA_DW.obj_am.orbMetadataObj,
    &RRTV3_PX4_OA_DW.obj_am.eventStructObj, &RRTV3_PX4_OA_B.r4, false, 1.0);

  // Outputs for Enabled SubSystem: '<S84>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S87>/Enable'

  // Start for MATLABSystem: '<S84>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S87>/In1'
    RRTV3_PX4_OA_B.In1_o = RRTV3_PX4_OA_B.r4;
  }

  // End of Outputs for SubSystem: '<S84>/Enabled Subsystem'

  // Gain: '<S79>/Gain6' incorporates:
  //   DataTypeConversion: '<S79>/Data Type Conversion1'

  RRTV3_PX4_OA_B.ControlLevel = RRTV3_PX4_OA_P.Gain6_Gain * static_cast<real_T>
    (RRTV3_PX4_OA_B.In1_o.manual_control_signal_lost);

  // Gain: '<S79>/Gain17'
  RRTV3_PX4_OA_B.PilotSource = RRTV3_PX4_OA_P.Gain17_Gain *
    RRTV3_PX4_OA_B.CastToDouble[8];

  // MATLABSystem: '<S121>/SourceBlock'
  b_varargout_1 = uORB_read_step(RRTV3_PX4_OA_DW.obj_omq.orbMetadataObj,
    &RRTV3_PX4_OA_DW.obj_omq.eventStructObj, &RRTV3_PX4_OA_B.r2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S121>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S122>/Enable'

  // Start for MATLABSystem: '<S121>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S122>/In1'
    RRTV3_PX4_OA_B.In1_d = RRTV3_PX4_OA_B.r2;
  }

  // End of Outputs for SubSystem: '<S121>/Enabled Subsystem'

  // MATLABSystem: '<S110>/SourceBlock'
  b_varargout_1 = uORB_read_step(RRTV3_PX4_OA_DW.obj_mcu.orbMetadataObj,
    &RRTV3_PX4_OA_DW.obj_mcu.eventStructObj, &RRTV3_PX4_OA_B.r, false, 1.0);

  // Outputs for Enabled SubSystem: '<S110>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S128>/Enable'

  // Start for MATLABSystem: '<S110>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S128>/In1'
    RRTV3_PX4_OA_B.In1 = RRTV3_PX4_OA_B.r;
  }

  // End of Outputs for SubSystem: '<S110>/Enabled Subsystem'

  // MATLABSystem: '<S53>/Max Phi Cmd6'
  if (RRTV3_PX4_OA_DW.obj_gm.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd6_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_gm.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd6_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_gm.MW_PARAMHANDLE, MW_INT32,
    &RRTV3_PX4_OA_B.ParamStep_m0);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_m0 = 0;
  }

  // Gain: '<S116>/Minimum sampling to time constant ratio'
  RRTV3_PX4_OA_B.Arm = RRTV3_PX4_OA_P.FilteredDerivative2_minRatio *
    RRTV3_PX4_OA_B.Probe[0];

  // MinMax: '<S116>/MinMax' incorporates:
  //   Constant: '<S116>/Time constant'

  if ((!(RRTV3_PX4_OA_B.Arm >= RRTV3_PX4_OA_P.FilteredDerivative2_T)) &&
      (!rtIsNaN(RRTV3_PX4_OA_P.FilteredDerivative2_T))) {
    RRTV3_PX4_OA_B.Arm = RRTV3_PX4_OA_P.FilteredDerivative2_T;
  }

  // End of MinMax: '<S116>/MinMax'

  // DiscreteIntegrator: '<S120>/Integrator' incorporates:
  //   Constant: '<S102>/Constant'
  //   DataTypeConversion: '<S96>/Data Type Conversion8'

  if (RRTV3_PX4_OA_DW.Integrator_IC_LOADING != 0) {
    RRTV3_PX4_OA_DW.Integrator_DSTATE = RRTV3_PX4_OA_B.In1.z;
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE > RRTV3_PX4_OA_P.Integrator_UpperSat_j)
    {
      RRTV3_PX4_OA_DW.Integrator_DSTATE = RRTV3_PX4_OA_P.Integrator_UpperSat_j;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE <
               RRTV3_PX4_OA_P.Integrator_LowerSat_n) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE = RRTV3_PX4_OA_P.Integrator_LowerSat_n;
    }
  }

  if ((RRTV3_PX4_OA_P.Constant_Value_b3 != 0.0) ||
      (RRTV3_PX4_OA_DW.Integrator_PrevResetState != 0)) {
    RRTV3_PX4_OA_DW.Integrator_DSTATE = RRTV3_PX4_OA_B.In1.z;
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE > RRTV3_PX4_OA_P.Integrator_UpperSat_j)
    {
      RRTV3_PX4_OA_DW.Integrator_DSTATE = RRTV3_PX4_OA_P.Integrator_UpperSat_j;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE <
               RRTV3_PX4_OA_P.Integrator_LowerSat_n) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE = RRTV3_PX4_OA_P.Integrator_LowerSat_n;
    }
  }

  // End of DiscreteIntegrator: '<S120>/Integrator'

  // Saturate: '<S120>/Saturation'
  if (RRTV3_PX4_OA_DW.Integrator_DSTATE > RRTV3_PX4_OA_P.Saturation_UpperSat_h)
  {
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_UpperSat_h;
  } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE <
             RRTV3_PX4_OA_P.Saturation_LowerSat_mt) {
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_LowerSat_mt;
  } else {
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_DW.Integrator_DSTATE;
  }

  // Product: '<S102>/1//T' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion8'
  //   Fcn: '<S116>/Avoid Divide by Zero'
  //   Saturate: '<S120>/Saturation'
  //   Sum: '<S102>/Sum1'

  RRTV3_PX4_OA_B.Arm = 1.0 / (static_cast<real_T>(RRTV3_PX4_OA_B.Arm == 0.0) *
    2.2204460492503131e-16 + RRTV3_PX4_OA_B.Arm) * (RRTV3_PX4_OA_B.In1.z -
    RRTV3_PX4_OA_B.LatRad);

  // Sum: '<S99>/Sum' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion1'
  //   Gain: '<S99>/Gain'
  //   Sum: '<S99>/Diff'
  //   UnitDelay: '<S99>/UD'
  //
  //  Block description for '<S99>/Sum':
  //
  //   Add in CPU
  //
  //  Block description for '<S99>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S99>/UD':
  //
  //   Store in Global RAM

  RRTV3_PX4_OA_DW.UD_DSTATE = (RRTV3_PX4_OA_DW.UD_DSTATE - RRTV3_PX4_OA_B.In1.vz)
    * RRTV3_PX4_OA_P.u01s1001s2_PoleZ + RRTV3_PX4_OA_B.In1.vz;

  // MultiPortSwitch: '<S96>/Multiport Switch1' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion1'
  //   MATLABSystem: '<S53>/Max Phi Cmd6'
  //   UnitDelay: '<S99>/UD'
  //  *
  //  Block description for '<S99>/UD':
  //
  //   Store in Global RAM

  switch (RRTV3_PX4_OA_B.ParamStep_m0) {
   case 0:
    RRTV3_PX4_OA_B.VD = RRTV3_PX4_OA_B.In1.vz;
    break;

   case 1:
    // Gain: '<S102>/Gain'
    RRTV3_PX4_OA_B.VD = RRTV3_PX4_OA_P.FilteredDerivative2_K *
      RRTV3_PX4_OA_B.Arm;

    // Saturate: '<S102>/[A,B]'
    if (RRTV3_PX4_OA_B.VD > RRTV3_PX4_OA_P.FilteredDerivative2_B) {
      RRTV3_PX4_OA_B.VD = RRTV3_PX4_OA_P.FilteredDerivative2_B;
    } else if (RRTV3_PX4_OA_B.VD < RRTV3_PX4_OA_P.FilteredDerivative2_A) {
      RRTV3_PX4_OA_B.VD = RRTV3_PX4_OA_P.FilteredDerivative2_A;
    }

    // End of Saturate: '<S102>/[A,B]'
    break;

   default:
    RRTV3_PX4_OA_B.VD = RRTV3_PX4_OA_DW.UD_DSTATE;
    break;
  }

  // End of MultiPortSwitch: '<S96>/Multiport Switch1'

  // MATLABSystem: '<S106>/SourceBlock'
  b_varargout_1 = uORB_read_step(RRTV3_PX4_OA_DW.obj_es.orbMetadataObj,
    &RRTV3_PX4_OA_DW.obj_es.eventStructObj, &RRTV3_PX4_OA_B.r7, false, 1.0);

  // Outputs for Enabled SubSystem: '<S106>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S124>/Enable'

  // Start for MATLABSystem: '<S106>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S124>/In1'
    RRTV3_PX4_OA_B.In1_n = RRTV3_PX4_OA_B.r7;
  }

  // End of Outputs for SubSystem: '<S106>/Enabled Subsystem'

  // MATLABSystem: '<S107>/SourceBlock'
  b_varargout_1 = uORB_read_step(RRTV3_PX4_OA_DW.obj_oe.orbMetadataObj,
    &RRTV3_PX4_OA_DW.obj_oe.eventStructObj, &RRTV3_PX4_OA_B.r6, false, 1.0);

  // Outputs for Enabled SubSystem: '<S107>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S125>/Enable'

  // Start for MATLABSystem: '<S107>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S125>/In1'
    RRTV3_PX4_OA_B.In1_h = RRTV3_PX4_OA_B.r6;
  }

  // End of Outputs for SubSystem: '<S107>/Enabled Subsystem'

  // MATLABSystem: '<S108>/SourceBlock'
  b_varargout_1 = uORB_read_step(RRTV3_PX4_OA_DW.obj_jx.orbMetadataObj,
    &RRTV3_PX4_OA_DW.obj_jx.eventStructObj, &RRTV3_PX4_OA_B.r8, false, 1.0);

  // Outputs for Enabled SubSystem: '<S108>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S126>/Enable'

  // Start for MATLABSystem: '<S108>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S126>/In1'
    RRTV3_PX4_OA_B.In1_g = RRTV3_PX4_OA_B.r8;
  }

  // End of Outputs for SubSystem: '<S108>/Enabled Subsystem'

  // MATLABSystem: '<S105>/SourceBlock'
  b_varargout_1 = uORB_read_step(RRTV3_PX4_OA_DW.obj_pd.orbMetadataObj,
    &RRTV3_PX4_OA_DW.obj_pd.eventStructObj, &RRTV3_PX4_OA_B.r5, false, 1.0);

  // Outputs for Enabled SubSystem: '<S105>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S123>/Enable'

  // Start for MATLABSystem: '<S105>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S123>/In1'
    RRTV3_PX4_OA_B.In1_a4 = RRTV3_PX4_OA_B.r5;
  }

  // End of Outputs for SubSystem: '<S105>/Enabled Subsystem'

  // MATLABSystem: '<S96>/Read Parameter1'
  if (RRTV3_PX4_OA_DW.obj.SampleTime !=
      RRTV3_PX4_OA_P.ReadParameter1_SampleTime_i) {
    RRTV3_PX4_OA_DW.obj.SampleTime = RRTV3_PX4_OA_P.ReadParameter1_SampleTime_i;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S109>/SourceBlock'
  b_varargout_1 = uORB_read_step(RRTV3_PX4_OA_DW.obj_jz.orbMetadataObj,
    &RRTV3_PX4_OA_DW.obj_jz.eventStructObj, &RRTV3_PX4_OA_B.r9, false, 1.0);

  // Outputs for Enabled SubSystem: '<S109>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S127>/Enable'

  // Start for MATLABSystem: '<S109>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S127>/In1'
    RRTV3_PX4_OA_B.In1_o2 = RRTV3_PX4_OA_B.r9;
  }

  // End of Outputs for SubSystem: '<S109>/Enabled Subsystem'

  // Sum: '<S100>/Diff' incorporates:
  //   UnitDelay: '<S100>/UD'
  //
  //  Block description for '<S100>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S100>/UD':
  //
  //   Store in Global RAM

  RRTV3_PX4_OA_DW.UD_DSTATE_p -= RRTV3_PX4_OA_B.In1_o2.true_airspeed_m_s;

  // Gain: '<S100>/Gain' incorporates:
  //   UnitDelay: '<S100>/UD'
  //
  //  Block description for '<S100>/UD':
  //
  //   Store in Global RAM

  RRTV3_PX4_OA_DW.UD_DSTATE_p *= RRTV3_PX4_OA_P.u025s1001s1_PoleZ;

  // Sum: '<S100>/Sum' incorporates:
  //   UnitDelay: '<S100>/UD'
  //
  //  Block description for '<S100>/Sum':
  //
  //   Add in CPU
  //
  //  Block description for '<S100>/UD':
  //
  //   Store in Global RAM

  RRTV3_PX4_OA_DW.UD_DSTATE_p += RRTV3_PX4_OA_B.In1_o2.true_airspeed_m_s;

  // Sum: '<S98>/Sum' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion13'
  //   Gain: '<S98>/Gain'
  //   Sum: '<S98>/Diff'
  //   UnitDelay: '<S98>/UD'
  //
  //  Block description for '<S98>/Sum':
  //
  //   Add in CPU
  //
  //  Block description for '<S98>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S98>/UD':
  //
  //   Store in Global RAM

  RRTV3_PX4_OA_DW.UD_DSTATE_m = (RRTV3_PX4_OA_DW.UD_DSTATE_m -
    RRTV3_PX4_OA_B.In1_a4.current_distance) * RRTV3_PX4_OA_P.u01s1001s_PoleZ +
    RRTV3_PX4_OA_B.In1_a4.current_distance;

  // Gain: '<S111>/Minimum sampling to time constant ratio'
  RRTV3_PX4_OA_B.Kill = RRTV3_PX4_OA_P.FilteredDerivative1_minRatio *
    RRTV3_PX4_OA_B.Probe_g[0];

  // MinMax: '<S111>/MinMax' incorporates:
  //   Constant: '<S111>/Time constant'

  if ((!(RRTV3_PX4_OA_B.Kill >= RRTV3_PX4_OA_P.FilteredDerivative1_T)) &&
      (!rtIsNaN(RRTV3_PX4_OA_P.FilteredDerivative1_T))) {
    RRTV3_PX4_OA_B.Kill = RRTV3_PX4_OA_P.FilteredDerivative1_T;
  }

  // End of MinMax: '<S111>/MinMax'

  // DiscreteIntegrator: '<S115>/Integrator' incorporates:
  //   Constant: '<S101>/Constant'
  //   DataTypeConversion: '<S96>/Data Type Conversion13'

  if (RRTV3_PX4_OA_DW.Integrator_IC_LOADING_p != 0) {
    RRTV3_PX4_OA_DW.Integrator_DSTATE_c = RRTV3_PX4_OA_B.In1_a4.current_distance;
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_c >
        RRTV3_PX4_OA_P.Integrator_UpperSat_gg) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_c =
        RRTV3_PX4_OA_P.Integrator_UpperSat_gg;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_c <
               RRTV3_PX4_OA_P.Integrator_LowerSat_ln) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_c =
        RRTV3_PX4_OA_P.Integrator_LowerSat_ln;
    }
  }

  if ((RRTV3_PX4_OA_P.Constant_Value_in != 0.0) ||
      (RRTV3_PX4_OA_DW.Integrator_PrevResetState_b != 0)) {
    RRTV3_PX4_OA_DW.Integrator_DSTATE_c = RRTV3_PX4_OA_B.In1_a4.current_distance;
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_c >
        RRTV3_PX4_OA_P.Integrator_UpperSat_gg) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_c =
        RRTV3_PX4_OA_P.Integrator_UpperSat_gg;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_c <
               RRTV3_PX4_OA_P.Integrator_LowerSat_ln) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_c =
        RRTV3_PX4_OA_P.Integrator_LowerSat_ln;
    }
  }

  // End of DiscreteIntegrator: '<S115>/Integrator'

  // Saturate: '<S115>/Saturation'
  if (RRTV3_PX4_OA_DW.Integrator_DSTATE_c > RRTV3_PX4_OA_P.Saturation_UpperSat_k)
  {
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_UpperSat_k;
  } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_c <
             RRTV3_PX4_OA_P.Saturation_LowerSat_d) {
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_LowerSat_d;
  } else {
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_DW.Integrator_DSTATE_c;
  }

  // Product: '<S101>/1//T' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion13'
  //   Fcn: '<S111>/Avoid Divide by Zero'
  //   Saturate: '<S115>/Saturation'
  //   Sum: '<S101>/Sum1'

  RRTV3_PX4_OA_B.Kill = 1.0 / (static_cast<real_T>(RRTV3_PX4_OA_B.Kill == 0.0) *
    2.2204460492503131e-16 + RRTV3_PX4_OA_B.Kill) *
    (RRTV3_PX4_OA_B.In1_a4.current_distance - RRTV3_PX4_OA_B.LatRad);

  // MATLABSystem: '<S53>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_nu.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_jy) {
    RRTV3_PX4_OA_DW.obj_nu.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_jy;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_nu.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_p);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_p = 0.0F;
  }

  // MATLABSystem: '<S53>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_p2.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_l) {
    RRTV3_PX4_OA_DW.obj_p2.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_l;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_p2.MW_PARAMHANDLE, MW_INT32,
    &RRTV3_PX4_OA_B.ParamStep_m0);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_m0 = 0;
  }

  // MATLABSystem: '<S53>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_bd.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_bd.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_bd.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_l);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S53>/Max Phi Cmd4'
  if (RRTV3_PX4_OA_DW.obj_ha.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_ha.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ha.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_j);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_j = 0.0F;
  }

  // MATLABSystem: '<S53>/Max Phi Cmd12'
  if (RRTV3_PX4_OA_DW.obj_m3.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime_dm) {
    RRTV3_PX4_OA_DW.obj_m3.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime_dm;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_m3.MW_PARAMHANDLE, MW_INT32,
    &RRTV3_PX4_OA_B.ParamStep_jgs);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_jgs = 0;
  }

  // MATLABSystem: '<S53>/Max Phi Cmd5'
  if (RRTV3_PX4_OA_DW.obj_d5s.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_n) {
    RRTV3_PX4_OA_DW.obj_d5s.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_n;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_d5s.MW_PARAMHANDLE, MW_INT32,
    &RRTV3_PX4_OA_B.ParamStep_fo);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_fo = 0;
  }

  // MATLABSystem: '<S53>/Max Phi Cmd8'
  if (RRTV3_PX4_OA_DW.obj_bv.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_j) {
    RRTV3_PX4_OA_DW.obj_bv.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_j;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_bv.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_d);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_d = 0.0F;
  }

  // MATLABSystem: '<S53>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_oa.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_l) {
    RRTV3_PX4_OA_DW.obj_oa.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_l;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_oa.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_g);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_g = 0.0F;
  }

  // MATLABSystem: '<S53>/Max Phi Cmd7'
  if (RRTV3_PX4_OA_DW.obj_d3.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_d3.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_d3.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ld);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ld = 0.0F;
  }

  // DiscreteIntegrator: '<S97>/Integrator' incorporates:
  //   Constant: '<S6>/Constant'
  //   Constant: '<S6>/Constant2'

  if (((RRTV3_PX4_OA_P.Constant_Value_it > 0.0) &&
       (RRTV3_PX4_OA_DW.Integrator_PrevResetState_n <= 0)) ||
      ((RRTV3_PX4_OA_P.Constant_Value_it <= 0.0) &&
       (RRTV3_PX4_OA_DW.Integrator_PrevResetState_n == 1))) {
    RRTV3_PX4_OA_DW.Integrator_DSTATE_e = RRTV3_PX4_OA_P.Constant2_Value_j;
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_e >
        RRTV3_PX4_OA_P.Integrator_UpperSat_e) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_e = RRTV3_PX4_OA_P.Integrator_UpperSat_e;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_e <
               RRTV3_PX4_OA_P.Integrator_LowerSat_m5) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_e =
        RRTV3_PX4_OA_P.Integrator_LowerSat_m5;
    }
  }

  // End of DiscreteIntegrator: '<S97>/Integrator'

  // Gain: '<S101>/Gain'
  RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.FilteredDerivative1_K *
    RRTV3_PX4_OA_B.Kill;

  // Saturate: '<S101>/[A,B]'
  if (RRTV3_PX4_OA_B.z_HDG > RRTV3_PX4_OA_P.FilteredDerivative1_B) {
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.FilteredDerivative1_B;
  } else if (RRTV3_PX4_OA_B.z_HDG < RRTV3_PX4_OA_P.FilteredDerivative1_A) {
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.FilteredDerivative1_A;
  }

  // End of Saturate: '<S101>/[A,B]'

  // Saturate: '<S96>/Saturation2'
  if (RRTV3_PX4_OA_B.z_HDG > RRTV3_PX4_OA_P.Saturation2_UpperSat) {
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.Saturation2_UpperSat;
  } else if (RRTV3_PX4_OA_B.z_HDG < RRTV3_PX4_OA_P.Saturation2_LowerSat) {
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.Saturation2_LowerSat;
  }

  // End of Saturate: '<S96>/Saturation2'

  // MATLAB Function: '<S6>/LinVel Bus + INS' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion'
  //   SignalConversion generated from: '<S95>/ SFunction '
  //   UnitDelay: '<S98>/UD'
  //
  //  Block description for '<S98>/UD':
  //
  //   Store in Global RAM

  RRTV3_PX4_OA_B.TBI = static_cast<real_T>(RRTV3_PX4_OA_B.In1_h.q[0]) *
    RRTV3_PX4_OA_B.In1_h.q[2] - static_cast<real_T>(RRTV3_PX4_OA_B.In1_h.q[1]) *
    RRTV3_PX4_OA_B.In1_h.q[3];
  RRTV3_PX4_OA_B.phi = 0.0;
  RRTV3_PX4_OA_B.theta = 0.0;
  RRTV3_PX4_OA_B.psi = 0.0;
  RRTV3_PX4_OA_B.gimballock = 0;
  if (RRTV3_PX4_OA_B.TBI == 0.5) {
    RRTV3_PX4_OA_B.psi = 1.5707963267948966;
    RRTV3_PX4_OA_B.theta = 1.5707963267948966;
    RRTV3_PX4_OA_B.phi = asin(RRTV3_PX4_OA_B.In1_h.q[1] / 0.70710678118654757) *
      2.0 + 1.5707963267948966;
    RRTV3_PX4_OA_B.gimballock = 1;
  }

  if (RRTV3_PX4_OA_B.TBI == -0.5) {
    RRTV3_PX4_OA_B.psi = 1.5707963267948966;
    RRTV3_PX4_OA_B.theta = -1.5707963267948966;
    RRTV3_PX4_OA_B.phi = asin(RRTV3_PX4_OA_B.In1_h.q[1] / 0.70710678118654757) *
      2.0 - 1.5707963267948966;
    RRTV3_PX4_OA_B.gimballock = 1;
  }

  if (RRTV3_PX4_OA_B.gimballock == 0) {
    RRTV3_PX4_OA_B.m = static_cast<real_T>(RRTV3_PX4_OA_B.In1_h.q[0]) *
      RRTV3_PX4_OA_B.In1_h.q[0];
    RRTV3_PX4_OA_B.psi = static_cast<real_T>(RRTV3_PX4_OA_B.In1_h.q[1]) *
      RRTV3_PX4_OA_B.In1_h.q[1];
    RRTV3_PX4_OA_B.h_LiDAR = static_cast<real_T>(RRTV3_PX4_OA_B.In1_h.q[2]) *
      RRTV3_PX4_OA_B.In1_h.q[2];
    RRTV3_PX4_OA_B.h_Pix = static_cast<real_T>(RRTV3_PX4_OA_B.In1_h.q[3]) *
      RRTV3_PX4_OA_B.In1_h.q[3];
    RRTV3_PX4_OA_B.phi = rt_atan2d_snf((static_cast<real_T>
      (RRTV3_PX4_OA_B.In1_h.q[2]) * RRTV3_PX4_OA_B.In1_h.q[3] + static_cast<
      real_T>(RRTV3_PX4_OA_B.In1_h.q[0]) * RRTV3_PX4_OA_B.In1_h.q[1]) * 2.0,
      ((RRTV3_PX4_OA_B.m - RRTV3_PX4_OA_B.psi) - RRTV3_PX4_OA_B.h_LiDAR) +
      RRTV3_PX4_OA_B.h_Pix);
    RRTV3_PX4_OA_B.theta = asin(RRTV3_PX4_OA_B.TBI * 2.0);
    RRTV3_PX4_OA_B.psi = rt_atan2d_snf((static_cast<real_T>
      (RRTV3_PX4_OA_B.In1_h.q[1]) * RRTV3_PX4_OA_B.In1_h.q[2] +
      static_cast<real_T>(RRTV3_PX4_OA_B.In1_h.q[0]) * RRTV3_PX4_OA_B.In1_h.q[3])
      * 2.0, ((RRTV3_PX4_OA_B.m + RRTV3_PX4_OA_B.psi) - RRTV3_PX4_OA_B.h_LiDAR)
      - RRTV3_PX4_OA_B.h_Pix);
  }

  RRTV3_PX4_OA_B.TBI = 0.0;
  RRTV3_PX4_OA_B.WPINDEX = cos(RRTV3_PX4_OA_B.theta);
  RRTV3_PX4_OA_B.h_LiDAR = cos(RRTV3_PX4_OA_B.phi) * RRTV3_PX4_OA_B.WPINDEX *
    RRTV3_PX4_OA_DW.UD_DSTATE_m;
  if (!(RRTV3_PX4_OA_B.h_LiDAR <= 15.0)) {
    RRTV3_PX4_OA_B.h_LiDAR = 15.0;
  }

  if (RRTV3_PX4_OA_B.h_LiDAR <= 0.0) {
    RRTV3_PX4_OA_B.h_LiDAR = 0.0;
  }

  // Saturate: '<S97>/Saturation'
  if (RRTV3_PX4_OA_DW.Integrator_DSTATE_e > RRTV3_PX4_OA_P.Saturation_UpperSat_a)
  {
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_UpperSat_a;
  } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_e <
             RRTV3_PX4_OA_P.Saturation_LowerSat_o) {
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_LowerSat_o;
  } else {
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_DW.Integrator_DSTATE_e;
  }

  // MATLAB Function: '<S6>/LinVel Bus + INS' incorporates:
  //   DataTypeConversion: '<S53>/Data Type Conversion14'
  //   DataTypeConversion: '<S53>/Data Type Conversion16'
  //   DataTypeConversion: '<S53>/Data Type Conversion17'
  //   DataTypeConversion: '<S53>/Data Type Conversion19'
  //   DataTypeConversion: '<S53>/Data Type Conversion2'
  //   DataTypeConversion: '<S53>/Data Type Conversion20'
  //   DataTypeConversion: '<S96>/Data Type Conversion13'
  //   DataTypeConversion: '<S96>/Data Type Conversion15'
  //   DataTypeConversion: '<S96>/Data Type Conversion2'
  //   DataTypeConversion: '<S96>/Data Type Conversion3'
  //   DataTypeConversion: '<S96>/Data Type Conversion8'
  //   MATLABSystem: '<S53>/Max Phi Cmd1'
  //   MATLABSystem: '<S53>/Max Phi Cmd12'
  //   MATLABSystem: '<S53>/Max Phi Cmd2'
  //   MATLABSystem: '<S53>/Max Phi Cmd3'
  //   MATLABSystem: '<S53>/Max Phi Cmd4'
  //   MATLABSystem: '<S53>/Max Phi Cmd5'
  //   MATLABSystem: '<S53>/Max Phi Cmd7'
  //   MATLABSystem: '<S53>/Max Phi Cmd8'
  //   MATLABSystem: '<S53>/Max Phi Cmd9'
  //   MATLABSystem: '<S96>/Read Parameter1'
  //   RelationalOperator: '<S104>/LessThanOrEqual'
  //   Saturate: '<S97>/Saturation'
  //   SignalConversion generated from: '<S103>/Matrix Concatenate1'
  //   SignalConversion generated from: '<S95>/ SFunction '
  //   UnitDelay: '<S100>/UD'
  //  *
  //  Block description for '<S100>/UD':
  //
  //   Store in Global RAM

  RRTV3_PX4_OA_B.h_Pix = -static_cast<real_T>(RRTV3_PX4_OA_B.In1.z) +
    RRTV3_PX4_OA_B.LatRad;
  RRTV3_PX4_OA_B.h2 = RRTV3_PX4_OA_B.ParamStep_g / 3.28;
  RRTV3_PX4_OA_B.m = 1.0 / (RRTV3_PX4_OA_B.h2 - RRTV3_PX4_OA_B.ParamStep_d /
    3.28);
  RRTV3_PX4_OA_B.m = 1.0 - (RRTV3_PX4_OA_B.h_LiDAR - (RRTV3_PX4_OA_B.h2 - 1.0 /
    RRTV3_PX4_OA_B.m)) * RRTV3_PX4_OA_B.m;
  if (!(RRTV3_PX4_OA_B.m <= 1.0)) {
    RRTV3_PX4_OA_B.m = 1.0;
  }

  if (RRTV3_PX4_OA_B.m <= 0.0) {
    RRTV3_PX4_OA_B.m = 0.0;
  }

  RRTV3_PX4_OA_B.h2 = (1.0 - RRTV3_PX4_OA_B.m) * RRTV3_PX4_OA_B.h_Pix +
    RRTV3_PX4_OA_B.h_LiDAR * RRTV3_PX4_OA_B.m;
  if (RRTV3_PX4_OA_B.ParamStep_jgs == 0) {
    RRTV3_PX4_OA_B.h2 = RRTV3_PX4_OA_B.h_Pix;
  }

  if (RRTV3_PX4_OA_B.ParamStep_jgs == 1) {
    RRTV3_PX4_OA_B.h2 = RRTV3_PX4_OA_B.h_LiDAR;
  }

  if ((RRTV3_PX4_OA_B.m > 0.0) && (RRTV3_PX4_OA_B.ParamStep_jgs != 0)) {
    RRTV3_PX4_OA_B.TBI = 1.0 / RRTV3_PX4_OA_B.ParamStep_ld *
      (RRTV3_PX4_OA_B.h_LiDAR - RRTV3_PX4_OA_B.h_Pix);
  }

  RRTV3_PX4_OA_B.h_LiDAR = (1.0 - RRTV3_PX4_OA_B.m) * -RRTV3_PX4_OA_B.VD +
    RRTV3_PX4_OA_B.z_HDG * RRTV3_PX4_OA_B.m;
  if (RRTV3_PX4_OA_B.ParamStep_fo == 0) {
    RRTV3_PX4_OA_B.h_LiDAR = -RRTV3_PX4_OA_B.VD;
  }

  if (RRTV3_PX4_OA_B.ParamStep_fo == 1) {
    RRTV3_PX4_OA_B.h_LiDAR = RRTV3_PX4_OA_B.z_HDG;
  }

  RRTV3_PX4_OA_B.HDG = RRTV3_PX4_OA_mod(RRTV3_PX4_OA_B.psi * 180.0 /
    3.1415926535897931) + RRTV3_PX4_OA_B.ParamStep_p;
  RRTV3_PX4_OA_B.VD = RRTV3_PX4_OA_B.HDG;
  RRTV3_PX4_OA_sind(&RRTV3_PX4_OA_B.VD);
  RRTV3_PX4_OA_B.h_Pix = RRTV3_PX4_OA_B.HDG;
  RRTV3_PX4_OA_cosd(&RRTV3_PX4_OA_B.h_Pix);
  RRTV3_PX4_OA_B.psi = RRTV3_PX4_OA_B.In1_d.vel_n_m_s * RRTV3_PX4_OA_B.h_Pix +
    RRTV3_PX4_OA_B.In1_d.vel_e_m_s * RRTV3_PX4_OA_B.VD;
  RRTV3_PX4_OA_B.m = 1.0 / (static_cast<real_T>(RRTV3_PX4_OA_B.ParamStep_j) -
    RRTV3_PX4_OA_B.ParamStep_l);
  RRTV3_PX4_OA_B.KEAS = RRTV3_PX4_OA_DW.UD_DSTATE_p / 0.51444;
  RRTV3_PX4_OA_B.VFWD_kts = RRTV3_PX4_OA_B.psi / 0.51444;
  RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_B.VFWD_kts;
  if (RRTV3_PX4_OA_B.ParamStep_m0 == 1) {
    RRTV3_PX4_OA_B.zeta = 1.0 - (RRTV3_PX4_OA_B.VFWD_kts -
      (RRTV3_PX4_OA_B.ParamStep_j - 1.0 / RRTV3_PX4_OA_B.m)) * RRTV3_PX4_OA_B.m;
    if (!(RRTV3_PX4_OA_B.zeta <= 1.0)) {
      RRTV3_PX4_OA_B.zeta = 1.0;
    }

    if (RRTV3_PX4_OA_B.zeta <= 0.0) {
      RRTV3_PX4_OA_B.zeta = 0.0;
    }

    RRTV3_PX4_OA_B.LatRad = (1.0 - RRTV3_PX4_OA_B.zeta) * RRTV3_PX4_OA_B.KEAS +
      RRTV3_PX4_OA_B.zeta * RRTV3_PX4_OA_B.VFWD_kts;
  }

  if (RRTV3_PX4_OA_B.ParamStep_m0 == 2) {
    RRTV3_PX4_OA_B.zeta = 1.0 - (RRTV3_PX4_OA_B.KEAS -
      (RRTV3_PX4_OA_B.ParamStep_j - 1.0 / RRTV3_PX4_OA_B.m)) * RRTV3_PX4_OA_B.m;
    if (!(RRTV3_PX4_OA_B.zeta <= 1.0)) {
      RRTV3_PX4_OA_B.zeta = 1.0;
    }

    if (RRTV3_PX4_OA_B.zeta <= 0.0) {
      RRTV3_PX4_OA_B.zeta = 0.0;
    }

    RRTV3_PX4_OA_B.LatRad = (1.0 - RRTV3_PX4_OA_B.zeta) * RRTV3_PX4_OA_B.KEAS +
      RRTV3_PX4_OA_B.zeta * RRTV3_PX4_OA_B.VFWD_kts;
  }

  RRTV3_PX4_OA_B.z_HDG = -static_cast<real_T>(RRTV3_PX4_OA_B.In1_d.vel_n_m_s) *
    RRTV3_PX4_OA_B.VD + RRTV3_PX4_OA_B.In1_d.vel_e_m_s * RRTV3_PX4_OA_B.h_Pix;
  if (!(RRTV3_PX4_OA_B.z_HDG <= 3.0)) {
    RRTV3_PX4_OA_B.z_HDG = 3.0;
  }

  if (!(RRTV3_PX4_OA_B.h_LiDAR <= 2.5)) {
    RRTV3_PX4_OA_B.h_LiDAR = 2.5;
  }

  RRTV3_PX4_OA_B.ParamStep_fo = (RRTV3_PX4_OA_B.In1_a4.current_distance <=
    RRTV3_PX4_OA_B.ParamStep);

  // Gain: '<S93>/Gain7' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion15'
  //   UnitDelay: '<S100>/UD'
  //
  //  Block description for '<S100>/UD':
  //
  //   Store in Global RAM

  RRTV3_PX4_OA_B.VD = RRTV3_PX4_OA_P.Gain7_Gain * RRTV3_PX4_OA_DW.UD_DSTATE_p;

  // Gain: '<S93>/Gain9' incorporates:
  //   MATLAB Function: '<S6>/LinVel Bus + INS'

  RRTV3_PX4_OA_B.m = RRTV3_PX4_OA_P.Gain9_Gain * RRTV3_PX4_OA_B.psi;

  // MATLAB Function: '<S6>/LinVel Bus + INS'
  if (RRTV3_PX4_OA_B.z_HDG <= -3.0) {
    RRTV3_PX4_OA_B.z_HDG = -3.0;
  }

  // Gain: '<S93>/Gain8' incorporates:
  //   MATLAB Function: '<S6>/LinVel Bus + INS'

  RRTV3_PX4_OA_B.psi = RRTV3_PX4_OA_P.Gain8_Gain * RRTV3_PX4_OA_B.z_HDG;

  // MATLAB Function: '<S6>/LinVel Bus + INS'
  if (RRTV3_PX4_OA_B.h_LiDAR <= -2.5) {
    RRTV3_PX4_OA_B.h_LiDAR = -2.5;
  }

  // Gain: '<S93>/Gain13' incorporates:
  //   MATLAB Function: '<S6>/LinVel Bus + INS'

  RRTV3_PX4_OA_B.h_LiDAR *= RRTV3_PX4_OA_P.Gain13_Gain;

  // Gain: '<S93>/Gain10' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion18'
  //   MATLAB Function: '<S6>/LinVel Bus + INS'

  RRTV3_PX4_OA_B.h_Pix = (RRTV3_PX4_OA_B.In1_g.xyz[0] - 9.81 * sin
    (RRTV3_PX4_OA_B.theta)) * RRTV3_PX4_OA_P.Gain10_Gain;

  // Gain: '<S93>/Gain16' incorporates:
  //   MATLAB Function: '<S6>/LinVel Bus + INS'

  RRTV3_PX4_OA_B.h2 *= RRTV3_PX4_OA_P.Gain16_Gain;

  // Gain: '<S93>/Gain18' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion26'
  //   Gain: '<S96>/Gain1'

  RRTV3_PX4_OA_B.KEAS = RRTV3_PX4_OA_P.Gain1_Gain_j * static_cast<real_T>
    (RRTV3_PX4_OA_B.In1_d.lat) * RRTV3_PX4_OA_P.Gain18_Gain;

  // Gain: '<S93>/Gain19' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion25'
  //   Gain: '<S96>/1e-7'

  RRTV3_PX4_OA_B.VFWD_kts = RRTV3_PX4_OA_P.ue7_Gain * static_cast<real_T>
    (RRTV3_PX4_OA_B.In1_d.lon) * RRTV3_PX4_OA_P.Gain19_Gain;

  // Gain: '<S93>/Gain22' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion2'
  //   MATLAB Function: '<S6>/LinVel Bus + INS'
  //   SignalConversion generated from: '<S103>/Matrix Concatenate1'
  //
  RRTV3_PX4_OA_B.zeta = RRTV3_PX4_OA_mod(57.295779513082323 * rt_atan2d_snf(
    static_cast<real_T>(RRTV3_PX4_OA_B.In1_d.vel_e_m_s), static_cast<real_T>
    (RRTV3_PX4_OA_B.In1_d.vel_n_m_s))) * 0.017453292519943295 *
    RRTV3_PX4_OA_P.Gain22_Gain;

  // MATLAB Function: '<S6>/LinVel Bus + INS'
  if ((RRTV3_PX4_OA_B.LatRad <= -5.0) || rtIsNaN(RRTV3_PX4_OA_B.LatRad)) {
    RRTV3_PX4_OA_B.LatRad = -5.0;
  }

  // Gain: '<S93>/Gain15' incorporates:
  //   MATLAB Function: '<S6>/LinVel Bus + INS'

  RRTV3_PX4_OA_B.VCSkt = RRTV3_PX4_OA_P.Gain15_Gain * RRTV3_PX4_OA_B.LatRad;

  // MATLABSystem: '<S4>/Read Parameter6'
  if (RRTV3_PX4_OA_DW.obj_p.SampleTime !=
      RRTV3_PX4_OA_P.ReadParameter6_SampleTime) {
    RRTV3_PX4_OA_DW.obj_p.SampleTime = RRTV3_PX4_OA_P.ReadParameter6_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_p.MW_PARAMHANDLE, MW_INT32,
    &RRTV3_PX4_OA_B.ParamStep_m0);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_m0 = 0;
  }

  // MATLABSystem: '<S83>/Read Parameter7'
  if (RRTV3_PX4_OA_DW.obj_k.SampleTime !=
      RRTV3_PX4_OA_P.ReadParameter7_SampleTime) {
    RRTV3_PX4_OA_DW.obj_k.SampleTime = RRTV3_PX4_OA_P.ReadParameter7_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_k.MW_PARAMHANDLE, MW_INT32,
    &RRTV3_PX4_OA_B.ParamStep_jgs);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_jgs = 0;
  }

  // Saturate: '<S83>/Saturation'
  if (RRTV3_PX4_OA_B.CastToDouble[4] > RRTV3_PX4_OA_P.Saturation_UpperSat_c) {
    RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_P.Saturation_UpperSat_c;
  } else if (RRTV3_PX4_OA_B.CastToDouble[4] <
             RRTV3_PX4_OA_P.Saturation_LowerSat_nc) {
    RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_P.Saturation_LowerSat_nc;
  } else {
    RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_B.CastToDouble[4];
  }

  // End of Saturate: '<S83>/Saturation'

  // MATLAB Function: '<S83>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S83>/Read Parameter7'
  //
  RRTV3_PX4_OA_B.AP_TKO = 0.0;
  RRTV3_PX4_OA_B.AP_DXN = 0.0;
  RRTV3_PX4_OA_B.AP_AXN = 0.0;
  RRTV3_PX4_OA_B.AP_LND = 0.0;
  RRTV3_PX4_OA_B.AP_NAV = 0.0;
  RRTV3_PX4_OA_B.AP_M1 = 0.0;
  RRTV3_PX4_OA_B.AP_M2 = 0.0;
  RRTV3_PX4_OA_B.AP_M3 = 0.0;
  RRTV3_PX4_OA_B.AP_M4 = 0.0;
  RRTV3_PX4_OA_B.AP_M5 = 0.0;
  if (RRTV3_PX4_OA_B.ParamStep_jgs == 1) {
    RRTV3_PX4_OA_B.AP_TKO = RRTV3_PX4_OA_B.u1;
  }

  if (RRTV3_PX4_OA_B.ParamStep_jgs == 2) {
    RRTV3_PX4_OA_B.AP_DXN = RRTV3_PX4_OA_B.u1;
  }

  if (RRTV3_PX4_OA_B.ParamStep_jgs == 3) {
    RRTV3_PX4_OA_B.AP_AXN = RRTV3_PX4_OA_B.u1;
  }

  if (RRTV3_PX4_OA_B.ParamStep_jgs == 4) {
    RRTV3_PX4_OA_B.AP_LND = RRTV3_PX4_OA_B.u1;
  }

  if (RRTV3_PX4_OA_B.ParamStep_jgs == 5) {
    RRTV3_PX4_OA_B.AP_NAV = RRTV3_PX4_OA_B.u1;
  }

  if (RRTV3_PX4_OA_B.ParamStep_jgs == 6) {
    RRTV3_PX4_OA_B.AP_M1 = RRTV3_PX4_OA_B.u1;
  }

  if (RRTV3_PX4_OA_B.ParamStep_jgs == 7) {
    RRTV3_PX4_OA_B.AP_M2 = RRTV3_PX4_OA_B.u1;
  }

  if (RRTV3_PX4_OA_B.ParamStep_jgs == 8) {
    RRTV3_PX4_OA_B.AP_M3 = RRTV3_PX4_OA_B.u1;
  }

  if (RRTV3_PX4_OA_B.ParamStep_jgs == 9) {
    RRTV3_PX4_OA_B.AP_M4 = RRTV3_PX4_OA_B.u1;
  }

  if (RRTV3_PX4_OA_B.ParamStep_jgs == 10) {
    RRTV3_PX4_OA_B.AP_M5 = RRTV3_PX4_OA_B.u1;
  }

  // End of MATLAB Function: '<S83>/MATLAB Function'

  // MATLABSystem: '<S83>/Read Parameter5'
  if (RRTV3_PX4_OA_DW.obj_a.SampleTime !=
      RRTV3_PX4_OA_P.ReadParameter5_SampleTime) {
    RRTV3_PX4_OA_DW.obj_a.SampleTime = RRTV3_PX4_OA_P.ReadParameter5_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_a.MW_PARAMHANDLE, MW_INT32,
    &RRTV3_PX4_OA_B.ParamStep_jgs);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_jgs = 0;
  }

  // Gain: '<S79>/Gain' incorporates:
  //   DataTypeConversion: '<S83>/Cast To Double5'
  //   MATLABSystem: '<S83>/Read Parameter5'
  //
  RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_P.Gain_Gain_b * static_cast<real_T>
    (RRTV3_PX4_OA_B.ParamStep_jgs);

  // MATLABSystem: '<S83>/Read Parameter6'
  if (RRTV3_PX4_OA_DW.obj_e.SampleTime !=
      RRTV3_PX4_OA_P.ReadParameter6_SampleTime_j) {
    RRTV3_PX4_OA_DW.obj_e.SampleTime =
      RRTV3_PX4_OA_P.ReadParameter6_SampleTime_j;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_e.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep = 0.0F;
  }

  // Gain: '<S79>/Gain1' incorporates:
  //   DataTypeConversion: '<S83>/Cast To Double6'
  //   MATLABSystem: '<S83>/Read Parameter6'
  //
  RRTV3_PX4_OA_B.NacelleManualCmd = RRTV3_PX4_OA_P.Gain1_Gain_l *
    RRTV3_PX4_OA_B.ParamStep;

  // MATLABSystem: '<S81>/SourceBlock'
  b_varargout_1 = uORB_read_step(RRTV3_PX4_OA_DW.obj_eq.orbMetadataObj,
    &RRTV3_PX4_OA_DW.obj_eq.eventStructObj, &RRTV3_PX4_OA_B.r3, false, 1.0);

  // Outputs for Enabled SubSystem: '<S81>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S82>/Enable'

  // Start for MATLABSystem: '<S81>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S82>/In1'
    RRTV3_PX4_OA_B.In1_a = RRTV3_PX4_OA_B.r3;
  }

  // End of Outputs for SubSystem: '<S81>/Enabled Subsystem'

  // DataTypeConversion: '<S78>/Cast To Double'
  for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 20; RRTV3_PX4_OA_B.i++) {
    RRTV3_PX4_OA_B.CastToDouble_j[RRTV3_PX4_OA_B.i] =
      RRTV3_PX4_OA_B.In1_a.data[RRTV3_PX4_OA_B.i];
  }

  // End of DataTypeConversion: '<S78>/Cast To Double'

  // MATLABSystem: '<S4>/Read Parameter1'
  if (RRTV3_PX4_OA_DW.obj_ki.SampleTime !=
      RRTV3_PX4_OA_P.ReadParameter1_SampleTime) {
    RRTV3_PX4_OA_DW.obj_ki.SampleTime = RRTV3_PX4_OA_P.ReadParameter1_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ki.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep = 0.0F;
  }

  // SignalConversion generated from: '<S80>/ SFunction ' incorporates:
  //   Constant: '<S79>/Constant2'
  //   Constant: '<S79>/Constant3'
  //   Gain: '<S79>/Gain10'
  //   Gain: '<S79>/Gain11'
  //   Gain: '<S79>/Gain12'
  //   Gain: '<S79>/Gain13'
  //   Gain: '<S79>/Gain14'
  //   Gain: '<S79>/Gain15'
  //   Gain: '<S79>/Gain16'
  //   Gain: '<S79>/Gain18'
  //   Gain: '<S79>/Gain19'
  //   Gain: '<S79>/Gain2'
  //   Gain: '<S79>/Gain3'
  //   Gain: '<S79>/Gain4'
  //   Gain: '<S79>/Gain5'
  //   Gain: '<S79>/Gain7'
  //   Gain: '<S79>/Gain8'
  //   Gain: '<S79>/Gain9'
  //   MATLAB Function: '<S77>/Pilot Inceptor Blending'

  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[0] = RRTV3_PX4_OA_P.Gain2_Gain_n *
    RRTV3_PX4_OA_B.CastToDouble[0];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[1] = RRTV3_PX4_OA_P.Gain3_Gain *
    RRTV3_PX4_OA_B.CastToDouble[1];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[2] = RRTV3_PX4_OA_P.Gain4_Gain *
    RRTV3_PX4_OA_B.CastToDouble[3];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[3] = RRTV3_PX4_OA_P.Gain5_Gain *
    RRTV3_PX4_OA_B.CastToDouble[2];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[4] = RRTV3_PX4_OA_P.Gain11_Gain *
    RRTV3_PX4_OA_B.AP_TKO;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[5] = RRTV3_PX4_OA_P.Gain10_Gain_d *
    RRTV3_PX4_OA_B.AP_DXN;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[6] = RRTV3_PX4_OA_P.Gain9_Gain_l *
    RRTV3_PX4_OA_B.AP_AXN;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[7] = RRTV3_PX4_OA_P.Gain7_Gain_a *
    RRTV3_PX4_OA_B.AP_LND;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[8] = RRTV3_PX4_OA_P.Gain8_Gain_d *
    RRTV3_PX4_OA_B.AP_NAV;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[9] = RRTV3_PX4_OA_P.Gain13_Gain_c *
    RRTV3_PX4_OA_B.AP_M1;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[10] = RRTV3_PX4_OA_P.Gain12_Gain *
    RRTV3_PX4_OA_B.AP_M2;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[11] = RRTV3_PX4_OA_P.Gain16_Gain_m *
    RRTV3_PX4_OA_B.AP_M3;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[12] = RRTV3_PX4_OA_P.Gain14_Gain *
    RRTV3_PX4_OA_B.AP_M4;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[13] = RRTV3_PX4_OA_P.Gain15_Gain_m *
    RRTV3_PX4_OA_B.AP_M5;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[14] = RRTV3_PX4_OA_B.u1;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[15] =
    RRTV3_PX4_OA_B.NacelleManualCmd;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[16] = RRTV3_PX4_OA_B.ControlLevel;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[17] = RRTV3_PX4_OA_B.PilotSource;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[18] = RRTV3_PX4_OA_P.Gain19_Gain_e *
    RRTV3_PX4_OA_P.Constant2_Value_h;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[19] = RRTV3_PX4_OA_P.Gain18_Gain_p *
    RRTV3_PX4_OA_P.Constant3_Value_i;

  // SignalConversion generated from: '<S80>/ SFunction ' incorporates:
  //   Gain: '<S78>/Gain'
  //   Gain: '<S78>/Gain1'
  //   Gain: '<S78>/Gain10'
  //   Gain: '<S78>/Gain11'
  //   Gain: '<S78>/Gain12'
  //   Gain: '<S78>/Gain13'
  //   Gain: '<S78>/Gain14'
  //   Gain: '<S78>/Gain15'
  //   Gain: '<S78>/Gain16'
  //   Gain: '<S78>/Gain17'
  //   Gain: '<S78>/Gain18'
  //   Gain: '<S78>/Gain19'
  //   Gain: '<S78>/Gain2'
  //   Gain: '<S78>/Gain3'
  //   Gain: '<S78>/Gain4'
  //   Gain: '<S78>/Gain5'
  //   Gain: '<S78>/Gain6'
  //   Gain: '<S78>/Gain7'
  //   Gain: '<S78>/Gain8'
  //   Gain: '<S78>/Gain9'
  //   MATLAB Function: '<S77>/Pilot Inceptor Blending'

  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[0] = RRTV3_PX4_OA_P.Gain2_Gain_h *
    RRTV3_PX4_OA_B.CastToDouble_j[0];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[1] = RRTV3_PX4_OA_P.Gain3_Gain_m *
    RRTV3_PX4_OA_B.CastToDouble_j[1];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[2] = RRTV3_PX4_OA_P.Gain5_Gain_d *
    RRTV3_PX4_OA_B.CastToDouble_j[2];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[3] = RRTV3_PX4_OA_P.Gain4_Gain_p *
    RRTV3_PX4_OA_B.CastToDouble_j[3];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[4] = RRTV3_PX4_OA_P.Gain11_Gain_g *
    RRTV3_PX4_OA_B.CastToDouble_j[4];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[5] = RRTV3_PX4_OA_P.Gain10_Gain_c *
    RRTV3_PX4_OA_B.CastToDouble_j[5];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[6] = RRTV3_PX4_OA_P.Gain9_Gain_c *
    RRTV3_PX4_OA_B.CastToDouble_j[6];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[7] = RRTV3_PX4_OA_P.Gain7_Gain_m *
    RRTV3_PX4_OA_B.CastToDouble_j[7];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[8] = RRTV3_PX4_OA_P.Gain8_Gain_f *
    RRTV3_PX4_OA_B.CastToDouble_j[8];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[9] = RRTV3_PX4_OA_P.Gain13_Gain_o *
    RRTV3_PX4_OA_B.CastToDouble_j[9];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[10] = RRTV3_PX4_OA_P.Gain12_Gain_p *
    RRTV3_PX4_OA_B.CastToDouble_j[10];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[11] = RRTV3_PX4_OA_P.Gain16_Gain_p *
    RRTV3_PX4_OA_B.CastToDouble_j[11];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[12] = RRTV3_PX4_OA_P.Gain14_Gain_k *
    RRTV3_PX4_OA_B.CastToDouble_j[12];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[13] = RRTV3_PX4_OA_P.Gain15_Gain_g *
    RRTV3_PX4_OA_B.CastToDouble_j[13];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[14] = RRTV3_PX4_OA_P.Gain_Gain_p *
    RRTV3_PX4_OA_B.u1;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[15] = RRTV3_PX4_OA_P.Gain1_Gain_n *
    RRTV3_PX4_OA_B.NacelleManualCmd;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[16] = RRTV3_PX4_OA_P.Gain6_Gain_a *
    RRTV3_PX4_OA_B.ControlLevel;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[17] = RRTV3_PX4_OA_P.Gain17_Gain_o *
    RRTV3_PX4_OA_B.PilotSource;
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[18] = RRTV3_PX4_OA_P.Gain18_Gain_h *
    RRTV3_PX4_OA_B.CastToDouble_j[18];
  RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[19] = RRTV3_PX4_OA_P.Gain19_Gain_i *
    RRTV3_PX4_OA_B.CastToDouble_j[19];

  // MATLAB Function: '<S77>/Pilot Inceptor Blending' incorporates:
  //   DataTypeConversion: '<S4>/Cast To Double1'
  //   MATLABSystem: '<S4>/Read Parameter1'
  //   MATLABSystem: '<S4>/Read Parameter6'
  //   SignalConversion generated from: '<S80>/ SFunction '
  //
  memcpy(&RRTV3_PX4_OA_B.CastToDouble_j[0],
         &RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[0], 20U * sizeof(real_T));
  if (RRTV3_PX4_OA_B.ParamStep_m0 == 1) {
    memcpy(&RRTV3_PX4_OA_B.CastToDouble_j[0],
           &RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[0], 20U * sizeof(real_T));
  }

  if ((RRTV3_PX4_OA_B.ParamStep_m0 == 2) && (RRTV3_PX4_OA_B.PilotSource == 1.0))
  {
    memcpy(&RRTV3_PX4_OA_B.CastToDouble_j[0],
           &RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[0], 20U * sizeof(real_T));
  }

  if ((RRTV3_PX4_OA_B.ParamStep_m0 == 3) && (RRTV3_PX4_OA_B.PilotSource == 1.0))
  {
    if (fabs(RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[0]) <
        RRTV3_PX4_OA_B.ParamStep) {
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[0] +
        RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[0];
      if (!(RRTV3_PX4_OA_B.z_HDG <= 1.0)) {
        RRTV3_PX4_OA_B.z_HDG = 1.0;
      }

      if (RRTV3_PX4_OA_B.z_HDG <= -1.0) {
        RRTV3_PX4_OA_B.CastToDouble_j[0] = -1.0;
      } else {
        RRTV3_PX4_OA_B.CastToDouble_j[0] = RRTV3_PX4_OA_B.z_HDG;
      }
    } else {
      RRTV3_PX4_OA_B.CastToDouble_j[0] =
        RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[0];
    }

    if (fabs(RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[1]) <
        RRTV3_PX4_OA_B.ParamStep) {
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[1] +
        RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[1];
      if (!(RRTV3_PX4_OA_B.z_HDG <= 1.0)) {
        RRTV3_PX4_OA_B.z_HDG = 1.0;
      }

      if (RRTV3_PX4_OA_B.z_HDG <= -1.0) {
        RRTV3_PX4_OA_B.CastToDouble_j[1] = -1.0;
      } else {
        RRTV3_PX4_OA_B.CastToDouble_j[1] = RRTV3_PX4_OA_B.z_HDG;
      }
    } else {
      RRTV3_PX4_OA_B.CastToDouble_j[1] =
        RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[1];
    }

    if (fabs(RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[2]) <
        RRTV3_PX4_OA_B.ParamStep) {
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[2] +
        RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[2];
      if (!(RRTV3_PX4_OA_B.z_HDG <= 1.0)) {
        RRTV3_PX4_OA_B.z_HDG = 1.0;
      }

      if (RRTV3_PX4_OA_B.z_HDG <= -1.0) {
        RRTV3_PX4_OA_B.CastToDouble_j[2] = -1.0;
      } else {
        RRTV3_PX4_OA_B.CastToDouble_j[2] = RRTV3_PX4_OA_B.z_HDG;
      }
    } else {
      RRTV3_PX4_OA_B.CastToDouble_j[2] =
        RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[2];
    }

    if (fabs(RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[3]) <
        RRTV3_PX4_OA_B.ParamStep) {
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[3] +
        RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[3];
      if (!(RRTV3_PX4_OA_B.z_HDG <= 1.0)) {
        RRTV3_PX4_OA_B.z_HDG = 1.0;
      }

      if (RRTV3_PX4_OA_B.z_HDG <= -1.0) {
        RRTV3_PX4_OA_B.CastToDouble_j[3] = -1.0;
      } else {
        RRTV3_PX4_OA_B.CastToDouble_j[3] = RRTV3_PX4_OA_B.z_HDG;
      }
    } else {
      RRTV3_PX4_OA_B.CastToDouble_j[3] =
        RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[3];
    }
  }

  // Gain: '<S77>/Gain2'
  RRTV3_PX4_OA_B.NacelleManualCmd = RRTV3_PX4_OA_P.Gain2_Gain_j *
    RRTV3_PX4_OA_B.CastToDouble_j[0];

  // Gain: '<S77>/Gain3'
  RRTV3_PX4_OA_B.dver_i = RRTV3_PX4_OA_P.Gain3_Gain_f *
    RRTV3_PX4_OA_B.CastToDouble_j[1];

  // Gain: '<S77>/Gain5'
  RRTV3_PX4_OA_B.ddir_h = RRTV3_PX4_OA_P.Gain5_Gain_f *
    RRTV3_PX4_OA_B.CastToDouble_j[2];

  // Gain: '<S77>/Gain4'
  RRTV3_PX4_OA_B.dacc_e = RRTV3_PX4_OA_P.Gain4_Gain_n *
    RRTV3_PX4_OA_B.CastToDouble_j[3];

  // Gain: '<S77>/Gain11'
  RRTV3_PX4_OA_B.TKO_d = RRTV3_PX4_OA_P.Gain11_Gain_h *
    RRTV3_PX4_OA_B.CastToDouble_j[4];

  // Gain: '<S77>/Gain10'
  RRTV3_PX4_OA_B.DXN_p = RRTV3_PX4_OA_P.Gain10_Gain_m *
    RRTV3_PX4_OA_B.CastToDouble_j[5];

  // Gain: '<S77>/Gain9'
  RRTV3_PX4_OA_B.NAV_p = RRTV3_PX4_OA_P.Gain9_Gain_d *
    RRTV3_PX4_OA_B.CastToDouble_j[6];

  // Gain: '<S77>/Gain7'
  RRTV3_PX4_OA_B.AXN_g = RRTV3_PX4_OA_P.Gain7_Gain_o *
    RRTV3_PX4_OA_B.CastToDouble_j[7];

  // Gain: '<S77>/Gain8'
  RRTV3_PX4_OA_B.LND_j = RRTV3_PX4_OA_P.Gain8_Gain_n *
    RRTV3_PX4_OA_B.CastToDouble_j[8];

  // Gain: '<S77>/Gain13'
  RRTV3_PX4_OA_B.M1_b = RRTV3_PX4_OA_P.Gain13_Gain_f *
    RRTV3_PX4_OA_B.CastToDouble_j[9];

  // Gain: '<S77>/Gain12'
  RRTV3_PX4_OA_B.M2_b = RRTV3_PX4_OA_P.Gain12_Gain_n *
    RRTV3_PX4_OA_B.CastToDouble_j[10];

  // Gain: '<S77>/Gain16'
  RRTV3_PX4_OA_B.M3_o = RRTV3_PX4_OA_P.Gain16_Gain_d *
    RRTV3_PX4_OA_B.CastToDouble_j[11];

  // Gain: '<S77>/Gain14'
  RRTV3_PX4_OA_B.M4_h = RRTV3_PX4_OA_P.Gain14_Gain_f *
    RRTV3_PX4_OA_B.CastToDouble_j[12];

  // Gain: '<S77>/Gain15'
  RRTV3_PX4_OA_B.M5_j = RRTV3_PX4_OA_P.Gain15_Gain_p *
    RRTV3_PX4_OA_B.CastToDouble_j[13];

  // Gain: '<S77>/Gain'
  RRTV3_PX4_OA_B.NacelleAutomaticFlag_p = RRTV3_PX4_OA_P.Gain_Gain_f *
    RRTV3_PX4_OA_B.CastToDouble_j[14];

  // Gain: '<S77>/Gain1'
  RRTV3_PX4_OA_B.NacelleManualCmd_c = RRTV3_PX4_OA_P.Gain1_Gain_fu *
    RRTV3_PX4_OA_B.CastToDouble_j[15];

  // Gain: '<S77>/Gain6' incorporates:
  //   MATLAB Function: '<S77>/Pilot Inceptor Blending'
  //   SignalConversion generated from: '<S80>/ SFunction '

  RRTV3_PX4_OA_B.SignalLoss_j = RRTV3_PX4_OA_P.Gain6_Gain_m *
    RRTV3_PX4_OA_B.ControlLevel;

  // Gain: '<S77>/Gain17'
  RRTV3_PX4_OA_B.PilotSource_g = RRTV3_PX4_OA_P.Gain17_Gain_k *
    RRTV3_PX4_OA_B.CastToDouble_j[17];

  // Gain: '<S77>/Gain19'
  RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_P.Gain19_Gain_p *
    RRTV3_PX4_OA_B.CastToDouble_j[18];

  // Gain: '<S77>/Gain18'
  RRTV3_PX4_OA_B.AP_TKO = RRTV3_PX4_OA_P.Gain18_Gain_f *
    RRTV3_PX4_OA_B.CastToDouble_j[19];

  // Gain: '<S93>/Gain2' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion7'

  RRTV3_PX4_OA_B.AP_NAV = RRTV3_PX4_OA_P.Gain2_Gain_jw *
    RRTV3_PX4_OA_B.In1_n.xyz[2];

  // Gain: '<S93>/Gain3' incorporates:
  //   MATLAB Function: '<S6>/LinVel Bus + INS'

  RRTV3_PX4_OA_B.AP_M2 = RRTV3_PX4_OA_P.Gain3_Gain_j * RRTV3_PX4_OA_B.phi;

  // Gain: '<S93>/Gain4' incorporates:
  //   MATLAB Function: '<S6>/LinVel Bus + INS'

  RRTV3_PX4_OA_B.AP_M1 = RRTV3_PX4_OA_P.Gain4_Gain_m * RRTV3_PX4_OA_B.theta;

  // Gain: '<S93>/Gain5' incorporates:
  //   MATLAB Function: '<S6>/LinVel Bus + INS'

  RRTV3_PX4_OA_B.HDGrad = RRTV3_PX4_OA_B.HDG * 0.017453292519943295 *
    RRTV3_PX4_OA_P.Gain5_Gain_k;

  // Gain: '<S93>/Gain11' incorporates:
  //   DataTypeConversion: '<S96>/Data Type Conversion18'
  //   MATLAB Function: '<S6>/LinVel Bus + INS'

  RRTV3_PX4_OA_B.ayms2 = (9.81 * sin(RRTV3_PX4_OA_B.phi) *
    RRTV3_PX4_OA_B.WPINDEX + RRTV3_PX4_OA_B.In1_g.xyz[1]) *
    RRTV3_PX4_OA_P.Gain11_Gain_i;

  // MATLABSystem: '<S55>/Max Phi Cmd8'
  if (RRTV3_PX4_OA_DW.obj_bo.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_n) {
    RRTV3_PX4_OA_DW.obj_bo.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_n;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_bo.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S55>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_jum.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_b) {
    RRTV3_PX4_OA_DW.obj_jum.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_b;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_jum.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_p);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_p = 0.0F;
  }

  // MATLABSystem: '<S55>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_pe.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_h) {
    RRTV3_PX4_OA_DW.obj_pe.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_h;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_pe.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_l);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S55>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_pas.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_jv) {
    RRTV3_PX4_OA_DW.obj_pas.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_jv;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_pas.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_j);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_j = 0.0F;
  }

  // MATLABSystem: '<S55>/Max Phi Cmd5'
  if (RRTV3_PX4_OA_DW.obj_iw.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_bq) {
    RRTV3_PX4_OA_DW.obj_iw.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_bq;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_iw.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_d);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_d = 0.0F;
  }

  // MATLABSystem: '<S55>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_eu.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_f) {
    RRTV3_PX4_OA_DW.obj_eu.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_f;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_eu.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_g);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_g = 0.0F;
  }

  // MATLABSystem: '<S57>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_f3.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_k) {
    RRTV3_PX4_OA_DW.obj_f3.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_k;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_f3.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ld);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ld = 0.0F;
  }

  // MATLABSystem: '<S57>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_hy.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_g) {
    RRTV3_PX4_OA_DW.obj_hy.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_g;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_hy.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_dh);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_dh = 0.0F;
  }

  // MATLABSystem: '<S57>/Max Phi Cmd7'
  if (RRTV3_PX4_OA_DW.obj_o0.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime_p) {
    RRTV3_PX4_OA_DW.obj_o0.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime_p;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_o0.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_dy);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_dy = 0.0F;
  }

  // MATLABSystem: '<S57>/Max Phi Cmd4'
  if (RRTV3_PX4_OA_DW.obj_aw.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_l) {
    RRTV3_PX4_OA_DW.obj_aw.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_l;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_aw.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_lx);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_lx = 0.0F;
  }

  // MATLABSystem: '<S57>/Max Phi Cmd6'
  if (RRTV3_PX4_OA_DW.obj_ci.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd6_SampleTime_g) {
    RRTV3_PX4_OA_DW.obj_ci.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd6_SampleTime_g;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ci.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_o);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S57>/Max Phi Cmd5'
  if (RRTV3_PX4_OA_DW.obj_op.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_h) {
    RRTV3_PX4_OA_DW.obj_op.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_h;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_op.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_b);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_b = 0.0F;
  }

  // MATLABSystem: '<S56>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_ce.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_a) {
    RRTV3_PX4_OA_DW.obj_ce.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_a;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ce.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_n);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_n = 0.0F;
  }

  // MATLABSystem: '<S56>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_cw.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_p) {
    RRTV3_PX4_OA_DW.obj_cw.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_p;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_cw.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_bs);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_bs = 0.0F;
  }

  // MATLABSystem: '<S56>/Max Phi Cmd8'
  if (RRTV3_PX4_OA_DW.obj_i5k.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_a) {
    RRTV3_PX4_OA_DW.obj_i5k.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_a;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_i5k.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_ln);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ln = 0.0F;
  }

  // MATLABSystem: '<S56>/Max Phi Cmd11'
  if (RRTV3_PX4_OA_DW.obj_d5.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd11_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_d5.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd11_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_d5.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_h);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_h = 0.0F;
  }

  // MATLABSystem: '<S56>/Max Phi Cmd10'
  if (RRTV3_PX4_OA_DW.obj_b1.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_b1.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_b1.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_bn);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_bn = 0.0F;
  }

  // MATLABSystem: '<S58>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_l4.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_p) {
    RRTV3_PX4_OA_DW.obj_l4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_p;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_l4.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_da);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_da = 0.0F;
  }

  // MATLABSystem: '<S58>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_ft.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_kw) {
    RRTV3_PX4_OA_DW.obj_ft.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_kw;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ft.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_e);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_e = 0.0F;
  }

  // MATLABSystem: '<S58>/Max Phi Cmd8'
  if (RRTV3_PX4_OA_DW.obj_hk.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_oa) {
    RRTV3_PX4_OA_DW.obj_hk.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_oa;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_hk.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_bj);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_bj = 0.0F;
  }

  // MATLABSystem: '<S58>/Max Phi Cmd11'
  if (RRTV3_PX4_OA_DW.obj_ey.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd11_SampleTime_f) {
    RRTV3_PX4_OA_DW.obj_ey.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd11_SampleTime_f;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ey.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_jz);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_jz = 0.0F;
  }

  // MATLABSystem: '<S58>/Max Phi Cmd10'
  if (RRTV3_PX4_OA_DW.obj_ixo.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime_f) {
    RRTV3_PX4_OA_DW.obj_ixo.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime_f;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ixo.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_f);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_f = 0.0F;
  }

  // MATLABSystem: '<S59>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_hl.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_l5) {
    RRTV3_PX4_OA_DW.obj_hl.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_l5;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_hl.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_a);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_a = 0.0F;
  }

  // MATLABSystem: '<S59>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_oj.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_ki) {
    RRTV3_PX4_OA_DW.obj_oj.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_ki;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_oj.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ju);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ju = 0.0F;
  }

  // MATLABSystem: '<S59>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_pm.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_l) {
    RRTV3_PX4_OA_DW.obj_pm.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_l;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_pm.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_jz5);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_jz5 = 0.0F;
  }

  // MATLABSystem: '<S67>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_mv.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_ni) {
    RRTV3_PX4_OA_DW.obj_mv.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_ni;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_mv.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_o4);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_o4 = 0.0F;
  }

  // MATLABSystem: '<S67>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_mc.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_n) {
    RRTV3_PX4_OA_DW.obj_mc.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_n;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_mc.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ny);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ny = 0.0F;
  }

  // MATLABSystem: '<S67>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_hd.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_i0) {
    RRTV3_PX4_OA_DW.obj_hd.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_i0;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_hd.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_i);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S67>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_fx.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_ga) {
    RRTV3_PX4_OA_DW.obj_fx.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_ga;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_fx.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_oy);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_oy = 0.0F;
  }

  // MATLABSystem: '<S67>/Max Phi Cmd7'
  if (RRTV3_PX4_OA_DW.obj_ac.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime_e) {
    RRTV3_PX4_OA_DW.obj_ac.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime_e;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ac.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_nv);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_nv = 0.0F;
  }

  // MATLABSystem: '<S67>/Max Phi Cmd4'
  if (RRTV3_PX4_OA_DW.obj_ko.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_d) {
    RRTV3_PX4_OA_DW.obj_ko.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_d;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ko.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_m);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_m = 0.0F;
  }

  // MATLABSystem: '<S67>/Max Phi Cmd10'
  if (RRTV3_PX4_OA_DW.obj_l.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime_p) {
    RRTV3_PX4_OA_DW.obj_l.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime_p;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_l.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_c);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_c = 0.0F;
  }

  // MATLABSystem: '<S67>/Max Phi Cmd12'
  if (RRTV3_PX4_OA_DW.obj_ii.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime_h) {
    RRTV3_PX4_OA_DW.obj_ii.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime_h;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ii.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_md);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_md = 0.0F;
  }

  // MATLABSystem: '<S67>/Max Phi Cmd11'
  if (RRTV3_PX4_OA_DW.obj_b.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd11_SampleTime_l) {
    RRTV3_PX4_OA_DW.obj_b.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd11_SampleTime_l;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_b.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_m3);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_m3 = 0.0F;
  }

  // MATLABSystem: '<S68>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_mzd.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_j) {
    RRTV3_PX4_OA_DW.obj_mzd.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_j;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_mzd.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_ja);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ja = 0.0F;
  }

  // MATLABSystem: '<S68>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_h3.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_j) {
    RRTV3_PX4_OA_DW.obj_h3.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_j;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_h3.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_h5);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_h5 = 0.0F;
  }

  // MATLABSystem: '<S68>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_ix.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_pa) {
    RRTV3_PX4_OA_DW.obj_ix.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_pa;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ix.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_c0);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_c0 = 0.0F;
  }

  // MATLABSystem: '<S65>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_n0.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_h3) {
    RRTV3_PX4_OA_DW.obj_n0.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_h3;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_n0.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ct);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ct = 0.0F;
  }

  // MATLABSystem: '<S65>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_bu.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_o) {
    RRTV3_PX4_OA_DW.obj_bu.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_o;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_bu.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_px);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_px = 0.0F;
  }

  // MATLABSystem: '<S65>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_ag.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_kp) {
    RRTV3_PX4_OA_DW.obj_ag.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_kp;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ag.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_p5);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_p5 = 0.0F;
  }

  // MATLABSystem: '<S62>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_ez.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_n) {
    RRTV3_PX4_OA_DW.obj_ez.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_n;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ez.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_af);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_af = 0.0F;
  }

  // MATLABSystem: '<S62>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_l0.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_p) {
    RRTV3_PX4_OA_DW.obj_l0.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_p;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_l0.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ev);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ev = 0.0F;
  }

  // MATLABSystem: '<S62>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_p4.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_c) {
    RRTV3_PX4_OA_DW.obj_p4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_c;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_p4.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ax);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ax = 0.0F;
  }

  // MATLABSystem: '<S62>/Max Phi Cmd5'
  if (RRTV3_PX4_OA_DW.obj_d.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_hb) {
    RRTV3_PX4_OA_DW.obj_d.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_hb;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_d.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_as);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_as = 0.0F;
  }

  // MATLABSystem: '<S62>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_pb.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_c) {
    RRTV3_PX4_OA_DW.obj_pb.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_c;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_pb.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_if);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_if = 0.0F;
  }

  // MATLABSystem: '<S63>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_lm.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_hz) {
    RRTV3_PX4_OA_DW.obj_lm.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_hz;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_lm.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_lt);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_lt = 0.0F;
  }

  // MATLABSystem: '<S63>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_g.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_d)
  {
    RRTV3_PX4_OA_DW.obj_g.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_d;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_g.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_oj);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_oj = 0.0F;
  }

  // MATLABSystem: '<S63>/Max Phi Cmd5'
  if (RRTV3_PX4_OA_DW.obj_os.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_p) {
    RRTV3_PX4_OA_DW.obj_os.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_p;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_os.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_o2);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S63>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_jv.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_lv) {
    RRTV3_PX4_OA_DW.obj_jv.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_lv;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_jv.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ip);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ip = 0.0F;
  }

  // MATLABSystem: '<S63>/Max Phi Cmd4'
  if (RRTV3_PX4_OA_DW.obj_c.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_km) {
    RRTV3_PX4_OA_DW.obj_c.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_km;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_c.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_fk);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_fk = 0.0F;
  }

  // MATLABSystem: '<S66>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_mz4.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_c) {
    RRTV3_PX4_OA_DW.obj_mz4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_c;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_mz4.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_iz);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_iz = 0.0F;
  }

  // MATLABSystem: '<S66>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_mj.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_f) {
    RRTV3_PX4_OA_DW.obj_mj.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_f;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_mj.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ff);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ff = 0.0F;
  }

  // MATLABSystem: '<S66>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_m2.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_fy) {
    RRTV3_PX4_OA_DW.obj_m2.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_fy;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_m2.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_gx);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_gx = 0.0F;
  }

  // MATLABSystem: '<S66>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_jf.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_n) {
    RRTV3_PX4_OA_DW.obj_jf.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_n;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_jf.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_co);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_co = 0.0F;
  }

  // MATLABSystem: '<S66>/Max Phi Cmd4'
  if (RRTV3_PX4_OA_DW.obj_eg.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_pr) {
    RRTV3_PX4_OA_DW.obj_eg.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_pr;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_eg.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_o3);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_o3 = 0.0F;
  }

  // MATLABSystem: '<S70>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_o.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_k)
  {
    RRTV3_PX4_OA_DW.obj_o.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_k;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_o.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_lm);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_lm = 0.0F;
  }

  // MATLABSystem: '<S70>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_n.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_c)
  {
    RRTV3_PX4_OA_DW.obj_n.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_c;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_n.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_mv);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_mv = 0.0F;
  }

  // MATLABSystem: '<S70>/Max Phi Cmd5'
  if (RRTV3_PX4_OA_DW.obj_i.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_c)
  {
    RRTV3_PX4_OA_DW.obj_i.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_c;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_i.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_mj);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_mj = 0.0F;
  }

  // MATLABSystem: '<S70>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_j.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_f)
  {
    RRTV3_PX4_OA_DW.obj_j.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_f;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_j.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_cn);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_cn = 0.0F;
  }

  // MATLABSystem: '<S69>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_fy.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_a) {
    RRTV3_PX4_OA_DW.obj_fy.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_a;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_fy.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_fm);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_fm = 0.0F;
  }

  // MATLABSystem: '<S69>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_h.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_pz) {
    RRTV3_PX4_OA_DW.obj_h.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_pz;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_h.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_p4);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_p4 = 0.0F;
  }

  // MATLABSystem: '<S69>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_mz.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_n) {
    RRTV3_PX4_OA_DW.obj_mz.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_n;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_mz.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_e1);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_e1 = 0.0F;
  }

  // MATLABSystem: '<S69>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_i4.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_ju) {
    RRTV3_PX4_OA_DW.obj_i4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_ju;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_i4.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_o4a);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_o4a = 0.0F;
  }

  // MATLABSystem: '<S69>/Max Phi Cmd7'
  if (RRTV3_PX4_OA_DW.obj_m.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime_d)
  {
    RRTV3_PX4_OA_DW.obj_m.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime_d;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_m.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_hh);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_hh = 0.0F;
  }

  // MATLABSystem: '<S69>/Max Phi Cmd4'
  if (RRTV3_PX4_OA_DW.obj_nw.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_b) {
    RRTV3_PX4_OA_DW.obj_nw.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_b;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_nw.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_l5);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_l5 = 0.0F;
  }

  // MATLABSystem: '<S69>/Max Phi Cmd6'
  if (RRTV3_PX4_OA_DW.obj_km.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd6_SampleTime_k) {
    RRTV3_PX4_OA_DW.obj_km.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd6_SampleTime_k;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_km.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_h2);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_h2 = 0.0F;
  }

  // MATLABSystem: '<S69>/Max Phi Cmd5'
  if (RRTV3_PX4_OA_DW.obj_ju.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_f) {
    RRTV3_PX4_OA_DW.obj_ju.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_f;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ju.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_me);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_me = 0.0F;
  }

  // MATLABSystem: '<S69>/Max Phi Cmd10'
  if (RRTV3_PX4_OA_DW.obj_jd.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime_pj) {
    RRTV3_PX4_OA_DW.obj_jd.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime_pj;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_jd.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_mc);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_mc = 0.0F;
  }

  // MATLABSystem: '<S64>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_b5.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_i) {
    RRTV3_PX4_OA_DW.obj_b5.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_i;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_b5.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_h3);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_h3 = 0.0F;
  }

  // MATLABSystem: '<S64>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_bi.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_bc) {
    RRTV3_PX4_OA_DW.obj_bi.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_bc;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_bi.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_cs);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_cs = 0.0F;
  }

  // MATLABSystem: '<S64>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_fc.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_f) {
    RRTV3_PX4_OA_DW.obj_fc.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_f;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_fc.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_k);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_k = 0.0F;
  }

  // MATLABSystem: '<S64>/Max Phi Cmd5'
  if (RRTV3_PX4_OA_DW.obj_m4.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_nz) {
    RRTV3_PX4_OA_DW.obj_m4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_nz;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_m4.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_pc);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_pc = 0.0F;
  }

  // MATLABSystem: '<S64>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_om.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_p5) {
    RRTV3_PX4_OA_DW.obj_om.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_p5;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_om.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_pxv);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_pxv = 0.0F;
  }

  // MATLABSystem: '<S64>/Max Phi Cmd4'
  if (RRTV3_PX4_OA_DW.obj_po.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_p) {
    RRTV3_PX4_OA_DW.obj_po.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_p;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_po.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_p4u);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_p4u = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd8'
  if (RRTV3_PX4_OA_DW.obj_el.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_b) {
    RRTV3_PX4_OA_DW.obj_el.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_b;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_el.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ap);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ap = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_hwf.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_m) {
    RRTV3_PX4_OA_DW.obj_hwf.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_m;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_hwf.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_jd);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_jd = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd3'
  if (RRTV3_PX4_OA_DW.obj_hw.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_i) {
    RRTV3_PX4_OA_DW.obj_hw.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_i;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_hw.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ek);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ek = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_gv.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_m) {
    RRTV3_PX4_OA_DW.obj_gv.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_m;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_gv.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ol);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ol = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd5'
  if (RRTV3_PX4_OA_DW.obj_cx2.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_e) {
    RRTV3_PX4_OA_DW.obj_cx2.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_e;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_cx2.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_bb);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_bb = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd4'
  if (RRTV3_PX4_OA_DW.obj_it.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_k) {
    RRTV3_PX4_OA_DW.obj_it.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_k;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_it.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ao);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ao = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd12'
  if (RRTV3_PX4_OA_DW.obj_bis.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime_p) {
    RRTV3_PX4_OA_DW.obj_bis.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime_p;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_bis.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_g2);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_g2 = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd6'
  if (RRTV3_PX4_OA_DW.obj_jg.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd6_SampleTime_o) {
    RRTV3_PX4_OA_DW.obj_jg.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd6_SampleTime_o;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_jg.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ex);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ex = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_cx.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_g) {
    RRTV3_PX4_OA_DW.obj_cx.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_g;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_cx.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_fi);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_fi = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd7'
  if (RRTV3_PX4_OA_DW.obj_jp.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime_k) {
    RRTV3_PX4_OA_DW.obj_jp.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime_k;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_jp.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_h22);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_h22 = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd30'
  if (RRTV3_PX4_OA_DW.obj_ln.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd30_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_ln.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd30_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ln.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ei);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ei = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd31'
  if (RRTV3_PX4_OA_DW.obj_cy.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd31_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_cy.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd31_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_cy.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ch);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ch = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd11'
  if (RRTV3_PX4_OA_DW.obj_hc.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd11_SampleTime_g) {
    RRTV3_PX4_OA_DW.obj_hc.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd11_SampleTime_g;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_hc.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_axz);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_axz = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd10'
  if (RRTV3_PX4_OA_DW.obj_c4.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime_j) {
    RRTV3_PX4_OA_DW.obj_c4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime_j;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_c4.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_dau);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_dau = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd23'
  if (RRTV3_PX4_OA_DW.obj_er.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd23_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_er.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd23_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_er.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_af2);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_af2 = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd13'
  if (RRTV3_PX4_OA_DW.obj_pa.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd13_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_pa.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd13_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_pa.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_pb);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_pb = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd18'
  if (RRTV3_PX4_OA_DW.obj_hb.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd18_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_hb.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd18_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_hb.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ms);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ms = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd16'
  if (RRTV3_PX4_OA_DW.obj_cf.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd16_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_cf.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd16_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_cf.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_o3v);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_o3v = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd21'
  if (RRTV3_PX4_OA_DW.obj_jl.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd21_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_jl.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd21_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_jl.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_nh);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_nh = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd22'
  if (RRTV3_PX4_OA_DW.obj_a1.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd22_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_a1.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd22_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_a1.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_lu);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_lu = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd15'
  if (RRTV3_PX4_OA_DW.obj_bg.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd15_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_bg.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd15_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_bg.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_pe);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_pe = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd14'
  if (RRTV3_PX4_OA_DW.obj_dg.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd14_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_dg.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd14_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_dg.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_pt);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_pt = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd28'
  if (RRTV3_PX4_OA_DW.obj_j3.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd28_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_j3.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd28_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_j3.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ft);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ft = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd27'
  if (RRTV3_PX4_OA_DW.obj_j34.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd27_SampleTime) {
    RRTV3_PX4_OA_DW.obj_j34.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd27_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_j34.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_ie);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ie = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd26'
  if (RRTV3_PX4_OA_DW.obj_nn.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd26_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_nn.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd26_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_nn.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ox);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ox = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd25'
  if (RRTV3_PX4_OA_DW.obj_jn.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd25_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_jn.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd25_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_jn.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_kk);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_kk = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd20'
  if (RRTV3_PX4_OA_DW.obj_me.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd20_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_me.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd20_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_me.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ieu);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ieu = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd19'
  if (RRTV3_PX4_OA_DW.obj_fp.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd19_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_fp.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd19_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_fp.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_oc);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_oc = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd17'
  if (RRTV3_PX4_OA_DW.obj_jfi.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd17_SampleTime) {
    RRTV3_PX4_OA_DW.obj_jfi.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd17_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_jfi.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_m4);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_m4 = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd29'
  if (RRTV3_PX4_OA_DW.obj_m5.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd29_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_m5.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd29_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_m5.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_cu);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_cu = 0.0F;
  }

  // MATLABSystem: '<S60>/Max Phi Cmd24'
  if (RRTV3_PX4_OA_DW.obj_i5.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd24_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_i5.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd24_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_i5.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_fb);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_fb = 0.0F;
  }

  // MATLABSystem: '<S52>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_jh.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_dr) {
    RRTV3_PX4_OA_DW.obj_jh.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_dr;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_jh.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_hc);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_hc = 0.0F;
  }

  // MATLABSystem: '<S52>/Max Phi Cmd5'
  if (RRTV3_PX4_OA_DW.obj_eo.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_m) {
    RRTV3_PX4_OA_DW.obj_eo.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_m;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_eo.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_m44);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_m44 = 0.0F;
  }

  // MATLABSystem: '<S52>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_bisy.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_k) {
    RRTV3_PX4_OA_DW.obj_bisy.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_k;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_bisy.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_ad);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ad = 0.0F;
  }

  // MATLABSystem: '<S2>/Max Phi Cmd8'
  if (RRTV3_PX4_OA_DW.obj_j0.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_o) {
    RRTV3_PX4_OA_DW.obj_j0.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_o;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_j0.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_kb);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_kb = 0.0F;
  }

  // MATLABSystem: '<S2>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_ba.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_d) {
    RRTV3_PX4_OA_DW.obj_ba.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_d;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ba.MW_PARAMHANDLE, MW_INT32,
    &RRTV3_PX4_OA_B.ParamStep_m0);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_m0 = 0;
  }

  // MATLABSystem: '<S51>/Max Phi Cmd8'
  if (RRTV3_PX4_OA_DW.obj_ji.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_on) {
    RRTV3_PX4_OA_DW.obj_ji.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_on;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ji.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_pcr);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_pcr = 0.0F;
  }

  // MATLABSystem: '<S51>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_mo.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_h) {
    RRTV3_PX4_OA_DW.obj_mo.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_h;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_mo.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_bp);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_bp = 0.0F;
  }

  // MATLABSystem: '<S51>/Max Phi Cmd5'
  if (RRTV3_PX4_OA_DW.obj_ia.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_b) {
    RRTV3_PX4_OA_DW.obj_ia.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_b;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ia.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_chp);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_chp = 0.0F;
  }

  // MATLABSystem: '<S51>/Max Phi Cmd12'
  if (RRTV3_PX4_OA_DW.obj_ja.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime_d) {
    RRTV3_PX4_OA_DW.obj_ja.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime_d;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ja.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_nb);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_nb = 0.0F;
  }

  // MATLABSystem: '<S51>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_bt.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_j) {
    RRTV3_PX4_OA_DW.obj_bt.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_j;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_bt.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_ij);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_ij = 0.0F;
  }

  // MATLABSystem: '<S50>/Max Phi Cmd8'
  if (RRTV3_PX4_OA_DW.obj_cxq.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_d) {
    RRTV3_PX4_OA_DW.obj_cxq.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_d;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_cxq.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_my);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_my = 0.0F;
  }

  // MATLABSystem: '<S50>/Max Phi Cmd9'
  if (RRTV3_PX4_OA_DW.obj_cl.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_cl.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_cl.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_jg);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_jg = 0.0F;
  }

  // MATLABSystem: '<S50>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_f1.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_i) {
    RRTV3_PX4_OA_DW.obj_f1.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_i;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_f1.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_evk);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_evk = 0.0F;
  }

  // MATLABSystem: '<S79>/Read Parameter6'
  if (RRTV3_PX4_OA_DW.obj_f.SampleTime !=
      RRTV3_PX4_OA_P.ReadParameter6_SampleTime_b) {
    RRTV3_PX4_OA_DW.obj_f.SampleTime =
      RRTV3_PX4_OA_P.ReadParameter6_SampleTime_b;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_f.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_mvx);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_mvx = 0.0F;
  }

  // Outputs for Enabled SubSystem: '<Root>/Controllers' incorporates:
  //   EnablePort: '<S1>/Enable'

  // DataTypeConversion: '<S4>/Cast To Boolean'
  if (RRTV3_PX4_OA_B.Arm_i != 0) {
    // MATLAB Function: '<S42>/MATLAB Function' incorporates:
    //   Constant: '<S42>/Constant'
    //   Constant: '<S42>/Constant2'
    //   Constant: '<S42>/Constant3'
    //   Constant: '<S42>/Constant4'
    //   Constant: '<S42>/Constant5'
    //   DataTypeConversion: '<S51>/Data Type Conversion17'
    //   MATLABSystem: '<S51>/Max Phi Cmd8'
    //   MATLABSystem: '<S51>/Max Phi Cmd9'
    //   Memory: '<S13>/Memory2'
    //
    memset(&RRTV3_PX4_OA_B.PathDef[0], 0, 140U * sizeof(real_T));
    RRTV3_PX4_OA_B.ParamStep_jgs = 0;
    if (RRTV3_PX4_OA_DW.Memory2_PreviousInput[6] == 1.0) {
      memcpy(&RRTV3_PX4_OA_B.PathDef[0], &RRTV3_PX4_OA_P.PathDef1[0], 140U *
             sizeof(real_T));
    }

    if (RRTV3_PX4_OA_DW.Memory2_PreviousInput[6] == 2.0) {
      memcpy(&RRTV3_PX4_OA_B.PathDef[0], &RRTV3_PX4_OA_P.PathDef2[0], 140U *
             sizeof(real_T));
    }

    if (RRTV3_PX4_OA_DW.Memory2_PreviousInput[6] == 3.0) {
      memcpy(&RRTV3_PX4_OA_B.PathDef[0], &RRTV3_PX4_OA_P.PathDef3[0], 140U *
             sizeof(real_T));
    }

    if (RRTV3_PX4_OA_DW.Memory2_PreviousInput[6] == 4.0) {
      memcpy(&RRTV3_PX4_OA_B.PathDef[0], &RRTV3_PX4_OA_P.PathDef4[0], 140U *
             sizeof(real_T));
    }

    if (RRTV3_PX4_OA_DW.Memory2_PreviousInput[6] == 5.0) {
      memcpy(&RRTV3_PX4_OA_B.PathDef[0], &RRTV3_PX4_OA_P.PathDef5[0], 140U *
             sizeof(real_T));
    }

    RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_B.PathDef[120];
    if (RRTV3_PX4_OA_B.PathDef[120] == 0.0) {
      for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 20; RRTV3_PX4_OA_B.i++) {
        RRTV3_PX4_OA_B.PathDef[RRTV3_PX4_OA_B.i + 120] = 5.0;
      }
    }

    if ((RRTV3_PX4_OA_DW.Memory2_PreviousInput[2] == 1.0) &&
        (RRTV3_PX4_OA_DW.Memory2_PreviousInput[6] > 0.0) && (RRTV3_PX4_OA_B.phi >
         0.0)) {
      RRTV3_PX4_OA_B.ParamStep_jgs = 1;
    }

    if (RRTV3_PX4_OA_B.ParamStep_pcr > 0.0F) {
      for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 19; RRTV3_PX4_OA_B.i++) {
        RRTV3_PX4_OA_B.PathDef[RRTV3_PX4_OA_B.i + 80] =
          RRTV3_PX4_OA_B.ParamStep_pcr;
      }
    }

    if (RRTV3_PX4_OA_B.ParamStep_bp > 0.0F) {
      for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 20; RRTV3_PX4_OA_B.i++) {
        RRTV3_PX4_OA_B.PathDef[RRTV3_PX4_OA_B.i + 40] =
          RRTV3_PX4_OA_B.ParamStep_bp / 3.28;
      }
    }

    // End of MATLAB Function: '<S42>/MATLAB Function'

    // Saturate: '<S9>/[-40,+400]'
    if (RRTV3_PX4_OA_B.VCSkt > RRTV3_PX4_OA_P.u0400_UpperSat) {
      RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.u0400_UpperSat;
    } else if (RRTV3_PX4_OA_B.VCSkt < RRTV3_PX4_OA_P.u0400_LowerSat) {
      RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.u0400_LowerSat;
    } else {
      RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_B.VCSkt;
    }

    // End of Saturate: '<S9>/[-40,+400]'

    // SignalConversion generated from: '<S28>/ SFunction ' incorporates:
    //   MATLAB Function: '<S13>/MATLAB Function'
    //   MATLAB Function: '<S9>/GAIN SCHEDULER'
    //   SignalConversion generated from: '<S40>/ SFunction '

    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[0] =
      RRTV3_PX4_OA_B.NacelleManualCmd;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[1] = RRTV3_PX4_OA_B.dver_i;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[2] = RRTV3_PX4_OA_B.ddir_h;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[3] = RRTV3_PX4_OA_B.dacc_e;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[4] = RRTV3_PX4_OA_B.TKO_d;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[5] = RRTV3_PX4_OA_B.DXN_p;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[6] = RRTV3_PX4_OA_B.NAV_p;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[7] = RRTV3_PX4_OA_B.AXN_g;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[8] = RRTV3_PX4_OA_B.LND_j;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[9] = RRTV3_PX4_OA_B.M1_b;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[10] = RRTV3_PX4_OA_B.M2_b;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[11] = RRTV3_PX4_OA_B.M3_o;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[12] = RRTV3_PX4_OA_B.M4_h;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[13] = RRTV3_PX4_OA_B.M5_j;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[14] =
      RRTV3_PX4_OA_B.NacelleAutomaticFlag_p;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[15] =
      RRTV3_PX4_OA_B.NacelleManualCmd_c;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[16] = RRTV3_PX4_OA_B.SignalLoss_j;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[17] =
      RRTV3_PX4_OA_B.PilotSource_g;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[18] = RRTV3_PX4_OA_B.u1;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a[19] = RRTV3_PX4_OA_B.AP_TKO;

    // SignalConversion generated from: '<S28>/ SFunction ' incorporates:
    //   Constant: '<S56>/Constant'
    //   Constant: '<S56>/Constant1'
    //   Constant: '<S56>/Constant2'
    //   Constant: '<S56>/Constant3'
    //   Constant: '<S56>/Constant4'
    //   Constant: '<S56>/Constant5'
    //   MATLAB Function: '<S9>/GAIN SCHEDULER'
    //   MATLABSystem: '<S56>/Max Phi Cmd10'
    //   MATLABSystem: '<S56>/Max Phi Cmd11'
    //   MATLABSystem: '<S56>/Max Phi Cmd2'
    //   MATLABSystem: '<S56>/Max Phi Cmd3'
    //   MATLABSystem: '<S56>/Max Phi Cmd8'
    //
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[0] =
      RRTV3_PX4_OA_P.Constant_Value_bw;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[1] =
      RRTV3_PX4_OA_P.Constant1_Value_i;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[2] = RRTV3_PX4_OA_B.ParamStep_n;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[3] = RRTV3_PX4_OA_B.ParamStep_bs;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[4] =
      RRTV3_PX4_OA_P.Constant2_Value_i;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[5] =
      RRTV3_PX4_OA_P.Constant3_Value_g;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[6] =
      RRTV3_PX4_OA_P.Constant4_Value_e;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[7] =
      RRTV3_PX4_OA_P.Constant5_Value_j;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[8] = RRTV3_PX4_OA_B.ParamStep_ln;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[9] = RRTV3_PX4_OA_B.ParamStep_h;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[10] = RRTV3_PX4_OA_B.ParamStep_bn;

    // SignalConversion generated from: '<S28>/ SFunction ' incorporates:
    //   Constant: '<S57>/Constant'
    //   Constant: '<S57>/Constant1'
    //   MATLAB Function: '<S9>/GAIN SCHEDULER'
    //   MATLABSystem: '<S57>/Max Phi Cmd2'
    //   MATLABSystem: '<S57>/Max Phi Cmd3'
    //   MATLABSystem: '<S57>/Max Phi Cmd4'
    //   MATLABSystem: '<S57>/Max Phi Cmd5'
    //   MATLABSystem: '<S57>/Max Phi Cmd6'
    //   MATLABSystem: '<S57>/Max Phi Cmd7'
    //
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_ht[0] =
      RRTV3_PX4_OA_P.Constant_Value_d;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_ht[1] =
      RRTV3_PX4_OA_P.Constant1_Value_g;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_ht[2] = RRTV3_PX4_OA_B.ParamStep_ld;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_ht[3] = RRTV3_PX4_OA_B.ParamStep_dh;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_ht[4] = RRTV3_PX4_OA_B.ParamStep_dy;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_ht[5] = RRTV3_PX4_OA_B.ParamStep_lx;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_ht[6] = RRTV3_PX4_OA_B.ParamStep_o;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_ht[7] = RRTV3_PX4_OA_B.ParamStep_b;

    // SignalConversion generated from: '<S28>/ SFunction ' incorporates:
    //   Constant: '<S58>/Constant'
    //   Constant: '<S58>/Constant1'
    //   Constant: '<S58>/Constant2'
    //   Constant: '<S58>/Constant3'
    //   Constant: '<S58>/Constant4'
    //   Constant: '<S58>/Constant5'
    //   MATLAB Function: '<S9>/GAIN SCHEDULER'
    //   MATLABSystem: '<S58>/Max Phi Cmd10'
    //   MATLABSystem: '<S58>/Max Phi Cmd11'
    //   MATLABSystem: '<S58>/Max Phi Cmd2'
    //   MATLABSystem: '<S58>/Max Phi Cmd3'
    //   MATLABSystem: '<S58>/Max Phi Cmd8'
    //
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[0] =
      RRTV3_PX4_OA_P.Constant_Value_ac;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[1] =
      RRTV3_PX4_OA_P.Constant1_Value_kg;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[2] = RRTV3_PX4_OA_B.ParamStep_da;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[3] = RRTV3_PX4_OA_B.ParamStep_e;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[4] =
      RRTV3_PX4_OA_P.Constant2_Value_c;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[5] =
      RRTV3_PX4_OA_P.Constant3_Value_f;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[6] =
      RRTV3_PX4_OA_P.Constant4_Value_b;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[7] =
      RRTV3_PX4_OA_P.Constant5_Value_o;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[8] = RRTV3_PX4_OA_B.ParamStep_bj;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[9] = RRTV3_PX4_OA_B.ParamStep_jz;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[10] = RRTV3_PX4_OA_B.ParamStep_f;

    // SignalConversion generated from: '<S28>/ SFunction ' incorporates:
    //   Constant: '<S55>/Constant1'
    //   Constant: '<S55>/Constant2'
    //   Constant: '<S55>/Constant3'
    //   Constant: '<S55>/Constant4'
    //   MATLAB Function: '<S9>/GAIN SCHEDULER'
    //   MATLABSystem: '<S55>/Max Phi Cmd1'
    //   MATLABSystem: '<S55>/Max Phi Cmd2'
    //   MATLABSystem: '<S55>/Max Phi Cmd3'
    //   MATLABSystem: '<S55>/Max Phi Cmd5'
    //   MATLABSystem: '<S55>/Max Phi Cmd8'
    //   MATLABSystem: '<S55>/Max Phi Cmd9'
    //
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[0] = RRTV3_PX4_OA_B.ParamStep;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[1] = RRTV3_PX4_OA_B.ParamStep_p;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[2] = RRTV3_PX4_OA_B.ParamStep_l;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[3] = RRTV3_PX4_OA_B.ParamStep_j;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[4] =
      RRTV3_PX4_OA_P.Constant3_Value_i3;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[5] =
      RRTV3_PX4_OA_P.Constant1_Value_h;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[6] =
      RRTV3_PX4_OA_P.Constant2_Value_ey;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[7] = RRTV3_PX4_OA_B.ParamStep_d;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[8] = RRTV3_PX4_OA_B.ParamStep_g;
    RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[9] =
      RRTV3_PX4_OA_P.Constant4_Value_h;

    // MATLAB Function: '<S9>/GAIN SCHEDULER' incorporates:
    //   Constant: '<S27>/Constant1'
    //   Constant: '<S27>/Constant2'
    //   Constant: '<S27>/Constant20'
    //   Constant: '<S27>/Constant21'
    //   Constant: '<S27>/Constant22'
    //   Constant: '<S27>/Constant3'
    //   Constant: '<S27>/Constant4'
    //   Constant: '<S27>/Constant5'
    //   Constant: '<S27>/Constant6'
    //   Constant: '<S2>/Constant4'
    //   Constant: '<S52>/Constant4'
    //   Constant: '<S59>/Constant'
    //   Constant: '<S60>/Constant12'
    //   Constant: '<S60>/Constant13'
    //   Constant: '<S60>/Constant14'
    //   Constant: '<S60>/Constant20'
    //   Constant: '<S65>/Constant1'
    //   Constant: '<S65>/Constant2'
    //   Constant: '<S67>/Constant1'
    //   Constant: '<S67>/Constant2'
    //   Constant: '<S67>/Constant3'
    //   Constant: '<S68>/Constant'
    //   Constant: '<S68>/Constant1'
    //   Constant: '<S68>/Constant2'
    //   Constant: '<S68>/Constant3'
    //   Constant: '<S68>/Constant4'
    //   Constant: '<S68>/Constant5'
    //   Constant: '<S68>/Constant6'
    //   Constant: '<S9>/Constant'
    //   DataTypeConversion: '<S2>/Data Type Conversion19'
    //   MATLABSystem: '<S2>/Max Phi Cmd1'
    //   MATLABSystem: '<S2>/Max Phi Cmd8'
    //   MATLABSystem: '<S52>/Max Phi Cmd1'
    //   MATLABSystem: '<S52>/Max Phi Cmd2'
    //   MATLABSystem: '<S52>/Max Phi Cmd5'
    //   MATLABSystem: '<S59>/Max Phi Cmd1'
    //   MATLABSystem: '<S59>/Max Phi Cmd2'
    //   MATLABSystem: '<S59>/Max Phi Cmd9'
    //   MATLABSystem: '<S60>/Max Phi Cmd1'
    //   MATLABSystem: '<S60>/Max Phi Cmd10'
    //   MATLABSystem: '<S60>/Max Phi Cmd11'
    //   MATLABSystem: '<S60>/Max Phi Cmd12'
    //   MATLABSystem: '<S60>/Max Phi Cmd13'
    //   MATLABSystem: '<S60>/Max Phi Cmd14'
    //   MATLABSystem: '<S60>/Max Phi Cmd15'
    //   MATLABSystem: '<S60>/Max Phi Cmd16'
    //   MATLABSystem: '<S60>/Max Phi Cmd17'
    //   MATLABSystem: '<S60>/Max Phi Cmd18'
    //   MATLABSystem: '<S60>/Max Phi Cmd19'
    //   MATLABSystem: '<S60>/Max Phi Cmd2'
    //   MATLABSystem: '<S60>/Max Phi Cmd20'
    //   MATLABSystem: '<S60>/Max Phi Cmd21'
    //   MATLABSystem: '<S60>/Max Phi Cmd22'
    //   MATLABSystem: '<S60>/Max Phi Cmd23'
    //   MATLABSystem: '<S60>/Max Phi Cmd24'
    //   MATLABSystem: '<S60>/Max Phi Cmd25'
    //   MATLABSystem: '<S60>/Max Phi Cmd26'
    //   MATLABSystem: '<S60>/Max Phi Cmd27'
    //   MATLABSystem: '<S60>/Max Phi Cmd28'
    //   MATLABSystem: '<S60>/Max Phi Cmd29'
    //   MATLABSystem: '<S60>/Max Phi Cmd3'
    //   MATLABSystem: '<S60>/Max Phi Cmd30'
    //   MATLABSystem: '<S60>/Max Phi Cmd31'
    //   MATLABSystem: '<S60>/Max Phi Cmd4'
    //   MATLABSystem: '<S60>/Max Phi Cmd5'
    //   MATLABSystem: '<S60>/Max Phi Cmd6'
    //   MATLABSystem: '<S60>/Max Phi Cmd7'
    //   MATLABSystem: '<S60>/Max Phi Cmd8'
    //   MATLABSystem: '<S60>/Max Phi Cmd9'
    //   MATLABSystem: '<S62>/Max Phi Cmd1'
    //   MATLABSystem: '<S62>/Max Phi Cmd2'
    //   MATLABSystem: '<S62>/Max Phi Cmd3'
    //   MATLABSystem: '<S62>/Max Phi Cmd5'
    //   MATLABSystem: '<S62>/Max Phi Cmd9'
    //   MATLABSystem: '<S63>/Max Phi Cmd2'
    //   MATLABSystem: '<S63>/Max Phi Cmd3'
    //   MATLABSystem: '<S63>/Max Phi Cmd4'
    //   MATLABSystem: '<S63>/Max Phi Cmd5'
    //   MATLABSystem: '<S63>/Max Phi Cmd9'
    //   MATLABSystem: '<S64>/Max Phi Cmd1'
    //   MATLABSystem: '<S64>/Max Phi Cmd2'
    //   MATLABSystem: '<S64>/Max Phi Cmd3'
    //   MATLABSystem: '<S64>/Max Phi Cmd4'
    //   MATLABSystem: '<S64>/Max Phi Cmd5'
    //   MATLABSystem: '<S64>/Max Phi Cmd9'
    //   MATLABSystem: '<S65>/Max Phi Cmd1'
    //   MATLABSystem: '<S65>/Max Phi Cmd3'
    //   MATLABSystem: '<S65>/Max Phi Cmd9'
    //   MATLABSystem: '<S66>/Max Phi Cmd1'
    //   MATLABSystem: '<S66>/Max Phi Cmd2'
    //   MATLABSystem: '<S66>/Max Phi Cmd3'
    //   MATLABSystem: '<S66>/Max Phi Cmd4'
    //   MATLABSystem: '<S66>/Max Phi Cmd9'
    //   MATLABSystem: '<S67>/Max Phi Cmd1'
    //   MATLABSystem: '<S67>/Max Phi Cmd10'
    //   MATLABSystem: '<S67>/Max Phi Cmd11'
    //   MATLABSystem: '<S67>/Max Phi Cmd12'
    //   MATLABSystem: '<S67>/Max Phi Cmd2'
    //   MATLABSystem: '<S67>/Max Phi Cmd3'
    //   MATLABSystem: '<S67>/Max Phi Cmd4'
    //   MATLABSystem: '<S67>/Max Phi Cmd7'
    //   MATLABSystem: '<S67>/Max Phi Cmd9'
    //   MATLABSystem: '<S68>/Max Phi Cmd1'
    //   MATLABSystem: '<S68>/Max Phi Cmd2'
    //   MATLABSystem: '<S68>/Max Phi Cmd3'
    //   MATLABSystem: '<S69>/Max Phi Cmd1'
    //   MATLABSystem: '<S69>/Max Phi Cmd10'
    //   MATLABSystem: '<S69>/Max Phi Cmd2'
    //   MATLABSystem: '<S69>/Max Phi Cmd3'
    //   MATLABSystem: '<S69>/Max Phi Cmd4'
    //   MATLABSystem: '<S69>/Max Phi Cmd5'
    //   MATLABSystem: '<S69>/Max Phi Cmd6'
    //   MATLABSystem: '<S69>/Max Phi Cmd7'
    //   MATLABSystem: '<S69>/Max Phi Cmd9'
    //   MATLABSystem: '<S70>/Max Phi Cmd1'
    //   MATLABSystem: '<S70>/Max Phi Cmd2'
    //   MATLABSystem: '<S70>/Max Phi Cmd5'
    //   MATLABSystem: '<S70>/Max Phi Cmd9'
    //   SignalConversion generated from: '<S28>/ SFunction '
    //
    memcpy(&RRTV3_PX4_OA_B.EMF_Long[0], &RRTV3_PX4_OA_P.Constant2_Value[0], 99U *
           sizeof(real_T));
    memcpy(&RRTV3_PX4_OA_B.EMF_Lat[0], &RRTV3_PX4_OA_P.Constant1_Value[0], 72U *
           sizeof(real_T));
    memcpy(&RRTV3_PX4_OA_B.EMF_Dir[0], &RRTV3_PX4_OA_P.Constant4_Value[0], 99U *
           sizeof(real_T));
    memcpy(&RRTV3_PX4_OA_B.TCS[0], &RRTV3_PX4_OA_P.Constant3_Value[0], 90U *
           sizeof(real_T));
    memcpy(&RRTV3_PX4_OA_B.LATCS[0], &RRTV3_PX4_OA_P.Constant5_Value[0], 36U *
           sizeof(real_T));
    memcpy(&RRTV3_PX4_OA_B.TC[0], &RRTV3_PX4_OA_P.Constant6_Value[0], 9U *
           sizeof(real_T));
    memcpy(&RRTV3_PX4_OA_B.TCSParameters[0], &RRTV3_PX4_OA_P.Constant20_Value[0],
           35U * sizeof(real_T));
    memcpy(&RRTV3_PX4_OA_B.PIIParameters[0], &RRTV3_PX4_OA_P.Constant21_Value[0],
           67U * sizeof(real_T));
    RRTV3_PX4_OA_B.gimballock = -1;
    RRTV3_PX4_OA_B.i = 0;
    exitg1 = false;
    while ((!exitg1) && (RRTV3_PX4_OA_B.i < 8)) {
      if (RRTV3_PX4_OA_B.phi < RRTV3_PX4_OA_P.Constant_Value_a0[RRTV3_PX4_OA_B.i])
      {
        RRTV3_PX4_OA_B.gimballock = RRTV3_PX4_OA_B.i;
        exitg1 = true;
      } else {
        RRTV3_PX4_OA_B.i++;
      }
    }

    if (RRTV3_PX4_OA_B.gimballock <= 1) {
      RRTV3_PX4_OA_B.i = 1;
    } else {
      RRTV3_PX4_OA_B.i = RRTV3_PX4_OA_B.gimballock;
    }

    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Constant_Value_a0[RRTV3_PX4_OA_B.i -
      1];
    RRTV3_PX4_OA_B.z_HDG = (RRTV3_PX4_OA_B.phi - RRTV3_PX4_OA_B.LatRad) /
      (RRTV3_PX4_OA_P.Constant_Value_a0[RRTV3_PX4_OA_B.gimballock] -
       RRTV3_PX4_OA_B.LatRad);
    if ((RRTV3_PX4_OA_B.z_HDG >= 1.0) || rtIsNaN(RRTV3_PX4_OA_B.z_HDG)) {
      RRTV3_PX4_OA_B.z_HDG = 1.0;
    }

    RRTV3_PX4_OA_B.phi = ((static_cast<real_T>(RRTV3_PX4_OA_B.i - 1) + 1.0) +
                          RRTV3_PX4_OA_B.z_HDG) - (static_cast<real_T>
      (RRTV3_PX4_OA_B.i - 1) + 1.0);
    if (RRTV3_PX4_OA_B.ParamStep_kb >= 1.0F) {
      RRTV3_PX4_OA_B.theta = rt_roundd_snf(RRTV3_PX4_OA_B.ParamStep_kb + 1.0);
      for (RRTV3_PX4_OA_B.LATCS_tmp = 0; RRTV3_PX4_OA_B.LATCS_tmp < 8;
           RRTV3_PX4_OA_B.LATCS_tmp++) {
        RRTV3_PX4_OA_B.EMF_Lat[RRTV3_PX4_OA_B.LATCS_tmp + ((static_cast<int32_T>
          (RRTV3_PX4_OA_B.theta) - 1) << 3)] =
          RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_ht[RRTV3_PX4_OA_B.LATCS_tmp];
      }

      for (RRTV3_PX4_OA_B.LATCS_tmp = 0; RRTV3_PX4_OA_B.LATCS_tmp < 11;
           RRTV3_PX4_OA_B.LATCS_tmp++) {
        RRTV3_PX4_OA_B.EMF_Long_tmp = (static_cast<int32_T>(RRTV3_PX4_OA_B.theta)
          - 1) * 11 + RRTV3_PX4_OA_B.LATCS_tmp;
        RRTV3_PX4_OA_B.EMF_Long[RRTV3_PX4_OA_B.EMF_Long_tmp] =
          RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[RRTV3_PX4_OA_B.LATCS_tmp];
        RRTV3_PX4_OA_B.EMF_Dir[RRTV3_PX4_OA_B.EMF_Long_tmp] =
          RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[RRTV3_PX4_OA_B.LATCS_tmp];
      }

      for (RRTV3_PX4_OA_B.LATCS_tmp = 0; RRTV3_PX4_OA_B.LATCS_tmp < 10;
           RRTV3_PX4_OA_B.LATCS_tmp++) {
        RRTV3_PX4_OA_B.TCS[RRTV3_PX4_OA_B.LATCS_tmp + 10 * (static_cast<int32_T>
          (RRTV3_PX4_OA_B.theta) - 1)] =
          RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[RRTV3_PX4_OA_B.LATCS_tmp];
      }

      RRTV3_PX4_OA_B.LATCS_tmp = (static_cast<int32_T>(RRTV3_PX4_OA_B.theta) - 1)
        << 2;
      RRTV3_PX4_OA_B.LATCS[RRTV3_PX4_OA_B.LATCS_tmp] =
        RRTV3_PX4_OA_B.ParamStep_a;
      RRTV3_PX4_OA_B.LATCS[RRTV3_PX4_OA_B.LATCS_tmp + 1] =
        RRTV3_PX4_OA_B.ParamStep_ju;
      RRTV3_PX4_OA_B.LATCS[RRTV3_PX4_OA_B.LATCS_tmp + 2] =
        RRTV3_PX4_OA_P.Constant_Value_j;
      RRTV3_PX4_OA_B.LATCS[RRTV3_PX4_OA_B.LATCS_tmp + 3] =
        RRTV3_PX4_OA_B.ParamStep_jz5;
      RRTV3_PX4_OA_B.TC[static_cast<int32_T>(RRTV3_PX4_OA_B.theta) - 1] =
        RRTV3_PX4_OA_P.Constant4_Value_j;
    }

    for (RRTV3_PX4_OA_B.LATCS_tmp = 0; RRTV3_PX4_OA_B.LATCS_tmp < 11;
         RRTV3_PX4_OA_B.LATCS_tmp++) {
      RRTV3_PX4_OA_B.theta = RRTV3_PX4_OA_B.EMF_Long[(RRTV3_PX4_OA_B.i - 1) * 11
        + RRTV3_PX4_OA_B.LATCS_tmp];
      RRTV3_PX4_OA_B.EMF_LongGains[RRTV3_PX4_OA_B.LATCS_tmp] =
        (RRTV3_PX4_OA_B.EMF_Long[11 * RRTV3_PX4_OA_B.gimballock +
         RRTV3_PX4_OA_B.LATCS_tmp] - RRTV3_PX4_OA_B.theta) * RRTV3_PX4_OA_B.phi
        + RRTV3_PX4_OA_B.theta;
    }

    for (RRTV3_PX4_OA_B.LATCS_tmp = 0; RRTV3_PX4_OA_B.LATCS_tmp < 8;
         RRTV3_PX4_OA_B.LATCS_tmp++) {
      RRTV3_PX4_OA_B.theta = RRTV3_PX4_OA_B.EMF_Lat[((RRTV3_PX4_OA_B.i - 1) << 3)
        + RRTV3_PX4_OA_B.LATCS_tmp];
      RRTV3_PX4_OA_B.EMF_LatGains[RRTV3_PX4_OA_B.LATCS_tmp] =
        (RRTV3_PX4_OA_B.EMF_Lat[(RRTV3_PX4_OA_B.gimballock << 3) +
         RRTV3_PX4_OA_B.LATCS_tmp] - RRTV3_PX4_OA_B.theta) * RRTV3_PX4_OA_B.phi
        + RRTV3_PX4_OA_B.theta;
    }

    for (RRTV3_PX4_OA_B.LATCS_tmp = 0; RRTV3_PX4_OA_B.LATCS_tmp < 11;
         RRTV3_PX4_OA_B.LATCS_tmp++) {
      RRTV3_PX4_OA_B.theta = RRTV3_PX4_OA_B.EMF_Dir[(RRTV3_PX4_OA_B.i - 1) * 11
        + RRTV3_PX4_OA_B.LATCS_tmp];
      RRTV3_PX4_OA_B.EMF_DirGains[RRTV3_PX4_OA_B.LATCS_tmp] =
        (RRTV3_PX4_OA_B.EMF_Dir[11 * RRTV3_PX4_OA_B.gimballock +
         RRTV3_PX4_OA_B.LATCS_tmp] - RRTV3_PX4_OA_B.theta) * RRTV3_PX4_OA_B.phi
        + RRTV3_PX4_OA_B.theta;
    }

    for (RRTV3_PX4_OA_B.LATCS_tmp = 0; RRTV3_PX4_OA_B.LATCS_tmp < 10;
         RRTV3_PX4_OA_B.LATCS_tmp++) {
      RRTV3_PX4_OA_B.theta = RRTV3_PX4_OA_B.TCS[(RRTV3_PX4_OA_B.i - 1) * 10 +
        RRTV3_PX4_OA_B.LATCS_tmp];
      RRTV3_PX4_OA_B.TCSGains[RRTV3_PX4_OA_B.LATCS_tmp] = (RRTV3_PX4_OA_B.TCS[10
        * RRTV3_PX4_OA_B.gimballock + RRTV3_PX4_OA_B.LATCS_tmp] -
        RRTV3_PX4_OA_B.theta) * RRTV3_PX4_OA_B.phi + RRTV3_PX4_OA_B.theta;
    }

    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_B.TC[RRTV3_PX4_OA_B.i - 1];
    RRTV3_PX4_OA_B.AP_M4 = (RRTV3_PX4_OA_B.TC[RRTV3_PX4_OA_B.gimballock] -
      RRTV3_PX4_OA_B.LatRad) * RRTV3_PX4_OA_B.phi + RRTV3_PX4_OA_B.LatRad;
    RRTV3_PX4_OA_B.i = (RRTV3_PX4_OA_B.i - 1) << 2;
    RRTV3_PX4_OA_B.theta = RRTV3_PX4_OA_B.LATCS[RRTV3_PX4_OA_B.i];
    RRTV3_PX4_OA_B.gimballock <<= 2;
    RRTV3_PX4_OA_B.theta += (RRTV3_PX4_OA_B.LATCS[RRTV3_PX4_OA_B.gimballock] -
      RRTV3_PX4_OA_B.theta) * RRTV3_PX4_OA_B.phi;
    RRTV3_PX4_OA_B.NacParameters[0] = RRTV3_PX4_OA_P.Constant22_Value[0];
    RRTV3_PX4_OA_B.WPINDEX = RRTV3_PX4_OA_B.LATCS[RRTV3_PX4_OA_B.i + 1];
    RRTV3_PX4_OA_B.PIIParameters[44] =
      (RRTV3_PX4_OA_B.LATCS[RRTV3_PX4_OA_B.gimballock + 1] -
       RRTV3_PX4_OA_B.WPINDEX) * RRTV3_PX4_OA_B.phi + RRTV3_PX4_OA_B.WPINDEX;
    RRTV3_PX4_OA_B.NacParameters[1] = RRTV3_PX4_OA_P.Constant22_Value[1];
    RRTV3_PX4_OA_B.WPINDEX = RRTV3_PX4_OA_B.LATCS[RRTV3_PX4_OA_B.i + 2];
    RRTV3_PX4_OA_B.PIIParameters[27] =
      (RRTV3_PX4_OA_B.LATCS[RRTV3_PX4_OA_B.gimballock + 2] -
       RRTV3_PX4_OA_B.WPINDEX) * RRTV3_PX4_OA_B.phi + RRTV3_PX4_OA_B.WPINDEX;
    RRTV3_PX4_OA_B.NacParameters[2] = RRTV3_PX4_OA_P.Constant22_Value[2];
    RRTV3_PX4_OA_B.WPINDEX = RRTV3_PX4_OA_B.LATCS[RRTV3_PX4_OA_B.i + 3];
    RRTV3_PX4_OA_B.PIIParameters[49] =
      (RRTV3_PX4_OA_B.LATCS[RRTV3_PX4_OA_B.gimballock + 3] -
       RRTV3_PX4_OA_B.WPINDEX) * RRTV3_PX4_OA_B.phi + RRTV3_PX4_OA_B.WPINDEX;
    RRTV3_PX4_OA_B.NacParameters[3] = RRTV3_PX4_OA_P.Constant22_Value[3];
    RRTV3_PX4_OA_B.NacParameters[4] = RRTV3_PX4_OA_B.M1_b;
    RRTV3_PX4_OA_B.NacParameters[5] = RRTV3_PX4_OA_B.M2_b;
    if (RRTV3_PX4_OA_B.ParamStep_kb == 0.0F) {
      memcpy(&RRTV3_PX4_OA_B.EMF_LatGains[0],
             &RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_ht[0], sizeof(real_T) <<
             3U);
      memcpy(&RRTV3_PX4_OA_B.EMF_LongGains[0],
             &RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_b1[0], 11U * sizeof(real_T));
      memcpy(&RRTV3_PX4_OA_B.EMF_DirGains[0],
             &RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_mc[0], 11U * sizeof(real_T));
      memcpy(&RRTV3_PX4_OA_B.TCSGains[0],
             &RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[0], 10U * sizeof(real_T));
      RRTV3_PX4_OA_B.theta = RRTV3_PX4_OA_B.ParamStep_a;
      RRTV3_PX4_OA_B.PIIParameters[44] = RRTV3_PX4_OA_B.ParamStep_ju;
      RRTV3_PX4_OA_B.PIIParameters[27] = RRTV3_PX4_OA_P.Constant_Value_j;
      RRTV3_PX4_OA_B.PIIParameters[49] = RRTV3_PX4_OA_B.ParamStep_jz5;
      RRTV3_PX4_OA_B.AP_M4 = RRTV3_PX4_OA_P.Constant4_Value_j;
    }

    if (RRTV3_PX4_OA_B.ParamStep_m0 == 0) {
      RRTV3_PX4_OA_B.TCSParameters[0] = RRTV3_PX4_OA_B.ParamStep_ap;
      RRTV3_PX4_OA_B.TCSParameters[1] = RRTV3_PX4_OA_B.ParamStep_jd;
      RRTV3_PX4_OA_B.TCSParameters[2] = RRTV3_PX4_OA_B.ParamStep_ek;
      RRTV3_PX4_OA_B.TCSParameters[3] = RRTV3_PX4_OA_B.ParamStep_ol;
      RRTV3_PX4_OA_B.TCSParameters[4] = RRTV3_PX4_OA_B.ParamStep_bb;
      RRTV3_PX4_OA_B.TCSParameters[5] = RRTV3_PX4_OA_B.ParamStep_ao;
      RRTV3_PX4_OA_B.TCSParameters[6] = RRTV3_PX4_OA_B.ParamStep_g2;
      RRTV3_PX4_OA_B.TCSParameters[7] = RRTV3_PX4_OA_B.ParamStep_ex;
      RRTV3_PX4_OA_B.TCSParameters[8] = RRTV3_PX4_OA_B.ParamStep_fi;
      RRTV3_PX4_OA_B.TCSParameters[9] = RRTV3_PX4_OA_B.ParamStep_h22;
      RRTV3_PX4_OA_B.TCSParameters[10] = RRTV3_PX4_OA_B.ParamStep_ei;
      RRTV3_PX4_OA_B.TCSParameters[11] = RRTV3_PX4_OA_B.ParamStep_ch;
      RRTV3_PX4_OA_B.TCSParameters[12] = RRTV3_PX4_OA_P.Constant12_Value;
      RRTV3_PX4_OA_B.TCSParameters[13] = RRTV3_PX4_OA_P.Constant13_Value;
      RRTV3_PX4_OA_B.TCSParameters[14] = RRTV3_PX4_OA_P.Constant14_Value;
      RRTV3_PX4_OA_B.TCSParameters[15] = RRTV3_PX4_OA_B.ParamStep_axz;
      RRTV3_PX4_OA_B.TCSParameters[16] = RRTV3_PX4_OA_P.Constant20_Value_p;
      RRTV3_PX4_OA_B.TCSParameters[17] = RRTV3_PX4_OA_B.ParamStep_dau;
      RRTV3_PX4_OA_B.TCSParameters[18] = RRTV3_PX4_OA_B.ParamStep_af2;
      RRTV3_PX4_OA_B.TCSParameters[19] = RRTV3_PX4_OA_B.ParamStep_pb;
      RRTV3_PX4_OA_B.TCSParameters[20] = RRTV3_PX4_OA_B.ParamStep_ms;
      RRTV3_PX4_OA_B.TCSParameters[21] = RRTV3_PX4_OA_B.ParamStep_o3v;
      RRTV3_PX4_OA_B.TCSParameters[22] = RRTV3_PX4_OA_B.ParamStep_nh;
      RRTV3_PX4_OA_B.TCSParameters[23] = RRTV3_PX4_OA_B.ParamStep_lu;
      RRTV3_PX4_OA_B.TCSParameters[24] = RRTV3_PX4_OA_B.ParamStep_pe;
      RRTV3_PX4_OA_B.TCSParameters[25] = RRTV3_PX4_OA_B.ParamStep_pt;
      RRTV3_PX4_OA_B.TCSParameters[26] = RRTV3_PX4_OA_B.ParamStep_ft;
      RRTV3_PX4_OA_B.TCSParameters[27] = RRTV3_PX4_OA_B.ParamStep_ie;
      RRTV3_PX4_OA_B.TCSParameters[28] = RRTV3_PX4_OA_B.ParamStep_ox;
      RRTV3_PX4_OA_B.TCSParameters[29] = RRTV3_PX4_OA_B.ParamStep_kk;
      RRTV3_PX4_OA_B.TCSParameters[30] = RRTV3_PX4_OA_B.ParamStep_ieu;
      RRTV3_PX4_OA_B.TCSParameters[31] = RRTV3_PX4_OA_B.ParamStep_oc;
      RRTV3_PX4_OA_B.TCSParameters[32] = RRTV3_PX4_OA_B.ParamStep_m4;
      RRTV3_PX4_OA_B.TCSParameters[33] = RRTV3_PX4_OA_B.ParamStep_cu;
      RRTV3_PX4_OA_B.TCSParameters[34] = RRTV3_PX4_OA_B.ParamStep_fb;
      RRTV3_PX4_OA_B.PIIParameters[0] = RRTV3_PX4_OA_B.ParamStep_o4;
      RRTV3_PX4_OA_B.PIIParameters[1] = RRTV3_PX4_OA_B.ParamStep_ny;
      RRTV3_PX4_OA_B.PIIParameters[2] = RRTV3_PX4_OA_B.ParamStep_i;
      RRTV3_PX4_OA_B.PIIParameters[3] = RRTV3_PX4_OA_B.ParamStep_oy;
      RRTV3_PX4_OA_B.PIIParameters[4] = RRTV3_PX4_OA_B.ParamStep_nv;
      RRTV3_PX4_OA_B.PIIParameters[5] = RRTV3_PX4_OA_B.ParamStep_m;
      RRTV3_PX4_OA_B.PIIParameters[6] = RRTV3_PX4_OA_P.Constant3_Value_o;
      RRTV3_PX4_OA_B.PIIParameters[7] = RRTV3_PX4_OA_P.Constant2_Value_l;
      RRTV3_PX4_OA_B.PIIParameters[8] = RRTV3_PX4_OA_P.Constant1_Value_o;
      RRTV3_PX4_OA_B.PIIParameters[10] = RRTV3_PX4_OA_B.ParamStep_c;
      RRTV3_PX4_OA_B.PIIParameters[11] = RRTV3_PX4_OA_B.ParamStep_md;
      RRTV3_PX4_OA_B.PIIParameters[12] = RRTV3_PX4_OA_B.ParamStep_m3;
      RRTV3_PX4_OA_B.PIIParameters[13] = RRTV3_PX4_OA_P.Constant3_Value_fu;
      RRTV3_PX4_OA_B.PIIParameters[14] = RRTV3_PX4_OA_B.ParamStep_ja;
      RRTV3_PX4_OA_B.PIIParameters[15] = RRTV3_PX4_OA_B.ParamStep_h5;
      RRTV3_PX4_OA_B.PIIParameters[16] = RRTV3_PX4_OA_B.ParamStep_c0;
      RRTV3_PX4_OA_B.PIIParameters[17] = RRTV3_PX4_OA_P.Constant6_Value_h;
      RRTV3_PX4_OA_B.PIIParameters[18] = RRTV3_PX4_OA_P.Constant2_Value_m;
      RRTV3_PX4_OA_B.PIIParameters[19] = RRTV3_PX4_OA_P.Constant_Value_p0;
      RRTV3_PX4_OA_B.PIIParameters[20] = RRTV3_PX4_OA_P.Constant1_Value_c;
      RRTV3_PX4_OA_B.PIIParameters[21] = RRTV3_PX4_OA_P.Constant4_Value_f;
      RRTV3_PX4_OA_B.PIIParameters[22] = RRTV3_PX4_OA_P.Constant5_Value_l;
      RRTV3_PX4_OA_B.PIIParameters[23] = RRTV3_PX4_OA_B.ParamStep_ct;
      RRTV3_PX4_OA_B.PIIParameters[24] = RRTV3_PX4_OA_B.ParamStep_px;
      RRTV3_PX4_OA_B.PIIParameters[25] = RRTV3_PX4_OA_B.ParamStep_p5;
      RRTV3_PX4_OA_B.PIIParameters[26] = RRTV3_PX4_OA_P.Constant1_Value_h5;
      RRTV3_PX4_OA_B.PIIParameters[28] = RRTV3_PX4_OA_P.Constant2_Value_k;
      RRTV3_PX4_OA_B.PIIParameters[29] = RRTV3_PX4_OA_B.ParamStep_af;
      RRTV3_PX4_OA_B.PIIParameters[30] = RRTV3_PX4_OA_B.ParamStep_ev;
      RRTV3_PX4_OA_B.PIIParameters[31] = RRTV3_PX4_OA_B.ParamStep_ax;
      RRTV3_PX4_OA_B.PIIParameters[32] = RRTV3_PX4_OA_B.ParamStep_as;
      RRTV3_PX4_OA_B.PIIParameters[33] = RRTV3_PX4_OA_B.ParamStep_if;
      RRTV3_PX4_OA_B.PIIParameters[35] = RRTV3_PX4_OA_B.ParamStep_lt;
      RRTV3_PX4_OA_B.PIIParameters[37] = RRTV3_PX4_OA_B.ParamStep_oj;
      RRTV3_PX4_OA_B.PIIParameters[38] = RRTV3_PX4_OA_B.ParamStep_o2;
      RRTV3_PX4_OA_B.PIIParameters[39] = RRTV3_PX4_OA_B.ParamStep_ip;
      RRTV3_PX4_OA_B.PIIParameters[40] = RRTV3_PX4_OA_B.ParamStep_fk;
      RRTV3_PX4_OA_B.PIIParameters[41] = RRTV3_PX4_OA_B.ParamStep_iz;
      RRTV3_PX4_OA_B.PIIParameters[42] = RRTV3_PX4_OA_B.ParamStep_ff;
      RRTV3_PX4_OA_B.PIIParameters[43] = RRTV3_PX4_OA_B.ParamStep_gx;
      RRTV3_PX4_OA_B.PIIParameters[45] = RRTV3_PX4_OA_B.ParamStep_co;
      RRTV3_PX4_OA_B.PIIParameters[46] = RRTV3_PX4_OA_B.ParamStep_o3;
      RRTV3_PX4_OA_B.PIIParameters[47] = RRTV3_PX4_OA_B.ParamStep_lm;
      RRTV3_PX4_OA_B.PIIParameters[48] = RRTV3_PX4_OA_B.ParamStep_mv;
      RRTV3_PX4_OA_B.PIIParameters[50] = RRTV3_PX4_OA_B.ParamStep_mj;
      RRTV3_PX4_OA_B.PIIParameters[51] = RRTV3_PX4_OA_B.ParamStep_cn;
      RRTV3_PX4_OA_B.PIIParameters[52] = RRTV3_PX4_OA_B.ParamStep_fm;
      RRTV3_PX4_OA_B.PIIParameters[53] = RRTV3_PX4_OA_B.ParamStep_p4;
      RRTV3_PX4_OA_B.PIIParameters[54] = RRTV3_PX4_OA_B.ParamStep_e1;
      RRTV3_PX4_OA_B.PIIParameters[55] = RRTV3_PX4_OA_B.ParamStep_o4a;
      RRTV3_PX4_OA_B.PIIParameters[56] = RRTV3_PX4_OA_B.ParamStep_hh;
      RRTV3_PX4_OA_B.PIIParameters[57] = RRTV3_PX4_OA_B.ParamStep_l5;
      RRTV3_PX4_OA_B.PIIParameters[58] = RRTV3_PX4_OA_B.ParamStep_h2;
      RRTV3_PX4_OA_B.PIIParameters[59] = RRTV3_PX4_OA_B.ParamStep_me;
      RRTV3_PX4_OA_B.PIIParameters[60] = RRTV3_PX4_OA_B.ParamStep_mc;
      RRTV3_PX4_OA_B.PIIParameters[61] = RRTV3_PX4_OA_B.ParamStep_h3;
      RRTV3_PX4_OA_B.PIIParameters[62] = RRTV3_PX4_OA_B.ParamStep_cs;
      RRTV3_PX4_OA_B.PIIParameters[63] = RRTV3_PX4_OA_B.ParamStep_k;
      RRTV3_PX4_OA_B.PIIParameters[64] = RRTV3_PX4_OA_B.ParamStep_pc;
      RRTV3_PX4_OA_B.PIIParameters[65] = RRTV3_PX4_OA_B.ParamStep_pxv;
      RRTV3_PX4_OA_B.PIIParameters[66] = RRTV3_PX4_OA_B.ParamStep_p4u;
      RRTV3_PX4_OA_B.NacParameters[0] = RRTV3_PX4_OA_P.Constant4_Value_c;
      RRTV3_PX4_OA_B.NacParameters[1] = RRTV3_PX4_OA_B.ParamStep_hc;
      RRTV3_PX4_OA_B.NacParameters[2] = RRTV3_PX4_OA_B.ParamStep_m44;
      RRTV3_PX4_OA_B.NacParameters[3] = RRTV3_PX4_OA_B.ParamStep_ad;
      RRTV3_PX4_OA_B.NacParameters[4] = RRTV3_PX4_OA_B.NacelleAutomaticFlag_p;
      RRTV3_PX4_OA_B.NacParameters[5] = RRTV3_PX4_OA_B.NacelleManualCmd_c;
    }

    RRTV3_PX4_OA_B.PIIParameters[9] = RRTV3_PX4_OA_B.theta * 0.51444 * 57.3;
    RRTV3_PX4_OA_B.PIIParameters[34] = RRTV3_PX4_OA_B.TCSGains[8] / 9.81;
    RRTV3_PX4_OA_B.PIIParameters[36] = RRTV3_PX4_OA_B.TCSGains[7] * 60.0;

    // DiscreteIntegrator: '<S48>/Integrator' incorporates:
    //   Constant: '<S42>/Constant1'

    if (RRTV3_PX4_OA_DW.Integrator_PrevResetState_i <= 0) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0] = RRTV3_PX4_OA_P.Constant1_Value_l
        [0];
      if (RRTV3_PX4_OA_P.Constant1_Value_l[0] >
          RRTV3_PX4_OA_P.Integrator_UpperSat) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0] =
          RRTV3_PX4_OA_P.Integrator_UpperSat;
      } else if (RRTV3_PX4_OA_P.Constant1_Value_l[0] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0] =
          RRTV3_PX4_OA_P.Integrator_LowerSat;
      }

      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1] = RRTV3_PX4_OA_P.Constant1_Value_l
        [1];
      if (RRTV3_PX4_OA_P.Constant1_Value_l[1] >
          RRTV3_PX4_OA_P.Integrator_UpperSat) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1] =
          RRTV3_PX4_OA_P.Integrator_UpperSat;
      } else if (RRTV3_PX4_OA_P.Constant1_Value_l[1] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1] =
          RRTV3_PX4_OA_P.Integrator_LowerSat;
      }

      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2] = RRTV3_PX4_OA_P.Constant1_Value_l
        [2];
      if (RRTV3_PX4_OA_P.Constant1_Value_l[2] >
          RRTV3_PX4_OA_P.Integrator_UpperSat) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2] =
          RRTV3_PX4_OA_P.Integrator_UpperSat;
      } else if (RRTV3_PX4_OA_P.Constant1_Value_l[2] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2] =
          RRTV3_PX4_OA_P.Integrator_LowerSat;
      }

      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[3] = RRTV3_PX4_OA_P.Constant1_Value_l
        [3];
      if (RRTV3_PX4_OA_P.Constant1_Value_l[3] >
          RRTV3_PX4_OA_P.Integrator_UpperSat) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_h[3] =
          RRTV3_PX4_OA_P.Integrator_UpperSat;
      } else if (RRTV3_PX4_OA_P.Constant1_Value_l[3] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_h[3] =
          RRTV3_PX4_OA_P.Integrator_LowerSat;
      }
    }

    // Saturate: '<S48>/Saturation' incorporates:
    //   DiscreteIntegrator: '<S48>/Integrator'

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1] >
        RRTV3_PX4_OA_P.Saturation_UpperSat) {
      RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Saturation_UpperSat;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1] <
               RRTV3_PX4_OA_P.Saturation_LowerSat) {
      RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Saturation_LowerSat;
    } else {
      RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1];
    }

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2] >
        RRTV3_PX4_OA_P.Saturation_UpperSat) {
      RRTV3_PX4_OA_B.theta = RRTV3_PX4_OA_P.Saturation_UpperSat;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2] <
               RRTV3_PX4_OA_P.Saturation_LowerSat) {
      RRTV3_PX4_OA_B.theta = RRTV3_PX4_OA_P.Saturation_LowerSat;
    } else {
      RRTV3_PX4_OA_B.theta = RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2];
    }

    // MATLAB Function: '<S42>/MATLAB Function1' incorporates:
    //   DataTypeConversion: '<S51>/Data Type Conversion5'
    //   MATLABSystem: '<S51>/Max Phi Cmd12'
    //   Memory: '<S42>/Memory2'
    //   SignalConversion generated from: '<S47>/ SFunction '
    //
    RRTV3_PX4_OA_B.Alt = RRTV3_PX4_OA_B.h2 - RRTV3_PX4_OA_B.ParamStep_nb;
    RRTV3_PX4_OA_B.AP_M3 = RRTV3_PX4_OA_B.zeta * 180.0 / 3.1415926535897931;
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_B.KEAS * 3.1415926535897931 / 180.0;
    RRTV3_PX4_OA_B.LongRad = RRTV3_PX4_OA_B.VFWD_kts * 3.1415926535897931 /
      180.0;
    RRTV3_PX4_OA_B.AP_DXN = RRTV3_PX4_OA_DW.Memory2_PreviousInput_p[0];
    RRTV3_PX4_OA_B.WPINDEX = RRTV3_PX4_OA_DW.Memory2_PreviousInput_p[1];
    RRTV3_PX4_OA_B.HDG = RRTV3_PX4_OA_DW.Memory2_PreviousInput_p[2];
    RRTV3_PX4_OA_B.TRK_target = 0.0;
    RRTV3_PX4_OA_B.AP_LND = 0.0;
    RRTV3_PX4_OA_B.AP_M5 = (rtInf);
    RRTV3_PX4_OA_B.DistToTarget = 0.0;

    // MATLAB Function: '<S13>/MATLAB Function1' incorporates:
    //   MATLAB Function: '<S42>/MATLAB Function1'

    RRTV3_PX4_OA_B.LATSIG[7] = 0.0;

    // MATLAB Function: '<S42>/MATLAB Function1' incorporates:
    //   DataTypeConversion: '<S51>/Data Type Conversion20'
    //   DataTypeConversion: '<S51>/Data Type Conversion7'
    //   MATLABSystem: '<S51>/Max Phi Cmd2'
    //   MATLABSystem: '<S51>/Max Phi Cmd5'
    //   Memory: '<S42>/Memory2'
    //   SignalConversion generated from: '<S47>/ SFunction '
    //
    RRTV3_PX4_OA_B.AP_AXN = 0.0;
    RRTV3_PX4_OA_B.FPA_Target = 0.0;
    RRTV3_PX4_OA_B.z_HDG = cos(RRTV3_PX4_OA_B.LatRad);
    RRTV3_PX4_OA_B.L1 = RRTV3_PX4_OA_B.z_HDG / 6.378137E+6;
    RRTV3_PX4_OA_B.NAVSTATUS = sin(RRTV3_PX4_OA_B.LatRad) / 6.3567523E+6;
    RRTV3_PX4_OA_B.L1 = 1.0 / sqrt(RRTV3_PX4_OA_B.L1 * RRTV3_PX4_OA_B.L1 +
      RRTV3_PX4_OA_B.NAVSTATUS * RRTV3_PX4_OA_B.NAVSTATUS) + RRTV3_PX4_OA_B.h2;
    for (RRTV3_PX4_OA_B.ParamStep_m0 = 0; RRTV3_PX4_OA_B.ParamStep_m0 < 20;
         RRTV3_PX4_OA_B.ParamStep_m0++) {
      RRTV3_PX4_OA_B.SPDCMD = RRTV3_PX4_OA_B.PathDef[RRTV3_PX4_OA_B.ParamStep_m0]
        * 3.1415926535897931 / 180.0;
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[RRTV3_PX4_OA_B.ParamStep_m0] =
        RRTV3_PX4_OA_B.SPDCMD;
      RRTV3_PX4_OA_B.rtb_CastToDouble_j_k =
        RRTV3_PX4_OA_B.PathDef[RRTV3_PX4_OA_B.ParamStep_m0 + 20] *
        3.1415926535897931 / 180.0;
      RRTV3_PX4_OA_B.CastToDouble_j[RRTV3_PX4_OA_B.ParamStep_m0] =
        RRTV3_PX4_OA_B.rtb_CastToDouble_j_k;
      RRTV3_PX4_OA_B.NAVSTATUS = RRTV3_PX4_OA_B.SPDCMD - RRTV3_PX4_OA_B.LatRad;
      RRTV3_PX4_OA_B.SPDCMD = cos((RRTV3_PX4_OA_B.LatRad + RRTV3_PX4_OA_B.SPDCMD)
        / 2.0);
      RRTV3_PX4_OA_B.b_y_c = RRTV3_PX4_OA_B.SPDCMD * RRTV3_PX4_OA_B.SPDCMD;
      RRTV3_PX4_OA_B.b_y[RRTV3_PX4_OA_B.ParamStep_m0] = RRTV3_PX4_OA_B.b_y_c;
      RRTV3_PX4_OA_B.rtb_CastToDouble_j_k -= RRTV3_PX4_OA_B.LongRad;
      RRTV3_PX4_OA_B.TRKPath_b = RRTV3_PX4_OA_B.rtb_CastToDouble_j_k *
        RRTV3_PX4_OA_B.rtb_CastToDouble_j_k;
      RRTV3_PX4_OA_B.TRKPath[RRTV3_PX4_OA_B.ParamStep_m0] =
        RRTV3_PX4_OA_B.TRKPath_b;
      RRTV3_PX4_OA_B.b_y_c = sqrt(RRTV3_PX4_OA_B.NAVSTATUS *
        RRTV3_PX4_OA_B.NAVSTATUS + RRTV3_PX4_OA_B.b_y_c *
        RRTV3_PX4_OA_B.TRKPath_b) * RRTV3_PX4_OA_B.L1;
      RRTV3_PX4_OA_B.DistToPoints[RRTV3_PX4_OA_B.ParamStep_m0] =
        RRTV3_PX4_OA_B.b_y_c;
      RRTV3_PX4_OA_B.FPAToPoints[RRTV3_PX4_OA_B.ParamStep_m0] = rt_atan2d_snf
        (RRTV3_PX4_OA_B.PathDef[RRTV3_PX4_OA_B.ParamStep_m0 + 40] -
         RRTV3_PX4_OA_B.Alt, RRTV3_PX4_OA_B.b_y_c) * 57.295779513082323;
      RRTV3_PX4_OA_B.TRKToPoints[RRTV3_PX4_OA_B.ParamStep_m0] = rt_atan2d_snf
        (RRTV3_PX4_OA_B.rtb_CastToDouble_j_k * RRTV3_PX4_OA_B.SPDCMD,
         RRTV3_PX4_OA_B.NAVSTATUS) * 57.295779513082323;
    }

    RRTV3_PX4_OA_diff(RRTV3_PX4_OA_B.CastToDouble_j, RRTV3_PX4_OA_B.c_x_tmp);
    RRTV3_PX4_OA_diff(RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h,
                      RRTV3_PX4_OA_B.y_tmp);
    RRTV3_PX4_OA_B.TRKPath[0] = RRTV3_PX4_OA_B.TRKToPoints[0];
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_B.z_HDG * RRTV3_PX4_OA_B.z_HDG;
    RRTV3_PX4_OA_B.b_y[0] = RRTV3_PX4_OA_B.DistToPoints[0];
    RRTV3_PX4_OA_diff(&RRTV3_PX4_OA_B.PathDef[40], RRTV3_PX4_OA_B.dv1);
    RRTV3_PX4_OA_B.CastToDouble_j[0] = RRTV3_PX4_OA_B.PathDef[40] -
      RRTV3_PX4_OA_B.Alt;
    for (RRTV3_PX4_OA_B.ParamStep_m0 = 0; RRTV3_PX4_OA_B.ParamStep_m0 < 19;
         RRTV3_PX4_OA_B.ParamStep_m0++) {
      RRTV3_PX4_OA_B.Alt = RRTV3_PX4_OA_B.c_x_tmp[RRTV3_PX4_OA_B.ParamStep_m0];
      RRTV3_PX4_OA_B.LongRad = RRTV3_PX4_OA_B.y_tmp[RRTV3_PX4_OA_B.ParamStep_m0];
      RRTV3_PX4_OA_B.TRKPath[RRTV3_PX4_OA_B.ParamStep_m0 + 1] = rt_atan2d_snf
        (RRTV3_PX4_OA_B.Alt * RRTV3_PX4_OA_B.z_HDG, RRTV3_PX4_OA_B.LongRad) *
        57.295779513082323;
      RRTV3_PX4_OA_B.b_y[RRTV3_PX4_OA_B.ParamStep_m0 + 1] = sqrt
        (RRTV3_PX4_OA_B.Alt * RRTV3_PX4_OA_B.Alt * RRTV3_PX4_OA_B.LatRad +
         RRTV3_PX4_OA_B.LongRad * RRTV3_PX4_OA_B.LongRad) * RRTV3_PX4_OA_B.L1;
      RRTV3_PX4_OA_B.CastToDouble_j[RRTV3_PX4_OA_B.ParamStep_m0 + 1] =
        RRTV3_PX4_OA_B.dv1[RRTV3_PX4_OA_B.ParamStep_m0];
    }

    for (RRTV3_PX4_OA_B.ParamStep_m0 = 0; RRTV3_PX4_OA_B.ParamStep_m0 < 20;
         RRTV3_PX4_OA_B.ParamStep_m0++) {
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[RRTV3_PX4_OA_B.ParamStep_m0] =
        57.295779513082323 * rt_atan2d_snf
        (RRTV3_PX4_OA_B.CastToDouble_j[RRTV3_PX4_OA_B.ParamStep_m0],
         RRTV3_PX4_OA_B.b_y[RRTV3_PX4_OA_B.ParamStep_m0]);
    }

    RRTV3_PX4_OA_B.L1 = 1.4142135623730951 * RRTV3_PX4_OA_B.m / 0.3;
    RRTV3_PX4_OA_B.z_HDG = 1.0 - (RRTV3_PX4_OA_B.m - 3.0) * 0.5;
    if (!(RRTV3_PX4_OA_B.z_HDG <= 1.0)) {
      RRTV3_PX4_OA_B.z_HDG = 1.0;
    }

    if (RRTV3_PX4_OA_B.z_HDG <= 0.0) {
      RRTV3_PX4_OA_B.z_HDG = 0.0;
    }

    if (RRTV3_PX4_OA_DW.Memory2_PreviousInput_p[1] < 2.0) {
      RRTV3_PX4_OA_B.AP_M3 = RRTV3_PX4_OA_B.HDGrad * 180.0 / 3.1415926535897931 *
        RRTV3_PX4_OA_B.z_HDG + (1.0 - RRTV3_PX4_OA_B.z_HDG) *
        RRTV3_PX4_OA_B.AP_M3;
    }

    if (RRTV3_PX4_OA_DW.Memory2_PreviousInput_p[0] == 0.0) {
      RRTV3_PX4_OA_B.AP_DXN = 1.0;
      RRTV3_PX4_OA_B.WPINDEX = 1.0;
    }

    if ((RRTV3_PX4_OA_B.AP_DXN == 1.0) || (RRTV3_PX4_OA_B.WPINDEX == 1.0)) {
      RRTV3_PX4_OA_B.TRKPath[static_cast<int32_T>(RRTV3_PX4_OA_B.WPINDEX) - 1] =
        RRTV3_PX4_OA_B.AP_M3;
    }

    for (RRTV3_PX4_OA_B.ParamStep_m0 = 0; RRTV3_PX4_OA_B.ParamStep_m0 < 20;
         RRTV3_PX4_OA_B.ParamStep_m0++) {
      RRTV3_PX4_OA_B.z_HDG =
        RRTV3_PX4_OA_B.TRKToPoints[RRTV3_PX4_OA_B.ParamStep_m0];
      if (RRTV3_PX4_OA_B.z_HDG < 0.0) {
        RRTV3_PX4_OA_B.TRKToPoints[RRTV3_PX4_OA_B.ParamStep_m0] =
          RRTV3_PX4_OA_B.z_HDG + 360.0;
      }

      RRTV3_PX4_OA_B.TRKPath_b =
        RRTV3_PX4_OA_B.TRKPath[RRTV3_PX4_OA_B.ParamStep_m0];
      if (RRTV3_PX4_OA_B.TRKPath_b < 0.0) {
        RRTV3_PX4_OA_B.TRKPath[RRTV3_PX4_OA_B.ParamStep_m0] =
          RRTV3_PX4_OA_B.TRKPath_b + 360.0;
      }
    }

    if (RRTV3_PX4_OA_B.AP_DXN == 1.0) {
      RRTV3_PX4_OA_B.TRK_target = RRTV3_PX4_OA_B.TRKToPoints[static_cast<int32_T>
        (RRTV3_PX4_OA_B.WPINDEX) - 1];
      RRTV3_PX4_OA_B.DistToTarget = RRTV3_PX4_OA_B.DistToPoints
        [static_cast<int32_T>(RRTV3_PX4_OA_B.WPINDEX) - 1];
      RRTV3_PX4_OA_B.AP_LND = RRTV3_PX4_OA_B.TRK_target - RRTV3_PX4_OA_B.AP_M3;
      if (RRTV3_PX4_OA_B.AP_LND > 180.0) {
        RRTV3_PX4_OA_B.AP_LND -= 360.0;
      }

      if (RRTV3_PX4_OA_B.AP_LND < -180.0) {
        RRTV3_PX4_OA_B.AP_LND += 360.0;
      }

      RRTV3_PX4_OA_B.AP_LND *= 0.5;
      if ((RRTV3_PX4_OA_B.AP_LND <= -30.0) || rtIsNaN(RRTV3_PX4_OA_B.AP_LND)) {
        RRTV3_PX4_OA_B.AP_LND = -30.0;
      }

      if (RRTV3_PX4_OA_B.AP_LND >= 30.0) {
        RRTV3_PX4_OA_B.AP_LND = 30.0;
      }

      if (RRTV3_PX4_OA_B.DistToTarget < RRTV3_PX4_OA_B.ParamStep_ij *
          RRTV3_PX4_OA_B.m) {
        RRTV3_PX4_OA_B.AP_DXN = 2.0;
        if (RRTV3_PX4_OA_B.WPINDEX < RRTV3_PX4_OA_B.PathDef[120]) {
          RRTV3_PX4_OA_B.WPINDEX++;
        }
      }

      if ((RRTV3_PX4_OA_B.DistToTarget < RRTV3_PX4_OA_B.L1) &&
          (RRTV3_PX4_OA_B.PathDef[static_cast<int32_T>(RRTV3_PX4_OA_B.WPINDEX) +
           79] == 2.0)) {
        RRTV3_PX4_OA_B.AP_DXN = 2.0;
        if (RRTV3_PX4_OA_B.WPINDEX < RRTV3_PX4_OA_B.PathDef[120]) {
          RRTV3_PX4_OA_B.WPINDEX++;
        }
      }
    }

    if ((RRTV3_PX4_OA_B.AP_DXN == 2.0) || (RRTV3_PX4_OA_B.AP_DXN == 3.0)) {
      RRTV3_PX4_OA_B.DistToTarget = RRTV3_PX4_OA_B.DistToPoints[static_cast<
        int32_T>(RRTV3_PX4_OA_B.WPINDEX) - 1];
      RRTV3_PX4_OA_B.AP_LND = RRTV3_PX4_OA_B.TRKPath[static_cast<int32_T>
        (RRTV3_PX4_OA_B.WPINDEX) - 1];
      RRTV3_PX4_OA_B.AP_M5 = RRTV3_PX4_OA_B.AP_LND - RRTV3_PX4_OA_B.TRKToPoints[
        static_cast<int32_T>(RRTV3_PX4_OA_B.WPINDEX) - 1];
      RRTV3_PX4_OA_sind(&RRTV3_PX4_OA_B.AP_M5);
      RRTV3_PX4_OA_B.AP_M5 *= RRTV3_PX4_OA_B.DistToTarget;
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_B.AP_M5 / RRTV3_PX4_OA_B.L1;
      if ((RRTV3_PX4_OA_B.z_HDG >= 1.0) || rtIsNaN(RRTV3_PX4_OA_B.z_HDG)) {
        RRTV3_PX4_OA_B.z_HDG = 1.0;
      }

      if (RRTV3_PX4_OA_B.z_HDG <= -1.0) {
        RRTV3_PX4_OA_B.z_HDG = -1.0;
      }

      RRTV3_PX4_OA_B.TRK_target = RRTV3_PX4_OA_B.AP_LND - 57.295779513082323 *
        asin(RRTV3_PX4_OA_B.z_HDG);
      RRTV3_PX4_OA_B.AP_LND = RRTV3_PX4_OA_B.TRK_target - RRTV3_PX4_OA_B.AP_M3;
      if (RRTV3_PX4_OA_B.AP_LND > 180.0) {
        RRTV3_PX4_OA_B.AP_LND -= 360.0;
      }

      if (RRTV3_PX4_OA_B.AP_LND < -180.0) {
        RRTV3_PX4_OA_B.AP_LND += 360.0;
      }

      RRTV3_PX4_OA_sind(&RRTV3_PX4_OA_B.AP_LND);
      RRTV3_PX4_OA_B.AP_LND = atan(RRTV3_PX4_OA_B.m * RRTV3_PX4_OA_B.m * 2.0 /
        (9.81 * RRTV3_PX4_OA_B.L1) * RRTV3_PX4_OA_B.AP_LND) * 57.295779513082323;
      if ((RRTV3_PX4_OA_B.AP_LND <= -30.0) || rtIsNaN(RRTV3_PX4_OA_B.AP_LND)) {
        RRTV3_PX4_OA_B.AP_LND = -30.0;
      }

      if (RRTV3_PX4_OA_B.AP_LND >= 30.0) {
        RRTV3_PX4_OA_B.AP_LND = 30.0;
      }

      if (RRTV3_PX4_OA_B.DistToTarget < RRTV3_PX4_OA_B.ParamStep_ij *
          RRTV3_PX4_OA_B.m) {
        if (RRTV3_PX4_OA_B.WPINDEX < RRTV3_PX4_OA_B.PathDef[120]) {
          RRTV3_PX4_OA_B.WPINDEX++;
        }

        if ((RRTV3_PX4_OA_B.PathDef[static_cast<int32_T>(RRTV3_PX4_OA_B.WPINDEX)
             + 79] == 2.0) && (RRTV3_PX4_OA_B.WPINDEX < RRTV3_PX4_OA_B.PathDef
                               [120])) {
          RRTV3_PX4_OA_B.WPINDEX++;
        }
      }
    }

    RRTV3_PX4_OA_B.Alt = RRTV3_PX4_OA_B.AP_LND;
    RRTV3_PX4_OA_B.AP_M3 = 0.0;
    if (RRTV3_PX4_OA_B.ParamStep_jgs == 0) {
      // Saturate: '<S48>/Saturation' incorporates:
      //   DiscreteIntegrator: '<S48>/Integrator'

      if (RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0] >
          RRTV3_PX4_OA_P.Saturation_UpperSat) {
        RRTV3_PX4_OA_B.AP_M3 = -RRTV3_PX4_OA_P.Saturation_UpperSat;
      } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0] <
                 RRTV3_PX4_OA_P.Saturation_LowerSat) {
        RRTV3_PX4_OA_B.AP_M3 = -RRTV3_PX4_OA_P.Saturation_LowerSat;
      } else {
        RRTV3_PX4_OA_B.AP_M3 = -RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0];
      }

      RRTV3_PX4_OA_B.Alt = 0.0;
      if (fabs(RRTV3_PX4_OA_B.AP_M5) > RRTV3_PX4_OA_B.L1) {
        RRTV3_PX4_OA_minimum(RRTV3_PX4_OA_B.DistToPoints, &RRTV3_PX4_OA_B.AP_DXN,
                             &RRTV3_PX4_OA_B.ParamStep_m0);
        if (RRTV3_PX4_OA_B.WPINDEX != 1.0) {
          RRTV3_PX4_OA_B.WPINDEX = RRTV3_PX4_OA_B.ParamStep_m0;
        }

        RRTV3_PX4_OA_B.AP_DXN = 1.0;
      }
    }

    if ((RRTV3_PX4_OA_B.m < 5.1444) && (RRTV3_PX4_OA_B.AP_LND <= -10.0)) {
      RRTV3_PX4_OA_B.AP_LND = -10.0;
    }

    RRTV3_PX4_OA_B.LongRad = 0.0;
    if (RRTV3_PX4_OA_B.ParamStep_jgs == 1) {
      RRTV3_PX4_OA_B.AP_M5 = RRTV3_PX4_OA_B.PathDef[static_cast<int32_T>
        (RRTV3_PX4_OA_B.WPINDEX) + 99];

      // MATLAB Function: '<S13>/MATLAB Function1'
      RRTV3_PX4_OA_B.LATSIG[7] = RRTV3_PX4_OA_B.AP_M5;
      RRTV3_PX4_OA_B.DistToTarget = RRTV3_PX4_OA_B.DistToPoints
        [static_cast<int32_T>(RRTV3_PX4_OA_B.WPINDEX) - 1];
      RRTV3_PX4_OA_B.AP_AXN = RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_h[
        static_cast<int32_T>(RRTV3_PX4_OA_B.WPINDEX) - 1];
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_B.AP_AXN - RRTV3_PX4_OA_B.FPAToPoints[
        static_cast<int32_T>(RRTV3_PX4_OA_B.WPINDEX) - 1];
      RRTV3_PX4_OA_sind(&RRTV3_PX4_OA_B.z_HDG);
      if ((!(RRTV3_PX4_OA_B.L1 >= RRTV3_PX4_OA_B.ParamStep_chp)) && (!rtIsNaN(
            static_cast<real_T>(RRTV3_PX4_OA_B.ParamStep_chp)))) {
        RRTV3_PX4_OA_B.L1 = RRTV3_PX4_OA_B.ParamStep_chp;
      }

      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_B.DistToTarget * RRTV3_PX4_OA_B.z_HDG /
        RRTV3_PX4_OA_B.L1;
      if ((RRTV3_PX4_OA_B.z_HDG >= 1.0) || rtIsNaN(RRTV3_PX4_OA_B.z_HDG)) {
        RRTV3_PX4_OA_B.z_HDG = 1.0;
      }

      if (RRTV3_PX4_OA_B.z_HDG <= -1.0) {
        RRTV3_PX4_OA_B.z_HDG = -1.0;
      }

      RRTV3_PX4_OA_B.FPA_Target = RRTV3_PX4_OA_B.AP_AXN - 57.295779513082323 *
        asin(RRTV3_PX4_OA_B.z_HDG);
      RRTV3_PX4_OA_B.LongRad = RRTV3_PX4_OA_B.FPA_Target;
      RRTV3_PX4_OA_B.AP_AXN = RRTV3_PX4_OA_B.FPA_Target / 20.0;
      if (RRTV3_PX4_OA_B.AP_M5 == 1.0) {
        RRTV3_PX4_OA_B.LongRad = RRTV3_PX4_OA_B.PathDef[static_cast<int32_T>
          (RRTV3_PX4_OA_B.WPINDEX) + 39];
      }
    }

    RRTV3_PX4_OA_B.L1 = RRTV3_PX4_OA_B.PathDef[static_cast<int32_T>
      (RRTV3_PX4_OA_B.WPINDEX) + 59];
    RRTV3_PX4_OA_B.SPDCMD = RRTV3_PX4_OA_B.L1;
    if (RRTV3_PX4_OA_B.PathDef[static_cast<int32_T>(RRTV3_PX4_OA_B.WPINDEX) + 79]
        == 2.0) {
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_B.L1 * 0.51444;
      RRTV3_PX4_OA_B.AP_M5 = (RRTV3_PX4_OA_B.z_HDG * RRTV3_PX4_OA_B.z_HDG -
        RRTV3_PX4_OA_B.m * RRTV3_PX4_OA_B.m) / (RRTV3_PX4_OA_B.DistToPoints[
        static_cast<int32_T>(RRTV3_PX4_OA_B.WPINDEX) - 1] * 2.0);
      RRTV3_PX4_OA_B.SPDCMD = (RRTV3_PX4_OA_B.z_HDG - (RRTV3_PX4_OA_B.z_HDG -
        RRTV3_PX4_OA_B.m) / RRTV3_PX4_OA_B.AP_M5 * RRTV3_PX4_OA_B.AP_M5) /
        0.51444;
      RRTV3_PX4_OA_B.L1 = RRTV3_PX4_OA_B.AP_M5 / 9.81;
    }

    RRTV3_PX4_OA_B.NAVSTATUS = RRTV3_PX4_OA_B.WPINDEX;
    if (RRTV3_PX4_OA_B.WPINDEX == RRTV3_PX4_OA_B.PathDef[120]) {
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_B.ParamStep_ij * RRTV3_PX4_OA_B.m;
      if ((RRTV3_PX4_OA_B.z_HDG <= 50.0) || rtIsNaN(RRTV3_PX4_OA_B.z_HDG)) {
        RRTV3_PX4_OA_B.z_HDG = 50.0;
      }

      if (RRTV3_PX4_OA_B.DistToPoints[static_cast<int32_T>
          (RRTV3_PX4_OA_B.WPINDEX) - 1] < RRTV3_PX4_OA_B.z_HDG) {
        RRTV3_PX4_OA_B.HDG = 1.0;
      }
    }

    if (RRTV3_PX4_OA_B.HDG == 1.0) {
      RRTV3_PX4_OA_B.NAVSTATUS = 0.0;
      RRTV3_PX4_OA_B.LongRad = 0.0;
      RRTV3_PX4_OA_B.Alt = 0.0;
      RRTV3_PX4_OA_B.L1 = RRTV3_PX4_OA_B.PathDef[static_cast<int32_T>
        (RRTV3_PX4_OA_B.WPINDEX) + 59];
    }

    if ((RRTV3_PX4_OA_B.ParamStep_fo > 0) && (RRTV3_PX4_OA_B.ParamStep_jgs == 0))
    {
      RRTV3_PX4_OA_B.WPINDEX = 1.0;
      RRTV3_PX4_OA_B.NAVSTATUS = 1.0;
      RRTV3_PX4_OA_B.HDG = 0.0;
    }

    RRTV3_PX4_OA_B.AP_M5 = 0.0;
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_B.PathDef[static_cast<int32_T>
      (RRTV3_PX4_OA_B.WPINDEX) + 79];
    if (RRTV3_PX4_OA_B.LatRad == 1.0) {
      RRTV3_PX4_OA_B.AP_M5 = RRTV3_PX4_OA_B.SPDCMD;
    }

    if (RRTV3_PX4_OA_B.LatRad == 2.0) {
      RRTV3_PX4_OA_B.AP_M5 = RRTV3_PX4_OA_B.L1 * 9.81 / 0.51444;
    }

    RRTV3_PX4_OA_B.MiscOP[0] = RRTV3_PX4_OA_B.Alt;
    RRTV3_PX4_OA_B.MiscOP[1] = RRTV3_PX4_OA_B.LongRad;
    RRTV3_PX4_OA_B.MiscOP[2] = RRTV3_PX4_OA_B.L1;
    RRTV3_PX4_OA_B.MiscOP[3] = RRTV3_PX4_OA_B.WPINDEX;
    RRTV3_PX4_OA_B.MiscOP[4] = RRTV3_PX4_OA_B.DistToTarget;
    RRTV3_PX4_OA_B.MiscOP[5] = RRTV3_PX4_OA_B.TRK_target;
    RRTV3_PX4_OA_B.MiscOP[6] = RRTV3_PX4_OA_B.FPA_Target;
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_B.PathDef[static_cast<int32_T>
      (RRTV3_PX4_OA_B.WPINDEX) + 39];
    RRTV3_PX4_OA_B.MiscOP[7] = RRTV3_PX4_OA_B.LatRad;
    RRTV3_PX4_OA_B.MiscOP[8] = RRTV3_PX4_OA_B.NAVSTATUS;
    RRTV3_PX4_OA_B.GUIDANCE[0] = RRTV3_PX4_OA_B.ParamStep_jgs;
    RRTV3_PX4_OA_B.GUIDANCE[1] = RRTV3_PX4_OA_B.phi;
    RRTV3_PX4_OA_B.GUIDANCE[2] = RRTV3_PX4_OA_B.ParamStep_jgs;
    RRTV3_PX4_OA_B.GUIDANCE[3] = RRTV3_PX4_OA_B.theta;
    RRTV3_PX4_OA_B.GUIDANCE[4] = 0.0;
    RRTV3_PX4_OA_B.GUIDANCE[5] = 0.0;

    // DiscreteIntegrator: '<S44>/Integrator' incorporates:
    //   Constant: '<S13>/Constant2'

    if ((RRTV3_PX4_OA_P.Constant2_Value_b != 0.0) ||
        (RRTV3_PX4_OA_DW.Integrator_PrevResetState_k != 0)) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_b = RRTV3_PX4_OA_P.Constant2_Value_b;
      if (RRTV3_PX4_OA_DW.Integrator_DSTATE_b >
          RRTV3_PX4_OA_P.Integrator_UpperSat_l) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_b =
          RRTV3_PX4_OA_P.Integrator_UpperSat_l;
      } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_b <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_h) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_b =
          RRTV3_PX4_OA_P.Integrator_LowerSat_h;
      }
    }

    // End of DiscreteIntegrator: '<S44>/Integrator'

    // DiscreteIntegrator: '<S43>/Integrator' incorporates:
    //   Constant: '<S13>/Constant'

    if (RRTV3_PX4_OA_DW.Integrator_PrevResetState_by <= 0) {
      for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 10; RRTV3_PX4_OA_B.i++) {
        RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.Constant_Value_i[RRTV3_PX4_OA_B.i];
        RRTV3_PX4_OA_DW.Integrator_DSTATE_f[RRTV3_PX4_OA_B.i] =
          RRTV3_PX4_OA_B.z_HDG;
        if (RRTV3_PX4_OA_B.z_HDG > RRTV3_PX4_OA_P.Integrator_UpperSat_p) {
          RRTV3_PX4_OA_DW.Integrator_DSTATE_f[RRTV3_PX4_OA_B.i] =
            RRTV3_PX4_OA_P.Integrator_UpperSat_p;
        } else if (RRTV3_PX4_OA_B.z_HDG < RRTV3_PX4_OA_P.Integrator_LowerSat_m)
        {
          RRTV3_PX4_OA_DW.Integrator_DSTATE_f[RRTV3_PX4_OA_B.i] =
            RRTV3_PX4_OA_P.Integrator_LowerSat_m;
        }
      }
    }

    // Saturate: '<S43>/Saturation'
    for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 10; RRTV3_PX4_OA_B.i++) {
      // DiscreteIntegrator: '<S43>/Integrator'
      RRTV3_PX4_OA_B.z_HDG =
        RRTV3_PX4_OA_DW.Integrator_DSTATE_f[RRTV3_PX4_OA_B.i];
      if (RRTV3_PX4_OA_B.z_HDG > RRTV3_PX4_OA_P.Saturation_UpperSat_f) {
        RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[RRTV3_PX4_OA_B.i] =
          RRTV3_PX4_OA_P.Saturation_UpperSat_f;
      } else if (RRTV3_PX4_OA_B.z_HDG < RRTV3_PX4_OA_P.Saturation_LowerSat_l) {
        RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[RRTV3_PX4_OA_B.i] =
          RRTV3_PX4_OA_P.Saturation_LowerSat_l;
      } else {
        RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[RRTV3_PX4_OA_B.i] =
          RRTV3_PX4_OA_B.z_HDG;
      }
    }

    // End of Saturate: '<S43>/Saturation'

    // SignalConversion generated from: '<S41>/ SFunction ' incorporates:
    //   MATLAB Function: '<S13>/MATLAB Function1'

    RRTV3_PX4_OA_B.DistToPoints[0] = RRTV3_PX4_OA_B.NacelleManualCmd;
    RRTV3_PX4_OA_B.DistToPoints[1] = RRTV3_PX4_OA_B.dver_i;
    RRTV3_PX4_OA_B.DistToPoints[2] = RRTV3_PX4_OA_B.ddir_h;
    RRTV3_PX4_OA_B.DistToPoints[3] = RRTV3_PX4_OA_B.dacc_e;
    RRTV3_PX4_OA_B.DistToPoints[4] = RRTV3_PX4_OA_B.TKO_d;
    RRTV3_PX4_OA_B.DistToPoints[5] = RRTV3_PX4_OA_B.DXN_p;
    RRTV3_PX4_OA_B.DistToPoints[6] = RRTV3_PX4_OA_B.NAV_p;
    RRTV3_PX4_OA_B.DistToPoints[7] = RRTV3_PX4_OA_B.AXN_g;
    RRTV3_PX4_OA_B.DistToPoints[8] = RRTV3_PX4_OA_B.LND_j;
    RRTV3_PX4_OA_B.DistToPoints[9] = RRTV3_PX4_OA_B.M1_b;
    RRTV3_PX4_OA_B.DistToPoints[10] = RRTV3_PX4_OA_B.M2_b;
    RRTV3_PX4_OA_B.DistToPoints[11] = RRTV3_PX4_OA_B.M3_o;
    RRTV3_PX4_OA_B.DistToPoints[12] = RRTV3_PX4_OA_B.M4_h;
    RRTV3_PX4_OA_B.DistToPoints[13] = RRTV3_PX4_OA_B.M5_j;
    RRTV3_PX4_OA_B.DistToPoints[14] = RRTV3_PX4_OA_B.NacelleAutomaticFlag_p;
    RRTV3_PX4_OA_B.DistToPoints[15] = RRTV3_PX4_OA_B.NacelleManualCmd_c;
    RRTV3_PX4_OA_B.DistToPoints[16] = RRTV3_PX4_OA_B.SignalLoss_j;
    RRTV3_PX4_OA_B.DistToPoints[17] = RRTV3_PX4_OA_B.PilotSource_g;
    RRTV3_PX4_OA_B.DistToPoints[18] = RRTV3_PX4_OA_B.u1;
    RRTV3_PX4_OA_B.DistToPoints[19] = RRTV3_PX4_OA_B.AP_TKO;

    // MATLAB Function: '<S13>/MATLAB Function1' incorporates:
    //   MATLAB Function: '<S42>/MATLAB Function1'

    RRTV3_PX4_OA_B.LATSIG[0] = RRTV3_PX4_OA_B.Alt;
    RRTV3_PX4_OA_B.LATSIG[1] = RRTV3_PX4_OA_B.LongRad;
    RRTV3_PX4_OA_B.LATSIG[2] = RRTV3_PX4_OA_B.L1;
    RRTV3_PX4_OA_B.LATSIG[3] = RRTV3_PX4_OA_B.NAVSTATUS;
    RRTV3_PX4_OA_B.LATSIG[4] = RRTV3_PX4_OA_B.PathDef[static_cast<int32_T>
      (RRTV3_PX4_OA_B.WPINDEX) - 1];
    RRTV3_PX4_OA_B.LATSIG[5] = RRTV3_PX4_OA_B.PathDef[static_cast<int32_T>
      (RRTV3_PX4_OA_B.WPINDEX) + 19];
    RRTV3_PX4_OA_B.LATSIG[6] = RRTV3_PX4_OA_B.DistToTarget;
    RRTV3_PX4_OA_B.LATSIG[8] = RRTV3_PX4_OA_B.LatRad;

    // SignalConversion generated from: '<S41>/ SFunction ' incorporates:
    //   MATLAB Function: '<S13>/MATLAB Function1'

    RRTV3_PX4_OA_B.rtb_phirad_m[0] = RRTV3_PX4_OA_B.AP_M2;
    RRTV3_PX4_OA_B.rtb_phirad_m[1] = RRTV3_PX4_OA_B.AP_M1;
    RRTV3_PX4_OA_B.rtb_phirad_m[2] = RRTV3_PX4_OA_B.HDGrad;
    RRTV3_PX4_OA_B.rtb_phirad_m[3] = RRTV3_PX4_OA_B.AP_NAV;
    RRTV3_PX4_OA_B.rtb_phirad_m[4] = RRTV3_PX4_OA_B.VCSkt;
    RRTV3_PX4_OA_B.rtb_phirad_m[5] = RRTV3_PX4_OA_B.psi;
    RRTV3_PX4_OA_B.rtb_phirad_m[6] = RRTV3_PX4_OA_B.ayms2;
    RRTV3_PX4_OA_B.rtb_phirad_m[7] = RRTV3_PX4_OA_B.KEAS;
    RRTV3_PX4_OA_B.rtb_phirad_m[8] = RRTV3_PX4_OA_B.VFWD_kts;
    RRTV3_PX4_OA_B.rtb_phirad_m[9] = RRTV3_PX4_OA_B.h_LiDAR;
    RRTV3_PX4_OA_B.rtb_phirad_m[10] = RRTV3_PX4_OA_B.h2;
    RRTV3_PX4_OA_B.rtb_phirad_m[11] = RRTV3_PX4_OA_B.zeta;
    RRTV3_PX4_OA_B.rtb_phirad_m[12] = RRTV3_PX4_OA_B.ParamStep_fo;

    // Saturate: '<S44>/Saturation'
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_b >
        RRTV3_PX4_OA_P.Saturation_UpperSat_b) {
      RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_UpperSat_b;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_b <
               RRTV3_PX4_OA_P.Saturation_LowerSat_n) {
      RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_LowerSat_n;
    } else {
      RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_DW.Integrator_DSTATE_b;
    }

    // Memory: '<S13>/Memory1'
    memcpy(&RRTV3_PX4_OA_B.dv[0], &RRTV3_PX4_OA_DW.Memory1_PreviousInput[0], 22U
           * sizeof(real_T));

    // MATLAB Function: '<S13>/MATLAB Function1' incorporates:
    //   Memory: '<S13>/Memory1'
    //   Saturate: '<S44>/Saturation'

    RRTV3_PX4_OA_AUTOFLIGHT(RRTV3_PX4_OA_B.PIIParameters,
      RRTV3_PX4_OA_B.DistToPoints, RRTV3_PX4_OA_B.LATSIG,
      RRTV3_PX4_OA_B.rtb_phirad_m, RRTV3_PX4_OA_B.LatRad, RRTV3_PX4_OA_B.dv,
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4, RRTV3_PX4_OA_B.AUTOFLIGHT_CMDS,
      RRTV3_PX4_OA_DW.Memory2_PreviousInput,
      RRTV3_PX4_OA_DW.Memory1_PreviousInput);

    // SignalConversion generated from: '<S40>/ SFunction ' incorporates:
    //   MATLAB Function: '<S13>/MATLAB Function'
    //   MATLAB Function: '<S13>/MATLAB Function1'
    //   SignalConversion generated from: '<S41>/ SFunction '

    RRTV3_PX4_OA_B.rtb_phirad_m[0] = RRTV3_PX4_OA_B.AP_M2;
    RRTV3_PX4_OA_B.rtb_phirad_m[1] = RRTV3_PX4_OA_B.AP_M1;
    RRTV3_PX4_OA_B.rtb_phirad_m[2] = RRTV3_PX4_OA_B.HDGrad;
    RRTV3_PX4_OA_B.rtb_phirad_m[3] = RRTV3_PX4_OA_B.AP_NAV;
    RRTV3_PX4_OA_B.rtb_phirad_m[4] = RRTV3_PX4_OA_B.VCSkt;
    RRTV3_PX4_OA_B.rtb_phirad_m[5] = RRTV3_PX4_OA_B.psi;
    RRTV3_PX4_OA_B.rtb_phirad_m[6] = RRTV3_PX4_OA_B.ayms2;
    RRTV3_PX4_OA_B.rtb_phirad_m[7] = RRTV3_PX4_OA_B.KEAS;
    RRTV3_PX4_OA_B.rtb_phirad_m[8] = RRTV3_PX4_OA_B.VFWD_kts;
    RRTV3_PX4_OA_B.rtb_phirad_m[9] = RRTV3_PX4_OA_B.h_LiDAR;
    RRTV3_PX4_OA_B.rtb_phirad_m[10] = RRTV3_PX4_OA_B.h2;
    RRTV3_PX4_OA_B.rtb_phirad_m[11] = RRTV3_PX4_OA_B.zeta;
    RRTV3_PX4_OA_B.rtb_phirad_m[12] = RRTV3_PX4_OA_B.ParamStep_fo;

    // Memory: '<S13>/Memory'
    memcpy(&RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_ht[0],
           &RRTV3_PX4_OA_DW.Memory_PreviousInput[0], sizeof(real_T) << 3U);

    // MATLAB Function: '<S13>/MATLAB Function' incorporates:
    //   MATLAB Function: '<S9>/GAIN SCHEDULER'
    //   SignalConversion generated from: '<S28>/ SFunction '

    RRTV3_PX4_ProcessInceptorInputs(RRTV3_PX4_OA_B.PIIParameters,
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_a, RRTV3_PX4_OA_B.rtb_phirad_m,
      RRTV3_PX4_OA_B.AUTOFLIGHT_CMDS, RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4,
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_ht,
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFunct, &RRTV3_PX4_OA_B.TKO_d,
      &RRTV3_PX4_OA_B.DXN_p, &RRTV3_PX4_OA_B.NAV_p, &RRTV3_PX4_OA_B.AXN_g,
      &RRTV3_PX4_OA_B.LND_j, RRTV3_PX4_OA_B.TBI_b,
      RRTV3_PX4_OA_DW.Memory_PreviousInput);
    if (RRTV3_PX4_OA_B.Control_Level <= 1) {
      RRTV3_PX4_OA_B.AXN_g = RRTV3_PX4_OA_B.NacelleManualCmd;
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFunct[0] = RRTV3_PX4_OA_B.dver_i;
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFunct[1] = 0.0;
      RRTV3_PX4_OA_B.LND_j = RRTV3_PX4_OA_B.ddir_h;
      RRTV3_PX4_OA_B.TKO_d = RRTV3_PX4_OA_B.dacc_e;
    }

    if (RRTV3_PX4_OA_B.Control_Level == 2) {
      RRTV3_PX4_OA_B.AXN_g = RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[0] *
        RRTV3_PX4_OA_B.PIIParameters[4];
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFunct[0] =
        RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[1] *
        RRTV3_PX4_OA_B.PIIParameters[17];
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFunct[1] = 0.0;
      RRTV3_PX4_OA_B.LND_j = RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[2] *
        RRTV3_PX4_OA_B.PIIParameters[25];
      RRTV3_PX4_OA_B.TKO_d = RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4[3];
    }

    RRTV3_PX4_OA_B.PII_collect[0] = RRTV3_PX4_OA_B.TmpSignalConversionAtSFunct[0];
    RRTV3_PX4_OA_B.PII_collect[1] = RRTV3_PX4_OA_B.TKO_d;
    RRTV3_PX4_OA_B.PII_collect[2] = RRTV3_PX4_OA_B.DXN_p;
    RRTV3_PX4_OA_B.PII_collect[3] = RRTV3_PX4_OA_B.AXN_g;
    RRTV3_PX4_OA_B.PII_collect[4] = RRTV3_PX4_OA_B.LND_j;
    RRTV3_PX4_OA_B.PII_collect[5] = RRTV3_PX4_OA_DW.Memory_PreviousInput[0];
    RRTV3_PX4_OA_B.PII_collect[6] = RRTV3_PX4_OA_DW.Memory_PreviousInput[1];
    RRTV3_PX4_OA_B.PII_collect[7] = RRTV3_PX4_OA_DW.Memory_PreviousInput[2];
    RRTV3_PX4_OA_B.PII_collect[8] = RRTV3_PX4_OA_DW.Memory_PreviousInput[3];
    RRTV3_PX4_OA_B.PII_collect[9] = RRTV3_PX4_OA_DW.Memory_PreviousInput[6];
    RRTV3_PX4_OA_B.PII_collect[10] = RRTV3_PX4_OA_DW.Memory_PreviousInput[7];
    RRTV3_PX4_OA_B.PII_collect[11] = RRTV3_PX4_OA_B.TBI_b[8];
    RRTV3_PX4_OA_B.PII_collect[12] = RRTV3_PX4_OA_B.TBI_b[9];
    RRTV3_PX4_OA_B.PII_collect[13] = RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4
      [0];
    RRTV3_PX4_OA_B.PII_collect[14] = RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4
      [1];
    RRTV3_PX4_OA_B.PII_collect[15] = RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4
      [2];
    RRTV3_PX4_OA_B.PII_collect[16] = RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_j4
      [3];

    // Gain: '<S8>/Gain' incorporates:
    //   MATLAB Function: '<S13>/MATLAB Function'

    RRTV3_PX4_OA_B.dacc_e = RRTV3_PX4_OA_P.Gain_Gain * RRTV3_PX4_OA_B.AXN_g;

    // DiscreteIntegrator: '<S24>/Integrator' incorporates:
    //   Constant: '<S8>/Constant'

    if (RRTV3_PX4_OA_DW.Integrator_PrevResetState_m <= 0) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0] = RRTV3_PX4_OA_P.Constant_Value_lz
        [0];
      if (RRTV3_PX4_OA_P.Constant_Value_lz[0] >
          RRTV3_PX4_OA_P.Integrator_UpperSat_g) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_g;
      } else if (RRTV3_PX4_OA_P.Constant_Value_lz[0] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_l) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_l;
      }

      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1] = RRTV3_PX4_OA_P.Constant_Value_lz
        [1];
      if (RRTV3_PX4_OA_P.Constant_Value_lz[1] >
          RRTV3_PX4_OA_P.Integrator_UpperSat_g) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_g;
      } else if (RRTV3_PX4_OA_P.Constant_Value_lz[1] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_l) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_l;
      }

      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2] = RRTV3_PX4_OA_P.Constant_Value_lz
        [2];
      if (RRTV3_PX4_OA_P.Constant_Value_lz[2] >
          RRTV3_PX4_OA_P.Integrator_UpperSat_g) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_g;
      } else if (RRTV3_PX4_OA_P.Constant_Value_lz[2] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_l) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_l;
      }
    }

    // Saturate: '<S24>/Saturation' incorporates:
    //   DiscreteIntegrator: '<S24>/Integrator'

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0] >
        RRTV3_PX4_OA_P.Saturation_UpperSat_n) {
      RRTV3_PX4_OA_B.NacelleManualCmd = RRTV3_PX4_OA_P.Saturation_UpperSat_n;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0] <
               RRTV3_PX4_OA_P.Saturation_LowerSat_m) {
      RRTV3_PX4_OA_B.NacelleManualCmd = RRTV3_PX4_OA_P.Saturation_LowerSat_m;
    } else {
      RRTV3_PX4_OA_B.NacelleManualCmd = RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0];
    }

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1] >
        RRTV3_PX4_OA_P.Saturation_UpperSat_n) {
      RRTV3_PX4_OA_B.NAV_p = RRTV3_PX4_OA_P.Saturation_UpperSat_n;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1] <
               RRTV3_PX4_OA_P.Saturation_LowerSat_m) {
      RRTV3_PX4_OA_B.NAV_p = RRTV3_PX4_OA_P.Saturation_LowerSat_m;
    } else {
      RRTV3_PX4_OA_B.NAV_p = RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1];
    }

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2] >
        RRTV3_PX4_OA_P.Saturation_UpperSat_n) {
      RRTV3_PX4_OA_B.M1_b = RRTV3_PX4_OA_P.Saturation_UpperSat_n;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2] <
               RRTV3_PX4_OA_P.Saturation_LowerSat_m) {
      RRTV3_PX4_OA_B.M1_b = RRTV3_PX4_OA_P.Saturation_LowerSat_m;
    } else {
      RRTV3_PX4_OA_B.M1_b = RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2];
    }

    // End of Saturate: '<S24>/Saturation'

    // MATLAB Function: '<S8>/fcn_EMF_Lat' incorporates:
    //   DataTypeConversion: '<S96>/Data Type Conversion7'
    //   Delay: '<S8>/Delay2'
    //   Gain: '<S93>/Gain'
    //   Memory: '<S8>/Memory7'
    //   SignalConversion generated from: '<S22>/ SFunction '

    RRTV3_PX4_OA_B.ddir_h = (RRTV3_PX4_OA_B.dacc_e * 3.1415926535897931 / 180.0
      - RRTV3_PX4_OA_B.NAV_p) * (RRTV3_PX4_OA_B.EMF_LatGains[0] *
      RRTV3_PX4_OA_B.EMF_LatGains[0]) - 2.0 * RRTV3_PX4_OA_B.EMF_LatGains[1] *
      RRTV3_PX4_OA_B.EMF_LatGains[0] * RRTV3_PX4_OA_B.NacelleManualCmd;
    RRTV3_PX4_OA_B.M2_b = RRTV3_PX4_OA_DW.Delay2_DSTATE[1] -
      RRTV3_PX4_OA_B.AP_M2;
    RRTV3_PX4_OA_B.dver_i = RRTV3_PX4_OA_B.EMF_LatGains[7] * RRTV3_PX4_OA_B.M2_b;
    if (RRTV3_PX4_OA_B.EMF_LatGains[4] <= 0.25) {
      RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_B.EMF_LatGains[4];
    } else {
      RRTV3_PX4_OA_B.LatRad = 0.25;
    }

    if (RRTV3_PX4_OA_B.LatRad <= -0.25) {
      RRTV3_PX4_OA_B.LatRad = -0.25;
    }

    RRTV3_PX4_OA_B.ulat = ((((RRTV3_PX4_OA_DW.Delay2_DSTATE[0] -
      RRTV3_PX4_OA_P.Gain_Gain_m * RRTV3_PX4_OA_B.In1_n.xyz[0]) *
      RRTV3_PX4_OA_B.EMF_LatGains[5] + RRTV3_PX4_OA_B.EMF_LatGains[6] *
      RRTV3_PX4_OA_B.M2_b) + RRTV3_PX4_OA_B.M1_b) + (RRTV3_PX4_OA_B.ddir_h -
      RRTV3_PX4_OA_B.NacelleManualCmd * RRTV3_PX4_OA_B.EMF_LatGains[2]) /
      RRTV3_PX4_OA_B.EMF_LatGains[3]) + 0.0 * RRTV3_PX4_OA_B.LatRad *
      RRTV3_PX4_OA_DW.Memory7_PreviousInput;
    if ((RRTV3_PX4_OA_B.ulat >= 1.0) || rtIsNaN(RRTV3_PX4_OA_B.ulat)) {
      RRTV3_PX4_OA_B.ulat = 1.0;
    }

    if (RRTV3_PX4_OA_B.ulat <= -1.0) {
      RRTV3_PX4_OA_B.ulat = -1.0;
    }

    if ((RRTV3_PX4_OA_B.ulat >= 1.0) && ((RRTV3_PX4_OA_B.dver_i >= 0.0) ||
         rtIsNaN(RRTV3_PX4_OA_B.dver_i))) {
      RRTV3_PX4_OA_B.dver_i = 0.0;
    }

    if ((RRTV3_PX4_OA_B.ulat <= -1.0) && ((RRTV3_PX4_OA_B.dver_i <= 0.0) ||
         rtIsNaN(RRTV3_PX4_OA_B.dver_i))) {
      RRTV3_PX4_OA_B.dver_i = 0.0;
    }

    RRTV3_PX4_OA_DW.Delay2_DSTATE[0] = RRTV3_PX4_OA_B.NacelleManualCmd;
    RRTV3_PX4_OA_DW.Delay2_DSTATE[1] = RRTV3_PX4_OA_B.NAV_p;
    if (RRTV3_PX4_OA_B.ParamStep_fo > 0) {
      RRTV3_PX4_OA_B.ddir_h = -RRTV3_PX4_OA_B.NacelleManualCmd;
      RRTV3_PX4_OA_B.NacelleManualCmd = -RRTV3_PX4_OA_B.NAV_p;
      RRTV3_PX4_OA_B.dver_i = -RRTV3_PX4_OA_B.M1_b;
    }

    if (RRTV3_PX4_OA_B.Control_Level < 2) {
      RRTV3_PX4_OA_B.ulat = RRTV3_PX4_OA_B.dacc_e;
    }

    // End of MATLAB Function: '<S8>/fcn_EMF_Lat'

    // DiscreteIntegrator: '<S36>/Integrator' incorporates:
    //   Constant: '<S12>/Constant2'

    if (RRTV3_PX4_OA_DW.Integrator_PrevResetState_h <= 0) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_g = RRTV3_PX4_OA_P.Constant2_Value_e;
      if (RRTV3_PX4_OA_DW.Integrator_DSTATE_g >
          RRTV3_PX4_OA_P.Integrator_UpperSat_pu) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_g =
          RRTV3_PX4_OA_P.Integrator_UpperSat_pu;
      } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_g <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_i) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_g =
          RRTV3_PX4_OA_P.Integrator_LowerSat_i;
      }
    }

    // End of DiscreteIntegrator: '<S36>/Integrator'

    // SignalConversion generated from: '<S33>/ SFunction ' incorporates:
    //   MATLAB Function: '<S12>/MATLAB Function'
    //   MATLAB Function: '<S12>/OBSTACLE AVOIDANCE'

    RRTV3_PX4_OA_B.dv2[5] = 0.0;

    // MATLAB Function: '<S12>/OBSTACLE AVOIDANCE'
    RRTV3_PX4_OA_B.ParamStep_jgs = 0;
    if ((RRTV3_PX4_OA_DW.Memory2_PreviousInput[2] == 1.0) && (RRTV3_PX4_OA_B.u1 ==
         1.0) && (RRTV3_PX4_OA_B.MiscOP[3] == 2.0) && (RRTV3_PX4_OA_B.MiscOP[4] <
         190.0)) {
      // Saturate: '<S36>/Saturation'
      if (RRTV3_PX4_OA_DW.Integrator_DSTATE_g >
          RRTV3_PX4_OA_P.Saturation_UpperSat_g) {
        RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_UpperSat_g;
      } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_g <
                 RRTV3_PX4_OA_P.Saturation_LowerSat_b) {
        RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_LowerSat_b;
      } else {
        RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_DW.Integrator_DSTATE_g;
      }

      // End of Saturate: '<S36>/Saturation'
      if (RRTV3_PX4_OA_B.LatRad < 3.0) {
        // SignalConversion generated from: '<S33>/ SFunction ' incorporates:
        //   MATLAB Function: '<S12>/MATLAB Function'
        //   Memory: '<S12>/Memory1'

        RRTV3_PX4_OA_B.dv2[5] = RRTV3_PX4_OA_DW.Memory1_PreviousInput_a + 10.0;
        RRTV3_PX4_OA_B.ParamStep_jgs = 1;
      } else {
        RRTV3_PX4_OA_DW.Memory1_PreviousInput_a = RRTV3_PX4_OA_B.AP_M1 * 180.0 /
          3.1415926535897931;
      }
    } else {
      RRTV3_PX4_OA_DW.Memory1_PreviousInput_a = RRTV3_PX4_OA_B.AP_M1 * 180.0 /
        3.1415926535897931;
    }

    // DiscreteIntegrator: '<S35>/Integrator' incorporates:
    //   Constant: '<S12>/Constant1'

    if (RRTV3_PX4_OA_DW.Integrator_PrevResetState_hc <= 0) {
      for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 5; RRTV3_PX4_OA_B.i++) {
        RRTV3_PX4_OA_B.NAV_p = RRTV3_PX4_OA_P.Constant1_Value_n[RRTV3_PX4_OA_B.i];
        RRTV3_PX4_OA_DW.Integrator_DSTATE_m[RRTV3_PX4_OA_B.i] =
          RRTV3_PX4_OA_B.NAV_p;

        // DiscreteIntegrator: '<S35>/Integrator' incorporates:
        //   Constant: '<S12>/Constant1'

        RRTV3_PX4_OA_B.M1_b =
          RRTV3_PX4_OA_P.Integrator_UpperSat_o[RRTV3_PX4_OA_B.i];
        if (RRTV3_PX4_OA_B.NAV_p > RRTV3_PX4_OA_B.M1_b) {
          RRTV3_PX4_OA_DW.Integrator_DSTATE_m[RRTV3_PX4_OA_B.i] =
            RRTV3_PX4_OA_B.M1_b;
        } else {
          RRTV3_PX4_OA_B.M1_b =
            RRTV3_PX4_OA_P.Integrator_LowerSat_a[RRTV3_PX4_OA_B.i];
          if (RRTV3_PX4_OA_B.NAV_p < RRTV3_PX4_OA_B.M1_b) {
            RRTV3_PX4_OA_DW.Integrator_DSTATE_m[RRTV3_PX4_OA_B.i] =
              RRTV3_PX4_OA_B.M1_b;
          }
        }
      }
    }

    for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 5; RRTV3_PX4_OA_B.i++) {
      // SignalConversion generated from: '<S33>/ SFunction ' incorporates:
      //   Constant: '<S12>/Constant'
      //   MATLAB Function: '<S12>/MATLAB Function'

      RRTV3_PX4_OA_B.dv2[RRTV3_PX4_OA_B.i] =
        RRTV3_PX4_OA_P.Constant_Value_p[RRTV3_PX4_OA_B.i];

      // DiscreteIntegrator: '<S35>/Integrator'
      RRTV3_PX4_OA_B.z_HDG =
        RRTV3_PX4_OA_DW.Integrator_DSTATE_m[RRTV3_PX4_OA_B.i];

      // Saturate: '<S35>/Saturation' incorporates:
      //   DiscreteIntegrator: '<S35>/Integrator'

      if (RRTV3_PX4_OA_B.z_HDG > RRTV3_PX4_OA_P.Saturation_UpperSat_fv) {
        RRTV3_PX4_OA_B.dv3[RRTV3_PX4_OA_B.i] =
          RRTV3_PX4_OA_P.Saturation_UpperSat_fv;
      } else if (RRTV3_PX4_OA_B.z_HDG < RRTV3_PX4_OA_P.Saturation_LowerSat_j) {
        RRTV3_PX4_OA_B.dv3[RRTV3_PX4_OA_B.i] =
          RRTV3_PX4_OA_P.Saturation_LowerSat_j;
      } else {
        RRTV3_PX4_OA_B.dv3[RRTV3_PX4_OA_B.i] = RRTV3_PX4_OA_B.z_HDG;
      }

      // End of Saturate: '<S35>/Saturation'
    }

    // SignalConversion generated from: '<S33>/ SFunction ' incorporates:
    //   MATLAB Function: '<S12>/MATLAB Function'
    //   MATLAB Function: '<S13>/MATLAB Function'
    //   MATLAB Function: '<S13>/MATLAB Function1'
    //   SignalConversion generated from: '<S41>/ SFunction '

    RRTV3_PX4_OA_B.rtb_VVms_c[0] = RRTV3_PX4_OA_B.h_LiDAR;
    RRTV3_PX4_OA_B.rtb_VVms_c[1] = RRTV3_PX4_OA_B.h_Pix;
    RRTV3_PX4_OA_B.rtb_VVms_c[2] = RRTV3_PX4_OA_B.VCSkt;
    RRTV3_PX4_OA_B.rtb_VVms_c[3] = RRTV3_PX4_OA_B.ParamStep_fo;
    RRTV3_PX4_OA_B.rtb_VVms_c[4] = RRTV3_PX4_OA_B.AXN_g;

    // Memory: '<S12>/Memory'
    for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 2; RRTV3_PX4_OA_B.i++) {
      RRTV3_PX4_OA_B.dv4[RRTV3_PX4_OA_B.i] =
        RRTV3_PX4_OA_DW.Memory_PreviousInput_l[RRTV3_PX4_OA_B.i];
    }

    // End of Memory: '<S12>/Memory'

    // MATLAB Function: '<S12>/MATLAB Function' incorporates:
    //   MATLAB Function: '<S13>/MATLAB Function'

    RRTV3_PX4_OA_TCS_RRTV(RRTV3_PX4_OA_B.TKO_d,
                          RRTV3_PX4_OA_B.TmpSignalConversionAtSFunct,
                          RRTV3_PX4_OA_B.DXN_p, RRTV3_PX4_OA_B.TCSGains,
                          RRTV3_PX4_OA_B.TCSParameters,
                          RRTV3_PX4_OA_B.NacParameters, RRTV3_PX4_OA_B.dv2,
                          RRTV3_PX4_OA_B.dv3, RRTV3_PX4_OA_B.dv4,
                          RRTV3_PX4_OA_B.rtb_VVms_c, &RRTV3_PX4_OA_B.u1,
                          &RRTV3_PX4_OA_B.M1_b, &RRTV3_PX4_OA_B.NAV_p,
                          &RRTV3_PX4_OA_B.dacc_e,
                          RRTV3_PX4_OA_B.TmpSignalConversionAtSFun_c,
                          RRTV3_PX4_OA_B.TBI_ir,
                          RRTV3_PX4_OA_DW.Memory_PreviousInput_l);
    if (RRTV3_PX4_OA_B.Control_Level == 1) {
      RRTV3_PX4_OA_B.M1_b = RRTV3_PX4_OA_B.TKO_d;
      RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_B.TmpSignalConversionAtSFunct[0];
      RRTV3_PX4_OA_B.TBI_ir[0] = 0.0;
      RRTV3_PX4_OA_B.TBI_ir[1] = 0.0;
      RRTV3_PX4_OA_B.TBI_ir[2] = 0.0;
      RRTV3_PX4_OA_B.TBI_ir[3] = 0.0;
    }

    if (RRTV3_PX4_OA_B.Control_Level == 2) {
      RRTV3_PX4_OA_B.M1_b = RRTV3_PX4_OA_B.TKO_d + 1.0;
      RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_B.TmpSignalConversionAtSFunct[0];
      RRTV3_PX4_OA_B.TBI_ir[0] = 0.0;
      RRTV3_PX4_OA_B.TBI_ir[1] = 0.0;
      RRTV3_PX4_OA_B.TBI_ir[2] = 0.0;
      RRTV3_PX4_OA_B.TBI_ir[3] = 0.0;
    }

    if (rtIsInf(RRTV3_PX4_OA_B.dacc_e) || rtIsNaN(RRTV3_PX4_OA_B.dacc_e)) {
      RRTV3_PX4_OA_B.M2_b = (rtNaN);
    } else {
      RRTV3_PX4_OA_B.M3_o = RRTV3_PX4_OA_rt_remd_snf(RRTV3_PX4_OA_B.dacc_e,
        360.0);
      RRTV3_PX4_OA_B.M2_b = fabs(RRTV3_PX4_OA_B.M3_o);
      if (RRTV3_PX4_OA_B.M2_b > 180.0) {
        if (RRTV3_PX4_OA_B.M3_o > 0.0) {
          RRTV3_PX4_OA_B.M3_o -= 360.0;
        } else {
          RRTV3_PX4_OA_B.M3_o += 360.0;
        }

        RRTV3_PX4_OA_B.M2_b = fabs(RRTV3_PX4_OA_B.M3_o);
      }

      if (RRTV3_PX4_OA_B.M2_b <= 45.0) {
        RRTV3_PX4_OA_B.M3_o *= 0.017453292519943295;
        n = 0;
      } else if (RRTV3_PX4_OA_B.M2_b <= 135.0) {
        if (RRTV3_PX4_OA_B.M3_o > 0.0) {
          RRTV3_PX4_OA_B.M3_o = (RRTV3_PX4_OA_B.M3_o - 90.0) *
            0.017453292519943295;
          n = 1;
        } else {
          RRTV3_PX4_OA_B.M3_o = (RRTV3_PX4_OA_B.M3_o + 90.0) *
            0.017453292519943295;
          n = -1;
        }
      } else if (RRTV3_PX4_OA_B.M3_o > 0.0) {
        RRTV3_PX4_OA_B.M3_o = (RRTV3_PX4_OA_B.M3_o - 180.0) *
          0.017453292519943295;
        n = 2;
      } else {
        RRTV3_PX4_OA_B.M3_o = (RRTV3_PX4_OA_B.M3_o + 180.0) *
          0.017453292519943295;
        n = -2;
      }

      switch (n) {
       case 0:
        RRTV3_PX4_OA_B.M2_b = sin(RRTV3_PX4_OA_B.M3_o);
        break;

       case 1:
        RRTV3_PX4_OA_B.M2_b = cos(RRTV3_PX4_OA_B.M3_o);
        break;

       case -1:
        RRTV3_PX4_OA_B.M2_b = -cos(RRTV3_PX4_OA_B.M3_o);
        break;

       default:
        RRTV3_PX4_OA_B.M2_b = -sin(RRTV3_PX4_OA_B.M3_o);
        break;
      }
    }

    RRTV3_PX4_OA_cosd(&RRTV3_PX4_OA_B.dacc_e);
    RRTV3_PX4_OA_B.TCS_Out[0] = RRTV3_PX4_OA_B.M1_b;
    RRTV3_PX4_OA_B.TCS_Out[1] = 0.0;
    RRTV3_PX4_OA_B.TCS_Out[2] = RRTV3_PX4_OA_B.NAV_p;
    RRTV3_PX4_OA_B.TCS_Out[3] = RRTV3_PX4_OA_B.u1;
    RRTV3_PX4_OA_B.TCS_Out[4] = RRTV3_PX4_OA_DW.Memory_PreviousInput_l[0];
    RRTV3_PX4_OA_B.TCS_Out[5] = RRTV3_PX4_OA_B.M1_b * RRTV3_PX4_OA_B.dacc_e;
    RRTV3_PX4_OA_B.TCS_Out[6] = RRTV3_PX4_OA_B.M1_b * RRTV3_PX4_OA_B.M2_b;

    // Gain: '<S8>/Gain2' incorporates:
    //   MATLAB Function: '<S12>/MATLAB Function'

    RRTV3_PX4_OA_B.M4_h = RRTV3_PX4_OA_P.Gain2_Gain * RRTV3_PX4_OA_B.u1;

    // DiscreteIntegrator: '<S26>/Integrator' incorporates:
    //   Constant: '<S8>/Constant3'

    if (RRTV3_PX4_OA_DW.Integrator_PrevResetState_n2 <= 0) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0] =
        RRTV3_PX4_OA_P.Constant3_Value_n[0];
      if (RRTV3_PX4_OA_P.Constant3_Value_n[0] >
          RRTV3_PX4_OA_P.Integrator_UpperSat_m) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_m;
      } else if (RRTV3_PX4_OA_P.Constant3_Value_n[0] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_c) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_c;
      }

      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1] =
        RRTV3_PX4_OA_P.Constant3_Value_n[1];
      if (RRTV3_PX4_OA_P.Constant3_Value_n[1] >
          RRTV3_PX4_OA_P.Integrator_UpperSat_m) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_m;
      } else if (RRTV3_PX4_OA_P.Constant3_Value_n[1] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_c) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_c;
      }

      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2] =
        RRTV3_PX4_OA_P.Constant3_Value_n[2];
      if (RRTV3_PX4_OA_P.Constant3_Value_n[2] >
          RRTV3_PX4_OA_P.Integrator_UpperSat_m) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_m;
      } else if (RRTV3_PX4_OA_P.Constant3_Value_n[2] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_c) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_c;
      }

      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3] =
        RRTV3_PX4_OA_P.Constant3_Value_n[3];
      if (RRTV3_PX4_OA_P.Constant3_Value_n[3] >
          RRTV3_PX4_OA_P.Integrator_UpperSat_m) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_m;
      } else if (RRTV3_PX4_OA_P.Constant3_Value_n[3] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_c) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_c;
      }
    }

    // Saturate: '<S26>/Saturation' incorporates:
    //   DiscreteIntegrator: '<S26>/Integrator'

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0] >
        RRTV3_PX4_OA_P.Saturation_UpperSat_bs) {
      RRTV3_PX4_OA_B.DXN_p = RRTV3_PX4_OA_P.Saturation_UpperSat_bs;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0] <
               RRTV3_PX4_OA_P.Saturation_LowerSat_b3) {
      RRTV3_PX4_OA_B.DXN_p = RRTV3_PX4_OA_P.Saturation_LowerSat_b3;
    } else {
      RRTV3_PX4_OA_B.DXN_p = RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0];
    }

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1] >
        RRTV3_PX4_OA_P.Saturation_UpperSat_bs) {
      RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_P.Saturation_UpperSat_bs;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1] <
               RRTV3_PX4_OA_P.Saturation_LowerSat_b3) {
      RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_P.Saturation_LowerSat_b3;
    } else {
      RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1];
    }

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3] >
        RRTV3_PX4_OA_P.Saturation_UpperSat_bs) {
      RRTV3_PX4_OA_B.dacc_e = RRTV3_PX4_OA_P.Saturation_UpperSat_bs;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3] <
               RRTV3_PX4_OA_P.Saturation_LowerSat_b3) {
      RRTV3_PX4_OA_B.dacc_e = RRTV3_PX4_OA_P.Saturation_LowerSat_b3;
    } else {
      RRTV3_PX4_OA_B.dacc_e = RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3];
    }

    // SampleTimeMath: '<S16>/TSamp' incorporates:
    //   Memory: '<S8>/Memory3'
    //
    //  About '<S16>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    RRTV3_PX4_OA_B.TKO_d = RRTV3_PX4_OA_DW.Memory3_PreviousInput *
      RRTV3_PX4_OA_P.TSamp_WtEt;

    // SignalConversion generated from: '<S23>/ SFunction ' incorporates:
    //   MATLAB Function: '<S8>/fcn_EMF_Long'

    memcpy(&RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[0],
           &RRTV3_PX4_OA_B.EMF_LongGains[0], 11U * sizeof(real_T));

    // MATLAB Function: '<S8>/fcn_EMF_Long' incorporates:
    //   Delay: '<S8>/Delay1'
    //   SignalConversion generated from: '<S23>/ SFunction '
    //   Sum: '<S16>/Diff'
    //   UnitDelay: '<S16>/UD'
    //
    //  Block description for '<S16>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S16>/UD':
    //
    //   Store in Global RAM

    RRTV3_PX4_OA_B.M3_o = RRTV3_PX4_OA_B.AP_M2 * 57.295779513082323;
    RRTV3_PX4_OA_DW.Memory3_PreviousInput = (RRTV3_PX4_OA_B.M4_h *
      3.1415926535897931 / 180.0 - RRTV3_PX4_OA_B.u1) *
      (RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[0] *
       RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[0]) - 2.0 *
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[1] *
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[0] * RRTV3_PX4_OA_B.DXN_p;
    RRTV3_PX4_OA_B.AXN_g = (RRTV3_PX4_OA_DW.Memory3_PreviousInput -
      RRTV3_PX4_OA_B.DXN_p * RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[2]) /
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[3];
    RRTV3_PX4_OA_B.AP_M2 = (((2.0 * RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[4]
      * RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[5] *
      RRTV3_PX4_OA_DW.Memory3_PreviousInput + (RRTV3_PX4_OA_B.TKO_d -
      RRTV3_PX4_OA_DW.UD_DSTATE_h)) +
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[5] *
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[5] * RRTV3_PX4_OA_B.DXN_p) -
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[3] /
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[6] * RRTV3_PX4_OA_B.dacc_e) /
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[3];
    if ((RRTV3_PX4_OA_B.dacc_e == 1.0) && (RRTV3_PX4_OA_B.AP_M2 > 0.0)) {
      RRTV3_PX4_OA_B.AP_M2 = 0.0;
    }

    if ((RRTV3_PX4_OA_B.dacc_e == -1.0) && (RRTV3_PX4_OA_B.AP_M2 < 0.0)) {
      RRTV3_PX4_OA_B.AP_M2 = 0.0;
    }

    if (RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[7] == 0.0) {
      RRTV3_PX4_OA_B.AP_M2 = (RRTV3_PX4_OA_B.AXN_g - RRTV3_PX4_OA_B.dacc_e) /
        0.1;
    }

    if (rtIsInf(RRTV3_PX4_OA_B.M3_o) || rtIsNaN(RRTV3_PX4_OA_B.M3_o)) {
      RRTV3_PX4_OA_B.M2_b = (rtNaN);
    } else {
      RRTV3_PX4_OA_B.M3_o = RRTV3_PX4_OA_rt_remd_snf(RRTV3_PX4_OA_B.M3_o, 360.0);
      RRTV3_PX4_OA_B.M2_b = fabs(RRTV3_PX4_OA_B.M3_o);
      if (RRTV3_PX4_OA_B.M2_b > 180.0) {
        if (RRTV3_PX4_OA_B.M3_o > 0.0) {
          RRTV3_PX4_OA_B.M3_o -= 360.0;
        } else {
          RRTV3_PX4_OA_B.M3_o += 360.0;
        }

        RRTV3_PX4_OA_B.M2_b = fabs(RRTV3_PX4_OA_B.M3_o);
      }

      if (RRTV3_PX4_OA_B.M2_b <= 45.0) {
        RRTV3_PX4_OA_B.M3_o *= 0.017453292519943295;
        n = 0;
      } else if (RRTV3_PX4_OA_B.M2_b <= 135.0) {
        if (RRTV3_PX4_OA_B.M3_o > 0.0) {
          RRTV3_PX4_OA_B.M3_o = (RRTV3_PX4_OA_B.M3_o - 90.0) *
            0.017453292519943295;
          n = 1;
        } else {
          RRTV3_PX4_OA_B.M3_o = (RRTV3_PX4_OA_B.M3_o + 90.0) *
            0.017453292519943295;
          n = -1;
        }
      } else if (RRTV3_PX4_OA_B.M3_o > 0.0) {
        RRTV3_PX4_OA_B.M3_o = (RRTV3_PX4_OA_B.M3_o - 180.0) *
          0.017453292519943295;
        n = 2;
      } else {
        RRTV3_PX4_OA_B.M3_o = (RRTV3_PX4_OA_B.M3_o + 180.0) *
          0.017453292519943295;
        n = -2;
      }

      switch (n) {
       case 0:
        RRTV3_PX4_OA_B.M2_b = cos(RRTV3_PX4_OA_B.M3_o);
        break;

       case 1:
        RRTV3_PX4_OA_B.M2_b = -sin(RRTV3_PX4_OA_B.M3_o);
        break;

       case -1:
        RRTV3_PX4_OA_B.M2_b = sin(RRTV3_PX4_OA_B.M3_o);
        break;

       default:
        RRTV3_PX4_OA_B.M2_b = -cos(RRTV3_PX4_OA_B.M3_o);
        break;
      }
    }

    RRTV3_PX4_OA_B.M3_o = RRTV3_PX4_OA_DW.Delay1_DSTATE[1] -
      RRTV3_PX4_OA_B.AP_M1;
    RRTV3_PX4_OA_B.AP_M1 = RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[10] *
      RRTV3_PX4_OA_B.M3_o;

    // Saturate: '<S26>/Saturation' incorporates:
    //   DiscreteIntegrator: '<S26>/Integrator'

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2] >
        RRTV3_PX4_OA_P.Saturation_UpperSat_bs) {
      RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_UpperSat_bs;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2] <
               RRTV3_PX4_OA_P.Saturation_LowerSat_b3) {
      RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_LowerSat_b3;
    } else {
      RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2];
    }

    // MATLAB Function: '<S8>/fcn_EMF_Long' incorporates:
    //   DataTypeConversion: '<S96>/Data Type Conversion7'
    //   Delay: '<S8>/Delay1'
    //   Gain: '<S93>/Gain1'
    //   Saturate: '<S26>/Saturation'
    //   SignalConversion generated from: '<S23>/ SFunction '

    RRTV3_PX4_OA_B.ulon = ((((RRTV3_PX4_OA_DW.Delay1_DSTATE[0] -
      RRTV3_PX4_OA_P.Gain1_Gain_fg * RRTV3_PX4_OA_B.In1_n.xyz[1]) *
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[8] +
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[9] * RRTV3_PX4_OA_B.M3_o) +
      RRTV3_PX4_OA_B.LatRad) + ((1.0 -
      RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[7]) * RRTV3_PX4_OA_B.AXN_g +
      RRTV3_PX4_OA_B.dacc_e * RRTV3_PX4_OA_B.TmpSignalConversionAtSFu_bn[7])) +
      (1.0 / RRTV3_PX4_OA_B.M2_b - 1.0) * RRTV3_PX4_OA_B.AP_M4 * 0.0;
    if ((RRTV3_PX4_OA_B.ulon >= 1.0) || rtIsNaN(RRTV3_PX4_OA_B.ulon)) {
      RRTV3_PX4_OA_B.ulon = 1.0;
    }

    if (RRTV3_PX4_OA_B.ulon <= -1.0) {
      RRTV3_PX4_OA_B.ulon = -1.0;
    }

    if (RRTV3_PX4_OA_B.ulon >= 1.0) {
      if ((RRTV3_PX4_OA_B.AP_M1 >= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.AP_M1)) {
        RRTV3_PX4_OA_B.AP_M1 = 0.0;
      }

      if ((RRTV3_PX4_OA_B.AP_M2 >= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.AP_M2)) {
        RRTV3_PX4_OA_B.AP_M2 = 0.0;
      }
    }

    if (RRTV3_PX4_OA_B.ulon <= -1.0) {
      if ((RRTV3_PX4_OA_B.AP_M1 <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.AP_M1)) {
        RRTV3_PX4_OA_B.AP_M1 = 0.0;
      }

      if ((RRTV3_PX4_OA_B.AP_M2 <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.AP_M2)) {
        RRTV3_PX4_OA_B.AP_M2 = 0.0;
      }
    }

    RRTV3_PX4_OA_DW.Delay1_DSTATE[0] = RRTV3_PX4_OA_B.DXN_p;
    RRTV3_PX4_OA_DW.Delay1_DSTATE[1] = RRTV3_PX4_OA_B.u1;
    RRTV3_PX4_OA_B.AXN_g = RRTV3_PX4_OA_DW.Memory3_PreviousInput;
    RRTV3_PX4_OA_B.AP_M4 = RRTV3_PX4_OA_B.DXN_p;
    if (RRTV3_PX4_OA_B.ParamStep_fo > 0) {
      RRTV3_PX4_OA_B.AXN_g = -RRTV3_PX4_OA_B.DXN_p;
      RRTV3_PX4_OA_B.AP_M4 = -RRTV3_PX4_OA_B.u1;
      RRTV3_PX4_OA_B.AP_M2 = -RRTV3_PX4_OA_B.dacc_e;
      RRTV3_PX4_OA_B.AP_M1 = 0.0;
    }

    if (RRTV3_PX4_OA_B.Control_Level < 2) {
      RRTV3_PX4_OA_B.ulon = RRTV3_PX4_OA_B.M4_h;
    }

    // Gain: '<S8>/Gain1' incorporates:
    //   MATLAB Function: '<S13>/MATLAB Function'

    RRTV3_PX4_OA_B.M2_b = RRTV3_PX4_OA_P.Gain1_Gain * RRTV3_PX4_OA_B.LND_j;

    // DiscreteIntegrator: '<S25>/Integrator' incorporates:
    //   Constant: '<S8>/Constant2'

    if (RRTV3_PX4_OA_DW.Integrator_PrevResetState_e <= 0) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0] =
        RRTV3_PX4_OA_P.Constant2_Value_n[0];
      if (RRTV3_PX4_OA_P.Constant2_Value_n[0] >
          RRTV3_PX4_OA_P.Integrator_UpperSat_py) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_py;
      } else if (RRTV3_PX4_OA_P.Constant2_Value_n[0] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_c4) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_c4;
      }

      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1] =
        RRTV3_PX4_OA_P.Constant2_Value_n[1];
      if (RRTV3_PX4_OA_P.Constant2_Value_n[1] >
          RRTV3_PX4_OA_P.Integrator_UpperSat_py) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_py;
      } else if (RRTV3_PX4_OA_P.Constant2_Value_n[1] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_c4) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_c4;
      }

      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2] =
        RRTV3_PX4_OA_P.Constant2_Value_n[2];
      if (RRTV3_PX4_OA_P.Constant2_Value_n[2] >
          RRTV3_PX4_OA_P.Integrator_UpperSat_py) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_py;
      } else if (RRTV3_PX4_OA_P.Constant2_Value_n[2] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_c4) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_c4;
      }

      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3] =
        RRTV3_PX4_OA_P.Constant2_Value_n[3];
      if (RRTV3_PX4_OA_P.Constant2_Value_n[3] >
          RRTV3_PX4_OA_P.Integrator_UpperSat_py) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_py;
      } else if (RRTV3_PX4_OA_P.Constant2_Value_n[3] <
                 RRTV3_PX4_OA_P.Integrator_LowerSat_c4) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_c4;
      }
    }

    // Saturate: '<S25>/Saturation' incorporates:
    //   DiscreteIntegrator: '<S25>/Integrator'

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0] >
        RRTV3_PX4_OA_P.Saturation_UpperSat_m) {
      RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_P.Saturation_UpperSat_m;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0] <
               RRTV3_PX4_OA_P.Saturation_LowerSat_bj) {
      RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_P.Saturation_LowerSat_bj;
    } else {
      RRTV3_PX4_OA_B.u1 = RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0];
    }

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1] >
        RRTV3_PX4_OA_P.Saturation_UpperSat_m) {
      RRTV3_PX4_OA_B.M3_o = RRTV3_PX4_OA_P.Saturation_UpperSat_m;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1] <
               RRTV3_PX4_OA_P.Saturation_LowerSat_bj) {
      RRTV3_PX4_OA_B.M3_o = RRTV3_PX4_OA_P.Saturation_LowerSat_bj;
    } else {
      RRTV3_PX4_OA_B.M3_o = RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1];
    }

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2] >
        RRTV3_PX4_OA_P.Saturation_UpperSat_m) {
      RRTV3_PX4_OA_B.M4_h = RRTV3_PX4_OA_P.Saturation_UpperSat_m;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2] <
               RRTV3_PX4_OA_P.Saturation_LowerSat_bj) {
      RRTV3_PX4_OA_B.M4_h = RRTV3_PX4_OA_P.Saturation_LowerSat_bj;
    } else {
      RRTV3_PX4_OA_B.M4_h = RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2];
    }

    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3] >
        RRTV3_PX4_OA_P.Saturation_UpperSat_m) {
      RRTV3_PX4_OA_B.M5_j = RRTV3_PX4_OA_P.Saturation_UpperSat_m;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3] <
               RRTV3_PX4_OA_P.Saturation_LowerSat_bj) {
      RRTV3_PX4_OA_B.M5_j = RRTV3_PX4_OA_P.Saturation_LowerSat_bj;
    } else {
      RRTV3_PX4_OA_B.M5_j = RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3];
    }

    // End of Saturate: '<S25>/Saturation'

    // SampleTimeMath: '<S17>/TSamp' incorporates:
    //   Memory: '<S8>/Memory6'
    //
    //  About '<S17>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    RRTV3_PX4_OA_B.LND_j = RRTV3_PX4_OA_DW.Memory6_PreviousInput *
      RRTV3_PX4_OA_P.TSamp_WtEt_b;

    // MATLAB Function: '<S8>/fcn_EMF_Dir' incorporates:
    //   Delay: '<S8>/Delay'
    //   Memory: '<S8>/Memory1'
    //   SignalConversion generated from: '<S21>/ SFunction '
    //   Sum: '<S17>/Diff'
    //   UnitDelay: '<S17>/UD'
    //
    //  Block description for '<S17>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S17>/UD':
    //
    //   Store in Global RAM

    RRTV3_PX4_OA_B.NacelleAutomaticFlag_p = 0.1;
    if (RRTV3_PX4_OA_B.VD <= 10.0) {
      RRTV3_PX4_OA_B.NacelleAutomaticFlag_p = 0.0;
    }

    RRTV3_PX4_OA_DW.Memory6_PreviousInput = (RRTV3_PX4_OA_B.M2_b *
      3.1415926535897931 / 180.0 - RRTV3_PX4_OA_B.M3_o) *
      (RRTV3_PX4_OA_B.EMF_DirGains[0] * RRTV3_PX4_OA_B.EMF_DirGains[0]) - 2.0 *
      RRTV3_PX4_OA_B.EMF_DirGains[1] * RRTV3_PX4_OA_B.EMF_DirGains[0] *
      RRTV3_PX4_OA_B.u1;
    if ((RRTV3_PX4_OA_B.M5_j >= 1.0) || rtIsNaN(RRTV3_PX4_OA_B.M5_j)) {
      RRTV3_PX4_OA_B.DXN_p = 1.0;
    } else {
      RRTV3_PX4_OA_B.DXN_p = RRTV3_PX4_OA_B.M5_j;
    }

    if (RRTV3_PX4_OA_B.DXN_p <= -1.0) {
      RRTV3_PX4_OA_B.DXN_p = -1.0;
    }

    RRTV3_PX4_OA_B.dacc_e = (((2.0 * RRTV3_PX4_OA_B.EMF_DirGains[4] *
      RRTV3_PX4_OA_B.EMF_DirGains[5] * RRTV3_PX4_OA_B.u1 + (RRTV3_PX4_OA_B.LND_j
      - RRTV3_PX4_OA_DW.UD_DSTATE_c)) + RRTV3_PX4_OA_B.EMF_DirGains[5] *
      RRTV3_PX4_OA_B.EMF_DirGains[5] * RRTV3_PX4_OA_B.M3_o) -
      RRTV3_PX4_OA_B.EMF_DirGains[3] / RRTV3_PX4_OA_B.EMF_DirGains[6] *
      RRTV3_PX4_OA_B.DXN_p) / RRTV3_PX4_OA_B.EMF_DirGains[3];
    if (RRTV3_PX4_OA_B.EMF_DirGains[7] == 0.0) {
      RRTV3_PX4_OA_B.dacc_e = -RRTV3_PX4_OA_B.M5_j;
    }

    RRTV3_PX4_OA_B.NacelleManualCmd_c = RRTV3_PX4_OA_DW.Delay_DSTATE -
      RRTV3_PX4_OA_B.AP_NAV;
    RRTV3_PX4_OA_B.AP_NAV = RRTV3_PX4_OA_B.EMF_DirGains[10] *
      RRTV3_PX4_OA_B.NacelleManualCmd_c - RRTV3_PX4_OA_B.NacelleAutomaticFlag_p *
      RRTV3_PX4_OA_B.M4_h;
    RRTV3_PX4_OA_B.z_HDG = (10.0 - RRTV3_PX4_OA_B.VD) * 0.2;
    if (!(RRTV3_PX4_OA_B.z_HDG <= 1.0)) {
      RRTV3_PX4_OA_B.z_HDG = 1.0;
    }

    if (RRTV3_PX4_OA_B.EMF_DirGains[8] <= 0.3) {
      RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_B.EMF_DirGains[8];
    } else {
      RRTV3_PX4_OA_B.LatRad = 0.3;
    }

    if (RRTV3_PX4_OA_B.z_HDG <= 0.0) {
      RRTV3_PX4_OA_B.z_HDG = 0.0;
    }

    if ((RRTV3_PX4_OA_B.LatRad <= -0.3) || rtIsNaN(RRTV3_PX4_OA_B.LatRad)) {
      RRTV3_PX4_OA_B.LatRad = -0.3;
    }

    RRTV3_PX4_OA_B.udir = (((RRTV3_PX4_OA_B.u1 - RRTV3_PX4_OA_B.M3_o *
      RRTV3_PX4_OA_B.EMF_DirGains[2]) / RRTV3_PX4_OA_B.EMF_DirGains[3] * (1.0 -
      RRTV3_PX4_OA_B.EMF_DirGains[7]) + RRTV3_PX4_OA_B.EMF_DirGains[7] *
      RRTV3_PX4_OA_B.DXN_p) * RRTV3_PX4_OA_B.z_HDG +
      (RRTV3_PX4_OA_B.EMF_DirGains[9] * RRTV3_PX4_OA_B.NacelleManualCmd_c +
       RRTV3_PX4_OA_B.M4_h)) + RRTV3_PX4_OA_B.LatRad *
      RRTV3_PX4_OA_DW.Memory1_PreviousInput_b;
    if ((RRTV3_PX4_OA_B.udir >= 1.0) || rtIsNaN(RRTV3_PX4_OA_B.udir)) {
      RRTV3_PX4_OA_B.udir = 1.0;
    }

    if (RRTV3_PX4_OA_B.udir <= -1.0) {
      RRTV3_PX4_OA_B.udir = -1.0;
    }

    if (RRTV3_PX4_OA_B.udir >= 1.0) {
      if ((RRTV3_PX4_OA_B.AP_NAV >= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.AP_NAV)) {
        RRTV3_PX4_OA_B.AP_NAV = 0.0;
      }

      if ((RRTV3_PX4_OA_B.dacc_e >= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.dacc_e)) {
        RRTV3_PX4_OA_B.dacc_e = 0.0;
      }
    }

    if (RRTV3_PX4_OA_B.udir <= -1.0) {
      if ((RRTV3_PX4_OA_B.AP_NAV <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.AP_NAV)) {
        RRTV3_PX4_OA_B.AP_NAV = 0.0;
      }

      if ((RRTV3_PX4_OA_B.dacc_e <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.dacc_e)) {
        RRTV3_PX4_OA_B.dacc_e = 0.0;
      }
    }

    RRTV3_PX4_OA_DW.Delay_DSTATE = RRTV3_PX4_OA_B.M3_o;
    RRTV3_PX4_OA_B.DXN_p = RRTV3_PX4_OA_DW.Memory6_PreviousInput;
    if (RRTV3_PX4_OA_B.ParamStep_fo > 0) {
      RRTV3_PX4_OA_B.DXN_p = -RRTV3_PX4_OA_B.u1;
      RRTV3_PX4_OA_B.u1 = -RRTV3_PX4_OA_B.M3_o;
      RRTV3_PX4_OA_B.AP_NAV = -RRTV3_PX4_OA_B.M4_h;
      RRTV3_PX4_OA_B.dacc_e = -RRTV3_PX4_OA_B.M5_j;
    }

    if (RRTV3_PX4_OA_B.Control_Level < 2) {
      RRTV3_PX4_OA_B.udir = RRTV3_PX4_OA_B.M2_b;
    }

    // End of MATLAB Function: '<S8>/fcn_EMF_Dir'

    // MATLAB Function: '<S11>/MATLAB Function' incorporates:
    //   Constant: '<S11>/Constant3'
    //   DataTypeConversion: '<S50>/Data Type Conversion2'
    //   Gain: '<S11>/Gain2'
    //   MATLAB Function: '<S12>/MATLAB Function'
    //   MATLABSystem: '<S50>/Max Phi Cmd2'
    //
    RRTV3_PX4_OA_B.M1_b = RRTV3_PX4_OA_P.Gain2_Gain_e *
      RRTV3_PX4_OA_B.ParamStep_evk * RRTV3_PX4_OA_B.M1_b /
      RRTV3_PX4_OA_P.Constant3_Value_d;
    if (RRTV3_PX4_OA_B.Control_Level == 1) {
      RRTV3_PX4_OA_B.M1_b *= 1.1;
    }

    // End of MATLAB Function: '<S11>/MATLAB Function'

    // Gain: '<S11>/Gain1' incorporates:
    //   MATLAB Function: '<S12>/MATLAB Function'

    RRTV3_PX4_OA_B.M2_b = RRTV3_PX4_OA_P.Gain1_Gain_f * RRTV3_PX4_OA_B.NAV_p;

    // MATLAB Function: '<S11>/MATLAB Function1' incorporates:
    //   DataTypeConversion: '<S50>/Data Type Conversion17'
    //   DataTypeConversion: '<S50>/Data Type Conversion19'
    //   Gain: '<S11>/Gain'
    //   MATLABSystem: '<S50>/Max Phi Cmd8'
    //   MATLABSystem: '<S50>/Max Phi Cmd9'
    //
    if (rtIsInf(RRTV3_PX4_OA_B.M2_b) || rtIsNaN(RRTV3_PX4_OA_B.M2_b)) {
      RRTV3_PX4_OA_B.M2_b = (rtNaN);
    } else {
      RRTV3_PX4_OA_B.M3_o = RRTV3_PX4_OA_rt_remd_snf(RRTV3_PX4_OA_B.M2_b, 360.0);
      RRTV3_PX4_OA_B.M2_b = fabs(RRTV3_PX4_OA_B.M3_o);
      if (RRTV3_PX4_OA_B.M2_b > 180.0) {
        if (RRTV3_PX4_OA_B.M3_o > 0.0) {
          RRTV3_PX4_OA_B.M3_o -= 360.0;
        } else {
          RRTV3_PX4_OA_B.M3_o += 360.0;
        }

        RRTV3_PX4_OA_B.M2_b = fabs(RRTV3_PX4_OA_B.M3_o);
      }

      if (RRTV3_PX4_OA_B.M2_b <= 45.0) {
        RRTV3_PX4_OA_B.M3_o *= 0.017453292519943295;
        n = 0;
      } else if (RRTV3_PX4_OA_B.M2_b <= 135.0) {
        if (RRTV3_PX4_OA_B.M3_o > 0.0) {
          RRTV3_PX4_OA_B.M3_o = (RRTV3_PX4_OA_B.M3_o - 90.0) *
            0.017453292519943295;
          n = 1;
        } else {
          RRTV3_PX4_OA_B.M3_o = (RRTV3_PX4_OA_B.M3_o + 90.0) *
            0.017453292519943295;
          n = -1;
        }
      } else if (RRTV3_PX4_OA_B.M3_o > 0.0) {
        RRTV3_PX4_OA_B.M3_o = (RRTV3_PX4_OA_B.M3_o - 180.0) *
          0.017453292519943295;
        n = 2;
      } else {
        RRTV3_PX4_OA_B.M3_o = (RRTV3_PX4_OA_B.M3_o + 180.0) *
          0.017453292519943295;
        n = -2;
      }

      switch (n) {
       case 0:
        RRTV3_PX4_OA_B.M2_b = cos(RRTV3_PX4_OA_B.M3_o);
        break;

       case 1:
        RRTV3_PX4_OA_B.M2_b = -sin(RRTV3_PX4_OA_B.M3_o);
        break;

       case -1:
        RRTV3_PX4_OA_B.M2_b = sin(RRTV3_PX4_OA_B.M3_o);
        break;

       default:
        RRTV3_PX4_OA_B.M2_b = -cos(RRTV3_PX4_OA_B.M3_o);
        break;
      }
    }

    RRTV3_PX4_OA_B.M2_b *= RRTV3_PX4_OA_P.Gain_Gain_g * RRTV3_PX4_OA_B.VCSkt;
    RRTV3_PX4_OA_B.M3_o = RRTV3_PX4_OA_B.M1_b * RRTV3_PX4_OA_B.M1_b;
    RRTV3_PX4_OA_B.M4_h = RRTV3_PX4_OA_B.M2_b * RRTV3_PX4_OA_B.M2_b;
    RRTV3_PX4_OA_B.MPRPM = (((((((((131.8 * RRTV3_PX4_OA_B.M1_b + 930.6) + 39.7 *
      RRTV3_PX4_OA_B.M2_b) + RRTV3_PX4_OA_B.M3_o * -1.48) + -1.683 *
      RRTV3_PX4_OA_B.M1_b * RRTV3_PX4_OA_B.M2_b) + RRTV3_PX4_OA_B.M4_h * 3.944)
      + 0.007859 * rt_powd_snf(RRTV3_PX4_OA_B.M1_b, 3.0)) + RRTV3_PX4_OA_B.M3_o *
      0.01704 * RRTV3_PX4_OA_B.M2_b) + -0.008263 * RRTV3_PX4_OA_B.M1_b *
      RRTV3_PX4_OA_B.M4_h) + -0.04586 * rt_powd_snf(RRTV3_PX4_OA_B.M2_b, 3.0)) /
      sqrt(RRTV3_PX4_OA_B.ParamStep_my / 1.225) + RRTV3_PX4_OA_B.ParamStep_jg;

    // End of MATLAB Function: '<S11>/MATLAB Function1'

    // Saturate: '<S11>/ RPM LIMITER'
    if (RRTV3_PX4_OA_B.MPRPM > RRTV3_PX4_OA_P.RPMLIMITER_UpperSat) {
      // Saturate: '<S11>/ RPM LIMITER'
      RRTV3_PX4_OA_B.MPRPM = RRTV3_PX4_OA_P.RPMLIMITER_UpperSat;
    } else if (RRTV3_PX4_OA_B.MPRPM < RRTV3_PX4_OA_P.RPMLIMITER_LowerSat) {
      // Saturate: '<S11>/ RPM LIMITER'
      RRTV3_PX4_OA_B.MPRPM = RRTV3_PX4_OA_P.RPMLIMITER_LowerSat;
    }

    // End of Saturate: '<S11>/ RPM LIMITER'

    // Saturate: '<S79>/Saturation' incorporates:
    //   DataTypeConversion: '<S79>/Cast To Double6'
    //   MATLABSystem: '<S79>/Read Parameter6'
    //
    if (RRTV3_PX4_OA_B.ParamStep_mvx > RRTV3_PX4_OA_P.Saturation_UpperSat_nd) {
      RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_UpperSat_nd;
    } else if (RRTV3_PX4_OA_B.ParamStep_mvx <
               RRTV3_PX4_OA_P.Saturation_LowerSat_nk) {
      RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_P.Saturation_LowerSat_nk;
    } else {
      RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_B.ParamStep_mvx;
    }

    // Gain: '<S7>/Gain' incorporates:
    //   Saturate: '<S79>/Saturation'

    RRTV3_PX4_OA_B.M1_b = RRTV3_PX4_OA_P.Gain_Gain_j * RRTV3_PX4_OA_B.LatRad;

    // MATLAB Function: '<S7>/Control Allocation (shell)' incorporates:
    //   MATLAB Function: '<S12>/MATLAB Function'

    if ((RRTV3_PX4_OA_B.ulat <= -1.0) || rtIsNaN(RRTV3_PX4_OA_B.ulat)) {
      RRTV3_PX4_OA_B.M2_b = -1.0;
    } else {
      RRTV3_PX4_OA_B.M2_b = RRTV3_PX4_OA_B.ulat;
    }

    if (RRTV3_PX4_OA_B.M2_b >= 1.0) {
      RRTV3_PX4_OA_B.M2_b = 1.0;
    }

    if ((RRTV3_PX4_OA_B.ulon <= -1.0) || rtIsNaN(RRTV3_PX4_OA_B.ulon)) {
      RRTV3_PX4_OA_B.M3_o = -1.0;
    } else {
      RRTV3_PX4_OA_B.M3_o = RRTV3_PX4_OA_B.ulon;
    }

    if (RRTV3_PX4_OA_B.M3_o >= 1.0) {
      RRTV3_PX4_OA_B.M3_o = 1.0;
    }

    if ((RRTV3_PX4_OA_B.udir <= -1.0) || rtIsNaN(RRTV3_PX4_OA_B.udir)) {
      RRTV3_PX4_OA_B.M4_h = -1.0;
    } else {
      RRTV3_PX4_OA_B.M4_h = RRTV3_PX4_OA_B.udir;
    }

    if (RRTV3_PX4_OA_B.M4_h >= 1.0) {
      RRTV3_PX4_OA_B.M4_h = 1.0;
    }

    RRTV3_PX4_OA_B.NacelleAutomaticFlag_p = 0.0;
    if ((RRTV3_PX4_OA_B.NAV_p > 50.0) && (RRTV3_PX4_OA_B.NAV_p < 60.0)) {
      RRTV3_PX4_OA_B.NacelleAutomaticFlag_p = (RRTV3_PX4_OA_B.NAV_p - 60.0) *
        -20.0 / -10.0;
    }

    if ((RRTV3_PX4_OA_B.NAV_p > 15.0) && (RRTV3_PX4_OA_B.NAV_p < 50.0)) {
      RRTV3_PX4_OA_B.NacelleAutomaticFlag_p = -20.0;
    }

    if ((RRTV3_PX4_OA_B.NAV_p > 5.0) && (RRTV3_PX4_OA_B.NAV_p < 15.0)) {
      RRTV3_PX4_OA_B.NacelleAutomaticFlag_p = -20.0 - (RRTV3_PX4_OA_B.NAV_p -
        15.0) * -20.0 / -10.0;
    }

    RRTV3_PX4_OA_B.M5_j = (60.0 - RRTV3_PX4_OA_B.NAV_p) / 20.0;
    if ((RRTV3_PX4_OA_B.M5_j <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.M5_j)) {
      RRTV3_PX4_OA_B.M5_j = 0.0;
    }

    if (RRTV3_PX4_OA_B.M5_j >= 1.0) {
      RRTV3_PX4_OA_B.M5_j = 1.0;
    }

    RRTV3_PX4_OA_B.NacelleManualCmd_c = 1.0 - (70.0 - RRTV3_PX4_OA_B.NAV_p) /
      20.0;
    if ((RRTV3_PX4_OA_B.NacelleManualCmd_c <= 0.0) || rtIsNaN
        (RRTV3_PX4_OA_B.NacelleManualCmd_c)) {
      RRTV3_PX4_OA_B.NacelleManualCmd_c = 0.0;
    }

    if (RRTV3_PX4_OA_B.NacelleManualCmd_c >= 1.0) {
      RRTV3_PX4_OA_B.NacelleManualCmd_c = 1.0;
    }

    RRTV3_PX4_OA_B.ParamStep_m0 = 30;
    if (RRTV3_PX4_OA_B.NacelleAutomaticFlag_p != 0.0) {
      RRTV3_PX4_OA_B.ParamStep_m0 = 0;
    }

    RRTV3_PX4_OA_B.SignalLoss_j = 30.0 * RRTV3_PX4_OA_B.M2_b *
      RRTV3_PX4_OA_B.M5_j;
    RRTV3_PX4_OA_B.z_HDG = 30.0 * RRTV3_PX4_OA_B.M4_h *
      RRTV3_PX4_OA_B.NacelleManualCmd_c - RRTV3_PX4_OA_B.SignalLoss_j;
    if (RRTV3_PX4_OA_B.z_HDG <= -30.0) {
      RRTV3_PX4_OA_B.z_HDG = -30.0;
    }

    if (RRTV3_PX4_OA_B.ParamStep_m0 <= RRTV3_PX4_OA_B.z_HDG) {
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_B.ParamStep_m0;
    }

    RRTV3_PX4_OA_B.M5_j = RRTV3_PX4_OA_B.z_HDG +
      RRTV3_PX4_OA_B.NacelleAutomaticFlag_p;
    if (RRTV3_PX4_OA_B.M5_j <= -30.0) {
      RRTV3_PX4_OA_B.M5_j = -30.0;
    }

    RRTV3_PX4_OA_B.z_HDG = -30.0 * RRTV3_PX4_OA_B.M4_h *
      RRTV3_PX4_OA_B.NacelleManualCmd_c + RRTV3_PX4_OA_B.SignalLoss_j;
    if (RRTV3_PX4_OA_B.z_HDG <= -30.0) {
      RRTV3_PX4_OA_B.z_HDG = -30.0;
    }

    if (RRTV3_PX4_OA_B.ParamStep_m0 <= RRTV3_PX4_OA_B.z_HDG) {
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_B.ParamStep_m0;
    }

    RRTV3_PX4_OA_B.NacelleAutomaticFlag_p += RRTV3_PX4_OA_B.z_HDG;
    if (RRTV3_PX4_OA_B.NacelleAutomaticFlag_p <= -30.0) {
      RRTV3_PX4_OA_B.NacelleAutomaticFlag_p = -30.0;
    }

    RRTV3_PX4_OA_B.z_HDG = 1.0 - (70.0 - RRTV3_PX4_OA_B.NAV_p) / 35.0;
    if ((RRTV3_PX4_OA_B.z_HDG <= 0.0) || rtIsNaN(RRTV3_PX4_OA_B.z_HDG)) {
      RRTV3_PX4_OA_B.z_HDG = 0.0;
    }

    if (RRTV3_PX4_OA_B.z_HDG >= 1.0) {
      RRTV3_PX4_OA_B.z_HDG = 1.0;
    }

    RRTV3_PX4_OA_B.NacelleManualCmd_c = (RRTV3_PX4_OA_B.M2_b *
      RRTV3_PX4_OA_B.z_HDG + RRTV3_PX4_OA_B.M4_h * 0.0) * 500.0;

    // SignalConversion generated from: '<S1>/Control Cmds' incorporates:
    //   MATLAB Function: '<S7>/Control Allocation (shell)'

    RRTV3_PX4_OA_B.OutportBufferForControlCmds[15] = 2000.0;
    RRTV3_PX4_OA_B.OutportBufferForControlCmds[14] = 2000.0;

    // MATLAB Function: '<S7>/Control Allocation (shell)'
    if (RRTV3_PX4_OA_B.M3_o < 0.0) {
      // SignalConversion generated from: '<S1>/Control Cmds'
      RRTV3_PX4_OA_B.OutportBufferForControlCmds[15] = fabs(RRTV3_PX4_OA_B.M3_o)
        * 6800.0 + 2000.0;
    }

    if (RRTV3_PX4_OA_B.M3_o > 0.0) {
      // SignalConversion generated from: '<S1>/Control Cmds'
      RRTV3_PX4_OA_B.OutportBufferForControlCmds[14] = RRTV3_PX4_OA_B.M3_o *
        6800.0 + 2000.0;
    }

    // SignalConversion generated from: '<S1>/Control Cmds' incorporates:
    //   MATLAB Function: '<S7>/Control Allocation (shell)'

    RRTV3_PX4_OA_B.OutportBufferForControlCmds[0] =
      RRTV3_PX4_OA_B.NacelleAutomaticFlag_p;
    RRTV3_PX4_OA_B.OutportBufferForControlCmds[1] =
      RRTV3_PX4_OA_B.NacelleAutomaticFlag_p;
    RRTV3_PX4_OA_B.OutportBufferForControlCmds[2] = RRTV3_PX4_OA_B.M5_j;
    RRTV3_PX4_OA_B.OutportBufferForControlCmds[3] = RRTV3_PX4_OA_B.M5_j;

    // MATLAB Function: '<S7>/Control Allocation (shell)'
    RRTV3_PX4_OA_B.z_HDG = -30.0 * RRTV3_PX4_OA_B.M3_o + 15.0 *
      RRTV3_PX4_OA_B.M2_b;
    if (RRTV3_PX4_OA_B.z_HDG >= 30.0) {
      RRTV3_PX4_OA_B.z_HDG = 30.0;
    }

    if (RRTV3_PX4_OA_B.z_HDG <= -30.0) {
      // SignalConversion generated from: '<S1>/Control Cmds'
      RRTV3_PX4_OA_B.OutportBufferForControlCmds[4] = -30.0;
    } else {
      // SignalConversion generated from: '<S1>/Control Cmds'
      RRTV3_PX4_OA_B.OutportBufferForControlCmds[4] = RRTV3_PX4_OA_B.z_HDG;
    }

    RRTV3_PX4_OA_B.z_HDG = -30.0 * RRTV3_PX4_OA_B.M3_o - 15.0 *
      RRTV3_PX4_OA_B.M2_b;
    if (RRTV3_PX4_OA_B.z_HDG >= 30.0) {
      RRTV3_PX4_OA_B.z_HDG = 30.0;
    }

    if (RRTV3_PX4_OA_B.z_HDG <= -30.0) {
      // SignalConversion generated from: '<S1>/Control Cmds'
      RRTV3_PX4_OA_B.OutportBufferForControlCmds[5] = -30.0;
    } else {
      // SignalConversion generated from: '<S1>/Control Cmds'
      RRTV3_PX4_OA_B.OutportBufferForControlCmds[5] = RRTV3_PX4_OA_B.z_HDG;
    }

    // SignalConversion generated from: '<S1>/Control Cmds' incorporates:
    //   Constant: '<S15>/GEAR IS FIXED ON 1//5 SCALE'
    //   MATLAB Function: '<S12>/MATLAB Function'
    //   MATLAB Function: '<S7>/Control Allocation (shell)'

    RRTV3_PX4_OA_B.OutportBufferForControlCmds[6] = 30.0 * RRTV3_PX4_OA_B.M4_h;
    RRTV3_PX4_OA_B.OutportBufferForControlCmds[7] = 30.0 * RRTV3_PX4_OA_B.M4_h;
    RRTV3_PX4_OA_B.OutportBufferForControlCmds[8] = RRTV3_PX4_OA_B.NAV_p;
    RRTV3_PX4_OA_B.OutportBufferForControlCmds[9] = 0.0;
    RRTV3_PX4_OA_B.OutportBufferForControlCmds[10] = 0.0;
    RRTV3_PX4_OA_B.OutportBufferForControlCmds[11] = 0.0;
    RRTV3_PX4_OA_B.OutportBufferForControlCmds[12] = (RRTV3_PX4_OA_B.MPRPM +
      RRTV3_PX4_OA_B.NacelleManualCmd_c) + RRTV3_PX4_OA_B.M1_b;
    RRTV3_PX4_OA_B.OutportBufferForControlCmds[13] = (RRTV3_PX4_OA_B.MPRPM -
      RRTV3_PX4_OA_B.NacelleManualCmd_c) - RRTV3_PX4_OA_B.M1_b;
    RRTV3_PX4_OA_B.OutportBufferForControlCmds[16] =
      RRTV3_PX4_OA_P.GEARISFIXEDON15SCALE_Value;

    // MATLAB Function: '<S13>/AF Encoder'
    RRTV3_PX4_OA_B.AF = ((((((1.0E+6 * RRTV3_PX4_OA_DW.Memory2_PreviousInput[0]
      + 1.111111E+6) + 100000.0 * RRTV3_PX4_OA_DW.Memory2_PreviousInput[1]) +
      10000.0 * RRTV3_PX4_OA_DW.Memory2_PreviousInput[2]) + 1000.0 *
      RRTV3_PX4_OA_DW.Memory2_PreviousInput[3]) + 100.0 *
                          RRTV3_PX4_OA_DW.Memory2_PreviousInput[4]) + 10.0 *
                         RRTV3_PX4_OA_DW.Memory2_PreviousInput[5]) +
      RRTV3_PX4_OA_DW.Memory2_PreviousInput[6];

    // SignalConversion generated from: '<S11>/Constant' incorporates:
    //   Constant: '<S11>/Constant'

    RRTV3_PX4_OA_B.LPRPM = RRTV3_PX4_OA_P.Constant_Value_fw;

    // Update for DiscreteIntegrator: '<S48>/Integrator' incorporates:
    //   MATLAB Function: '<S42>/MATLAB Function1'

    RRTV3_PX4_OA_B.AP_M3 = RRTV3_PX4_OA_P.Integrator_gainval *
      RRTV3_PX4_OA_B.AP_M3 + RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0] = RRTV3_PX4_OA_B.AP_M3;
    if (RRTV3_PX4_OA_B.AP_M3 > RRTV3_PX4_OA_P.Integrator_UpperSat) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0] =
        RRTV3_PX4_OA_P.Integrator_UpperSat;
    } else if (RRTV3_PX4_OA_B.AP_M3 < RRTV3_PX4_OA_P.Integrator_LowerSat) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0] =
        RRTV3_PX4_OA_P.Integrator_LowerSat;
    }

    RRTV3_PX4_OA_B.AP_M3 = (RRTV3_PX4_OA_B.AP_LND / 30.0 - RRTV3_PX4_OA_B.phi) /
      2.0 * RRTV3_PX4_OA_P.Integrator_gainval +
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1] = RRTV3_PX4_OA_B.AP_M3;
    if (RRTV3_PX4_OA_B.AP_M3 > RRTV3_PX4_OA_P.Integrator_UpperSat) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1] =
        RRTV3_PX4_OA_P.Integrator_UpperSat;
    } else if (RRTV3_PX4_OA_B.AP_M3 < RRTV3_PX4_OA_P.Integrator_LowerSat) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1] =
        RRTV3_PX4_OA_P.Integrator_LowerSat;
    }

    RRTV3_PX4_OA_B.AP_M3 = (RRTV3_PX4_OA_B.AP_AXN - RRTV3_PX4_OA_B.theta) *
      RRTV3_PX4_OA_P.Integrator_gainval + RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2] = RRTV3_PX4_OA_B.AP_M3;
    if (RRTV3_PX4_OA_B.AP_M3 > RRTV3_PX4_OA_P.Integrator_UpperSat) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2] =
        RRTV3_PX4_OA_P.Integrator_UpperSat;
    } else if (RRTV3_PX4_OA_B.AP_M3 < RRTV3_PX4_OA_P.Integrator_LowerSat) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2] =
        RRTV3_PX4_OA_P.Integrator_LowerSat;
    }

    RRTV3_PX4_OA_B.AP_M3 = RRTV3_PX4_OA_P.Integrator_gainval *
      RRTV3_PX4_OA_B.AP_M5 + RRTV3_PX4_OA_DW.Integrator_DSTATE_h[3];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_h[3] = RRTV3_PX4_OA_B.AP_M3;
    if (RRTV3_PX4_OA_B.AP_M3 > RRTV3_PX4_OA_P.Integrator_UpperSat) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[3] =
        RRTV3_PX4_OA_P.Integrator_UpperSat;
    } else if (RRTV3_PX4_OA_B.AP_M3 < RRTV3_PX4_OA_P.Integrator_LowerSat) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[3] =
        RRTV3_PX4_OA_P.Integrator_LowerSat;
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_i = 1;

    // End of Update for DiscreteIntegrator: '<S48>/Integrator'

    // Update for Memory: '<S42>/Memory2' incorporates:
    //   MATLAB Function: '<S42>/MATLAB Function1'

    RRTV3_PX4_OA_DW.Memory2_PreviousInput_p[0] = RRTV3_PX4_OA_B.AP_DXN;
    RRTV3_PX4_OA_DW.Memory2_PreviousInput_p[1] = RRTV3_PX4_OA_B.WPINDEX;
    RRTV3_PX4_OA_DW.Memory2_PreviousInput_p[2] = RRTV3_PX4_OA_B.HDG;

    // Update for DiscreteIntegrator: '<S44>/Integrator' incorporates:
    //   Constant: '<S13>/Constant1'
    //   Constant: '<S13>/Constant2'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_b += RRTV3_PX4_OA_P.Integrator_gainval_o *
      RRTV3_PX4_OA_P.Constant1_Value_k;
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_b >
        RRTV3_PX4_OA_P.Integrator_UpperSat_l) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_b = RRTV3_PX4_OA_P.Integrator_UpperSat_l;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_b <
               RRTV3_PX4_OA_P.Integrator_LowerSat_h) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_b = RRTV3_PX4_OA_P.Integrator_LowerSat_h;
    }

    if (RRTV3_PX4_OA_P.Constant2_Value_b > 0.0) {
      RRTV3_PX4_OA_DW.Integrator_PrevResetState_k = 1;
    } else if (RRTV3_PX4_OA_P.Constant2_Value_b < 0.0) {
      RRTV3_PX4_OA_DW.Integrator_PrevResetState_k = -1;
    } else if (RRTV3_PX4_OA_P.Constant2_Value_b == 0.0) {
      RRTV3_PX4_OA_DW.Integrator_PrevResetState_k = 0;
    } else {
      RRTV3_PX4_OA_DW.Integrator_PrevResetState_k = 2;
    }

    // End of Update for DiscreteIntegrator: '<S44>/Integrator'

    // Update for DiscreteIntegrator: '<S43>/Integrator'
    for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 10; RRTV3_PX4_OA_B.i++) {
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.Integrator_gainval_j *
        RRTV3_PX4_OA_B.TBI_b[RRTV3_PX4_OA_B.i] +
        RRTV3_PX4_OA_DW.Integrator_DSTATE_f[RRTV3_PX4_OA_B.i];
      RRTV3_PX4_OA_DW.Integrator_DSTATE_f[RRTV3_PX4_OA_B.i] =
        RRTV3_PX4_OA_B.z_HDG;
      if (RRTV3_PX4_OA_B.z_HDG > RRTV3_PX4_OA_P.Integrator_UpperSat_p) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_f[RRTV3_PX4_OA_B.i] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_p;
      } else if (RRTV3_PX4_OA_B.z_HDG < RRTV3_PX4_OA_P.Integrator_LowerSat_m) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_f[RRTV3_PX4_OA_B.i] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_m;
      }
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_by = 1;

    // End of Update for DiscreteIntegrator: '<S43>/Integrator'

    // Update for Memory: '<S8>/Memory7'
    RRTV3_PX4_OA_DW.Memory7_PreviousInput = RRTV3_PX4_OA_B.udir;

    // Update for DiscreteIntegrator: '<S24>/Integrator'
    RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Integrator_gainval_g *
      RRTV3_PX4_OA_B.ddir_h + RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0] = RRTV3_PX4_OA_B.phi;
    if (RRTV3_PX4_OA_B.phi > RRTV3_PX4_OA_P.Integrator_UpperSat_g) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_g;
    } else if (RRTV3_PX4_OA_B.phi < RRTV3_PX4_OA_P.Integrator_LowerSat_l) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_l;
    }

    RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Integrator_gainval_g *
      RRTV3_PX4_OA_B.NacelleManualCmd + RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1] = RRTV3_PX4_OA_B.phi;
    if (RRTV3_PX4_OA_B.phi > RRTV3_PX4_OA_P.Integrator_UpperSat_g) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_g;
    } else if (RRTV3_PX4_OA_B.phi < RRTV3_PX4_OA_P.Integrator_LowerSat_l) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_l;
    }

    RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Integrator_gainval_g *
      RRTV3_PX4_OA_B.dver_i + RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2] = RRTV3_PX4_OA_B.phi;
    if (RRTV3_PX4_OA_B.phi > RRTV3_PX4_OA_P.Integrator_UpperSat_g) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_g;
    } else if (RRTV3_PX4_OA_B.phi < RRTV3_PX4_OA_P.Integrator_LowerSat_l) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_l;
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_m = 1;

    // End of Update for DiscreteIntegrator: '<S24>/Integrator'

    // Update for DiscreteIntegrator: '<S36>/Integrator'
    RRTV3_PX4_OA_DW.Integrator_DSTATE_g += RRTV3_PX4_OA_P.Integrator_gainval_c *
      static_cast<real_T>(RRTV3_PX4_OA_B.ParamStep_jgs);
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_g >
        RRTV3_PX4_OA_P.Integrator_UpperSat_pu) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_g =
        RRTV3_PX4_OA_P.Integrator_UpperSat_pu;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_g <
               RRTV3_PX4_OA_P.Integrator_LowerSat_i) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_g = RRTV3_PX4_OA_P.Integrator_LowerSat_i;
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_h = 1;

    // End of Update for DiscreteIntegrator: '<S36>/Integrator'

    // Update for DiscreteIntegrator: '<S35>/Integrator'
    for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 5; RRTV3_PX4_OA_B.i++) {
      RRTV3_PX4_OA_B.NAV_p = RRTV3_PX4_OA_P.Integrator_gainval_f *
        RRTV3_PX4_OA_B.TBI_ir[RRTV3_PX4_OA_B.i] +
        RRTV3_PX4_OA_DW.Integrator_DSTATE_m[RRTV3_PX4_OA_B.i];
      RRTV3_PX4_OA_DW.Integrator_DSTATE_m[RRTV3_PX4_OA_B.i] =
        RRTV3_PX4_OA_B.NAV_p;

      // Update for DiscreteIntegrator: '<S35>/Integrator'
      RRTV3_PX4_OA_B.M1_b =
        RRTV3_PX4_OA_P.Integrator_UpperSat_o[RRTV3_PX4_OA_B.i];
      if (RRTV3_PX4_OA_B.NAV_p > RRTV3_PX4_OA_B.M1_b) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_m[RRTV3_PX4_OA_B.i] =
          RRTV3_PX4_OA_B.M1_b;
      } else {
        RRTV3_PX4_OA_B.M1_b =
          RRTV3_PX4_OA_P.Integrator_LowerSat_a[RRTV3_PX4_OA_B.i];
        if (RRTV3_PX4_OA_B.NAV_p < RRTV3_PX4_OA_B.M1_b) {
          RRTV3_PX4_OA_DW.Integrator_DSTATE_m[RRTV3_PX4_OA_B.i] =
            RRTV3_PX4_OA_B.M1_b;
        }
      }
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_hc = 1;

    // End of Update for DiscreteIntegrator: '<S35>/Integrator'

    // Update for DiscreteIntegrator: '<S26>/Integrator'
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_n2 = 1;

    // Update for UnitDelay: '<S16>/UD'
    //
    //  Block description for '<S16>/UD':
    //
    //   Store in Global RAM

    RRTV3_PX4_OA_DW.UD_DSTATE_h = RRTV3_PX4_OA_B.TKO_d;

    // Update for Memory: '<S8>/Memory1'
    RRTV3_PX4_OA_DW.Memory1_PreviousInput_b = RRTV3_PX4_OA_B.ulat;

    // Update for DiscreteIntegrator: '<S26>/Integrator'
    RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Integrator_gainval_l *
      RRTV3_PX4_OA_B.AXN_g + RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0] = RRTV3_PX4_OA_B.phi;
    if (RRTV3_PX4_OA_B.phi > RRTV3_PX4_OA_P.Integrator_UpperSat_m) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_m;
    } else if (RRTV3_PX4_OA_B.phi < RRTV3_PX4_OA_P.Integrator_LowerSat_c) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c;
    }

    // Update for DiscreteIntegrator: '<S25>/Integrator'
    RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Integrator_gainval_k *
      RRTV3_PX4_OA_B.DXN_p + RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0] = RRTV3_PX4_OA_B.phi;
    if (RRTV3_PX4_OA_B.phi > RRTV3_PX4_OA_P.Integrator_UpperSat_py) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_py;
    } else if (RRTV3_PX4_OA_B.phi < RRTV3_PX4_OA_P.Integrator_LowerSat_c4) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c4;
    }

    // Update for DiscreteIntegrator: '<S26>/Integrator'
    RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Integrator_gainval_l *
      RRTV3_PX4_OA_B.AP_M4 + RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1] = RRTV3_PX4_OA_B.phi;
    if (RRTV3_PX4_OA_B.phi > RRTV3_PX4_OA_P.Integrator_UpperSat_m) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_m;
    } else if (RRTV3_PX4_OA_B.phi < RRTV3_PX4_OA_P.Integrator_LowerSat_c) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c;
    }

    // Update for DiscreteIntegrator: '<S25>/Integrator'
    RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Integrator_gainval_k * RRTV3_PX4_OA_B.u1
      + RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1] = RRTV3_PX4_OA_B.phi;
    if (RRTV3_PX4_OA_B.phi > RRTV3_PX4_OA_P.Integrator_UpperSat_py) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_py;
    } else if (RRTV3_PX4_OA_B.phi < RRTV3_PX4_OA_P.Integrator_LowerSat_c4) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c4;
    }

    // Update for DiscreteIntegrator: '<S26>/Integrator'
    RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Integrator_gainval_l *
      RRTV3_PX4_OA_B.AP_M1 + RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2] = RRTV3_PX4_OA_B.phi;
    if (RRTV3_PX4_OA_B.phi > RRTV3_PX4_OA_P.Integrator_UpperSat_m) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_m;
    } else if (RRTV3_PX4_OA_B.phi < RRTV3_PX4_OA_P.Integrator_LowerSat_c) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c;
    }

    // Update for DiscreteIntegrator: '<S25>/Integrator'
    RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Integrator_gainval_k *
      RRTV3_PX4_OA_B.AP_NAV + RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2] = RRTV3_PX4_OA_B.phi;
    if (RRTV3_PX4_OA_B.phi > RRTV3_PX4_OA_P.Integrator_UpperSat_py) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_py;
    } else if (RRTV3_PX4_OA_B.phi < RRTV3_PX4_OA_P.Integrator_LowerSat_c4) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c4;
    }

    // Update for DiscreteIntegrator: '<S26>/Integrator'
    RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Integrator_gainval_l *
      RRTV3_PX4_OA_B.AP_M2 + RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3] = RRTV3_PX4_OA_B.phi;
    if (RRTV3_PX4_OA_B.phi > RRTV3_PX4_OA_P.Integrator_UpperSat_m) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_m;
    } else if (RRTV3_PX4_OA_B.phi < RRTV3_PX4_OA_P.Integrator_LowerSat_c) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c;
    }

    // Update for DiscreteIntegrator: '<S25>/Integrator'
    RRTV3_PX4_OA_B.phi = RRTV3_PX4_OA_P.Integrator_gainval_k *
      RRTV3_PX4_OA_B.dacc_e + RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3];
    RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3] = RRTV3_PX4_OA_B.phi;
    if (RRTV3_PX4_OA_B.phi > RRTV3_PX4_OA_P.Integrator_UpperSat_py) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_py;
    } else if (RRTV3_PX4_OA_B.phi < RRTV3_PX4_OA_P.Integrator_LowerSat_c4) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c4;
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_e = 1;

    // Update for UnitDelay: '<S17>/UD'
    //
    //  Block description for '<S17>/UD':
    //
    //   Store in Global RAM

    RRTV3_PX4_OA_DW.UD_DSTATE_c = RRTV3_PX4_OA_B.LND_j;
  }

  // End of Outputs for SubSystem: '<Root>/Controllers'

  // Sum: '<S75>/Sum' incorporates:
  //   Gain: '<S75>/Gain'
  //   Sum: '<S75>/Diff'
  //   UnitDelay: '<S75>/UD'
  //
  //  Block description for '<S75>/Sum':
  //
  //   Add in CPU
  //
  //  Block description for '<S75>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S75>/UD':
  //
  //   Store in Global RAM

  RRTV3_PX4_OA_DW.UD_DSTATE_mb = (RRTV3_PX4_OA_DW.UD_DSTATE_mb -
    RRTV3_PX4_OA_B.AP_TKO) * RRTV3_PX4_OA_P.u01s1001s2_PoleZ_o +
    RRTV3_PX4_OA_B.AP_TKO;

  // DiscreteIntegrator: '<S92>/Integrator' incorporates:
  //   Constant: '<S5>/Constant2'
  //   DataTypeConversion: '<S4>/Cast To Boolean'

  if (((RRTV3_PX4_OA_B.Arm_i != 0) &&
       (RRTV3_PX4_OA_DW.Integrator_PrevResetState_o <= 0)) ||
      ((RRTV3_PX4_OA_B.Arm_i == 0) &&
       (RRTV3_PX4_OA_DW.Integrator_PrevResetState_o == 1))) {
    RRTV3_PX4_OA_DW.Integrator_DSTATE_d = RRTV3_PX4_OA_P.Constant2_Value_o;
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_d >
        RRTV3_PX4_OA_P.Integrator_UpperSat_k) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_d = RRTV3_PX4_OA_P.Integrator_UpperSat_k;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_d <
               RRTV3_PX4_OA_P.Integrator_LowerSat_k) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_d = RRTV3_PX4_OA_P.Integrator_LowerSat_k;
    }
  }

  // End of DiscreteIntegrator: '<S92>/Integrator'

  // RateTransition: '<S5>/Rate Transition' incorporates:
  //   Reshape: '<S5>/Reshape1'
  //   SignalConversion generated from: '<S103>/Matrix Concatenate1'
  //   UnitDelay: '<S75>/UD'
  //  *
  //  Block description for '<S75>/UD':
  //
  //   Store in Global RAM

  if (RRTV3_PX4_OA_M->Timing.RateInteraction.TID0_1) {
    RRTV3_PX4_OA_DW.RateTransition_Buffer[0] = RRTV3_PX4_OA_B.ulat;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[1] = RRTV3_PX4_OA_B.ulon;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[2] = RRTV3_PX4_OA_B.udir;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[3] = RRTV3_PX4_OA_B.LPRPM;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[4] = RRTV3_PX4_OA_B.MPRPM;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[5] = RRTV3_PX4_OA_B.PII_collect[3];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[6] = RRTV3_PX4_OA_B.TCS_Out[3];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[7] = RRTV3_PX4_OA_B.PII_collect[4];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[8] = RRTV3_PX4_OA_B.PII_collect[0];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[9] = RRTV3_PX4_OA_B.PII_collect[1];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[10] = RRTV3_PX4_OA_B.PII_collect[2];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[13] = RRTV3_PX4_OA_B.TCS_Out[2];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[14] = RRTV3_PX4_OA_B.TCS_Out[4];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[11] = RRTV3_PX4_OA_B.TCS_Out[5];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[15] = RRTV3_PX4_OA_B.TCS_Out[0];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[12] = RRTV3_PX4_OA_B.TCS_Out[6];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[16] = RRTV3_PX4_OA_B.TCS_Out[1];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[17] = RRTV3_PX4_OA_B.PII_collect[5];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[18] = RRTV3_PX4_OA_B.PII_collect[6];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[19] = RRTV3_PX4_OA_B.PII_collect[7];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[20] = RRTV3_PX4_OA_B.PII_collect[8];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[21] = RRTV3_PX4_OA_B.PII_collect[11];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[23] = RRTV3_PX4_OA_B.PII_collect[9];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[22] = RRTV3_PX4_OA_B.PII_collect[12];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[24] = RRTV3_PX4_OA_B.PII_collect[10];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[25] = RRTV3_PX4_OA_B.AF;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[26] = RRTV3_PX4_OA_B.GUIDANCE[1];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[27] = RRTV3_PX4_OA_B.GUIDANCE[3];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[28] = RRTV3_PX4_OA_B.GUIDANCE[5];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[29] = RRTV3_PX4_OA_B.MiscOP[8];
    for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 6; RRTV3_PX4_OA_B.i++) {
      RRTV3_PX4_OA_DW.RateTransition_Buffer[RRTV3_PX4_OA_B.i + 30] =
        RRTV3_PX4_OA_B.MiscOP[RRTV3_PX4_OA_B.i];
    }

    RRTV3_PX4_OA_DW.RateTransition_Buffer[36] = RRTV3_PX4_OA_B.In1_d.vel_n_m_s;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[37] = RRTV3_PX4_OA_B.In1_d.vel_e_m_s;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[38] = RRTV3_PX4_OA_B.h2;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[39] = RRTV3_PX4_OA_B.VD;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[40] = RRTV3_PX4_OA_B.m;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[41] = RRTV3_PX4_OA_B.psi;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[42] = RRTV3_PX4_OA_B.KEAS;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[43] = RRTV3_PX4_OA_B.VFWD_kts;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[44] = RRTV3_PX4_OA_B.h_LiDAR;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[45] = RRTV3_PX4_OA_B.ParamStep_fo;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[46] = RRTV3_PX4_OA_B.VCSkt;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[47] = RRTV3_PX4_OA_B.zeta;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[48] = RRTV3_PX4_OA_B.h_Pix;

    // Saturate: '<S92>/Saturation' incorporates:
    //   Reshape: '<S5>/Reshape1'
    //   SignalConversion generated from: '<S103>/Matrix Concatenate1'
    //
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_d >
        RRTV3_PX4_OA_P.Saturation_UpperSat_gl) {
      RRTV3_PX4_OA_DW.RateTransition_Buffer[49] =
        RRTV3_PX4_OA_P.Saturation_UpperSat_gl;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_d <
               RRTV3_PX4_OA_P.Saturation_LowerSat_dd) {
      RRTV3_PX4_OA_DW.RateTransition_Buffer[49] =
        RRTV3_PX4_OA_P.Saturation_LowerSat_dd;
    } else {
      RRTV3_PX4_OA_DW.RateTransition_Buffer[49] =
        RRTV3_PX4_OA_DW.Integrator_DSTATE_d;
    }

    // End of Saturate: '<S92>/Saturation'
    RRTV3_PX4_OA_DW.RateTransition_Buffer[50] = RRTV3_PX4_OA_B.PII_collect[13];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[51] = RRTV3_PX4_OA_B.PII_collect[14];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[52] = RRTV3_PX4_OA_B.PII_collect[15];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[53] = RRTV3_PX4_OA_B.PII_collect[16];
    RRTV3_PX4_OA_DW.RateTransition_Buffer[54] = RRTV3_PX4_OA_B.Control_Level;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[55] = RRTV3_PX4_OA_B.ControlLevel;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[56] = RRTV3_PX4_OA_B.PilotSource;
    RRTV3_PX4_OA_DW.RateTransition_Buffer[57] = RRTV3_PX4_OA_DW.UD_DSTATE_mb;
  }

  // End of RateTransition: '<S5>/Rate Transition'

  // MATLABSystem: '<S54>/AUX 1'
  if (RRTV3_PX4_OA_DW.obj_bge.SampleTime != RRTV3_PX4_OA_P.AUX1_SampleTime) {
    RRTV3_PX4_OA_DW.obj_bge.SampleTime = RRTV3_PX4_OA_P.AUX1_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_bge.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S54>/AUX 2'
  if (RRTV3_PX4_OA_DW.obj_k3.SampleTime != RRTV3_PX4_OA_P.AUX2_SampleTime) {
    RRTV3_PX4_OA_DW.obj_k3.SampleTime = RRTV3_PX4_OA_P.AUX2_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_k3.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_p);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_p = 0.0F;
  }

  // MATLABSystem: '<S54>/AUX 3'
  if (RRTV3_PX4_OA_DW.obj_hg.SampleTime != RRTV3_PX4_OA_P.AUX3_SampleTime) {
    RRTV3_PX4_OA_DW.obj_hg.SampleTime = RRTV3_PX4_OA_P.AUX3_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_hg.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_l);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S54>/AUX 4'
  if (RRTV3_PX4_OA_DW.obj_ml.SampleTime != RRTV3_PX4_OA_P.AUX4_SampleTime) {
    RRTV3_PX4_OA_DW.obj_ml.SampleTime = RRTV3_PX4_OA_P.AUX4_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ml.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_j);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_j = 0.0F;
  }

  // MATLABSystem: '<S54>/AUX 5'
  if (RRTV3_PX4_OA_DW.obj_i43.SampleTime != RRTV3_PX4_OA_P.AUX5_SampleTime) {
    RRTV3_PX4_OA_DW.obj_i43.SampleTime = RRTV3_PX4_OA_P.AUX5_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_i43.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep_d);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_d = 0.0F;
  }

  // MATLABSystem: '<S54>/AUX 12'
  if (RRTV3_PX4_OA_DW.obj_dr.SampleTime != RRTV3_PX4_OA_P.AUX12_SampleTime) {
    RRTV3_PX4_OA_DW.obj_dr.SampleTime = RRTV3_PX4_OA_P.AUX12_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_dr.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_g);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_g = 0.0F;
  }

  // MATLAB Function: '<S3>/Control Surface Mixing' incorporates:
  //   DataTypeConversion: '<S54>/Data Type Conversion'
  //   DataTypeConversion: '<S54>/Data Type Conversion1'
  //   DataTypeConversion: '<S54>/Data Type Conversion11'
  //   DataTypeConversion: '<S54>/Data Type Conversion2'
  //   DataTypeConversion: '<S54>/Data Type Conversion3'
  //   DataTypeConversion: '<S54>/Data Type Conversion4'
  //   MATLABSystem: '<S54>/AUX 1'
  //   MATLABSystem: '<S54>/AUX 12'
  //   MATLABSystem: '<S54>/AUX 2'
  //   MATLABSystem: '<S54>/AUX 3'
  //   MATLABSystem: '<S54>/AUX 4'
  //   MATLABSystem: '<S54>/AUX 5'
  //
  RRTV3_PX4_OA_B.AUX[0] = RRTV3_PX4_OA_B.OutportBufferForControlCmds[0] / 60.0 *
    RRTV3_PX4_OA_B.ParamStep + 0.5;
  RRTV3_PX4_OA_B.AUX[1] = RRTV3_PX4_OA_B.OutportBufferForControlCmds[3] / 60.0 *
    RRTV3_PX4_OA_B.ParamStep_p + 0.5;
  RRTV3_PX4_OA_B.AUX[2] = RRTV3_PX4_OA_B.OutportBufferForControlCmds[4] / 60.0 *
    RRTV3_PX4_OA_B.ParamStep_l + 0.5;
  RRTV3_PX4_OA_B.AUX[3] = RRTV3_PX4_OA_B.OutportBufferForControlCmds[5] / 60.0 *
    RRTV3_PX4_OA_B.ParamStep_j + 0.5;
  RRTV3_PX4_OA_B.AUX[4] = RRTV3_PX4_OA_B.OutportBufferForControlCmds[6] / 60.0 *
    RRTV3_PX4_OA_B.ParamStep_d + 0.5;
  RRTV3_PX4_OA_B.AUX[5] = RRTV3_PX4_OA_B.OutportBufferForControlCmds[8] / 90.0 *
    RRTV3_PX4_OA_B.ParamStep_g;

  // Sum: '<S3>/Sum' incorporates:
  //   Constant: '<S3>/Constant'
  //   Gain: '<S3>/Gain'
  //   Saturate: '<S3>/[0,1]'

  for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 6; RRTV3_PX4_OA_B.i++) {
    // Saturate: '<S3>/[0,1]'
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_B.AUX[RRTV3_PX4_OA_B.i];
    if (RRTV3_PX4_OA_B.z_HDG > RRTV3_PX4_OA_P.u1_UpperSat) {
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.u1_UpperSat;
    } else if (RRTV3_PX4_OA_B.z_HDG < RRTV3_PX4_OA_P.u1_LowerSat) {
      RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.u1_LowerSat;
    }

    RRTV3_PX4_OA_B.AUX[RRTV3_PX4_OA_B.i] = RRTV3_PX4_OA_P.Gain_Gain_d *
      RRTV3_PX4_OA_B.z_HDG + RRTV3_PX4_OA_P.Constant_Value_c;
  }

  // End of Sum: '<S3>/Sum'

  // MATLABSystem: '<S54>/AUX 7'
  if (RRTV3_PX4_OA_DW.obj_jk.SampleTime != RRTV3_PX4_OA_P.AUX7_SampleTime) {
    RRTV3_PX4_OA_DW.obj_jk.SampleTime = RRTV3_PX4_OA_P.AUX7_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_jk.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S54>/AUX 8'
  if (RRTV3_PX4_OA_DW.obj_ne.SampleTime != RRTV3_PX4_OA_P.AUX8_SampleTime) {
    RRTV3_PX4_OA_DW.obj_ne.SampleTime = RRTV3_PX4_OA_P.AUX8_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ne.MW_PARAMHANDLE, MW_SINGLE,
    &RRTV3_PX4_OA_B.ParamStep_p);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep_p = 0.0F;
  }

  // DataTypeConversion: '<S71>/Data Type Conversion6'
  for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 5; RRTV3_PX4_OA_B.i++) {
    RRTV3_PX4_OA_B.LatRad = floor(RRTV3_PX4_OA_B.AUX[RRTV3_PX4_OA_B.i]);
    if (rtIsNaN(RRTV3_PX4_OA_B.LatRad) || rtIsInf(RRTV3_PX4_OA_B.LatRad)) {
      RRTV3_PX4_OA_B.LatRad = 0.0;
    } else {
      RRTV3_PX4_OA_B.LatRad = fmod(RRTV3_PX4_OA_B.LatRad, 65536.0);
    }

    RRTV3_PX4_OA_B.DataTypeConversion6[RRTV3_PX4_OA_B.i] = static_cast<uint16_T>
      (RRTV3_PX4_OA_B.LatRad < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(
         -static_cast<int16_T>(static_cast<uint16_T>(-RRTV3_PX4_OA_B.LatRad)))) :
       static_cast<int32_T>(static_cast<uint16_T>(RRTV3_PX4_OA_B.LatRad)));
  }

  // MATLAB Function: '<S71>/MATLAB Function'
  if (RRTV3_PX4_OA_B.AUX[5] <= 2000.0) {
    RRTV3_PX4_OA_B.LatRad = RRTV3_PX4_OA_B.AUX[5];
  } else {
    RRTV3_PX4_OA_B.LatRad = 2000.0;
  }

  if (!(RRTV3_PX4_OA_B.LatRad >= 1000.0)) {
    RRTV3_PX4_OA_B.LatRad = 1000.0;
  }

  // DataTypeConversion: '<S71>/Data Type Conversion6' incorporates:
  //   DataTypeConversion: '<S54>/Data Type Conversion6'
  //   DataTypeConversion: '<S54>/Data Type Conversion7'
  //   MATLAB Function: '<S71>/MATLAB Function'
  //   MATLABSystem: '<S54>/AUX 7'
  //   MATLABSystem: '<S54>/AUX 8'
  //
  RRTV3_PX4_OA_B.LatRad = floor((static_cast<real_T>(RRTV3_PX4_OA_B.ParamStep_p)
    - RRTV3_PX4_OA_B.ParamStep) * (RRTV3_PX4_OA_B.LatRad - 1000.0) / 1000.0 +
    RRTV3_PX4_OA_B.ParamStep);
  if (rtIsNaN(RRTV3_PX4_OA_B.LatRad) || rtIsInf(RRTV3_PX4_OA_B.LatRad)) {
    RRTV3_PX4_OA_B.LatRad = 0.0;
  } else {
    RRTV3_PX4_OA_B.LatRad = fmod(RRTV3_PX4_OA_B.LatRad, 65536.0);
  }

  // MATLABSystem: '<S3>/PX4 PWM Output1' incorporates:
  //   DataTypeConversion: '<S4>/Cast To Boolean'
  //   DataTypeConversion: '<S4>/Cast To Boolean1'
  //   DataTypeConversion: '<S71>/Data Type Conversion6'

  for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 8; RRTV3_PX4_OA_B.i++) {
    RRTV3_PX4_OA_B.pwmValue[RRTV3_PX4_OA_B.i] = 0U;
  }

  RRTV3_PX4_OA_B.pwmValue[0] = RRTV3_PX4_OA_B.DataTypeConversion6[0];
  RRTV3_PX4_OA_B.pwmValue[1] = RRTV3_PX4_OA_B.DataTypeConversion6[1];
  RRTV3_PX4_OA_B.pwmValue[2] = RRTV3_PX4_OA_B.DataTypeConversion6[2];
  RRTV3_PX4_OA_B.pwmValue[3] = RRTV3_PX4_OA_B.DataTypeConversion6[3];
  RRTV3_PX4_OA_B.pwmValue[4] = RRTV3_PX4_OA_B.DataTypeConversion6[4];
  RRTV3_PX4_OA_B.pwmValue[5] = static_cast<uint16_T>(RRTV3_PX4_OA_B.LatRad < 0.0
    ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-RRTV3_PX4_OA_B.LatRad)))) : static_cast<int32_T>(
    static_cast<uint16_T>(RRTV3_PX4_OA_B.LatRad)));
  if (RRTV3_PX4_OA_B.Arm_i != 0) {
    if (!RRTV3_PX4_OA_DW.obj_ec.isArmed) {
      RRTV3_PX4_OA_DW.obj_ec.isArmed = true;
      pwm_arm(&RRTV3_PX4_OA_DW.obj_ec.armAdvertiseObj);
    }

    pwm_setServo(RRTV3_PX4_OA_DW.obj_ec.servoCount,
                 RRTV3_PX4_OA_DW.obj_ec.channelMask, &RRTV3_PX4_OA_B.pwmValue[0],
                 RRTV3_PX4_OA_DW.obj_ec.isMain,
                 &RRTV3_PX4_OA_DW.obj_ec.actuatorAdvertiseObj);
  } else {
    pwm_disarm(&RRTV3_PX4_OA_DW.obj_ec.armAdvertiseObj);
    RRTV3_PX4_OA_DW.obj_ec.isArmed = false;
    pwm_resetServo(RRTV3_PX4_OA_DW.obj_ec.servoCount,
                   RRTV3_PX4_OA_DW.obj_ec.isMain,
                   &RRTV3_PX4_OA_DW.obj_ec.actuatorAdvertiseObj);
  }

  if (RRTV3_PX4_OA_DW.obj_ec.isMain) {
    if (RRTV3_PX4_OA_B.Kill_p != 0) {
      pwm_disarm(&RRTV3_PX4_OA_DW.obj_ec.armAdvertiseObj);
    } else {
      pwm_arm(&RRTV3_PX4_OA_DW.obj_ec.armAdvertiseObj);
    }
  }

  // End of MATLABSystem: '<S3>/PX4 PWM Output1'

  // Sum: '<S73>/Sum' incorporates:
  //   Constant: '<S73>/Constant'
  //   UnitDelay: '<S75>/UD'
  //
  //  Block description for '<S75>/UD':
  //
  //   Store in Global RAM

  RRTV3_PX4_OA_B.PilotSource = RRTV3_PX4_OA_P.Constant_Value_o -
    RRTV3_PX4_OA_DW.UD_DSTATE_mb;

  // MATLABSystem: '<S50>/Max Phi Cmd12'
  if (RRTV3_PX4_OA_DW.obj_eui.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime) {
    RRTV3_PX4_OA_DW.obj_eui.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_eui.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep = 0.0F;
  }

  // Lookup_n-D: '<S73>/Main Prop 1'
  RRTV3_PX4_OA_B.m = look1_binlxpw(RRTV3_PX4_OA_B.OutportBufferForControlCmds[12],
    RRTV3_PX4_OA_P.MainProp1_bp01Data, RRTV3_PX4_OA_P.MainProp1_tableData, 19U);

  // Lookup_n-D: '<S73>/Main Prop 2'
  RRTV3_PX4_OA_B.VD = look1_binlxpw(RRTV3_PX4_OA_B.OutportBufferForControlCmds
    [13], RRTV3_PX4_OA_P.MainProp2_bp01Data, RRTV3_PX4_OA_P.MainProp2_tableData,
    19U);

  // Saturate: '<S73>/[1000,2000]' incorporates:
  //   Lookup_n-D: '<S73>/Main Prop 1'

  if (RRTV3_PX4_OA_B.m > RRTV3_PX4_OA_P.u0002000_UpperSat) {
    RRTV3_PX4_OA_B.m = RRTV3_PX4_OA_P.u0002000_UpperSat;
  } else if (RRTV3_PX4_OA_B.m < RRTV3_PX4_OA_P.u0002000_LowerSat) {
    RRTV3_PX4_OA_B.m = RRTV3_PX4_OA_P.u0002000_LowerSat;
  }

  // Saturate: '<S73>/[1000 2000]' incorporates:
  //   DataTypeConversion: '<S50>/Data Type Conversion5'
  //   MATLABSystem: '<S50>/Max Phi Cmd12'
  //   Product: '<S73>/Divide'
  //   Saturate: '<S73>/[1000,2000]'
  //   Sum: '<S73>/Add'
  //
  RRTV3_PX4_OA_B.z_HDG = (RRTV3_PX4_OA_B.m + RRTV3_PX4_OA_B.ParamStep) *
    RRTV3_PX4_OA_B.PilotSource;
  if (RRTV3_PX4_OA_B.z_HDG > RRTV3_PX4_OA_P.u0002000_UpperSat_b) {
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.u0002000_UpperSat_b;
  } else if (RRTV3_PX4_OA_B.z_HDG < RRTV3_PX4_OA_P.u0002000_LowerSat_a) {
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.u0002000_LowerSat_a;
  }

  // DataTypeConversion: '<S73>/Data Type Conversion1' incorporates:
  //   Saturate: '<S73>/[1000 2000]'

  RRTV3_PX4_OA_B.LatRad = floor(RRTV3_PX4_OA_B.z_HDG);
  if (rtIsNaN(RRTV3_PX4_OA_B.LatRad) || rtIsInf(RRTV3_PX4_OA_B.LatRad)) {
    RRTV3_PX4_OA_B.LatRad = 0.0;
  } else {
    RRTV3_PX4_OA_B.LatRad = fmod(RRTV3_PX4_OA_B.LatRad, 65536.0);
  }

  // Saturate: '<S73>/[1000,2000]' incorporates:
  //   Lookup_n-D: '<S73>/Main Prop 2'

  if (RRTV3_PX4_OA_B.VD > RRTV3_PX4_OA_P.u0002000_UpperSat) {
    RRTV3_PX4_OA_B.VD = RRTV3_PX4_OA_P.u0002000_UpperSat;
  } else if (RRTV3_PX4_OA_B.VD < RRTV3_PX4_OA_P.u0002000_LowerSat) {
    RRTV3_PX4_OA_B.VD = RRTV3_PX4_OA_P.u0002000_LowerSat;
  }

  // Saturate: '<S73>/[1000 2000]' incorporates:
  //   DataTypeConversion: '<S50>/Data Type Conversion5'
  //   MATLABSystem: '<S50>/Max Phi Cmd12'
  //   Product: '<S73>/Divide'
  //   Saturate: '<S73>/[1000,2000]'
  //   Sum: '<S73>/Add'
  //
  RRTV3_PX4_OA_B.z_HDG = (RRTV3_PX4_OA_B.VD + RRTV3_PX4_OA_B.ParamStep) *
    RRTV3_PX4_OA_B.PilotSource;
  if (RRTV3_PX4_OA_B.z_HDG > RRTV3_PX4_OA_P.u0002000_UpperSat_b) {
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.u0002000_UpperSat_b;
  } else if (RRTV3_PX4_OA_B.z_HDG < RRTV3_PX4_OA_P.u0002000_LowerSat_a) {
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.u0002000_LowerSat_a;
  }

  // DataTypeConversion: '<S73>/Data Type Conversion1' incorporates:
  //   Saturate: '<S73>/[1000 2000]'

  RRTV3_PX4_OA_B.ControlLevel = floor(RRTV3_PX4_OA_B.z_HDG);
  if (rtIsNaN(RRTV3_PX4_OA_B.ControlLevel) || rtIsInf
      (RRTV3_PX4_OA_B.ControlLevel)) {
    RRTV3_PX4_OA_B.ControlLevel = 0.0;
  } else {
    RRTV3_PX4_OA_B.ControlLevel = fmod(RRTV3_PX4_OA_B.ControlLevel, 65536.0);
  }

  // MATLABSystem: '<S50>/Max Phi Cmd5'
  if (RRTV3_PX4_OA_DW.obj_ftm.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_ftm.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(RRTV3_PX4_OA_DW.obj_ftm.MW_PARAMHANDLE,
    MW_SINGLE, &RRTV3_PX4_OA_B.ParamStep);
  if (b_varargout_1) {
    RRTV3_PX4_OA_B.ParamStep = 0.0F;
  }

  // Lookup_n-D: '<S73>/Tail Prop 1 (UP)'
  RRTV3_PX4_OA_B.m = look1_binlxpw(RRTV3_PX4_OA_B.OutportBufferForControlCmds[14],
    RRTV3_PX4_OA_P.TPRPM_ext, RRTV3_PX4_OA_P.TPPWM_ext, 20U);

  // Lookup_n-D: '<S73>/Tail Prop 2 (DOWN)'
  RRTV3_PX4_OA_B.VD = look1_binlxpw(RRTV3_PX4_OA_B.OutportBufferForControlCmds
    [15], RRTV3_PX4_OA_P.TPRPM_ext, RRTV3_PX4_OA_P.TPPWM_ext, 20U);

  // Saturate: '<S73>/[1000,2000]1' incorporates:
  //   Lookup_n-D: '<S73>/Tail Prop 1 (UP)'

  if (RRTV3_PX4_OA_B.m > RRTV3_PX4_OA_P.u00020001_UpperSat) {
    RRTV3_PX4_OA_B.m = RRTV3_PX4_OA_P.u00020001_UpperSat;
  } else if (RRTV3_PX4_OA_B.m < RRTV3_PX4_OA_P.u00020001_LowerSat) {
    RRTV3_PX4_OA_B.m = RRTV3_PX4_OA_P.u00020001_LowerSat;
  }

  // Saturate: '<S73>/[1000 2000]1' incorporates:
  //   DataTypeConversion: '<S50>/Data Type Conversion6'
  //   MATLABSystem: '<S50>/Max Phi Cmd5'
  //   Product: '<S73>/Divide1'
  //   Saturate: '<S73>/[1000,2000]1'
  //   Sum: '<S73>/Add1'
  //
  RRTV3_PX4_OA_B.z_HDG = (RRTV3_PX4_OA_B.ParamStep + RRTV3_PX4_OA_B.m) *
    RRTV3_PX4_OA_B.PilotSource;
  if (RRTV3_PX4_OA_B.z_HDG > RRTV3_PX4_OA_P.u00020001_UpperSat_h) {
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.u00020001_UpperSat_h;
  } else if (RRTV3_PX4_OA_B.z_HDG < RRTV3_PX4_OA_P.u00020001_LowerSat_h) {
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.u00020001_LowerSat_h;
  }

  // DataTypeConversion: '<S73>/Data Type Conversion2' incorporates:
  //   Saturate: '<S73>/[1000 2000]1'

  RRTV3_PX4_OA_B.m = floor(RRTV3_PX4_OA_B.z_HDG);
  if (rtIsNaN(RRTV3_PX4_OA_B.m) || rtIsInf(RRTV3_PX4_OA_B.m)) {
    RRTV3_PX4_OA_B.m = 0.0;
  } else {
    RRTV3_PX4_OA_B.m = fmod(RRTV3_PX4_OA_B.m, 65536.0);
  }

  // Saturate: '<S73>/[1000,2000]1' incorporates:
  //   Lookup_n-D: '<S73>/Tail Prop 2 (DOWN)'

  if (RRTV3_PX4_OA_B.VD > RRTV3_PX4_OA_P.u00020001_UpperSat) {
    RRTV3_PX4_OA_B.VD = RRTV3_PX4_OA_P.u00020001_UpperSat;
  } else if (RRTV3_PX4_OA_B.VD < RRTV3_PX4_OA_P.u00020001_LowerSat) {
    RRTV3_PX4_OA_B.VD = RRTV3_PX4_OA_P.u00020001_LowerSat;
  }

  // Saturate: '<S73>/[1000 2000]1' incorporates:
  //   DataTypeConversion: '<S50>/Data Type Conversion6'
  //   MATLABSystem: '<S50>/Max Phi Cmd5'
  //   Product: '<S73>/Divide1'
  //   Saturate: '<S73>/[1000,2000]1'
  //   Sum: '<S73>/Add1'
  //
  RRTV3_PX4_OA_B.z_HDG = (RRTV3_PX4_OA_B.ParamStep + RRTV3_PX4_OA_B.VD) *
    RRTV3_PX4_OA_B.PilotSource;
  if (RRTV3_PX4_OA_B.z_HDG > RRTV3_PX4_OA_P.u00020001_UpperSat_h) {
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.u00020001_UpperSat_h;
  } else if (RRTV3_PX4_OA_B.z_HDG < RRTV3_PX4_OA_P.u00020001_LowerSat_h) {
    RRTV3_PX4_OA_B.z_HDG = RRTV3_PX4_OA_P.u00020001_LowerSat_h;
  }

  // DataTypeConversion: '<S73>/Data Type Conversion2' incorporates:
  //   Saturate: '<S73>/[1000 2000]1'

  RRTV3_PX4_OA_B.PilotSource = floor(RRTV3_PX4_OA_B.z_HDG);
  if (rtIsNaN(RRTV3_PX4_OA_B.PilotSource) || rtIsInf(RRTV3_PX4_OA_B.PilotSource))
  {
    RRTV3_PX4_OA_B.PilotSource = 0.0;
  } else {
    RRTV3_PX4_OA_B.PilotSource = fmod(RRTV3_PX4_OA_B.PilotSource, 65536.0);
  }

  // MATLABSystem: '<S3>/PX4 PWM Output' incorporates:
  //   DataTypeConversion: '<S4>/Cast To Boolean'
  //   DataTypeConversion: '<S4>/Cast To Boolean1'
  //   DataTypeConversion: '<S73>/Data Type Conversion1'
  //   DataTypeConversion: '<S73>/Data Type Conversion2'

  for (RRTV3_PX4_OA_B.i = 0; RRTV3_PX4_OA_B.i < 8; RRTV3_PX4_OA_B.i++) {
    RRTV3_PX4_OA_B.pwmValue[RRTV3_PX4_OA_B.i] = 0U;
  }

  RRTV3_PX4_OA_B.pwmValue[0] = static_cast<uint16_T>(RRTV3_PX4_OA_B.LatRad < 0.0
    ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-RRTV3_PX4_OA_B.LatRad)))) : static_cast<int32_T>(
    static_cast<uint16_T>(RRTV3_PX4_OA_B.LatRad)));
  RRTV3_PX4_OA_B.pwmValue[1] = static_cast<uint16_T>(RRTV3_PX4_OA_B.ControlLevel
    < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-RRTV3_PX4_OA_B.ControlLevel)))) : static_cast<int32_T>
    (static_cast<uint16_T>(RRTV3_PX4_OA_B.ControlLevel)));
  RRTV3_PX4_OA_B.pwmValue[2] = static_cast<uint16_T>(RRTV3_PX4_OA_B.m < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-RRTV3_PX4_OA_B.m)))) : static_cast<int32_T>(
    static_cast<uint16_T>(RRTV3_PX4_OA_B.m)));
  RRTV3_PX4_OA_B.pwmValue[3] = static_cast<uint16_T>(RRTV3_PX4_OA_B.PilotSource <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-RRTV3_PX4_OA_B.PilotSource)))) : static_cast<int32_T>
    (static_cast<uint16_T>(RRTV3_PX4_OA_B.PilotSource)));
  if (RRTV3_PX4_OA_B.Arm_i != 0) {
    if (!RRTV3_PX4_OA_DW.obj_gg.isArmed) {
      RRTV3_PX4_OA_DW.obj_gg.isArmed = true;
      pwm_arm(&RRTV3_PX4_OA_DW.obj_gg.armAdvertiseObj);
    }

    pwm_setServo(RRTV3_PX4_OA_DW.obj_gg.servoCount,
                 RRTV3_PX4_OA_DW.obj_gg.channelMask, &RRTV3_PX4_OA_B.pwmValue[0],
                 RRTV3_PX4_OA_DW.obj_gg.isMain,
                 &RRTV3_PX4_OA_DW.obj_gg.actuatorAdvertiseObj);
  } else {
    pwm_disarm(&RRTV3_PX4_OA_DW.obj_gg.armAdvertiseObj);
    RRTV3_PX4_OA_DW.obj_gg.isArmed = false;
    pwm_resetServo(RRTV3_PX4_OA_DW.obj_gg.servoCount,
                   RRTV3_PX4_OA_DW.obj_gg.isMain,
                   &RRTV3_PX4_OA_DW.obj_gg.actuatorAdvertiseObj);
  }

  if (RRTV3_PX4_OA_DW.obj_gg.isMain) {
    if (RRTV3_PX4_OA_B.Kill_p != 0) {
      pwm_disarm(&RRTV3_PX4_OA_DW.obj_gg.armAdvertiseObj);
    } else {
      pwm_arm(&RRTV3_PX4_OA_DW.obj_gg.armAdvertiseObj);
    }
  }

  // End of MATLABSystem: '<S3>/PX4 PWM Output'

  // MATLABSystem: '<S49>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_e2.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_e2.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_e2.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S49>/Max Phi Cmd1'

  // MATLABSystem: '<S49>/Max Phi Cmd2'
  if (RRTV3_PX4_OA_DW.obj_ck.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_ck.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_ck.MW_PARAMHANDLE, MW_INT32,
                &RRTV3_PX4_OA_B.ParamStep_m0);

  // End of MATLABSystem: '<S49>/Max Phi Cmd2'

  // MATLABSystem: '<S49>/Max Phi Cmd8'
  if (RRTV3_PX4_OA_DW.obj_j4.SampleTime != RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime)
  {
    RRTV3_PX4_OA_DW.obj_j4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_j4.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S49>/Max Phi Cmd8'

  // MATLABSystem: '<S50>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_o2.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_k) {
    RRTV3_PX4_OA_DW.obj_o2.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_k;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_o2.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S50>/Max Phi Cmd1'

  // MATLABSystem: '<S51>/Max Phi Cmd1'
  if (RRTV3_PX4_OA_DW.obj_hm.SampleTime !=
      RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_du) {
    RRTV3_PX4_OA_DW.obj_hm.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_du;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_hm.MW_PARAMHANDLE, MW_INT32,
                &RRTV3_PX4_OA_B.ParamStep_m0);

  // End of MATLABSystem: '<S51>/Max Phi Cmd1'

  // MATLABSystem: '<S54>/AUX 10'
  if (RRTV3_PX4_OA_DW.obj_cd.SampleTime != RRTV3_PX4_OA_P.AUX10_SampleTime) {
    RRTV3_PX4_OA_DW.obj_cd.SampleTime = RRTV3_PX4_OA_P.AUX10_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_cd.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S54>/AUX 10'

  // MATLABSystem: '<S54>/AUX 11'
  if (RRTV3_PX4_OA_DW.obj_cf1.SampleTime != RRTV3_PX4_OA_P.AUX11_SampleTime) {
    RRTV3_PX4_OA_DW.obj_cf1.SampleTime = RRTV3_PX4_OA_P.AUX11_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_cf1.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S54>/AUX 11'

  // MATLABSystem: '<S54>/AUX 13'
  if (RRTV3_PX4_OA_DW.obj_ca.SampleTime != RRTV3_PX4_OA_P.AUX13_SampleTime) {
    RRTV3_PX4_OA_DW.obj_ca.SampleTime = RRTV3_PX4_OA_P.AUX13_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_ca.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S54>/AUX 13'

  // MATLABSystem: '<S54>/AUX 14'
  if (RRTV3_PX4_OA_DW.obj_dv.SampleTime != RRTV3_PX4_OA_P.AUX14_SampleTime) {
    RRTV3_PX4_OA_DW.obj_dv.SampleTime = RRTV3_PX4_OA_P.AUX14_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_dv.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S54>/AUX 14'

  // MATLABSystem: '<S54>/AUX 15'
  if (RRTV3_PX4_OA_DW.obj_ik.SampleTime != RRTV3_PX4_OA_P.AUX15_SampleTime) {
    RRTV3_PX4_OA_DW.obj_ik.SampleTime = RRTV3_PX4_OA_P.AUX15_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_ik.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S54>/AUX 15'

  // MATLABSystem: '<S54>/AUX 16'
  if (RRTV3_PX4_OA_DW.obj_f0.SampleTime != RRTV3_PX4_OA_P.AUX16_SampleTime) {
    RRTV3_PX4_OA_DW.obj_f0.SampleTime = RRTV3_PX4_OA_P.AUX16_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_f0.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S54>/AUX 16'

  // MATLABSystem: '<S54>/AUX 17'
  if (RRTV3_PX4_OA_DW.obj_kf.SampleTime != RRTV3_PX4_OA_P.AUX17_SampleTime) {
    RRTV3_PX4_OA_DW.obj_kf.SampleTime = RRTV3_PX4_OA_P.AUX17_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_kf.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S54>/AUX 17'

  // MATLABSystem: '<S54>/AUX 18'
  if (RRTV3_PX4_OA_DW.obj_pb0.SampleTime != RRTV3_PX4_OA_P.AUX18_SampleTime) {
    RRTV3_PX4_OA_DW.obj_pb0.SampleTime = RRTV3_PX4_OA_P.AUX18_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_pb0.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S54>/AUX 18'

  // MATLABSystem: '<S54>/AUX 6'
  if (RRTV3_PX4_OA_DW.obj_cj.SampleTime != RRTV3_PX4_OA_P.AUX6_SampleTime) {
    RRTV3_PX4_OA_DW.obj_cj.SampleTime = RRTV3_PX4_OA_P.AUX6_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_cj.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S54>/AUX 6'

  // MATLABSystem: '<S54>/AUX 9'
  if (RRTV3_PX4_OA_DW.obj_np.SampleTime != RRTV3_PX4_OA_P.AUX9_SampleTime) {
    RRTV3_PX4_OA_DW.obj_np.SampleTime = RRTV3_PX4_OA_P.AUX9_SampleTime;
  }

  MW_Param_Step(RRTV3_PX4_OA_DW.obj_np.MW_PARAMHANDLE, MW_SINGLE,
                &RRTV3_PX4_OA_B.ParamStep);

  // End of MATLABSystem: '<S54>/AUX 9'

  // Update for DiscreteIntegrator: '<S120>/Integrator' incorporates:
  //   Constant: '<S102>/Constant'

  RRTV3_PX4_OA_DW.Integrator_IC_LOADING = 0U;
  RRTV3_PX4_OA_DW.Integrator_DSTATE += RRTV3_PX4_OA_P.Integrator_gainval_jr *
    RRTV3_PX4_OA_B.Arm;
  if (RRTV3_PX4_OA_DW.Integrator_DSTATE > RRTV3_PX4_OA_P.Integrator_UpperSat_j)
  {
    RRTV3_PX4_OA_DW.Integrator_DSTATE = RRTV3_PX4_OA_P.Integrator_UpperSat_j;
  } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE <
             RRTV3_PX4_OA_P.Integrator_LowerSat_n) {
    RRTV3_PX4_OA_DW.Integrator_DSTATE = RRTV3_PX4_OA_P.Integrator_LowerSat_n;
  }

  if (RRTV3_PX4_OA_P.Constant_Value_b3 > 0.0) {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState = 1;
  } else if (RRTV3_PX4_OA_P.Constant_Value_b3 < 0.0) {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState = -1;
  } else if (RRTV3_PX4_OA_P.Constant_Value_b3 == 0.0) {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState = 0;
  } else {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState = 2;
  }

  // End of Update for DiscreteIntegrator: '<S120>/Integrator'

  // Update for DiscreteIntegrator: '<S115>/Integrator' incorporates:
  //   Constant: '<S101>/Constant'

  RRTV3_PX4_OA_DW.Integrator_IC_LOADING_p = 0U;
  RRTV3_PX4_OA_DW.Integrator_DSTATE_c += RRTV3_PX4_OA_P.Integrator_gainval_e *
    RRTV3_PX4_OA_B.Kill;
  if (RRTV3_PX4_OA_DW.Integrator_DSTATE_c >
      RRTV3_PX4_OA_P.Integrator_UpperSat_gg) {
    RRTV3_PX4_OA_DW.Integrator_DSTATE_c = RRTV3_PX4_OA_P.Integrator_UpperSat_gg;
  } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_c <
             RRTV3_PX4_OA_P.Integrator_LowerSat_ln) {
    RRTV3_PX4_OA_DW.Integrator_DSTATE_c = RRTV3_PX4_OA_P.Integrator_LowerSat_ln;
  }

  if (RRTV3_PX4_OA_P.Constant_Value_in > 0.0) {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_b = 1;
  } else if (RRTV3_PX4_OA_P.Constant_Value_in < 0.0) {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_b = -1;
  } else if (RRTV3_PX4_OA_P.Constant_Value_in == 0.0) {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_b = 0;
  } else {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_b = 2;
  }

  // End of Update for DiscreteIntegrator: '<S115>/Integrator'

  // Update for DiscreteIntegrator: '<S97>/Integrator' incorporates:
  //   Constant: '<S6>/Constant'

  RRTV3_PX4_OA_DW.Integrator_DSTATE_e += RRTV3_PX4_OA_P.Integrator_gainval_h *
    RRTV3_PX4_OA_B.TBI;
  if (RRTV3_PX4_OA_DW.Integrator_DSTATE_e > RRTV3_PX4_OA_P.Integrator_UpperSat_e)
  {
    RRTV3_PX4_OA_DW.Integrator_DSTATE_e = RRTV3_PX4_OA_P.Integrator_UpperSat_e;
  } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_e <
             RRTV3_PX4_OA_P.Integrator_LowerSat_m5) {
    RRTV3_PX4_OA_DW.Integrator_DSTATE_e = RRTV3_PX4_OA_P.Integrator_LowerSat_m5;
  }

  if (RRTV3_PX4_OA_P.Constant_Value_it > 0.0) {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_n = 1;
  } else if (RRTV3_PX4_OA_P.Constant_Value_it < 0.0) {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_n = -1;
  } else if (RRTV3_PX4_OA_P.Constant_Value_it == 0.0) {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_n = 0;
  } else {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_n = 2;
  }

  // End of Update for DiscreteIntegrator: '<S97>/Integrator'

  // Update for DiscreteIntegrator: '<S92>/Integrator' incorporates:
  //   DataTypeConversion: '<S4>/Cast To Boolean'
  //   DataTypeConversion: '<S5>/Cast To Double4'

  RRTV3_PX4_OA_DW.Integrator_DSTATE_d += static_cast<real_T>
    (RRTV3_PX4_OA_B.Arm_i != 0) * RRTV3_PX4_OA_P.Integrator_gainval_n;
  if (RRTV3_PX4_OA_DW.Integrator_DSTATE_d > RRTV3_PX4_OA_P.Integrator_UpperSat_k)
  {
    RRTV3_PX4_OA_DW.Integrator_DSTATE_d = RRTV3_PX4_OA_P.Integrator_UpperSat_k;
  } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_d <
             RRTV3_PX4_OA_P.Integrator_LowerSat_k) {
    RRTV3_PX4_OA_DW.Integrator_DSTATE_d = RRTV3_PX4_OA_P.Integrator_LowerSat_k;
  }

  if (RRTV3_PX4_OA_B.Arm_i != 0) {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_o = 1;
  } else {
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_o = 0;
  }

  // End of Update for DiscreteIntegrator: '<S92>/Integrator'
}

// Model step function for TID1
void RRTV3_PX4_OA_step1(void)          // Sample time: [0.06s, 0.0s]
{
  // BusAssignment: '<S5>/Bus Assignment' incorporates:
  //   Constant: '<S90>/Constant'

  RRTV3_PX4_OA_B.BusAssignment = RRTV3_PX4_OA_P.Constant_Value;

  // BusAssignment: '<S5>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Single'
  //   RateTransition: '<S5>/Rate Transition'

  for (int32_T i = 0; i < 58; i++) {
    RRTV3_PX4_OA_B.BusAssignment.data[i] = static_cast<real32_T>
      (RRTV3_PX4_OA_DW.RateTransition_Buffer[i]);
  }

  // MATLABSystem: '<S91>/SinkBlock' incorporates:
  //   BusAssignment: '<S5>/Bus Assignment'

  uORB_write_step(RRTV3_PX4_OA_DW.obj_ej.orbMetadataObj,
                  &RRTV3_PX4_OA_DW.obj_ej.orbAdvertiseObj,
                  &RRTV3_PX4_OA_B.BusAssignment);
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void RRTV3_PX4_OA_step(int_T tid)
{
  switch (tid) {
   case 0 :
    RRTV3_PX4_OA_step0();
    break;

   case 1 :
    RRTV3_PX4_OA_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void RRTV3_PX4_OA_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  RRTV3_PX4_OA_P.FilteredDerivative2_A = rtMinusInf;
  RRTV3_PX4_OA_P.FilteredDerivative1_A = rtMinusInf;
  RRTV3_PX4_OA_P.FilteredDerivative2_B = rtInf;
  RRTV3_PX4_OA_P.FilteredDerivative1_B = rtInf;
  RRTV3_PX4_OA_P.Saturation_UpperSat = rtInf;
  RRTV3_PX4_OA_P.Saturation_LowerSat = rtMinusInf;
  RRTV3_PX4_OA_P.Integrator_UpperSat_l = rtInf;
  RRTV3_PX4_OA_P.Integrator_LowerSat_h = rtMinusInf;
  RRTV3_PX4_OA_P.Saturation_UpperSat_b = rtInf;
  RRTV3_PX4_OA_P.Saturation_LowerSat_n = rtMinusInf;
  RRTV3_PX4_OA_P.Saturation_UpperSat_f = rtInf;
  RRTV3_PX4_OA_P.Saturation_LowerSat_l = rtMinusInf;
  RRTV3_PX4_OA_P.Saturation_UpperSat_n = rtInf;
  RRTV3_PX4_OA_P.Saturation_LowerSat_m = rtMinusInf;
  RRTV3_PX4_OA_P.Integrator_UpperSat_pu = rtInf;
  RRTV3_PX4_OA_P.Integrator_LowerSat_i = rtMinusInf;
  RRTV3_PX4_OA_P.Saturation_UpperSat_g = rtInf;
  RRTV3_PX4_OA_P.Saturation_LowerSat_b = rtMinusInf;
  RRTV3_PX4_OA_P.Saturation_UpperSat_fv = rtInf;
  RRTV3_PX4_OA_P.Saturation_LowerSat_j = rtMinusInf;
  RRTV3_PX4_OA_P.Saturation_UpperSat_bs = rtInf;
  RRTV3_PX4_OA_P.Saturation_LowerSat_b3 = rtMinusInf;
  RRTV3_PX4_OA_P.Saturation_UpperSat_m = rtInf;
  RRTV3_PX4_OA_P.Saturation_LowerSat_bj = rtMinusInf;
  RRTV3_PX4_OA_P.Integrator_UpperSat_j = rtInf;
  RRTV3_PX4_OA_P.Integrator_LowerSat_n = rtMinusInf;
  RRTV3_PX4_OA_P.Saturation_UpperSat_h = rtInf;
  RRTV3_PX4_OA_P.Saturation_LowerSat_mt = rtMinusInf;
  RRTV3_PX4_OA_P.Integrator_UpperSat_gg = rtInf;
  RRTV3_PX4_OA_P.Integrator_LowerSat_ln = rtMinusInf;
  RRTV3_PX4_OA_P.Saturation_UpperSat_k = rtInf;
  RRTV3_PX4_OA_P.Saturation_LowerSat_d = rtMinusInf;
  RRTV3_PX4_OA_P.Integrator_UpperSat_e = rtInf;
  RRTV3_PX4_OA_P.Integrator_LowerSat_m5 = rtMinusInf;
  RRTV3_PX4_OA_P.Saturation_UpperSat_a = rtInf;
  RRTV3_PX4_OA_P.Saturation_LowerSat_o = rtMinusInf;
  RRTV3_PX4_OA_P.Integrator_UpperSat_k = rtInf;
  RRTV3_PX4_OA_P.Integrator_LowerSat_k = rtMinusInf;
  RRTV3_PX4_OA_P.Saturation_UpperSat_gl = rtInf;
  RRTV3_PX4_OA_P.Saturation_LowerSat_dd = rtMinusInf;

  // block I/O
  (void) memset((static_cast<void *>(&RRTV3_PX4_OA_B)), 0,
                sizeof(B_RRTV3_PX4_OA_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&RRTV3_PX4_OA_DW), 0,
                sizeof(DW_RRTV3_PX4_OA_T));

  {
    static const char_T ParameterNameStr[13] = "SM_VV_SOURCE";
    static const char_T ParameterNameStr_0[13] = "EKF2_MIN_RNG";
    static const char_T ParameterNameStr_1[14] = "SM_HDG_OFFSET";
    static const char_T ParameterNameStr_2[12] = "SM_SPD_MODE";
    static const char_T ParameterNameStr_3[10] = "SM_SPD_V1";
    static const char_T ParameterNameStr_4[10] = "SM_SPD_V2";
    static const char_T ParameterNameStr_5[15] = "SM_LIDAR_HMODE";
    static const char_T ParameterNameStr_6[16] = "SM_LIDAR_VVMODE";
    static const char_T ParameterNameStr_7[12] = "SM_LIDAR_H1";
    static const char_T ParameterNameStr_8[12] = "SM_LIDAR_H2";
    static const char_T ParameterNameStr_9[13] = "SM_LIDAR_TAU";
    static const char_T ParameterNameStr_a[11] = "SM_PI_MODE";
    static const char_T ParameterNameStr_b[13] = "SM_AP_SOURCE";
    static const char_T ParameterNameStr_c[12] = "SM_NAC_AUTO";
    static const char_T ParameterNameStr_d[11] = "SM_NAC_CMD";
    static const char_T ParameterNameStr_e[15] = "SM_PI_BREAKOUT";
    static const char_T ParameterNameStr_f[10] = "SM_TCS_K1";
    static const char_T ParameterNameStr_g[10] = "SM_TCS_K2";
    static const char_T ParameterNameStr_h[10] = "SM_TCS_K3";
    static const char_T ParameterNameStr_i[10] = "SM_TCS_K4";
    static const char_T ParameterNameStr_j[10] = "SM_TCS_K5";
    static const char_T ParameterNameStr_k[10] = "SM_TCS_K6";
    static const char_T ParameterNameStr_l[13] = "SM_EMF_LAT_1";
    static const char_T ParameterNameStr_m[13] = "SM_EMF_LAT_2";
    static const char_T ParameterNameStr_n[13] = "SM_EMF_LAT_3";
    static const char_T ParameterNameStr_o[13] = "SM_EMF_LAT_4";
    static const char_T ParameterNameStr_p[13] = "SM_EMF_LAT_5";
    static const char_T ParameterNameStr_q[13] = "SM_EMF_LAT_6";
    static const char_T ParameterNameStr_r[13] = "SM_EMF_LON_1";
    static const char_T ParameterNameStr_s[13] = "SM_EMF_LON_2";
    static const char_T ParameterNameStr_t[13] = "SM_EMF_LON_3";
    static const char_T ParameterNameStr_u[13] = "SM_EMF_LON_4";
    static const char_T ParameterNameStr_v[13] = "SM_EMF_LON_5";
    static const char_T ParameterNameStr_w[13] = "SM_EMF_DIR_1";
    static const char_T ParameterNameStr_x[13] = "SM_EMF_DIR_2";
    static const char_T ParameterNameStr_y[13] = "SM_EMF_DIR_3";
    static const char_T ParameterNameStr_z[13] = "SM_EMF_DIR_4";
    static const char_T ParameterNameStr_10[13] = "SM_EMF_DIR_5";
    static const char_T ParameterNameStr_11[12] = "SM_LATCS_K1";
    static const char_T ParameterNameStr_12[12] = "SM_LATCS_K2";
    static const char_T ParameterNameStr_13[12] = "SM_LATCS_K3";
    static const char_T ParameterNameStr_14[13] = "SM_PII_LAT_1";
    static const char_T ParameterNameStr_15[13] = "SM_PII_LAT_2";
    static const char_T ParameterNameStr_16[13] = "SM_PII_LAT_3";
    static const char_T ParameterNameStr_17[13] = "SM_PII_LAT_4";
    static const char_T ParameterNameStr_18[13] = "SM_PII_LAT_5";
    static const char_T ParameterNameStr_19[13] = "SM_PII_LAT_6";
    static const char_T ParameterNameStr_1a[13] = "SM_PII_LAT_7";
    static const char_T ParameterNameStr_1b[13] = "SM_PII_LAT_8";
    static const char_T ParameterNameStr_1c[13] = "SM_PII_LAT_9";
    static const char_T ParameterNameStr_1d[13] = "SM_PII_LON_1";
    static const char_T ParameterNameStr_1e[13] = "SM_PII_LON_2";
    static const char_T ParameterNameStr_1f[13] = "SM_PII_LON_3";
    static const char_T ParameterNameStr_1g[13] = "SM_PII_DIR_1";
    static const char_T ParameterNameStr_1h[13] = "SM_PII_DIR_2";
    static const char_T ParameterNameStr_1i[13] = "SM_PII_DIR_3";
    static const char_T ParameterNameStr_1j[13] = "SM_PII_ACC_1";
    static const char_T ParameterNameStr_1k[13] = "SM_PII_ACC_2";
    static const char_T ParameterNameStr_1l[13] = "SM_PII_ACC_3";
    static const char_T ParameterNameStr_1m[13] = "SM_PII_ACC_4";
    static const char_T ParameterNameStr_1n[13] = "SM_PII_ACC_5";
    static const char_T ParameterNameStr_1o[13] = "SM_PII_ALT_1";
    static const char_T ParameterNameStr_1p[13] = "SM_PII_ALT_2";
    static const char_T ParameterNameStr_1q[13] = "SM_PII_ALT_3";
    static const char_T ParameterNameStr_1r[13] = "SM_PII_ALT_4";
    static const char_T ParameterNameStr_1s[13] = "SM_PII_ALT_5";
    static const char_T ParameterNameStr_1t[13] = "SM_PII_HDG_1";
    static const char_T ParameterNameStr_1u[13] = "SM_PII_HDG_2";
    static const char_T ParameterNameStr_1v[13] = "SM_PII_HDG_3";
    static const char_T ParameterNameStr_1w[13] = "SM_PII_HDG_4";
    static const char_T ParameterNameStr_1x[13] = "SM_PII_HDG_5";
    static const char_T ParameterNameStr_1y[13] = "SM_PII_TRK_1";
    static const char_T ParameterNameStr_1z[13] = "SM_PII_TRK_2";
    static const char_T ParameterNameStr_20[13] = "SM_PII_TRK_3";
    static const char_T ParameterNameStr_21[13] = "SM_PII_TRK_4";
    static const char_T ParameterNameStr_22[12] = "SM_PII_PH_1";
    static const char_T ParameterNameStr_23[12] = "SM_PII_PH_2";
    static const char_T ParameterNameStr_24[12] = "SM_PII_PH_3";
    static const char_T ParameterNameStr_25[12] = "SM_PII_PH_4";
    static const char_T ParameterNameStr_26[12] = "SM_PII_PH_5";
    static const char_T ParameterNameStr_27[12] = "SM_PII_PH_6";
    static const char_T ParameterNameStr_28[12] = "SM_PII_PH_7";
    static const char_T ParameterNameStr_29[12] = "SM_PII_PH_8";
    static const char_T ParameterNameStr_2a[12] = "SM_PII_PH_9";
    static const char_T ParameterNameStr_2b[12] = "SM_PII_AP_1";
    static const char_T ParameterNameStr_2c[12] = "SM_PII_AP_2";
    static const char_T ParameterNameStr_2d[12] = "SM_PII_AP_3";
    static const char_T ParameterNameStr_2e[12] = "SM_PII_AP_4";
    static const char_T ParameterNameStr_2f[12] = "SM_PII_AP_5";
    static const char_T ParameterNameStr_2g[12] = "SM_PII_AP_6";
    static const char_T ParameterNameStr_2h[10] = "SM_TCS_V1";
    static const char_T ParameterNameStr_2i[10] = "SM_TCS_V2";
    static const char_T ParameterNameStr_2j[10] = "SM_TCS_V3";
    static const char_T ParameterNameStr_2k[10] = "SM_TCS_V4";
    static const char_T ParameterNameStr_2l[11] = "SM_TCS_DL1";
    static const char_T ParameterNameStr_2m[11] = "SM_TCS_DL2";
    static const char_T ParameterNameStr_2n[11] = "SM_TCS_DL3";
    static const char_T ParameterNameStr_2o[11] = "SM_TCS_DL4";
    static const char_T ParameterNameStr_2p[11] = "SM_TCS_DL5";
    static const char_T ParameterNameStr_2q[11] = "SM_TCS_DL6";
    static const char_T ParameterNameStr_2r[12] = "SM_TCS_TKO1";
    static const char_T ParameterNameStr_2s[12] = "SM_TCS_TKO2";
    static const char_T ParameterNameStr_2t[12] = "SM_TCS_TKO3";
    static const char_T ParameterNameStr_2u[12] = "SM_TCS_TKO4";
    static const char_T ParameterNameStr_2v[12] = "SM_TCS_TKO5";
    static const char_T ParameterNameStr_2w[14] = "SM_TCS_PITCH1";
    static const char_T ParameterNameStr_2x[14] = "SM_TCS_PITCH2";
    static const char_T ParameterNameStr_2y[14] = "SM_TCS_PITCH3";
    static const char_T ParameterNameStr_2z[15] = "SM_TCS_SAFETY1";
    static const char_T ParameterNameStr_30[15] = "SM_TCS_SAFETY2";
    static const char_T ParameterNameStr_31[12] = "SM_TCS_TAI1";
    static const char_T ParameterNameStr_32[12] = "SM_TCS_TAI2";
    static const char_T ParameterNameStr_33[12] = "SM_TCS_TAI3";
    static const char_T ParameterNameStr_34[12] = "SM_TCS_TAI4";
    static const char_T ParameterNameStr_35[13] = "SM_TCS_RATE1";
    static const char_T ParameterNameStr_36[13] = "SM_TCS_RATE2";
    static const char_T ParameterNameStr_37[13] = "SM_TCS_RATE3";
    static const char_T ParameterNameStr_38[13] = "SM_TCS_RATE4";
    static const char_T ParameterNameStr_39[13] = "SM_TCS_RATE5";
    static const char_T ParameterNameStr_3a[13] = "SM_TCS_RATE6";
    static const char_T ParameterNameStr_3b[13] = "SM_TCS_RATE7";
    static const char_T ParameterNameStr_3c[9] = "SM_NAC_1";
    static const char_T ParameterNameStr_3d[9] = "SM_NAC_2";
    static const char_T ParameterNameStr_3e[9] = "SM_NAC_3";
    static const char_T ParameterNameStr_3f[14] = "SM_GAIN_INDEX";
    static const char_T ParameterNameStr_3g[15] = "SM_PARAM_INDEX";
    static const char_T ParameterNameStr_3h[12] = "SM_NAV_VCMD";
    static const char_T ParameterNameStr_3i[12] = "SM_NAV_HCMD";
    static const char_T ParameterNameStr_3j[13] = "SM_NAV_VAGGR";
    static const char_T ParameterNameStr_3k[12] = "SM_NAV_ALT0";
    static const char_T ParameterNameStr_3l[11] = "SM_NAV_LAF";
    static const char_T ParameterNameStr_3m[12] = "SM_IPPM_RHO";
    static const char_T ParameterNameStr_3n[12] = "SM_IPPM_DMP";
    static const char_T ParameterNameStr_3o[13] = "SM_IPPM_MASS";
    static const char_T ParameterNameStr_3p[15] = "SM_PI_ROT_DIAL";
    static const char_T ParameterNameStr_3q[13] = "SM_AUX_MIX_1";
    static const char_T ParameterNameStr_3r[13] = "SM_AUX_MIX_2";
    static const char_T ParameterNameStr_3s[13] = "SM_AUX_MIX_3";
    static const char_T ParameterNameStr_3t[13] = "SM_AUX_MIX_4";
    static const char_T ParameterNameStr_3u[13] = "SM_AUX_MIX_5";
    static const char_T ParameterNameStr_3v[13] = "SM_AUX_MIX_6";
    static const char_T ParameterNameStr_3w[14] = "SM_AUX_NMIN_1";
    static const char_T ParameterNameStr_3x[14] = "SM_AUX_NMAX_1";
    static const char_T ParameterNameStr_3y[12] = "SM_IPPM_MP0";
    static const char_T ParameterNameStr_3z[12] = "SM_IPPM_LP0";
    static const char_T ParameterNameStr_40[12] = "SM_FCS_VTXN";
    static const char_T ParameterNameStr_41[13] = "SM_FCS_NPROP";
    static const char_T ParameterNameStr_42[13] = "SM_FCS_DFLAP";
    static const char_T ParameterNameStr_43[12] = "SM_IPPM_DLP";
    static const char_T ParameterNameStr_44[14] = "SM_NAV_SAFETY";
    static const char_T ParameterNameStr_45[14] = "SM_AUX_NMIN_3";
    static const char_T ParameterNameStr_46[14] = "SM_AUX_NMAX_3";
    static const char_T ParameterNameStr_47[13] = "SM_AUX_MIX_7";
    static const char_T ParameterNameStr_48[13] = "SM_AUX_MIX_8";
    static const char_T ParameterNameStr_49[14] = "SM_AUX_NMIN_4";
    static const char_T ParameterNameStr_4a[14] = "SM_AUX_NMAX_4";
    static const char_T ParameterNameStr_4b[14] = "SM_AUX_NMIN_5";
    static const char_T ParameterNameStr_4c[14] = "SM_AUX_NMAX_5";
    static const char_T ParameterNameStr_4d[14] = "SM_AUX_NMIN_2";
    static const char_T ParameterNameStr_4e[14] = "SM_AUX_NMAX_2";
    real_T Integrator_DSTATE_f;
    real_T Integrator_UpperSat_o;
    int32_T i;

    // Start for Probe: '<S116>/Probe'
    RRTV3_PX4_OA_B.Probe[0] = 0.02;
    RRTV3_PX4_OA_B.Probe[1] = 0.0;

    // Start for Probe: '<S111>/Probe'
    RRTV3_PX4_OA_B.Probe_g[0] = 0.02;
    RRTV3_PX4_OA_B.Probe_g[1] = 0.0;

    // InitializeConditions for DiscreteIntegrator: '<S120>/Integrator'
    RRTV3_PX4_OA_DW.Integrator_PrevResetState = 0;
    RRTV3_PX4_OA_DW.Integrator_IC_LOADING = 1U;

    // InitializeConditions for UnitDelay: '<S99>/UD'
    //
    //  Block description for '<S99>/UD':
    //
    //   Store in Global RAM

    RRTV3_PX4_OA_DW.UD_DSTATE = RRTV3_PX4_OA_P.u01s1001s2_ICPrevOutput;

    // InitializeConditions for UnitDelay: '<S100>/UD'
    //
    //  Block description for '<S100>/UD':
    //
    //   Store in Global RAM

    RRTV3_PX4_OA_DW.UD_DSTATE_p = RRTV3_PX4_OA_P.u025s1001s1_ICPrevOutput;

    // InitializeConditions for UnitDelay: '<S98>/UD'
    //
    //  Block description for '<S98>/UD':
    //
    //   Store in Global RAM

    RRTV3_PX4_OA_DW.UD_DSTATE_m = RRTV3_PX4_OA_P.u01s1001s_ICPrevOutput;

    // InitializeConditions for DiscreteIntegrator: '<S115>/Integrator'
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_b = 0;
    RRTV3_PX4_OA_DW.Integrator_IC_LOADING_p = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S97>/Integrator' incorporates:
    //   Constant: '<S6>/Constant2'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_e = RRTV3_PX4_OA_P.Constant2_Value_j;
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_e >
        RRTV3_PX4_OA_P.Integrator_UpperSat_e) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_e = RRTV3_PX4_OA_P.Integrator_UpperSat_e;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_e <
               RRTV3_PX4_OA_P.Integrator_LowerSat_m5) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_e =
        RRTV3_PX4_OA_P.Integrator_LowerSat_m5;
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_n = 2;

    // End of InitializeConditions for DiscreteIntegrator: '<S97>/Integrator'

    // InitializeConditions for UnitDelay: '<S75>/UD'
    //
    //  Block description for '<S75>/UD':
    //
    //   Store in Global RAM

    RRTV3_PX4_OA_DW.UD_DSTATE_mb = RRTV3_PX4_OA_P.u01s1001s2_ICPrevOutput_g;

    // InitializeConditions for DiscreteIntegrator: '<S92>/Integrator' incorporates:
    //   Constant: '<S5>/Constant2'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_d = RRTV3_PX4_OA_P.Constant2_Value_o;
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_d >
        RRTV3_PX4_OA_P.Integrator_UpperSat_k) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_d = RRTV3_PX4_OA_P.Integrator_UpperSat_k;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_d <
               RRTV3_PX4_OA_P.Integrator_LowerSat_k) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_d = RRTV3_PX4_OA_P.Integrator_LowerSat_k;
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_o = 2;

    // End of InitializeConditions for DiscreteIntegrator: '<S92>/Integrator'

    // SystemInitialize for Enabled SubSystem: '<Root>/Controllers'
    // InitializeConditions for Memory: '<S13>/Memory2'
    for (i = 0; i < 7; i++) {
      RRTV3_PX4_OA_DW.Memory2_PreviousInput[i] =
        RRTV3_PX4_OA_P.Memory2_InitialCondition[i];
    }

    // End of InitializeConditions for Memory: '<S13>/Memory2'

    // InitializeConditions for DiscreteIntegrator: '<S48>/Integrator' incorporates:
    //   Constant: '<S42>/Constant1'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0] = RRTV3_PX4_OA_P.Constant1_Value_l[0];
    if (RRTV3_PX4_OA_P.Constant1_Value_l[0] > RRTV3_PX4_OA_P.Integrator_UpperSat)
    {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0] =
        RRTV3_PX4_OA_P.Integrator_UpperSat;
    } else if (RRTV3_PX4_OA_P.Constant1_Value_l[0] <
               RRTV3_PX4_OA_P.Integrator_LowerSat) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[0] =
        RRTV3_PX4_OA_P.Integrator_LowerSat;
    }

    RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1] = RRTV3_PX4_OA_P.Constant1_Value_l[1];
    if (RRTV3_PX4_OA_P.Constant1_Value_l[1] > RRTV3_PX4_OA_P.Integrator_UpperSat)
    {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1] =
        RRTV3_PX4_OA_P.Integrator_UpperSat;
    } else if (RRTV3_PX4_OA_P.Constant1_Value_l[1] <
               RRTV3_PX4_OA_P.Integrator_LowerSat) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[1] =
        RRTV3_PX4_OA_P.Integrator_LowerSat;
    }

    RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2] = RRTV3_PX4_OA_P.Constant1_Value_l[2];
    if (RRTV3_PX4_OA_P.Constant1_Value_l[2] > RRTV3_PX4_OA_P.Integrator_UpperSat)
    {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2] =
        RRTV3_PX4_OA_P.Integrator_UpperSat;
    } else if (RRTV3_PX4_OA_P.Constant1_Value_l[2] <
               RRTV3_PX4_OA_P.Integrator_LowerSat) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[2] =
        RRTV3_PX4_OA_P.Integrator_LowerSat;
    }

    RRTV3_PX4_OA_DW.Integrator_DSTATE_h[3] = RRTV3_PX4_OA_P.Constant1_Value_l[3];
    if (RRTV3_PX4_OA_P.Constant1_Value_l[3] > RRTV3_PX4_OA_P.Integrator_UpperSat)
    {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[3] =
        RRTV3_PX4_OA_P.Integrator_UpperSat;
    } else if (RRTV3_PX4_OA_P.Constant1_Value_l[3] <
               RRTV3_PX4_OA_P.Integrator_LowerSat) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_h[3] =
        RRTV3_PX4_OA_P.Integrator_LowerSat;
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_i = 2;

    // End of InitializeConditions for DiscreteIntegrator: '<S48>/Integrator'

    // InitializeConditions for Memory: '<S42>/Memory2'
    RRTV3_PX4_OA_DW.Memory2_PreviousInput_p[0] =
      RRTV3_PX4_OA_P.Memory2_InitialCondition_p[0];
    RRTV3_PX4_OA_DW.Memory2_PreviousInput_p[1] =
      RRTV3_PX4_OA_P.Memory2_InitialCondition_p[1];
    RRTV3_PX4_OA_DW.Memory2_PreviousInput_p[2] =
      RRTV3_PX4_OA_P.Memory2_InitialCondition_p[2];

    // InitializeConditions for DiscreteIntegrator: '<S44>/Integrator' incorporates:
    //   Constant: '<S13>/Constant2'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_b = RRTV3_PX4_OA_P.Constant2_Value_b;
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_b >
        RRTV3_PX4_OA_P.Integrator_UpperSat_l) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_b = RRTV3_PX4_OA_P.Integrator_UpperSat_l;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_b <
               RRTV3_PX4_OA_P.Integrator_LowerSat_h) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_b = RRTV3_PX4_OA_P.Integrator_LowerSat_h;
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_k = 0;

    // End of InitializeConditions for DiscreteIntegrator: '<S44>/Integrator'

    // InitializeConditions for DiscreteIntegrator: '<S43>/Integrator' incorporates:
    //   Constant: '<S13>/Constant'

    for (i = 0; i < 10; i++) {
      Integrator_DSTATE_f = RRTV3_PX4_OA_P.Constant_Value_i[i];
      RRTV3_PX4_OA_DW.Integrator_DSTATE_f[i] = Integrator_DSTATE_f;
      if (Integrator_DSTATE_f > RRTV3_PX4_OA_P.Integrator_UpperSat_p) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_f[i] =
          RRTV3_PX4_OA_P.Integrator_UpperSat_p;
      } else if (Integrator_DSTATE_f < RRTV3_PX4_OA_P.Integrator_LowerSat_m) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_f[i] =
          RRTV3_PX4_OA_P.Integrator_LowerSat_m;
      }
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_by = 2;

    // End of InitializeConditions for DiscreteIntegrator: '<S43>/Integrator'

    // InitializeConditions for Memory: '<S13>/Memory1'
    memcpy(&RRTV3_PX4_OA_DW.Memory1_PreviousInput[0],
           &RRTV3_PX4_OA_P.Memory1_InitialCondition[0], 22U * sizeof(real_T));

    // InitializeConditions for Memory: '<S13>/Memory'
    memcpy(&RRTV3_PX4_OA_DW.Memory_PreviousInput[0],
           &RRTV3_PX4_OA_P.Memory_InitialCondition[0], sizeof(real_T) << 3U);

    // InitializeConditions for Memory: '<S8>/Memory7'
    RRTV3_PX4_OA_DW.Memory7_PreviousInput =
      RRTV3_PX4_OA_P.Memory7_InitialCondition;

    // InitializeConditions for Delay: '<S8>/Delay2'
    RRTV3_PX4_OA_DW.Delay2_DSTATE[0] = RRTV3_PX4_OA_P.Delay2_InitialCondition;
    RRTV3_PX4_OA_DW.Delay2_DSTATE[1] = RRTV3_PX4_OA_P.Delay2_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S24>/Integrator' incorporates:
    //   Constant: '<S8>/Constant'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0] = RRTV3_PX4_OA_P.Constant_Value_lz[0];
    if (RRTV3_PX4_OA_P.Constant_Value_lz[0] >
        RRTV3_PX4_OA_P.Integrator_UpperSat_g) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_g;
    } else if (RRTV3_PX4_OA_P.Constant_Value_lz[0] <
               RRTV3_PX4_OA_P.Integrator_LowerSat_l) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[0] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_l;
    }

    RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1] = RRTV3_PX4_OA_P.Constant_Value_lz[1];
    if (RRTV3_PX4_OA_P.Constant_Value_lz[1] >
        RRTV3_PX4_OA_P.Integrator_UpperSat_g) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_g;
    } else if (RRTV3_PX4_OA_P.Constant_Value_lz[1] <
               RRTV3_PX4_OA_P.Integrator_LowerSat_l) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[1] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_l;
    }

    RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2] = RRTV3_PX4_OA_P.Constant_Value_lz[2];
    if (RRTV3_PX4_OA_P.Constant_Value_lz[2] >
        RRTV3_PX4_OA_P.Integrator_UpperSat_g) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_g;
    } else if (RRTV3_PX4_OA_P.Constant_Value_lz[2] <
               RRTV3_PX4_OA_P.Integrator_LowerSat_l) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_n[2] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_l;
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_m = 2;

    // End of InitializeConditions for DiscreteIntegrator: '<S24>/Integrator'

    // InitializeConditions for Memory: '<S12>/Memory1'
    RRTV3_PX4_OA_DW.Memory1_PreviousInput_a =
      RRTV3_PX4_OA_P.Memory1_InitialCondition_l;

    // InitializeConditions for DiscreteIntegrator: '<S36>/Integrator' incorporates:
    //   Constant: '<S12>/Constant2'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_g = RRTV3_PX4_OA_P.Constant2_Value_e;
    if (RRTV3_PX4_OA_DW.Integrator_DSTATE_g >
        RRTV3_PX4_OA_P.Integrator_UpperSat_pu) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_g =
        RRTV3_PX4_OA_P.Integrator_UpperSat_pu;
    } else if (RRTV3_PX4_OA_DW.Integrator_DSTATE_g <
               RRTV3_PX4_OA_P.Integrator_LowerSat_i) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_g = RRTV3_PX4_OA_P.Integrator_LowerSat_i;
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_h = 2;

    // End of InitializeConditions for DiscreteIntegrator: '<S36>/Integrator'

    // InitializeConditions for DiscreteIntegrator: '<S35>/Integrator' incorporates:
    //   Constant: '<S12>/Constant1'

    for (i = 0; i < 5; i++) {
      Integrator_DSTATE_f = RRTV3_PX4_OA_P.Constant1_Value_n[i];
      RRTV3_PX4_OA_DW.Integrator_DSTATE_m[i] = Integrator_DSTATE_f;

      // InitializeConditions for DiscreteIntegrator: '<S35>/Integrator' incorporates:
      //   Constant: '<S12>/Constant1'

      Integrator_UpperSat_o = RRTV3_PX4_OA_P.Integrator_UpperSat_o[i];
      if (Integrator_DSTATE_f > Integrator_UpperSat_o) {
        RRTV3_PX4_OA_DW.Integrator_DSTATE_m[i] = Integrator_UpperSat_o;
      } else {
        Integrator_UpperSat_o = RRTV3_PX4_OA_P.Integrator_LowerSat_a[i];
        if (Integrator_DSTATE_f < Integrator_UpperSat_o) {
          RRTV3_PX4_OA_DW.Integrator_DSTATE_m[i] = Integrator_UpperSat_o;
        }
      }
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_hc = 2;

    // End of InitializeConditions for DiscreteIntegrator: '<S35>/Integrator'

    // InitializeConditions for Memory: '<S12>/Memory'
    RRTV3_PX4_OA_DW.Memory_PreviousInput_l[0] =
      RRTV3_PX4_OA_P.Memory_InitialCondition_o[0];

    // InitializeConditions for Delay: '<S8>/Delay1'
    RRTV3_PX4_OA_DW.Delay1_DSTATE[0] = RRTV3_PX4_OA_P.Delay1_InitialCondition;

    // InitializeConditions for Memory: '<S12>/Memory'
    RRTV3_PX4_OA_DW.Memory_PreviousInput_l[1] =
      RRTV3_PX4_OA_P.Memory_InitialCondition_o[1];

    // InitializeConditions for Delay: '<S8>/Delay1'
    RRTV3_PX4_OA_DW.Delay1_DSTATE[1] = RRTV3_PX4_OA_P.Delay1_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S26>/Integrator'
    RRTV3_PX4_OA_DW.Integrator_PrevResetState_n2 = 2;

    // InitializeConditions for Memory: '<S8>/Memory3'
    RRTV3_PX4_OA_DW.Memory3_PreviousInput =
      RRTV3_PX4_OA_P.Memory3_InitialCondition;

    // InitializeConditions for UnitDelay: '<S16>/UD'
    //
    //  Block description for '<S16>/UD':
    //
    //   Store in Global RAM

    RRTV3_PX4_OA_DW.UD_DSTATE_h = RRTV3_PX4_OA_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for Memory: '<S8>/Memory1'
    RRTV3_PX4_OA_DW.Memory1_PreviousInput_b =
      RRTV3_PX4_OA_P.Memory1_InitialCondition_a;

    // InitializeConditions for Delay: '<S8>/Delay'
    RRTV3_PX4_OA_DW.Delay_DSTATE = RRTV3_PX4_OA_P.Delay_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S26>/Integrator' incorporates:
    //   Constant: '<S8>/Constant3'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0] = RRTV3_PX4_OA_P.Constant3_Value_n[0];
    if (RRTV3_PX4_OA_P.Constant3_Value_n[0] >
        RRTV3_PX4_OA_P.Integrator_UpperSat_m) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_m;
    } else if (RRTV3_PX4_OA_P.Constant3_Value_n[0] <
               RRTV3_PX4_OA_P.Integrator_LowerSat_c) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[0] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c;
    }

    // InitializeConditions for DiscreteIntegrator: '<S25>/Integrator' incorporates:
    //   Constant: '<S8>/Constant2'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0] = RRTV3_PX4_OA_P.Constant2_Value_n[0];
    if (RRTV3_PX4_OA_P.Constant2_Value_n[0] >
        RRTV3_PX4_OA_P.Integrator_UpperSat_py) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_py;
    } else if (RRTV3_PX4_OA_P.Constant2_Value_n[0] <
               RRTV3_PX4_OA_P.Integrator_LowerSat_c4) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[0] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c4;
    }

    // InitializeConditions for DiscreteIntegrator: '<S26>/Integrator' incorporates:
    //   Constant: '<S8>/Constant3'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1] = RRTV3_PX4_OA_P.Constant3_Value_n[1];
    if (RRTV3_PX4_OA_P.Constant3_Value_n[1] >
        RRTV3_PX4_OA_P.Integrator_UpperSat_m) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_m;
    } else if (RRTV3_PX4_OA_P.Constant3_Value_n[1] <
               RRTV3_PX4_OA_P.Integrator_LowerSat_c) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[1] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c;
    }

    // InitializeConditions for DiscreteIntegrator: '<S25>/Integrator' incorporates:
    //   Constant: '<S8>/Constant2'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1] = RRTV3_PX4_OA_P.Constant2_Value_n[1];
    if (RRTV3_PX4_OA_P.Constant2_Value_n[1] >
        RRTV3_PX4_OA_P.Integrator_UpperSat_py) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_py;
    } else if (RRTV3_PX4_OA_P.Constant2_Value_n[1] <
               RRTV3_PX4_OA_P.Integrator_LowerSat_c4) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[1] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c4;
    }

    // InitializeConditions for DiscreteIntegrator: '<S26>/Integrator' incorporates:
    //   Constant: '<S8>/Constant3'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2] = RRTV3_PX4_OA_P.Constant3_Value_n[2];
    if (RRTV3_PX4_OA_P.Constant3_Value_n[2] >
        RRTV3_PX4_OA_P.Integrator_UpperSat_m) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_m;
    } else if (RRTV3_PX4_OA_P.Constant3_Value_n[2] <
               RRTV3_PX4_OA_P.Integrator_LowerSat_c) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[2] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c;
    }

    // InitializeConditions for DiscreteIntegrator: '<S25>/Integrator' incorporates:
    //   Constant: '<S8>/Constant2'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2] = RRTV3_PX4_OA_P.Constant2_Value_n[2];
    if (RRTV3_PX4_OA_P.Constant2_Value_n[2] >
        RRTV3_PX4_OA_P.Integrator_UpperSat_py) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_py;
    } else if (RRTV3_PX4_OA_P.Constant2_Value_n[2] <
               RRTV3_PX4_OA_P.Integrator_LowerSat_c4) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[2] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c4;
    }

    // InitializeConditions for DiscreteIntegrator: '<S26>/Integrator' incorporates:
    //   Constant: '<S8>/Constant3'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3] = RRTV3_PX4_OA_P.Constant3_Value_n[3];
    if (RRTV3_PX4_OA_P.Constant3_Value_n[3] >
        RRTV3_PX4_OA_P.Integrator_UpperSat_m) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_m;
    } else if (RRTV3_PX4_OA_P.Constant3_Value_n[3] <
               RRTV3_PX4_OA_P.Integrator_LowerSat_c) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_mu[3] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c;
    }

    // InitializeConditions for DiscreteIntegrator: '<S25>/Integrator' incorporates:
    //   Constant: '<S8>/Constant2'

    RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3] = RRTV3_PX4_OA_P.Constant2_Value_n[3];
    if (RRTV3_PX4_OA_P.Constant2_Value_n[3] >
        RRTV3_PX4_OA_P.Integrator_UpperSat_py) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3] =
        RRTV3_PX4_OA_P.Integrator_UpperSat_py;
    } else if (RRTV3_PX4_OA_P.Constant2_Value_n[3] <
               RRTV3_PX4_OA_P.Integrator_LowerSat_c4) {
      RRTV3_PX4_OA_DW.Integrator_DSTATE_hn[3] =
        RRTV3_PX4_OA_P.Integrator_LowerSat_c4;
    }

    RRTV3_PX4_OA_DW.Integrator_PrevResetState_e = 2;

    // InitializeConditions for Memory: '<S8>/Memory6'
    RRTV3_PX4_OA_DW.Memory6_PreviousInput =
      RRTV3_PX4_OA_P.Memory6_InitialCondition;

    // InitializeConditions for UnitDelay: '<S17>/UD'
    //
    //  Block description for '<S17>/UD':
    //
    //   Store in Global RAM

    RRTV3_PX4_OA_DW.UD_DSTATE_c = RRTV3_PX4_OA_P.DiscreteDerivative1_ICPrevScale;
    for (i = 0; i < 17; i++) {
      // SystemInitialize for SignalConversion generated from: '<S1>/Control Cmds' incorporates:
      //   Outport: '<S1>/Control Cmds'

      RRTV3_PX4_OA_B.OutportBufferForControlCmds[i] =
        RRTV3_PX4_OA_P.ControlCmds_Y0;
    }

    // SystemInitialize for Outport: '<S1>/GCS Out'
    RRTV3_PX4_OA_B.PII_collect[0] = 0.0;
    RRTV3_PX4_OA_B.PII_collect[1] = 0.0;
    RRTV3_PX4_OA_B.PII_collect[2] = 0.0;
    RRTV3_PX4_OA_B.PII_collect[3] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.phiCmd;
    RRTV3_PX4_OA_B.PII_collect[4] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.rCmd;
    RRTV3_PX4_OA_B.PII_collect[5] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.DIR;
    RRTV3_PX4_OA_B.PII_collect[6] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.HDGmem;
    RRTV3_PX4_OA_B.PII_collect[7] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.TRKmem;
    RRTV3_PX4_OA_B.PII_collect[8] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.POS;
    RRTV3_PX4_OA_B.PII_collect[9] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.ALT;
    RRTV3_PX4_OA_B.PII_collect[10] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.ALTmem;
    RRTV3_PX4_OA_B.PII_collect[11] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.LongErr;
    RRTV3_PX4_OA_B.PII_collect[12] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.LatErr;
    RRTV3_PX4_OA_B.PII_collect[13] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.dlat;
    RRTV3_PX4_OA_B.PII_collect[14] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.dver;
    RRTV3_PX4_OA_B.PII_collect[15] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.ddir;
    RRTV3_PX4_OA_B.PII_collect[16] = RRTV3_PX4_OA_P.GCSOut_Y0.PII.dacc;
    RRTV3_PX4_OA_B.TCS_Out[0] = RRTV3_PX4_OA_P.GCSOut_Y0.TCS.TWMP_Cmd;
    RRTV3_PX4_OA_B.TCS_Out[1] = RRTV3_PX4_OA_P.GCSOut_Y0.TCS.TWLP_Cmd;
    RRTV3_PX4_OA_B.TCS_Out[2] = RRTV3_PX4_OA_P.GCSOut_Y0.TCS.WingCmd;
    RRTV3_PX4_OA_B.TCS_Out[3] = RRTV3_PX4_OA_P.GCSOut_Y0.TCS.PitchCmd;
    RRTV3_PX4_OA_B.TCS_Out[4] = RRTV3_PX4_OA_P.GCSOut_Y0.TCS.TCS_Mode;
    RRTV3_PX4_OA_B.TCS_Out[5] = RRTV3_PX4_OA_P.GCSOut_Y0.TCS.TWH;
    RRTV3_PX4_OA_B.TCS_Out[6] = RRTV3_PX4_OA_P.GCSOut_Y0.TCS.TWV;
    RRTV3_PX4_OA_B.ulat = RRTV3_PX4_OA_P.GCSOut_Y0.EMF.ulat;
    RRTV3_PX4_OA_B.ulon = RRTV3_PX4_OA_P.GCSOut_Y0.EMF.ulon;
    RRTV3_PX4_OA_B.udir = RRTV3_PX4_OA_P.GCSOut_Y0.EMF.udir;
    RRTV3_PX4_OA_B.AF = RRTV3_PX4_OA_P.GCSOut_Y0.AP;

    // SystemInitialize for SignalConversion generated from: '<S11>/Constant' incorporates:
    //   Outport: '<S1>/GCS Out'

    RRTV3_PX4_OA_B.LPRPM = RRTV3_PX4_OA_P.GCSOut_Y0.RPM.LPRPM;

    // SystemInitialize for Saturate: '<S11>/ RPM LIMITER' incorporates:
    //   Outport: '<S1>/GCS Out'

    RRTV3_PX4_OA_B.MPRPM = RRTV3_PX4_OA_P.GCSOut_Y0.RPM.MPRPM;

    // SystemInitialize for Outport: '<S1>/GCS Out'
    RRTV3_PX4_OA_B.MiscOP[0] = RRTV3_PX4_OA_P.GCSOut_Y0.NAV.LATSIG;
    RRTV3_PX4_OA_B.MiscOP[1] = RRTV3_PX4_OA_P.GCSOut_Y0.NAV.LONGSIG;
    RRTV3_PX4_OA_B.MiscOP[2] = RRTV3_PX4_OA_P.GCSOut_Y0.NAV.SPDSIG;
    RRTV3_PX4_OA_B.MiscOP[3] = RRTV3_PX4_OA_P.GCSOut_Y0.NAV.WPINDEX;
    RRTV3_PX4_OA_B.MiscOP[4] = RRTV3_PX4_OA_P.GCSOut_Y0.NAV.DistToTarget;
    RRTV3_PX4_OA_B.MiscOP[5] = RRTV3_PX4_OA_P.GCSOut_Y0.NAV.TRK_target;
    RRTV3_PX4_OA_B.MiscOP[6] = RRTV3_PX4_OA_P.GCSOut_Y0.NAV.FPA_target;
    RRTV3_PX4_OA_B.MiscOP[7] = RRTV3_PX4_OA_P.GCSOut_Y0.NAV.Altpath;
    RRTV3_PX4_OA_B.MiscOP[8] = RRTV3_PX4_OA_P.GCSOut_Y0.NAV.NAVSTATUS;
    RRTV3_PX4_OA_B.GUIDANCE[0] = RRTV3_PX4_OA_P.GCSOut_Y0.GUIDANCE.LNAV;
    RRTV3_PX4_OA_B.GUIDANCE[1] = RRTV3_PX4_OA_P.GCSOut_Y0.GUIDANCE.LNAV_NORM;
    RRTV3_PX4_OA_B.GUIDANCE[2] = RRTV3_PX4_OA_P.GCSOut_Y0.GUIDANCE.VNAV;
    RRTV3_PX4_OA_B.GUIDANCE[3] = RRTV3_PX4_OA_P.GCSOut_Y0.GUIDANCE.VNAV_NORM;
    RRTV3_PX4_OA_B.GUIDANCE[4] = RRTV3_PX4_OA_P.GCSOut_Y0.GUIDANCE.SPD;
    RRTV3_PX4_OA_B.GUIDANCE[5] = RRTV3_PX4_OA_P.GCSOut_Y0.GUIDANCE.SPD_CUE;

    // End of SystemInitialize for SubSystem: '<Root>/Controllers'

    // SystemInitialize for Enabled SubSystem: '<S81>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S82>/In1' incorporates:
    //   Outport: '<S82>/Out1'

    RRTV3_PX4_OA_B.In1_a = RRTV3_PX4_OA_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S81>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S84>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S87>/In1' incorporates:
    //   Outport: '<S87>/Out1'

    RRTV3_PX4_OA_B.In1_o = RRTV3_PX4_OA_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S84>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S85>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S88>/In1' incorporates:
    //   Outport: '<S88>/Out1'

    RRTV3_PX4_OA_B.In1_f = RRTV3_PX4_OA_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S85>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S121>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S122>/In1' incorporates:
    //   Outport: '<S122>/Out1'

    RRTV3_PX4_OA_B.In1_d = RRTV3_PX4_OA_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S121>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S105>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S123>/In1' incorporates:
    //   Outport: '<S123>/Out1'

    RRTV3_PX4_OA_B.In1_a4 = RRTV3_PX4_OA_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S105>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S106>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S124>/In1' incorporates:
    //   Outport: '<S124>/Out1'

    RRTV3_PX4_OA_B.In1_n = RRTV3_PX4_OA_P.Out1_Y0_f4;

    // End of SystemInitialize for SubSystem: '<S106>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S107>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S125>/In1' incorporates:
    //   Outport: '<S125>/Out1'

    RRTV3_PX4_OA_B.In1_h = RRTV3_PX4_OA_P.Out1_Y0_fb;

    // End of SystemInitialize for SubSystem: '<S107>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S108>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S126>/In1' incorporates:
    //   Outport: '<S126>/Out1'

    RRTV3_PX4_OA_B.In1_g = RRTV3_PX4_OA_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S108>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S109>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S127>/In1' incorporates:
    //   Outport: '<S127>/Out1'

    RRTV3_PX4_OA_B.In1_o2 = RRTV3_PX4_OA_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S109>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S110>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S128>/In1' incorporates:
    //   Outport: '<S128>/Out1'

    RRTV3_PX4_OA_B.In1 = RRTV3_PX4_OA_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S110>/Enabled Subsystem'

    // Start for MATLABSystem: '<S85>/SourceBlock'
    RRTV3_PX4_OA_DW.obj_go.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_go.isInitialized = 1;
    RRTV3_PX4_OA_DW.obj_go.orbMetadataObj = ORB_ID(rc_channels);
    uORB_read_initialize(RRTV3_PX4_OA_DW.obj_go.orbMetadataObj,
                         &RRTV3_PX4_OA_DW.obj_go.eventStructObj);
    RRTV3_PX4_OA_DW.obj_go.isSetupComplete = true;

    // Start for MATLABSystem: '<S84>/SourceBlock'
    RRTV3_PX4_OA_DW.obj_am.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_am.isInitialized = 1;
    RRTV3_PX4_OA_DW.obj_am.orbMetadataObj = ORB_ID(failsafe_flags);
    uORB_read_initialize(RRTV3_PX4_OA_DW.obj_am.orbMetadataObj,
                         &RRTV3_PX4_OA_DW.obj_am.eventStructObj);
    RRTV3_PX4_OA_DW.obj_am.isSetupComplete = true;

    // Start for MATLABSystem: '<S121>/SourceBlock'
    RRTV3_PX4_OA_DW.obj_omq.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_omq.isInitialized = 1;
    RRTV3_PX4_OA_DW.obj_omq.orbMetadataObj = ORB_ID(vehicle_gps_position);
    uORB_read_initialize(RRTV3_PX4_OA_DW.obj_omq.orbMetadataObj,
                         &RRTV3_PX4_OA_DW.obj_omq.eventStructObj);
    RRTV3_PX4_OA_DW.obj_omq.isSetupComplete = true;

    // Start for MATLABSystem: '<S110>/SourceBlock'
    RRTV3_PX4_OA_DW.obj_mcu.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_mcu.isInitialized = 1;
    RRTV3_PX4_OA_DW.obj_mcu.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(RRTV3_PX4_OA_DW.obj_mcu.orbMetadataObj,
                         &RRTV3_PX4_OA_DW.obj_mcu.eventStructObj);
    RRTV3_PX4_OA_DW.obj_mcu.isSetupComplete = true;

    // Start for MATLABSystem: '<S53>/Max Phi Cmd6'
    RRTV3_PX4_OA_DW.obj_gm.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_gm.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd6_SampleTime;
    RRTV3_PX4_OA_DW.obj_gm.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_gm.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_gm.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_gm.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_gm.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S53>/Max Phi Cmd6'

    // Start for MATLABSystem: '<S106>/SourceBlock'
    RRTV3_PX4_OA_DW.obj_es.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_es.isInitialized = 1;
    RRTV3_PX4_OA_DW.obj_es.orbMetadataObj = ORB_ID(vehicle_angular_velocity);
    uORB_read_initialize(RRTV3_PX4_OA_DW.obj_es.orbMetadataObj,
                         &RRTV3_PX4_OA_DW.obj_es.eventStructObj);
    RRTV3_PX4_OA_DW.obj_es.isSetupComplete = true;

    // Start for MATLABSystem: '<S107>/SourceBlock'
    RRTV3_PX4_OA_DW.obj_oe.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_oe.isInitialized = 1;
    RRTV3_PX4_OA_DW.obj_oe.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(RRTV3_PX4_OA_DW.obj_oe.orbMetadataObj,
                         &RRTV3_PX4_OA_DW.obj_oe.eventStructObj);
    RRTV3_PX4_OA_DW.obj_oe.isSetupComplete = true;

    // Start for MATLABSystem: '<S108>/SourceBlock'
    RRTV3_PX4_OA_DW.obj_jx.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jx.isInitialized = 1;
    RRTV3_PX4_OA_DW.obj_jx.orbMetadataObj = ORB_ID(vehicle_acceleration);
    uORB_read_initialize(RRTV3_PX4_OA_DW.obj_jx.orbMetadataObj,
                         &RRTV3_PX4_OA_DW.obj_jx.eventStructObj);
    RRTV3_PX4_OA_DW.obj_jx.isSetupComplete = true;

    // Start for MATLABSystem: '<S105>/SourceBlock'
    RRTV3_PX4_OA_DW.obj_pd.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_pd.isInitialized = 1;
    RRTV3_PX4_OA_DW.obj_pd.orbMetadataObj = ORB_ID(distance_sensor);
    uORB_read_initialize(RRTV3_PX4_OA_DW.obj_pd.orbMetadataObj,
                         &RRTV3_PX4_OA_DW.obj_pd.eventStructObj);
    RRTV3_PX4_OA_DW.obj_pd.isSetupComplete = true;

    // Start for MATLABSystem: '<S96>/Read Parameter1'
    RRTV3_PX4_OA_DW.obj.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj.SampleTime = RRTV3_PX4_OA_P.ReadParameter1_SampleTime_i;
    RRTV3_PX4_OA_DW.obj.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_0[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S96>/Read Parameter1'

    // Start for MATLABSystem: '<S109>/SourceBlock'
    RRTV3_PX4_OA_DW.obj_jz.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jz.isInitialized = 1;
    RRTV3_PX4_OA_DW.obj_jz.orbMetadataObj = ORB_ID(airspeed);
    uORB_read_initialize(RRTV3_PX4_OA_DW.obj_jz.orbMetadataObj,
                         &RRTV3_PX4_OA_DW.obj_jz.eventStructObj);
    RRTV3_PX4_OA_DW.obj_jz.isSetupComplete = true;

    // Start for MATLABSystem: '<S53>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_nu.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_nu.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_jy;
    RRTV3_PX4_OA_DW.obj_nu.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_nu.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_nu.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_nu.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_nu.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S53>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S53>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_p2.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_p2.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_l;
    RRTV3_PX4_OA_DW.obj_p2.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_p2.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_p2.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_p2.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_p2.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S53>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S53>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_bd.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_bd.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime;
    RRTV3_PX4_OA_DW.obj_bd.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_bd.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_bd.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_bd.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_bd.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S53>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S53>/Max Phi Cmd4'
    RRTV3_PX4_OA_DW.obj_ha.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ha.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime;
    RRTV3_PX4_OA_DW.obj_ha.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ha.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ha.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ha.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_4[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ha.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S53>/Max Phi Cmd4'

    // Start for MATLABSystem: '<S53>/Max Phi Cmd12'
    RRTV3_PX4_OA_DW.obj_m3.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_m3.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime_dm;
    RRTV3_PX4_OA_DW.obj_m3.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_m3.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_m3.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_m3.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_5[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_m3.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S53>/Max Phi Cmd12'

    // Start for MATLABSystem: '<S53>/Max Phi Cmd5'
    RRTV3_PX4_OA_DW.obj_d5s.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_d5s.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_n;
    RRTV3_PX4_OA_DW.obj_d5s.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_d5s.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_d5s.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_d5s.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_6[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_d5s.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S53>/Max Phi Cmd5'

    // Start for MATLABSystem: '<S53>/Max Phi Cmd8'
    RRTV3_PX4_OA_DW.obj_bv.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_bv.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_j;
    RRTV3_PX4_OA_DW.obj_bv.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_bv.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_bv.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_bv.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_7[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_bv.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S53>/Max Phi Cmd8'

    // Start for MATLABSystem: '<S53>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_oa.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_oa.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_l;
    RRTV3_PX4_OA_DW.obj_oa.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_oa.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_oa.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_oa.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_8[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_oa.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S53>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S53>/Max Phi Cmd7'
    RRTV3_PX4_OA_DW.obj_d3.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_d3.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime;
    RRTV3_PX4_OA_DW.obj_d3.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_d3.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_d3.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_d3.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_9[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_d3.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S53>/Max Phi Cmd7'

    // Start for MATLABSystem: '<S4>/Read Parameter6'
    RRTV3_PX4_OA_DW.obj_p.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_p.SampleTime = RRTV3_PX4_OA_P.ReadParameter6_SampleTime;
    RRTV3_PX4_OA_DW.obj_p.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_p.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_p.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_a[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter6'

    // Start for MATLABSystem: '<S83>/Read Parameter7'
    RRTV3_PX4_OA_DW.obj_k.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_k.SampleTime = RRTV3_PX4_OA_P.ReadParameter7_SampleTime;
    RRTV3_PX4_OA_DW.obj_k.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_k.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_k.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_b[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S83>/Read Parameter7'

    // Start for MATLABSystem: '<S83>/Read Parameter5'
    RRTV3_PX4_OA_DW.obj_a.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_a.SampleTime = RRTV3_PX4_OA_P.ReadParameter5_SampleTime;
    RRTV3_PX4_OA_DW.obj_a.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_a.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_a.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_c[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S83>/Read Parameter5'

    // Start for MATLABSystem: '<S83>/Read Parameter6'
    RRTV3_PX4_OA_DW.obj_e.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_e.SampleTime =
      RRTV3_PX4_OA_P.ReadParameter6_SampleTime_j;
    RRTV3_PX4_OA_DW.obj_e.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_e.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_e.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_d[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S83>/Read Parameter6'

    // Start for MATLABSystem: '<S81>/SourceBlock'
    RRTV3_PX4_OA_DW.obj_eq.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_eq.isInitialized = 1;
    RRTV3_PX4_OA_DW.obj_eq.orbMetadataObj = ORB_ID(debug_vect);
    uORB_read_initialize(RRTV3_PX4_OA_DW.obj_eq.orbMetadataObj,
                         &RRTV3_PX4_OA_DW.obj_eq.eventStructObj);
    RRTV3_PX4_OA_DW.obj_eq.isSetupComplete = true;

    // Start for MATLABSystem: '<S4>/Read Parameter1'
    RRTV3_PX4_OA_DW.obj_ki.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ki.SampleTime = RRTV3_PX4_OA_P.ReadParameter1_SampleTime;
    RRTV3_PX4_OA_DW.obj_ki.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ki.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ki.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ki.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_e[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ki.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/Read Parameter1'

    // Start for MATLABSystem: '<S55>/Max Phi Cmd8'
    RRTV3_PX4_OA_DW.obj_bo.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_bo.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_n;
    RRTV3_PX4_OA_DW.obj_bo.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_bo.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_bo.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_bo.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_f[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_bo.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S55>/Max Phi Cmd8'

    // Start for MATLABSystem: '<S55>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_jum.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jum.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_b;
    RRTV3_PX4_OA_DW.obj_jum.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_jum.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_jum.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_jum.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_g[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_jum.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S55>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S55>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_pe.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_pe.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_h;
    RRTV3_PX4_OA_DW.obj_pe.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_pe.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_pe.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_pe.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_h[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_pe.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S55>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S55>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_pas.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_pas.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_jv;
    RRTV3_PX4_OA_DW.obj_pas.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_pas.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_pas.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_pas.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_i[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_pas.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S55>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S55>/Max Phi Cmd5'
    RRTV3_PX4_OA_DW.obj_iw.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_iw.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_bq;
    RRTV3_PX4_OA_DW.obj_iw.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_iw.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_iw.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_iw.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_j[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_iw.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S55>/Max Phi Cmd5'

    // Start for MATLABSystem: '<S55>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_eu.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_eu.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_f;
    RRTV3_PX4_OA_DW.obj_eu.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_eu.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_eu.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_eu.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_k[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_eu.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S55>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S57>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_f3.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_f3.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_k;
    RRTV3_PX4_OA_DW.obj_f3.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_f3.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_f3.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_f3.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_l[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_f3.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S57>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S57>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_hy.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_hy.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_g;
    RRTV3_PX4_OA_DW.obj_hy.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_hy.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_hy.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_hy.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_m[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_hy.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S57>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S57>/Max Phi Cmd7'
    RRTV3_PX4_OA_DW.obj_o0.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_o0.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime_p;
    RRTV3_PX4_OA_DW.obj_o0.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_o0.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_o0.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_o0.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_n[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_o0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S57>/Max Phi Cmd7'

    // Start for MATLABSystem: '<S57>/Max Phi Cmd4'
    RRTV3_PX4_OA_DW.obj_aw.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_aw.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_l;
    RRTV3_PX4_OA_DW.obj_aw.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_aw.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_aw.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_aw.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_o[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_aw.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S57>/Max Phi Cmd4'

    // Start for MATLABSystem: '<S57>/Max Phi Cmd6'
    RRTV3_PX4_OA_DW.obj_ci.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ci.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd6_SampleTime_g;
    RRTV3_PX4_OA_DW.obj_ci.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ci.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ci.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ci.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_p[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ci.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S57>/Max Phi Cmd6'

    // Start for MATLABSystem: '<S57>/Max Phi Cmd5'
    RRTV3_PX4_OA_DW.obj_op.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_op.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_h;
    RRTV3_PX4_OA_DW.obj_op.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_op.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_op.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_op.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_q[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_op.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S57>/Max Phi Cmd5'

    // Start for MATLABSystem: '<S56>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_ce.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ce.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_a;
    RRTV3_PX4_OA_DW.obj_ce.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ce.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ce.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ce.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_r[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ce.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S56>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S56>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_cw.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_cw.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_p;
    RRTV3_PX4_OA_DW.obj_cw.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_cw.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_cw.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_cw.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_s[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_cw.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S56>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S56>/Max Phi Cmd8'
    RRTV3_PX4_OA_DW.obj_i5k.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_i5k.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_a;
    RRTV3_PX4_OA_DW.obj_i5k.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_i5k.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_i5k.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_i5k.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_t[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_i5k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S56>/Max Phi Cmd8'

    // Start for MATLABSystem: '<S56>/Max Phi Cmd11'
    RRTV3_PX4_OA_DW.obj_d5.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_d5.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd11_SampleTime;
    RRTV3_PX4_OA_DW.obj_d5.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_d5.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_d5.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_d5.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_u[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_d5.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S56>/Max Phi Cmd11'

    // Start for MATLABSystem: '<S56>/Max Phi Cmd10'
    RRTV3_PX4_OA_DW.obj_b1.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_b1.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime;
    RRTV3_PX4_OA_DW.obj_b1.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_b1.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_b1.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_b1.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_v[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_b1.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S56>/Max Phi Cmd10'

    // Start for MATLABSystem: '<S58>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_l4.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_l4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_p;
    RRTV3_PX4_OA_DW.obj_l4.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_l4.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_l4.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_l4.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_w[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_l4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S58>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S58>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_ft.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ft.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_kw;
    RRTV3_PX4_OA_DW.obj_ft.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ft.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ft.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ft.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_x[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ft.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S58>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S58>/Max Phi Cmd8'
    RRTV3_PX4_OA_DW.obj_hk.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_hk.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_oa;
    RRTV3_PX4_OA_DW.obj_hk.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_hk.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_hk.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_hk.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_y[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_hk.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S58>/Max Phi Cmd8'

    // Start for MATLABSystem: '<S58>/Max Phi Cmd11'
    RRTV3_PX4_OA_DW.obj_ey.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ey.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd11_SampleTime_f;
    RRTV3_PX4_OA_DW.obj_ey.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ey.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ey.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ey.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_z[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ey.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S58>/Max Phi Cmd11'

    // Start for MATLABSystem: '<S58>/Max Phi Cmd10'
    RRTV3_PX4_OA_DW.obj_ixo.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ixo.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime_f;
    RRTV3_PX4_OA_DW.obj_ixo.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ixo.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ixo.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ixo.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_10
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ixo.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S58>/Max Phi Cmd10'

    // Start for MATLABSystem: '<S59>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_hl.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_hl.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_l5;
    RRTV3_PX4_OA_DW.obj_hl.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_hl.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_hl.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_hl.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_11[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_hl.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S59>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S59>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_oj.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_oj.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_ki;
    RRTV3_PX4_OA_DW.obj_oj.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_oj.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_oj.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_oj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_12[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_oj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S59>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S59>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_pm.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_pm.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_l;
    RRTV3_PX4_OA_DW.obj_pm.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_pm.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_pm.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_pm.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_13[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_pm.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S59>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S67>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_mv.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_mv.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_ni;
    RRTV3_PX4_OA_DW.obj_mv.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_mv.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_mv.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_mv.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_14[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_mv.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S67>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S67>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_mc.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_mc.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_n;
    RRTV3_PX4_OA_DW.obj_mc.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_mc.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_mc.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_mc.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_15[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_mc.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S67>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S67>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_hd.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_hd.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_i0;
    RRTV3_PX4_OA_DW.obj_hd.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_hd.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_hd.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_hd.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_16[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_hd.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S67>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S67>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_fx.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_fx.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_ga;
    RRTV3_PX4_OA_DW.obj_fx.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_fx.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_fx.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_fx.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_17[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_fx.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S67>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S67>/Max Phi Cmd7'
    RRTV3_PX4_OA_DW.obj_ac.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ac.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime_e;
    RRTV3_PX4_OA_DW.obj_ac.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ac.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ac.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ac.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_18[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ac.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S67>/Max Phi Cmd7'

    // Start for MATLABSystem: '<S67>/Max Phi Cmd4'
    RRTV3_PX4_OA_DW.obj_ko.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ko.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_d;
    RRTV3_PX4_OA_DW.obj_ko.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ko.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ko.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ko.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_19[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ko.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S67>/Max Phi Cmd4'

    // Start for MATLABSystem: '<S67>/Max Phi Cmd10'
    RRTV3_PX4_OA_DW.obj_l.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_l.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime_p;
    RRTV3_PX4_OA_DW.obj_l.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_l.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_l.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_l.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1a[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S67>/Max Phi Cmd10'

    // Start for MATLABSystem: '<S67>/Max Phi Cmd12'
    RRTV3_PX4_OA_DW.obj_ii.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ii.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime_h;
    RRTV3_PX4_OA_DW.obj_ii.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ii.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ii.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ii.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1b[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ii.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S67>/Max Phi Cmd12'

    // Start for MATLABSystem: '<S67>/Max Phi Cmd11'
    RRTV3_PX4_OA_DW.obj_b.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_b.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd11_SampleTime_l;
    RRTV3_PX4_OA_DW.obj_b.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_b.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_b.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1c[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S67>/Max Phi Cmd11'

    // Start for MATLABSystem: '<S68>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_mzd.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_mzd.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_j;
    RRTV3_PX4_OA_DW.obj_mzd.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_mzd.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_mzd.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_mzd.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1d
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_mzd.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S68>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S68>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_h3.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_h3.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_j;
    RRTV3_PX4_OA_DW.obj_h3.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_h3.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_h3.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_h3.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1e[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_h3.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S68>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S68>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_ix.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ix.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_pa;
    RRTV3_PX4_OA_DW.obj_ix.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ix.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ix.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ix.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1f[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ix.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S68>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S65>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_n0.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_n0.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_h3;
    RRTV3_PX4_OA_DW.obj_n0.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_n0.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_n0.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_n0.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1g[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_n0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S65>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S65>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_bu.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_bu.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_o;
    RRTV3_PX4_OA_DW.obj_bu.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_bu.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_bu.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_bu.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1h[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_bu.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S65>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S65>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_ag.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ag.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_kp;
    RRTV3_PX4_OA_DW.obj_ag.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ag.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ag.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ag.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1i[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ag.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S65>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S62>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_ez.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ez.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_n;
    RRTV3_PX4_OA_DW.obj_ez.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ez.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ez.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ez.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1j[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ez.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S62>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S62>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_l0.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_l0.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_p;
    RRTV3_PX4_OA_DW.obj_l0.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_l0.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_l0.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_l0.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1k[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_l0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S62>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S62>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_p4.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_p4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_c;
    RRTV3_PX4_OA_DW.obj_p4.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_p4.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_p4.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_p4.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1l[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_p4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S62>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S62>/Max Phi Cmd5'
    RRTV3_PX4_OA_DW.obj_d.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_d.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_hb;
    RRTV3_PX4_OA_DW.obj_d.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_d.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_d.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1m[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S62>/Max Phi Cmd5'

    // Start for MATLABSystem: '<S62>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_pb.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_pb.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_c;
    RRTV3_PX4_OA_DW.obj_pb.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_pb.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_pb.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_pb.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1n[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_pb.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S62>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S63>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_lm.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_lm.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_hz;
    RRTV3_PX4_OA_DW.obj_lm.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_lm.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_lm.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_lm.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1o[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_lm.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S63>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S63>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_g.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_g.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_d;
    RRTV3_PX4_OA_DW.obj_g.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_g.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_g.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1p[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S63>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S63>/Max Phi Cmd5'
    RRTV3_PX4_OA_DW.obj_os.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_os.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_p;
    RRTV3_PX4_OA_DW.obj_os.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_os.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_os.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_os.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1q[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_os.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S63>/Max Phi Cmd5'

    // Start for MATLABSystem: '<S63>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_jv.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jv.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_lv;
    RRTV3_PX4_OA_DW.obj_jv.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_jv.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_jv.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_jv.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1r[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_jv.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S63>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S63>/Max Phi Cmd4'
    RRTV3_PX4_OA_DW.obj_c.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_c.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_km;
    RRTV3_PX4_OA_DW.obj_c.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_c.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_c.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_c.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1s[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S63>/Max Phi Cmd4'

    // Start for MATLABSystem: '<S66>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_mz4.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_mz4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_c;
    RRTV3_PX4_OA_DW.obj_mz4.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_mz4.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_mz4.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_mz4.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1t
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_mz4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S66>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S66>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_mj.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_mj.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_f;
    RRTV3_PX4_OA_DW.obj_mj.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_mj.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_mj.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_mj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1u[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_mj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S66>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S66>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_m2.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_m2.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_fy;
    RRTV3_PX4_OA_DW.obj_m2.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_m2.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_m2.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_m2.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1v[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_m2.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S66>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S66>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_jf.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jf.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_n;
    RRTV3_PX4_OA_DW.obj_jf.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_jf.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_jf.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_jf.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1w[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_jf.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S66>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S66>/Max Phi Cmd4'
    RRTV3_PX4_OA_DW.obj_eg.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_eg.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_pr;
    RRTV3_PX4_OA_DW.obj_eg.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_eg.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_eg.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_eg.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1x[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_eg.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S66>/Max Phi Cmd4'

    // Start for MATLABSystem: '<S70>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_o.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_o.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_k;
    RRTV3_PX4_OA_DW.obj_o.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_o.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_o.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_o.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1y[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S70>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S70>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_n.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_n.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_c;
    RRTV3_PX4_OA_DW.obj_n.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_n.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_n.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1z[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S70>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S70>/Max Phi Cmd5'
    RRTV3_PX4_OA_DW.obj_i.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_i.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_c;
    RRTV3_PX4_OA_DW.obj_i.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_i.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_i.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_20[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S70>/Max Phi Cmd5'

    // Start for MATLABSystem: '<S70>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_j.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_j.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_f;
    RRTV3_PX4_OA_DW.obj_j.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_j.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_j.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_21[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S70>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S69>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_fy.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_fy.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_a;
    RRTV3_PX4_OA_DW.obj_fy.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_fy.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_fy.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_fy.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_22[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_fy.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S69>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S69>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_h.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_h.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_pz;
    RRTV3_PX4_OA_DW.obj_h.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_h.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_h.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_23[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S69>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S69>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_mz.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_mz.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_n;
    RRTV3_PX4_OA_DW.obj_mz.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_mz.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_mz.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_mz.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_24[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_mz.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S69>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S69>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_i4.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_i4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_ju;
    RRTV3_PX4_OA_DW.obj_i4.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_i4.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_i4.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_i4.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_25[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_i4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S69>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S69>/Max Phi Cmd7'
    RRTV3_PX4_OA_DW.obj_m.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_m.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime_d;
    RRTV3_PX4_OA_DW.obj_m.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_m.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_m.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_26[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S69>/Max Phi Cmd7'

    // Start for MATLABSystem: '<S69>/Max Phi Cmd4'
    RRTV3_PX4_OA_DW.obj_nw.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_nw.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_b;
    RRTV3_PX4_OA_DW.obj_nw.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_nw.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_nw.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_nw.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_27[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_nw.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S69>/Max Phi Cmd4'

    // Start for MATLABSystem: '<S69>/Max Phi Cmd6'
    RRTV3_PX4_OA_DW.obj_km.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_km.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd6_SampleTime_k;
    RRTV3_PX4_OA_DW.obj_km.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_km.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_km.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_km.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_28[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_km.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S69>/Max Phi Cmd6'

    // Start for MATLABSystem: '<S69>/Max Phi Cmd5'
    RRTV3_PX4_OA_DW.obj_ju.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ju.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_f;
    RRTV3_PX4_OA_DW.obj_ju.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ju.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ju.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ju.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_29[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ju.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S69>/Max Phi Cmd5'

    // Start for MATLABSystem: '<S69>/Max Phi Cmd10'
    RRTV3_PX4_OA_DW.obj_jd.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jd.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime_pj;
    RRTV3_PX4_OA_DW.obj_jd.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_jd.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_jd.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_jd.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2a[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_jd.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S69>/Max Phi Cmd10'

    // Start for MATLABSystem: '<S64>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_b5.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_b5.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_i;
    RRTV3_PX4_OA_DW.obj_b5.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_b5.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_b5.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_b5.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2b[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_b5.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S64>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S64>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_bi.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_bi.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_bc;
    RRTV3_PX4_OA_DW.obj_bi.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_bi.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_bi.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_bi.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2c[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_bi.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S64>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S64>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_fc.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_fc.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_f;
    RRTV3_PX4_OA_DW.obj_fc.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_fc.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_fc.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_fc.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2d[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_fc.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S64>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S64>/Max Phi Cmd5'
    RRTV3_PX4_OA_DW.obj_m4.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_m4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_nz;
    RRTV3_PX4_OA_DW.obj_m4.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_m4.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_m4.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_m4.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2e[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_m4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S64>/Max Phi Cmd5'

    // Start for MATLABSystem: '<S64>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_om.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_om.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_p5;
    RRTV3_PX4_OA_DW.obj_om.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_om.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_om.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_om.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2f[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_om.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S64>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S64>/Max Phi Cmd4'
    RRTV3_PX4_OA_DW.obj_po.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_po.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_p;
    RRTV3_PX4_OA_DW.obj_po.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_po.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_po.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_po.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2g[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_po.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S64>/Max Phi Cmd4'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd8'
    RRTV3_PX4_OA_DW.obj_el.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_el.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_b;
    RRTV3_PX4_OA_DW.obj_el.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_el.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_el.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_el.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2h[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_el.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd8'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_hwf.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_hwf.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_m;
    RRTV3_PX4_OA_DW.obj_hwf.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_hwf.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_hwf.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_hwf.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2i
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_hwf.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd3'
    RRTV3_PX4_OA_DW.obj_hw.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_hw.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd3_SampleTime_i;
    RRTV3_PX4_OA_DW.obj_hw.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_hw.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_hw.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_hw.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2j[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_hw.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd3'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_gv.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_gv.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_m;
    RRTV3_PX4_OA_DW.obj_gv.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_gv.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_gv.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_gv.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2k[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_gv.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd5'
    RRTV3_PX4_OA_DW.obj_cx2.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_cx2.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_e;
    RRTV3_PX4_OA_DW.obj_cx2.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_cx2.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_cx2.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_cx2.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2l
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_cx2.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd5'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd4'
    RRTV3_PX4_OA_DW.obj_it.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_it.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd4_SampleTime_k;
    RRTV3_PX4_OA_DW.obj_it.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_it.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_it.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_it.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2m[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_it.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd4'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd12'
    RRTV3_PX4_OA_DW.obj_bis.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_bis.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime_p;
    RRTV3_PX4_OA_DW.obj_bis.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_bis.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_bis.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_bis.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2n
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_bis.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd12'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd6'
    RRTV3_PX4_OA_DW.obj_jg.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jg.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd6_SampleTime_o;
    RRTV3_PX4_OA_DW.obj_jg.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_jg.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_jg.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_jg.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2o[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_jg.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd6'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_cx.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_cx.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_g;
    RRTV3_PX4_OA_DW.obj_cx.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_cx.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_cx.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_cx.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2p[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_cx.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd7'
    RRTV3_PX4_OA_DW.obj_jp.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jp.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd7_SampleTime_k;
    RRTV3_PX4_OA_DW.obj_jp.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_jp.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_jp.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_jp.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2q[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_jp.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd7'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd30'
    RRTV3_PX4_OA_DW.obj_ln.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ln.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd30_SampleTime;
    RRTV3_PX4_OA_DW.obj_ln.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ln.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ln.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ln.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2r[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ln.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd30'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd31'
    RRTV3_PX4_OA_DW.obj_cy.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_cy.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd31_SampleTime;
    RRTV3_PX4_OA_DW.obj_cy.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_cy.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_cy.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_cy.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2s[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_cy.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd31'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd11'
    RRTV3_PX4_OA_DW.obj_hc.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_hc.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd11_SampleTime_g;
    RRTV3_PX4_OA_DW.obj_hc.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_hc.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_hc.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_hc.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2t[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_hc.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd11'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd10'
    RRTV3_PX4_OA_DW.obj_c4.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_c4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd10_SampleTime_j;
    RRTV3_PX4_OA_DW.obj_c4.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_c4.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_c4.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_c4.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2u[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_c4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd10'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd23'
    RRTV3_PX4_OA_DW.obj_er.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_er.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd23_SampleTime;
    RRTV3_PX4_OA_DW.obj_er.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_er.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_er.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_er.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2v[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_er.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd23'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd13'
    RRTV3_PX4_OA_DW.obj_pa.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_pa.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd13_SampleTime;
    RRTV3_PX4_OA_DW.obj_pa.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_pa.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_pa.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_pa.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2w[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_pa.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd13'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd18'
    RRTV3_PX4_OA_DW.obj_hb.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_hb.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd18_SampleTime;
    RRTV3_PX4_OA_DW.obj_hb.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_hb.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_hb.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_hb.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2x[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_hb.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd18'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd16'
    RRTV3_PX4_OA_DW.obj_cf.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_cf.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd16_SampleTime;
    RRTV3_PX4_OA_DW.obj_cf.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_cf.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_cf.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_cf.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2y[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_cf.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd16'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd21'
    RRTV3_PX4_OA_DW.obj_jl.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jl.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd21_SampleTime;
    RRTV3_PX4_OA_DW.obj_jl.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_jl.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_jl.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_jl.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2z[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_jl.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd21'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd22'
    RRTV3_PX4_OA_DW.obj_a1.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_a1.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd22_SampleTime;
    RRTV3_PX4_OA_DW.obj_a1.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_a1.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_a1.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_a1.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_30[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_a1.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd22'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd15'
    RRTV3_PX4_OA_DW.obj_bg.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_bg.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd15_SampleTime;
    RRTV3_PX4_OA_DW.obj_bg.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_bg.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_bg.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_bg.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_31[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_bg.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd15'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd14'
    RRTV3_PX4_OA_DW.obj_dg.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_dg.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd14_SampleTime;
    RRTV3_PX4_OA_DW.obj_dg.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_dg.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_dg.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_dg.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_32[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_dg.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd14'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd28'
    RRTV3_PX4_OA_DW.obj_j3.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_j3.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd28_SampleTime;
    RRTV3_PX4_OA_DW.obj_j3.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_j3.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_j3.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_j3.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_33[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_j3.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd28'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd27'
    RRTV3_PX4_OA_DW.obj_j34.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_j34.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd27_SampleTime;
    RRTV3_PX4_OA_DW.obj_j34.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_j34.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_j34.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_j34.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_34
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_j34.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd27'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd26'
    RRTV3_PX4_OA_DW.obj_nn.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_nn.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd26_SampleTime;
    RRTV3_PX4_OA_DW.obj_nn.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_nn.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_nn.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_nn.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_35[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_nn.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd26'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd25'
    RRTV3_PX4_OA_DW.obj_jn.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jn.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd25_SampleTime;
    RRTV3_PX4_OA_DW.obj_jn.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_jn.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_jn.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_jn.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_36[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_jn.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd25'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd20'
    RRTV3_PX4_OA_DW.obj_me.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_me.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd20_SampleTime;
    RRTV3_PX4_OA_DW.obj_me.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_me.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_me.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_me.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_37[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_me.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd20'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd19'
    RRTV3_PX4_OA_DW.obj_fp.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_fp.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd19_SampleTime;
    RRTV3_PX4_OA_DW.obj_fp.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_fp.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_fp.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_fp.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_38[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_fp.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd19'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd17'
    RRTV3_PX4_OA_DW.obj_jfi.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jfi.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd17_SampleTime;
    RRTV3_PX4_OA_DW.obj_jfi.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_jfi.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_jfi.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_jfi.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_39
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_jfi.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd17'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd29'
    RRTV3_PX4_OA_DW.obj_m5.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_m5.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd29_SampleTime;
    RRTV3_PX4_OA_DW.obj_m5.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_m5.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_m5.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_m5.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3a[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_m5.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd29'

    // Start for MATLABSystem: '<S60>/Max Phi Cmd24'
    RRTV3_PX4_OA_DW.obj_i5.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_i5.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd24_SampleTime;
    RRTV3_PX4_OA_DW.obj_i5.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_i5.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_i5.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_i5.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3b[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_i5.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Max Phi Cmd24'

    // Start for MATLABSystem: '<S52>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_jh.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jh.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_dr;
    RRTV3_PX4_OA_DW.obj_jh.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_jh.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_jh.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_jh.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3c[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_jh.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S52>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S52>/Max Phi Cmd5'
    RRTV3_PX4_OA_DW.obj_eo.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_eo.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_m;
    RRTV3_PX4_OA_DW.obj_eo.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_eo.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_eo.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_eo.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3d[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_eo.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S52>/Max Phi Cmd5'

    // Start for MATLABSystem: '<S52>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_bisy.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_bisy.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_k;
    RRTV3_PX4_OA_DW.obj_bisy.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_bisy.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_bisy.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_bisy.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3e[0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_bisy.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S52>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S2>/Max Phi Cmd8'
    RRTV3_PX4_OA_DW.obj_j0.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_j0.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_o;
    RRTV3_PX4_OA_DW.obj_j0.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_j0.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_j0.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_j0.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3f[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_j0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Max Phi Cmd8'

    // Start for MATLABSystem: '<S2>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_ba.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ba.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_d;
    RRTV3_PX4_OA_DW.obj_ba.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ba.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ba.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ba.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3g[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ba.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S51>/Max Phi Cmd8'
    RRTV3_PX4_OA_DW.obj_ji.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ji.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_on;
    RRTV3_PX4_OA_DW.obj_ji.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ji.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ji.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ji.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3h[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ji.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S51>/Max Phi Cmd8'

    // Start for MATLABSystem: '<S51>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_mo.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_mo.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime_h;
    RRTV3_PX4_OA_DW.obj_mo.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_mo.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_mo.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_mo.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3i[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_mo.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S51>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S51>/Max Phi Cmd5'
    RRTV3_PX4_OA_DW.obj_ia.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ia.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime_b;
    RRTV3_PX4_OA_DW.obj_ia.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ia.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ia.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ia.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3j[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ia.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S51>/Max Phi Cmd5'

    // Start for MATLABSystem: '<S51>/Max Phi Cmd12'
    RRTV3_PX4_OA_DW.obj_ja.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ja.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime_d;
    RRTV3_PX4_OA_DW.obj_ja.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ja.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ja.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ja.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3k[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ja.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S51>/Max Phi Cmd12'

    // Start for MATLABSystem: '<S51>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_bt.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_bt.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_j;
    RRTV3_PX4_OA_DW.obj_bt.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_bt.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_bt.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_bt.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3l[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_bt.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S51>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S50>/Max Phi Cmd8'
    RRTV3_PX4_OA_DW.obj_cxq.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_cxq.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime_d;
    RRTV3_PX4_OA_DW.obj_cxq.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_cxq.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_cxq.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_cxq.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3m
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_cxq.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S50>/Max Phi Cmd8'

    // Start for MATLABSystem: '<S50>/Max Phi Cmd9'
    RRTV3_PX4_OA_DW.obj_cl.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_cl.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd9_SampleTime;
    RRTV3_PX4_OA_DW.obj_cl.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_cl.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_cl.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_cl.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3n[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_cl.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S50>/Max Phi Cmd9'

    // Start for MATLABSystem: '<S50>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_f1.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_f1.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime_i;
    RRTV3_PX4_OA_DW.obj_f1.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_f1.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_f1.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_f1.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3o[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_f1.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S50>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S79>/Read Parameter6'
    RRTV3_PX4_OA_DW.obj_f.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_f.SampleTime =
      RRTV3_PX4_OA_P.ReadParameter6_SampleTime_b;
    RRTV3_PX4_OA_DW.obj_f.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_f.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_f.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3p[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S79>/Read Parameter6'

    // Start for MATLABSystem: '<S54>/AUX 1'
    RRTV3_PX4_OA_DW.obj_bge.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_bge.SampleTime = RRTV3_PX4_OA_P.AUX1_SampleTime;
    RRTV3_PX4_OA_DW.obj_bge.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_bge.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_bge.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_bge.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3q
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_bge.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 1'

    // Start for MATLABSystem: '<S54>/AUX 2'
    RRTV3_PX4_OA_DW.obj_k3.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_k3.SampleTime = RRTV3_PX4_OA_P.AUX2_SampleTime;
    RRTV3_PX4_OA_DW.obj_k3.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_k3.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_k3.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_k3.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3r[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_k3.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 2'

    // Start for MATLABSystem: '<S54>/AUX 3'
    RRTV3_PX4_OA_DW.obj_hg.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_hg.SampleTime = RRTV3_PX4_OA_P.AUX3_SampleTime;
    RRTV3_PX4_OA_DW.obj_hg.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_hg.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_hg.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_hg.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3s[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_hg.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 3'

    // Start for MATLABSystem: '<S54>/AUX 4'
    RRTV3_PX4_OA_DW.obj_ml.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ml.SampleTime = RRTV3_PX4_OA_P.AUX4_SampleTime;
    RRTV3_PX4_OA_DW.obj_ml.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ml.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ml.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ml.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3t[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ml.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 4'

    // Start for MATLABSystem: '<S54>/AUX 5'
    RRTV3_PX4_OA_DW.obj_i43.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_i43.SampleTime = RRTV3_PX4_OA_P.AUX5_SampleTime;
    RRTV3_PX4_OA_DW.obj_i43.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_i43.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_i43.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_i43.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3u
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_i43.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 5'

    // Start for MATLABSystem: '<S54>/AUX 12'
    RRTV3_PX4_OA_DW.obj_dr.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_dr.SampleTime = RRTV3_PX4_OA_P.AUX12_SampleTime;
    RRTV3_PX4_OA_DW.obj_dr.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_dr.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_dr.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_dr.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3v[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_dr.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 12'

    // Start for MATLABSystem: '<S54>/AUX 7'
    RRTV3_PX4_OA_DW.obj_jk.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_jk.SampleTime = RRTV3_PX4_OA_P.AUX7_SampleTime;
    RRTV3_PX4_OA_DW.obj_jk.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_jk.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_jk.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_jk.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3w[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_jk.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 7'

    // Start for MATLABSystem: '<S54>/AUX 8'
    RRTV3_PX4_OA_DW.obj_ne.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ne.SampleTime = RRTV3_PX4_OA_P.AUX8_SampleTime;
    RRTV3_PX4_OA_DW.obj_ne.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ne.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ne.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ne.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3x[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ne.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 8'

    // Start for MATLABSystem: '<S3>/PX4 PWM Output1'
    RRTV3_PX4_OA_DW.obj_ec.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ec.isSetupComplete = false;
    RRTV3_PX4_OA_DW.obj_ec.isInitialized = 1;
    RRTV3_PX4_OA_PWM_setupImpl_p(&RRTV3_PX4_OA_DW.obj_ec, false, false);
    RRTV3_PX4_OA_DW.obj_ec.isSetupComplete = true;

    // Start for MATLABSystem: '<S50>/Max Phi Cmd12'
    RRTV3_PX4_OA_DW.obj_eui.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_eui.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd12_SampleTime;
    RRTV3_PX4_OA_DW.obj_eui.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_eui.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_eui.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_eui.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3y
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_eui.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S50>/Max Phi Cmd12'

    // Start for MATLABSystem: '<S50>/Max Phi Cmd5'
    RRTV3_PX4_OA_DW.obj_ftm.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ftm.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd5_SampleTime;
    RRTV3_PX4_OA_DW.obj_ftm.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ftm.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ftm.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ftm.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3z
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ftm.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S50>/Max Phi Cmd5'

    // Start for MATLABSystem: '<S3>/PX4 PWM Output'
    RRTV3_PX4_OA_DW.obj_gg.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_gg.isSetupComplete = false;
    RRTV3_PX4_OA_DW.obj_gg.isInitialized = 1;
    RRTV3_PX4_OA_PWM_setupImpl(&RRTV3_PX4_OA_DW.obj_gg, false, false);
    RRTV3_PX4_OA_DW.obj_gg.isSetupComplete = true;

    // Start for MATLABSystem: '<S49>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_e2.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_e2.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime;
    RRTV3_PX4_OA_DW.obj_e2.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_e2.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_e2.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_e2.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_40[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_e2.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S49>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S49>/Max Phi Cmd2'
    RRTV3_PX4_OA_DW.obj_ck.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ck.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd2_SampleTime;
    RRTV3_PX4_OA_DW.obj_ck.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ck.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ck.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ck.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_41[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ck.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S49>/Max Phi Cmd2'

    // Start for MATLABSystem: '<S49>/Max Phi Cmd8'
    RRTV3_PX4_OA_DW.obj_j4.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_j4.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd8_SampleTime;
    RRTV3_PX4_OA_DW.obj_j4.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_j4.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_j4.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_j4.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_42[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_j4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S49>/Max Phi Cmd8'

    // Start for MATLABSystem: '<S50>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_o2.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_o2.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_k;
    RRTV3_PX4_OA_DW.obj_o2.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_o2.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_o2.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_o2.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_43[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_o2.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S50>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S51>/Max Phi Cmd1'
    RRTV3_PX4_OA_DW.obj_hm.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_hm.SampleTime = RRTV3_PX4_OA_P.MaxPhiCmd1_SampleTime_du;
    RRTV3_PX4_OA_DW.obj_hm.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_hm.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_hm.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_hm.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_44[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_hm.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S51>/Max Phi Cmd1'

    // Start for MATLABSystem: '<S54>/AUX 10'
    RRTV3_PX4_OA_DW.obj_cd.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_cd.SampleTime = RRTV3_PX4_OA_P.AUX10_SampleTime;
    RRTV3_PX4_OA_DW.obj_cd.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_cd.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_cd.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_cd.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_45[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_cd.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 10'

    // Start for MATLABSystem: '<S54>/AUX 11'
    RRTV3_PX4_OA_DW.obj_cf1.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_cf1.SampleTime = RRTV3_PX4_OA_P.AUX11_SampleTime;
    RRTV3_PX4_OA_DW.obj_cf1.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_cf1.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_cf1.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_cf1.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_46
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_cf1.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 11'

    // Start for MATLABSystem: '<S54>/AUX 13'
    RRTV3_PX4_OA_DW.obj_ca.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ca.SampleTime = RRTV3_PX4_OA_P.AUX13_SampleTime;
    RRTV3_PX4_OA_DW.obj_ca.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ca.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ca.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ca.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_47[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ca.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 13'

    // Start for MATLABSystem: '<S54>/AUX 14'
    RRTV3_PX4_OA_DW.obj_dv.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_dv.SampleTime = RRTV3_PX4_OA_P.AUX14_SampleTime;
    RRTV3_PX4_OA_DW.obj_dv.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_dv.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_dv.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_dv.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_48[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_dv.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 14'

    // Start for MATLABSystem: '<S54>/AUX 15'
    RRTV3_PX4_OA_DW.obj_ik.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ik.SampleTime = RRTV3_PX4_OA_P.AUX15_SampleTime;
    RRTV3_PX4_OA_DW.obj_ik.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_ik.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_ik.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_ik.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_49[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_ik.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 15'

    // Start for MATLABSystem: '<S54>/AUX 16'
    RRTV3_PX4_OA_DW.obj_f0.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_f0.SampleTime = RRTV3_PX4_OA_P.AUX16_SampleTime;
    RRTV3_PX4_OA_DW.obj_f0.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_f0.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_f0.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_f0.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_4a[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_f0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 16'

    // Start for MATLABSystem: '<S54>/AUX 17'
    RRTV3_PX4_OA_DW.obj_kf.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_kf.SampleTime = RRTV3_PX4_OA_P.AUX17_SampleTime;
    RRTV3_PX4_OA_DW.obj_kf.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_kf.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_kf.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_kf.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_4b[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_kf.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 17'

    // Start for MATLABSystem: '<S54>/AUX 18'
    RRTV3_PX4_OA_DW.obj_pb0.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_pb0.SampleTime = RRTV3_PX4_OA_P.AUX18_SampleTime;
    RRTV3_PX4_OA_DW.obj_pb0.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_pb0.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_pb0.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_pb0.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_4c
      [0], true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_pb0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 18'

    // Start for MATLABSystem: '<S54>/AUX 6'
    RRTV3_PX4_OA_DW.obj_cj.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_cj.SampleTime = RRTV3_PX4_OA_P.AUX6_SampleTime;
    RRTV3_PX4_OA_DW.obj_cj.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_cj.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_cj.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_cj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_4d[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_cj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 6'

    // Start for MATLABSystem: '<S54>/AUX 9'
    RRTV3_PX4_OA_DW.obj_np.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_np.SampleTime = RRTV3_PX4_OA_P.AUX9_SampleTime;
    RRTV3_PX4_OA_DW.obj_np.isInitialized = 1;
    if (RRTV3_PX4_OA_DW.obj_np.SampleTime == -1.0) {
      Integrator_DSTATE_f = 0.2;
    } else {
      Integrator_DSTATE_f = RRTV3_PX4_OA_DW.obj_np.SampleTime;
    }

    RRTV3_PX4_OA_DW.obj_np.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_4e[0],
      true, Integrator_DSTATE_f * 1000.0);
    RRTV3_PX4_OA_DW.obj_np.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S54>/AUX 9'

    // Start for MATLABSystem: '<S91>/SinkBlock' incorporates:
    //   BusAssignment: '<S5>/Bus Assignment'

    RRTV3_PX4_OA_DW.obj_ej.matlabCodegenIsDeleted = false;
    RRTV3_PX4_OA_DW.obj_ej.isInitialized = 1;
    RRTV3_PX4_OA_DW.obj_ej.orbMetadataObj = ORB_ID(debug_array);
    uORB_write_initialize(RRTV3_PX4_OA_DW.obj_ej.orbMetadataObj,
                          &RRTV3_PX4_OA_DW.obj_ej.orbAdvertiseObj,
                          &RRTV3_PX4_OA_B.BusAssignment, 1);
    RRTV3_PX4_OA_DW.obj_ej.isSetupComplete = true;
  }
}

// Model terminate function
void RRTV3_PX4_OA_terminate(void)
{
  // Terminate for MATLABSystem: '<S85>/SourceBlock'
  if (!RRTV3_PX4_OA_DW.obj_go.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_go.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_go.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_go.isSetupComplete) {
      uORB_read_terminate(&RRTV3_PX4_OA_DW.obj_go.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S85>/SourceBlock'

  // Terminate for MATLABSystem: '<S84>/SourceBlock'
  if (!RRTV3_PX4_OA_DW.obj_am.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_am.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_am.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_am.isSetupComplete) {
      uORB_read_terminate(&RRTV3_PX4_OA_DW.obj_am.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S84>/SourceBlock'

  // Terminate for MATLABSystem: '<S121>/SourceBlock'
  if (!RRTV3_PX4_OA_DW.obj_omq.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_omq.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_omq.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_omq.isSetupComplete) {
      uORB_read_terminate(&RRTV3_PX4_OA_DW.obj_omq.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S121>/SourceBlock'

  // Terminate for MATLABSystem: '<S110>/SourceBlock'
  if (!RRTV3_PX4_OA_DW.obj_mcu.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_mcu.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_mcu.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_mcu.isSetupComplete) {
      uORB_read_terminate(&RRTV3_PX4_OA_DW.obj_mcu.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S110>/SourceBlock'

  // Terminate for MATLABSystem: '<S53>/Max Phi Cmd6'
  if (!RRTV3_PX4_OA_DW.obj_gm.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_gm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S53>/Max Phi Cmd6'

  // Terminate for MATLABSystem: '<S106>/SourceBlock'
  if (!RRTV3_PX4_OA_DW.obj_es.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_es.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_es.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_es.isSetupComplete) {
      uORB_read_terminate(&RRTV3_PX4_OA_DW.obj_es.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S106>/SourceBlock'

  // Terminate for MATLABSystem: '<S107>/SourceBlock'
  if (!RRTV3_PX4_OA_DW.obj_oe.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_oe.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_oe.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_oe.isSetupComplete) {
      uORB_read_terminate(&RRTV3_PX4_OA_DW.obj_oe.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S107>/SourceBlock'

  // Terminate for MATLABSystem: '<S108>/SourceBlock'
  if (!RRTV3_PX4_OA_DW.obj_jx.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jx.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_jx.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_jx.isSetupComplete) {
      uORB_read_terminate(&RRTV3_PX4_OA_DW.obj_jx.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S108>/SourceBlock'

  // Terminate for MATLABSystem: '<S105>/SourceBlock'
  if (!RRTV3_PX4_OA_DW.obj_pd.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_pd.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_pd.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_pd.isSetupComplete) {
      uORB_read_terminate(&RRTV3_PX4_OA_DW.obj_pd.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S105>/SourceBlock'

  // Terminate for MATLABSystem: '<S96>/Read Parameter1'
  if (!RRTV3_PX4_OA_DW.obj.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S96>/Read Parameter1'

  // Terminate for MATLABSystem: '<S109>/SourceBlock'
  if (!RRTV3_PX4_OA_DW.obj_jz.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jz.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_jz.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_jz.isSetupComplete) {
      uORB_read_terminate(&RRTV3_PX4_OA_DW.obj_jz.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S109>/SourceBlock'

  // Terminate for MATLABSystem: '<S53>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_nu.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_nu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S53>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S53>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_p2.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_p2.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S53>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S53>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_bd.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_bd.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S53>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S53>/Max Phi Cmd4'
  if (!RRTV3_PX4_OA_DW.obj_ha.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ha.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S53>/Max Phi Cmd4'

  // Terminate for MATLABSystem: '<S53>/Max Phi Cmd12'
  if (!RRTV3_PX4_OA_DW.obj_m3.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_m3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S53>/Max Phi Cmd12'

  // Terminate for MATLABSystem: '<S53>/Max Phi Cmd5'
  if (!RRTV3_PX4_OA_DW.obj_d5s.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_d5s.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S53>/Max Phi Cmd5'

  // Terminate for MATLABSystem: '<S53>/Max Phi Cmd8'
  if (!RRTV3_PX4_OA_DW.obj_bv.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_bv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S53>/Max Phi Cmd8'

  // Terminate for MATLABSystem: '<S53>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_oa.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_oa.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S53>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S53>/Max Phi Cmd7'
  if (!RRTV3_PX4_OA_DW.obj_d3.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_d3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S53>/Max Phi Cmd7'

  // Terminate for MATLABSystem: '<S4>/Read Parameter6'
  if (!RRTV3_PX4_OA_DW.obj_p.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter6'

  // Terminate for MATLABSystem: '<S83>/Read Parameter7'
  if (!RRTV3_PX4_OA_DW.obj_k.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter7'

  // Terminate for MATLABSystem: '<S83>/Read Parameter5'
  if (!RRTV3_PX4_OA_DW.obj_a.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter5'

  // Terminate for MATLABSystem: '<S83>/Read Parameter6'
  if (!RRTV3_PX4_OA_DW.obj_e.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter6'

  // Terminate for MATLABSystem: '<S81>/SourceBlock'
  if (!RRTV3_PX4_OA_DW.obj_eq.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_eq.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_eq.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_eq.isSetupComplete) {
      uORB_read_terminate(&RRTV3_PX4_OA_DW.obj_eq.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S81>/SourceBlock'

  // Terminate for MATLABSystem: '<S4>/Read Parameter1'
  if (!RRTV3_PX4_OA_DW.obj_ki.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ki.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Read Parameter1'

  // Terminate for MATLABSystem: '<S55>/Max Phi Cmd8'
  if (!RRTV3_PX4_OA_DW.obj_bo.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_bo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/Max Phi Cmd8'

  // Terminate for MATLABSystem: '<S55>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_jum.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jum.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S55>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_pe.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_pe.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S55>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_pas.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_pas.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S55>/Max Phi Cmd5'
  if (!RRTV3_PX4_OA_DW.obj_iw.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_iw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/Max Phi Cmd5'

  // Terminate for MATLABSystem: '<S55>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_eu.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_eu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S57>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_f3.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_f3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S57>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S57>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_hy.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_hy.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S57>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S57>/Max Phi Cmd7'
  if (!RRTV3_PX4_OA_DW.obj_o0.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_o0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S57>/Max Phi Cmd7'

  // Terminate for MATLABSystem: '<S57>/Max Phi Cmd4'
  if (!RRTV3_PX4_OA_DW.obj_aw.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_aw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S57>/Max Phi Cmd4'

  // Terminate for MATLABSystem: '<S57>/Max Phi Cmd6'
  if (!RRTV3_PX4_OA_DW.obj_ci.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ci.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S57>/Max Phi Cmd6'

  // Terminate for MATLABSystem: '<S57>/Max Phi Cmd5'
  if (!RRTV3_PX4_OA_DW.obj_op.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_op.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S57>/Max Phi Cmd5'

  // Terminate for MATLABSystem: '<S56>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_ce.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ce.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S56>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S56>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_cw.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_cw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S56>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S56>/Max Phi Cmd8'
  if (!RRTV3_PX4_OA_DW.obj_i5k.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_i5k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S56>/Max Phi Cmd8'

  // Terminate for MATLABSystem: '<S56>/Max Phi Cmd11'
  if (!RRTV3_PX4_OA_DW.obj_d5.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_d5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S56>/Max Phi Cmd11'

  // Terminate for MATLABSystem: '<S56>/Max Phi Cmd10'
  if (!RRTV3_PX4_OA_DW.obj_b1.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_b1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S56>/Max Phi Cmd10'

  // Terminate for MATLABSystem: '<S58>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_l4.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_l4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S58>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S58>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_ft.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ft.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S58>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S58>/Max Phi Cmd8'
  if (!RRTV3_PX4_OA_DW.obj_hk.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_hk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S58>/Max Phi Cmd8'

  // Terminate for MATLABSystem: '<S58>/Max Phi Cmd11'
  if (!RRTV3_PX4_OA_DW.obj_ey.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ey.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S58>/Max Phi Cmd11'

  // Terminate for MATLABSystem: '<S58>/Max Phi Cmd10'
  if (!RRTV3_PX4_OA_DW.obj_ixo.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ixo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S58>/Max Phi Cmd10'

  // Terminate for MATLABSystem: '<S59>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_hl.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_hl.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S59>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S59>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_oj.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_oj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S59>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S59>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_pm.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_pm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S59>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S67>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_mv.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_mv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S67>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S67>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_mc.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_mc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S67>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S67>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_hd.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_hd.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S67>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S67>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_fx.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_fx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S67>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S67>/Max Phi Cmd7'
  if (!RRTV3_PX4_OA_DW.obj_ac.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ac.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S67>/Max Phi Cmd7'

  // Terminate for MATLABSystem: '<S67>/Max Phi Cmd4'
  if (!RRTV3_PX4_OA_DW.obj_ko.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ko.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S67>/Max Phi Cmd4'

  // Terminate for MATLABSystem: '<S67>/Max Phi Cmd10'
  if (!RRTV3_PX4_OA_DW.obj_l.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S67>/Max Phi Cmd10'

  // Terminate for MATLABSystem: '<S67>/Max Phi Cmd12'
  if (!RRTV3_PX4_OA_DW.obj_ii.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ii.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S67>/Max Phi Cmd12'

  // Terminate for MATLABSystem: '<S67>/Max Phi Cmd11'
  if (!RRTV3_PX4_OA_DW.obj_b.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S67>/Max Phi Cmd11'

  // Terminate for MATLABSystem: '<S68>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_mzd.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_mzd.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S68>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S68>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_h3.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_h3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S68>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S68>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_ix.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ix.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S68>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S65>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_n0.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_n0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S65>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S65>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_bu.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_bu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S65>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S65>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_ag.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ag.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S65>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S62>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_ez.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ez.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S62>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S62>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_l0.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_l0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S62>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S62>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_p4.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_p4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S62>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S62>/Max Phi Cmd5'
  if (!RRTV3_PX4_OA_DW.obj_d.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S62>/Max Phi Cmd5'

  // Terminate for MATLABSystem: '<S62>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_pb.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_pb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S62>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S63>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_lm.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_lm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S63>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S63>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_g.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S63>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S63>/Max Phi Cmd5'
  if (!RRTV3_PX4_OA_DW.obj_os.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_os.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S63>/Max Phi Cmd5'

  // Terminate for MATLABSystem: '<S63>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_jv.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S63>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S63>/Max Phi Cmd4'
  if (!RRTV3_PX4_OA_DW.obj_c.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S63>/Max Phi Cmd4'

  // Terminate for MATLABSystem: '<S66>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_mz4.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_mz4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S66>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S66>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_mj.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_mj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S66>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S66>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_m2.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_m2.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S66>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S66>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_jf.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S66>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S66>/Max Phi Cmd4'
  if (!RRTV3_PX4_OA_DW.obj_eg.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_eg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S66>/Max Phi Cmd4'

  // Terminate for MATLABSystem: '<S70>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_o.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S70>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S70>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_n.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S70>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S70>/Max Phi Cmd5'
  if (!RRTV3_PX4_OA_DW.obj_i.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S70>/Max Phi Cmd5'

  // Terminate for MATLABSystem: '<S70>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_j.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S70>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S69>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_fy.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_fy.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S69>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S69>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_h.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S69>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S69>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_mz.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_mz.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S69>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S69>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_i4.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_i4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S69>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S69>/Max Phi Cmd7'
  if (!RRTV3_PX4_OA_DW.obj_m.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S69>/Max Phi Cmd7'

  // Terminate for MATLABSystem: '<S69>/Max Phi Cmd4'
  if (!RRTV3_PX4_OA_DW.obj_nw.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_nw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S69>/Max Phi Cmd4'

  // Terminate for MATLABSystem: '<S69>/Max Phi Cmd6'
  if (!RRTV3_PX4_OA_DW.obj_km.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_km.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S69>/Max Phi Cmd6'

  // Terminate for MATLABSystem: '<S69>/Max Phi Cmd5'
  if (!RRTV3_PX4_OA_DW.obj_ju.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ju.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S69>/Max Phi Cmd5'

  // Terminate for MATLABSystem: '<S69>/Max Phi Cmd10'
  if (!RRTV3_PX4_OA_DW.obj_jd.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jd.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S69>/Max Phi Cmd10'

  // Terminate for MATLABSystem: '<S64>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_b5.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_b5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S64>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S64>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_bi.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_bi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S64>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S64>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_fc.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_fc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S64>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S64>/Max Phi Cmd5'
  if (!RRTV3_PX4_OA_DW.obj_m4.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_m4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S64>/Max Phi Cmd5'

  // Terminate for MATLABSystem: '<S64>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_om.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_om.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S64>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S64>/Max Phi Cmd4'
  if (!RRTV3_PX4_OA_DW.obj_po.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_po.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S64>/Max Phi Cmd4'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd8'
  if (!RRTV3_PX4_OA_DW.obj_el.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_el.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd8'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_hwf.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_hwf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd3'
  if (!RRTV3_PX4_OA_DW.obj_hw.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_hw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd3'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_gv.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_gv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd5'
  if (!RRTV3_PX4_OA_DW.obj_cx2.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_cx2.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd5'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd4'
  if (!RRTV3_PX4_OA_DW.obj_it.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_it.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd4'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd12'
  if (!RRTV3_PX4_OA_DW.obj_bis.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_bis.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd12'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd6'
  if (!RRTV3_PX4_OA_DW.obj_jg.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd6'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_cx.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_cx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd7'
  if (!RRTV3_PX4_OA_DW.obj_jp.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jp.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd7'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd30'
  if (!RRTV3_PX4_OA_DW.obj_ln.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ln.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd30'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd31'
  if (!RRTV3_PX4_OA_DW.obj_cy.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_cy.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd31'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd11'
  if (!RRTV3_PX4_OA_DW.obj_hc.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_hc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd11'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd10'
  if (!RRTV3_PX4_OA_DW.obj_c4.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_c4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd10'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd23'
  if (!RRTV3_PX4_OA_DW.obj_er.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_er.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd23'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd13'
  if (!RRTV3_PX4_OA_DW.obj_pa.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_pa.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd13'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd18'
  if (!RRTV3_PX4_OA_DW.obj_hb.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_hb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd18'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd16'
  if (!RRTV3_PX4_OA_DW.obj_cf.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_cf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd16'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd21'
  if (!RRTV3_PX4_OA_DW.obj_jl.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jl.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd21'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd22'
  if (!RRTV3_PX4_OA_DW.obj_a1.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_a1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd22'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd15'
  if (!RRTV3_PX4_OA_DW.obj_bg.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_bg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd15'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd14'
  if (!RRTV3_PX4_OA_DW.obj_dg.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_dg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd14'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd28'
  if (!RRTV3_PX4_OA_DW.obj_j3.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_j3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd28'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd27'
  if (!RRTV3_PX4_OA_DW.obj_j34.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_j34.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd27'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd26'
  if (!RRTV3_PX4_OA_DW.obj_nn.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_nn.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd26'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd25'
  if (!RRTV3_PX4_OA_DW.obj_jn.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jn.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd25'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd20'
  if (!RRTV3_PX4_OA_DW.obj_me.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_me.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd20'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd19'
  if (!RRTV3_PX4_OA_DW.obj_fp.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_fp.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd19'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd17'
  if (!RRTV3_PX4_OA_DW.obj_jfi.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jfi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd17'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd29'
  if (!RRTV3_PX4_OA_DW.obj_m5.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_m5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd29'

  // Terminate for MATLABSystem: '<S60>/Max Phi Cmd24'
  if (!RRTV3_PX4_OA_DW.obj_i5.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_i5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Max Phi Cmd24'

  // Terminate for MATLABSystem: '<S52>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_jh.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jh.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S52>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S52>/Max Phi Cmd5'
  if (!RRTV3_PX4_OA_DW.obj_eo.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_eo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S52>/Max Phi Cmd5'

  // Terminate for MATLABSystem: '<S52>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_bisy.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_bisy.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S52>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S2>/Max Phi Cmd8'
  if (!RRTV3_PX4_OA_DW.obj_j0.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_j0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Max Phi Cmd8'

  // Terminate for MATLABSystem: '<S2>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_ba.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ba.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S51>/Max Phi Cmd8'
  if (!RRTV3_PX4_OA_DW.obj_ji.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ji.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S51>/Max Phi Cmd8'

  // Terminate for MATLABSystem: '<S51>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_mo.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_mo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S51>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S51>/Max Phi Cmd5'
  if (!RRTV3_PX4_OA_DW.obj_ia.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ia.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S51>/Max Phi Cmd5'

  // Terminate for MATLABSystem: '<S51>/Max Phi Cmd12'
  if (!RRTV3_PX4_OA_DW.obj_ja.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ja.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S51>/Max Phi Cmd12'

  // Terminate for MATLABSystem: '<S51>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_bt.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_bt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S51>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S50>/Max Phi Cmd8'
  if (!RRTV3_PX4_OA_DW.obj_cxq.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_cxq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S50>/Max Phi Cmd8'

  // Terminate for MATLABSystem: '<S50>/Max Phi Cmd9'
  if (!RRTV3_PX4_OA_DW.obj_cl.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_cl.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S50>/Max Phi Cmd9'

  // Terminate for MATLABSystem: '<S50>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_f1.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_f1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S50>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S79>/Read Parameter6'
  if (!RRTV3_PX4_OA_DW.obj_f.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S79>/Read Parameter6'

  // Terminate for MATLABSystem: '<S54>/AUX 1'
  if (!RRTV3_PX4_OA_DW.obj_bge.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_bge.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 1'

  // Terminate for MATLABSystem: '<S54>/AUX 2'
  if (!RRTV3_PX4_OA_DW.obj_k3.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_k3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 2'

  // Terminate for MATLABSystem: '<S54>/AUX 3'
  if (!RRTV3_PX4_OA_DW.obj_hg.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_hg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 3'

  // Terminate for MATLABSystem: '<S54>/AUX 4'
  if (!RRTV3_PX4_OA_DW.obj_ml.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ml.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 4'

  // Terminate for MATLABSystem: '<S54>/AUX 5'
  if (!RRTV3_PX4_OA_DW.obj_i43.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_i43.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 5'

  // Terminate for MATLABSystem: '<S54>/AUX 12'
  if (!RRTV3_PX4_OA_DW.obj_dr.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_dr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 12'

  // Terminate for MATLABSystem: '<S54>/AUX 7'
  if (!RRTV3_PX4_OA_DW.obj_jk.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_jk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 7'

  // Terminate for MATLABSystem: '<S54>/AUX 8'
  if (!RRTV3_PX4_OA_DW.obj_ne.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ne.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 8'

  // Terminate for MATLABSystem: '<S3>/PX4 PWM Output1'
  if (!RRTV3_PX4_OA_DW.obj_ec.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ec.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_ec.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_ec.isSetupComplete) {
      pwm_disarm(&RRTV3_PX4_OA_DW.obj_ec.armAdvertiseObj);
      pwm_resetServo(RRTV3_PX4_OA_DW.obj_ec.servoCount,
                     RRTV3_PX4_OA_DW.obj_ec.isMain,
                     &RRTV3_PX4_OA_DW.obj_ec.actuatorAdvertiseObj);
      pwm_close(RRTV3_PX4_OA_DW.obj_ec.servoCount,
                &RRTV3_PX4_OA_DW.obj_ec.actuatorAdvertiseObj,
                &RRTV3_PX4_OA_DW.obj_ec.armAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S3>/PX4 PWM Output1'

  // Terminate for MATLABSystem: '<S50>/Max Phi Cmd12'
  if (!RRTV3_PX4_OA_DW.obj_eui.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_eui.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S50>/Max Phi Cmd12'

  // Terminate for MATLABSystem: '<S50>/Max Phi Cmd5'
  if (!RRTV3_PX4_OA_DW.obj_ftm.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ftm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S50>/Max Phi Cmd5'

  // Terminate for MATLABSystem: '<S3>/PX4 PWM Output'
  if (!RRTV3_PX4_OA_DW.obj_gg.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_gg.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_gg.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_gg.isSetupComplete) {
      pwm_disarm(&RRTV3_PX4_OA_DW.obj_gg.armAdvertiseObj);
      pwm_resetServo(RRTV3_PX4_OA_DW.obj_gg.servoCount,
                     RRTV3_PX4_OA_DW.obj_gg.isMain,
                     &RRTV3_PX4_OA_DW.obj_gg.actuatorAdvertiseObj);
      pwm_close(RRTV3_PX4_OA_DW.obj_gg.servoCount,
                &RRTV3_PX4_OA_DW.obj_gg.actuatorAdvertiseObj,
                &RRTV3_PX4_OA_DW.obj_gg.armAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S3>/PX4 PWM Output'

  // Terminate for MATLABSystem: '<S49>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_e2.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_e2.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S49>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S49>/Max Phi Cmd2'
  if (!RRTV3_PX4_OA_DW.obj_ck.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ck.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S49>/Max Phi Cmd2'

  // Terminate for MATLABSystem: '<S49>/Max Phi Cmd8'
  if (!RRTV3_PX4_OA_DW.obj_j4.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_j4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S49>/Max Phi Cmd8'

  // Terminate for MATLABSystem: '<S50>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_o2.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_o2.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S50>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S51>/Max Phi Cmd1'
  if (!RRTV3_PX4_OA_DW.obj_hm.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_hm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S51>/Max Phi Cmd1'

  // Terminate for MATLABSystem: '<S54>/AUX 10'
  if (!RRTV3_PX4_OA_DW.obj_cd.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_cd.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 10'

  // Terminate for MATLABSystem: '<S54>/AUX 11'
  if (!RRTV3_PX4_OA_DW.obj_cf1.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_cf1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 11'

  // Terminate for MATLABSystem: '<S54>/AUX 13'
  if (!RRTV3_PX4_OA_DW.obj_ca.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ca.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 13'

  // Terminate for MATLABSystem: '<S54>/AUX 14'
  if (!RRTV3_PX4_OA_DW.obj_dv.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_dv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 14'

  // Terminate for MATLABSystem: '<S54>/AUX 15'
  if (!RRTV3_PX4_OA_DW.obj_ik.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ik.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 15'

  // Terminate for MATLABSystem: '<S54>/AUX 16'
  if (!RRTV3_PX4_OA_DW.obj_f0.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_f0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 16'

  // Terminate for MATLABSystem: '<S54>/AUX 17'
  if (!RRTV3_PX4_OA_DW.obj_kf.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_kf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 17'

  // Terminate for MATLABSystem: '<S54>/AUX 18'
  if (!RRTV3_PX4_OA_DW.obj_pb0.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_pb0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 18'

  // Terminate for MATLABSystem: '<S54>/AUX 6'
  if (!RRTV3_PX4_OA_DW.obj_cj.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_cj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 6'

  // Terminate for MATLABSystem: '<S54>/AUX 9'
  if (!RRTV3_PX4_OA_DW.obj_np.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_np.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/AUX 9'

  // Terminate for MATLABSystem: '<S91>/SinkBlock'
  if (!RRTV3_PX4_OA_DW.obj_ej.matlabCodegenIsDeleted) {
    RRTV3_PX4_OA_DW.obj_ej.matlabCodegenIsDeleted = true;
    if ((RRTV3_PX4_OA_DW.obj_ej.isInitialized == 1) &&
        RRTV3_PX4_OA_DW.obj_ej.isSetupComplete) {
      uORB_write_terminate(&RRTV3_PX4_OA_DW.obj_ej.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S91>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
