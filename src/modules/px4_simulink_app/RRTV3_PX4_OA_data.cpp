//
// File: RRTV3_PX4_OA_data.cpp
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

// Block parameters (default storage)
P_RRTV3_PX4_OA_T RRTV3_PX4_OA_P = {
  // Variable: PathDef1
  //  Referenced by: '<S42>/Constant'

  { 32.495106, 32.49133, 32.490386, 32.489442, 32.488498, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -85.779563,
    -85.774721, -85.77351, -85.7723, -85.771089, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 24.390243902439025,
    24.390243902439025, 24.390243902439025, 24.390243902439025,
    6.0975609756097562, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 45.0, 45.0, 20.0, 20.0, 9.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Variable: PathDef2
  //  Referenced by: '<S42>/Constant2'

  { 32.495106, 32.49133, 32.490386, 32.489442, 32.488498, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -85.779563,
    -85.774721, -85.77351, -85.7723, -85.771089, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 24.390243902439025,
    24.390243902439025, 24.390243902439025, 24.390243902439025,
    6.0975609756097562, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 50.0, 50.0, 20.0, 20.0, 9.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Variable: PathDef3
  //  Referenced by: '<S42>/Constant3'

  { 32.495106, 32.49133, 32.490386, 32.489442, 32.488498, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -85.779563,
    -85.774721, -85.77351, -85.7723, -85.771089, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 12.195121951219512,
    12.195121951219512, 12.195121951219512, 12.195121951219512,
    6.0975609756097562, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 50.0, 50.0, 20.0, 20.0, 9.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Variable: PathDef4
  //  Referenced by: '<S42>/Constant4'

  { 32.495106, 32.49133, 32.489442, 32.488498, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -85.779563, -85.774721,
    -85.7723, -85.771089, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 24.390243902439025, 24.390243902439025,
    24.390243902439025, 6.0975609756097562, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 60.0, 60.0, 20.0, 9.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.0, 4.0, 4.0, 4.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Variable: PathDef5
  //  Referenced by: '<S42>/Constant5'

  { 32.493218, 32.495106, 32.49605, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -85.777142, -85.779563, -85.780773,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 4.5731707317073171, 4.5731707317073171, 4.5731707317073171, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 15.0, 15.0, 9.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Variable: TPPWM_ext
  //  Referenced by:
  //    '<S73>/Tail Prop 1 (UP)'
  //    '<S73>/Tail Prop 2 (DOWN)'

  { 1000.0, 1050.0, 1100.0, 1150.0, 1200.0, 1250.0, 1300.0, 1350.0, 1400.0,
    1450.0, 1500.0, 1550.0, 1600.0, 1650.0, 1700.0, 1750.0, 1800.0, 1850.0,
    1900.0, 1950.0, 2000.0 },

  // Variable: TPRPM_ext
  //  Referenced by:
  //    '<S73>/Tail Prop 1 (UP)'
  //    '<S73>/Tail Prop 2 (DOWN)'

  { 0.0, 1968.0, 2287.0, 2856.0, 3512.0, 3949.0, 4101.0, 4439.0, 4729.0, 5214.0,
    5574.0, 5751.0, 6183.0, 6597.0, 6991.0, 7342.0, 7671.0, 7994.0, 8321.0,
    8635.0, 8790.0 },

  // Mask Parameter: FilteredDerivative2_A
  //  Referenced by: '<S102>/[A,B]'

  0.0,

  // Mask Parameter: FilteredDerivative1_A
  //  Referenced by: '<S101>/[A,B]'

  0.0,

  // Mask Parameter: FilteredDerivative2_B
  //  Referenced by: '<S102>/[A,B]'

  0.0,

  // Mask Parameter: FilteredDerivative1_B
  //  Referenced by: '<S101>/[A,B]'

  0.0,

  // Mask Parameter: u01s1001s2_ICPrevOutput
  //  Referenced by: '<S99>/UD'

  0.0,

  // Mask Parameter: u01s1001s_ICPrevOutput
  //  Referenced by: '<S98>/UD'

  0.0,

  // Mask Parameter: u01s1001s2_ICPrevOutput_g
  //  Referenced by: '<S75>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S16>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevScale
  //  Referenced by: '<S17>/UD'

  0.0,

  // Mask Parameter: FilteredDerivative2_K
  //  Referenced by: '<S102>/Gain'

  1.0,

  // Mask Parameter: FilteredDerivative1_K
  //  Referenced by: '<S101>/Gain'

  1.0,

  // Mask Parameter: u01s1001s2_PoleZ
  //  Referenced by: '<S99>/Gain'

  0.8187,

  // Mask Parameter: u01s1001s_PoleZ
  //  Referenced by: '<S98>/Gain'

  0.8187,

  // Mask Parameter: u01s1001s2_PoleZ_o
  //  Referenced by: '<S75>/Gain'

  0.9608,

  // Mask Parameter: FilteredDerivative2_T
  //  Referenced by: '<S116>/Time constant'

  0.1,

  // Mask Parameter: FilteredDerivative1_T
  //  Referenced by: '<S111>/Time constant'

  0.1,

  // Mask Parameter: FilteredDerivative2_minRatio
  //  Referenced by: '<S116>/Minimum sampling to time constant ratio'

  15.0,

  // Mask Parameter: FilteredDerivative1_minRatio
  //  Referenced by: '<S111>/Minimum sampling to time constant ratio'

  15.0,

  // Mask Parameter: u025s1001s1_ICPrevOutput
  //  Referenced by: '<S100>/UD'

  0.0F,

  // Mask Parameter: u025s1001s1_PoleZ
  //  Referenced by: '<S100>/Gain'

  0.9231F,

  // Computed Parameter: GCSOut_Y0
  //  Referenced by: '<S1>/GCS Out'

  {
    {
      0.0,                             // VV_Cmd
      0.0,                             // Acc_Cmd
      0.0,                             // V_Cmd
      0.0,                             // phiCmd
      0.0,                             // rCmd
      0.0,                             // DIR
      0.0,                             // HDGmem
      0.0,                             // TRKmem
      0.0,                             // POS
      0.0,                             // ALT
      0.0,                             // ALTmem
      0.0,                             // LongErr
      0.0,                             // LatErr
      0.0,                             // dlat
      0.0,                             // dver
      0.0,                             // ddir
      0.0                              // dacc
    },                                 // PII

    {
      0.0,                             // TWMP_Cmd
      0.0,                             // TWLP_Cmd
      0.0,                             // WingCmd
      0.0,                             // PitchCmd
      0.0,                             // TCS_Mode
      0.0,                             // TWH
      0.0                              // TWV
    },                                 // TCS

    {
      0.0,                             // ulat
      0.0,                             // ulon
      0.0                              // udir
    },                                 // EMF
    0.0,                               // AP

    {
      0.0,                             // LPRPM
      0.0                              // MPRPM
    },                                 // RPM

    {
      0.0,                             // LATSIG
      0.0,                             // LONGSIG
      0.0,                             // SPDSIG
      0.0,                             // WPINDEX
      0.0,                             // DistToTarget
      0.0,                             // TRK_target
      0.0,                             // FPA_target
      0.0,                             // Altpath
      0.0                              // NAVSTATUS
    },                                 // NAV

    {
      0.0,                             // LNAV
      0.0,                             // LNAV_NORM
      0.0,                             // VNAV
      0.0,                             // VNAV_NORM
      0.0,                             // SPD
      0.0                              // SPD_CUE
    }                                  // GUIDANCE
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S90>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // data
    0U,                                // id

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // name

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S128>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S110>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S88>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_valid

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // channels
    0U,                                // frame_drop_count
    0U,                                // channel_count

    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0 }
    ,                                  // function
    0U,                                // rssi
    false,                             // signal_lost

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S85>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_valid

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // channels
    0U,                                // frame_drop_count
    0U,                                // channel_count

    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0 }
    ,                                  // function
    0U,                                // rssi
    false,                             // signal_lost

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_m
  //  Referenced by: '<S122>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // time_utc_usec
    0U,                                // device_id
    0,                                 // lat
    0,                                 // lon
    0,                                 // alt
    0,                                 // alt_ellipsoid
    0.0F,                              // s_variance_m_s
    0.0F,                              // c_variance_rad
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // hdop
    0.0F,                              // vdop
    0,                                 // noise_per_ms
    0,                                 // jamming_indicator
    0.0F,                              // vel_m_s
    0.0F,                              // vel_n_m_s
    0.0F,                              // vel_e_m_s
    0.0F,                              // vel_d_m_s
    0.0F,                              // cog_rad
    0,                                 // timestamp_time_relative
    0.0F,                              // heading
    0.0F,                              // heading_offset
    0.0F,                              // heading_accuracy
    0.0F,                              // rtcm_injection_rate
    0U,                                // automatic_gain_control
    0U,                                // fix_type
    0U,                                // jamming_state
    0U,                                // spoofing_state
    false,                             // vel_ned_valid
    0U,                                // satellites_used
    0U,                                // selected_rtcm_instance

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S121>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // time_utc_usec
    0U,                                // device_id
    0,                                 // lat
    0,                                 // lon
    0,                                 // alt
    0,                                 // alt_ellipsoid
    0.0F,                              // s_variance_m_s
    0.0F,                              // c_variance_rad
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // hdop
    0.0F,                              // vdop
    0,                                 // noise_per_ms
    0,                                 // jamming_indicator
    0.0F,                              // vel_m_s
    0.0F,                              // vel_n_m_s
    0.0F,                              // vel_e_m_s
    0.0F,                              // vel_d_m_s
    0.0F,                              // cog_rad
    0,                                 // timestamp_time_relative
    0.0F,                              // heading
    0.0F,                              // heading_offset
    0.0F,                              // heading_accuracy
    0.0F,                              // rtcm_injection_rate
    0U,                                // automatic_gain_control
    0U,                                // fix_type
    0U,                                // jamming_state
    0U,                                // spoofing_state
    false,                             // vel_ned_valid
    0U,                                // satellites_used
    0U,                                // selected_rtcm_instance

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S82>/Out1'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // data
    0U,                                // id

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // name

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_nv
  //  Referenced by: '<S81>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // data
    0U,                                // id

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // name

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S87>/Out1'

  {
    (0ULL),                            // timestamp
    0U,                                // mode_req_angular_velocity
    0U,                                // mode_req_attitude
    0U,                                // mode_req_local_alt
    0U,                                // mode_req_local_position
    0U,                                // mode_req_local_position_relaxed
    0U,                                // mode_req_global_position
    0U,                                // mode_req_mission
    0U,                                // mode_req_offboard_signal
    0U,                                // mode_req_home_position
    0U,                             // mode_req_wind_and_flight_time_compliance
    0U,                                // mode_req_prevent_arming
    0U,                                // mode_req_manual_control
    0U,                                // mode_req_other
    false,                             // angular_velocity_invalid
    false,                             // attitude_invalid
    false,                             // local_altitude_invalid
    false,                             // local_position_invalid
    false,                             // local_position_invalid_relaxed
    false,                             // local_velocity_invalid
    false,                             // global_position_invalid
    false,                             // auto_mission_missing
    false,                             // offboard_control_signal_lost
    false,                             // home_position_invalid
    false,                             // manual_control_signal_lost
    false,                             // gcs_connection_lost
    0U,                                // battery_warning
    false,                             // battery_low_remaining_time
    false,                             // battery_unhealthy
    false,                             // primary_geofence_breached
    false,                             // mission_failure
    false,                             // vtol_fixed_wing_system_failure
    false,                             // wind_limit_exceeded
    false,                             // flight_time_limit_exceeded
    false,                             // local_position_accuracy_low
    false,                             // fd_critical_failure
    false,                             // fd_esc_arming_failure
    false,                             // fd_imbalanced_prop
    false,                             // fd_motor_failure

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S84>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // mode_req_angular_velocity
    0U,                                // mode_req_attitude
    0U,                                // mode_req_local_alt
    0U,                                // mode_req_local_position
    0U,                                // mode_req_local_position_relaxed
    0U,                                // mode_req_global_position
    0U,                                // mode_req_mission
    0U,                                // mode_req_offboard_signal
    0U,                                // mode_req_home_position
    0U,                             // mode_req_wind_and_flight_time_compliance
    0U,                                // mode_req_prevent_arming
    0U,                                // mode_req_manual_control
    0U,                                // mode_req_other
    false,                             // angular_velocity_invalid
    false,                             // attitude_invalid
    false,                             // local_altitude_invalid
    false,                             // local_position_invalid
    false,                             // local_position_invalid_relaxed
    false,                             // local_velocity_invalid
    false,                             // global_position_invalid
    false,                             // auto_mission_missing
    false,                             // offboard_control_signal_lost
    false,                             // home_position_invalid
    false,                             // manual_control_signal_lost
    false,                             // gcs_connection_lost
    0U,                                // battery_warning
    false,                             // battery_low_remaining_time
    false,                             // battery_unhealthy
    false,                             // primary_geofence_breached
    false,                             // mission_failure
    false,                             // vtol_fixed_wing_system_failure
    false,                             // wind_limit_exceeded
    false,                             // flight_time_limit_exceeded
    false,                             // local_position_accuracy_low
    false,                             // fd_critical_failure
    false,                             // fd_esc_arming_failure
    false,                             // fd_imbalanced_prop
    false,                             // fd_motor_failure

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_b
  //  Referenced by: '<S123>/Out1'

  {
    (0ULL),                            // timestamp
    0U,                                // device_id
    0.0F,                              // min_distance
    0.0F,                              // max_distance
    0.0F,                              // current_distance
    0.0F,                              // variance
    0.0F,                              // h_fov
    0.0F,                              // v_fov

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q
    0,                                 // signal_quality
    0U,                                // type
    0U,                                // orientation
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S105>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // device_id
    0.0F,                              // min_distance
    0.0F,                              // max_distance
    0.0F,                              // current_distance
    0.0F,                              // variance
    0.0F,                              // h_fov
    0.0F,                              // v_fov

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q
    0,                                 // signal_quality
    0U,                                // type
    0U,                                // orientation
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_fb
  //  Referenced by: '<S125>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S107>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_f4
  //  Referenced by: '<S124>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // xyz

    {
      0.0F, 0.0F, 0.0F }
    // xyz_derivative
  },

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S106>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // xyz

    {
      0.0F, 0.0F, 0.0F }
    // xyz_derivative
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S127>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Constant_Value_m5
  //  Referenced by: '<S109>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S126>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // xyz

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S108>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // xyz

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: ControlCmds_Y0
  //  Referenced by: '<S1>/Control Cmds'

  0.0,

  // Expression: zeros(7,1)
  //  Referenced by: '<S13>/Memory2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: Vehicle.Controllers.EMF.Longitudinal
  //  Referenced by: '<S27>/Constant2'

  { 3.0, 1.0, 0.22725886096140818, 4.790638341941249, 0.0, 0.0, 0.0, 0.0, 1.25,
    1.3163264841168436, 1.572340463142754, 3.0, 1.0, 0.22725886096140818,
    4.790638341941249, 0.0, 0.0, 0.0, 0.0, 1.25, 1.3163264841168436,
    1.572340463142754, 3.0, 1.0, 0.0, 5.3013719882491053, 0.1069060969003659,
    1.8672277772299575, 99.999963278268808, 1.0, 0.93286356321096275,
    2.0432255478953563, 1.9962211181779941, 3.0, 1.0, 0.0, 6.7987666598658691,
    0.19308294824926361, 3.3389686993680638, 99.999979236068143, 1.0,
    0.55727345244299875, 1.5961513938314535, 1.9999994105987793, 3.0, 1.0, 0.0,
    8.77630199879217, 0.23625027078431018, 5.0215675411351937,
    3.8167718250070468, 1.0, 0.58337568174523668, 2.5064398391265259,
    1.999999585025882, 3.0, 1.0, 0.0, 14.370226351367481, 0.32835512339649464,
    7.3526126616348915, 0.56020974216574582, 1.0, 0.37652190190116164,
    1.6349697682294591, 1.9999998519163324, 3.0, 1.0, 0.0, 15.903008636218342,
    0.3456096422696201, 9.20860118997338, 0.34055437146749623, 1.0,
    0.48415775673104577, 1.4920849526303006, 1.9999999973850602, 3.0, 1.0, 0.0,
    17.998015703372293, 0.35900462566847857, 10.881529554909346,
    0.25734592669148787, 1.0, 0.554696945326083, 1.3160320709416302,
    1.7140493092518372, 3.0, 1.0, 0.0, 17.998015703372293, 0.35900462566847857,
    10.881529554909346, 0.25734592669148787, 1.0, 0.554696945326083,
    1.3160320709416302, 1.7140493092518372 },

  // Expression: Vehicle.Controllers.EMF.Directional
  //  Referenced by: '<S27>/Constant4'

  { 3.0, 1.0, -0.65256472419543121, 3.3188485179220293, 0.0, 0.0, 0.0, 0.0,
    -0.0680110939489202, 0.5000336195957944, 0.33280527843101937, 3.0, 1.0,
    -0.65256472419543121, 3.3188485179220293, 0.0, 0.0, 0.0, 0.0,
    -0.0680110939489202, 0.5000336195957944, 0.33280527843101937, 3.0, 1.0, 0.0,
    1.6643685115116187, 0.089113700366585571, 1.4416957268336055,
    0.85374188503274362, 1.0, -0.25, 3.4999999992624673, 2.9490110119376323, 3.0,
    1.0, 0.0, 1.034868739134575, 0.26507428766307728, 2.7249887930955254,
    3.6501620126015708, 1.0, -0.25, 2.9999999930350882, 1.7339999531526986, 3.0,
    1.0, 0.0, 2.4348706220877632, 0.28936580449480553, 4.0020831030095234,
    2.2727269873123479, 1.0, -0.25, 1.0682222918093638, 0.39206356334741188, 3.0,
    1.0, 0.0, 4.3991570558555795, 0.2816400185687048, 5.1893008252517179,
    1.496399522010355, 1.0, -0.25, 0.97202381493471446, 0.42678372171156631, 3.0,
    1.0, 0.0, 6.9532682071285095, 0.26727269105430407, 6.6691332042452274,
    1.3839382369060433, 1.0, -0.25, 0.29476871488894163, 0.20117634749257585,
    3.0, 1.0, 0.0, 9.9698853519314454, 0.26259239179643246, 8.0377631276309867,
    1.2079530217178025, 1.0, -0.1948670687345512, 0.33727306106127386,
    0.20002147465729139, 3.0, 1.0, 0.0, 9.9698853519314454, 0.26259239179643246,
    8.0377631276309867, 1.2079530217178025, 1.0, -0.1948670687345512,
    0.33727306106127386, 0.20002147465729139 },

  // Expression: Vehicle.Controllers.TCS.Gains
  //  Referenced by: '<S27>/Constant3'

  { 0.81983641326554935, 0.3998473756669676, 0.43333274971194136,
    0.52614830621870412, 0.0, 0.0, 0.0, 0.48848911308667231, 0.83695053096003824,
    1.0068979621900815, 0.81983641326554935, 0.3998473756669676,
    0.43333274971194136, 0.52614830621870412, 0.0, 0.0, 0.0, 0.48848911308667231,
    0.83695053096003824, 1.0068979621900815, 0.4439881081836069,
    0.10000786857469729, 0.32010261339543145, 0.30769596968702284,
    0.65136574443790152, 164.35496868775624, 43.094174358679581,
    0.44547710108983962, 0.60059831689539944, 0.92582341023410719,
    0.72052333002858515, 0.1001046203752346, 0.21046208095980767,
    0.19281754999037781, 0.65136574443790152, 20.54437108596953,
    10.773543589669895, 0.34984499678839659, 0.50006198883056641,
    1.066829332278453, 0.78064734392936352, 0.20015389896167685,
    0.41155235388660827, 0.27072614833749709, 0.54942690171777842,
    6.0872210625094922, 4.7882415954088424, 0.47167822801340442,
    0.31182775433381271, 0.98381173936412047, 1.0027562216112873,
    0.20001357618606372, 0.49987414809986341, 0.31729302028377737,
    0.19803892608255735, 2.5680463857461913, 2.6933858974174738,
    0.37659688530177549, 0.39999999474841125, 0.19530951594596602,
    1.0974730927929082, 0.2000000082831706, 0.51199207697001747,
    0.24065935610251926, 0.10116675657734929, 1.31483974950205,
    1.7237669743471828, 0.34748864707228189, 0.39999998999843583,
    0.18574406089970544, 1.1042092716821419, 0.20000983105446646,
    0.61376046801972284, 0.20002348220927629, 0.066589812305385063,
    0.76090263281368653, 1.1970603988522106, 0.31865228909462634,
    0.39999999444591094, 0.22105634649034511, 1.1042092716821419,
    0.20000983105446646, 0.61376046801972284, 0.20002348220927629,
    0.066589812305385063, 0.76090263281368653, 1.1970603988522106,
    0.31865228909462634, 0.39999999444591094, 0.22105634649034511 },

  // Expression: Vehicle.Controllers.EMF.Lateral
  //  Referenced by: '<S27>/Constant1'

  { 3.0, 1.0, -0.10036515414961351, 12.743839054698773, -0.010859509185310244,
    0.388722645397249, 0.60940433213804535, 0.93749518348650474, 3.0, 1.0,
    -0.10036515414961351, 12.743839054698773, -0.010859509185310244,
    0.388722645397249, 0.60940433213804535, 0.93749518348650474, 3.0, 1.0,
    -0.47490020834396646, 10.129391311008224, 0.40530836072059134,
    0.49999998662763717, 1.1486340827532571, 1.9999999875196008, 3.0, 1.0,
    -1.0860860264475591, 9.1403990452184729, 0.031422723420855239,
    0.31533962365468937, 0.419258075202086, 0.10011090510986409, 3.0, 1.0,
    -1.4815787257109936, 12.040546804784711, 0.053260869225515185,
    0.24791345108559604, 0.30003827075700396, 0.17505894152850998, 3.0, 1.0,
    -2.4452565873265151, 29.783340676963498, 0.037037447206520489,
    0.2026242740067522, 1.0911657398332224, 0.5010991580983577, 3.0, 1.0,
    -3.4670375045293591, 45.890254999374015, 0.038196010182912278,
    0.33979616165161131, 0.5, 0.5, 3.0, 1.0, -4.33261617680736, 65.7008285540706,
    0.038531262740187422, 0.26048543914087563, 0.50000956725010282,
    0.500016814105992, 3.0, 1.0, -4.33261617680736, 65.7008285540706,
    0.038531262740187422, 0.26048543914087563, 0.50000956725010282,
    0.500016814105992 },

  // Expression: 400
  //  Referenced by: '<S9>/[-40,+400]'

  400.0,

  // Expression: -40
  //  Referenced by: '<S9>/[-40,+400]'

  -40.0,

  // Expression: Vehicle.Controllers.KEASRef
  //  Referenced by: '<S9>/Constant'

  { -100.0, 0.01, 10.0, 20.0, 30.0, 40.0, 50.0, 160.0 },

  // Expression: Vehicle.Controllers.LATCS
  //  Referenced by: '<S27>/Constant5'

  { 0.09763144142586859, 0.699999996519546, 0.0, 0.0, 0.09763144142586859,
    0.699999996519546, 0.0, 0.0, 0.05, 0.62753294111972668, 1.1717184278577073,
    0.428132886540571, 0.05, 0.60770304238050021, 3.4049606257121288,
    2.1553099937890829, 0.05, 0.6215498492233813, 3.4999999923440366, 3.5, 0.05,
    0.69999993970374286, 3.4999999743706427, 3.5, 0.05, 0.69999997010964266,
    4.99999994676385, 3.5, 0.05, 0.69999876226421043, 4.9999999679513243, 3.5,
    0.05, 0.69999876226421043, 4.9999999679513243, 3.5 },

  // Expression: Vehicle.Controls.TurnComp
  //  Referenced by: '<S27>/Constant6'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.12516386158617968, 0.090111177215578181,
    0.0653595074450572, 0.0653595074450572 },

  // Expression: Vehicle.Controllers.TCS.Params
  //  Referenced by: '<S27>/Constant20'

  { 3.0, 6.0, 25.0, 35.0, 0.1, 1.1, 1.9, 2.0, 1.7, 0.9, 0.1, 0.8, 0.2, 0.5, 15.0,
    3.0, 1.0, 0.1, 5.0, 15.0, -15.0, 3.0, 1.0, 0.15, 40.0, 5.0, 10.0, 85.0, 5.0,
    -0.35, 0.2, 0.1, 0.35, 4.0, 4.0 },

  // Expression: Vehicle.Controllers.WingParams
  //  Referenced by: '<S27>/Constant22'

  { 90.0, 0.0, 10.0, -10.0 },

  // Expression: Vehicle.Controllers.PIIParameters
  //  Referenced by: '<S27>/Constant21'

  { 2.0, 0.1, 0.03, 10.0, 20.0, 45.0, 45.0, 0.2, 0.3, 2.0, 0.0, 5.0, 10.0, 1.0,
    0.05, 0.03, 1500.0, 40.0, 10.0, -1.0, 3.8, 60.0, 70.0, 0.1, 0.03, 40.0, 10.0,
    1.0, 0.1, 0.1, 0.03, 0.2, 8.0, 10.0, 0.03, 1.0, 10.0, 0.01, 1.0, 100.0,
    200.0, 1.0, 1.0, 0.1, 3.0, 0.0, 12.0, 1.0, 1.0, 0.5, 0.1, 12.0, 1.0, 1.0,
    0.1, 5.0, 1.0, 0.001, 5.0, 5.0, 1.0, 10.0, 150.0, 100.0, 30.0, 10.0, 70.0 },

  // Expression: [0,0,0,0]
  //  Referenced by: '<S42>/Constant1'

  { 0.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S48>/Integrator'

  0.02,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S48>/Integrator'

  50.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S48>/Integrator'

  -50.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S48>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S48>/Saturation'

  0.0,

  // Expression: [0,0,0]
  //  Referenced by: '<S42>/Memory2'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S13>/Constant2'

  0.0,

  // Computed Parameter: Integrator_gainval_o
  //  Referenced by: '<S44>/Integrator'

  0.02,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S44>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S44>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S44>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S44>/Saturation'

  0.0,

  // Expression: [0;0;0;0;0;0;TP.KEAS;0;0;0]
  //  Referenced by: '<S13>/Constant'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0 },

  // Computed Parameter: Integrator_gainval_j
  //  Referenced by: '<S43>/Integrator'

  0.02,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S43>/Integrator'

  100.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S43>/Integrator'

  -100.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S43>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S43>/Saturation'

  0.0,

  // Expression: zeros(22,1)
  //  Referenced by: '<S13>/Memory1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0;Init.HDG;0;0;0;0;1;Init.AltMSL_ft-97*3.28]
  //  Referenced by: '<S13>/Memory'

  { 0.0, 135.0, 0.0, 0.0, 0.0, 0.0, 1.0, -1.1599999999999682 },

  // Expression: 1
  //  Referenced by: '<S8>/Gain'

  1.0,

  // Expression: 0
  //  Referenced by: '<S8>/Memory7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S8>/Delay2'

  0.0,

  // Expression: [0,0,TP.ULAT]
  //  Referenced by: '<S8>/Constant'

  { 0.0, 0.0, 0.0057565714439471016 },

  // Computed Parameter: Integrator_gainval_g
  //  Referenced by: '<S24>/Integrator'

  0.02,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S24>/Integrator'

  10.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S24>/Integrator'

  -10.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S24>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S24>/Saturation'

  0.0,

  // Expression: zeros(5,1)
  //  Referenced by: '<S12>/Constant'

  { 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S12>/Memory1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S12>/Constant2'

  0.0,

  // Computed Parameter: Integrator_gainval_c
  //  Referenced by: '<S36>/Integrator'

  0.02,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S36>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S36>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S36>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S36>/Saturation'

  0.0,

  // Expression: [TP.TWH; TP.TWV; TP.AOA; TP.TW; TP.dW]
  //  Referenced by: '<S12>/Constant1'

  { 0.0, 0.1, 0.0, 0.1, 89.233839533247888 },

  // Computed Parameter: Integrator_gainval_f
  //  Referenced by: '<S35>/Integrator'

  0.02,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S35>/Integrator'

  { 2.0, 2.0, 30.0, 2.0, 90.0 },

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S35>/Integrator'

  { -0.3, 0.01, -30.0, 0.01, 0.0 },

  // Expression: windupUpperLimit
  //  Referenced by: '<S35>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S35>/Saturation'

  0.0,

  // Expression: [Init.Mode,1]
  //  Referenced by: '<S12>/Memory'

  { 1.0, 1.0 },

  // Expression: 1
  //  Referenced by: '<S8>/Gain2'

  1.0,

  // Expression: 0
  //  Referenced by: '<S8>/Delay1'

  0.0,

  // Expression: [0,TP.AOA*pi/180,0,0]
  //  Referenced by: '<S8>/Constant3'

  { 0.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: Integrator_gainval_l
  //  Referenced by: '<S26>/Integrator'

  0.02,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S26>/Integrator'

  20.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S26>/Integrator'

  -20.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S26>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S26>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S8>/Memory3'

  0.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S16>/TSamp'

  50.0,

  // Expression: 0
  //  Referenced by: '<S8>/Memory1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S8>/Gain1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S8>/Delay'

  0.0,

  // Expression: [0;0;TP.UDIR;0]
  //  Referenced by: '<S8>/Constant2'

  { 0.0, 0.0, -0.0028841365858740635, 0.0 },

  // Computed Parameter: Integrator_gainval_k
  //  Referenced by: '<S25>/Integrator'

  0.02,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S25>/Integrator'

  10.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S25>/Integrator'

  -10.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S25>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S25>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S8>/Memory6'

  0.0,

  // Computed Parameter: TSamp_WtEt_b
  //  Referenced by: '<S17>/TSamp'

  50.0,

  // Expression: 2
  //  Referenced by: '<S11>/Constant3'

  2.0,

  // Expression: 9.81
  //  Referenced by: '<S11>/Gain2'

  9.81,

  // Expression: 1
  //  Referenced by: '<S11>/Gain1'

  1.0,

  // Expression: 0.51444
  //  Referenced by: '<S11>/Gain'

  0.51444,

  // Expression: 8500
  //  Referenced by: '<S11>/ RPM LIMITER'

  8500.0,

  // Expression: 0
  //  Referenced by: '<S11>/ RPM LIMITER'

  0.0,

  // Expression: 100
  //  Referenced by: '<S7>/Gain'

  100.0,

  // Expression: 1
  //  Referenced by: '<S15>/GEAR IS FIXED ON 1//5 SCALE'

  1.0,

  // Expression: 0
  //  Referenced by: '<S11>/Constant'

  0.0,

  // Expression: 1
  //  Referenced by: '<S13>/Constant1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S49>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S49>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S49>/Max Phi Cmd8'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S50>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S50>/Max Phi Cmd12'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S50>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S50>/Max Phi Cmd5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S50>/Max Phi Cmd8'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S50>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S2>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S2>/Max Phi Cmd8'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S51>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S51>/Max Phi Cmd12'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S51>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S51>/Max Phi Cmd5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S51>/Max Phi Cmd8'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S51>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S52>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S52>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S52>/Max Phi Cmd5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S53>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S53>/Max Phi Cmd12'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S53>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S53>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S53>/Max Phi Cmd4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S53>/Max Phi Cmd5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S53>/Max Phi Cmd6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S53>/Max Phi Cmd7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S53>/Max Phi Cmd8'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S53>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 10'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 11'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 12'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 13'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 14'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 15'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 16'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 17'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 18'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 8'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/AUX 9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S55>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S55>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S55>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S55>/Max Phi Cmd5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S55>/Max Phi Cmd8'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S55>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S56>/Max Phi Cmd10'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S56>/Max Phi Cmd11'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S56>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S56>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S56>/Max Phi Cmd8'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S57>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S57>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S57>/Max Phi Cmd4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S57>/Max Phi Cmd5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S57>/Max Phi Cmd6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S57>/Max Phi Cmd7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S58>/Max Phi Cmd10'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S58>/Max Phi Cmd11'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S58>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S58>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S58>/Max Phi Cmd8'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S59>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S59>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S59>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd10'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd11'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd12'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd13'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd14'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd15'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd16'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd17'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd18'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd19'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd20'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd21'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd22'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd23'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd24'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd25'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd26'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd27'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd28'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd29'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd30'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd31'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd8'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S60>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S62>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S62>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S62>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S62>/Max Phi Cmd5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S62>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S63>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S63>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S63>/Max Phi Cmd4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S63>/Max Phi Cmd5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S63>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S64>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S64>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S64>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S64>/Max Phi Cmd4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S64>/Max Phi Cmd5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S64>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S65>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S65>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S65>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S66>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S66>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S66>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S66>/Max Phi Cmd4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S66>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S67>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S67>/Max Phi Cmd10'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S67>/Max Phi Cmd11'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S67>/Max Phi Cmd12'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S67>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S67>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S67>/Max Phi Cmd4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S67>/Max Phi Cmd7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S67>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S68>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S68>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S68>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S69>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S69>/Max Phi Cmd10'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S69>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S69>/Max Phi Cmd3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S69>/Max Phi Cmd4'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S69>/Max Phi Cmd5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S69>/Max Phi Cmd6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S69>/Max Phi Cmd7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S69>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S70>/Max Phi Cmd1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S70>/Max Phi Cmd2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S70>/Max Phi Cmd5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S70>/Max Phi Cmd9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S4>/Read Parameter1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S4>/Read Parameter6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S83>/Read Parameter5'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S83>/Read Parameter6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S83>/Read Parameter7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S79>/Read Parameter6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S96>/Read Parameter1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain6'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain17'

  1.0,

  // Expression: 0
  //  Referenced by: '<S102>/Constant'

  0.0,

  // Computed Parameter: Integrator_gainval_jr
  //  Referenced by: '<S120>/Integrator'

  0.02,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S120>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S120>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S120>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S120>/Saturation'

  0.0,

  // Expression: 1e-7
  //  Referenced by: '<S96>/Gain1'

  1.0E-7,

  // Expression: 1e-7
  //  Referenced by: '<S96>/1e-7'

  1.0E-7,

  // Expression: 0
  //  Referenced by: '<S101>/Constant'

  0.0,

  // Computed Parameter: Integrator_gainval_e
  //  Referenced by: '<S115>/Integrator'

  0.02,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S115>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S115>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S115>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S115>/Saturation'

  0.0,

  // Expression: 3
  //  Referenced by: '<S96>/Saturation2'

  3.0,

  // Expression: -3
  //  Referenced by: '<S96>/Saturation2'

  -3.0,

  // Expression: 0
  //  Referenced by: '<S6>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S6>/Constant2'

  0.0,

  // Computed Parameter: Integrator_gainval_h
  //  Referenced by: '<S97>/Integrator'

  0.02,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S97>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S97>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S97>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S97>/Saturation'

  0.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain7'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain9'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain8'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain13'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain10'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain16'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain18'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain19'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain22'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain15'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain2'

  1.0,

  // Expression: -1
  //  Referenced by: '<S79>/Gain3'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain4'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain5'

  1.0,

  // Expression: 1
  //  Referenced by: '<S83>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S83>/Saturation'

  0.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain11'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain10'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain9'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain7'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain8'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain13'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain12'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain16'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain14'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain15'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain'

  1.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S79>/Constant2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain19'

  1.0,

  // Expression: 0
  //  Referenced by: '<S79>/Constant3'

  0.0,

  // Expression: 1
  //  Referenced by: '<S79>/Gain18'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain2'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain3'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain5'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain4'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain11'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain10'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain9'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain7'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain8'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain13'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain12'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain16'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain14'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain15'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain1'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain6'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain17'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain18'

  1.0,

  // Expression: 1
  //  Referenced by: '<S78>/Gain19'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain2'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain3'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain5'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain4'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain11'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain10'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain9'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain7'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain8'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain13'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain12'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain16'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain14'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain15'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain1'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain6'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain17'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain19'

  1.0,

  // Expression: 1
  //  Referenced by: '<S77>/Gain18'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain1'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain2'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain3'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain4'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain5'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/Gain11'

  1.0,

  // Expression: 0
  //  Referenced by: '<S55>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S55>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S55>/Constant2'

  0.0,

  // Expression: 0.67
  //  Referenced by: '<S55>/Constant4'

  0.67,

  // Expression: 3
  //  Referenced by: '<S57>/Constant'

  3.0,

  // Expression: 1
  //  Referenced by: '<S57>/Constant1'

  1.0,

  // Expression: 3
  //  Referenced by: '<S56>/Constant'

  3.0,

  // Expression: 1
  //  Referenced by: '<S56>/Constant1'

  1.0,

  // Expression: 0.3
  //  Referenced by: '<S56>/Constant2'

  0.3,

  // Expression: 3
  //  Referenced by: '<S56>/Constant3'

  3.0,

  // Expression: 10
  //  Referenced by: '<S56>/Constant4'

  10.0,

  // Expression: 0
  //  Referenced by: '<S56>/Constant5'

  0.0,

  // Expression: 3
  //  Referenced by: '<S58>/Constant'

  3.0,

  // Expression: 1
  //  Referenced by: '<S58>/Constant1'

  1.0,

  // Expression: 0.3
  //  Referenced by: '<S58>/Constant2'

  0.3,

  // Expression: 3
  //  Referenced by: '<S58>/Constant3'

  3.0,

  // Expression: 10
  //  Referenced by: '<S58>/Constant4'

  10.0,

  // Expression: 0
  //  Referenced by: '<S58>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S59>/Constant'

  0.0,

  // Expression: 10
  //  Referenced by: '<S67>/Constant3'

  10.0,

  // Expression: 0.1
  //  Referenced by: '<S67>/Constant2'

  0.1,

  // Expression: 0.1
  //  Referenced by: '<S67>/Constant1'

  0.1,

  // Expression: 0.08
  //  Referenced by: '<S67>/Constant'

  0.08,

  // Expression: 1
  //  Referenced by: '<S68>/Constant3'

  1.0,

  // Expression: 20
  //  Referenced by: '<S68>/Constant6'

  20.0,

  // Expression: 20
  //  Referenced by: '<S68>/Constant2'

  20.0,

  // Expression: -1
  //  Referenced by: '<S68>/Constant'

  -1.0,

  // Expression: 3
  //  Referenced by: '<S68>/Constant1'

  3.0,

  // Expression: 100
  //  Referenced by: '<S68>/Constant4'

  100.0,

  // Expression: 110
  //  Referenced by: '<S68>/Constant5'

  110.0,

  // Expression: 0
  //  Referenced by: '<S65>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S65>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S65>/Constant2'

  0.0,

  // Expression: 0.15
  //  Referenced by: '<S62>/Constant1'

  0.15,

  // Expression: 0.2
  //  Referenced by: '<S63>/Constant1'

  0.2,

  // Expression: 0.4
  //  Referenced by: '<S66>/Constant1'

  0.4,

  // Expression: 1
  //  Referenced by: '<S70>/Constant1'

  1.0,

  // Expression: 0.2
  //  Referenced by: '<S60>/Constant12'

  0.2,

  // Expression: 0.5
  //  Referenced by: '<S60>/Constant13'

  0.5,

  // Expression: 15
  //  Referenced by: '<S60>/Constant14'

  15.0,

  // Expression: 1
  //  Referenced by: '<S60>/Constant20'

  1.0,

  // Expression: 90
  //  Referenced by: '<S52>/Constant4'

  90.0,

  // Expression: 1
  //  Referenced by: '<S79>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S79>/Saturation'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S2>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S5>/Constant2'

  0.0,

  // Computed Parameter: Integrator_gainval_n
  //  Referenced by: '<S92>/Integrator'

  0.02,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S92>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S92>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S92>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S92>/Saturation'

  0.0,

  // Expression: 1
  //  Referenced by: '<S3>/[0,1]'

  1.0,

  // Expression: 0
  //  Referenced by: '<S3>/[0,1]'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S3>/Gain'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S3>/Constant'

  1000.0,

  // Expression: 1
  //  Referenced by: '<S73>/Constant'

  1.0,

  // Expression: MPPWM_ext(2:end)
  //  Referenced by: '<S73>/Main Prop 1'

  { 1050.0, 1100.0, 1150.0, 1200.0, 1250.0, 1300.0, 1350.0, 1400.0, 1450.0,
    1500.0, 1550.0, 1600.0, 1650.0, 1700.0, 1750.0, 1800.0, 1850.0, 1900.0,
    1950.0, 2000.0 },

  // Expression: MPRPM_ext(2:end)
  //  Referenced by: '<S73>/Main Prop 1'

  { 0.0, 1195.0, 1723.0, 2217.0, 2695.0, 3126.0, 3530.0, 3892.0, 4193.0, 4367.0,
    4541.0, 4715.0, 4889.0, 5063.0, 5237.0, 5411.0, 5585.0, 5759.0, 5933.0,
    6107.0 },

  // Expression: MPPWM_ext(2:end)
  //  Referenced by: '<S73>/Main Prop 2'

  { 1050.0, 1100.0, 1150.0, 1200.0, 1250.0, 1300.0, 1350.0, 1400.0, 1450.0,
    1500.0, 1550.0, 1600.0, 1650.0, 1700.0, 1750.0, 1800.0, 1850.0, 1900.0,
    1950.0, 2000.0 },

  // Expression: MPRPM_ext(2:end)
  //  Referenced by: '<S73>/Main Prop 2'

  { 0.0, 1195.0, 1723.0, 2217.0, 2695.0, 3126.0, 3530.0, 3892.0, 4193.0, 4367.0,
    4541.0, 4715.0, 4889.0, 5063.0, 5237.0, 5411.0, 5585.0, 5759.0, 5933.0,
    6107.0 },

  // Expression: 2000
  //  Referenced by: '<S73>/[1000,2000]'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S73>/[1000,2000]'

  1000.0,

  // Expression: 2000
  //  Referenced by: '<S73>/[1000 2000]'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S73>/[1000 2000]'

  1000.0,

  // Expression: 2000
  //  Referenced by: '<S73>/[1000,2000]1'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S73>/[1000,2000]1'

  1000.0,

  // Expression: 2000
  //  Referenced by: '<S73>/[1000 2000]1'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S73>/[1000 2000]1'

  1000.0
};

//
// File trailer for generated code.
//
// [EOF]
//
