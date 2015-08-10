typedef struct {
    bool available;
    float variance;
    int32_t value;
} navCLTAxisPos_s;

typedef struct {
    bool available;
    float variance;
    float value;
} navCLTAxisVel_s;

typedef struct {
    struct {
        // For GPS we are doing only altitude
        navCLTAxisPos_s alt;
        navCLTAxisVel_s vel[XYZ_AXIS_COUNT];
    } gps;

    struct {
        navCLTAxisPos_s alt;
        navCLTAxisVel_s vel;
    } baro;

    struct {
        navCLTAxisPos_s alt;
        navCLTAxisVel_s vel;
    } sonar;

    struct {
        navCLTAxisVel_s vel[XYZ_AXIS_COUNT];
    } imu;

    struct {
        navCLTAxisPos_s alt;
        navCLTAxisVel_s vel[XYZ_AXIS_COUNT];
    } estimated;
} navCLTState_s;

static navCLTState_s cltState;

static void cltFilterReset(void)
{
    int axis;

    for (axis = 0; axis < XYZ_AXIS_COUNT; axis++) {
        cltState.gps.vel[axis].available = false;
        cltState.imu.vel[axis].available = false;
        cltState.estimated.vel[axis].available = false;
    }

    cltState.gps.alt.available = false;
    cltState.sonar.alt.available = false;
    cltState.sonar.vel.available = false;
    cltState.baro.alt.available = false;
    cltState.baro.vel.available = false;
    cltState.estimated.alt.available = false;
}

static void cltFilterUpdateEstimate(void)
{
    int axis;
    float new_variance;
    float new_value;
    bool new_available;

    // ALTITUDE
    new_variance = 0;
    new_value = 0;
    new_available = false;

    // GPS altitude
    if (cltState.gps.alt.available) {
        cltState.gps.alt.available = false;
        new_available = true;
        new_variance += 1.0f / cltState.gps.alt.variance;
        new_value += (float)cltState.gps.alt.value / cltState.gps.alt.variance;
    }

    // Baro
    if (cltState.baro.alt.available) {
        cltState.baro.alt.available = false;
        new_available = true;
        new_variance += 1.0f / cltState.baro.alt.variance;
        new_value += (float)cltState.baro.alt.value / cltState.baro.alt.variance;
    }

    // Sonar
    if (cltState.sonar.alt.available) {
        cltState.sonar.alt.available = false;
        new_available = true;
        new_variance += 1.0f / cltState.sonar.alt.variance;
        new_value += (float)cltState.sonar.alt.value / cltState.sonar.alt.variance;
    }

    // Current estimate
    if (cltState.estimated.alt.available) {
        new_variance += 1.0f / cltState.estimated.alt.variance;
        new_value += (float)cltState.estimated.alt.value / cltState.estimated.alt.variance;
    }

    // Update estimate
    cltState.estimated.alt.available = new_available;
    if (new_available) {
        cltState.estimated.alt.variance = 1.0f / new_variance;
        cltState.estimated.alt.value = new_value / new_variance;
    }

    // VELOCITIES
    for (axis = 0; axis < XYZ_AXIS_COUNT; axis++) {
        new_variance = 0;
        new_value = 0;
        new_available = false;

        // GPS velocity
        if (cltState.gps.vel[axis].available) {
            cltState.gps.vel[axis].available = false;
            new_available = true;
            new_variance += 1.0f / cltState.gps.vel[axis].variance;
            new_value += (float)cltState.gps.vel[axis].value / cltState.gps.vel[axis].variance;
        }

        // IMU
        if (cltState.imu.vel[axis].available) {
            cltState.imu.vel[axis].available = false;
            new_available = true;
            new_variance += 1.0f / cltState.imu.vel[axis].variance;
            new_value += (float)cltState.imu.vel[axis].value / cltState.imu.vel[axis].variance;
        }

        // Baro
        if ((axis == Z) && cltState.baro.vel.available) {
            cltState.baro.vel.available = false;
            new_available = true;
            new_variance += 1.0f / cltState.baro.vel.variance;
            new_value += (float)cltState.baro.vel.value / cltState.baro.vel.variance;
        }

        // Sonar
        if ((axis == Z) && cltState.sonar.vel.available) {
            cltState.sonar.vel.available = false;
            new_available = true;
            new_variance += 1.0f / cltState.sonar.vel.variance;
            new_value += (float)cltState.sonar.vel.value / cltState.sonar.vel.variance;
        }

        // Update estimate
        cltState.estimated.vel[axis].available = new_available;
        if (new_available) {
            cltState.estimated.vel[axis].variance = 1.0f / new_variance;
            cltState.estimated.vel[axis].value = new_value / new_variance;
        }
    }
}

