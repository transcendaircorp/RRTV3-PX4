//
// File: RRTV3_PX4_OA.h
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
#ifndef RRTV3_PX4_OA_h_
#define RRTV3_PX4_OA_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "ScaledPressure2_cgen_wrapper.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "RRTV3_PX4_OA_types.h"
#include <uORB/topics/debug_array.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/rc_channels.h>
#include <uORB/topics/sensor_gps.h>
#include <uORB/topics/debug_vect.h>
#include <uORB/topics/failsafe_flags.h>
#include <uORB/topics/distance_sensor.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/vehicle_acceleration.h>
#include <uORB/topics/airspeed.h>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <string.h>
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

// Block signals (default storage)
struct B_RRTV3_PX4_OA_T {
  real_T PathDef[140];                 // '<S42>/MATLAB Function'
  real_T EMF_Long[99];
  real_T EMF_Dir[99];
  real_T TCS[90];
  real_T EMF_Lat[72];
  real_T PIIParameters[67];            // '<S9>/GAIN SCHEDULER'
  real_T LATCS[36];
  real_T TCSParameters[35];            // '<S9>/GAIN SCHEDULER'
  px4_Bus_debug_array BusAssignment;   // '<S5>/Bus Assignment'
  real_T dv[22];
  px4_Bus_vehicle_local_position In1;  // '<S128>/In1'
  px4_Bus_vehicle_local_position r;
  real_T DistToPoints[20];
  real_T FPAToPoints[20];
  real_T TRKToPoints[20];
  real_T TRKPath[20];
  real_T b_y[20];
  real_T TmpSignalConversionAtSFun_a[20];// '<S13>/MATLAB Function'
  real_T CastToDouble_j[20];           // '<S78>/Cast To Double'
  real_T TmpSignalConversionAtSFun_h[20];// '<S77>/Pilot Inceptor Blending'
  real_T y_tmp[19];
  real_T c_x_tmp[19];
  real_T dv1[19];
  real_T CastToDouble[18];             // '<S79>/Cast To Double'
  px4_Bus_rc_channels In1_f;           // '<S88>/In1'
  px4_Bus_rc_channels r1;
  px4_Bus_sensor_gps In1_d;            // '<S122>/In1'
  px4_Bus_sensor_gps r2;
  real_T AUTOFLIGHT_CMDS[15];          // '<S13>/MATLAB Function1'
  px4_Bus_debug_vect In1_a;            // '<S82>/In1'
  px4_Bus_debug_vect r3;
  real_T rtb_phirad_m[13];
  real_T TmpSignalConversionAtSFu_bn[12];// '<S8>/fcn_EMF_Long'
  px4_Bus_failsafe_flags In1_o;        // '<S87>/In1'
  px4_Bus_failsafe_flags r4;
  real_T TmpSignalConversionAtSFu_b1[11];// '<S9>/GAIN SCHEDULER'
  real_T TmpSignalConversionAtSFu_mc[11];// '<S9>/GAIN SCHEDULER'
  real_T EMF_LongGains[11];            // '<S9>/GAIN SCHEDULER'
  real_T EMF_DirGains[11];             // '<S9>/GAIN SCHEDULER'
  real_T TmpSignalConversionAtSFu_j4[10];// '<S9>/GAIN SCHEDULER'
  real_T TCSGains[10];                 // '<S9>/GAIN SCHEDULER'
  real_T TBI_b[10];                    // '<S13>/MATLAB Function'
  real_T TC[9];
  real_T LATSIG[9];
  real_T TmpSignalConversionAtSFu_ht[8];// '<S9>/GAIN SCHEDULER'
  real_T EMF_LatGains[8];              // '<S9>/GAIN SCHEDULER'
  px4_Bus_distance_sensor r5;
  px4_Bus_vehicle_attitude In1_h;      // '<S125>/In1'
  px4_Bus_distance_sensor In1_a4;      // '<S123>/In1'
  px4_Bus_vehicle_attitude r6;
  real_T NacParameters[6];             // '<S9>/GAIN SCHEDULER'
  real_T AUX[6];                       // '<S3>/Control Surface Mixing'
  real_T dv2[6];
  px4_Bus_vehicle_angular_velocity In1_n;// '<S124>/In1'
  px4_Bus_vehicle_angular_velocity r7;
  real_T TBI_ir[5];                    // '<S12>/MATLAB Function'
  real_T dv3[5];
  real_T rtb_VVms_c[5];
  px4_Bus_vehicle_acceleration In1_g;  // '<S126>/In1'
  px4_Bus_vehicle_acceleration r8;
  px4_Bus_airspeed In1_o2;             // '<S127>/In1'
  px4_Bus_airspeed r9;
  uint16_T pwmValue[8];
  real_T Probe[2];                     // '<S116>/Probe'
  real_T Probe_g[2];                   // '<S111>/Probe'
  real_T GUIDANCE[6];                  // '<S42>/MATLAB Function1'
  real_T MiscOP[9];                    // '<S42>/MATLAB Function1'
  real_T PII_collect[17];              // '<S13>/MATLAB Function'
  real_T TmpSignalConversionAtSFunct[2];// '<S6>/LinVel Bus + INS'
  real_T TmpSignalConversionAtSFun_c[2];// '<S6>/LinVel Bus + INS'
  real_T dv4[2];
  uint16_T DataTypeConversion6[6];     // '<S71>/Data Type Conversion6'
  real_T MPRPM;                        // '<S11>/ RPM LIMITER'
  real_T OutportBufferForControlCmds[17];// '<S1>/CONTROL MIXER//ALLOCATOR'
  real_T LPRPM;                        // '<S11>/Constant'
  real_T AF;                           // '<S13>/AF Encoder'
  real_T TCS_Out[7];                   // '<S12>/MATLAB Function'
  real_T ulon;                         // '<S8>/fcn_EMF_Long'
  real_T ulat;                         // '<S8>/fcn_EMF_Lat'
  real_T udir;                         // '<S8>/fcn_EMF_Dir'
  real_T phi;
  real_T theta;
  real_T psi;
  real_T h_LiDAR;
  real_T h_Pix;
  real_T h2;
  real_T m;
  real_T HDG;
  real_T KEAS;
  real_T VFWD_kts;
  real_T zeta;
  real_T Alt;
  real_T LatRad;
  real_T LongRad;
  real_T WPINDEX;
  real_T TRK_target;
  real_T DistToTarget;
  real_T NAVSTATUS;
  real_T FPA_Target;
  real_T L1;
  real_T z_HDG;
  real_T SPDCMD;
  real_T Arm;                          // '<S79>/Divide'
  real_T Kill;                         // '<S79>/Divide1'
  real_T ControlLevel;                 // '<S79>/Sign2'
  real_T PilotSource;                  // '<S79>/Gain17'
  real_T VD;                           // '<S96>/Multiport Switch1'
  real_T TBI;                          // '<S6>/LinVel Bus + INS'
  real_T VCSkt;                        // '<S93>/Gain15'
  real_T u1;                           // '<S83>/Saturation'
  real_T AP_TKO;                       // '<S83>/MATLAB Function'
  real_T AP_DXN;                       // '<S83>/MATLAB Function'
  real_T AP_AXN;                       // '<S83>/MATLAB Function'
  real_T AP_LND;                       // '<S83>/MATLAB Function'
  real_T AP_NAV;                       // '<S83>/MATLAB Function'
  real_T AP_M1;                        // '<S83>/MATLAB Function'
  real_T AP_M2;                        // '<S83>/MATLAB Function'
  real_T AP_M3;                        // '<S83>/MATLAB Function'
  real_T AP_M4;                        // '<S83>/MATLAB Function'
  real_T AP_M5;                        // '<S83>/MATLAB Function'
  real_T NacelleManualCmd;             // '<S79>/Gain1'
  real_T dver_i;                       // '<S77>/Gain3'
  real_T ddir_h;                       // '<S77>/Gain5'
  real_T dacc_e;                       // '<S77>/Gain4'
  real_T TKO_d;                        // '<S77>/Gain11'
  real_T DXN_p;                        // '<S77>/Gain10'
  real_T NAV_p;                        // '<S77>/Gain9'
  real_T AXN_g;                        // '<S77>/Gain7'
  real_T LND_j;                        // '<S77>/Gain8'
  real_T M1_b;                         // '<S77>/Gain13'
  real_T M2_b;                         // '<S77>/Gain12'
  real_T M3_o;                         // '<S77>/Gain16'
  real_T M4_h;                         // '<S77>/Gain14'
  real_T M5_j;                         // '<S77>/Gain15'
  real_T NacelleAutomaticFlag_p;       // '<S77>/Gain'
  real_T NacelleManualCmd_c;           // '<S77>/Gain1'
  real_T SignalLoss_j;                 // '<S77>/Gain6'
  real_T PilotSource_g;                // '<S77>/Gain17'
  real_T HDGrad;                       // '<S93>/Gain5'
  real_T ayms2;                        // '<S93>/Gain11'
  real_T rtb_CastToDouble_j_k;
  real_T b_y_c;
  real_T TRKPath_b;
  real_T DIRHOLD;
  real_T HDG_mem;
  real_T TRK_mem;
  real_T POSNHOLD;
  real_T LatDeg_mem;
  real_T LongDeg_mem;
  real_T LatDeg_ref;
  real_T LongDeg_ref;
  real_T BankRateCmd;
  real_T HeightError;
  real_T LeftRightPosnErr;
  real_T FwdAftPosnErr;
  real_T LatVelErr;
  real_T DihedralEffect;
  real_T LatVel_kt;
  real_T BANK;
  real_T FPM;
  real_T hAGL_ft;
  real_T TurnRate;
  real_T HDG_p;
  real_T TRK;
  real_T d_lat_inc;
  real_T d_lon_inc;
  real_T d_dir_inc;
  real_T d_acc_inc;
  real_T FPMCmd;
  real_T DissipationGain;
  real_T dHDG;
  real_T FPARateLoadFactorLimits_idx_0;
  real_T FPARateLoadFactorLimits_idx_1;
  real_T Vfwd_ms_tmp;
  real_T u1_tmp;
  real_T b_x;
  real_T absx;
  real_T q;
  real_T AutoTakeoffLevelOffAGL_ft;
  real_T TKOMODE;
  real_T DXNMODE;
  real_T NAVMODE;
  real_T AXNMODE;
  real_T LDGMODE;
  real_T PROGMANEUVER;
  real_T sequencer;
  real_T stopwatch_active;
  real_T hAGL_ft_c;
  real_T HDG_f;
  real_T FPMCmd_g;
  real_T dy;
  real_T dist;
  real_T VREF_FWD_ms;
  real_T FwdAftPosnErr_tmp;
  real_T VCS_ms_tmp;
  real_T alt_ft;
  real_T dalt_ft;
  real_T u1_g;
  real_T TWCmd_ShadowRate;
  real_T WingCmd_Rate;
  real_T Acc;
  real_T Va2;
  real_T F;
  real_T zeta_a;
  real_T DeckLev;
  real_T KFFA;
  real_T th_c;
  real_T b_x_m;
  real_T absx_n;
  captured_var_RRTV3_PX4_OA_T conv_m_to_ft;
  captured_var_RRTV3_PX4_OA_T conv_ms_to_fpm;
  real32_T ParamStep;
  real32_T ParamStep_p;
  real32_T ParamStep_l;
  real32_T ParamStep_j;
  real32_T ParamStep_d;
  real32_T ParamStep_g;
  real32_T ParamStep_ld;
  real32_T ParamStep_dh;
  real32_T ParamStep_dy;
  real32_T ParamStep_lx;
  real32_T ParamStep_o;
  real32_T ParamStep_b;
  real32_T ParamStep_n;
  real32_T ParamStep_bs;
  real32_T ParamStep_ln;
  real32_T ParamStep_h;
  real32_T ParamStep_bn;
  real32_T ParamStep_da;
  real32_T ParamStep_e;
  real32_T ParamStep_bj;
  real32_T ParamStep_jz;
  real32_T ParamStep_f;
  real32_T ParamStep_a;
  real32_T ParamStep_ju;
  real32_T ParamStep_jz5;
  real32_T ParamStep_o4;
  real32_T ParamStep_ny;
  real32_T ParamStep_i;
  real32_T ParamStep_oy;
  real32_T ParamStep_nv;
  real32_T ParamStep_m;
  real32_T ParamStep_c;
  real32_T ParamStep_md;
  real32_T ParamStep_m3;
  real32_T ParamStep_ja;
  real32_T ParamStep_h5;
  real32_T ParamStep_c0;
  real32_T ParamStep_ct;
  real32_T ParamStep_px;
  real32_T ParamStep_p5;
  real32_T ParamStep_af;
  real32_T ParamStep_ev;
  real32_T ParamStep_ax;
  real32_T ParamStep_as;
  real32_T ParamStep_if;
  real32_T ParamStep_lt;
  real32_T ParamStep_oj;
  real32_T ParamStep_o2;
  real32_T ParamStep_ip;
  real32_T ParamStep_fk;
  real32_T ParamStep_iz;
  real32_T ParamStep_ff;
  real32_T ParamStep_gx;
  real32_T ParamStep_co;
  real32_T ParamStep_o3;
  real32_T ParamStep_lm;
  real32_T ParamStep_mv;
  real32_T ParamStep_mj;
  real32_T ParamStep_cn;
  real32_T ParamStep_fm;
  real32_T ParamStep_p4;
  real32_T ParamStep_e1;
  real32_T ParamStep_o4a;
  real32_T ParamStep_hh;
  real32_T ParamStep_l5;
  real32_T ParamStep_h2;
  real32_T ParamStep_me;
  real32_T ParamStep_mc;
  real32_T ParamStep_h3;
  real32_T ParamStep_cs;
  real32_T ParamStep_k;
  real32_T ParamStep_pc;
  real32_T ParamStep_pxv;
  real32_T ParamStep_p4u;
  real32_T ParamStep_ap;
  real32_T ParamStep_jd;
  real32_T ParamStep_ek;
  real32_T ParamStep_ol;
  real32_T ParamStep_bb;
  real32_T ParamStep_ao;
  real32_T ParamStep_g2;
  real32_T ParamStep_ex;
  real32_T ParamStep_fi;
  real32_T ParamStep_h22;
  real32_T ParamStep_ei;
  real32_T ParamStep_ch;
  real32_T ParamStep_axz;
  real32_T ParamStep_dau;
  real32_T ParamStep_af2;
  real32_T ParamStep_pb;
  real32_T ParamStep_ms;
  real32_T ParamStep_o3v;
  real32_T ParamStep_nh;
  real32_T ParamStep_lu;
  real32_T ParamStep_pe;
  real32_T ParamStep_pt;
  real32_T ParamStep_ft;
  real32_T ParamStep_ie;
  real32_T ParamStep_ox;
  real32_T ParamStep_kk;
  real32_T ParamStep_ieu;
  real32_T ParamStep_oc;
  real32_T ParamStep_m4;
  real32_T ParamStep_cu;
  real32_T ParamStep_fb;
  real32_T ParamStep_hc;
  real32_T ParamStep_m44;
  real32_T ParamStep_ad;
  real32_T ParamStep_kb;
  real32_T ParamStep_pcr;
  real32_T ParamStep_bp;
  real32_T ParamStep_chp;
  real32_T ParamStep_nb;
  real32_T ParamStep_ij;
  real32_T ParamStep_my;
  real32_T ParamStep_jg;
  real32_T ParamStep_evk;
  real32_T ParamStep_mvx;
  int32_T gimballock;
  int32_T ParamStep_m0;
  int32_T ParamStep_jgs;
  int32_T ParamStep_fo;
  int32_T Control_Level;               // '<S4>/Control Level Determination'
  int32_T Arm_i;                       // '<S4>/Control Level Determination'
  int32_T Kill_p;                      // '<S4>/Control Level Determination'
  int32_T i;
  int32_T EMF_Long_tmp;
  int32_T LATCS_tmp;
  int16_T DataTypeConversion;          // '<Root>/Data Type Conversion'
};

