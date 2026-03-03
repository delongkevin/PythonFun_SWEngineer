/*
 * $QNXLicenseC:
 * Copyright 2019, QNX Software Systems. All Rights Reserved.
 *
 * You must obtain a written license from and pay applicable
 * license fees to QNX Software Systems before you may reproduce,
 * modify or distribute this software, or any work that includes
 * all or part of this software. Free development licenses are
 * available for evaluation and non-commercial purposes. For more
 * information visit http://licensing.qnx.com or email
 * licensing@qnx.com.
 *
 * This file may contain contributions from others. Please review
 * this entire file for other proprietary rights or license notices,
 * as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */

/**
 * @file serdes_ti_api.h
 *
 * @brief The definitions and functions to use the Texas Instruments (TI)
 *        family of serializers and deserializers.
 *
 * @details This file contains definitions and functions that are specific to
 *          TI serializers and deserializers.  They expand on the general
 *          definitions that can be found in serdes_api.h.
 */

#ifndef __SERDES_TI_API_H__
#define __SERDES_TI_API_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <camera/serdes/serdes_api.h>

/**
 * @brief The name of the this library.
 */
#define TI_SERDES_LIBRARY_PATH                      "libserdes_ti.so"

/**
 * @brief The list of supported TI deserializers.
 * @details These are the acceptable values to use for @c deserializer_id
 *          parameter in the function @c serdes_open_func_t.
 */
typedef enum {
    TI_DESERIALIZER_UB914 = 0,
    TI_DESERIALIZER_UB954,
    TI_DESERIALIZER_UB960
} serdes_ti_deserializer_id_t;

/**
 * @brief The list of supported TI serializers.
 * @details These are the acceptable values to use for @c serializer_id
 *          parameter in the function @c serdes_open_func_t.
 */
typedef enum {
    TI_SERIALIZER_UB913 = 0,
    TI_SERIALIZER_UB953
} serdes_ti_serializer_id_t;

/**
 * @brief The supported GPIO pin value for TI serdes library.
 * @details These are the acceptable values to use for @c pin parameter in the
 *          function @c serdes_set_gpio_func_t.
 */
typedef enum {
    /**
     * Logical low output.
     */
    TI_GPIO_LOW = 0,
    /**
     * Logical high output.
     */
    TI_GPIO_HIGH = 1,
    /**
     * Use frame sync signal as output for this GPIO.
     */
    TI_GPIO_FRAME_SYNC = 2
} serdes_ti_gpio_value_t;

/**
 * @brief The list of flags supported for the deserializer properties.
 * @details You can OR in any combination of these flags when setting the
 *          @c DESER_PROP_FLAGS for the TI serdes library.
 */
typedef enum {
    /**
     * Set this flag to configure low polarity for frame valid (FV) signal
     * which indicates that FV is low during the duration of the valid video
     * frame.  When this flag is false, it configures high polarity for FV
     * which is high during the duration of the valid video frame.
     */
    TI_DESER_FLAG_FV_LOW_POLARITY = 1,
    /**
     * Set this flag to configure low polarity for line valid (LV) signal
     * which indicates that LV is low during the duration of a valid video
     * line.  When this flag is false, it configures high polarity for LV
     * which is high during the duration of a valid video line.
     */
    TI_DESER_FLAG_LV_LOW_POLARITY = 2,
} serdes_ti_deserializer_flags_t;

/**
 * @brief The list of flags supported for the serializer properties.
 * @details You can OR in any combination of these flags when setting the
 *          @c SER_PROP_FLAGS for the TI serdes library.
 */
typedef enum {
    /**
     * Set this flag to enable sending a sensor clock from the serializer
     * output.  The frequency of the generated clock will be controlled by
     * @c TI_SER_PROP_SENSOR_CLOCK.
     */
    TI_SER_FLAG_ENABLE_SENSOR_CLOCK = 1,
} serdes_ti_serializer_flags_t;

/**
 * @brief The fed voltage input for the deserializer.
 * @details Acceptable values for @c TI_DESER_PROP_VOLTAGE_SUPPLY.
 */
typedef enum {
    /**
     * Voltage of 3.3 V.
     */
    TI_VOLTAGE_SUPPLY_3p3,
    /**
     * Voltage of 1.8 V.
     */
    TI_VOLTAGE_SUPPLY_1p8
} serdes_ti_voltage_supply_t;

/**
 * @brief The clock divider to use for a generated clock.
 */
typedef enum {
    /**
     * No division of the input clock.
     */
    TI_CLOCK_DIVIDE_BY_1 = 0,
    /**
     * Input clock is divided by a factor of 2.
     */
    TI_CLOCK_DIVIDE_BY_2,
    /**
     * Input clock is divided by a factor of 4.
     */
    TI_CLOCK_DIVIDE_BY_4,
    /**
     * Input clock is divided by a factor of 8.
     */
    TI_CLOCK_DIVIDE_BY_8,
    /**
     * Input clock is divided by a factor of 16.
     */
    TI_CLOCK_DIVIDE_BY_16
} serdes_ti_clock_divider_t;

/**
 * @brief The configuration for a generated sensor clock from a serializer.
 * @details Acceptable values for @c TI_SER_PROP_SENSOR_CLOCK.  It is supported
 *          only for @c TI_SERIALIZER_UB953 serializer.
 */
