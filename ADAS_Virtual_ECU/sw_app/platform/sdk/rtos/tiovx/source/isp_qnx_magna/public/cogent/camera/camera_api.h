/*
 * $QNXLicenseC:
 * Copyright 2012-2017, QNX Software Systems. All Rights Reserved.
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
 * @file camera_api.h
 *
 * @brief The main definitions and functions for the Camera Library.
 *
 */

/**
 * @mainpage Camera Library Reference
 *
 * The Camera library provides an application with a consistent
 * interface to interact with one or more cameras connected to the system.
 * Using this library, you can perform operations such as:
 *
 *  - Connect and disconnect from a camera.
 *  - Start and stop the viewfinder.
 *  - Use features on the camera, such as zoom, autofocus,
 *    auto white balance, and auto exposure.
 *  - Adjust focus, exposure, and white balance algorithms by defining
 *    regions of interest, or applying manual controls.
 *  - Encode video and save video recordings to file.
 *
 */

#ifndef __CAMERA_API_H__
#define __CAMERA_API_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#ifndef PC_VER
#include <screen/screen.h>
#include <sys/siginfo.h>
#endif

/**
 * The version of the Camera library. The version is used for IPC
 * handshaking and communication between the Camera API and the operating system.
 * You can compare @c CAMERA_API_VERSION with the value returned by the @c
 * camera_get_api_version() function to determine whether the runtime library is
 * different from the version your application was compiled with. Differences
 * may indicate potential incompatibilities.
 */
#define CAMERA_API_VERSION    3


/**
 * Error codes for the Camera library.
 * If you receive an error code which is not enumerated in this list, consult
 * the system-wide list of error codes in errno.h.
 */
typedef enum {
    /**
     * The function call to the camera completed successfully.
     */
    CAMERA_EOK = EOK,
    /**
     * The function call failed due to a permission issue.
     */
    CAMERA_EPERM = EPERM,
    /**
     * The function call failed due to a temporary unavailable condition.
     * Try to call the function again.
     */
    CAMERA_EAGAIN = EAGAIN,
    /**
     * The function call failed because of an invalid argument.
     */
    CAMERA_EINVAL = EINVAL,
    /**
     * The function call failed because the specified camera was not found.
     */
    CAMERA_ENODEV = ENODEV,
    /**
     * The function call failed because of a file table overflow.
     */
    CAMERA_EMFILE = EMFILE,
    /**
     * The function call failed because an invalid @c
     * ::camera_handle_t value was used.
     */
    CAMERA_EBADF = EBADF,
    /**
     * The function call failed because the necessary permissions to access
     * the camera are not available.
     */
    CAMERA_EACCESS = EACCES,
    /**
     * The function call failed because an invalid file descriptor was used.
     */
    CAMERA_EBADR = EBADR,
    /**
     * The function call failed because the requested data does not
     * exist.
     */
    CAMERA_ENODATA = ENODATA,
    /**
     * The function call failed because the specified file or directory does
     * not exist.
     */
    CAMERA_ENOENT = ENOENT,
    /**
     * The function call failed because memory allocation failed.
     */
    CAMERA_ENOMEM = ENOMEM,
    /**
     * The function call failed because the requested operation is not
     * supported.
     */
    CAMERA_EOPNOTSUPP = EOPNOTSUPP,
    /**
     * The function call failed due to communication problem or time-out with
     * the camera.
     */
    CAMERA_ETIMEDOUT = ETIMEDOUT,
    /**
     * The function call failed because an operation on the camera is already in
     * progress. In addition, this error can indicate that a call could not be
     * completed because it was invalid or completed already. For example,
     * if you called the @c camera_stop_video() function but the camera had
     * already stopped recording video, this error code would be returned.
     */
#ifdef EALREADY_NEW
    CAMERA_EALREADY = EALREADY_NEW,
#else
    CAMERA_EALREADY = EALREADY,
#endif
    /**
     * The function call failed because the camera is busy.  Typically you
     * receive this error when you try to open a camera while the camera or
     * its required resources are in use.
     */
    CAMERA_EBUSY = EBUSY,
    /**
     * The function call failed because the disk is full.  This typically
     * happens when you are trying to start a video recording and less than
     * the system-reserved amount of disk space remains.
     */
    CAMERA_ENOSPC = ENOSPC,
    /**
     * The function call failed because of an Input/Output error.  This
     * typically happens when a file I/O operation failed.
     */
    CAMERA_EIO = EIO,
    /**
     * The function call failed because the entity trying to be created already
     * exists.
     */
    CAMERA_EEXIST = EEXIST,
    /**
     * The function call failed because the camera is in a bad state.
     */
    CAMERA_EDEADLK = EDEADLK,
    /**
     * The function call failed because the Camera library has not been
     * initialized.
     */
    CAMERA_EUNINIT = 0x1000,
    /**
     * The function call failed because the registration of a callback failed.
     */
    CAMERA_EREGFAULT,
    /**
     * The function call failed because the microphone is already in use.
     */
    CAMERA_EMICINUSE,
    /**
     * The function call failed because the operation cannot be completed while
     * the desktop type camera is in use.
     */
    CAMERA_EDESKTOPCAMERAINUSE,
    /**
     * The function call failed because the camera is in the power down state.
     */
    CAMERA_EPOWERDOWN,
    /**
     * The function call failed because a 3A lock is active.
     */
    CAMERA_3ALOCKED,
    /**
     * The function call failed because the viewfinder freeze flag was set on
     * the device for privacy reasons.
     */
    CAMERA_EVIEWFINDERFROZEN,
    /**
     * The function call failed due to an internal overflow.
     */
    CAMERA_EOVERFLOW,
    /**
     * The function call failed because the camera is in power down state to
     * prevent damage due to excessive heat.
     */
    CAMERA_ETHERMALSHUTDOWN,
    /**
     * The function call failed due to an hardware fault with the camera.
     */
    CAMERA_EHARDWARE
    /*...*/
} camera_error_t;


/**
 * @brief This enumerated type specifies the image properties list.
 *
 * These properties are used as keys for the following functions:
 * - @c camera_set_vf_property()
 * - @c camera_get_vf_property()
 * - @c camera_set_video_property()
 * - @c camera_get_video_property()
 *
 * Each key is associated with a value of the indicated type.
 */
typedef enum {
    /**
     * End-of-list identifier.
     */
    CAMERA_IMGPROP_END = -1,
    /**
     * The image format as a @c ::camera_frametype_t value.
     */
    CAMERA_IMGPROP_FORMAT = 0,
    /**
     * The width of the image as a @c uint32_t value.
     */
    CAMERA_IMGPROP_WIDTH,
    /**
     * The height of the image as a @c uint32_t value.
     */
    CAMERA_IMGPROP_HEIGHT,
    /**
     * The frame rate of the image sequence as a @c double value.
     * When @c #CAMERA_IMGPROP_VARIABLEFRAMERATE is set to a
     * value of 1, @c #CAMERA_IMGPROP_FRAMERATE indicates the maximum
     * frame rate to use for the image sequence.
     */
    CAMERA_IMGPROP_FRAMERATE,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_IMGPROP_RESERVED1,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_IMGPROP_RESERVED2,
    /**
     * The image rotation angle (in degrees) as a @c uint32_t
     * value. Rotation angles are measured in the clockwise direction.
     */
    CAMERA_IMGPROP_ROTATION,
    /**
     * Enable built-in stabilization algorithms to help avoid a
     * blurry image. The value is specified as an @c int value. A
     * value of 0 indicates that stabilization is off and a value of 1
     * indicates that stabilization is on. To enable stabilization for video,
     * @c #CAMERA_FEATURE_VIDEOSTABILIZATION must be available on the camera.
     * Note that @c #CAMERA_IMGPROP_MAXFOV must be set to 0 when starting
     * the viewfinder before video stabilization can be enabled.
     */
    CAMERA_IMGPROP_STABILIZATION,
    /**
     * Zoom factor is used as a @c uint32_t value.
     * The zoom factor is a value supported by the camera hardware and
     * represents digital zoom or optical zoom. Optical zoom is
     * only supported if the camera supports it. Most digital cameras
     * support digital zoom.
     */
    CAMERA_IMGPROP_ZOOMFACTOR,
    /**
     * The viewfinder can use hardware acceleration for @e blitting.
     * To use this feature, the hardware acceleration for the blitting feature
     * must be available (@c #CAMERA_FEATURE_VFHWOVERLAY). Use
     * the @c camera_can_feature() function to determine whether the camera
     * supports the feature. To use blitting, specify as an @c int value where
     * 0 indicates not to use blitting and 1 indicates to use blitting.
     *
     * Blitting is a hardware acceleration feature used for efficiently
     * transferring image buffers to the video display. For more
     * information, see @c SCREEN_USAGE_OVERLAY used in the
     * @c screen_set_window_property_iv() function in the Screen Library Reference
     * of the @e Screen @e Developer's @e Guide.
     * When you use this value, the viewfinder window uses
     * @c SCREEN_USAGE_OVERLAY window property where possible.
     */
    CAMERA_IMGPROP_HWOVERLAY,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_IMGPROP_JPEGQFACTOR,
    /**
     * The window group ID the viewfinder should be created in, as a @c const
     * @c char* value. For more information, see the QNX Screen Graphics Subsystem.
     */
    CAMERA_IMGPROP_WIN_GROUPID,
    /**
     * The window ID to apply to the viewfinder window that is created
     * as a @c const @c char* value.
     */
    CAMERA_IMGPROP_WIN_ID,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_IMGPROP_RESERVED3,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_IMGPROP_RESERVED4,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_IMGPROP_RESERVED5,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_IMGPROP_VARIABLEFRAMERATE,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_IMGPROP_MINFRAMERATE,
    /**
     * An embedded window will be created (see "Screen window types" in the
     * Screen Library Reference of the @e Screen @e Developer's @e Guide.
     * window-types). If the viewfinder is being created as a child of an
     * existing child window, then this flag must be set using an @c int. Use a
     * value of 1 to create an embedded window and 0 otherwise.
     */
    CAMERA_IMGPROP_ISEMBEDDED,
    /**
     * Whether to create a visible viewfinder window or not. This flag accepts
     * @c int values. Setting the value to 1 causes a viewfinder window to be
     * created (see the Screen Graphics Subsystem for information on managing
     * windows). Setting the value to 0 suppresses the creation of a viewfinder
     * window.
     *
     * @note To create a viewfinder window, the feature
     *       @c #CAMERA_FEATURE_VFWINDOW must be available on the camera.
     *
     * @note On some platforms not all frame types are supported. Call
     *       @c camera_is_create_window_supported() to check if the frame type
     *       you are using allows @c #CAMERA_IMGPROP_CREATEWINDOW to be @c true.
     *
     */
    CAMERA_IMGPROP_CREATEWINDOW,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_IMGPROP_METAORIENTATIONHINT,
    /**
     * Indicates that the FOV (field of view) of the viewfinder should not be
     * cropped when the viewfinder is started. This parameter must be set using
     * an @c int value. A value of 0 indicates that the viewfinder may be
     * started with cropping applied in order to support use of the
     * @c #CAMERA_IMGPROP_STABILIZATION property. A value of 1 indicates that
     * the viewfinder will provide the widest possible field of view at startup
     * and will disallow attempts to use the @c #CAMERA_IMGPROP_STABILIZATION
     * property.
     */
    CAMERA_IMGPROP_MAXFOV,
    /**
     * The video codec used when generating video files or streams using
     * @c camera_start_video() or @c camera_start_encode(). The video
     * codec value is of type @c ::camera_videocodec_t.
     */
    CAMERA_IMGPROP_VIDEOCODEC,
    /**
     * The audio codec used when generating video files or streams using
     * @c camera_start_video() or @c camera_start_encode(). The audio
     * codec value is of type @c ::camera_audiocodec_t.
     */
    CAMERA_IMGPROP_AUDIOCODEC,
    /**
     * The viewfinder window is updated with frames from the camera when
     * this property is set to 1. Rendering is suspended if the value is set
     * to 0. The parameter must be an @c int value, and can be used to mask
     * undesirable visual artifacts when exposure bracketing is active.
     */
    CAMERA_IMGPROP_RENDERTOWINDOW,
    /**
     * The viewfinder window is created with a certain number of buffers to
     * accomodate both the buffer requirements of the camera and to have
     * additional buffers that can be held by the user for callback or event
     * handling. This property indicates how many additional buffers are
     * allocated for the user. While it's always possible to read this
     * property, it is only writable before starting the viewfinder and for
     * cameras that support the feature @c #CAMERA_FEATURE_NUMVFUSERBUFFERS.
     * The parameter is a @c uint32_t value.
     */
    CAMERA_IMGPROP_NUMUSERBUFFERS
} camera_imgprop_t;


/**
 * @brief This enumerated type specifies the camera physical properties list
 *
 *        These properties are used as keys for the @c
 *        camera_get_physical_property() function.
 *        Each key is associated with a value of the indicated type.
 */
typedef enum {
    /**
     * The end-of-list identifier.
     */
    CAMERA_PHYSPROP_END = -1,
    /**
     * The focal length of the lens in millimeters as a @c double value.
     */
    CAMERA_PHYSPROP_FOCALLENGTH = 0,
    /**
     * The horizontal field of view of the camera when set to its minimum zoom
     * factor and at its full-frame resolution. The value (in degrees) is a @c
     * double value. The horizontal axis is defined as the axis running
     * from left to right of the device when held in its default orientation
     * (i.e., the BlackBerry logo is upright).
     */
    CAMERA_PHYSPROP_HORIZONTALFOV,
    /**
     * The vertical field of view of the camera when set to its minimum zoom
     * factor and its full-frame resolution. The value (in degrees) is a @c
     * double value. The vertical axis is defined as the axis running
     * from top to bottom of the device when held in its default orientation
     * (i.e., the BlackBerry logo is upright).
     */
    CAMERA_PHYSPROP_VERTICALFOV,
    /**
     * The full-frame width of the imaging sensor in millimeters as a
     * @c double value. The width corresponds to the sensor axis which runs
     * from left to right of the device when held in its default orientation
     * (i.e., the BlackBerry logo is upright).
     */
    CAMERA_PHYSPROP_SENSORWIDTH,
    /**
     * The full-frame height of the imaging sensor in millimeters as a @c double
     * value. The height corresponds to the sensor axis which runs from top
     * to bottom of the device when held in its default orientation
     * (i.e., the BlackBerry logo is upright).
     */
    CAMERA_PHYSPROP_SENSORHEIGHT,
    /**
     * The magnification ratio between the maximum zoom factor
     * and the minimum zoom factor as a @c double value.
     * For example, a ratio of 3.0 indicates that a fully zoomed-in image
     * is expanded by a magnification factor of 3.0 times when compared with the
     * fully zoomed-out version of the image.
     */
    CAMERA_PHYSPROP_MAXZOOMRATIO,
    /**
     * The full-frame width of the imaging sensor in pixels as a
     * @c uint32_t value. The width corresponds to the sensor axis which runs
     * from left to right of the device when held in its default orientation
     * (i.e., the BlackBerry logo is upright).
     */
    CAMERA_PHYSPROP_SENSORWIDTHPIXELS,
    /**
     * The full-frame height of the imaging sensor in pixels as a @c uint32_t
     * value. The height corresponds to the sensor axis which runs from top
     * to bottom of the device when held in its default orientation
     * (i.e., the BlackBerry logo is upright).
     */
    CAMERA_PHYSPROP_SENSORHEIGHTPIXELS,
    /**
     * The 35mm-equilvalent focal length of the lens in millimeters as a
     * @c double value.
     */
    CAMERA_PHYSPROP_FOCALLENGTH35MM,
    /**
     * The aperture (or F-number) is expressed as the ratio of the focal length
     * to the diameter of the entrance pupil of the lens as a @c double value.
     * If a variable aperture is supported, the value reported refers to the
     * ratio at maximum pupil opening.
     */
    CAMERA_PHYSPROP_APERTURE,
    /**
     * The native sensitivity of the camera sensor expressed as a @c uint32_t
     * ISO value. The native sensitivity is defined as the effective sensitivity
     * of the camera at unity gain.
     */
    CAMERA_PHYSPROP_SENSORISO
} camera_physprop_t;


/**
 * The status of the camera device.
 * These values are delivered to your status callback functions or via the
 * @c camera_get_status_details() function whenever the state of the camera
 * changes.
 *
 * Some examples of conditions which may trigger a status change include:
 * - whether the viewfinder was started
 * - whether recording has stopped
 * - whether autofocus is searching or has locked
 * - whether the camera has powered down
 * - whether a capture was aborted due to a fault
 *
 * Status changes may also convey additional information as a @c uint16_t
 * value where indicated.
 */
typedef enum {
    /**
     * The status of the camera is not known.
     */
    CAMERA_STATUS_UNKNOWN = 0,
    /**
     * No user is connected to the camera.
     */
    CAMERA_STATUS_DISCONNECTED,
    /**
     * A user is connected to the camera but the camera is in the
     * idle state.
     */
    CAMERA_STATUS_CONNECTED,
    /**
     * The camera is not powered. This is typical when the device is going into
     * a standby state. The extra @c uint16_t value can be interpreted as
     * follows:
     *
     * - Bits 15..8: For internal use only. Do not use.
     * - Bits  7..0: The @c ::camera_powerdownreason_t value indicating the reason.
     *
     */
    CAMERA_STATUS_POWERDOWN,
    /**
     * For internal use only. Do not use.
     **/
    CAMERA_STATUS_PHOTOVF,
    /**
     * The video viewfinder has started.
     */
    CAMERA_STATUS_VIDEOVF,
    /**
     * The recording has stopped due to a memory error or multimedia
     * framework error (used by the video encoder).
     */
    CAMERA_STATUS_MM_ERROR,
    /**
     * A file has exceeded the maximum size. Recordings
     * will stop with this error when the size is getting too close to the
     * limit.
     */
    CAMERA_STATUS_FILESIZE_ERROR,
    /**
     * The recording has stopped because there is no more disk space
     * available.
     */
    CAMERA_STATUS_NOSPACE_ERROR,
    /**
     * The capture of a still image failed and was aborted.
     */
    CAMERA_STATUS_CAPTURE_ABORTED,
    /**
     * The user-configurable time-remaining threshold has been
     * exceeded while recording video. The default is 60 seconds, but you can
     * change the time-remaining threshold using the @c
     * camera_set_video_filesize_warning() function.
     */
    CAMERA_STATUS_FILESIZE_WARNING,
    /**
     * The focus changed on the camera.
     * The extra @c uint16_t value can be interpreted as follows:
     *
     * - Bits 15..8: For internal use only. Do not use.
     * - Bits  7..0: The @c ::camera_focusstate_t value indicating the focus state.
     *
     * You can call the @c camera_get_focus_state() function to retrieve
     * further details, including the focus region co-ordinates.
     */
    CAMERA_STATUS_FOCUS_CHANGE,
    /**
     * A warning that the camera is about to free resources
     * due to a power-down or arbitration event (resources needed elsewhere).
     * You should release camera resources by returning buffers, stopping
     * recordings, and stopping viewfinders. This event happens when
     * the device is about to enter standby mode or a higher-priority process
     * needs access to resources that are shared with the camera.
     * The extra @c uint16_t value can be interpreted as follows:
     *
     * - Bits 15..8: For internal use only. Do not use.
     * - Bits  7..0: A @c ::camera_powerdownreason_t value indicating the reason.
     *
     *
     * @note For more important information related to the triggering of
     *       this status event, see  "Resource management" in the
     *       @e Camera @e Library @e Developer's @e Guide and
     *       the @c camera_register_resource() function.
     *
     */
    CAMERA_STATUS_RESOURCENOTAVAIL,
    /**
     * Video encoding has been paused. This pause is due to
     * resources needed for video encoding not being currently available
     * (needed elsewhere). Once resources are available again, @c
     * #CAMERA_STATUS_VIDEO_RESUME status change will be sent.
     * While encoding is in this paused state, there will be a gap in the
     * video file. Your application may choose to stop video encoding when
     * this status event is received.
     */
    CAMERA_STATUS_VIDEO_PAUSE,
    /**
     * Video encoding has resumed again following a pause or has
     * started encoding for the first time.
     */
    CAMERA_STATUS_VIDEO_RESUME,
    /**
     * Still capture has completed and you may now take another picture.
     */
    CAMERA_STATUS_CAPTURECOMPLETE,
    /**
     * The camera has been repowered. This status typically occurs when the
     * device returns from the standby (i.e., @c #CAMERA_STATUS_POWERDOWN)
     * state.
     */
    CAMERA_STATUS_POWERUP,
    /**
     * For system privacy reasons, the viewfinder has been frozen. When the
     * viewfinder is frozen, the same frame is continually sent until the
     * @c #CAMERA_STATUS_VIEWFINDER_UNFREEZE status is sent.
     */
    CAMERA_STATUS_VIEWFINDER_FREEZE,
    /**
     * The viewfinder that was previously frozen has resumed the display of
     * frames. This status can only be received after the
     * @c #CAMERA_STATUS_VIEWFINDER_FREEZE status has been received previously.
     */
    CAMERA_STATUS_VIEWFINDER_UNFREEZE,
    /**
     * This indicates that the low-light status has changed. The least
     * significant bit of the @c uint16_t value will be 1 when low-light
     * is detected, and 0 when low-light is not detected. All other bits in
     * the @c uint16_t value are for internal use only. Do not use.
     */
    CAMERA_STATUS_LOWLIGHT,
    /**
     * This indicates that a frame was dropped internally either due to the
     * user taking too long to process a callback frame or due to some internal
     * error. The @c uint16_t extra argument contains the @c ::camera_eventkey_t
     * associated with the buffer queue that overflowed. This event is cleared
     * by @c camera_get_frame_stats_property() and the event will not occur
     * again until this function is called.
     */
    CAMERA_STATUS_FRAME_DROPPED,
    /**
     * For system privacy reasons, the viewfinder has been suspended. No frames
     * will be delivered while the viewfinder is suspended.
     */
    CAMERA_STATUS_VIEWFINDER_SUSPEND,
    /**
     * The viewfinder that was previously suspended has resumed the delivery of
     * frames. This status will only be received after the @c
     * #CAMERA_STATUS_VIEWFINDER_SUSPEND status has been received previously.
     */
    CAMERA_STATUS_VIEWFINDER_UNSUSPEND,
    /**
     * For internal use only. Do not use.
     **/
    CAMERA_STATUS_FLASH_LEVEL_CHANGE,
    /**
     * For internal use only. Do not use.
     **/
    CAMERA_STATUS_VIDEOLIGHT_LEVEL_CHANGE,
    /**
     * For internal use only. Do not use.
     **/
    CAMERA_STATUS_VIDEOLIGHT_CHANGE,
    /**
     * The user-configurable time before reaching the user configured file size
     * limit has been reached while recording a video.  This status event is
     * generated after the user has called @c camera_set_video_filesize_limit()
     * to set a non-zero file size limit and that it was determined that the
     * file size limit will be reached in the configured warning time.
     */
    CAMERA_STATUS_FILESIZE_LIMIT_WARNING,
    /**
     * Viewfinder is active and working properly.  This is sent initially after
     * entering @c CAMERA_STATUS_VIDEOVF to indicate that we have received our
     * first viewfinder buffer.  This is also sent after we recover from an
     * error such as @c CAMERA_STATUS_BUFFER_UNDERFLOW or @c
     * CAMERA_STATUS_VIEWFINDER_ERROR to indicate that streaming is back to
     * working as expected.
     */
    CAMERA_STATUS_VIEWFINDER_ACTIVE,
    /**
     * The viewfinder is out of buffers and cannot stream any further buffers
     * until a buffer is freed.  Once recovered, a @c
     * CAMERA_STATUS_VIEWFINDER_ACTIVE indication will be given.  This will
     * typically occur if a user is holding on to more buffers than what is
     * specified in the number of user buffer configuration.
     */
    CAMERA_STATUS_BUFFER_UNDERFLOW,
    /**
     * An unexpected error was encountered while the viewfinder was active that
     * prevents the camera from streaming any further data.  Once recovered, a
     * @c CAMERA_STATUS_VIEWFINDER_ACTIVE indication will be given.
     */
    CAMERA_STATUS_VIEWFINDER_ERROR,
    /**
     * The camera has been physically disconnected from the platform. The
     * application should immediately call @c camera_close() on the
     * @c camera_handle_t received from @c camera_open(). After the
     * application calls @c camera_close() it may wait for the camera to be
     * reconnected (the camera will be returned from a call to
     * @c camera_get_supported_cameras()) at which point the application can
     * call @c camera_open() again.
     */
    CAMERA_STATUS_PHYSICAL_REMOVAL = 34,
    /**
     * Streaming is active and buffers are being filled by the camera.
     * However, the data stored in the buffers contain one or more gaps
     * due to missed camera readings.
     */
    CAMERA_STATUS_STREAMING_GAP,
    /**
     * For camera data, this indicates that data readout from the camera sensor
     * began. Indicates that the data readout of a given packet from the
     * camera sensor has started.  Note that this status event is only supported
     * on some camera sensors.
     */
    CAMERA_STATUS_DATA_READ_STARTED = 36,
    /**
     * This indicates that the camera was unplugged and is no longer accessible.
     * When the camera becomes again accessible, a @c CAMERA_STATUS_CAMERA_PLUGGED will be sent.
     * Note that this status event is only supported on cameras that support recovery from being unplugged.
     */
    CAMERA_STATUS_CAMERA_UNPLUGGED,
    /**
     * This indicates that the camera was replugged and becomes again accessible.
     * Note that this status event is only supported on cameras that support recovery from being unplugged.
     */
    CAMERA_STATUS_CAMERA_PLUGGED = 40,
    /**
     * Indicates stream rewound to the beginning. This event is sent only when using a file camera.
     */
    CAMERA_STATUS_VIDEO_REWIND = 41,
    /**
     * An unexpected issue was encountered while the viewfinder was active.
     * This issue does not prevent the camera from streaming, but it may affect the camera image quality.
     */
    CAMERA_STATUS_VIEWFINDER_WARNING = 42,
    /**
     * Indicates that the camera output frame rate has been changed.
     * The @c uint16_t extra argument contains the new frame rate value.
     */
    CAMERA_STATUS_FRAMERATE_CHANGE = 43

} camera_devstatus_t;


