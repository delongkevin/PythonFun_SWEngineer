#ifndef ERRORMANAGERTYPES_RTE_H_INCLUDEGUARD
#define ERRORMANAGERTYPES_RTE_H_INCLUDEGUARD

#include <assert.h>

#include "ErrorManagerDef.h"
#include "ipc_lookup_table.h"


/* ErrorManager Aggregators RTE Interfaces*/

#ifdef RTE_ERRORMGRAGG_RTE_STUB_IFDEFS

	#if ERRMANAGER_QM_LEVEL_ACTIVE == 1

	extern Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_stub(ldef_ErrorMgr_ErrorCommPack_1_0_QM *data);
	extern Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_QM_stub(ldef_ErrorMgr_ErrorCommPack_2_0_QM *data);
	extern Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_QM_stub(ldef_ErrorMgr_ErrorCommPack_2_1_QM *data);
/*	extern Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_0_QM_stub(ldef_ErrorMgr_ErrorCommPack_3_0_QM *data);
	extern Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_1_QM_stub(ldef_ErrorMgr_ErrorCommPack_3_1_QM *data);*/
	extern Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_QM_stub(ldef_ErrorMgr_ErrorCommPack_QNX_QM *data);

	extern Std_ReturnType Rte_Write_P_Errors_QM_Errors_QM_stub(uint32_t *data,uint32_t ErrorSize,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef);
	extern Std_ReturnType Rte_Write_P_SafeState_SafeStateOp_QM_stub(bool_t  *data,uint32_t SafeStateMax,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef);


	extern Std_ReturnType Rte_Call_DtcData_stub_QM(void* status, void* addData);
	#endif

	#if ERRMANAGER_B_LEVEL_ACTIVE == 1

		extern Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B_stub(ldef_ErrorMgr_ErrorCommPack_1_0_B *data);
		extern Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_B_stub(ldef_ErrorMgr_ErrorCommPack_2_0_B *data);
		extern Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_B_stub(ldef_ErrorMgr_ErrorCommPack_2_1_B *data);
/*		extern Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_0_B_stub(ldef_ErrorMgr_ErrorCommPack_3_0_B *data);
		extern Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_1_B_stub(ldef_ErrorMgr_ErrorCommPack_3_1_B *data);*/
		extern Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_B_stub(ldef_ErrorMgr_ErrorCommPack_QNX_B *data);
		#if ERRORMGR_CURRENTCORE == ERRORMGRCORE_MCU1_0
        extern void ErrorMgrAggregatorApp_Write_SafeState2Reason(uint16 FaultEnum_u16);
		#endif
		extern Std_ReturnType Rte_Write_P_Errors_B_Errors_B_stub(uint32_t *data,uint32_t ErrorSize,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef);
		extern Std_ReturnType Rte_Write_P_SafeState_SafeStateOp_B_stub(bool_t *data,uint32_t SafeStateMax,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef);

		extern Std_ReturnType Rte_Call_DtcData_stub_B(void* status, void* addData);
	#endif




		/*extern Std_ReturnType Rte_Write_P_Errors_A_Errors_A_stub(bool_t *data,uint32_t ErrorSize,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef);
		
		extern Std_ReturnType Rte_Write_P_Errors_C_Errors_C_stub(bool_t *data,uint32_t ErrorSize,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef);
		extern Std_ReturnType Rte_Write_P_Errors_D_Errors_D_stub(bool_t *data,uint32_t ErrorSize,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef);


		extern Std_ReturnType Rte_Write_P_SafeState_SafeStateOp_A_stub(bool_t *data,uint32_t SafeStateMax,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef);
		
		extern Std_ReturnType Rte_Write_P_SafeState_SafeStateOp_C_stub(bool_t *data,uint32_t SafeStateMax,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef);
		extern Std_ReturnType Rte_Write_P_SafeState_SafeStateOp_D_stub(bool_t *data,uint32_t SafeStateMax,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef);*/



#endif



