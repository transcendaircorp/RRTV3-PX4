//
// File: RRTV3_PX4_OA_types.h
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
#ifndef RRTV3_PX4_OA_types_h_
#define RRTV3_PX4_OA_types_h_
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include <uORB/topics/debug_vect.h>
#include <uORB/topics/failsafe_flags.h>
#include <uORB/topics/rc_channels.h>
#include <uORB/topics/debug_array.h>
#include <uORB/topics/sensor_gps.h>
#include <uORB/topics/distance_sensor.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_acceleration.h>
#include <uORB/topics/airspeed.h>
#include <uORB/topics/vehicle_local_position.h>
#ifndef DEFINED_TYPEDEF_FOR_struct_gx3jCOK9e6qPe6wEU9rbFD_
#define DEFINED_TYPEDEF_FOR_struct_gx3jCOK9e6qPe6wEU9rbFD_

struct struct_gx3jCOK9e6qPe6wEU9rbFD
{
  real_T VV_Cmd;
  real_T Acc_Cmd;
  real_T V_Cmd;
  real_T phiCmd;
  real_T rCmd;
  real_T DIR;
  real_T HDGmem;
  real_T TRKmem;
  real_T POS;
  real_T ALT;
  real_T ALTmem;
  real_T LongErr;
  real_T LatErr;
  real_T dlat;
  real_T dver;
  real_T ddir;
  real_T dacc;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ixHDEYHWEGb1snVYdLNbKD_
#define DEFINED_TYPEDEF_FOR_struct_ixHDEYHWEGb1snVYdLNbKD_

struct struct_ixHDEYHWEGb1snVYdLNbKD
{
  real_T TWMP_Cmd;
  real_T TWLP_Cmd;
  real_T WingCmd;
  real_T PitchCmd;
  real_T TCS_Mode;
  real_T TWH;
  real_T TWV;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_SgYlKfpOErlBXTbu4h3BVC_
#define DEFINED_TYPEDEF_FOR_struct_SgYlKfpOErlBXTbu4h3BVC_

struct struct_SgYlKfpOErlBXTbu4h3BVC
{
  real_T ulat;
  real_T ulon;
  real_T udir;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ui9GzrWoEdRciRtvzMQi8_
#define DEFINED_TYPEDEF_FOR_struct_ui9GzrWoEdRciRtvzMQi8_

struct struct_ui9GzrWoEdRciRtvzMQi8
{
  real_T LPRPM;
  real_T MPRPM;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_P4dYo7hFyV2JM5WAl5q7GH_
#define DEFINED_TYPEDEF_FOR_struct_P4dYo7hFyV2JM5WAl5q7GH_

struct struct_P4dYo7hFyV2JM5WAl5q7GH
{
  real_T LATSIG;
  real_T LONGSIG;
  real_T SPDSIG;
  real_T WPINDEX;
  real_T DistToTarget;
  real_T TRK_target;
  real_T FPA_target;
  real_T Altpath;
  real_T NAVSTATUS;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_aoDhCARVUiLKrtWxFEloQ_
#define DEFINED_TYPEDEF_FOR_struct_aoDhCARVUiLKrtWxFEloQ_

struct struct_aoDhCARVUiLKrtWxFEloQ
{
  real_T LNAV;
  real_T LNAV_NORM;
  real_T VNAV;
  real_T VNAV_NORM;
  real_T SPD;
  real_T SPD_CUE;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_wz0OBjMbdkTLgUmJwHSIeB_
#define DEFINED_TYPEDEF_FOR_struct_wz0OBjMbdkTLgUmJwHSIeB_

struct struct_wz0OBjMbdkTLgUmJwHSIeB
{
  struct_gx3jCOK9e6qPe6wEU9rbFD PII;
  struct_ixHDEYHWEGb1snVYdLNbKD TCS;
  struct_SgYlKfpOErlBXTbu4h3BVC EMF;
  real_T AP;
  struct_ui9GzrWoEdRciRtvzMQi8 RPM;
  struct_P4dYo7hFyV2JM5WAl5q7GH NAV;
  struct_aoDhCARVUiLKrtWxFEloQ GUIDANCE;
};

#endif

// Custom Type definition for MATLAB Function: '<S13>/MATLAB Function1'
#ifndef struct_captured_var_RRTV3_PX4_OA_T
#define struct_captured_var_RRTV3_PX4_OA_T

struct captured_var_RRTV3_PX4_OA_T
{
  real_T contents;
};

#endif                                 // struct_captured_var_RRTV3_PX4_OA_T

// Custom Type definition for MATLABSystem: '<S96>/Read Parameter1'
#include "MW_Parameter.h"
#ifndef struct_px4_internal_block_ParameterU_T
#define struct_px4_internal_block_ParameterU_T

struct px4_internal_block_ParameterU_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  MW_Param_Handle MW_PARAMHANDLE;
};

#endif                                // struct_px4_internal_block_ParameterU_T

#ifndef struct_px4_internal_block_PWM_RRTV3__T
#define struct_px4_internal_block_PWM_RRTV3__T

struct px4_internal_block_PWM_RRTV3__T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  unsigned int servoCount;
  int channelMask;
  boolean_T isMain;
  orb_advert_t armAdvertiseObj;
  orb_advert_t actuatorAdvertiseObj;
  boolean_T isArmed;
};

#endif                                // struct_px4_internal_block_PWM_RRTV3__T

#ifndef struct_e_px4_internal_block_SampleTi_T
#define struct_e_px4_internal_block_SampleTi_T

struct e_px4_internal_block_SampleTi_T
{
  int32_T __dummy;
};

#endif                                // struct_e_px4_internal_block_SampleTi_T

#ifndef struct_px4_internal_block_Subscriber_T
#define struct_px4_internal_block_Subscriber_T

struct px4_internal_block_Subscriber_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  e_px4_internal_block_SampleTi_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
};

#endif                                // struct_px4_internal_block_Subscriber_T

#ifndef struct_px4_internal_block_Publisher__T
#define struct_px4_internal_block_Publisher__T

struct px4_internal_block_Publisher__T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  orb_advert_t orbAdvertiseObj;
  orb_metadata_t * orbMetadataObj;
};

#endif                                // struct_px4_internal_block_Publisher__T

// Parameters (default storage)
typedef struct P_RRTV3_PX4_OA_T_ P_RRTV3_PX4_OA_T;

// Forward declaration for rtModel
typedef struct tag_RTM_RRTV3_PX4_OA_T RT_MODEL_RRTV3_PX4_OA_T;

#endif                                 // RRTV3_PX4_OA_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
