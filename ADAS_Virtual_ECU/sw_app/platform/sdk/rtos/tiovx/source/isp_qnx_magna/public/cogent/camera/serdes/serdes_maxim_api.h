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
 * @file serdes_maxim_api.h
 *
 * @brief The definitions and functions to use the Maxim family of serializers
 *        and deserializers.
 *
 * @details This file contains definitions and functions that are specific to
 *          Maxim serializers and deserializers.  They expand on the general
 *          definitions that can be found in serdes_api.h.
 */

#ifndef __SERDES_MAXIM_API_H__
#define __SERDES_MAXIM_API_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <camera/serdes/serdes_api.h>

/**
 * @brief The name of the this library.
 */
#define MAXIM_SERDES_LIBRARY_PATH                   "libserdes_maxim.so"

/**
 * @brief The list of supported Maxim deserializers.
 * @details These are the acceptable values to use for @c deserializer_id
 *          parameter in the function @c serdes_open_func_t.
 */
typedef enum {
    MAXIM_DESERIALIZER_MAX9286 = 0,
} serdes_maxim_deserializer_id_t;

/**
 * @brief The list of supported Maxim serializers.
 * @details These are the acceptable values to use for @c serializer_id
 *          parameter in the function @c serdes_open_func_t.
 */
typedef enum {
    MAXIM_SERIALIZER_MAX9271 = 0,
    MAXIM_SERIALIZER_MAX96705,
    MAXIM_SERIALIZER_MAX96709,
    MAXIM_SERIALIZER_MAX96715
} serdes_maxim_serializer_id_t;

/**
 * @brief The supported GPIO pin value for Maxim serdes library.
 * @details These are the acceptable values to use for @c pin parameter in the
 *          function @c serdes_set_gpio_func_t.
 */
typedef enum {
    /**
     * Logical low output.
     */
    MAXIM_GPIO_LOW = 0,
    /**
     * Logical high output.
     */
    MAXIM_GPIO_HIGH = 1
} serdes_maxim_gpio_value_t;

/**
 * @brief The list of flags supported for the deserializer properties.
 * @details You can OR in any combination of these flags when setting the
 *          @c DESER_PROP_FLAGS for the Maxim serdes library.
 */
typedef enum {
    /**
     * Set this flag to initialize the reverse channel.
     */
    MAXIM_DESER_FLAG_INIT_REVERSE_CHANNEL = 1,
    /**
     * Set this flag to set non-default values for the CSI2 PHY parameters.
     */
    MAXIM_DESER_FLAG_SET_CSI2_PHY = 2,
    /**
     * Set this flag to invert VSYNC polarity from active high to active low.
     */
    MAXIM_DESER_FLAG_INVERT_VSYNC = 4,
    /**
     * Set this flag to invert HSYNC polarity from active high to active low.
     */
    MAXIM_DESER_FLAG_INVERT_HSYNC = 8,
    /**
     * Set this flag to enable double input mode.  When not set, single input
     * mode is used.
     */
    MAXIM_DESER_FLAG_DOUBLE_INPUT_MODE = 0x10,
    /**
     * Set this flag to use 32-bit Bandwidth Select (BWS); if not set, uses
     * 24-bit BWS.
     */
    MAXIM_DESER_FLAG_USE_32BIT_BWS = 0x20,
    /**
     * Set this flag to boost the reverse channel transmitter pulse amplitude;
     * if not set, default amplitude for the output type is used.
     */
    MAXIM_DESER_FLAG_BOOST_REVERSE_CHANNEL_PULSE = 0x40,
    /**
     * Set this flag to override a reserved bit in the VC register to 1; if not
     * set, this reserved bit will be set to its default value of 0.
     */
    MAXIM_DESER_FLAG_USE_VC_RESERVED = 0x80,
    /**
     * Set this flag to use serializer broacast I2C address when enabling or
     * disabling serializer links.  This will use the I2C broadcast I2C
     * address set as @c MAXIM_DESER_SERIALIZER_I2C_BROADCAST_ALIAS.  If not
     * set, individual writes will be done to each serializer.
     */
    MAXIM_DESER_FLAG_USE_SERIALIZER_BROADCAST = 0x100,
    /**
     * Set this flag to make use of the generated VSYNC of the deserializer
     * instead of the one obtained from the camera.
     */
    MAXIM_DESER_FLAG_USE_GENERATED_VSYNC = 0x200,
    /**
     * Set this flag to disable line fault monitoring.
     */
    MAXIM_DESER_FLAG_DISABLE_LINE_FAULT = 0x400,
    /**
     * Set this flag to disable local acknowledge.
     */
    MAXIM_DESER_FLAG_DISABLE_LOCAL_ACK = 0x800
} serdes_maxim_deserializer_flags_t;

