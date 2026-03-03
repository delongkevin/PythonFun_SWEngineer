#include "ErrorManagerSatelliteDef.h"
#include "ErrorManagerSatelliteApp.h"

#if ERRORMGRSATELLITE_UNDERLYINGCOMLAYER == ERRORMGR_TYPE_UNDERLYINGCOMLAYER_SIGNALMGR	
#include "SignalDef.h"
#elif ERRORMGRSATELLITE_UNDERLYINGCOMLAYER == 	ERRORMGR_TYPE_UNDERLYINGCOMLAYER_RTE
#define RTE_ERRORMGRSAT_RTE_STUB_IFDEFS
#include "ErrorManager_Rte.h"
#endif





void ErrorMgrSatelliteApp_Init(ErrorMgr_AsilList AsilLevel)
{
  /* DD-ID: {31A53C19-2EAE-4099-A1F3-9F7B22D69B95}*/
  (void)AsilLevel;
}

/* DD-ID: {E2C00D21-6132-4372-A9CB-9FBBE98E56AA}*/
/*void ErrorMgrSatelliteApp_DeInit(void)
{
  Kept for future use.
}*/

void ErrorMggrSatelliteApp_Send(const ldef_ErrorMgr_ErrorCommPack* ComPack, ErrorMgr_AsilList AsilLevel)
{
  /* DD-ID: {90BC9021-314A-4880-B003-D39D39D0F08F}*/

	switch (AsilLevel)
	{
	#if ERRMANAGER_QM_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_QM:
		(void)ERRORMGRSATELLITE_SATELLITE_SEND_QM(ComPack->pCommData);
		break;
	#endif
	#if ERRMANAGER_A_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_A:
		ERRORMGRSATELLITE_SATELLITE_SEND_A(ComPack->pCommData);
		break;
	#endif
	#if ERRMANAGER_B_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_B:
		(void)ERRORMGRSATELLITE_SATELLITE_SEND_B(ComPack->pCommData);
		break;
	#endif
	#if ERRMANAGER_C_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_C:
		ERRORMGRSATELLITE_SATELLITE_SEND_C(ComPack->pCommData);
		break;
	#endif
	#if ERRMANAGER_D_LEVEL_ACTIVE == 1
	case ErrorMgr_Asil_D:
		ERRORMGRSATELLITE_SATELLITE_SEND_D(ComPack->pCommData);
		break;
	#endif
	default:
		/* Do Nothing */
		break;
	}

}

