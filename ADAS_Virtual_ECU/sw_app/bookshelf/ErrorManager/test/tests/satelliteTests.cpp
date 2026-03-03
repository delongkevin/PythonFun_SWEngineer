#include "gtest/gtest.h"






#if defined(BUILD_MCU2_0)|| defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0) || defined (BUILD_MPU1_0)
#include "ErrorManagerDef.h"
#include "ErrorManagerSatellite.h"
#include "SignalDef.h"
#include "SignalMgr.h"
#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)


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

#include "DegManagerGenEnTypes.h"


#define TESTCASES_ADDITIONALCHECKS
#undef TESTCASES_ADDITIONALCHECKS

#include "TestSupportDefs.h"
#include "ErrorManagerTestDef.h"

std::vector<int> CoresToTest_AllCores= { ErrorMgr_Core_1_0,ErrorMgr_Core_2_0, ErrorMgr_Core_2_1,ErrorMgr_Core_3_0, ErrorMgr_Core_3_1,ErrorMgr_Core_QNX };
std::vector<int> CoresToTest_AllAsilLevels = { ErrorMgr_Asil_QM,ErrorMgr_Asil_A,ErrorMgr_Asil_B,ErrorMgr_Asil_C,ErrorMgr_Asil_D};


#ifdef BUILD_MCU1_0
	ErrorMgr_CoreList T_enCoreToTest = ErrorMgr_Core_1_0;
	typedef ErrorMgr_ErrorCommPack_1_0_QM ErrorMgr_QM_SatOutputType;
	typedef ErrorMgr_ErrorCommPack_1_0_B ErrorMgr_B_SatOutputType;
	typedef ErrorMgr_ErrorCommPack_1_0_A ErrorMgr_A_SatOutputType;
	uint32 u32CoreMaxQM = ErrorMgr_CoreAsilSpecific_1_0_QM_MAX;
	uint32 u32CoreMaxB = ErrorMgr_CoreAsilSpecific_1_0_B_MAX;
	uint32 u32CoreMaxD = ErrorMgr_CoreAsilSpecific_1_0_D_MAX;
#elif defined(BUILD_MCU2_0)
	ErrorMgr_CoreList T_enCoreToTest = ErrorMgr_Core_2_0;
	typedef ErrorMgr_ErrorCommPack_2_0_QM ErrorMgr_QM_SatOutputType;
	typedef ErrorMgr_ErrorCommPack_2_0_B ErrorMgr_B_SatOutputType;

	uint32 u32CoreMaxQM = ErrorMgr_CoreAsilSpecific_2_0_QM_MAX;
	uint32 u32CoreMaxB = ErrorMgr_CoreAsilSpecific_2_0_B_MAX;
#elif defined(BUILD_MCU2_1)
	ErrorMgr_CoreList T_enCoreToTest = ErrorMgr_Core_2_1;
	typedef ErrorMgr_ErrorCommPack_2_1_QM ErrorMgr_QM_SatOutputType;
	typedef ErrorMgr_ErrorCommPack_2_1_B ErrorMgr_B_SatOutputType;
	typedef ErrorMgr_ErrorCommPack_2_1_D ErrorMgr_D_SatOutputType;
	uint32 u32CoreMaxQM = ErrorMgr_CoreAsilSpecific_2_1_QM_MAX;
	uint32 u32CoreMaxB = ErrorMgr_CoreAsilSpecific_2_1_B_MAX;
#elif defined(BUILD_MCU3_0)
	ErrorMgr_CoreList T_enCoreToTest = ErrorMgr_Core_3_0;
	typedef ErrorMgr_ErrorCommPack_3_0_QM ErrorMgr_QM_SatOutputType;
	typedef ErrorMgr_ErrorCommPack_3_0_B ErrorMgr_B_SatOutputType;

	uint32 u32CoreMaxQM = ErrorMgr_CoreAsilSpecific_3_0_QM_MAX;
	uint32 u32CoreMaxB = ErrorMgr_CoreAsilSpecific_3_0_B_MAX;
