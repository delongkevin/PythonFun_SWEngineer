/// @file   LMD_Input_Outputs.h
/// @brief  LMD_Input_Outputs Interface Data Structure definition
///
///  LMD detection input structure is defined
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author  Rohit Borse (rohit.borse@magna.com)
/// updated by: Afshan Shaikh (afshan.shaikh@magna.com)
/// --------------------------------------------------------------------------
#ifndef _LMD_INPUT_OUTPUT_H_
#define _LMD_INPUT_OUTPUT_H_

#include "../magna_apps/tha_sm_vc/algo/common/CppAdaptation.h"


/* ############################# Inputs to LMD ############################# */
#include "ProxiMgrIpcDataTypes.h"
/* ME_Proxi_to_IpcSignals_t */
/* From Proxi Manager (MCU1_0) to A72     */

#include "VehicleInputAdapterDataTypes.h"
/* ME_VehInp_to_IpcSignals_t */
/* From FDCAN2 (MCU1_0) to A72        */

#include "DegManager_Inputs_Outputs.h"
/* FID_STRUCT_A */
/* From Degradation Manager (MCU1_0) to A72  */

/* IKinematicData_t */
/* From Kinematic model (MCU1_0) to A72  */

/*From CalDataProvider(MCU1_0) to A72(MPU1_0)*/
/* ITbLMD_VrntTunParam_t */

#include "USS_Inputs_Outputs.h"
/* US_S_USSErrorDiagData_t  */
/* US_S_BlockageBit_t       */
/* From USS_Manager(MCU2_1) to A72(MPU1_0)  */

//#include "TVGLDWLanes_enums.h"

// LMD algorithm state
enum LMD_Status
{
	LMD_Active = 0,
	LMD_NotActive = 1,
	LMD_Faulted = 2
};

// Lane Health
typedef enum LaneDetHealth_e
{
	Lane_Faulted = 0,
	Lane_Blocked,
	Lane_Unknown,
	Lane_Healthy
} LaneDetHealth_t;

// Camera Manager Status
typedef enum CameraStatus_e
{
	Camera_None_Active = 0,
	Camera_Left_Right_Front,
	Camera_Left_Right,
	Camera_Left_Front,
	Camera_Right_Front,
	Camera_Front,
	Camera_Left,
	Camera_Right
} CameraStatus_t;

// Confidence
typedef enum Confidence_e
{
	Conf_Not_Detected = 0,
	Conf_Detected_Low_Confidence,
	Conf_Detected_Medium_Confidence,
	Conf_Detected_High_Confidence
} Confidence_t;

// Lane Line Color
typedef enum LaneColor_e
{
	LaneColor_None = 0,
	LaneColor_White,
	LaneColor_Yellow,
	LaneColor_Orange,        //lanes in construction sites
	LaneColor_Other
} LaneColor_t;

// Lane Line Style
typedef enum LaneType_e
{
	LaneType_None = 0,
	LaneType_Solid,
	LaneType_Dashed,
	LaneType_Double,
	LaneType_RoadEdge,
	LaneType_BottDots,
	LaneType_Barrier,
	LaneType_Other
} LaneType_t;

typedef enum LaneTrackState_e
{
    LaneTrackState_Null = 0,
    LaneTrackState_Average,
    LaneTrackState_Reset,
    LaneTrackState_Hold
}LaneTrackState;

/* ############################# Outputs from LMD ############################# */
/* LMD_Outputs_CVPAMFDData2_t */
/* From A72 to MCU1_0 (CAN 2 and CAN 14 both)  */

/* LMD_Lane_Outputs_s */
/* From A72 to MCU1_0 (CAN)  */

/* ############################# Outputs from FOD ############################# */
/* FOD_Outputs_CVPAMFDData_t */
/* From A72 to MCU1_0 (CAN)  */

/************************************* Sub structures and Enums ******************************************/

#ifndef DEFINED_TYPEDEF_FOR_ME_VEHOUT_LMD_
#define DEFINED_TYPEDEF_FOR_ME_VEHOUT_LMD_

// Lane Line Style

// Lane Health

// Camera Manager Status

