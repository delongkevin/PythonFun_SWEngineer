/*
 * $QNXLicenseC:
 * Copyright 2018, QNX Software Systems. All Rights Reserved.
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
 * @file external_camera_api.h
 *
 * @brief The definitions and functions to use the External Camera library.
 *
 *        The cameras that this library works with must be configured
 *        in the sensors configuration file that's loaded by the
 *        Sensor service.
 *
 */

#ifndef __EXTERNAL_CAMERA_API_H__
#define __EXTERNAL_CAMERA_API_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <screen/screen.h>
#include <sys/siginfo.h>
#include <camera/camera_api.h>
#include <camera/camera_3a.h>
#include <sensor/sensor_api.h>

/**
 * This structure is used to keep information about buffers,
 * which will be used for preview.
 */
typedef struct {
    /**
     * The number of buffers in list.
     */
    uint32_t                        num;
    /**
     * The list of buffer's physical addresses.
     */
    off_t *                         physical_addrs;
    /**
     * The list of buffer's virtual addresses.
     */
    void **                         virtual_addrs;
    /**
     * The list of buffer's screen addresses.
     */
    screen_buffer_t *               screen_addrs;
    /**
     * The list of buffer's sizes in bytes.
     */
    uint64_t *                      sizes;
    /**
     * The list of buffer's widths in pixels.
     */
    int *                           widths;
    /**
     * The list of buffer's heights in pixels.
     */
    int *                           heights;
} camera_buffer_list_t;

/**
 * This structure represents camera preview parameters.
 */
typedef struct {
    /**
     * The preview buffer height in pixels.
     */
    uint16_t                        preview_height;
    /**
     * The preview buffer width in pixels.
     */
    uint16_t                        preview_width;
    /**
     * The preview buffer stride in bytes.
     */
    uint32_t                        preview_stride;
    /**
     * The preview frame type. See @c camera_frametype_t for more information.
     */
    camera_frametype_t              preview_frametype;
    /**
     * The frame rate expressed in Q16 format.
     */
    uint32_t                        framerate_q16;
    /**
     * The zoom level
     */
    uint32_t                        zoom_level;
    /**
     * The image rotation angle value, in degrees.
     * Rotation angles are measured in a clockwise direction.
     */
    uint32_t                        rotation;
} camera_preview_params_t;

/**
 * This structure represents camera preview frame status.
 */
typedef struct {
    /**
     * This value is @c true if a preview frame was captured;
     * otherwise, it is set to @c false for initial pipelining.
     */
    bool captured;
    /**
     * This value is @c true if the input buffer provided wasn't consumed by
     * the ISP and should be freed; otherwise @c false.
     */
    bool freeInputBuffer;
    /**
     * This value specifies the number of bytes of data in the buffer.
     * This value is used for compressed camera frame types.
     */
    uint32_t filledSize;
    /**
     * For internal use only. Do not use.
     */
    uint32_t internal;
} camera_preview_frame_flags_t;

/**
 * This @c enum is used for array index of frame rates for the function
 * @c get_supported_vf_frame_rates() when @c isMaxMin is set to @c true.
 */
typedef enum {
    /** The maximum frame rate. **/
    CAMERA_VF_FRAMERATE_MAX_INDEX = 0,
     /** The minimum frame rate. **/
    CAMERA_VF_FRAMERATE_MIN_INDEX
} camera_vf_framerate_min_max_index_t;

/**
 * This @c enum is used to indicate the type of ISP configuration that is being
 * configured.
 */