// Block states (default storage) for system '<Root>'
struct DW_RRTV3_PX4_OA_T {
  px4_internal_block_ParameterU_T obj; // '<S96>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_f;// '<S79>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_k;// '<S83>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_e;// '<S83>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_a;// '<S83>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_p;// '<S4>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_ki;// '<S4>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_o;// '<S70>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_i;// '<S70>/Max Phi Cmd5'
  px4_internal_block_ParameterU_T obj_j;// '<S70>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_n;// '<S70>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_fy;// '<S69>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_m;// '<S69>/Max Phi Cmd7'
  px4_internal_block_ParameterU_T obj_km;// '<S69>/Max Phi Cmd6'
  px4_internal_block_ParameterU_T obj_ju;// '<S69>/Max Phi Cmd5'
  px4_internal_block_ParameterU_T obj_nw;// '<S69>/Max Phi Cmd4'
  px4_internal_block_ParameterU_T obj_mz;// '<S69>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_i4;// '<S69>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_jd;// '<S69>/Max Phi Cmd10'
  px4_internal_block_ParameterU_T obj_h;// '<S69>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_h3;// '<S68>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_ix;// '<S68>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_mzd;// '<S68>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_mv;// '<S67>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_ac;// '<S67>/Max Phi Cmd7'
  px4_internal_block_ParameterU_T obj_ko;// '<S67>/Max Phi Cmd4'
  px4_internal_block_ParameterU_T obj_hd;// '<S67>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_fx;// '<S67>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_ii;// '<S67>/Max Phi Cmd12'
  px4_internal_block_ParameterU_T obj_b;// '<S67>/Max Phi Cmd11'
  px4_internal_block_ParameterU_T obj_l;// '<S67>/Max Phi Cmd10'
  px4_internal_block_ParameterU_T obj_mc;// '<S67>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_mz4;// '<S66>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_eg;// '<S66>/Max Phi Cmd4'
  px4_internal_block_ParameterU_T obj_m2;// '<S66>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_jf;// '<S66>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_mj;// '<S66>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_n0;// '<S65>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_ag;// '<S65>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_bu;// '<S65>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_b5;// '<S64>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_m4;// '<S64>/Max Phi Cmd5'
  px4_internal_block_ParameterU_T obj_po;// '<S64>/Max Phi Cmd4'
  px4_internal_block_ParameterU_T obj_fc;// '<S64>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_om;// '<S64>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_bi;// '<S64>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_lm;// '<S63>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_os;// '<S63>/Max Phi Cmd5'
  px4_internal_block_ParameterU_T obj_c;// '<S63>/Max Phi Cmd4'
  px4_internal_block_ParameterU_T obj_g;// '<S63>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_jv;// '<S63>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_ez;// '<S62>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_d;// '<S62>/Max Phi Cmd5'
  px4_internal_block_ParameterU_T obj_p4;// '<S62>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_pb;// '<S62>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_l0;// '<S62>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_cx;// '<S60>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_el;// '<S60>/Max Phi Cmd8'
  px4_internal_block_ParameterU_T obj_jp;// '<S60>/Max Phi Cmd7'
  px4_internal_block_ParameterU_T obj_jg;// '<S60>/Max Phi Cmd6'
  px4_internal_block_ParameterU_T obj_cx2;// '<S60>/Max Phi Cmd5'
  px4_internal_block_ParameterU_T obj_it;// '<S60>/Max Phi Cmd4'
  px4_internal_block_ParameterU_T obj_cy;// '<S60>/Max Phi Cmd31'
  px4_internal_block_ParameterU_T obj_ln;// '<S60>/Max Phi Cmd30'
  px4_internal_block_ParameterU_T obj_hw;// '<S60>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_m5;// '<S60>/Max Phi Cmd29'
  px4_internal_block_ParameterU_T obj_j3;// '<S60>/Max Phi Cmd28'
  px4_internal_block_ParameterU_T obj_j34;// '<S60>/Max Phi Cmd27'
  px4_internal_block_ParameterU_T obj_nn;// '<S60>/Max Phi Cmd26'
  px4_internal_block_ParameterU_T obj_jn;// '<S60>/Max Phi Cmd25'
  px4_internal_block_ParameterU_T obj_i5;// '<S60>/Max Phi Cmd24'
  px4_internal_block_ParameterU_T obj_er;// '<S60>/Max Phi Cmd23'
  px4_internal_block_ParameterU_T obj_a1;// '<S60>/Max Phi Cmd22'
  px4_internal_block_ParameterU_T obj_jl;// '<S60>/Max Phi Cmd21'
  px4_internal_block_ParameterU_T obj_me;// '<S60>/Max Phi Cmd20'
  px4_internal_block_ParameterU_T obj_gv;// '<S60>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_fp;// '<S60>/Max Phi Cmd19'
  px4_internal_block_ParameterU_T obj_hb;// '<S60>/Max Phi Cmd18'
  px4_internal_block_ParameterU_T obj_jfi;// '<S60>/Max Phi Cmd17'
  px4_internal_block_ParameterU_T obj_cf;// '<S60>/Max Phi Cmd16'
  px4_internal_block_ParameterU_T obj_bg;// '<S60>/Max Phi Cmd15'
  px4_internal_block_ParameterU_T obj_dg;// '<S60>/Max Phi Cmd14'
  px4_internal_block_ParameterU_T obj_pa;// '<S60>/Max Phi Cmd13'
  px4_internal_block_ParameterU_T obj_bis;// '<S60>/Max Phi Cmd12'
  px4_internal_block_ParameterU_T obj_hc;// '<S60>/Max Phi Cmd11'
  px4_internal_block_ParameterU_T obj_c4;// '<S60>/Max Phi Cmd10'
  px4_internal_block_ParameterU_T obj_hwf;// '<S60>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_hl;// '<S59>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_pm;// '<S59>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_oj;// '<S59>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_hk;// '<S58>/Max Phi Cmd8'
  px4_internal_block_ParameterU_T obj_l4;// '<S58>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_ft;// '<S58>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_ey;// '<S58>/Max Phi Cmd11'
  px4_internal_block_ParameterU_T obj_ixo;// '<S58>/Max Phi Cmd10'
  px4_internal_block_ParameterU_T obj_o0;// '<S57>/Max Phi Cmd7'
  px4_internal_block_ParameterU_T obj_ci;// '<S57>/Max Phi Cmd6'
  px4_internal_block_ParameterU_T obj_op;// '<S57>/Max Phi Cmd5'
  px4_internal_block_ParameterU_T obj_aw;// '<S57>/Max Phi Cmd4'
  px4_internal_block_ParameterU_T obj_f3;// '<S57>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_hy;// '<S57>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_i5k;// '<S56>/Max Phi Cmd8'
  px4_internal_block_ParameterU_T obj_ce;// '<S56>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_cw;// '<S56>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_d5;// '<S56>/Max Phi Cmd11'
  px4_internal_block_ParameterU_T obj_b1;// '<S56>/Max Phi Cmd10'
  px4_internal_block_ParameterU_T obj_eu;// '<S55>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_bo;// '<S55>/Max Phi Cmd8'
  px4_internal_block_ParameterU_T obj_iw;// '<S55>/Max Phi Cmd5'
  px4_internal_block_ParameterU_T obj_pe;// '<S55>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_pas;// '<S55>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_jum;// '<S55>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_np;// '<S54>/AUX 9'
  px4_internal_block_ParameterU_T obj_ne;// '<S54>/AUX 8'
  px4_internal_block_ParameterU_T obj_jk;// '<S54>/AUX 7'
  px4_internal_block_ParameterU_T obj_cj;// '<S54>/AUX 6'
  px4_internal_block_ParameterU_T obj_i43;// '<S54>/AUX 5'
  px4_internal_block_ParameterU_T obj_ml;// '<S54>/AUX 4'
  px4_internal_block_ParameterU_T obj_hg;// '<S54>/AUX 3'
  px4_internal_block_ParameterU_T obj_k3;// '<S54>/AUX 2'
  px4_internal_block_ParameterU_T obj_pb0;// '<S54>/AUX 18'
  px4_internal_block_ParameterU_T obj_kf;// '<S54>/AUX 17'
  px4_internal_block_ParameterU_T obj_f0;// '<S54>/AUX 16'
  px4_internal_block_ParameterU_T obj_ik;// '<S54>/AUX 15'
  px4_internal_block_ParameterU_T obj_dv;// '<S54>/AUX 14'
  px4_internal_block_ParameterU_T obj_ca;// '<S54>/AUX 13'
  px4_internal_block_ParameterU_T obj_dr;// '<S54>/AUX 12'
  px4_internal_block_ParameterU_T obj_cf1;// '<S54>/AUX 11'
  px4_internal_block_ParameterU_T obj_cd;// '<S54>/AUX 10'
  px4_internal_block_ParameterU_T obj_bge;// '<S54>/AUX 1'
  px4_internal_block_ParameterU_T obj_oa;// '<S53>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_bv;// '<S53>/Max Phi Cmd8'
  px4_internal_block_ParameterU_T obj_d3;// '<S53>/Max Phi Cmd7'
  px4_internal_block_ParameterU_T obj_gm;// '<S53>/Max Phi Cmd6'
  px4_internal_block_ParameterU_T obj_d5s;// '<S53>/Max Phi Cmd5'
  px4_internal_block_ParameterU_T obj_ha;// '<S53>/Max Phi Cmd4'
  px4_internal_block_ParameterU_T obj_bd;// '<S53>/Max Phi Cmd3'
  px4_internal_block_ParameterU_T obj_nu;// '<S53>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_m3;// '<S53>/Max Phi Cmd12'
  px4_internal_block_ParameterU_T obj_p2;// '<S53>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_eo;// '<S52>/Max Phi Cmd5'
  px4_internal_block_ParameterU_T obj_bisy;// '<S52>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_jh;// '<S52>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_mo;// '<S51>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_ji;// '<S51>/Max Phi Cmd8'
  px4_internal_block_ParameterU_T obj_ia;// '<S51>/Max Phi Cmd5'
  px4_internal_block_ParameterU_T obj_bt;// '<S51>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_ja;// '<S51>/Max Phi Cmd12'
  px4_internal_block_ParameterU_T obj_hm;// '<S51>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_j0;// '<S2>/Max Phi Cmd8'
  px4_internal_block_ParameterU_T obj_ba;// '<S2>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_cl;// '<S50>/Max Phi Cmd9'
  px4_internal_block_ParameterU_T obj_cxq;// '<S50>/Max Phi Cmd8'
  px4_internal_block_ParameterU_T obj_ftm;// '<S50>/Max Phi Cmd5'
  px4_internal_block_ParameterU_T obj_f1;// '<S50>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_eui;// '<S50>/Max Phi Cmd12'
  px4_internal_block_ParameterU_T obj_o2;// '<S50>/Max Phi Cmd1'
  px4_internal_block_ParameterU_T obj_j4;// '<S49>/Max Phi Cmd8'
  px4_internal_block_ParameterU_T obj_ck;// '<S49>/Max Phi Cmd2'
  px4_internal_block_ParameterU_T obj_e2;// '<S49>/Max Phi Cmd1'
  px4_internal_block_Subscriber_T obj_mcu;// '<S110>/SourceBlock'
  px4_internal_block_Subscriber_T obj_jz;// '<S109>/SourceBlock'
  px4_internal_block_Subscriber_T obj_jx;// '<S108>/SourceBlock'
  px4_internal_block_Subscriber_T obj_oe;// '<S107>/SourceBlock'
  px4_internal_block_Subscriber_T obj_es;// '<S106>/SourceBlock'
  px4_internal_block_Subscriber_T obj_pd;// '<S105>/SourceBlock'
  px4_internal_block_Subscriber_T obj_omq;// '<S121>/SourceBlock'
  px4_internal_block_Subscriber_T obj_go;// '<S85>/SourceBlock'
  px4_internal_block_Subscriber_T obj_am;// '<S84>/SourceBlock'
  px4_internal_block_Subscriber_T obj_eq;// '<S81>/SourceBlock'
  px4_internal_block_PWM_RRTV3__T obj_ec;// '<S3>/PX4 PWM Output1'
  px4_internal_block_PWM_RRTV3__T obj_gg;// '<S3>/PX4 PWM Output'
  px4_internal_block_Publisher__T obj_ej;// '<S91>/SinkBlock'
  real_T Integrator_DSTATE;            // '<S120>/Integrator'
  real_T UD_DSTATE;                    // '<S99>/UD'
  real_T UD_DSTATE_m;                  // '<S98>/UD'
  real_T Integrator_DSTATE_c;          // '<S115>/Integrator'
  real_T Integrator_DSTATE_e;          // '<S97>/Integrator'
  real_T UD_DSTATE_mb;                 // '<S75>/UD'
  real_T Integrator_DSTATE_d;          // '<S92>/Integrator'
  real_T Integrator_DSTATE_h[4];       // '<S48>/Integrator'
  real_T Integrator_DSTATE_b;          // '<S44>/Integrator'
  real_T Integrator_DSTATE_f[10];      // '<S43>/Integrator'
  real_T Delay2_DSTATE[2];             // '<S8>/Delay2'
  real_T Integrator_DSTATE_n[3];       // '<S24>/Integrator'
  real_T Integrator_DSTATE_g;          // '<S36>/Integrator'
  real_T Integrator_DSTATE_m[5];       // '<S35>/Integrator'
  real_T Delay1_DSTATE[2];             // '<S8>/Delay1'
  real_T Integrator_DSTATE_mu[4];      // '<S26>/Integrator'
  real_T UD_DSTATE_h;                  // '<S16>/UD'
  real_T Delay_DSTATE;                 // '<S8>/Delay'
  real_T Integrator_DSTATE_hn[4];      // '<S25>/Integrator'
  real_T UD_DSTATE_c;                  // '<S17>/UD'
  real_T RateTransition_Buffer[58];    // '<S5>/Rate Transition'
  real_T Memory2_PreviousInput[7];     // '<S13>/Memory2'
  real_T Memory2_PreviousInput_p[3];   // '<S42>/Memory2'
  real_T Memory1_PreviousInput[22];    // '<S13>/Memory1'
  real_T Memory_PreviousInput[8];      // '<S13>/Memory'
  real_T Memory7_PreviousInput;        // '<S8>/Memory7'
  real_T Memory1_PreviousInput_a;      // '<S12>/Memory1'
  real_T Memory_PreviousInput_l[2];    // '<S12>/Memory'
  real_T Memory3_PreviousInput;        // '<S8>/Memory3'
  real_T Memory1_PreviousInput_b;      // '<S8>/Memory1'
  real_T Memory6_PreviousInput;        // '<S8>/Memory6'
  real32_T UD_DSTATE_p;                // '<S100>/UD'
  int8_T Integrator_PrevResetState;    // '<S120>/Integrator'
  int8_T Integrator_PrevResetState_b;  // '<S115>/Integrator'
  int8_T Integrator_PrevResetState_n;  // '<S97>/Integrator'
  int8_T Integrator_PrevResetState_o;  // '<S92>/Integrator'
  int8_T Integrator_PrevResetState_i;  // '<S48>/Integrator'
  int8_T Integrator_PrevResetState_k;  // '<S44>/Integrator'
  int8_T Integrator_PrevResetState_by; // '<S43>/Integrator'
  int8_T Integrator_PrevResetState_m;  // '<S24>/Integrator'
  int8_T Integrator_PrevResetState_h;  // '<S36>/Integrator'
  int8_T Integrator_PrevResetState_hc; // '<S35>/Integrator'
  int8_T Integrator_PrevResetState_n2; // '<S26>/Integrator'
  int8_T Integrator_PrevResetState_e;  // '<S25>/Integrator'
  uint8_T Integrator_IC_LOADING;       // '<S120>/Integrator'
  uint8_T Integrator_IC_LOADING_p;     // '<S115>/Integrator'
};

