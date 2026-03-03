

#if defined( BUILD_MCU2_1 ) || defined( BUILD_MCU2_0 )
    #include "SignalDef.h"
#elif defined( BUILD_MCU1_0 )
    #include "Rte_SSM_Slave_1_0.h"
#endif

#include "PlatformDataTypes.h"
#include "SSM_Slave_app.h"
#include "CalDataProvider_defs.h"
#include "ProxiMgrIpcDataTypes.h"


#ifdef  SSM_APPLICATION_SLAVE

#if defined( BUILD_MCU2_1 ) || defined( BUILD_MCU2_0 )
    /* Forward Declarations */
    /* Tying this approach as otherwise the chain of dependencies have to be added to the makefile */
    /*void*/bool_t Tasks_Launch_AppTasks(void);
#endif
#if defined( BUILD_MCU2_1 )
    bool_t Tasks_Launch_AppSafetyTasks(void);
#endif

#if defined(BUILD_MCU1_0) 
void SSM_Slave_App_HandleStateChange(SSM_CoreSlaveCoreStateDef Curr, SSM_CoreSlaveCoreStateDef Next)
#else
void SSM_Slave_App_HandleStateChange(SSM_CoreSlaveCoreStateDef_i Curr, SSM_CoreSlaveCoreStateDef_i Next)
#endif
{
    /* DD-ID: {43855FD4-DBA2-45a6-9D1A-EFD1A0296F9A}*/
    /* DD-ID:{017D2F5C-5054-46f9-A9EB-D68FA01F3AD6}*/
    //Any Additional Handling like intializing States , starting RT/Tasks
    #if defined(BUILD_MCU1_0) 
    if((Curr == SSM_SlaveCore_State_BSP_Init_Done) && (Next == SSM_SlaveCore_State_Calibrated))
    #else
    if((Curr == SSM_SlaveCore_State_BSP_Init_Done_i) && (Next == SSM_SlaveCore_State_Calibrated_i))
    #endif
    {
        //Start the Application Tasks

        #if defined( BUILD_MCU2_1 ) || defined( BUILD_MCU2_0 )
        Tasks_Launch_AppTasks();
        #endif
        #if defined( BUILD_MCU2_1 )
        Tasks_Launch_AppSafetyTasks();
        #endif
    }
}

uint32_t SSM_Slave_App_getLocalTime(void)
{
  /* DD-ID: {2D6216B0-0E4E-462b-BA73-4F4DA3BAFA74}*/
    return 0;
}

void SSM_Slave_App_SendCoreStatus(const SSM_LocalCoreStatus* CoreStatus)
{
  /* DD-ID: {1F31FBB9-4DF3-4696-BEB2-0A5E4C65802C}*/
    //Write to the underlying Communication Layer
    #ifdef BUILD_MCU2_0
            SigMgr_PpSR_State_MCU2_State_2_0_Put(( SSM_2_0_CoreStatus *)CoreStatus);
    #endif
    #ifdef BUILD_MCU2_1
            SigMgr_PpSR_State_MCU2_State_2_1_Put(( SSM_2_1_CoreStatus *)CoreStatus);
    #endif
    #ifdef  BUILD_MCU1_0
            (void)Rte_Write_P_SSM_1_0_State_State_1_0((const SSM_1_0_CoreStatus *)CoreStatus);
    #endif
    #ifdef  BUILD_MCUQNX
            /*  Below function call is enabled when SSM implementation for QNX is added */
            /* SigMgr_PpSR_State_QNX_State_QNX_Put(( SSM_QNX_CoreStatus *)CoreStatus */

    #endif
}


bool_t SSM_Slave_App_GetStartupDataAvailability(void)
{
  /* DD-ID: {55576056-C69E-4bd7-A53E-69E135981080}*/
    bool_t bDataAvaialable = FALSE;
    //Check if the calibration data is available
 

     //Write to the underlying Communication Layer
    #ifdef BUILD_MCU1_0
			//No Sync Needed as CalDataProvider sits in the MCU1_0 core
            /* CalDataProvider_MCU_1_0_Def CalibData */
            /* ME_Hydra2defs_S_CodingTableExt_t ProxiData */

                bDataAvaialable=TRUE;

    #endif
    #ifdef BUILD_MCU2_0
            const CalDataProvider_MCU_2_0_Def *CalibDataPtr;
            const ME_ProxiToMCU2_0_Def_t *ProxiDataPtr;

            // Read the Proxi Data for MCU2_0
            ProxiDataPtr = SigMgr_Data_ME_ProxiToMCU2_0_Def_t_GetDataObjRef();

            // Read the Calibration Data for MCU2_0
            CalibDataPtr=SigMgr_Data_CalDataProvider_MCU_2_0_Def_GetDataObjRef();

            // Check the validity of the Proxi and Calibration data
            if((ProxiDataPtr->PRX_bValid_b == TRUE) && (CalibDataPtr->bValid == TRUE))
            {
                bDataAvaialable=TRUE;
            }
    #endif
    #ifdef BUILD_MCU2_1
            const CalDataProvider_MCU_2_1_Def *CalibDataPtr;
            /* ME_Proxi_to_IpcSignals_t *ProxiDataPtr */
            const ME_ProxiToMCU2_1_Def_t  *ProxiDataPtr;
            const US_S_MarriageSensorIDs_t *UssMarDataPtr;

            // Read the Proxi Data for MCU2_1
            ProxiDataPtr = SigMgr_Data_ME_ProxiToMCU2_1_Def_t_GetDataObjRef();

            // Read the Calibration Data for MCU2_1
            CalibDataPtr= SigMgr_Data_CalDataProvider_MCU_2_1_Def_GetDataObjRef();

            // Read the USS marriage data
            UssMarDataPtr = SigMgr_Data_US_S_MarriageSensorIDs_t_GetDataObjRef();

            // Check the validity of the Proxi and Calibration data
            if( (ProxiDataPtr->PRX_bValid_b == TRUE) && (CalibDataPtr->bValid == TRUE)
            	&& (UssMarDataPtr->bValid == TRUE) )
            {
                bDataAvaialable=TRUE;
            }
    #endif
    #ifdef BUILD_MCUQNX

            // Below code is enabled when SSM implementation for QNX is added.
#if 0
            const CalDataProvider_MPU_1_0_Def *CalibDataPtr;
            const ME_ProxiToMPU1_0_Def_t *ProxiDataPtr;

            // Read the Proxi Data for MPU
            ProxiDataPtr = SigMgr_Data_ME_ProxiToMPU1_0_Def_t_GetDataObjRef();

            // Read the Calibration Data for MPU
            CalibDataPtr= SigMgr_Data_CalDataProvider_MPU_1_0_Def_GetDataObjRef();

            // Check the validity of the Proxi and Calibration data
            if( (ProxiDataPtr->PRX_bValid_b == TRUE) && (CalibDataPtr->bValid == TRUE))
            {
                bDataAvaialable=TRUE;
            }
#endif
			bDataAvaialable=TRUE;


    #endif

    return bDataAvaialable;
}


void SSM_Slave_App_MainTask(void)
{
  /* DD-ID: {09F99D5B-1EE1-4dec-853C-E2AB901AFF12}*/

}


#endif



