/* QNX Camera IPC API */


#ifndef __CAMERA_IPC_H__
#define __CAMERA_IPC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/iofunc.h>
#include <devctl.h>
#include <camera/camera_api.h>
#include <camera/camera_prim.h>


enum {
    CAMERA_PULSE_CODE_CALLBACK = 0
};


#define _DCMD_CAMERA 0x12


typedef union {
    struct {
        uint32_t version;
        uint32_t mode;
    } i;
    struct {
    } o;
} camera_ipc_access_t;

typedef union {
    struct {
        camera_param_t parm;
    } i;
    struct {
    } o;
} camera_ipc_supported_t;

typedef union {
    struct {
        camera_param_t parm;
    } i;
    struct {
        camera_param_t parm;
        uint32_t len;
        camera_paramval_t readval;
    } o;
} camera_ipc_parmread_t;

typedef union {
    struct {
        camera_param_t parm;
        uint32_t len;
        camera_paramval_t writeval;
    } i;
    struct {
    } o;
} camera_ipc_parmwrite_t;

typedef union {
    struct {
        camera_event_t event;
    } i;
    struct {
    } o;
} camera_ipc_trigger_t;

typedef union {
    struct {
        camera_event_t event;
        camera_buffermode_t mode;  /* can determine reader/filter from this */
        struct sigevent sigev;
        bool enable;
    } i;
    struct {
        camera_eventkey_t key;
    } o;
} camera_ipc_attachcallback_t;

typedef union {
    struct {
        camera_eventkey_t key;
    } i;
    struct {
    } o;
} camera_ipc_detachcallback_t;

typedef union {
    struct {
        camera_event_t event;
        camera_buffermode_t mode;  /* can determine reader/filter from this */
        struct sigevent sigev;
        camera_eventkey_t key;
        bool enable;
    } i;
    struct {
    } o;
} camera_ipc_modifycallback_t;

/* the getbuf message is broken into parts for IOV use */
typedef union {
    struct {
        camera_event_t event;
        camera_eventkey_t cbkey;
        bool needInBuf;
        bool needOutBuf;
    } i;
    struct {
        camera_event_t event;
        camera_error_t status;  /* status of the datpath */
    } o;
} camera_ipc_getbuf_header_t;
typedef union {
    struct {
        camera_ipc_getbuf_header_t header;
    } i;
    struct {
        camera_ipc_getbuf_header_t header;
        camera_buffer_t inbuf;
        camera_buffer_t outbuf;
    } __attribute__((packed)) o;
} camera_ipc_getbuf_t;

typedef union {
    struct {
        camera_buffer_t buf;
    } i;
    struct {
    } o;
} camera_ipc_releasebuf_t;

typedef union {
    struct {
        camera_regiontype_t regiontype;
        uint32_t regionnum;
        camera_frametype_t frametype;
    } i;
    struct {
        camera_region_t region;
    } o;
} camera_ipc_getregion_t;

typedef union {
    struct {
        camera_eventkey_t cbkey;
        uint32_t numasked;
    } i;
    struct {
        size_t size;
        uint32_t numsupported;
        uint8_t* buffers[CAMERA_MAX_PREMAP_BUF_NUM];   // Just need to make sure to have enough space.
        off_t offsets[CAMERA_MAX_PREMAP_BUF_NUM];
    } o;
} camera_ipc_premapallbufs_t;

typedef union {
    struct {
        camera_param_t parm;
        uint64_t index;
    } i;
    struct {
        camera_param_t parm;
        uint32_t len;
        camera_paramval_t readval;
    } o;
} camera_ipc_indexedparmread_t;

typedef union {
    struct {
        camera_param_t parm;
        uint32_t len;
        camera_paramval_t writeval;
    } i;
    struct {
        uint32_t len;
        camera_paramval_t readval;
    } o;
} camera_ipc_parmwriteread_t;

/* ACCESS - request access to camera device - after open() */
#define DCMD_CAMERA_ACCESS __DIOT(_DCMD_CAMERA,  0, camera_ipc_access_t)

/* PARMSUPPORTED - query parameter support */
#define DCMD_CAMERA_SUPPORTED __DIOT(_DCMD_CAMERA, 1, camera_ipc_supported_t)

/* PARMREAD - read a parameter */
#define DCMD_CAMERA_PARMREAD __DIOTF(_DCMD_CAMERA, 2, camera_ipc_parmread_t)

/* PARMWRITE - write a parameter */
#define DCMD_CAMERA_PARMWRITE __DIOT(_DCMD_CAMERA, 3, camera_ipc_parmwrite_t)

/* TRIGGER - trigger an event */
#define DCMD_CAMERA_TRIGGER __DIOT(_DCMD_CAMERA, 4, camera_ipc_trigger_t)

/* ATTACH_CALLBACK - attach callback for an event */
#define DCMD_CAMERA_ATTACHCALLBACK __DIOTF(_DCMD_CAMERA, 5, camera_ipc_attachcallback_t)

/* DETACH_CALLBACK - detach callback for an event */
#define DCMD_CAMERA_DETACHCALLBACK __DIOT(_DCMD_CAMERA, 6, camera_ipc_detachcallback_t)

/* GETBUF - request a buffer be passed to the client */
#define DCMD_CAMERA_GETBUF __DIOTF(_DCMD_CAMERA, 7, camera_ipc_getbuf_t)

/* RELEASEBUF - notify service that client is finished with buffer */
#define DCMD_CAMERA_RELEASEBUF __DIOT(_DCMD_CAMERA, 8, camera_ipc_releasebuf_t)

