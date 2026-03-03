/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Configuration file for compression / decompression
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Florian Hees                  FHe           Vector Informatik GmbH
 *  Joern Herwig                  JHg           Vector Informatik GmbH
 *  Achim Strobelt                Ach           Vector Informatik GmbH
 *  Daniel Köbel                  DKl           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2006-03-15  FHe                      Initial version
 *  01.01.00   2008-10-06  FHe                      Added new define to avoid multiple inclusion
 *  01.03.00   2010-02-09  JHg                      No changes
 *  01.04.00   2010-12-09  JHg     ESCAN00047587    Configurable elemental data types
 *  01.05.00   2012-11-13  Ach     ESCAN00062975    Adapted comments to use Doxygen
 *  02.00.00   2019-07-01  DKl     ESCAN00103551    No changes
 **********************************************************************************************************************/

#ifndef __CMPR_CFG_H__
#define __CMPR_CFG_H__

/** Define watchdog function for compression module */
# define CMPR_WATCHDOG_FCT()              FblLookForWatchdog()

/* Configure elemental data types */
# define CMPR_TYPE_UINT8   vuint8
# define CMPR_TYPE_SINT8   vsint8

# define CMPR_TYPE_UINT16  vuint16
# define CMPR_TYPE_SINT16  vsint16

# define CMPR_TYPE_UINT32  vuint32
# define CMPR_TYPE_SINT32  vsint32

#endif  /* __CMPR_CFG_H__ */

/***********************************************************************************************************************
 *  END OF FILE: CMPR_CFG.H
 **********************************************************************************************************************/