#elif defined(BUILD_MCU3_1)
	ErrorMgr_CoreList T_enCoreToTest = ErrorMgr_Core_3_1;
	typedef ErrorMgr_ErrorCommPack_3_1_QM ErrorMgr_QM_SatOutputType;
	typedef ErrorMgr_ErrorCommPack_3_1_B ErrorMgr_B_SatOutputType;

	uint32 u32CoreMaxQM = ErrorMgr_CoreAsilSpecific_3_1_QM_MAX;
	uint32 u32CoreMaxB = ErrorMgr_CoreAsilSpecific_3_1_B_MAX;
#elif defined(BUILD_MPU1_0)
	ErrorMgr_CoreList T_enCoreToTest = ErrorMgr_Core_QNX;
	typedef ErrorMgr_ErrorCommPack_QNX_QM ErrorMgr_QM_SatOutputType;
	typedef ErrorMgr_ErrorCommPack_QNX_B ErrorMgr_B_SatOutputType;

	uint32 u32CoreMaxQM = ErrorMgr_CoreAsilSpecific_QNX_QM_MAX;
	uint32 u32CoreMaxB = ErrorMgr_CoreAsilSpecific_QNX_B_MAX;
#endif






class Fixture_Base_ErrorMgr_SatErrMgr
{
public:
	// Test the output after initialization
	ErrorMgr_QM_SatOutputType QM_Data;
	ErrorMgr_B_SatOutputType B_Data;
	ErrorMgr_A_SatOutputType A_Data;

	uint32_t m_RefRunningCounter[ErrorMgr_Asil_MAX];


	std::vector<ldef_ErrorMgr_stAddData> m_CurrentTestAdditionalDataLogged;
	std::vector<ErrorMgr_enErrorNo> AllErrorEnumsToCheck;


	Fixture_Base_ErrorMgr_SatErrMgr()
	{
		
		for (int i = 0; i < ldef_ErrorMgr_ErrorNum_Max; i++)
		{
			ldef_ErrorMgr_stAddData AddData;
			m_FillAdditionalDataStructure_RandValues(AddData);
			m_CurrentTestAdditionalDataLogged.push_back(AddData);

			AllErrorEnumsToCheck.push_back((ErrorMgr_enErrorNo)i);

		}
	}


	void m_RunPeriodic_SatRunnable(ErrorMgr_AsilList asil, int Count)
	{
		for (int i = 0; i < Count; i++)
		{
			switch (asil)
			{
			case ErrorMgr_Asil_QM:
				ErrorMgrSatellite_PeriodicFunction_QM();
				break;

			case ErrorMgr_Asil_B:
				ErrorMgrSatellite_PeriodicFunction_B();
				break;

			case ErrorMgr_Asil_A:
				//ErrorMgrSatellite_PeriodicFunction_A();
				break;

			case ErrorMgr_Asil_D:
				ErrorMgrSatellite_PeriodicFunction_D();
				break;

			default:
				break;
			}
		}
	}

	void m_RunAllPeriodic_SatRunnables(int Count)
	{
		for (int i = 0; i < Count; i++)
		{
			for (auto asil : CoresToTest_AllAsilLevels)
			{
				m_RunPeriodic_SatRunnable((ErrorMgr_AsilList)asil,1);
			}
		}
	}

	template<class T_ErrMgrDataType_Current>
	void GetSatOutput(T_ErrMgrDataType_Current* DataPtr, ErrorMgr_CoreList Core, ErrorMgr_AsilList asil)
	{


#ifdef BUILD_MCU1_0
		
			switch (asil)
			{
			case ErrorMgr_Asil_QM:
				Rte_Read_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM((ErrorMgr_QM_SatOutputType*)DataPtr);
				break;
			case ErrorMgr_Asil_B:
				Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B((ErrorMgr_B_SatOutputType*)DataPtr);
				break;
			case ErrorMgr_Asil_A:
				//Rte_Read_ErrorMgrAgg_1_0_A_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_A((ErrorMgr_A_SatOutputType*)DataPtr);
				break;
			//case ErrorMgr_Asil_D:
			//	Rte_Read_ErrorMgrAgg_1_0_D_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_D((ErrorMgr_D_SatOutputType*)DataPtr);
			//	break;
			default:
				break;

			}

#elif defined(BUILD_MCU2_0)
		switch (asil)
		{
		case ErrorMgr_Asil_QM:
			SigMgr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM_Get(DataPtr);
			break;
		case ErrorMgr_Asil_B:
			SigMgr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B_Get(DataPtr);
			break;

		default:
			break;

		}
#elif defined(BUILD_MCU2_1)
		switch (asil)
		{
		case ErrorMgr_Asil_QM:
			SigMgr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM_Get(DataPtr);
			break;
		case ErrorMgr_Asil_B:
			SigMgr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B_Get(DataPtr);
			break;

		default:
			break;

		}
#elif defined(BUILD_MCU3_0)
		switch (asil)
		{
		case ErrorMgr_Asil_QM:
			SigMgr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_3_0_QM_Get((ErrorMgr_QM_SatOutputType*)DataPtr);
			break;
		case ErrorMgr_Asil_B:
			SigMgr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_3_0_B_Get((ErrorMgr_B_SatOutputType*)DataPtr);
			break;

		default:
			break;

		}

#elif defined(BUILD_MCU3_1)
		ErrorMgr_CoreList T_enCoreToTest = ErrorMgr_Core_3_1;
#elif defined(BUILD_MPU1_0)
		ErrorMgr_CoreList T_enCoreToTest = ErrorMgr_Core_QNX;
#endif
	}

