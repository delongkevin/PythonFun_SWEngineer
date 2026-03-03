/// @file   CrossplatformCommon.hpp
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
#ifndef MULTIPLATCOMMON_HPP
#define MULTIPLATCOMMON_HPP

#include "mecl/mecl.h"
#include "meal/camera/core/inc/CameraPoint.h"

/// PI definition from AppCtrl. Turn PI32/PI64 into PI to prove
/// changes only appeared due to different PI values.
/// #define PI      (3.1415926535897)
#define PI32 (mecl::math::constants<float32_t>::pi_x())
#define PI64 (mecl::math::constants<float64_t>::pi_x())

#define POSINF32 (mecl::math::numeric_limits<float32_t>::infinity_x())
#define NEGINF32 (mecl::math::constants<float32_t>::minusOne_x() * POSINF32)
#define POSINF64 (mecl::math::numeric_limits<float64_t>::infinity_x())
#define NEGINF64 (mecl::math::constants<float64_t>::minusOne_x() * POSINF64)

typedef mecl::math::numeric_limits<float64_t> numlim;
typedef mecl::math::trigonometry<float64_t> trig64;
typedef mecl::math::trigonometry<float32_t> trig32;
typedef mecl::math::algebra<float64_t> alge64;
typedef mecl::math::algebra<float32_t> alge32;

struct PotentialMap
{
	static constexpr uint16_t MULTIPLIER_SIZE = 12;

	// potmapBuf size == width * height
	float32_t *potmapBuf;
	uint16_t USPatt_ArcThickness;
	uint16_t width;
	uint16_t height;
	float32_t res;
	PotentialMap() : potmapBuf(nullptr), USPatt_ArcThickness(0), width(0), height(0), res(0)
	{
		Reset();
	}

	PotentialMap(float32_t *buf, uint16_t ArcThickness, uint16_t w, uint16_t h, float32_t res)
		: potmapBuf(buf), USPatt_ArcThickness(ArcThickness), width(w), height(h), res(res)
	{		
	}

	void Reset()
	{
		 potmapBuf  = nullptr;
		 width = 0;
		 height = 0;
		 res = 0.0f;
		 USPatt_ArcThickness = 0;
	}
};
typedef struct ParkingSlotCoordinatesWorld
{
	ParkingSlotCoordinatesWorld()
		: C1_Real(0.0f, 0.0f),
		  C2_Real(0.0f, 0.0f),
		  C3_Real(0.0f, 0.0f),
		  C4_Real(0.0f, 0.0f)
	{
		Reset();
	}
	void Reset()
	{
		C1_Real.x = 0.0f, C1_Real.y = 0.0f;
		C2_Real.x = 0.0f, C2_Real.y = 0.0f;
		C3_Real.x = 0.0f, C3_Real.y = 0.0f;
		C4_Real.x = 0.0f, C4_Real.y = 0.0f;
	}
	Point2f C1_Real;
	Point2f C2_Real;
	Point2f C3_Real;
	Point2f C4_Real;
} eParkingSlotCordWorld_t;

typedef struct ParkingLotType
{
	ParkingSlotType_t PLType;
	float32_t probability;
	float32_t priorprobs[3];
	uint16_t lineCounter;
	ParkingLotType()
	{
		Reset();
	}
	void Reset()
	{
		PLType = ParkingSlotType_E_PW_NODIR;
		probability = 0.0f;
		unsigned int size = (sizeof(priorprobs)) / (sizeof(priorprobs[0]));
		for (unsigned int i = 0; i < size; i++)
		{
			priorprobs[i] = 0.0f;
		}
		lineCounter = 0;
	}
} ParkingLotType_t;

typedef struct ParkingSlotCoordinatesImage
{
	ParkingSlotCoordinatesImage() : C1_tvg(0.0f, 0.0f),
									C2_tvg(0.0f, 0.0f),
									C3_tvg(0.0f, 0.0f),
									C4_tvg(0.0f, 0.0f)
	{
		Reset();
	}
	void Reset()
	{
		C1_tvg.x = 0.0f, C1_tvg.y = 0.0f;
		C2_tvg.x = 0.0f, C2_tvg.y = 0.0f;
		C3_tvg.x = 0.0f, C3_tvg.y = 0.0f;
		C4_tvg.x = 0.0f, C4_tvg.y = 0.0f;
	}
	Point2f C1_tvg;
	Point2f C2_tvg;
	Point2f C3_tvg;
	Point2f C4_tvg;
} eParkingSlotCordImg_t;

