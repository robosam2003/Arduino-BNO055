//
// Created by Tom Danvers on 02/01/2022.
// 2022 TeamSunride.
//

#ifndef BNO055_CONSTANTS_H
#define BNO055_CONSTANTS_H
#define pi 3.14159265359

// Comments in this file are not mine and are taken from the BNO055 datasheet

#include "util/Vector.h"
#include "util/Quaternion.h"

/**
 * Each unsigned integer represents the calibration status of a sensor.
 * 3 indicates fully calibrated, 0 indicates not calibrated.
 * Refer to section 3.10 of the datasheet
 */
typedef struct {
    uint8_t accel;
    uint8_t gyro;
    uint8_t mag;
    uint8_t sys;
} bno055_calib_stat_t;

typedef struct {
    Vector<double> accel;
    Vector<double> mag;
    Vector<double> gyro;
    Vector<double> linearAccel;
    Vector<double> gravityVector;
    Quaternion quaternion;
    Vector<double> euler;



} bno055_burst_t;

enum BNO055_TEMP_SOURCE_TYPE {
    ACCEL_TEMP = 0b00,
    GYRO_TEMP = 0b01
};

enum BNO055_POWER_MODE {
    /**
     * In normal mode all sensors required for the selected operating mode (see section 3.3) are
     * always switched ON. The register map and the internal peripherals of the MCU are always
     * operative in this mode.
     */
    NORMAL = 0b00,

    /**
     * If no activity (i.e. no motion) is detected for a configurable duration (default 5 seconds), the
     * BNO055 enters the low power mode. In this mode only the accelerometer is active. Once
     * motion is detected (i.e. the accelerometer signals an any-motion interrupt), the system is
     * woken up and normal mode is entered.
     */
    LOW_POWER = 0b01,

    /**
     * In suspend mode the system is paused and all the sensors and the microcontroller are put
     * into sleep mode. No values in the register map will be updated in this mode. To exit from
     * suspend mode the mode should be changed by writing to the PWR_MODE register (see Table 3-1).
     */
    SUSPEND = 0b10
};

/**
 * The BNO055 provides a variety of output signals, which can be chosen by selecting the
appropriate operation mode.
 */
enum BNO055_OPERATION_MODE {
    /**
     * This mode is used to configure BNO, wherein all output data is reset to zero and sensor
fusion is halted. This is the only mode in which all the writable register map entries can be
changed. (Exceptions from this rule are the interrupt registers (INT and INT_MSK) and the
operation mode register (OPR_MODE), which can be modified in any operation mode.)
As being said, this mode is the default operation mode after power-on or RESET. Any other
mode must be chosen to be able to read any sensor data.
     */
    CONFIGMODE = 0b0000,
    /**
     * If the application requires only raw accelerometer data, this mode can be chosen. In this
mode the other sensors (magnetometer, gyro) are suspended to lower the power
consumption. In this mode, the BNO055 behaves like a stand-alone acceleration sensor
     */
    ACCONLY = 0b0001,
    /**
     * In MAGONLY mode, the BNO055 behaves like a stand-alone magnetometer, with
acceleration sensor and gyroscope being suspended.
     */
    MAGONLY = 0b0010,
    /**
     * In GYROONLY mode, the BNO055 behaves like a stand-alone gyroscope, with acceleration
sensor and magnetometer being suspended.
     */
    GYROONLY = 0b0011,
    /**
     * Both accelerometer and magnetometer are switched on, the user can read the data from
these two sensors.
     */
    ACCMAG = 0b0100,
    /**
     * Both accelerometer and gyroscope are switched on; the user can read the data from these
two sensors.
     */
    ACCGYRO = 0b0101,
    /**
     * Both magnetometer and gyroscope are switched on, the user can read the data from these
two sensors.
     */
    MAGGYRO = 0b0110,
    /**
     * All three sensors accelerometer, magnetometer and gyroscope are switched on.
     */
    AMG = 0b0111,
    /**
     * In the IMU mode the relative orientation of the BNO055 in space is calculated from the
accelerometer and gyroscope data. The calculation is fast (i.e. high output data rate).
     */
    IMU = 0b1000,
    /**
     * The COMPASS mode is intended to measure the magnetic earth field and calculate the
geographic direction.
The earth magnetic field is a vector with the horizontal components x,y and the vertical z
component. It depends on the position on the globe and natural iron occurrence. For
heading calculation (direction of compass pointer) only the horizontal components x and y
are used. Therefore the vector components of the earth magnetic field must be transformed
in the horizontal plane, which requires the knowledge of the direction of the gravity vector.
To summarize, the heading can only be calculated when considering gravity and magnetic
field at the same time.
However, the measurement accuracy depends on the stability of the surrounding magnetic
field. Furthermore, since the earth magnetic field is usually much smaller than the magnetic
fields that occur around and inside electronic devices, the compass mode requires
calibration (see chapter 3.10)
     */
    COMPASS = 0b1001,
    /**
     * The M4G mode is similar to the IMU mode, but instead of using the gyroscope signal to
detect rotation, the changing orientation of the magnetometer in the magnetic field is used.
Since the magnetometer has much lower power consumption than the gyroscope, this mode
is less power consuming in comparison to the IMU mode. There are no drift effects in this
mode which are inherent to the gyroscope.
However, as for compass mode, the measurement accuracy depends on the stability of the
surrounding magnetic field.
For this mode no magnetometer calibration is required and also not available.
     */
    M4G = 0b1010,
    /**
     * This fusion mode is same as NDOF mode, but with the Fast Magnetometer Calibration
turned ‘OFF’.
     */
    NDOF_FMC_OFF = 0b1011,
    /**
     * This is a fusion mode with 9 degrees of freedom where the fused absolute orientation data
is calculated from accelerometer, gyroscope and the magnetometer. The advantages of
combining all three sensors are a fast calculation, resulting in high output data rate, and high
robustness from magnetic field distortions. In this mode the Fast Magnetometer calibration
is turned ON and thereby resulting in quick calibration of the magnetometer and higher
output data accuracy. The current consumption is slightly higher in comparison to the
NDOF_FMC_OFF fusion mode.
     */
    NDOF = 0b1100
};

