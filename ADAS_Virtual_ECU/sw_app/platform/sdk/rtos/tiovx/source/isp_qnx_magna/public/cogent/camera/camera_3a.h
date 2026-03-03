#ifndef _CAMERA_3A_H_
#define _CAMERA_3A_H_

/*
 * $QNXLicenseC:
 * Copyright 2015-2017, QNX Software Systems. All Rights Reserved.
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
 * @file camera_3a.h
 *
 * @brief Contains enumerations and functions that permit the configuration of 3A
 *        algorithms (Auto Exposure, Auto White Balance, Auto Focus) for
 *        cameras that use the Camera Library.
 *
 * You can configure various manual settings (i.e., ISO, shutter
 * speed, white balance, and aperture) after you start the
 * viewfinder on the camera. Changes in settings may not be visible for several
 * frames due to latency in the image processing pipeline.
 *
 * For example, when you use an exposure mode (@c ::camera_exposuremode_t) that
 * has a manual component such as @c #CAMERA_EXPOSUREMODE_ISO_PRIORITY and you
 * change the ISO setting (@c camera_set_manual_iso()), you may not see the
 * results of the ISO change until several frames later.
 *
 * @note Cameras may not support all available manual settings. You should call
 *       the @c camera_get_exposure_modes() to determine which manual
 *       exposure settings can be adjusted.
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The state of the autofocus algorithm on the camera.
 */
typedef enum {
    /**
     * Autofocus is disabled or isn't available.
     */
    CAMERA_FOCUSSTATE_NONE = 0,
    /**
     * The system is waiting for the scene to stabilize before trying to focus.
     * Depending on the platform, this intermediate state may not get
     * reported.
     */
    CAMERA_FOCUSSTATE_WAITING,
    /**
     * The system is searching for an object to focus on.
     */
    CAMERA_FOCUSSTATE_SEARCHING,
    /**
     * The system has failed to focus.
     */
    CAMERA_FOCUSSTATE_FAILED,
    /**
     * The focus is successfully locked.
     */
    CAMERA_FOCUSSTATE_LOCKED,
    /**
     * The system detected a significant change in the scene.
     */
     CAMERA_FOCUSSTATE_SCENECHANGE
} camera_focusstate_t;


/**
 * The focus mode of the camera. Use @c camera_get_focus_modes() to determine
 * the focus modes that are supported by the current platform and camera.
 */
typedef enum {
    /**
     * Focus is disabled.
     */
    CAMERA_FOCUSMODE_OFF = 0,
    /**
     * The camera is using extended depth of field (EDoF) focus
     * mode.
     */
    CAMERA_FOCUSMODE_EDOF,
    /**
     * The camera is using manual focus mode.
     */
    CAMERA_FOCUSMODE_MANUAL,
    /**
     * The camera is using single-cycle autofocus. Single-cycle
     * focus occurs once and then stops.
     */
    CAMERA_FOCUSMODE_AUTO,
    /**
     * The camera is using single-cycle macro autofocus.
     * Single-cycle focus occurs once and then stops.
     */
    CAMERA_FOCUSMODE_MACRO,
    /**
     * The camera is using continuous autofocus mode. The
     * autofocus algorithm restarts if the scene goes out of focus.
     */
    CAMERA_FOCUSMODE_CONTINUOUS_AUTO,
    /**
     * The camera is using continuous autofocus mode for macro-range subjects.
     * The autofocus algorithm restarts if the scene goes out of focus.
     */
    CAMERA_FOCUSMODE_CONTINUOUS_MACRO,
    /**
     * The total number of supported focus modes.
     */
    CAMERA_FOCUSMODE_NUMFOCUSMODES
} camera_focusmode_t;


/**
 * The exposure mode of the camera. You can use the
 * @c camera_get_exposure_modes() function to determine which modes are
 * supported by the current platform and camera.
 */
typedef enum {
    /**
     * The default exposure mode for the camera. Because not every camera supports
     * all exposure modes, @c CAMERA_EXPOSUREMODE_DEFAULT can always be used as
     * an alias to the best automatic exposure mode that's supported by the camera.
     */
    CAMERA_EXPOSUREMODE_DEFAULT,
    /**
     * Auto exposure is off.
     */
    CAMERA_EXPOSUREMODE_OFF,
    /**
     * Exposure is automatically adjusted by the camera by varying the
     * shutter speed, ISO value, and aperture value.
     */
    CAMERA_EXPOSUREMODE_AUTO,
    /**
     * Manual exposure mode.
     * The camera won't automatically adjust any of the exposure controls.
     * The shutter speed, ISO value, and aperture value must all be set
     * manually.
     */
    CAMERA_EXPOSUREMODE_MANUAL,
    /**
     * The ISO value must be manually set. The camera automatically adjusts
     * the shutter speed and aperture value.
     */
    CAMERA_EXPOSUREMODE_ISO_PRIORITY,
    /**
     * The shutter speed must be manually set. The camera automatically
     * adjusts the ISO value and aperture value.
     */
    CAMERA_EXPOSUREMODE_SHUTTER_PRIORITY,
    /**
     * The aperture value must be manually set. The camera automatically
     * adjusts the shutter speed and ISO value.
     */
    CAMERA_EXPOSUREMODE_APERTURE_PRIORITY,
    /**
     * The ISO value and shutter speed must be manually set. The camera
     * automatically adjusts the aperture value.
     */
    CAMERA_EXPOSUREMODE_ISO_SHUTTER_PRIORITY,
    /**
     * The ISO value and aperture value must be manually set. The camera
     * automatically adjusts the shutter speed.
     */
    CAMERA_EXPOSUREMODE_ISO_APERTURE_PRIORITY,
    /**
     * The shutter speed and aperture value must be manually set.
     * The camera automatically adjusts the ISO value.
     */
    CAMERA_EXPOSUREMODE_SHUTTER_APERTURE_PRIORITY,
    /**
     * The total number of exposure modes.
     */
    CAMERA_EXPOSUREMODE_NUMEXPOSUREMODES
} camera_exposuremode_t;