typedef enum {
    /**
     * Renesas V3x ISP white balance configuration.
     */
    ISP_CONFIG_V3X_WHITEBALANCE,
    /**
     * Renesas V3x ISP vision mode configuration.
     */
    ISP_CONFIG_V3X_VISION_MODE,
    /**
     * Renesas V3x ISP runtime AE mode configuration.
     */
    ISP_CONFIG_V3X_RUNTIME_AE_MODE,
    /**
     * Renesas V3x ISP runtime AWB mode configuration.
     */
    ISP_CONFIG_V3X_RUNTIME_AWB_MODE,
    /**
     * Renesas V3x ISP WB Cfg mode configuration.
     */
    ISP_CONFIG_V3X_WB_CFG_MODE,
    /**
     * Renesas V3x ISP Gamma Cfg mode configuration.
     */
    ISP_CONFIG_V3X_GAMMA_CFG_MODE,
    /**
     * Renesas V3x ISP Gamma Cfg Lut configuration.
     */
    ISP_CONFIG_V3X_GAMMA_CFG_LUT,
    /**
     * Renesas V3x ISP Radial Shading mode configuration.
     */
    ISP_CONFIG_V3X_RADIAL_SHADING_CFG_MODE,
    /**
     * Renesas V3x ISP Sinter Cfg mode configuration.
     */
    ISP_CONFIG_V3X_SINTER_CFG_MODE,
    /**
     * Renesas V3x ISP Sharp Strength configuration.
     */
    ISP_CONFIG_V3X_SHARP_STRENGTH,
    /**
     * Renesas V3x ISP Tone Map Cfg mode configuration.
     */
    ISP_CONFIG_V3X_TONE_MAP_CFG_MODE,
    /**
     * Renesas V3X ISP Stats Roi configuration.
     */
    ISP_CONFIG_SET_STATS_ROI,
    /**
     * Renesas V3X camera parameters to calculate ISP Stats Roi.
     */
    ISP_CONFIG_CAMERA_PARAMS_FOR_STATS_ROI,
    /**
     * Renesas V3X camera parameters to skip one context switch.
     */
    ISP_CONFIG_SKIP_CONTEXT_SWITCH,
    /**
     * To notify the V3X ISP to dump the next possible raw input frame.
     * The frame would be dumped exactly as the ISP receives it, so it
     * might be padded to be aligned.
     */
    ISP_CONFIG_DUMP_RAW_INPUT_FRAME,
    /**
     * To configure the V3X ISP brightness and contrast step.
     */
    ISP_CONFIG_BRIGHTNESS_CONTRAST_STEP
} camera_isp_config_type_t;

/**
 * @brief Request a handle to access an external camera
 * @details If the camera is available, a handle for access to the camera
 *          is returned.
 *
 * @param input The camera input parsed from the configuration file.
 *
 * @return A pointer to the returned camera handle if access is granted.
 */
typedef void* (*open_external_camera_func_t)(uint32_t input);

/**
 * @brief Discontinue use of an external camera on the device
 *
 * @details Any internal resources associated with a previously
 *          opened camera are freed.
 *
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 */
typedef void (*close_external_camera_func_t)(void* handle);

