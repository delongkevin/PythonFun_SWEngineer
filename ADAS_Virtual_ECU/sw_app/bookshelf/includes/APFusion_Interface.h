//--------------------------------------------------------------------------
/// @file APFusion_Interface.h
/// @brief Contains Interfaces for APFusion input and output structs
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Rohit Borse (rohit.borse@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef APA_USSOM_FPA_INOUT_DEFS_
#define APA_USSOM_FPA_INOUT_DEFS_

#include "LwSpd_SimulinkAdaptation.h"
#include "CrossplatformCommon.h"

typedef float Rect[4];
typedef Rect    Rectangle;

typedef struct USSObjectPos_s
{
    float32_t X_mm;
    float32_t Y_mm;
    float32_t Z_mm;
}IUSSObjectPos_t;

typedef struct UPASensorV2_s
{
    IUSSObjectPos_t SensorPos;
    float32_t SensorAngle;
}IUPASensorV2_t;

typedef struct IME_US_FiringSensorsOutputBuff_s
{
    uint32_t timestamp;
    uint16_t firingSensors;
} IME_US_FiringSensorsOutputBuff_t;

typedef struct IME_US_SensorFiringModeOutputBuff_s
{
    uint32_t timestamp;
    uint8_t  sensorFiringMode;
} IME_US_SensorFiringModeOutputBuff_t;

typedef struct IMsgCAN1_ME_Diag_1_s
{
    unsigned short Sig_Snr_EEPROM_Fail;
    unsigned short Sig_Snr_High_Voltage;
    unsigned short Sig_Snr_Low_Voltage;
    unsigned short Sig_Snr_RAM_Fail;
} IMsgCAN1_ME_Diag_1_t;

typedef struct IMsgCAN1_ME_Diag_2_s
{
    unsigned char Sig_Disturbance_Detected;
    unsigned char Sig_FW_Inconsistant_Snr;
    unsigned char Sig_ECU_EEPROM_Fail;
    unsigned char Sig_ECU_Low_Voltage;
    unsigned char Sig_ECU_High_Voltage;
    unsigned char Sig_Comm_Snr_Error;
    unsigned short Sig_Snr_Transducer_Error;
    unsigned short Sig_Snr_Abnormal;
    unsigned short Sig_Snr_Blockage;
    unsigned short Sig_Snr_Disconnect;
} IMsgCAN1_ME_Diag_2_t;

typedef struct IMsgCAN1_ME_SnsDat_Front_Direct_s
{
    unsigned short Sig_SnrDat_FSR_Dir1_cm;
    unsigned short Sig_SnrDat_FOR_Dir1_cm;
    unsigned short Sig_SnrDat_FIR_Dir1_cm;
    unsigned short Sig_SnrDat_FIL_Dir1_cm;
    unsigned short Sig_SnrDat_FOL_Dir1_cm;
    unsigned short Sig_SnrDat_FSL_Dir1_cm;
} IMsgCAN1_ME_SnsDat_Front_Direct_t;

typedef struct IMsgCAN1_ME_SnsDat_Front_Direct_2_s
{
    unsigned short Sig_SnrDat_FSR_Dir2_cm;
    unsigned short Sig_SnrDat_FOR_Dir2_cm;
    unsigned short Sig_SnrDat_FIR_Dir2_cm;
    unsigned short Sig_SnrDat_FIL_Dir2_cm;
    unsigned short Sig_SnrDat_FOL_Dir2_cm;
    unsigned short Sig_SnrDat_FSL_Dir2_cm;
} IMsgCAN1_ME_SnsDat_Front_Direct_2_t;

typedef struct IMsgCAN1_ME_SnsDat_FrontPSM_Echoes_s
{
    unsigned short Sig_SnsDat_FSL_Timestamp_us;
    unsigned short Sig_SnsDat_FSL_DirEcho1_cm;
    unsigned short Sig_SnsDat_FSL_DirEcho2_cm;
    unsigned short Sig_SnsDat_FSR_Timestamp_us;     /*TODO-KPK Need to check the signal in DBC*/
    unsigned short Sig_SnsDat_FSR_DirEcho1_cm;
    unsigned short Sig_SnsDat_FSR_DirEcho2_cm;
} IMsgCAN1_ME_SnsDat_FrontPSM_Echoes_t;

typedef struct IMsgCAN1_ME_SnsDat_Rear_Direct_s
{
    unsigned short Sig_SnrDat_RSR_Dir1_cm;
    unsigned short Sig_SnrDat_ROR_Dir1_cm;
    unsigned short Sig_SnrDat_RIR_Dir1_cm;
    unsigned short Sig_SnrDat_RIL_Dir1_cm;
    unsigned short Sig_SnrDat_ROL_Dir1_cm;
    unsigned short Sig_SnrDat_RSL_Dir1_cm;
} IMsgCAN1_ME_SnsDat_Rear_Direct_t;

typedef struct IMsgCAN1_ME_SnsDat_Rear_Direct_2_s
{
    unsigned short Sig_SnrDat_RSR_Dir2_cm;
    unsigned short Sig_SnrDat_ROR_Dir2_cm;
    unsigned short Sig_SnrDat_RIR_Dir2_cm;
    unsigned short Sig_SnrDat_RIL_Dir2_cm;
    unsigned short Sig_SnrDat_ROL_Dir2_cm;
    unsigned short Sig_SnrDat_RSL_Dir2_cm;
} IMsgCAN1_ME_SnsDat_Rear_Direct_2_t;

typedef struct IMsgCAN1_ME_SnsDat_RearSide_Echoes_s
{
    unsigned short Sig_SnsDat_RSL_Timestamp_us;
    unsigned short Sig_SnsDat_RSL_DirEcho1_cm;
    unsigned short Sig_SnsDat_RSL_DirEcho2_cm;
    unsigned short Sig_SnsDat_RSR_Timestamp_us;
    unsigned short Sig_SnsDat_RSR_DirEcho1_cm;
    unsigned short Sig_SnsDat_RSR_DirEcho2_cm;
} IMsgCAN1_ME_SnsDat_RearSide_Echoes_t;

typedef enum IUS_E_ParkingMode_e
{
    APA_US_PARKMODE_STANDBY = 0,
    APA_US_PARKMODE_SCANNING,
    APA_US_PARKMODE_PARKING
} IUS_E_ParkingMode_t;

typedef struct IME_US_S_PointOutputBuff_s
{
    sint16_t x;
    sint16_t y;
    uint8_t  height;
    uint8_t  confidence;
    uint8_t  age;
} IME_US_S_PointOutputBuff_t;

typedef struct IUS_S_PointsMapOutputBuff_s
{
    uint32_t timestamp;
    IME_US_S_PointOutputBuff_t pointMap[96];
} IME_US_PointMapOutputBuff_t;

typedef struct IDistancePointMap_s
{
    IME_US_S_PointOutputBuff_t m_PointOutput;
    IME_US_PointMapOutputBuff_t m_PointMap;
} IDistancePointMap_t;


/* mcu2_1 to mcu2_1 */

typedef struct IUPASensorDataV2_s
{
    IUPASensorV2_t m_sensors[12];
    IME_US_FiringSensorsOutputBuff_t m_FiringSensor;
    IME_US_SensorFiringModeOutputBuff_t m_FiringMode;
    IMsgCAN1_ME_Diag_1_t m_Diag1;
    IMsgCAN1_ME_Diag_2_t m_Diag2;
    IMsgCAN1_ME_SnsDat_Front_Direct_t m_Front_Direct;
    IMsgCAN1_ME_SnsDat_Front_Direct_2_t m_Front_Direct_2;
    IMsgCAN1_ME_SnsDat_FrontPSM_Echoes_t m_FrontPSM_Echoes;
    IMsgCAN1_ME_SnsDat_Rear_Direct_t m_Rear_Direct;
    IMsgCAN1_ME_SnsDat_Rear_Direct_2_t m_Rear_Direct_2;
    IMsgCAN1_ME_SnsDat_RearSide_Echoes_t m_RearSide_Echoes;
    IUS_E_ParkingMode_t m_SetUSSParkingMode;
    IDistancePointMap_t m_DistancePointMap[12];
}IUPASensorDataV2_t;

/* mcu2_1 to mcu2_1, A72 */
/* IKinematicData_t;*/

typedef struct
{
    ROI_TYPE_t roi_type;
    ROI_DIRECTION_t roi_direction;
    float roi_angle_rad;
    Rectangle roi_rect;
    Int2 roi_pts[4];
}IROIRegion;

typedef struct
{
    ParkingSlotType_t PLType;
    float32_t probability;
    float32_t priorprobs[3];
    uint16_t lineCounter;
}IParkingLotType;

typedef struct
{
    Float2 strtpoint;
    Float2 endpoint;
    Float2 Globalstrtpoint;
    Float2 Globalendpoint;
    uint16_t no_pnts;
    uint8_t confidance;
    bool_t valid;
    float32_t angle;
    float32_t length;
    bool_t aligned;
    uint8_t LineID;
}Iparkline;

typedef struct
{
    bool_t IsPLExcist;
    uint8_t status;
    Int2 HeadPt; //start point
    Int2 TailPt; //end point
    Int2 GlobalHeadPt; //start point
    Int2 GlobalTailPt; //end point
    float32_t LineLength;
    float32_t LineAngle;
    float32_t lineDetectionScore;
    ROI_DIRECTION_t Linedirection;
} IDETParkLine;

typedef struct
{
	bool_t valid;
    Float2 Vertices[4];
    Float2 GlobalVertices[4];
    uint8_t SlotID;
}IQuadrilateral;


/* Not used in latest code at Fisker_APV3_V1.4_Emb. This needs to be removed */
typedef struct
{
    IDETParkLine v_LeftLine;
    IDETParkLine v_RightLine;
    Iparkline* m_jobLeftLinesQueue;
    Iparkline* m_jobRightLinesQueue;
    IQuadrilateral* m_jobLeftParkingStalls;
    IQuadrilateral* m_jobRightParkingStalls;
    IQuadrilateral* m_jobLockedParkingStall;
    sint8_t m_jobLeftGapIndex;
    sint8_t m_jobRightGapIndex;
    IParkingLotType m_jobLeftParkType;
    IParkingLotType m_jobRightParkType;
    IROIRegion m_jobSearchingWindow1;
    IROIRegion m_jobSearchingWindow2;
}JobPLDOutput;


typedef struct IParkingSlotData_s
{
   Float2 Vertices[4];
   ParkingSlotType_t m_SlotType;
   SlotSide_t m_SlotSide;
   ParkingSlotID_t m_SlotID;
   bool_t m_isSlotValid_b;
}IParkingSlotData_t;


/* A72 to mcu2_1 and mcu1_0*/

typedef struct IJobPLDOutput_s
{
    bool_t isPLDInitSuccess_b;                  //PLD Success/Fail
    IParkingSlotData_t stPLDParkingSlotData[6];    //Left and right park slot coordinates info in image coordinates sent to FPA module
    IParkingSlotData_t stPLDLockedSlotData;        //Locked + tracked slot coordinate info in image coordinates sent to FPA module
}IJobPLDOutput_t;

typedef struct
{
    Int2 C1_tvg;
    Int2 C2_tvg;
    Int2 C3_tvg;
    Int2 C4_tvg;
}IParkingSlotCoordinatesImage;

typedef struct
{
    Float2 C1_Real;
    Float2 C2_Real;
    Float2 C3_Real;
    Float2 C4_Real;
}IParkingSlotCoordinatesWorld;


/* A72 to mcu2_1 */
typedef struct IParkingSlotInformation_s
{
	bool_t m_SelectedSlot;
	ParkingSlotType_t m_SlotType;
	SlotSide_t m_SlotSide;
	ParkingSlotID_t m_ParkingSlotID;
	ParkINStyle_t m_ParkingDirection;
	IParkingSlotCoordinatesWorld m_ParkingCoordinates_Real;
	IParkingSlotCoordinatesWorld m_ParkingCoordinates_Global_Locked;
	IParkingSlotCoordinatesImage m_ParkingCoordinates_tvg;
}IParkingSlotInformation_t;

typedef struct ISTRectangle_s

{
	Float2 Vertices[4];
	Float2 openCenter;
	float32_t Angle;
	float32_t Width;
	float32_t Depth;
}ISTRectangle_t;

struct IUsblSlot
{
	Float2 Vertices[4];
	Float2 GlobalVertices[4];
	bool_t valid;
	SensorType_t SensType;
	uint8_t SVSSlotID;
	uint8_t USSSlotID;
	ISTRectangle_t FittedRect;
}; 

/* mcu2_1 to mcu2_1 */
typedef struct IFPAInfoToVC_s
{
	IParkingSlotData_t stFPALockedSlotData;		//VehicleCoordinates and other details 
	float32_t LockedSlotWidth;
	float32_t LockedSlotDepth;
	ParkOutStyle_t parkOutStyle;
}IFPAInfoToVC_t;

/* mcu2_1 to A72 */
typedef struct IFPAInfoToPLD_s
{
    ParkingSlotID_t PLDSlotID;             //Locked slot ID output sent to PLD module (R5 to A72)
}IFPAInfoToPLD_t;


/* mcu2_0 to mcu2_1 */
typedef struct IHMIInfoToFPA_s
{
    ParkingSlotID_t m_selectedslotID;     //locked slot ID
    ParkINStyle_t VehicleParkDirection;		//RearIN or Front IN
}IHMIInfoToFPA_t;

typedef struct IFPAInfoToUSSOM_s
{
    ParkingSlotID_t USSOMSlotID;          //Locked slot ID output sent to USSOM module(R5 to R5)
    IParkingSlotData_t ParkOutSlotData;
}IFPAInfoToUSSOM_t;


/* mcu2_1 to mcu2_0 */
typedef struct IFPAInfoToHMI_s
{
		IParkingSlotData_t stFPAParkingSlotData[6];	//Vehicle Coordinates
		IParkingSlotData_t stFPALockedSlotData;	//VehicleCoordinates
		float32_t LockedSlotWidth;
		float32_t LockedSlotDepth;
		bool_t m_Parkable[6];
        IAllowedParkingDirection_t m_ParkableInDIrection[6];
		bool_t ParkOutEnableFlag;				//ParkOut Enable Flag
}IFPAInfoToHMI_t;

/* mcu1_0 to A72 and A72 to mcu1_0 */
typedef struct INVMSignalManager_s
{
	bool_t m_ReadNVMParam_b;
	bool_t m_WriteNVMParam_b;
	ParkINStyle_t m_ParkINStyle_e;
	IParkingSlotData_t m_ParkInSlotData;
} INVMSignalManager_t;

/* mcu2_1 to "A72, mcu2_1, mcu2_0, mcu1_0" */
typedef struct IJobFPAOutput_s
{
    bool_t AutoParkInitializedStatus_b;     //Status of Autopark initialization
    IFPAInfoToVC_t m_FpaInfoToVC;            //FPA output data to Vehicle control module
    IFPAInfoToPLD_t m_FPAInfoToPLD;          //FPA output data to PLD module
    IFPAInfoToUSSOM_t m_FPAInfoToUSSOM;      //FPA output data to USSOM module
    IFPAInfoToHMI_t m_FPAInfoToHMI;          //FPA output data to HMI module
	INVMSignalManager_t m_FPAToNVM;			//FPA I/O interface with NVM Manager
}IJobFPAOutput_t;

//typedef IJobFPAOutput_t JobFPAOutput;


/* mcu2_1 to mcu2_1 */
typedef struct AutoParkingState_s
{
    eAutoParkingState_t eAutoParkingState;
}IAutoParkingState_t;


/* mcu2_0 to mcu2_1 */
typedef struct ParkingSlotID_s
{
    ParkingSlotID_t LockedSlotID;
}IParkingSlotID_t;


/* mcu2_1 to mcu2_1 */
typedef struct PathPlannerState_s
{
    uint8_t m_PathPlannerState;
}IPathPlannerState_t;

typedef struct IobjectEdge_s
{
 Float2 center;
 float32_t curvature;
 Float2 endpoints[2];
 float32_t fit_err;
 float32_t hitratio;
 uint16_t numPoint;
 bool_t isCurve;
 bool_t valid;
}IobjectEdge_t;

typedef struct IJobUSSObjectMapOutput_s
{
 bool_t isUSSOMInitSuccess_b; // Status of USSOM init Success/Fail
 IParkingSlotData_t stUSSParkingSlotData[6]; // Left and right park slot coordinates info in image coordinates sent to FPA module
 uint16_t numPointsL; // Count of the points at left side sent to FPA - This has been added as FPA uses data currently
 uint16_t numPointsR; // Count of the points at right side sent to FPA- This has been added as FPA uses data currently
 IobjectEdge_t LeftObjectList[4]; // Keeps Left object edge information
 IobjectEdge_t RightObjectList[4]; // Keeps right object edge information
 IParkingSlotData_t stUSSLockedSlotData; // Locked park slot coordinates info in image coordinates sent to FPA module
} IJobUSSObjectMapOutput_t;


/* For A72(PLD) to MCU2_1 (R5F)*/
/* IParkingSlotData*/

/* NVM to MCU2_1*/
/*ParkINStyle_t*/

/* CalData(MCU1_0) to APFusion(MCU2_1)*/
/* TbAPFPA_AlgoTunParam_t*/
/* TbAPUSSOM_AlgoTunParam_t*/

/* CalData(MCU1_0) to PLD(A72)*/
/* TbAPPLD_AlgoTunParam_t*/

#endif //APA_USSOM_FPA_INOUT_DEFS_