/**
 * @brief The list of flags supported for the serializer properties.
 * @details You can OR in any combination of these flags when setting the
 *          @c SER_PROP_FLAGS for the Maxim serdes library.
 */
typedef enum {
    /**
     * Set this flag to implement a retry mechanism for the I2C alias set for
     * the sensor in the serializer.
     */
    MAXIM_SER_FLAG_RETRY_I2C_ALIAS = 1,
    /**
     * Set this flag to disable presence check of the serializer which is used
     * to skip the initialization of the serializer if it responds to requests
     * using its I2c alias in case it was previously initialized.
     */
    MAXIM_SER_FLAG_DISABLE_CHECK_PRESENCE = 2,
    /**
     * Set this flag to enable the reverse control channel programming mode.
     */
    MAXIM_SER_FLAG_ENABLE_RCCP = 4,
    /**
     * Set this flag to enable dual single ended outputs (coax); if this flag
     * is not set, it uses differential output (STP mode).
     */
    MAXIM_SER_FLAG_COAX_OUTPUT = 8,
    /**
     * Set this flag to sample the data on pixel clock rising edge; if this
     * flag is not set, data is sampled on pixel clock falling edge.
     */
    MAXIM_SER_FLAG_PCLK_RISING_EDGE = 0x10,
    /**
     * Set this flag to enable HSYNC generation from the serializer; if this
     * flag is not set, HSYNC from the sensor is used.
     */
    MAXIM_SER_FLAG_ENABLE_HSYNC_GENERATION = 0x20,
    /**
     * Set this flag to enable VSYNC generation from the serializer; if this
     * flag is not set, VSYNC from the sensor is used.
     */
    MAXIM_SER_FLAG_ENABLE_VSYNC_GENERATION = 0x40,
    /**
     * Set this flag to enable auto configuration link which automatically
     * enables the configuration link when no pixel clock is detected.
     */
    MAXIM_SER_FLAG_AUTO_CONFIGURATION_LINK = 0x80,
    /**
     * Set this flag to delay setup of the serializer reverse channel until
     * the reverse channel amplitude has been configured.  If not set, the
     * recommended order of setting the serializer reverse channel prior
     * to setting the reverse channel amplitude is used.
     */
    MAXIM_SER_FLAG_DELAY_REVERSE_CHANNEL = 0x100,
    /**
     * Set this flag to enable high immunity mode of the reverse control
     * channel.
     */
    MAXIM_SER_FLAG_HIGH_IMMUNITY = 0x200,
    /**
     * Set this flag to enable high pulse amplitude of the reverse channel
     * transmitter.
     */
    MAXIM_SER_FLAG_HIGH_REVERSE_AMPLITUDE = 0x400,
    /**
     * Set this flag to skip initialization of the serializer.
     */
    MAXIM_SER_FLAG_SKIP_INITIALIZATION = 0x800
} serdes_maxim_serializer_flags_t;

/**
 * @brief Specific frame synchronization modes supported for Maxim serdes.
 * @details This extends the definition @c serdes_fsync_t by permitting
 *          these definitions to be ORed together.
 */
