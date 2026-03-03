/* QNX Camera Primitives API */

#ifndef __CAMERA_PRIM_H__
#define __CAMERA_PRIM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <camera/camera_api.h>
#include <camera/camera_encoder.h>
#include <camera/camera_3a.h>
#include <camera/camera_meta.h>
#include <camera/camera_v3x_api.h>
#include <camera/external_camera_api.h>
#include <camera/camera_magna_api.h>
#include <camera/serdes/serdes_maxim_api.h>

#define CAMERA_ROLL_PHOTO_EXT_JPG "jpg"
#define CAMERA_ROLL_PHOTO_EXT_PNG "png"
#define CAMERA_ROLL_VIDEO_EXT_MP4 "mp4"
#define CAMERA_ROLL_VIDEO_EXT_MOV "mov"
#define CAMERA_ROLL_VIDEO_EXT_UCV "ucv"

/*
 * camera_callbackkey_t: Used to identify an attached reader/filter callback
 */
typedef camera_eventkey_t camera_callbackkey_t;

#define CAMERA_CALLBACKKEY_INVALID      (-1)

#define CAMERA_MAX_OPEN_HANDLES         16

#define CAMERA_MAX_PREMAP_BUF_NUM       64

#define CAMERA_MANU_INFO_BUFFER_SIZE    256

#define CAMERA_MAX_RECORDING_METADATA   512

/*
 * values and functions that have been "privatized" from the camera_api.h file
 */
/* private camera_devstatus_t values */
enum {
    CAMERA_STATUS_PRIVATE = 0x4000,
    /**
     * Indicates request to change the deserializer FSYNC period.
     */
    CAMERA_STATUS_CHANGE_DESERIALIZER_FSYNC_PERIOD,
    /**
     * Indicates request to change the camera output frame rate.
     */
    CAMERA_STATUS_CHANGE_OUTPUT_FRAME_RATE,
    /**
     * End of private status
     */
    CAMERA_STATUS_PRIVATE_END
};

/* private camera_imgprop_t values */
enum {
    CAMERA_IMGPROP_PRIVATE = 0x02000000,  /* WNDPROP starts at 0x40000000 */
    CAMERA_IMGPROP_LTRINTERVAL
};

/* private camera_h264avc_parameters_t values */
enum {
    CAMERA_H264AVC_PRIVATE = 0x02000000,
    CAMERA_H264AVC_LTRINTERVAL
};

/* Flags used to communicate events/statuses from external ISP library to platform class */
enum {
    // ISP dumped the frame to disk
    CAMERA_FRAME_DUMPED = 0x00000001
};

/**
 * @private
 */

camera_error_t
camera_push_status_notification(camera_handle_t handle,
                                camera_devstatus_t status,
                                uint16_t extra);


/**
 * @brief Retrieve the size of the frame buffer based on the frame type
 * @details You pass the size of the frame buffer using the @c buf parameter.
 *          This function is a helper function that returns the extents of the
 *          image data based on the frame-type that is indicated in the
 *          descriptor.
 *
 * @param buf A pointer to the framebuffer.
 * @param size A pointer to a 64-bit integer that is updated with the
 *             size of the framebuffer when the function completes
 *             successfully.
 * @return @c CAM_EOK when the function successfully completes, otherwise
 *         another @c camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_get_framebuf_size(camera_buffer_t *buf,
                         uint64_t *size);


/**
 * The maximum length of a filename supported by the camera library.
 */
#define CAMERA_MAX_FILENAME_LEN   (CAMERA_ROLL_NAMELEN)



/*
 * camera_param_t: Camera Parameters enumeration
 * A growing list of parameter identifiers.  Used to query availability of features and set/get operating parameters.
 *
 * Another quick note about parameters is that each parameter can have different types of data associated (see camera_paramval_t).
 * Convenience wrappers can be provided for common parameters which hide some of these details away from the user.
 */