#ifdef RTE_ERRORMGRAGG_1_0_QM_H


		Std_ReturnType Rte_Call_DtcData_stub_QM(void* status, void* addData)
		{
			Std_ReturnType Ret1,  Ret2;
			Std_ReturnType Ret = E_NOT_OK;

			Ret1=Rte_Write_ErrorMgrAgg_1_0_QM_P_DtcData_Data_DtcAddData_QM((DtcAddData_QM*)addData);
			Ret2=Rte_Write_ErrorMgrAgg_1_0_QM_P_DtcData_Data_DtcStatus_QM((DtcStatus_QM*)status);

			if ((Ret1 == E_OK) && (Ret2 == E_OK))
			{
				Ret = E_OK;
			}

			return Ret;
		}

	Std_ReturnType Rte_Write_P_SafeState_SafeStateOp_QM_stub(bool_t *data,uint32_t ErrorSize,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef)
	{
		Std_ReturnType Ret=E_NOT_OK;
		if(ErrorSize <= sizeof(SafeStateOpDef))
		{
			Ret=Rte_Write_P_SafeState_SafeStateOp((SafeStateOpDef *)data);
		}
		else
		{
			ErrDef->Err_Output_SafeState_RteSize_Mismatch += (uint32_t)1;/* PRQA 3383 *//* No functional impact in runtime. Done to check incorrect argument passed. */
		}
		return Ret;
	}

	Std_ReturnType Rte_Write_P_Errors_QM_Errors_QM_stub(uint32_t *data,uint32_t ErrorSize,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef)
	{
		Std_ReturnType Ret=E_NOT_OK;
		if(ErrorSize <= sizeof(ErrorListArr_QM))
		{
			Ret=Rte_Write_P_Errors_QM_Errors_QM((const uint32*)data);
		}
		else
		{
			ErrDef->Err_Output_ErrorStatus_RteSize_Mismatch += (uint32_t)1;/* PRQA 3383 *//* No functional impact in runtime. Done to check incorrect argument passed. */
		}
		return Ret;
	}


	Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_stub(ldef_ErrorMgr_ErrorCommPack_1_0_QM *data)
	{	
		Std_ReturnType Ret=E_NOT_OK;
		/*After the static size check is added the dynamic check is not needed . But just let it be nevertheless*/
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_1_0_QM) == sizeof(ErrorMgr_ErrorCommPack_1_0_QM), "ErrorMgr ErrorMgr_ErrorCommPack_1_0_QM SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_1_0_QM) == sizeof(ErrorMgr_ErrorCommPack_1_0_QM))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM((ErrorMgr_ErrorCommPack_1_0_QM *)data);
		}
		return Ret;
	}
	Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_QM_stub(ldef_ErrorMgr_ErrorCommPack_2_0_QM *data)
	{
		Std_ReturnType Ret=E_NOT_OK;
		/*After the static size check is added the dynamic check is not needed . But just let it be nevertheless*/
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_2_0_QM) == sizeof(ErrorMgr_ErrorCommPack_2_0_QM), "ErrorMgr ErrorMgr_ErrorCommPack_2_0_QM SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_2_0_QM) == sizeof(ErrorMgr_ErrorCommPack_2_0_QM))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_QM((ErrorMgr_ErrorCommPack_2_0_QM *)data);
		}
		return Ret;

	}
	Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_QM_stub(ldef_ErrorMgr_ErrorCommPack_2_1_QM *data)
	{
		Std_ReturnType Ret=E_NOT_OK;
		/*After the static size check is added the dynamic check is not needed . But just let it be nevertheless*/
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_2_1_QM) == sizeof(ErrorMgr_ErrorCommPack_2_1_QM), "ErrorMgr ErrorMgr_ErrorCommPack_2_1_QM SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_2_1_QM) == sizeof(ErrorMgr_ErrorCommPack_2_1_QM))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_QM((ErrorMgr_ErrorCommPack_2_1_QM *)data);
		}
		return Ret;

	}
	/*Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_0_QM_stub(ldef_ErrorMgr_ErrorCommPack_3_0_QM *data)
	{
		Std_ReturnType Ret=E_NOT_OK;
		*After the static size check is added the dynamic check is not needed . But just let it be nevertheless*
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_3_0_QM) == sizeof(ErrorMgr_ErrorCommPack_3_0_QM), "ErrorMgr ErrorMgr_ErrorCommPack_3_0_QM SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_3_0_QM) == sizeof(ErrorMgr_ErrorCommPack_3_0_QM))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_0_QM((ErrorMgr_ErrorCommPack_3_0_QM *)data);
		}
		return Ret;

	}
	Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_1_QM_stub(ldef_ErrorMgr_ErrorCommPack_3_1_QM *data)
	{
		Std_ReturnType Ret=E_NOT_OK;
		*After the static size check is added the dynamic check is not needed . But just let it be nevertheless*
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_3_1_QM) == sizeof(ErrorMgr_ErrorCommPack_3_1_QM), "ErrorMgr ErrorMgr_ErrorCommPack_3_1_QM SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_3_1_QM) == sizeof(ErrorMgr_ErrorCommPack_3_1_QM))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_1_QM((ErrorMgr_ErrorCommPack_3_1_QM *)data);
		}
		return Ret;

	}*/
	Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_QM_stub(ldef_ErrorMgr_ErrorCommPack_QNX_QM *data)
	{
		Std_ReturnType Ret=E_NOT_OK;
		/*After the static size check is added the dynamic check is not needed . But just let it be nevertheless*/
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_QNX_QM) == sizeof(ErrorMgr_ErrorCommPack_QNX_QM), "ErrorMgr ErrorMgr_ErrorCommPack_QNX_QM SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_QNX_QM) == sizeof(ErrorMgr_ErrorCommPack_QNX_QM))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_QM((ErrorMgr_ErrorCommPack_QNX_QM *)data);
		}
		return Ret;

	}