// Parameters (default storage)
struct P_RRTV3_PX4_OA_T_ {
  real_T PathDef1[140];                // Variable: PathDef1
                                          //  Referenced by: '<S42>/Constant'

  real_T PathDef2[140];                // Variable: PathDef2
                                          //  Referenced by: '<S42>/Constant2'

  real_T PathDef3[140];                // Variable: PathDef3
                                          //  Referenced by: '<S42>/Constant3'

  real_T PathDef4[140];                // Variable: PathDef4
                                          //  Referenced by: '<S42>/Constant4'

  real_T PathDef5[140];                // Variable: PathDef5
                                          //  Referenced by: '<S42>/Constant5'

  real_T TPPWM_ext[21];                // Variable: TPPWM_ext
                                          //  Referenced by:
                                          //    '<S73>/Tail Prop 1 (UP)'
                                          //    '<S73>/Tail Prop 2 (DOWN)'

  real_T TPRPM_ext[21];                // Variable: TPRPM_ext
                                          //  Referenced by:
                                          //    '<S73>/Tail Prop 1 (UP)'
                                          //    '<S73>/Tail Prop 2 (DOWN)'

  real_T FilteredDerivative2_A;        // Mask Parameter: FilteredDerivative2_A
                                          //  Referenced by: '<S102>/[A,B]'

  real_T FilteredDerivative1_A;        // Mask Parameter: FilteredDerivative1_A
                                          //  Referenced by: '<S101>/[A,B]'

  real_T FilteredDerivative2_B;        // Mask Parameter: FilteredDerivative2_B
                                          //  Referenced by: '<S102>/[A,B]'

  real_T FilteredDerivative1_B;        // Mask Parameter: FilteredDerivative1_B
                                          //  Referenced by: '<S101>/[A,B]'

  real_T u01s1001s2_ICPrevOutput;     // Mask Parameter: u01s1001s2_ICPrevOutput
                                         //  Referenced by: '<S99>/UD'

  real_T u01s1001s_ICPrevOutput;       // Mask Parameter: u01s1001s_ICPrevOutput
                                          //  Referenced by: '<S98>/UD'

  real_T u01s1001s2_ICPrevOutput_g; // Mask Parameter: u01s1001s2_ICPrevOutput_g
                                       //  Referenced by: '<S75>/UD'

  real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S16>/UD'

  real_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S17>/UD'

  real_T FilteredDerivative2_K;        // Mask Parameter: FilteredDerivative2_K
                                          //  Referenced by: '<S102>/Gain'

  real_T FilteredDerivative1_K;        // Mask Parameter: FilteredDerivative1_K
                                          //  Referenced by: '<S101>/Gain'

  real_T u01s1001s2_PoleZ;             // Mask Parameter: u01s1001s2_PoleZ
                                          //  Referenced by: '<S99>/Gain'

  real_T u01s1001s_PoleZ;              // Mask Parameter: u01s1001s_PoleZ
                                          //  Referenced by: '<S98>/Gain'

  real_T u01s1001s2_PoleZ_o;           // Mask Parameter: u01s1001s2_PoleZ_o
                                          //  Referenced by: '<S75>/Gain'

  real_T FilteredDerivative2_T;        // Mask Parameter: FilteredDerivative2_T
                                          //  Referenced by: '<S116>/Time constant'

  real_T FilteredDerivative1_T;        // Mask Parameter: FilteredDerivative1_T
                                          //  Referenced by: '<S111>/Time constant'

  real_T FilteredDerivative2_minRatio;
                                 // Mask Parameter: FilteredDerivative2_minRatio
                                    //  Referenced by: '<S116>/Minimum sampling to time constant ratio'

  real_T FilteredDerivative1_minRatio;
                                 // Mask Parameter: FilteredDerivative1_minRatio
                                    //  Referenced by: '<S111>/Minimum sampling to time constant ratio'

  real32_T u025s1001s1_ICPrevOutput; // Mask Parameter: u025s1001s1_ICPrevOutput
                                        //  Referenced by: '<S100>/UD'

  real32_T u025s1001s1_PoleZ;          // Mask Parameter: u025s1001s1_PoleZ
                                          //  Referenced by: '<S100>/Gain'

  struct_wz0OBjMbdkTLgUmJwHSIeB GCSOut_Y0;// Computed Parameter: GCSOut_Y0
                                             //  Referenced by: '<S1>/GCS Out'

  px4_Bus_debug_array Constant_Value;  // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S90>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S128>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                     //  Referenced by: '<S110>/Constant'

  px4_Bus_rc_channels Out1_Y0_k;       // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S88>/Out1'

  px4_Bus_rc_channels Constant_Value_l;// Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S85>/Constant'

  px4_Bus_sensor_gps Out1_Y0_m;        // Computed Parameter: Out1_Y0_m
                                          //  Referenced by: '<S122>/Out1'

  px4_Bus_sensor_gps Constant_Value_f; // Computed Parameter: Constant_Value_f
                                          //  Referenced by: '<S121>/Constant'

  px4_Bus_debug_vect Out1_Y0_f;        // Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S82>/Out1'

  px4_Bus_debug_vect Constant_Value_nv;// Computed Parameter: Constant_Value_nv
                                          //  Referenced by: '<S81>/Constant'

  px4_Bus_failsafe_flags Out1_Y0_n;    // Computed Parameter: Out1_Y0_n
                                          //  Referenced by: '<S87>/Out1'

  px4_Bus_failsafe_flags Constant_Value_a;// Computed Parameter: Constant_Value_a
                                             //  Referenced by: '<S84>/Constant'

  px4_Bus_distance_sensor Out1_Y0_b;   // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S123>/Out1'

  px4_Bus_distance_sensor Constant_Value_m;// Computed Parameter: Constant_Value_m
                                              //  Referenced by: '<S105>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_fb; // Computed Parameter: Out1_Y0_fb
                                          //  Referenced by: '<S125>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_b;// Computed Parameter: Constant_Value_b
                                               //  Referenced by: '<S107>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_f4;// Computed Parameter: Out1_Y0_f4
                                                 //  Referenced by: '<S124>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                       //  Referenced by: '<S106>/Constant'

  px4_Bus_airspeed Out1_Y0_p;          // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S127>/Out1'

  px4_Bus_airspeed Constant_Value_m5;  // Computed Parameter: Constant_Value_m5
                                          //  Referenced by: '<S109>/Constant'

  px4_Bus_vehicle_acceleration Out1_Y0_c;// Computed Parameter: Out1_Y0_c
                                            //  Referenced by: '<S126>/Out1'

  px4_Bus_vehicle_acceleration Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                   //  Referenced by: '<S108>/Constant'

  real_T ControlCmds_Y0;               // Computed Parameter: ControlCmds_Y0
                                          //  Referenced by: '<S1>/Control Cmds'

  real_T Memory2_InitialCondition[7];  // Expression: zeros(7,1)
                                          //  Referenced by: '<S13>/Memory2'

  real_T Constant2_Value[99];// Expression: Vehicle.Controllers.EMF.Longitudinal
                                //  Referenced by: '<S27>/Constant2'

  real_T Constant4_Value[99]; // Expression: Vehicle.Controllers.EMF.Directional
                                 //  Referenced by: '<S27>/Constant4'

  real_T Constant3_Value[90];       // Expression: Vehicle.Controllers.TCS.Gains
                                       //  Referenced by: '<S27>/Constant3'

  real_T Constant1_Value[72];     // Expression: Vehicle.Controllers.EMF.Lateral
                                     //  Referenced by: '<S27>/Constant1'

  real_T u0400_UpperSat;               // Expression: 400
                                          //  Referenced by: '<S9>/[-40,+400]'

