#ifndef TIMEMANAGERPROXY_TYPES_H_
#define TIMEMANAGERPROXY_TYPES_H_

typedef struct TimeManagerProxy_TimeStamp_t {
    /*! CPTS hardware push event timestamp  */
    uint64_t StbmTimeStamp;

    uint64_t appLogTimeStamp;
} TimeManagerProxy_TimeStamp_t;

#endif