#ifndef DEGMANAGER_CFG_INCLUDEGAURD
#define DEGMANAGER_CFG_INCLUDEGAURD

//#define DEGMANAGER_ALLOWLOWERLEVELASIL_INPUTS


#define DEGMANAGER_QM_LEVEL_ACTIVE	1u
#define DEGMANAGER_A_LEVEL_ACTIVE	0u
#define DEGMANAGER_B_LEVEL_ACTIVE	1u
#define DEGMANAGER_C_LEVEL_ACTIVE	0u
#define DEGMANAGER_D_LEVEL_ACTIVE	0u

#define DEGMANAGER_SEND_VIA_IPC 				0x01u
#define DEGMANAGER_SEND_VIA_SIGNALMGR 			0x02u
#define DEGMANAGER_SEND_VIA_SIGNALMGR_RTE 		0x03u
#define DEGMANAGER_SEND_TYPE	DEGMANAGER_SEND_VIA_IPC


#if DEGMANAGER_SEND_TYPE == DEGMANAGER_SEND_VIA_IPC

	#define DEGMANAGER_SEND_QM(x,y,z)	Rte_Call_R_IPC_IPC_Write_v_stub((void *)x,y,z)
	#define DEGMANAGER_SEND_B(x,y,z)	Rte_Call_R_IPC_IPC_Write_v_stub((void *)x,y,z)

#elif DEGMANAGER_SEND_TYPE == DEGMANAGER_SEND_VIA_SIGNALMGR


	#define DEGMANAGER_SEND_QM(x,y,z)	SigMgr_Data_DegManager_Output_QM_Put(x)
	#define DEGMANAGER_SEND_B(x,y,z)	SigMgr_Data_DegManager_Output_B_Put(x)


#elif DEGMANAGER_SEND_TYPE == DEGMANAGER_SEND_VIA_SIGNALMGR_RTE

	#error  "Needs to be filled in"
	#define DEGMANAGER_SEND_QM(x,y,z)
	#define DEGMANAGER_SEND_B(x,y,z)
#else
	#error "Undefined Sendtype in DEGMANAGER Send Type"
#endif


/* Todo : IPC Message ID's need to be updated */
#if DEGMANAGER_QM_LEVEL_ACTIVE == 1u
	#ifdef  DISABLE_FIDSEND_TO_FEATURES_NONPROD_BUILD
#define DEGMANAGER_WRITE_QM_MSGID  (e_IpcMsgId_Data_FID_STRUCT_QM)
	#else
		#define DEGMANAGER_WRITE_QM_MSGID  (e_IpcMsgId_Data_FID_STRUCT_QM)  /*(e_IpcMsgId_Data_FID_STRUCT_QM)*/
	#endif

	#define DEGMANAGER_READ_QM_INPUT_BY_QM(x)  Rte_DEGMANAGER_READ_QM_INPUT_BY_QM(x)
	#define DEGMANAGER_READ_B_INPUT_BY_QM(x)   Rte_DEGMANAGER_READ_B_INPUT_BY_QM(x)
#endif

#if DEGMANAGER_A_LEVEL_ACTIVE == 1u
#define DEGMANAGER_WRITE_A_MSGID  (0u)
#endif

#if DEGMANAGER_B_LEVEL_ACTIVE == 1u
	#ifdef  DISABLE_FIDSEND_TO_FEATURES_NONPROD_BUILD
#define DEGMANAGER_WRITE_B_MSGID  (e_IpcMsgId_Data_FID_STRUCT_B)
	#else
		#define DEGMANAGER_WRITE_B_MSGID  (e_IpcMsgId_Data_FID_STRUCT_B) /*(e_IpcMsgId_Data_FID_STRUCT_B)*/
	#endif
	#define DEGMANAGER_READ_B_INPUT_BY_B(x)    Rte_DEGMANAGER_READ_B_INPUT_BY_B(x)
	#define DEGMANAGER_READ_QM_INPUT_BY_B(x)    Rte_DEGMANAGER_READ_QM_INPUT_BY_B(x)
#endif

#if DEGMANAGER_C_LEVEL_ACTIVE == 1u
#define DEGMANAGER_WRITE_C_MSGID  (0u)
#endif

#if DEGMANAGER_D_LEVEL_ACTIVE == 1u
#define DEGMANAGER_WRITE_D_MSGID  (0u)
#endif



#define DEGMANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION    1u


#define DEGMANAGER_PACKINGSIZE	(32u)

/* CVADAS :Define to match IPC struct*/
#define DEGMANAGER_FID_BYTE_STRUCT   1u

//Todo:Temporary configurations till fixed permanently by users:
//Application features are reading C object which should be removed
#define SigMgr_Data_DegManager_Output_C_Get(x)
#define DegManagerApp_ConvStruct_C(x,y,z)
typedef struct {
 unsigned char Dummy;
}DegManager_Dummy_Struct_PlaceHolder;
typedef DegManager_Dummy_Struct_PlaceHolder FID_STRUCT_A;
typedef DegManager_Dummy_Struct_PlaceHolder RES_STRUCT_FEATURES_A;
typedef DegManager_Dummy_Struct_PlaceHolder FID_STRUCT_C;
typedef DegManager_Dummy_Struct_PlaceHolder RES_STRUCT_FEATURES_C;
typedef DegManager_Dummy_Struct_PlaceHolder FID_STRUCT_D;
typedef DegManager_Dummy_Struct_PlaceHolder RES_STRUCT_FEATURES_D;
typedef DegManager_Dummy_Struct_PlaceHolder DegManager_Output_C_t;
//End temporary fix



#define DEGRADATIONMANAGER_QM_EXECUTION_DIVISOR_COUNT	 (3u)
#define DEGRADATIONMANAGER_B_EXECUTION_DIVISOR_COUNT	 (3u)


#ifdef WIN32

//VS Enviroment
#define DEGMANAGER_ATTR_B_HIGHPERF_BSS
#define DEGMANAGER_ATTR_B_BSS

#define DEGMANAGER_ATTR_QM_HIGHPERF_BSS
#define DEGMANAGER_ATTR_QM_BSS

#else

#define DEGMANAGER_ATTR_B_HIGHPERF_BSS 		__attribute__((section("DegManager_BSS_B_HighPerf")))
#define DEGMANAGER_ATTR_B_BSS 				__attribute__((section("DegManager_BSS_B")))

#define DEGMANAGER_ATTR_QM_HIGHPERF_BSS 	__attribute__((section("DegManager_BSS_QM_HighPerf")))
#define DEGMANAGER_ATTR_QM_BSS 				__attribute__((section("DegManager_BSS_QM")))

#endif


#endif
