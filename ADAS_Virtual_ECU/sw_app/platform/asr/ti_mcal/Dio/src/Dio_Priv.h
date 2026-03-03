/*
*
* Copyright (c) 2019 Texas Instruments Incorporated
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
 *  \file     Dio_priv.h
 *
 *  \brief    This file contains the common declarations and macros used across
 *            all the DIO MCAL driver files.
 *
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "Std_Types.h"
#include "Dio.h"
#include "Dio_Cfg.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define DIO_UTILS_ARRAYSIZE(array)             ((sizeof (array) / \
                                                 sizeof ((array)[0])))

/* GPIO Instance Ids */
#if defined (SOC_J721E)

/* GPIO Instance Id: WAKEUP Domain 0*/
#define DIO_INSTANCE_0                            (0U)
/* GPIO Instance Id: WAKEUP Domain 1*/
#define DIO_INSTANCE_1                            (1U)
/* GPIO Instance Id: Main Domain 0*/
#define DIO_INSTANCE_2                            (2U)
/* GPIO Instance Id: Main Domain 1*/
#define DIO_INSTANCE_3                            (3U)
/* GPIO Instance Id: Main Domain 2*/
#define DIO_INSTANCE_4                            (4U)
/* GPIO Instance Id: Main Domain 3*/
#define DIO_INSTANCE_5                            (5U)
/* GPIO Instance Id: Main Domain 4*/
#define DIO_INSTANCE_6                            (6U)
/* GPIO Instance Id: Main Domain 5*/
#define DIO_INSTANCE_7                            (7U)
/* GPIO Instance Id: Main Domain 6*/
#define DIO_INSTANCE_8                            (8U)
/* GPIO Instance Id: Main Domain 7*/
#define DIO_INSTANCE_9                            (9U)

/* GPIO Instance Id: Max */
#define DIO_MAX_INSTANCE_ID                       (DIO_INSTANCE_9)


/* GPIO Instance Limits */
/* GPIO Instance Limits: WAKEUP Domain 0*/
#define DIO_MAX_PORT_ID_INSTANCE_0                (3U)
/* GPIO Instance Limits: WAKEUP Domain 1*/
#define DIO_MAX_PORT_ID_INSTANCE_1                (6U)
/* GPIO Instance Limits: Main Domain 0*/
#define DIO_MAX_PORT_ID_INSTANCE_2                (10U)
/* GPIO Instance Limits: Main Domain 1*/
#define DIO_MAX_PORT_ID_INSTANCE_3                (12U)
/* GPIO Instance Limits: Main Domain 2*/
#define DIO_MAX_PORT_ID_INSTANCE_4                (16U)
/* GPIO Instance Limits: Main Domain 3*/
#define DIO_MAX_PORT_ID_INSTANCE_5                (18U)
/* GPIO Instance Limits: Main Domain 4*/
#define DIO_MAX_PORT_ID_INSTANCE_6                (22U)
/* GPIO Instance Limits: Main Domain 5*/
#define DIO_MAX_PORT_ID_INSTANCE_7                (24U)
/* GPIO Instance Limits: Main Domain 6*/
#define DIO_MAX_PORT_ID_INSTANCE_8                (28U)
/* GPIO Instance Limits: Main Domain 7*/
#define DIO_MAX_PORT_ID_INSTANCE_9                (30U)

