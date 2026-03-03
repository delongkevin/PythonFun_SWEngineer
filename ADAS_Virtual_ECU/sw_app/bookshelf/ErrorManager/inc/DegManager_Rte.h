#ifndef DEGMANAGER_RTE_H_INCLUDEGUARD
#define DEGMANAGER_RTE_H_INCLUDEGUARD

#include "PlatformDataTypes.h"
#include "DegManagercfg.h"

/* 3406, 0310 */ /* MD_MSR_Rule8.6, MD_MSR_Rule11.3 */
/*************************************** Justification *********************************************/
/*
 * 3406: No functional impact. Macros used to call functions are defined in RTE Gendata header files and are included accordingly as per QM or B code.
 * 0310: No functional impact. Pointers cast to a larger data type and does not result in loss of value.
 */

#ifdef DEGMANAGER_RTE_STUB_IF


extern Std_ReturnType Rte_Call_R_IPC_IPC_Write_v_stub(dtRef_VOID b_TxData_pv, UINT16 i_IpcMsgId_u16, UINT16 i_IpcMsgSize_u16);

extern Std_ReturnType Rte_Write_P_FID_Output_B_FID_B_stub(const uint32_t *data);
//extern Std_ReturnType Rte_Write_P_FID_Output_D_FID_D_stub(const uint32_t*data);
extern Std_ReturnType Rte_Write_P_FID_Output_QM_FID_QM_stub(const uint32_t*data);

extern Std_ReturnType Rte_Write_P_RES_Output_B_RES_B_stub(const uint32_t *data);
extern Std_ReturnType Rte_Write_P_RES_Output_QM_RES_QM_stub(const uint32_t*data);

extern Std_ReturnType Rte_Read_R_Errors_QM_Errors_QM_stub(uint32_t * data);
//extern Std_ReturnType Rte_Read_R_Errors_A_Errors_A_stub(uint32_t * data);
extern Std_ReturnType Rte_Read_R_Errors_B_Errors_B_stub(uint32_t * data);
//extern Std_ReturnType Rte_Read_R_Errors_C_Errors_C_stub(uint32_t * data);
//extern Std_ReturnType Rte_Read_R_Errors_D_Errors_D_stub(uint32_t * data);


extern Std_ReturnType Rte_DEGMANAGER_READ_QM_INPUT_BY_B(uint32_t * data);
extern Std_ReturnType Rte_DEGMANAGER_READ_QM_INPUT_BY_QM(uint32_t * data);
extern Std_ReturnType Rte_DEGMANAGER_READ_B_INPUT_BY_B(uint32_t * data);
extern Std_ReturnType Rte_DEGMANAGER_READ_B_INPUT_BY_QM(uint32_t * data);
 
#endif

#ifdef RTE_DEGMANAGER_QM_H
#if !defined(DEGMANAGER_FID_BYTE_STRUCT)
Std_ReturnType Rte_Write_P_FID_Output_QM_FID_QM_stub(const uint32_t * data)
{
#if defined(BUILD_MCU1_0)
    return Rte_Write_P_FID_Output_QM_FID_QM((uint32*)data);
#else
    return Rte_Write_P_FID_Output_QM_FID_QM(data);
#endif
}


Std_ReturnType Rte_Write_P_RES_Output_QM_RES_QM_stub(const uint32_t * data)
{
     return Rte_Write_P_RES_Output_QM_RES_QM(data);
}

#endif
#endif

#ifdef RTE_DEGMANAGER_B_H
#if !defined(DEGMANAGER_FID_BYTE_STRUCT)
Std_ReturnType Rte_Write_P_FID_Output_B_FID_B_stub(const uint32_t * data)
{
    return Rte_Write_P_FID_Output_B_FID_B(data);
}

Std_ReturnType Rte_Write_P_RES_Output_B_RES_B_stub(const uint32_t * data)
{
  //  return Rte_Write_P_RES_Output_B_RES_B(data);
	(void)data;
	return E_NOT_OK;
}
#endif
#endif

#ifdef RTE_DEGMANAGER_D_H
#if !defined(DEGMANAGER_FID_BYTE_STRUCT)
Std_ReturnType Rte_Write_P_FID_Output_D_FID_D_stub(const uint32_t * data)
{
    //return Rte_Write_P_FID_Output_D_FID_D(data);
	(void)data;
    return E_NOT_OK;
    
}
#endif
#endif


#if defined(RTE_DEGMANAGER_QM_H)

#if DEGMANAGER_SEND_TYPE == DEGMANAGER_SEND_VIA_IPC
Std_ReturnType Rte_Call_R_IPC_IPC_Write_v_stub(dtRef_VOID b_TxData_pv, UINT16 i_IpcMsgId_u16, UINT16 i_IpcMsgSize_u16)
{
    return Rte_Call_R_IPC_IPC_Write_v(b_TxData_pv,i_IpcMsgId_u16,i_IpcMsgSize_u16);
}
#endif

#endif

#if defined(RTE_DEGMANAGER_QM_H) 
Std_ReturnType Rte_DEGMANAGER_READ_QM_INPUT_BY_QM(uint32_t* data)
{
#ifdef Rte_Read_R_Errors_QM_Errors_QM
    return Rte_Read_R_Errors_QM_Errors_QM((uint32*)data);
#else
    (void)data;
    return E_NOT_OK;
#endif
}

Std_ReturnType Rte_DEGMANAGER_READ_B_INPUT_BY_QM(uint32_t* data)
{
#ifdef Rte_Read_R_Errors_QM_Errors_QM
    return Rte_Read_R_Errors_B_Errors_B((uint32*)data);
#else
    (void)data;
    return E_NOT_OK;
#endif

}
#endif

#if defined(RTE_DEGMANAGER_A_H) 
Std_ReturnType Rte_Read_R_Errors_A_Errors_A_stub(uint32_t* data)
{
#ifdef Rte_Read_R_Errors_A_Errors_A
    return Rte_Read_R_Errors_A_Errors_A(data);
#else
    (void)data;
    return E_NOT_OK;
#endif
}
#endif

#if defined(RTE_DEGMANAGER_B_H) 
Std_ReturnType Rte_DEGMANAGER_READ_B_INPUT_BY_B(uint32_t* data)
{
#ifdef Rte_Read_R_Errors_B_Errors_B
    return Rte_Read_R_Errors_B_Errors_B((uint32*)data);
#else
    (void)data;
    return E_NOT_OK;
#endif
}

Std_ReturnType Rte_DEGMANAGER_READ_QM_INPUT_BY_B(uint32_t* data)
{
#ifdef Rte_Read_R_Errors_QM_Errors_QM
    return Rte_Read_R_Errors_QM_Errors_QM(data);
#else
    (void)data;
    return E_NOT_OK;
#endif
}



#endif

#if defined(RTE_DEGMANAGER_C_H) 
Std_ReturnType Rte_Read_R_Errors_C_Errors_C_stub(uint32_t *data)
{
#ifdef Rte_Read_R_Errors_C_Errors_C
    return Rte_Read_R_Errors_C_Errors_C(data);
#else
    (void)data;
return E_NOT_OK;
#endif
}
#endif

#if defined(RTE_DEGMANAGER_D_H) 
Std_ReturnType Rte_Read_R_Errors_D_Errors_D_stub(uint32_t *data)
{
#ifdef Rte_Read_R_Errors_D_Errors_D
    return Rte_Read_R_Errors_D_Errors_D(data);
#else
    (void)data;
return E_NOT_OK;
#endif
}
#endif

#endif


