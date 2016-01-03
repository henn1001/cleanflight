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

#include <stdbool.h>
#include <stdint.h>

#include <platform.h>

#include "build_config.h"

#include "gps_i2c.h"

#include "gpio.h"
#include "system.h"
#include "bus_i2c.h"

#include "debug.h"


#define I2C_GPS_ADDRESS               0x42   //ublox default adress
#define I2C_GPS_BYTES_AVAILABLE_HIGH  0xFD
#define I2C_GPS_BYTES_AVAILABLE_LOW   0xFE
#define I2C_GPS_DATA_STREAM           0xFF

bool i2cGPSModuleDetect(void)
{
    bool ack;
    uint8_t i2cGpsStatus;
    
    ack = i2cRead(I2C_GPS_ADDRESS, I2C_GPS_BYTES_AVAILABLE_LOW, 1, &i2cGpsStatus); /* check bytes */
    
    if (ack) 
        return true;
    
    return false;
}

void i2cGPSModuleRead(uint8_t * gpsMsg)
{
    bool ack;
    uint8_t buf[256];
    ack = i2cRead(I2C_GPS_ADDRESS, I2C_GPS_BYTES_AVAILABLE_HIGH, 2, (uint8_t *) buf); /* check bytes */

    //debug to make sure it works
    if (!ack)
        return;

    uint16_t totalBytes = ((uint16_t) buf[0] << 8) | buf[1];

    debug[1] = totalBytes;

    i2cRead(I2C_GPS_ADDRESS, I2C_GPS_DATA_STREAM, totalBytes, (uint8_t *) buf);

    for (uint8_t i = 0; i < totalBytes; i++)
        gpsMsg += buf[i];

//    while (totalBytes)
//      {
//        uint16_t bytes2Read;
//        if (totalBytes > 128)
//          bytes2Read = 128;
//        else
//          bytes2Read = totalBytes;

//        i2cRead(I2C_GPS_ADDRESS, I2C_GPS_DATA_STREAM, bytes2Read, (uint8_t *) buf);

//        for (uint8_t i = 0; i < bytes; i++)
//          gpsMsg += buf[i];

//        totalBytes -= bytes2Read;
//      }

}

void i2cGPSModuleWrite(uint8_t * data)
{
    i2cWrite(I2C_GPS_ADDRESS, 0, data);

}
