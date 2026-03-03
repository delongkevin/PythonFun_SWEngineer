/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file  File:  BrsHw_Ports.h
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsHw for platform Texas Instruments Jacinto7
 *
 *  \brief Description:  This header file contains the information for the evalboard specific port settings,
 *                       supported by this Brs implementation.
 *
 *  \attention Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to BrsHw.h.
 *********************************************************************************************************************/

#ifndef _BRSHW_PORTS_H_
#define _BRSHW_PORTS_H_

/*******************************************************************************
 *  Generic PORT definition types
 *******************************************************************************/
typedef enum
{
  GPIO0=0x600000UL,
  WKUP_GPIO0=0x42110000UL
}brsHw_Port_PortGroupType;

typedef struct
{
  brsHw_Port_PortGroupType  portGroup;
  uint32                    portNumber;
}brsHw_Port_PortType;

#if defined (_BRSHW_C_)
  #define BRSHW_PORT_PIN(name, group, number) const brsHw_Port_PortType name = {group, number}
#else
  #define BRSHW_PORT_PIN(name, group, number) extern const brsHw_Port_PortType name
#endif

#define BRSHW_PORT_LOGIC_HIGH (uint8)1
#define BRSHW_PORT_LOGIC_LOW  (uint8)0

/*******************************************************************************
 *  PIN configuration for alive LED support
 *******************************************************************************/
#if defined (BRS_ENABLE_SUPPORT_LEDS)
# if defined (BRS_EVA_BOARD_J721EVM)
/* Toggle WAKEUP_GPIO0_6 Pin */
BRSHW_PORT_PIN(BRSHW_PORT_LED, WKUP_GPIO0, 6U);
# elif defined (BRS_EVA_BOARD_J721S2)
BRSHW_PORT_PIN(BRSHW_PORT_LED, WKUP_GPIO0, 6U);
# else
  #error "Your chosen EvaBoard is not yet supported for LED support. Feel free to add your EvaBoard on top, or disable BRS LED support."
# endif /*BRS_EVA_BOARD_x*/
#endif /*BRS_ENABLE_SUPPORT_LEDS*/

/*******************************************************************************
 *  PIN configuration for toggle WD pin support
 *******************************************************************************/
#if defined (BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN)
# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_START_SEC_RAM_CONST
  #include "Brs_MemMap.h"
# endif

  #error "Please configure here the needed WD-toggle pin and uncomment this error, or disable BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN"*/

BRSHW_PORT_PIN(BRSHW_PORT_TOGGLE_WD, BRSHW_PORT_PORTGROUP_x, PORT_PORTNUMBER);

# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_STOP_SEC_RAM_CONST
  #include "Brs_MemMap.h"
# endif
#endif /*BRS_ENABLE_SUPPORT_WD_PIN*/

/*******************************************************************************
 *  PIN configuration for toggle CUSTOM pin support
 *******************************************************************************/
#if defined (BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN)
# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_START_SEC_RAM_CONST
  #include "Brs_MemMap.h"
# endif

  #error "Please configure here the needed custom toggle pin and uncomment this error, or disable BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN"*/

BRSHW_PORT_PIN(BRSHW_PORT_TOGGLE_CUSTOM, BRSHW_PORT_PORTGROUP_x, PORT_PORTNUMBER);

# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_STOP_SEC_RAM_CONST
  #include "Brs_MemMap.h"
# endif
#endif /*BRS_ENABLE_SUPPORT_CUSTOM_PIN*/

/*******************************************************************************
 *  ------------------------------------------------------------
 *  COMMUNICATION DRIVER SPECIFIC PORT SETTINGS
 *  ------------------------------------------------------------
 *******************************************************************************/
/*******************************************************************************
 *  GENERAL COMMUNICATION DRIVER SPECIFIC SETTINGS
 *******************************************************************************/

/*******************************************************************************
 *  CAN driver
 *******************************************************************************/

/* Calls of BrsHwInitPortOutput() and BrsHwInitPortInput() replaced by proprietery Can_PlatformInit() function, provided by TI */

/*******************************************************************************
 *  LIN driver
 *******************************************************************************/
/* Calls of BrsHwInitPortOutput() and BrsHwInitPortInput() replaced by proprietery Lin_PlatformInit() function, provided by TI */

/*******************************************************************************
 *  FLEXRAY driver
 *******************************************************************************/
#if defined (BRS_ENABLE_FLEXRAY_SUPPORT)
  #error "PortPins for FlexRay are not yet supported!"
#endif

/*******************************************************************************
 *  ETHERNET driver
 *******************************************************************************/
/* Calls of BrsHwInitPortOutput() and BrsHwInitPortInput() replaced by proprietery Eth_PlatformInit() function, provided by TI */

/*******************************************************************************
 *  I2C driver
 *******************************************************************************/
/* Calls of BrsHwInitPortOutput() and BrsHwInitPortInput() replaced by proprietery I2C_PlatformInit() function, provided by TI */
 
/*******************************************************************************
 *  SPI driver
 *******************************************************************************/
#if defined (BRS_ENABLE_SPI_SUPPORT)
  #error "PortPins for SPI are not yet supported!"
#endif /*BRS_ENABLE_SPI_SUPPORT*/

#endif /*_BRSHW_PORTS_H_*/
