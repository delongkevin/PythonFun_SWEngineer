/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Configuration of the HIS security module - Seed/key authentication
 *
 *  \note         Please note, that this file contains an implementation/configuration example for the security
 *                access service used by the respective vehicle manufacturer.
 *                This code may influence the behavior of the diagnostic security access in principle. Therefore,
 *                great care must be taken to verify the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. implementation proposals.
 *                With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                admissible by law or statute.
 *  -------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/*********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2015-11-03  visjhg  ESCAN00086209    Initial release
 *  01.01.00   2020-08-06  visrie  FBL-1923         Preparation of new SecModHis version
 *  01.01.01   2022-02-16  vishor  FBL-3957         Add template information in file header
 **********************************************************************************************************************/

#ifndef __SEC_SEEDKEY_CFG_H__
#define __SEC_SEEDKEY_CFG_H__

/***********************************************************************************************************************
 *   VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : SecAccess_His_Vector CQComponent : Implementation */
#define SECACCESS_HIS_VECTOR_VERSION            0x0101u
#define SECACCESS_HIS_VECTOR_RELEASE_VERSION    0x01u

/* Reference interface version */
/** Major interface version identifies incompatible changes */
#define SECACCESS_API_REFERENCE_VERSION_MAJOR      0x01u
/** Minor interface version identifies backward compatible changes */
#define SECACCESS_API_REFERENCE_VERSION_MINOR      0x00u
/** Release interface version identifies cosmetic changes */
#define SECACCESS_API_REFERENCE_VERSION_RELEASE    0x00u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* --- Configuration of seed/key interface --- */

/* Check if new SecModHis version is used which generates those defines */
#if !defined( SEC_SEED_LENGTH )
/** Seed length in bytes */
# define SEC_SEED_LENGTH      4u
/** Key length in bytes */
# define SEC_KEY_LENGTH       4u

/** Seed data stored as array of bytes */
/* # define SEC_BYTE_ARRAY_SEED */
/** Seed data stored as array of words */
/* # define SEC_WORD_ARRAY_SEED */
/** Key data stored as array of bytes */
/* # define SEC_BYTE_ARRAY_KEY */

/** Key generated using asymmetric algorithm */
/* # define SEC_ENABLE_SEED_KEY_ASYMMETRIC */
#endif /* SEC_SEED_LENGTH */

#endif /* __SEC_SEEDKEY_CFG_H__ */

/***********************************************************************************************************************
 *  END OF FILE: SEC_SEEDKEY_CFG.H
 **********************************************************************************************************************/