typedef enum {
    /**
     * Set this flag combined with @c SERDES_FSYNC_INTERNAL to use the
     * semi-automatic frame synchronization method as described by Maxim.
     */
    MAXIM_FSYNC_SEMI_AUTOMATIC = 0x100,
    /**
     * Set this flag combined with @c SERDES_FSYNC_INTERNAL to use the
     * automatic frame synchronization method as described by Maxim.
     */
    MAXIM_FSYNC_AUTOMATIC = 0x200,
    /**
     * Set this flag combined with @c SERDES_FSYNC_INTERNAL to use the
     * manual frame synchronization method as described by Maxim.
     */
    MAXIM_FSYNC_MANUAL = 0x400,
    /**
     * Set this flag combined with @c SERDES_FSYNC_EXTERNAL to use an
     * external frame synchronization signal from another deserializer.
     */
    MAXIM_FSYNC_EXT_DESER = 0x800,
    /**
     * Set this flag combined with @c SERDES_FSYNC_EXTERNAL to use an
     * external frame synchronization signal from ECU using a FSYNC input pin.
     */
    MAXIM_FSYNC_EXT_ECU = 0x1000
} serdes_maxim_fsync_t;

/**
 * @brief The supported error detection mode.
 */
typedef enum {
    /**
     * Error detection is done using 1-bit parity error code.
     */
    MAXIM_EDC_PARITY_1BIT = 0,
    /**
     * Error detection is done using 6-bit CRC code.
     */
    MAXIM_EDC_CRC_6BIT,
    /**
     * Error detection is done using 6-bit Hamming code.
     */
    MAXIM_EDC_HAMMING_6BIT
} serdes_maxim_edc_t;

/**
 * @brief The supported line equalization gain.
 */
typedef enum {
    /**
     * Line equalization gain of 2.1 dB.
     */
    MAXIM_EQUALIZER_GAIN_2_1_DB = 0,
    /**
     * Line equalization gain of 2.8 dB.
     */
    MAXIM_EQUALIZER_GAIN_2_8_DB,
    /**
     * Line equalization gain of 3.4 dB.
     */
    MAXIM_EQUALIZER_GAIN_3_4_DB,
    /**
     * Line equalization gain of 4.2 dB.
     */
    MAXIM_EQUALIZER_GAIN_4_2_DB,
    /**
     * Line equalization gain of 5.2 dB.
     */
    MAXIM_EQUALIZER_GAIN_5_2_DB,
    /**
     * Line equalization gain of 6.2 dB.
     */
    MAXIM_EQUALIZER_GAIN_6_2_DB,
    /**
     * Line equalization gain of 7.0 dB.
     */
    MAXIM_EQUALIZER_GAIN_7_0_DB,
    /**
     * Line equalization gain of 8.2 dB.
     */
    MAXIM_EQUALIZER_GAIN_8_2_DB,
    /**
     * Line equalization gain of 9.4 dB.
     */
    MAXIM_EQUALIZER_GAIN_9_4_DB,
    /**
     * Line equalization gain of 10.7 dB.
     */
    MAXIM_EQUALIZER_GAIN_10_7_DB,
    /**
     * Line equalization gain of 11.7 dB.
     */
    MAXIM_EQUALIZER_GAIN_11_7_DB,
    /**
     * Line equalization gain of 13.0 dB.
     */
    MAXIM_EQUALIZER_GAIN_13_0_DB,
    /**
     * Line equalization on this link is disabled.
     */
    MAXIM_EQUALIZER_GAIN_DISABLED
} serdes_maxim_equalizer_gain_t;

/**
 * @brief The supported crossbar output.
 * @details These are the output signals sent on the GMSL output based on
 *          an associated input pin signal.
 */
typedef enum {
    MAXIM_XBO_0 = 0,
    MAXIM_XBO_1,
    MAXIM_XBO_2,
    MAXIM_XBO_3,
    MAXIM_XBO_4,
    MAXIM_XBO_5,
    MAXIM_XBO_6,
    MAXIM_XBO_7,
    MAXIM_XBO_8,
    MAXIM_XBO_9,
    MAXIM_XBO_10,
    MAXIM_XBO_11,
    MAXIM_XBO_12,
    MAXIM_XBO_13,
    MAXIM_XBO_14,
    MAXIM_XBO_15,
    MAXIM_XBO_16,
    MAXIM_XBO_17,
    MAXIM_XBO_18,
    MAXIM_XBO_19,
    MAXIM_XBO_20,
    MAXIM_XBO_21,
    MAXIM_XBO_22,
    MAXIM_XBO_23,
    MAXIM_XBO_24,
    MAXIM_XBO_25,
    MAXIM_XBO_26,
    MAXIM_XBO_27,
    MAXIM_XBO_28,
    MAXIM_XBO_29,
    MAXIM_XBO_30,
    MAXIM_XBO_HS,
    MAXIM_XBO_VS,
    MAXIM_XBO_DE,
    MAXIM_XBO_NUM_OUTPUTS
} serdes_maxim_crossbar_output_t;