	void m_CheckAndUpdateRunningCount(uint32_t* RefValue,uint32_t CurrentValue,bool IgnoreCheck=FALSE)
	{
		if (IgnoreCheck == FALSE)
		{
			EXPECT_EQ(*RefValue, CurrentValue);
		}
		*RefValue = *RefValue + 1;
	}


	template<class StructType>
	void m_Check_ifOutputStructure_Zero(StructType *Data,uint32_t FieldMaxValue,std::string DatasringType)
	{
		//EXPECT_EQ(Data->RunningCounter, 0);
		for (unsigned int i = 0; i < FieldMaxValue; i++)
		{
			EXPECT_EQ(Data->Error[i], 0);
			for (int j = 0; j < ERRORMGR_ADDITIONALDATASIZE_COUNT; j++)
			{
				EXPECT_EQ(Data->Data[i].AdditionalData[j], 0) << DatasringType<< "::" << i<<"::"<<j;
			}
		}
	}


	
	void m_CheckFaultValue(std::vector< ErrorMgr_enErrorNo> ToCheckErrorEnumVals, std::vector< ldef_ErrorMgr_ErrorField>ExpectedValues, ErrorMgr_CoreList testCore)
	{
		GetSatOutput< ErrorMgr_QM_SatOutputType>(&QM_Data, T_enCoreToTest, ErrorMgr_Asil_QM);
		GetSatOutput< ErrorMgr_B_SatOutputType>(&B_Data, T_enCoreToTest, ErrorMgr_Asil_B);
		GetSatOutput< ErrorMgr_A_SatOutputType>(&A_Data, T_enCoreToTest, ErrorMgr_Asil_A);



		for (unsigned int i = 0; i < ToCheckErrorEnumVals.size(); i++)
		{
			// Only if this error is handled by this current core
			if (ErrorMgr_TestDefs[i].enCore == testCore)
			{
				ErrorMgr_enErrorNo CurrentError = ToCheckErrorEnumVals[i];
				ErrorMgr_stTestErrorSpecs CurrentErrorSpec = ErrorMgr_TestDefs[CurrentError];
				uint32_t index = CurrentErrorSpec.enCoreAsilSpecificEnumVal;

				#if defined(BUILD_MCU2_0)|| defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0) || defined (BUILD_MPU1_0)
					ldef_ErrorMgr_stAddData addData;
					ldef_ErrorMgr_ErrorField ErrorValue = 255;
				#elif defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
					static_assert(sizeof(ldef_ErrorMgr_stAddData) == sizeof(ErrorMgr_stAddData), "stDataSize MisMatch");
					static_assert(sizeof(ldef_ErrorMgr_ErrorField) == sizeof(ErrorMgr_ErrorField), "stDataSize MisMatch");
					ErrorMgr_stAddData addData;
					ErrorMgr_ErrorField ErrorValue = 255;
				#endif
				
				bool bCheckValid = FALSE;

				switch (CurrentErrorSpec.enAsil)
				{
				case ErrorMgr_Asil_QM:
					addData = QM_Data.Data[index];
					ErrorValue = QM_Data.Error[index];
					bCheckValid = TRUE;
					break;
				case ErrorMgr_Asil_B:
					addData = B_Data.Data[index];
					ErrorValue = B_Data.Error[index];
					bCheckValid = TRUE;
					break;
				case ErrorMgr_Asil_A:
					addData = A_Data.Data[index];
					ErrorValue = A_Data.Error[index];
					std::cout << "Warning::Invalid Error in the invalid ASIL A Category" << std::endl;
					bCheckValid = FALSE;
					break;
				default:
					bCheckValid = FALSE;
					break;
				}

				if (bCheckValid == TRUE)
				{
					EXPECT_EQ(ErrorValue, ExpectedValues[i]) << "Ev.F Index ::->" << i << "::" << index;
					if (ExpectedValues[i] == 1)
					{
						for (int y = 0; y < ERRORMGR_ADDITIONALDATASIZE_COUNT; y++)
						{
							EXPECT_EQ(addData.AdditionalData[y], m_CurrentTestAdditionalDataLogged[CurrentError].AdditionalData[y]) << "AddData.F:Index" << y;
						}
					}
					else
					{
						#ifdef TESTCASES_ADDITIONALCHECKS
						for (int j = 0; j < ERRORMGR_ADDITIONALDATASIZE_COUNT; j++)
						{
							EXPECT_EQ(Data->Data[i].AdditionalData[j], 0);
						}
						#endif

					}
				}
			}

		}

	}