/**
 * PAGE 0
 *
 * The following registers are on PAGE 0 of the register map
 */

// An enum might be better here??
#define BNO055_CHIP_ID              0x00
#define BNO055_ACC_ID               0x01
#define BNO055_MAG_ID               0x02
#define BNO055_GYR_ID               0x03
#define BNO055_SW_REV_ID_LSB        0x04
#define BNO055_SW_REV_ID_MSB        0x05
#define BNO055_BL_Rev_ID            0x06
#define BNO055_PAGE_ID              0x07

#define BNO055_ACC_DATA_X_LSB       0x08
#define BNO055_ACC_DATA_X_MSB       0x09
#define BNO055_ACC_DATA_Y_LSB       0xA
#define BNO055_ACC_DATA_Y_MSB       0xB
#define BNO055_ACC_DATA_Z_LSB       0xC
#define BNO055_ACC_DATA_Z_MSB       0xD

#define BNO055_MAG_DATA_X_LSB       0xE
#define BNO055_MAG_DATA_X_MSB       0xF
#define BNO055_MAG_DATA_Y_LSB       0x10
#define BNO055_MAG_DATA_Y_MSB       0x11
#define BNO055_MAG_DATA_Z_LSB       0x12
#define BNO055_MAG_DATA_Z_MSB       0x13

#define BNO055_GYR_DATA_X_LSB       0x14
#define BNO055_GYR_DATA_X_MSB       0x15
#define BNO055_GYR_DATA_Y_LSB       0x16
#define BNO055_GYR_DATA_Y_MSB       0x17
#define BNO055_GYR_DATA_Z_LSB       0x18
#define BNO055_GYR_DATA_Z_MSB       0x19

#define BNO055_EUL_HEADING_LSB      0x1A
#define BNO055_EUL_HEADING_MSB      0x1B
#define BNO055_EUL_ROLL_LSB         0x1C
#define BNO055_EUL_ROLL_MSB         0x1D
#define BNO055_EUL_PITCH_LSB        0x1E
#define BNO055_EUL_PITCH_MSB        0x1F

#define BNO055_QUA_DATA_W_LSB       0x20
#define BNO055_QUA_DATA_W_MSB       0x21
#define BNO055_QUA_DATA_X_LSB       0x22
#define BNO055_QUA_DATA_X_MSB       0x23
#define BNO055_QUA_DATA_Y_LSB       0x24
#define BNO055_QUA_DATA_Y_MSB       0x25
#define BNO055_QUA_DATA_Z_LSB       0x26
#define BNO055_QUA_DATA_Z_MSB       0x27

#define BNO055_LIA_DATA_X_LSB       0x28
#define BNO055_LIA_DATA_X_MSB       0x29
#define BNO055_LIA_DATA_Y_LSB       0x2A
#define BNO055_LIA_DATA_Y_MSB       0x2B
#define BNO055_LIA_DATA_Z_LSB       0x2C
#define BNO055_LIA_DATA_Z_MSB       0x2D

