/****************************************************************************
 *
 *   Copyright (c) 2019 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/console_buffer.h>
#include <px4_platform_common/module.h>
#include <px4_platform_common/getopt.h>

#include <poll.h>

#include <uORB/topics/uORBTopics.hpp>
#include <uORB/topics/vehicle_global_position.h>
#include <uORB/topics/sensor_gps.h>

extern "C" {
	__EXPORT int wp_main(int argc, char *argv[]);
}


int wp_main(int argc, char *argv[])
{
    int instances, i;
    orb_id_t id1 = ORB_ID(vehicle_global_position);
    orb_id_t id2 = ORB_ID(sensor_gps);

    printf("Called wp_main\n");
    instances = 0;
    for (i = 0; i < ORB_MULTI_MAX_INSTANCES; i++) {
        if (orb_exists(id1, i) == PX4_OK)
            instances++;
    }
    if (instances == 1) {
        vehicle_global_position_s vgp;
        int sub = orb_subscribe(id1);

        if (sub == PX4_ERROR) {
            printf("Cannot vgp subscribe(%d).\n", errno);
        } else {
            int ret;
            struct pollfd fds;

            fds.fd = sub;
            fds.events = POLLIN;
            printf("start vgp poll..."); fflush(stdout);
            /* 1 fd, 10 second timeout */
            ret = poll(&fds, 1, 10 * 1000);
            printf("finish (%d)\n", ret);
            if (ret > 0) {
                ret = orb_copy(id1, sub, &vgp);
                if (ret == PX4_OK)
                    printf("lat/lon %.7f/%.7f\n", vgp.lat, vgp.lon);
                else
                    printf("Can't do anything...could not copy GPS data\n");
            } else
                printf("poll shows no data arriving\n");
            orb_unsubscribe(sub);
        }
    } else
        printf("Can't do anything; no vgp GPS position instance found!\n");
    
    instances = 0;
    for (i = 0; i < ORB_MULTI_MAX_INSTANCES; i++) {
        if (orb_exists(id2, i) == PX4_OK)
            instances++;
    }
    if (instances == 1) {
        sensor_gps_s sg;
        int sub = orb_subscribe(id2);

        if (sub == PX4_ERROR) {
            printf("Cannot sg subscribe(%d).\n", errno);
        } else {
            int ret;
            struct pollfd fds;

            fds.fd = sub;
            fds.events = POLLIN;
            printf("start sg poll..."); fflush(stdout);
            /* 1 fd, 10 second timeout */
            ret = poll(&fds, 1, 10 * 1000);
            printf("finish (%d)\n", ret);
            if (ret > 0) {
                ret = orb_copy(id2, sub, &sg);
                if (ret == PX4_OK)
                    printf("lat/lon %ld/%ld\n", sg.lat, sg.lon);
                else
                    printf("Can't do anything...could not copy GPS data\n");
            } else
                printf("poll shows no data arriving\n");
            orb_unsubscribe(sub);
        }
    } else
        printf("Can't do anything; no sg GPS position instance found!\n");
    
    return 1;
}

#if 0
    Gonna use GPS_RAW_INT messages to know lat/lon

    // do the dance infintely
    for (;;)
    {
        float m, d, d_x, d_y, d_lo, d_la, r_earth;
        int timesThru;
        int s;
        long ns;

        // Following code for converting speed/heading into lat/lon changes is derived from
        // https://stackoverflow.com/questions/7477003/calculating-new-longitude-latitude-from-old-n-meters
        //
        // Note that speed is in km/h
        // The framerate is spec'd by its inverse; maybe we should smooth this value out rather than
        // using its instantaneous value?
        d = (speed * 1000 / 3600) * *frameperiod_p;

        // Given that distance, use the heading to determine the X- and y-axis components in meters
        d_x = d * fabs(cos(heading * M_PI / 180));
        d_y = d * fabs(sin(heading * M_PI / 180));

        // OK. Now that we have x and y distances in meters, let's turn those distances into deltas
        // of longitude and latitude...
        r_earth = 6378 * 1000;  // radius of earth in meters
        // the "delta latitude" value is the # of meters we want to move times the number of latitudinal degrees per meter
        m = 1 / ((2.0 * M_PI / 360) * r_earth);
        d_la = d_x * m;

        disturbLLEByNum(&la, &lo, &el, 0);
        el += AGL;
        timesThru = 200;
        clock0(0);
        for (j = 0; j < timesThru; j++)
        {
            d_lo = (d_y * m) / cos(la * M_PI/180);
            lo += d_lo;
            la += d_la;
            // The following applies to aircraft #1
            xpnVehiclePropsAndNum(la, lo, el, heading, 0.0, 0.0, 1); myprintf(xpnStatusBuf());
            mebbePause();
        }
        clock1(0, &s, &ns);
        myprintf("thru the loop in %d.%09d\n", s, ns);
    }
#endif