#endif


#ifdef RTE_ERRORMGRAGG_1_0_B_H

	Std_ReturnType Rte_Call_DtcData_stub_B(void* status, void* addData) {
		Std_ReturnType Ret1,Ret2;
		Std_ReturnType Ret = E_NOT_OK;
		Ret1=Rte_Write_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcAddData_B((DtcAddData_B*)addData);
		Ret2 = Rte_Write_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcStatus_B((DtcStatus_B*)status);
		if ((Ret1 == E_OK) && (Ret2 == E_OK))
		{
			Ret = E_OK;
		}

		return Ret;
	}


	Std_ReturnType Rte_Write_P_SafeState_SafeStateOp_B_stub(bool_t *data,uint32_t ErrorSize,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef)
	{
		Std_ReturnType Ret=E_NOT_OK;
		if(ErrorSize <= sizeof(SafeStateOpDef))
		{
			Ret=Rte_Write_P_SafeState_SafeStateOp((SafeStateOpDef *)data);
		}
		else
		{
			ErrDef->Err_Output_SafeState_RteSize_Mismatch += (uint32_t)1;/* PRQA 3383 *//* No functional impact in runtime. Done to check incorrect argument passed. */
		}
		return Ret;
	}

	Std_ReturnType Rte_Write_P_Errors_B_Errors_B_stub(uint32_t *data,uint32_t ErrorSize,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef)
	{
		Std_ReturnType Ret=E_NOT_OK;
		if(ErrorSize <= sizeof(ErrorListArr_B))
		{
			Ret=Rte_Write_P_Errors_B_Errors_B((const uint32*)data);
		}
		else
		{
			ErrDef->Err_Output_ErrorStatus_RteSize_Mismatch += (uint32_t)1;/* PRQA 3383 *//* No functional impact in runtime. Done to check incorrect argument passed. */
		}
		return Ret;
	}


	Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B_stub(ldef_ErrorMgr_ErrorCommPack_1_0_B *data)
	{
		Std_ReturnType Ret=E_NOT_OK;
		/*After the static size check is added the dynamic check is not needed . But just let it be nevertheless*/
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_1_0_B) == sizeof(ErrorMgr_ErrorCommPack_1_0_B), "ErrorMgr ErrorMgr_ErrorCommPack_1_0_B SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_1_0_B) == sizeof(ErrorMgr_ErrorCommPack_1_0_B))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B((ErrorMgr_ErrorCommPack_1_0_B *)data);
		}
		return Ret;
	}
	Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_B_stub(ldef_ErrorMgr_ErrorCommPack_2_0_B *data)
	{
		Std_ReturnType Ret=E_NOT_OK;
		/*After the static size check is added the dynamic check is not needed . But just let it be nevertheless*/
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_2_0_B) == sizeof(ErrorMgr_ErrorCommPack_2_0_B), "ErrorMgr ErrorMgr_ErrorCommPack_2_0_B SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_2_0_B) == sizeof(ErrorMgr_ErrorCommPack_2_0_B))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_B((ErrorMgr_ErrorCommPack_2_0_B *)data);
		}
		return Ret;
	}
	Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_B_stub(ldef_ErrorMgr_ErrorCommPack_2_1_B *data)
	{
		Std_ReturnType Ret=E_NOT_OK;
		/*After the static size check is added the dynamic check is not needed . But just let it be nevertheless*/
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_2_1_B) == sizeof(ldef_ErrorMgr_ErrorCommPack_2_1_B), "ErrorMgr ErrorMgr_ErrorCommPack_2_1_B SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_2_1_B) == sizeof(ErrorMgr_ErrorCommPack_2_1_B))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_B((ErrorMgr_ErrorCommPack_2_1_B *)data);
		}
		return Ret;
	}
	/*Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_0_B_stub(ldef_ErrorMgr_ErrorCommPack_3_0_B *data)
	{
		Std_ReturnType Ret=E_NOT_OK;
		*After the static size check is added the dynamic check is not needed . But just let it be nevertheless*
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_3_0_B) == sizeof(ErrorMgr_ErrorCommPack_3_0_B), "ErrorMgr ErrorMgr_ErrorCommPack_3_0_B SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_3_0_B) == sizeof(ErrorMgr_ErrorCommPack_3_0_B))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_0_B((ErrorMgr_ErrorCommPack_3_0_B*)data);
		}
		return Ret;
	}

	Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_1_B_stub(ldef_ErrorMgr_ErrorCommPack_3_1_B *data)
	{
		Std_ReturnType Ret=E_NOT_OK;
		*After the static size check is added the dynamic check is not needed . But just let it be neverthless*
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_3_1_B) == sizeof(ErrorMgr_ErrorCommPack_3_1_B), "ErrorMgr ErrorMgr_ErrorCommPack_3_1_B SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_3_1_B) == sizeof(ErrorMgr_ErrorCommPack_3_1_B))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_3_1_B((ErrorMgr_ErrorCommPack_3_1_B *)data);
		}
		return Ret;
	}*/
	Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_B_stub(ldef_ErrorMgr_ErrorCommPack_QNX_B *data)
	{
		Std_ReturnType Ret=E_NOT_OK;
		/*After the static size check is added the dynamic check is not needed . But just let it be nevertheless*/
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_QNX_B) == sizeof(ErrorMgr_ErrorCommPack_QNX_B), "ErrorMgr ErrorMgr_ErrorCommPack_QNX_B SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_QNX_B) == sizeof(ErrorMgr_ErrorCommPack_QNX_B))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_B((ErrorMgr_ErrorCommPack_QNX_B *)data);
		}
		return Ret;
	}