typedef enum {
    CAMERA_PARAM_FIRSTPARAM = 0,
    CAMERA_PARAM_UNIT = CAMERA_PARAM_FIRSTPARAM,
    CAMERA_PARAM_EXISTS,
    CAMERA_PARAM_STATUS,
    CAMERA_PARAM_ISP_CONFIGURATION,
    CAMERA_PARAM_PREALLOCATE_MEM,
    CAMERA_PARAM_VF_TYPE,
    CAMERA_PARAM_UNUSED6,
    CAMERA_PARAM_UNUSED7,
    CAMERA_PARAM_VIDEOVFCONFIG,
    CAMERA_PARAM_ZOOM,
    CAMERA_PARAM_MAX_ZOOM,
    CAMERA_PARAM_MIN_ZOOM,
    CAMERA_PARAM_UNUSED12,
    CAMERA_PARAM_UNUSED13,
    CAMERA_PARAM_UNUSED14,
    CAMERA_PARAM_UNUSED15,
    CAMERA_PARAM_UNUSED16,
    CAMERA_PARAM_UNUSED17,
    CAMERA_PARAM_UNUSED18,
    CAMERA_PARAM_FRAME_STATS,
    CAMERA_PARAM_VF_MODE,
    CAMERA_PARAM_SUPPORTED_VF_MODES,
    CAMERA_PARAM_VF_CONFIG,
    CAMERA_PARAM_UNUSED23,
    CAMERA_PARAM_UNUSED24,
    CAMERA_PARAM_NUMVIDEOCAPTURERES,
    CAMERA_PARAM_NUMVIDEOPREVIEWRES,
    CAMERA_PARAM_LOG_TRACKER,
    CAMERA_PARAM_FILENAME,
    CAMERA_PARAM_UNUSED29,
    CAMERA_PARAM_UNUSED30,
    CAMERA_PARAM_FEATURES,
    CAMERA_PARAM_FEATURESNOW,
    CAMERA_PARAM_QUERYVIDEOFORMAT,
    CAMERA_PARAM_UNUSED34,
    CAMERA_PARAM_UNUSED35,
    CAMERA_PARAM_UNUSED36,
    CAMERA_PARAM_VIDEOOUTPUTCONFIG,
    CAMERA_PARAM_FORCESTATUSNOTIFY,
    CAMERA_PARAM_UNUSED39,
    CAMERA_PARAM_UNUSED40,
    CAMERA_PARAM_FOCUSSTATE,
    CAMERA_PARAM_ROLLPHOTOPATH,
    CAMERA_PARAM_ROLLVIDEOPATH,
    CAMERA_PARAM_FOCUSMODE,
    CAMERA_PARAM_NUMFOCUSREGIONS,
    CAMERA_PARAM_MANUALFOCUSSTEP,
    CAMERA_PARAM_UNUSED47,
    CAMERA_PARAM_VIDEOVFROTATIONS,
    CAMERA_PARAM_UNUSED49,
    CAMERA_PARAM_VIDEOROTATIONS,
    CAMERA_PARAM_UNUSED51,
    CAMERA_PARAM_UNUSED52,
    CAMERA_PARAM_RESOURCEINUSE,
    CAMERA_PARAM_CAMERATYPE,
    CAMERA_PARAM_UNUSED55,
    CAMERA_PARAM_UNUSED56,
    CAMERA_PARAM_UNUSED57,
    CAMERA_PARAM_SETFOCUSREGION,
    CAMERA_PARAM_MAXNUMFOCUSREGIONS,
    CAMERA_PARAM_3ALOCK,
    CAMERA_PARAM_MAXMANUALFOCUSSTEP,
    CAMERA_PARAM_UNUSED62,
    CAMERA_PARAM_UNUSED63,
    CAMERA_PARAM_UNUSED64,
    CAMERA_PARAM_UNUSED65,
    CAMERA_PARAM_UNUSED66,
    CAMERA_PARAM_3ALOCKMODES,
    CAMERA_PARAM_FOCUSMODES,
    CAMERA_PARAM_UNUSED69,
    CAMERA_PARAM_VIDEOVF_FRAMETYPES,
    CAMERA_PARAM_UNUSED71,
    CAMERA_PARAM_UNUSED72,
    CAMERA_PARAM_EXPOSUREMODE,
    CAMERA_PARAM_EXPOSUREMODES,
    CAMERA_PARAM_WHITEBALANCEMODE,
    CAMERA_PARAM_WHITEBALANCEMODES,
    CAMERA_PARAM_UNUSED77,
    CAMERA_PARAM_VIDEOVF_FRAMERATES,
    CAMERA_PARAM_UNUSED79,
    CAMERA_PARAM_UNUSED80,
    CAMERA_PARAM_UNUSED81,
    CAMERA_PARAM_UNUSED82,
    CAMERA_PARAM_UNUSED83,
    CAMERA_PARAM_UNUSED84,
    CAMERA_PARAM_UNUSED85,
    CAMERA_PARAM_UNUSED86,
    CAMERA_PARAM_UNUSED87,
    CAMERA_PARAM_NUMEXPOSUREREGIONS,
    CAMERA_PARAM_SETEXPOSUREREGION,
    CAMERA_PARAM_MAXNUMEXPOSUREREGIONS,
    CAMERA_PARAM_NUMWHITEBALANCEREGIONS,
    CAMERA_PARAM_SETWHITEBALANCEREGION,
    CAMERA_PARAM_MAXNUMWHITEBALANCEREGIONS,
    CAMERA_PARAM_UNUSED88,
    CAMERA_PARAM_RESOURCEPID,
    CAMERA_PARAM_PHYSPARAMS,
    CAMERA_PARAM_UNUSED97,
    CAMERA_PARAM_UNUSED98,
    CAMERA_PARAM_UNUSED99,
    CAMERA_PARAM_UNUSED100,
    CAMERA_PARAM_UNUSED101,
    CAMERA_PARAM_UNUSED102,
    CAMERA_PARAM_UNUSED103,
    CAMERA_PARAM_UNUSED104,
    CAMERA_PARAM_VIDEOENCODER_PARAMETER_VALUES,
    CAMERA_PARAM_VIDEOCODEC_SUPPORT,
    CAMERA_PARAM_UNUSED107,
    CAMERA_PARAM_WHITEBALANCEVALUE,
    CAMERA_PARAM_SUPPORTED_WHITEBALANCEVALUES,
    CAMERA_PARAM_ISOVALUE,
    CAMERA_PARAM_SUPPORTED_ISOVALUES,
    CAMERA_PARAM_SHUTTERSPEED,
    CAMERA_PARAM_SUPPORTED_SHUTTERSPEEDS,
    CAMERA_PARAM_APERTUREVALUE,
    CAMERA_PARAM_SUPPORTED_APERTUREVALUES,
    CAMERA_PARAM_EVOFFSET,
    CAMERA_PARAM_SUPPORTED_EVOFFSETS,
    CAMERA_PARAM_UNUSED118,
    CAMERA_PARAM_UNUSED119,
    CAMERA_PARAM_VIDEOENCODERCONFIG_SUPPORT,
    CAMERA_PARAM_UNUSED121,
    CAMERA_PARAM_UNUSED122,
    CAMERA_PARAM_UNUSED123,
    CAMERA_PARAM_UNUSED124,
    CAMERA_PARAM_UNUSED125,
    CAMERA_PARAM_UNUSED126,
    CAMERA_PARAM_UNUSED127,
    CAMERA_PARAM_VIDEO_FRAMETYPES,
    CAMERA_PARAM_UNUSED129,
    CAMERA_PARAM_ZOOM_RATIO,
    CAMERA_PARAM_UNUSED131,
    CAMERA_PARAM_UNUSED132,
    CAMERA_PARAM_UNUSED133,
    CAMERA_PARAM_UNUSED134,
    CAMERA_PARAM_UNUSED135,
    CAMERA_PARAM_UNUSED136,
    CAMERA_PARAM_LOCATION,
    CAMERA_PARAM_BRIGHTNESS,
    CAMERA_PARAM_SUPPORTED_BRIGHTNESS,
    CAMERA_PARAM_CONTRAST,
    CAMERA_PARAM_SUPPORTED_CONTRAST,
    CAMERA_PARAM_SHARPNESS,
    CAMERA_PARAM_SUPPORTED_SHARPNESS,
    CAMERA_PARAM_HUE,
    CAMERA_PARAM_SUPPORTED_HUE,
    CAMERA_PARAM_SATURATION,
    CAMERA_PARAM_SUPPORTED_SATURATION,
    CAMERA_PARAM_CAPTURE_PROPERTY,
    CAMERA_PARAM_ANALOG_VIDEO_STANDARD,
    CAMERA_PARAM_SUPPORTED_WHITEBALANCE_RB_GAIN,
    CAMERA_PARAM_WHITEBALANCE_RB_GAIN,
    CAMERA_PARAM_CREATE_WINDOW_VALID,
    CAMERA_PARAM_MANUFACTURING_INFO,
    CAMERA_PARAM_REFERENCE_TIME,
    CAMERA_PARAM_RECORDED_METADATA,
    CAMERA_PARAM_POWER_MODE,
    CAMERA_PARAM_RECONNECT_MODE,
    CAMERA_PARAM_PRBS_TEST,
    CAMERA_PARAM_DESERIALIZER_PARAM,
    CAMERA_PARAM_SERIALIZER_PARAM,
    /* add new parameters above this line */
    CAMERA_PARAM_NUMPARAMS
} camera_param_t;


/*
 * camera_param_vf_type_t: viewfinder mode parameter
 */