/**
 * The reason that the camera was turned off or was shutdown.
 *
 * When you use @e event mode, you can use @c camera_get_status_details()
 * to retrieve the reason the camera was turned off. The @c devstatusextra
 * argument is one of the listed enumerations from this enumerated type.
 * For information about the event mode, see "Event mode" in the
 * @e Camera @e Library @e Developer's @e Guide.
 *
 * When you are in @e callback mode, you can retrieve the reason using the third
 * argument from the status callback. For information about the callback
 * arguments, see "Callback mode" in the
 * @e Camera @e Library @e Developer's @e Guide.
 */
typedef enum {
    /**
     * The camera was turned off for an unknown reason.
     */
    CAMERA_POWERDOWNREASON_UNKNOWN = 0,
    /**
     * The camera was turned off because the device went into standby mode.
     */
    CAMERA_POWERDOWNREASON_STANDBY,
    /**
     * The camera was turned off because the shared resources used by the camera
     * were required by another component of the operating system.
     */
    CAMERA_POWERDOWNREASON_RESOURCEARBITRATION,
    /**
     * The camera was turned off to prevent damage due to excessive heat.
     */
    CAMERA_POWERDOWNREASON_THERMAL,
    /**
     * The camera was required by a higher priority application. Your
     * application must close the camera.
     */
    CAMERA_POWERDOWNREASON_FORCECLOSE
} camera_powerdownreason_t;


/**
 * Represents the camera units on the device. It's possible for a
 * device to have multiple cameras units.
 */
typedef enum {
    /**
     * For internal use only. Do not use.
     */
    CAMERA_UNIT_NONE = 0,
    /**
     * Camera identifier on the device.
     */
    CAMERA_UNIT_1,
    CAMERA_UNIT_2,
    CAMERA_UNIT_3,
    CAMERA_UNIT_4,
    CAMERA_UNIT_5,
    CAMERA_UNIT_6,
    CAMERA_UNIT_7,
    CAMERA_UNIT_8,
    CAMERA_UNIT_9,
    CAMERA_UNIT_10,
    CAMERA_UNIT_11,
    CAMERA_UNIT_12,
    CAMERA_UNIT_13,
    CAMERA_UNIT_14,
    CAMERA_UNIT_15,
    CAMERA_UNIT_16,
    CAMERA_UNIT_17,
    CAMERA_UNIT_18,
    CAMERA_UNIT_19,
    CAMERA_UNIT_20,
    CAMERA_UNIT_21,
    CAMERA_UNIT_22,
    CAMERA_UNIT_23,
    CAMERA_UNIT_24,
    CAMERA_UNIT_25,
    CAMERA_UNIT_26,
    CAMERA_UNIT_27,
    CAMERA_UNIT_28,
    CAMERA_UNIT_29,
    CAMERA_UNIT_30,
    CAMERA_UNIT_31,
    CAMERA_UNIT_32,
    CAMERA_UNIT_33,
    CAMERA_UNIT_34,
    CAMERA_UNIT_35,
    CAMERA_UNIT_36,
    CAMERA_UNIT_37,
    CAMERA_UNIT_38,
    CAMERA_UNIT_39,
    CAMERA_UNIT_40,
    CAMERA_UNIT_41,
    CAMERA_UNIT_42,
    CAMERA_UNIT_43,
    CAMERA_UNIT_44,
    CAMERA_UNIT_45,
    CAMERA_UNIT_46,
    CAMERA_UNIT_47,
    CAMERA_UNIT_48,
    CAMERA_UNIT_49,
    CAMERA_UNIT_50,
    CAMERA_UNIT_51,
    CAMERA_UNIT_52,
    CAMERA_UNIT_53,
    CAMERA_UNIT_54,
    CAMERA_UNIT_55,
    CAMERA_UNIT_56,
    CAMERA_UNIT_57,
    CAMERA_UNIT_58,
    CAMERA_UNIT_59,
    CAMERA_UNIT_60,
    CAMERA_UNIT_61,
    CAMERA_UNIT_62,
    CAMERA_UNIT_63,
    CAMERA_UNIT_64,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_UNIT_NUM_UNITS
} camera_unit_t;


/**
 * Represents the major mode of the viewfinder. Each viewfinder mode provides a
 * different set of capabilities, which can be checked using @c
 * camera_has_feature() after choosing a mode. Not all cameras support all
 * viewfinder modes, so ensure you query @c camera_get_supported_vf_modes()
 * before using @c camera_set_vf_mode().
 *
 * For more information about viewfinder modes, see
 * "Viewfinder mode" in the @e Camera @e Library @e Developer's @e Guide.
 */
typedef enum {
    /**
     * The default viewfinder mode when a camera is opened. The
     * @c camera_has_feature() function provides a complete list of features
     * supported by the camera.
     */
    CAMERA_VFMODE_DEFAULT,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_VFMODE_PHOTO,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_VFMODE_CONTINUOUS_BURST,

    /**
     * For internal use only. Do not use.
     */
    CAMERA_VFMODE_FIXED_BURST,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_VFMODE_EV_BRACKETING,
    /**
     * Video mode allows for videos to be recorded or encoded. For more
     * information, see @c camera_start_video() and @c camera_start_encode().
     */
    CAMERA_VFMODE_VIDEO,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_VFMODE_VIDEO_SNAPSHOT,
    /**
     * High-speed video mode allows for videos to be recorded or encoded at
     * higher frame rates than @c CAMERA_VFMODE_VIDEO. For more information,
     * see @c camera_start_video() and @c camera_start_encode().
     */
    CAMERA_VFMODE_HIGH_SPEED_VIDEO,
    /**
     * HDR (high dynamic range) video mode allows for videos to be recorded
     * with a higher dynamic range than @c CAMERA_VFMODE_VIDEO. For more
     * information, see @c camera_start_video() and @c camera_start_encode().
     */
    CAMERA_VFMODE_HDR_VIDEO,
    /**
     * An end-of-list identifier.
     */
    CAMERA_VFMODE_NUM_MODES
} camera_vfmode_t;


/**
 * A 32-bit value representing a handle used to identify an open instance of
 * a logical camera unit on a device. A handle to the camera is created by
 * calling the @c camera_open() function and is released by calling the @c
 * camera_close() function. A handle, when available, is similar to a file
 * descriptor used to access the camera. Various Camera library calls
 * use the handle to interact with the camera.
 */
typedef int32_t camera_handle_t;


/**
 * A safe-initializer value for a @c ::camera_handle_t. Use this value to
 * check that correct initialization occurred and whether a call to the @c
 * camera_open() function was successful. You should use this value to
 * initialize camera handle variables, and after you close a handle.
 */
#define CAMERA_HANDLE_INVALID  (-1)


/**
 * The camera capabilities or features available on the camera. The enumerated
 * type is used with the @c camera_has_feature() and @c camera_can_feature()
 * functions.
 */
typedef enum {
    /**
     * The camera supports queries from the @c
     * camera_can_feature() and @c camera_has_feature() functions.
     */
    CAMERA_FEATURE_FBM = 0,
    /**
     * For internal use only. Do not use.
     **/
    CAMERA_FEATURE_PHOTO = 1,
    /**
     * It is possible to encode video.
     */
    CAMERA_FEATURE_VIDEO = 2,
    /**
     * For internal use only. Do not use.
     **/
    CAMERA_FEATURE_PHOTOZOOM = 3,
    /**
     * Zoom is available in the video viewfinder mode.
     */
    CAMERA_FEATURE_VIDEOZOOM = 4,
    /**
     * Zero-shutter lag is available.
     */
    CAMERA_FEATURE_ZSL = 5,
    /**
     * For internal use only. Do not use.
     **/
    CAMERA_FEATURE_BURST = 6,
    /**
     * For internal use only. Do not use.
     **/
    CAMERA_FEATURE_EVBRACKETING = 7,
    /**
     * For internal use only. Do not use.
     **/
    CAMERA_FEATURE_FLASH = 8,
    /**
     * For internal use only. Do not use.
     **/
    CAMERA_FEATURE_VIDEOLIGHT = 9,
    /**
     * There is no standalone video buffer stream available.
     * Preview buffers are used for both viewfinder and video encoding.
     * For more information, see @c camera_set_video_property().
     */
    CAMERA_FEATURE_PREVIEWISVIDEO = 10,
    /**
     * Autofocus is available.
     */
    CAMERA_FEATURE_AUTOFOCUS = 11,
    /**
     * Manual focus is available.
     */
    CAMERA_FEATURE_MANUALFOCUS = 12,
    /**
     * It is possible to focus on a specific region
     * in the viewfinder.
     */
    CAMERA_FEATURE_REGIONFOCUS = 13,
    /**
     * Macro focus mode is available. Macro mode allows you to
     * focus on objects that are close to the camera, such as 10 centimeters
     * away.
     */
    CAMERA_FEATURE_MACROFOCUS = 14,
    /**
     * The focus assist feature is available. Focus assist turns on the
     * light when running single focus cycles in low-light conditions.
     * The light will also be turned on in low-light conditions if
     * continuous autofocus is enabled and focus is not locked prior to
     * taking a picture.
     */
    CAMERA_FEATURE_FOCUSASSIST = 15,
    /**
     * The viewfinder can use hardware acceleration for blitting.
     * Blitting is a hardware acceleration feature used for efficiently
     * transferring image buffers to the video display. For more
     * information, see @c SCREEN_USAGE_OVERLAY used in the @c
     * screen_set_window_property_iv() function in the "Screen Library Reference"
     * in the @e Screen @e Developer's @e Guide.
     * When you use this value, the viewfinder window uses @c
     * SCREEN_USAGE_OVERLAY window property where possible.
     */
    CAMERA_FEATURE_VFHWOVERLAY = 16,
    /**
     * Region exposure is available. Region exposure allows you
     * to perform spot and partial metering in specific regions of an image.
     */
    CAMERA_FEATURE_REGIONEXPOSURE = 17,
    /**
     * Region white balance is available. Region white balance uses the image
     * data in the user-specified region to make white balance adjustment
     * (color correction) computations.
     */
    CAMERA_FEATURE_REGIONWHITEBALANCE = 18,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_FEATURE_CONTINUOUSBURST = 19,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_FEATURE_VFFACEDETECT = 20,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_FEATURE_FACEDETECT = 21,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_FEATURE_PHOTOVFVARIABLEFRAMERATE = 22,
    /**
     * Auto exposure is available.
     */
    CAMERA_FEATURE_AUTOEXPOSURE = 23,
    /**
     * Auto white balance is available.
     */
    CAMERA_FEATURE_AUTOWHITEBALANCE = 24,
    /**
     * Manual exposure is available.
     */
    CAMERA_FEATURE_MANUALEXPOSURE = 25,
    /**
     * Manual white balance is available.
     */
    CAMERA_FEATURE_MANUALWHITEBALANCE = 26,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_FEATURE_PREMAPBUFFERS = 27,
    /**
     * Low-light status notification is available.
     */
    CAMERA_FEATURE_LOWLIGHT_STATUS = 28,
    /**
     * For internal use only. Do not use.
     **/
    CAMERA_FEATURE_VFHISTOGRAM = 29,
    /**
     * Video stabilization is available on the camera. For more information,
     * see @c #CAMERA_IMGPROP_STABILIZATION.
     */
    CAMERA_FEATURE_VIDEOSTABILIZATION = 30,
    /**
     * For internal use only. Do not use.
     **/
    CAMERA_FEATURE_PHOTOSTABILIZATION = 31,
    /**
     * Optical image stabilization is available on the camera.
     */
    CAMERA_FEATURE_OPTICALIMAGESTABILIZATION = 32,
    /**
     * The camera is an analog camera and supports configuring parameters that
     * are specific to analog cameras.
     */
    CAMERA_FEATURE_ANALOGCAMERA = 33,
    /**
     * A visible viewfinder window is supported.  For more information, see
     * @c #CAMERA_IMGPROP_CREATEWINDOW.
     */
    CAMERA_FEATURE_VFWINDOW = 34,
    /**
     * It is possible to set the number of user buffers to be allocated for a
     * viewfinder.  For more information, see
     * @c #CAMERA_IMGPROP_NUMUSERBUFFERS.
     */
    CAMERA_FEATURE_NUMVFUSERBUFFERS = 35,
    /**
     * It is possible to call @c camera_set_filename() to dynamically change
     * the file associated with a camera that plays out a file to simulate a
     * camera.
     */
    CAMERA_FEATURE_FILENAME = 36,
    /**
     * An end-of-list identifier that indicates the total number of features
     * recognized by the Camera library.
     */
    CAMERA_FEATURE_NUMFEATURES
} camera_feature_t;


/**
 * The maximum length of a filename returned by camera-roll functions. The value
 * is useful for you to determine the largest @c char* buffer to allocate. The
 * camera roll is a directory where video files are saved.
 */
#define CAMERA_ROLL_NAMELEN  (256)


/**
 * The maximum length of a filename suffix to add to filenames returned by
 * camera-roll functions.
 */
#define CAMERA_ROLL_SUFFIXLEN (64)


/**
 * The frame types identifiers for an image buffer. Frame types are used to
 * distinguish between frame descriptors within a @c ::camera_buffer_t
 * structure.
 */
typedef enum {
    /**
     * The frame type has no associated format, no recognized
     * format, or is unformatted.
     */
    CAMERA_FRAMETYPE_UNSPECIFIED = 0,
    /**
     * The frame type is NV12 formatted data. The @c
     * ::camera_frame_nv12_t structure represents this frame type.
     */
    CAMERA_FRAMETYPE_NV12 = 1,
    /**
     * The frame type is 32-bit ARGB data. The @c
     * ::camera_frame_rgb8888_t structure represents this frame type.
     */
    CAMERA_FRAMETYPE_RGB8888 = 2,
    /**
     * The frame type is 24-bit RGB data. The @c
     * ::camera_frame_rgb888_t structure represents this frame type.
     */
    CAMERA_FRAMETYPE_RGB888 = 3,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_FRAMETYPE_JPEG = 4,
    /**
     * The frame type is 8-bit gray-scale image data. The @c
     * ::camera_frame_gray8_t structure represents this frame type.
     */
    CAMERA_FRAMETYPE_GRAY8 = 5,
    /**
     * The frame type is metadata. The @c
     * ::camera_frame_meta_t structure represents this frame type.
     */
    CAMERA_FRAMETYPE_METADATA = 6,
    /**
     * The image is a 10-bit Bayer frame type. The @c
     * ::camera_frame_bayer_t structure represents this frame type.
     */
    CAMERA_FRAMETYPE_BAYER = 7,
    /**
     * The image is a YCbCr 4:2:2 packed frame type. The @c
     * ::camera_frame_cbycry_t structure represents this frame type.
     */
    CAMERA_FRAMETYPE_CBYCRY = 8,
    /**
     * The frame consists of compressed video data.  The @c
     * ::camera_frame_compressedvideo_t structure represents this frame type.
     */
    CAMERA_FRAMETYPE_COMPRESSEDVIDEO = 9,
    /**
     * The frame consists of compressed audio data.  The @c
     * ::camera_frame_compressedaudio_t structure represents this frame type.
     */
    CAMERA_FRAMETYPE_COMPRESSEDAUDIO = 10,
    /**
     * The frame type is 16-bit RGB data (5-bit red component, 6-bit green
     * component, 5-bit blue component). The @c ::camera_frame_rgb565_t
     * structure represents this frame type.
     */
    CAMERA_FRAMETYPE_RGB565 = 11,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_FRAMETYPE_PRIVATE = 12,
    /**
     * The frame type is a 4:2:0 YCbCr formats where Y, Cb and Cr are stored in
     * separate planes.  The @c ::camera_frame_ycbcr420p_t structure represents
     * this frame type.
     */
    CAMERA_FRAMETYPE_YCBCR420P = 13,
    /**
     * The image is a YCbCr 4:2:2 packed frame type where the pixel order is
     * Y, Cb, Y, Cr. The @c ::camera_frame_ycbycr_t structure represents this
     * frame type.
     */
    CAMERA_FRAMETYPE_YCBYCR = 14,
    /**
     * The image is a YCbCr 4:2:2 packed frame type where the pixel order is
     * Y, Cr, Y, Cb. The @c ::camera_frame_ycrycb_t structure represents this
     * frame type.
     */
    CAMERA_FRAMETYPE_YCRYCB = 15,
    /**
     * The image is a YCbCr 4:2:2 packed frame type where the pixel order is
     * Cr, Y, Cb, Y. The @c ::camera_frame_crycby_t structure represents this
     * frame type.
     */
    CAMERA_FRAMETYPE_CRYCBY = 16,
    /**
     * The image is a region-of-interest (ROI) image within a bigger buffer.
     * The @c ::camera_frame_roi_t structure represents this frame type.
     */
    CAMERA_FRAMETYPE_ROI = 17,
    /**
     * The image is 14-bit Bayer data in a 16-bit buffer. The
     * @c ::camera_frame_bayer_t structure represents this frame type,
     * and is filled in as follows :
     * @code
     * format = CAMERA_BAYERFORMAT_RGGB
     * packing = 16
     * bpp = 14
     * le = false
     * cadence_length = 16
     * pixels_per_cadence = 1
     * justification = CAMERA_BAYERJUSTIFY_LEFT_BIT0LSB,
     * Bit:          FEDCBA9876543210 FEDCBA9876543210
     * Scanline n:   RRRRRRRRRRRRRR00 GGGGGGGGGGGGGG00
     * Scanline n+1: GGGGGGGGGGGGGG00 BBBBBBBBBBBBBB00
     * @endcode
     */
    CAMERA_FRAMETYPE_BAYER14_RGGB_PADLO16 = 18,

    /**
     * The frame type is NV16 formatted data. The @c
     * ::camera_frame_nv12_t (both are semiplanar) structure represents this frame type.
     */
    CAMERA_FRAMETYPE_NV16 = 27,

    /**
     * The frame type is as NV24 formatted data but with 12 bit Y padded to 16 bits.
     * The @c ::camera_frame_nv12_t (both are semiplanar) structure represents
     * this frame type.
     */
    CAMERA_FRAMETYPE_NV24_Y12 = 28,

    /**
     * An end-of-list identifier that indicates the number of frame types
     * recognized by this library.
     */
    CAMERA_FRAMETYPE_NUMFRAMETYPES
} camera_frametype_t;


