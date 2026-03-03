

#ifndef ENUMS
#define ENUMS


#ifdef __cplusplus
namespace variants
{
#endif // if cplusplus

typedef enum Language_e
{
      e_LanguageEnglish = 0, // English Language
      e_LanguageGerman = 1, // German Language
      e_LanguageFrench = 2, // French Language
      e_LanguageSpanish = 3, // Spanish Language
      e_LanguageCount = 4, // Number of Enum Elements
      e_LanguageInvalid = 5 // Invalid Entry
} Language_t;

typedef enum Camera_e
{
      e_CameraFront = 0, // Front Camera
      e_CameraLeft = 1, // Left Camera
      e_CameraRear = 2, // Rear Camera
      e_CameraRight = 3, // Right Camera
      e_CameraChmsl = 4, // todo
      e_CameraCount = 5, // Number of Enum Elements
      e_CameraInvalid = 6 // Invalid Entry
} Camera_t;

typedef enum CameraHW_e
{
      e_CameraHWLeft = 0, // Left Camera
      e_CameraHWRight = 1, // Right Camera
      e_CameraHWFront = 2, // Front Camera
      e_CameraHWRear = 3, // Rear Camera
} CameraHW_t;

typedef enum Coefficients_e
{
      e_Coeff0 = 0, // just used for index
      e_Coeff1 = 1, // just used for index
      e_Coeff2 = 2, // just used for index
      e_Coeff3 = 3, // just used for index
      e_Coeff4 = 4, // just used for index
      e_Coeff5 = 5, // just used for index
      e_CoefficientsCount = 6, // Number of Enum Elements
      e_CoefficientsInvalid = 7 // Invalid Entry
} Coefficients_t;


typedef enum PreRoll_e
{
      e_PreRoll0 = 0, // todo
      e_PreRoll90 = 1, // todo
      e_PreRoll180 = 2, // todo
      e_PreRoll270 = 3, // todo
      e_PreRollCount = 4, // Number of Enum Elements
      e_PreRollInvalid = 5 // Invalid Entry
} PreRoll_t;


typedef enum RotationType_e
{
      e_WorldToCamera = 0, // todo
      e_CameraToWorld = 1, // todo
      e_RotationTypeCount = 2, // Number of Enum Elements
      e_RotationTypeInvalid = 3 // Invalid Entry
} RotationType_t;


typedef enum ImageOriginPosition_e
{
      e_UpperLeft = 0, // todo
      e_UpperRight = 1, // todo
      e_LowerLeft = 2, // todo
      e_LowerRight = 3, // todo
      e_ImageOriginPositionCount = 4, // Number of Enum Elements
      e_ImageOriginPositionInvalid = 5 // Invalid Entry
} ImageOriginPosition_t;


typedef enum CameraDevice_e
{
      e_SpiFlashW25Q40 = 0, // todo
      e_SerializerCXD4963ER = 1, // todo
      e_DeserializerCXD4960ER = 2, // todo
      e_ImagerAS0149AT = 3, // todo
      e_CameraDeviceCount = 4, // Number of Enum Elements
      e_CameraDeviceInvalid = 5 // Invalid Entry
} CameraDevice_t;


typedef enum CameraPowerMode_e
{
      e_CameraPowerModeOff = 0, // todo
      e_CameraPowerModeOn = 1, // todo
      e_CameraPowerModeSleep = 2, // todo
      e_CameraPowerModeCount = 3, // Number of Enum Elements
      e_CameraPowerModeInvalid = 4 // Invalid Entry
} CameraPowerMode_t;


typedef enum CameraPrbsTestState_e
{
      e_CameraPrbsTestStateStarted = 0, // todo
      e_CameraPrbsTestStateNotStarted = 1, // todo
      e_CameraPrbsTestStateSuccessful = 2, // todo
      e_CameraPrbsTestStateNotSuccessful = 3, // todo
      e_CameraPrbsTestStateCount = 4, // Number of Enum Elements
      e_CameraPrbsTestStateInvalid = 5 // Invalid Entry
} CameraPrbsTestState_t;


typedef enum ViewId_e
{
      e_ServiceHelper_E_HMIView_NoView  = 0, // todo
      e_ServiceHelper_E_HMIView_FRONT_TOP_ALL = 1, // todo
      e_ServiceHelper_E_HMIView_FRONT_TOP_FL = 2, // todo
      e_ServiceHelper_E_HMIView_FRONT_TOP_FR = 3, // todo
      e_ServiceHelper_E_HMIView_FRONT_TOP_RL = 4, // todo
      e_ServiceHelper_E_HMIView_FRONT_TOP_RR = 5, // todo
      e_ServiceHelper_E_HMIView_FRONT_SPLIT_TOP_ALL = 6, // todo
      e_ServiceHelper_E_HMIView_FRONT_SPLIT_TOP_FL = 7, // todo
      e_ServiceHelper_E_HMIView_FRONT_SPLIT_TOP_FR = 8, // todo
      e_ServiceHelper_E_HMIView_FRONT_SPLIT_TOP_RL = 9, // todo
      e_ServiceHelper_E_HMIView_FRONT_SPLIT_TOP_RR = 10, // todo
      e_ServiceHelper_E_HMIView_REAR_TOP_ALL = 11, // todo
      e_ServiceHelper_E_HMIView_REAR_TOP_FL = 12, // todo
      e_ServiceHelper_E_HMIView_REAR_TOP_FR = 13, // todo
      e_ServiceHelper_E_HMIView_REAR_TOP_RL = 14, // todo
      e_ServiceHelper_E_HMIView_REAR_TOP_RR = 15, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_CENTER_TOP_ALL = 16, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_CENTER_TOP_FL = 17, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_CENTER_TOP_FR = 18, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_CENTER_TOP_RL = 19, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_CENTER_TOP_RR = 20, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_RIGHT_TOP_ALL = 21, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_RIGHT_TOP_FL = 22, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_RIGHT_TOP_FR = 23, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_RIGHT_TOP_RL = 24, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_RIGHT_TOP_RR = 25, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_FAR_RIGHT_TOP_ALL = 26, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_FAR_RIGHT_TOP_FL = 27, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_FAR_RIGHT_TOP_FR = 28, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_FAR_RIGHT_TOP_RL = 29, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_FAR_RIGHT_TOP_RR = 30, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_LEFT_TOP_ALL = 31, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_LEFT_TOP_FL = 32, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_LEFT_TOP_FR = 33, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_LEFT_TOP_RL = 34, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_LEFT_TOP_RR = 35, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_FAR_LEFT_TOP_ALL = 36, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_FAR_LEFT_TOP_FL = 37, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_FAR_LEFT_TOP_FR = 38, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_FAR_LEFT_TOP_RL = 39, // todo
      e_ServiceHelper_E_HMIView_REAR_SPLIT_FAR_LEFT_TOP_RR = 40, // todo
      e_ServiceHelper_E_HMIView_FRONT_FULL = 41, // todo
      e_ServiceHelper_E_HMIView_REAR_WIDE = 42, // todo
      e_ServiceHelper_E_HMIView_BED_ST = 43, // todo
      e_ServiceHelper_E_HMIView_CONFIRM_EXTERIOR = 44, // todo
      e_ServiceHelper_E_HMIView_CONFIRM_EXTERIOR_COLOR = 45, // todo
      e_ServiceHelper_E_HMIView_CONFIRM_INTERIOR = 46, // todo
      e_ServiceHelper_E_HMIView_CONFIRM_INTERIOR_COLOR = 47, // todo
      e_ServiceHelper_E_HMIView_FRONT_SIDE_OVERALL = 48, // todo
      e_ServiceHelper_E_HMIView_FRONT_SIDE_FRONTWHEEL = 49, // todo
      e_ServiceHelper_E_HMIView_UNDERFLOOR_SIDE_OVERALL = 50, // todo
      e_ServiceHelper_E_HMIView_UNDERFLOOR_SIDE_FRONTWHEEL = 51, // todo
      e_ServiceHelper_E_HMIView_BACK_SIDE_OVERALL = 52, // todo
      e_ServiceHelper_E_HMIView_WIDE_BACK = 53, // todo
      e_ServiceHelper_E_HMIView_REAR_NARROW = 54, // todo
      e_ServiceHelper_E_HMIView_HITCH_ZOOM = 55, // todo
      e_ServiceHelper_E_HMIView_QUAD = 56, // todo
      e_ServiceHelper_E_HMIView_TOP_ALL_CALIBRATION = 57, // todo
      e_ServiceHelper_E_HMIView_FRONT_RAW = 58, // todo
      e_ServiceHelper_E_HMIView_LEFT_RAW = 59, // todo
      e_ServiceHelper_E_HMIView_REAR_RAW = 60, // todo
      e_ServiceHelper_E_HMIView_RIGHT_RAW = 61, // todo
      e_ServiceHelper_E_HMIView_CHMSL_RAW = 62, // todo
      e_ViewIdCount = 63, // Number of Enum Elements
      e_ViewIdInvalid = 64 // Invalid Entry
} ViewId_t;


typedef enum VideoFlowType_e
{
      e_ImageVparkEtIncrustations = 0, // todo
      e_ImageVparkAerienne = 1, // todo
      e_VideoFlowTypeCount = 2, // Number of Enum Elements
      e_VideoFlowTypeInvalid = 3 // Invalid Entry
} VideoFlowType_t;


typedef enum AppState_e
{
      e_AppStateInit = 0, // todo
      e_AppStateNormal = 1, // todo
      e_AppStateVariantSwitch = 2, // todo
      e_AppStateCount = 3, // Number of Enum Elements
      e_AppStateInvalid = 4 // Invalid Entry
} AppState_t;


typedef enum Job_e
{
      e_JobSys = 0, // todo
      e_JobAppM = 1, // todo
      e_JobSigM = 2, // todo
      e_JobVarM = 3, // todo
      e_JobLogM = 4, // todo
      e_JobSysMon = 5, // todo
      e_JobOVL3D = 6, // todo
      e_JobTIOVX = 7, // todo
      e_JobEol = 8, // todo
      e_JobOC = 9, // todo
      e_JobCamM = 10, // todo
      e_JobCalSM = 11, // todo
      e_JobTHA = 12, // todo
      e_JobTAD2 = 13, // todo
      e_JobDLD = 14, // todo
      e_JobCount = 15, // Number of Enum Elements
      e_JobInvalid = 16 // Invalid Entry
} Job_t;


typedef enum SpeedrangesE_e
{
      e_Speed0 = 0, // todo
      e_Speed1 = 1, // todo
      e_Speed2 = 2, // todo
      e_Speed3 = 3, // todo
      e_Speed4 = 4, // todo
      e_Speed5 = 5, // todo
      e_SpeedrangesECount = 6, // Number of Enum Elements
      e_SpeedrangesEInvalid = 7 // Invalid Entry
} SpeedrangesE_t;


typedef enum FrameSkipsE_e
{
      e_Frame0 = 0, // todo
      e_Frame1 = 1, // todo
      e_Frame2 = 2, // todo
      e_Frame3 = 3, // todo
      e_Frame4 = 4, // todo
      e_Frame5 = 5, // todo
      e_FrameSkipsECount = 6, // Number of Enum Elements
      e_FrameSkipsEInvalid = 7 // Invalid Entry
} FrameSkipsE_t;


typedef enum ROIPoolE_e
{
      e_ROIPool0 = 0, // todo
      e_ROIPool1 = 1, // todo
      e_ROIPoolECount = 2, // Number of Enum Elements
      e_ROIPoolEInvalid = 3 // Invalid Entry
} ROIPoolE_t;


typedef enum ROIPoolRectE_e
{
      e_ROIPoolRect0 = 0, // todo
      e_ROIPoolRect1 = 1, // todo
      e_ROIPoolRectECount = 2, // Number of Enum Elements
      e_ROIPoolRectEInvalid = 3 // Invalid Entry
} ROIPoolRectE_t;


typedef enum OCErrorCodeE_e
{
      e_OcErrCodeNoError = 0, // todo
      e_OcErrCodeInitFail = 1, // todo
      e_OcErrCodeStartFail = 2, // todo
      e_OcErrCodeFeatureCollectionError = 3, // todo
      e_OcErrCodeCalibrationError = 4, // todo
      e_OcErrCodeInvalidConfiguration = 5, // todo
      e_OcErrCodeInvalidSavedData = 6, // todo
      e_OcErrCodeUnexpectedRequest = 7, // todo
      e_OCErrorCodeECount = 8, // Number of Enum Elements
      e_OCErrorCodeEInvalid = 9 // Invalid Entry
} OCErrorCodeE_t;


typedef enum OCAlgoStateE_e
{
      e_OcStateUninit = 0, // todo
      e_OcStateInitOk = 1, // todo
      e_OcStateError = 2, // todo
      e_OcStateFeatureCollection = 3, // todo
      e_OcStateFeatureCollectionCompleted = 4, // todo
      e_OcStateCalibration = 5, // todo
      e_OcStateCalibrationCompleted = 6, // todo
      e_OcStateTerminated = 7, // todo
      e_OcStatePaused = 8, // todo
      e_OcStateUnknown = 9, // todo
      e_OcStateEnd = 10, // todo
      e_OCAlgoStateECount = 11, // Number of Enum Elements
      e_OCAlgoStateEInvalid = 12 // Invalid Entry
} OCAlgoStateE_t;


typedef enum CalibrationRequestE_e
{
      e_CalibReqNone = 0, // todo
      e_CalibReqStart = 1, // todo
      e_CalibReqStop = 2, // todo
      e_CalibReqPause = 3, // todo
      e_CalibReqResume = 4, // todo
      e_CalibReqStatus = 5, // todo
      e_CalibReqDebug = 6, // todo
      e_CalibrationRequestECount = 7, // Number of Enum Elements
      e_CalibrationRequestEInvalid = 8 // Invalid Entry
} CalibrationRequestE_t;


typedef enum CalibrationTypeE_e
{
      e_CalibTypeNONE = 0, // todo
      e_CalibTypeEOL = 1, // todo
      e_CalibTypeOC = 2, // todo
      e_CalibTypeTEOL = 3, // todo
      e_CalibTypeSC = 4, // todo
      e_CalibTypeSSA = 5, // todo
      e_CalibTypeDSA = 6, // todo
      e_CalibTypeMax = 7, // todo
      e_CalibrationTypeECount = 8, // Number of Enum Elements
      e_CalibrationTypeEInvalid = 9 // Invalid Entry
} CalibrationTypeE_t;


typedef enum TargetArray_e
{
      e_TargetArray0 = 0, // todo
      e_TargetArray1 = 1, // todo
      e_TargetArray2 = 2, // todo
      e_TargetArrayCount = 3, // Number of Enum Elements
      e_TargetArrayInvalid = 4 // Invalid Entry
} TargetArray_t;


typedef enum MaxTargetPoints_e
{
      e_TargetPoint0 = 0, // todo
      e_TargetPoint1 = 1, // todo
      e_TargetPoint2 = 2, // todo
      e_TargetPoint3 = 3, // todo
      e_TargetPoint4 = 4, // todo
      e_TargetPoint5 = 5, // todo
      e_TargetPoint6 = 6, // todo
      e_TargetPoint7 = 7, // todo
      e_TargetPoint8 = 8, // todo
      e_TargetPoint9 = 9, // todo
      e_TargetPoint10 = 10, // todo
      e_TargetPoint11 = 11, // todo
      e_TargetPoint12 = 12, // todo
      e_TargetPoint13 = 13, // todo
      e_TargetPoint14 = 14, // todo
      e_TargetPoint15 = 15, // todo
      e_TargetPoint16 = 16, // todo
      e_TargetPoint17 = 17, // todo
      e_TargetPoint18 = 18, // todo
      e_TargetPoint19 = 19, // todo
      e_TargetPoint20 = 20, // todo
      e_TargetPoint21 = 21, // todo
      e_TargetPoint22 = 22, // todo
      e_TargetPoint23 = 23, // todo
      e_TargetPoint24 = 24, // todo
      e_TargetPoint25 = 25, // todo
      e_TargetPoint26 = 26, // todo
      e_TargetPoint27 = 27, // todo
      e_TargetPoint28 = 28, // todo
      e_TargetPoint29 = 29, // todo
      e_TargetPoint30 = 30, // todo
      e_TargetPoint31 = 31, // todo
      e_TargetPoint32 = 32, // todo
      e_TargetPoint33 = 33, // todo
      e_TargetPoint34 = 34, // todo
      e_TargetPoint35 = 35, // todo
      e_TargetPoint36 = 36, // todo
      e_TargetPoint37 = 37, // todo
      e_TargetPoint38 = 38, // todo
      e_TargetPoint39 = 39, // todo
      e_MaxTargetPointsCount = 40, // Number of Enum Elements
      e_MaxTargetPointsInvalid = 41 // Invalid Entry
} MaxTargetPoints_t;


typedef enum GeometricDimensionsWorld_e
{
      e_GEOX = 0, // todo
      e_GEOY = 1, // todo
      e_GEOZ = 2, // todo
      e_GeometricDimensionsWorldCount = 3, // Number of Enum Elements
      e_GeometricDimensionsWorldInvalid = 4 // Invalid Entry
} GeometricDimensionsWorld_t;


typedef enum Orientation_e
{
      e_ZPlane = 0, // todo
      e_XPlane = 1, // todo
      e_YPlane = 2, // todo
      e_OrientationCount = 3, // Number of Enum Elements
      e_OrientationInvalid = 4 // Invalid Entry
} Orientation_t;


typedef enum SignalTypesResponseCode_e
{
      e_ResponseCodeFailed = 0x00, // todo
      e_ResponseCodePositive = 1, // todo
      e_ResponseCodeNotSupportedCANID = 255, // FF
      e_ResponseCodeNotSupportedParam = 254, // FE
      e_ResponseCodeUndefError = 253, // FD
      e_ResponseCodeDelayed = 252, // FC
      e_SignalTypesResponseCodeCount = 6, // Number of Enum Elements
      e_SignalTypesResponseCodeInvalid = 7 // Invalid Entry
} SignalTypesResponseCode_t;


typedef enum EolErrorCodeE_e
{
      e_EOL_NoError = 0, // todo
      e_EOL_In_PROCESS = 1, // todo
      e_EOL_MISSING_SOFTWARE = 2, // todo
      e_EOL_PRECONDITION_VRANGE = 3, // todo
      e_EOL_PRECONDITION_BASE_MODULE_360 = 4, // todo
      e_EOL_CAMERA_ERROR = 5, // todo
      e_EOL_VARIANT_CODING = 6, // todo
      e_EOL_TARGET_NOT_FOUND_INIT = 7, // todo
      e_EOL_TARGET_NOT_FOUND_LEFT = 8, // todo
      e_EOL_TARGET_NOT_FOUND_RIGHT = 9, // todo
      e_EOL_TARGET_IDENT_ERROR_LEFT = 10, // todo
      e_EOL_TARGET_IDENT_ERROR_RIGHT = 11, // todo
      e_EOL_EXCEED_QUALITY_LIMIT = 12, // todo
      e_EOL_NOT_CALIBRATED = 13, // todo
      e_EOL_ABORTED = 14, // todo
      e_EOL_H_ESTIMATION_ERROR = 15, // todo
      e_EOL_PRECONDITION_VELOCITY = 16, // todo
      e_EOL_PRECONDITION_DOORS = 17, // todo
      e_EOL_WRONG_CAMERA_SOFTWARE = 18, // todo
      e_EOL_PRECONDITION = 19, // todo
      e_EolErrorCodeECount = 20, // Number of Enum Elements
      e_EolErrorCodeEInvalid = 21 // Invalid Entry
} EolErrorCodeE_t;


typedef enum EolAlgoStateE_e
{
      e_Eol_NotInit = 0, // todo
      e_Eol_Init = 1, // todo
      e_Eol_Start = 2, // todo
      e_Eol_Running = 3, // todo
      e_Eol_Finished = 4, // todo
      e_EolAlgoStateECount = 5, // Number of Enum Elements
      e_EolAlgoStateEInvalid = 6 // Invalid Entry
} EolAlgoStateE_t;


typedef enum OcAlgoStateE_e
{
      e_Oc_Uninit = 0, // todo
      e_Oc_InitOk = 1, // todo
      e_Oc_Error = 2, // todo
      e_Oc_FeatureCollection = 3, // todo
      e_Oc_FeatureCollectionCompleted = 4, // todo
      e_Oc_Calibration = 5, // todo
      e_Oc_CalibrationCompleted = 6, // todo
      e_Oc_Terminated = 7, // todo
      e_Oc_Paused = 8, // todo
      e_Oc_Unknown = 9, // todo
      e_Oc_End = 10, // todo
      e_OcAlgoStateECount = 11, // Number of Enum Elements
      e_OcAlgoStateEInvalid = 12 // Invalid Entry
} OcAlgoStateE_t;


typedef enum OcErrorCodeE_e
{
      e_Oc_NoError = 0, // todo
      e_Oc_InitFail = 1, // todo
      e_Oc_StartFail = 2, // todo
      e_Oc_FeatureCollectionError = 3, // todo
      e_Oc_CalibrationError = 4, // todo
      e_Oc_InvalidConfiguration = 5, // todo
      e_Oc_InvalidSavedData = 6, // todo
      e_Oc_UnexpectedRequest = 7, // todo
      e_Oc_Num = 8, // todo
      e_OcErrorCodeECount = 9, // Number of Enum Elements
      e_OcErrorCodeEInvalid = 10 // Invalid Entry
} OcErrorCodeE_t;


typedef enum TeolErrorCodeE_e
{
      e_Teol_No_Error = 0, // todo
      e_Teol_NOTCALIBRATED = 1, // todo
      e_TeolErrorCodeECount = 2, // Number of Enum Elements
      e_TeolErrorCodeEInvalid = 3 // Invalid Entry
} TeolErrorCodeE_t;


typedef enum TeolAlgoStateE_e
{
      e_Teol_NotInit = 0, // todo
      e_Teol_Init = 1, // todo
      e_Teol_Start = 2, // todo
      e_Teol_Running = 3, // todo
      e_Teol_Finished = 4, // todo
      e_TeolAlgoStateECount = 5, // Number of Enum Elements
      e_TeolAlgoStateEInvalid = 6 // Invalid Entry
} TeolAlgoStateE_t;


typedef enum ScErrorCodeE_e
{
      e_Sc_Error_NoError = 0, // todo
      e_Sc_Error_NotCalibrated = 1, // todo
      e_Sc_Error_Unknown = 2, // todo
      e_ScErrorCodeECount = 3, // Number of Enum Elements
      e_ScErrorCodeEInvalid = 4 // Invalid Entry
} ScErrorCodeE_t;


typedef enum ScAlgoStateE_e
{
      e_Sc_NotInit = 0, // todo
      e_Sc_Init = 1, // todo
      e_Sc_Start = 2, // todo
      e_Sc_Running = 3, // todo
      e_Sc_Finished = 4, // todo
      e_ScAlgoStateECount = 5, // Number of Enum Elements
      e_ScAlgoStateEInvalid = 6 // Invalid Entry
} ScAlgoStateE_t;


typedef enum PerfMBootState_e
{
      e_PerfMBootStateComplete = 0,
      e_PerfMBootStateBooting = 1,
      e_PerfMBootStateInit = 2,
      e_PerfMBootStateSNA = 255,
      e_PerfMBootStateCount = 4, // Number of Enum Elements
      e_PerfMBootStateInvalid = 5 // Invalid Entry
} PerfMBootState_t;


typedef enum PerfMErrorCategory_e
{
      e_PerfMErrorCategoryCamera = 0,
      e_PerfMErrorCategoryOthers = 1,
      e_PerfMErrorCategoryCount = 2, // Number of Enum Elements
      e_PerfMErrorCategoryInvalid = 3 // Invalid Entry
} PerfMErrorCategory_t;


typedef enum CamError_e
{
      e_CamErrorNone = 0, // Everything is fine
      e_CamErrorCrc = 1, // EEPROM Crc check failed
      e_CamErrorInitFailed = 2, // Init failed, some internal camera error
      e_CamErrorUpdateFailed = 3, // Update Variant data failed
      e_CamErrorDisconnected = 4, // Camera was unplugged or disconnected
      e_CamErrorCount = 5, // Number of Enum Elements
      e_CamErrorInvalid = 6 // Invalid Entry
} CamError_t;


typedef enum SwType_e
{
      e_SwTypeVersionPuC = 0, // PuC Software Version
      e_SwTypeOS = 1, // Operation System Type
      e_SwTypeCpuLoad = 2, // Type for getting CPU load
      e_SwTypeVersionPL = 3, // todo
      e_SwTempMeasurementSoC = 4, // todo
      e_SwTypeCamVersion = 5, // todo
      e_SwTypeCount = 6, // Number of Enum Elements
      e_SwTypeInvalid = 7 // Invalid Entry
} SwType_t;


typedef enum OsType_e
{
      e_OsTypeQNX = 0, // QNX Operating System
      e_OSTypeWindows = 1, // Windows Operating System
      e_OsTypeCount = 2, // Number of Enum Elements
      e_OsTypeInvalid = 3 // Invalid Entry
} OsType_t;


typedef enum CamTestPattern_e
{
      e_CamTestPatternNone = 0, // No test pattern (normal operation)
      e_CamTestPatternFullVertColorBars = 2, // 100 percent Vertical Color Bars test pattern
      e_CamTestPatternFadeToGrey = 3, // Fade To Grey Vertical Color Bars test pattern
      e_CamTestPatternSolidBlack = 4, // Solid Black Color test pattern
      e_CamTestPatternSolidWhite = 5, // Solid White Color test pattern
      e_CamTestPatternSolidRed = 6, // Solid Red Color test pattern
      e_CamTestPatternSolidGreen = 7, // Solid Green Color test pattern
      e_CamTestPatternSolidBlue = 8, // Solid Blue Color test pattern
      e_CamTestPatternTurnOff = 15, // Power off camera deserialiizer
      e_CamTestPatternCount = 9, // Number of Enum Elements
      e_CamTestPatternInvalid = 10 // Invalid Entry
} CamTestPattern_t;


typedef enum HmiSoftButton_e
{
      e_aPerfM_E_HmiSoftButton_None = 0, // todo
      e_aPerfM_E_HmiSoftButton_Ok = 1, // todo
      e_aPerfM_E_HmiSoftButton_Back = 2, // todo
      e_aPerfM_E_HmiSoftButton_Next = 3, // todo
      e_aPerfM_E_HmiSoftButton_NG = 4, // todo
      e_aPerfM_E_HmiSoftButton_Cancel = 5, // todo
      e_aPerfM_E_HmiSoftButton_UpArrow = 6, // todo
      e_aPerfM_E_HmiSoftButton_DownArrow = 7, // todo
      e_aPerfM_E_HmiSoftButton_LeftArrow = 8, // todo
      e_aPerfM_E_HmiSoftButton_RightArrow = 9, // todo
      e_aPerfM_E_HmiSoftButton_NextPage = 10, // todo
      e_aPerfM_E_HmiSoftButton_PreviousPage = 11, // todo
      e_aPerfM_E_HmiSoftButton_CounterClockwiseArrow = 12, // todo
      e_aPerfM_E_HmiSoftButton_ClockwiseArrow = 13, // todo
      e_aPerfM_E_HmiSoftButton_FrontCam = 14, // todo
      e_aPerfM_E_HmiSoftButton_RearCam = 15, // todo
      e_aPerfM_E_HmiSoftButton_LeftCam = 16, // todo
      e_aPerfM_E_HmiSoftButton_RightCam = 17, // todo
      e_aPerfM_E_HmiSoftButton_AllViewReset = 18, // todo
      e_aPerfM_E_HmiSoftButton_NewCamera = 19, // todo
      e_aPerfM_E_HmiSoftButton_Init = 20, // todo
      e_aPerfM_E_HmiSoftButton_ViewAdjustment = 21, // todo
      e_aPerfM_E_HmiSoftButton_CameraCheck = 22, // todo
      e_aPerfM_E_HmiSoftButton_DiagCheck = 23, // todo
      e_HmiSoftButtonCount = 24, // Number of Enum Elements
      e_HmiSoftButtonInvalid = 25 // Invalid Entry
} HmiSoftButton_t;


typedef enum HmiSoftButtonStatus_e
{
      e_aPerfM_E_HmiSoftButtonStatus_Normal = 0, // todo
      e_aPerfM_E_HmiSoftButtonStatus_React = 1, // todo
      e_aPerfM_E_HmiSoftButtonStatus_Select = 2, // todo
      e_aPerfM_E_HmiSoftButtonStatus_SelectReact = 3, // todo
      e_aPerfM_E_HmiSoftButtonStatus_ToneDown = 4, // todo
      e_aPerfM_E_HmiSoftButtonStatus_ToneDownReact = 5, // todo
      e_HmiSoftButtonStatusCount = 6, // Number of Enum Elements
      e_HmiSoftButtonStatusInvalid = 7 // Invalid Entry
} HmiSoftButtonStatus_t;


typedef enum SingleViews_e
{
      e_SingleViewFullFront = 0, // todo
      e_SingleViewFullRearWide = 1, // todo
      e_SingleViewFullRearNarrow = 2, // todo
      e_SingleViewFullRearHitch = 3, // todo
      e_SingleViewTopPrimaryFront = 4, // todo
      e_SingleViewTopPrimaryRear = 5, // todo
      e_SingleViewTopAllFront = 6, // todo
      e_SingleViewTopAllLeft = 7, // todo
      e_SingleViewTopAllRear = 8, // todo
      e_SingleViewTopAllRight = 9, // todo
      e_SingleViewTopFlFront = 10, // todo
      e_SingleViewTopFrFront = 11, // todo
      e_SingleViewTopFlLeft = 12, // todo
      e_SingleViewTopRlLeft = 13, // todo
      e_SingleViewTopRlRear = 14, // todo
      e_SingleViewTopRrRear = 15, // todo
      e_SingleViewTopFrRight = 16, // todo
      e_SingleViewTopRrRight = 17, // todo
      e_SingleViewFrontSplitLeft = 18, // todo
      e_SingleViewFrontSplitRight = 19, // todo
      e_SingleViewBed = 20, // todo
      e_SingleViewAux = 21, // todo
      e_SingleViewRearSplitCenterLeft = 22, // todo
      e_SingleViewRearSplitCenterRight = 23, // todo
      e_SingleViewRearSplitRightLeft = 24, // todo
      e_SingleViewRearSplitRightRight = 25, // todo
      e_SingleViewRearSplitLeftLeft = 26, // todo
      e_SingleViewRearSplitLeftRight = 27, // todo
      e_SingleViewRearSplitFarLeft = 28, // todo
      e_SingleViewRearSplitFarRight = 29, // todo
      e_SingleViewMtmFrontSideOverallLeft = 30, // todo
      e_SingleViewMtmFrontSideOverallCenter = 31, // todo
      e_SingleViewMtmFrontSideOverallRight = 32, // todo
      e_SingleViewMtmFrontSideLeft = 33, // todo
      e_SingleViewMtmFrontSideCenter = 34, // todo
      e_SingleViewMtmFrontSideRight = 35, // todo
      e_SingleViewMtmRearSideOverallLeft = 36, // todo
      e_SingleViewMtmRearSideOverallCenter = 37, // todo
      e_SingleViewMtmRearSideOverallRight = 38, // todo
      e_SingleViewMtmRearFull = 39, // todo
      e_SingleViewQuadFront = 40, // todo
      e_SingleViewQuadLeft = 41, // todo
      e_SingleViewQuadRear = 42, // todo
      e_SingleViewQuadRight = 43, // todo
      e_SingleViewTopAllFrontCalibration = 44, // todo
      e_SingleViewTopAllLeftCalibration = 45, // todo
      e_SingleViewTopAllRearCalibration = 46, // todo
      e_SingleViewTopAllRightCalibration = 47, // todo
      e_SingleViewMtmUnderfloorSideOverallCenterHistoric = 48, // todo
      e_SingleViewMtmUnderfloorSideOverallCenterFront = 49, // todo
      e_SingleViewMtmUnderfloorSideOverallCenterLeft = 50, // todo
      e_SingleViewMtmUnderfloorSideOverallCenterRight = 51, // todo
      e_SingleViewMtmUnderfloorSideCenterHistoric = 52, // todo
      e_SingleViewMtmUnderfloorSideCenterFront = 53, // todo
      e_SingleViewMtmUnderfloorSideCenterLeft = 54, // todo
      e_SingleViewMtmUnderfloorSideCenterRight = 55, // todo
      e_SingleViewRawFront = 56, // todo
      e_SingleViewRawLeft = 57, // todo
      e_SingleViewRawRear = 58, // todo
      e_SingleViewRawRight = 59, // todo
      e_SingleViewRawChmsl = 60, // todo
      e_SingleViewsCount = 61, // Number of Enum Elements
      e_SingleViewsInvalid = 62 // Invalid Entry
} SingleViews_t;


typedef enum SingleViewLinks_e
{
      e_SingleViewLink0 = 0, // todo
      e_SingleViewLink1 = 1, // todo
      e_SingleViewLink2 = 2, // todo
      e_SingleViewLink3 = 3, // todo
      e_SingleViewLink4 = 4, // todo
      e_SingleViewLink5 = 5, // todo
      e_SingleViewLinksCount = 6, // Number of Enum Elements
      e_SingleViewLinksInvalid = 7 // Invalid Entry
} SingleViewLinks_t;


typedef enum VirtualCameras_e
{
      e_VirtualCameraFullFront = 0, // todo
      e_VirtualCameraFullRearWide = 1, // todo
      e_VirtualCameraFullRearNarrow = 2, // todo
      e_VirtualCameraFullRearHitch = 3, // todo
      e_VirtualCameraTopPrimaryFront = 4, // todo
      e_VirtualCameraTopPrimaryRear = 5, // todo
      e_VirtualCameraTopAll = 6, // todo
      e_VirtualCameraTopFl = 7, // todo
      e_VirtualCameraTopFr = 8, // todo
      e_VirtualCameraTopRl = 9, // todo
      e_VirtualCameraTopRr = 10, // todo
      e_VirtualCameraFrontSplitLeft = 11, // todo
      e_VirtualCameraFrontSplitRight = 12, // todo
      e_VirtualCameraBed = 13, // todo
      e_VirtualCameraAux = 14, // todo
      e_VirtualCameraRearSplitCenterLeft = 15, // todo
      e_VirtualCameraRearSplitCenterRight = 16, // todo
      e_VirtualCameraRearSplitRightLeft = 17, // todo
      e_VirtualCameraRearSplitRightRight = 18, // todo
      e_VirtualCameraRearSplitLeftLeft = 19, // todo
      e_VirtualCameraRearSplitLeftRight = 20, // todo
      e_VirtualCameraRearSplitFarLeft = 21, // todo
      e_VirtualCameraRearSplitFarRight = 22, // todo
      e_VirtualCameraMtmFrontSideOverallLeft = 23, // todo
      e_VirtualCameraMtmFrontSideOverallCenter = 24, // todo
      e_VirtualCameraMtmFrontSideOverallRight = 25, // todo
      e_VirtualCameraMtmFrontSideLeft = 26, // todo
      e_VirtualCameraMtmFrontSideCenter = 27, // todo
      e_VirtualCameraMtmFrontSideRight = 28, // todo
      e_VirtualCameraMtmRearSideOverallLeft = 29, // todo
      e_VirtualCameraMtmRearSideOverallCenter = 30, // todo
      e_VirtualCameraMtmRearSideOverallRight = 31, // todo
      e_VirtualCameraMtmRearFull = 32, // todo
      e_VirtualCameraQuadFront = 33, // todo
      e_VirtualCameraQuadLeft = 34, // todo
      e_VirtualCameraQuadRear = 35, // todo
      e_VirtualCameraQuadRight = 36, // todo
      e_VirtualCameraTopAllCalibration = 37, // todo
      e_VirtualCameraMtmUnderfloorSideOverallCenter = 38, // todo
      e_VirtualCameraMtmUnderfloorSideCenter = 39, // todo
      e_VirtualCameraRawFront = 40, // todo
      e_VirtualCameraRawLeft = 41, // todo
      e_VirtualCameraRawRear = 42, // todo
      e_VirtualCameraRawRight = 43, // todo
      e_VirtualCameraRawChmsl = 44, // todo
      e_VirtualCamerasCount = 45, // Number of Enum Elements
      e_VirtualCamerasInvalid = 46 // Invalid Entry
} VirtualCameras_t;


typedef enum VideoLayer_e
{
      e_VideoLayer0 = 0, // todo
      e_VideoLayer1 = 1, // todo
      e_VideoLayer2 = 2, // todo
      e_VideoLayerCount = 3, // Number of Enum Elements
      e_VideoLayerInvalid = 4 // Invalid Entry
} VideoLayer_t;


typedef enum Zoomable_e
{
      e_ZoomableNo = 0, // todo
      e_ZoomableYes = 1, // todo
      e_ZoomableCount = 2, // Number of Enum Elements
      e_ZoomableInvalid = 3 // Invalid Entry
} Zoomable_t;


typedef enum PixelAreas_e
{
      e_PixelAreaFull = 0, // todo
      e_PixelAreaTopAll = 1, // todo
      e_PixelAreaTopAllFront = 2, // todo
      e_PixelAreaTopAllLeft = 3, // todo
      e_PixelAreaTopAllRear = 4, // todo
      e_PixelAreaTopAllRight = 5, // todo
      e_PixelAreaTopZoomFront = 6, // todo
      e_PixelAreaTopZoomLeft = 7, // todo
      e_PixelAreaTopZoomRear = 8, // todo
      e_PixelAreaTopZoomRight = 9, // todo
      e_PixelAreaTopPrimary = 10, // todo
      e_PixelAreaSplitCenterLeft = 11, // todo
      e_PixelAreaSplitCenterRight = 12, // todo
      e_PixelAreaSplitRightLeft = 13, // todo
      e_PixelAreaSplitRightRight = 14, // todo
      e_PixelAreaSplitLeftLeft = 15, // todo
      e_PixelAreaSplitLeftRight = 16, // todo
      e_PixelAreaMtmSideOverallLeft = 17, // todo
      e_PixelAreaMtmSideOverallCenter = 18, // todo
      e_PixelAreaMtmSideOverallRight = 19, // todo
      e_PixelAreaMtmSideLeft = 20, // todo
      e_PixelAreaMtmSideCenter = 21, // todo
      e_PixelAreaMtmSideRight = 22, // todo
      e_PixelAreaMtmFull = 23, // todo
      e_PixelAreaQuadAll = 24, // todo
      e_PixelAreaQuadFront = 25, // todo
      e_PixelAreaQuadLeft = 26, // todo
      e_PixelAreaQuadRear = 27, // todo
      e_PixelAreaQuadRight = 28, // todo
      e_PixelAreaTopAllCalibration = 29, // todo
      e_PixelAreaTopAllFrontCalibration = 30, // todo
      e_PixelAreaTopAllLeftCalibration = 31, // todo
      e_PixelAreaTopAllRearCalibration = 32, // todo
      e_PixelAreaTopAllRightCalibration = 33, // todo
      e_PixelAreasCount = 34, // Number of Enum Elements
      e_PixelAreasInvalid = 35 // Invalid Entry
} PixelAreas_t;


typedef enum StitchParams_e
{
      e_StitchParamsTopAllFrontLeft = 0, // todo
      e_StitchParamsTopAllFrontRight = 1, // todo
      e_StitchParamsTopAllRearLeft = 2, // todo
      e_StitchParamsTopAllRearRight = 3, // todo
      e_StitchParamsTopZoomFrontLeft = 4, // todo
      e_StitchParamsTopZoomFrontRight = 5, // todo
      e_StitchParamsTopZoomRearLeft = 6, // todo
      e_StitchParamsTopZoomRearRight = 7, // todo
      e_StitchParamsTopAllFrontLeftCalibration = 8, // todo
      e_StitchParamsTopAllFrontRightCalibration = 9, // todo
      e_StitchParamsTopAllRearLeftCalibration = 10, // todo
      e_StitchParamsTopAllRearRightCalibration = 11, // todo
      e_StitchParamsCount = 12, // Number of Enum Elements
      e_StitchParamsInvalid = 13 // Invalid Entry
} StitchParams_t;


typedef enum StitchParamsLinks_e
{
      e_StitchParamsLink0 = 0, // todo
      e_StitchParamsLink1 = 1, // todo
      e_StitchParamsLink2 = 2, // todo
      e_StitchParamsLink3 = 3, // todo
      e_StitchParamsLinksCount = 4, // Number of Enum Elements
      e_StitchParamsLinksInvalid = 5 // Invalid Entry
} StitchParamsLinks_t;


typedef enum LensStretchCoefficients_e
{
      e_LensStretchCoeff0 = 0, // todo
      e_LensStretchCoeff1 = 1, // todo
      e_LensStretchCoeff2 = 2, // todo
      e_LensStretchCoeff3 = 3, // todo
      e_LensStretchCoeff4 = 4, // todo
      e_LensStretchCoeff5 = 5, // todo
      e_LensStretchCoeff6 = 6, // todo
      e_LensStretchCoefficientsCount = 7, // Number of Enum Elements
      e_LensStretchCoefficientsInvalid = 8 // Invalid Entry
} LensStretchCoefficients_t;


typedef enum CarColorSelection_e
{
      e_CarColorIndex0 = 0, // Wind Chill Pearl (E3E9E9)
      e_CarColorIndex1 = 1, // Magnetic Gray Metallic (494848)
      e_CarColorIndex2 = 2, // Midnight Black Metallic (00031E)
      e_CarColorIndex3 = 3, // Supersonic Red (E20500)
      e_CarColorIndex4 = 4, // Smoked Mesquite (412C1B)
      e_CarColorIndex5 = 5, // Army Green (2A3A2A)
      e_CarColorIndex6 = 6, // Lunar Rock (949B96)
      e_CarColorIndex7 = 7, // Blueprint (1E2548)
      e_CarColorSelectionCount = 8, // Number of Enum Elements
      e_CarColorSelectionInvalid = 9 // Invalid Entry
} CarColorSelection_t;


typedef enum DriverSide_e
{
      e_DriverSideLeft = 0, // todo
      e_DriverSideRight = 1, // todo
      e_DriverSideCount = 2, // Number of Enum Elements
      e_DriverSideInvalid = 3 // Invalid Entry
} DriverSide_t;


typedef enum VariantIds_e
{
      e_VariantId0 = 0, //   Config A | 780B C-Cab Long     | Grille Type 1 | Normal   Mirror | 14 Inch
      e_VariantId1 = 1, //   Config A | 780B C-Cab Long     | Grille Type 1 | Extended Mirror | 14 Inch
      e_VariantId2 = 2, //   Config B | 780B D-Cab Standard | Grille Type 1 | Normal   Mirror | 14 Inch
      e_VariantId3 = 3, //   Config B | 780B D-Cab Standard | Grille Type 1 | Extended Mirror | 14 Inch
      e_VariantId4 = 4, //   Config C | 780B C-Cab Standard | Grille Type 1 | Normal   Mirror | 14 Inch
      e_VariantId5 = 5, //   Config C | 780B C-Cab Standard | Grille Type 1 | Extended Mirror | 14 Inch
      e_VariantId6 = 6, //   Config D | 780B D-Cab Short    | Grille Type 1 | Normal   Mirror | 14 Inch
      e_VariantId7 = 7, //   Config D | 780B D-Cab Short    | Grille Type 1 | Extended Mirror | 14 Inch
      e_VariantId8 = 8, //   Config D | 780B D-Cab Short    | Grille Type 2 | Normal   Mirror | 14 Inch
      e_VariantId9 = 9, //   Config D | 780B D-Cab Short    | Grille Type 2 | Extended Mirror | 14 Inch
      e_VariantId10 = 10, // Config E | 660B                | Grille Type 1 | Normal   Mirror | 14 Inch
      e_VariantId11 = 11, // Config E | 660B                | Grille Type 1 | Extended Mirror | 14 Inch
      e_VariantId12 = 12, // Config E | 660B                | Grille Type 2 | Normal   Mirror | 14 Inch
      e_VariantId13 = 13, // Config E | 660B                | Grille Type 2 | Extended Mirror | 14 Inch
      e_VariantId14 = 14, // Config E | 660B                | Grille Type 1 | Normal   Mirror |  8 Inch
      e_VariantId15 = 15, // Config E | 660B                | Grille Type 1 | Extended Mirror |  8 Inch
      e_VariantId16 = 16, // Config E | 660B                | Grille Type 2 | Normal   Mirror |  8 Inch
      e_VariantId17 = 17, // Config E | 660B                | Grille Type 2 | Extended Mirror |  8 Inch
      e_VariantId18 = 18, // todo
      e_VariantId19 = 19, // todo
      e_VariantIdsCount = 20, // Number of Enum Elements
      e_VariantIdsInvalid = 21 // Invalid Entry
} VariantIds_t;

#ifdef __cplusplus
} // namespace variants
#endif // if cplusplus

#endif // ENUMS