	void m_FillAdditionalDataStructure_RandValues(ldef_ErrorMgr_stAddData& data)
	{
		for (int i = 0; i < ERRORMGR_ADDITIONALDATASIZE_COUNT; i++)
		{
			data.AdditionalData[i] = rand() % 256;
		}
	}


	

	void m_MatureFaultFrom_Inactive_AndTest(std::vector< ErrorMgr_stTestErrorSpecs> ErrorsToMature,bool SpecificAsilLevel, ErrorMgr_AsilList AsilLevel,bool SetFaultEveryCycle, ErrorMgr_CoreList testCore)
	{
		std::vector<uint32_t> MaturingCounts;
		std::vector<uint32_t> CurrentCount;
		uint32_t MaxCount = 0;		

		for (unsigned int i = 0; i < ErrorsToMature.size(); i++)
		{		

			unsigned int Count_mature = ErrorsToMature[i].Timing.MatureTime / (ERRORMGRSATELLITE_PERIODICFUNC_TIME_MS * ERRORMGRSATELLITE_NOTIFICATION_RATE_PER_NTH_CYCLE);
			MaturingCounts.push_back(Count_mature);
			CurrentCount.push_back(0);
			if (Count_mature > MaxCount)
			{
				MaxCount = Count_mature;
			}
		}

		//Set the fault
		for (unsigned int i = 0; i < ErrorsToMature.size(); i++)
		{
			m_FillAdditionalDataStructure_RandValues(m_CurrentTestAdditionalDataLogged[ErrorsToMature[i].enGlobalErrNo]);
			ErrorMgrSatellite_ReportErrorStatus(ErrorsToMature[i].enGlobalErrNo, ldef_ErrorMgr_ErrorActive, &m_CurrentTestAdditionalDataLogged[ErrorsToMature[i].enGlobalErrNo]);
		}

		//start the maturing process
		for (unsigned int cnt = 0; cnt < MaxCount+1; cnt++)
		{

			std::vector< ldef_ErrorMgr_ErrorField> ExpectedErrorValues(ldef_ErrorMgr_ErrorNum_Max,0);


			if (SetFaultEveryCycle == true)
			{
				//Set the fault
				for (unsigned int i = 0; i < ErrorsToMature.size(); i++)
				{
					//generate random data for 
					m_FillAdditionalDataStructure_RandValues(m_CurrentTestAdditionalDataLogged[ErrorsToMature[i].enGlobalErrNo]);
					ErrorMgrSatellite_ReportErrorStatus(ErrorsToMature[i].enGlobalErrNo, ldef_ErrorMgr_ErrorActive, &m_CurrentTestAdditionalDataLogged[ErrorsToMature[i].enGlobalErrNo]);
				}
			}

			if (SpecificAsilLevel == false)
			{
				m_RunAllPeriodic_SatRunnables(1);

				GetSatOutput< ErrorMgr_QM_SatOutputType>(&QM_Data, T_enCoreToTest, ErrorMgr_Asil_QM);
				GetSatOutput< ErrorMgr_B_SatOutputType>(&B_Data, T_enCoreToTest, ErrorMgr_Asil_B);

				m_CheckAndUpdateRunningCount((uint32_t *)&m_RefRunningCounter[ErrorMgr_Asil_QM], (uint32_t)QM_Data.RunningCounter,FALSE);
				m_CheckAndUpdateRunningCount((uint32_t *)&m_RefRunningCounter[ErrorMgr_Asil_B], B_Data.RunningCounter,FALSE);
			}
			else
			{
				m_RunPeriodic_SatRunnable(AsilLevel, 1);
				if (AsilLevel == ErrorMgr_Asil_A)
				{
					GetSatOutput< ErrorMgr_A_SatOutputType>(&A_Data, T_enCoreToTest, ErrorMgr_Asil_A);
					m_CheckAndUpdateRunningCount(&m_RefRunningCounter[ErrorMgr_Asil_A], A_Data.RunningCounter);
				}
				if (AsilLevel == ErrorMgr_Asil_B)
				{
					GetSatOutput< ErrorMgr_B_SatOutputType>(&B_Data, T_enCoreToTest, ErrorMgr_Asil_B);
					m_CheckAndUpdateRunningCount(&m_RefRunningCounter[ErrorMgr_Asil_B], B_Data.RunningCounter);
				}
				if (AsilLevel == ErrorMgr_Asil_QM)
				{
					GetSatOutput< ErrorMgr_QM_SatOutputType>(&QM_Data, T_enCoreToTest, ErrorMgr_Asil_QM);
					m_CheckAndUpdateRunningCount(&m_RefRunningCounter[ErrorMgr_Asil_QM], QM_Data.RunningCounter);
				}
			}

			
			for (unsigned int i = 0; i < ErrorsToMature.size(); i++)
			{
				//generate random data for 
				CurrentCount[i] += 1;
				if (CurrentCount[i] > MaturingCounts[i])
				{
					//if only the error is handled by current core
					if (ErrorsToMature[i].enCore == testCore)
					{
						ExpectedErrorValues[ErrorsToMature[i].enGlobalErrNo] = 1;
					}
				}
			}

			

			//Check whether the errors have matured correctly
			m_CheckFaultValue(AllErrorEnumsToCheck, ExpectedErrorValues,testCore);



		}
	}

};


