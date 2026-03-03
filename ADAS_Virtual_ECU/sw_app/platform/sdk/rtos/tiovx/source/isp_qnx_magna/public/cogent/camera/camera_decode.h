#ifndef _CAMERA_DECODE_H_
#define _CAMERA_DECODE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <camera/camera_api.h>
#include <screen/screen.h>

/**
 * @brief List of different events being returned to the callback
 * @details
 * See @c decodeFrameCallback definition for the definition of each of these events.
 */
typedef enum {
    DECODE_EVENT_BUFFER,
    DECODE_EVENT_ERROR,
    DECODE_EVENT_REWIND_START,
    DECODE_EVENT_REWIND_COMPLETE
} decodeEvent_t;

/**
 * @brief The handle to a video decode session
 * @details
 * The handle is created by calling @c decodeVideoCreate and destroyed by calling
 * @c decodeVideoDestroy.
 */
typedef void* decodeHandle_t;

/**
 * @brief Information about the video that is going to be decoded
 * @details
 * Filled in by @c decodeVideoCreate, can be used by user to know what type of
 * video will be decoded by this session.  Information returned contains the
 * following:
 *   - bufferWidth: width of the buffer we need to allocate
 *   - bufferHeight: height of the buffer we need to allocate
 *   - framerate: the framerate of the decoded video
 *   - frametype: the format of the decoded video
 *   - rollFormat: the file format of the recorded file
 *   - videoWidth: the width of the decoded video; may we smaller than bufferWidth
 *   - videoHeight: the height of the decoded video; may be smaller than bufferHeight
 *   - minimumBufferCount: the minimum number of buffers we need to allocate
 *   - duration: duration in microseconds
 *   - startTime: video start calendar time in microseconds since 1970
 */
typedef struct {
    uint32_t                bufferWidth;
    uint32_t                bufferHeight;
    uint32_t                framerate;
    camera_frametype_t      frametype;
    camera_roll_video_fmt_t rollFormat;
    uint32_t                videoWidth;
    uint32_t                videoHeight;
    uint32_t                minimumBufferCount;
    uint64_t                duration;
    uint64_t                startTime;
} decodeVideoInfo_t;

/**
 * @brief Parameters to apply to a video decode session that is created
 * @details
 * Parameters are the following:
 *   - latencyMicroSeconds: How much lantecy in micro-seconds to add to our decoding
 *         of video to deal with jitter in reading the frames
 *   - feedDefinedBuffersOnStop: If true, all defined buffers will be automatically
 *         fed to the graph on stop to handle a potential loopback.  If false, all
 *         fed buffers are removed on graph stop.
 *   - initBufferTime: RTSP streamer initial buffer time (if non-zero)
 *   - bufferTime: RTSP streamer underflow buffer time (if non-zero)
 *   - playbackSpeed: playback speed in percentage (100 for normal play speed)
 */
typedef struct {
    uint32_t            latencyMicroSeconds;
    bool                feedDefinedBuffersOnStop;
    uint32_t            initBufferTime;
    uint32_t            bufferTime;
    uint32_t            playbackSpeed;
} decodeParams_t;

/**
 * @brief Callback function for decodeVideoStart
 * @details
 * The callback function is called with event set as follows:
 * DECODE_EVENT_BUFFER - a buffer was received and is ready to process
 * DECODE_EVENT_ERROR - an error was encountered
 * DECODE_EVENT_REWIND - the end of file was reached and we have seeked back to the start
 */
typedef void (*decodeFrameCallback_t)(camera_buffer_t* buffer, void* arg, uint32_t event);

/**
 * @brief Create a video decoding graph reading files from an MP4 file
 * @details
 * Creates a MMF graph that will decode compressed frames from an MP4 file and will
 * call our callback once with each frame that was decoded from the file.  The
 * function only creates the graph and returns.
 *
 * @param filename Full path of the file to decode
 * @param callback The callback function that will be called for each event
 * @param arg A user supplied argument that will be sent as part of each callback
 * @param params Decode session parameters
 * @param handle On success, it is filled with the handle to be used for this
 *               decoding session.
 * @param info On success, it is filled with information regarding the video
 *             frames that will be generated from the file
 *
 * @return @c camera_error_t
 */
int decodeVideoCreate(const char* filename, decodeFrameCallback_t callback,
                      void* arg, decodeParams_t* params, decodeHandle_t* handle,
                      decodeVideoInfo_t* info);

/**
 * @brief Create a video decoding graph reading an RTSP stream
 * @details
 * Creates a MMF graph that will decode compressed frames from an RTSP stream and will
 * call our callback once with each frame that was decoded from the file.  The
 * function only creates the graph and returns.
 *
 * @param stream_path Full path of the stream to decode
 * @param callback The callback function that will be called for each event
 * @param arg A user supplied argument that will be sent as part of each callback
 * @param params Decode session parameters
 * @param handle On success, it is filled with the handle to be used for this
 *               decoding session.
 * @param info On success, it is filled with information regarding the video
 *             frames that will be generated from the stream
 *
 * @return @c camera_error_t
 */
int decodeVideoStreamCreate(const char* stream_path, decodeFrameCallback_t callback,
                            void* arg, decodeParams_t* params, decodeHandle_t* handle,
                            decodeVideoInfo_t* info);

