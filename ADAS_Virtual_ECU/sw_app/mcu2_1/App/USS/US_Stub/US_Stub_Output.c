/** \file US_Stub_Input.c
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore
 *  \brief This file contains platform specific input interfaces.
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "US_Stub.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_ComInputBuffer_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_Hsd_Global.h"
#include "VoltageCurrent_data.h"
#include "US_Stub_IfMap.h"
#include "SSM_Slave.h"
#include "Us_Csm_If.h"
/*PRQA S 0776,0751 EOF */

/************************************************************************************************************************
                                                            Imported data
************************************************************************************************************************/
extern uint8_t UssCom_DataSequenceNumber;


/************************************************************************************************************************
                                                            Local #defines
************************************************************************************************************************/
#if(QAC_WARNING_FIX == ME_FALSE)
#define OUTPUT_CYCLE_20MS     (2U)
#endif
#define OUTPUT_CYCLE_40MS     (4U)
#define OUTPUT_CYCLE_200MS    (20U)
#define OUTPUT_CYCLE_10000MS  (1000U)

#define NULL_PTR_US_POINT_MAP         ((US_S_PointMapGroup_t *)0)
#define NULL_PTR_US_POINT_DIST        ((US_S_PointDistOutputBuff_t *)0)
#define NULL_PTR_US_DIRECT_ECHO       ((US_S_SnrDirEcho_t *)0)
#define NULL_PTR_US_ZONE_INFO         ((US_S_ZoneInfo_t *)0)
#define NULL_PTR_US_BLOCKAGE_FLAG     ((US_S_BlockageBit_t *)0)
#define NULL_PTR_US_CONSTANT_DATA     ((US_S_USSConstantData_t *)0)
#define NULL_PTR_US_PERIOD_DATA       ((US_S_USSPeriodDiagData_t *)0)
#define NULL_PTR_US_ERROR_DIAG_DATA   ((US_S_USSErrorDiagData_t *)0)
#define NULL_PTR_US_ODOMETRY_DATA     ((UssCom_S_OdometryData_t *)0)
#define NULL_PTR_US_DEBUG_SIGNAL      ((US_S_DebugMsg_t *)0)
#define NULL_PTR_US_POINT_DEBUG_DATA  ((UssCom_S_PntDebugData_t *)0)
#define NULL_PTR_US_DATA_COLLECTION  ((US_S_USSDataCollectionData_t *)0)

/************************************************************************************************************************
                                                            Global Variables
************************************************************************************************************************/
US_S_USSDataCollectionData_t US_sDataCollectionData;
USS_PowerSelect_t Dsi3BusPowerReq;

/************************************************************************************************************************
                                                            Local Variables
************************************************************************************************************************/
#if(USS_COM_DATA_SHARE_ENBL_POINT_DIST ==  US_STD_ON)
static US_S_PointDistOutputBuff_t US_sPointDistOutputBuff;
#endif

#if(USS_COM_DATA_SHARE_ENBL_POINT_MAP ==  US_STD_ON)
static US_S_PointMapGroup_t US_sPointMapOutputBuff;
#endif

#if(USS_COM_DATA_SHARE_ENBL_DIRECT_ECHO ==  US_STD_ON)
static  US_S_SnrDirEcho_t US_sSnrDirEchoOutputBuff;
#endif

#if(USS_COM_DATA_SHARE_ENBL_ZONE_INFO ==  US_STD_ON)
static US_S_ZoneInfo_t US_sZoneInfoOutputBuffer;
#endif

#if(USS_COM_DATA_SHARE_ENBL_BLOCKAGE_FLAG ==  US_STD_ON)
static US_S_BlockageBit_t US_sBlockageBitOutputBuff;
#endif

#if(USS_COM_DATA_SHARE_ENBL_PART_NO_VERSION ==  US_STD_ON)
static US_S_USSConstantData_t US_sConstantInfo;
#endif

#if(USS_COM_DATA_SHARE_ENBL_PERIODIC_DIAG ==  US_STD_ON)
static US_S_USSPeriodDiagData_t US_sPeriodDiagInfo;
#endif

#if(USS_COM_DATA_SHARE_ENBL_ERR_DIAG ==  US_STD_ON)
static US_S_USSErrorDiagData_t US_sErrorDiagInfo;
#endif

static US_S_MarriageSensorIDs_t US_sMarriageSensordata={0};	
static uint8_t UsComOutputDataOnInit = ME_TRUE;


/************************************************************************************************************************
                                                            Global Functions
************************************************************************************************************************/
void US_StubOuput_Init(void);
void US_Com_ReqHsdPwrChannel_A(bool on);
void US_Com_ReqHsdPwrChannel_B(bool on);
uint8_t UssStubOutput_SnrCfg_CmdReq(uint8_t *ptrCmd, uint8 cmdSize, uint8 snrTuneId);
uint16_t USS_Send_UssTunningDataByIPC(const uint8_t *SndData,uint16_t len,uint8_t ID);
/*comment out void US_ComShareOutputBuff(void *Data); */
/*comment out void UssCom_F_OutputDataShareMain(void); */


/************************************************************************************************************************
                                                            Local Functions
************************************************************************************************************************/
#if(USS_COM_DATA_SHARE_ENBL_POINT_DIST ==  US_STD_ON)
  static void Us_StubOutput_PointDist(US_S_PointDistOutputBuff_t *ptrPointDist);
#endif

#if(USS_COM_DATA_SHARE_ENBL_POINT_MAP ==  US_STD_ON)
 static void Us_StubOutput_PointMap(US_S_PointMapGroup_t *ptrPointMapGroup);
#endif

#if(USS_COM_DATA_SHARE_ENBL_DIRECT_ECHO ==  US_STD_ON)
   static void Us_StubOutput_DirectEcho(US_S_SnrDirEcho_t *ptrDirEcho);
#endif

#if(USS_COM_DATA_SHARE_ENBL_ZONE_INFO ==  US_STD_ON)
   static void Us_StubOutput_ZoneInfo(US_S_ZoneInfo_t *ptrZoneInfo);;
#endif

#if(USS_COM_DATA_SHARE_ENBL_BLOCKAGE_FLAG ==  US_STD_ON)
    static void Us_StubOutput_BlockageBit(US_S_BlockageBit_t *ptrBlockageBit);
#endif

#if(USS_COM_DATA_SHARE_ENBL_PART_NO_VERSION ==  US_STD_ON)
	static void UssCom_CopySnrMurataSerNumForIPC(void);
	static void UssCom_CopySnrIMESerNumForIPC(void);
	static void UssCom_CopySnrPwrSupplyParameters(void);
	static void UssCom_CopySnrPartNum(void);
	static void UssCom_CopyUssVersion(void);
    static void Us_StubOutput_USSConstantData(US_S_USSConstantData_t *US_sConstantInfo_ptr);
#endif

#if(USS_COM_DATA_SHARE_ENBL_PERIODIC_DIAG ==  US_STD_ON)
	static void UssCom_CopyDrvFrqForIPC(UssCom_S_TestDataMux_t *Data);
	static void UssCom_CopyRingFrqForIPC(UssCom_S_TestDataMux_t *Data);
	static void UssCom_CopyRingTimeForIPC(UssCom_S_TestDataMux_t *Data);
	static void UssCom_CopyBlockageCounterIPC(UssCom_S_TestDataMux_t *Data);
	static void UssCom_CopySnrTempForIPC(sint16_t* Data);
    static void Us_StubOutput_USSPeriodDiagData(US_S_USSPeriodDiagData_t *ptrUSSPeriodDiagData);
#endif

#if(USS_COM_DATA_SHARE_ENBL_ERR_DIAG ==  US_STD_ON)
   static void Us_StubOutput_ErrorDiagData(US_S_USSErrorDiagData_t *ptrErrorDiagData);
#endif

#if(USS_COM_DATA_SHARE_ENBL_ODOMETRY_DATA ==  US_STD_ON)
   static void Us_StubOutput_OdometryData(UssCom_S_OdometryData_t *ptrOdometryData);