  real_T u0400_LowerSat;               // Expression: -40
                                          //  Referenced by: '<S9>/[-40,+400]'

  real_T Constant_Value_a0[8];        // Expression: Vehicle.Controllers.KEASRef
                                         //  Referenced by: '<S9>/Constant'

  real_T Constant5_Value[36];          // Expression: Vehicle.Controllers.LATCS
                                          //  Referenced by: '<S27>/Constant5'

  real_T Constant6_Value[9];           // Expression: Vehicle.Controls.TurnComp
                                          //  Referenced by: '<S27>/Constant6'

  real_T Constant20_Value[35];     // Expression: Vehicle.Controllers.TCS.Params
                                      //  Referenced by: '<S27>/Constant20'

  real_T Constant22_Value[4];      // Expression: Vehicle.Controllers.WingParams
                                      //  Referenced by: '<S27>/Constant22'

  real_T Constant21_Value[67];  // Expression: Vehicle.Controllers.PIIParameters
                                   //  Referenced by: '<S27>/Constant21'

  real_T Constant1_Value_l[4];         // Expression: [0,0,0,0]
                                          //  Referenced by: '<S42>/Constant1'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S48>/Integrator'

  real_T Integrator_UpperSat;          // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S48>/Integrator'

  real_T Integrator_LowerSat;          // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S48>/Integrator'

  real_T Saturation_UpperSat;          // Expression: windupUpperLimit
                                          //  Referenced by: '<S48>/Saturation'

  real_T Saturation_LowerSat;          // Expression: windupLowerLimit
                                          //  Referenced by: '<S48>/Saturation'

  real_T Memory2_InitialCondition_p[3];// Expression: [0,0,0]
                                          //  Referenced by: '<S42>/Memory2'

  real_T Constant2_Value_b;            // Expression: 0
                                          //  Referenced by: '<S13>/Constant2'

  real_T Integrator_gainval_o;       // Computed Parameter: Integrator_gainval_o
                                        //  Referenced by: '<S44>/Integrator'

  real_T Integrator_UpperSat_l;        // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S44>/Integrator'

  real_T Integrator_LowerSat_h;        // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S44>/Integrator'

  real_T Saturation_UpperSat_b;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S44>/Saturation'

  real_T Saturation_LowerSat_n;        // Expression: windupLowerLimit
                                          //  Referenced by: '<S44>/Saturation'

  real_T Constant_Value_i[10];        // Expression: [0;0;0;0;0;0;TP.KEAS;0;0;0]
                                         //  Referenced by: '<S13>/Constant'

  real_T Integrator_gainval_j;       // Computed Parameter: Integrator_gainval_j
                                        //  Referenced by: '<S43>/Integrator'

  real_T Integrator_UpperSat_p;        // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S43>/Integrator'

  real_T Integrator_LowerSat_m;        // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S43>/Integrator'

  real_T Saturation_UpperSat_f;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S43>/Saturation'

  real_T Saturation_LowerSat_l;        // Expression: windupLowerLimit
                                          //  Referenced by: '<S43>/Saturation'

  real_T Memory1_InitialCondition[22]; // Expression: zeros(22,1)
                                          //  Referenced by: '<S13>/Memory1'

  real_T Memory_InitialCondition[8];
                    // Expression: [0;Init.HDG;0;0;0;0;1;Init.AltMSL_ft-97*3.28]
                       //  Referenced by: '<S13>/Memory'

  real_T Gain_Gain;                    // Expression: 1
                                          //  Referenced by: '<S8>/Gain'

  real_T Memory7_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S8>/Memory7'

  real_T Delay2_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S8>/Delay2'

  real_T Constant_Value_lz[3];         // Expression: [0,0,TP.ULAT]
                                          //  Referenced by: '<S8>/Constant'

  real_T Integrator_gainval_g;       // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S24>/Integrator'

  real_T Integrator_UpperSat_g;        // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S24>/Integrator'

  real_T Integrator_LowerSat_l;        // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S24>/Integrator'

  real_T Saturation_UpperSat_n;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S24>/Saturation'

  real_T Saturation_LowerSat_m;        // Expression: windupLowerLimit
                                          //  Referenced by: '<S24>/Saturation'

  real_T Constant_Value_p[5];          // Expression: zeros(5,1)
                                          //  Referenced by: '<S12>/Constant'

  real_T Memory1_InitialCondition_l;   // Expression: 0
                                          //  Referenced by: '<S12>/Memory1'

  real_T Constant2_Value_e;            // Expression: 0
                                          //  Referenced by: '<S12>/Constant2'

  real_T Integrator_gainval_c;       // Computed Parameter: Integrator_gainval_c
                                        //  Referenced by: '<S36>/Integrator'

  real_T Integrator_UpperSat_pu;       // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S36>/Integrator'

  real_T Integrator_LowerSat_i;        // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S36>/Integrator'

  real_T Saturation_UpperSat_g;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S36>/Saturation'

  real_T Saturation_LowerSat_b;        // Expression: windupLowerLimit
                                          //  Referenced by: '<S36>/Saturation'

  real_T Constant1_Value_n[5];
                           // Expression: [TP.TWH; TP.TWV; TP.AOA; TP.TW; TP.dW]
                              //  Referenced by: '<S12>/Constant1'

  real_T Integrator_gainval_f;       // Computed Parameter: Integrator_gainval_f
                                        //  Referenced by: '<S35>/Integrator'

  real_T Integrator_UpperSat_o[5];     // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S35>/Integrator'

  real_T Integrator_LowerSat_a[5];     // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S35>/Integrator'

  real_T Saturation_UpperSat_fv;       // Expression: windupUpperLimit
                                          //  Referenced by: '<S35>/Saturation'

  real_T Saturation_LowerSat_j;        // Expression: windupLowerLimit
                                          //  Referenced by: '<S35>/Saturation'

  real_T Memory_InitialCondition_o[2]; // Expression: [Init.Mode,1]
                                          //  Referenced by: '<S12>/Memory'

  real_T Gain2_Gain;                   // Expression: 1
                                          //  Referenced by: '<S8>/Gain2'

  real_T Delay1_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S8>/Delay1'

  real_T Constant3_Value_n[4];         // Expression: [0,TP.AOA*pi/180,0,0]
                                          //  Referenced by: '<S8>/Constant3'

  real_T Integrator_gainval_l;       // Computed Parameter: Integrator_gainval_l
                                        //  Referenced by: '<S26>/Integrator'

  real_T Integrator_UpperSat_m;        // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S26>/Integrator'

  real_T Integrator_LowerSat_c;        // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S26>/Integrator'

  real_T Saturation_UpperSat_bs;       // Expression: windupUpperLimit
                                          //  Referenced by: '<S26>/Saturation'

  real_T Saturation_LowerSat_b3;       // Expression: windupLowerLimit
                                          //  Referenced by: '<S26>/Saturation'

  real_T Memory3_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S8>/Memory3'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S16>/TSamp'

  real_T Memory1_InitialCondition_a;   // Expression: 0
                                          //  Referenced by: '<S8>/Memory1'

  real_T Gain1_Gain;                   // Expression: 1
                                          //  Referenced by: '<S8>/Gain1'

  real_T Delay_InitialCondition;       // Expression: 0
                                          //  Referenced by: '<S8>/Delay'

  real_T Constant2_Value_n[4];         // Expression: [0;0;TP.UDIR;0]
                                          //  Referenced by: '<S8>/Constant2'

  real_T Integrator_gainval_k;       // Computed Parameter: Integrator_gainval_k
                                        //  Referenced by: '<S25>/Integrator'

  real_T Integrator_UpperSat_py;       // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S25>/Integrator'

  real_T Integrator_LowerSat_c4;       // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S25>/Integrator'

  real_T Saturation_UpperSat_m;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S25>/Saturation'

  real_T Saturation_LowerSat_bj;       // Expression: windupLowerLimit
                                          //  Referenced by: '<S25>/Saturation'

  real_T Memory6_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S8>/Memory6'

  real_T TSamp_WtEt_b;                 // Computed Parameter: TSamp_WtEt_b
                                          //  Referenced by: '<S17>/TSamp'

  real_T Constant3_Value_d;            // Expression: 2
                                          //  Referenced by: '<S11>/Constant3'

  real_T Gain2_Gain_e;                 // Expression: 9.81
                                          //  Referenced by: '<S11>/Gain2'

  real_T Gain1_Gain_f;                 // Expression: 1
                                          //  Referenced by: '<S11>/Gain1'

  real_T Gain_Gain_g;                  // Expression: 0.51444
                                          //  Referenced by: '<S11>/Gain'

  real_T RPMLIMITER_UpperSat;          // Expression: 8500
                                          //  Referenced by: '<S11>/ RPM LIMITER'

  real_T RPMLIMITER_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S11>/ RPM LIMITER'

  real_T Gain_Gain_j;                  // Expression: 100
                                          //  Referenced by: '<S7>/Gain'

  real_T GEARISFIXEDON15SCALE_Value;   // Expression: 1
                                          //  Referenced by: '<S15>/GEAR IS FIXED ON 1//5 SCALE'

  real_T Constant_Value_fw;            // Expression: 0
                                          //  Referenced by: '<S11>/Constant'

  real_T Constant1_Value_k;            // Expression: 1
                                          //  Referenced by: '<S13>/Constant1'

  real_T MaxPhiCmd1_SampleTime;        // Expression: -1
                                          //  Referenced by: '<S49>/Max Phi Cmd1'

  real_T MaxPhiCmd2_SampleTime;        // Expression: -1
                                          //  Referenced by: '<S49>/Max Phi Cmd2'

  real_T MaxPhiCmd8_SampleTime;        // Expression: -1
                                          //  Referenced by: '<S49>/Max Phi Cmd8'

  real_T MaxPhiCmd1_SampleTime_k;      // Expression: -1
                                          //  Referenced by: '<S50>/Max Phi Cmd1'

  real_T MaxPhiCmd12_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S50>/Max Phi Cmd12'

  real_T MaxPhiCmd2_SampleTime_i;      // Expression: -1
                                          //  Referenced by: '<S50>/Max Phi Cmd2'

  real_T MaxPhiCmd5_SampleTime;        // Expression: -1
                                          //  Referenced by: '<S50>/Max Phi Cmd5'

  real_T MaxPhiCmd8_SampleTime_d;      // Expression: -1
                                          //  Referenced by: '<S50>/Max Phi Cmd8'

  real_T MaxPhiCmd9_SampleTime;        // Expression: -1
                                          //  Referenced by: '<S50>/Max Phi Cmd9'

  real_T MaxPhiCmd1_SampleTime_d;      // Expression: -1
                                          //  Referenced by: '<S2>/Max Phi Cmd1'

  real_T MaxPhiCmd8_SampleTime_o;      // Expression: -1
                                          //  Referenced by: '<S2>/Max Phi Cmd8'

  real_T MaxPhiCmd1_SampleTime_du;     // Expression: -1
                                          //  Referenced by: '<S51>/Max Phi Cmd1'

  real_T MaxPhiCmd12_SampleTime_d;     // Expression: -1
                                          //  Referenced by: '<S51>/Max Phi Cmd12'

  real_T MaxPhiCmd2_SampleTime_j;      // Expression: -1
                                          //  Referenced by: '<S51>/Max Phi Cmd2'

  real_T MaxPhiCmd5_SampleTime_b;      // Expression: -1
                                          //  Referenced by: '<S51>/Max Phi Cmd5'

  real_T MaxPhiCmd8_SampleTime_on;     // Expression: -1
                                          //  Referenced by: '<S51>/Max Phi Cmd8'

  real_T MaxPhiCmd9_SampleTime_h;      // Expression: -1
                                          //  Referenced by: '<S51>/Max Phi Cmd9'

  real_T MaxPhiCmd1_SampleTime_dr;     // Expression: -1
                                          //  Referenced by: '<S52>/Max Phi Cmd1'

  real_T MaxPhiCmd2_SampleTime_k;      // Expression: -1
                                          //  Referenced by: '<S52>/Max Phi Cmd2'

  real_T MaxPhiCmd5_SampleTime_m;      // Expression: -1
                                          //  Referenced by: '<S52>/Max Phi Cmd5'

  real_T MaxPhiCmd1_SampleTime_l;      // Expression: -1
                                          //  Referenced by: '<S53>/Max Phi Cmd1'

  real_T MaxPhiCmd12_SampleTime_dm;    // Expression: -1
                                          //  Referenced by: '<S53>/Max Phi Cmd12'

  real_T MaxPhiCmd2_SampleTime_jy;     // Expression: -1
                                          //  Referenced by: '<S53>/Max Phi Cmd2'

  real_T MaxPhiCmd3_SampleTime;        // Expression: -1
                                          //  Referenced by: '<S53>/Max Phi Cmd3'

  real_T MaxPhiCmd4_SampleTime;        // Expression: -1
                                          //  Referenced by: '<S53>/Max Phi Cmd4'

  real_T MaxPhiCmd5_SampleTime_n;      // Expression: -1
                                          //  Referenced by: '<S53>/Max Phi Cmd5'

  real_T MaxPhiCmd6_SampleTime;        // Expression: -1
                                          //  Referenced by: '<S53>/Max Phi Cmd6'