typedef enum {
    CAMERA_VF_TYPE_OFF = 0,
    CAMERA_VF_TYPE_PHOTO,
    CAMERA_VF_TYPE_VIDEO
} camera_param_vf_type_t;


#define CAMERA_ID_STRING_LENGTH 512
/*
 * camera_param_vfconfig_t: viewfinder config parameter structure
 */
typedef struct {
    uint64_t propertyBitmap;
    uint64_t windowPropertyBitmap;
    char windowId[CAMERA_ID_STRING_LENGTH];
    char groupId[CAMERA_ID_STRING_LENGTH];
    double framerate;
    bool burst;
    bool variableFramerate;
    double minFramerate;
    int32_t pic_w;
    int32_t pic_h;
    int32_t rotation;
    int32_t zoomFactor;
    bool hwOverlay;
    camera_frametype_t frameType;
    int32_t wnd_x;
    int32_t wnd_y;
    int32_t wnd_zorder;
    int32_t wnd_width;
    int32_t wnd_height;
    int32_t wnd_rotation;
    int32_t wnd_mirror;
    int32_t wnd_visible;
    int32_t isembedded;
    int32_t wnd_isfloating;
    int32_t wnd_idlemode;
    int32_t wnd_apply_changes; // boolean; service will update the window only if set to 1
    int32_t wnd_isapplication;
    bool maxFov;
    bool renderToWindow;
    camera_vfmode_t mode;
    camera_param_vf_type_t vf_type;
    bool createWindow;
    uint32_t numUserBuffers;
} camera_param_vfconfig_t;


/*
 * camera_h264avc_config_t: configuration of the video output
 */
typedef struct {
    camera_h264avc_slicetype_t sliceType;
    camera_h264avc_profile_t profile;
    camera_h264avc_level_t level;
    camera_h264avc_entropycoding_t entropyCoding;
    camera_h264avc_ratecontrol_t rateControl;
    int qpI;
    int qpP;
} camera_h264avc_config_t;

/*
 * camera_videoencoder_config_t: configuration of the video encoder
 */
typedef union {
    camera_h264avc_config_t h264avc;
} camera_videoencoder_config_t;

/*
 * camera_param_videooutputconfig_t: configuration of the video output
 */
typedef struct {
    unsigned int pic_w;
    unsigned int pic_h;
    int rotation;
    double framerate;
    unsigned int ltrInterval;
    unsigned int keyFrameInterval;
    unsigned int bitrate;
    unsigned int sliceSize;
    unsigned int stabilization;
    camera_videocodec_t videoCodec;
    camera_audiocodec_t audioCodec;
    camera_videoencoder_config_t videoEncoderConfig;
    bool useDesktopAudio;
    camera_frametype_t frameType;
} camera_param_videooutputconfig_t;


/*
 * camera_minmax_u: a generic min/max union
 */
typedef union {
    uint32_t val_uint32_t;
    int32_t val_int32_t;
    uint64_t val_uint64_t;
    int64_t val_int64_t;
    float val_float;
    double val_double;
} camera_minmax_u;


/*
 * camera_param_zoom_t: zoom setting
 */
typedef struct {
    int32_t factor;
    bool smooth;
} camera_param_zoom_t;


/*
 * camera_param_featurebitmap_t: service+device feature bitmap
 * encodes up to 256 individual feature bits.  extend as necessary.
 */
typedef struct {
    uint32_t fbm[8];
} camera_param_featurebitmap_t;


/*
 * camera_param_statusnotify_t: force a status event
 */
typedef struct {
    camera_devstatus_t status;
    uint16_t extra;
} camera_param_statusnotify_t;


/*
 * camera_param_focusstate_t: report focus state
 */
typedef struct {
    camera_focusstate_t state;
    uint32_t left;
    uint32_t top;
    uint32_t width;
    uint32_t height;
} camera_param_focusstate_t;


/*
 * camera_param_rotations_t: report available rotations.
 */
typedef struct {
    int numrotations;
    uint32_t rotations[4];
    bool nonsquare;
    camera_frametype_t frametype;
} camera_param_rotations_t;


/*
 * camera_param_3alockmodes_t: report available 3a lock modes.
 */
typedef struct {
    int nummodes;
    uint32_t modes[8];  /* max of 8 permutations possible with 3 modes (2^3) */
} camera_param_3alockmodes_t;

/*
 * camera_param_focusmodes_t: report available focusmodes
 */
typedef struct {
    int nummodes;
    camera_focusmode_t modes[CAMERA_FOCUSMODE_NUMFOCUSMODES];
} camera_param_focusmodes_t;

typedef struct {
    int num_modes;
    camera_vfmode_t modes[CAMERA_VFMODE_NUM_MODES];
} camera_param_vf_modes_t;

/*
 * camera_param_framerates_maxmin: an enum which describes the order of values
 * returned in camera_param_framerates_t if maxmin=true
 */
enum camera_param_framerates_maxmin {
    CAMERA_PARAM_FRAMERATES_MAX_INDEX = 0,
    CAMERA_PARAM_FRAMERATES_MIN_INDEX = 1,
    CAMERA_PARAM_FRAMERATES_NUMRATES = 100 // some arbitrary maximum
};

/*
 * camera_param_framerates_t: report available frame rates
 */
typedef struct {
    int numrates;
    bool maxmin;
    float rates[CAMERA_PARAM_FRAMERATES_NUMRATES];  // using float here to save space vs double
    camera_frametype_t frametype;
    camera_res_t resolution;
} camera_param_framerates_t;

/*
 * camera_param_exposuremodes_t: report available exposure modes
 */
typedef struct {
    int nummodes;
    camera_exposuremode_t modes[CAMERA_EXPOSUREMODE_NUMEXPOSUREMODES];
} camera_param_exposuremodes_t;

/*
 * camera_param_whitebalancemodes_t: report available white-balance modes
 */
typedef struct {
    int nummodes;
    camera_whitebalancemode_t modes[CAMERA_WHITEBALANCEMODE_NUMWHITEBALANCEMODES];
} camera_param_whitebalancemodes_t;

/*
 * camera_param_whitebalancevalues_maxmin: an enum which describes the order of values
 * returned in camera_param_whitebalancevalues_t if maxmin=true
 */
enum camera_param_whitebalancevalues_maxmin {
    CAMERA_PARAM_WHITEBALANCEVALUES_MAX_INDEX = 0,
    CAMERA_PARAM_WHITEBALANCEVALUES_MIN_INDEX = 1,
    CAMERA_PARAM_WHITEBALANCEVALUES_NUMVALUES = 100 // some arbitrary maximum
};

/*
 * camera_param_whitebalancevalues_t: report available white balance values
 */
typedef struct {
    int numvalues;
    bool maxmin;
    unsigned values[CAMERA_PARAM_WHITEBALANCEVALUES_NUMVALUES];
} camera_param_whitebalancevalues_t;