#endif

#if(USS_COM_DATA_SHARE_ENBL_DEBUG_SIGNAL ==  US_STD_ON)
   static void Us_StubOutput_DebugMsg(US_S_DebugMsg_t  *ptrsDebugMsg);
#endif

#if(USS_COM_DATA_SHARE_ENBL_POINT_DEBUG ==  US_STD_ON)
   static void Us_StubOutput_PointDebug(UssCom_S_PntDebugData_t  *ptrsPntDebugData);
#endif

#ifndef PLAYBACK_SW_ENABLE
static void Us_StubOutput_USSDataCollectionData(US_S_USSDataCollectionData_t *ptrUSSDataCollectionData);
#endif 
 

/************************************************************************************************************************
                                                            Function Definations
************************************************************************************************************************/

/**
 * /brief This function request to save the sensor marraige data.
 * 
 * /param data 
 * /return uint16_t 
 */
/* ===========================================================================
 * Name: NVMWrite_SensorMarriage    
 * Remarks:  DD-ID: {F4BF6F8A-32F1-4eec-B2BA-02889CC5E5F5}
 * ===========================================================================*/
uint16_t NVMWrite_SensorMarriage(US_S_MarriageSensorIDs_t *data) 
{
	 bool_t status = ME_FALSE;
	 uint16_t ret = ME_NOT_OK;
 	 
	 (void)memcpy(&US_sMarriageSensordata,data,sizeof(US_S_MarriageSensorIDs_t));    
     US_sMarriageSensordata.bValid = ME_TRUE;
 	 status = UsStubOutput_WriteIf_MarriageSnrId(&US_sMarriageSensordata);

     if(status ==(bool_t) ME_TRUE)
	 {
		 ret = ME_OK;
	 }

     return ret;
}


/* ===========================================================================
 * Name:	 USS_Send_UssTunningDataByIPC
 * Remarks:  DD-ID: {48E724C5-48C6-4c95-BD68-15755C662F33}
 * ===========================================================================*/

uint16_t USS_Send_UssTunningDataByIPC(const uint8_t *SndData,uint16_t len,uint8_t ID)
{
	uint16_t SndLen,TuningCmdSeqID;
#if ((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)
	static UssTunningData_mcu2_1_t SndUssTunningData;
    TuningCmdSeqID = US_Get_DynamicCalMsgID(); 
#endif
	if(len > (TUNING_DATA_MAX_SIZE - SEVEN))
	{
		SndLen = TUNING_DATA_MAX_SIZE - SEVEN;
	}
	else
	{
		SndLen = len; 
	}
	SndLen += FIVE;	
  #if ((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)
	(void)memcpy((uint8_t*)&SndUssTunningData.UssTunningDataOut[TWO], (uint8_t*)&TuningCmdSeqID,TWO);
	(void)memcpy((uint8_t*)&SndUssTunningData.UssTunningDataOut[ZERO], (uint8_t*)&SndLen,TWO);
	(void)memcpy((uint8_t*)&SndUssTunningData.UssTunningDataOut[SEVEN], (uint8_t*)SndData,SndLen);
	SndUssTunningData.UssTunningDataOut[FOUR] = ZERO;
	SndUssTunningData.UssTunningDataOut[FIVE] = ZERO;
	SndUssTunningData.UssTunningDataOut[SIX] = ID;
	(void)SigMgr_PpUssTunData_UssTunningData_mcu2_1_t_Put(&SndUssTunningData);
 #endif
                     SndLen -= FIVE;
  return (SndLen);
}

/**
 * /brief This function initialize the data uss high side driver request data.
 * 
 */
/* ===========================================================================
 * Name: US_StubOuput_Init     
 * Remarks:  DD-ID:{6F163529-E0DD-4460-9C07-42DDBC47D81F} 
 * ===========================================================================*/
 void US_StubOuput_Init(void)
 {
	Dsi3BusPowerReq.USS_PWR_EN_A = ME_FALSE;
	Dsi3BusPowerReq.USS_PWR_EN_B = ME_FALSE;
 }
 

/**
 * /brief This function outputs final uss output data on required interface like IPC, CAN, Callbacks etc.
 *  Also this function control the data output rate.
 * 
 * /param Data 
 */
/* ===========================================================================
 * Name:  US_ComShareOutputBuff   
 * Remarks:  DD-ID: {5BE3DA32-DCB1-4fa8-B2E1-3B5AB1D7A0A1}
 * ===========================================================================*/
 void US_ComShareOutputBuff(void *Data)
 {
 	static uint16_t cnt = ZERO;
    UssMgr_s_OutputSignals_t *UssComOutputBuffer =(UssMgr_s_OutputSignals_t*)Data;
    bool_t bNewData,bDataCopied;  
  	bNewData = UssCom_F_IsNewDataAvailable();
	bDataCopied = UssCom_F_Get_OutDataCopiedFlag();
    if((bNewData !=(bool_t) ME_FALSE )&&(bDataCopied !=(bool_t) ME_FALSE))
	{
        UssCom_F_ClearNewDataFlag();
		UssCom_F_Clr_OutDataCopiedFlag();
        UssComOutputBuffer->sFiringSensors.rsv = 0x01; /* Set here, cleared there */
#if(USS_COM_DATA_SHARE_ENBL_POINT_MAP == US_STD_ON)
		(void)memcpy(&US_sPointMapOutputBuff, &UssComOutputBuffer->sFiringSensors,  sizeof(US_S_PointMapGroup_t));  
		Us_StubOutput_PointMap(&US_sPointMapOutputBuff);   /*public Point Map */
#endif

#if(USS_COM_DATA_SHARE_ENBL_POINT_DIST == US_STD_ON)
		(void)memcpy(&US_sPointDistOutputBuff, &UssComOutputBuffer->sPointDistOutputBuff,  sizeof(US_S_PointDistOutputBuff_t));
		Us_StubOutput_PointDist(&US_sPointDistOutputBuff);
#endif

#if(USS_COM_DATA_SHARE_ENBL_DIRECT_ECHO == US_STD_ON)
		(void)memcpy(&US_sSnrDirEchoOutputBuff, &UssComOutputBuffer->sSnsDat_Front_Direct_v,  sizeof(US_S_SnrDirEcho_t));
		Us_StubOutput_DirectEcho(&US_sSnrDirEchoOutputBuff);  /*Direct Echo */
#endif

#if(USS_COM_DATA_SHARE_ENBL_BLOCKAGE_FLAG == US_STD_ON)
		(void)memcpy(&US_sBlockageBitOutputBuff, &UssComOutputBuffer->sBlockageFlags,  sizeof(US_S_BlockageBit_t));  
		Us_StubOutput_BlockageBit(&US_sBlockageBitOutputBuff);  /*public Blockage Info */
#endif

#if(USS_COM_DATA_SHARE_ENBL_ZONE_INFO == US_STD_ON)
		memcpy(&US_sZoneInfoOutputBuffer, &UssComOutputBuffer->sZoneInfo,  sizeof(US_S_ZoneInfo_t));
		Us_StubOutput_ZoneInfo(&US_sZoneInfoOutputBuffer);  /*public Zone Info */
#endif

#if(USS_COM_DATA_SHARE_ENBL_PERIODIC_DIAG == US_STD_ON)
		UssCom_CopyDrvFrqForIPC((UssCom_S_TestDataMux_t *)&UssComOutputBuffer->sTestData.sDataMux);  
		UssCom_CopyRingFrqForIPC((UssCom_S_TestDataMux_t *)&UssComOutputBuffer->sTestData.sDataMux);  
		UssCom_CopyRingTimeForIPC((UssCom_S_TestDataMux_t *)&UssComOutputBuffer->sTestData.sDataMux);  
		UssCom_CopyBlockageCounterIPC((UssCom_S_TestDataMux_t *)&UssComOutputBuffer->sTestData.sDataMux);   
		UssCom_CopySnrTempForIPC((sint16_t *)&UssComOutputBuffer->USSDataCollectionData.Log_SnrTemperature);  
		UssCom_CopySnrPwrSupplyParameters();
		Us_StubOutput_USSPeriodDiagData(&US_sPeriodDiagInfo);
#endif 


#ifndef PLAYBACK_SW_ENABLE
		(void)memcpy(&US_sDataCollectionData, &UssComOutputBuffer->USSDataCollectionData,  sizeof(US_S_USSDataCollectionData_t));
		Us_StubOutput_USSDataCollectionData(&US_sDataCollectionData); /*Data collection */
#endif

#if(USS_COM_DATA_SHARE_ENBL_POINT_DEBUG == US_STD_ON)
      Us_StubOutput_PointDebug(&UssCom_sOutputBuffer.sPntDebugData[ZERO]);
#endif

        /* Copied all data to IPC, let US COM know*/
        UssCom_F_ClearNewDataFlag();
	}

    if((cnt % OUTPUT_CYCLE_200MS) == TWO)  /*every 200ms output once */
	{ 
#if(USS_COM_DATA_SHARE_ENBL_ERR_DIAG == US_STD_ON)
		(void)memcpy(&US_sErrorDiagInfo.ErrorMsg, &UssComOutputBuffer->sDiagnostics,  sizeof(US_S_DiagnosticsOutputBuff_t)); 
		Us_StubOutput_ErrorDiagData(&US_sErrorDiagInfo);
#endif  
 	}

    if((cnt % OUTPUT_CYCLE_200MS) == ONE)  /*every 200ms output once */
	{ 
#if(USS_COM_DATA_SHARE_ENBL_DEBUG_SIGNAL == US_STD_ON)
		Us_StubOutput_DebugMsg(&UssComOutputBuffer->sDebugMsg_v);
#endif
	}

	if(((cnt % OUTPUT_CYCLE_10000MS) == THREE) || ((uint8_t)ME_TRUE == UsComOutputDataOnInit))  
	{
#if(USS_COM_DATA_SHARE_ENBL_PART_NO_VERSION == US_STD_ON)
		UssCom_CopySnrMurataSerNumForIPC();
		UssCom_CopySnrIMESerNumForIPC();	
		UssCom_CopySnrPartNum();
        UssCom_CopyUssVersion();
		Us_StubOutput_USSConstantData(&US_sConstantInfo);
#endif
	}

	UsComOutputDataOnInit = ME_FALSE;
    cnt++;	 
 }


