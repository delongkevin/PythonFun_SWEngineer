
#include "gtest/gtest.h"




#if defined(BUILD_MCU2_0)|| defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0) || defined (BUILD_MPU1_0)
#include "ErrorManagerDef.h"
#include "ErrorManagerSatellite.h"
#include "SignalDef.h"
#include "SignalMgr.h"
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)

#include "Rte_CDD_IPCDataHndlr.h"
#undef RTE_APPLICATION_HEADER_FILE
#include "Rte_DegManager_B.h"
#undef RTE_APPLICATION_HEADER_FILE
#include "Rte_DegManager_QM.h"
#undef RTE_APPLICATION_HEADER_FILE

#include "Rte_ErrorMgrAgg_1_0_B.h"
#undef RTE_APPLICATION_HEADER_FILE
#include "Rte_ErrorMgrSat_1_0_B.h"
#undef RTE_APPLICATION_HEADER_FILE
#include "Rte_ErrorMgrAgg_1_0_QM.h"
#undef RTE_APPLICATION_HEADER_FILE
#include "Rte_ErrorMgrSat_1_0_QM.h"
#undef RTE_APPLICATION_HEADER_FILE
//#include "Rte_ErrorMgrAgg_1_0_D.h"
#undef RTE_APPLICATION_HEADER_FILE
//#include "Rte_ErrorMgrSat_1_0_D.h"
#include "ErrorManagerTypes.h"
#include "ErrorManagerAggregator.h"
#include "ErrorManagerSatellite.h"
#include "ErrorManager_Rte.h"
#include "ErrorManagerDef.h"




#endif

#include "DegManagerGenEnTypes.h"
#include "CommonTestFramework.h"

#include "DegManagerApp_HelperFuncs.h"

#define TESTCASES_ADDITIONALCHECKS
#undef TESTCASES_ADDITIONALCHECKS

#include "TestSupportDefs.h"
#include "ErrorManagerTestDef.h"

#include <string>

#include "DegManager.h"
#include "DegManagerTypes.h"


//typedef  uint8_t DegManager_Output_QM_Type[QM_FID_MAX == 0 ? 1 : QM_FID_MAX] ;
//typedef  uint8_t DegManager_Output_A_Type[A_FID_MAX == 0 ? 1 : A_FID_MAX] ;
//typedef  uint8_t DegManager_Output_B_Type[B_FID_MAX == 0 ? 1 : B_FID_MAX] ;
//typedef  uint8_t DegManager_Output_C_Type[C_FID_MAX == 0 ? 1 : C_FID_MAX] ;
//typedef  uint8_t DegManager_Output_C_Type[D_FID_MAX == 0 ? 1 : D_FID_MAX] ;

std::vector<int> CoresToTest_AllCores = { ErrorMgr_Core_1_0,ErrorMgr_Core_2_0, ErrorMgr_Core_2_1,ErrorMgr_Core_3_0, ErrorMgr_Core_3_1,ErrorMgr_Core_QNX };
std::vector<int> CoresToTest_AllAsilLevels = { ErrorMgr_Asil_QM,ErrorMgr_Asil_B,};

std::vector<std::vector<uint32>> v_Test_AllErrors_Asil = { v_Test_AllErrors_QM,  v_Test_AllErrors_B};

extern "C"
{
	extern const uint8_t ErrorMgrAgg_RunDivisor[ErrorMgr_Asil_MAX];
}


template < class DegMgOutputType>
class Fixture_Base_ErrorMgr_Aggregator
{
public:
	//Outputs
	//ErrOutType ErrList_Output;
	DegMgOutputType mDegOutput_Module;
	DegMgOutputType mDegOutput_IPC;
	DegMgOutputType mDegOutput_RTE;
	//Safe state is unconnected hence they cannot be tested
	SafeStateActive_arr SafeStateActive_B;


	ErrorMgr_ErrorCommPack_1_0_QM Err_1_0_QM;
	ErrorMgr_ErrorCommPack_2_0_QM Err_2_0_QM;
	ErrorMgr_ErrorCommPack_2_1_QM Err_2_1_QM;
	ErrorMgr_ErrorCommPack_3_0_QM Err_3_0_QM;
	ErrorMgr_ErrorCommPack_3_1_QM Err_3_1_QM;
	ErrorMgr_ErrorCommPack_QNX_QM Err_QNX_QM;