/**
 * @brief The supported crossbar input pins.
 * @details These are the input pins to connect to the desired crossbar
 *          output.  When DBL is used, it is also possible to select the high
 *          clock values for those pins, others select the low clock values.
 *          For @c MAXIM_XBO_HS, @c MAXIM_XBO_VS and @c MAXIM_XBO_DE, only the
 *          low clock value can be selected.
 */
typedef enum {
    MAXIM_XBI_DIN0 = 0,
    MAXIM_XBI_DIN1,
    MAXIM_XBI_DIN2,
    MAXIM_XBI_DIN3,
    MAXIM_XBI_DIN4,
    MAXIM_XBI_DIN5,
    MAXIM_XBI_DIN6,
    MAXIM_XBI_DIN7,
    MAXIM_XBI_DIN8,
    MAXIM_XBI_DIN9,
    MAXIM_XBI_DIN10,
    MAXIM_XBI_DIN11,
    MAXIM_XBI_DIN12,
    MAXIM_XBI_DIN13,
    MAXIM_XBI_DIN14,
    MAXIM_XBI_DIN15,
    MAXIM_XBI_DIN0_HIGH,
    MAXIM_XBI_DIN1_HIGH,
    MAXIM_XBI_DIN2_HIGH,
    MAXIM_XBI_DIN3_HIGH,
    MAXIM_XBI_DIN4_HIGH,
    MAXIM_XBI_DIN5_HIGH,
    MAXIM_XBI_DIN6_HIGH,
    MAXIM_XBI_DIN7_HIGH,
    MAXIM_XBI_DIN8_HIGH,
    MAXIM_XBI_DIN9_HIGH,
    MAXIM_XBI_DIN10_HIGH,
    MAXIM_XBI_DIN11_HIGH,
    MAXIM_XBI_DIN12_HIGH,
    MAXIM_XBI_DIN13_HIGH,
    MAXIM_XBI_DIN14_HIGH,
    MAXIM_XBI_DIN15_HIGH
} serdes_maxim_crossbar_input_t;

/**
 * @brief Additional flags to qualify the connection of the crossbar.
 */
typedef enum {
    /**
     * No flags have been set.
     */
    MAXIM_XBFLAG_NONE = 0,
    /**
     * If this flag is set, the output will be the inverted input value.
     */
    MAXIM_XBFLAG_INVERT_OUTPUT = 1,
    /**
     * If this flag is set, the output will be always set to logical low value.
     */
    MAXIM_XBFLAG_FORCE_LOW = 2,
    /**
     * If this flag is set, the output will be disabled.  Please note that this
     * setting is using a setting that is not officially supported according to
     * Maxim documentation.  This is only applicable to @c MAXIM_XBO_HS,
     * @c MAXIM_XBO_VS and @c MAXIM_XBO_DE.
     */
    MAXIM_XBFLAG_DISABLE = 4
} serdes_maxim_crossbar_flags_t;

/**
 * @brief The configuration for a given crossbar entry.
 * @details These are to be used when configuring @c MAXIM_SER_CROSSBAR
 *          property of the serializer.  It indicates what pin value to assign
 *          for a given output signal sent on the GMSL link.
 */
typedef struct {
    /**
     * The input pin that is to be connected to the desired crossbar output.
     */
    serdes_maxim_crossbar_input_t       input;
    /**
     * The desired crossbar output to configure.
     */
    serdes_maxim_crossbar_output_t      output;
    /**
     * Additional flags to qualify the crossbar connection.  You can OR in any
     * flags defined in @c serdes_maxim_crossbar_flags_t.
     */
    uint32_t                            flags;
} serdes_maxim_crossbar_t;