/*
 * camera_param_whitebalancecolorgains_t: white balance color gains (red and blue)
 */
typedef struct {
    uint32_t redGain;
    uint32_t blueGain;
} camera_param_whitebalance_colorgains_t;

/*
 * camera_param_isovalues_maxmin: an enum which describes the order of values
 * returned in camera_param_isovalues_t if maxmin=true
 */
enum camera_param_isovalues_maxmin {
    CAMERA_PARAM_ISOVALUES_MAX_INDEX = 0,
    CAMERA_PARAM_ISOVALUES_MIN_INDEX = 1,
    CAMERA_PARAM_ISOVALUES_NUMVALUES = 100 // some arbitrary maximum
};

/*
 * camera_param_isovalues_t: report available iso values
 */
typedef struct {
    int numvalues;
    bool maxmin;
    unsigned values[CAMERA_PARAM_ISOVALUES_NUMVALUES];
} camera_param_isovalues_t;

/*
 * camera_param_shutterspeeds_maxmin: an enum which describes the order of values
 * returned in camera_param_shutterspeeds_t if maxmin=true
 */
enum camera_param_shutterspeeds_maxmin {
    CAMERA_PARAM_SHUTTERSPEEDS_MAX_INDEX = 0,
    CAMERA_PARAM_SHUTTERSPEEDS_MIN_INDEX = 1,
    CAMERA_PARAM_SHUTTERSPEEDS_NUMSPEEDS = 100 // some arbitrary maximum
};

/*
 * camera_param_shutterspeeds_t: report available shutter speeds
 */
typedef struct {
    int numvalues;
    bool maxmin;
    double values[CAMERA_PARAM_SHUTTERSPEEDS_NUMSPEEDS];
} camera_param_shutterspeeds_t;

/*
 * camera_param_aperturevalues_maxmin: an enum which describes the order of values
 * returned in camera_param_aperturevalues_t if maxmin=true
 */
enum camera_param_aperturevalues_maxmin {
    CAMERA_PARAM_APERTUREVALUES_MAX_INDEX = 0,
    CAMERA_PARAM_APERTUREVALUES_MIN_INDEX = 1,
    CAMERA_PARAM_APERTUREVALUES_NUMVALUES = 100 // some arbitrary maximum
};

/*
 * camera_param_aperturevalues_t: report available aperture values
 */
typedef struct {
    int numvalues;
    bool maxmin;
    double values[CAMERA_PARAM_APERTUREVALUES_NUMVALUES];
} camera_param_aperturevalues_t;

/*
 * camera_param_evoffsets_maxmin: an enum which describes the order of values
 * returned in camera_param_evoffsets_t if maxmin=true
 */
enum camera_param_evoffsets_maxmin {
    CAMERA_PARAM_EVOFFSETS_MAX_INDEX = 0,
    CAMERA_PARAM_EVOFFSETS_MIN_INDEX = 1,
    CAMERA_PARAM_EVOFFSETS_NUMVALUES = 100 // some arbitrary maximum
};

/*
 * camera_param_evoffsets_t: report available ev offsets
 */
typedef struct {
    int numvalues;
    bool maxmin;
    double values[CAMERA_PARAM_EVOFFSETS_NUMVALUES];
} camera_param_evoffsets_t;

/*
 * camera_param_setregion_t: region identifier plus data.  used for write.
 */
typedef struct {
    int num;
    bool clearSingle;
    bool clearAll;
    bool flush;
    camera_region_t region;
} camera_param_setregion_t;

typedef enum {
    CAMERA_REGIONTYPE_NONE = 0,
    // these regions report supported resolutions
    CAMERA_REGIONTYPE_UNUSED1,
    CAMERA_REGIONTYPE_UNUSED2,
    CAMERA_REGIONTYPE_VIDEOVF,
    CAMERA_REGIONTYPE_VIDEOCAPTURE,
    CAMERA_REGIONTYPE_UNUSED5,
    // these are used in 3A processing
    CAMERA_REGIONTYPE_AUTOFOCUS,
    CAMERA_REGIONTYPE_AUTOEXPOSURE,
    CAMERA_REGIONTYPE_AUTOWHITEBALANCE,
} camera_regiontype_t;

/*
 * camera_param_frametypes_t: report available frametypes
 */
typedef struct {
    int numtypes;
    camera_frametype_t types[CAMERA_FRAMETYPE_NUMFRAMETYPES];
} camera_param_frametypes_t;

/*
 * camera_param_physicalparams_t: fixed physical camera/lens properties
 */
typedef struct {
    double focalLength;
    double focalLength35mm;
    double fNumber;
    double horizontalFov;
    double verticalFov;
    double sensorWidth;
    double sensorHeight;
    double maxZoomRatio;
    uint32_t widthPixels;
    uint32_t heightPixels;
    uint32_t sensorISO;
} camera_param_physicalparams_t;

/*
 * camera_param_videoencoder_values_maxmin_t: an enum which describes the order
 * of values returned in camera_param_videoencoder_parameter_values_t if
 * maxmin is true
 */
typedef enum {
    CAMERA_PARAM_VIDEOENCODERVALUES_MAX_INDEX = 0,
    CAMERA_PARAM_VIDEOENCODERVALUES_MIN_INDEX = 1,
    CAMERA_PARAM_VIDEOENCODERVALUES_NUMVALUES = 100 // some arbitrary maximum
} camera_param_videoencoder_values_maxmin_t;

/*
 * camera_param_videoencoder_values_t: report supported video encoder
 * parameter values
 */
typedef struct {
    int numvalues;
    bool maxmin;
    int values[CAMERA_PARAM_VIDEOENCODERVALUES_NUMVALUES];
} camera_param_videoencoder_values_t;

/**
 * This structure is used to query the availablity of certain encoder
 * configuration
 */
typedef struct {
    /**
     * The width of the image in pixels.
     */
    unsigned int width;
    /**
     * The height of the image in pixels.
     */
    unsigned int height;
    /**
     * The maxium framerate used in encoder.
     */
    double max_frame_rate;
    /**
     * The codec type.
     */
    camera_videocodec_t codec;
    /**
     * The H.264/AVC profile used by video encoder.
     */
    camera_h264avc_profile_t profile;
    /**
     * The H.264/AVC profile level used by video encoder
     */
    camera_h264avc_level_t profile_level;
} camera_videoencodercapability_info_t;

/*
 * Frame drop information structure
 */
typedef struct {
    uint32_t size;
    camera_eventkey_t key;
    camera_frametype_t format;
    bool client_notified;
    // Total captured frame count since the last time it was cleared.
    uint64_t total_frame_count;
    // Dropped frame count since the last time it was cleared.
    uint64_t dropped_frame_count;
    uint64_t last_cleared_time;
    uint64_t last_dropped_time;
    uint64_t last_dropped_frame_timestamp;
} camera_frame_stats_t;