#if(USS_COM_DATA_SHARE_ENBL_POINT_MAP ==  US_STD_ON)
/**
 * /brief This function outputs the final point map output data.
 * 
 * /param ptrPointMapGroup 
 */
/* ===========================================================================
 * Name: Us_StubOutput_PointMap     
 * Remarks:  DD-ID: {E1193958-C60E-484a-8328-094A96B03665}
 * ===========================================================================*/
 static void Us_StubOutput_PointMap(US_S_PointMapGroup_t *ptrPointMapGroup)
 {
	if(ptrPointMapGroup != NULL_PTR_US_POINT_MAP)
	{
#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)
		(void)UsStubOutput_WriteIf_PointMap(ptrPointMapGroup);   /*public Point Map */
#endif	

#if(USS_FEATURE_USS_IO_DATA_ON_CAN == US_STD_ON)
/*Place holder to send data on CAN*/	
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_ETH == US_STD_ON)
/*Place holder to send data on Ethernet*/
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_CBK == US_STD_ON)
/*Place holder to send data though callback*/	
#endif
	}
 }
#endif


#if(USS_COM_DATA_SHARE_ENBL_POINT_DIST ==  US_STD_ON)
/**
 * /brief This function outputs the final point distance output data.
 * 
 * /param ptrPointDist 
 */
 /* ===========================================================================
 * Name: Us_StubOutput_PointDist    
 * Remarks:  DD-ID: {B6BFEC79-2B40-4e33-B307-A2A3DE974602}
 * ===========================================================================*/
 static void Us_StubOutput_PointDist(US_S_PointDistOutputBuff_t *ptrPointDist)
 {
	if(ptrPointDist != NULL_PTR_US_POINT_DIST)
	{
#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)
		(void)UsStubOutput_WriteIf_PointDist(ptrPointDist); /*Distance point map */
#endif	

#if(USS_FEATURE_USS_IO_DATA_ON_CAN == US_STD_ON)
/*Place holder to send data on CAN*/	
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_ETH == US_STD_ON)
/*Place holder to send data on Ethernet*/
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_CBK == US_STD_ON)
/*Place holder to send data though callback*/	
#endif
	}
 }
#endif


#if(USS_COM_DATA_SHARE_ENBL_DIRECT_ECHO ==  US_STD_ON)
/**
 * /brief This function outputs the final direct echo output data
 * 
 * /param ptrDirEcho 
 */
/* ===========================================================================
 * Name: Us_StubOutput_DirectEcho    
 * Remarks:  DD-ID: {E04DC18D-B5AB-45eb-BA8B-0235CE817CB2} 
 * ===========================================================================*/
 static void Us_StubOutput_DirectEcho(US_S_SnrDirEcho_t *ptrDirEcho)
 {
	if(ptrDirEcho != NULL_PTR_US_DIRECT_ECHO)
	{
#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)
		(void)UsStubOutput_WriteIf_DirEcho(ptrDirEcho);  /*Direct Echo */
#endif	

#if(USS_FEATURE_USS_IO_DATA_ON_CAN == US_STD_ON)
/*Place holder to send data on CAN*/	
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_ETH == US_STD_ON)
/*Place holder to send data on Ethernet*/
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_CBK == US_STD_ON)
/*Place holder to send data though callback*/	
#endif
 	}
 }
#endif

		
#if(USS_COM_DATA_SHARE_ENBL_BLOCKAGE_FLAG == US_STD_ON)
/**
 * /brief This function outputs the final direct blockage bit data
 * 
 * /param ptrBlockageBit 
 */
/* ===========================================================================
 * Name: Us_StubOutput_BlockageBit    
 * Remarks:  DD-ID: {6B15FC7F-8439-4630-A108-91D3E7C3261B}
 * ===========================================================================*/
 static void Us_StubOutput_BlockageBit(US_S_BlockageBit_t *ptrBlockageBit)
 {
	if(ptrBlockageBit != NULL_PTR_US_BLOCKAGE_FLAG)
	{
#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)
		(void)UsStubOutput_WriteIf_BlockageBit(ptrBlockageBit);  /*public Blockage Info */
#endif	

#if(USS_FEATURE_USS_IO_DATA_ON_CAN == US_STD_ON)
/*Place holder to send data on CAN*/	
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_ETH == US_STD_ON)
/*Place holder to send data on Ethernet*/
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_CBK == US_STD_ON)
/*Place holder to send data though callback*/	
#endif
 	}
 }
#endif


#if(USS_COM_DATA_SHARE_ENBL_ZONE_INFO == US_STD_ON)
/**
 * /brief This function outputs the final zone info output data
 * 
 * /param ptrZoneInfo 
 */
 static void Us_StubOutput_ZoneInfo(US_S_ZoneInfo_t *ptrZoneInfo)
 {
	if(ptrZoneInfo != NULL_PTR_US_ZONE_INFO)
	{
#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)
	UsStubOutput_WriteIf_ZoneInfo(ptrZoneInfo);  /*public Zone Info */
#endif	

#if(USS_FEATURE_USS_IO_DATA_ON_CAN == US_STD_ON)
/*Place holder to send data on CAN*/	
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_ETH == US_STD_ON)
/*Place holder to send data on Ethernet*/
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_CBK == US_STD_ON)
/*Place holder to send data though callback*/	
#endif
	}
 }	
#endif


#ifndef PLAYBACK_SW_ENABLE
/**
 * /brief This function outputs the final data collection output data.
 * 
 * /param ptrUSSDataCollectionData 
 */
