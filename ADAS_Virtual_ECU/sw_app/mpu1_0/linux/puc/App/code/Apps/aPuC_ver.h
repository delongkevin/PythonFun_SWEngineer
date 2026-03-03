/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:       aPuC_ver.h
 * DESIGN:      2018
 * DESCRIPTION: PuC Version Information
 * ======================================================================== */

 /**
 * \file     aPuC_ver.h
 * \brief    PuC Version Information
 * \author   Marcel Engelhardt
 * \version  $Revision: 1.2 $
 * \details  h file public description of module
 */
 
#ifndef APUC_VER_H_
#define APUC_VER_H_

// PRQA S 2400 EOF // global scope, this is the version definition file
// PRQA S 1020 EOF // global scope, this is the version definition file

/* ######################################################################################################
 * --- HEADER VERSION ---
 * ###################################################################################################### */
#define aPuC_ver_D_VERSION_ID "$Id: aPuC_ver.h 1.2 2021/08/17 08:51:53CEST Martin Rachor (MEE_MRACHO) draft  $"

#define PARTNUMBER "C01 050A3"

/* ######################################################################################################
 * --- Public Type definitions, Enumerations, Defines ---
 * ###################################################################################################### */

/*                                                                  YEAR  WEEK  DAY   BUILD HW    VARIANT */
#define aPuC_ver_D_INTERNAL_SOFTWARE_RELEASE_NUMBER_CONSTANT_VALUE  0x15, 0x1D, 0x02, 0x01, 0x00, 0x00
typedef struct aPuC_ver_S_VersionInformation
{
  uint8_t YEAR;
  uint8_t WEEK;
  uint8_t DAY;
  uint8_t BUILD;
  uint8_t HW;
  uint8_t VARIANT;
} aPuC_ver_S_VersionInformation_t;


#endif /* APUC_VER_H_ */