	ErrorMgr_ErrorCommPack_1_0_B Err_1_0_B;
	ErrorMgr_ErrorCommPack_2_0_B Err_2_0_B;
	ErrorMgr_ErrorCommPack_2_1_B Err_2_1_B;
	ErrorMgr_ErrorCommPack_3_0_B Err_3_0_B;
	ErrorMgr_ErrorCommPack_3_1_B Err_3_1_B;
	ErrorMgr_ErrorCommPack_QNX_B Err_QNX_B;

	//ErrorMgr_ErrorCommPack_1_0_A Err_1_0_A;
	//ErrorMgr_ErrorCommPack_2_0_A Err_2_0_A;
	//ErrorMgr_ErrorCommPack_2_1_A Err_2_1_A;
	//ErrorMgr_ErrorCommPack_3_0_A Err_3_0_A;
	//ErrorMgr_ErrorCommPack_3_1_A Err_3_1_A;
	//ErrorMgr_ErrorCommPack_QNX_A Err_QNX_A;

	std::vector<ErrorMgr_stAddData> m_CurrentTestAdditionalDataLogged;
	ErrorMgr_AsilList m_TestAsilLevel;
	bool Check_for_F;

	Fixture_Base_ErrorMgr_Aggregator()
	{
		Rte_InitMemory_Stub();
		for (int i = 0; i < ldef_ErrorMgr_ErrorNum_Max; i++)
		{
			ErrorMgr_stAddData AddData;
			m_FillAdditionalDataStructure_RandValues(AddData);
			m_CurrentTestAdditionalDataLogged.push_back(AddData);

		}
		Check_for_F = true;
	}

	void SetCheckCondition_AsFid()
	{
		Check_for_F = true;
	}

	void SetCheckCondition_AsRes()
	{
		Check_for_F = false;
	}

	virtual void WriteSatData_Core_B(ErrorMgr_CoreList Core) = 0;
	virtual void WriteSatData_Core_QM(ErrorMgr_CoreList Core) = 0;
	virtual void ReadDeg_OutputData() = 0;


	void m_FillAdditionalDataStructure_RandValues(ErrorMgr_stAddData& data)
	{
		for (int i = 0; i < ERRORMGR_ADDITIONALDATASIZE_COUNT; i++)
		{
			data.AdditionalData[i] = rand() % 256;
		}
	}

	void CheckAdditionalData(ErrorMgr_stAddData* data1, ErrorMgr_stAddData* data2)
	{
		for (int i = 0; i < ERRORMGR_ADDITIONALDATASIZE_COUNT; i++)
		{
			EXPECT_EQ(data1->AdditionalData[i], data2->AdditionalData[i]);
		}
	}

	void m_RunPeriodic_AggRunnable(ErrorMgr_AsilList asil, int Count)
	{
		for (int i = 0; i < Count; i++)
		{
			switch (asil)
			{
			case ErrorMgr_Asil_QM:
				ErrorMgrAggregator_PeriodicFunction_QM();
				break;

			case ErrorMgr_Asil_B:
				ErrorMgrAggregator_PeriodicFunction_B();
				break;

#if ERRMANAGER_D_LEVEL_ACTIVE	== 1
			case ErrorMgr_Asil_D:
				ErrorMgrAggregator_PeriodicFunction_D();
				break;
#endif

			default:
				break;
			}
		}
	}