/**
 * For querying number of supported resolutions
 */
typedef struct {
    uint32_t numSupported;
    camera_frametype_t frameType;
} camera_param_num_resolutions_t;

/*
 * camera_param_location_t: location information of the camera
 */
typedef struct {
    char   name[CAMERA_LOCATION_NAMELEN];
    double position[3];
    double direction[3];
    // Deprecated orientation from ADAS 1.0
    double orientation;
} camera_param_location_t;

/*
 * camera_param_position: an enum that defines how to index the elements
 * of camera_param_location_t's position member
 */
enum camera_param_position {
    CAMERA_PARAM_POSITION_X = 0,
    CAMERA_PARAM_POSITION_Y = 1,
    CAMERA_PARAM_POSITION_Z = 2
};

/*
 * camera_param_direction: an enum that defines how to index the elements
 * of camera_param_location_t's direction member
 */
enum camera_param_direction {
    CAMERA_PARAM_DIRECTION_YAW = 0,
    CAMERA_PARAM_DIRECTION_PITCH = 1,
    CAMERA_PARAM_DIRECTION_ROLL = 2
};

/*
 * camera_param_int_maxmin: an enum which describes the order of values
 * returned in camera_param_supported_int_t if maxmin=true
 */
enum camera_param_int_maxmin {
    CAMERA_PARAM_INT_MAX_INDEX = 0,
    CAMERA_PARAM_INT_MIN_INDEX = 1,
    CAMERA_PARAM_INT_NUMVALUES = 100 // some arbitrary maximum
};

/*
 * camera_param_supported_int_t: report supported integer values
 */
typedef struct {
    int numvalues;
    bool maxmin;
    int32_t values[CAMERA_PARAM_INT_NUMVALUES];
} camera_param_supported_int_t;

/*
 * camera_param_capture_property_t: set/get a capture property
 */
typedef struct {
    uint32_t property;
    int32_t value;
} camera_param_capture_property_t;

/*
 * camera_param_manufacturing_info_t: manufacturing information
 */
typedef struct {
    uint32_t size;
    uint32_t offset;
    uint8_t buffer[CAMERA_MANU_INFO_BUFFER_SIZE];
} camera_param_manufacturing_info_t;

/*
 * camera_param_isp_configuration_t: ISP dynamic configuration update for
 * CAMERA_PARAM_ISP_CONFIGURATION
 */
typedef struct {
    camera_isp_config_type_t                type;
    union {
        uint32_t                            config;
        v3xISP_WbCfg_t                      v3xWb;
        v3xISP_VisionMode_t                 v3xVisionMode;
        v3xISP_RuntimeAeMode_t              v3xRuntimeAeMode;
        v3xISP_RuntimeAwbMode_t             v3xRuntimeAwbMode;
        v3xISP_WbCfgMode_t                  v3xWbCfgMode;
        v3xISP_GammaCfgMode_t               v3xGammaCfgMode;
        v3xISP_GammaCfgLut_t                v3xGammaCfgLut;
        v3xISP_RadialShadingCfgMode_t       v3xRadialShadingCfgMode;
        v3xISP_SinterCfgMode_t              v3xSinterCfgMode;
        v3xISP_SharpStrength_t              v3xSharpStrength;
        v3xISP_ToneMapCfgMode_t             v3xToneMapCfgMode;
        v3xISP_StatsRoi_t                   v3xStatsRoi;
        v3xISP_CameraParamsForStatsRoi_t    v3xCameraParamsForStatsRoi;
        v3xISP_CameraParamsDumpRawInput_t   v3xCameraParamsDumpRawInput;
        v3xISP_BrightnessContrastStep_t     v3xBrightnessContrastStep;
    };
} camera_param_isp_configuration_t;

/*
 * camera_param_ref_time_t: camera reference time
 */
typedef struct {
    camera_reference_clock_type_t   ref_clock_type;
    int64_t                         reference_time;
    int64_t                         monotonic_time;
} camera_param_ref_time_t;

/*
 * camera_param_power_mode_t: camera power mode
 */
typedef struct {
    camera_power_mode_t             power_mode;
} camera_param_power_mode_t;

/*
 * camera_param_reconnect_mode_t: camera reconnect mode
 */
typedef struct {
    camera_reconnect_mode_t         reconnect_mode;
} camera_param_reconnect_mode_t;

/*
 * camera_param_prbs_test_t: camera PRBS test
 */
typedef struct {
    camera_prbs_type_t              prbsTestType;
    uint32_t                        prbsTestInterval;
    camera_prbs_results_t           prbsTestRes;
} camera_param_prbs_test_t;

/*
 * camera_deserializer_param_t: deserializer parameters
 */
typedef struct {
    int                                     type;
    union {
        uint32_t                            param;
        serdes_maxim_equalizer_gain_t       equalizerGain;
    };
} camera_deserializer_param_t;

/*
 * camera_serializer_param_t: camera serializer parameters
 */
typedef struct {
    int                                     type;
    union {
        uint32_t                            param;
        serdes_maxim_spread_spectrum_t      spreadSpectrum;
        serdes_maxim_preemp_level_t         preempLevel;
    };
} camera_serializer_param_t;

/*
 * camera_paramval_t: a generic parameter associated with a camera_param_t
 * place-holders for now
 */
typedef union {
    uint32_t                               u32;
    int32_t                                s32;
    uint64_t                               u64;
    bool                                   boolean;
    camera_error_t                         err;
    camera_unit_t                          unit;
    char                                   str64[64];
    char                                   str256[256];
    char                                   filename[CAMERA_MAX_FILENAME_LEN];
    camera_param_vfconfig_t                vfConfig;
    camera_param_vf_type_t                 vfType;
    camera_devstatus_t                     devStatus;
    camera_param_zoom_t                    zoom;
    camera_param_featurebitmap_t           featureBitmap;
    camera_buffer_t                        cameraBuffer;
    camera_param_videooutputconfig_t       videoOutputConfig;
    camera_param_statusnotify_t            statusNotify;
    camera_param_focusstate_t              focusState;
    camera_focusmode_t                     focusMode;
    camera_param_rotations_t               rotations[CAMERA_FRAMETYPE_NUMFRAMETYPES];
    camera_param_setregion_t               setRegion;
    camera_param_3alockmodes_t             modes3a;
    camera_param_focusmodes_t              focusModes;
    camera_param_frametypes_t              frameTypes;
    camera_param_framerates_t              frameRates;
    camera_exposuremode_t                  exposureMode;
    camera_param_exposuremodes_t           exposureModes;
    camera_whitebalancemode_t              whiteBalanceMode;
    camera_param_whitebalancemodes_t       whiteBalanceModes;
    pid_t                                  pid;
    camera_param_physicalparams_t          physParams;
    camera_param_videoencoder_values_t     videoEncoderValues;
    camera_param_shutterspeeds_t           supportedShutterSpeeds;
    camera_param_whitebalancevalues_t      supportedWhiteBalanceValues;
    camera_param_whitebalance_colorgains_t whiteBalanceColorGains;
    camera_param_isovalues_t               supportedIsoValues;
    camera_param_aperturevalues_t          supportedApertureValues;
    camera_param_evoffsets_t               supportedEvOffsets;
    double                                 dbl;
    camera_videoencodercapability_info_t   videoCapabilityConfig;
    camera_frame_stats_t                   droppedFrameInfo;
    camera_vfmode_t                        vf_mode;
    camera_param_vf_modes_t                supportedVFModes;
    camera_param_num_resolutions_t         numResolutions;
    camera_param_location_t                location;
    camera_param_supported_int_t           supportedInt;
    camera_param_capture_property_t        capture;
    camera_analog_video_standard_t         standard;
    camera_param_manufacturing_info_t      manufacturingInfo;
    camera_param_isp_configuration_t       ispConfiguration;
    camera_param_ref_time_t                referenceTime;
    uint8_t                                recordingMetadata[CAMERA_MAX_RECORDING_METADATA];
    camera_param_power_mode_t              powerMode;
    camera_param_reconnect_mode_t          reconnectMode;
    camera_param_prbs_test_t               prbsTest;
    camera_deserializer_param_t            deserParam;
    camera_serializer_param_t              serParam;
} camera_paramval_t;

