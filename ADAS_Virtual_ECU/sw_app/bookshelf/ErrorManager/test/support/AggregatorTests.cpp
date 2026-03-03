#include "pch.h"





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
#include "Rte_ErrorMgrAgg_1_0_D.h"
#undef RTE_APPLICATION_HEADER_FILE
#include "Rte_ErrorMgrSat_1_0_D.h"
#include "ErrorManagerTypes.h"
#include "ErrorManagerAggregator.h"
#include "ErrorManagerSatellite.h"
#include "ErrorManager_Rte.h"
#include "ErrorManagerDef.h"




#endif



#define TESTCASES_ADDITIONALCHECKS
#undef TESTCASES_ADDITIONALCHECKS

#include "TestSupportDefs.h"
#include "ErrorManagerTestDef.h"

std::vector<int> CoresToTest_AllCores = { ErrorMgr_Core_1_0,ErrorMgr_Core_2_0, ErrorMgr_Core_2_1,ErrorMgr_Core_3_0, ErrorMgr_Core_3_1,ErrorMgr_Core_QNX };
std::vector<int> CoresToTest_AllAsilLevels = { ErrorMgr_Asil_QM,ErrorMgr_Asil_A,ErrorMgr_Asil_B,ErrorMgr_Asil_C,ErrorMgr_Asil_D };

std::vector<std::vector<uint32>> v_Test_AllErrors_Asil = { v_Test_AllErrors_QM, v_Test_AllErrors_A, v_Test_AllErrors_B, v_Test_AllErrors_C, v_Test_AllErrors_D };

typedef struct
{
	std::string DtcHigh;
	uint16_t DtcLow;
	uint8 FaultStatus;
	uint16_t ExtendedId;
	ErrorMgr_stAddData AddData;
}DemCallBackLogData;

std::vector<DemCallBackLogData> DemCallLogInfo;

extern "C"
{
	Std_ReturnType TEST_FRAMEWORK_DIAGMGR_CALLBACK(const char* DtcHigh, uint16_t DtcLow, uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, uint8* i_AdditionalData_pu8)
	{
		DemCallBackLogData mData;

		bool bFound = false;
		for (std::vector< DemCallBackLogData>::iterator DLog = DemCallLogInfo.begin(); DLog != DemCallLogInfo.end(); DLog++)
		{
			if (((*DLog).DtcHigh.compare(DtcHigh) == 0) && ((*DLog).DtcLow == DtcLow))
			{
				bFound = true;
				(*DLog).ExtendedId = i_Fault_Flag_u16;
				(*DLog).FaultStatus = i_FaultStatus_u8;
				for (int i = 0; i < ERRORMGR_ADDITIONALDATASIZE_COUNT; i++)
				{
					(*DLog).AddData.AdditionalData[i] = i_AdditionalData_pu8[i];
				}
			}
		}

		if (bFound == false)
		{
			for (int i = 0; i < ERRORMGR_ADDITIONALDATASIZE_COUNT; i++)
			{
				mData.AddData.AdditionalData[i] = i_AdditionalData_pu8[i];
			}
			mData.DtcHigh.assign(DtcHigh);
			mData.DtcLow = DtcLow;
			mData.FaultStatus = i_FaultStatus_u8;
			mData.ExtendedId = i_Fault_Flag_u16;

			DemCallLogInfo.push_back(mData);
		}

		return E_OK;
	}
}


template <class ErrOutType,class Err_1_0_type, class Err_2_0_type, class Err_2_1_type, class Err_3_0_type, class Err_3_1_type, class Err_QNX_type>
class Fixture_Base_ErrorMgr_Aggregator
{
public:
	//Outputs
	ErrOutType ErrList_Output;
	//Safe state is unconnected hence they cannot be tested
	SafeStateActive_arr SafeStateActive_B;

	Err_1_0_type Err_1_0;
	Err_2_0_type Err_2_0;
	Err_2_1_type Err_2_1;
	Err_3_0_type Err_3_0;
	Err_3_1_type Err_3_1;
	Err_QNX_type Err_QNX;

	std::vector<ErrorMgr_stAddData> m_CurrentTestAdditionalDataLogged;
	ErrorMgr_AsilList m_TestAsilLevel;

	Fixture_Base_ErrorMgr_Aggregator()
	{
		Rte_InitMemory_Stub();
		for (int i = 0; i < ErrorMgr_ErrorNum_Max; i++)
		{
			ErrorMgr_stAddData AddData;
			m_FillAdditionalDataStructure_RandValues(AddData);
			m_CurrentTestAdditionalDataLogged.push_back(AddData);

		}
	}

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

