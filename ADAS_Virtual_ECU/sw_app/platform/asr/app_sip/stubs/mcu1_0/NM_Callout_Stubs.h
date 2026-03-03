#include "Can_GeneralTypes.h"

#include "EcuM.h"



/***************************************************************************/
/* function prototypes / API                                               */
/***************************************************************************/
void CanWUp_Val_StartWakeUpValidation(void);

void CanWUp_Val_StopWakeUpValidation(void);

void CanWUp_Val_CheckPN(VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource);