/**
 * The white balance mode of the camera. You can use the
 * @c camera_get_whitebalance_modes() function to determine which modes are
 * supported by the current platform and camera.
 */
typedef enum {
    /**
     * The default white balance mode. Because not every camera supports all
     * available white balance modes, @c CAMERA_WHITEBALANCEMODE_DEFAULT can be
     * used as an alias to select a valid white balance mode.
     */
    CAMERA_WHITEBALANCEMODE_DEFAULT,
    /**
     * Auto white balance is disabled.
     */
    CAMERA_WHITEBALANCEMODE_OFF,
    /**
     * Auto white balance is enabled and the white balance will
     * be automatically adjusted by the camera.
     */
    CAMERA_WHITEBALANCEMODE_AUTO,
    /**
     * White balance must be manually set in terms of color temperature.
     */
    CAMERA_WHITEBALANCEMODE_MANUAL,
    /**
     * White balance must be manually set in terms of red and blue gains.
     */
    CAMERA_WHITEBALANCEMODE_MANUAL_RB_GAIN,
    /**
     * Auto white balance is run once on the camera to adjust the white
     * balance based on current lighting conditions.  Once the adjustments
     * are made, no further adjustments are done and the same white balance
     * settings are used for the camera.  You can set this mode multiple times
     * to re-run this one-time adjustment.
     */
    CAMERA_WHITEBALANCEMODE_AUTO_ONCE,
    /**
     * The total number of white balance modes.
     */
    CAMERA_WHITEBALANCEMODE_NUMWHITEBALANCEMODES
} camera_whitebalancemode_t;


/**
 * The autofocus, auto exposure, and auto white balance algorithms (3A).
 * The values in this enumerated type are typically used as bitmasks
 * for use with the 3A functions to indicate which of the 3A algorithms
 * to apply.
 */
typedef enum {
    /**
     * No 3A algorithm.
     */
    CAMERA_3A_NONE = 0,
    /**
     * The autofocus algorithm.
     */
    CAMERA_3A_AUTOFOCUS =        1<<0,
    /**
     * The auto exposure algorithm.
     */
    CAMERA_3A_AUTOEXPOSURE =     1<<1,
    /**
     * The auto white balance algorithm.
     */
    CAMERA_3A_AUTOWHITEBALANCE = 1<<2
} camera_3a_t;