/**
 * @brief Initialize external camera
 * @details Perform any required initialization of the external camera.
 *
 * @param handle The handle that's returned from calling the function
 *               @c open_external_camera_func_t.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*init_camera_func_t)(void* handle);

/**
 * @brief Deinitialize external camera
 * @details Do any required deinitialization of the external camera.
 *
 * @param handle The handle that's returned from calling the function
 *        @c open_external_camera_func_t.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*deinit_camera_func_t)(void* handle);

/**
 * @brief Start preview (viewfinder) in the mode you want
 * @details Call this function when preview mode should be started.
 *          This function configures the camera to start
 *          producing preview frames that are consumed by an
 *          upper-layer thread, which repeatedly calls into the blocking
 *          function @c get_preview_frame_func_t.
 *
 * @note Some cameras need to know  of all buffers
 *       that will be used prior to starting the
 *       preview in order to pre-map buffers or due to
 *       restrictions in the underlying Aamera API.
 *       For this reason, a complete @c buflist is provided
 *       when preview mode starts.
 *
 * @param handle The handle that's returned from calling the function
 *               @c open_external_camera_func_t.
 * @param params A set of preview parameters (e.g., resolution, rotation,
 *              frame rate).
 * @param buflist A complete list of the buffers which will be used for preview.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*start_preview_func_t)(void* handle, camera_preview_params_t* params,
                                camera_buffer_list_t* buflist);
/**
 * @brief Stops a running preview (viewfinder)
 * @details This function is invoked when the Sensor service needs to stop the
 *          viewfinder.
 *
 * @param handle The handle that's returned from calling the function
 *               @c open_external_camera_func_t.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*stop_preview_func_t)(void* handle);

/**
 * @brief Retrieves the next available preview frame
 * @details This is the main interface between the preview thread and the
 *          camera. The Sensor service runs the preview thread that repeatedly
 *          calls into @c get_preview_frame_func_t to receive the next available
 *          frame from the camera. This operation both enqueues empty buffers
 *          for use by the camera (i.e., to pipeline) and expects to receive
 *          filled buffers back from the camera. If the camera's hardware
 *          requires pipelining, this function doesn't return any new frames
 *          until enough empty buffers have been supplied.
 *
 * @note This function call is blocking when the camera is fully pipelined.
 *
 * @param handle The handle that's returned from calling the function
 *               @c open_external_camera_func_t.
 * @param bufferIn An empty buffer to feed in to the camera to be filled now
 *                 or in the future.
 * @param flags The returned flags. See @c ::camera_preview_frame_flags_t for
 *              information.
 * @param bufferOut The newly acquired preview image data.
 * @param timestamp The returned timestamp, which indicates the capture time of
 *                  the preview frame. The clock is measured in microseconds and
 *                  is in the sensor time domain. See @c get_time_func_t for more
 *                  information.
 * @param metaOut The returned metadata associated with this preview frame.
 * @param metaSize A pointer to value passed in as @c metaSize indicates
 *                 the maximum space available in the @c metaOut buffer.
 *                 The value returned indicates how much space
 *                 was actually populated with metadata  (e.g., 64k in, 1k out).
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*get_preview_frame_func_t)(void* handle, void* bufferIn, camera_preview_frame_flags_t *flags,
                                   void** bufferOut, int64_t *timestamp, void* metaOut,
                                   uint64_t *metaSize);

 /**
 * @brief Determine the number of required preview buffers that the camera
 *        requires
 * @details When allocating buffers, the platform may call this function to
 *          determine how many preview buffers need to be allocated for the
 *          specified viewfinder type.  The platform adds to this number the
 *          additional number of buffers required by other parts of the system.
 *
 * @param handle The handle that's returned from calling the function @c open_external_camera_func_t.
 *
 * @return The number of preview buffers required for this camera.
 */
typedef int (*get_preview_num_buffers_func_t)(void* handle);