typedef struct {
    /**
     * Divider to apply to the input clock.
     */
    serdes_ti_clock_divider_t       divider;
    /**
     * M value for the M/N ratio that is applied to the clock.
     */
    uint8_t                         ratio_m;
    /**
     * N value for the M/N ratio that is applied to the clock.
     */
    uint8_t                         ratio_n;
} serdes_ti_sensor_clock_t;

/**
 * @brief Specific frame synchronization modes supported for TI serdes.
 * @details This extends the definition @c serdes_fsync_t by permitting
 *          these definitions to be ORed together.
 */
typedef enum {
    /**
     * Set this flag combined with @c SERDES_FSYNC_INTERNAL to use the
     * manual frame synchronization method as described by TI using 25 MHz
     * clock.
     */
    TI_FSYNC_MANUAL_25MHZ = 0x400,
    /**
     * Set this flag combined with @c SERDES_FSYNC_INTERNAL to use the
     * manual frame synchronization method as described by TI using
     * back-channel frame clock from port 0.
     */
    TI_FSYNC_MANUAL_BC0 = 0x800,
    /**
     * Set this flag combined with @c SERDES_FSYNC_INTERNAL to use the
     * manual frame synchronization method as described by TI using
     * back-channel frame clock from port 1.
     */
    TI_FSYNC_MANUAL_BC1 = 0x1000,
    /**
     * Set this flag combined with @c SERDES_FSYNC_INTERNAL to use the
     * manual frame synchronization method as described by TI using
     * back-channel frame clock from port 2.
     */
    TI_FSYNC_MANUAL_BC2 = 0x2000,
    /**
     * Set this flag combined with @c SERDES_FSYNC_INTERNAL to use the
     * manual frame synchronization method as described by TI using
     * back-channel frame clock from port 3.
     */
    TI_FSYNC_MANUAL_BC3 = 0x4000,
    /**
     * Set this flag combined with @c SERDES_FSYNC_EXTERNAL to use an
     * external frame synchronization signal from GPIO0
     */
    TI_FSYNC_EXT_GPIO0 = 0x8000,
    /**
     * Set this flag combined with @c SERDES_FSYNC_EXTERNAL to use an
     * external frame synchronization signal from GPIO1
     */
    TI_FSYNC_EXT_GPIO1 = 0x10000,
    /**
     * Set this flag combined with @c SERDES_FSYNC_EXTERNAL to use an
     * external frame synchronization signal from GPIO2
     */
    TI_FSYNC_EXT_GPIO2 = 0x20000,
    /**
     * Set this flag combined with @c SERDES_FSYNC_EXTERNAL to use an
     * external frame synchronization signal from GPIO3
     */
    TI_FSYNC_EXT_GPIO3 = 0x40000,
    /**
     * Set this flag combined with @c SERDES_FSYNC_EXTERNAL to use an
     * external frame synchronization signal from GPIO4
     */
    TI_FSYNC_EXT_GPIO4 = 0x80000,
    /**
     * Set this flag combined with @c SERDES_FSYNC_EXTERNAL to use an
     * external frame synchronization signal from GPIO5
     */
    TI_FSYNC_EXT_GPIO5 = 0x100000,
    /**
     * Set this flag combined with @c SERDES_FSYNC_EXTERNAL to use an
     * external frame synchronization signal from GPIO6
     */
    TI_FSYNC_EXT_GPIO6 = 0x200000,
    /**
     * Set this flag combined with @c SERDES_FSYNC_EXTERNAL to use an
     * external frame synchronization signal from GPIO7
     */
    TI_FSYNC_EXT_GPIO7 = 0x400000
} serdes_ti_fsync_t;

/**
 * @brief Specific deserializer properties support for TI deserializers.
 * @details This extends the definitions of available deserializer properties
 *          in @c serdes_deserializer_property_t.
 */
typedef enum {
    /**
     * Specify the fed input voltage for the deserializer as a
     * @c serdes_ti_voltage_supply_t value.
     */
    TI_DESER_PROP_VOLTAGE_SUPPLY = DESER_PROP_VENDOR_SPECIFIC,
    /**
     * Remap the I2C address of the deserializer.  The value specified here as
     * a @uint8_t value is the original I2c address of the deserializer.  The
     * new I2c address to use for this deserializer will be the one specified
     * as @c DESER_PROP_I2C_ADDR.  This remapping takes effect as part of the
     * initialization.
     */
    TI_DESER_PROP_REMAP_I2C,
    /**
     * Specify the output CSI2 clock frequency to use for the deserializer in
     * MHz as a @uint32_t value.
     */
    TI_DESER_PROP_CSI2_FREQUENCY,
} serdes_ti_deserializer_property_t;

/**
 * @brief Specific serializer properties support for TI serializers.
 * @details This extends the definitions of available serializer properties
 *          in @c serdes_serializer_property_t.
 */
typedef enum {
    /**
     * Configure the properties of the sensor clock if enabled using
     * @c TI_SER_FLAG_ENABLE_SENSOR_CLOCK as a @c serdes_ti_sensor_clock_t*
     * value.
     */
    TI_SER_PROP_SENSOR_CLOCK = SER_PROP_VENDOR_SPECIFIC,
} serdes_ti_serializer_property_t;

#ifdef __cplusplus
}
#endif
#endif   /* __SERDES_TI_API_H__ */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL$ $Rev$")
#endif