/**
 * The video compression formats used by the video encoder.
 */
typedef enum {
    /**
     * No compression.
     */
    CAMERA_VIDEOCODEC_NONE = 0,
    /**
     * AVC1 compression (NALU).
     */
    CAMERA_VIDEOCODEC_AVC1,
    /**
     * H264 compression (Annex B).
     */
    CAMERA_VIDEOCODEC_H264
} camera_videocodec_t;


/**
 * The audio compression formats used by the video encoder.
 */
typedef enum {
    /**
     * No audio is encoded in the video.
     */
    CAMERA_AUDIOCODEC_NONE = 0,
    /**
     * MPEG-2/4 AAC compression.
     */
    CAMERA_AUDIOCODEC_AAC,
    /**
     * Uncompressed PCM audio samples.
     */
    CAMERA_AUDIOCODEC_RAW
} camera_audiocodec_t;


/**
 * The maximum size, in bytes, of the frame descriptor.
 */
#define CAMERA_MAX_FRAMEDESC_SIZE  (256)


/**
 * A camera event key that is used to identify an event that is enabled.
 * For more information about events, see "Event mode" in the
 * @e Camera @e Library @e Developer's @e Guide.
 */
typedef int32_t camera_eventkey_t;


/**
 * @brief Event buffering modes
 * @details The event buffering mode dictates the behavior of the @c inbuffer
 *          and @c outbuffer arguments of the buffer retrieval functions.
 *          The enumerated values are for use with the following functions:
 *          - @c camera_enable_status_event()
 *          - @c camera_enable_video_event()
 *          - @c camera_enable_viewfinder_event()
 *
 *          You use the following functions to retrieve the buffers:
 *          - @c camera_get_video_buffers()
 *          - @c camera_get_viewfinder_buffers()
 */
typedef enum {
    /**
     * Read-only access to buffers is requested. This is the same buffer access
     * mode employed when a callback function is used. The @c inbuffer argument
     * is read-only.
     */
    CAMERA_EVENTMODE_READONLY,
    /**
     * Read-write access to buffers is requested. Using this mode allows you to
     * modify buffers prior to delivery to callback functions or read-only event
     * consumers. The @c inbuffer and @c outbuffer arguments refer to the same
     * image data in physical memory however, @c outbuffer is modifiable, while
     * @c inbuffer remains read-only.
     */
    CAMERA_EVENTMODE_READWRITE,
} camera_eventmode_t;


/**
 * A frame descriptor that holds only data. Use this frame descriptor when the
 * @c #CAMERA_FRAMETYPE_UNSPECIFIED is reported as the @c ::camera_frametype_t.
 */
typedef struct {
    /**
     * An array representing the frame data. The size of the array is
     * the size indicated by the @c #CAMERA_MAX_FRAMEDESC_SIZE value. This
     * placeholder value ensures that the buffer descriptor is always padded for
     * forward compatibility.
     */
     uint8_t  framedata[CAMERA_MAX_FRAMEDESC_SIZE];
} camera_frame_unspecified_t;


/**
 * A frame descriptor used for NV12 frame types. Use this frame descriptor when
 * @c #CAMERA_FRAMETYPE_NV12 is reported as the @c ::camera_frametype_t.
 */
typedef struct {
    /**
     * The height of the frame in pixels.
     */
     uint32_t height;
    /**
     * The width of the frame in pixels.
     */
     uint32_t width;
    /**
     * The number of bytes between the first pixel of the first row in memory
     * and the first pixel of the second row in memory of the luminance (Y)
     * plane. Stride is often called @e pitch. For more information, see the
     * @c uv_stride member.
     */
     uint32_t stride;
    /**
     * The number of bytes between the first pixel of the Y plane in memory
     * and the first pixel of the UV plane in memory. On a device where
     * there is no gap between the Y and UV planes, the uv_offset would be
     * height times stride bytes. This equivalence is not guaranteed across
     * all devices, so it is important to observe the uv_offset value rather
     * than attempting to compute the offset.
     */
     int64_t uv_offset;
    /**
     * The number of bytes between the first pixel of the first row in memory
     * and the first pixel of the second row in memory of the chrominance (UV)
     * plane. For more information, see the @c stride member.
     */
     int64_t uv_stride;
} camera_frame_nv12_t;


/**
 * A frame descriptor used for RGB8888 frame types. Use this frame descriptor
 * when @c #CAMERA_FRAMETYPE_RGB8888 is reported as the @c ::camera_frametype_t.
 */
typedef struct {
    /**
     * The height of the frame in pixels.
     */
    uint32_t height;
   /**
    * The width of the frame in pixels.
    */
    uint32_t width;
    /**
     * The number of bytes between the first pixel of the first row in memory
     * and the first pixel of the second row in memory.
     * Stride is often called @e pitch.
     */
    uint32_t stride;
} camera_frame_rgb8888_t;


/**
 * A frame descriptor used for RGB888 frame types. Use this frame descriptor
 * when @c #CAMERA_FRAMETYPE_RGB888 is reported as the @c ::camera_frametype_t.
 */
typedef struct {
    /**
     * The height of the frame in pixels.
     */
    uint32_t height;
    /**
     * The width of the frame in pixels.
     */
    uint32_t width;
    /**
     * The number of bytes between the first pixel of the first row in memory
     * and the first pixel of the second row in memory.
     * Stride is often called @e pitch.
     */
    uint32_t stride;
} camera_frame_rgb888_t;


/**
 * A frame descriptor used for RGB565 frame types. Use this frame descriptor
 * when @c #CAMERA_FRAMETYPE_RGB565 is reported as the @c ::camera_frametype_t.
 */
typedef struct {
    /**
     * The height of the frame in pixels.
     */
    uint32_t height;
    /**
     * The width of the frame in pixels.
     */
    uint32_t width;
    /**
     * The number of bytes between the first pixel of the first row in memory
     * and the first pixel of the second row in memory.
     * Stride is often called @e pitch.
     */
    uint32_t stride;
} camera_frame_rgb565_t;


/**
 * For internal use only. Do not use.
 */
typedef struct {
    /**
     * The size of the JPEG buffer in bytes.
     */
    uint64_t bufsize;
    /*...*/
} camera_frame_jpeg_t;


/**
 * A frame descriptor for 8-bits per pixel grayscale frame types. Use this
 * frame descriptor when @c #CAMERA_FRAMETYPE_GRAY8 is reported as the @c
 * ::camera_frametype_t.
 */
typedef struct {
    /**
     * The height of the frame in pixels.
     */
    uint32_t height;
    /**
     * The width of the frame in pixels.
     */
    uint32_t width;
    /**
     * The number of bytes between the first pixel of the first row in memory
     * and the first pixel of the second row in memory.
     * Stride is often called @e pitch.
     */
    uint32_t stride;
} camera_frame_gray8_t;


/**
 * For internal use only. Do not use.
 */
typedef struct {
    /**
     * The size of the frame in bytes.
     */
    uint64_t bufsize;
    /*...*/
} camera_frame_meta_t;


/**
 * Bayer bit justification.
 * The Bayer bit justification indicates whether bit 0 is the
 * least significant or most significant bit of the word, and
 * it also indicates whether the bits are justified towards
 * the 0th bit (right justified), or to the Nth bit (left justified).
 * For example:
 * @code
 * le = false
 * bpp = 10
 * packing = 16
 * cadence_length = 16
 * pixels_per_cadence = 1
 * format = CAMERA_BAYERFORMAT_RGGB
 * @endcode
 * @c #CAMERA_BAYERJUSTIFY_RIGHT_BIT0LSB would represent:
 * @code
 * Bit:          FEDCBA9876543210 FEDCBA9876543210
 * Scanline n:   000000RRRRRRRRRR 000000GGGGGGGGGG
 * Scanline n+1: 000000GGGGGGGGGG 000000BBBBBBBBBB
 * @endcode
 * Note that the 0th bit in the word represents the least-significant bit,
 * and the bits are justified to the right of the word.
 */
typedef enum {
    /** Bit 0 is the least significant bit, and the bits are right justified.
     */
    CAMERA_BAYERJUSTIFY_RIGHT_BIT0LSB,
    /** Bit 0 is the least significant bit, and the bits are left justified.
     */
    CAMERA_BAYERJUSTIFY_LEFT_BIT0LSB,
    /** Bit 0 is the most significant bit, and the bits are right justified.
     */
    CAMERA_BAYERJUSTIFY_RIGHT_BIT0MSB,
    /** Bit 0 is the most significant bit, and the bits are left justified.
     */
    CAMERA_BAYERJUSTIFY_LEFT_BIT0MSB,
} camera_bayerjustify_t;


/**
 * The Bayer array macro-pixel format. For more information about the Bayer
 * frame format, see @c ::camera_frame_bayer_t.
 */
typedef enum {
    /**
     * Camera Bayer array macro-pixel format is unknown or unspecified.
     */
    CAMERA_BAYERFORMAT_UNSPECIFIED,

    /**
     * Camera Bayer array macro-pixel format is:
     * @code
     *  G R
     *  B G
     * @endcode
     */
    CAMERA_BAYERFORMAT_GRBG,

    /**
     * Camera Bayer array macro-pixel format is:
     * @code
     *  R G
     *  G B
     * @endcode
     */
    CAMERA_BAYERFORMAT_RGGB,

    /**
     * Camera Bayer array macro-pixel format is:
     * @code
     *  B G
     *  G R
     * @endcode
     */
    CAMERA_BAYERFORMAT_BGGR,

    /**
     * Camera Bayer array macro-pixel format is:
     * @code
     *  G B
     *  R G
     * @endcode
     */
    CAMERA_BAYERFORMAT_GBRG,
} camera_bayerformat_t;


/**
 * A frame descriptor for a Bayer frame type. Use this frame
 * descriptor when @c #CAMERA_FRAMETYPE_BAYER is reported as the @c
 * ::camera_frametype_t.
 *
 * Each pixel in the Bayer frame is part of a Bayer @e macro-pixel. Each Bayer
 * macro-pixel is made up of four color components: one red, one blue, and two
 * green. We refer to the color components as @e pixels, and the group of four
 * as a macro-pixel.
 *
 * Each macro-pixel is stored across two lines in the frame. The first two
 * pixels are stored contiguously on the first line. The @c stride separates the
 * first pixel from the third, and the second pixel from the fourth.
 *
 * Each pixel of the Bayer macro-pixel comprises @c bpp bits. These bits can
 * be packed into larger sized words with a size indicated by the @c packing
 * field. In addition, groups of pixels may be tightly packed into a cadence
 * which is defined by @c cadence_length and @c pixels_per_cadence. The ordering
 * of the bits is determined by the @c justification field.
 *
 * Example 1:
 * @code
 * le = true
 * bpp = 10
 * packing = 16
 * cadence_length = 16
 * pixels_per_cadence = 1
 * justification = CAMERA_BAYERJUSTIFY_RIGHT_BIT0LSB
 * format = CAMERA_BAYERFORMAT_RGGB
 * @endcode
 * This example describes a 10-bit Bayer frame where each color component is
 * stored as 10 bits packed into 16-bit words. The word is stored in little-
 * endian byte order. Bit 0 represents the least significant bit, and the bits
 * are justified to the right of each byte. This leaves six unused bits per
 * pixel.
 * The Bayer macro-pixels in one cadence would be stored like so, with
 * PxHi indicating the most significant bits of pixel x, and PxLo indicating
 * the least significant bits of pixel x:
 * @code
 * Bit:                  76543210
 * Scanline n,   byte 0: RRRRRRRR    P1Lo(Red)
 * Scanline n,   byte 1: 000000RR    P1Hi(Red)
 * Scanline n,   byte 2: GGGGGGGG    P2Lo(Green)
 * Scanline n,   byte 3: 000000GG    P2Hi(Green)
 * ...and repeats.
 *
 * Scanline n+1, byte 0: GGGGGGGG    P1Lo(Green)
 * Scanline n+1, byte 1: 000000GG    P1Hi(Green)
 * Scanline n+1, byte 2: BBBBBBBB    P2Lo(Blue)
 * Scanline n+1, byte 3: 000000BB    P2Hi(Blue)
 * ...and repeats.
 * @endcode
 *
 * Example 2:
 * @code
 * le = false
 * bpp = 10
 * packing = 10
 * justification = CAMERA_BAYERJUSTIFY_LEFT_BIT0LSB
 * cadence_length = 10
 * pixels_per_cadence = 1
 * format = CAMERA_BAYERFORMAT_RGGB
 * @endcode
 * This example describes a 10-bit Bayer frame where each 10-bit pixel is
 * tightly packed into a 10-bit word. There are no wasted bits in between
 * pixels in this example. Each word is stored in big-endian byte order.
 * Bit 0 represents the least significant bit, and the bits
 * are justified to the left of each byte.
 * The Bayer macro-pixels in one cadence would be stored like so, with PxHi
 * indicating the most significant bits of pixel x, and PxLo indicating the
 * least significant bits of pixel x:
 *
 * @code
 * Bits:                 76543210
 * Scanline n,   byte 0: RRRRRRRR    P1Hi(Red)
 * Scanline n,   byte 1: RRGGGGGG    P1Lo(Red)     & P2Hi(Green)
 * Scanline n,   byte 2: GGGGRRRR    P2Lo(Green)   & P3Hi(Red)
 * Scanline n,   byte 3: RRRRRRGG    P3Lo(Red)     & P4Hi(Green)
 * Scanline n,   byte 4: GGGGGGGG    P4Lo(Green)
 * ...and repeats.
 *
 * Scanline n+1, byte 0: GGGGGGGG    P1Hi(Green)
 * Scanline n+1, byte 1: GGBBBBBB    P1Lo(Green)   & P2Hi(Blue)
 * Scanline n+1, byte 2: BBBBGGGG    P2Lo(Blue)    & P3Hi(Green)
 * Scanline n+1, byte 3: GGGGGGBB    P3Lo(Green)   & P4Hi(Blue)
 * Scanline n+1, byte 4: BBBBBBBB    P4Lo(Blue)
 * ...and repeats.
 * @endcode
 *
 * Example 3:
 * @code
 * le = true
 * bpp = 10
 * packing = 10
 * justification = CAMERA_BAYERJUSTIFY_RIGHT_BIT0LSB
 * cadence_length = 64
 * pixels_per_cadence = 6
 * format = CAMERA_BAYERFORMAT_RGGB
 * @endcode
 * This example describes a 10-bit Bayer frame where each 10-bit pixel
 * is tightly packed into a 10-bit word, and six pixels are packed into
 * a 64-bit cadence. The word is stored in little-endian byte order. Bit
 * 0 represents the least significant bit and the bits are justified to
 * the right of each byte. This leaves four unused bits for each six
 * pixel cadence.
 * The Bayer macro-pixels in one cadence would be stored
 * like so, with PxHi indicating the most significant bits of pixel x,
 * and PxLo indicating the least significant bits of pixel x:
 * @code
 * Bits:                 76543210
 * Scanline n,   byte 0: RRRRRRRR    P1Lo(Red)
 * Scanline n,   byte 1: GGGGGGRR    P2Lo(Green)   & P1Hi(Red)
 * Scanline n,   byte 2: RRRRGGGG    P3Lo(Red)     & P2Hi(Green)
 * Scanline n,   byte 3: GGRRRRRR    P4Lo(Green)   & P3Hi(Red)
 * Scanline n,   byte 4: GGGGGGGG    P4Hi(Green)
 * Scanline n,   byte 5: RRRRRRRR    P5Lo(Red)
 * Scanline n,   byte 6: GGGGGGRR    P6Lo(Green)   & P5Hi(Red)
 * Scanline n,   byte 7: 0000GGGG    4 bits unused & P6Hi(Green)
 * ...and repeats.
 *
 * Scanline n+1, byte 0: GGGGGGGG    P1Lo(Green)
 * Scanline n+1, byte 1: BBBBBBGG    P2Lo(Blue)    & P1Hi(Green)
 * Scanline n+1, byte 2: GGGGBBBB    P3Lo(Green)   & P2Hi(Blue)
 * Scanline n+1, byte 3: BBGGGGGG    P4Lo(Blue)    & P3Hi(Green)
 * Scanline n+1, byte 4: BBBBBBBB    P4Hi(Blue)
 * Scanline n+1, byte 5: GGGGGGGG    P5Lo(Green)
 * Scanline n+1, byte 6: BBBBBBGG    P6Lo(Blue)    & P5Hi(Green)
 * Scanline n+1, byte 7: 0000BBBB    4 bits unused & P6Hi(Blue)
 * ...and repeats.
 * @endcode
 *
 * @note Looking at Scanline n, byte 1, you should see that the P1Hi bits
 *       (the most significant bits of pixel 1) begin at the right of the byte.
 *       The reason is because right justification is indicated by
 *       @c #CAMERA_BAYERJUSTIFY_RIGHT_BIT0LSB. This example is in contrast to Example 2
 *       where the bits are justified to the left, and occupy the upper bits of
 *       Scanline n, byte 1.
 *
 */
typedef struct {
    /**
     * The size of the frame, in bytes.
     */
    uint64_t bufsize;
    /**
     * The height of the frame, in pixels.
     */
    uint32_t height;
    /**
     * The width of the frame, in pixels.
     */
    uint32_t width;
    /**
     * The number of bytes between the first pixel of the first row in memory
     * and the first pixel of the second row in memory.
     * Stride is often called @e pitch.
     */
    uint32_t stride;
    /**
     * The format of the Bayer macro-pixel.
     */
    camera_bayerformat_t format;
    /**
     * The inter-pixel stride, in bits.
     */
    uint32_t packing;
    /**
     * The bits per pixel component inside the packing size.
     */
    uint32_t bpp;
    /**
     * Whether little-endian is used to pack the frame. When @c le is @c true,
     * the bytes are packed in little-endian, otherwise when @c le is @c false,
     * the bytes are packed using big-endian.
     */
    bool le;
    /**
     * The size (in bits) of a packing cadence.
     */
    uint32_t cadence_length;
    /**
     * The number of pixels in a packing cadence.
     */
    uint32_t pixels_per_cadence;
    /**
     * The justification of the pixel bits, For more information
     * see @c ::camera_bayerjustify_t
     */
    camera_bayerjustify_t justification;
    /*...*/
} camera_frame_bayer_t;


/**
 * A frame descriptor for a YCbCr 4:2:2 packed frame type. Use this frame
 * descriptor when @c #CAMERA_FRAMETYPE_CBYCRY is reported as the @c
 * ::camera_frametype_t.
 *
 * Each set of 2 pixel values in the CbYCrY frame is part of a macro-pixel.
 * Each macro-pixel is made up of four components in the following order: a Cb
 * (blue-difference chroma) component, a Y (luma) component, a Cr
 * (red-difference chroma)  component, and a Y (luma) component.  Each
 * macro-pixel is stored contiguously on the same line.
 *
 * A pixel of the CBYCRY macro-pixel consists of a luma (Y) component and an
 * associated chroma (Cb or Cr) component.  Each pixel contains @c bpp bits of
 * component data and is stored in @c packing bits.  The endian order @c le
 * indicates if the bit packing was done in little-endian or big-endian order.
 *
 * For example, @c le = true, @c bpp = 16, and @c packing = 16 describes a
 * macro-pixel stored as follows:
 * @code
 * Bit:          0 1 2 3 4 5 6 7  01234567 0 1 2 3 4 5 6 7  01234567
 * Scanline n:   CbCbCbCbCbCbCbCb YYYYYYYY CrCrCrCrCrCrCrCr YYYYYYYY = 32 bits
 * @endcode
 */
typedef struct {
    /**
     * The size of the buffer as a 64-bit integer.
     */
    uint64_t bufsize;
    /**
     * The height of the image, in pixels.
     */
    uint32_t height;
    /**
     * The width of the image, in pixels.
     */
    uint32_t width;
    /**
     * The number of bytes between the first pixel of the first row in memory
     * and the first pixel of the second row in memory.
     * Stride is often called @e pitch.
     */
    uint32_t stride;
    /**
     * The inter-pixel distance, in bits.
     */
    uint32_t packing;
    /**
     * The number of bits used to encode a pixel value.
     */
    uint32_t bpp;
    /**
     * The endian order used for packing the data. A value of @c true indicates
     * that the bytes are packed using little-endian order, otherwise, a value
     * of @c false indicates that the bytes are packed using big-endian
     * order.
     */
    bool le;
    /*...*/
} camera_frame_cbycry_t;


/**
 * A frame descriptor for compressed video frame types. Use this
 * frame descriptor when @c #CAMERA_FRAMETYPE_COMPRESSEDVIDEO is reported as
 * the @c ::camera_frametype_t.
 */
typedef struct {
    /**
     * The size of the buffer as a 64-bit integer.
     */
    uint64_t bufsize;
    /**
     * The format of the compressed video.
     */
    camera_videocodec_t codec;
    /**
     * A flag indicating whether this frame is a keyframe.
     */
    bool keyframe;
    /**
     * Bitrate expressed in bits per second.
     */
    uint64_t bitrate;
} camera_frame_compressedvideo_t;


/**
 * A frame descriptor for compressed audio frame types. Use this
 * frame descriptor when @c #CAMERA_FRAMETYPE_COMPRESSEDAUDIO is reported as
 * the @c ::camera_frametype_t.
 */
typedef struct {
    /**
     * The size of the buffer as a 64-bit integer.
     */
    uint64_t bufsize;
    /**
     * The format of the compressed audio.
     */
    camera_audiocodec_t codec;
    /**
     * A flag indicating whether this frame is a keyframe.
     */
    bool keyframe;
    /**
     * Number of channels in the audio stream.
     */
    uint32_t channels;
    /**
     * Number of bits per sample per channel.
     */
    uint32_t bits;
    /**
     * Uncompressed sample rate in hertz (Hz).
     */
    uint32_t samplerate;
    /**
     * Bitrate expressed in bits per second.
     */
    uint64_t bitrate;
} camera_frame_compressedaudio_t;