typedef struct ParkingSlotInformation
{
	ParkingSlotInformation() :
		m_SelectedSlot(false),
		m_SlotType(ParkingSlotType_t::ParkingSlotType_E_PW_NODIR),
		m_SlotSide(SlotSide_t::SlotSide_E_SLOT_NULL),
		m_ParkingSlotID(ParkingSlotID_t::ParkingSlotID_E_NONE),
		m_ParkingDirection(ParkINStyle_t::ParkINStyle_E_CAR_IN_NULL)
	{
		Reset();
	}
	void Reset()
	{
		m_SelectedSlot = (false);
		m_SlotType = (ParkingSlotType_t::ParkingSlotType_E_PW_NODIR);
		m_SlotSide = (SlotSide_t::SlotSide_E_SLOT_NULL);
		m_ParkingSlotID = (ParkingSlotID_t::ParkingSlotID_E_NONE);
		m_ParkingDirection = (ParkINStyle_t::ParkINStyle_E_CAR_IN_NULL);
		m_ParkingCoordinates_tvg.Reset();
		m_ParkingCoordinates_Real.Reset();
		m_ParkingCoordinates_Global_Locked.Reset();
	}
	bool_t m_SelectedSlot;
	ParkingSlotType_t m_SlotType;
	SlotSide_t m_SlotSide;
	ParkingSlotID_t m_ParkingSlotID;
	ParkINStyle_t m_ParkingDirection;
	ParkingSlotCoordinatesWorld m_ParkingCoordinates_Real;
	ParkingSlotCoordinatesWorld m_ParkingCoordinates_Global_Locked;
	ParkingSlotCoordinatesImage m_ParkingCoordinates_tvg;

} ParkingSlotInfo_t;

typedef struct ParkingInterCommunication
{
	ParkingInterCommunication() :
		m_ParkState(eAutoParkingState_t::eAutoParkingState_E_PW_APS_IDLE),
		m_resetKM(false)
	{
		Reset();
	}
	void Reset()
	{
		m_ParkState = eAutoParkingState_t::eAutoParkingState_E_PW_APS_IDLE;
		m_resetKM = false;
		m_LockedSlotInformation.Reset();
	}
	eAutoParkingState_t m_ParkState;
	bool m_resetKM;
	ParkingSlotInformation m_LockedSlotInformation;
} eParkingInterComm_t;

struct STRectangle
{
	Point2f Vertices[4];
	Point2f openCenter;
	float32_t Angle;
	float32_t Width;
	float32_t Depth;
	STRectangle():Angle(0.0f)
	{
		Reset();
	}
	void Reset()
	{
		for (unsigned int i = 0; i < sizeof(Vertices) / sizeof(Vertices[0]); i++)
		{
			Vertices[i].x = Vertices[i].y = 0.0f;
		}
		openCenter.x = openCenter.y = 0.0f;
		Angle = 0.0f;
		Width = 0.0f;
		Depth = 0.0f;
	}
};

struct Quadrilateral
{
	bool_t valid;
	uint8_t SlotID;
	ParkingSlotType_t m_SlotType;
	Point2f Vertices[4];
	Point2f GlobalVertices[4];
	void Reset()
	{
		valid = false;
		SlotID = 0;
		for (unsigned int i = 0; i < sizeof(Vertices) / sizeof(Vertices[0]); i++)
		{
			Vertices[i].x = Vertices[i].y = 0.0f;
		}
		for (unsigned int i = 0; i < sizeof(GlobalVertices) / sizeof(GlobalVertices[0]); i++)
		{
			GlobalVertices[i].x = GlobalVertices[i].y = 0.0f;
		}
	}

	Quadrilateral()
	{
		Reset();
	}
};

