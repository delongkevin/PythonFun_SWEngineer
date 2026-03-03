/** @file compiler_asildefs.h
 *  @brief  
 *  Includes compiler specific asil data definitions
 *  
 * 
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * 
 *  @author Anonymous Author (Anonymous.Author@magna.com)
 */
 
#ifndef COMPILER_ASILDEFS_H_
#define COMPILER_ASILDEFS_H_
/*==================[inclusions]============================================*/
//#if !defined(BUILD_MCU2_0)
    /* Definition for clang compiler */
    #define ASILB_DATA_SECTION      __attribute__ ( ( section ( "__asilb_data__" ) ) )

    #define ASILB_CODE_SECTION      __attribute__ ( ( section ( "__asilb_code__" ) ) )

    #define ASILB_CONST_SECTION      __attribute__ ( ( section ( "__asilb_const__" ) ) )
/*#else
    #define ASILB_DATA_SECTION

    #define ASILB_CODE_SECTION

    #define ASILB_CONST_SECTION
#endif*/


#endif  /* #ifndef COMPILER_ASILDEFS_H_ */