/* GPIO Instance Pin Limits */
/* GPIO Instance Pin Limits: WAKEUP Domain 0*/
#define DIO_MAX_PIN_ID_INSTANCE_0                 (144U)
/* GPIO Instance Pin Limits: WAKEUP Domain 1*/
#define DIO_MAX_PIN_ID_INSTANCE_1                 (288U)
/* GPIO Instance Pin Limits: Main Domain 0*/
#define DIO_MAX_PIN_ID_INSTANCE_2                 (432U)
/* GPIO Instance Pin Limits: Main Domain 1*/
#define DIO_MAX_PIN_ID_INSTANCE_3                 (576U)
/* GPIO Instance Pin Limits: Main Domain 2*/
#define DIO_MAX_PIN_ID_INSTANCE_4                 (720U)
/* GPIO Instance Pin Limits: Main Domain 3*/
#define DIO_MAX_PIN_ID_INSTANCE_5                 (864U)
/* GPIO Instance Pin Limits: Main Domain 4*/
#define DIO_MAX_PIN_ID_INSTANCE_6                 (1008U)
/* GPIO Instance Pin Limits: Main Domain 5*/
#define DIO_MAX_PIN_ID_INSTANCE_7                 (1152U)
/* GPIO Instance Pin Limits: Main Domain 6*/
#define DIO_MAX_PIN_ID_INSTANCE_8                 (1296U)
/* GPIO Instance Pin Limits: Main Domain 7*/
#define DIO_MAX_PIN_ID_INSTANCE_9                 (1440U)

#elif defined (SOC_J7200)

/* GPIO Instance Id: WAKEUP Domain 0*/
#define DIO_INSTANCE_0                            (0U)
/* GPIO Instance Id: WAKEUP Domain 1*/
#define DIO_INSTANCE_1                            (1U)
/* GPIO Instance Id: Main Domain 0*/
#define DIO_INSTANCE_2                            (2U)
/* GPIO Instance Id: Main Domain 1*/
#define DIO_INSTANCE_3                            (3U)
/* GPIO Instance Id: Main Domain 2*/
#define DIO_INSTANCE_4                            (4U)
/* GPIO Instance Id: Main Domain 3*/
#define DIO_INSTANCE_5                            (5U)
/* GPIO Instance Id: Main Domain 4*/

/* GPIO Instance Id: Max */
#define DIO_MAX_INSTANCE_ID                       (DIO_INSTANCE_5)

/* GPIO Instance Limits */
/* GPIO Instance Limits: WAKEUP Domain 0*/
#define DIO_MAX_PORT_ID_INSTANCE_0                (3U)
/* GPIO Instance Limits: WAKEUP Domain 1*/
#define DIO_MAX_PORT_ID_INSTANCE_1                (6U)
/* GPIO Instance Limits: Main Domain 0*/
#define DIO_MAX_PORT_ID_INSTANCE_2                (9U)
/* GPIO Instance Limits: Main Domain 1*/
#define DIO_MAX_PORT_ID_INSTANCE_3                (12U)
/* GPIO Instance Limits: Main Domain 2*/
#define DIO_MAX_PORT_ID_INSTANCE_4                (15U)
/* GPIO Instance Limits: Main Domain 3*/
#define DIO_MAX_PORT_ID_INSTANCE_5                (18U)
/* GPIO Instance Limits: Main Domain 4*/

/* GPIO Instance Pin Limits */
/* GPIO Instance Pin Limits: WAKEUP Domain 0*/
#define DIO_MAX_PIN_ID_INSTANCE_0                 (144U)
/* GPIO Instance Pin Limits: WAKEUP Domain 1*/
#define DIO_MAX_PIN_ID_INSTANCE_1                 (288U)
/* GPIO Instance Pin Limits: Main Domain 0*/
#define DIO_MAX_PIN_ID_INSTANCE_2                 (432U)
/* GPIO Instance Pin Limits: Main Domain 1*/
#define DIO_MAX_PIN_ID_INSTANCE_3                 (576U)
/* GPIO Instance Pin Limits: Main Domain 2*/
#define DIO_MAX_PIN_ID_INSTANCE_4                 (720U)
/* GPIO Instance Pin Limits: Main Domain 3*/
#define DIO_MAX_PIN_ID_INSTANCE_5                 (864U)
/* GPIO Instance Pin Limits: Main Domain 4*/

#elif defined (SOC_J721S2)

/* GPIO Instance Id: WAKEUP Domain 0*/
#define DIO_INSTANCE_0                            (0U)
/* GPIO Instance Id: WAKEUP Domain 1*/
#define DIO_INSTANCE_1                            (1U)
/* GPIO Instance Id: Main Domain 0*/
#define DIO_INSTANCE_2                            (2U)
/* GPIO Instance Id: Main Domain 1*/
#define DIO_INSTANCE_3                            (3U)
/* GPIO Instance Id: Main Domain 2*/
#define DIO_INSTANCE_4                            (4U)
/* GPIO Instance Id: Main Domain 3*/
#define DIO_INSTANCE_5                            (5U)
/* GPIO Instance Id: Main Domain 4*/

