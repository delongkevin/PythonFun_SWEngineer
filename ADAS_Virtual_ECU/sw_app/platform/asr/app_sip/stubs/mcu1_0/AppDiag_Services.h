/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 * This document in its entirety is CONFIDENTIAL and may not be disclosed,
 * disseminated or distributed to parties outside MAGNA Electronics
 * without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:       Dcm callout function
 * DESIGN:      2022
 * DESCRIPTION: Dcm callout function
 * ======================================================================== */

/**
 * \file     AppDiag_Services.h
 * \brief    Dcm callout function
 * \author   Bhagwan Patil
 * \version
 * \details  h file public description of module
 */
/* ======================================================================== */


/* ======================================================================== */


#define NO_RESET  0x0u
#define BOOTLOADER_RESET 0x1u
#define SOFT_RESET 0x2u

void EEP_Shutdown(void);
void BSW_Set_SC_CAL_ResetType(void);
void ReqSciclientECUReset(void);
void AppDiag_InternalError_SysResetReq(void);