/**
 * A frame descriptor used for Y Cb Cr 4:2:0 planar frame type. Use this frame
 * descriptor when @c #CAMERA_FRAMETYPE_YCBCR420P is reported as the @c
 * ::camera_frametype_t.  The data is organized in memory as follows:
 *  - Y plane (luminance data)  containing 'height' lines of 'width' luminance
 *    values, each line separated by 'y_stride' bytes.
 *  - Cb plane (blue chrominance data) that is located 'cb_offset' bytes after
 *    the start of the Y plane.  It contains 'height'/2 lines of 'width'/2
 *    chroma values, each line separated by 'cb_stride' bytes.
 *  - Cr plane (red chrominance data) that is located 'cr_offset' bytes after
 *    the start of the Y plane.  It contains 'height'/2 lines of 'width'/2
 *    chroma values, each line separated by 'cr_stride' bytes.
 *  - each value (luminance and chrominance) consumes 8-bits
 */
typedef struct {
    /**
     * The height of the frame in pixels.
     */
     uint32_t height;
    /**
     * The width of the frame in pixels.
     */
     uint32_t width;
    /**
     * The number of bytes between the first pixel of a given row in memory
     * and the first pixel of the next row in memory of the luminance (Y)
     * plane. Stride is often called @e pitch.
     */
     uint32_t y_stride;
    /**
     * The number of bytes between the first pixel of the Y plane in memory
     * and the first pixel of the Cb plane in memory.
     */
     int32_t cb_offset;
    /**
     * The number of bytes between the first pixel of a given row in memory
     * and the first pixel of the next row in memory of the Cb plane.
     */
     int32_t cb_stride;
     /**
      * The number of bytes between the first pixel of the Y plane in memory
      * and the first pixel of the Cr plane in memory.
      */
      int32_t cr_offset;
     /**
      * The number of bytes between the first pixel of a given row in memory
      * and the first pixel of the next row in memory of the Cr plane.
      */
      int32_t cr_stride;
} camera_frame_ycbcr420p_t;


/**
 * A frame descriptor for a YCbCr 4:2:2 packed frame type. Use this frame
 * descriptor when @c #CAMERA_FRAMETYPE_YCBYCR is reported as the @c
 * ::camera_frametype_t.
 *
 * Each set of 2 pixel values in the YCbYCr frame is part of a macro-pixel.
 * Each macro-pixel is made up of four components in the following byte order:
 * a Y (luma) component, a Cb (blue-difference chroma) component, a Y (luma)
 * component and a Cr (red-difference chroma) component.  Each macro-pixel is
 * stored contiguously on the same line and each component consumes 8 bits.
 */
typedef struct {
    /**
     * The height of the image, in pixels.
     */
    uint32_t height;
    /**
     * The width of the image, in pixels.
     */
    uint32_t width;
    /**
     * The number of bytes between the first pixel of the first row in memory
     * and the first pixel of the second row in memory.
     * Stride is often called @e pitch.
     */
    uint32_t stride;
} camera_frame_ycbycr_t;


/**
 * A frame descriptor for a YCbCr 4:2:2 packed frame type. Use this frame
 * descriptor when @c #CAMERA_FRAMETYPE_YCRYCB is reported as the @c
 * ::camera_frametype_t.
 *
 * Each set of 2 pixel values in the YCrYCb frame is part of a macro-pixel.
 * Each macro-pixel is made up of four components in the following byte order:
 * a Y (luma) component, a Cr (red-difference chroma) component, a Y (luma)
 * component and a Cb (blue-difference chroma) component.  Each macro-pixel is
 * stored contiguously on the same line and each component consumes 8 bits.
 */
typedef struct {
    /**
     * The height of the image, in pixels.
     */
    uint32_t height;
    /**
     * The width of the image, in pixels.
     */
    uint32_t width;
    /**
     * The number of bytes between the first pixel of the first row in memory
     * and the first pixel of the second row in memory.
     * Stride is often called @e pitch.
     */
    uint32_t stride;
} camera_frame_ycrycb_t;


/**
 * A frame descriptor for a YCbCr 4:2:2 packed frame type. Use this frame
 * descriptor when @c #CAMERA_FRAMETYPE_CRYCBY is reported as the @c
 * ::camera_frametype_t.
 *
 * Each set of 2 pixel values in the CrYCbY frame is part of a macro-pixel.
 * Each macro-pixel is made up of four components in the following byte order:
 * a Cr (red-difference chroma) component, a Y (luma) component, a Cb
 * (blue-difference chroma) component and a Y (luma) component.  Each
 * macro-pixel is stored contiguously on the same line and each component
 * consumes 8 bits.
 */
typedef struct {
    /**
     * The height of the image, in pixels.
     */
    uint32_t height;
    /**
     * The width of the image, in pixels.
     */
    uint32_t width;
    /**
     * The number of bytes between the first pixel of the first row in memory
     * and the first pixel of the second row in memory.
     * Stride is often called @e pitch.
     */
    uint32_t stride;
} camera_frame_crycby_t;


/**
 * A frame descriptor for a region-of-interest (ROI) image frame type. Use this
 * frame descriptor when @c #CAMERA_FRAMETYPE_ROI is reported as the @c
 * ::camera_frametype_t.
 *
 * The width and height of this structure describe the size of the buffer
 * while the ROI width and height describe the size of the image of interest
 * inside this bigger buffer.  The ROI X and Y values describe the offset from
 * the beginning of the buffer to find the image of interest.  The user should
 * access only the ROI within this buffer and ignore the rest of the buffer
 * content.
 *
 * The layout of the pixels within this buffer depends on the @c
 * ::camera_frametype_t reported within this structure as this structure can
 * accomodate multiple pixel layouts. See the description
 * for specified @c ::camera_frametype_t value to understand the
 * pixel layout for this buffer.
 *
 */
typedef struct {
    /**
     * The height of the buffer, in pixels.
     */
    uint32_t height;
    /**
     * The width of the buffer, in pixels.
     */
    uint32_t width;
    /**
     * The height of the image of interest, in pixels.
     */
    uint32_t roi_height;
    /**
     * The width of the image of intrest, in pixels.
     */
    uint32_t roi_width;
    /**
     * The X offset inside of the buffer to the image of interest, in pixels.
     */
    uint32_t roi_x;
    /**
     * The Y offset inside of the buffer to the image of interest, in pixels.
     */
    uint32_t roi_y;
    /**
     * The type describing the layout of pixels within this buffer.
     */
    camera_frametype_t type;
    /**
     * The number of bytes between the first pixel of a given row in memory
     * and the first pixel of the next row in memory of a given plane. Stride
     * is often called @e pitch.  This is an array of 3 stride values to
     * represent the stride to use for each plane of the image.  For images
     * with pixel layout of less than 3 planes, the additional stride values
     * can be ignored.
     */
     uint32_t stride[3];
    /**
     * The number of bytes between the first pixel of the buffer in memory and
     * the first pixel of a given plane in memory.  This is an array of 3
     * offset values to represent the offset to use for each plane of the
     * image.  For images with pixel layout of less than 3 planes, the
     * additional offset values can be ignored.
     */
     int32_t offset[3];
} camera_frame_roi_t;


/**
 * A union that contains all available frame descriptors for the
 * Camera library.
 */
typedef union {
    /**
     * An unknown frame type or unspecified frame type.
     */
    camera_frame_unspecified_t      unspecified;
    /**
     * The @c ::camera_frame_nv12_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_NV12 enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_nv12_t             nv12;
    /**
     * The @c ::camera_frame_rgb8888_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_RGB8888 enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_rgb8888_t          rgb8888;
    /**
     * The @c ::camera_frame_rgb888_t member corresponds to the
     * #CAMERA_FRAMETYPE_RGB888 enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_rgb888_t           rgb888;
    /**
     * For internal use only. Do not use.
     */
    camera_frame_jpeg_t             jpeg;
    /**
     * The @c ::camera_frame_gray8_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_GRAY8 enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_gray8_t            gray8;
    /**
     * The @c ::camera_frame_meta_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_METADATA enumerator in the @c ::camera_frametype_t
     * type.
     */
    camera_frame_meta_t             meta;
    /**
     * The @c ::camera_frame_bayer_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_BAYER enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_bayer_t            bayer;
    /**
     * The @c ::camera_frame_cbycry_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_CBYCRY enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_cbycry_t           cbycry;
    /**
     * The @c ::camera_frame_compressedvideo_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_COMPRESSEDVIDEO enumerator in the @c
     * ::camera_frametype_t type.
     */
    camera_frame_compressedvideo_t  compvid;
    /**
     * The @c ::camera_frame_compressedaudio_t member corresponds to the
     * #CAMERA_FRAMETYPE_COMPRESSEDAUDIO enumerator in the @c
     * ::camera_frametype_t type.
     */
    camera_frame_compressedaudio_t  compaud;
    /**
     * The @c ::camera_frame_rgb565_t member corresponds to the
     * #CAMERA_FRAMETYPE_RGB565 enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_rgb565_t           rgb565;
    /**
     * The @c ::camera_frame_ycbcr420p_t member corresponds to the
     * #CAMERA_FRAMETYPE_YCBCR420P enumerator in the @c ::camera_frametype_t
     * type.
     */
    camera_frame_ycbcr420p_t        ycbcr420p;
    /**
     * The @c ::camera_frame_ycbycr_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_YCBYCR enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_ycbycr_t           ycbycr;
    /**
     * The @c ::camera_frame_ycrycb_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_YCRYCB enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_ycrycb_t           ycrycb;
    /**
     * The @c ::camera_frame_crycby_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_CRYCBY enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_crycby_t           crycby;
    /**
     * The @c ::camera_frame_roi_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_ROI enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_roi_t              roi;
    /**
     * The @c ::camera_frame_nv12_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_NV16 enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_nv12_t             nv16;
    /**
     * The @c ::camera_frame_nv12_t member corresponds to the @c
     * #CAMERA_FRAMETYPE_NV24_Y12 enumerator in the @c ::camera_frametype_t type.
     */
    camera_frame_nv12_t             nv24;
    /*...*/
} camera_framedesc_t;


/**
 * The camera buffer structure is used to convey image data between the API
 * and an application and to adequately describe the format of the image data.
 */
typedef struct {
    /**
     * The type of frame descriptor that is used to distinguish between members
     * of the @c ::camera_framedesc_t union.
     */
    camera_frametype_t      frametype;
    /**
     * The size of the @c ::camera_buffer_t structure.
     *
     * @note This does not describe the size of the image data pointed to
     *       by @c framebuf. The actual image size must be computed using
     *       format-specific fields in the appropriate @c ::camera_framedesc_t member.
     *
     */
    uint64_t                framesize;
    /**
     * A pointer to the frame data.
     */
    uint8_t                *framebuf;
    /**
     * The size of the associated metadata.
     */
    uint64_t                framemetasize;
    /**
     * A pointer to the associated metadata.
     */
    void                   *framemeta;
    /**
     * The timestamp when the buffer was filled. The timestamp is referenced to
     * the system monotonic clock (CLOCK_MONOTONIC) and is in units of
     * micro-seconds.
     */
    int64_t                 frametimestamp;
    /**
     * The rotation delta from the default device orientation. The rotation
     * is measured in degrees, clockwise.
     */
    int32_t                 frameorientation;
    /**
     * For internal use only. Do not use.
     */
    uint32_t                reserved[4];
    /**
     * The union which describes the geometry of the image data being reported
     * by the @c framebuf field in this structure.
     */
    camera_framedesc_t      framedesc;
} camera_buffer_t;


/**
 * The resolution (height and width of an image) in pixels. Use this structure
 * when querying supported resolutions.
 */
typedef struct {
    /**
     * The width of the image in pixels.
     */
    unsigned int            width;
    /**
     * The height of the image in pixels.
     */
    unsigned int            height;
} camera_res_t;


/**
 * The camera access mode flags that are passed to the @c camera_open() function
 * to indicate the type of access that is required.
 * @anonenum camapi_camera_modeflags Camera access mode flags
 */
enum {
    /**
     * Read-access to the camera configuration.
     */
    CAMERA_MODE_PREAD =      1<<0,
    /**
     * Write-access to the camera configuration.
     */
    CAMERA_MODE_PWRITE =     1<<1,
    /**
     * Read-access to the camera imaging datapath (image buffers).
     */
    CAMERA_MODE_DREAD =      1<<2,
    /**
     * Write access to the camera imaging datapath (image buffers).
     */
    CAMERA_MODE_DWRITE =     1<<3,
    /**
     * Access to the camera roll. The camera roll creates uniquely named
     * files in the camera roll directory.
     */
    CAMERA_MODE_ROLL =       1<<4,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_MODE_SHARED =    1<<6,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_MODE_PRIVILEGED = 1<<5,
    /**
     * The application has read-only access to the camera configuration and the
     * camera imaging datapath.
     */
    CAMERA_MODE_RO =         (CAMERA_MODE_PREAD | CAMERA_MODE_DREAD),
    /**
     * The application has read-access and write-access to camera
     * configuration and the camera imaging datapath. Use this as an alias for
     * @c #CAMERA_MODE_PREAD, @c #CAMERA_MODE_PWRITE, @c #CAMERA_MODE_DREAD, and
     * @c #CAMERA_MODE_DWRITE.
     */
    CAMERA_MODE_RW =         (CAMERA_MODE_PREAD | CAMERA_MODE_PWRITE |
                              CAMERA_MODE_DREAD | CAMERA_MODE_DWRITE),
};


/**
 * The supported video file format extensions on the camera roll.
 * These extensions are used only to generate filenames. The actual formatting
 * of the video data is the responsibility of the application writing to the
 * file.
 */
typedef enum {
    /**
     * Use the system-specified default video file format extension.
     */
    CAMERA_ROLL_VIDEO_FMT_DEFAULT = 0,
    /**
     * Compressed video files are saved to the camera roll with an @c .MP4 extension.
     */
    CAMERA_ROLL_VIDEO_FMT_MP4,
    /**
     * Uncompressed video files are saved to the camera roll with an @c .MOV extension.
     */
    CAMERA_ROLL_VIDEO_FMT_MOV,
    /**
     * Uncompressed proprietary video files are saved to the camera roll with an @c .UCV extension.
     */
    CAMERA_ROLL_VIDEO_FMT_UCV,
    /**
     * For internal use only. Do not use.
     */
    CAMERA_ROLL_NUM_VIDEO_FMTS
} camera_roll_video_fmt_t;


/**
 * The maximum length of a string returned for camera location name. The value
 * is useful for you to determine the largest @c char* buffer to allocate.
 */
#define CAMERA_LOCATION_NAMELEN  (64)

/**
 * @brief This enumerated type specifies the camera location properties list
 *
 *        These properties are used as keys for the
 *        @c camera_get_location_property() function.
 *        Each key is associated with a value of the indicated type.
 */
typedef enum {
    /**
     * End-of-list identifier.
     */
    CAMERA_LOCATION_END = 0,
    /**
     * The informal name associated with the location of the camera as a
     * @c const @c char* value.  The string pointed to by this array should be
     * allocated of size @c CAMERA_LOCATION_NAMELEN bytes.
     */
    CAMERA_LOCATION_NAME,
    /**
     * The X-coordinate of the position of the camera, in millimeters. The value
     * is a @c double.
     */
    CAMERA_LOCATION_POSITION_X,
    /**
     * The Y-coordinate of the position of the camera, in millimeters. The value
     * is a @c double.
     */
    CAMERA_LOCATION_POSITION_Y,
    /**
     * The Z-coordinate of the position of the camera, in millimeters.
     * The value is a @c double.
     */
    CAMERA_LOCATION_POSITION_Z,
    /**
     * The orientation of the camera relative to the Z-axis, in degrees. The
     * @c double value represents a counter clockwise rotation.
     */
    CAMERA_LOCATION_YAW,
    /**
     * Deprecated. This value is the same as @c CAMERA_LOCATION_YAW.
     */
    CAMERA_LOCATION_DIRECTION_X = CAMERA_LOCATION_YAW,
    /**
     * The orientation of the camera relative to the Y-axis, in degrees. The @c double value
     * represents a counter clockwise rotation.
     */
    CAMERA_LOCATION_PITCH,
    /**
     * Deprecated. This value is the same as @c CAMERA_LOCATION_PITCH.
     */
    CAMERA_LOCATION_DIRECTION_Y = CAMERA_LOCATION_PITCH,
    /**
     * The orientation of the camera relative to the X-axis, in degrees. The
     * @c double value represents a counter clockwise rotation.
     */
    CAMERA_LOCATION_ROLL,
    /**
     * Deprecated. This value is the same as @c CAMERA_LOCATION_ROLL.
     */
    CAMERA_LOCATION_DIRECTION_Z = CAMERA_LOCATION_ROLL,
    /**
     * Deprecated. This value is the same as @c CAMERA_LOCATION_ROLL.
     */
    CAMERA_LOCATION_ORIENTATION = CAMERA_LOCATION_ROLL
} camera_location_prop_t;

/**
 * @brief This enumerated type specifies the camera frame stats properties.
 *
 *        These properties are used as keys for the
 *        @c camera_get_framestats_property() function.
 *        Each key is associated with a value of the indicated type.
 */
typedef enum {
    /**
     * End-of-list identifier.
     */
    CAMERA_FRAME_STATS_END = 0,
    /**
     * Number of frames dropped. The value is a @c uint64_t.
     */
    CAMERA_FRAME_STATS_DROPPED_COUNT,
    /**
     * Total number of frames captured. The value is a @c uint64_t.
     */
    CAMERA_FRAME_STATS_TOTAL_COUNT
} camera_frame_stats_prop_t;

/**
 * @brief This enumerated type specifies the analog video standard
 *
 *        These properties are used as parameters for the
 *        @c camera_set_analog_video_standard() and @c
 *        camera_get_analog_video_standard functions.
 */
typedef enum {
    /**
     * The NTSC-M and J variants. NTSC-M is the most widely used while NTSC-J
     * is a slight variant used in Japan.
     */
    CAMERA_AVSTANDARD_NTSC_M_J = 1,
    /**
     * The 4.43 variant of NTSC. It uses a 4.43 MHz color sub-carrier instead
     * of the usual 3.58 MHz. This pseudo-color system that transmits NTSC
     * encoding (not a broadcast format).
     */
    CAMERA_AVSTANDARD_NTSC_4_43,
    /**
     * The M variant of the PAL standard. PAL-M is equivalent to NTSC-M except
     * for a slight difference in the color sub-carrier frequency.
     * This PAL format uses 525 lines and 59.94 fields per second;
     * this video standard is used in Brazil.
     */
    CAMERA_AVSTANDARD_PAL_M,
    /**
     * The main variant of the PAL standard.
     * This PAL format uses 625 lines and 50 fields per second with various
     * signal characteristics and color encodings.
     */
    CAMERA_AVSTANDARD_PAL_B_G_H_I_D,
    /**
     * The combination N variant of the PAL standard. This narrow bandwidth
     * PAL format is used in Argentina, Paraguay, and Uruguay.
     */
    CAMERA_AVSTANDARD_PAL_COMBINATION_N,
    /**
     * The 60Hz variant of the PAL format with narrow bandwidth that's used
     * in Argentina, Paraguay, and Uruguay. This multi-system PAL support that
     * uses 525 lines and 60 fields per second (not a broadcast format).
     */
    CAMERA_AVSTANDARD_PAL_60,
    /**
     * The SECAM standard.
     */
    CAMERA_AVSTANDARD_SECAM,
    /**
     * The video standard is automatically detected.
     */
    CAMERA_AVSTANDARD_AUTO
} camera_analog_video_standard_t;


/**
 * This structure is used to identify a subset of pixels in an image.
 * Regions are used to report focus lock positions and to configure
 * region-dependent focus, exposure, and white balance operations.
 */
typedef struct {
    /**
     * The left coordinate of the region. A value of 0 refers to the left-most
     * column of the image.
     */
    uint32_t left;
    /**
     * The top coordinate of the region. A value of 0 refers to the top-most
     * column of the image.
     */
    uint32_t top;
    /**
     * The width of the region in pixels.
     */
    uint32_t width;
    /**
     * The height of the region in pixels.
     */
    uint32_t height;
    /**
     * An additional application-dependent value that can be used to convey
     * extra information about a region. Typically, this extra information may
     * be a weighting, ranking, or other application-specific value to apply
     * when defining a set of regions.
     */
    uint32_t extra;
} camera_region_t;


/**
 * A 32-bit value that represents a unique identifier for a video group.  A new
 * video group is created by calling the function @c
 * camera_create_video_group() function and is released by calling the @c
 * camera_destroy_video_group() function.
 */
typedef int32_t camera_video_group_id_t;


/**
 * A safe-initializer value for a @c ::camera_video_group_id_t. Use this value
 * to check that the correct initialization occurred and whether a call to the
 * @c camera_create_video_group() function was successful. You should use this
 * value to initialize @c camera_video_group_id_t variables, and after you
 * destroy the video group associated with it.
 */
#define CAMERA_VIDEO_GROUP_INVALID              (-1)


/**
 * Camera reference clock type.
 */
typedef enum {
    /**
     * Camera clock is based on @c CLOCK_MONOTONIC.
     */
    CAMERA_REFERENCE_CLOCK_MONOTONIC = 0,
    /**
     * Camera clock is based on @c CLOCK_REALTIME.
     */
    CAMERA_REFERENCE_CLOCK_REALTIME,
    /**
     * Camera clock is based on PTP (Precision Time Protocol) time.
     */
    CAMERA_REFERENCE_CLOCK_PTP,
    /**
     * Camera clock is based on external library.
     */
    CAMERA_REFERENCE_CLOCK_EXTERNAL
} camera_reference_clock_type_t;

/**
 * Camera reference time structure.
 */
typedef struct {
    /**
     * Camera reference clock type.
     */
    camera_reference_clock_type_t   ref_clock_type;
    /**
     * The current time from camera reference clock.
     */
    int64_t                         reference_time;
    /**
     * The monotonic time when the above @ reference_time was retrieved.
     */
    int64_t                         monotonic_time;
} camera_reference_time_t;

/**
 * @brief Retrieve the current build version of the Camera library
 * @details The API build version is useful to ensure that certain calls are
 *          available. You can use the returned value to compare to the @c
 *          #CAMERA_API_VERSION to determine if the runtime library is different
 *          from the version your application was compiled with. Differences
 *          may indicate potential incompatibilities.
 *
 *          For more information about current and previous versions, see
 *          @c #CAMERA_API_VERSION.
 *
 * @return  A value representing the version of the Camera library.
 */
int
camera_get_api_version(void);


