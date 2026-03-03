
/// @file   CrossplatformCommon.h
/// @brief  Cross platform Common Data Structure definition
///
///  Cross platform Common Data Structure definition
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author  Kedar Naphad (kedar.naphad@magna.com)
///

#ifndef MULTIPLATCOMMON_H
#define MULTIPLATCOMMON_H

#include "PlatformDataTypes.h" 

#define NUM_OF_WHEELS  (4u)
/// -------------------------------------------------------------------------------
/// Image size
/// -------------------------------------------------------------------------------
// PD input source
#define PD_INP_SRC_CAMERA (0) /* Life feed from camera */
#define PD_INP_SRC_FILE (1)	  /* Input read from file on the file system */
#define PD_INP_SRC_CODE (2)	  /* Input read from hard-coded image */
// #define PD_INP_SRC PD_INP_SRC_FILE
#define PD_INP_SRC PD_INP_SRC_CAMERA

// PD output source
#define PD_OUT_SRC_PL (0)	/* Output created by PL */
#define PD_OUT_SRC_FILE (1) /* Input read from file on the file system */
#define PD_OUT_SRC_CODE (2) /* Input read from hard-coded image */
// #define PD_OUT_SRC PD_OUT_SRC_FILE
#define PD_OUT_SRC PD_OUT_SRC_PL

#if PD_INP_SRC == PD_INP_SRC_CAMERA
#define PD_CAMERA_MODEL_HARDCODED (0)
#else // #if PD_INP_SRC == PD_INP_SRC_CAMERA
#define PD_CAMERA_MODEL_HARDCODED (1)
#endif // #if PD_INP_SRC == PD_INP_SRC_CAMERA

#define MAX_PATH (260)
#define PD_CROP_ENABLED (1)
#define PD_1M_ENABLED (1)
#define PD_CACHE_ENABLED (1)
#if (PD_1M_ENABLED)
#define PD_IMG_WIDTH (1280)
#define PD_IMG_HEIGHT (800)
#else // #if (PD_CROP_ENABLED)
#define PD_IMG_WIDTH (640)
#define PD_IMG_HEIGHT (400)
#endif // #if (PD_CROP_ENABLED)
#define PD_LUMA_WIDTH (640)
#define PD_LUMA_HEIGHT (400)
#if (PD_CROP_ENABLED)
#define PD_CROP_WIDTH (1280)
#define PD_CROP_HEIGHT (200)
#endif													 // #if (PD_CROP_ENABLED)
#define MAX_CT_BUF_SIZE (PD_LUMA_WIDTH * PD_LUMA_HEIGHT) // max UOLBP image: 640x400 for regular scales or 1280x200 for cropped scale
#define PD_FAST_SCAN_RESULTS (0x1000)
#define PD_FRONT_ENABLED (0x1)
#define PD_REAR_ENABLED (0x1)

#define DEFAULT_SLOT_WIDTH	(68u)
#define DEFAULT_SLOT_DEPTH	(145u)
#define DEFAULTSLOTWIDTH	(70.0f)
#define DEFAULTSLOTDEPTH	(150.0f)


#define DEFAULT_AVAILABLE_VEHICLESLOTS (3u)
#define DEFAULT_AVAILABLE_VehicleEdges (20u)