/**
 * @brief The type of PRBS test to perform.
 */
typedef enum {
    /**
     * Use MAX9249, MAX9259-MAX9265 and MAX9275-MAX9293
     * compatible PRBS test.
     */
    MAXIM_PRBS_LEGACY_MODE,
    /**
     * Use MAX9271-MAX9273 compatible PRBS test.
     */
    MAXIM_PRBS_MAX9271_MODE
} serdes_maxim_prbs_type_t;

/**
 * @brief Parameters for the PRBS test to perform.
 */
typedef struct {
    /**
     * The type of the test to perform.
     */
    serdes_maxim_prbs_type_t            type;
    /**
     * How long to run the test in micro-seconds.
     */
    uint32_t                            test_interval;
} serdes_maxim_prbs_params_t;

/**
 * @brief The results from running the PRBS test.
 */
typedef struct {
    /**
     * Detected error counter for link 0.
     */
    uint8_t num_detected_errors_link_0;
    /**
     * Detected error counter for link 1.
     */
    uint8_t num_detected_errors_link_1;
    /**
     * Detected error counter for link 2.
     */
    uint8_t num_detected_errors_link_2;
    /**
     * Detected error counter for link 3.
     */
    uint8_t num_detected_errors_link_3;
    /**
     * Corrected error counter for link 0.
     */
    uint8_t num_corrected_errors_link_0;
    /**
     * Corrected error counter for link 1.
     */
    uint8_t num_corrected_errors_link_1;
    /**
     * Corrected error counter for link 2.
     */
    uint8_t num_corrected_errors_link_2;
    /**
     * Corrected error counter for link 3.
     */
    uint8_t num_corrected_errors_link_3;
} serdes_maxim_prbs_results_t;

/**
 * @brief The supported spread spectrum.
 */
typedef enum {
    /**
     * Spread is off.
     */
    MAXIM_SPREAD_SPECTRUM_OFF = 0,
    /**
     * 0.5% spread setting.
     */
    MAXIM_SPREAD_SPECTRUM_0_5,
    /**
     * 1.5% spread setting.
     */
    MAXIM_SPREAD_SPECTRUM_1_5,
    /**
     * 2.0% spread setting.
     */
    MAXIM_SPREAD_SPECTRUM_2_0,
    /**
     * Spread is off.
     */
    MAXIM_SPREAD_SPECTRUM_OFF_2,
    /**
     * 1.0% spread setting.
     */
    MAXIM_SPREAD_SPECTRUM_1_0,
    /**
     * 3.0% spread setting.
     */
    MAXIM_SPREAD_SPECTRUM_3_0,
    /**
     * 4.0% spread setting.
     */
    MAXIM_SPREAD_SPECTRUM_4_0
} serdes_maxim_spread_spectrum_t;

/**
 * Camera serializer preemphasis level.
 */
typedef enum {
    /**
     * Preemphasis off.
     */
    MAXIM_PREEMP_OFF = 0,
    /**
     * 1.2dB deemphasis.
     */
    MAXIM_PREEMP_1_2DB_DEEM,
    /**
     * 2.5dB deemphasis.
     */
    MAXIM_PREEMP_2_5DB_DEEM,
    /**
     * 4.1dB deemphasis.
     */
    MAXIM_PREEMP_4_1DB_DEEM,
    /**
     * 6.0dB deemphasis.
     */
    MAXIM_PREEMP_6_0DB_DEEM,
    /**
     * Do not use
     */
    MAXIM_PREEMP_DO_NOT_USE_1,
    MAXIM_PREEMP_DO_NOT_USE_2,
    MAXIM_PREEMP_DO_NOT_USE_3,
    /**
     * 1.1dB preemphasis.
     */
    MAXIM_PREEMP_1_1DB_PREEM,
    /**
     * 2.2dB preemphasis.
     */
    MAXIM_PREEMP_2_2DB_PREEM,
    /**
     * 3.3dB preemphasis.
     */
    MAXIM_PREEMP_3_3DB_PREEM,
    /**
     * 4.4dB preemphasis.
     */
    MAXIM_PREEMP_4_4DB_PREEM,
    /**
     * 6.0dB preemphasis.
     */
    MAXIM_PREEMP_6_0DB_PREEM,
    /**
     * 8.0dB preemphasis.
     */
    MAXIM_PREEMP_8_0DB_PREEM,
    /**
     * 10.5dB preemphasis.
     */
    MAXIM_PREEMP_10_5DB_PREEM,
    /**
     * 14.0dB preemphasis.
     */
    MAXIM_PREEMP_14_0DB_PREEM
} serdes_maxim_preemp_level_t;

