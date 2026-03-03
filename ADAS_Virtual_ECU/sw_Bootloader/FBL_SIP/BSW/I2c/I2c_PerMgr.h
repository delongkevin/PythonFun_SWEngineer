/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*        \file   I2c_PerMgr.h
 *        \brief  I2c peripheral manager for Jacinto7
 *
 *      \details  This sub-module controls the specific I2c peripherals of the Jacinto7 platform. It takes requests for
 *                simple data transfers from the higher layers and executes them on the specific hardware. The result of
 *                a data transfer which depends on successful transmission or a detected error event is reported back to
 *                the layers above. In addition, the module offers mechanisms for the handling of error states to the
 *                layers above.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author      Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2020-08-12  virzln      CTM-1582      Initial creation of component.
 *  01.01.00  2021-06-25  virwsl      CTM-3314      Upgrade to I2c__core[5.02.00].
 *  02.00.00  2022-03-07  virzln      CTM-4567      Polling mode I2c Jacinto7 feature development
 *  02.01.00  2022-08-03  virzln      CTM-4893      I2c Jacinto7 goes ASIL
 *  02.01.01  2022-11-17  virzln      CTM-5329      I2c Jacinto7 finalize ASIL D release (Safety check)
 *********************************************************************************************************************/

#if !defined (I2C_PERMGR_H)
# define I2C_PERMGR_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "I2c_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define I2C_SW_MAJOR_VERSION                 (2u)
# define I2C_SW_MINOR_VERSION                 (1u)
# define I2C_SW_PATCH_VERSION                 (1u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define I2C_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * I2c_PerMgr_Init()
 *********************************************************************************************************************/
/*! \brief       Initialization function.
 *  \details     This function initializes the module I2c_PerMgr for the specified hardware unit. It initializes
 *               required variables and enables the hardware unit.
 *  \param[in]   hwUnitId               Id of the hardware unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, I2C_CODE) I2c_PerMgr_Init(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
 * I2c_PerMgr_DeInit()
 *********************************************************************************************************************/
/*! \brief       De-Initialization function.
 *  \details     This function de-initializes the module I2c_PerMgr for the specified hardware unit.
 *  \param[in]   hwUnitId               Id of the hardware unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, I2C_CODE) I2c_PerMgr_DeInit(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
 * I2c_PerMgr_IsHwUnitIdle()
 *********************************************************************************************************************/
/*! \brief       Checks if the hardware unit idles.
 *  \details     This function is used to check if the hardware unit idles and is available for a transfer.
 *  \param[in]   hwUnitId               Id of the hardware unit.
 *  \pre         -
 *  \return      TRUE - The hardware unit is idle.
 *  \return      FALSE - The hardware unit is busy.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, I2C_CODE) I2c_PerMgr_IsHwUnitIdle(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
 * I2c_PerMgr_IrqHandler()
 *********************************************************************************************************************/
/*! \brief       Interrupt service routine.
 *  \details     This function processes the transmissions in the interrupt context. It is responsible for sending the
 *               header frames and also handles the read from / write to the data buffers.
 *  \param[in]   hwUnitId               Id of the hardware unit.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The function gets called cyclically in interrupt context.
 *********************************************************************************************************************/
FUNC(void, I2C_CODE) I2c_PerMgr_IrqHandler(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
 * I2c_PerMgr_MainFunction()
 *********************************************************************************************************************/
/*! \brief       Main function.
 *  \details     This function performs timeout monitoring. In case the timeout has expired,
 *               a bus error is reported.
 *  \param[in]   hwUnitId               Id of the hardware unit
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, I2C_CODE) I2c_PerMgr_MainFunction(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
 * I2c_PerMgr_FreeBus()
 *********************************************************************************************************************/
/*! \brief       Frees the bus
 *  \details     This function frees the bus in case the data line (SDA) is stuck LOW by sending nine clock pulses.
 *               It is called by the upper-layer sub-modules in case a timeout is detected and timeout handling is set
 *               to 'I2C_RECURRENT'.
 *  \param[in]   hwUnitId               Id of the hardware unit.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, I2C_CODE) I2c_PerMgr_FreeBus(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
 * I2c_PerMgr_ConfigHwUnit()
 *********************************************************************************************************************/
/*! \brief       Configures the hardware unit.
 *  \details     This function is used by upper-layer sub-modules to configure the baud-rate and the timeout value for
 *               the I2c peripheral. This function is called every time before a sequence is transferred.
 *  \param[in]   hwUnitId               Id of the hardware unit.
 *  \param[in]   baudrate               Baudrate to set for specified hardware unit.
 *  \param[in]   timeout                Time after which transmission should be considered as failed.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, I2C_CODE) I2c_PerMgr_ConfigHwUnit(I2c_HwUnitType hwUnitId, I2c_BaudrateType baudrate, I2c_TimeoutType timeout);

/**********************************************************************************************************************
 * I2c_PerMgr_TransData()
 *********************************************************************************************************************/
/*! \brief       Initiates a data transfer.
 *  \details     This function is called by the high-level to initiate a data transfer. The transfer is parameterized
 *               via a hardware-unit specific RAM which is set by the upper-layer sub-modules.
 *  \param[in]   hwUnitId               Id of the hardware unit.
 *  \pre         Hardware-unit is not busy.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, I2C_CODE) I2c_PerMgr_TransData(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
 * I2c_PerMgr_DetachBus()
 *********************************************************************************************************************/
/*! \brief       Detaches the peripheral from the bus.
 *  \details     This function restarts the I2c peripheral to detach from the bus. It is called by the upper-layer
 *               sub-modules in case:
 *                 - the transmission of the current sequence is cancelled (via API).
 *                 - an arbitration failure is detected and the handling is set to 'I2C_BURST'.
 *                 - a bus failure is detected.
 *  \param[in]   hwUnitId               Id of the hardware unit.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, I2C_CODE) I2c_PerMgr_DetachBus(I2c_HwUnitType hwUnitId);

# if (I2C_POLLING_MODE == STD_ON)
/**********************************************************************************************************************
 * I2c_PerMgr_PollingModeProcessing()
 *********************************************************************************************************************/
/*! \brief       Ensures proper processing of I2c communication in the case of disabled interrupts.
 *  \details     This function processes hardware dependent parts of the ongoing I2c communication.
 *  \param[in]   hwUnitId               Id of the hardware unit.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, I2C_CODE) I2c_PerMgr_PollingModeProcessing(I2c_HwUnitType hwUnitId);
# endif


# define I2C_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/*!
*\exclusivearea I2C_PERMGR_EXCLUSIVE_AREA_0
* Ensures the generation of a clean, uniform clock pulse signal which might be required by external slave devices.
* Ensures consistency of hwRuntimeDataPtr->State variable
* \protects counting the clock pulse edges, hwRuntimeDataPtr->State from modification by interrupt function.
* \usedin I2c_PerMgr_FreeBus, I2c_PerMgr_TransData, I2c_PerMgr_CheckForReportResult.
* \exclude -
* \length LONG This exclusive area covers calls to several sub-functions (especially in case of I2c_PerMgr_CheckForReportResult).
*\endexclusivearea
*/

#endif /* I2C_PERMGR_H */

/**********************************************************************************************************************
 *  END OF FILE: I2c_PerMgr.h
 *********************************************************************************************************************/
