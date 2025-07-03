
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#define SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "rtwtypes.h"
#undef SIMPLIFIED_RTWTYPES_COMPATIBILITY
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>

#include "mavlink_main.h"
#include "mavlink_messages.h"
#include "mavlink_command_sender.h"
#include "mavlink_simple_analyzer.h"

#include "streams/SCALED_PRESSURE2.hpp"

extern int16_t SM_ControlLevel;
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
extern "C" void ScaledPressure2_Outputs_wrapper(const int16_T *u0);

void ScaledPressure2_Outputs_wrapper(const int16_T *u0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
SM_ControlLevel = *u0;

#ifdef DirectlyEmittingMAVlinkMessages
    mavlink_scaled_pressure2_t msg;

    memset(&msg, 0, sizeof(msg));
    msg.time_boot_ms = hrt_absolute_time() / 1000;
    msg.temperature = *u0;
    mavlink_msg_scaled_pressure2_send_struct(MAVLINK_COMM_0, &msg);
    mavlink_msg_scaled_pressure2_send_struct(MAVLINK_COMM_1, &msg);
    mavlink_msg_scaled_pressure2_send_struct(MAVLINK_COMM_2, &msg);
    mavlink_msg_scaled_pressure2_send_struct(MAVLINK_COMM_3, &msg);
#endif /* DirectlyEmittingMAVlinkMessages */
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