/**
 * @brief Request a handle to access a logical camera unit
 * @details If the camera is available, a handle for access to the camera unit
 *          is returned. You must pass in a @c ::camera_handle_t value to store
 *          the handle. You must also have access permissions to use the
 *          camera.
 *
 * @note    There is a limit on the number of handles that can be opened on a
 *          given logical camera unit.  If this limit would be exceeded, this
 *          function will fail and return @c #CAMERA_EAGAIN.  There is also a
 *          limit on the number of handles that an application using this
 *          library can have open.  If this limit would be exceeded, this
 *          function will fail and return @c #CAMERA_EMFILE.  There is also a
 *          limit of only one handle that can be opened on a given logical
 *          camera unit with @c #CAMERA_MODE_PWRITE.  If this limit would be
 *          exceeded, this function will fail and return @c #CAMERA_EBUSY.
 *
 * @param unit The logical camera unit to open.
 * @param mode The access mode of the camera, which is comprised of the
 *             @ref camapi_camera_modeflags flags ORed together.
 * @param handle A pointer to the returned camera handle if access is granted.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_open(camera_unit_t unit,
            uint32_t mode,
            camera_handle_t *handle);


/**
 * @brief Discontinue use of a logical camera on the device
 *
 * @details Any internal resources associated with a previously
 *          opened camera unit are freed.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_close(camera_handle_t handle);


/**
 * @brief Retrieve an enumerated list of cameras available on the device
 * @details An array of camera units is returned in the @c cameras
 *          argument.
 *
 *          Ensure that the @c cameras argument points to an array which has at
 *          least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          cameras argument to @c NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param numasked The requested number of camera units to return in the
 *                 array.
 * @param numsupported A pointer to the number of camera units that you have
 *                     access to. The argument is updated when the function
 *                     completes successfully.
 * @param cameras A pointer to the first element in a @c ::camera_unit_t array.
 *                The array is updated with the cameras that you have access
 *                to when the function completes successfully.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_cameras(unsigned int numasked,
                             unsigned int *numsupported,
                             camera_unit_t *cameras);


/**
 * @brief Retrieve the list of supported viewfinder modes
 * @details Use this function to determine which viewfinder modes can be
 *          selected using the @c camera_set_vf_mode() function.
 *
 *          For more information about about viewfinder
 *          modes, see "Viewfinder mode" in the
 *          @e Camera @e Library @e Developer's @e Guide.
 *
 *          Ensure that the @c modes argument points to an array which has at
 *          least @c numasked elements allocated. To determine an
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
 * @param numasked The requested number of viewfinder modes to return in the
 *                 @c modes array. You can specify a value of 0 to determine the
 *                 number of viewfinder modes supported.
 * @param numsupported A pointer to an integer that is updated with the
 *                     number of viewfinder modes supported.
 * @param modes A pointer to a @c ::camera_vfmode_t array. The array is
 *              updated with the list of viewfinder modes supported.
 *              Ensure that you allocate an array with the
 *              same number of elements as the @c numasked argument.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_vf_modes(camera_handle_t handle,
                              uint32_t numasked,
                              uint32_t *numsupported,
                              camera_vfmode_t *modes);


/**
 * @brief Set the viewfinder mode for a camera
 * @details A viewfinder mode must be selected prior to configuring and starting
 *          the viewfinder. Changing viewfinder modes is not allowed while the
 *          viewfinder is already running.
 *          The @c camera_get_supported_vf_modes() function should be called
 *          prior to setting the viewfinder mode to determine the supported
 *          viewfinder modes.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param mode The desired viewfinder mode to set the camera to.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_vf_mode(camera_handle_t handle,
                   camera_vfmode_t mode);


/**
 * @brief Query the viewfinder mode for a camera
 * @details Use this function to retrieve the currently configured
 *          viewfinder mode.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param mode A pointer to @c ::camera_vfmode_t value in which to return the
 *             current viewfinder mode.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_vf_mode(camera_handle_t handle,
                   camera_vfmode_t *mode);


/**
 * @brief Start the viewfinder on the camera
 * @details Use this function to start the viewfinder on the camera. Only call
 *          this function if the viewfinder mode has been
 *          set to a value other than @c #CAMERA_VFMODE_DEFAULT using @c
 *          camera_set_vf_mode().
 *
 *          Before calling this function, ensure that you:
 *           - Use the @c camera_set_vf_property() function to configure
 *             the viewfinder.
 *           - If @c ::camera_imgprop_createwindow is set to 1, you can create
 *             a screen window to be the parent of the child viewfinder
 *             window that's created by this call.
 *
 *          Once the viewfinder is running, you can adjust zoom levels, and
 *          other camera operations. In addition, you can reposition or resize
 *          the viewfinder window using the Screen API. In order to retrieve
 *          a window handle to the viewfinder window that is created, you must
 *          listen for the appropriate @c SCREEN_EVENT_CREATE event using the
 *          Screen API. For more information, see the "Screen library reference"
 *          in the @e Screen @e Developer's @e Guide.
 *
 * @note It is important that your application follows the guidelines for
 *       resource management described in "Resource management"
 *       in the @e Camera @e Library @e Developer's @e Guide.
 *       If you do not observe these guidelines, your application is at
 *       risk of crashing due to memory access errors when resource
 *       arbitration is performed by the operating system.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param viewfinder_callback A function pointer to a function with the
 *                            following signature:
 * @code
 * void function_name( camera_handle_t,
 *                     camera_buffer_t*,
 *                     void* );
 * @endcode
 *                            The function is a callback that is invoked
 *                            when an image buffer becomes available.
 *                            Set this argument to @c NULL if no function
 *                            needs to be called.
 *                            For information about the callback arguments,
 *                            see "Callback mode" in the
 *                            @e Camera @e Library @e Developer's @e Guide.
 * @param status_callback A function pointer to a function with the following
 *                        signature:
 * @code
 * void function_name( camera_handle_t,
 *                     camera_devstatus_t,
 *                     uint16_t,
 *                     void* );
 * @endcode
 *                        The function is a callback that is invoked when
 *                        status events occur. Set this argument to @c NULL
 *                        if no function needs to be called.
 *                        For information about the callback arguments, see
 *                        "Callback mode" in the
 *                        @e Camera @e Library @e Developer's @e Guide.
 * @param arg The argument passed to all callback functions, which is the
 *            last argument in the callback functions.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_start_viewfinder(camera_handle_t handle,
                        void (*viewfinder_callback)
                             (camera_handle_t, camera_buffer_t*, void*),
                        void (*status_callback)
                             (camera_handle_t, camera_devstatus_t,
                              uint16_t, void*),
                        void *arg);


/**
 * @brief Stop using the viewfinder
 * @details You can stop the viewfinder only after you have successfully
 *          started it using @c camera_start_viewfinder().
 *          After you stop running the viewfinder, you can no longer capture
 *          images or record videos.
 *
  * @param handle The handle returned by a call to the @c camera_open() function.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_stop_viewfinder(camera_handle_t handle);


/**
 * @brief Determine whether a feature is available on the camera
 * @details The availability of a feature does not mean that the feature is
 *          usable. For example, this function may indicate that physical
 *          flash is available, but the feature actually may not be used
 *          until the viewfinder is active. To determine if a feature can be
 *          used in the camera's current state, use the @c camera_can_feature()
 *          function.
 *
 *          Many developers may choose to use the set of available features
 *          in order to determine whether their application will function
 *          properly, or whether a different behaviour may be required. For
 *          example: if @c #CAMERA_FEATURE_VIDEO is not supported, then they
 *          may disable any video mode-switching buttons in their UI.
 *
 * @note The set of available features may vary based on the current
 *       viewfinder mode. For more information, see "Viewfinder mode"
 *       in the @e Camera @e Library @e Developer's @e Guide.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param feature The specific feature to query.
 * @return @c true when the specified feature is available on the camera,
 *         otherwise a value of @c false.
 */
bool
camera_has_feature(camera_handle_t handle,
                   camera_feature_t feature);


/**
 * @brief Determine whether a feature is available on the camera in its
 *        current state
 * @details The difference between this function and the @c
 *          camera_has_feature() function is that this function indicates the
 *          features on the camera are usable in the current
 *          camera state rather than just available.
 *
 *          Many developers may choose to use the set of usable features
 *          to disable specific UI elements in their application.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param feature The specific feature to query.
 * @return @c true when the specified feature is currently usable on the camera,
 *         otherwise a value of @c false.
 */
bool
camera_can_feature(camera_handle_t handle,
                   camera_feature_t feature);


/**
 * @brief Find the cameras that have the specified features
 * @details Use this function to find cameras with the features required for
 *          your application. For example, you can use it to find cameras which
 *          have a flash or that support video recording.
 *
 *          This function provides a list of cameras by implementing an
 *          iterator.
 *
 *          To start iterating through the cameras, set the @c
 *          prevunit argument to @c #CAMERA_UNIT_NONE. Doing so returns the
 *          first camera found by the iterator that supports the list of
 *          features defined by @c features. The matching camera unit is
 *          returned in the @c nextunit argument. To continue iterating through
 *          the list, you can call this function again and set @c prevunit to
 *          the value previously returned by @c nextunit. In this way, the
 *          function is always searching the list using @c prevunit as the
 *          starting point.
 *          When the end of the list is reached, @c nextunit returns a value of
 *          @c #CAMERA_UNIT_NONE.
 *
 * @param features A pointer to an array of @c ::camera_feature_t values.
 * @param nfeatures The number of features specified in the first argument.
 * @param prevunit The previous unit that was returned or @c #CAMERA_UNIT_NONE
 *                 if this is the first call to this function.
 * @param nextunit A pointer to a @c ::camera_unit_t value where the function
 *                 returns the next unit which supports all requested
 *                 features.
 * @return @c #CAMERA_EOK when the function successfully completes.
 *         @c #CAMERA_ENODEV indicates that the end of list was reached.
 */
camera_error_t
camera_find_capable(camera_feature_t *features,
                    int nfeatures,
                    camera_unit_t prevunit,
                    camera_unit_t *nextunit);


/**
 * @brief Retrieve one or more location properties for a given camera
 * @details For the @c args argument, you can provide one or more
 *          property-value pairs using @c ::camera_location_prop_t values as
 *          the name of the property and a pointer to the correct type for the
 *          value such as an @c int or @c double value. For more information
 *          about the correct types to use, see @c ::camera_location_prop_t.
 *          Location information can provide you information in order to
 *          properly identify where each camera is located on the device.
 *
 *          @note There is no type-checking performed by the compiler,
 *                therefore, you must ensure that the value you provide
 *                for each property matches the expected data type. Data type
 *                mismatches can result in undefined behavior and may cause
 *                your application to crash.
 *
 *          You can specify multiple property-value pairs by delimiting them
 *          with a comma as follows:
 * @code
 * camera_get_location_property(CAMERA_UNIT_1,
 *                              CAMERA_LOCATION_NAME, nameString,
 *                              CAMERA_LOCATION_ORIENTATION, &orientation );
 * @endcode
 *
 * @param unit The @c camera_unit_t of the camera you wish to query.
 * @param args... A series of comma-delimited property-value pairs where each
 *                value must be a pointer to a variable of the expected type.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
#define camera_get_location_property(unit, args...)\
        camera_get_location_property_internal(unit, args, CAMERA_LOCATION_END)

/**
 * For internal use only. Do not use. Instead, use
 * @c camera_get_location_property().
 */
camera_error_t
camera_get_location_property_internal(camera_unit_t unit,
                                      ...);


/**
 * @brief Get the list of supported viewfinder resolutions for a given frame type
 * @details After you use this function to retrieve the viewfinder resolutions
 *          that are supported by the camera, you can configure the viewfinder
 *          size using @c camera_set_vf_property().
 *
 *          Ensure that the @c resolutions argument points to an array
 *          that has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          resolutions argument to @c NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param frametype The frame type to query supported the frame rates against.
 * @param numasked The requested number of viewfinder resolutions to return in
 *                 the @c resolutions array. You can use a value of 0 to
 *                 determine the number of viewfinder resolutions
 *                 supported by the camera.
 * @param numsupported The returned number of viewfinder resolutions supported
 *                     by the specified camera.
 * @param resolutions A pointer to a @c ::camera_res_t array. The array
 *                    is updated with the viewfinder resolutions supported by
 *                    the camera. Ensure that you allocate an array with the
 *                    same number of elements as specified in the @c numasked
 *                    argument.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_specified_vf_resolutions(camera_handle_t handle,
                                    camera_frametype_t frametype,
                                    uint32_t numasked,
                                    uint32_t *numsupported,
                                    camera_res_t *resolutions);


/**
 * @brief Get the list of supported viewfinder resolutions for the currently
 *        configured frame type.
 * @details After you use this function to retrieve the viewfinder resolutions
 *          that are supported by the camera, you can configure the viewfinder
 *          size using @c camera_set_vf_property().
 *
 *          Ensure that the @c resolutions argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          resolutions argument to @c NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of viewfinder resolutions to return in
 *                 the @c resolutions array. You can use a value of zero to
 *                 determine the number of viewfinder resolutions
 *                 supported by the camera.
 * @param numsupported The returned number of viewfinder resolutions supported
 *                     by the specified camera.
 * @param resolutions A pointer to a @c ::camera_res_t array. The array
 *                    is updated with the viewfinder resolutions supported by
 *                    the camera. Ensure that you allocate an array with the
 *                    same number of elements as specified in the @c numasked
 *                    argument.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_vf_resolutions(camera_handle_t handle,
                                    uint32_t numasked,
                                    uint32_t *numsupported,
                                    camera_res_t *resolutions);


/**
 * @brief Retrieve the list of supported viewfinder rotation angles
 * @details After you use this function to retrieve the viewfinder rotations
 *          that are supported by the camera, you can configure the viewfinder
 *          rotation using @c camera_set_vf_property().
 *
 *          Typical rotations are multiples of 90 degrees (called square
 *          rotations), such as 0, 90, 180, and 270. For cameras that
 *          support only square rotations, a value of @c false will be
 *          returned in the @c nonsquare argument.
 *
 *          Ensure that the @c rotations argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          rotations argument to @c NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param frametype The frame type to query supported rotations for. Using
 *                  @c #CAMERA_FRAMETYPE_UNSPECIFIED will return the supported
 *                  rotations for the currently configured frame type.
 * @param numasked The requested number of viewfinder rotations to return in the
 *                 @c rotations array. You can use a value of 0 to
 *                 determine the number of viewfinder rotations
 *                 supported by the camera.
 * @param numsupported The returned number of viewfinder rotations supported by
 *                     the specified camera.
 * @param rotations A pointer to a @c uint32_t array. The array
 *                  is updated with the viewfinder rotations supported by
 *                  the camera. Ensure that you allocate an array with the
 *                  same number of elements as specified in the @c numasked
 *                  argument.
 * @param nonsquare  The value updated to reflect whether the camera supports
 *                   rotation of viewfinder images that are not a square angle
 *                   (multiples of 90 degrees).
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_vf_rotations(camera_handle_t handle,
                                  camera_frametype_t frametype,
                                  uint32_t numasked,
                                  uint32_t *numsupported,
                                  uint32_t *rotations,
                                  bool *nonsquare);


/**
 * @brief Retrieve the viewfinder frame types available on the camera
 * @details Use this function to retrieve the viewfinder frame
 *          types supported by the current camera.
 *          The returned formats can be applied to @c #CAMERA_IMGPROP_FORMAT
 *          using the @c camera_set_vf_property() function.
 *
 *          Ensure that the @c frametypes argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          types argument to @c NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of viewfinder frame types to return in
 *                 the @c frametypes array. You can use a value of 0 to
 *                 determine the number of viewfinder frame types
 *                 supported by the camera.
 * @param numsupported The returned number of viewfinder frame types supported
 *                     by the specified camera.
 * @param frametypes A pointer to a @c ::camera_frametype_t array. The array
 *                   is updated with the viewfinder frame types supported by
 *                   the camera. Ensure that you allocate an array with the
 *                   same number of elements as specified in the @c numasked
 *                   argument.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_vf_frame_types(camera_handle_t handle,
                                    uint32_t numasked,
                                    uint32_t *numsupported,
                                    camera_frametype_t *frametypes);


/**
 * @brief Retrieve the supported viewfinder frame rates for the specified
 *        frame type and resolution
 * @details Use this function to retrieve the supported viewfinder frame
 *          rates for the specified resolution and frame type. You can use
 *          the values returned by this function to configure the viewfinder
 *          frame rate using @c camera_set_vf_property().
 *
 *          Ensure that the @c rates argument points to an array
 *          that has at least @c numasked elements allocated. To
 *          determine an appropriate size for this array, you can invoke this
 *          function in @e presizing mode by setting the @c numasked argument to
 *          to zero or the @c rates argument to @c NULL. When the function is
 *          invoked in @e presizing mode, the maximum array size that's
 *          required is returned in the @c numsupported argument. You can then
 *          allocate an array of the appropriate size and invoke the function
 *          again with the @c numasked argument set to the value returned
 *          previously in the @c numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param frametype The frame type to query supported frame rates for. Using
 *                  @c #CAMERA_FRAMETYPE_UNSPECIFIED will return the supported
 *                  frame rates for the currently configured frame type.
 * @param resolution The specified resolution to query for supported frame rates.
 *                   Using a resolution of (0, 0) will return the supported
 *                   frame rates for the currently configured resolution.
 * @param numasked The requested number of frame rates to return in the
 *                 @c rates array. You can use a value of 0 to
 *                 determine the number of viewfinder frame rates
 *                 supported by the camera.
 * @param numsupported The returned number of frame rates supported by the
 *                     specified camera.
 * @param rates A pointer to a @c double array. The array
 *              is updated with the viewfinder frame rates supported by
 *              the camera. Ensure that you allocate an array with the
 *              same number of elements as specified in the @c numasked
 *              argument. If the @c maxmin flag returns @c true, then
 *              the first value returned in the @c rates array is the maximum
 *              supported frame rate, and the second value returned is the
 *              minimum supported frame rate.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c rates argument. This argument is set to @c true if
 *               the values are to be interpreted as a maximum and minimum
 *               value; otherwise, it's set to @c false to indicate that the
 *               values describe only the discrete viewfinder frame rates that
 *               are supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_specified_vf_framerates(camera_handle_t handle,
                                   camera_frametype_t frametype,
                                   camera_res_t resolution,
                                   uint32_t numasked,
                                   uint32_t *numsupported,
                                   double *rates,
                                   bool *maxmin);


/**
 * @brief Retrieve the supported viewfinder frame rates for the specified frame
 *        type.
 * @details Use this function to retrieve the set of supported
 *          viewfinder frame rates that are supported by the currently
 *          configured resolution. You can use the values returned by
 *          this function to configure the viewfinder frame rate using
 *          @c camera_set_vf_property().
 *
 *          Ensure that the @c rates argument points to an array
 *          which has at least @c numasked elements allocated. To
 *          determine an appropriate size for this array, you can invoke this
 *          function in @e presizing mode by setting the @c numasked argument to
 *          to 0 or the @c rates argument to @c NULL. When the function is
 *          invoked in @e presizing mode, the maximum array size that is
 *          required is returned in the @c numsupported argument. You can then
 *          allocate an array of the appropriate size and invoke the function
 *          again with the @c numasked argument set to the value returned
 *          previously in the @c numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param frametype The frame type to query supported frame rates for. Using
 *                  @c #CAMERA_FRAMETYPE_UNSPECIFIED will return the supported
 *                  frame rates for the currently configured frame type.
 * @param numasked The requested number of frame rates to return in the
 *                 @c rates array. You can use a value of 0 to
 *                 determine the number of viewfinder frame rates
 *                 supported by the camera.
 * @param numsupported The returned number of frame rates supported by the
 *                     specified camera.
 * @param rates A pointer to a @c double array. The array
 *              is updated with the viewfinder frame rates supported by
 *              the camera. Ensure that you allocate an array with the
 *              same number of elements as specified in the @c numasked
 *              argument. If the @c maxmin flag returns @c true, then
 *              the first value returned in the @c rates array is the maximum
 *              supported frame rate, and the second value returned is the
 *              minimum supported frame rate.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c rates argument. This argument is set to @c true if
 *               the values are to be interpreted as a maximum and minimum
 *               value; otherwise, it's set to @c false to indicate that the
 *               values describe only the discrete frame rates that are supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_vf_framerates(camera_handle_t handle,
                                   camera_frametype_t frametype,
                                   uint32_t numasked,
                                   uint32_t *numsupported,
                                   double *rates,
                                   bool *maxmin);


/**
 * @brief Configure one or more settings of the viewfinder
 *
 * @details For the @c args argument, you can provide one or more
 *          property-value pairs using @c ::camera_imgprop_t values as the name
 *          of the property and the correct type for the value such as an
 *          @c int or @c double value. The following
 *          @c ::camera_imgprop_t values can be used with this function:
 *           - @c #CAMERA_IMGPROP_WIN_GROUPID
 *           - @c #CAMERA_IMGPROP_WIN_ID
 *           - @c #CAMERA_IMGPROP_CREATEWINDOW
 *           - @c #CAMERA_IMGPROP_RENDERTOWINDOW
 *           - @c #CAMERA_IMGPROP_FORMAT
 *           - @c #CAMERA_IMGPROP_WIDTH
 *           - @c #CAMERA_IMGPROP_HEIGHT
 *           - @c #CAMERA_IMGPROP_FRAMERATE
 *           - @c #CAMERA_IMGPROP_ROTATION
 *           - @c #CAMERA_IMGPROP_HWOVERLAY
 *           - @c #CAMERA_IMGPROP_ISEMBEDDED
 *           - @c #CAMERA_IMGPROP_ZOOMFACTOR
 *           - @c #CAMERA_IMGPROP_VARIABLEFRAMERATE
 *           - @c #CAMERA_IMGPROP_MAXFOV
 *           - @c #CAMERA_IMGPROP_NUMUSERBUFFERS
 *
 *           @note There is no type-checking performed by the compiler,
 *                 therefore, you must ensure that the value you provide
 *                 for each property-value pair matches the expected data
 *                 type. Data type mismatches can result in undefined
 *                 behavior and may cause your application to crash.
 *
 *           You can specify multiple property-value pairs by delimiting them
 *           with a comma as follows:
 * @code
 * camera_set_vf_property( camera_handle,
 *                         CAMERA_IMGPROP_WIN_GROUPID, "mygroup",
 *                         CAMERA_IMGPROP_WIN_ID, "vfwindow",
 *                         CAMERA_IMGPROP_WIDTH, 720,
 *                         CAMERA_IMGPROP_HEIGHT, 1280,
 *                         CAMERA_IMGPROP_ROTATION, 270,
 *                         CAMERA_IMGPROP_FRAMERATE, (double)15.0 );
 * @endcode
 *
 * @note The following properties can't be changed while the viewfinder
 *       is running:
 *       - @c #CAMERA_IMGPROP_WIN_ID
 *       - @c #CAMERA_IMGPROP_CREATEWINDOW
 *       - @c #CAMERA_IMGPROP_FORMAT
 *       - @c #CAMERA_IMGPROP_ISEMBEDDED
 *       - @c #CAMERA_IMGPROP_HWOVERLAY
 *       - @c #CAMERA_IMGPROP_MAXFOV
 *
 *       When the viewfinder is running, then
 *       @c #CAMERA_IMGPROP_WIN_GROUPID can only be changed if the
 *       current value is an empty string.
 *
 *
 * @note The following properties can't be changed while a non-video
 *       viewfinder is running:
 *       - @c #CAMERA_IMGPROP_WIDTH
 *       - @c #CAMERA_IMGPROP_HEIGHT
 *       - @c #CAMERA_IMGPROP_ROTATION
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param args... A series of comma-delimited property-value pairs.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
#define camera_set_vf_property(handle, args...) \
camera_private_set_vf_property(handle, args, CAMERA_IMGPROP_END)


/**
 * For internal use only. Do not use. Instead, use
 * @c camera_set_vf_property().
 */