	void m_RunPeriodic_DegRunnable(ErrorMgr_AsilList asil, int Count)
	{
		for (int i = 0; i < Count; i++)
		{
			switch (asil)
			{

#if ERRMANAGER_QM_LEVEL_ACTIVE	== 1
			case ErrorMgr_Asil_QM:
				RE_Periodic_DegManager_QM();
				break;
#endif

#if ERRMANAGER_B_LEVEL_ACTIVE	== 1
			case ErrorMgr_Asil_B:
				RE_Periodic_DegManager_B();
				break;
#endif
			
#if ERRMANAGER_A_LEVEL_ACTIVE	== 1
			case ErrorMgr_Asil_A:
				//RE_Periodic_DegManager_A();
				std::cout << "This is a Error" << std::endl;
				break;
			#endif

#if ERRMANAGER_C_LEVEL_ACTIVE	== 1
			case ErrorMgr_Asil_C:
				//RE_Periodic_DegManager_C();
				break;
#endif

#if ERRMANAGER_D_LEVEL_ACTIVE	== 1
			case ErrorMgr_Asil_D:
				//RE_Periodic_DegManager_D();
				break;
#endif

			default:
				break;
			}
		}
	}

	void m_RunAllPeriodic_AggRunnables(int Count)
	{
		for (int i = 0; i < Count; i++)
		{
			for (auto asil : CoresToTest_AllAsilLevels)
			{
				m_RunPeriodic_AggRunnable((ErrorMgr_AsilList)asil, 1);
			}
		}
	}

	std::vector<uint32_t> Get_ErrNosApplicableToThisAsilLevel(std::vector<uint32_t> Input_ErroNos)
	{
		std::vector<uint32_t> Ouput;
		for (std::vector< ErrorMgr_enErrorNo>::iterator it = Input_ErroNos.begin(); it != Input_ErroNos.end(); it++)
		{
			if (ErrorMgr_TestDefs[*it].enAsil == m_TestAsilLevel)
			{
				Ouput.push_back(*it);
			}
		}

		return Ouput;
	}


	std::vector<uint32_t> GetOutputPositions(std::vector<ErrorMgr_enErrorNo> ErrNos)
	{
		std::vector<uint32_t> Ouput;
		std::vector<uint32_t> Input = Get_ErrNosApplicableToThisAsilLevel(ErrNos);

		for (std::vector< ErrorMgr_enErrorNo>::iterator it = Input.begin(); it != Input.end(); it++)
		{
			Ouput.push_back(ErrorMgr_TestDefs[*it].enAsilEnumVal);
		}

		return Ouput;
	}


#if 0
	void CheckIfDemIs(std::vector<uint32_t> ErrNos,uint8_t Value)
	{
		std::vector<uint32_t> Input = Get_ErrNosApplicableToThisAsilLevel(ErrNos);
		
		EXPECT_EQ(Input.size(), DemCallLogInfo.size());
		for (std::vector< ErrorMgr_enErrorNo>::iterator it = Input.begin(); it != Input.end(); it++)
		{
			bool bFound = false;
			for (std::vector< DemCallBackLogData>::iterator DLog = DemCallLogInfo.begin(); DLog != DemCallLogInfo.end(); DLog++)
			{
				if (((*DLog).DtcHigh.compare(ErrorMgr_TestDefs[*it].DiagDetails.DTCNo) == 0) && ((*DLog).DtcLow == ErrorMgr_TestDefs[*it].DiagDetails.DTCLow))
				{
					bFound = true;

				}
				EXPECT_EQ((*DLog).ExtendedId, ErrorMgr_TestDefs[*it].DiagDetails.ExtendedError);
				EXPECT_EQ((*DLog).FaultStatus, Value);
				for (int x = 0; x < ERRORMGR_ADDITIONALDATASIZE_COUNT; x++)
				{
					EXPECT_EQ((*DLog).AddData.AdditionalData[x], m_CurrentTestAdditionalDataLogged[*it].AdditionalData[x]);
				}
			}
			EXPECT_EQ(bFound, TRUE);
		}	

	}

	
	void CheckIfSet(std::vector<uint32_t> SetBitPositions, uint32_t MaxValue)
	{
		//static_assert(B_ErrorMgr_ErrorNum_Max == sizeof(ErrList_B) / sizeof(BOOL), "ErrList_B size does not match enum");
		for (uint32_t i = 0; i < MaxValue; i++)
		{
			if ((std::find(SetBitPositions.begin(), SetBitPositions.end(), i) != SetBitPositions.end()))
			{
				EXPECT_EQ(ErrList_Output[i], 1);
			}
			else
			{
				EXPECT_EQ(ErrList_Output[i], 0);
			}

		}
	}
#endif