#if !defined(BUILD_MCU1_0)
typedef struct  TbAPFPA_AlgoTunParam_s {

	float32_t TOPVIEW_IMAGE_RESOLUTION_X;
	float32_t TOPVIEW_IMAGE_RESOLUTION_Y;
	float32_t PERP_DEFAULT_LENGTH;
	float32_t PERP_DEFAULT_WIDTH;
	float32_t PARA_DEFAULT_LENGTH;
	float32_t PARA_DEFAULT_WIDTH;
	float32_t PERP_MINIMUM_LENGTH;
	float32_t PERP_MINIMUM_WIDTH;
	float32_t PARA_MINIMUM_LENGTH;
	float32_t PARA_MINIMUM_WIDTH;
	float32_t PARKABLE_PERP_MINIMUM_LENGTH;
	float32_t PARKABLE_PERP_MINIMUM_WIDTH;
	float32_t PARKABLE_PARA_MINIMUM_LENGTH;
	float32_t PARKABLE_PARA_MINIMUM_WIDTH;
	float32_t MinParaLongDist;
	float32_t MinParaLatDist;
	float32_t MinPerpLongDist;
	float32_t MinPerpLatDist;
	float32_t MaxParaLongDist;
	float32_t MaxParaLatDist;
	float32_t MaxPerpLongDist;
	float32_t MaxPerpLatDist;
	float32_t IOU_CUTOFF;
	float32_t NUM_USSPOINTS;
	float32_t SIDE_OFFSET;
	float32_t REQ_SLOT_WIDTH;
	float32_t PIX_OFFSET;
	float32_t REQ_SLOT_DEPTH;
	float32_t MIN_CAR_WIDTH;
	float32_t MIN_CAR_DEPTH;
	float32_t  AP_PARA_Maximum_Slot_Depth;
	float32_t  AP_PARA_Maximum_Slot_Width;
	float32_t  AP_PERP_Maximum_Slot_Depth;
	float32_t  AP_PERP_Maximum_Slot_Width;
	float32_t  AP_PERP_Minimum_Slot_Depth;
	float32_t  AP_PERP_Minimum_Slot_Width;
	float32_t  AP_PARA_Minimum_Slot_Depth;
	float32_t  AP_PARA_Minimum_Slot_Width;
	float32_t  AP_PARA_Slot_Width_Parking_Gap;
	float32_t  AP_PERP_Slot_Width_Parking_Gap;
	float32_t  AP_PERP_Parking_Gap_Slot_Depth;
	uint8_t  AP_Distance_D1_Lower_Limit;
	uint8_t  AP_Distance_D2_Upper_Limit;
	uint8_t  AP_Angle_Tolerance;
	int8_t FUSION_ENABLE;
	uint8_t PLD_Enable;
	uint8_t USSOM_Enable;
	uint8_t dummy1;
	uint8_t dummy2;
}TbAPFPA_AlgoTunParam_t;

typedef struct  TbAPPLD_AlgoTunParam_s {
	float32_t WHEEL_BASE_M;
	float32_t TOPVIEW_IMAGE_RESOLUTION_X;
	float32_t TOPVIEW_IMAGE_RESOLUTION_Y;
	float32_t Variant_WhlAngCFWt;
	float32_t Variant_WhlAngCFBias;
	uint16_t scanPerpLineMin;
	uint16_t scanPerpLineMax;
	uint16_t scanParaLineMin;
	uint16_t scanParaLineMax;
	uint16_t scanFishLineMin;
	uint16_t scanFishLineMax;
	uint16_t perpGapWidthMin;
	uint16_t perpGapWidthMax;
	uint16_t paraGapWidthMin;
	uint16_t paraGapWidthMax;
	uint16_t fishGapWidthMin;
	uint16_t fishGapWidthMax;
	uint16_t gapLockDistance;
	uint16_t maximumIDThreshold;
	uint16_t scanSmallROI_x_L;
	uint16_t scanSmallROI_y_L;
	uint16_t scanSmallROI_width_L;
	uint16_t scanSmallROI_height_L;
	uint16_t scanBigROI_x_L;
	uint16_t scanBigROI_y_L;
	uint16_t scanBigROI_width_L;
	uint16_t scanBigROI_height_L;
	uint16_t scanSmallROI_x;
	uint16_t scanSmallROI_y;
	uint16_t scanSmallROI_width;
	uint16_t scanSmallROI_height;
	uint16_t scanBigROI_x;
	uint16_t scanBigROI_y;
	uint16_t scanBigROI_width;
	uint16_t scanBigROI_height;
	uint8_t lineBufferSize;
	uint8_t lineBufferSize_L;
	uint8_t LINE_INPUT_ENABLE_L;
	uint8_t LINE_INPUT_ENABLE;
}TbAPPLD_AlgoTunParam_t;