/*
 * camera_sizeof_buffer() - handy define to determine framesize given descriptor type
 * eg. camera_sizeof_buffer(camera_frame_nv12_t) if framedesc is an nv12 descriptor
 */
#define camera_sizeof_buffer(x) (sizeof(camera_buffer_t)-sizeof(camera_framedesc_t)+sizeof(x))


/*
 * camera_buffermode_t: callback buffering modes
 */
typedef enum {
    CAMERA_BUFFERMODE_NONE = 0,
    CAMERA_BUFFERMODE_READONLY,
    CAMERA_BUFFERMODE_READWRITE,
    CAMERA_BUFFERMODE_COPY,
    CAMERA_BUFFERMODE_PRECOPY,
    CAMERA_BUFFERMODE_EMPTY,
    CAMERA_BUFFERMODE_GEN
} camera_buffermode_t;


typedef enum {
    CAMERA_AUTORELEASE_NONE = 0,
    CAMERA_AUTORELEASE_INBUF = 1<<0,
    CAMERA_AUTORELEASE_OUTBUF = 1<<1,
    CAMERA_AUTORELEASE_ALL = (CAMERA_AUTORELEASE_INBUF | \
                              CAMERA_AUTORELEASE_OUTBUF)
} camera_autorelease_t;

/*
 * camera_event_t: used to specify exactly where in the image datapath the user would like to get/put data from
 */
typedef enum {
    CAMERA_EVENT_FIRST = 0,
    CAMERA_EVENT_NONE = CAMERA_EVENT_FIRST,
    CAMERA_EVENT_STATUS,
    CAMERA_EVENT_UNUSED2,
    CAMERA_EVENT_UNUSED3,
    CAMERA_EVENT_UNUSED4,
    CAMERA_EVENT_PREVIEW,
    CAMERA_EVENT_VIDEOFRAME,
    CAMERA_EVENT_UNUSED7,
    CAMERA_EVENT_UNUSED8,
    CAMERA_EVENT_NUMEVENTS
} camera_event_t;


/*
 * camera_readerfptr_t: function pointer typedef for reader callbacks
 * - Prototype: void callback(camera_handle_t handle,
 *                            camera_event_t camevent,
 *                            camera_error_t error,
 *                            camera_buffer_t *buf,
 *                            void *arg);
 * - Arguments:
 *   - handle: the handle of the camera invoking the callback
 *   - camevent: the camera event that triggered the callback
 *   - error: explicit error/status code from the service
 *   - buf: pointer to the image data
 *   - arg: user-defined argument
 * - Returns:
 *   - void
 */
typedef void (*camera_readerfptr_t) (camera_handle_t, camera_event_t, camera_error_t, camera_buffer_t*, void*);


/*
 * camera_filterfptr_t: function pointer typedef for filter callbacks
 * - Prototype: void callback(camera_handle_t handle,
 *                            camera_event_t camevent,
 *                            camera_error_t error,
 *                            camera_buffer_t *inbuf,
 *                            camera_buffer_t *outbuf,
 *                            void *arg);
 * - Arguments:
 *   - handle: the handle of the camera invoking the callback
 *   - camevent: the camera event that triggered the callback
 *   - error: explicit error/status code from the service
 *   - inbuf: pointer to the image data buffer read from the camera
 *   - outbuf: pointer to the image data buffer to write back to the camera
 *   - arg: user-defined argument
 * - Returns:
 *   - void
 */
typedef camera_error_t (*camera_filterfptr_t) (camera_handle_t, camera_event_t, camera_error_t, camera_buffer_t*, camera_buffer_t*, void*);

/*
 * camera_statusfptr_t: function pointer typedef for status callbacks
 * - Prototype: void callback(camera_handle_t handle,
 *                            camera_event_t camevent,
 *                            camera_error_t error,
 *                            camera_devstatus_t status,
 *                            void *arg);
 * - Arguments:
 *   - handle: the handle of the camera invoking the callback
 *   - camevent: the camera event that triggered the callback
 *   - error: explicit error/status code from the service
 *   - status: status being reported (16 bits)
 *   - parm: additional status parameters (16 bits)
 *   - arg: user-defined argument
 * - Returns:
 *   - void
 */
typedef void (*camera_statusfptr_t) (camera_handle_t, camera_event_t, camera_error_t, camera_devstatus_t, uint16_t, void*);

/*
 * camera_callbackfptr_t: union of all callback function pointers
 */
typedef union {
    camera_readerfptr_t reader;
    camera_filterfptr_t filter;
    camera_statusfptr_t status;
} camera_callbackfptr_t;


/*
 * camera_reserved_t: definitions of reserved fields in camera_buffer_t
 */
typedef enum {
    // Physical address (off_t)
    CAMERA_RESERVED_PHYSICAL_ADDRESS = 0,
    // Continuation of physical address on 64-bit environments
    CAMERA_RESERVED_PHYSICAL_PART2,
    // Unused for now
    CAMERA_RESERVED_FUTURE,
    // screen_buffer_t SCREEN_PROPERTY_ID - unique buffer ID (int)
    CAMERA_RESERVED_BUFFER_ID
} camera_reserved_t;

#define SET_BITPOSITION(f, p) (f |= (1<<p))
#define IS_BITPOSITION_SET(f, p)  (f & (1<<p))