	void CheckFidValue(uint32_t FidInhibited, bool_t Value ,uint32_t ErrorEn)
	{
		if (Check_for_F == true)
		{
			EXPECT_EQ(DEGGetError_BitPacked_Rshd_1stbitPos(mDegOutput_Module.FID_Output,FidInhibited), Value) << "Error :" << mErrurEnumStringLookup[ErrorEn] << "Fid :" << mFidStringLookup[FidInhibited];
		}
		else
		{
			EXPECT_EQ(DEGGetError_BitPacked_Rshd_1stbitPos(mDegOutput_Module.RES_Output,FidInhibited), Value) << "Error :" << mErrurEnumStringLookup[ErrorEn] << "Fid :" << mResStringLookup[FidInhibited];

		}
		//EXPECT_EQ(mDegOutput_Module[FidInhibited], Value) << "Error :" << mErrurEnumStringLookup[ErrorEn] ;
		//EXPECT_EQ(mDegOutput_Module[FidInhibited], Value) << " Fid :" << mFidStringLookup[FidInhibited];
	}


	void SetInput(ErrorMgr_enErrorNo err, BOOL bValue)
	{
		ErrorMgr_ErrorField* ErrField=NULL;
		ErrorMgr_stAddData* AdditionalData=NULL;

		if (ErrorMgr_TestDefs[err].enAsil != ErrorMgr_Asil_MAX)
		{
			switch (ErrorMgr_TestDefs[err].enCore)
			{
			case ErrorMgr_Core_1_0:
				switch (ErrorMgr_TestDefs[err].enAsil)
				{
					case ErrorMgr_Asil_QM:
						ErrField = &Err_1_0_QM.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
						AdditionalData = &Err_1_0_QM.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
						break;

					case ErrorMgr_Asil_B:
						ErrField = &Err_1_0_B.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
						AdditionalData = &Err_1_0_B.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
						break;

#if ERRMANAGER_A_LEVEL_ACTIVE	== 1
					case ErrorMgr_Asil_A:
						ErrField = &Err_1_0_A.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
						AdditionalData = &Err_1_0_A.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
						break;
#endif

					default:
						break;
				}				
				break;

			case ErrorMgr_Core_2_0:
				switch (ErrorMgr_TestDefs[err].enAsil)
				{
				case ErrorMgr_Asil_QM:
					ErrField = &Err_2_0_QM.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_2_0_QM.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;

				case ErrorMgr_Asil_B:
					ErrField = &Err_2_0_B.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_2_0_B.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;
#if ERRMANAGER_A_LEVEL_ACTIVE	== 1
				case ErrorMgr_Asil_A:
					ErrField = &Err_2_0_A.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_2_0_A.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;
#endif

				default:
					break;
				}
				break;

			case ErrorMgr_Core_2_1:
				switch (ErrorMgr_TestDefs[err].enAsil)
				{
				case ErrorMgr_Asil_QM:
					ErrField = &Err_2_1_QM.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_2_1_QM.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;

				case ErrorMgr_Asil_B:
					ErrField = &Err_2_1_B.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_2_1_B.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;

#if ERRMANAGER_A_LEVEL_ACTIVE	== 1
				case ErrorMgr_Asil_A:
					ErrField = &Err_2_1_A.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_2_1_A.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;
#endif

				default:
					break;
				}
				break;


			case ErrorMgr_Core_3_0:
				switch (ErrorMgr_TestDefs[err].enAsil)
				{
				case ErrorMgr_Asil_QM:
					ErrField = &Err_3_0_QM.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_3_0_QM.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;

				case ErrorMgr_Asil_B:
					ErrField = &Err_3_0_B.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_3_0_B.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;

#if ERRMANAGER_A_LEVEL_ACTIVE	== 1
				case ErrorMgr_Asil_A:
					ErrField = &Err_3_0_A.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_3_0_A.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;
#endif

				default:
					break;
				}
				break;


			case ErrorMgr_Core_3_1:
				switch (ErrorMgr_TestDefs[err].enAsil)
				{
				case ErrorMgr_Asil_QM:
					ErrField = &Err_3_1_QM.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_3_1_QM.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;

				case ErrorMgr_Asil_B:
					ErrField = &Err_3_1_B.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_3_1_B.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;
#if ERRMANAGER_A_LEVEL_ACTIVE	== 1
				case ErrorMgr_Asil_A:
					ErrField = &Err_3_1_A.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_3_1_A.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;
#endif

				default:
					break;
				}
				break;


			case ErrorMgr_Core_QNX:
				switch (ErrorMgr_TestDefs[err].enAsil)
				{
				case ErrorMgr_Asil_QM:
					ErrField = &Err_QNX_QM.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_QNX_QM.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;

				case ErrorMgr_Asil_B:
					ErrField = &Err_QNX_B.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_QNX_B.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;
#if ERRMANAGER_A_LEVEL_ACTIVE	== 1
				case ErrorMgr_Asil_A:
					ErrField = &Err_QNX_A.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					AdditionalData = &Err_QNX_A.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
					break;
#endif

				default:
					break;
				}
				break;

			default:
				break;
			}

			if (ErrField == NULL)
			{
				EXPECT_EQ(FALSE, TRUE) << "ErrField == NULL . Invalid data";
			}
			else
			{

				*ErrField = bValue;
				*AdditionalData = m_CurrentTestAdditionalDataLogged[err];
			}
		}



	}

