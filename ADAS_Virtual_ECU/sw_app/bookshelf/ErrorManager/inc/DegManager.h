#ifndef DEG_MANAGER_INCLUDEGUARD_NAME
#define DEG_MANAGER_INCLUDEGUARD_NAME

#include "DegManagercfg.h"
#include "DegManagerDef.h"
#include "DegManagerTypes.h"


#ifdef __cplusplus
extern "C" {
#endif


void DegManager_Init_QM(void);
//void DegManager_Init_A(void);
void DegManager_Init_B(void);
//void DegManager_Init_C(void);
//void DegManager_Init_D(void);

void DegManager_Periodic_QM(void);
//void DegManager_Periodic_A(void);
void DegManager_Periodic_B(void);
//void DegManager_Periodic_C(void);
//void DegManager_Periodic_D(void);

/*void * DegManager_getOutput_QM();*/
//void * DegManager_getOutput_A();
/*void * DegManager_getOutput_B();*/
//void * DegManager_getOutput_C();
//void * DegManager_getOutput_D();


void DegManager_FimCalcualtion(uint32_t *InputDataBuff,ErrorMgr_AsilList minAsilLevel,uint32_t FidMax,uint32_t *DegManager_Output,DegManager_DiagnosticDebugErrorCount *ErrorLog, const uint32* DegManager_InputMaskPtrs[ErrorMgr_Asil_MAX]);




#ifdef __cplusplus
}
#endif







#endif