/**
 * @brief Defines the buffers that will be used to hold the decoded frames
 * @details
 * After having called @c decodeVideoCreate() but before calling @c decodeVideoStart(),
 * call this function to define the buffers that will be used to hold the decoded
 * frames.  Note that these buffers will not be used by the decoder session until they
 * are fed to the session using @decodeVideoFeedBuffer().
 *
 * @param handle The handle associated with the decode session
 * @param numBuffers How many buffers will be used
 * @param buffer Array of 'numBuffers' pointers to the buffers (virtual address)
 * @param offset Array of 'numBuffers' physical offsets to the buffer (physical address)
 * @param size Size of each buffer in bytes
 * @param screenbuf Screen buffer to be saved for use by writer filter
 *
 * @return @c camera_error_t
 */
int decodeVideoDefineBuffers(decodeHandle_t handle, uint32_t numBuffers,
                             void** buffer, off_t* offset, size_t size,
                             screen_buffer_t *screenbuf);

/**
 * @brief Feed in a buffer to be used by the video decode graph
 * @details
 * After having called @c decodeVideoStart, call this function to permit the
 * graph to make use of a buffer.  Once this function is called for a given
 * buffer, it is to be used exclusively by the decode session until it is
 * returned as part of the decodeFrameCallback, at which point it is no longer
 * in use and may be fed again if desired.  A buffer is also no longer in use
 * whenever the decode session is stopped or a DECODE_EVENT_REWIND event occurs.
 *
 * @param handle The handle associated with the decode session
 * @param buffer Pointer to the buffer (virtual address)
 *
 * @return @c camera_error_t
 */
int decodeVideoFeedBuffer(decodeHandle_t handle, void* buffer);

/**
 * @brief Returns the current time in our video decode session
 * @details
 * After having called @c decodeVideoStart(), call this function to get the
 * current video decode time.  This can be used to do time synchronization of
 * the frames received from this session.
 *
 * @param handle The handle associated with the decode session
 * @param time On success, this gets filled with a micro-second count from the
 *             start of our video decode session.
 *
 * @return @c camera_error_t
 */
int decodeVideoGetTime(decodeHandle_t handle, int64_t* time);

/**
 * @brief Sets the time to start playing out video from the stream
 * @details
 * This permits skipping frames at the beginning of the video that may not be
 * of interest.  All video at the beginning until the specified time has
 * elapsed will simply be decoded and discarded as quickly as possible.  This
 * needs to be called prior to calling @c decoderVideoStart().  The same amount
 * of skipping is applied as well to subsequent rewind of the clip.
 *
 * @param handle The handle associated with the decode session
 * @param time The amount of time in micro-seconds to skip at the beginning of
 *             the video.  Set to zero to not skip any.
 *
 * @return @c camera_error_t
 */
int decodeVideoSetStart(decodeHandle_t handle, int32_t time);

/**
 * @brief Trigger a rewind of the clip to the beginning and resume playback
 * @details
 * Typically a decode session will automatically rewind when it reaches the end
 * of the file.  This function permits to trigger such a rewind before the end
 * of the file is reached to skip the remaining part of the clip.  Note that no
 * rewind events are generated for a rewind triggered through this function.
 *
 * @param handle The handle associated with the decode session
 *
 * @return @c camera_error_t
 */
int decodeVideoRewind(decodeHandle_t handle);

/**
 * @brief Sets the time offset to apply to timestamps of the acquired frames
 * @details
 * This permits adjusting the timestamp to take into account some blocking in
 * the receipt of frames and/or skipping of frames at the start that has made
 * the timestamps no longer being coordinated with the graph clock.
 *
 * @param handle The handle associated with the decode session
 * @param offset The amount of time in micro-seconds to add to each frame
 *               timestamp.
 *
 * @return @c camera_error_t
 */
int decodeVideoSetTimeOffset(decodeHandle_t handle, int32_t offset);

/**
 * @brief Starts decoding compressed frames
 * @details
 * After having called @c decodeVideoCreate(), call this function to start the
 * decoding session.  Once started successfully, decode events will start
 * being received in the registered callback function.
 *
 * @param handle The handle associated with the decode session
 *
 * @return @c camera_error_t
 */
int decodeVideoStart(decodeHandle_t handle);

/**
 * @brief Stops decoding compressed frames
 * @details
 * After having called @c decodeVideoStart(), call this function to stop the
 * decoding.  Note that this function must not be called in the context of a
 * callback function.
 *
 *@param handle The handle associated with the decode session
 *
 * @return @c camera_error_t
 */
int decodeVideoStop(decodeHandle_t handle);

/**
 * @brief Clean up when done with our video decode session
 * @details
 * After having called @c decodeVideoCreate(), call this function to clean up
 * and stop using this video decode session.
 *
 *@param handle The handle associated with the decode session
 *
 * @return @c camera_error_t
 */
int decodeVideoDestroy(decodeHandle_t handle);

#ifdef __cplusplus
}
#endif

#endif // _CAMERA_DECODE_H_

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/camapi/public/camera/camera_decode.h $ $Rev: 884406 $")
#endif
