#ifndef SYSTEMSTATEDEFINITION_INCLUDEGUARD_H
#define SYSTEMSTATEDEFINITION_INCLUDEGUARD_H

#include "SSM_Cfg.h"
#include <assert.h>
#ifdef BUILD_MCU1_0
#include "Rte_Type.h"
#include "Rte_SSM_Slave_1_0_Type.h"
#include "Rte_SSM_Master_Type.h"
#endif

#include "PlatformDataTypes.h"

/* Section : ASR- NON ASR  . Non Overlapping Data Defintions */
typedef enum
{
    SSM_STARTUPDATA_UNKNOWN,
    SSM_STARTUPDATA_COMPLETED,
    SSM_STARTUPDATA_Size_Enforcer=0xFFFFFFFFu,
}SSM_STARTUPDATA_Def;

typedef enum
{
    SSM_CORE_1_0,
    SSM_CORE_2_0,
    SSM_CORE_2_1,
    SSM_CORE_QNX,
    SSM_CORE_MAX,
    SSM_CORE_Size_Enforcer=0xFFFFFFFFu,
}SSM_CORE_Defs;

typedef enum
{
    SSM_MCU_1_0_Application_CalDataProvider,
	SSM_MCU_1_0_Application_ProxiManager,
	SSM_MCU_1_0_Application_PartNumManager,
	SSM_MCU_1_0_Application_SafeVcanRx,
    SSM_MCU_1_0_Application_MAX,
    SSM_MCU_1_0_Application_Size_Enforcer=0xFFFFFFFFu,
}SSM_MCU_1_0_Applications;

typedef enum
{
    SSM_MCU_2_0_Application_ErrorMgr,
    SSM_MCU_2_0_Application_HMIMgr,
	SSM_MCU_2_0_Application_USS_Pwr,
    SSM_MCU_2_0_Application_MAX,
	SSM_MCU_2_0_Application_Size_Enforcer=0xFFFFFFFFu,
}SSM_MCU_2_0_Applications;


typedef enum
{
    SSM_MCU_2_1_Application_ErrorMgr,
    SSM_MCU_2_1_Application_TRSC,
    SSM_MCU_2_1_Application_THASM,
    SSM_MCU_2_1_Application_APFusion,
    SSM_MCU_2_1_Application_AutoPark,
    SSM_MCU_2_1_Application_USS,
    SSM_MCU_2_1_Application_FOD,
    SSM_MCU_2_1_Application_Arbiter,
    SSM_MCU_2_1_Application_MAX,
    SSM_MCU_2_1_Application_Size_Enforcer=0xFFFFFFFFu,
}SSM_MCU_2_1_Applications;



typedef enum
{
    SSM_MCU_QNX_Application_MAX,
    SSM_MCU_QNX_Application_Size_Enforcer=0xFFFFFFFFu,
}SSM_MCU_QNX_Applications;

typedef enum
{
    SSM_APPSTATE_UNINIT_i,
    SSM_APPSTATE_INIT_i,
    SSM_APPSTATE_RUNNING_i,
    SSM_APPSTATE_DEGRADED_i,
    SSM_APPSTATE_STOPPED_i,
    SSM_APPSTATE_MAX_i,
    SSM_APPSTATE_Size_Enforcer_i=0xFFFFFFFFu,
}SSM_ApplicationStatus_i;


#if defined(RTE_APPLICATION_HEADER_FILE ) && defined(SSM_APPSTATE_MAX)
    #ifndef SSM_DISABLE_STATIC_ALERTCHECKS
        //Size Check
        static_assert(sizeof(SSM_ApplicationStatus_i) == sizeof(SSM_ApplicationStatus) ,"Static assert failed: Size : SSM_CoreSlaveCoreStateDef");
        //Value Check
        static_assert(SSM_APPSTATE_UNINIT_i == SSM_APPSTATE_UNINIT ,"Static assert failed: Value id of SSM_APPSTATE_UNINIT is different");
        static_assert(SSM_APPSTATE_INIT_i == SSM_APPSTATE_INIT ,"Static assert failed: Value id of SSM_APPSTATE_INIT is different");
        static_assert(SSM_APPSTATE_RUNNING_i == SSM_APPSTATE_RUNNING ,"Static assert failed: Value id of SSM_APPSTATE_RUNNING is different");
        static_assert(SSM_APPSTATE_DEGRADED_i == SSM_APPSTATE_DEGRADED ,"Static assert failed: Value id of SSM_APPSTATE_DEGRADED is different");
        static_assert(SSM_APPSTATE_STOPPED_i == SSM_APPSTATE_STOPPED ,"Static assert failed: Value id of SSM_APPSTATE_STOPPED is different");
        static_assert(SSM_APPSTATE_MAX_i == SSM_APPSTATE_MAX ,"Static assert failed: Value id of SSM_APPSTATE_MAX is different");
    #endif