/* GPIO Instance Id: Max */
#define DIO_MAX_INSTANCE_ID                       (DIO_INSTANCE_5)

/* GPIO Instance Limits */
/* GPIO Instance Limits: WAKEUP Domain 0*/
#define DIO_MAX_PORT_ID_INSTANCE_0                (3U)
/* GPIO Instance Limits: WAKEUP Domain 1*/
#define DIO_MAX_PORT_ID_INSTANCE_1                (6U)
/* GPIO Instance Limits: Main Domain 0*/
#define DIO_MAX_PORT_ID_INSTANCE_2                (9U)
/* GPIO Instance Limits: Main Domain 1*/
#define DIO_MAX_PORT_ID_INSTANCE_3                (12U)
/* GPIO Instance Limits: Main Domain 2*/
#define DIO_MAX_PORT_ID_INSTANCE_4                (15U)
/* GPIO Instance Limits: Main Domain 3*/
#define DIO_MAX_PORT_ID_INSTANCE_5                (18U)
/* GPIO Instance Limits: Main Domain 4*/

/* GPIO Instance Pin Limits */
/* GPIO Instance Pin Limits: WAKEUP Domain 0*/
#define DIO_MAX_PIN_ID_INSTANCE_0                 (144U)
/* GPIO Instance Pin Limits: WAKEUP Domain 1*/
#define DIO_MAX_PIN_ID_INSTANCE_1                 (288U)
/* GPIO Instance Pin Limits: Main Domain 0*/
#define DIO_MAX_PIN_ID_INSTANCE_2                 (432U)
/* GPIO Instance Pin Limits: Main Domain 1*/
#define DIO_MAX_PIN_ID_INSTANCE_3                 (576U)
/* GPIO Instance Pin Limits: Main Domain 2*/
#define DIO_MAX_PIN_ID_INSTANCE_4                 (720U)
/* GPIO Instance Pin Limits: Main Domain 3*/
#define DIO_MAX_PIN_ID_INSTANCE_5                 (864U)
/* GPIO Instance Pin Limits: Main Domain 4*/

#endif

/*
** \name Values used to configure the direction of GPIO pins.
* @{
*/
typedef enum {
    DIO_DIR_INPUT  = 0x1U,
    DIO_DIR_OUTPUT = 0x0U
} Dio_DirectionType;
/* @} */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/** \brief Structure to specify the instance, base address ,
*           port , direction and pin number of a channel **/

typedef struct {
    /*Instance : WakeUp, Main 0, Main 1*/
    uint8 Dio_InstanceId;
    /*Base address of Instance Selected*/
    uint32 baseaddr;
    /*Port Id in the instance selected*/
    Dio_PortType Dio_PortId;
    /*Pin number wrt Port selected*/
    Dio_ChannelType Dio_PinNum;
    /*Direction of the Pin*/
    Dio_DirectionType Dio_Direction;
} Dio_ChannelInfo;

/** \brief Structure to specify the instance, base address ,
*            port and direction of a Port **/
typedef struct {
    /*Instance : WakeUp, Main 0, Main 1*/
    uint8 Dio_InstanceId;
    /*Base address of Instance Selected*/
    uint32 baseaddr;
    /*Port Id in the instance selected*/
    Dio_PortType Dio_PortId;
    /*Direction of the Port*/
    uint32 Dio_PortDirection;
} Dio_PortInfo;


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

uint32 Dio_getGPIOBaseAddr(uint8 regNum);
boolean Dio_isReservedPin(uint8 regNum, uint32 pinNum);
#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)
void Dio_UpdatePortInfoInternal(Dio_PortType PortId,
                                        Dio_PortInfo * DioPortInfo);
#endif
#ifdef __cplusplus
}
#endif

#endif  /* #ifndef DIO_PRIV_H_ */