typedef struct
{
        uint64_t IeLMD_e_FrameIndexLanes2;
		uint64_t IeLMD_e_CntrAdasFdLanes2;
		float32_t IeLMD_e_LineSeg1Conf;
        float32_t IeLMD_e_LineSeg2Conf;
        float32_t IeLMD_e_LineSeg3Conf;
        float32_t IeLMD_e_LineSeg4Conf;
        float32_t IeLMD_e_LineSeg5Conf;
        float32_t IeLMD_e_LineSeg6Conf;
        float32_t IeLMD_e_LineSeg7Conf;
        float32_t IeLMD_e_LineSeg8Conf;
        //-------------------------
        float32_t IeLMD_m_LineSeg1X1;
        float32_t IeLMD_m_LineSeg2X1;
        float32_t IeLMD_m_LineSeg3X1;
        float32_t IeLMD_m_LineSeg4X1;
        float32_t IeLMD_m_LineSeg5X1;
        float32_t IeLMD_m_LineSeg6X1;
        float32_t IeLMD_m_LineSeg7X1;
        float32_t IeLMD_m_LineSeg8X1;
        //-------------------------
        float32_t IeLMD_m_LineSeg1X2;
        float32_t IeLMD_m_LineSeg2X2;
        float32_t IeLMD_m_LineSeg3X2;
        float32_t IeLMD_m_LineSeg4X2;
        float32_t IeLMD_m_LineSeg5X2;
        float32_t IeLMD_m_LineSeg6X2;
        float32_t IeLMD_m_LineSeg7X2;
        float32_t IeLMD_m_LineSeg8X2;
        //-------------------------
        float32_t IeLMD_m_LineSeg1Y1;
        float32_t IeLMD_m_LineSeg2Y1;
        float32_t IeLMD_m_LineSeg3Y1;
        float32_t IeLMD_m_LineSeg4Y1;
        float32_t IeLMD_m_LineSeg5Y1;
        float32_t IeLMD_m_LineSeg6Y1;
        float32_t IeLMD_m_LineSeg7Y1;
        float32_t IeLMD_m_LineSeg8Y1;
        //-------------------------
        float32_t IeLMD_m_LineSeg1Y2;
        float32_t IeLMD_m_LineSeg2Y2;
        float32_t IeLMD_m_LineSeg3Y2;
        float32_t IeLMD_m_LineSeg4Y2;
        float32_t IeLMD_m_LineSeg5Y2;
        float32_t IeLMD_m_LineSeg6Y2;
        float32_t IeLMD_m_LineSeg7Y2;
        float32_t IeLMD_m_LineSeg8Y2;
		
		uint16_t IeLMD_e_CrcAdasFdLanes2;
        //-------------------------
        uint8_t IeLMD_e_LineSeg1Id;
        uint8_t IeLMD_e_LineSeg2Id;
        uint8_t IeLMD_e_LineSeg3Id;
        uint8_t IeLMD_e_LineSeg4Id;
        uint8_t IeLMD_e_LineSeg5Id;
        uint8_t IeLMD_e_LineSeg6Id;
        uint8_t IeLMD_e_LineSeg7Id;
        uint8_t IeLMD_e_LineSeg8Id;
        //-------------------------------------
        uint8_t IeLMD_e_MsgCntrAdasFdLanes2;
        uint8_t IeLMD_e_MacAdasFdLanes2;
        uint8_t IeLMD_e_ReservedForFunctionalSafety2;
		uint8_t Dummy1_2_b;
		uint8_t Dummy2_2_b;
		uint8_t Dummy3_2_b;
}ILMD_Outputs_ADASFDLANES2_t;