struct parkline
{
	Point2f strtpoint;
	Point2f endpoint;
	Point2f Globalstrtpoint;
	Point2f Globalendpoint;
	uint16_t no_pnts;
	uint8_t confidence;
	bool_t valid;
	float32_t angle;
	float32_t length;
	bool_t aligned;
	uint8_t LineID;
	parkline():LineID(0)
	{
		Reset();
	}
	void Reset()
	{
		strtpoint.x = strtpoint.y = 0.0f;
		endpoint.x = endpoint.y = 0.0f;
		Globalstrtpoint.x = Globalstrtpoint.y = 0.0f;
		Globalendpoint.x = Globalendpoint.y = 0.0f;
		no_pnts = 0;
		confidence = 0;
		valid = false;
		angle = 0.0f;
		length = 0.0f;
		aligned = false;
		LineID = 0;

	}
};

typedef struct DETParkLine
{
	bool_t IsPLExcist;
	uint8_t status;
	Point2f HeadPt; //start point
	Point2f TailPt; //end point
	Point2f GlobalHeadPt; //start point
	Point2f GlobalTailPt; //end point
	float32_t LineLength;
	float32_t LineAngle;
	float32_t lineDetectionScore;
	ROI_DIRECTION Linedirection;
	DETParkLine():status(0)
	{
		Reset();
	}
	void Reset()
	{
		IsPLExcist = false;
		status = 0;
		HeadPt.x = HeadPt.y = 0; //start point
		TailPt.x = TailPt.y = 0; //end point
		GlobalHeadPt.x = GlobalHeadPt.y = 0; //start point
		GlobalTailPt.x = GlobalTailPt.y = 0; //end point
		LineLength = 0.0f;
		LineAngle = 0.0f;
		lineDetectionScore = 0.0f;
		Linedirection = LEFT;
	}
} DETParkLine_t;

struct ROIRegion
{
	ROI_TYPE roi_type;
	ROI_DIRECTION roi_direction;
	float32_t roi_angle_rad;
	Recti roi_rect;
	Point2i roi_pts[4];
	ROIRegion() :roi_angle_rad(0.0f)
	{
		Reset();
	}
	void Reset()
	{
		roi_type = ROI_Perp;
		roi_direction = LEFT;
		roi_angle_rad = 0.0f;
		roi_rect = { 0,0,0,0 };
		for (unsigned int i = 0; i < sizeof(roi_pts) / sizeof(roi_pts[0]); i++)
		{
			roi_pts[i].x = roi_pts[i].y = 0;
		}
	}
};



struct objectEdge
{
	Point2f center;
	float32_t curvature;
	Point2f endpoints[2];
	float32_t fit_err;
	float32_t hitratio;
	uint16_t numPoint;
	bool_t isCurve;
	bool_t valid;
	objectEdge():numPoint(0)
	{
		Reset();
	}
	void Reset()
	{
		center.x = center.y = 0.0f;
		curvature = 0.0f;
		for (unsigned int i = 0; i < sizeof(endpoints) / sizeof(endpoints[0]); i++)
		{
			endpoints[i].x = endpoints[i].y = 0.0f;
		}
		fit_err = 0.0f;
		hitratio = 0.0f;
		numPoint = 0;
		isCurve = false;
		valid = false;
	}
};

struct USSObjectPos
{
	USSObjectPos() :
		X_mm(0.0f),
		Y_mm(0.0f),
		Z_mm(0.0f)
	{	
		Reset();
	}
	float X_mm;
	float Y_mm;
	float Z_mm;
	
	void Reset()
	{
		X_mm = 0.0f;
		Y_mm = 0.0f;
		Z_mm = 0.0f;
	}
};

struct SensorData
{
	SensorData() :
		row(0),
		column(0),
		hitcount(0),
		valid(false),
		//objectPos(),
		SensorID(eUPASensorSource_E_CS_UPA_MAX)
	{
		Reset();
	}
	uint16_t row;
	uint16_t column;
	uint16_t hitcount;
	bool_t valid;
	//USSObjectPos objectPos;
	eUPASensorSource SensorID;

	void Reset()
	{
		row = 0;
		column = 0;
		hitcount = 0;
		valid = false;
		//objectPos.Reset();
		SensorID = eUPASensorSource_E_CS_UPA_MAX;
	}
};