/* GETREGION - retrieve variable number of regions */
#define DCMD_CAMERA_GETREGION __DIOTF(_DCMD_CAMERA, 9, camera_ipc_getregion_t)

/* GETBUF - request a buffer be passed to the client */
#define DCMD_CAMERA_PREMAPALLBUFS __DIOTF(_DCMD_CAMERA, 10, camera_ipc_premapallbufs_t)

/* INDEXEDPARMREAD - read a parameter with a specified extra index parameter */
#define DCMD_CAMERA_INDEXEDPARMREAD __DIOTF(_DCMD_CAMERA, 11, camera_ipc_indexedparmread_t)

/* DCMD_CAMERA_PARMWRITEREAD - write a parameter and return read value */
#define DCMD_CAMERA_PARMWRITEREAD __DIOTF(_DCMD_CAMERA, 12, camera_ipc_parmwriteread_t)

/* DCMD_CAMERA_PARMWRITEREAD - write a parameter and return read value */
#define DCMD_CAMERA_MODIFYCALLBACK __DIOTF(_DCMD_CAMERA, 13, camera_ipc_modifycallback_t)

/* Maximum size of string of IPC path */
#define CAMERA_IPC_PATH_MAX_SIZE            32

/*
 * camera_ipc_unittoname: get string of path name associated with a unit; 'name'
 *                        string passed in of 'len' bytes will be filled.
 */
int camera_ipc_unittoname(camera_unit_t unit, char *name, size_t len);

/*
 * camera_ipc_nametounit: get unit corresponding to a path name;
 *                        CAMERA_UNIT_NUM_UNITS if does not match any.
 */
camera_unit_t camera_ipc_nametounit(char *name);

/*
 * camera_ipc_mountpoint: get string corresponding to service mountpoint (base path)
 */
const char *camera_ipc_mountpoint();

/*
 * camera_ipc_access: request access to device
 */
camera_error_t camera_ipc_access(int fd,
                                 uint32_t version,
                                 uint32_t mode);


/*
 * camera_ipc_supported: query service for parameter support
 */
camera_error_t camera_ipc_supported(int fd,
                                    camera_param_t parm);


/*
 * camera_ipc_parmread: parameter read from camera device fd
 */
camera_error_t camera_ipc_parmread(int fd,
                                   camera_param_t parm,
                                   void *buf,
                                   int *size);


/*
 * camera_ipc_parmwrite: parameter write to camera device fd
 */
camera_error_t camera_ipc_parmwrite(int fd,
                                    camera_param_t parm,
                                    void *buf,
                                    int size);


/*
 * camera_ipc_trigger: trigger a camera event
 */
camera_error_t camera_ipc_trigger(int fd,
                                  camera_event_t event);


/*
 * camera_ipc_attachcallback: register a callback pulse
 */
camera_error_t camera_ipc_attachcallback(int fd,
                                         camera_event_t event,
                                         uint32_t mode,
                                         struct sigevent *sigev,
                                         bool enable,
                                         camera_eventkey_t *key);


/*
 * camera_ipc_detachcallback: deregister a callback pulse
 */
camera_error_t camera_ipc_detachcallback(int fd,
                                         camera_eventkey_t key);


/*
 * camera_ipc_modifycallback: modify a callback pulse
 */
camera_error_t camera_ipc_modifycallback(int fd,
                                         camera_event_t event,
                                         uint32_t mode,
                                         struct sigevent *sigev,
                                         camera_eventkey_t inKey,
                                         bool enable);
/*
 * camera_ipc_getbufs: retrieve a set of buffers
 */
camera_error_t camera_ipc_getbufs(int fd,
                                  camera_event_t event,
                                  camera_eventkey_t key,
                                  camera_error_t *status,
                                  camera_buffer_t *inbuf,
                                  camera_buffer_t *outbuf);


/*
 * camera_ipc_releasebuf: release a buffer pointer back to the service
 */
camera_error_t camera_ipc_releasebuf(int fd,
                                     camera_buffer_t *buf);


/*
 * camera_ipc_getregion: query for a specific region
 */
camera_error_t camera_ipc_getregion(int fd,
                                    camera_regiontype_t regiontype,
                                    uint32_t regionnum,
                                    camera_frametype_t frametype,
                                    camera_region_t *region);

/*
 * camera_ipc_getallvfbufs: Get all viewfinder buffers and map them to caller's pid.
 */
camera_error_t camera_ipc_premapallbuffers(int fd,
                                           camera_eventkey_t key,
                                           void **buffers,
                                           off_t* offsets,
                                           size_t* size,
                                           uint32_t numasked,
                                           uint32_t* numsupported);

/*
 * camera_ipc_indexedparmread: indexed parameter read from camera device fd that
 * permits specifying an extra index qualifier for your read as compared to
 * camera_ipc_parmread
 */
camera_error_t camera_ipc_indexedparmread(int fd,
                                          camera_param_t parm,
                                          uint64_t index,
                                          void *buf,
                                          int *size);
/*
 * camera_ipc_parmwriteread: write a parameter and return a read value
 */
camera_error_t camera_ipc_parmwriteread(int fd,
                                        camera_param_t parm,
                                        void *buf,
                                        int *size);

#ifdef __cplusplus
}
#endif

#endif   /* __CAMERA_IPC_H__ */



#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/camapi/public/camera/camera_ipc.h $ $Rev: 899217 $")
#endif
