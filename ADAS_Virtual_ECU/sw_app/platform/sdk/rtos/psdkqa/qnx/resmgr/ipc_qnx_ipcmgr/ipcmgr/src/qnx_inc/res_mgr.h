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
#ifndef IPC_MGR_H_
#define IPC_MGR_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/slog.h>
#include <sys/slogcodes.h>
#include <unistd.h>
#include <sys/iofunc.h>
#include <sys/dispatch.h>
#include <sys/neutrino.h>
#include <errno.h>
#include <devctl.h>
#include <fcntl.h>
#include <sys/procmgr.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <sys/resmgr.h>
#include <hw/inout.h>
#include <drvr/hwinfo.h>

#include "ipc_manager.h"
#include "PlatformSpecsQnx64.h"

typedef struct ResMgr_CmdArgs {
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
} ResMgr_CmdArgs;

#define DCMD_RESMGR_MSG_SEND              __DIOTF(_DCMD_MISC, 0, ResMgr_CmdArgs)
#define DCMD_RESMGR_MSG_RECV              __DIOTF(_DCMD_MISC, 1, ResMgr_CmdArgs)

#endif //IPC_MGR_H_