struct UsblSlot
{
	Point2f Vertices[4];
	Point2f GlobalVertices[4];
	bool_t valid;
	SensorType_t SensType;
	ParkingSlotType_t m_SlotType;
	uint8_t SVSSlotID;
	uint8_t USSSlotID;
	STRectangle FittedRect;
	UsblSlot()
	{
		Reset();
	}
	void Reset()
	{
		SensType = SensorType::None;
		m_SlotType = ParkingSlotType_t::ParkingSlotType_E_PW_NODIR;
		valid = false;
		SVSSlotID = 0;
		USSSlotID = 0;
		FittedRect.Reset();
		for (unsigned int i = 0; i < sizeof(Vertices) / sizeof(Vertices[0]); i++)
		{
			Vertices[i].x = Vertices[i].y = 0.0f;
			GlobalVertices[i].x = GlobalVertices[i].y = 0.0f;
		}
	}
};

struct ParkingSlotData
{
	/*
	@@ SUB_STRUCTURE = Vertices
	@@ STRUCTURE = ParkingSlotData
	@@ DATA_TYPE = STRUCTURE Point2f
	@@ DIMENSION = 4 SPLIT
	@@ END
	*/
	Point2f Vertices[4];				//All 4 top view image coordinates of a parking slot rectangle
	/*
	@@ ELEMENT = m_SlotType
	@@ STRUCTURE = ParkingSlotData
	@@ A2L_TYPE = PARAMETER 
	@@ DATA_TYPE = UBYTE
	@@ END
	*/
	ParkingSlotType_t m_SlotType;		//Perp/Parallel/FishBone
	/*
	@@ ELEMENT = m_SlotSide
	@@ STRUCTURE = ParkingSlotData
	@@ A2L_TYPE = PARAMETER 
	@@ DATA_TYPE = UBYTE
	@@ END
	*/
	SlotSide_t m_SlotSide;				//Slot Left/Right Side
	/*
	@@ ELEMENT = m_SlotID
	@@ STRUCTURE = ParkingSlotData
	@@ A2L_TYPE = PARAMETER 
	@@ DATA_TYPE = UBYTE
	@@ END
	*/
	ParkingSlotID_t m_SlotID;				//Slot ID L1-L3/R1-R3
	/*
	@@ ELEMENT = m_isSlotValid_b
	@@ STRUCTURE = ParkingSlotData
	@@ A2L_TYPE = PARAMETER 
	@@ DATA_TYPE = UBYTE [0 ... 1]
	@@ END
	*/
	bool_t m_isSlotValid_b;				//Check the validity of slot
	ParkingSlotData():m_isSlotValid_b(false)
	{
		Reset();
	}
	void Reset()
	{
		m_SlotType = ParkingSlotType_E_PW_NODIR;
		m_SlotSide = SlotSide_E_SLOT_NULL;
		m_SlotID = ParkingSlotID_E_NONE;
		m_isSlotValid_b = false;
		for (unsigned int i = 0; i < sizeof(Vertices) / sizeof(Vertices[0]); i++)
		{
			Vertices[i].x = Vertices[i].y = 0.0f;
		}
	}
};

typedef struct NVMSignalManager_s
{
	/*
	@@ ELEMENT = m_ReadNVMParam_b
	@@ STRUCTURE = NVMSignalManager_t
	@@ A2L_TYPE = PARAMETER
	@@ DATA_TYPE = UBYTE [0 ... 1]
	@@ END
	*/
	bool_t m_ReadNVMParam_b;
	/*
	@@ ELEMENT = m_WriteNVMParam_b
	@@ STRUCTURE = NVMSignalManager_t
	@@ A2L_TYPE = PARAMETER
	@@ DATA_TYPE = UBYTE [0 ... 1]
	@@ END
	*/
	bool_t m_WriteNVMParam_b;
	/*
	@@ ELEMENT = m_ParkINStyle_e
	@@ STRUCTURE = NVMSignalManager_t
	@@ A2L_TYPE = PARAMETER
	@@ DATA_TYPE = UBYTE 
	@@ END
	*/
	ParkINStyle_t m_ParkINStyle_e;
	/*
	@@ ELEMENT = m_ParkInSlotData
	@@ STRUCTURE = NVMSignalManager_t
	@@ A2L_TYPE = PARAMETER
	@@ DATA_TYPE = STRUCTURE ParkingSlotData
	@@ END
	*/
	ParkingSlotData m_ParkInSlotData;
	NVMSignalManager_s():m_WriteNVMParam_b(false)
	{
		Reset();
	}

	void Reset()
	{
		m_ReadNVMParam_b = false;
		m_WriteNVMParam_b = false;
		m_ParkINStyle_e = ParkINStyle_E_CAR_IN_NULL;
	}
}NVMSignalManager_t;