/**
 * @brief Retrieve the focus state of the camera
 * @details Determine the focus state and the region of focus.
 *          Typically, you call this function when a status event of type
 *          @c #CAMERA_STATUS_FOCUS_CHANGE is received.
 *
 *          The viewfinder must be running before using this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param state A pointer to a @c ::camera_focusstate_t value that will be
 *              updated with the focus state of the camera.
 * @param region A pointer to a @c ::camera_region_t value that will be updated
 *               with the region that the focus has locked to.
 *               This argument only returns valid data when @c state reports @c
 *               #CAMERA_FOCUSSTATE_LOCKED.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_focus_state(camera_handle_t handle,
                       camera_focusstate_t *state,
                       camera_region_t *region);


/**
 * @brief Configure the focus mode of the camera
 * @details You can use values defined by @c ::camera_focusmode_t to set the
 *          focus mode of the camera. Use @c camera_get_focus_modes() to
 *          determine the focus modes that are supported by the current
 *          camera.
 *
 *          The viewfinder must be running before using this function.
 *
 *          The focus mode is reset to default when the viewfinder is stopped.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param mode The focus mode to use.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_focus_mode(camera_handle_t handle,
                      camera_focusmode_t mode);


/**
 * @brief Retrieve the current focus mode of the camera
 * @details Use this function to determine the currently configured focus
 *          mode of the camera.
 *
 *          The viewfinder must be running before using this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param mode A pointer to a @c ::camera_focusmode_t value that will be updated
 *             with the current focus mode of the camera.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_focus_mode(camera_handle_t handle,
                      camera_focusmode_t *mode);


/**
 * @brief Retrieve the focus modes available on the camera
 * @details Use this function to retrieve the focus modes available on the
 *          current camera.
 *
 *          Ensure that the @c modes argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          modes argument to NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of focus modes to return in the
 *                 @c modes array. You can use a value of 0 to
 *                 determine the number of focus modes supported
 *                 by the camera.
 * @param numsupported The returned number of focus modes supported by the
 *                     camera.
 * @param modes A pointer to a @c ::camera_focusmode_t array. The array
 *              will be  updated with the focus modes supported by
 *              the camera. Ensure that you allocate an array with the
 *              same number of elements as specified in the @c numasked
 *              argument.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_focus_modes(camera_handle_t handle,
                       int numasked,
                       int *numsupported,
                       camera_focusmode_t *modes);


/**
 * @brief Configure the focus regions on the camera
 * @details When focus regions are defined, the autofocus algorithm will give
 *          priority to focusing on objects in the defined areas of the scene.
 *
 *          Only call this function if the @c #CAMERA_FEATURE_REGIONFOCUS
 *          feature is available. You can determine whether this feature is
 *          available by calling the @c camera_can_feature() function.
 *
 *          The maximum number of focus regions that you can configure is
 *          returned by the @c numsupported argument of the
 *          @c camera_get_focus_regions() function.
 *
 *          After setting the regions, you must call the @c
 *          camera_set_focus_mode() function to commit the changes.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numregions The number of regions to apply, which is the number of
 *                   elements in the @c regions array.
 * @param regions A pointer to an array of focus regions to apply. The region
 *                co-ordinates are interpreted relative to a viewfinder buffer
 *                with (0, 0) representing the top-left corner of the frame,
 *                and (width-1, height-1) representing the bottom-right corner.
 *                If @c #CAMERA_IMGPROP_ROTATION is applied to the viewfinder,
 *                then the co-ordinate frame of reference is also rotated
 *                accordingly.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_focus_regions(camera_handle_t handle,
                         int numregions,
                         camera_region_t *regions);


/**
 * @brief Retrieve the focus regions configured on the camera
 * @details Use this function to retrieve the configured autofocus
 *          regions from the camera. For more information on configuring focus
 *          regions, see @c camera_set_focus_regions().
 *          When focus regions are defined, the autofocus algorithm will give
 *          priority to focusing on objects in the defined areas of the scene.
 *
 *          The maximum number of supported focus regions is determined by
 *          checking the @c numsupported argument when the function completes
 *          successfully.
 *
 *          Ensure that the @c regions argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          regions argument to @c NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 *          The viewfinder must be running before using this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of regions to return in the @c regions
 *                 array. You can specify a value of 0 to determine the number
 *                 of focus regions supported by the camera.
 * @param numsupported A pointer to an integer that will be updated with the
 *                     number of focus regions supported by the camera.
 * @param numreturned A pointer to an integer that will be updated with the
 *                    number of focus regions returned in the @c regions array.
 * @param regions A pointer to a @c ::camera_region_t array. The array is
 *                updated with the focus regions configured on the camera.
 *                Ensure that you allocate an array with the same number of
 *                elements as the @c numasked argument.
 *                For more information about interpreting region geometry,
 *                see @c camera_set_focus_regions().
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_focus_regions(camera_handle_t handle,
                         int numasked,
                         int *numsupported,
                         int *numreturned,
                         camera_region_t *regions);


/**
 * @brief Configure the auto exposure regions on the camera
 * @details When exposure regions are defined, the auto exposure algorithm will
 *          give exposure priority to objects in the defined areas of the scene.
 *
 *          Call this function only if the @c #CAMERA_FEATURE_REGIONEXPOSURE
 *          feature is available. You can call @c camera_can_feature() to determine
 *          if the @c CAMERA_FEATURE_REGIONEXPOSURE is available.
 *
 *          The maximum number of exposure regions that you can configure is
 *          returned by the @c numsupported argument of the
 *          @c camera_get_exposure_regions() function.
 *
 *          After setting the regions, you must call the @c
 *          camera_set_exposure_mode() function to commit the changes.
 *
 *          The viewfinder must be running before using this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numregions The number of regions to apply, which is the number of
 *                   elements in the @c regions array.
 * @param regions A pointer to an array of exposure regions to apply. The region
 *                co-ordinates are interpreted relative to a viewfinder buffer
 *                with (0, 0) representing the top-left corner of the frame,
 *                and (width-1, height-1) representing the bottom-right corner.
 *                If @c #CAMERA_IMGPROP_ROTATION is applied to the viewfinder,
 *                then the co-ordinate frame of reference is also rotated
 *                accordingly.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_exposure_regions(camera_handle_t handle,
                            int numregions,
                            camera_region_t *regions);


/**
 * @brief Retrieve the exposure regions configured on the camera
 * @details Use this function to retrieve the configured auto exposure
 *          regions from the camera.  For more information on configuring
 *          exposure regions, see @c camera_set_exposure_regions().
 *          When exposure regions are defined, the auto exposure algorithm
 *          gives exposure priority to objects in the defined areas of the scene.
 *
 *          The maximum number of supported exposure regions is determined by
 *          checking the @c numsupported argument when the function completes
 *          successfully.
 *
 *          Ensure that the @c regions argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          regions argument to @c NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 *          The viewfinder must be running before using this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of regions to return in the @c regions
 *                 array. You can specify a value of 0 to determine the number
 *                 of focus regions supported by the camera.
 * @param numsupported A pointer to an integer that will be updated with the
 *                     number of exposure regions supported by the camera.
 * @param numreturned A pointer to an integer that will be updated with the
 *                    number of exposure regions returned in the @c regions
 *                    array.
 * @param regions A pointer to a @c ::camera_region_t array. The array is
 *                updated with the exposure regions configured on the camera.
 *                Ensure that you allocate an array with the same number of
 *                elements as the @c numasked argument.
 *                For more information about interpreting region geometry,
 *                see @c camera_set_exposure_regions().
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_exposure_regions(camera_handle_t handle,
                            int numasked,
                            int *numsupported,
                            int *numreturned,
                            camera_region_t *regions);


/**
 * @brief Configure the white balance regions on the camera
 * @details When white balance regions are defined, the auto white balance
 *          algorithm gives priority to objects in the defined areas of
 *          the scene.
 *
 *          Only call this function if the @c
 *          #CAMERA_FEATURE_REGIONWHITEBALANCE feature is available.
 *          Use the @c camera_can_feature() function to determine whether this
 *          feature is available.
 *
 *          The maximum number of white balance regions that you can configure
 *          is returned by the @c numsupported argument of the @c
 *          camera_get_whitebalance_regions() function.
 *
 *          After setting the regions, you must call the @c
 *          camera_set_whitebalance_mode() function to commit the changes.
 *
 *          The viewfinder must be running before using this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numregions The number of regions to apply, which is the number of
 *                   elements in the @c regions array.
 * @param regions A pointer to an array of white balance regions to apply. The
 *                region co-ordinates are interpreted relative to a viewfinder
 *                buffer with (0, 0) representing the top-left corner of the
 *                frame, and (width-1, height-1) representing the bottom-right
 *                corner.
 *                If @c #CAMERA_IMGPROP_ROTATION is applied to the viewfinder,
 *                then the co-ordinate frame of reference is also rotated
 *                accordingly.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_whitebalance_regions(camera_handle_t handle,
                                int numregions,
                                camera_region_t *regions);


/**
 * @brief Retrieve the white balance regions configured on the camera
 * @details Use this function to retrieve the configured auto
 *          white balance regions from the camera. For more information
 *          on configuring white balance regions, see @c
 *          camera_set_whitebalance_regions().
 *          When white balance regions are defined, the auto white balance
 *          algorithm gives priority to objects in the defined areas of the
 *          scene.
 *
 *          The maximum number of supported white balance regions is determined
 *          by checking the @c numsupported argument when the function completes
 *          successfully.
 *
 *          Ensure that the @c regions argument points to an array
 *          which has at least @c numasked elements allocated.To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or
 *          setting the regions argument to NULL. When the function is invoked
 *          in @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 *          The viewfinder must be running before using this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of regions to return in the @c regions
 *                 array. You can specify a value of 0 to determine the
 *                 number of white balance regions supported by the camera.
 * @param numsupported A pointer to an integer that will be updated with the
 *                     number of white balance regions supported by the camera.
 * @param numreturned A pointer to an integer that will be updated with the
 *                    number of white balance regions returned in the @c regions
 *                    array.
 * @param regions A pointer to a @c ::camera_region_t array. The array is
 *                updated with the white balance regions configured on the
 *                camera. Ensure that you allocate an array with the same number
 *                of elements as the @c numasked argument.
 *                For more information about interpreting region geometry,
 *                see @c camera_set_whitebalance_regions().
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_whitebalance_regions(camera_handle_t handle,
                                int numasked,
                                int *numsupported,
                                int *numreturned,
                                camera_region_t *regions);


/**
 * @brief Configure the autofocus, auto exposure, and auto white balance
 *        (the 3A algorithms) locks on the camera
 * @details For the @c locks argument, you can specify the 3A algorithms to
 *          lock by ORing values from the @c ::camera_3a_t enumerated type.
 *          The following are examples:
 *          - To unlock autofocus, auto exposure, and auto white balance, use
 *            the value of @c #CAMERA_3A_NONE.
 *          - To lock autofocus and auto exposure and unlock
 *            auto white balance, use the value of
 *            (@c #CAMERA_3A_AUTOFOCUS | @c #CAMERA_3A_AUTOEXPOSURE).
 *
 * @note Not all cameras allow the independent locking of individual
 *       3A algorithms. For example, it may be required that auto exposure
 *       and auto white balance be locked together. Use the @c
 *       camera_get_3a_lock_modes() function to discover these restrictions.
 *
 *       The viewfinder must be running before using this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param locks A bitmask of 3A algorithms to lock on the camera.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_3a_lock(camera_handle_t handle,
                   uint32_t locks);


/**
 * @brief Retrieve the list of supported 3A lock modes on the camera
 *
 * @details The 3A lock modes, which are independently lockable, are returned as
 *          separate elements in an array. Not all of the 3A algorithms may
 *          be independently lockable. The following examples illustrate some
 *          possible @c modes lists that may be returned:
 *
 *          For a camera where all three 3A algorithms can be locked
 *          independently, the array returned is as follows:
 *          @code
 *           - element 0: CAMERA_3A_AUTOFOCUS
 *           - element 1: CAMERA_3A_AUTOEXPOSURE
 *           - element 2: CAMERA_3A_AUTOWHITEBALANCE
 *           - element 3: CAMERA_3A_NONE
 *          @endcode
 *          For a camera where autofocus and auto exposure need to be locked
 *          simultaneously, and auto white balance may be locked independently,
 *          the array returned is as follows:
 *           @code
 *           - element 0: CAMERA_3A_AUTOFOCUS | CAMERA_3A_AUTOEXPOSURE
 *           - element 1: CAMERA_3A_AUTOWHITEBALANCE
 *           - element 1: CAMERA_3A_NONE
 *           @endcode
 *          For a camera where autofocus, auto exposure, and auto white balance
 *          need to be locked together, the array returned is as follows:
 *          @code
 *           - element 0: CAMERA_3A_AUTOFOCUS | CAMERA_3A_AUTOEXPOSURE |
 *                        CAMERA_3A_AUTOWHITEBALANCE
 *           - element 1: CAMERA_3A_NONE
 *          @endcode
 *          For a camera where only autofocus may be locked, the array returned
 *          is as follows:
 *          @code
 *           - element 0: CAMERA_3A_AUTOFOCUS
 *           - element 1: CAMERA_3A_NONE
 *          @endcode
 *
 *          You may can logically OR any of the elements of the returned
 *          @c modes list together to obtain a valid @c locks argument to use
 *          with the @c camera_set_3a_lock() function.
 *
 *          Ensure that the @c modes argument points to an array
 *          that has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          modes argument to @c NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of independently lockable 3A modes
 *                 in the @c modes array. You can use a value of 0 to
 *                 determine the number of independently lockable 3A modes
 *                 supported by the camera.
 * @param numsupported The returned number of independently lockable 3A
 *                     modes supported by the camera.
 * @param modes A pointer to a @c uint32_t array. The array will be updated with
 *              the combinations of independently lockable 3A modes supported by
 *              the camera. Ensure that you allocate an array with the
 *              same number of elements as specified in the @c numasked
 *              argument.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_3a_lock_modes(camera_handle_t handle,
                         int numasked,
                         int *numsupported,
                         uint32_t *modes);


/**
 * @brief Manually adjust the lens position on the camera
 * @details Use this function to adjust the lens position when using
 *          manual focus mode. Larger @c step values correspond to lens
 *          positions approaching infinity focus, and smaller @c step values
 *          correspond to lens positions approaching macro focus.
 *
 *          You can only use this function when the @c
 *          #CAMERA_FEATURE_MANUALFOCUS feature is available.
 *          You can determine whether this feature is
 *          available by calling the @c camera_can_feature() function.
 *
 *          Before you can change the focus, you must set the
 *          camera to @c #CAMERA_FOCUSMODE_MANUAL using the @c
 *          camera_set_focus_mode() function.
 *
 *          The viewfinder must be running before using this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param step The position to set the lens to. Use the @c
 *             camera_get_manual_focus_step() function to retrieve the details
 *             on the range of values supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_manual_focus_step(camera_handle_t handle,
                             int step);


/**
 * @brief Retrieve the current manual focus lens position and range
 * @details Use this function to query the current position of the lens
 *          in manual focus mode and the maximum step value supported
 *          by @c camera_set_manual_focus_step().
 *
 *          You can use this function only when the @c
 *          #CAMERA_FEATURE_MANUALFOCUS feature is available.
 *          You can determine whether this feature is
 *          available by calling the @c camera_can_feature() function.
 *
 *          Before you can use this function to retrieve the range of accepted
 *          values, you need to set the camera to @c #CAMERA_FOCUSMODE_MANUAL
 *          using the @c camera_set_focus_mode() function.
 *
 *          The viewfinder must be running before using this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param maxstep A pointer to the returned maximum settable step value that can
 *                be used for manual focus. It also indicates the infinity focus
 *                lens position.
 * @param step A pointer to the returned current step value (position) of the
 *             lens. The minimum step value is 0 and the maximum step is the
 *             value returned in the @c maxstep argument.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_manual_focus_step(camera_handle_t handle,
                             int *maxstep,
                             int *step);


/**
 * @brief Retrieve the exposure modes that are available on the camera
 * @details Use this function to retrieve the list of exposure modes that
 *          are available on the camera. You can change the current exposure
 *          mode using the @c camera_set_exposure_mode() function.
 *
 *          Ensure that the @c modes argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          modes argument to @c NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of exposure modes to return in the
 *                 @c modes array. You can specify a value of 0 to determine
 *                 the number of supported exposure modes available on the
 *                 camera.
 * @param numsupported A pointer to an integer that will be updated with the
 *                     number of exposure modes supported by the camera.
 * @param modes   A pointer to a @c ::camera_exposuremode_t array. The array is
 *                updated with the exposure modes available on the camera.
 *                Ensure that you allocate an array with the same number of
 *                elements as the @c numasked argument.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_exposure_modes(camera_handle_t handle,
                          int numasked,
                          int *numsupported,
                          camera_exposuremode_t *modes);


/**
 * @brief Configure the white balance mode on the camera
 * @details Use this function to set the active white balance mode on the
 *          camera. To determine valid white balance modes that can be set,
 *          call the @c camera_get_whitebalance_modes() function.
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param mode The white balance mode to apply.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_whitebalance_mode(camera_handle_t handle,
                             camera_whitebalancemode_t mode);


/**
 * @brief Retrieve the white balance mode from the camera
 * @details Use this function to query the current white balance mode of the
 *          camera. See also @c camera_set_whitebalance_mode().
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param mode A pointer to a @c ::camera_whitebalancemode_t value that is
 *             updated with the current white balance mode of the camera.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_whitebalance_mode(camera_handle_t handle,
                             camera_whitebalancemode_t *mode);


/**
 * @brief Retrieve the white balance modes that are available on the camera
 * @details Use this function to retrieve the list of white balance modes that
 *          are available on the camera. You can change the current white
 *          balance mode using the @c camera_set_whitebalance_mode() function.
 *
 *          Ensure that the @c modes argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          modes argument to @c NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of white balance modes to return in the
 *                 @c modes array. You can specify a value of 0 to determine
 *                 the number of supported white balance modes available on the
 *                 camera.
 * @param numsupported A pointer to an integer that will be updated with the
 *                     number of white balance modes supported by the camera.
 * @param modes   A pointer to a @c ::camera_whitebalancemode_t array. The array
 *                is updated with the white balance modes available on the
 *                camera. Ensure that you allocate an array with the same number
 *                of elements as the @c numasked argument.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_whitebalance_modes(camera_handle_t handle,
                              int numasked,
                              int *numsupported,
                              camera_whitebalancemode_t *modes);


/**
 * @brief Change the manual white balance color temperature
 * @details Use this function to set the white balance color
 *          temperature. The white balance alters the color for the image.
 *          The value that you set using this function is only applied when the
 *          white balance mode has been set to manual white balance using the
 *          @c camera_set_whitebalance_mode() function with the @c
 *          #CAMERA_WHITEBALANCEMODE_MANUAL property.
 *
 *          For more information regarding when these manual settings take
 *          effect, see @ref camapi_manual_settings and
 *          @c ::camera_whitebalancemode_t.
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param whitebalancevalue The manual white balance color temperature (in
 *                          Kelvin). Use
 *                          @c camera_get_supported_manual_white_balance_values()
 *                          to determine the white balance color temperature
 *                          values that can be set.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_manual_white_balance(camera_handle_t handle,
                                unsigned whitebalancevalue);


/**
 * @brief Retrieve the manual white balance color temperature
 * @details Use this function to retrieve the current manual white balance
 *          color temperature. If no white balance value was set, a default
 *          white balance value is returned.
 *          To see how to set the white blance, see
 *          @c camera_set_manual_white_balance().
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param whitebalancevalue A pointer to an integer value that will be updated
 *                          with the manual white balance color temperature
 *                          value (in Kelvin).
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_manual_white_balance(camera_handle_t handle,
                                unsigned *whitebalancevalue);


/**
 * @brief Change the manual white balance red and blue gains
 * @details Use this function to set the white balance red and blue gain values.
 *          The red and blue gains alter the amount of red and blue colors in
 *          the image. The values that you set using this function are only
 *          applied when the white balance mode has been set to manual, using
 *          the @c camera_set_whitebalance_mode() function with the @c
 *          #CAMERA_WHITEBALANCEMODE_MANUAL_RB_GAIN property.
 *
 *          For more information regarding when these manual settings take
 *          effect, see @ref camapi_manual_settings and
 *          @c ::camera_whitebalancemode_t.
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param red_gain The white balance red gain value.
 *                 Use @c camera_get_supported_manual_white_balance_rb_gain()
 *                 to determine the white balance red gain values that can
 *                 be set.
 * @param blue_gain The white balance blue gain value.
 *                  Use @c camera_get_supported_manual_white_balance_rb_gain()
 *                  to determine the white balance blue gain values that can
 *                  be set.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_manual_white_balance_rb_gain(camera_handle_t handle,
                                        unsigned red_gain,
                                        unsigned blue_gain);


/**
 * @brief Retrieve the manual white balance red and blue gains
 * @details Use this function to retrieve the current manual white balance red
 *          and blue gain values. If red and blue gains weren't already set,
 *          default values are returned.
 *          To see how to set the white balance red and blue gain values, see
 *          @c camera_set_manual_white_balance_red_gain().
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param red_gain Pointer to integer that will be updated with the red gain
 *                 value from camera.
 * @param blue_gain Pointer to integer that will be updated with the blue gain
 *                  value from camera.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_manual_white_balance_rb_gain(camera_handle_t handle,
                                        unsigned *red_gain,
                                        unsigned *blue_gain);


/**
 * @brief Retrieve the supported manual white balance color temperature values
 * @details Use this function to retrieve the set of supported manual white
 *          balance color temperature values for the camera.
 *
 *          Ensure that the @c whitebalancevalues argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          whitebalancevalues argument to @c NULL. When the function is invoked
 *          in this @e presizing mode, the maximum array size required is
 *          returned in the @c numsupported argument. You can then allocate an
 *          array of the appropriate size and invoke the function again with the
 *          @c numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 *          The values that you retrieve using this function can be set using
 *          the @c camera_set_manual_white_balance() function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of white balance color temperature
 *                 values to return in the @c whitebalancevalues array. You can
 *                 specify a value of zero to determine the number of supported
 *                 white balance color temperature values.
 * @param numsupported A pointer to an integer that will be updated with the
 *                     number of supported white balance color temperature
 *                     values.
 * @param whitebalancevalues A pointer to an @c unsigned @c int array. The array
 *                           is updated with the manual white balance color
 *                           temperature values that are supported. Ensure that
 *                           you allocate an array with the same number of
 *                           elements as the @c numasked argument. If the
 *                           @c maxmin argument returns @c true, then the first
 *                           value returned in the @c whitebalancevalues array
 *                           is the maximum supported white balance value, and the
 *                           second value returned is the minimum supported
 *                           color temperature.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c whitebalancevalues argument. This argument is set to
 *               @c true if the values are to be interpreted as a maximum and
 *               minimum value; otherwise, it's set to @c false to indicate that
 *               the values describe only the discrete white balance colour
 *               temperature values that are supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_manual_white_balance_values(camera_handle_t handle,
                                                 unsigned numasked,
                                                 unsigned *numsupported,
                                                 unsigned *whitebalancevalues,
                                                 bool *maxmin);


/**
 * @brief Retrieve the supported manual white balance red/blue gains values.
 * @details Use this function to retrieve the set of supported manual white
 *          balance red/blue gain values for the camera.
 *
 *          Ensure that the @c whitebalancevalues argument points to an array
 *          that has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in
 *          @e presizing mode by setting the @c numasked argument to 0 or the
 *          @c whitebalancevalues argument to @c NULL. When the function is
 *          invoked in this @e presizing mode, the maximum array size required
 *          is returned in the @c numsupported argument. You can then allocate an
 *          array of the appropriate size and invoke the function again with the
 *          @c numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 *          The values that you retrieve using this function can be set using
 *          the @c camera_set_manual_white_balance_rb_gain().
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of white balance red/blue gain
 *                 values to return in the @c whitebalancevalues array. You can
 *                 specify a value of zero to determine the number of supported
 *                 white balance red/blue gain values.
 * @param numsupported A pointer to an integer that will be updated with the
 *                     number of supported white balance red/blue gain
 *                     values.
 * @param gainvalues A pointer to an @c unsigned @c int array. The array is
 *                   updated with the manual white balance red/blue gain values
 *                   that are supported. Ensure that you allocate an array with
 *                   the same number of elements as the @c numasked argument.
 *                   If the @c maxmin argument returns @c true, then the first
 *                   value returned in the @c whitebalancevalues array is the
 *                   maximum supported red/blue gain value, and the second value
 *                   returned is the minimum supported red/blue gain value.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c gainvalues argument. This argument is set to @c true if
 *               the values are to be interpreted as a maximum and minimum
 *               value; otherwise, it's set to @c false to indicate that
 *               the values describe only the discrete white balance red/blue gain
 *               values that are supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_manual_white_balance_rb_gain(camera_handle_t handle,
                                                  unsigned numasked,
                                                  unsigned *numsupported,
                                                  unsigned *gainvalues,
                                                  bool *maxmin);



/**
 * @brief Change the manual ISO value on the camera
 * @details Use this function to set the manual ISO value. The value
 *          that you set using this function is only applied when the exposure
 *          mode has been set to allow manual ISO settings using
 *          @c camera_set_exposure_mode(). You can use the
 *          @c camera_get_supported_manual_iso_values() function to determine
 *          the range of valid ISO values that you can use.
 *
 *          For more information regarding when these manual settings take
 *          effect, see @ref camapi_manual_settings and
 *          @c ::camera_exposuremode_t.
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param isovalue The ISO value to set on the camera.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_manual_iso(camera_handle_t handle,
                      unsigned isovalue);


/**
 * @brief Retrieve the current manual ISO value
 * @details Use this function to retrieve the current manual ISO value.
 *          See also @c camera_set_manual_iso().
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param isovalue A pointer to an @c unsigned @c int value that will be updated
 *                 with the current manual ISO value.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_manual_iso(camera_handle_t handle,
                      unsigned *isovalue);


/**
 * @brief Retrieve the supported manual ISO values
 *
 * @details Use this function to retrieve the set of supported manual ISO
 *          values for the camera.
 *
 *          Ensure that the @c isovalues argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          isovalues argument to @c NULL. When the function is invoked
 *          in this @e presizing mode, the maximum array size required is
 *          returned in the @c numsupported argument. You can then allocate an
 *          array of the appropriate size and invoke the function again with the
 *          @c numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 *          The values that you retrieve using this function can be set using
 *          the @c camera_set_manual_iso() function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of manual ISO values to return in the
 *                 @c isovalues array. You can specify a value of 0 to determine
 *                 the number of supported manual ISO values.
 * @param numsupported A pointer to an integer that will be updated with the
 *                     number of supported manual ISO values.
 * @param isovalues  A pointer to an @c unsigned @ int array that will be
 *                   updated with the manual ISO values that are supported.
 *                   Ensure that you allocate the array with at least @c
 *                   numasked elements. If the @c maxmin argument returns @c
 *                   true, then the first value returned in the @c isovalues
 *                   array is the maximum supported manual ISO value, and the
 *                   second value that is returned is the minimum supported
 *                   manual ISO value.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c isovalues argument. This argument is set to @c true if
 *               the values are to be interpreted as a maximum and minimum
 *               value; otherwise, it's set to @c false to indicate that the
 *               values describe only the discrete manual ISO values that
 *               are supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_manual_iso_values(camera_handle_t handle,
                                       unsigned numasked,
                                       unsigned *numsupported,
                                       unsigned *isovalues,
                                       bool *maxmin);


/**
 * @brief Change the manual shutter speed
 * @details Use this function to set the manual shutter speed on the camera.
 *          The value that you set using this function is only applied when
 *          the exposure mode is set to allow manual shutter speed control
 *          using @c camera_set_exposure_mode(). You can use
 *          @c camera_get_supported_manual_shutter_speeds() to
 *          determine the range of valid shutter speeds values that you can use.
 *
 *          For more information regarding when the value takes
 *          effect, see @ref camapi_manual_settings and
 *          @c ::camera_exposuremode_t.
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param shutterspeed The manual shutter speed (in seconds) to set.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_manual_shutter_speed(camera_handle_t handle,
                                double shutterspeed);


/**
 * @brief Retrieve the current manual shutter speed
 * @details Use this function to retrieve the currently set manual shutter
 *          speed. To set the shutter speed manually, see
 *          @c camera_set_manual_shutter_speed().
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param shutterspeed A pointer to a @c double value that is updated with
 *                     the current manual shutter speed (in seconds).
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_manual_shutter_speed(camera_handle_t handle,
                                double *shutterspeed);


/**
 * @brief Retrieve the supported manual shutter speeds
 * @details Use this function to retrieve the set of supported manual shutter
 *          speeds that you can use with the current camera.
 *
 *          Ensure that the @c shutterspeeds argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          shutterspeeds argument to @c NULL. When the function is invoked
 *          in this @e presizing mode, the maximum array size required is
 *          returned in the @c numsupported argument. You can then allocate an
 *          array of the appropriate size and invoke the function again with the
 *          @c numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 *          The values that you retrieve using this function can be set using
 *          the @c camera_set_manual_shutter_speed() function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of manaul shutter speeds to return in
 *                 the @c shutterspeeds array. You can specify a value of 0 to
 *                 determine the number of supported manual shutter speeds.
 * @param numsupported A pointer to an integer that will be updated with the
 *                     number of supported shutter speeds.
 * @param shutterspeeds  A pointer to a @c double array. The array is updated
 *                       with the manual shutter speeds (in seconds) supported.
 *                       Ensure that you allocate an array at least @c numasked
 *                       elements. If the @c maxmin argument returns @c true,
 *                       then the first value returned in the @c shutterspeeds
 *                       array is the maximum supported shutter speed, and the
 *                       second value returned is the minimum supported shutter
 *                       speed.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c shutterspeeds argument. This argument is set to @c true
 *               if the values are to be interpreted as a maximum and minimum
 *               value; otherwise, it's set to @c false to indicate that the
 *               values describe only the discrete shutter speeds that are
 *               supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_manual_shutter_speeds(camera_handle_t handle,
                                           unsigned numasked,
                                           unsigned *numsupported,
                                           double *shutterspeeds,
                                           bool *maxmin);


/**
 * @brief Change the manual aperture value (f-number) on the camera
 * @details Use this function to set the manual aperture value.
 *
 *          Setting a small f-number results in a reduced depth of field.
 *          Setting a large f-number results in an increased depth of field.
 *
 *          The value that you set using this function is only applied when the
 *          exposure mode has been set to allow manual aperture settings using
 *          @c camera_set_exposure_mode(). You can use the
 *          @c camera_get_supported_manual_aperture_values() function to
 *          determine the range of valid aperture values that you can use.
 *          For more information regarding when manual settings take
 *          effect, see Manual Settings in the
 *          @e Camera @e Developer's @e Guide and
 *          @c ::camera_exposuremode_t.
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param aperturevalue The aperture value to set on the camera.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_manual_aperture(camera_handle_t handle,
                           double aperturevalue);


/**
 * @brief Retrieve the current manual aperture value (f-number)
 * @details Use this function to retrieve the current manual aperture
 *          value (f-number). See also @c camera_set_manual_aperture().
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param aperturevalue A pointer to a @c double that will be updated with the
 *                      current manual aperture value.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_manual_aperture(camera_handle_t handle,
                           double *aperturevalue);


/**
 * @brief Retrieve the supported manual aperture values (f-numbers)
 * @details Use this function to retrieve the set of supported manual
 *          aperture values (f-numbers) for the camera.
 *
 *          Ensure that the @c aperturevalues argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          aperturevalues argument to @c NULL. When the function is invoked
 *          in this @e presizing mode, the maximum array size required is
 *          returned in the @c numsupported argument. You can then allocate an
 *          array of the appropriate size and invoke the function again with the
 *          @c numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 *          The values that you retrieve using this function can be set using
 *          the @c camera_set_manual_aperture() function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of manual aperture values to return in
 *                 the @c aperturevalues array. You can specify a value of zero
 *                 to determine the number of supported manual aperture values.
 * @param numsupported A pointer to an integer that will be updated with the
 *                     number of supported manual aperture values.
 * @param aperturevalues A pointer to a @c double array. The array is updated
 *                       with the manual aperture values supported. Ensure that
 *                       you allocate an array with the same number of elements
 *                       as the @c numasked argument. If the @c maxmin argument
 *                       returns @c true, then the first value returned in the
 *                       @c aperturevalues array is the maximum supported
 *                       manual aperture value, and the second value returned
 *                       is the minimum supported manual aperture value.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c aperturevalues argument. This argument is set to @c true
 *               if the values are to be interpreted as a maximum and minimum
 *               value; otherwise, it's set to @c false to indicate that the
 *               values describe only the discrete manual aperture values that
 *               are supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_manual_aperture_values(camera_handle_t handle,
                                            unsigned numasked,
                                            unsigned *numsupported,
                                            double *aperturevalues,
                                            bool *maxmin);


/**
 * @brief Configure the exposure mode on the camera
 * @details Use this function to set the active exposure mode on the
 *          camera. To determine valid exposure modes that can be set,
 *          call the @c camera_get_exposure_modes() function.
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param mode The exposure mode to apply.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_exposure_mode(camera_handle_t handle,
                         camera_exposuremode_t mode);


/**
 * @brief Retrieve the exposure mode from the camera
 * @details Use this function to query the current exposure mode
 *          of the camera. See also @c camera_set_exposure_mode().
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param mode A pointer to a @c ::camera_exposuremode_t value that is updated
 *             with the current exposure mode of the camera.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_exposure_mode(camera_handle_t handle,
                         camera_exposuremode_t *mode);


/**
 * @brief Set the exposure value (EV) offset for exposure compensation
 * @details Use this function to set the EV offset to make pictures brighter
 *          or darker. The value set in this function @b does @b not take effect
 *          if the exposure mode (@c ::camera_exposuremode_t) is set to one of
 *          these values:
 *            - @c #CAMERA_EXPOSUREMODE_MANUAL
 *            - @c #CAMERA_EXPOSUREMODE_OFF
 *
 *          You can call @c camera_get_supported_ev_offsets() to determine
 *          the available EV offset values that can be used.
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param offset The EV offset to set. Positive values, such as +1 will
 *               make the picture brighter while negative values, such as -1
 *               will make the picture darker.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_ev_offset(camera_handle_t handle,
                     double offset);


/**
 * @brief Retrieve the current exposure value (EV) offset for exposure
 *        compensation
 * @details Use this function to retrieve the current EV offset. The
 *          current EV offset is disabled when the exposure mode is one of
 *          these values:
 *            - @c #CAMERA_EXPOSUREMODE_MANUAL
 *            - @c #CAMERA_EXPOSUREMODE_OFF
 *
 *          See also @c camera_set_ev_offset().
 *
 *          The viewfinder must be running before calling this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param offset A pointer to a @c double value that will be updated with the
 *               current EV offset.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_ev_offset(camera_handle_t handle,
                     double *offset);


/**
 * @brief Retrieve the supported range of EV offset values
 * @details Use this function to retrieve the EV offset values that are
 *          available on the camera.
 *
 *          Ensure that the @c offsets argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          offsets argument to @c NULL. When the function is invoked
 *          in this @e presizing mode, the maximum array size required is
 *          returned in the @c numsupported argument. You can then allocate an
 *          array of the appropriate size and invoke the function again with the
 *          @c numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 *          The values that you retrieve using this function can be set using
 *          the @c camera_set_ev_offset() function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of EV offset values to return in the
 *                 @c offsets array. You can specify a value of 0 to
 *                 determine the number of supported EV offsets values.
 * @param numsupported A pointer to an integer that will be updated with the
 *                     number of supported EV offset values.
 * @param offsets A pointer to a @c double array. The array is updated
 *                with the EV offset values supported by the camera. Ensure that
 *                you allocate an array with the same number of elements as the
 *                @c numasked argument. If the @c maxmin argument returns @c true,
 *                then the first value returned in the @c offsets array is the
 *                maximum supported EV offset, and the second value returned is
 *                the minimum supported EV offset.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c offsets argument. This argument is set to @c true
 *               if the values are to be interpreted as a maximum and minimum
 *               value; otherwise, it's set to @c false to indicate that the
 *               values describe only the discrete EV offset values that are
 *                supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_ev_offsets(camera_handle_t handle,
                                unsigned numasked,
                                unsigned *numsupported,
                                double *offsets,
                                bool *maxmin);


#ifdef __cplusplus
}
#endif

#endif // _CAMERA_3A_H_

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/camapi/public/camera/camera_3a.h $ $Rev: 886530 $")
#endif
