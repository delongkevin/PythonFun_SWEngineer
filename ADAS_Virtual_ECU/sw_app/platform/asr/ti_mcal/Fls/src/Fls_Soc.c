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
  *  \file      Fls_Soc.c
  *
  *  \brief    This file contains Fls MCAL driver
  *
  */

#if defined (SOC_J721E)
#include <ti/csl/soc/j721e/src/cslr_soc.h>
#include <ti/csl/soc/j721e/src/csl_psilcfg_thread_map.h>
#elif defined (SOC_J7200)
#include <ti/csl/soc/j7200/src/cslr_soc.h>
#include <ti/csl/soc/j7200/src/csl_psilcfg_thread_map.h>
#elif defined (SOC_J721S2)
#include <ti/csl/soc/j721s2/src/cslr_soc.h>
#include <ti/csl/soc/j721s2/src/csl_psilcfg_thread_map.h>
#endif

#include "Fls_Soc.h"

#define SPI_OSPI_PER_CNT (1U)

/* OSPI objects */
OSPI_Object OspiObjects[SPI_OSPI_PER_CNT + 1U];

/* OSPI configuration structure */
OSPI_HwAttrs ospiInitCfg[SPI_OSPI_PER_CNT + 1U]=
{

        {
                (const CSL_ospi_flash_cfgRegs *)CSL_MCU_FSS0_OSPI0_CTRL_BASE,      /* flash config register baseAddr */
#if defined (__aarch64__)
                (uint32)CSL_MCU_FSS0_DAT_REG0_BASE,        /* OSPI data base address */
#else
                (uint32)CSL_MCU_FSS0_DAT_REG1_BASE,
#endif
                OSPI_MODULE_CLOCK,                 /* Input frequency */
#if defined(BUILD_MPU)
                CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_MCU_FSS0_OSPI_0_OSPI_LVL_INTR_0,
#else
                CSLR_MCU_R5FSS0_CORE0_INTR_MCU_FSS0_OSPI_0_OSPI_LVL_INTR_0, /* OSPI int number for ARM GIC INTC */
#endif
                0,                                 /* Event ID not used for ARM INTC */
                OSPI_OPER_MODE_CFG,                /* operMode */
                CSL_OSPI_CS0,                      /* chipSelect */
                CSL_OSPI_CLK_MODE_0,               /* frmFmt */
                {
                        0,                             /* default Chip Select Start of Transfer Delay */
                        0,                             /* default Chip Select End of Transfer Delay */
                        0,                             /* default Chip Select De-Assert Different Slaves Delay */
                        OSPI_DEV_DELAY_CSDA            /* default Chip Select De-Assert Delay */
                },
                256,                               /* device page size is 256 bytes  */
#if defined (SOC_J721E)
                17,                                /* device block size is 2 ^ 17 = 128K bytes */
#elif defined (SOC_J7200)
                18,                                /* device block size is 2 ^ 18 = 256K bytes */
#elif defined (SOC_J721S2)
                18, // TODO refer back to OSPI PDK driver after support is added.
#endif
                OSPI_XFER_LINES_OCTAL,             /* xferLines */
                (uint8)FALSE,                       /* Interrupt mode */
                (uint8)FALSE,                        /* Direct Access Controller mode */
                (uint8)FALSE,                       /* DMA mode */
                (uint8)FALSE,                        /* enable PHY */
                0,                                 /* rdDataCapDelay */
                (uint8)FALSE,                        /* enable DTR - DDR enable*/
                (uint8)FALSE,                       /* enable XIP */
                10U,                                /* Chip Select Start Of Transfer delay */
                0U                                 /* Baudrate divider, set to a non-zero value (2 to 32) to override default divider value */
        },
        {
                0U,
        }
};

/* SPI configuration structure */
CSL_PUBLIC_CONST SPI_config_list SPI_config = {
    {
        &OspiObjects[0],
        &ospiInitCfg[0]
    },
    {
        NULL,
        NULL
    },
};