class Fixture_ErrorMgr_Sat_Init : public Fixture_Base_ErrorMgr_SatErrMgr, public ::testing::TestWithParam<int>
{
public:
	static void SetUpTestCase()
	{

	}

	static void TearDownTestCase()
	{

	}


	void SetUp()
	{
		memset(m_RefRunningCounter, 0, sizeof(m_RefRunningCounter));
		#if defined(BUILD_MCU2_0)|| defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0) || defined (BUILD_MPU1_0)
			SignalMgr_Init();
		#elif defined(BUILD_MCU1_0)|| defined(BUILD_MCU3_1)
			Rte_InitMemory_Stub();
		#endif
		ErrorMgrSatellite_Init_QM();
		ErrorMgrSatellite_Init_A();
		ErrorMgrSatellite_Init_B();
		ErrorMgrSatellite_Init_C();
		ErrorMgrSatellite_Init_D();

	}

	void TearDown()
	{

	}

};

class Fixture_ErrorMgr_Sat_ErrorSetting : public Fixture_Base_ErrorMgr_SatErrMgr, public ::testing::TestWithParam<std::tuple<ErrorMgr_stTestErrorSpecs, int>>
{
public:
	static void SetUpTestCase()
	{
	


	}

	static void TearDownTestCase()
	{

	}

	void SetUp()
	{
		memset(m_RefRunningCounter, 0, sizeof(m_RefRunningCounter));
		#if defined(BUILD_MCU2_0)|| defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0) || defined (BUILD_MPU1_0)
			SignalMgr_Init();
		#elif defined(BUILD_MCU1_0)|| defined(BUILD_MCU3_1)
			Rte_InitMemory_Stub();
		#endif
		ErrorMgrSatellite_Init_QM();
		ErrorMgrSatellite_Init_A();
		ErrorMgrSatellite_Init_B();
		ErrorMgrSatellite_Init_C();
		ErrorMgrSatellite_Init_D();

	}

	void TearDown()
	{

	}

};




