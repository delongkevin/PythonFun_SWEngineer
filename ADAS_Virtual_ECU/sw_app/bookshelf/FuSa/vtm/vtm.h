/** @file vtm.h 
 *  @brief  VTM 
 * 
 *  Voltage and Thermal Module (VTM) Application
 * 
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * 
 *  @author Matt Kloepfer (Matt.Kloepfer@magna.com)
 */

#ifndef VTM_APP_H_
#define VTM_APP_H_

#include <sdl_types.h>

#define FUSA_VTM_NO_ERROR (0u)
#define FUSA_VTM_OVERTEMP_WARNING (1u)
#define FUSA_VTM_MAX_ERROR (8u)

#define VTM_Thermal_Pre_warning_detected (1u<<0u)
#define VTM_Overtemperature_detected (1u<<1u)
#define VTM_Parity_error_on_VTM_configuration_registers (1u<<2u)
#define VTM_Configuration_readback_error_VTM_registers (1u<<3u)
#define VTM_Fault_inject_test_failure_on_Over_temperature_detection (1u<<4u)
#define VTM_Fault_inject_test_error_on_Parity_detection_logic__VTM_configuration_registers (1u<<5u)

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

void TASK_vtm_app_init(void);
uint8_t Vtm_app_check_error_status(void);
void Vtm_MainFunction(void);


#endif /*  VTM_APP_H_ */
