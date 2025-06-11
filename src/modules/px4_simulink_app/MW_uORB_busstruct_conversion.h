#ifndef _MW_UORB_BUSSTRUCT_CONVERSION_H_
#define _MW_UORB_BUSSTRUCT_CONVERSION_H_

#include <uORB/topics/airspeed.h>
#include <uORB/topics/debug_array.h>
#include <uORB/topics/debug_vect.h>
#include <uORB/topics/distance_sensor.h>
#include <uORB/topics/failsafe_flags.h>
#include <uORB/topics/rc_channels.h>
#include <uORB/topics/sensor_gps.h>
#include <uORB/topics/vehicle_acceleration.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_local_position.h>

typedef struct airspeed_s  px4_Bus_airspeed ;
typedef struct debug_array_s  px4_Bus_debug_array ;
typedef struct debug_vect_s  px4_Bus_debug_vect ;
typedef struct distance_sensor_s  px4_Bus_distance_sensor ;
typedef struct failsafe_flags_s  px4_Bus_failsafe_flags ;
typedef struct rc_channels_s  px4_Bus_rc_channels ;
typedef struct sensor_gps_s  px4_Bus_sensor_gps ;
typedef struct vehicle_acceleration_s  px4_Bus_vehicle_acceleration ;
typedef struct vehicle_angular_velocity_s  px4_Bus_vehicle_angular_velocity ;
typedef struct vehicle_attitude_s  px4_Bus_vehicle_attitude ;
typedef struct vehicle_local_position_s  px4_Bus_vehicle_local_position ;

#endif
