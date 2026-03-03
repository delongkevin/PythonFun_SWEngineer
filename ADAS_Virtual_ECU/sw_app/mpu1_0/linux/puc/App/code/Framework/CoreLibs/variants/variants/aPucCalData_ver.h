/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:       aPucCalData_ver.h
 * DESIGN:      2018
 * DESCRIPTION: PuC Calibration Data (GDE) Version Information
 * ======================================================================== */

 /**
 * \file     aPucCalData_ver.h
 * \brief    PuC Calibration Data (GDE) Version Information
 * \author   Andreas Graf
 * \version  $Revision: 1.2 $
 * \details  h file public description of module
 */
 
#ifndef APUCCALDATA_VER_H_
#define APUCCALDATA_VER_H_

// PRQA S 2400 EOF // global scope, this is the version definition file
// PRQA S 1020 EOF // global scope, this is the version definition file

/* ######################################################################################################
 * --- HEADER VERSION ---
 * ###################################################################################################### */
#define aPucCalData_ver_D_VERSION_ID "$Id: aPucCalData_ver.h 1.2 2021/08/17 08:52:02CEST Martin Rachor (MEE_MRACHO) draft  $"

/* ######################################################################################################
 * --- Public Type definitions, Enumerations, Defines ---
 * ###################################################################################################### */

/*                                                                  YEAR  WEEK  DAY   BUILD HW    VARIANT */
#define aPucCalData_ver_D_INTERNAL_SOFTWARE_RELEASE_NUMBER_CONSTANT_VALUE  0x13, 0x2C, 0x01, 0x03, 0x00, 0x00
typedef struct aPucCalData_ver_S_VersionInformation
{
  uint8_t YEAR;
  uint8_t WEEK;
  uint8_t DAY;
  uint8_t BUILD;
  uint8_t HW;
  uint8_t VARIANT;
} aPucCalData_ver_S_VersionInformation_t;


#endif /* APUCCALDATA_VER_H_ */