/**
 * @brief Retrieve the list of supported viewfinder frame types
 * @details This function returns a list of the supported viewfinder frame types
 *          for the specified camera (eg. NV12, RGB, etc.).
 *
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 * @param numTypes Need to be set to the number of viewfinder frame types
 *                 supported by the camera.
 * @param types Array to fill with the supported frame types.
 *
 * @return @c CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*get_supported_vf_frametypes_func_t)(void* handle, int *numTypes,
                                                 camera_frametype_t* types);

/**
 * @brief Return the list of supported viewfinder resolutions
 * @details This function returns a list of the supported viewfinder
 *          resolutions for the specified camera frame type
 *
 * @param handle The handle that's returned from calling the function
 *               @c open_external_camera_func_t.
 * @param frametype The frame type to be used for the requested resolutions.
 * @param numsupported The returned number of entries in the resolutions list.
 * @param resolutions The returned list of supported resolutions.
 *
 * @return @c #CAMERA_EOK  when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*get_supported_vf_resolutions_func_t)(void* handle, camera_frametype_t frametype,
                                                  int *numsupported, const camera_res_t** resolutions);

/**
 * @brief Retrieve the list of supported viewfinder frame rates
 * @details The viewfinder is capable of operating at different frame rates.
 *          This function retrieves the list of supported frame rates for the
 *          specified camera for a given frame type and resolution. Note that
 *          the fractional precision of each supported frame rate shouldn't
 *          exceed 3 digits of precision.
 *
 * @param handle The handle that's returned from calling the function
 *               @c open_external_camera_func_t.
 * @param resolution The resolution associated with this query.
 * @param frametype The frame type associated with this query
 * @param numRates Needs to be set to the number of viewfinder frame rates
 *                 supported.
 * @param isMaxMin Need to be set to @c true if the rates provided represents
 *                 a range of value between a minimum and a maximum; need to set
 *                 to @c @c false if the rates provided represent the list of
 *                 individual rates supported.
 * @param rates Array to fill with the supported frame rates; if @c isMaxMin
 *              is set to @c true, use array index defined in
 *              @c ::camera_vf_framerate_min_max_index_t for the minimum and
 *              maximum values; if @c isMaxMin is set to @c false, set the
 *              individual frame rates that are supported up to 100 entries.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*get_supported_vf_framerates_func_t)(void* handle,
                                                 camera_res_t *resolution,
                                                 camera_frametype_t frametype,
                                                 int* numRates,
                                                 bool* isMaxMin,
                                                 float* rates);

/**
 * @brief Retrieve the current camera time
 * @details This function returns  the current time value
 *          in the camera time domain in microseconds.
 *          The time domain used here must be the same one as the
 *          one used to fill the timestamp in @c get_preview_frame_func_t.
 *
 * @note This function is optional.
 *       If this function isn't specified, the
 *       default implementation uses @c CLOCK_MONOTONIC.
 *
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 *
 * @return The current sensor time in microseconds.
 */
typedef int64_t (*get_time_func_t)(void* handle);

/**
 * @brief Parse a camera specific attribute from the configuration file
 * @details This function is called for each attribute associated
 *          with the camera in the configuration file.
 *
 * @note This function is optional. This function is called before the function
 *       @c init_camera_func_t.
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 * @param name  The name of camera attribute.
 * @param value The value of camera attribute.
 *
 * @return @c #CAMERA_EOK if the attribute was parsed successfully by the sensor,
 *         @c #CAMERA_ENOTSUPP if the attribute is not a camera-specific attribute,
 *         another @c ::camera_error_t value if any errors encountered in
 *         the parsing of the attribute.
 */
typedef int (*parse_config_func_t)(void* handle, char* name, char* value);