/*
 * camera_metadata_t: structure to describe an ISP metadata item.
 */
typedef struct {
    camera_metadata_id_t    id;
    size_t                  length;
} camera_metadata_header_t;

/*
 * camera_get_parameter: returns the current value of a specified parameter for a given camera
 * - Description:
 *   NOTE: Caller provides storage for value.
 * - Arguments:
 *   - handle: handle for the camera to query
 *   - param: the parameter to retrieve limits for
 *   - value: pointer to the returned value of the parameter
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t camera_get_parameter(camera_handle_t handle,
                                    camera_param_t param,
                                    camera_paramval_t *value);


/*
 * camera_set_parameter: sets the current value of a specified parameter for a given camera
 * - Description:
 * - Arguments:
 *   - handle: handle for the camera to query
 *   - param: the parameter to retrieve limits for
 *   - value: pointer to the value to set
 *   - len: length to set, or 0 for maximum size
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t camera_set_parameter(camera_handle_t handle,
                                    camera_param_t param,
                                    camera_paramval_t *value,
                                    uint32_t len);



/*
 * camera_attach_reader: register a callback function to receive data from the camera datapath
 * - Description:
 *   -NOTE: bufmode is provided in order to instruct the camera service how to handle buffers that
 *          will be passed to the reader:
 *          CAMERA_BUFFERMODE_NONE: no buffers are returned (NULL)
 *          CAMERA_BUFFERMODE_READONLY: the buffer is provided read-only to the callback
 *          CAMERA_BUFFERMODE_COPY: a read/write copy of the buffer is provided to the callback
 *   -NOTE: callback completion does not release buffers.  user must explicitly release buffers before
 *          the callback will be triggered again.
 * - Arguments:
 *   - handle: handle for the camera
 *   - camevent: specify when the callback function will be invoked
 *   - bufmode: specify the type of buffer required by the callback
 *   - callback: function pointer invoked when camevent occurs
 *   - arg: user-defined argument which will be passed as parameter 5 of the callback function
 *   - key: pointer to key identifier returned by the service - use for detach.
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t camera_attach_reader(camera_handle_t handle,
                                    camera_event_t camevent,
                                    camera_buffermode_t bufmode,
                                    camera_autorelease_t autorelease,
                                    camera_readerfptr_t callback,
                                    void *arg,
                                    camera_eventkey_t *key);


/*
 * camera_detach_reader: de-register a callback function to receive data from the camera datapath
 * - Description:
 * - Arguments:
 *   - handle: handle for the camera that a callback was previously attached to
 *   - key: key returned by camera_attach_filter()
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t camera_detach_reader(camera_handle_t handle,
                                    camera_eventkey_t key);


/*
 * camera_attach_filter: register to read/write data into the camera datapath
 * - Description:  this has the effect of breaking the internal image pipeline to allow for injection of image data.
 *                 while filters are attached, the downstream processing stage stalls waiting for filter outbufs.
 *   -NOTE: bufmode is provided in order to instruct the camera service how to handle buffers that
 *          will be passed to the filter.  See camera_filterfptr_t for prototype information.
 *          CAMERA_BUFFERMODE_NONE: inbuf=outbuf=NULL.
 *          CAMERA_BUFFERMODE_READONLY: inbuf=outbuf.  both are read-only.  similar to reader callback mode.
 *          CAMERA_BUFFERMODE_READWRITE: inbuf=outbuf.  both are read/write.  used for in-place modification.
 *          CAMERA_BUFFERMODE_EMPTY: inbuf is read-only.  outbuf is a r/w empty buffer.  used where in-place modification is not possible.
 *          CAMERA_BUFFERMODE_GEN: inbuf=NULL.  outbuf is a r/w empty buffer.  used where filter is an image source with no input dependancy.
 *   -NOTE: callback completion does not release buffers.  user must explicitly release buffers before
 *          the callback will be triggered again.  inbuf will be returned to the pool.  outbuf passes to the next processing stage.
 * - Arguments:
 *   - handle: handle for the camera
 *   - camevent: specify when the callback function will be invoked
 *   - bufmode: specify the type of buffer required by the callback
 *   - callback: function pointer invoked when camevent occurs
 *   - arg: user-defined argument which will be passed as parameter 5 of the callback function
 *   - key: pointer to key identifier returned by the service - use for detach.
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t camera_attach_filter(camera_handle_t handle,
                                    camera_event_t camevent,
                                    camera_buffermode_t bufmode,
                                    camera_autorelease_t autorelease,
                                    camera_filterfptr_t callback,
                                    void *arg,
                                    camera_eventkey_t *key);


/*
 * camera_detach_filter: de-register a filter from the datapath
 * - Description:  this has the effect of reconnecting the internal image pipeline.
 * - Arguments:
 *   - handle: handle for the camera
 *   - key: key returned by camera_attach_filter()
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t camera_detach_filter(camera_handle_t handle,
                                    camera_eventkey_t key);


/*
 * camera_attach_status: register a callback function to receive status updates
 * - Description:
 *   -NOTE: unlike filter and reader, a status callback has no buffer pointers
 * - Arguments:
 *   - handle: handle for the camera
 *   - camevent: specify when the callback function will be invoked
 *   - callback: function pointer invoked when camevent occurs
 *   - arg: user-defined argument which will be passed as parameter 5 of the callback function
 *   - key: pointer to key identifier returned by the service - use for detach.
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t camera_attach_status(camera_handle_t handle,
                                    camera_event_t camevent,
                                    camera_statusfptr_t callback,
                                    void *arg,
                                    camera_eventkey_t *key);


/*
 * camera_detach_status: de-register a callback function to receive status updates
 * - Description:
 * - Arguments:
 *   - handle: handle for the camera that a callback was previously attached to
 *   - key: key returned by camera_attach_filter()
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t camera_detach_status(camera_handle_t handle,
                                    camera_eventkey_t key);


/*
 * camera_release_buffer: releases a buffer that was previously allocated
 * - Description: Use this at the tail end of a callback to return buffers to the camera service.
 * - Arguments:
 *   - handle: handle for the camera
 *   - buffer: the buffer to release
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t camera_release_buffer(camera_handle_t handle,
                                     camera_buffer_t *buffer);


/*
 * camera_isfilter: returns 1 if bufmode indicates a filter (not a reader)
 */
int camera_isfilter(camera_buffermode_t bufmode);