typedef struct JobPLDOutput_s
{
	/*
	@@ ELEMENT = isPLDInitSuccess_b
	@@ STRUCTURE = JobPLDOutput_t
	@@ A2L_TYPE = PARAMETER
	@@ DATA_TYPE = UBYTE [0 ... 1]
	@@ END
	*/
	bool_t isPLDInitSuccess_b; 					//PLD Success/Fail
	/*
	@@ SUB_STRUCTURE = stPLDParkingSlotData
	@@ STRUCTURE = JobPLDOutput_t
	@@ DATA_TYPE = STRUCTURE ParkingSlotData
	@@ DIMENSION = 6 SPLIT
	@@ END
	*/
	ParkingSlotData stPLDParkingSlotData[6];	// ParkingSlotData Left and right park slot coordinates info in image coordinates sent to FPA module
	/*
	@@ SUB_STRUCTURE = stPLDLockedSlotData
	@@ STRUCTURE = JobPLDOutput_t
	@@ DATA_TYPE = STRUCTURE ParkingSlotData
	@@ END
	*/
	ParkingSlotData stPLDLockedSlotData;		//ParkingSlotData Locked + tracked slot coordinate info in image coordinates sent to FPA module
	JobPLDOutput_s()
	{
		Reset();
	}
	void Reset()
	{
		isPLDInitSuccess_b = false;
		for (uint8_t nItr = 0; nItr < 6; ++nItr)
		{
			stPLDParkingSlotData[nItr].Reset();
		}
		stPLDLockedSlotData.Reset();
	}
}JobPLDOutput_t;