/**
 * @brief Adjust the preview frame rate
 * @details Change the current frame rate for a running preview.
 *
 * @note This function is optional. If it is not present,
 *       set framerate will not be supported for this camera.
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 * @param framerate_q16 The frame rate you want expressed in Q16 format.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*set_framerate_func_t)(void* handle, uint32_t framerate_q16);

/**
 * @brief Get the current frame rate
 * @details Retrieve the currently configured preview frame rate.
 *
 * @note This function is optional. If it is not present,
 *       get framerate will not be supported for this camera.
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 * @param framerate_q16 The returned frame rate expressed in Q16 format.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*get_framerate_func_t)(void* handle, uint32_t* framerate_q16);

/**
 * @brief Callback to notify subscribers about stream status changes.
 * @details The function that would be called when ISP library
 *          needs to notify subscribers changes in stream status.
 *
 * @param unit The sensor unit this camera corresponds to.
 * @param status New status of the stream
 * @param statusextra Extra information to provide more details about the
 *                    status change.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*status_callback)(sensor_unit_t unit, sensor_devstatus_t status, uint16_t extra);

/**
 * @brief Set callback to notify subscribers about stream status changes.
 * @details Register a function that would be called when ISP library
 *          needs to notify subscribers changes in stream status.
 *
 * @note This function is optional. If it is not present,
 *       status callback will not be provided by this camera.
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 * @param unit The sensor unit this camera corresponds to.
 * @param func The function that would be called by the ISP
 *             library to notify subscribers about status changes.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*register_status_callback_t)(void* handle, sensor_unit_t unit, status_callback func);

/**
 * @brief Restart preview for a given camera handle.
 * @details This function is called to recover streaming for a camera that was previously unplugged.
 *
 * @note This function is optional. If it is not present,
 *       restart preview will not be supported for this camera.
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*restart_preview_t)(void* handle);

/**
 * @brief Set a new configuration for the ISP.
 * @details Dynamically updates a given aspect of the ISP configuration.
 *          Different configurations are supported by different ISP.  Implement
 *          this function if the ISP does support dynamic updates to at least
 *          a given type of configuration.
 *
 * @note This function is optional. If it is not present, dynamic ISP
 *       configuration will not be supported for this camera.
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 * @param unit The sensor unit this camera corresponds to.
 * @param type The type of configuration that is desired to be set.
 * @param config Pointer to configuration to be set.  The structure associated
 *               with this configuration is dependent on @c type.
 *
 * @return @c #CAMERA_EOK when the function successfully completes,
 *         @c #CAMERA_EOPNOTSUPP if this configuration is not supported,
 *         otherwise another @c ::camera_error_t value that provides the reason
 *         that the call failed.
 */
typedef int (*set_isp_config_func_t)(void* handle,
                                     sensor_unit_t unit,
                                     camera_isp_config_type_t type,
                                     void* config);

/**
 * @brief Retrieve the set of supported brightness values
 * @details This function is used to retrieve the set of supported brightness
 *          values.
 *
 * @note This function is optional. If it is not present,
 *       get supported brightness will not be supported for this camera.
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 * @param minBrightness The returned minimal supported brightness value.
 * @param maxBrightness The returned maximal supported brightness value.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*get_supported_brightness_func_t)(void* handle,
                                               int32_t* minBrightness,
                                               int32_t* maxBrightness);

/**
 * @brief Adjust the brightness value
 * @details Change the current brightness value for a defined camera.
 *
 * @note This function is optional. If it is not present,
 *       set brightness will not be supported for this camera.
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 * @param brightness The brightness value.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*set_brightness_func_t)(void* handle, int32_t brightness);

/**
 * @brief Retrieve the set of supported contrast values
 * @details This function is used to retrieve the set of supported contrast
 *          values.
 *
 * @note This function is optional. If it is not present,
 *       get supported contrast will not be supported for this camera.
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 * @param minContrast The returned minimal supported contrast value.
 * @param maxContrast The returned maximal supported contrast value.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*get_supported_contrast_func_t)(void* handle,
                                             int32_t* minContrast,
                                             int32_t* maxContrast);

/**
 * @brief Adjust the contrast value
 * @details Change the current contrast value for a defined camera.
 *
 * @note This function is optional. If it is not present,
 *       set contrast will not be supported for this camera.
 * @param handle The handle that's returned from calling the
 *               function @c open_external_camera_func_t.
 * @param contrast The contrast value.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*set_contrast_func_t)(void* handle, int32_t contrast);

/**
 * @brief Set camera sensor into standby mode
 * @details Places the camera sensor in a low power mode.
 *
 * @note This function is optional. If it is not present,
 *       set standby mode will not be supported for this camera.
 * @param handle The handle that's returned from calling the function
 *               @c open_external_camera_func_t.
 * @param enableStandbyMode If true then place sensor in a low power mode.
 *                          If false then place sensor in a normal power mode.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*set_standby_mode_func_t)(void* handle, bool enableStandbyMode);

/**
 *  @brief Query if the specified white balance mode is valid
 *  @details This function is used to determine if a white balance mode is
 *           supported prior to calling @c set_whitebalance_mode_func_t().
 *
 * @note This function is optional. If it is not present,
 *       set standby mode will not be supported for this camera.
 * @param handle The handle that's returned from calling the function
 *               @c open_external_camera_func_t.
 * @param mode The white balance mode to query.
 *
 * @return @c true if @c mode is supported, false otherwise
 */