  real_T MaxPhiCmd7_SampleTime;        // Expression: -1
                                          //  Referenced by: '<S53>/Max Phi Cmd7'

  real_T MaxPhiCmd8_SampleTime_j;      // Expression: -1
                                          //  Referenced by: '<S53>/Max Phi Cmd8'

  real_T MaxPhiCmd9_SampleTime_l;      // Expression: -1
                                          //  Referenced by: '<S53>/Max Phi Cmd9'

  real_T AUX1_SampleTime;              // Expression: -1
                                          //  Referenced by: '<S54>/AUX 1'

  real_T AUX10_SampleTime;             // Expression: -1
                                          //  Referenced by: '<S54>/AUX 10'

  real_T AUX11_SampleTime;             // Expression: -1
                                          //  Referenced by: '<S54>/AUX 11'

  real_T AUX12_SampleTime;             // Expression: -1
                                          //  Referenced by: '<S54>/AUX 12'

  real_T AUX13_SampleTime;             // Expression: -1
                                          //  Referenced by: '<S54>/AUX 13'

  real_T AUX14_SampleTime;             // Expression: -1
                                          //  Referenced by: '<S54>/AUX 14'

  real_T AUX15_SampleTime;             // Expression: -1
                                          //  Referenced by: '<S54>/AUX 15'

  real_T AUX16_SampleTime;             // Expression: -1
                                          //  Referenced by: '<S54>/AUX 16'

  real_T AUX17_SampleTime;             // Expression: -1
                                          //  Referenced by: '<S54>/AUX 17'

  real_T AUX18_SampleTime;             // Expression: -1
                                          //  Referenced by: '<S54>/AUX 18'

  real_T AUX2_SampleTime;              // Expression: -1
                                          //  Referenced by: '<S54>/AUX 2'

  real_T AUX3_SampleTime;              // Expression: -1
                                          //  Referenced by: '<S54>/AUX 3'

  real_T AUX4_SampleTime;              // Expression: -1
                                          //  Referenced by: '<S54>/AUX 4'

  real_T AUX5_SampleTime;              // Expression: -1
                                          //  Referenced by: '<S54>/AUX 5'

  real_T AUX6_SampleTime;              // Expression: -1
                                          //  Referenced by: '<S54>/AUX 6'

  real_T AUX7_SampleTime;              // Expression: -1
                                          //  Referenced by: '<S54>/AUX 7'

  real_T AUX8_SampleTime;              // Expression: -1
                                          //  Referenced by: '<S54>/AUX 8'

  real_T AUX9_SampleTime;              // Expression: -1
                                          //  Referenced by: '<S54>/AUX 9'

  real_T MaxPhiCmd1_SampleTime_b;      // Expression: -1
                                          //  Referenced by: '<S55>/Max Phi Cmd1'

  real_T MaxPhiCmd2_SampleTime_jv;     // Expression: -1
                                          //  Referenced by: '<S55>/Max Phi Cmd2'

  real_T MaxPhiCmd3_SampleTime_h;      // Expression: -1
                                          //  Referenced by: '<S55>/Max Phi Cmd3'

  real_T MaxPhiCmd5_SampleTime_bq;     // Expression: -1
                                          //  Referenced by: '<S55>/Max Phi Cmd5'

  real_T MaxPhiCmd8_SampleTime_n;      // Expression: -1
                                          //  Referenced by: '<S55>/Max Phi Cmd8'

  real_T MaxPhiCmd9_SampleTime_f;      // Expression: -1
                                          //  Referenced by: '<S55>/Max Phi Cmd9'

  real_T MaxPhiCmd10_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S56>/Max Phi Cmd10'

  real_T MaxPhiCmd11_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S56>/Max Phi Cmd11'

  real_T MaxPhiCmd2_SampleTime_p;      // Expression: -1
                                          //  Referenced by: '<S56>/Max Phi Cmd2'

  real_T MaxPhiCmd3_SampleTime_a;      // Expression: -1
                                          //  Referenced by: '<S56>/Max Phi Cmd3'

  real_T MaxPhiCmd8_SampleTime_a;      // Expression: -1
                                          //  Referenced by: '<S56>/Max Phi Cmd8'

  real_T MaxPhiCmd2_SampleTime_g;      // Expression: -1
                                          //  Referenced by: '<S57>/Max Phi Cmd2'

  real_T MaxPhiCmd3_SampleTime_k;      // Expression: -1
                                          //  Referenced by: '<S57>/Max Phi Cmd3'

  real_T MaxPhiCmd4_SampleTime_l;      // Expression: -1
                                          //  Referenced by: '<S57>/Max Phi Cmd4'

  real_T MaxPhiCmd5_SampleTime_h;      // Expression: -1
                                          //  Referenced by: '<S57>/Max Phi Cmd5'

  real_T MaxPhiCmd6_SampleTime_g;      // Expression: -1
                                          //  Referenced by: '<S57>/Max Phi Cmd6'

  real_T MaxPhiCmd7_SampleTime_p;      // Expression: -1
                                          //  Referenced by: '<S57>/Max Phi Cmd7'

  real_T MaxPhiCmd10_SampleTime_f;     // Expression: -1
                                          //  Referenced by: '<S58>/Max Phi Cmd10'

  real_T MaxPhiCmd11_SampleTime_f;     // Expression: -1
                                          //  Referenced by: '<S58>/Max Phi Cmd11'

  real_T MaxPhiCmd2_SampleTime_kw;     // Expression: -1
                                          //  Referenced by: '<S58>/Max Phi Cmd2'

  real_T MaxPhiCmd3_SampleTime_p;      // Expression: -1
                                          //  Referenced by: '<S58>/Max Phi Cmd3'

  real_T MaxPhiCmd8_SampleTime_oa;     // Expression: -1
                                          //  Referenced by: '<S58>/Max Phi Cmd8'

  real_T MaxPhiCmd1_SampleTime_ki;     // Expression: -1
                                          //  Referenced by: '<S59>/Max Phi Cmd1'

  real_T MaxPhiCmd2_SampleTime_l;      // Expression: -1
                                          //  Referenced by: '<S59>/Max Phi Cmd2'

  real_T MaxPhiCmd9_SampleTime_l5;     // Expression: -1
                                          //  Referenced by: '<S59>/Max Phi Cmd9'

  real_T MaxPhiCmd1_SampleTime_m;      // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd1'

  real_T MaxPhiCmd10_SampleTime_j;     // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd10'

  real_T MaxPhiCmd11_SampleTime_g;     // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd11'

  real_T MaxPhiCmd12_SampleTime_p;     // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd12'

  real_T MaxPhiCmd13_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd13'

  real_T MaxPhiCmd14_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd14'

  real_T MaxPhiCmd15_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd15'

  real_T MaxPhiCmd16_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd16'

  real_T MaxPhiCmd17_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd17'

  real_T MaxPhiCmd18_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd18'

  real_T MaxPhiCmd19_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd19'

  real_T MaxPhiCmd2_SampleTime_m;      // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd2'

  real_T MaxPhiCmd20_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd20'

  real_T MaxPhiCmd21_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd21'

  real_T MaxPhiCmd22_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd22'

  real_T MaxPhiCmd23_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd23'

  real_T MaxPhiCmd24_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd24'

  real_T MaxPhiCmd25_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd25'

  real_T MaxPhiCmd26_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd26'

  real_T MaxPhiCmd27_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd27'

  real_T MaxPhiCmd28_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd28'

  real_T MaxPhiCmd29_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd29'

  real_T MaxPhiCmd3_SampleTime_i;      // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd3'

  real_T MaxPhiCmd30_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd30'

  real_T MaxPhiCmd31_SampleTime;       // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd31'

  real_T MaxPhiCmd4_SampleTime_k;      // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd4'

  real_T MaxPhiCmd5_SampleTime_e;      // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd5'

  real_T MaxPhiCmd6_SampleTime_o;      // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd6'

  real_T MaxPhiCmd7_SampleTime_k;      // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd7'

  real_T MaxPhiCmd8_SampleTime_b;      // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd8'

  real_T MaxPhiCmd9_SampleTime_g;      // Expression: -1
                                          //  Referenced by: '<S60>/Max Phi Cmd9'

  real_T MaxPhiCmd1_SampleTime_p;      // Expression: -1
                                          //  Referenced by: '<S62>/Max Phi Cmd1'

  real_T MaxPhiCmd2_SampleTime_c;      // Expression: -1
                                          //  Referenced by: '<S62>/Max Phi Cmd2'

  real_T MaxPhiCmd3_SampleTime_c;      // Expression: -1
                                          //  Referenced by: '<S62>/Max Phi Cmd3'

  real_T MaxPhiCmd5_SampleTime_hb;     // Expression: -1
                                          //  Referenced by: '<S62>/Max Phi Cmd5'

  real_T MaxPhiCmd9_SampleTime_n;      // Expression: -1
                                          //  Referenced by: '<S62>/Max Phi Cmd9'

  real_T MaxPhiCmd2_SampleTime_lv;     // Expression: -1
                                          //  Referenced by: '<S63>/Max Phi Cmd2'

  real_T MaxPhiCmd3_SampleTime_d;      // Expression: -1
                                          //  Referenced by: '<S63>/Max Phi Cmd3'

  real_T MaxPhiCmd4_SampleTime_km;     // Expression: -1
                                          //  Referenced by: '<S63>/Max Phi Cmd4'

  real_T MaxPhiCmd5_SampleTime_p;      // Expression: -1
                                          //  Referenced by: '<S63>/Max Phi Cmd5'

  real_T MaxPhiCmd9_SampleTime_hz;     // Expression: -1
                                          //  Referenced by: '<S63>/Max Phi Cmd9'

  real_T MaxPhiCmd1_SampleTime_bc;     // Expression: -1
                                          //  Referenced by: '<S64>/Max Phi Cmd1'

  real_T MaxPhiCmd2_SampleTime_p5;     // Expression: -1
                                          //  Referenced by: '<S64>/Max Phi Cmd2'

  real_T MaxPhiCmd3_SampleTime_f;      // Expression: -1
                                          //  Referenced by: '<S64>/Max Phi Cmd3'

  real_T MaxPhiCmd4_SampleTime_p;      // Expression: -1
                                          //  Referenced by: '<S64>/Max Phi Cmd4'

  real_T MaxPhiCmd5_SampleTime_nz;     // Expression: -1
                                          //  Referenced by: '<S64>/Max Phi Cmd5'

  real_T MaxPhiCmd9_SampleTime_i;      // Expression: -1
                                          //  Referenced by: '<S64>/Max Phi Cmd9'

  real_T MaxPhiCmd1_SampleTime_o;      // Expression: -1
                                          //  Referenced by: '<S65>/Max Phi Cmd1'

  real_T MaxPhiCmd3_SampleTime_kp;     // Expression: -1
                                          //  Referenced by: '<S65>/Max Phi Cmd3'

  real_T MaxPhiCmd9_SampleTime_h3;     // Expression: -1
                                          //  Referenced by: '<S65>/Max Phi Cmd9'

  real_T MaxPhiCmd1_SampleTime_f;      // Expression: -1
                                          //  Referenced by: '<S66>/Max Phi Cmd1'

  real_T MaxPhiCmd2_SampleTime_n;      // Expression: -1
                                          //  Referenced by: '<S66>/Max Phi Cmd2'

  real_T MaxPhiCmd3_SampleTime_fy;     // Expression: -1
                                          //  Referenced by: '<S66>/Max Phi Cmd3'

  real_T MaxPhiCmd4_SampleTime_pr;     // Expression: -1
                                          //  Referenced by: '<S66>/Max Phi Cmd4'

  real_T MaxPhiCmd9_SampleTime_c;      // Expression: -1
                                          //  Referenced by: '<S66>/Max Phi Cmd9'

  real_T MaxPhiCmd1_SampleTime_n;      // Expression: -1
                                          //  Referenced by: '<S67>/Max Phi Cmd1'

  real_T MaxPhiCmd10_SampleTime_p;     // Expression: -1
                                          //  Referenced by: '<S67>/Max Phi Cmd10'

  real_T MaxPhiCmd11_SampleTime_l;     // Expression: -1
                                          //  Referenced by: '<S67>/Max Phi Cmd11'

  real_T MaxPhiCmd12_SampleTime_h;     // Expression: -1
                                          //  Referenced by: '<S67>/Max Phi Cmd12'

  real_T MaxPhiCmd2_SampleTime_ga;     // Expression: -1
                                          //  Referenced by: '<S67>/Max Phi Cmd2'

  real_T MaxPhiCmd3_SampleTime_i0;     // Expression: -1
                                          //  Referenced by: '<S67>/Max Phi Cmd3'

  real_T MaxPhiCmd4_SampleTime_d;      // Expression: -1
                                          //  Referenced by: '<S67>/Max Phi Cmd4'

  real_T MaxPhiCmd7_SampleTime_e;      // Expression: -1
                                          //  Referenced by: '<S67>/Max Phi Cmd7'

  real_T MaxPhiCmd9_SampleTime_ni;     // Expression: -1
                                          //  Referenced by: '<S67>/Max Phi Cmd9'

  real_T MaxPhiCmd1_SampleTime_j;      // Expression: -1
                                          //  Referenced by: '<S68>/Max Phi Cmd1'