typedef struct JobUSSObjectMapOutput_s
{
	/*
	@@ ELEMENT = isUSSOMInitSuccess_b
	@@ STRUCTURE = JobUSSObjectMapOutput_t
	@@ A2L_TYPE = PARAMETER
	@@ DATA_TYPE = UBYTE [0 ... 1]
	@@ END
	*/
	bool_t isUSSOMInitSuccess_b;				//Status of USSOM init Success/Fail
	/*
	@@ SUB_STRUCTURE = stUSSParkingSlotData
	@@ STRUCTURE = JobUSSObjectMapOutput_t
	@@ DATA_TYPE = STRUCTURE ParkingSlotData
	@@ DIMENSION = 6 SPLIT
	@@ END
	*/
	ParkingSlotData stUSSParkingSlotData[6];	//Left and right park slot coordinates info in image coordinates sent to FPA module
	/*
	@@ ELEMENT = isUSSOMInitSuccess_b
	@@ STRUCTURE = JobUSSObjectMapOutput_t
	@@ A2L_TYPE = PARAMETER
	@@ DATA_TYPE = UWORD
	@@ END
	*/
	uint16_t numPointsL;						//Count of the points at left side sent to FPA - This has been added as FPA uses data currently
	/*
	@@ ELEMENT = isUSSOMInitSuccess_b
	@@ STRUCTURE = JobUSSObjectMapOutput_t
	@@ A2L_TYPE = PARAMETER
	@@ DATA_TYPE = UWORD
	@@ END
	*/
	uint16_t numPointsR;						//Count of the points at right side sent to FPA- This has been added as FPA uses data currently
	/*
	@@ SUB_STRUCTURE = LeftObjectList
	@@ STRUCTURE = JobUSSObjectMapOutput_t
	@@ DATA_TYPE = STRUCTURE objectEdge
	@@ DIMENSION = 4 SPLIT
	@@ END
	*/
	objectEdge LeftObjectList[DEFAULT_AVAILABLE_VehicleEdges];				//Keeps Left object edge information
	/*
	@@ SUB_STRUCTURE = RightObjectList
	@@ STRUCTURE = JobUSSObjectMapOutput_t
	@@ DATA_TYPE = STRUCTURE objectEdge
	@@ DIMENSION = 4 SPLIT
	@@ END
	*/
	objectEdge RightObjectList[DEFAULT_AVAILABLE_VehicleEdges];				//Keeps right object edge information
	/*
	@@ SUB_STRUCTURE = Left2Dpoints
	@@ STRUCTURE = JobUSSObjectMapOutput_t
	@@ DATA_TYPE = STRUCTURE Point2i
	@@ DIMENSION = 400 SPLIT
	@@ END
	*/
	Point2i Left2Dpoints[400];					//array of the 2D points at left side sent to FPA- This has been added as FPA uses data currently
	/*
	@@ SUB_STRUCTURE = Right2Dpoints
	@@ STRUCTURE = JobUSSObjectMapOutput_t
	@@ DATA_TYPE = STRUCTURE Point2i
	@@ DIMENSION = 400 SPLIT
	@@ END
	*/
	Point2i Right2Dpoints[400];					//array of the 2D points at right side sent to FPA- This has been added as FPA uses data currently
	/*
	@@ SUB_STRUCTURE = stUSSLockedSlotData
	@@ STRUCTURE = JobUSSObjectMapOutput_t
	@@ DATA_TYPE = STRUCTURE ParkingSlotData
	@@ END
	*/
	ParkingSlotData stUSSLockedSlotData; 		//Locked park slot coordinates info in image coordinates sent to FPA module
	/*
	@@ SUB_STRUCTURE = sensorData
	@@ STRUCTURE = JobUSSObjectMapOutput_t
	@@ DATA_TYPE = STRUCTURE SensorData
	@@ DIMENSION = 400 SPLIT
	@@ END
	*/
	SensorData sensorData[400];						//USS Points information

	JobUSSObjectMapOutput_s()
	{
		Reset();
	}
	void Reset()
	{
		isUSSOMInitSuccess_b = false;

		numPointsL = numPointsR = 0;
		for (uint8_t nItr = 0; nItr < DEFAULT_AVAILABLE_VehicleEdges; ++nItr)
		{
			LeftObjectList[nItr].Reset();
			RightObjectList[nItr].Reset();
		}
		for (unsigned int i = 0; i < sizeof(Left2Dpoints) / sizeof(Left2Dpoints[0]); i++)
		{
			Left2Dpoints[i].x = Left2Dpoints[i].y = 0;
		}
		for (unsigned int i = 0; i < sizeof(Right2Dpoints) / sizeof(Right2Dpoints[0]); i++)
		{
			Right2Dpoints[i].x = Right2Dpoints[i].y = 0;
		}

		for (uint8_t nItr = 0; nItr < 6; ++nItr)
		{
			stUSSParkingSlotData[nItr].Reset();
		}
		stUSSLockedSlotData.Reset();
	}
}JobUSSObjectMapOutput_t;


	typedef struct FPAInfoToVC_s
	{
		/*
		@@ SUB_STRUCTURE = stFPALockedSlotData
		@@ STRUCTURE = FPAInfoToVC_t
		@@ DATA_TYPE = STRUCTURE ParkingSlotData
		@@ END
		*/
		ParkingSlotData stFPALockedSlotData;		//VehicleCoordinates and other details 
		float32_t LockedSlotWidth;
		float32_t LockedSlotDepth;
													/*
		@@ ELEMENT = ParkOutStyle_t
		@@ STRUCTURE = FPAInfoToVC_t
		@@ A2L_TYPE = PARAMETER
		@@ DATA_TYPE = UBYTE
		@@ END
		*/
		ParkOutStyle_t parkOutStyle;

		FPAInfoToVC_s() :parkOutStyle(ParkOutStyle_E_CAR_OUT_NULL)
		{
			Reset();
		}
		void Reset()
		{
			parkOutStyle = ParkOutStyle_E_CAR_OUT_NULL;
			LockedSlotWidth = 0;
			LockedSlotDepth = 0;
			stFPALockedSlotData.Reset();
		}
	}FPAInfoToVC_t;

	typedef	struct FPAInfoToHMI_s
	{
		/*
		@@ SUB_STRUCTURE = stFPAParkingSlotData
		@@ STRUCTURE = FPAInfoToHMI_t
		@@ DATA_TYPE = STRUCTURE ParkingSlotData
		@@ DIMENSION = 6 SPLIT
		@@ END
		*/
		ParkingSlotData stFPAParkingSlotData[6];	//Vehicle Coordinates

		/*
		@@ SUB_STRUCTURE = stFPALockedSlotData
		@@ STRUCTURE = FPAInfoToHMI_t
		@@ DATA_TYPE = STRUCTURE ParkingSlotData
		@@ END
		*/
		ParkingSlotData stFPALockedSlotData;	//VehicleCoordinates
		float32_t LockedSlotWidth;
		float32_t LockedSlotDepth;
		/*
		@@ ELEMENT = ParkOutEnableFlag
		@@ STRUCTURE = FPAInfoToHMI_t
		@@ A2L_TYPE = PARAMETER
		@@ DATA_TYPE = UBYTE [0 ... 1]
		@@ END
		*/
		bool_t m_Parkable[6];
		bool_t ParkOutEnableFlag;				//ParkOut Enable Flag

		FPAInfoToHMI_s() :ParkOutEnableFlag(false)
		{
			Reset();
		}
		void Reset()
		{
			ParkOutEnableFlag = false;
			LockedSlotWidth = 0;
			LockedSlotDepth = 0;
			for (uint8_t nItr = 0; nItr < 6; ++nItr)
			{
			m_Parkable[nItr] = false;
			stFPAParkingSlotData[nItr].Reset();
			}
			stFPALockedSlotData.Reset();
		}
	}FPAInfoToHMI_t;

	typedef	struct FPAMappingTable_s
	{
		/*
		@@ SUB_STRUCTURE = CombinedInfo
		@@ STRUCTURE = FPAMappingTable_t
		@@ DATA_TYPE = STRUCTURE Point2i_1t
		@@ DIMENSION = 12 SPLIT
		@@ END
		*/
		Point2i_1t CombinedInfo[12];	//both Coordinates
		/*
		@@ ELEMENT = countSlots
		@@ STRUCTURE = FPAMappingTable_t
		@@ A2L_TYPE = PARAMETER
		@@ DATA_TYPE = ULONG
		@@ END
		*/
		uint32_t countSlots;
		void Reset()
		{
			for (uint8_t nItr = 0; nItr < 12; ++nItr)
			{
				CombinedInfo[nItr].Pld = 0;
				CombinedInfo[nItr].Uss = 0;
			}
			countSlots = 0;
		}

		FPAMappingTable_s()
		{
			Reset();
		}

	}FPAMappingTable_t;

	typedef struct FusionMappingTable_s
	{
		uint32_t countSlots;
		UsblSlot LeftSlots[3];
		UsblSlot RightSlots[3];
		void Reset()
		{
			countSlots = 0;
			for (uint8_t i = 0; i < 3; i++)
			{
				LeftSlots[i].Reset();
				RightSlots[i].Reset();
			}
		}
		FusionMappingTable_s()
		{
			Reset();
		}

	} FusionMappingTable_t;

	//Output of HMI to FPA module
	typedef	struct HMIInfoToFPA_s
	{
		/*
		@@ ELEMENT = m_selectedslotID
		@@ STRUCTURE = HMIInfoToFPA_t
		@@ A2L_TYPE = PARAMETER
		@@ DATA_TYPE = UBYTE
		@@ END
		*/
		ParkingSlotID_t m_selectedslotID;		//locked slot ID
		/*
		@@ ELEMENT = VehicleParkDirection
		@@ STRUCTURE = HMIInfoToFPA_t
		@@ A2L_TYPE = PARAMETER
		@@ DATA_TYPE = UBYTE
		@@ END
		*/
		ParkINStyle_t VehicleParkDirection; // RearIN or Front IN
		/*
		@@ ELEMENT = ParkOutSideDirection
		@@ STRUCTURE = HMIInfoToFPA_t
		@@ A2L_TYPE = PARAMETER
		@@ DATA_TYPE = UBYTE
		@@ END
		*/
		SlotSide_t ParkOutSideDirection;
		HMIInfoToFPA_s()
		{
			Reset();
		}
		void Reset()
		{
			m_selectedslotID = ParkingSlotID_E_NONE;
			VehicleParkDirection = ParkINStyle_E_CAR_IN_NULL;
			ParkOutSideDirection = SlotSide_E_SLOT_NULL;
		}
	}HMIInfoToFPA_t;

	typedef	struct FPAInfoToPLD_s
	{
		/*
		@@ ELEMENT = PLDSlotID
		@@ STRUCTURE = FPAInfoToPLD_t
		@@ A2L_TYPE = PARAMETER
		@@ DATA_TYPE = UBYTE
		@@ END
		*/
		ParkingSlotID_t PLDSlotID;				//Locked slot ID output sent to PLD module (R5 to A72)
		FPAInfoToPLD_s()
		{
			Reset();
		}
		void Reset()
		{
			PLDSlotID = ParkingSlotID_E_NONE;
		}
	}FPAInfoToPLD_t;

	typedef	struct FPAInfoToUSSOM_s
	{
		/*
		@@ ELEMENT = USSOMSlotID
		@@ STRUCTURE = FPAInfoToUSSOM_t
		@@ A2L_TYPE = PARAMETER 
		@@ DATA_TYPE = UBYTE
		@@ END
		*/
		ParkingSlotID_t USSOMSlotID;			//Locked slot ID output sent to USSOM module(R5 to R5)
		/*
		@@ SUB_STRUCTURE = ParkOutSlotData
		@@ STRUCTURE = FPAInfoToUSSOM_t
		@@ DATA_TYPE = STRUCTURE ParkingSlotData
		@@ END
		*/
		ParkingSlotData ParkOutSlotData;
		FPAInfoToUSSOM_s()
		{
			Reset();
		}
		void Reset()
		{
			USSOMSlotID = ParkingSlotID_E_NONE;
		}
	}FPAInfoToUSSOM_t;

	// FPA Output consolidated in structure for other modules
	typedef struct JobFPAOutput_s
	{
		/*
		@@ ELEMENT = AutoParkInitializedStatus_b
		@@ STRUCTURE = JobFPAOutput_t
		@@ A2L_TYPE = PARAMETER
		@@ DATA_TYPE = UBYTE [0 ... 1]
		@@ END
		*/
		bool_t AutoParkInitializedStatus_b;		//Status of Autopark initialization	
		/*
		@@ SUB_STRUCTURE = m_FpaInfoToVC
		@@ STRUCTURE = JobFPAOutput_t
		@@ DATA_TYPE = STRUCTURE FPAInfoToVC_t
		@@ END
		*/
		FPAInfoToVC_t m_FpaInfoToVC;			//FPA output data to Vehicle control module<IPC signal name:IFPAInfoToVC_t>
		/*
		@@ SUB_STRUCTURE = m_FPAInfoToPLD
		@@ STRUCTURE = JobFPAOutput_t
		@@ DATA_TYPE = STRUCTURE FPAInfoToPLD_t
		@@ END
		*/
		FPAInfoToPLD_t m_FPAInfoToPLD;			//FPA output data to PLD module <IPC signal name:IFPAInfoToPLD_t>
		/*
		@@ SUB_STRUCTURE = m_FPAInfoToUSSOM
		@@ STRUCTURE = JobFPAOutput_t
		@@ DATA_TYPE = STRUCTURE FPAInfoToUSSOM_t
		@@ END
		*/
		FPAInfoToUSSOM_t m_FPAInfoToUSSOM;		//FPA output data to USSOM module <IPC signal name: IFPAInfoToUSSOM_t>
		/*
		@@ SUB_STRUCTURE = m_FPAInfoToHMI
		@@ STRUCTURE = JobFPAOutput_t
		@@ DATA_TYPE = STRUCTURE FPAInfoToHMI_t
		@@ END
		*/
		FPAInfoToHMI_t m_FPAInfoToHMI;			//FPA output data to HMI module<IPC signal name:IFPAInfoToHMI_t>
		/*
		@@ SUB_STRUCTURE = m_FPAToNVM
		@@ STRUCTURE = JobFPAOutput_t
		@@ DATA_TYPE = STRUCTURE NVMSignalManager_t
		@@ END
		*/
		NVMSignalManager_t m_FPAToNVM;			//FPA I/O interface with NVM Manager
#if 1//Windows_Debug_Display
		FPAMappingTable_t m_mapTableLeft;
		FPAMappingTable_t m_mapTableRight;
#endif
		JobFPAOutput_s()
		{
			Reset();
		}
		void Reset()
		{
			AutoParkInitializedStatus_b = false;
			m_FpaInfoToVC.Reset();
			m_FPAInfoToPLD.Reset();
			m_FPAInfoToUSSOM.Reset();
			m_FPAInfoToHMI.Reset();
			//m_FPAToNVM.Reset();
		}
	}JobFPAOutput_t;


#endif // !MULTIPLATCOMMON_H