	void ClearInput_CoreFullStruct(ErrorMgr_CoreList Core)
	{
		switch (Core)
		{
		case ErrorMgr_Core_1_0:
			memset(&Err_1_0_QM, 0, sizeof(Err_1_0_QM));
			//memset(&Err_1_0_A, 0, sizeof(Err_1_0_A));
			memset(&Err_1_0_B, 0, sizeof(Err_1_0_B));
			break;
		case ErrorMgr_Core_2_0:
			memset(&Err_2_0_QM, 0, sizeof(Err_2_0_QM));
			//memset(&Err_2_0_A, 0, sizeof(Err_2_0_A));
			memset(&Err_2_0_B, 0, sizeof(Err_2_0_B));
			break;
		case ErrorMgr_Core_2_1:
			memset(&Err_2_1_QM, 0, sizeof(Err_2_1_QM));
			//memset(&Err_2_1_A, 0, sizeof(Err_2_1_A));
			memset(&Err_2_1_B, 0, sizeof(Err_2_1_B));
			break;
		case ErrorMgr_Core_3_0:
			memset(&Err_3_0_QM, 0, sizeof(Err_3_0_QM));
			//memset(&Err_3_0_A, 0, sizeof(Err_3_0_A));
			memset(&Err_3_0_B, 0, sizeof(Err_3_0_B));
			break;
		case ErrorMgr_Core_3_1:
			memset(&Err_3_1_QM, 0, sizeof(Err_3_1_QM));
			//memset(&Err_3_1_A, 0, sizeof(Err_3_1_A));
			memset(&Err_3_1_B, 0, sizeof(Err_3_1_B));
			break;
		case ErrorMgr_Core_QNX:
			memset(&Err_QNX_QM, 0, sizeof(Err_QNX_QM));
			//memset(&Err_QNX_A, 0, sizeof(Err_QNX_A));
			memset(&Err_QNX_B, 0, sizeof(Err_QNX_B));
			break;
		default:
			break;
		}

	}

	void ClearInput_AllCoreFullStruct()
	{
		for (int i = 0; i < ErrorMgr_Core_CORE_MAX; i++)
		{
			ClearInput_CoreFullStruct((ErrorMgr_CoreList)i);
		}

	}

#if 0
	void ClearInput_ErrorInfo(ErrorMgr_CoreList Core)
	{
		switch (Core)
		{
		case ErrorMgr_Core_1_0:
			memset(&Err_1_0.Error, 0, sizeof(Err_1_0.Error));
			break;
		case ErrorMgr_Core_2_0:
			memset(&Err_2_0.Error, 0, sizeof(Err_2_0.Error));
			break;
		case ErrorMgr_Core_2_1:
			memset(&Err_2_1.Error, 0, sizeof(Err_2_1.Error));
			break;
		case ErrorMgr_Core_3_0:
			memset(&Err_3_0.Error, 0, sizeof(Err_3_0.Error));
			break;
		case ErrorMgr_Core_3_1:
			memset(&Err_3_1.Error, 0, sizeof(Err_3_1.Error));
			break;
		case ErrorMgr_Core_QNX:
			memset(&Err_QNX.Error, 0, sizeof(Err_QNX.Error));
			break;
		default:
			break;
		}

	}

