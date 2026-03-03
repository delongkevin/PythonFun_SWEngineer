/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Definition of common data structures which are shared between
 *                 bootloader and application software
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *
 *  \par Note
 *  \verbatim
 *  Please note, that this file contains a collection of callback functions to be used with the Flash Bootloader. 
 *  These functions may influence the behaviour of the bootloader in principle. 
 *  Therefore, great care must be taken to verify the correctness of the implementation.
 * 
 *  The contents of the originally delivered files are only examples resp. implementation proposals. 
 *  With regard to the fact that these functions are meant for demonstration purposes only, Vector Informatik´s 
 *  liability shall be expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute. 
 *  \endverbatim  
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Christian Baeuerle            CB            Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  00.01.00   2018-01-11  CB      -                Initial Implementation
 *  01.00.00   2018-07-11  CB      -                Initial Release
 *  01.00.01   2018-08-10  CB      -                Corrected size of VIN Origina
 **********************************************************************************************************************/

#ifndef __COMDAT_H__
#define __COMDAT_H__

/*
   The following typedefs avoid the usage of Vector types (e.g. vuint8) so
   they can be easily re-used in the application software.
 */

/* Type definition for process information values */
typedef unsigned char tFblDiagSpecInformation[4];
typedef unsigned char tFblDiagDiagnosticVariant[2];
typedef unsigned char tFblDiagSwDefinitionNumber[2];
typedef unsigned char tFblDiagSupplierId[2];
typedef unsigned char tFblEcuSerialNumber[16];
typedef unsigned char tFblVinOriginal[17];
typedef unsigned char tFblVehicleManufEcuHwNumber[11];
typedef unsigned char tFblSuppManEcuHwPartNumber[11];
typedef unsigned char tFblSuppManEcuHwVersionNumber[1];
typedef unsigned char tFblBootSoftwareVersionInformation[13];
typedef unsigned char tFblStandardBootloaderSoftwareInformation[8];
typedef unsigned char tFblHardwareSupplierId[2];
typedef unsigned char tFblSoftwareSupplierId[2];

typedef unsigned char tFblAlgorithmIdNumber[2];

typedef struct tagFblCommonData
{
   /* F10D - Diagnostic Specification Information */
   tFblDiagSpecInformation                   diagSpecInfo;

   /* F110 - ECU Diagnostic Information
    * data elements which are not updated after an application download 
    */
   tFblDiagDiagnosticVariant                 diagnosticVariant;
   tFblDiagSwDefinitionNumber                swDefinitonNumber;
   tFblDiagSupplierId                        supplierId;

   /* F190 */
   tFblVinOriginal                           VinOriginal;

   /* F191 */
   tFblVehicleManufEcuHwNumber               VehicleManufEcuHwNumber;
   
   /* F192 */
   tFblSuppManEcuHwPartNumber                SuppManEcuHwPartNumber;
   
   /* F193 */
   tFblSuppManEcuHwVersionNumber             SuppManEcuHwVersionNumber;

   /* F180 */
   tFblBootSoftwareVersionInformation        bootSoftwareVersionInformation;

   /* F154 */
   tFblHardwareSupplierId                    HwSupplierId;
   
   /* F155 */
   tFblSoftwareSupplierId                    swSupplierId;

   /* F1A4 */
   tFblAlgorithmIdNumber                     algorithmIdNumber;
   

   tFblStandardBootloaderSoftwareInformation StandardBootloaderSoftwareInformation;

} tFblCommonData;

#if defined( VGEN_ENABLE_CANFBL )
#else
/** Common data access macro for usage in the application software */
# define fblCommonData   (*((V_MEMROM1_FAR tFblCommonData V_MEMROM2_FAR *)GetFblCommonDataPtr()))
#endif

#endif /* __COMDAT_H__ */

/***********************************************************************************************************************
 *  END OF FILE: _COMDAT.H
 **********************************************************************************************************************/
