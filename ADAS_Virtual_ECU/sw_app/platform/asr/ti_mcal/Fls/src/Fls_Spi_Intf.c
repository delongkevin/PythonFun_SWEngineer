/*
*
* Copyright (c) 2020 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
  *  \file      Fls_Spi_Intf.c
  *
  *  \brief    This file contains SPI interface for FLS MCAL driver
  *
  */


 /* ========================================================================== */
 /*                             Include Files                                  */
 /* ========================================================================== */

#include "Std_Types.h"
#include "Fls.h"
#include "Fls_Ospi.h"
#include "Fls_Spi_Intf.h"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* Default SPI parameters structure */
const SPI_Params SPI_defaultParams = {
    SPI_MODE_CALLBACK,  /* transferMode */
    0U,                 /* transferTimeout */
    SPI_MASTER,         /* mode */
    1000000,            /* bitRate */
    8,                  /* dataSize */
    SPI_POL0_PHA0,      /* frameFormat */
    NULL                /* custom */
};

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* Externs */
extern const SPI_config_list SPI_config;


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */


#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/*
 *  ======== SPI_close ========
 */
FLS_FUNC_TEXT_SECTION void SPI_close(SPI_Handle handle)
{
    if (handle != NULL)
    {
        OSPI_close(handle);
    }
}

/*
 *  ======== SPI_transfer ========
 */
FLS_FUNC_TEXT_SECTION boolean SPI_transfer(SPI_Handle handle, SPI_Transaction *transaction)
{
    boolean retVal = FALSE;

    if ((handle != NULL) && (transaction != NULL))
    {
        retVal = OSPI_transfer(handle, transaction);
    }

    return (retVal);
}

/*
 *  ======== SPI_control ========
 */
FLS_FUNC_TEXT_SECTION Std_ReturnType SPI_control(SPI_Handle handle, uint32 cmd, void *arg)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (handle != NULL)
    {
        retVal = OSPI_control(handle, cmd, arg);
    }
    return (retVal);
}

/*
 *  ======== SPI_init ========
 */
FLS_FUNC_TEXT_SECTION SPI_Handle SPI_init(void)
{
    OSPI_init((SPI_Handle)&(SPI_config[0]));
    return (SPI_Handle)&(SPI_config[0]);
}

/*
 *  ======== SPI_open ========
 */
FLS_FUNC_TEXT_SECTION SPI_Handle SPI_open(SPI_Handle handle, SPI_Params *params)
{
    SPI_Handle hwHandle = handle;
    hwHandle = OSPI_open(handle, params);
    return (hwHandle);
}

/*
 *  ======== SPI_Params_init ========
 */
FLS_FUNC_TEXT_SECTION void SPI_Params_init(SPI_Params *params)
{
    if (params != NULL)
    {
        *params = SPI_defaultParams;
    }
}


#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