  real_T MaxPhiCmd2_SampleTime_pa;     // Expression: -1
                                          //  Referenced by: '<S68>/Max Phi Cmd2'

  real_T MaxPhiCmd3_SampleTime_j;      // Expression: -1
                                          //  Referenced by: '<S68>/Max Phi Cmd3'

  real_T MaxPhiCmd1_SampleTime_pz;     // Expression: -1
                                          //  Referenced by: '<S69>/Max Phi Cmd1'

  real_T MaxPhiCmd10_SampleTime_pj;    // Expression: -1
                                          //  Referenced by: '<S69>/Max Phi Cmd10'

  real_T MaxPhiCmd2_SampleTime_ju;     // Expression: -1
                                          //  Referenced by: '<S69>/Max Phi Cmd2'

  real_T MaxPhiCmd3_SampleTime_n;      // Expression: -1
                                          //  Referenced by: '<S69>/Max Phi Cmd3'

  real_T MaxPhiCmd4_SampleTime_b;      // Expression: -1
                                          //  Referenced by: '<S69>/Max Phi Cmd4'

  real_T MaxPhiCmd5_SampleTime_f;      // Expression: -1
                                          //  Referenced by: '<S69>/Max Phi Cmd5'

  real_T MaxPhiCmd6_SampleTime_k;      // Expression: -1
                                          //  Referenced by: '<S69>/Max Phi Cmd6'

  real_T MaxPhiCmd7_SampleTime_d;      // Expression: -1
                                          //  Referenced by: '<S69>/Max Phi Cmd7'

  real_T MaxPhiCmd9_SampleTime_a;      // Expression: -1
                                          //  Referenced by: '<S69>/Max Phi Cmd9'

  real_T MaxPhiCmd1_SampleTime_c;      // Expression: -1
                                          //  Referenced by: '<S70>/Max Phi Cmd1'

  real_T MaxPhiCmd2_SampleTime_f;      // Expression: -1
                                          //  Referenced by: '<S70>/Max Phi Cmd2'

  real_T MaxPhiCmd5_SampleTime_c;      // Expression: -1
                                          //  Referenced by: '<S70>/Max Phi Cmd5'

  real_T MaxPhiCmd9_SampleTime_k;      // Expression: -1
                                          //  Referenced by: '<S70>/Max Phi Cmd9'

  real_T ReadParameter1_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S4>/Read Parameter1'

  real_T ReadParameter6_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S4>/Read Parameter6'

  real_T ReadParameter5_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S83>/Read Parameter5'

  real_T ReadParameter6_SampleTime_j;  // Expression: -1
                                          //  Referenced by: '<S83>/Read Parameter6'

  real_T ReadParameter7_SampleTime;    // Expression: -1
                                          //  Referenced by: '<S83>/Read Parameter7'

  real_T ReadParameter6_SampleTime_b;  // Expression: -1
                                          //  Referenced by: '<S79>/Read Parameter6'

  real_T ReadParameter1_SampleTime_i;  // Expression: -1
                                          //  Referenced by: '<S96>/Read Parameter1'

  real_T Gain6_Gain;                   // Expression: 1
                                          //  Referenced by: '<S79>/Gain6'

  real_T Gain17_Gain;                  // Expression: 1
                                          //  Referenced by: '<S79>/Gain17'

  real_T Constant_Value_b3;            // Expression: 0
                                          //  Referenced by: '<S102>/Constant'

  real_T Integrator_gainval_jr;     // Computed Parameter: Integrator_gainval_jr
                                       //  Referenced by: '<S120>/Integrator'

  real_T Integrator_UpperSat_j;        // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S120>/Integrator'

  real_T Integrator_LowerSat_n;        // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S120>/Integrator'

  real_T Saturation_UpperSat_h;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S120>/Saturation'

  real_T Saturation_LowerSat_mt;       // Expression: windupLowerLimit
                                          //  Referenced by: '<S120>/Saturation'

  real_T Gain1_Gain_j;                 // Expression: 1e-7
                                          //  Referenced by: '<S96>/Gain1'

  real_T ue7_Gain;                     // Expression: 1e-7
                                          //  Referenced by: '<S96>/1e-7'

  real_T Constant_Value_in;            // Expression: 0
                                          //  Referenced by: '<S101>/Constant'

  real_T Integrator_gainval_e;       // Computed Parameter: Integrator_gainval_e
                                        //  Referenced by: '<S115>/Integrator'

  real_T Integrator_UpperSat_gg;       // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S115>/Integrator'

  real_T Integrator_LowerSat_ln;       // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S115>/Integrator'

  real_T Saturation_UpperSat_k;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S115>/Saturation'

  real_T Saturation_LowerSat_d;        // Expression: windupLowerLimit
                                          //  Referenced by: '<S115>/Saturation'

  real_T Saturation2_UpperSat;         // Expression: 3
                                          //  Referenced by: '<S96>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -3
                                          //  Referenced by: '<S96>/Saturation2'

  real_T Constant_Value_it;            // Expression: 0
                                          //  Referenced by: '<S6>/Constant'

  real_T Constant2_Value_j;            // Expression: 0
                                          //  Referenced by: '<S6>/Constant2'

  real_T Integrator_gainval_h;       // Computed Parameter: Integrator_gainval_h
                                        //  Referenced by: '<S97>/Integrator'

  real_T Integrator_UpperSat_e;        // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S97>/Integrator'

  real_T Integrator_LowerSat_m5;       // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S97>/Integrator'

  real_T Saturation_UpperSat_a;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S97>/Saturation'

  real_T Saturation_LowerSat_o;        // Expression: windupLowerLimit
                                          //  Referenced by: '<S97>/Saturation'

  real_T Gain7_Gain;                   // Expression: 1
                                          //  Referenced by: '<S93>/Gain7'

  real_T Gain9_Gain;                   // Expression: 1
                                          //  Referenced by: '<S93>/Gain9'

  real_T Gain8_Gain;                   // Expression: 1
                                          //  Referenced by: '<S93>/Gain8'

  real_T Gain13_Gain;                  // Expression: 1
                                          //  Referenced by: '<S93>/Gain13'

  real_T Gain10_Gain;                  // Expression: 1
                                          //  Referenced by: '<S93>/Gain10'

  real_T Gain16_Gain;                  // Expression: 1
                                          //  Referenced by: '<S93>/Gain16'

  real_T Gain18_Gain;                  // Expression: 1
                                          //  Referenced by: '<S93>/Gain18'

  real_T Gain19_Gain;                  // Expression: 1
                                          //  Referenced by: '<S93>/Gain19'

  real_T Gain22_Gain;                  // Expression: 1
                                          //  Referenced by: '<S93>/Gain22'

  real_T Gain15_Gain;                  // Expression: 1
                                          //  Referenced by: '<S93>/Gain15'

  real_T Gain2_Gain_n;                 // Expression: 1
                                          //  Referenced by: '<S79>/Gain2'

  real_T Gain3_Gain;                   // Expression: -1
                                          //  Referenced by: '<S79>/Gain3'

  real_T Gain4_Gain;                   // Expression: 1
                                          //  Referenced by: '<S79>/Gain4'

  real_T Gain5_Gain;                   // Expression: 1
                                          //  Referenced by: '<S79>/Gain5'

  real_T Saturation_UpperSat_c;        // Expression: 1
                                          //  Referenced by: '<S83>/Saturation'

  real_T Saturation_LowerSat_nc;       // Expression: 0
                                          //  Referenced by: '<S83>/Saturation'

  real_T Gain11_Gain;                  // Expression: 1
                                          //  Referenced by: '<S79>/Gain11'

  real_T Gain10_Gain_d;                // Expression: 1
                                          //  Referenced by: '<S79>/Gain10'

  real_T Gain9_Gain_l;                 // Expression: 1
                                          //  Referenced by: '<S79>/Gain9'

  real_T Gain7_Gain_a;                 // Expression: 1
                                          //  Referenced by: '<S79>/Gain7'

  real_T Gain8_Gain_d;                 // Expression: 1
                                          //  Referenced by: '<S79>/Gain8'

  real_T Gain13_Gain_c;                // Expression: 1
                                          //  Referenced by: '<S79>/Gain13'

  real_T Gain12_Gain;                  // Expression: 1
                                          //  Referenced by: '<S79>/Gain12'

  real_T Gain16_Gain_m;                // Expression: 1
                                          //  Referenced by: '<S79>/Gain16'

  real_T Gain14_Gain;                  // Expression: 1
                                          //  Referenced by: '<S79>/Gain14'

  real_T Gain15_Gain_m;                // Expression: 1
                                          //  Referenced by: '<S79>/Gain15'

  real_T Gain_Gain_b;                  // Expression: 1
                                          //  Referenced by: '<S79>/Gain'

  real_T Gain1_Gain_l;                 // Expression: 1
                                          //  Referenced by: '<S79>/Gain1'

  real_T Constant2_Value_h;            // Expression: 0
                                          //  Referenced by: '<S79>/Constant2'

  real_T Gain19_Gain_e;                // Expression: 1
                                          //  Referenced by: '<S79>/Gain19'

  real_T Constant3_Value_i;            // Expression: 0
                                          //  Referenced by: '<S79>/Constant3'

  real_T Gain18_Gain_p;                // Expression: 1
                                          //  Referenced by: '<S79>/Gain18'

  real_T Gain2_Gain_h;                 // Expression: 1
                                          //  Referenced by: '<S78>/Gain2'

  real_T Gain3_Gain_m;                 // Expression: 1
                                          //  Referenced by: '<S78>/Gain3'

  real_T Gain5_Gain_d;                 // Expression: 1
                                          //  Referenced by: '<S78>/Gain5'

  real_T Gain4_Gain_p;                 // Expression: 1
                                          //  Referenced by: '<S78>/Gain4'

  real_T Gain11_Gain_g;                // Expression: 1
                                          //  Referenced by: '<S78>/Gain11'

  real_T Gain10_Gain_c;                // Expression: 1
                                          //  Referenced by: '<S78>/Gain10'

  real_T Gain9_Gain_c;                 // Expression: 1
                                          //  Referenced by: '<S78>/Gain9'

  real_T Gain7_Gain_m;                 // Expression: 1
                                          //  Referenced by: '<S78>/Gain7'

  real_T Gain8_Gain_f;                 // Expression: 1
                                          //  Referenced by: '<S78>/Gain8'

  real_T Gain13_Gain_o;                // Expression: 1
                                          //  Referenced by: '<S78>/Gain13'

  real_T Gain12_Gain_p;                // Expression: 1
                                          //  Referenced by: '<S78>/Gain12'

  real_T Gain16_Gain_p;                // Expression: 1
                                          //  Referenced by: '<S78>/Gain16'

  real_T Gain14_Gain_k;                // Expression: 1
                                          //  Referenced by: '<S78>/Gain14'

  real_T Gain15_Gain_g;                // Expression: 1
                                          //  Referenced by: '<S78>/Gain15'

  real_T Gain_Gain_p;                  // Expression: 1
                                          //  Referenced by: '<S78>/Gain'

  real_T Gain1_Gain_n;                 // Expression: 1
                                          //  Referenced by: '<S78>/Gain1'

  real_T Gain6_Gain_a;                 // Expression: 1
                                          //  Referenced by: '<S78>/Gain6'

  real_T Gain17_Gain_o;                // Expression: 1
                                          //  Referenced by: '<S78>/Gain17'

  real_T Gain18_Gain_h;                // Expression: 1
                                          //  Referenced by: '<S78>/Gain18'

  real_T Gain19_Gain_i;                // Expression: 1
                                          //  Referenced by: '<S78>/Gain19'

  real_T Gain2_Gain_j;                 // Expression: 1
                                          //  Referenced by: '<S77>/Gain2'

  real_T Gain3_Gain_f;                 // Expression: 1
                                          //  Referenced by: '<S77>/Gain3'

  real_T Gain5_Gain_f;                 // Expression: 1
                                          //  Referenced by: '<S77>/Gain5'

  real_T Gain4_Gain_n;                 // Expression: 1
                                          //  Referenced by: '<S77>/Gain4'

  real_T Gain11_Gain_h;                // Expression: 1
                                          //  Referenced by: '<S77>/Gain11'

  real_T Gain10_Gain_m;                // Expression: 1
                                          //  Referenced by: '<S77>/Gain10'

  real_T Gain9_Gain_d;                 // Expression: 1
                                          //  Referenced by: '<S77>/Gain9'

  real_T Gain7_Gain_o;                 // Expression: 1
                                          //  Referenced by: '<S77>/Gain7'

  real_T Gain8_Gain_n;                 // Expression: 1
                                          //  Referenced by: '<S77>/Gain8'

  real_T Gain13_Gain_f;                // Expression: 1
                                          //  Referenced by: '<S77>/Gain13'

  real_T Gain12_Gain_n;                // Expression: 1
                                          //  Referenced by: '<S77>/Gain12'

  real_T Gain16_Gain_d;                // Expression: 1
                                          //  Referenced by: '<S77>/Gain16'

  real_T Gain14_Gain_f;                // Expression: 1
                                          //  Referenced by: '<S77>/Gain14'