			case ErrorMgr_Asil_D:
				ErrorMgrAggregator_PeriodicFunction_D();
				break;

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


	void SetInput(ErrorMgr_enErrorNo err, BOOL bValue)
	{
		ErrorMgr_ErrorField* ErrField;
		ErrorMgr_stAddData* AdditionalData;

		if (ErrorMgr_TestDefs[err].enAsil == m_TestAsilLevel)
		{
			switch (ErrorMgr_TestDefs[err].enCore)
			{
			case ErrorMgr_Core_1_0:
				ErrField = &Err_1_0.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
				AdditionalData = &Err_1_0.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
				break;
			case ErrorMgr_Core_2_0:
				ErrField = &Err_2_0.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
				AdditionalData = &Err_2_0.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
				break;
			case ErrorMgr_Core_2_1:
				ErrField = &Err_2_1.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
				AdditionalData = &Err_2_1.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
				break;
			case ErrorMgr_Core_3_0:
				ErrField = &Err_3_0.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
				AdditionalData = &Err_3_0.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
				break;
			case ErrorMgr_Core_3_1:
				ErrField = &Err_3_1.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
				AdditionalData = &Err_3_1.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
				break;
			case ErrorMgr_Core_QNX:
				ErrField = &Err_QNX.Error[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
				AdditionalData = &Err_QNX.Data[ErrorMgr_TestDefs[err].enCoreAsilSpecificEnumVal];
				break;
			default:
				break;
			}

			*ErrField = bValue;
			*AdditionalData = m_CurrentTestAdditionalDataLogged[err];
		}



	}

	void ClearInput_CoreFullStruct(ErrorMgr_CoreList Core)
	{
		switch (Core)
		{
		case ErrorMgr_Core_1_0:
			memset(&Err_1_0, 0, sizeof(Err_1_0));
			break;
		case ErrorMgr_Core_2_0:
			memset(&Err_2_0, 0, sizeof(Err_2_0));
			break;
		case ErrorMgr_Core_2_1:
			memset(&Err_2_1, 0, sizeof(Err_2_1));
			break;
		case ErrorMgr_Core_3_0:
			memset(&Err_3_0, 0, sizeof(Err_3_0));
			break;
		case ErrorMgr_Core_3_1:
			memset(&Err_3_1, 0, sizeof(Err_3_1));
			break;
		case ErrorMgr_Core_QNX:
			memset(&Err_QNX, 0, sizeof(Err_QNX));
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



	void ClearError_Single(ErrorMgr_enErrorNo err)
	{
		SetInput(err, 0);
	}


	void SetError_Single(ErrorMgr_enErrorNo err)
	{
		SetInput(err, 1);
	}

	void WriteData_AllCores()
	{
		for (int i = 0; i < ErrorMgr_Core_CORE_MAX; i++)
		{
			WriteData_Core((ErrorMgr_CoreList)i);
		}

	}

	virtual void WriteData_Core(ErrorMgr_CoreList Core)=0;
	virtual void ReadAgg_OutputData()=0;

	

	void TestFunction_GenericSingle_ErrSetClear(ErrorMgr_enErrorNo errNo,uint32 OutputErrMax)
	{
		if (errNo < ErrorMgr_ErrorNum_Max)
		{

			ClearInput_AllCoreFullStruct();
			DemCallLogInfo.clear();

			ReadAgg_OutputData();
			//Expect the output to be cleared
			CheckIfSet(std::vector<uint32_t>(), OutputErrMax);

	
			if (ErrorMgr_TestDefs[errNo].enAsil == m_TestAsilLevel)
			{
				SetError_Single(errNo);
			}

			WriteData_AllCores();
			m_RunPeriodic_AggRunnable(m_TestAsilLevel, 1);

			ReadAgg_OutputData();
			std::vector<uint32_t> enToCheck = { errNo };
			std::vector< uint32_t> OutPos = GetOutputPositions(enToCheck);
			CheckIfSet(OutPos, OutputErrMax);
			CheckIfDemIs(enToCheck, 1);


			//if this error has asil B Error
			if (ErrorMgr_TestDefs[errNo].enAsil == m_TestAsilLevel)
			{
				ClearError_Single(errNo);
			}

			WriteData_AllCores();
			m_RunPeriodic_AggRunnable(m_TestAsilLevel, 1);


			ReadAgg_OutputData();
			//Expect the output to be cleared
			CheckIfSet(std::vector<uint32_t>(), OutputErrMax);
			CheckIfDemIs(enToCheck, 0);

		}

	}


};



class Fixture_ErrorMgr_AGG_B : public Fixture_Base_ErrorMgr_Aggregator<ErrorListArr_B,ErrorMgr_ErrorCommPack_1_0_B, ErrorMgr_ErrorCommPack_2_0_B, ErrorMgr_ErrorCommPack_2_1_B, ErrorMgr_ErrorCommPack_3_0_B, ErrorMgr_ErrorCommPack_3_1_B, ErrorMgr_ErrorCommPack_QNX_B>, public ::testing::TestWithParam<uint32_t>
{
public:

	Fixture_ErrorMgr_AGG_B()
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

	void ReadAgg_OutputData()
	{
		Rte_Read_DegManager_B_R_Errors_B_Errors_B((BOOL *)&ErrList_Output);
	}



	void WriteData_Core(ErrorMgr_CoreList Core)
	{
		switch (Core)
		{
		case ErrorMgr_Core_1_0:
			Err_1_0.RunningCounter += 1;
			Rte_Write_ErrorMgrSat_1_0_B_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B(&Err_1_0);
			break;
		case ErrorMgr_Core_2_0:
			Err_2_0.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B(&Err_2_0);
			break;
		case ErrorMgr_Core_2_1:
			Err_2_1.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B(&Err_2_1);
			break;
		case ErrorMgr_Core_3_0:
			Err_3_0.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_3_0_B(&Err_3_0);
			break;
		case ErrorMgr_Core_3_1:
			Err_3_1.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_3_1_B(&Err_3_1);
			break;
		case ErrorMgr_Core_QNX:
			Err_QNX.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B(&Err_QNX);
			break;
		default:
			break;
		}

	}




};

class Fixture_ErrorMgr_AGG_QM : public Fixture_Base_ErrorMgr_Aggregator<ErrorListArr_QM, ErrorMgr_ErrorCommPack_1_0_QM, ErrorMgr_ErrorCommPack_2_0_QM, ErrorMgr_ErrorCommPack_2_1_QM, ErrorMgr_ErrorCommPack_3_0_QM, ErrorMgr_ErrorCommPack_3_1_QM, ErrorMgr_ErrorCommPack_QNX_QM>, public ::testing::TestWithParam<uint32_t>
{
public:

	Fixture_ErrorMgr_AGG_QM()
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

	void ReadAgg_OutputData()
	{
		Rte_Read_DegManager_B_R_Errors_QM_Errors_QM((BOOL*)&ErrList_Output);
	}



	void WriteData_Core(ErrorMgr_CoreList Core)
	{
		switch (Core)
		{
		case ErrorMgr_Core_1_0:
			Err_1_0.RunningCounter += 1;
			Rte_Write_ErrorMgrSat_1_0_QM_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM(&Err_1_0);
			break;
		case ErrorMgr_Core_2_0:
			Err_2_0.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM(&Err_2_0);
			break;
		case ErrorMgr_Core_2_1:
			Err_2_1.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM(&Err_2_1);
			break;
		case ErrorMgr_Core_3_0:
			Err_3_0.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_3_0_QM(&Err_3_0);
			break;
		case ErrorMgr_Core_3_1:
			Err_3_1.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_3_1_QM(&Err_3_1);
			break;
		case ErrorMgr_Core_QNX:
			Err_QNX.RunningCounter += 1;
			Rte_Write_CDD_IPCDataHndlr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM(&Err_QNX);
			break;
		default:
			break;
		}

	}

};




TEST_P(Fixture_ErrorMgr_AGG_B, SetErrorTestCase_SingleFault)
{
	TestFunction_GenericSingle_ErrSetClear((ErrorMgr_enErrorNo)(GetParam()), B_ErrorMgr_ErrorNum_Max);
}

TEST_P(Fixture_ErrorMgr_AGG_QM, SetErrorTestCase_SingleFault)
{
	TestFunction_GenericSingle_ErrSetClear((ErrorMgr_enErrorNo)(GetParam()), QM_ErrorMgr_ErrorNum_Max);
}



INSTANTIATE_TEST_CASE_P(ErrSetting, Fixture_ErrorMgr_AGG_B,
		::testing::ValuesIn(v_Test_AllErrors),
);

INSTANTIATE_TEST_CASE_P(ErrSetting, Fixture_ErrorMgr_AGG_QM,
	::testing::ValuesIn(v_Test_AllErrors),
	);

