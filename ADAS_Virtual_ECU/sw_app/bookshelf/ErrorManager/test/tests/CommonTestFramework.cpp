#include <string>
#include <vector>
#include  <stdint.h>
#include "PlatformDataTypes.h"
#include "ErrorManagerShared.h"
#include "CommonTestFramework.h"

using namespace std;


//std::vector<int> CoresToTest_AllCores = { ErrorMgr_Core_1_0,ErrorMgr_Core_2_0, ErrorMgr_Core_2_1,ErrorMgr_Core_3_0, ErrorMgr_Core_3_1,ErrorMgr_Core_QNX };
//std::vector<int> CoresToTest_AllAsilLevels = { ErrorMgr_Asil_QM,ErrorMgr_Asil_A,ErrorMgr_Asil_B,ErrorMgr_Asil_C,ErrorMgr_Asil_D };

//std::vector<std::vector<uint32>> v_Test_AllErrors_Asil = { v_Test_AllErrors_QM, v_Test_AllErrors_A, v_Test_AllErrors_B, v_Test_AllErrors_C, v_Test_AllErrors_D };


std::vector<DemCallBackLogData> DemCallLogInfo;

extern "C"
{
	Std_ReturnType TEST_FRAMEWORK_DIAGMGR_CALLBACK(const char* DtcHigh, uint16_t DtcLow, uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, uint8* i_AdditionalData_pu8)
	{
		DemCallBackLogData mData;
		DemCallBackLogData pData;

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