  real_T Gain15_Gain_p;                // Expression: 1
                                          //  Referenced by: '<S77>/Gain15'

  real_T Gain_Gain_f;                  // Expression: 1
                                          //  Referenced by: '<S77>/Gain'

  real_T Gain1_Gain_fu;                // Expression: 1
                                          //  Referenced by: '<S77>/Gain1'

  real_T Gain6_Gain_m;                 // Expression: 1
                                          //  Referenced by: '<S77>/Gain6'

  real_T Gain17_Gain_k;                // Expression: 1
                                          //  Referenced by: '<S77>/Gain17'

  real_T Gain19_Gain_p;                // Expression: 1
                                          //  Referenced by: '<S77>/Gain19'

  real_T Gain18_Gain_f;                // Expression: 1
                                          //  Referenced by: '<S77>/Gain18'

  real_T Gain_Gain_m;                  // Expression: 1
                                          //  Referenced by: '<S93>/Gain'

  real_T Gain1_Gain_fg;                // Expression: 1
                                          //  Referenced by: '<S93>/Gain1'

  real_T Gain2_Gain_jw;                // Expression: 1
                                          //  Referenced by: '<S93>/Gain2'

  real_T Gain3_Gain_j;                 // Expression: 1
                                          //  Referenced by: '<S93>/Gain3'

  real_T Gain4_Gain_m;                 // Expression: 1
                                          //  Referenced by: '<S93>/Gain4'

  real_T Gain5_Gain_k;                 // Expression: 1
                                          //  Referenced by: '<S93>/Gain5'

  real_T Gain11_Gain_i;                // Expression: 1
                                          //  Referenced by: '<S93>/Gain11'

  real_T Constant3_Value_i3;           // Expression: 0
                                          //  Referenced by: '<S55>/Constant3'

  real_T Constant1_Value_h;            // Expression: 0
                                          //  Referenced by: '<S55>/Constant1'

  real_T Constant2_Value_ey;           // Expression: 0
                                          //  Referenced by: '<S55>/Constant2'

  real_T Constant4_Value_h;            // Expression: 0.67
                                          //  Referenced by: '<S55>/Constant4'

  real_T Constant_Value_d;             // Expression: 3
                                          //  Referenced by: '<S57>/Constant'

  real_T Constant1_Value_g;            // Expression: 1
                                          //  Referenced by: '<S57>/Constant1'

  real_T Constant_Value_bw;            // Expression: 3
                                          //  Referenced by: '<S56>/Constant'

  real_T Constant1_Value_i;            // Expression: 1
                                          //  Referenced by: '<S56>/Constant1'

  real_T Constant2_Value_i;            // Expression: 0.3
                                          //  Referenced by: '<S56>/Constant2'

  real_T Constant3_Value_g;            // Expression: 3
                                          //  Referenced by: '<S56>/Constant3'

  real_T Constant4_Value_e;            // Expression: 10
                                          //  Referenced by: '<S56>/Constant4'

  real_T Constant5_Value_j;            // Expression: 0
                                          //  Referenced by: '<S56>/Constant5'

  real_T Constant_Value_ac;            // Expression: 3
                                          //  Referenced by: '<S58>/Constant'

  real_T Constant1_Value_kg;           // Expression: 1
                                          //  Referenced by: '<S58>/Constant1'

  real_T Constant2_Value_c;            // Expression: 0.3
                                          //  Referenced by: '<S58>/Constant2'

  real_T Constant3_Value_f;            // Expression: 3
                                          //  Referenced by: '<S58>/Constant3'

  real_T Constant4_Value_b;            // Expression: 10
                                          //  Referenced by: '<S58>/Constant4'

  real_T Constant5_Value_o;            // Expression: 0
                                          //  Referenced by: '<S58>/Constant5'

  real_T Constant_Value_j;             // Expression: 0
                                          //  Referenced by: '<S59>/Constant'

  real_T Constant3_Value_o;            // Expression: 10
                                          //  Referenced by: '<S67>/Constant3'

  real_T Constant2_Value_l;            // Expression: 0.1
                                          //  Referenced by: '<S67>/Constant2'

  real_T Constant1_Value_o;            // Expression: 0.1
                                          //  Referenced by: '<S67>/Constant1'

  real_T Constant_Value_pl;            // Expression: 0.08
                                          //  Referenced by: '<S67>/Constant'

  real_T Constant3_Value_fu;           // Expression: 1
                                          //  Referenced by: '<S68>/Constant3'

  real_T Constant6_Value_h;            // Expression: 20
                                          //  Referenced by: '<S68>/Constant6'

  real_T Constant2_Value_m;            // Expression: 20
                                          //  Referenced by: '<S68>/Constant2'

  real_T Constant_Value_p0;            // Expression: -1
                                          //  Referenced by: '<S68>/Constant'

  real_T Constant1_Value_c;            // Expression: 3
                                          //  Referenced by: '<S68>/Constant1'

  real_T Constant4_Value_f;            // Expression: 100
                                          //  Referenced by: '<S68>/Constant4'

  real_T Constant5_Value_l;            // Expression: 110
                                          //  Referenced by: '<S68>/Constant5'

  real_T Constant1_Value_h5;           // Expression: 0
                                          //  Referenced by: '<S65>/Constant1'

  real_T Constant_Value_lx;            // Expression: 0
                                          //  Referenced by: '<S65>/Constant'

  real_T Constant2_Value_k;            // Expression: 0
                                          //  Referenced by: '<S65>/Constant2'

  real_T Constant1_Value_d;            // Expression: 0.15
                                          //  Referenced by: '<S62>/Constant1'

  real_T Constant1_Value_lx;           // Expression: 0.2
                                          //  Referenced by: '<S63>/Constant1'

  real_T Constant1_Value_b;            // Expression: 0.4
                                          //  Referenced by: '<S66>/Constant1'

  real_T Constant1_Value_kv;           // Expression: 1
                                          //  Referenced by: '<S70>/Constant1'

  real_T Constant12_Value;             // Expression: 0.2
                                          //  Referenced by: '<S60>/Constant12'

  real_T Constant13_Value;             // Expression: 0.5
                                          //  Referenced by: '<S60>/Constant13'

  real_T Constant14_Value;             // Expression: 15
                                          //  Referenced by: '<S60>/Constant14'

  real_T Constant20_Value_p;           // Expression: 1
                                          //  Referenced by: '<S60>/Constant20'

  real_T Constant4_Value_c;            // Expression: 90
                                          //  Referenced by: '<S52>/Constant4'

  real_T Saturation_UpperSat_nd;       // Expression: 1
                                          //  Referenced by: '<S79>/Saturation'

  real_T Saturation_LowerSat_nk;       // Expression: -1
                                          //  Referenced by: '<S79>/Saturation'

  real_T Constant4_Value_j;            // Expression: 0
                                          //  Referenced by: '<S2>/Constant4'

  real_T Constant2_Value_o;            // Expression: 0
                                          //  Referenced by: '<S5>/Constant2'

  real_T Integrator_gainval_n;       // Computed Parameter: Integrator_gainval_n
                                        //  Referenced by: '<S92>/Integrator'

  real_T Integrator_UpperSat_k;        // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S92>/Integrator'

  real_T Integrator_LowerSat_k;        // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S92>/Integrator'

  real_T Saturation_UpperSat_gl;       // Expression: windupUpperLimit
                                          //  Referenced by: '<S92>/Saturation'

  real_T Saturation_LowerSat_dd;       // Expression: windupLowerLimit
                                          //  Referenced by: '<S92>/Saturation'

  real_T u1_UpperSat;                  // Expression: 1
                                          //  Referenced by: '<S3>/[0,1]'

  real_T u1_LowerSat;                  // Expression: 0
                                          //  Referenced by: '<S3>/[0,1]'

  real_T Gain_Gain_d;                  // Expression: 1000
                                          //  Referenced by: '<S3>/Gain'

  real_T Constant_Value_c;             // Expression: 1000
                                          //  Referenced by: '<S3>/Constant'

  real_T Constant_Value_o;             // Expression: 1
                                          //  Referenced by: '<S73>/Constant'

  real_T MainProp1_tableData[20];      // Expression: MPPWM_ext(2:end)
                                          //  Referenced by: '<S73>/Main Prop 1'

  real_T MainProp1_bp01Data[20];       // Expression: MPRPM_ext(2:end)
                                          //  Referenced by: '<S73>/Main Prop 1'

  real_T MainProp2_tableData[20];      // Expression: MPPWM_ext(2:end)
                                          //  Referenced by: '<S73>/Main Prop 2'

  real_T MainProp2_bp01Data[20];       // Expression: MPRPM_ext(2:end)
                                          //  Referenced by: '<S73>/Main Prop 2'

  real_T u0002000_UpperSat;            // Expression: 2000
                                          //  Referenced by: '<S73>/[1000,2000]'

  real_T u0002000_LowerSat;            // Expression: 1000
                                          //  Referenced by: '<S73>/[1000,2000]'

  real_T u0002000_UpperSat_b;          // Expression: 2000
                                          //  Referenced by: '<S73>/[1000 2000]'

  real_T u0002000_LowerSat_a;          // Expression: 1000
                                          //  Referenced by: '<S73>/[1000 2000]'

  real_T u00020001_UpperSat;           // Expression: 2000
                                          //  Referenced by: '<S73>/[1000,2000]1'

  real_T u00020001_LowerSat;           // Expression: 1000
                                          //  Referenced by: '<S73>/[1000,2000]1'

  real_T u00020001_UpperSat_h;         // Expression: 2000
                                          //  Referenced by: '<S73>/[1000 2000]1'

  real_T u00020001_LowerSat_h;         // Expression: 1000
                                          //  Referenced by: '<S73>/[1000 2000]1'

  real_T Multiply_Gain;                // Expression: 100
                                          //  Referenced by: '<Root>/Multiply'

};

// Real-time Model Data Structure
struct tag_RTM_RRTV3_PX4_OA_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_RRTV3_PX4_OA_T RRTV3_PX4_OA_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_RRTV3_PX4_OA_T RRTV3_PX4_OA_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_RRTV3_PX4_OA_T RRTV3_PX4_OA_DW;

// External function called from main
#ifdef __cplusplus