#endif


typedef enum
{
    SSM_STATE_BOOTING_i,
    SSM_STATE_IPCREADY_i,
    SSM_STATE_RUNNING_i,
    SSM_STATE_DEGRADED_i, /* Place holder : May not be needed */
    SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP_i,
    SSM_STATE_SHUTTINGDOWN_REMOTECORES_i,
    SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE_i,
    SSM_STATE_OFF_i,
    SSM_STATE_BOOT_ERROR_i,
    SSM_STATE_MAX_i,
    SSM_STATE_Size_Enforcer_i=0xFFFFFFFFu,
}SSM_SystemStateDef_i;


#ifdef RTE_APPLICATION_HEADER_FILE
    #ifndef SSM_DISABLE_STATIC_ALERTCHECKS
        //Size Check
        static_assert(sizeof(SSM_SystemStateDef_i) == sizeof(SSM_SystemStateDef) ,"Static assert failed: Size : SSM_CoreSlaveCoreStateDef");
        //Value Check
        static_assert(SSM_STATE_BOOTING_i == SSM_STATE_BOOTING ,"Static assert failed: Value id of SSM_STATE_BOOTING is different");
        static_assert(SSM_STATE_IPCREADY_i == SSM_STATE_IPCREADY ,"Static assert failed: Value id of SSM_STATE_IPCREADY is different");
        static_assert(SSM_STATE_RUNNING_i == SSM_STATE_RUNNING ,"Static assert failed: Value id of SSM_STATE_RUNNING is different");
        static_assert(SSM_STATE_DEGRADED_i == SSM_STATE_DEGRADED ,"Static assert failed: Value id of SSM_STATE_DEGRADED is different");
        static_assert(SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP_i == SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP ,"Static assert failed: Value id of SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP is different");
        static_assert(SSM_STATE_SHUTTINGDOWN_REMOTECORES_i == SSM_STATE_SHUTTINGDOWN_REMOTECORES ,"Static assert failed: Value id of SSM_STATE_SHUTTINGDOWN_REMOTECORES is different");
        static_assert(SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE_i == SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE ,"Static assert failed: Value id of SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE is different");
        static_assert(SSM_STATE_OFF_i == SSM_STATE_OFF ,"Static assert failed: Value id of SSM_STATE_OFF is different");
        static_assert(SSM_STATE_BOOT_ERROR_i == SSM_STATE_BOOT_ERROR ,"Static assert failed: Value id of SSM_STATE_BOOT_ERROR is different");
        static_assert(SSM_STATE_MAX_i == SSM_STATE_MAX ,"Static assert failed: Value id of SSM_STATE_MAX is different");
    #endif
#endif


typedef enum
{
    SSM_DEGRADEDSTATE_MAX_i,
    SSM_DEGRADEDSTATE_Size_Enforcer_i=0xFFFFFFFFu,
}SSM_DegradedState_i;


#ifdef RTE_APPLICATION_HEADER_FILE
    #ifndef SSM_DISABLE_STATIC_ALERTCHECKS
        //Size Check
        static_assert(sizeof(SSM_DegradedState_i) == sizeof(SSM_DegradedState) ,"Static assert failed: Size : SSM_CoreSlaveCoreStateDef");
        //Value Check
        static_assert(SSM_DEGRADEDSTATE_MAX_i == SSM_DEGRADEDSTATE_MAX ,"Static assert failed: Value id different");
    #endif
#endif

typedef enum
{
    SSM_SlaveCore_State_Unknown_i,
    SSM_SlaveCore_State_BSP_Booting_i,
    SSM_SlaveCore_State_BSP_Init_Done_i,
    SSM_SlaveCore_State_Calibrated_i,
    SSM_SlaveCore_State_AppInitialized_i,
    SSM_SlaveCore_State_Running_i,
    SSM_SlaveCore_State_MAX_i,
    SSM_SlaveCore_Size_Enforcer_i=0xFFFFFFFFu,
}SSM_CoreSlaveCoreStateDef_i;