/* ===========================================================================
 * Name: Us_StubOutput_USSDataCollectionData    
 * Remarks:  DD-ID: {FD2FAACB-0D0E-43a5-B46B-3A9234939DDA}
 * ===========================================================================*/
 static void Us_StubOutput_USSDataCollectionData(US_S_USSDataCollectionData_t *ptrUSSDataCollectionData)
 {
	static uint8_t UssCom_PrevDataSequenceNumber = 0xFFu;
	ME_CanDebugRIDStatus_t debugStatus_s;
	SigMgr_Data_ME_CanDebugRIDStatus_t_Get(&debugStatus_s);
	if(NULL_PTR_US_DATA_COLLECTION != ptrUSSDataCollectionData)
	{
		if (UssCom_PrevDataSequenceNumber != UssCom_DataSequenceNumber)
		{
			// Send Debug IPC message only when enabled via RID
        	if (Record_UssDebug_Mode == debugStatus_s.CanDebugMode)
        	{
        	  	#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)
					(void)UsStubOutput_WriteIf_DataCollection(ptrUSSDataCollectionData); /*Data collection */
				#endif
        	}
		#if(USS_FEATURE_USS_IO_DATA_ON_CAN == US_STD_ON)
	     /*Place holder to send data on CAN*/	
	    #endif

	    #if(USS_FEATURE_USS_IO_DATA_ON_ETH == US_STD_ON)
	    /*Place holder to send data on Ethernet*/
	    #endif

	    #if(USS_FEATURE_USS_IO_DATA_ON_CBK == US_STD_ON)
	    /*Place holder to send data though callback*/	
	    #endif
		    	UssCom_PrevDataSequenceNumber = UssCom_DataSequenceNumber;
		}
	}
 }	
#endif


#if(USS_COM_DATA_SHARE_ENBL_ERR_DIAG == US_STD_ON)
/**
 * /brief This function outputs the final error diagnostics output data.
 * 
 * /param ptrErrorDiagData 
 */
/* ===========================================================================
 * Name: Us_StubOutput_ErrorDiagData    
 * Remarks:  DD-ID: {2C3E9375-59E8-40b7-BB68-ED402349BE76} 
 * ===========================================================================*/
 static void Us_StubOutput_ErrorDiagData(US_S_USSErrorDiagData_t *ptrErrorDiagData)
 {
	if(ptrErrorDiagData != NULL_PTR_US_ERROR_DIAG_DATA)
	{
#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)
		(void)UsStubOutput_WriteIf_ErrorDiagData(ptrErrorDiagData);	
#endif	

#if(USS_FEATURE_USS_IO_DATA_ON_CAN == US_STD_ON)
/*Place holder to send data on CAN*/	
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_ETH == US_STD_ON)
/*Place holder to send data on Ethernet*/
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_CBK == US_STD_ON)
/*Place holder to send data though callback*/	
#endif
	}
 }
#endif 


#if(USS_COM_DATA_SHARE_ENBL_PERIODIC_DIAG == US_STD_ON)
/**
 * /brief This function outputs the final period diagnostics output data.
 * 
 * /param ptrUSSPeriodDiagData 
 */
 /* ===========================================================================
 * Name: Us_StubOutput_USSPeriodDiagData    
 * Remarks:  DD-ID: {0D856858-CA03-423b-9FA9-83D7731DEA76}
 * ===========================================================================*/
 static void Us_StubOutput_USSPeriodDiagData(US_S_USSPeriodDiagData_t *ptrUSSPeriodDiagData)
 {
	if(ptrUSSPeriodDiagData != NULL_PTR_US_PERIOD_DATA)
	{
#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)
		(void)UsStubOutput_WriteIf_PeriodDiagData(ptrUSSPeriodDiagData);	
#endif	

#if(USS_FEATURE_USS_IO_DATA_ON_CAN == US_STD_ON)
/*Place holder to send data on CAN*/	
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_ETH == US_STD_ON)
/*Place holder to send data on Ethernet*/
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_CBK == US_STD_ON)
/*Place holder to send data though callback*/	
#endif
 	}
 }		
#endif 


#if(USS_COM_DATA_SHARE_ENBL_PART_NO_VERSION == US_STD_ON)
/**
 * /brief This function outputs the final uss serial/ part number output data.
 * 
 * /param US_sConstantInfo 
 */
/* ===========================================================================
 * Name: Us_StubOutput_USSConstantData    
 * Remarks:  DD-ID: {E6A117A0-FDAF-4aeb-BE80-035553C86815}
 * ===========================================================================*/
 static void Us_StubOutput_USSConstantData(US_S_USSConstantData_t *US_sConstantInfo_ptr)
 {
 	if(US_sConstantInfo_ptr != NULL_PTR_US_CONSTANT_DATA)
	{
#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)
		(void)UsStubOutput_WriteIf_ConstantData(US_sConstantInfo_ptr);	
#endif	

#if(USS_FEATURE_USS_IO_DATA_ON_CAN == US_STD_ON)
/*Place holder to send data on CAN*/	
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_ETH == US_STD_ON)
/*Place holder to send data on Ethernet*/
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_CBK == US_STD_ON)
/*Place holder to send data though callback*/	
#endif
	}
 }
#endif


#if(USS_COM_DATA_SHARE_ENBL_ODOMETRY_DATA == US_STD_ON)
/**
 * /brief This function outputs the final odometry output data.
 * 
 * /param ptrOdometryData 
 */
 /* ===========================================================================
 * Name: Us_StubOutput_OdometryData     
 * Remarks:  DD-ID: {1C0AA908-59A9-4d76-BA70-E108376F7BB0} 
 * ===========================================================================*/
 static void  Us_StubOutput_OdometryData(UssCom_S_OdometryData_t *ptrOdometryData) 
 {
 	if(ptrOdometryData != NULL_PTR_US_ODOMETRY_DATA)
	{
#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)
		(void)(*ptrOdometryData);	
#endif	

#if(USS_FEATURE_USS_IO_DATA_ON_CAN == US_STD_ON)
/*Place holder to send data on CAN*/	
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_ETH == US_STD_ON)
/*Place holder to send data on Ethernet*/
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_CBK == US_STD_ON)
/*Place holder to send data though callback*/	
#endif
	}
 }
#endif


#if(USS_COM_DATA_SHARE_ENBL_DEBUG_SIGNAL == US_STD_ON)
/**
 * /brief This function outputs the final unsigned debug output data.
 * 
 * /param ptrsDebugMsg 
 */
/* ===========================================================================
 * Name: Us_StubOutput_DebugMsg    
 * Remarks:  DD-ID: {840B4021-7697-4e3f-9744-758AF076E2C2}
 * ===========================================================================*/
 static void Us_StubOutput_DebugMsg(US_S_DebugMsg_t  *ptrsDebugMsg)
 {
	ME_CanDebugRIDStatus_t debugStatus_s;
	SigMgr_Data_ME_CanDebugRIDStatus_t_Get(&debugStatus_s);
	if(ptrsDebugMsg != NULL_PTR_US_DEBUG_SIGNAL)
	{
#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)
        // Send Debug IPC message only when enabled via RID
        if (Record_UssDebug_Mode == debugStatus_s.CanDebugMode)
		{
			(void)UsStubOutput_WriteIf_DebugMsg(ptrsDebugMsg);
		}	  
#endif	

#if(USS_FEATURE_USS_IO_DATA_ON_CAN == US_STD_ON)
/*Place holder to send data on CAN*/
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_ETH == US_STD_ON)
/*Place holder to send data on Ethernet*/
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_CBK == US_STD_ON)
/*Place holder to send data though callback*/	
#endif
	}
 }
#endif