/*
 * camera_prim_open: Request a handle to access a logical camera unit
 * - Description: If available, returns a handle for exclusive access to a camera unit.
 *   - NOTE: caller provides storage for handle.
 * - Arguments:
 *   - unit: the logical camera unit to open
 *   - mode: mode flags (CAMERA_MODE_xxx flags ORed together)
 *   - handle: pointer to the returned camera_handle_t on success
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t
camera_prim_open(camera_unit_t unit,
                 uint32_t mode,
                 camera_handle_t *handle);

/*
 * camera_prim_close: Discontinue use of a logical camera unit
 * - Description: Cleans up internal resources associated with a previously opened camera unit
 * - Arguments:
 *   - handle: the handle to close
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t
camera_prim_close(camera_handle_t handle);


/*
 * camera_is_roll_parameter: Returns true if the camera parameter
 * is a camera roll parameter
 * Arguments:
 *  parm - the camera parameter
 * Returns:
 *  true if the camera parameter is a camera roll parameter
 *  false if the camera parameter is not a camera roll parameter
 */
bool
camera_is_roll_parameter(camera_param_t parm);

/*
 * camera_roll_get_video_format_from_extension: Converts a file extension
 * into its currently mapped video format
 * Arguments:
 *  ext - the file extensionr
 *  fmt - pointer to the returned video format
 * Returns:
 *  CAM_EOK: on success
 *  CAM_xxx: on error
 */
camera_error_t
camera_roll_get_video_format_from_extension(const char *ext,
                                           camera_roll_video_fmt_t *fmt);


/*
 * camera_roll_get_video_ext: Converts a video format
 * into its currently mapped file extension.
 * Arguments:
 *  fmt - the video format
 *  pext - pointer to the returned file extension
 * Returns:
 *  CAM_EOK: on success
 *  CAM_xxx: on error
 */
camera_error_t
camera_roll_get_video_ext(camera_roll_video_fmt_t fmt,
                         const char ** const pext);


/**
 * @brief retrieve current roll path
 * @details
 * Retrieve the current camera roll path for the specified camera.
 * @param handle an open camera handle
 *
 * @return the roll path
 */
const char*
camera_prim_get_roll_path(camera_handle_t handle);


/**
 * @brief set the current roll path
 * @details
 * Set the camera roll path for the specified camera.  Subsequent calls to camera_prim_open_roll_file()
 * will use this path when opening files.  This must be called at least once after a camera unit is opened to set
 * the default roll path.  This is typically done by camera_prim_open().
 * @param handle an open camera handle
 * @param pathname the path to set, or "" to select a default based on the caller's credentials.
 *
 * @return @c CAMERA_EOK on success.
 */
camera_error_t
camera_prim_set_roll_path(camera_handle_t handle, char* pathname);


/**
 * @brief set the current roll suffix
 * @details
 * Set the camera roll suffix.  This is a string that is appended to the end of
 * the filenames generated from the roll for this handle.
 * @param handle an open camera handle
 * @param suffix the suffix string to use
 *
 * @return @c CAMERA_EOK on success.
 */
camera_error_t
camera_prim_set_roll_suffix(camera_handle_t handle, char* suffix);


/**
 * @brief open a new file for writing on the camera roll
 * @details
 * Used to create new photo / video files on the camera roll. Atomicity is guaranteed by the use of O_EXCL.
 * The filename incorporates date and time, and deals with collisions by appending an extra number before the extension.
 * Make sure to close the fd when done!
 * @param handle an open camera handle
 * @param fd returned file descriptor
 * @param filename name of the file opened (including full path)
 * @param namelen size of the buffer provided by the caller for @c filename
 * @param ext file extension to append
 *
 * @return @c CAMERA_EOK on success.
 */
camera_error_t
camera_prim_open_roll_file(camera_handle_t handle,
                           int *fd,
                           char *filename,
                           int namelen,
                           const char* ext);


/**
 * @brief Dynamically updates video encoder parameters
 *
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param cfg The updated video output configuration to apply.
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_change_videoencoder_parameters(camera_handle_t handle,
                                      camera_param_videooutputconfig_t *cfg);

/*
 * camera_get_indexed_parameter: returns the current value of a specified
 *  indexed parameter for a given camera
 * - Description:
 *   NOTE: Caller provides storage for value.
 * - Arguments:
 *   - handle: handle for the camera to query
 *   - parameter: the parameter to retrieve
 *   - index: index further qualifying this parameter
 *   - value: pointer to the returned value of the parameter
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t camera_get_indexed_parameter(camera_handle_t handle,
                                            camera_param_t param,
                                            uint64_t index,
                                            camera_paramval_t *value);


/*
 * camera_set_parameter_read: sets the current value of a specified parameter
 * and return a value
 * - Description:
 * - Arguments:
 *   - handle: handle for the camera to query
 *   - parameter: the parameter to retrieve limits for
 *   - value: pointer to the value to set and pointer to the query result
 * - Returns:
 *   - CAM_EOK: on success
 *   - CAM_xxx: on error
 */
camera_error_t
camera_set_parameter_readback(camera_handle_t handle,
                              camera_param_t param,
                              camera_paramval_t *value);


camera_param_vf_type_t
camera_get_vf_type_from_vf_mode(camera_vfmode_t mode);


/**
 * @brief Return current thread's priority
 * @details Used to figure out what the current thread's priority is.
 * @return the priority of the current thread or -1 if we can't find the current
 *         thread's priority.
 */
int camera_get_cur_thread_prio();


/**
 * @brief Return the handle's camera unit
 * @details Used to acquire a certain handle's associated camera unit
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @return the camera unit of type camera_unit_t or -1 if the handle is not valid
 */
camera_unit_t camera_get_unit_from_handle(camera_handle_t handle);


/* Internal debug function */
camera_error_t
camera_dump_tracker_information(camera_handle_t handle);


/**
 * @brief Register a video group with a camera handle
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param group_id The group_id returned by a call to camera_create_video_group()
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_prim_register_video_group(camera_handle_t handle, camera_video_group_id_t group_id);


/**
 * @brief Deregister a video group from a camera handle
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param group_id The group_id returned by a call to camera_create_video_group()
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_prim_deregister_video_group(camera_handle_t handle, camera_video_group_id_t group_id);


/**
 * @brief Retrieve the video group associated with a camera handle
 * @param handle The handle returned by a call to the @c camera_open() function.
 * @param group_id The group_id associated with this camera handle
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_prim_get_video_group(camera_handle_t handle, camera_video_group_id_t* group_id);


/**
 * @brief Retrieve physical address associated with a given camera_buffer_t.
 * @details
 * It is the physical address associated with the virtual address
 * buf->framebuf.
 *
 * @param buf The camera_buffer_t of interest
 * @param phys_addr On success, set to physical address associated with buf
 *
 * @return @c #CAMERA_EOK when the function successfully completes, otherwise
 *         another @c ::camera_error_t value that provides the reason that the
 *         call failed.
 */
camera_error_t
camera_prim_get_phys_addr(camera_buffer_t* buf, off_t* phys_addr);


#ifdef __cplusplus
}
#endif


#endif   /* __CAMERA_PRIM_H__ */



#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/camapi/public/camera/camera_prim.h $ $Rev: 899560 $")
#endif