typedef struct  TbAPUSSOM_AlgoTunParam_s {
	float32_t USS_Bumper_Layout[48];
	float32_t AngPar_1_2;
	float32_t AngPar_2_3;
	float32_t AngPar_2_4;
	float32_t AngPar_2_5;
	float32_t AngPar_3_4;
	float32_t AngPar_3_5;
	float32_t AngPar_4_5;
	float32_t AngPar_5_6;
	float32_t AngPar_7_8;
	float32_t AngPar_7_9;
	float32_t AngPar_7_10;
	float32_t AngPar_8_9;
	float32_t AngPar_8_10;
	float32_t AngPar_8_11;
	float32_t AngPar_9_10;
	float32_t AngPar_9_11;
	float32_t AngPar_9_12;
	float32_t AngPar_10_11;
	float32_t AngPar_10_12;
	float32_t AngPar_11_12;
	int32_t VehicleType;
	uint8_t BeforeVehicleSlotDetection;
	uint8_t AfterVehicleSlotDetection;
	uint8_t Tail_Point_Adjustment;
	uint8_t Head_Point_Adjustment;
	uint8_t MABxEgoMotion;
	uint8_t SlotWidth;
	uint8_t SlotDepth;
	uint8_t Distance_from_car;
	uint8_t USSCalPoints;
	uint8_t USSslotOffset;
	uint8_t dummy1;
	uint8_t dummy2;
}TbAPUSSOM_AlgoTunParam_t;

struct GPSData
{
	float32_t GPS_Latitude_Degree;
	float32_t GPS_Latitude_Minutes;
	float32_t GPS_Longitude_Degree;
	float32_t GPS_Longitude_Minutes;
	float32_t MagneticField_X;
	float32_t MagneticField_Y;
	float32_t MagneticField_Z;
	float32_t Acceleration_X;
	float32_t Acceleration_Y;
	float32_t Acceleration_Z;
	float32_t GPS_speed;
	float32_t GPS_course;
	float32_t Rotation_X;
	float32_t Rotation_Y;
	float32_t Rotation_Z;
	int16_t Attitude_Roll;
	int16_t Attitude_Pitch;
	uint16_t Attitude_Yaw;
	int64_t Longitude;
	int64_t Latitude;
	float32_t Height;
	int16_t Attitude_Yaw_Std_Dev;
	int16_t North_Std_Dev;
	int16_t East_Std_Dev;
	int16_t Height_Std_Dev;
	float32_t Velocity_East;
	float32_t Velocity_North;
	float32_t Velocity_Up;
	float32_t Heading_deg;
	bool VelocityEastExists;
	bool VelocityNorthExists;
	bool VelocityUpExists;
};

typedef enum m_GearValues
{
	GearValues_E_GEAR_REVERSE = -1,
	GearValues_E_GEAR_NEUTRAL = 0,
	GearValues_E_GEAR_FORWARD = 1,
	GearValues_E_GEAR_PARK = 2
} m_GearValues_t;

typedef enum
{
	PK_Undefined = 0,
	PK_LEFT_PERP_BACKIN = 1,
	PK_RIGHT_PERP_BACKIN = 2,
	PK_LEFT_PERP_NOSEIN = 3,
	PK_RIGHT_PERP_NOSEIN = 4,
	PK_LEFT_PARA = 5,
	PK_RIGHT_PARA = 6,
	PK_LEFT_FISH = 7,
	PK_RIGHT_FISH = 8
} PK_Type;

struct EgoMotionVector
{
	float32_t X_position_mm;
	float32_t Y_position_mm;
	float32_t HeadingAngle_rad;
	float32_t Timestamp_ms;
};