#if(USS_COM_DATA_SHARE_ENBL_POINT_DEBUG == US_STD_ON)
/**
 * /brief This function outputs the final point debug output data.
 * 
 * /param ptrsPntDebugData 
 */
 //comment out extern bool_t SigMgr_PpPntDebugData_USS_S_PntDebugDataOutput_t_Put(USS_S_PntDebugDataOutput_t *data);
 /* ===========================================================================
 * Name: Us_StubOutput_PointDebug    
 * Remarks:  DD-ID: {E3D74299-2CCF-4061-8CC2-4CDCB629906C}
 * ===========================================================================*/
 static void Us_StubOutput_PointDebug(UssCom_S_PntDebugData_t  *ptrsPntDebugData)
 {
	if(ptrsPntDebugData != NULL_PTR_US_POINT_DEBUG_DATA)
	{
#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)	
        /* DOES NOT EXIST IN BSW LAYER!! wait for it to exist first */
        //UsStubOutput_WriteIf_PntDebugData((USS_S_PntDebugDataOutput_t*)ptrsPntDebugData);
#endif	

#if(USS_FEATURE_USS_IO_DATA_ON_CAN == US_STD_ON)
/*Place holder to send data on CAN*/
		Rte_PntDebugData_0_MsgCopy((uint8_t*)&ptrsPntDebugData[ZERO]);
		Rte_PntDebugData_1_MsgCopy((uint8_t*)&ptrsPntDebugData[ONE]);
		Rte_PntDebugData_2_MsgCopy((uint8_t*)&ptrsPntDebugData[TWO]);
		Rte_PntDebugData_3_MsgCopy((uint8_t*)&ptrsPntDebugData[THREE]);	
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_ETH == US_STD_ON)
/*Place holder to send data on Ethernet*/
#endif

#if(USS_FEATURE_USS_IO_DATA_ON_CBK == US_STD_ON)
/*Place holder to send data though callback*/	
#endif	
 	}
 }
#endif


/**
 * /brief This function request to respective core to turn on USS high side driver channelA/0
 * 
 * /param on 
 */
/* ===========================================================================
 * Name: US_Com_ReqHsdPwrChannel_A   
 * Remarks:  DD-ID: {06985EF4-23E5-4c3e-A80E-F7383CE4E113}
 * ===========================================================================*/
void US_Com_ReqHsdPwrChannel_A(bool on)
{
	/*Limit check for power enable*/
	Dsi3BusPowerReq.USS_PWR_EN_A = (uint8_t)on;
	(void)SigMgr_Data_USS_PowerSelect_t_Put(&Dsi3BusPowerReq);
}


/**
 * /brief This function request to respective core to turn on USS high side driver channelB/1
 * 
 * /param on 
 */
/* ===========================================================================
 * Name: US_Com_ReqHsdPwrChannel_B   
 * Remarks:  DD-ID: {3DC93E00-8EBD-468a-A449-08B6CF8D2D4B}
 * ===========================================================================*/
void US_Com_ReqHsdPwrChannel_B(bool on)
{
	/*Limit check for power enable*/
	Dsi3BusPowerReq.USS_PWR_EN_B =(uint8_t) on;
	(void)SigMgr_Data_USS_PowerSelect_t_Put(&Dsi3BusPowerReq);
}


/***************************************************************************************************************/

/**
 * /brief This function invoked periodically to output the data
 * 
 */
/* ===========================================================================
 * Name: UssCom_F_OutputDataShareMain    
 * Remarks:  DD-ID: {D59EC4A0-42C2-4a9c-9421-A40C3611FF29}
 * ===========================================================================*/
void UssCom_F_OutputDataShareMain(void)
{
	USSCom_F_OutputDataBuffer_v();
}

#if(USS_COM_DATA_SHARE_ENBL_PERIODIC_DIAG == US_STD_ON)
	/*===========================================================================
	* /brief Function to Driving Frequency from Output buffer to the IPC shared structure
	*
	* /param UssCom_S_TestDataMux_t *
	* /param none
	* /return none
	* /remarks
	*/
	/* ===========================================================================
	* Name:	 UssCom_CopyDrvFrqForIPC
	* Remarks:  DD-ID: {1E66DE91-9DA6-4fd4-88EF-6EFB9E2C2C13}
	* ===========================================================================*/
	static void UssCom_CopyDrvFrqForIPC(UssCom_S_TestDataMux_t *Data)
	{
		US_S_DrivingFrequency_t  *pUS_sDrivingFrequency = &US_sPeriodDiagInfo.SnrDrvFreq;

		pUS_sDrivingFrequency->uDrvFreq_FSR = Data[US_D_SENSOR_FSR].uDrvFreq;
		pUS_sDrivingFrequency->uDrvFreq_FOR = Data[US_D_SENSOR_FOR].uDrvFreq;
		pUS_sDrivingFrequency->uDrvFreq_FIR = Data[US_D_SENSOR_FIR].uDrvFreq;
		pUS_sDrivingFrequency->uDrvFreq_FIL = Data[US_D_SENSOR_FIL].uDrvFreq;
		pUS_sDrivingFrequency->uDrvFreq_FOL = Data[US_D_SENSOR_FOL].uDrvFreq;
		pUS_sDrivingFrequency->uDrvFreq_FSL = Data[US_D_SENSOR_FSL].uDrvFreq;
		pUS_sDrivingFrequency->uDrvFreq_RSR = Data[US_D_SENSOR_RSR].uDrvFreq;
		pUS_sDrivingFrequency->uDrvFreq_ROR = Data[US_D_SENSOR_ROR].uDrvFreq;
		pUS_sDrivingFrequency->uDrvFreq_RIR = Data[US_D_SENSOR_RIR].uDrvFreq;
		pUS_sDrivingFrequency->uDrvFreq_RIL = Data[US_D_SENSOR_RIL].uDrvFreq;
		pUS_sDrivingFrequency->uDrvFreq_ROL = Data[US_D_SENSOR_ROL].uDrvFreq;
		pUS_sDrivingFrequency->uDrvFreq_RSL = Data[US_D_SENSOR_RSL].uDrvFreq;

	}

	/*===========================================================================
	* /brief Function to copy Ring Frequency from Output buffer to the IPC shared structure
	*
	* /param UssCom_S_TestDataMux_t *
	* /param none
	* /return none
	* /remarks
	*/
	/* ===========================================================================
	* Name:	 UssCom_CopyRingFrqForIPC
	* Remarks:  DD-ID: {3333FC47-7022-4bde-A81C-82543768F3E6}
	* ===========================================================================*/
	static void UssCom_CopyRingFrqForIPC(UssCom_S_TestDataMux_t *Data)
	{
		US_S_RigningFrequency_t *pUS_sRigningFrequency = &US_sPeriodDiagInfo.SnrRingFreq;
		
		pUS_sRigningFrequency->uRingFreq_FSR = Data[US_D_SENSOR_FSR].uRingFreq;
		pUS_sRigningFrequency->uRingFreq_FOR = Data[US_D_SENSOR_FOR].uRingFreq;
		pUS_sRigningFrequency->uRingFreq_FIR = Data[US_D_SENSOR_FIR].uRingFreq;
		pUS_sRigningFrequency->uRingFreq_FIL = Data[US_D_SENSOR_FIL].uRingFreq;
		pUS_sRigningFrequency->uRingFreq_FOL = Data[US_D_SENSOR_FOL].uRingFreq;
		pUS_sRigningFrequency->uRingFreq_FSL = Data[US_D_SENSOR_FSL].uRingFreq;
		pUS_sRigningFrequency->uRingFreq_RSR = Data[US_D_SENSOR_RSR].uRingFreq;
		pUS_sRigningFrequency->uRingFreq_ROR = Data[US_D_SENSOR_ROR].uRingFreq;
		pUS_sRigningFrequency->uRingFreq_RIR = Data[US_D_SENSOR_RIR].uRingFreq;
		pUS_sRigningFrequency->uRingFreq_RIL = Data[US_D_SENSOR_RIL].uRingFreq;
		pUS_sRigningFrequency->uRingFreq_ROL = Data[US_D_SENSOR_ROL].uRingFreq;
		pUS_sRigningFrequency->uRingFreq_RSL = Data[US_D_SENSOR_RSL].uRingFreq;

	}

	/*===========================================================================
	* /brief Function to copy Ring Time from Output buffer to the IPC shared structure
	*
	* /param UssCom_S_TestDataMux_t *
	* /param none
	* /return none
	* /remarks
	*/
	/* ===========================================================================
	* Name:	 UssCom_CopyRingTimeForIPC
	* Remarks:  DD-ID: {1A3AB8F6-E0AD-4ed6-B890-8A43F67BC378}
	* ===========================================================================*/
	static void UssCom_CopyRingTimeForIPC(UssCom_S_TestDataMux_t *Data)
	{
		US_S_RigningTime_t *pUS_sRigningTime = &US_sPeriodDiagInfo.SnrRingTime;

		pUS_sRigningTime->uRingTime_FSR = Data[US_D_SENSOR_FSR].uRingTime;
		pUS_sRigningTime->uRingTime_FOR = Data[US_D_SENSOR_FOR].uRingTime;
		pUS_sRigningTime->uRingTime_FIR = Data[US_D_SENSOR_FIR].uRingTime;
		pUS_sRigningTime->uRingTime_FIL = Data[US_D_SENSOR_FIL].uRingTime;
		pUS_sRigningTime->uRingTime_FOL = Data[US_D_SENSOR_FOL].uRingTime;
		pUS_sRigningTime->uRingTime_FSL = Data[US_D_SENSOR_FSL].uRingTime;
		pUS_sRigningTime->uRingTime_RSR = Data[US_D_SENSOR_RSR].uRingTime;
		pUS_sRigningTime->uRingTime_ROR = Data[US_D_SENSOR_ROR].uRingTime;
		pUS_sRigningTime->uRingTime_RIR = Data[US_D_SENSOR_RIR].uRingTime;
		pUS_sRigningTime->uRingTime_RIL = Data[US_D_SENSOR_RIL].uRingTime;
		pUS_sRigningTime->uRingTime_ROL = Data[US_D_SENSOR_ROL].uRingTime;
		pUS_sRigningTime->uRingTime_RSL = Data[US_D_SENSOR_RSL].uRingTime;

	}