extern "C"
{

#endif

  extern void RRTV3_PX4_OA_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void RRTV3_PX4_OA_initialize(void);
  extern void RRTV3_PX4_OA_step0(void);
  extern void RRTV3_PX4_OA_step1(void);
  extern void RRTV3_PX4_OA_step(int_T tid);
  extern void RRTV3_PX4_OA_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_RRTV3_PX4_OA_T *const RRTV3_PX4_OA_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S16>/Data Type Duplicate' : Unused code path elimination
//  Block '<S17>/Data Type Duplicate' : Unused code path elimination
//  Block '<S12>/Display1' : Unused code path elimination
//  Block '<S12>/Display11' : Unused code path elimination
//  Block '<S49>/Data Type Conversion1' : Unused code path elimination
//  Block '<S49>/Data Type Conversion2' : Unused code path elimination
//  Block '<S49>/Data Type Conversion3' : Unused code path elimination
//  Block '<S50>/Data Type Conversion1' : Unused code path elimination
//  Block '<S51>/Constant4' : Unused code path elimination
//  Block '<S51>/Data Type Conversion1' : Unused code path elimination
//  Block '<S51>/Data Type Conversion8' : Unused code path elimination
//  Block '<S52>/Constant1' : Unused code path elimination
//  Block '<S52>/Constant2' : Unused code path elimination
//  Block '<S54>/Data Type Conversion10' : Unused code path elimination
//  Block '<S54>/Data Type Conversion12' : Unused code path elimination
//  Block '<S54>/Data Type Conversion13' : Unused code path elimination
//  Block '<S54>/Data Type Conversion14' : Unused code path elimination
//  Block '<S54>/Data Type Conversion15' : Unused code path elimination
//  Block '<S54>/Data Type Conversion16' : Unused code path elimination
//  Block '<S54>/Data Type Conversion17' : Unused code path elimination
//  Block '<S54>/Data Type Conversion5' : Unused code path elimination
//  Block '<S54>/Data Type Conversion8' : Unused code path elimination
//  Block '<S54>/Data Type Conversion9' : Unused code path elimination
//  Block '<S75>/Data Type Duplicate' : Unused code path elimination
//  Block '<S81>/NOT' : Unused code path elimination
//  Block '<S79>/Constant' : Unused code path elimination
//  Block '<S79>/Constant1' : Unused code path elimination
//  Block '<S79>/Data Type Conversion2' : Unused code path elimination
//  Block '<S84>/NOT' : Unused code path elimination
//  Block '<S85>/NOT' : Unused code path elimination
//  Block '<S93>/Gain12' : Unused code path elimination
//  Block '<S93>/Gain14' : Unused code path elimination
//  Block '<S93>/Gain20' : Unused code path elimination
//  Block '<S93>/Gain21' : Unused code path elimination
//  Block '<S93>/Gain6' : Unused code path elimination
//  Block '<S98>/Data Type Duplicate' : Unused code path elimination
//  Block '<S99>/Data Type Duplicate' : Unused code path elimination
//  Block '<S100>/Data Type Duplicate' : Unused code path elimination
//  Block '<S96>/Data Type Conversion11' : Unused code path elimination
//  Block '<S121>/NOT' : Unused code path elimination
//  Block '<S105>/NOT' : Unused code path elimination
//  Block '<S106>/NOT' : Unused code path elimination
//  Block '<S107>/NOT' : Unused code path elimination
//  Block '<S108>/NOT' : Unused code path elimination
//  Block '<S109>/NOT' : Unused code path elimination
//  Block '<S110>/NOT' : Unused code path elimination
//  Block '<S9>/Reshape1' : Reshape block reduction
//  Block '<S2>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S55>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S60>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S65>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S71>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S6>/Data Type Conversion8' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'RRTV3_PX4_OA'
//  '<S1>'   : 'RRTV3_PX4_OA/Controllers'
//  '<S2>'   : 'RRTV3_PX4_OA/External Gains//Parameters'
//  '<S3>'   : 'RRTV3_PX4_OA/PWM Mapping'
//  '<S4>'   : 'RRTV3_PX4_OA/Pilot Commands'
//  '<S5>'   : 'RRTV3_PX4_OA/Post-Processing'
//  '<S6>'   : 'RRTV3_PX4_OA/Sensor Outputs'
//  '<S7>'   : 'RRTV3_PX4_OA/Controllers/CONTROL MIXER//ALLOCATOR'
//  '<S8>'   : 'RRTV3_PX4_OA/Controllers/EMF Inner-Loops'
//  '<S9>'   : 'RRTV3_PX4_OA/Controllers/GAIN SCHEDULE'
//  '<S10>'  : 'RRTV3_PX4_OA/Controllers/GCS Signals'
//  '<S11>'  : 'RRTV3_PX4_OA/Controllers/Inverse Propulsor Model'
//  '<S12>'  : 'RRTV3_PX4_OA/Controllers/TCS Core'
//  '<S13>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation'
//  '<S14>'  : 'RRTV3_PX4_OA/Controllers/CONTROL MIXER//ALLOCATOR/Control Allocation (shell)'
//  '<S15>'  : 'RRTV3_PX4_OA/Controllers/CONTROL MIXER//ALLOCATOR/Subsystem'
//  '<S16>'  : 'RRTV3_PX4_OA/Controllers/EMF Inner-Loops/Discrete Derivative'
//  '<S17>'  : 'RRTV3_PX4_OA/Controllers/EMF Inner-Loops/Discrete Derivative1'
//  '<S18>'  : 'RRTV3_PX4_OA/Controllers/EMF Inner-Loops/Integrator (Discrete or Continuous)'
//  '<S19>'  : 'RRTV3_PX4_OA/Controllers/EMF Inner-Loops/Integrator (Discrete or Continuous)1'
//  '<S20>'  : 'RRTV3_PX4_OA/Controllers/EMF Inner-Loops/Integrator (Discrete or Continuous)2'
//  '<S21>'  : 'RRTV3_PX4_OA/Controllers/EMF Inner-Loops/fcn_EMF_Dir'
//  '<S22>'  : 'RRTV3_PX4_OA/Controllers/EMF Inner-Loops/fcn_EMF_Lat'
//  '<S23>'  : 'RRTV3_PX4_OA/Controllers/EMF Inner-Loops/fcn_EMF_Long'
//  '<S24>'  : 'RRTV3_PX4_OA/Controllers/EMF Inner-Loops/Integrator (Discrete or Continuous)/Discrete'
//  '<S25>'  : 'RRTV3_PX4_OA/Controllers/EMF Inner-Loops/Integrator (Discrete or Continuous)1/Discrete'
//  '<S26>'  : 'RRTV3_PX4_OA/Controllers/EMF Inner-Loops/Integrator (Discrete or Continuous)2/Discrete'
//  '<S27>'  : 'RRTV3_PX4_OA/Controllers/GAIN SCHEDULE/Fixed Gain Schedule'
//  '<S28>'  : 'RRTV3_PX4_OA/Controllers/GAIN SCHEDULE/GAIN SCHEDULER'
//  '<S29>'  : 'RRTV3_PX4_OA/Controllers/Inverse Propulsor Model/MATLAB Function'
//  '<S30>'  : 'RRTV3_PX4_OA/Controllers/Inverse Propulsor Model/MATLAB Function1'
//  '<S31>'  : 'RRTV3_PX4_OA/Controllers/TCS Core/Integrator (Discrete or Continuous)'
//  '<S32>'  : 'RRTV3_PX4_OA/Controllers/TCS Core/Integrator (Discrete or Continuous)1'
//  '<S33>'  : 'RRTV3_PX4_OA/Controllers/TCS Core/MATLAB Function'
//  '<S34>'  : 'RRTV3_PX4_OA/Controllers/TCS Core/OBSTACLE AVOIDANCE'
//  '<S35>'  : 'RRTV3_PX4_OA/Controllers/TCS Core/Integrator (Discrete or Continuous)/Discrete'
//  '<S36>'  : 'RRTV3_PX4_OA/Controllers/TCS Core/Integrator (Discrete or Continuous)1/Discrete'
//  '<S37>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation/AF Encoder'
//  '<S38>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation/Integrator'
//  '<S39>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation/Integrator (Discrete or Continuous)'
//  '<S40>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation/MATLAB Function'
//  '<S41>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation/MATLAB Function1'
//  '<S42>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation/NAVIGATION'
//  '<S43>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation/Integrator/Discrete'
//  '<S44>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation/Integrator (Discrete or Continuous)/Discrete'
//  '<S45>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation/NAVIGATION/Integrator (Discrete or Continuous)1'
//  '<S46>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation/NAVIGATION/MATLAB Function'
//  '<S47>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation/NAVIGATION/MATLAB Function1'
//  '<S48>'  : 'RRTV3_PX4_OA/Controllers/Trajectory Cmd Generation/NAVIGATION/Integrator (Discrete or Continuous)1/Discrete'
//  '<S49>'  : 'RRTV3_PX4_OA/External Gains//Parameters/FCS Params'
//  '<S50>'  : 'RRTV3_PX4_OA/External Gains//Parameters/IPPM Params'
//  '<S51>'  : 'RRTV3_PX4_OA/External Gains//Parameters/NAV Parameters'
//  '<S52>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Nacelle'
//  '<S53>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Sensor Parameters'
//  '<S54>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Servo Mixing'
//  '<S55>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Subsystem'
//  '<S56>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Subsystem2'
//  '<S57>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Subsystem3'
//  '<S58>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Subsystem4'
//  '<S59>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Subsystem5'
//  '<S60>'  : 'RRTV3_PX4_OA/External Gains//Parameters/TCS Parameters'
//  '<S61>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Tuneable Parameters'
//  '<S62>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Tuneable Parameters/Acceleration Inceptor'
//  '<S63>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Tuneable Parameters/Altitude Hold'
//  '<S64>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Tuneable Parameters/Auto Flight'
//  '<S65>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Tuneable Parameters/Directional Inceptor'
//  '<S66>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Tuneable Parameters/Heading Hold'
//  '<S67>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Tuneable Parameters/Lateral Inceptor'
//  '<S68>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Tuneable Parameters/Longitudinal Inceptor'
//  '<S69>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Tuneable Parameters/Position Hold'
//  '<S70>'  : 'RRTV3_PX4_OA/External Gains//Parameters/Tuneable Parameters/Track Hold'
//  '<S71>'  : 'RRTV3_PX4_OA/PWM Mapping/AUX PWM Mapping'
//  '<S72>'  : 'RRTV3_PX4_OA/PWM Mapping/Control Surface Mixing'
//  '<S73>'  : 'RRTV3_PX4_OA/PWM Mapping/Main PWM Mapping'
//  '<S74>'  : 'RRTV3_PX4_OA/PWM Mapping/AUX PWM Mapping/MATLAB Function'
//  '<S75>'  : 'RRTV3_PX4_OA/Pilot Commands/1//[0.1s + 1], 0.01s2'
//  '<S76>'  : 'RRTV3_PX4_OA/Pilot Commands/Control Level Determination'
//  '<S77>'  : 'RRTV3_PX4_OA/Pilot Commands/Pilot Inceptor Blending'
//  '<S78>'  : 'RRTV3_PX4_OA/Pilot Commands/Transmitter Inputs (Cube Orange) - GCS'
//  '<S79>'  : 'RRTV3_PX4_OA/Pilot Commands/Transmitter Inputs (Cube Orange) - HereLink'
//  '<S80>'  : 'RRTV3_PX4_OA/Pilot Commands/Pilot Inceptor Blending/Pilot Inceptor Blending'
//  '<S81>'  : 'RRTV3_PX4_OA/Pilot Commands/Transmitter Inputs (Cube Orange) - GCS/PX4 uORB Read'
//  '<S82>'  : 'RRTV3_PX4_OA/Pilot Commands/Transmitter Inputs (Cube Orange) - GCS/PX4 uORB Read/Enabled Subsystem'
//  '<S83>'  : 'RRTV3_PX4_OA/Pilot Commands/Transmitter Inputs (Cube Orange) - HereLink/AP & Ext Inputs'
//  '<S84>'  : 'RRTV3_PX4_OA/Pilot Commands/Transmitter Inputs (Cube Orange) - HereLink/PX4 uORB Read'
//  '<S85>'  : 'RRTV3_PX4_OA/Pilot Commands/Transmitter Inputs (Cube Orange) - HereLink/PX4 uORB Read2'
//  '<S86>'  : 'RRTV3_PX4_OA/Pilot Commands/Transmitter Inputs (Cube Orange) - HereLink/AP & Ext Inputs/MATLAB Function'
//  '<S87>'  : 'RRTV3_PX4_OA/Pilot Commands/Transmitter Inputs (Cube Orange) - HereLink/PX4 uORB Read/Enabled Subsystem'
//  '<S88>'  : 'RRTV3_PX4_OA/Pilot Commands/Transmitter Inputs (Cube Orange) - HereLink/PX4 uORB Read2/Enabled Subsystem'
//  '<S89>'  : 'RRTV3_PX4_OA/Post-Processing/Integrator (Discrete or Continuous)'
//  '<S90>'  : 'RRTV3_PX4_OA/Post-Processing/PX4 uORB Message'
//  '<S91>'  : 'RRTV3_PX4_OA/Post-Processing/PX4 uORB Write'
//  '<S92>'  : 'RRTV3_PX4_OA/Post-Processing/Integrator (Discrete or Continuous)/Discrete'
//  '<S93>'  : 'RRTV3_PX4_OA/Sensor Outputs/Extract Sensor Feed'
//  '<S94>'  : 'RRTV3_PX4_OA/Sensor Outputs/Integrator (Discrete or Continuous)2'
//  '<S95>'  : 'RRTV3_PX4_OA/Sensor Outputs/LinVel Bus + INS'
//  '<S96>'  : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction'
//  '<S97>'  : 'RRTV3_PX4_OA/Sensor Outputs/Integrator (Discrete or Continuous)2/Discrete'
//  '<S98>'  : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/1//[0.1s + 1], 0.01s'
//  '<S99>'  : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/1//[0.1s + 1], 0.01s2'
//  '<S100>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/1//[0.25s + 1], 0.01s1'
//  '<S101>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Filtered Derivative1'
//  '<S102>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Filtered Derivative2'
//  '<S103>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/GPS1'
//  '<S104>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Ground Contact Sensor'
//  '<S105>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/PX4 uORB Read2'
//  '<S106>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/PX4 uORB Read3'
//  '<S107>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/vehicle_attitude'
//  '<S108>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/vehicle_attitude1'
//  '<S109>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/vehicle_attitude2'
//  '<S110>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/vehicle_local_pos'
//  '<S111>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Filtered Derivative1/Enable//disable time constant'
//  '<S112>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Filtered Derivative1/Initialization'
//  '<S113>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Filtered Derivative1/Integrator (Discrete or Continuous)'
//  '<S114>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Filtered Derivative1/Initialization/Init_u'
//  '<S115>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Filtered Derivative1/Integrator (Discrete or Continuous)/Discrete'
//  '<S116>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Filtered Derivative2/Enable//disable time constant'
//  '<S117>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Filtered Derivative2/Initialization'
//  '<S118>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Filtered Derivative2/Integrator (Discrete or Continuous)'
//  '<S119>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Filtered Derivative2/Initialization/Init_u'
//  '<S120>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/Filtered Derivative2/Integrator (Discrete or Continuous)/Discrete'
//  '<S121>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/GPS1/PX4 uORB Read'
//  '<S122>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/GPS1/PX4 uORB Read/Enabled Subsystem'
//  '<S123>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/PX4 uORB Read2/Enabled Subsystem'
//  '<S124>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/PX4 uORB Read3/Enabled Subsystem'
//  '<S125>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/vehicle_attitude/Enabled Subsystem'
//  '<S126>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/vehicle_attitude1/Enabled Subsystem'
//  '<S127>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/vehicle_attitude2/Enabled Subsystem'
//  '<S128>' : 'RRTV3_PX4_OA/Sensor Outputs/Sensor Construction/vehicle_local_pos/Enabled Subsystem'

#endif                                 // RRTV3_PX4_OA_h_

//
// File trailer for generated code.
//
// [EOF]
//