typedef enum eAutoParkingState
{
	eAutoParkingState_E_PW_APS_IDLE = 0,	/* Autoparking process in the idle state */
	eAutoParkingState_E_PW_APS_SCANNING,	/* Autoparking in scanning mode */
	eAutoParkingState_E_PW_APS_PARKINGIN,	/* Autoparking in parking-in state */
	eAutoParkingState_E_PW_APS_PARKINGOUT,	/* Autoparking in parking-out state */
	eAutoParkingState_E_PW_APS_HANDSHAKE,	/* Autoparking in parking-out state */
} eAutoParkingState_t;

typedef enum eVCState
{
	eVCState_E_UMAP_IDLE = 0,  // 0
	eVCState_E_UMAP_SEARCH,    // 1
	eVCState_E_UMAP_FOUND,     // 2
	eVCState_E_UMAP_STROKE1,   // 3
	eVCState_E_UMAP_STROKE2,   // 4
	eVCState_E_UMAP_STROKE3,   // 5
	eVCState_E_UMAP_STROKE4,   // 6
	eVCState_E_UMAP_STROKE5,   // 7
	eVCState_E_UMAP_END,       // 8
	eVCState_E_UMAP_CANCEL,    // 9
	eVCState_E_UMAP_FAULT,     // 10
	eVCState_E_UMAP_STROKE6,   // 11
	eVCState_E_UMAP_STROKE7,   // 12
	eVCState_E_UMAP_INVALID    // 13
} eVCState_t;

typedef enum ParkingSlotType_e
{
	ParkingSlotType_E_PW_NODIR = 0,               /* Orientation Unknown */
	ParkingSlotType_E_PW_PERPENDICULAR,           /* Perperdicular slot */
	ParkingSlotType_E_PW_DIAGONAL,                /* Diagonal slot */
	ParkingSlotType_E_PW_PARALLEL,                /* Parallel slot */
	ParkingSlotType_t_MAX_Enforcer = 0xFFFFFFFF
} ParkingSlotType_t;

typedef enum AllowedParkingDirection_s
{
	AllowedParkingDirection_E_NODIR = 0,      
	AllowedParkingDirection_E_NOSE_IN_Only,           
	AllowedParkingDirection_E_REAR_IN_Only,
	AllowedParkingDirection_E_BOTH,                
	AllowedParkingDirection_t_MAX_Enforcer = 0xFFFFFFFF
} IAllowedParkingDirection_t;

// FPA Input - Slot Side
typedef enum SlotSide_e
{
	SlotSide_E_SLOT_NULL = 0,
	SlotSide_E_SLOT_LEFT = 1,
	SlotSide_E_SLOT_RIGHT = 2,
	SlotSide_t_MAX_Enforcer = 0xFFFFFFFF
} SlotSide_t;

// PLD, USSOM, FPA Input - Parking slot ID
typedef enum ParkingSlotID
{
	ParkingSlotID_E_NONE = 0,
	ParkingSlotID_E_L1,
	ParkingSlotID_E_L2,
	ParkingSlotID_E_L3,
	ParkingSlotID_E_R1,
	ParkingSlotID_E_R2,
	ParkingSlotID_E_R3,
	ParkingSlotID_t_MAX_Enforcer = 0xFFFFFFFF
} ParkingSlotID_t;

typedef enum ParkINStyle
{
	ParkINStyle_E_CAR_IN_NULL = 0,
	ParkINStyle_E_FRONT_IN = 1, // Front In for  Park IN	Direction
	ParkINStyle_E_REAR_IN = 2,	// Rear In for Park IN Direction
    ParkINStyle_t_MAX_Enforcer = 0xFFFFFFFF
} ParkINStyle_t;