/**
 * /brief This function copies blockage counter diagnostics data
 * 
 */
/* ===========================================================================
 * Name: UssCom_CopyBlockageCounterIPC    
 * Remarks:  DD-ID: {E70770CA-0A95-43f2-BD97-1A2D84848AE3}
 * ===========================================================================*/
	static void UssCom_CopyBlockageCounterIPC(UssCom_S_TestDataMux_t *Data)
	{
		US_S_uBlockageClrCnt_t *pUS_uBlockageClrCnt = &US_sPeriodDiagInfo.BlockageClrCnt;
		US_S_uBlockageSetCnt_t *pUS_uBlockageSetCnt = &US_sPeriodDiagInfo.BlockageSetCnt;

		pUS_uBlockageClrCnt->uBlockageClrCnt_FSR = Data[US_D_SENSOR_FSR].uBlockageClrCnt; 
		pUS_uBlockageClrCnt->uBlockageClrCnt_FOR = Data[US_D_SENSOR_FOR].uBlockageClrCnt;
		pUS_uBlockageClrCnt->uBlockageClrCnt_FIR = Data[US_D_SENSOR_FIR].uBlockageClrCnt;
		pUS_uBlockageClrCnt->uBlockageClrCnt_FIL = Data[US_D_SENSOR_FIL].uBlockageClrCnt;
		pUS_uBlockageClrCnt->uBlockageClrCnt_FOL = Data[US_D_SENSOR_FOL].uBlockageClrCnt;
		pUS_uBlockageClrCnt->uBlockageClrCnt_FSL = Data[US_D_SENSOR_FSL].uBlockageClrCnt;
		pUS_uBlockageClrCnt->uBlockageClrCnt_RSR = Data[US_D_SENSOR_RSR].uBlockageClrCnt;
		pUS_uBlockageClrCnt->uBlockageClrCnt_ROR = Data[US_D_SENSOR_ROR].uBlockageClrCnt;
		pUS_uBlockageClrCnt->uBlockageClrCnt_RIR = Data[US_D_SENSOR_RIR].uBlockageClrCnt;
		pUS_uBlockageClrCnt->uBlockageClrCnt_RIL = Data[US_D_SENSOR_RIL].uBlockageClrCnt;
		pUS_uBlockageClrCnt->uBlockageClrCnt_ROL = Data[US_D_SENSOR_ROL].uBlockageClrCnt;
		pUS_uBlockageClrCnt->uBlockageClrCnt_RSL = Data[US_D_SENSOR_RSL].uBlockageClrCnt;

		pUS_uBlockageSetCnt->uBlockageSetCnt_FSR = Data[US_D_SENSOR_FSR].uBlockageSetCnt; 
		pUS_uBlockageSetCnt->uBlockageSetCnt_FOR = Data[US_D_SENSOR_FOR].uBlockageSetCnt;
		pUS_uBlockageSetCnt->uBlockageSetCnt_FIR = Data[US_D_SENSOR_FIR].uBlockageSetCnt;
		pUS_uBlockageSetCnt->uBlockageSetCnt_FIL = Data[US_D_SENSOR_FIL].uBlockageSetCnt;
		pUS_uBlockageSetCnt->uBlockageSetCnt_FOL = Data[US_D_SENSOR_FOL].uBlockageSetCnt;
		pUS_uBlockageSetCnt->uBlockageSetCnt_FSL = Data[US_D_SENSOR_FSL].uBlockageSetCnt;
		pUS_uBlockageSetCnt->uBlockageSetCnt_RSR = Data[US_D_SENSOR_RSR].uBlockageSetCnt;
		pUS_uBlockageSetCnt->uBlockageSetCnt_ROR = Data[US_D_SENSOR_ROR].uBlockageSetCnt;
		pUS_uBlockageSetCnt->uBlockageSetCnt_RIR = Data[US_D_SENSOR_RIR].uBlockageSetCnt;
		pUS_uBlockageSetCnt->uBlockageSetCnt_RIL = Data[US_D_SENSOR_RIL].uBlockageSetCnt;
		pUS_uBlockageSetCnt->uBlockageSetCnt_ROL = Data[US_D_SENSOR_ROL].uBlockageSetCnt;
		pUS_uBlockageSetCnt->uBlockageSetCnt_RSL = Data[US_D_SENSOR_RSL].uBlockageSetCnt;
	} 

	/*===========================================================================
	* /brief Function to copy Sensor temperature from Output buffer to the IPC shared structure
	*
	* /param uint16_t*
	* /param none
	* /return none
	* /remarks
	*/
	/* ===========================================================================
	* Name:	 UssCom_CopySnrTempForIPC
	* Remarks:  DD-ID: {2DBF8C21-B74B-437d-92FD-E99760A30A27}
	* ===========================================================================*/
	static void UssCom_CopySnrTempForIPC(sint16_t* Data)
	{
		US_S_SensorTemp_t *pUS_sSensorTemp = &US_sPeriodDiagInfo.SnrTemperature;
		pUS_sSensorTemp->sSensorTemp_FSR = Data[US_D_SENSOR_FSR];
		pUS_sSensorTemp->sSensorTemp_FOR = Data[US_D_SENSOR_FOR];
		pUS_sSensorTemp->sSensorTemp_FIR = Data[US_D_SENSOR_FIR];
		pUS_sSensorTemp->sSensorTemp_FIL = Data[US_D_SENSOR_FIL];
		pUS_sSensorTemp->sSensorTemp_FOL = Data[US_D_SENSOR_FOL];
		pUS_sSensorTemp->sSensorTemp_FSL = Data[US_D_SENSOR_FSL];
		pUS_sSensorTemp->sSensorTemp_RSR = Data[US_D_SENSOR_RSR];
		pUS_sSensorTemp->sSensorTemp_ROR = Data[US_D_SENSOR_ROR];
		pUS_sSensorTemp->sSensorTemp_RIR = Data[US_D_SENSOR_RIR];
		pUS_sSensorTemp->sSensorTemp_RIL = Data[US_D_SENSOR_RIL];
		pUS_sSensorTemp->sSensorTemp_ROL = Data[US_D_SENSOR_ROL];
		pUS_sSensorTemp->sSensorTemp_RSL = Data[US_D_SENSOR_RSL];
	}

	/*===========================================================================
	* /brief Copy Power Supply Parameter into IPC shared structure
	*
	* /param US_S_SnrPowerSupply_t *
	* /param none
	* /return none
	* /remarks
	*/
	/* ===========================================================================
	* Name:	 UssCom_CopySnrPwrSupplyParameters
	* Remarks:  DD-ID: {9F78A9E2-6D02-4b78-AB60-43CCB3BA9EA8}
	* ===========================================================================*/
	static void UssCom_CopySnrPwrSupplyParameters(void)
	{
		US_sPeriodDiagInfo.SnrPwr.uUSSPowerAMonVtg = UssHsd_F_psGet_Pwr_Vtg_mV((uint8_t)Uss_Hsd_Channel_PWR_A);
		US_sPeriodDiagInfo.SnrPwr.uUSSPowerBMonVtg = UssHsd_F_psGet_Pwr_Vtg_mV((uint8_t)Uss_Hsd_Channel_PWR_B);
		US_sPeriodDiagInfo.SnrPwr.uUSSPowerCMonVtg = 12000; /*Currently not used populating typical values*/
		/* Only current for PWR channel A is considered */
		US_sPeriodDiagInfo.SnrPwr.uUSSPowerIS1Current = UssHsd_F_psGet_Pwr_Ct_mA((uint8_t)Uss_Hsd_Channel_PWR_A);
		US_sPeriodDiagInfo.SnrPwr.uUSSPowerIS2Current = UssHsd_F_psGet_Pwr_Ct_mA((uint8_t)Uss_Hsd_Channel_PWR_B); /*Currently not used populating typical values*/
	}