typedef bool (*is_whitebalance_mode_valid_func_t)(void* handle,
                                                  camera_whitebalancemode_t mode);

/**
 * @brief Sets the white balance mode to that specified
 * @details This function is used to set a new white balance mode.
 *
 * @note This function is optional. If it is not present,
 *       set standby mode will not be supported for this camera.
 * @param handle The handle that's returned from calling the function
 *               @c open_external_camera_func_t.
 * @param mode The white balance mode to set.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*set_whitebalance_mode_func_t)(void* handle,
                                            camera_whitebalancemode_t mode);

/**
 * @brief Retrieve the set of supported white balance values
 * @details This function is used to retrieve the set of supported white
 *          balance values.
 *
 * @note This function is optional. If it is not present, get supported white
 *       balance values will not be supported for this camera.
 * @param handle The handle that's returned from calling the function
 *               @c open_external_camera_func_t.
 * @param minWbVal The returned minimal supported white balance value.
 * @param maxWbVal The returned maximal supported white balance value.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*get_supported_whitebalance_func_t)(void* handle,
                                                 unsigned* minWbVal,
                                                 unsigned* maxWbVal);

/**
 * @brief Set the white balance value
 * @details Changes the current white balance value for a defined camera.
 *
 * @note This function is optional. If it is not present, set white balance
 *       will not be supported for this camera.
 * @param handle The handle that's returned from calling the function
 *               @c open_external_camera_func_t.
 * @param wbVal The white balance value to set (in Kelvin).
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*set_whitebalance_func_t)(void* handle, unsigned wbVal);

/**
 * @brief Retrieves the currently set white balance value
 * @details Returns the current white balance value in Kelvin. This is either
 *          the determined auto-white balance value or the one applied
 *          manually with @c set_whitebalance_func_t().
 *
 * @note This function is optional. If it is not present, set white balance
 *       will not be supported for this camera.
 * @param handle The handle that's returned from calling the function
 *               @c open_external_camera_func_t.
 * @param wbVal A pointer to @c unsigned that will be set to the current
 *              white balance value.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
typedef int (*get_whitebalance_func_t)(void* handle, unsigned* wbVal);

/**
 * Bit flags indicating the presence of some optional functions.
 */
typedef enum {
    /**
     * Flag indicates the presence of @c is_whitebalance_mode_valid.
     */
    IS_WHITEBALANCE_MODE_VALID_FUNC_FLAG = (1 << 0),
    /**
     * Flag indicates the presence of @c set_whitebalance_mode.
     */
    SET_WHITEBALANCE_MODE_FUNC_FLAG = (1 << 1),
    /**
     * Flag indicates the presence of @c get_supported_whitebalance.
     */
    GET_SUPPORTED_WHITEBALANCE_FUNC_FLAG = (1 << 2),
    /**
     * Flag indicates the presence of @c set_whitebalance.
     */
    SET_WHITEBALANCE_FUNC_FLAG = (1 << 3),
    /**
     * Flag indiciates the presence of @c get_whitebalance.
     */
    GET_WHITEBALANCE_FUNC_FLAG = (1 << 4)
} optional_function_flags_t;