/**
 * @brief Specific deserializer properties support for Maxim deserializers.
 * @details This extends the definitions of available deserializer properties
 *          in @c serdes_deserializer_property_t.
 */
typedef enum {
    /**
     * The error detection scheme for the GSML link as a @c serdes_maxim_edc_t
     * value.
     */
    MAXIM_DESER_PROP_ERROR_DETECTION = DESER_PROP_VENDOR_SPECIFIC,
    /**
     * The line equalizer gain to apply as a @ serdes_maxim_equalizer_gain_t.
     * It defaults to @c MAXIM_EQUALIZER_GAIN_DISABLED.
     */
    MAXIM_DESER_PROP_EQUALIZER_GAIN,
    /**
     * The link to enable for reverse control send of I2C commands as a
     * @c serdes_link_t.  Use @c SERDES_LINK_NONE to enable all links which
     * is the default behavior after initialization.  Note that this property
     * can only be set after having called @c serdes_init_func_t which is
     * different than other properties.
     */
    MAXIM_DESER_PROP_ENABLE_REVERSE_LINK,
    /*
     * Read-only property that indicates the status of the links attached to
     * the deserializer to know which ones are active currently as a @c uint8_t
     * value.  Bit 0 represents the status of the first link while subsequent
     * bits represent the status of the other links.  If the bit is set to 1,
     * it indicates that this link is detected as active.
     */
    MAXIM_DESER_PROP_LINK_STATUS,
    /**
     * To reduce the number of I2C writes that are used to enable the
     * serializer links, it is possible to set a @c
     * MAXIM_SER_PROP_DEVICE_I2C_ALIAS for each serializer that can be used
     * to configure all serializer simultaneously.  If this is desired, set
     * this property to the desired I2C alias address to use as a @c uint8_t
     * and set @c MAXIN_DESER_FLAG_USE_SERIALIZER_BROADCAST to enable this
     * feature.
     */
    MAXIM_DESER_PROP_SERIALIZER_I2C_BROADCAST_ALIAS,
    /**
     * Write this property to start running a PRBS test on the deserializer.
     * The parameters of the test are set as a @c serdes_maxim_prbs_params_t*.
     * Note that this property is write-only, can only be set after having
     * called @c serdes_init_func_t and is only permitted when streaming is
     * not active.  Writing this parameter will block until the test has
     * completed.
     */
    MAXIM_DESER_PROP_START_PRBS,
    /*
     * Read-only property that indicates the result of the PRBS test that was
     * started in the last write to @c MAXIM_DESER_PROP_START_PRBS.  The value
     * read is of format @c serdes_maxim_prbs_results_t.
     */
    MAXIM_DESER_PROP_GET_PRBS_RESULTS,
    /**
     * Set this property to @c true to place deserializer in low power mode,
     * to @c false to place deserializer in normal power mode.  The value
     * is a @c bool.  This property is write-only and can only be set after
     * initialization has completed.
     */
    MAXIM_DESER_PROP_STANDBY
} serdes_maxim_deserializer_property_t;

/**
 * @brief Specific serializer properties support for Maxim serializers.
 * @details This extends the definitions of available serializer properties
 *          in @c serdes_serializer_property_t.
 */