typedef enum ParkOutStyle
{
	ParkOutStyle_E_CAR_OUT_NULL = 0,
	ParkOutStyle_E_FRONT_OUT = 1,	//Front Out for Park Out Direction
	ParkOutStyle_E_REAR_OUT = 2,	//Rear Out for Park Out Direction
	ParkOutStyle_t_MAX_Enforcer = 0xFFFFFFFF
} ParkOutStyle_t;

typedef enum ROI_DIRECTION
{
	LEFT = 0,
	RIGHT,
	MAX_DIRECTION_NUM
} ROI_DIRECTION_t;

typedef enum SensorType
{
	None = 0,
	USS,
	SVC,
	FUS
} SensorType_t;

typedef enum ROI_TYPE
{
	ROI_Perp = 0,
	ROI_Para,
	ROI_Angle_60,
} ROI_TYPE_t;

typedef enum eUPASensorSource
{
	eUPASensorSource_E_CS_UPA_S1 = 0,
	eUPASensorSource_E_CS_UPA_S2,
	eUPASensorSource_E_CS_UPA_S3,
	eUPASensorSource_E_CS_UPA_S4,
	eUPASensorSource_E_CS_UPA_S5,
	eUPASensorSource_E_CS_UPA_S6,
	eUPASensorSource_E_CS_UPA_S7,
	eUPASensorSource_E_CS_UPA_S8,
	eUPASensorSource_E_CS_UPA_S9,
	eUPASensorSource_E_CS_UPA_S10,
	eUPASensorSource_E_CS_UPA_S11,
	eUPASensorSource_E_CS_UPA_S12,
	eUPASensorSource_E_CS_UPA_MAX //12
} eUPASensorSource_t;

typedef struct Point2i_1
{
	/*
	@@ ELEMENT = Pld
	@@ STRUCTURE = Point2i_1
	@@ A2L_TYPE = PARAMETER
	@@ DATA_TYPE = ULONG
	@@ END
	*/
	uint32_t Pld;
	/*
	@@ ELEMENT = Uss
	@@ STRUCTURE = Point2i_1
	@@ A2L_TYPE = PARAMETER
	@@ DATA_TYPE = ULONG
	@@ END
	*/
	uint32_t Uss;
} Point2i_1t;

typedef struct
{
	float32_t wheel[NUM_OF_WHEELS];
	float32_t steeringWheelAngle;
} WheelStat_s;

typedef struct VehicleInfo_s
{
	char m_nondriven_speed_info;
	char m_driven_speed_info;
	float32_t m_Speed;				// --- speed
	float32_t m_Gear;				// --- Gear Information
	float32_t m_Steeringwheelangle; // --- left image
	int m_GearDirection;
	WheelStat_s m_WheelStat;
	float32_t m_WheelAngle;
	float32_t m_timeElapsed;
	float32_t m_YawRateTimeStamp;
	float32_t m_YawRate;
} VehicleInfo_t;

typedef struct VehicleInfoPD_s
{
	unsigned short CANTranslationID;
	int NumWheelPulses;
	int MaxWheelPulses;
	double WheelCircumference_mm;
	double DistanceCoG2FrontAxis_mm;
	double DistanceCoG2RearAxis_mm;
	int VehicleWidth_mm;
	int VehicleLength_mm;
	int FrontOverhang_mm;
	int RearOverhang_mm;
	float WheelBase_mm;
} VehicleInfoPD_t;

extern VehicleInfoPD_t VehicleInfoPD;

// Track the Parking Spot Selected by User
typedef enum
{
	SLOT_NONE = 0,
	LEFT_1,
	LEFT_2,
	LEFT_3,
	RIGHT_1,
	RIGHT_2,
	RIGHT_3
} ParkingSelectedSpot;

enum ParkingDirection
{
	CAR_NULL = 0,
	FRONT_IN_OUT = 1,
	REAR_IN_OUT = 2
};
#endif
#endif // !MULTIPLATCOMMON_H