TEST_P(Fixture_ErrorMgr_Sat_ErrorSetting, SetErrorTestCase_SingleFault)
{
	ErrorMgr_CoreList TestCore = (ErrorMgr_CoreList)std::get<1>(GetParam());
	ErrorMgr_stTestErrorSpecs V1 = (std::get<0>(GetParam()));

	GetSatOutput< ErrorMgr_QM_SatOutputType>(&QM_Data, T_enCoreToTest, ErrorMgr_Asil_QM);
	GetSatOutput< ErrorMgr_B_SatOutputType>(&B_Data, T_enCoreToTest, ErrorMgr_Asil_B);

	m_CheckAndUpdateRunningCount(&m_RefRunningCounter[ErrorMgr_Asil_QM], QM_Data.RunningCounter,TRUE);
	m_CheckAndUpdateRunningCount(&m_RefRunningCounter[ErrorMgr_Asil_B], B_Data.RunningCounter,TRUE);

	m_Check_ifOutputStructure_Zero<ErrorMgr_QM_SatOutputType>(&QM_Data, u32CoreMaxQM ,"QM_Data");
	m_Check_ifOutputStructure_Zero<ErrorMgr_B_SatOutputType>(&B_Data, u32CoreMaxB,"B_Data");


	//Just run once and ensure that the data is still 0
	m_RunAllPeriodic_SatRunnables(1);

	GetSatOutput< ErrorMgr_QM_SatOutputType>(&QM_Data, T_enCoreToTest, ErrorMgr_Asil_QM);
	GetSatOutput< ErrorMgr_B_SatOutputType>(&B_Data, T_enCoreToTest, ErrorMgr_Asil_B);

	m_CheckAndUpdateRunningCount(&m_RefRunningCounter[ErrorMgr_Asil_QM], QM_Data.RunningCounter);
	m_CheckAndUpdateRunningCount(&m_RefRunningCounter[ErrorMgr_Asil_B], B_Data.RunningCounter);

	m_Check_ifOutputStructure_Zero<ErrorMgr_QM_SatOutputType>(&QM_Data, u32CoreMaxQM,"QM_Data");
	m_Check_ifOutputStructure_Zero<ErrorMgr_B_SatOutputType>(&B_Data, u32CoreMaxB,"B_Data");

	//Fault Maturing
	std::vector< ErrorMgr_stTestErrorSpecs> ErrorsToMature{ V1 };
	m_MatureFaultFrom_Inactive_AndTest(ErrorsToMature, false, ErrorMgr_Asil_MAX, true,TestCore);

	
}

TEST_P(Fixture_ErrorMgr_Sat_Init, InitalizationTest)
{
	ErrorMgr_CoreList TestCore = (ErrorMgr_CoreList)(GetParam());


	GetSatOutput< ErrorMgr_QM_SatOutputType>(&QM_Data, T_enCoreToTest, ErrorMgr_Asil_QM);
	GetSatOutput< ErrorMgr_B_SatOutputType>(&B_Data, T_enCoreToTest, ErrorMgr_Asil_B);


	m_CheckAndUpdateRunningCount(&m_RefRunningCounter[ErrorMgr_Asil_QM], QM_Data.RunningCounter);
	m_CheckAndUpdateRunningCount(&m_RefRunningCounter[ErrorMgr_Asil_B], B_Data.RunningCounter);

	m_Check_ifOutputStructure_Zero<ErrorMgr_QM_SatOutputType>(&QM_Data, u32CoreMaxQM,"QM_Data");
	m_Check_ifOutputStructure_Zero<ErrorMgr_B_SatOutputType>(&B_Data, u32CoreMaxB,"B_Data");


}



std::vector<int> CoresToTest_InitializationTestCase = { T_enCoreToTest };

INSTANTIATE_TEST_CASE_P(InitializationTestCase, Fixture_ErrorMgr_Sat_Init,
		::testing::ValuesIn(CoresToTest_InitializationTestCase)
);


INSTANTIATE_TEST_CASE_P(ErrSetting, Fixture_ErrorMgr_Sat_ErrorSetting,
	::testing::Combine(
		::testing::ValuesIn(ErrorMgr_TestDefs),
		::testing::ValuesIn(CoresToTest_InitializationTestCase)
	)
);

int main(int argc, char **argv) {
      ::testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
}



