/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        OEM specific assertion defines
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2020-03-25  vistbe  FBL-1510         No changes
 *                                 ESCAN00105933    No changes
 *                                 ESCAN00105934    No changes
 *                                 ESCAN00105730    No changes
 *                                 ESCAN00105864    No changes
 *  02.00.01   2020-05-26  visjdn  ESCAN00105865    No changes
 *  02.01.00   2020-06-16  vistbe  FBL-1919         No changes
 *  02.02.00   2020-07-13  visrie  FBL-2021         Added support for OTA
 *                                 ESCAN00106775    No changes
 *  02.02.01   2020-11-02  visrcn  ESCAN00105639    No changes
 *  02.03.00   2020-12-17  vistbe  FBL-1352         No changes
 *  02.04.00   2021-04-14  vistmo  FBL-2961         No changes
 *  02.04.01   2021-08-18  vistbe  ESCAN00109813    No changes
 *  02.05.00   2021-08-24  vishor  FBL-3800         No changes
 *  02.05.01   2021-11-09  visrie  ESCAN00110248    No changes
 *  02.06.00   2022-01-20  vistmo  FBL-4156         No changes
 *  02.06.01   2022-02-16  visrie  ESCAN00110576    No changes
 *                                 ESCAN00110609    No changes
 *  02.07.00   2022-06-14  visrie  ESCAN00111989    No changes
 *  02.07.01   2022-07-27  vismix  ESCAN00109293    No changes
 *  02.07.02   2022-10-14  visjns  ESCAN00112112    No changes
 *  02.07.03   2022-11-16  vismix  ESCAN00112841    No changes
 *                                 ESCAN00112884    No changes
 *  02.07.04   2022-11-21  vismix  ESCAN00112934    No changes
 *  02.08.00   2022-12-02  visjdn  FBL-6117         No changes
 *                                 ESCAN00110368    No changes
 *                                 ESCAN00112786    No changes
 *                                 ESCAN00113224    No changes
 **********************************************************************************************************************/

#ifndef FBL_ASSERT_OEM_H
#define FBL_ASSERT_OEM_H

/***********************************************************************************************************************
 *  DEFINITION OF ASSERTION CODES (OEM)
 **********************************************************************************************************************/

/* 0x80-0xFF: OEM specific */
/* Diagnostic module errors */
#define kFblOemAssertMainHandlerIdxInvalid   0x80u
#define kFblOemAssertWrongServiceHandler     0x81u
#define kFblOemAssertInvalidError            0x82u
#define kFblOemAssertNoNrcSet                0x83u

#define kFblOemAssertParameterOutOfRange     0xA0u
#define kFblOemAssertIllegalReturnValue      0xA1u

/***********************************************************************************************************************
 *  END OF FILE: FBL_ASSERT_OEM.H
 **********************************************************************************************************************/

#endif /* FBL_ASSERT_OEM_H */
