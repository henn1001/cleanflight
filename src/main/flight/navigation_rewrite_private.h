/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "flight/pid.h"
#include "sensors/barometer.h"
#include "io/rc_controls.h"
#include "io/escservo.h"

// Undefine this to use CF's native magHold PID and MAG mode to control heading, if defined, NAV will control YAW by itself
#define NAV_HEADING_CONTROL_PID

#define DISTANCE_BETWEEN_TWO_LONGITUDE_POINTS_AT_EQUATOR 1.113195f  // MagicEarthNumber from APM

#define LANDING_DETECTION_TIMEOUT       10000000     // 10 second timeout
#define RADX10                          0.00174532925f
#define RADX100                         0.000174532925f
#define CROSSTRACK_GAIN                 1
#define NAV_ROLL_PITCH_MAX              300 // Max control input from NAV
#define NAV_THROTTLE_CORRECTION_ANGLE   450

//Update rate for position target update (minumum possible speed in cms will be this value)
#define POSITION_TARGET_UPDATE_RATE_HZ  5

// max 35hz update rate (almost maximum possible rate for BMP085)
#define MAX_ALTITUDE_UPDATE_FREQUENCY_HZ    35
#define MIN_ALTITUDE_UPDATE_FREQUENCY_HZ    15      // althold will not be applied if update rate is less than this constant
#define MIN_POSITION_UPDATE_FREQUENCY_HZ    2       // GPS navigation (PH/WP/RTH) won't be applied unless update rate is above this

#define NAV_VEL_ERROR_CUTOFF_FREQENCY_HZ    4       // low-pass filter on Z-velocity error
#define NAV_THROTTLE_CUTOFF_FREQENCY_HZ     2       // low-pass filter on throttle output
#define NAV_ACCEL_ERROR_CUTOFF_FREQUENCY_HZ 2       // low-pass filter on XY-acceleration error

#define NAV_ACCELERATION_XY_MAX             980.0f  // cm/s/s

// Should apply position-to-velocity PID controller for POS_HOLD
#define navShouldApplyPosHold() ((navMode & (NAV_MODE_POSHOLD_2D | NAV_MODE_POSHOLD_3D)) != 0)
// Should apply position-to-velocity PID controller for waypoint navigation (WP/RTH)
#define navShouldApplyWaypoint() ((navMode & (NAV_MODE_WP | NAV_MODE_RTH)) != 0)
// Should apply altitude PID controller
#define navShouldApplyAltHold() ((navMode & (NAV_MODE_ALTHOLD | NAV_MODE_POSHOLD_3D | NAV_MODE_WP | NAV_MODE_RTH)) != 0)
// Should apply RTH-specific logic
#define navShouldApplyRTHLogic() ((navMode & NAV_MODE_RTH) != 0)

// 
#define navShouldApplyHeadingControl() ((navMode & (NAV_MODE_WP | NAV_MODE_RTH | NAV_MODE_POSHOLD_2D | NAV_MODE_POSHOLD_3D)) != 0)
#define navShouldAdjustHeading() ((navMode & (NAV_MODE_WP | NAV_MODE_RTH)) != 0)

#define navCanAdjustAltitudeFromRCInput() (((navMode & (NAV_MODE_ALTHOLD | NAV_MODE_POSHOLD_3D)) != 0) || ((navMode == NAV_MODE_RTH) && (navRthState == NAV_RTH_STATE_HEAD_HOME)))
#define navCanAdjustHorizontalVelocityAndAttitudeFromRCInput() ((navMode & (NAV_MODE_POSHOLD_2D | NAV_MODE_POSHOLD_3D | NAV_MODE_RTH)) != 0)
#define navCanAdjustHeadingFromRCInput() ((navMode & (NAV_MODE_POSHOLD_2D | NAV_MODE_POSHOLD_3D | NAV_MODE_RTH)) != 0)

typedef enum navRthState_e {
    NAV_RTH_STATE_INIT = 0,
    NAV_RTH_STATE_CLIMB_TO_SAVE_ALTITUDE,
    NAV_RTH_STATE_HEAD_HOME,
    NAV_RTH_STATE_HOME_AUTOLAND,
    NAV_RTH_STATE_LANDED,
    NAV_RTH_STATE_FINISHED,
} navRthState_t;

typedef struct navigationFlags_s {
    bool verticalPositionNewData;
    bool horizontalPositionNewData;
    bool headingNewData;
} navigationFlags_t;

typedef struct {
    float kP;
    float kI;
    float kD;
    float Imax;
} pidControllerParam_t;

typedef struct {
    float kP;
} pControllerParam_t;

typedef struct {
    pidControllerParam_t param;
    float integrator;       // integrator value
    float last_error;       // last input for derivative
    float pterm_filter_state;
    float dterm_filter_state;  // last derivative for low-pass filter

#if defined(NAV_BLACKBOX)
    float lastP, lastI, lastD;
#endif
} pidController_t;

typedef struct {
    pControllerParam_t param;
    float pterm_filter_state;
#if defined(NAV_BLACKBOX)
    float lastP;
#endif
} pController_t;

typedef struct navigationPIDControllers_s {
    pController_t   pos[XYZ_AXIS_COUNT];
    pController_t   vel[XYZ_AXIS_COUNT];
    pidController_t acc[XYZ_AXIS_COUNT];
#if defined(NAV_HEADING_CONTROL_PID)
    pController_t   heading;
#endif
} navigationPIDControllers_t;

typedef struct {
    navigationPIDControllers_t  pids;
} navigationPosControl_t;
