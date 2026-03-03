#ifndef MRR_IPC_SIGNAL_GROUPING_H
# define MRR_IPC_SIGNAL_GROUPING_H 

typedef struct
{
  float32 RadarAnglAzimuth;
  float32 RadarAnglElevation;
  float32 RadarPosX;
  float32 RadarPosY;
  float32 RadarPosZ;
  uint8 RadarAnglAzimuthSt;
  uint8 RadarAnglElevationSt;
  uint8 RadarFuncCfg;
  uint8 RadarPosXSt;
  uint8 RadarPosYSt;
  uint8 RadarPosZSt;
  uint8 RadarRoleConfig;
  uint8 dummy[1];
} ts_mrr_radar_config_data;

typedef struct
{
  uint32 MRRTimestampNSec;
  uint32 MRRTimestampSec;
  uint16 ObjectTimestampNSec;
  uint16 ObjectTimestampSec;
  uint8 BlockageProb;
  uint8 BlockageStatus;
  uint8 MRRTimesyncStatus;
  uint8 NumberOfObjects;
  uint8 RadarScanID;
  uint8 SafetyDistance;
  uint8 SensorStatus;
  uint8 TunnelDistance;
  uint8 TunnelPresence;
  uint8 TunnelProb;
  uint8 dummy[2];
} ts_mrr_radar_info_data;

typedef struct
{
  float32 RoadBorderAngleLt;
  float32 RoadBorderAngleRt;
  float32 RoadBorderInitialCurvatureGradLt;
  float32 RoadBorderInitialCurvatureGradRt;
  float32 RoadBorderInitialCurvatureLt;
  float32 RoadBorderInitialCurvatureRt;
  float32 RoadBorderMaxRangeLt;
  float32 RoadBorderMaxRangeRt;
  float32 RoadBorderOffsetXLt;
  float32 RoadBorderOffsetXRt;
  float32 RoadBorderOffsetYLt;
  float32 RoadBorderOffsetYRt;
  float32 RoadBorderSecondCurvatureGradLt;
  float32 RoadBorderSecondCurvatureGradRt;
  float32 RoadBorderTransitionPointLt;
  float32 RoadBorderTransitionPointRt;
  uint32 RoadBorderTimestampNSec;
  uint16 RoadBorderTimestampSec;
  uint8 RoadBorderConfidenceLt;
  uint8 RoadBorderConfidenceRt;
  uint8 RoadBorderScanID;
  uint8 RoadBorderStLt;
  uint8 RoadBorderStRt;
  uint8 dummy[3];
} ts_mrr_road_border_data;

typedef struct
{
  float32 ObjectDistanceStdDevX_xx;
  float32 ObjectDistanceStdDevY_xx;
  float32 ObjectDistanceX_xx;
  float32 ObjectDistanceY_xx;
  float32 ObjectLength_xx;
  float32 ObjectLengthStdDev_xx;
  float32 ObjectRelAccelerationStdDevX_xx;
  float32 ObjectRelAccelerationStdDevY_xx;
  float32 ObjectRelAccelerationX_xx;
  float32 ObjectRelAccelerationY_xx;
  float32 ObjectRelVelocityStdDevX_xx;
  float32 ObjectRelVelocityStdDevY_xx;
  float32 ObjectRelVelocityX_xx;
  float32 ObjectRelVelocityY_xx;
  float32 ObjectWidth_xx;
  float32 ObjectWidthStdDev_xx;
  float32 ObjectYawAngle_xx;
  float32 ObjectYawAngleStdDev_xx;
  float32 ObjectYawRate_xx;
  float32 ObjectYawRateStdDev_xx;
  uint16 ObjectAge_xx;
  uint16 ObjectID_xx;
  uint16 ObjectMeasStatus_xx;
  sint8 ObjectDistanceCovXY_xx;
  sint8 ObjectRCS_xx;
  sint8 ObjectRelAccelerationCovXY_xx;
  sint8 ObjectRelVelocityCovXY_xx;
  uint8 ObjectClass_xx;
  uint8 ObjectClassConfidence_xx;
  uint8 ObjectConfidence_xx;
  uint8 ObjectFuSaLevel_xx;
  uint8 ObjectLengthSt_xx;
  uint8 ObjectMotionSt_xx;
  uint8 ObjectOverUnderDrivable_xx;
  uint8 ObjectOverUnderDriveableConf_xx;
  uint8 ObjectRefPoint_xx;
  uint8 ObjectWidthSt_xx;
  uint8 ScanID_xx;
  uint8 dummy[3];
} ts_object_data_xx;

