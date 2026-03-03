#ifndef __CAMERA_VIDEO_H__
#define __CAMERA_VIDEO_H__

// this API is internal to the camera library.

#include <camera/camera_api.h>
#include <camera/camera_prim.h>
#include <camera/camera_decode.h>


// some common defines for use by video decoder

// Prototype of camapi video library functions
typedef int (*DecodeVideoCreateFunc)(const char* filename, decodeFrameCallback_t callback,
                      void* arg, decodeParams_t* params, decodeHandle_t* handle,
                      decodeVideoInfo_t* info);
typedef int (*DecodeVideoStreamCreateFunc)(const char* stream_path, decodeFrameCallback_t callback,
                            void* arg, decodeParams_t* params, decodeHandle_t* handle,
                            decodeVideoInfo_t* info);
typedef int (*DecodeCompressedStreamCreateFunc)(const char* stream_path, decodeFrameCallback_t callback,
                            void* arg, decodeParams_t* params, decodeHandle_t* handle,
                            decodeVideoInfo_t* info);
typedef int (*DecodeVideoDefineBuffersFunc)(decodeHandle_t handle, uint32_t numBuffers,
                             void** buffer, off_t* offset, size_t size,
                             screen_buffer_t *screenbuf);
typedef int (*DecodeVideoFeedBufferFunc)(decodeHandle_t handle, void* buffer);
typedef int (*DecodeVideoGetTimeFunc)(decodeHandle_t handle, int64_t* time);
typedef int (*DecodeVideoSetStartFunc)(decodeHandle_t handle, int32_t time);
typedef int (*DecodeVideoRewindFunc)(decodeHandle_t handle);
typedef int (*DecodeVideoSetTimeOffsetFunc)(decodeHandle_t handle, int32_t offset);
typedef int (*DecodeVideoStartFunc)(decodeHandle_t handle);
typedef int (*DecodeVideoStopFunc)(decodeHandle_t handle);
typedef int (*DecodeVideoDestroyFunc)(decodeHandle_t handle);

// Decode function pointers for camapi video library
typedef struct {
    DecodeVideoCreateFunc               create;
    DecodeVideoStreamCreateFunc         streamCreate;
    DecodeCompressedStreamCreateFunc    compressedStreamCreate;
    DecodeVideoDefineBuffersFunc        defineBuffers;
    DecodeVideoFeedBufferFunc           feedBuffer;
    DecodeVideoGetTimeFunc              getTime;
    DecodeVideoSetStartFunc             setStart;
    DecodeVideoRewindFunc               rewind;
    DecodeVideoSetTimeOffsetFunc        setTimeOffset;
    DecodeVideoStartFunc                start;
    DecodeVideoStopFunc                 stop;
    DecodeVideoDestroyFunc              destroy;
} camapi_video_decode_funcs_t;

// some common defines for use by the video recorder
typedef struct {
    volatile bool          exit_thread;
    volatile bool          thread_has_exited;
    volatile bool          do_not_wait_on_exit;
    volatile bool          power_warn;
    pthread_t              vr_error_thread;
    volatile bool          mmf_error;
    pthread_mutex_t        wait_mutex;
    pthread_cond_t         wait_cond;
    pthread_mutex_t        exit_mutex;
    pthread_cond_t         exit_cond;
} vr_thread_control_t;


typedef enum {
    NONE = 0,
    RECORDER_GRAPH,
    ENCODE_GRAPH
} graph_type_t;

#define AURL_LEN           FILENAME_MAX