camera_error_t
camera_private_set_vf_property(camera_handle_t handle, ...);


/**
 * @brief Retrieve one or more properties of the viewfinder
 *
 * @details For the @c args argument, you can provide one or more
 *          property-value pairs using @c ::camera_imgprop_t values as the name
 *          of the property and a pointer to the correct type for the value such
 *          as an @c int or @c double value. The following @c
 *          ::camera_imgprop_t can be used with this function:
 *           - @c #CAMERA_IMGPROP_WIN_GROUPID
 *           - @c #CAMERA_IMGPROP_WIN_ID
 *           - @c #CAMERA_IMGPROP_CREATEWINDOW
 *           - @c #CAMERA_IMGPROP_RENDERTOWINDOW
 *           - @c #CAMERA_IMGPROP_FORMAT
 *           - @c #CAMERA_IMGPROP_WIDTH
 *           - @c #CAMERA_IMGPROP_HEIGHT
 *           - @c #CAMERA_IMGPROP_FRAMERATE
 *           - @c #CAMERA_IMGPROP_ROTATION
 *           - @c #CAMERA_IMGPROP_HWOVERLAY
 *           - @c #CAMERA_IMGPROP_ISEMBEDDED
 *           - @c #CAMERA_IMGPROP_ZOOMFACTOR
 *           - @c #CAMERA_IMGPROP_VARIABLEFRAMERATE
 *           - @c #CAMERA_IMGPROP_MAXFOV
 *           - @c #CAMERA_IMGPROP_NUMUSERBUFFERS
 *
 *           @note There is no type-checking performed by the compiler,
 *                 therefore, you must ensure that the value you provide
 *                 for each property matches the expected data type. Data
 *                 type mismatches can result in undefined
 *                 behavior and may cause your application to crash.
 *
 *           You can specify multiple property-value pairs by delimiting them
 *           with a comma as follows:
 * @code
 * camera_get_vf_property( camera_handle,
 *                         CAMERA_IMGPROP_WIDTH, &vf_width,
 *                         CAMERA_IMGPROP_HEIGHT, &vf_height,
 *                         CAMERA_IMGPROP_ROTATION, &vf_rotation,
 *                         CAMERA_IMGPROP_FRAMERATE, &framerate );
 * @endcode
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param args... A series of comma-delimited property-value pairs where each
 *                value must be a pointer to a variable of the expected type.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
#define camera_get_vf_property(handle, args...) \
camera_private_get_vf_property(handle, args, CAMERA_IMGPROP_END)


/**
 * For internal use only. Do not use. Instead, use
 * @c camera_get_vf_property().
 */
camera_error_t
camera_private_get_vf_property(camera_handle_t handle, ...);


/**
 * @brief Retrieve the supported output resolutions for video
 * @details After you use this function to retrieve the video resolutions that
 *          are supported by the camera, you can configure the video size using
 *          @c camera_set_video_property().
 *
 *          Ensure that the @c resolutions argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          resolutions argument to @c NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of video resolutions to return in the
 *                 @c resolutions array. You can use a value of 0 to
 *                 determine the number of video resolutions
 *                 supported by the camera.
 * @param numsupported The returned number of video resolutions supported by the
 *                     specified camera.
 * @param resolutions A pointer to a @c ::camera_res_t array. The array
 *                    is updated with the video resolutions supported by
 *                    the camera. Ensure that you allocate an array with the
 *                    same number of elements as specified in the @c numasked
 *                    argument.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_video_output_resolutions(camera_handle_t handle,
                                    unsigned int numasked,
                                    unsigned int *numsupported,
                                    camera_res_t *resolutions);


/**
 * @brief Configure the output properties for video recording and encoding
 * @details Ensure that you call this function before you start a video encoding
 *          or recording.
 *
 *          For the @c args argument, you can provide one or more
 *          property-value pairs using @c ::camera_imgprop_t values as the name
 *          of the property and the correct type for the value such as an
 *          @c int or @c double value. The following @c
 *          ::camera_imgprop_t can be used with this function:
 *          - @c #CAMERA_IMGPROP_WIDTH
 *          - @c #CAMERA_IMGPROP_HEIGHT
 *          - @c #CAMERA_IMGPROP_FRAMERATE
 *          - @c #CAMERA_IMGPROP_ROTATION
 *          - @c #CAMERA_IMGPROP_STABILIZATION
 *          - @c #CAMERA_IMGPROP_VIDEOCODEC
 *          - @c #CAMERA_IMGPROP_AUDIOCODEC
 *          - @c #CAMERA_IMGPROP_FORMAT
 *
 *           @note @c #CAMERA_IMGPROP_STABILIZATION may impact the
 *                 field-of-view of the viewfinder. You may want to apply
 *                 this setting prior to starting the viewfinder.
 *
 *
 *           @note There is no type-checking performed by the compiler,
 *                 therefore, you must ensure that the value you provide
 *                 for each property matches the expected data type. Data
 *                 type mismatches can result in undefined
 *                 behavior and may cause your application to crash.
 *
 *           You can specify multiple property-value pairs by delimiting them
 *           with a comma as follows:
 * @code
 * camera_set_video_property( camera_handle,
 *                            CAMERA_IMGPROP_WIDTH, 720,
 *                            CAMERA_IMGPROP_HEIGHT, 1280,
 *                            CAMERA_IMGPROP_ROTATION, 270,
 *                            CAMERA_IMGPROP_FRAMERATE, (double)30.0 );
 *
 * @endcode
 *
 * @note You should determine whether the @c #CAMERA_FEATURE_PREVIEWISVIDEO
 *       property is available using the @c camera_has_feature() function
 *       before configuring the video output properties. If this feature is
 *       available, then the camera does not provide independent video and
 *       viewfinder image streams.
 *
 *       When using such a camera, the @c #CAMERA_IMGPROP_WIDTH, @c
 *       #CAMERA_IMGPROP_HEIGHT, @c #CAMERA_IMGPROP_FORMAT, and
 *       @c #CAMERA_IMGPROP_ROTATION properties
 *       must match the values supplied to the @c camera_set_vf_property()
 *       function. The viewfinder frame rate (the value used for the @c
 *       @c #CAMERA_IMGPROP_FRAMERATE property in the @c
 *       camera_set_vf_property() function) must be an integer multiple
 *       of the video frame rate used in this function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param args... A series of comma-delimited property-value pairs.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
#define camera_set_video_property(handle, args...) \
        _camera_set_video_property(handle, args, CAMERA_IMGPROP_END)


/**
 * For internal use only. Do not use. Instead, use
 * @c camera_set_video_property().
 */
camera_error_t
_camera_set_video_property(camera_handle_t handle,
                           ...);


/**
 * @brief Retrieve the current output properties for video
 *
 * @details For the @c args argument, you can provide one or more
 *          property-value pairs using @c ::camera_imgprop_t values as the name
 *          of the property and a pointer to the correct type for the value such
 *          as an @c int or @c double value. The following @c
 *          ::camera_imgprop_t can be used with this function:
 *           - @c #CAMERA_IMGPROP_WIDTH
 *           - @c #CAMERA_IMGPROP_HEIGHT
 *           - @c #CAMERA_IMGPROP_FRAMERATE
 *           - @c #CAMERA_IMGPROP_ROTATION
 *           - @c #CAMERA_IMGPROP_STABILIZATION
 *           - @c #CAMERA_IMGPROP_VIDEOCODEC
 *           - @c #CAMERA_IMGPROP_AUDIOCODEC
 *           - @c #CAMERA_IMGPROP_FORMAT
 *
 *           @note There is no type-checking performed by the compiler,
 *                 therefore, you must ensure that the value you provide
 *                 for each property matches the expected data type. Data
 *                 type mismatches can result in undefined
 *                 behavior and may cause your application to crash.
 *
 *           You can specify multiple property-value pairs by delimiting them
 *           with a comma as follows:
 * @code
 * camera_get_video_property( camera_handle,
 *                            CAMERA_IMGPROP_WIDTH, &vid_width,
 *                            CAMERA_IMGPROP_HEIGHT, &vid_height,
 *                            CAMERA_IMGPROP_ROTATION, &vid_rotation,
 *                            CAMERA_IMGPROP_FRAMERATE, &vid_framerate );
 * @endcode
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param args... A series of comma-delimited property-value pairs where each
 *                value must be a pointer to a variable of the expected type.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
#define camera_get_video_property(handle, args...) \
        _camera_get_video_property(handle, args, CAMERA_IMGPROP_END)


/**
 * For internal use only. Do not use. Instead, use
 * @c camera_get_video_property().
 */
camera_error_t
_camera_get_video_property(camera_handle_t handle,
                           ...);


/**
 * @brief Performs optional initialization for video recording and encoding
 * @details Calling this function is optional, however, when called once, the
 *          first call to the @c camera_start_video() or @c
 *          camera_start_encode() functions take less time. If this function is
 *          not called, more initialization time is required when you call the
 *          @c camera_start_video() or @c camera_start_encode() functions the
 *          first time.
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_init_video_encoder(void);

/*
 * @brief Maps all viewfinder buffers to caller's process
 * @details Maps all viewfinder buffers to caller's pid, allocating the buffers
 *          if they have not been allocated yet. Information about the mapped
 *          buffers is provided as output to this function. Note that once the
 *          buffers have been premapped, some viewfinder properties such as
 *          resolution and frame type can't be changed.
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param key The callback key returned by a call to the @c camera_enable_viewfinder_event() function.
 * @param buffers On success, the provided array of buffer pointers is filled 
 *                with the addresses of the mapped buffers.
 * @param offsets On success, the provided array of physical address offset is
 *                filled with the physical addresses of the mapped buffers
 * @param size Pointer to return size of the frames pointed to by buffers.
 * @param numasked The number of elements allocated for the provided @c buffers
 *                 and @c offsets arrays.  An error will be returned if these
 *                 arrays are not big enough to accomodate all of the mapped buffers.
 * @param numsupported On success, it is set to the number of mapped viewfinder buffers.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
*/
camera_error_t
camera_premap_viewfinder_buffers(camera_handle_t handle,
                                 camera_eventkey_t key,
                                 void** buffers,
                                 off_t* offsets,
                                 size_t* size,
                                 uint32_t numasked,
                                 uint32_t* numsupported);

/**
 * @brief Start recording video to a file
 * @details This function can only be called if the @c #CAMERA_FEATURE_VIDEO
 *          feature is available. You can determine whether this feature is
 *          available by calling the @c camera_can_feature() function.
 *
 *          The viewfinder must be started in a viewfinder mode that supports
 *          video recording.
 *          For more information about viewfinder modes, see
 *          "Viewfinder mode" in the
 *          @e Camera @e Library @e Developer's @e Guide.
 *
 *          Video is recorded based on the configured properties. The audio
 *          track is recorded from the active audio input on the device.
 *
 * @note Before calling this function, ensure that all required video
 *       encoding properties are set using @c camera_set_video_property().
 *       For more information about encoding configurations, see the
 *       functions in camera_encoder.h.
 *
 *       If you require direct access to the encoded audio and video
 *       bitstreams for applications such as video chat or streaming,
 *       then you should use @c camera_start_encode() instead.
 *
 * @note It is important that your application follows the guidelines for
 *       resource management described in "Resource management" of
 *       the @e Camera @e Library @e Developer's @e Guide.
 *       If you do not observe these guidelines, your application is at
 *       risk of crashing due to memory access errors when resource
 *       arbitration is performed by the operating system.
 *
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param filename The name of the file to save the video to.
 * @param video_callback A function pointer to a function with the following
 *                       signature:
 * @code
 * void function_name( camera_handle_t,
 *                     camera_buffer_t*,
 *                     void* );
 * @endcode
 *                       The function is a callback function to invoke
 *                       when an uncompressed video frame is available.
 *                       You can use @c NULL if no function needs to be called.
 *                       For information about the callback arguments, see
 *                       "Callback mode" in the
 *                       @e Camera @e Library @e Developer's @e Guide.
 * @param status_callback A function pointer to a function with the following
 *                        signature:
 * @code
 * void function_name( camera_handle_t,
 *                     camera_devstatus_t,
 *                     uint16_t,
 *                     void* );
 * @endcode
 *                        The function is a callback that is invoked when
 *                        status events occur. You can use @c NULL if no
 *                        function needs to be called.
 *                        For information about the callback arguments, see
 *                        "Callback mode" in the
 *                       @e Camera @e Library @e Developer's @e Guide.
 * @param arg The argument passed to all callback functions, which is the
 *            last argument in the callback functions.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed. @c #CAMERA_EINVAL is returned if there's
 *         a mismatch in the video properties that were set using @c
 *         camera_set_video_property().
 */
camera_error_t
camera_start_video(camera_handle_t handle,
                   const char *filename,
                   void (*video_callback)(camera_handle_t,
                                          camera_buffer_t*, void*),
                   void (*status_callback)(camera_handle_t, camera_devstatus_t,
                                           uint16_t, void*),
                   void *arg);


/**
 * @brief Stop recording video
 * @details Use this function to stop a video recording that was started
 *          with the @c camera_start_video() function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_stop_video(camera_handle_t handle);


/**
 * @brief Start encoding video
 * @details This function can only be called if the @c #CAMERA_FEATURE_VIDEO
 *          feature is available. You can determine whether this feature is
 *          available by calling the @c camera_can_feature() function.
 *
 *          The viewfinder must be started in a viewfinder mode that supports
 *          video encoding.
 *          For more information about viewfinder modes, see
 *          "Viewfinder mode" in the
 *          @e Camera @e Library @e Developer's @e Guide.
 *
 *          Video is encoded based on the configured properties. The audio
 *          track is encoded from the active audio input on the device.
 *
 * @note Before calling this function, ensure that all required video
 *       encoding properties are set using @c camera_set_video_property().
 *       For more information about encoding configurations, see the
 *       functions in camera_encoder.h.
 *
 * @note It is important that your application follows the guidelines for
 *       resource management described in "Resource management" of the
 *       @e Camera @e Library @e Developer's @e Guide.
 *       If you do not observe these guidelines, your application is at
 *       risk of crashing due to memory access errors when resource
 *       arbitration is performed by the operating system.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param video_callback A function pointer to a function with the following
 *                       signature:
 * @code
 * void function_name( camera_handle_t,
 *                     camera_buffer_t*,
 *                     void* );
 * @endcode
 *                       The function is a callback function that is invoked
 *                       when an uncompressed video frame is available.
 *                       You can use @c NULL if no function needs to be called.
 *                       For information about the callback arguments, see
 *                       "Callback mode" in the
 *                       @e Camera @e Library @e Developer's @e Guide.
 * @param enc_video_callback A function pointer to a function with the following
 *                           signature:
 * @code
 * void function_name( camera_handle_t,
 *                     camera_buffer_t*,
 *                     void* );
 * @endcode
 *                           The function is a callback function that is invoked
 *                           when an encoded video frame is available.
 *                           This argument is mandatory and can't be a @c NULL
 *                           value.
 *                           For information about the callback arguments, see
 *                           "Callback mode" in the
 *                           @e  Camera @e Library @e Developer's @e Guide.
 * @param enc_audio_callback A function pointer to a function with the following
 *                           signature:
 * @code
 * void function_name( camera_handle_t,
 *                     camera_buffer_t*,
 *                     void* );
 * @endcode
 *                           The function is a callback function that is invoked
 *                           when an encoded audio frame is available.
 *                           You can use @c NULL if no function needs to be
 *                           called. For information about the callback
 *                           arguments, see "Callback mode" in the
 *                           @e Camera @e Library @e Developer's @e Guide.
 * @param status_callback A function pointer to a function with the following
 *                        signature:
 * @code
 * void function_name( camera_handle_t,
 *                     camera_devstatus_t,
 *                     uint16_t,
 *                     void* );
 * @endcode
 *                        The function is a callback function that is invoked
 *                        when status events occur. You can use @c NULL if no
 *                        function needs to be called.
 *                        For information about the callback arguments, see
 *                        "Callback mode" in the
 *                        @e Camera @e Library @e Developer's @e Guide.
 * @param arg The argument passed to all callback functions, which is the
 *            last argument in the callback functions.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed. @c #CAMERA_EINVAL is returned if there's
 *         a mismatch in the video properties that were set using @c
 *         camera_set_video_property().
 */
camera_error_t
camera_start_encode(camera_handle_t handle,
                    void (*video_callback)(camera_handle_t,
                                           camera_buffer_t*, void*),
                    void (*enc_video_callback)(camera_handle_t,
                                               camera_buffer_t*, void*),
                    void (*enc_audio_callback)(camera_handle_t,
                                               camera_buffer_t*, void*),
                    void (*status_callback)(camera_handle_t, camera_devstatus_t,
                                            uint16_t, void*),
                    void *arg);