#if defined(RTE_APPLICATION_HEADER_FILE ) && defined(SSM_SlaveCore_State_MAX)
    #ifndef SSM_DISABLE_STATIC_ALERTCHECKS
        //Size Check
        static_assert(sizeof(SSM_CoreSlaveCoreStateDef_i) == sizeof(SSM_CoreSlaveCoreStateDef) ,"Static assert failed: Size : SSM_CoreSlaveCoreStateDef");
        //Value Check
        static_assert(SSM_SlaveCore_State_Unknown_i == SSM_SlaveCore_State_Unknown ,"Static assert failed: Value id of SSM_SlaveCore_State_Unknown is different");
        static_assert(SSM_SlaveCore_State_BSP_Booting_i == SSM_SlaveCore_State_BSP_Booting ,"Static assert failed: Value id of SSM_SlaveCore_State_BSP_Booting is different");
        static_assert(SSM_SlaveCore_State_BSP_Init_Done_i == SSM_SlaveCore_State_BSP_Init_Done ,"Static assert failed: Value id of SSM_SlaveCore_State_BSP_Init_Done is different");
        static_assert(SSM_SlaveCore_State_Calibrated_i == SSM_SlaveCore_State_Calibrated ,"Static assert failed: Value id of SSM_SlaveCore_State_Calibrated is different");
        static_assert(SSM_SlaveCore_State_AppInitialized_i == SSM_SlaveCore_State_AppInitialized ,"Static assert failed: Value id of SSM_SlaveCore_State_AppInitialized is different");
        static_assert(SSM_SlaveCore_State_Running_i == SSM_SlaveCore_State_Running ,"Static assert failed: Value id of SSM_SlaveCore_State_Running is different");
        static_assert(SSM_SlaveCore_State_MAX_i == SSM_SlaveCore_State_MAX ,"Static assert failed: Value id of SSM_SlaveCore_State_MAX is different");
    #endif
#endif

typedef SSM_ApplicationStatus_i SSM_MCU_1_0_LocalAppStatus_Arr_i[D_STATICARRAYMAX_SSM_MCU_1_0_Application_MAX];
typedef SSM_ApplicationStatus_i SSM_MCU_2_0_LocalAppStatus_Arr_i[D_STATICARRAYMAX_SSM_MCU_2_0_Application_MAX];
typedef SSM_ApplicationStatus_i SSM_MCU_2_1_LocalAppStatus_Arr_i[D_STATICARRAYMAX_SSM_MCU_2_1_Application_MAX];
typedef SSM_ApplicationStatus_i SSM_MCU_QNX_LocalAppStatus_Arr_i[D_STATICARRAYMAX_SSM_MCU_QNX_Application_MAX];

#ifndef SSM_DISABLE_STATIC_ALERTCHECKS
    #ifdef Rte_TypeDef_SSM_MCU_1_0_LocalAppStatus_Arr        
    static_assert(sizeof(SSM_MCU_1_0_LocalAppStatus_Arr_i) == sizeof(SSM_MCU_1_0_LocalAppStatus_Arr) ,"Static assert failed: Size : ");
    #endif
    #ifdef Rte_TypeDef_SSM_MCU_2_0_LocalAppStatus_Arr 
    static_assert(sizeof(SSM_MCU_2_0_LocalAppStatus_Arr_i) == sizeof(SSM_MCU_2_0_LocalAppStatus_Arr) ,"Static assert failed: Size : ");
    #endif
    #ifdef Rte_TypeDef_SSM_MCU_2_1_LocalAppStatus_Arr 
    static_assert(sizeof(SSM_MCU_2_1_LocalAppStatus_Arr_i) == sizeof(SSM_MCU_2_1_LocalAppStatus_Arr) ,"Static assert failed: Size : ");
    #endif
    #ifdef Rte_TypeDef_SSM_MCU_QNX_LocalAppStatus_Arr 
    static_assert(sizeof(SSM_MCU_QNX_LocalAppStatus_Arr_i) == sizeof(SSM_MCU_QNX_LocalAppStatus_Arr) ,"Static assert failed: Size : ");
    #endif        
#endif    


/* Structures for IPC Communication */
/* 1_0 to all Cores */

typedef struct
{
    SSM_CoreSlaveCoreStateDef_i CoreStatus;
    SSM_MCU_1_0_LocalAppStatus_Arr_i LocalAppStatus;
}SSM_1_0_CoreStatus_i;

/* 2_0 to all Cores */
typedef struct
{
    SSM_CoreSlaveCoreStateDef_i CoreStatus;
    SSM_MCU_2_0_LocalAppStatus_Arr_i LocalAppStatus;
}SSM_2_0_CoreStatus_i;