	void ClearInput_AllCoreErrorInfo(ErrorMgr_CoreList Core)
	{
		for (int i = 0; i < ErrorMgr_Core_CORE_MAX; i++)
		{
			ClearInput_ErrorInfo((ErrorMgr_CoreList)i);
		}

	}
#endif



	void ClearError_Single(ErrorMgr_enErrorNo err)
	{
		SetInput(err, 0);
	}


	void SetError_Single(ErrorMgr_enErrorNo err)
	{
		SetInput(err, 1);
	}



	void WriteSatDataOutput_AllCores_AllAsil()
	{
		for (int i = 0; i < ErrorMgr_Core_CORE_MAX; i++)
		{
			WriteSatData_Core_B((ErrorMgr_CoreList)i);
			WriteSatData_Core_QM((ErrorMgr_CoreList)i);
		}

	}



	

	void TestFunction_FidSettingClearing_ForError(uint32_t errNo,uint32_t FidInhibited,uint32_t OutputErrMax)
	{
		if (errNo < ldef_ErrorMgr_ErrorNum_Max)
		{

			std::cout << "Info: Tesing :" << "Erren :" << mErrurEnumStringLookup[errNo] << "Fid :" << mFidStringLookup[FidInhibited];

			ClearInput_AllCoreFullStruct();
			DemCallLogInfo.clear();

			//ReadAgg_OutputData();
			ReadDeg_OutputData();
			//Expect the output to be cleared
			//CheckIfSet(std::vector<uint32_t>(), OutputErrMax);
			CheckFidValue(FidInhibited, FALSE, errNo);
	

			SetError_Single(errNo);


			WriteSatDataOutput_AllCores_AllAsil();

			m_RunAllPeriodic_AggRunnables(ErrorMgrAgg_RunDivisor[m_TestAsilLevel]);

			m_RunPeriodic_DegRunnable(m_TestAsilLevel, DEGRADATIONMANAGER_QM_EXECUTION_DIVISOR_COUNT);

			//Check Aggregator output is as expected
			//ReadAgg_OutputData();
			ReadDeg_OutputData();

			//std::vector<uint32_t> enToCheck = { errNo };
			//std::vector< uint32_t> OutPos = GetOutputPositions(enToCheck);
			//CheckIfSet(OutPos, OutputErrMax);
			//CheckIfDemIs(enToCheck, 1);

			//Check if FidIsSet
			CheckFidValue(FidInhibited, TRUE, errNo);

			//if this error has asil B Error
			ClearError_Single(errNo);

			WriteSatDataOutput_AllCores_AllAsil();

			m_RunAllPeriodic_AggRunnables(ErrorMgrAgg_RunDivisor[m_TestAsilLevel]);

			m_RunPeriodic_DegRunnable(m_TestAsilLevel, DEGRADATIONMANAGER_QM_EXECUTION_DIVISOR_COUNT);

			//ReadAgg_OutputData();
			ReadDeg_OutputData();

			//Expect the output to be cleared
			//CheckIfSet(std::vector<uint32_t>(), OutputErrMax);
			//CheckIfDemIs(enToCheck, 0);


			//Check if FidIsCleared
			CheckFidValue(FidInhibited, FALSE, errNo);

		}

	}


};

template < class Outputtype>
class ReadWriteHelper :public Fixture_Base_ErrorMgr_Aggregator<Outputtype>
{
	void WriteSatData_Core_B(ErrorMgr_CoreList Core)
	{
		switch (Core)
		{
		case ErrorMgr_Core_1_0:
			Err_1_0_B.RunningCounter += 1;
			Rte_Write_ErrorMgrSat_1_0_B_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B(&Err_1_0_B);
			break;
		case ErrorMgr_Core_2_0:
			Err_2_0_B.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B(&Err_2_0_B);
			break;
		case ErrorMgr_Core_2_1:
			Err_2_1_B.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B(&Err_2_1_B);
			break;
		case ErrorMgr_Core_3_0:
			Err_3_0_B.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_3_0_B(&Err_3_0_B);
			break;
		case ErrorMgr_Core_3_1:
			Err_3_1_B.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_3_1_B(&Err_3_1_B);
			break;
		case ErrorMgr_Core_QNX:
			Err_QNX_B.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B(&Err_QNX_B);
			break;
		default:
			break;
		}

	}