static void cltFilterUpdateNAV(void)
{
/*
    // Altitude
    if (cltState.estimated.alt.available)
        updateActualAltitude(cltState.estimated.alt.value);

    // Vertical velocity
    if (cltState.estimated.vel[Z].available)
        updateActualVerticalVelocity(cltState.estimated.vel[Z].value);

    // Horizontal velocity
    if (cltState.estimated.vel[X].available && cltState.estimated.vel[Y].available)
        updateActualHorizontalVelocity(cltState.estimated.vel[X].value, cltState.estimated.vel[Y].value);
*/
}

/*
 * Update CLT filter state from accelerometer integration result.
 */
static void cltFilterUpdateFromIMU(float dT)
{
    int axis;

    for (axis = 0; axis < XYZ_AXIS_COUNT; axis++) {
        if (cltState.estimated.vel[axis].available) {
            cltState.imu.vel[axis].available = true;
            cltState.imu.vel[axis].variance = 15.0f;
            cltState.imu.vel[axis].value = cltState.estimated.vel[axis].value + imuAverageAcceleration[axis] * dT;
        }
        else {
            cltState.imu.vel[axis].available = false;
        }
    }
}

static void cltFilterUpdateFromGPS(float vx, float vy, float vz)
{
    // RMS for GPS vel is about 0.4 cm/s, variance = 0.16
    cltState.gps.vel[X].available = false;
    cltState.gps.vel[X].variance = 0.16;
    cltState.gps.vel[X].value = vx;

    cltState.gps.vel[Y].available = false;
    cltState.gps.vel[Y].variance = 0.16;
    cltState.gps.vel[Y].value = vy;

    cltState.gps.vel[Z].available = false;
    cltState.gps.vel[Z].variance = 0.16;
    cltState.gps.vel[Z].value = vz;
}

static void cltFilterUpdateFromBaro(int32_t alt, float vel)
{
    cltState.baro.alt.available = true;
    cltState.baro.alt.variance = 300;
    cltState.baro.alt.value = alt;

    cltState.baro.vel.available = true;
    cltState.baro.vel.variance = 1000.0f;
    cltState.baro.vel.value = vel;
}





typedef struct {
    unsigned gps_origin_valid : 1;
} navigationStateEstimationFlags_t;

#define NAV_MAX_VARIANCE        (1e+6f)

typedef struct {
    // Origins
    navigationStateEstimationFlags_t    flags;
    navLocation_t                       gps_origin;     // GPS origin (LLH coordinates)

    t_fp_vector     vel;                // Estimated velocity
    t_fp_vector     vel_variance;       // Estimated velocity variance (for CLT fusion)
    
    t_fp_vector     pos;                // Estimated position
    t_fp_vector     pos_variance;       // Estimated position variance (for CLT fusion)
} navigationStateEstimation_t;


/*-----------------------------------------------------------
 * EXPERIMENTAL STATE ESTIMATION
 *-----------------------------------------------------------*/
static navigationStateEstimation_t  navState;

void navInitStateEstimation(void)
{
    navState.flags.gps_origin_valid = 0;

    navState.vel.V.X = 0.0f;
    navState.vel.V.Y = 0.0f;
    navState.vel.V.Z = 0.0f;

    navState.vel_variance.V.X = NAV_MAX_VARIANCE;
    navState.vel_variance.V.Y = NAV_MAX_VARIANCE;
    navState.vel_variance.V.Z = NAV_MAX_VARIANCE;

    navState.pos.V.X = 0.0f;
    navState.pos.V.Y = 0.0f;
    navState.pos.V.Z = 0.0f;

    navState.pos_variance.V.X = NAV_MAX_VARIANCE;
    navState.pos_variance.V.Y = NAV_MAX_VARIANCE;
    navState.pos_variance.V.Z = NAV_MAX_VARIANCE;
}

