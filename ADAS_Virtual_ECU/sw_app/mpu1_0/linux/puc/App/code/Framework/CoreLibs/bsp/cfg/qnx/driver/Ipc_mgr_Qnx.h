/*
 *--------------------------------------------------------------------------
 * @file res_mgr.h
 * @brief resource manager  header file
 *
 *
 *- frame structure
 *-
 *-
 *--------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 * This document in its entirety is CONFIDENTIAL and may not be disclosed,
 * disseminated or distributed to parties outside MAGNA Electronics
 * without written permission from MAGNA Electronics.
 *
 * @author Ananda Kavrady, ananda.kavrady@magna.com
 *
 * --------------------------------------------------------------------------
 */
#ifndef IPC_MGR_QNX_H_
#define IPC_MGR_QNX_H_

#include <platform/PlatformAPI.h>

#ifdef ME_PLATFORM_QNX

#define DCMD_RESMGR_MSG_SEND              __DIOTF(_DCMD_MISC, 0, ResMgr_CmdArgs_t)
#define DCMD_RESMGR_MSG_RECV              __DIOTF(_DCMD_MISC, 1, ResMgr_CmdArgs_t)

typedef struct ResMgr_CmdArgs_s {
    union {
        struct {
            uint16_t msgID;
            uint16_t len;
            void     *data;
        } send;
        struct {
            uint16_t msgID;
            uint16_t len;
            void  *data;
        } recv;
    } args;
    uint32_t status;
} ResMgr_CmdArgs_t;

#endif // ME_PLATFORM_QNX

#endif //IPC_MGR_QNX_H_