typedef enum {
    /**
     * The I2C address of a secondary device that is accessible by the
     * serializer in addition to the sensor as a @c uint8_t value.  An I2C
     * alias can be assigned to this device.
     */
    MAXIM_SER_PROP_DEVICE_I2C_ADDR = SER_PROP_VENDOR_SPECIFIC,
    /**
     * The alias I2C address to assign to the secondary device as a @c uint8_t
     * value.
     */
    MAXIM_SER_PROP_DEVICE_I2C_ALIAS,
    /**
     * The number of pixel clock cycles of delay to insert between the VSYNC
     * edge to the rising edge of the first HSYNC as a @c uint32_t value.
     */
    MAXIM_SER_PROP_HSYNC_DELAY,
    /**
     * The width of the high portion of the HSYNC in number of pixel clock
     * cycles as a @c uint16_t value.  This corresponds to the number of
     * active pixels in a line.
     */
    MAXIM_SER_PROP_HSYNC_HIGH_PERIOD,
    /**
     * The width of the low portion of the HSYNC in number of pixel clock
     * cycles as a @c uint16_t value.  This corresponds to the number of
     * non-active pixels in a line.
     */
    MAXIM_SER_PROP_HSYNC_LOW_PERIOD,
    /**
     * The number of HSYNC pulses in an image as a @c uint16_t value.
     * This corresponds to the number of lines in the image.
     */
    MAXIM_SER_PROP_HSYNC_COUNT,
    /**
     * The number of pixel clock cycles of delay to insert between the input
     * VSYNC from the sensor and the generated vsync as a @c uint32_t value.
     */
    MAXIM_SER_PROP_VSYNC_DELAY,
    /**
     * The width of the high portion of the VSYNC in number of pixel clock
     * cycles as a @c uint32_t value.  This corresponds to all active lines in
     * the image.
     */
    MAXIM_SER_PROP_VSYNC_HIGH_PERIOD,
    /**
     * The width of the low portion of the VSYNC in number of pixel clock
     * cycles as a @c uint32_t value.  This corresponds all vertical blanking
     * lines in the image.
     */
    MAXIM_SER_PROP_VSYNC_LOW_PERIOD,
    /**
     * The serializer crossbar configuration for a given serializer input as a
     * @c serdes_maxim_crossbar_t* value.  This property is write-only.  If not
     * configured, the default pin assignments to crossbar outputs will be
     * used.
     */
    MAXIM_SER_PROP_CROSSBAR,
    /**
     * Set this property to @c true to perform a re-initialization
     * of the serializer in case the link was disconnected.  The value
     * is a @c bool.  This property is write-only and can only be set after
     * initialization has completed.
     */
    MAXIM_SER_PROP_REINIT,
    /**
     * Was the initialization completed successfully on this serializer as a
     * @c bool value.  This is a read-only parameter that can be used to detect
     * configured links that failed initialization; most likely cause would be
     * for the link being disconnected.
     */
    MAXIM_SER_PROP_INIT_COMPLETE,
    /**
     * Set this property to non-zero value to manually enable the link of the
     * serializer.  The value specified indicates the number of retries.  The
     * value is a @c uint8_t.  This property is write-only and can only be set
     * after initialization has completed.
     */
    MAXIM_SER_PROP_ENABLE,
    /**
     * Set this property to non-zero value to manually disable the link of the
     * serializer.  The value specified indicates the number of retries.  The
     * value is a @c uint8_t.  This property is write-only and can only be set
     * after initialization has completed.
     */
    MAXIM_SER_PROP_DISABLE,
    /**
     * Set this property to @c true to place serializer in low power mode,
     * to @c false to place serializer in normal power mode.  The value
     * is a @c bool.  This property is write-only and can only be set after
     * initialization has completed.
     */
    MAXIM_SER_PROP_STANDBY,
    /**
     * This property is @c true if the serializer was detected during the
     * presence check, @false otherwise.  This property is a @c bool, read-only
     * and can only be read after having called @c serdes_init_func_t().
     */
    MAXIM_SER_PROP_PRESENCE_SKIP,
    /**
     * Spread-spectrum setting.
     */
    MAXIM_SER_PROP_SPREAD_SPECTRUM,
    /**
     * Preemphasis level setting.
     */
    MAXIM_SER_PROP_PREEMPHASIS_LEVEL
} serdes_maxim_serializer_property_t;

#ifdef __cplusplus
}
#endif
#endif   /* __SERDES_MAXIM_API_H__ */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL$ $Rev$")
#endif