	void WriteSatData_Core_QM(ErrorMgr_CoreList Core)
	{
		switch (Core)
		{
		case ErrorMgr_Core_1_0:
			Err_1_0_QM.RunningCounter += 1;
			Rte_Write_ErrorMgrSat_1_0_QM_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM(&Err_1_0_QM);
			break;
		case ErrorMgr_Core_2_0:
			Err_2_0_QM.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM(&Err_2_0_QM);
			break;
		case ErrorMgr_Core_2_1:
			Err_2_1_QM.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM(&Err_2_1_QM);
			break;
		case ErrorMgr_Core_3_0:
			Err_3_0_QM.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_3_0_QM(&Err_3_0_QM);
			break;
		case ErrorMgr_Core_3_1:
			Err_3_1_QM.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_3_1_QM(&Err_3_1_QM);
			break;
		case ErrorMgr_Core_QNX:
			Err_QNX_QM.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM(&Err_QNX_QM);
			break;
		default:
			break;
		}

	}

};



class Fixture_FID_B : public ReadWriteHelper<DegManager_Output_B_t>, public ::testing::TestWithParam < std::tuple<uint32_t, std::vector<uint32_t>>>
{
public:

	Fixture_FID_B()
	{
		m_TestAsilLevel = ErrorMgr_Asil_B;
	}

	void SetUp()
	{
		ErrorMgrAggregator_Init_B();
		//RE_Init_ErrorMgrAgg_1_0_B();
		RE_Init_DegManager_B();
	}

	void TearDown()
	{

	}

#if 0
	void ReadAgg_OutputData()
	{
		Rte_Read_DegManager_B_R_Errors_B_Errors_B((BOOL *)&ErrList_Output);
	}
#endif

	void ReadDeg_OutputData()
	{
		memcpy(&mDegOutput_Module, DegManager_getOutput_B(), sizeof(mDegOutput_Module));
	}


};

class Fixture_FID_QM : public ReadWriteHelper<DegManager_Output_QM_t>, public ::testing::TestWithParam< std::tuple<uint32_t, std::vector<uint32_t>>>
{
public:

	Fixture_FID_QM()
	{
		m_TestAsilLevel = ErrorMgr_Asil_QM;
	}

	void SetUp()
	{
		ErrorMgrAggregator_Init_QM();
		//RE_Init_ErrorMgrAgg_1_0_QM();
		RE_Init_DegManager_QM();
	}

	void TearDown()
	{

	}

	void ReadDeg_OutputData()
	{
		memcpy(&mDegOutput_Module, DegManager_getOutput_QM(), sizeof(mDegOutput_Module));
	}

};

class Fixture_RES_QM : public ReadWriteHelper<DegManager_Output_QM_t>, public ::testing::TestWithParam< std::tuple<uint32_t, std::vector<uint32_t>>>
{
public:

	Fixture_RES_QM()
	{
		m_TestAsilLevel = ErrorMgr_Asil_QM;
	}

	void SetUp()
	{
		ErrorMgrAggregator_Init_QM();
	}

	void TearDown()
	{

	}

	void ReadDeg_OutputData()
	{
		memcpy(&mDegOutput_Module, DegManager_getOutput_QM(), sizeof(mDegOutput_Module));
	}

};

class Fixture_RES_B : public ReadWriteHelper<DegManager_Output_B_t>, public ::testing::TestWithParam < std::tuple<uint32_t, std::vector<uint32_t>>>
{
public:

	Fixture_RES_B()
	{
		m_TestAsilLevel = ErrorMgr_Asil_B;
	}

	void SetUp()
	{
		ErrorMgrAggregator_Init_B();
	}