/**
 * @brief Stop encoding video
 * @details Use this function to stop a video recording that was started
 *          with the @c camera_start_encode() function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_stop_encode(camera_handle_t handle);


/**
 * @brief Retrieve the supported range of zoom levels and determine
 *        whether smooth zooming is supported by the camera
 * @details The range returned by this function represent the limits of the zoom
 *          values you can set using @c CAMERA_IMGPROP_ZOOMFACTOR.
 *          Not all cameras support smooth zooming.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param min_level A pointer to an @c int value that is updated with the
 *                  minimal zoom level supported by the camera.
 * @param max_level A pointer to an @c int value that is updated with the
 *                  maximum zoom level supported by the camera.
 * @param smooth A pointer to a boolean value that is updated when the call
 *               completes. A value of @c true indicates that smooth zooming is
 *               supported by the camera.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_zoom_limits(camera_handle_t handle,
                       unsigned int *min_level,
                       unsigned int *max_level,
                       bool *smooth);


/**
 * @brief   Retrieves the zoom ratio corresponding to a given zoom level
 * @details Use this function to retrieve the zoom ratio associated with a given
 *          zoom level. The zoom ratio describes the amount of magnification
 *          applied to the scene. For example: A zoom ratio
 *          of 1.0 indicates that no magnification is being applied to the
 *          scene. A zoom ratio of 2.0 indicates that 1/2 of the width 1/2 of
 *          the height of the scene is pictured when compared to the 1.0 zoom
 *          ratio.
 *
 * @param handle     The handle returned by a call to the @c camera_open()
 *                   function.
 * @param zoom_level The zoom level to retrieve a corresponding zoom ratio for.
 * @param zoom_ratio A pointer to a @c double value which will be set to the
 *                   magnification at the given zoom level.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_zoom_ratio_from_zoom_level(camera_handle_t handle,
                      uint32_t zoom_level,
                      double* zoom_ratio);


/**
 * @brief Create and open the next available video file on the camera roll for
 *        writing
 * @details The camera roll is a directory on the device where the camera
 *          application saves files. The Camera library manages unique
 *          filenames on behalf of the application. Use this function to
 *          retrieve the next available file from the camera roll. You require
 *          @c #CAMERA_MODE_ROLL access mode when you call the @c camera_open()
 *          function to open the camera in order to use this function.
 *
 *          After this function successfully returns, a file is created and
 *          opened for writing. To close the file, you must call the @c
 *          camera_roll_close_video() function.
 *
 *          For information about changing the roll path, see the @c
 *          camera_roll_set_path() function.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param  fd A pointer to the returned open file descriptor. The value that is
 *            returned corresponds to an open video file on the camera roll.
 * @param  filename A pointer to returned name of the file on the camera roll.
 *                  Ensure that the buffer pointed to by filename is the
 *                  same size as specified by @c namelen.
 * @param  namelen The size of the buffer provided by the caller as @c
 *                 filename. The recommended size for filenames is defined by
 *                 @c #CAMERA_ROLL_NAMELEN.
 * @param fmt A @c ::camera_roll_video_fmt_t value indicating the type of file
 *            to create.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_roll_open_video(camera_handle_t handle,
                       int *fd,
                       char *filename,
                       int namelen,
                       camera_roll_video_fmt_t fmt);


/**
 * @brief Close the file descriptor for a video file on the camera roll
 *
 * @details The camera roll is a directory on the device where the camera
 *          application saves files. The Camera library manages unique filenames
 *          on behalf of the application. Use this function to close the file
 *          descriptor that was returned by calling the @c
 *          camera_roll_open_video() function on the camera roll.
 *
 * @param fd The file descriptor for the file on the camera roll to close.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_roll_close_video(int fd);


/**
 * @brief Determines how much space (in bytes) is available for new video files
 *        on the camera roll
 * @details The @c size argument is updated with the amount of free space in
 *          bytes.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param size A pointer that is updated with the number of bytes available
 *             for saving videos.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_roll_available_video(camera_handle_t handle,
                            long long *size);


/**
 * @brief Instruct the video encoder to generate a keyframe on demand when
 *        encoding video
 * @details Typically, you would request a new keyframe when an error occurs
 *          while recording video, such as a network or system error. The new
 *          keyframe allows you to recover from the error as quickly as
 *          possible.
 *
 *          Only call this function after the video encoder has been
 *          started with a call to @c camera_start_video() or
 *          @c camera_start_encode().
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_force_video_keyframe(camera_handle_t handle);


/**
 * @brief Retrieve the configurable rotation angles supported for the encoded
 *        video produced by the camera
 *
 * @details Typical rotations are multiples of 90 degrees (called square
 *          rotations), such as 0, 90, 180, and 270. For cameras that
 *          support only square rotations, a value of @c false will be
 *          returned in the @c nonsquare argument.
 *
 *          The values that you retrieve using this function can be written to
 *          @c #CAMERA_IMGPROP_ROTATION property using the @c
 *          camera_set_video_property() function.
 *
 *          Ensure that the @c rotations argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          rotations argument to NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param frametype The frame type to query supported rotations for. Using
 *                  @c #CAMERA_FRAMETYPE_UNSPECIFIED will return the supported
 *                  rotations for the currently configured frame type.
 * @param numasked The requested number of video rotations to return in the
 *                 @c rotations array. You can use a value of 0 to
 *                 determine the number of rotations supported by the camera.
 * @param numsupported The returned number of video rotations supported by
 *                     the specified camera.
 * @param rotations A pointer to a @c uint32_t array. The array
 *                  is updated with the video rotations supported by
 *                  the camera. Ensure that you allocate an array with the
 *                  same number of elements as specified in the @c numasked
 *                  argument.
 * @param nonsquare  The value updated to reflect whether the camera supports
 *                   rotation of video output images that are not a square angle
 *                   (multiples of 90 degrees).
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_video_rotations(camera_handle_t handle,
                           camera_frametype_t frametype,
                           int numasked,
                           int *numsupported,
                           uint32_t *rotations,
                           bool *nonsquare);


/**
 * @brief Configure the threshold of recording time left on the
 *        device before a warning is issued
 * @details The device has a recording capacity measured in bytes, which can
 *          also be expressed as a number of seconds depending on the encoding
 *          bit-rate. The recording capacity is indicated as seconds of
 *          recording time, which is a reflection of the amount of time left
 *          before a video recording will be stopped. While encoding, there is a
 *          continual estimation of the how many seconds of recording time
 *          remains before the storage device is full.
 *
 *          The camera will deliver a status event to the application with
 *          a value of @c #CAMERA_STATUS_FILESIZE_WARNING when the estimated
 *          amount of time left to record video is less than the value set in
 *          the @c seconds_remaining argument. The status event is delivered to
 *          any status callback functions registered when you called the @c
 *          camera_start_viewfinder() or @c camera_start_video() functions.
 *          The status event will also be delivered via any @c sigevent that you
 *          enabled using the @c camera_enable_status_event() function.
 *          For more information, see "Event mode" and "Callback mode" in the
 *          @e Camera @e Library @e Developer's @e Guide.
 *
 * @note The time remaining that is calculated is an estimate based
 *       on the encoder's past performance and is subject to jitter. For this
 *       reason, the calculated time remaining may not be perfectly accurate.
 *
 *       Typically, an application would set this to five minutes (or 3000
 *       seconds). Once that threshold is crossed, an application would
 *       indicate a low-space warning. You can decide to adjust the threshold
 *       lower to receive additional warnings as the recording time
 *       approaches 0. For example, you could move the threshold to one
 *       minute (60 seconds) for the next warning.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param seconds_remaining The desired threshold (in seconds) remaining in
 *                          a recording when a warning status event will be
 *                          delivered.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_video_filesize_warning(camera_handle_t handle,
                                  uint16_t seconds_remaining);


/**
 * @brief Retrieve the video output frame types available on the camera
 *
 * @details Use this function to retrieve the video output frame
 *          types supported by the current camera.
 *          The returned formats can be applied to @c #CAMERA_IMGPROP_FORMAT
 *          using the @c camera_set_video_property() function.
 *
 *          Ensure that the @c types argument points to an array
 *          which has at least @c numasked elements allocated. To determine an
 *          appropriate size for this array, you can invoke this function in @e
 *          presizing mode by setting the @c numasked argument to 0 or the @c
 *          types argument to @c NULL. When the function is invoked in
 *          this @e presizing mode, the maximum array size required is returned
 *          in the @c numsupported argument. You can then allocate an array of
 *          the appropriate size and invoke the function again with the @c
 *          numasked argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of video output frame types to
 *                 return in the @c types array. You can use a value of 0 to
 *                 determine the number of video output frame types
 *                 supported by the camera.
 * @param numsupported The returned number of video output frame types
 *                     supported by the specified camera.
 * @param types A pointer to a @c ::camera_frametype_t array. The array
 *              is updated with the video output frame types supported by
 *              the camera. Ensure that you allocate an array with the
 *              same number of elements as specified in the @c numasked
 *              argument.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_video_frame_types(camera_handle_t handle,
                             int numasked,
                             int *numsupported,
                             camera_frametype_t *types);


/**
 * @brief Enable the status event
 * @details Use this function to enable the status event. The status event
 *          is delivered whenever there is additional status information to
 *          be reported by the camera. Such status information may include
 *          changes in focus state, whether the camera has powered off,
 *          or other events detailed by the @c ::camera_devstatus_t enumerated
 *          type. After a status event is delivered, you can retrieve specific
 *          details using @c camera_get_status_details().
 *          This is the same status information that is delivered
 *          to your @c status_callback function registered
 *          when you started the viewfinder using @c camera_start_viewfinder(),
 *          or started a capture using @c camera_start_encode() or
 *          @c camera_start_video().
 *
 *          Call this function when you are using this framework in
 *          @e event mode.
 *          For more information, see "Event mode" in the
 *          @e Camera @e Library @e Developer's @e Guide.
 *
 *          Use @c camera_disable_event() to disable an event when you no
 *          longer require status events to be delivered.
 *
 * @note It is not possible to receive status callbacks prior to starting
 *       the viewfinder, since callback functions are attached using
 *       @c camera_start_viewfinder(). Status events, however, may be
 *       enabled at any time after opening the camera.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param key A pointer to a returned @c ::camera_eventkey_t value. This
 *            argument is required for subsequent function calls to identify the
 *            proper event.
 * @param event A pointer to a @c struct @c sigevent. The @c struct @c sigevent
 *              must be initialized by the caller. This is the @c struct
 *              @c sigevent that will be delivered when a status change occurs.
 *              You can then retrieve the specific status details using
 *              @c camera_get_status_details().
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_enable_status_event(camera_handle_t handle,
                           camera_eventkey_t *key,
                           struct sigevent* event);


/**
 * @brief Enable the video event
 * @details Use this function to enable the video event. The video event
 *          is delivered when an uncompressed video frame is available.
 *          You can then retrieve the video frame using @c
 *          camera_get_video_buffers(). This is the same image data that
 *          is delivered to your @c video_callback function registered
 *          when you started video encoding using @c camera_start_video()
 *          or @c camera_start_encode().
 *
 * @note On platforms that advertise the @c #CAMERA_FEATURE_PREVIEWISVIDEO
 *       feature, video frames will be identical to viewfinder frames.
 *
 *          Call this function when you are using the Camera API in
 *          @e event mode.
 *          For more information, see "Event mode" in the
 *          @e Camera @e Library @e Developer's @e Guide.
 *
 *          Use @c camera_disable_event() to disable an event when you no
 *          longer require video events to be delivered.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param eventmode The event buffering mode as a @c ::camera_eventmode_t value.
 * @param key A pointer to a returned @c ::camera_eventkey_t value. This
 *            argument is required for subsequent function calls to identify the
 *            proper event.
 * @param event A pointer to a @c struct @c sigevent. The @c struct @c sigevent
 *              must be initialized by the caller. This is the @c struct
 *              @c sigevent that will be delivered when a video frame is
 *              available to retrieve using @c camera_get_postview_buffers().
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_enable_video_event(camera_handle_t handle,
                          camera_eventmode_t eventmode,
                          camera_eventkey_t *key,
                          struct sigevent* event);


/**
 * @brief Enable the viewfinder event
 * @details Use this function to enable the viewfinder event. The viewfinder
 *          event is delivered when a viewfinder frame is available.
 *          You can then retrieve the viewfinder frame using @c
 *          camera_get_viewfinder_buffers(). This is the same image data that
 *          is delivered to your @c viewfinder_callback function registered
 *          when you started the viewfinder using @c camera_start_viewfinder().
 *
 *          Call this function when you are using the Camera API in
 *          @e event mode.
 *          For more information, see "Callback mode" in the
 *          @e Camera @e Library @e Developer's @e Guide.
 *
 *          Use @c camera_disable_event() to disable an event when you no
 *          longer require viewfinder events to be delivered.
 *
 * @note The viewfinder is automatically rendered to a display by the
 *       operating system. It is not required to provide display code unless
 *       custom output is required using some other mechanism such as
 *       OpenGL.
 *
 * @note    There is a limit in the number of viewfinder events that can be
 *          registered for a given handle.  If this limit is exceeded, the
 *          function will fail and return @c #CAMERA_ENOMEM.  Note as well that
 *          there is a limit of only one viewfinder event of @c
 *          #CAMERA_EVENTMODE_READWRITE per given logical camera unit.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param eventmode The event buffering mode as a @c ::camera_eventmode_t value.
 * @param key A pointer to a returned @c ::camera_eventkey_t value. This
 *            argument is required for subsequent function calls to identify the
 *            proper event.
 * @param event A pointer to a @c struct @c sigevent. The @c struct @c sigevent
 *              must be initialized by the caller. This is the @c struct
 *              @c sigevent that will be delivered when a viewfinder frame is
 *              available to retrieve using @c camera_get_viewfinder_buffers().
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_enable_viewfinder_event(camera_handle_t handle,
                               camera_eventmode_t eventmode,
                               camera_eventkey_t *key,
                               struct sigevent* event);


/**
 * @brief Disable the specified event
 * @details Use this function to disable an event when you no longer want
 *          to receive the event.
 *
 *          For more information, see "Event mode" in the
 *          @e Camera @e Library @e Developer's @e Guide.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param key The key value that was returned by a call to an enable event
 *            function.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_disable_event(camera_handle_t handle,
                     camera_eventkey_t key);


/**
 * @brief Retrieve video buffers from the camera
 * @details Use this function to retrieve buffers with video data. Only call
 *          this function after receiving a video event.
 *
 *          Video events are enabled using @c camera_enable_video_event().
 *          Use the @c camera_return_buffer() when you are finished processing
 *          a buffer.
 *          For more information about event mode, see "Event mode" in the
 *          @e Camera @e Library @e Developer's @e Guide.
 *          For more information about when @c inbuffer and @c outbuffer are
 *          used, see @c ::camera_eventmode_t.
 *
 * @note It is important that your application follows the guidelines for
 *       resource management described in "Resource management" of the
 *       @e Camera @e Library @e Developer's @e Guide.
 *       If you do not observe these guidelines, your application is at
 *       risk of crashing due to memory access errors when resource
 *       arbitration is performed by the operating system.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param key The key value that was returned by a call to the @c
 *            camera_enable_video_event() function.
 * @param inbuffer A pointer to the input @c ::camera_buffer_t struct returned
 *                 by the camera.
 * @param outbuffer A pointer to the output @c ::camera_buffer_t struct returned
 *                  by the camera.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_video_buffers(camera_handle_t handle,
                         camera_eventkey_t key,
                         camera_buffer_t *inbuffer,
                         camera_buffer_t *outbuffer);


/**
 * @brief Retrieve image buffers from the camera
 * @details Use this function to retrieve buffers with viewfinder data. Only
 *          call this function after receiving a viewfinder event.
 *
 *          Viewfinder events are enabled using @c
 *          camera_enable_viewfinder_event().
 *          Use the @c camera_return_buffer() when you are finished processing
 *          a buffer.
 *          For more information about event mode, see "Event mode"
 *          in the @e Camera @e Library @e Developer's @e Guide.
 *          For more information about when @c inbuffer and @c outbuffer are
 *          used, see @c ::camera_eventmode_t.
 *
 * @note It is important that your application follows the guidelines for
 *       resource management described in "Resource management"
 *       of the @e Camera @e Library @e Developer's @e Guide.
 *       If you do not observe these guidelines, your application is at
 *       risk of crashing due to memory access errors when resource
 *       arbitration is performed by the operating system.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param key The key value that was returned by a call to the @c
 *            camera_enable_viewfinder_event() function.
 * @param inbuffer A pointer to the input @c ::camera_buffer_t struct returned
 *                 by the camera.
 * @param outbuffer A pointer to the output @c ::camera_buffer_t struct returned
 *                  by the camera.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_viewfinder_buffers(camera_handle_t handle,
                              camera_eventkey_t key,
                              camera_buffer_t *inbuffer,
                              camera_buffer_t *outbuffer);


/**
 * @brief Retrieve the status details from a status event.
 * @details Use this function to parse device status details from the
 *          @c sigval returned by a status event.
 *
 *          Status events are enabled using @c
 *          camera_enable_status_event().
 *          For more information about event mode, see "Event mode"
 *          in the @e Camera @e Library @e Developer's @e Guide.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param value The @c sigval extracted from the @c struct @c sigevent that was
 *              delivered to your application.
 * @param devstatus The returned device status details. For more information,
 *                  see @c ::camera_devstatus_t.
 * @param devstatusextra The returned extra device status details. For more
 *                       information, see @c ::camera_devstatus_t.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_status_details(camera_handle_t handle,
                          union sigval value,
                          camera_devstatus_t *devstatus,
                          uint16_t *devstatusextra);


/**
 * @brief Return a buffer to the camera
 * @details Use this function to return a buffer back to the camera after you
 *          are finished processing it.
 *          The @c buffer value you provide must be one that was acquired from
 *          the camera using one of the following functions:
 *          - @c camera_get_video_buffers()
 *          - @c camera_get_viewfinder_buffers()
 *          - @c camera_get_image_buffers()
 *          - @c camera_get_postview_buffers()
 *
 * @note Don't return a buffer that was delivered to a callback
 *       function, or was allocated through other means.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param buffer A pointer to a buffer acquired by a call to one of the above
 *               get-buffer functions.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_return_buffer(camera_handle_t handle,
                     camera_buffer_t *buffer);


/**
 * @brief Set the camera roll path
 * @details Use this function to change the directory that the camera uses
 *          to create video files when you call @c camera_roll_open_video().
 *          The value you set for the @c pathname argument must a
 *          NULL-terminated string and must not be larger than @c
 *          #CAMERA_ROLL_NAMELEN.
 *          The path you select must be a directory which your application has
 *          write access to.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param pathname The absolute path to the new camera roll directory as a
 *                 NULL-terminated string.  Specifying an empty string will
 *                 reset the roll path to its default value.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_roll_set_path(camera_handle_t handle,
                     char* pathname);


/**
 * @brief Retrieve the camera roll path
 * @details Use this function to retrieve the camera roll path where
 *          the camera stores video files when @c camera_roll_open_video()
 *          is called.
 *          See also @c camera_roll_set_path().
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param pathname A buffer to receive the NULL-terminated string specifying the
 *                 path to the camera roll.
 * @param pathlen The size of the @c pathname buffer. This should be set to @c
 *                #CAMERA_ROLL_NAMELEN.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_roll_get_path(camera_handle_t handle,
                     char* pathname,
                     int pathlen);


/**
 * @brief Set the suffix to add to filenames generated from the roll
 * @details Use this function to add a specific suffix that will be appended to
 *          all filenames generated using @c camera_roll_open_video() for this
 *          handle.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param suffix The NULL-terminated string to append as a suffix.  Specifying
 *               an empty string will remove the suffix.  The length of the
 *               suffix needs to be less than @c #CAMERA_ROLL_SUFFIXLEN.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_roll_set_filename_suffix(camera_handle_t handle,
                                char* suffix);


/**
 * @brief Verify whether the specified roll video format is supported
 * @details Checks if the specified roll video format is supported for
 *          recording data from the camera associated with the given handle.
 *          Note, that this is based on the current configuration of the
 *          camera, and that the result could be different for a different
 *          configuration.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param format The roll video format to verify.
 * @return @c true when the specified roll video format is supported,
 *         otherwise a value of @c false.
 */
bool
camera_is_roll_format_supported(camera_handle_t handle,
                                camera_roll_video_fmt_t format);


/**
 * @brief Register with the camera resource management component to let the
 *        operating system know that your application may be processing buffers
 * @details For more infomration about the resource management procedure,
 *          see "Resource management" in the
 *          @e Camera @e Library @e Developer's @e Guide.
 *
 *          You should use this function if any of your application code
 *          directly accesses camera buffers, otherwise you risk encountering
 *          memory access errors if buffers are unmapped while you are
 *          referencing them (e.g., saving to disk, image processing, etc.)
 *
 * @note You can call the @c camera_register_resource() function more than
 *       once if you wish to perform cleanup on multiple threads, but
 *       you must call the @c camera_deregister_resource() function the same
 *       number of times when cleaning up.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_register_resource(camera_handle_t handle);


/**
 * @brief Deregister from the camera resource management component
 * @details For more information about resource management procedures,
 *          see "Resource management" in the
 *          @e Camera @e Library @e Developer's @e Guide.
 *
 *          Use this function to indicate to the operating system that your
 *          application is no longer processing camera buffers.
 *          For more information, see @c camera_register_resource().
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_deregister_resource(camera_handle_t handle);


/**
 * @brief Retrieve one or more physical properties of the camera
 * @details For the @c args argument, you can provide one or more
 *          property-value pairs using @c ::camera_physprop_t values as the name
 *          of the property and a pointer to the correct type for the value such
 *          as an @c int or @c double value. For more information about the
 *          correct types to use, see @c ::camera_physprop_t.
 *
 *          @note There is no type-checking performed by the compiler,
 *                therefore, you must ensure that the value you provide
 *                for each property matches the expected data type. Data type
 *                mismatches can result in undefined behavior and may cause
 *                your application to crash.
 *
 *          You can specify multiple property-value pairs by delimiting them
 *          with a comma as follows:
 * @code
 * camera_get_physical_property( camera_handle,
 *                               CAMERA_PHYSPROP_FOCALLENGTH, &focalLength,
 *                               CAMERA_PHYSPROP_HORIZONTALFOV, &horizFov );
 * @endcode
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param args... A series of comma-delimited property-value pairs where each
 *                value must be a pointer to a variable of the expected type.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
#define camera_get_physical_property(handle, args...)\
        _camera_get_physical_property(handle, args, CAMERA_PHYSPROP_END)


/**
 * For internal use only. Do not use. Instead, use
 * @c camera_get_physical_property().
 */
camera_error_t
_camera_get_physical_property(camera_handle_t handle,
                              ...);


/**
 * @brief Verify whether the specified video codec is supported
 * @details Use this function to determine if a given video codec is supported
 *          on the device.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param codec The video codec to verify.
 * @return @c true when the specified video codec is supported by the device,
 *         otherwise a value of @c false.
 */
bool
camera_is_videocodec_supported(camera_handle_t handle,
                               camera_videocodec_t codec);


/**
 * @brief Verify whether a given audio codec is supported
 * @details Use this function to determine if a given audio codec is supported
 *          on the device.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param codec The audio codec to verify.
 * @return @c true when the specified audio codec is supported by the device,
 *         otherwise a value of @c false.
 */
bool
camera_is_audiocodec_supported(camera_handle_t handle,
                               camera_audiocodec_t codec);


/**
 * @brief Determine if the frame type specified allows for window creation
 * @details Before calling @c camera_start_viewfinder() with
 *          @c #CAMERA_IMGPROP_CREATEWINDOW set to true it is recommended to
 *          check if the device/frame type combination allows a window to
 *          be created.
 *
 * @param handle The handle returned by the @c camera_open() function.
 * @param frametype The frame type you want to check if it allows for a
 *                  window to be created.
 * @return @c true when the device allows window creation for the specified
 *         frame type, otherwise a value of @c false.
 */
bool
camera_is_create_window_supported(camera_handle_t handle,
                                  camera_frametype_t frametype);


