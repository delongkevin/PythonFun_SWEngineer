/**********************************************************************************************************************
 *  This is a Sample header file Created by the FblIntegrationAssistant Tool
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  FblIntegrationAssistant        virely        Vector Informatik GmbH
 *********************************************************************************************************************/



#ifndef PRESENSE_PATTERN_MEMMAP_H
#define PRESENSE_PATTERN_MEMMAP_H

#define FBL_MEMMAP_ERROR

#if defined( FBL_PP_START_SEC_CONST )
 __attribute__ ((section (".PresencePatternSection")))
 __attribute__ ((retain))
# undef FBL_PP_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_PP_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_PP_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#endif /* PRESENSE_PATTERN_MEMMAP_H */