	void TearDown()
	{

	}

#if 0
	void ReadAgg_OutputData()
	{
		Rte_Read_DegManager_B_R_Errors_B_Errors_B((BOOL*)&ErrList_Output);
	}
#endif

	void ReadDeg_OutputData()
	{
		memcpy(&mDegOutput_Module, DegManager_getOutput_B(), sizeof(mDegOutput_Module));
	}


};




TEST_P(Fixture_FID_QM, Fid_PerError)
{

	uint32_t Error = std::get<0>(GetParam());
	std::vector<uint32_t> Fids = std::get<1>(GetParam());

	SetCheckCondition_AsFid();

	for (int j = 0; j < Fids.size(); j++)
	{
		TestFunction_FidSettingClearing_ForError(Error, Fids[j], ldef_QM_ErrorMgr_ErrorNum_Max);
	}		

}

TEST_P(Fixture_FID_B, Fid_PerError)
{
	uint32_t Error = std::get<0>(GetParam());
	std::vector<uint32_t> Fids = std::get<1>(GetParam());

	SetCheckCondition_AsFid();

	for (int j = 0; j < Fids.size(); j++)
	{
		TestFunction_FidSettingClearing_ForError(Error, Fids[j], ldef_B_ErrorMgr_ErrorNum_Max);
	}

}


TEST_P(Fixture_RES_QM, RES_PerError)
{

	uint32_t Error = std::get<0>(GetParam());
	std::vector<uint32_t> Fids = std::get<1>(GetParam());

	SetCheckCondition_AsRes();

	for (int j = 0; j < Fids.size(); j++)
	{
		TestFunction_FidSettingClearing_ForError(Error, Fids[j], ldef_QM_ErrorMgr_ErrorNum_Max);
	}

}

TEST_P(Fixture_RES_B, RES_PerError)
{
	uint32_t Error = std::get<0>(GetParam());
	std::vector<uint32_t> Fids = std::get<1>(GetParam());

	SetCheckCondition_AsRes();

	for (int j = 0; j < Fids.size(); j++)
	{
		TestFunction_FidSettingClearing_ForError(Error, Fids[j], ldef_B_ErrorMgr_ErrorNum_Max);
	}

}


/*
TEST_P(Fixture_DegMgr_QM, Res_PerError)
{

	uint32_t Error = std::get<0>(GetParam());
	std::vector<uint32_t> Fids = std::get<1>(GetParam());

	SetCheckCondition_AsFid();

	for (int j = 0; j < Fids.size(); j++)
	{
		TestFunction_FidSettingClearing_ForError(Error, Fids[j], ldef_QM_ErrorMgr_ErrorNum_Max);
	}

}

TEST_P(Fixture_DegMgr_B, Fid_PerError)
{
	uint32_t Error = std::get<0>(GetParam());
	std::vector<uint32_t> Fids = std::get<1>(GetParam());

	SetCheckCondition_AsFid();

	for (int j = 0; j < Fids.size(); j++)
	{
		TestFunction_FidSettingClearing_ForError(Error, Fids[j], ldef_B_ErrorMgr_ErrorNum_Max);
	}

}
*/


TEST(HelperFunc, Conv_QM)
{
	TestFunction_Conv_QM();
}

TEST(HelperFunc, Conv_B)
{
	TestFunction_Conv_B();
}



INSTANTIATE_TEST_CASE_P( FID_QM_perErr, Fixture_FID_QM,
		::testing::ValuesIn(TestErrormap_vect_ErrorToFid_QM_FID_),
);

INSTANTIATE_TEST_CASE_P(FID_B_perErr, Fixture_FID_B,
	::testing::ValuesIn(TestErrormap_vect_ErrorToFid_B_FID_),
	);

INSTANTIATE_TEST_CASE_P(RES_QM_perErr, Fixture_RES_QM,
	::testing::ValuesIn(TestErrormap_vect_ErrorToFid_QM_RES_),
	);

INSTANTIATE_TEST_CASE_P(RES_B_perErr, Fixture_RES_B,
	::testing::ValuesIn(TestErrormap_vect_ErrorToFid_B_RES_),
	);






int main(int argc, char **argv) {
      ::testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
}