#define BNO055_GRV_DATA_X_LSB       0x2E
#define BNO055_GRV_DATA_X_MSB       0x2F
#define BNO055_GRV_DATA_Y_LSB       0x30
#define BNO055_GRV_DATA_Y_MSB       0x31
#define BNO055_GRV_DATA_Z_LSB       0x32
#define BNO055_GRV_DATA_Z_MSB       0x33

#define BNO055_TEMP_REG             0x34

#define BNO055_CALIB_STAT           0x35
#define BNO055_ST_RESULT            0x36
#define BNO055_INT_STA              0x37
#define BNO055_SYS_CLK_STATUS       0x38
#define BNO055_SYS_STATUS           0x39
#define BNO055_SYS_ERR              0x3A
#define BNO055_UNIT_SEL             0x3B
#define BNO055_OPR_MODE_REG         0x3D
#define BNO055_PWR_MODE_REG         0x3E
#define BNO055_SYS_TRIGGER          0x3F
#define BNO055_TEMP_SOURCE          0x40
#define BNO055_AXIS_MAP_CONFIG      0x41
#define BNO055_AXIS_MAP_SIGN        0x42

#define SIC_MATRIX_LSB0             0x43
#define SIC_MATRIX_MSB0             0x44
#define SIC_MATRIX_LSB1             0x45
#define SIC_MATRIX_MSB1             0x46
#define SIC_MATRIX_LSB2             0x47
#define SIC_MATRIX_MSB2             0x48
#define SIC_MATRIX_LSB3             0x49
#define SIC_MATRIX_MSB3             0x4A
#define SIC_MATRIX_LSB4             0x4B
#define SIC_MATRIX_LSB5             0x4D
#define SIC_MATRIX_MSB5             0x4E
#define SIC_MATRIX_LSB6             0x4F
#define SIC_MATRIX_MSB6             0x50
#define SIC_MATRIX_LSB7             0x51
#define SIC_MATRIX_MSB7             0x52
#define SIC_MATRIX_LSB8             0x53
#define SIC_MATRIX_MSB8             0x54


#define ACC_OFFSET_X_LSB            0x55
#define ACC_OFFSET_X_MSB            0x56
#define ACC_OFFSET_Y_LSB            0x57
#define ACC_OFFSET_Y_MSB            0x58
#define ACC_OFFSET_Z_LSB            0x59
#define ACC_OFFSET_Z_MSB            0x5A

#define MAG_OFFSET_X_LSB            0x5B
#define MAG_OFFSET_X_MSB            0x5C
#define MAG_OFFSET_Y_LSB            0x5D
#define MAG_OFFSET_Y_MSB            0x5E
#define MAG_OFFSET_Z_LSB            0x5F
#define MAG_OFFSET_Z_MSB            0x60

#define GYR_OFFSET_X_LSB            0x61
#define GYR_OFFSET_X_MSB            0x62
#define GYR_OFFSET_Y_LSB            0x63
#define GYR_OFFSET_Y_MSB            0x64
#define GYR_OFFSET_Z_LSB            0x65
#define GYR_OFFSET_Z_MSB            0x66

#define ACC_RADIUS_LSB              0x67
#define ACC_RADIUS_MSB              0x68
#define MAG_RADIUS_LSB              0x69
#define MAG_RADIUS_MSB              0x7A


/**
 * PAGE 1
 *
 * The following registers are on PAGE 1 of the register map
 */

#define BNO055_ACC_CONFIG           0x08
#define BNO055_MAG_CONFIG           0x09
#define BNO055_GYR_CONFIG_0         0xA
#define BNO055_GYR_CONFIG_1         0xB
#define BNO055_ACC_SLEEP_CONFIG     0xC
#define BNO055_GYR_SLEEP_CONFIG     0xD
#define BNO055_INT_MSK              0xF
#define BNO055_INT_EN               0x10

#define BNO055_ACC_AM_THRES         0x11
#define BNO055_ACC_INT_SETTINGS     0x12
#define BNO055_ACC_HG_DURATION      0x13
#define BNO055_ACC_HG_THRES         0x14
#define BNO055_ACC_NM_THRES         0x15
#define BNO055_ACC_NM_SET           0x16

#define BNO055_GYR_INT_SETTING      0x17
#define BNO055_GYR_HR_X_SET         0x18
#define BNO055_GYR_DUR_X            0x19
#define BNO055_GYR_HR_Y_SET         0x1A
#define BNO055_GYR_DUR_Y            0x1B
#define BNO055_GYR_HR_Z_SET         0x1C
#define BNO055_GYR_DUR_Z            0x1D
#define BNO055_GYR_AM_THRES         0x1E
#define BNO055_GYR_AM_SET           0x1F


// copying all of this from the datasheet was a lot of fun

#endif //BNO055_CONSTANTS_H