#if ERRORMGR_CURRENTCORE == ERRORMGRCORE_MCU1_0
    void ErrorMgrAggregatorApp_Write_SafeState2Reason(uint16 FaultEnum_u16)
	{
		(void)Rte_Write_P_SafeState2Reason_FaultEnum_u16(FaultEnum_u16);
	}
#endif
#endif


/*
#ifdef RTE_ERRORMGRAGG_1_0_D_H

	Std_ReturnType Rte_Write_P_SafeState_SafeStateOp_D_stub(bool_t *data,uint32_t ErrorSize,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef)
	{
		Std_ReturnType Ret=E_NOT_OK;
		if(ErrorSize <= sizeof(SafeStateOpDef))
		{
			Ret=Rte_Write_P_SafeState_SafeStateOp(data);
		}
		else
		{
			ErrDef->Err_Output_SafeState_RteSize_Mismatch+=1;
		}
		return Ret;
	}

	Std_ReturnType Rte_Write_P_Errors_D_Errors_D_stub(bool_t *data,uint32_t ErrorSize,ErrorMgrAggregator_InternalRuntimeErrorDefs *ErrDef)
	{
		Std_ReturnType Ret=E_NOT_OK;
		if(ErrorSize <= sizeof(ErrorListArr_D))
		{
			Ret=Rte_Write_P_Errors_D_Errors_D(data);
		}
		else
		{
			ErrDef->Err_Output_ErrorStatus_RteSize_Mismatch+=1;
		}
		return Ret;
	}

	Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_D_stub(ldef_ErrorMgr_ErrorCommPack_1_0_D *data)
	{
		Std_ReturnType Ret=E_NOT_OK;
		*After the static size check is added the dynamic check is not needed . But just let it be nevertheless*
		#ifndef ERRORMGR_AGGREGARTOR_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
		static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_1_0_D) == sizeof(ErrorMgr_ErrorCommPack_1_0_D), "ErrorMgr ErrorMgr_ErrorCommPack_1_0_D SizeMismatch");
		#endif
		if(sizeof(ldef_ErrorMgr_ErrorCommPack_1_0_D) == sizeof(ErrorMgr_ErrorCommPack_1_0_D))
		{
			Ret=Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_D((ErrorMgr_ErrorCommPack_1_0_D *)data);
		}
		return Ret;
	}
#endif */