typedef struct {
    camera_handle_t        handle;
    char                   filename[CAMERA_MAX_FILENAME_LEN];
    void                   (*callback_fptr_video)(camera_handle_t, camera_buffer_t*, void*);
    void                   (*callback_fptr_audio)(camera_handle_t, camera_buffer_t*, void*);
    void                   *callback_arg;
    char                   aurl[AURL_LEN];
    int                    nchan;
    int                    bitrate;
    double                 videoFrameRate;
    int                    keyframeinterval;
    int                    ltrinterval;
    int                    sliceSize;
    char                   *output_path;
    MmGraph_t              *mmgraph;
    AOIStream_t            *ifile;      // our mmf input streamer
    AOIStream_t            *ofile;      // our mmf output streamer
    MmFilter_t             *aenc;       // our audio encoder filter
    MmFilter_t             *venc;       // our video encoder filter.
    MmFilter_t             *fw;         // our file writer filter;
    MmFilter_t             *fw2;        // our secondary file writer filer (for a/v callback encode)
    MmFilter_t             *mdw;        // NULL or our metadata writer (typically the encoder)
    MmFilter_t             *vrf;        // our video reader filter (camera reader)
    MediaMetadataWriter    *mdi;        // NULL or the metadata interface
    int                    base_prio;
    unsigned               error_flags; // see enum error_flags
    int                    error_code;  // A POSIX errno
    pthread_mutex_t        error_mutex;
    pthread_mutex_t        mmgraph_mutex;
    uint32_t               aenc_bitrate;
    uint32_t               venc_bitrate;
    graph_type_t           graphType;
    MediaMetadataWriter    *metadata_writer_interface;
    MmFilter_t             *metadata_filter;
    int32_t                frameskipDivisor;
    bool                   movieRecordingRunning;
    bool                   videoEncodeRunning;
    vr_thread_control_t    vrThreadControl;
    bool                   mic_in_use;
    bool                   disk_full;
    bool                   fileSizeWarnSent;
    uint16_t               fileSizeWarnTime;
    pid_t                  resourcePid;
    camera_videocodec_t    videoCodec;
    camera_audiocodec_t    audioCodec;
    long long              reservedSpace;
    camera_videoencoder_config_t videoConfig;
    bool                   movieRecordingPaused;
    pthread_mutex_t        stop_mutex;
    pthread_cond_t         stop_cond;
    uint64_t               fileSizeLimit;
    uint32_t               fileSizeLimitWarnTime;
    bool                   fileSizeLimitWarnSent;
    int                    audioOverrunCount;
    MmFilter_t             *audioStreamer;
    bool                   synchroStartPending;
    bool                   synchroStopPending;
    bool                   writeComplete;

    // Callback functions for asynchronous calls to the caller
    camera_error_t         (*stopCallback)(camera_handle_t);
    camera_error_t         (*pushStatusCallback)(camera_handle_t, camera_devstatus_t, uint16_t);
    camera_error_t         (*attachReaderCallback)(camera_handle_t, camera_event_t, camera_buffermode_t,
                                        camera_autorelease_t, camera_readerfptr_t, void*, camera_eventkey_t*);
    camera_error_t         (*detachReaderCallback)(camera_handle_t, camera_eventkey_t);
    camera_error_t         (*releaseBufferCallback)(camera_handle_t, camera_buffer_t*);
    camera_error_t         (*premapAllBuffersCallback)(camera_handle_t,
                                        camera_eventkey_t, void**, off_t*,
                                        size_t*, uint32_t, uint32_t*);
    camera_error_t         (*getScreenBufCallback)(camera_handle_t, camera_buffer_t*, screen_buffer_t*);
    camera_error_t         (*getReferenceTimeCallback)(camera_handle_t, camera_reference_time_t*);

    // Parameters of the video buffer
    double                 vfFrameRate;
    camera_frametype_t     videoFrameFormat;
    uint32_t               videoWidth;
    uint32_t               videoHeight;
    int32_t                cbOffset;
    int32_t                crOffset;
    camera_frametype_t     roiFrameType;
    camera_frame_roi_t     roiInfo;
    bool                   needToPreMapBuffers;

    // Supported encoding parameters
    bool                   supportH264avcLtrInterval;
    bool                   supportH264avcSliceSize;
    bool                   supportH264avcSliceType;
    bool                   supportH264avcProfile;
    bool                   supportH264avcLevel;
    bool                   supportH264avcEntropyCoding;
    bool                   supportH264avcRateControl;
    bool                   supportH264avcQpI;
    bool                   supportH264avcQpP;
} recorderContext_t;

// Prototype of camapi video library record functions
typedef int (*videoRecordStartFunc)(recorderContext_t *context, bool synchronizedStart);
typedef int (*videoRecordStopFunc)(recorderContext_t *context);
typedef int (*videoRecordPauseFunc)(recorderContext_t *context);
typedef int (*videoRecordResumeFunc)(recorderContext_t *context);
typedef int (*videoRecordSetFileSizeLimitFunc)(recorderContext_t* context, uint64_t sizeLimit,
                                uint32_t warningSeconds);
typedef int (*videoEncodeStartFunc)(recorderContext_t *context, bool synchronizedStart);
typedef int (*videoEncodeStopFunc)(recorderContext_t *context);
typedef int (*videoParamChangeFunc)(recorderContext_t *context);
typedef int (*videoForceKeyFunc)(recorderContext_t *context);
typedef int (*videoDiskFreeFunc)(const char *pathname, long long *diskfree);
typedef int (*videoInitFunc)(void);
typedef int (*videoSynchronizedStartFunc)(recorderContext_t *context);
typedef int (*videoSynchronizedStopFunc)(recorderContext_t* context);

// Record function pointers for camapi video library
typedef struct {
    videoRecordStartFunc                recordStart;
    videoRecordStopFunc                 recordStop;
    videoRecordPauseFunc                recordPause;
    videoRecordResumeFunc               recordResume;
    videoRecordSetFileSizeLimitFunc     recordSetFileSizeLimit;
    videoEncodeStartFunc                encodeStart;
    videoEncodeStopFunc                 encodeStop;
    videoParamChangeFunc                paramChange;
    videoForceKeyFunc                   forceKey;
    videoDiskFreeFunc                   diskFree;
    videoInitFunc                       init;
    videoSynchronizedStartFunc          synchronizedStart;
    videoSynchronizedStopFunc           synchronizedStop;
} camapi_video_record_funcs_t;

// List of external functions from libcamapi_video
int videoRecordStart(recorderContext_t *context, bool synchronizedStart);

int videoRecordStop(recorderContext_t *context);

int videoRecordPause(recorderContext_t *context);

int videoRecordResume(recorderContext_t *context);

int videoRecordSetFileSizeLimit(recorderContext_t* context, uint64_t sizeLimit,
                                uint32_t warningSeconds);

int videoEncodeStart(recorderContext_t *context, bool synchronizedStart);

int videoEncodeStop(recorderContext_t *context);

int videoParamChange(recorderContext_t *context);

int videoForceKey(recorderContext_t *context);

int videoDiskFree(const char *pathname, long long *diskfree);

int videoInit(void);

int videoSynchronizedStart(recorderContext_t *context);

int videoSynchronizedStop(recorderContext_t* context);

#endif   /* __CAMERA_VIDEO_H__ */



#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/camapi/public/camera/camera_video.h $ $Rev: 899217 $")
#endif
