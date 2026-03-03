#ifndef InterfaceSignalForTestPatternRoutine_H_INCGUARD
#define InterfaceSignalForTestPatternRoutine_H_INCGUARD

#if defined(BUILD_MCU2_0) 
typedef enum ME_Hydra3defs_E_CameraID_e
{
  CamID_None    = 0,
  CamID_Front   = 1,
  CamID_Left    = 2,
  CamID_Rear    = 3,
  CamID_Right   = 4,
  CamID_Debug   = 5,
  CamID_Invalid = 6,
  CameraID_Enforcer = 0xFFFFFFFF
} ME_Hydra3defs_E_CameraID_t;

typedef enum ME_Hydra3defs_E_TestPatternType_e
{
  NoTP                              = 0u,
  VerticalColorBars100PercentTP     = 1u,
  FadeToGrayVerticalColorBarsTP     = 2u,
  TestPatternType_Enforcer = 0xFFFFFFFF
} ME_Hydra3defs_E_TestPatternType_t;

/*
ME_Hydra3defs_E_RoutineType_t contains information on which routine is activated
*/

typedef enum ME_Hydra3defs_E_RoutineType_e
{
  roucameraTestPattern = 1,
  rouActivateScreen    = 2,
  RoutineType_Enforcer = 0xFFFFFFFF
} ME_Hydra3defs_E_RoutineType_t;

/*
ME_Hydra3defs_E_NRCType_t contains Negative Response Code List
*/

typedef enum ME_Hydra3defs_E_NRCType_e
{
  none       = 0,
  outofrange = 1,
  invalid    = 2,
  NRCType_Enforcer = 0xFFFFFFFF
} ME_Hydra3defs_E_NRCType_t;

/*MCU2_0 to MCU1_0*/
typedef struct SVSToDiag_s
{
  ME_Hydra3defs_E_RoutineType_t     Routine_ID;    		// Routine ID response field	
  ME_Hydra3defs_E_CameraID_t        Camera_ID;			// Camera ID response field
  ME_Hydra3defs_E_TestPatternType_t TestPattern_ID;     // Test pattern Response Field
  boolean                           Response_Ack;       // Negative or positive response
  ME_Hydra3defs_E_NRCType_t         NRC_ID;             // Negative response code
} SVSToDiag_t;
#endif

/* MCU1_0 to MCU2_0*/
typedef struct DiagToSVS_s
{
  ME_Hydra3defs_E_RoutineType_t     Routine_ID;   		// Routine requested
  ME_Hydra3defs_E_CameraID_t        Camera_ID;   	 	// Camera Requested for Test pattern 
  ME_Hydra3defs_E_TestPatternType_t TestPattern_ID;	 	// Test Pattern Requested
  boolean                           isRoutineStarted; 	// Is routine started
} DiagToSVS_t;

#endif