#endif /*End of USS_COM_DATA_SHARE_ENBL_PERIODIC_DIAG*/


#if(USS_COM_DATA_SHARE_ENBL_PART_NO_VERSION == US_STD_ON)
/*===========================================================================
 * /brief Copy Murata serial numbers into IPC shared structure
 *
 * /param uint32_t*
 * /param none
 * /return none
 * /remarks
 */
/* ===========================================================================
 * Name:	 UssCom_CopySnrMurataSerNumForIPC
 * Remarks:  DD-ID: {33DE4D43-3438-4215-A49C-2203D201E5B3}
 * Traceability to source Code: Req.-ID: 15737491
 * Req.-ID:15737569
 * Req.-ID:15737585
 * Req.-ID:15737731
 * Req.-ID:15737899
 * Req.-ID:15738249
 * Req.-ID:15738329
 * Req.-ID:15738343
 * Req.-ID:15738356
 * Req.-ID:15738372
 * Req.-ID:15738387
 * Req.-ID:15738393
 * ===========================================================================*/
static void UssCom_CopySnrMurataSerNumForIPC(void)
{
	uint64_t *pMurataSerialNum = US_SnrCfg_F_Get_uNewSnrIDList();
	US_S_SnrMurataSerialNum_t *pUS_sSnrMurataSerialNum = &US_sConstantInfo.SensorMurataSerialNum;
	
	pUS_sSnrMurataSerialNum->uSnrMurataSerialNum_FSR =  pMurataSerialNum[US_D_SENSOR_FSR];
	pUS_sSnrMurataSerialNum->uSnrMurataSerialNum_FOR =  pMurataSerialNum[US_D_SENSOR_FOR];
	pUS_sSnrMurataSerialNum->uSnrMurataSerialNum_FIR =  pMurataSerialNum[US_D_SENSOR_FIR];
	pUS_sSnrMurataSerialNum->uSnrMurataSerialNum_FIL =  pMurataSerialNum[US_D_SENSOR_FIL];
	pUS_sSnrMurataSerialNum->uSnrMurataSerialNum_FOL =  pMurataSerialNum[US_D_SENSOR_FOL];
	pUS_sSnrMurataSerialNum->uSnrMurataSerialNum_FSL =  pMurataSerialNum[US_D_SENSOR_FSL];
	pUS_sSnrMurataSerialNum->uSnrMurataSerialNum_RSR =  pMurataSerialNum[US_D_SENSOR_RSR];
	pUS_sSnrMurataSerialNum->uSnrMurataSerialNum_ROR =  pMurataSerialNum[US_D_SENSOR_ROR];
	pUS_sSnrMurataSerialNum->uSnrMurataSerialNum_RIR =  pMurataSerialNum[US_D_SENSOR_RIR];
	pUS_sSnrMurataSerialNum->uSnrMurataSerialNum_RIL =  pMurataSerialNum[US_D_SENSOR_RIL];
	pUS_sSnrMurataSerialNum->uSnrMurataSerialNum_ROL =  pMurataSerialNum[US_D_SENSOR_ROL];
	pUS_sSnrMurataSerialNum->uSnrMurataSerialNum_RSL =  pMurataSerialNum[US_D_SENSOR_RSL];
}


/*===========================================================================
 * /brief Copy IME serial numbers into IPC shared structure
 *
 * /param uint32_t*
 * /param none
 * /return none
 * /remarks
 */
/* ===========================================================================
 * Name:	 UssCom_CopySnrIMESerNumForIPC
 * Remarks:  DD-ID: {D075F54A-C253-4cf8-9A29-6C423B9DEA21}
 * Traceability to source Code: Req.-ID: 15738558
 * Req.-ID:15738620
 * Req.-ID:15738630
 * Req.-ID:15738632
 * Req.-ID:15738655
 * Req.-ID:15738657
 * Req.-ID:15738668
 * Req.-ID:15738670
 * Req.-ID:15738672
 * Req.-ID:15738674
 * Req.-ID:15738676
 * Req.-ID:15738678
 * ===========================================================================*/
static void UssCom_CopySnrIMESerNumForIPC(void)
{
	uint32_t *pIMESerialNum = US_SnrCfg_F_Get_uSnrIDList();
	US_S_SnrIMESerialNum_t *pUS_sSnrIMESerialNum = &US_sConstantInfo.SensorIMESerialNum;
	
	pUS_sSnrIMESerialNum->uSnrIMESerialNum_FSR = pIMESerialNum[US_D_SENSOR_FSR];
	pUS_sSnrIMESerialNum->uSnrIMESerialNum_FOR = pIMESerialNum[US_D_SENSOR_FOR];
	pUS_sSnrIMESerialNum->uSnrIMESerialNum_FIR = pIMESerialNum[US_D_SENSOR_FIR];
	pUS_sSnrIMESerialNum->uSnrIMESerialNum_FIL = pIMESerialNum[US_D_SENSOR_FIL];
	pUS_sSnrIMESerialNum->uSnrIMESerialNum_FOL = pIMESerialNum[US_D_SENSOR_FOL];
	pUS_sSnrIMESerialNum->uSnrIMESerialNum_FSL = pIMESerialNum[US_D_SENSOR_FSL];
	pUS_sSnrIMESerialNum->uSnrIMESerialNum_RSR = pIMESerialNum[US_D_SENSOR_RSR];
	pUS_sSnrIMESerialNum->uSnrIMESerialNum_ROR = pIMESerialNum[US_D_SENSOR_ROR];
	pUS_sSnrIMESerialNum->uSnrIMESerialNum_RIR = pIMESerialNum[US_D_SENSOR_RIR];
	pUS_sSnrIMESerialNum->uSnrIMESerialNum_RIL = pIMESerialNum[US_D_SENSOR_RIL];
	pUS_sSnrIMESerialNum->uSnrIMESerialNum_ROL = pIMESerialNum[US_D_SENSOR_ROL];
	pUS_sSnrIMESerialNum->uSnrIMESerialNum_RSL = pIMESerialNum[US_D_SENSOR_RSL];
}

