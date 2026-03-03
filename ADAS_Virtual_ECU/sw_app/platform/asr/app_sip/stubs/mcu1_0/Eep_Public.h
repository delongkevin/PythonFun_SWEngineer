/** @file Eep_Manager.c
 *  @brief Eeprom handling
 * 
 *  Eeprom handling
 * 
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 *
 *  @author Anonymous Author (Anonymous.Author@magna.com)
 */


#ifndef _EEP_PUBLIC_H_
#define _EEP_PUBLIC_H_
/*==================[inclusions]============================================*/
/*==================[internal macros]=======================================*/
# define EEP_WRITE_MAX_TIMEOUT ((60 * 1000)/100) /* NVM Write Max timer */
# define EEP_NVM_WRITEALL_IDLE                               (0x00u)
# define EEP_NVM_WRITEALL_STARTED                            (0x01u)
# define EEP_NVM_WRITEALL_COMPLETED                          (0x02u)

/*==================[internal type definitions]=============================*/
/*==================[internal function declarations]========================*/
/*==================[internal constants]====================================*/
#define EEP_DEM_DEFAULT_PROTOTYPE(NAME) \
 Std_ReturnType EEP_Default_DemPrimary##NAME(void);
/*==================[internal data]=========================================*/

EEP_DEM_DEFAULT_PROTOTYPE(0)
EEP_DEM_DEFAULT_PROTOTYPE(1)
EEP_DEM_DEFAULT_PROTOTYPE(2)
EEP_DEM_DEFAULT_PROTOTYPE(3)
EEP_DEM_DEFAULT_PROTOTYPE(4)
EEP_DEM_DEFAULT_PROTOTYPE(5)
EEP_DEM_DEFAULT_PROTOTYPE(6)
EEP_DEM_DEFAULT_PROTOTYPE(7)

Std_ReturnType EEP_Default_Test(void);

typedef struct EEP_TEST_DATA_TAG
{
    uint8 Test[8];
}EEP_TEST_DATA_T;

extern EEP_TEST_DATA_T EEP_Test;

void EEP_Init(void);
void EEP_Statemachine(void);
/*==================[external function definitions]=========================*/

#endif   /* _APPDIAG_PUBLIC_H_*/