typedef struct
{
	uint64_t IeLMD_e_FrameIndexLanes1;
    uint64_t IeLMD_e_CntrAdasFdLanes1;
    //------------Lane Confidence-------------
    float32_t IeLMD_e_Line1Confidence;
    float32_t IeLMD_e_Line2Confidence;
    float32_t IeLMD_e_Line3Confidence;
    float32_t IeLMD_e_Line4Confidence;
    //------------Offset-------------
    float32_t IeLMD_m_Line1Offset;
    float32_t IeLMD_m_Line2Offset;
    float32_t IeLMD_m_Line3Offset;
    float32_t IeLMD_m_Line4Offset;
    //------------Heading-------------
    float32_t IeLMD_rad_Line1Heading;
    float32_t IeLMD_rad_Line2Heading;
    float32_t IeLMD_rad_Line3Heading;
    float32_t IeLMD_rad_Line4Heading;
    //------------Lane marker start range/view range-------------
    float32_t IeLMD_m_Line1StartRange;
    float32_t IeLMD_m_Line2StartRange;
    float32_t IeLMD_m_Line3StartRange;
    float32_t IeLMD_m_Line4StartRange;
    //------------Lane marker end range/view range-------------
    float32_t IeLMD_m_Line1EndRange;
    float32_t IeLMD_m_Line2EndRange;
    float32_t IeLMD_m_Line3EndRange;
    float32_t IeLMD_m_Line4EndRange;
    //------------Lane Marker Curvature Rate (2nd order)-------------
    float32_t IeLMD_e_Line1Curvature;      //x_img = c0 + c1 * y_img + c2 * y_img^2
    float32_t IeLMD_e_Line2Curvature;
    float32_t IeLMD_e_Line3Curvature;
    float32_t IeLMD_e_Line4Curvature;
    //------------Lane Marker Curvature Rate (3rd order)-------------
    float32_t IeLMD_e_Line1CurvatureRate;  //x_img = c0 + c1 * y_img + c2 * y_img^2 + c2 * y_img^3
    float32_t IeLMD_e_Line2CurvatureRate;
    float32_t IeLMD_e_Line3CurvatureRate;
    float32_t IeLMD_e_Line4CurvatureRate;
    //------------Line Marker Type-------------
    LaneType_t IeLMD_e_Line1Type;
    LaneType_t IeLMD_e_Line2Type;
    LaneType_t IeLMD_e_Line3Type;
    LaneType_t IeLMD_e_Line4Type;
    //------------Lane Health-------------
    LaneDetHealth_t IeLMD_e_LaneDetectionHealth;
    //------------Camera Status-------------
    CameraStatus_t IeLMD_e_CameraStatus;
    //-------------------------------------
    uint16_t IeLMD_e_CrcAdasFdLanes1;
    uint8_t IeLMD_e_MsgCntrAdasFdLanes1;
    uint8_t IeLMD_e_MacAdasFdLanes1;
    uint8_t IeLMD_e_ReservedForFunctionalSafety1;
	uint8_t Dummy1_1_b;
	uint8_t Dummy2_1_b;
	uint8_t Dummy3_1_b;
}ILMD_Outputs_ADASFDLANES1_t;

typedef struct
{
    float32_t C0;
    float32_t C1;
    float32_t C2;
}CurveModel_t;

typedef struct
{
    bool_t m_valid;
    uint8_t m_LineID;
    Point2f_c m_DetectionPoint_Front_5m;
    Point2f_c m_DetectionPoint_Front_12m;
    Point2f_c m_DetectionPoint_Rear_5m;
    Point2f_c m_DetectionPoint_Side_0m;
    int32_t m_LaneConfidence;                       //0~100
    CurveModel_t m_curveModel;                        //x_img = c0 + c1 * y_img + c2 * y_img^2.
    float32_t m_radiusOfCurvature;                  //m
    LaneType_t m_LaneType;
    int32_t m_LaneTypeConfidance;                   //0~100
    LaneColor_t m_LaneColor;
    int32_t m_LaneColorConfidance;                  //0~100
    float32_t m_LaneWidth;                          //m
    float32_t m_LateralDistToLaneFront;             //m
    float32_t m_LateralDistToLaneRear;              //m
    float32_t m_LongitudinalDistToLane;             //m
    float32_t m_TimeToLaneCrossing;                 //sec
}LaneParams_t;

typedef struct
{
    LaneParams_t m_LeftLane;
    LaneParams_t m_RightLane;
}LaneLists_t;

typedef struct
{
    int32_t START_ROW;
    int32_t END_ROW;
    int32_t START_COL;
    int32_t END_COL;
}ColumnRowParams_t;

typedef struct
{
    int32_t ValidNum;
    ColumnRowParams_t SubRois[2];
    int32_t RLDFeatureCountInSubRois[2];
    float32_t para[10];
    //para[0]: Max. pixel distance btw each subRoi and central line of vehicle.
    //para[1]: Min. RLD pixel count for Roi reset.
    int32_t LDW_REG_DYNAMIC_ROI_MAX_OFFSET_BTW_ROI_AND_CENTRAL_LINE;
    int32_t LDW_REG_DYNAMIC_ROI_MAX_RLD_PIXEL_COUNT;
    bool_t isLeft2Right;
    bool_t isRight2Left;
}Rois_t;

typedef struct
{
    int32_t x;
    int32_t y;
    float32_t x_World_mm;
    float32_t y_World_mm;
    int32_t confidanceScore;
    bool_t valid;
    float32_t angle;
    float32_t rho;
    bool_t selectCurveFit;
    bool_t IsInnerPoint;
}LC_LnPnt_t;

typedef struct
{
    int32_t width;
    int32_t height;
    int32_t startPositionX;
    int32_t startPositionY;
    LC_LnPnt_t leftPoint;
    LC_LnPnt_t rightPoint;
}LC_LnCup_t;

typedef struct
{
    float32_t coef_img[3];
    int32_t laneType;                       //LaneType_t
    int32_t laneType_conf;
    int32_t laneDetect_conf;
    int32_t laneColor;
    int32_t laneColor_conf;
    float32_t laneWidth;                    //meter
    Point2f_c distantToLane_pix;
    float32_t distantToLaneFront;           //meter
    float32_t distantToLaneRear;            //meter
    float32_t radiusOfCurvature;
    Point2f_c longituCrossCrossLanePoint_pix;
    float32_t longituCrossLaneDist;         //meter
    float32_t TTLC;                         //sec
}OutLaneInfo_t;