/**
 * @brief Set the brightness value on the camera
 * @details Use this function to increase or decrease the brightness of the
 *          image. Brightness controls the luminosity of the pixels in an
 *          image. You can call @c camera_get_supported_brightness() to
 *          determine the available brightness values that can be used.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param brightness The brightness value to set. Higher values make the image
 *                   brighter while lower values make the image darker.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_brightness(camera_handle_t handle,
                      int32_t brightness);


/**
 * @brief Retrieve the current brightness value configured on the camera
 * @details Use this function to retrieve the currently configured brightness
 *          value.  See also @c camera_set_brightness().
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param brightness A pointer to a @c int32_t value that is updated with
 *                   the current brightness value.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_brightness(camera_handle_t handle,
                      int32_t *brightness);


/**
 * @brief Retrieve the supported brightness values
 * @details Use this function to retrieve the set of supported brightness
 *          values. You can use the values returned by this function to
 *          configure the brightness using the function @c
 *          camera_set_brightness().
 *
 *          Ensure that the @c values argument points to an array which has at
 *          least @c numasked elements allocated. To determine an appropriate
 *          size for this array, you can invoke this function in @e presizing
 *          mode by setting the @c numasked argument to 0 or the @c values
 *          argument to @c NULL. When the function is invoked in @e presizing
 *          mode, the maximum array size that is required is returned in the
 *          @c numsupported argument. You can then allocate an array of the
 *          appropriate size and invoke the function again with the @c numasked
 *          argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of brightness values to return in the
 *                 @c values array. You can set it to 0 to determine the number
 *                 of brightness values supported by the camera.
 * @param numsupported The returned number of brightness values supported by
 *                     the camera.
 * @param values A pointer to a @c int32_t array. The array is updated with the
 *              brightness values supported by the camera.  Ensure that you
 *              allocate an array with the same number of elements as specified
 *              in the @c numasked argument. If the @c maxmin flag returns @c
 *              true, then the first value returned in the @c values array is
 *              the maximum supported brightness value, and the second value
 *              returned is the minimum supported brightness value.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c values argument. This argument is set to @c true if
 *               the values are to be interpreted as a maximum and minimum
 *               value; otherwise, it's set to @c false to indicate that the
 *               values describe only the discrete brightness values that are
 *               supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_brightness(camera_handle_t handle,
                                uint32_t numasked,
                                uint32_t *numsupported,
                                int32_t *values,
                                bool *maxmin);


/**
 * @brief Set the contrast value on the camera
 * @details Use this function to increase or decrease the contrast of the
 *          image.  Contrast controls the relative difference between pixel
 *          values in an image.  You can call @c
 *          camera_get_supported_contrast() to determine the available contrast
 *          values that can be used.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param contrast The contrast value to set.  Higher values increase the
 *                 contrast in the image while lower values decrease the
 *                 contrast in the image.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_contrast(camera_handle_t handle,
                    int32_t contrast);


/**
 * @brief Retrieve the current contrast value configured on the camera
 * @details Use this function to retrieve the currently configured contrast
 *          value.  See also @c camera_set_contrast().
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param contrast A pointer to a @c int32_t value that is updated with
 *                 the current contrast value.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_contrast(camera_handle_t handle,
                    int32_t *contrast);


/**
 * @brief Retrieve the supported contrast values
 * @details Use this function to retrieve the set of supported contrast values.
 *          You can use the values returned by this function to configure the
 *          contrast using the function @c camera_set_contrast().
 *
 *          Ensure that the @c values argument points to an array which has at
 *          least @c numasked elements allocated. To determine an appropriate
 *          size for this array, you can invoke this function in @e presizing
 *          mode by setting the @c numasked argument to 0 or the @c values
 *          argument to @c NULL. When the function is invoked in @e presizing
 *          mode, the maximum array size that is required is returned in the
 *          @c numsupported argument. You can then allocate an array of the
 *          appropriate size and invoke the function again with the @c numasked
 *          argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of contrast values to return in the
 *                 @c values array. You can set it to 0 to determine the number
 *                 of contrast values supported by the camera.
 * @param numsupported The returned number of contrast values supported by the
 *                     camera.
 * @param values A pointer to a @c int32_ array. The array is updated with the
 *              contrast values supported by the camera.  Ensure that you
 *              allocate an array with the same number of elements as specified
 *              in the @c numasked argument. If the @c maxmin flag returns @c
 *              true, then the first value returned in the @c values array is
 *              the maximum supported contrast value, and the second value
 *              returned is the minimum supported contrast value.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c values argument. This argument is set to @c true if
 *               the values are to be interpreted as a maximum and minimum
 *               value; otherwise, it's set to @c false to indicate that the
 *               values describe only the discrete contrast values that are
 *               supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_contrast(camera_handle_t handle,
                              uint32_t numasked,
                              uint32_t *numsupported,
                              int32_t *values,
                              bool *maxmin);


/**
 * @brief Set the sharpness value on the camera
 * @details Use this function to increase or decrease the sharpness of the
 *          image.  Sharpness controls the intensity of edges in an image.  You
 *          can call @c camera_get_supported_sharpness() to determine the
 *          available sharpness values that can be used.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param sharpness The sharpness value to set.  Higher values increase the
 *                  edge intensities in the image while lower values decrease
 *                  the edge intensities in the image.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_sharpness(camera_handle_t handle,
                     int32_t sharpness);


/**
 * @brief Retrieve the current sharpness value configured on the camera
 * @details Use this function to retrieve the currently configured sharpness
 *          value.  See also @c camera_set_sharpness().
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param sharpness A pointer to a @c int32_t value that is updated with
 *                  the current sharpness value.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_sharpness(camera_handle_t handle,
                     int32_t *sharpness);


/**
 * @brief Retrieve the supported sharpness values
 * @details Use this function to retrieve the set of supported sharpness
 *          values. You can use the values returned by this function to
 *          configure the sharpness using the function @c
 *          camera_set_sharpness().
 *
 *          Ensure that the @c values argument points to an array which has at
 *          least @c numasked elements allocated. To determine an appropriate
 *          size for this array, you can invoke this function in @e presizing
 *          mode by setting the @c numasked argument to 0 or the @c values
 *          argument to @c NULL. When the function is invoked in @e presizing
 *          mode, the maximum array size that is required is returned in the
 *          @c numsupported argument. You can then allocate an array of the
 *          appropriate size and invoke the function again with the @c numasked
 *          argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of sharpness values to return in the
 *                 @c values array. You can set it to 0 to determine the number
 *                 of sharpness values supported by the camera.
 * @param numsupported The returned number of sharpness values supported by the
 *                     camera.
 * @param values A pointer to a @c int32_t array. The array is updated with the
 *              sharpness values supported by the camera.  Ensure that you
 *              allocate an array with the same number of elements as specified
 *              in the @c numasked argument. If the @c maxmin flag returns @c
 *              true, then the first value returned in the @c values array is
 *              the maximum supported sharpness value, and the second value
 *              returned is the minimum supported sharpness value.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c values argument. This argument is set to @c true if
 *               the values are to be interpreted as a maximum and minimum
 *               value; otherwise, it's set to @c false to indicate that the
 *               values describe only the discrete sharpness values that are
 *               supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_sharpness(camera_handle_t handle,
                               uint32_t numasked,
                               uint32_t *numsupported,
                               int32_t *values,
                               bool *maxmin);


/**
 * @brief Set the hue value for the camera
 * @details Use this function to adjust the hue in an image. Hue can be used
 *          to modify the color associated with objects in an image. You can
 *          call @c camera_get_supported_hue() to determine the available hue
 *          values that can be used.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param hue The hue value to set.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_hue(camera_handle_t handle,
               int32_t hue);


/**
 * @brief Retrieve the current hue value configured for the camera
 * @details Use this function to retrieve the currently configured hue value.
 *          See also @c camera_set_hue().
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param hue A pointer to a @c int32_t value that is updated with the
 *            current hue value.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_hue(camera_handle_t handle,
               int32_t *hue);


/**
 * @brief Retrieve the supported hue values
 * @details Use this function to retrieve the set of supported hue values. You
 *          can use the values returned by this function to configure the hue
 *          using the function @c camera_set_hue().
 *
 *          Ensure that the @c values argument points to an array which has at
 *          least @c numasked elements allocated. To determine an appropriate
 *          size for this array, you can invoke this function in @e presizing
 *          mode by setting the @c numasked argument to 0 or the @c values
 *          argument to @c NULL. When the function is invoked in @e presizing
 *          mode, the maximum array size that is required is returned in the
 *          @c numsupported argument. You can then allocate an array of the
 *          appropriate size and invoke the function again with the @c numasked
 *          argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of hue values to return in the @c
 *                 values array. You can set it to 0 to determine the number of
 *                 hue values supported by the camera.
 * @param numsupported The returned number of hue values supported by the
 *                     camera.
 * @param values A pointer to a @c int32_t array. The array is updated with the
 *              hue values supported by the camera.  Ensure that you allocate
 *              an array with the same number of elements as specified in the
 *              @c numasked argument. If the @c maxmin flag returns @c true,
 *              then the first value returned in the @c values array is the
 *              maximum supported hue value, and the second value returned is
 *              the minimum supported hue value.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c values argument. This argument is set to @c true if
 *               the values are to be interpreted as a maximum and minimum
 *               value; otherwise, it's set to @c false to indicate that the
 *               values describe only the discrete hue values that are
 *               supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_hue(camera_handle_t handle,
                         uint32_t numasked,
                         uint32_t *numsupported,
                         int32_t *values,
                         bool *maxmin);


/**
 * @brief Set the saturation value for the camera
 * @details Use this function to adjust the saturation in an image.  Saturation
 *          controls the intensity of the colors in an image. You can call @c
 *          camera_get_supported_saturation() to determine the available
 *          saturation values that can be used.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param saturation The saturation value to set.  Higher values increase the
 *                   intensity of the colors in an image while lower values
 *                   decrease the intensity of the colors in an image.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_saturation(camera_handle_t handle,
                      int32_t saturation);


/**
 * @brief Retrieve the current saturation value configured for the camera
 * @details Use this function to retrieve the currently configured saturation
 *          value.  See also @c camera_set_saturation().
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param saturation A pointer to a @c int32_t value that is updated with
 *                   the current saturation value.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_saturation(camera_handle_t handle,
                      int32_t *saturation);


/**
 * @brief Retrieve the supported saturation values
 * @details Use this function to retrieve the set of supported saturation
 *          values. You can use the values returned by this function to
 *          configure the saturation using the function @c
 *          camera_set_saturation().
 *
 *          Ensure that the @c values argument points to an array which has at
 *          least @c numasked elements allocated. To determine an appropriate
 *          size for this array, you can invoke this function in @e presizing
 *          mode by setting the @c numasked argument to 0 or the @c values
 *          argument to @c NULL. When the function is invoked in @e presizing
 *          mode, the maximum array size that is required is returned in the
 *          @c numsupported argument. You can then allocate an array of the
 *          appropriate size and invoke the function again with the @c numasked
 *          argument set to the value returned previously in the @c
 *          numsupported argument.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param numasked The requested number of saturation values to return in the
 *                 @c values array. You can set it to 0 to determine the number
 *                 of saturation values supported by the camera.
 * @param numsupported The returned number of saturation values supported by
 *                     the camera.
 * @param values A pointer to a @c int32_ array. The array is updated with the
 *              saturation values supported by the camera.  Ensure that you
 *              allocate an array with the same number of elements as specified
 *              in the @c numasked argument. If the @c maxmin flag returns @c
 *              true, then the first value returned in the @c values array is
 *              the maximum supported saturation value, and the second value
 *              returned is the minimum supported saturation value.
 * @param maxmin A pointer to a @c bool value that specifies how to interpret
 *               the @c values argument. This argument is set to @c true if
 *               the values are to be interpreted as a maximum and minimum
 *               value; otherwise, it's set to @c false to indicate that the
 *               values describe only the discrete saturation values that are
 *               supported.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_supported_saturation(camera_handle_t handle,
                                uint32_t numasked,
                                uint32_t *numsupported,
                                int32_t *values,
                                bool *maxmin);


/**
 * @brief Set a property of an analog camera
 * @details Use this function to set a property that is specific to analog
 * cameras using the Video Capture API. A camera needs to support the
 * @c CAMERA_FEATURE_ANALOGCAMERA feature to use this API. This function is equivalent
 * This function is equivalent to calling the function @c capture_set_property_i() from
 * the Video Capture Library. For more information, see the
 * @e Video @e Capture @e Library @e API @e Reference.
 *
 * @note To ensure the proper operation of the camera, the writing of some capture
 *       properties are not permitted because that may interfere with other configurable
 *       properties of the camera. If an attempt to write a property isn't permitted, there
 *       is not effect on the camera and this function returns @c CAMERA_EOPNOTSUPP.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param prop The property to set. See the Video Capture Library in the
 *             @e Video @e Capture @e Developer's @e Guide for the valid
 *             values to use.
 * @param value The value to write for this property.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_capture_property(camera_handle_t handle,
                            uint32_t prop,
                            int32_t value);


/**
 * @brief Get a property of an analog camera
 * @details Use this function to get a property that is specific to analog
 * cameras using the Video Capture Library.  A camera needs to support the
 * @c CAMERA_FEATURE_ANALOGCAMERA feature to use this function.
 * This function is equivalent to calling the function @c capture_get_property_i()
 * from the Video Capture Library. For more information, see the
 * @e Video @e Capture @e Library @e API @e Reference.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param prop The property to retrieve. See the QNX Video Capture Library for
 *             valid values to use.
 * @param value The read value of this property on success.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_capture_property(camera_handle_t handle,
                            uint32_t prop,
                            int32_t *value);


/**
 * @brief Set the analog video standard
 * @details Use this function to set the analog video standard to use for
 * analog cameras.  A camera needs to support the feature @c
 * CAMERA_FEATURE_ANALOGCAMERA in order to support this API.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param standard The analog video standard to set
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_analog_video_standard(camera_handle_t handle,
                                 camera_analog_video_standard_t standard);


/**
 * @brief Get the configured analog video standard
 * @details Use this function to retrieve the configured analog video standard
 * for analog cameras.  A camera needs to support the feature @c
 * CAMERA_FEATURE_ANALOGCAMERA in order to support this API.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param standard The configured analog video standard on success.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_analog_video_standard(camera_handle_t handle,
                                 camera_analog_video_standard_t *standard);


/**
 * @brief Impose a limit to the recorded file size
 * @details A limit can be imposed on any video recording that was started using
 *          @c camera_start_video().  When there is less than a programmed
 *          number of seconds before the file size limit is reached, the
 *          camera will deliver a status event to the application with a value
 *          of @c CAMERA_STATUS_FILESIZE_LIMIT_WARNING.  The camera will stop
 *          the recording when it is estimated that the recording file size
 *          would exceed the file size limit if it would be permitted to
 *          continue recording.  A status event will be sent to the application
 *          with a value of @c CAMERA_STATUS_FILESIZE_ERROR when this occurs.
 *
 *          Note that you can only call this API when an active recording
 *          created by calling @c camera_start_video() is still active.
 *
 *          The status event is delivered to any status callback functions
 *          registered when you called the @c camera_start_viewfinder() or
 *          @c camera_start_video() functions.  The status event will also be
 *          delivered via any @c sigevent that you enabled using the
 *          @c camera_enable_status_event() function.
 *          For more information, see "Event mode" and
 *          "Callback mode" in the
 *          @e Camera @e Library @e Developer's @e Guide
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param size_limit The file size limit to impose in bytes.  Set to 0 to
 *                   disable any previously imposed file size limit.
 * @param prior_warning_seconds Specifies how many seconds prior to the file
 *                              limit being reached to issue the warning status
 *                              event.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_video_filesize_limit(camera_handle_t handle,
                                uint64_t size_limit,
                                uint32_t prior_warning_seconds);


/**
 * @brief Set the filename associated with a camera
 * @details For cameras that support the feature @c #CAMERA_FEATURE_FILENAME, this
 *          function permits to change the file that is used to generate the
 *          simulated content of the camera frames.  The file needs to be an
 *          MP4 file encoded in a video format supported by the platform.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param filename The name of the file to associate with the camera.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_filename(camera_handle_t handle,
                    const char *filename);


/**
 * @brief Retrieve the filename associated with a camera
 * @details For cameras that support the feature @c #CAMERA_FEATURE_FILENAME, this
 *          function permits to retrieve the name of the file that is used to
 *          generate the simulated content of the camera frames.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param filename The name of the file associated with the camera.
 * @param filename_len The size of the buffer provided by the caller as @c
 *                 filename. The recommended size for filenames is defined by
 *                 @c #CAMERA_ROLL_NAMELEN.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_filename(camera_handle_t handle,
                    char *filename,
                    uint32_t filename_len);


/**
 * @brief Create a video group for synchronized video recording/encoding
 * @details A video group permits multiple cameras to start and stop a video
 *          recording or encoding simultaneously.  After creating a video
 *          group, you need to register the camera handles of the cameras that
 *          need to belong to the group by calling @c
 *          camera_add_video_group_entry() for each camera that need to be part
 *          of the group.  Once the video group is no longer required, you need
 *          to call @c camera_destroy_video_group() to release it.
 *
 * @param max_entries The maximum number of entries that can belong to this
 *                    video group at any time.
 * @param group_id On successful creation of the video group, this will be set
 *                 to the group ID that uniquely identifies the created group.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_create_video_group(uint32_t max_entries,
                          camera_video_group_id_t* group_id);


/**
 * @brief Destroy a video group for synchronized video recording/encoding
 * @details This function releases all associations of cameras with the video
 *          group that was created using @c camera_create_video_group() and
 *          then destroys the video group.  After successully calling this
 *          function, the group ID can no longer be used in any other API
 *          function call.
 *
 * @param group_id The ID of the video group to destroy.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_destroy_video_group(camera_video_group_id_t group_id);


/**
 * @brief Associate a camera to a given video group
 * @details This function registers the camera handle of a camera with a video
 *          group that was created using @c camera_create_video_group().  After
 *          the camera is registered, it becomes associated with the video
 *          group and @c camera_start_video() or @c camera_start_encode() no
 *          longer start video encoding right away.  Instead, the video
 *          encoding waits until a call to @c camera_start_video_group(), which
 *          permits all cameras that are associated with a video group to start
 *          recording or encoding video at the same time.
 *
 * @param group_id The ID of the video group.
 * @param handle The camera handle of the camera to register with the group.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_add_video_group_entry(camera_video_group_id_t group_id,
                             camera_handle_t handle);


/**
 * @brief Disassociates a camera from a video group
 * @details This function removes a camera from an association with a video
 *          group that was added using the @c camera_add_video_group_entry().
 *          After a camera has been disassociated from a video group, it can
 *          record and encode video independently from the video group.
 *
 * @param group_id The ID of the video group.
 * @param handle The camera handle of the camera.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_remove_video_group_entry(camera_video_group_id_t group_id,
                                camera_handle_t handle);


/**
 * @brief Start synchronized video encoding/recording of the cameras associated
 *        with the video group.
 * @details This function simultaneously starts all video recording or encoding
 *          for cameras associated with the video group.  Before you call this
 *          function, all cameras that are associated with the video group must
 *          have called @c camera_start_video() or @c camera_start_encode().
 *
 *          To stop video recording or encoding, call @c
 *          camera_stop_video_group().
 *
 * @param group_id The ID of the video group.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_start_video_group(camera_video_group_id_t group_id);


/**
 * @brief Stop synchronized video encoding/recording of the video group
 * @details After having called @c camera_start_video_group() to start the
 *          video recordings and encodings, call this function to
 *          simultaneously stop the recording and encoding of video associated
 *          with the video group.  After having called this function, you will
 *          then need to call @c camera_stop_video() or @c camera_stop_encode()
 *          for all of the cameras associated with the video group to finalize
 *          the video recordings and encodings.
 *
 * @param group_id The ID of the video group.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_stop_video_group(camera_video_group_id_t group_id);


/**
 * @brief Retrieve the screen buffer associated with a camera buffer
 * @details After having called @c camera_start_viewfinder() to start the
 *          viewfinder, call this function to retrieve the screen buffer
 *          associated with a given camera buffer.  The screen buffer is useful
 *          to perform zero-copy of buffers using OpenGL.
 *
 * @param handle The camera handle of the camera.
 * @param camera_buffer The buffer of interest
 * @param screen_buffer On success, it is set to the screen buffer
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_screen_buffer(camera_handle_t handle,
                         camera_buffer_t* camera_buffer,
                         screen_buffer_t* screen_buffer);

/**
 * @brief Set manufacturing information for the camera whose handle is provided
 * @details Writes the provided buffer into non-volatile storage for the camera
 *          whose handle is provided.  The offset and size must not exceed the
 *          amount of storage for the camera.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param buffer A pointer to the buffer of manufacturing information.
 * @param offset Offset at which to write buffer contents.
 * @param size The number of bytes to write to non-volatile storage.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_set_manufacturer_information(camera_handle_t handle,
                                    void* buffer,
                                    uint32_t offset,
                                    uint32_t size);

/**
 * @brief Get manufacturing information for the camera whose handle is provided
 * @details Reads from non-volatile storage for the camera whose handle is
 *          provided into the buffer.  The offset and size must not exceed the
 *          amount of storage for the camera.
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param buffer A pointer to a buffer of at least size bytes that will be
 *               populated with the manufacturing information.
 * @param offset Offset at which to read from device.
 * @param size The number of bytes to read from non-volatile storage.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_manufacturer_information(camera_handle_t handle,
                                    void* buffer,
                                    uint32_t offset,
                                    uint32_t size);

/**
 * @brief Retrieve the camera reference time.
 * @details This function retrieves the type of reference clock configured for this camera,
 *          the current time from this reference clock and the time from @c CLOCK_MONOTONIC
 *          when this reference clock was retrieved.
 *
 * @param handle The handle that's returned from calling @c camera_open().
 * @param ref_time Pointer to @c camera_reference_time_t structure.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_reference_time(camera_handle_t handle,
                          camera_reference_time_t* ref_time);

/**
 * @brief Retrieve one or more frame stats properties for a given camera
 * @details For the @c args argument, you can provide one or more property-value
 *          pairs using @c ::camera_frame_stats_prop_t values as the name of the
 *          property and a pointer to the correct type for the value such as an
 *          @c int or @c double value. For more information about the correct
 *          types to use, see @c ::camera_frame_stats_prop_t. It provides
 *          statistics on how well frames are being received for a given
 *          callback or event. Properties get automatically cleared whenever
 *          this function is called. Typically call it after getting
 *          @c #CAMERA_STATUS_FRAME_DROPPED event; you will not get another such
 *          event until this function is called.
 *
 *          @note There is no type-checking performed by the compiler,
 *                therefore, you must ensure that the value you provide
 *                for each property matches the expected data type. Data type
 *                mismatches can result in undefined behavior and may cause
 *                your application to crash.
 *
 *          You can specify multiple property-value pairs by delimiting them
 *          with a comma as follows:
 * @code
 * camera_get_frame_stats_property(handle,
 *                                 key,
 *                                 CAMERA_FRAME_STATS_DROPPED_COUNT, &droppedFrameCount,
 *                                 CAMERA_FRAME_STATS_TOTAL_COUNT, &totalFrameCount);
 * @endcode
 *
 * @param handle The @c camera_handle_t of the camera you wish to query.
 * @param key The @c camera_eventkey_t of the callback. For callbacks, it is
 *            'extra' field associated with status event; for events, it is
 *            obtained when you register the event.
 * @param args... A series of comma-delimited property-value pairs where each
 *                value must be a pointer to a variable of the expected type.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
#define camera_get_frame_stats_property(handle, key, args...) \
        camera_get_frame_stats_property_internal(handle, key, args, CAMERA_FRAME_STATS_END)

/**
 * For internal use only. Do not use. Instead, use
 * @c camera_get_framestats_property().
 */
camera_error_t
camera_get_frame_stats_property_internal(camera_handle_t handle,
                                         camera_eventkey_t key,
                                         ...);

#ifdef __cplusplus
}
#endif
#endif   /* __CAMERA_API_H__ */



#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/camapi/public/camera/camera_api.h $ $Rev: 899217 $")
#endif