/**
 * @brief Functions that must be implemented by an external camera library
 * @details The external camera library must define an instance of this structure
 *          named @c external_camera_defs that the Sensor service will use to
 *          interface with the camera driver.
*/
typedef struct {
    /** A function pointer. For more information, see @c open_external_camera_funct_t().
    */
    open_external_camera_func_t                open;

    /** A function pointer. For more information, see @c close_external_camera_func_t().
    */
    close_external_camera_func_t               close;

    /** A function pointer. For more information, see @c init_camera_func_t().
    */
    init_camera_func_t                         init;

    /** A function pointer. For more information, see @c deinit_camera_func_t().
    */
    deinit_camera_func_t                       deinit;

    /** A function pointer. For more information, see @c start_preview_func_t()
    */
    start_preview_func_t                       start_preview;

    /** A function pointer. For more information, see @c stop_preview_func_t().
    */
    stop_preview_func_t                        stop_preview;

    /** A function pointer. For more information, see @c get_preview_frame_func_t().
    */
    get_preview_frame_func_t                   get_preview_frame;

    /** A function pointer. For more information, see @c get_preview_num_buffers_func_t().
    */
    get_preview_num_buffers_func_t             get_preview_num_buffers;

    /** A function pointer. For more information, see @c get_supported_vf_frametypes_func_t().
    */
    get_supported_vf_frametypes_func_t         get_supported_vf_frametype;

    /** A function pointer. For more information, see @c get_supported_vf_resolutions_func_t)().
    */
    get_supported_vf_resolutions_func_t        get_supported_vf_resolution;

    /** A function pointer. For more information, see @c get_supported_vf_framerates_func_t().
    */
    get_supported_vf_framerates_func_t         get_supported_vf_framerates;

    /** A function pointer. For more information, see @c get_time_func_t().
    */
    get_time_func_t                            get_time;

    /** A function pointer. For more information, see @c set_framerate_func_t().
    */
    set_framerate_func_t                       set_framerate;

    /** A function pointer. For more information, see @c get_framerate_func_t().
    */
    get_framerate_func_t                       get_framerate;

    /** A function pointer. For more information, see @c parse_config_func_t().
    */
    parse_config_func_t                        parse_config;

    /** A function pointer. For more information, see @c register_status_callback_t().
    */
    register_status_callback_t                 register_status_callback;

    /** A function pointer. For more information, see @c restart_preview_t().
    */
    restart_preview_t                          restart_preview;

    /** A function pointer. For more information, see @c set_isp_config_func_t().
     */
    set_isp_config_func_t                      set_isp_config;

    /** A function pointer. For more information, see @c get_supported_brightness_func_t().
     */
    get_supported_brightness_func_t            get_supported_brightness;

    /** A function pointer. For more information, see @c set_brightness_func_t().
     */
    set_brightness_func_t                      set_brightness;

    /** A function pointer. For more information, see @c get_supported_contrast_func_t().
     */
    get_supported_contrast_func_t              get_supported_contrast;

    /** A function pointer. For more information, see @c set_contrast_func_t().
     */
    set_contrast_func_t                        set_contrast;

    /** A function pointer. For more information, see @c set_standby_mode_func_t().
     */
    set_standby_mode_func_t                    set_standby_mode;

    /** Bitfield indicating the presence of some optional functions. For more
     *  information see @c optional_function_flags_t.
     */
    uint64_t                                   optional_function_flags;

    /** A function pointer. For more information, see @c is_supported_whitebalance_mode_func_t().
     */
    is_whitebalance_mode_valid_func_t          is_whitebalance_mode_valid;

    /** A function pointer. For more information, see @c set_whitebalance_mode_func_t().
     */
    set_whitebalance_mode_func_t               set_whitebalance_mode;

    /** A function pointer. For more information, see @c get_supported_whitebalance_func_t().
     */
    get_supported_whitebalance_func_t          get_supported_whitebalance;

    /** A function pointer. For more information, see @c set_whitebalance_func_t().
     */
    set_whitebalance_func_t                    set_whitebalance;

    /** A function pointer. For more information, see @c get_whitebalance_func_t().
     */
    get_whitebalance_func_t                    get_whitebalance;
} camera_external_camera_t;

#ifdef __cplusplus
}
#endif
#endif   /* __EXTERNAL_CAMERA_API_H__ */


#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/camapi/public/camera/external_camera_api.h $ $Rev: 898410 $")
#endif