typedef ts_object_data_xx mrr_object_data_xx[32];

typedef struct
{
  mrr_object_data_xx mrr_object_data_xx;
} ts_mrr_xx_object_data;

typedef struct
{
  ts_mrr_xx_object_data object_data_xx;
  ts_mrr_radar_config_data radar_config_data_xx;
  ts_mrr_radar_info_data radar_info_data_xx;
  ts_mrr_road_border_data road_border_data_xx;
} ts_mrr_xx_data;

/*  MSG ID 0x04 front center radar */
typedef struct
{
  ts_mrr_xx_data ipc_FrontCenterData;
} ts_mrr_FrontCenter_data;

/* MSG ID 0x05 front corner group */
typedef struct
{
  ts_mrr_xx_data ipc_FrontLeftCornerData;
  ts_mrr_xx_data ipc_FrontRightCornerData;
} ts_mrr_FrontCornerGroup_data;

/* MSG ID 0x06 rear corner group */
typedef struct
{
  ts_mrr_xx_data ipc_RearLeftCornerData;
  ts_mrr_xx_data ipc_RearRightCornerData;
} ts_mrr_RearCornerGroup_data;


typedef enum
{
    IObjectDistanceCovXY00 = 0u,
    IObjectDistanceCovXY01,
    IObjectDistanceCovXY02,
    IObjectDistanceCovXY03,
    IObjectDistanceCovXY04,
    IObjectDistanceCovXY05,
    IObjectDistanceCovXY06,
    IObjectDistanceCovXY07,
    IObjectDistanceCovXY08,
    IObjectDistanceCovXY09,
    IObjectDistanceCovXY10,
    IObjectDistanceCovXY11,
    IObjectDistanceCovXY12,
    IObjectDistanceCovXY13,
    IObjectDistanceCovXY14,
    IObjectDistanceCovXY15,
    IObjectDistanceCovXY16,
    IObjectDistanceCovXY17,
    IObjectDistanceCovXY18,
    IObjectDistanceCovXY19,
    IObjectDistanceCovXY20,
    IObjectDistanceCovXY21,
    IObjectDistanceCovXY22,
    IObjectDistanceCovXY23,
    IObjectDistanceCovXY24,
    IObjectDistanceCovXY25,
    IObjectDistanceCovXY26,
    IObjectDistanceCovXY27,
    IObjectDistanceCovXY28,
    IObjectDistanceCovXY29,
    IObjectDistanceCovXY30,
    IObjectDistanceCovXY31,
    ISafetyDistance,
    RoadBorderAngleRt
}e_PrvCANTimeoutMsgIdx;

/* Number of message monitor from MRR */
#define NUM_RX_MSG_MONITOR ((uint8)(RoadBorderAngleRt/8u) +1u)

/* RADAR diagnostic data */
typedef struct
{
    uint8 FCTimeOutStatus[NUM_RX_MSG_MONITOR];
    uint8 FLTimeOutStatus[NUM_RX_MSG_MONITOR];
    uint8 FRTimeOutStatus[NUM_RX_MSG_MONITOR];
    uint8 RLTimeOutStatus[NUM_RX_MSG_MONITOR];
    uint8 RRTimeOutStatus[NUM_RX_MSG_MONITOR];
    uint8 FCSensorStatus;
    uint8 FLSensorStatus;
    uint8 FRSensorStatus;
    uint8 RLSensorStatus;
    uint8 RRSensorStatus;
}ts_RadarDiagData;


#endif