/* Error Manager Satellite RTE interfaces */


#ifdef RTE_ERRORMGRSAT_RTE_STUB_IFDEFS

	Std_ReturnType Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B_stub(const void *data);
	Std_ReturnType Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_stub(const void *data);

	Std_ReturnType Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_3_1_B_stub(const void *data);
	Std_ReturnType Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_3_1_QM_stub(const void *data);
#endif



#ifdef RTE_ERRORMGRSAT_1_0_B_H
Std_ReturnType Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B_stub(const void *data)
{
	#ifndef ERRORMGR_SATELLITE_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
	static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_1_0_B) == sizeof(ErrorMgr_ErrorCommPack_1_0_B), "ErrorMgr ldef_ErrorMgr_ErrorCommPack_1_0_B SizeMismatch");
	#endif
	return Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B((ErrorMgr_ErrorCommPack_1_0_B *)data);
}
#endif

#ifdef RTE_ERRORMGRSAT_1_0_QM_H
Std_ReturnType Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_stub(const void *data)
{
	#ifndef ERRORMGR_SATELLITE_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
	static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_1_0_QM) == sizeof(ErrorMgr_ErrorCommPack_1_0_QM), "ErrorMgr ldef_ErrorMgr_ErrorCommPack_1_0_QM SizeMismatch");
	#endif
	return Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM((ErrorMgr_ErrorCommPack_1_0_QM *)data);
}
#endif


#ifdef RTE_ERRORMGRSAT_1_0_D_H
/*Std_ReturnType Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_D_stub(const void *data)
{
	#ifndef ERRORMGR_SATELLITE_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
	static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_1_0_D) == sizeof(ErrorMgr_ErrorCommPack_1_0_D), "ErrorMgr ldef_ErrorMgr_ErrorCommPack_1_0_D SizeMismatch");
	#endif
	return Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_D((ErrorMgr_ErrorCommPack_1_0_D *)data);
}
*/
#endif

#ifdef RTE_ERRORMGRSAT_3_1_B_H



Std_ReturnType Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_3_1_B_stub(const void *data)
{

	//There is some wierd packing issue here. 173 being an odd number. Need to look into this
	#ifndef ERRORMGR_SATELLITE_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
	static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_3_1_B) == sizeof(ErrorMgr_ErrorCommPack_3_1_B), "ErrorMgr ldef_ErrorMgr_ErrorCommPack_3_1_B SizeMismatch");
	#endif
	#if ERRORMGR_AGG_SLAVECORES_IPC_COMMTYPE == ERRORMGR_TYPE_UNDERLYINGCOMLAYER_SIGNALMGR
		return SigMgr_P_SatError_B_Data_ErrorMgr_ErrorCommPack_3_1_B_Put((const ErrorMgr_ErrorCommPack_3_1_B *)data);
	#else
		return Rte_Call_R_IPC_IPC_Write_v((void *)data, e_IpcMsgId_P_SatError_B_Data_ErrorMgr_ErrorCommPack_3_1_B, sizeof(ErrorMgr_ErrorCommPack_3_1_B));
	#endif

}
#endif

#ifdef RTE_ERRORMGRSAT_3_1_QM_H



Std_ReturnType Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_3_1_QM_stub(const void *data)
{
	#ifndef ERRORMGR_SATELLITE_DISABLE_STATICARRAYCHECKS_BETWEENRTEANDLOCALDATATYPES
	static_assert(sizeof(ldef_ErrorMgr_ErrorCommPack_3_1_QM) == sizeof(ErrorMgr_ErrorCommPack_3_1_QM), "ErrorMgr ldef_ErrorMgr_ErrorCommPack_3_1_QM SizeMismatch");
	#endif
	#if ERRORMGR_AGG_SLAVECORES_IPC_COMMTYPE == ERRORMGR_TYPE_UNDERLYINGCOMLAYER_SIGNALMGR
		return SigMgr_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_3_1_QM_Put((const ErrorMgr_ErrorCommPack_3_1_QM *)data);
	#else
		return Rte_Call_R_IPC_IPC_Write_v((void *)data, e_IpcMsgId_P_SatError_QM_Data_ErrorMgr_ErrorCommPack_3_1_QM, sizeof(ldef_ErrorMgr_ErrorCommPack_3_1_QM));
	#endif
}
#endif






#endif