/*===========================================================================
 * /brief Copy the Sensor Part numbers into IPC shared structure
 *
 * /param none
 * /param none
 * /return none
 * /remarks
 */
/* ===========================================================================
 * Name:	 UssCom_CopySnrPartNum
 * Remarks:  DD-ID: {A176A075-3822-4345-9509-788F25807524}
 * Traceability to source Code: Req.-ID: 15735934
 * Req.-ID:15736713
 * ===========================================================================*/
static void UssCom_CopySnrPartNum(void)
{
	US_S_USSPartNumberData_t *pUS_sUSSPartNumberData = &US_sConstantInfo.SensorPartNum;
 	uint8_t cnt,len,*pSnrPN,SensorPN[2][30];
    uint8_t *SnrType = UssCtrl_psGetSensorType();
	
    pSnrPN = US_SnrCfg_F_Get_SnrPN();
    if(pSnrPN != NULL)
	{   
        len = pSnrPN[0u] + 1u; 
        len=(len>30u)?30u:len;		
		(void)memcpy(SensorPN[0u],pSnrPN,len);  
        pSnrPN[len] = (pSnrPN[len]>29u)?29u:pSnrPN[len];		
		(void)memcpy(SensorPN[1],(pSnrPN + len),pSnrPN[len]+1u);  
	}
	else
	{
		(void)memset(SensorPN,0,60);  /*PRQA S 0315,1291 */
		SensorPN[0][0] = 13u;
		SensorPN[1][0] = 13u;
	}
	for(cnt =0;cnt<12u;cnt++)
	{
	    if(SnrType[cnt] == 0u)
		{
		   (void)memcpy((uint8_t*)&pUS_sUSSPartNumberData->uUSSPartNum_FSR + (cnt * SensorPN[0][0]),&SensorPN[0][1],SensorPN[0][0]); 
		}
		else
		{
		  (void) memcpy((uint8_t*)&pUS_sUSSPartNumberData->uUSSPartNum_FSR + (cnt * SensorPN[1][0]),&SensorPN[1][1],SensorPN[1][0]);   
		}
	}
}

/*===========================================================================
 * /brief Copy the USS verions into IPC shared structure
 *
 * /param none
 * /param none
 * /return none
 * /remarks
 */
/* ===========================================================================
 * Name:	 UssCom_CopyUssVersion
 * Remarks:  DD-ID: {01CAFEF6-115B-42a4-BAAE-D92030AC78D4}
 * Traceability to source Code: Req.-ID: 15739669
 * ===========================================================================*/
static void UssCom_CopyUssVersion(void)
{
	US_S_USSVersion_t *pUSS_Ver = &US_sConstantInfo.USS_Ver;
    uint8_t *USS_SwVer  = GetSoftwareVersion();
	pUSS_Ver->US_SnrVer  =  US_SnrCfg_Get_SnrFWVer();
	pUSS_Ver->US_CalVer  =  US_SnrCfg_F_Get_CaliVer();
	pUSS_Ver->US_ModuleVer_YEAR  =  USS_SwVer[ONE];
	pUSS_Ver->US_ModuleVer_WEEK  =  USS_SwVer[TWO];
	pUSS_Ver->US_ModuleVer_DAY  =  USS_SwVer[THREE];
	pUSS_Ver->US_ModuleVer_BUILD  =  USS_SwVer[FOUR];
	
}
#endif

/**
 * /brief Construct a new UsStub_SnrCfg_CmdReq object
 * 
 * /param ptrCmd 
 * /param cmdSize 
 */
/* ===========================================================================
uint8_t UssStubOutput_SnrCfg_CmdReq(uint8_t *ptrCmd, uint8 cmdSize, uint8 snrTuneId)
 * Name: UssStubOutput_SnrCfg_CmdReq     
 * Remarks:  DD-ID: {07946825-D558-4fe3-887F-0340915B9EC1}
 * ===========================================================================*/
uint8_t UssStubOutput_SnrCfg_CmdReq(uint8_t *ptrCmd, uint8 cmdSize, uint8 snrTuneId)
{
uint8_t retLen = 0;
(void)*ptrCmd;
(void)cmdSize;
(void)snrTuneId;
return (retLen);
}

#if(USS_FEATURE_CSM_NOTIFICATION == US_FEATURE_ON)
/**
 * /brief This function inovoked by csm module whenever the csm state changed due to internal csm action.
 * 
 * /param prevState 
 * /param currentState 
 */
/* ===========================================================================
 * Name: UsCsm_Notification_CsmStateChange    
 * Remarks:  DD-ID: {FB2DCF0F-D40F-41d0-9F51-792282167CF1}
 * ===========================================================================*/
 void UsCsm_Notification_CsmStateChange(UsCsm_StateId_Type currentState, UsCsm_StateId_Type prevState, UsCsm_CsmStateChangeReason_Type csmStateChangeReason)
 {  
    (void)prevState;
    SSM_ApplicationStatus_i Status = SSM_APPSTATE_STOPPED_i;
	ME_CanDebugRIDStatus_t debugStatus_s;
	SigMgr_Data_ME_CanDebugRIDStatus_t_Get(&debugStatus_s);

#if(USS_FEATURE_OUTPUT_CSM_STATE_CHANGE_REASON == US_FEATURE_ON)
	US_S_CsmStateChangeReason_Type outCsmStateChangeReason;
#endif

	switch(currentState)
	{
		case US_CSM_STATE_ID_UN_INIT :
			Status = SSM_APPSTATE_UNINIT_i;
		break;

		case US_CSM_STATE_ID_INIT:
			Status = SSM_APPSTATE_INIT_i;
		break;

		case US_CSM_STATE_ID_ACTIVE:
		case US_CSM_STATE_ID_PRE_SAFE_STATE_1:
		case US_CSM_STATE_ID_PRESHUTDOWN:
		case US_CSM_STATE_ID_PREDEGRADE:
		case US_CSM_STATE_ID_SAFE_STATE_1:
		case US_CSM_STATE_ID_DEGRADED:
			Status = SSM_APPSTATE_RUNNING_i;
		break;
		
		/*comment out case US_CSM_STATE_ID_SAFE_STATE_1:
comment out 		case US_CSM_STATE_ID_DEGRADED:
comment out 			Status = SSM_APPSTATE_DEGRADED_i; 
		break;*/ /*Application wise degraded is also running*/

		case US_CSM_STATE_ID_SHUTDOWN:
			Status = SSM_APPSTATE_STOPPED_i; 
		break;

		default:
                                             /*empty */
		break;
	}
	(void)SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_USS, Status);

#if(USS_FEATURE_OUTPUT_CSM_STATE_CHANGE_REASON == US_FEATURE_ON)
	outCsmStateChangeReason.CsmStateCurrent = (uint8_t)currentState;
	outCsmStateChangeReason.CsmStatePreviuos =  (uint8_t)prevState;
	outCsmStateChangeReason.CsmLocalModuleId = ((uint8_t)csmStateChangeReason.LocalModuleId);
	outCsmStateChangeReason.CsmLocalModuleInstanceId = ((uint8_t)csmStateChangeReason.InstanceId);
	outCsmStateChangeReason.CsmLocalErrOrEventId = ((uint8_t)csmStateChangeReason.LocalErrId);
	outCsmStateChangeReason.CsmLocalErrOrEventState = ((uint8_t)csmStateChangeReason.LocalErrState);
if (Record_UssDebug_Mode == debugStatus_s.CanDebugMode)
{
	#if(USS_FEATURE_USS_IO_DATA_ON_IPC == US_STD_ON)
		(void)UsStubOutput_WriteIf_CsmStateChangeReason(&outCsmStateChangeReason);
	#endif
}

#endif/*USS_FEATURE_OUTPUT_CSM_STATE_CHANGE_REASON*/
 }
#endif /*END OF USS_FEATURE_CSM_NOTIFICATION*/
