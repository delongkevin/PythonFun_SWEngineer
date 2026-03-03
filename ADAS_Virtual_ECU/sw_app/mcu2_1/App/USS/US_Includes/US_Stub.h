#ifndef _US_STUB_H
#define _US_STUB_H

#define US_COM_D_INPUT_DATA_PERIODICITY	(4U)

#include "US_ComInputBuffer_Global.h"
#include "USS_Library_Header.h"


/*definition of shared Input data buffers */
void US_ComShareOutputBuff(void *Data);
void UssCom_F_OutputDataShareMain(void);
void UssCom_F_InputDataShareMain(void);
void ME_US_F_RegisterDataCopyCallBackInput(void);
uint16_t US_Get_DynamicCalMsgID(void);

#endif
