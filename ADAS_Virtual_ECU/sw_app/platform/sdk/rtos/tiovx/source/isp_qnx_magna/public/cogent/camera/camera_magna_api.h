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
 * @file camera_magna_api.h
 *
 * @brief This file defines functions and data structures for Magna specifics APIs.
 *
 *
 */

#ifndef _CAMERA_MAGNA_API_H_
#define _CAMERA_MAGNA_API_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <camera/camera_api.h>

#define MAGNA_CAMERA_DEFAULT_FRAME_RATE     30

/**
 * The camera power mode
 */
typedef enum {
    /**
     * To turn camera power on.
     */
    CAMERA_POWER_ON,
    /**
     * To turn camera power off.
     */
    CAMERA_POWER_OFF,
    /**
     * Move camera to standby mode.
     */
    CAMERA_STANDBY_ON,
    /**
     * Wake up camera from standby mode.
     */
    CAMERA_STANDBY_OFF

} camera_power_mode_t;

/**
 * The camera reconnect mode
 */
typedef enum {
    /**
     * To enable auto-reconnection mode for the camera.
     * In this mode sensor service restores streaming from camera
     * after losing and restoring connection to it.
     */
    CAMERA_RECONNECT_ENABLED,
    /**
     * To disable auto-reconnection mode for the camera.
     * In this mode sensor service doesn't attempt to restore streaming
     * from camera after losing conenction to it.
     */
    CAMERA_RECONNECT_DISABLED
} camera_reconnect_mode_t;

/**
 * The results of the Pseudorandom binary sequence (PRBS) test.
 * This test verifies the integrity of the data path between the deserializer
 * and serializers and reports back errors encountered when running the test.
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
} camera_prbs_results_t;

/**
 * The PRBS test type
 */
typedef enum {
    /**
     * Use MAX9249, MAX9259-MAX9265 and MAX9275-MAX9293
     * compatible PRBS test.
     */
    CAMERA_PRBS_LEGACY_MODE,
    /**
     * Use MAX9271-MAX9273 compatible PRBS test.
     */
    CAMERA_PRBS_MAX9271_MODE
} camera_prbs_type_t;

/**
 * The camera viewfinder warning type
 */
typedef enum {
    /**
     * For internal use only. Do not use.
     */
    CAMERA_WARNING_NONE,
    /**
     * Failed to process frame by Cogent library.
     */
    CAMERA_WARNING_PROCESS_FRAME,
    /**
     * Failed to update the ISP settings.
     */
    CAMERA_WARNING_UPDATE_ISP,
    /**
     * Failed to update the camera sensor settings.
     */
    CAMERA_WARNING_UPDATE_SENSOR,
    /**
     * Failed to update the camera sensor register table.
     */
    CAMERA_WARNING_UPDATE_SENSOR_REG_TABLE,
    /**
     * Failed to read deserializer status registers.
     */
    CAMERA_WARNING_READ_DESER_STATUS,
    /**
     * Failed to get embedded statistics from the camera sensor.
     */
    CAMERA_WARNING_GET_EMBEDDED_STATS,
    /**
     * Failed to recover streaming from the camera sensor.
     */
    CAMERA_WARNING_RECOVERY_SENSOR_STREAMING,
    /**
     * Failed to re-enable the camera serializer link.
     */
    CAMERA_WARNING_SER_RESTART_STREAMING
} camera_viewfinder_warning_type_t;

/**
 * Camera output frame rate denominator.
 */
typedef enum {
    CAMERA_FR_DENOMINATOR_30_FPS = 1,
    CAMERA_FR_DENOMINATOR_15_FPS = 2,
    CAMERA_FR_DENOMINATOR_10_FPS = 3,
    CAMERA_FR_DENOMINATOR_5_FPS  = 6
} camera_frame_rate_denominator_t;

/**
 * @brief Set camera power mode.
 * @details Allows client to turn on/off cameras.
 *
 * @note The streaming from camera should be stopped when calling this API.
 *
 * @param handle The handle returned by a call to @c camera_open().
 * @param power_mode The power mode value (see @c camera_power_mode_t for detail)
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_power_mode(camera_handle_t handle, camera_power_mode_t power_mode);

/**
 * @brief Set camera reconnect mode.
 * @details Allows client to change reconnect mode for the camera.
 *
 * @note The streaming from camera should be stopped when calling this API.
 *
 * @param handle The handle returned by a call to @c camera_open().
 * @param reconnect_mode The reconnect mode value (see @c camera_reconnect_mode_t for detail)
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_reconnect_mode(camera_handle_t handle, camera_reconnect_mode_t reconnect_mode);

/**
 * @brief Run PRBS test.
 * @details Permits to have the deserializer associated with the camera to run
 *          a pseudorandom binary sequence (PRBS) test. This permits to verify
 *          the integrity of the serial links between the deserializer and all associated serializer.
 *
 * @note The streaming from all associated cameras with this deserializer must be stopped
 *       (call @c camera_stop_viewfinder() if running) before running this test.
 *
 * @param handle The handle returned by a call to @c camera_open().
 * @param type The PRBS test type (see @c camera_prbs_type_t for detail)
 * @param testInterval The interval in microseconds for PRBS test. The max supported interval is 30 sec.
 * @param res Results of the PRBS test (see @c camera_prbs_results_t for detail)
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_run_prbs_test(camera_handle_t handle, camera_prbs_type_t type, uint32_t testInterval, camera_prbs_results_t* res);

/**
 * @brief Set deserializer parameters.
 * @details Allows clients to provide settings for deserialzer
 *
 * @note The streaming from all associated cameras with this deserializer should be stopped
 *       (call @c camera_stop_viewfinder() if running) before calling this API.
 *
 * @param handle The handle returned by a call to @c camera_open().
 * @param type The deserializer parameter type (see @c serdes_maxim_deserializer_property_t for detail)
 * @param deserParam The deserializer parameter value. Please see @c serdes_maxim_deserializer_property_t for
 *                   the appropriate structure to use based on the value of @c type
 * @param size The size of the structure pointed to by @c param in bytes.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_deserializer_param(camera_handle_t handle, int type, void* deserParam, size_t size);

/**
 * @brief Set camera serializer parameters.
 * @details Allows clients to provide settings for camera serialzer
 *
 * @note The streaming from camera should be stopped when calling this API.
 *
 * @param handle The handle returned by a call to @c camera_open().
 * @param type The serializer parameter type (see @c serdes_maxim_serializer_property_t for detail)
 * @param serParam The deserializer parameter value. Please see @c serdes_maxim_serializer_property_t for
 *                 the appropriate structure to use based on the value of @c type
 * @param size The size of the structure pointed to by @c param in bytes.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_serializer_param(camera_handle_t handle, int type, void* serParam, size_t size);

#ifdef __cplusplus
}
#endif
#endif /* _CAMERA_MAGNA_API_H_ */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/camapi/public/camera/camera_magna_api.h $ $Rev: 899560 $")
#endif