/* 2_1 to all Cores */
typedef struct
{
    SSM_CoreSlaveCoreStateDef_i CoreStatus;
    SSM_MCU_2_1_LocalAppStatus_Arr_i LocalAppStatus;
}SSM_2_1_CoreStatus_i;


/* QNX to all Cores */
typedef struct
{
    SSM_CoreSlaveCoreStateDef_i CoreStatus;
    SSM_MCU_QNX_LocalAppStatus_Arr_i LocalAppStatus;
}SSM_QNX_CoreStatus_i;

typedef struct
{
    SSM_SystemStateDef_i SystemState;
    SSM_DegradedState_i DegradedState;
}SSM_SystemState_i;


/* Structure and  Array Defs */

#ifdef RTE_APPLICATION_HEADER_FILE
    #ifndef SSM_DISABLE_STATIC_ALERTCHECKS
    /* This is an RTE build : Data types will be from the RTE Defintion */
    // Some rationality checks make sure the arxl structure sizes and the definitions are not out alignmenet
    static_assert(sizeof(SSM_1_0_CoreStatus_i) == sizeof(SSM_1_0_CoreStatus), "ARXML SSM Size Misalignment");
    static_assert(sizeof(SSM_2_0_CoreStatus_i) == sizeof(SSM_2_0_CoreStatus), "ARXML SSM Size Misalignment");
    static_assert(sizeof(SSM_2_1_CoreStatus_i) == sizeof(SSM_2_1_CoreStatus), "ARXML SSM Size Misalignment");
    static_assert(sizeof(SSM_QNX_CoreStatus_i) == sizeof(SSM_QNX_CoreStatus), "ARXML SSM Size Misalignment");
    static_assert(sizeof(SSM_SystemState_i) == sizeof(SSM_SystemState), "ARXML SSM Size Misalignment");
    #endif
#else
    #if defined(BUILD_MCU1_0)
    #else
    //This is needed for IPC (because it only the common structure name it shares with the same name as RTE)
    typedef SSM_1_0_CoreStatus_i SSM_1_0_CoreStatus;
    typedef SSM_2_0_CoreStatus_i SSM_2_0_CoreStatus;
    typedef SSM_2_1_CoreStatus_i SSM_2_1_CoreStatus;
    typedef SSM_QNX_CoreStatus_i SSM_QNX_CoreStatus;
    typedef SSM_SystemState_i SSM_SystemState;
	#endif
#endif


#if defined(BUILD_MCU1_0) 
    typedef SSM_1_0_CoreStatus SSM_LocalCoreStatus;
    typedef SSM_MCU_1_0_Applications SSM_LocalCoreApplications;
    #define SSM_LOCALAPPLICATION_MAX SSM_MCU_1_0_Application_MAX
    #define SSM_SLAVE_CURRENTCORE   SSM_CORE_1_0
#elif defined(BUILD_MCU2_0) 
    typedef SSM_2_0_CoreStatus_i SSM_LocalCoreStatus;
    typedef SSM_MCU_2_0_Applications SSM_LocalCoreApplications;
    #define SSM_LOCALAPPLICATION_MAX SSM_MCU_2_0_Application_MAX
    #define SSM_SLAVE_CURRENTCORE   SSM_CORE_2_0
#elif defined(BUILD_MCU2_1) 
    typedef SSM_2_1_CoreStatus_i SSM_LocalCoreStatus;
    typedef SSM_MCU_2_1_Applications SSM_LocalCoreApplications;
    #define SSM_LOCALAPPLICATION_MAX SSM_MCU_2_1_Application_MAX
    #define SSM_SLAVE_CURRENTCORE   SSM_CORE_2_1
#elif defined(BUILD_MCUQNX) 
    typedef SSM_QNX_CoreStatus_i SSM_LocalCoreStatus;
    typedef SSM_MCU_QNX_Applications SSM_LocalCoreApplications;
    #define SSM_LOCALAPPLICATION_MAX SSM_MCU_QNX_Application_MAX
    #define SSM_SLAVE_CURRENTCORE   SSM_CORE_QNX
#else
    #warning "Undefined SSM"
#endif


#define SSM_MAX_MONITORED_APPLICATIONS  ((uint8_t)SSM_MCU_1_0_Application_MAX+(uint8_t)SSM_MCU_2_0_Application_MAX+(uint8_t)SSM_MCU_2_1_Application_MAX+(uint8_t)SSM_MCU_QNX_Application_MAX)

#endif