typedef struct
{
    LC_LnCup_t stepArray[60];
    int32_t averageLaneWidth;
    int32_t countLaneStep;
    float32_t laneCoef[2][3];       //[0:1]->left,right   [0:2]->c0,c1,c2    Y= [c0 c1 c2] * [1 X X^2]'.
    float32_t laneCoef_TVG[2][3];   //[0:1]->left,right   [0:2]->c0,c1,c2    img_x = [c0 c1 c2] * [1 img_y img_y^2]'.
    bool_t laneCoef_TVG_valid[2];   //[0:1]->left,right
    LaneTrackState lanTrack_s[2];   //[0:1]->left,right
    OutLaneInfo_t output[2];          //[0:1]->left,right
}LC_LnModel_t;

typedef struct
{
    #define DISPLAY_LANE_CURVE_DATA_MAX (50)
    Rois_t o_ProcessRoi;
    LC_LnModel_t o_egoLaneModel;
    uint32_t imgWidth;
    uint32_t imgHeight;
    bool_t showLaneInfo;
}DebugDumpAlgo_t;

// Structure to define Lane debug output signals
typedef struct Lane_Outputs_Debug_s
{
    LaneLists_t m_TotalLanes;
    DebugDumpAlgo_t m_DebugInfo;
} Lane_Outputs_Debug_t;

typedef struct 
{
	float32_t		IeFOD_deg_ObjAngle;
	float32_t		IeFOD_deg_ObjAngle2;
	float32_t		IeFOD_cm_ObjRange;
	float32_t		IeFOD_cm_ObjRange2;
	uint8_t			IeFOD_e_ObjConf_e;
	uint8_t			IeFOD_e_ObjType_e;
}FOD_Attributes_t;

typedef struct ITbLMD_VrntTunParam_t
{
    float32_t KeLMD_rollThd;
    float32_t KeLMD_yawThd;
    float32_t KeLMD_PitchThd;
    uint32_t keVehParam_m_WhlBse;
    float32_t Straight_Driving_Thresold;
    uint32_t Steering_Angle;
    float32_t keLMD_offset1Thd;
    float32_t keLMD_curvature1Thd;
    float32_t keLMD_Heading1Thd;
    float32_t keLMD_confidence1Thd;
    float32_t keLMD_offset2Thd;
    float32_t keLMD_curvature2Thd;
    float32_t keLMD_Heading2Thd;
    float32_t keLMD_confidence2Thd;
    float32_t keLMD_offset3Thd;
    float32_t keLMD_curvature3Thd;
    float32_t keLMD_Heading3Thd;
    float32_t keLMD_confidence3Thd;
    float32_t keLMD_offset4Thd;
    float32_t keLMD_curvature4Thd;
    float32_t keLMD_Heading4Thd;
    float32_t keLMD_confidence4Thd;
    float32_t keLMD_segmentConf1_Thd;
    float32_t keLMD_segmentConf2_Thd;
    float32_t keLMD_segmentConf3_Thd;
    float32_t keLMD_segmentConf4_Thd;
    float32_t keLMD_segmentConf5_Thd;
    float32_t keLMD_segmentConf6_Thd;
    float32_t keLMD_segmentConf7_Thd;
    float32_t keLMD_segmentConf8_Thd;
}ITbLMD_VrntTunParam_t;

typedef struct
{
    ILMD_Outputs_ADASFDLANES1_t LMD_Outputs_ADASFDLANES1_s;
    ILMD_Outputs_ADASFDLANES2_t LMD_Outputs_ADASFDLANES2_s;
}LMD_Outputs_CVPAMFDData2_t;

typedef struct
{
    Lane_Outputs_Debug_t Lane_Outputs_Debug_s;
}LMD_Lane_Outputs_s;

typedef struct
{
	FOD_Attributes_t	FOD_Attribute_s[6];
	uint64_t			IeFOD_e_MacCvpamFdData;
	uint16_t			IeFOD_e_CntrCvpamFdData;
	uint8_t				IeFOD_e_FrontSensorDetHealth_e;
	uint8_t				IeFOD_e_CrcCvpamFdData;
	uint8_t				IeFOD_e_msgCntrCvpamFdData;		
}FOD_Outputs_CVPAMFDData_t;

#endif

/* #####################################################################*/

#endif //_LMD_INPUT_OUTPUT_H_
