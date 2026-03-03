#ifndef MESSAGES_H
#define MESSAGES_H

#include "MessageSerializer.h"


/*  --- Structs --- */
typedef struct BootState_s
{
  sint32_t bootState_s32_s32; /* enum aZynqM_E_ModuleState_e */
} BootState_t;


typedef struct RequestApplyConfig_s
{
  sint32_t languageID_s32; /* ME_Hydra2defs_E_Language_e */
  sint32_t vehicleConfigID_s32; /* Supported Vehicle Configuration */
  sint32_t frameRate_s32; /* 25 or 30 */
  sint32_t flickerFrequency_s32; /* 50 Hz or 60 Hz */
  uint8_t digitalOutput_u8; /* 0=Analog, 1=Digital (displayConfig struct) */
  sint32_t outputResolution_s32; /* output Resolution Enum (displayConfig struct) */
  uint8_t failSafe_u8; /* Failsafe (ME_Hydra2defs_S_ConfigBits_s struct) */
  uint8_t debugFacilities_u8; /* 0=OFF, 1=ON (ME_Hydra2defs_S_ConfigBits_s struct) */
  uint8_t driverPosition_u8; /* 0=left hand drive, 1=right hand drive (ME_Hydra2defs_S_ConfigBits_s struct) */
  uint8_t configuredCams_u8; /* ME_HYDRA2DEFS_D_FRONTCAM 0x01 ME_HYDRA2DEFS_D_LEFTCAM 0x02 ME_HYDRA2DEFS_D_REARCAM 0x04 ME_HYDRA2DEFS_D_RIGHTCAM 0x08 ME_HYDRA2DEFS_D_5THCAM 0x10 */
} RequestApplyConfig_t;


const uint32_t c_MaxOverlays_u32 = 32;
typedef struct RequestScreen_s
{
  sint32_t Version_s32; /* Version Identifier */
  sint32_t ViewID_s32; /* View Identifier */
  uint8_t ZoomFactor_u8; /* Zoom Factor */
  uint8_t Overlays_au8[c_MaxOverlays_u32]; /* Overlay Bits Array */
} RequestScreen_t;


typedef struct SendVehicleState_s
{
  float32_t VehicleLevel_f32;
  float32_t SteeringAngle_f32;
} SendVehicleState_t;


typedef struct TestAllDataTypes_s
{
  uint8_t Test_u8;
  uint16_t Test_u16;
  uint32_t Test_u32;
  uint64_t Test_u64;
  sint8_t Test_s8;
  sint16_t Test_s16;
  sint32_t Test_s32;
  sint64_t Test_s64;
  float32_t Test_f32;
} TestAllDataTypes_t;



/*  --- Message Type to ID Mapping --- */
typedef enum MessageID_e
{
  e_Unknown = 0,
  e_BootState = 20,
  e_RequestApplyConfig = 30,
  e_RequestScreen = 110,
  e_SendVehicleState = 120,
  e_TestAllDataTypes = 440,
} MessageID_t;

/* Advances data pointer and returns the message ID */
MessageID_t getMessageId_e(uint8_t** b_data_pu8)
{
  MessageID_t v_Enum_e = e_Unknown;
  uint32_t v_Index_u32 = 0;
  
  /* Read Id from Data Pointer */
  uint16_t v_DataId_u16 = read_u16(*b_data_pu8, &v_Index_u32);
  
  /* Advance Data Pointer */
  *b_data_pu8 += v_Index_u32;
  
  switch (v_DataId_u16)
  {
    case e_BootState:
    {
      v_Enum_e = e_BootState;
      break;
    };
    case e_RequestApplyConfig:
    {
      v_Enum_e = e_RequestApplyConfig;
      break;
    };
    case e_RequestScreen:
    {
      v_Enum_e = e_RequestScreen;
      break;
    };
    case e_SendVehicleState:
    {
      v_Enum_e = e_SendVehicleState;
      break;
    };
    case e_TestAllDataTypes:
    {
      v_Enum_e = e_TestAllDataTypes;
      break;
    };
    
  }
  return v_Enum_e;
}

/*  --- Read Functions --- */
bool_t readBootState_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, BootState_t* b_BootState_ps)
{
  uint32_t v_Index_u32 = 0;
  
  bool_t v_Valid_b = (i_DataLength_u32 >= 4);
  
  if (true == v_Valid_b)
  {
    b_BootState_ps->bootState_s32_s32 = read_s32(i_Data_pc, &v_Index_u32);
  }
  
  return v_Valid_b;
}

bool_t readRequestApplyConfig_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, RequestApplyConfig_t* b_RequestApplyConfig_ps)
{
  uint32_t v_Index_u32 = 0;
  
  bool_t v_Valid_b = (i_DataLength_u32 >= 25);
  
  if (true == v_Valid_b)
  {
    b_RequestApplyConfig_ps->languageID_s32 = read_s32(i_Data_pc, &v_Index_u32);
    b_RequestApplyConfig_ps->vehicleConfigID_s32 = read_s32(i_Data_pc, &v_Index_u32);
    b_RequestApplyConfig_ps->frameRate_s32 = read_s32(i_Data_pc, &v_Index_u32);
    b_RequestApplyConfig_ps->flickerFrequency_s32 = read_s32(i_Data_pc, &v_Index_u32);
    b_RequestApplyConfig_ps->digitalOutput_u8 = read_u8(i_Data_pc, &v_Index_u32);
    b_RequestApplyConfig_ps->outputResolution_s32 = read_s32(i_Data_pc, &v_Index_u32);
    b_RequestApplyConfig_ps->failSafe_u8 = read_u8(i_Data_pc, &v_Index_u32);
    b_RequestApplyConfig_ps->debugFacilities_u8 = read_u8(i_Data_pc, &v_Index_u32);
    b_RequestApplyConfig_ps->driverPosition_u8 = read_u8(i_Data_pc, &v_Index_u32);
    b_RequestApplyConfig_ps->configuredCams_u8 = read_u8(i_Data_pc, &v_Index_u32);
  }
  
  return v_Valid_b;
}

bool_t readRequestScreen_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, RequestScreen_t* b_RequestScreen_ps)
{
  uint32_t v_Index_u32 = 0;
  
  bool_t v_Valid_b = (i_DataLength_u32 >= 41);
  
  if (true == v_Valid_b)
  {
    b_RequestScreen_ps->Version_s32 = read_s32(i_Data_pc, &v_Index_u32);
    b_RequestScreen_ps->ViewID_s32 = read_s32(i_Data_pc, &v_Index_u32);
    b_RequestScreen_ps->ZoomFactor_u8 = read_u8(i_Data_pc, &v_Index_u32);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < c_MaxOverlays_u32; ++v_I_u32)
    {
      b_RequestScreen_ps->Overlays_au8[v_I_u32] = read_u8(i_Data_pc, &v_Index_u32);
    }
  }
  
  return v_Valid_b;
}

bool_t readSendVehicleState_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, SendVehicleState_t* b_SendVehicleState_ps)
{
  uint32_t v_Index_u32 = 0;
  
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    b_SendVehicleState_ps->VehicleLevel_f32 = read_f32(i_Data_pc, &v_Index_u32);
    b_SendVehicleState_ps->SteeringAngle_f32 = read_f32(i_Data_pc, &v_Index_u32);
  }
  
  return v_Valid_b;
}

bool_t readTestAllDataTypes_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, TestAllDataTypes_t* b_TestAllDataTypes_ps)
{
  uint32_t v_Index_u32 = 0;
  
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    b_TestAllDataTypes_ps->Test_u8 = read_u8(i_Data_pc, &v_Index_u32);
    b_TestAllDataTypes_ps->Test_u16 = read_u16(i_Data_pc, &v_Index_u32);
    b_TestAllDataTypes_ps->Test_u32 = read_u32(i_Data_pc, &v_Index_u32);
    b_TestAllDataTypes_ps->Test_u64 = read_u64(i_Data_pc, &v_Index_u32);
    b_TestAllDataTypes_ps->Test_s8 = read_s8(i_Data_pc, &v_Index_u32);
    b_TestAllDataTypes_ps->Test_s16 = read_s16(i_Data_pc, &v_Index_u32);
    b_TestAllDataTypes_ps->Test_s32 = read_s32(i_Data_pc, &v_Index_u32);
    b_TestAllDataTypes_ps->Test_s64 = read_s64(i_Data_pc, &v_Index_u32);
    b_TestAllDataTypes_ps->Test_f32 = read_f32(i_Data_pc, &v_Index_u32);
  }
  
  return v_Valid_b;
}


/*  --- Write Functions --- */
bool_t writeBootState_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, BootState_t* b_BootState_ps)
{
  uint32_t v_Index_u32 = 0;
  
  bool_t v_Valid_b = (i_DataLength_u32 >= 4);
  
  if (true == v_Valid_b)
  {
    write_s32(b_Data_pc, &v_Index_u32, b_BootState_ps->bootState_s32_s32);
  }
  
  return v_Valid_b;
}

bool_t writeRequestApplyConfig_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, RequestApplyConfig_t* b_RequestApplyConfig_ps)
{
  uint32_t v_Index_u32 = 0;
  
  bool_t v_Valid_b = (i_DataLength_u32 >= 25);
  
  if (true == v_Valid_b)
  {
    write_s32(b_Data_pc, &v_Index_u32, b_RequestApplyConfig_ps->languageID_s32);
    write_s32(b_Data_pc, &v_Index_u32, b_RequestApplyConfig_ps->vehicleConfigID_s32);
    write_s32(b_Data_pc, &v_Index_u32, b_RequestApplyConfig_ps->frameRate_s32);
    write_s32(b_Data_pc, &v_Index_u32, b_RequestApplyConfig_ps->flickerFrequency_s32);
    write_u8(b_Data_pc, &v_Index_u32, b_RequestApplyConfig_ps->digitalOutput_u8);
    write_s32(b_Data_pc, &v_Index_u32, b_RequestApplyConfig_ps->outputResolution_s32);
    write_u8(b_Data_pc, &v_Index_u32, b_RequestApplyConfig_ps->failSafe_u8);
    write_u8(b_Data_pc, &v_Index_u32, b_RequestApplyConfig_ps->debugFacilities_u8);
    write_u8(b_Data_pc, &v_Index_u32, b_RequestApplyConfig_ps->driverPosition_u8);
    write_u8(b_Data_pc, &v_Index_u32, b_RequestApplyConfig_ps->configuredCams_u8);
  }
  
  return v_Valid_b;
}

bool_t writeRequestScreen_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, RequestScreen_t* b_RequestScreen_ps)
{
  uint32_t v_Index_u32 = 0;
  
  bool_t v_Valid_b = (i_DataLength_u32 >= 41);
  
  if (true == v_Valid_b)
  {
    write_s32(b_Data_pc, &v_Index_u32, b_RequestScreen_ps->Version_s32);
    write_s32(b_Data_pc, &v_Index_u32, b_RequestScreen_ps->ViewID_s32);
    write_u8(b_Data_pc, &v_Index_u32, b_RequestScreen_ps->ZoomFactor_u8);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < 32; ++v_I_u32)
    {
      write_u8(b_Data_pc, &v_Index_u32, b_RequestScreen_ps->Overlays_au8[v_I_u32]);
    }
  }
  
  return v_Valid_b;
}

bool_t writeSendVehicleState_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, SendVehicleState_t* b_SendVehicleState_ps)
{
  uint32_t v_Index_u32 = 0;
  
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    write_f32(b_Data_pc, &v_Index_u32, b_SendVehicleState_ps->VehicleLevel_f32);
    write_f32(b_Data_pc, &v_Index_u32, b_SendVehicleState_ps->SteeringAngle_f32);
  }
  
  return v_Valid_b;
}

bool_t writeTestAllDataTypes_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, TestAllDataTypes_t* b_TestAllDataTypes_ps)
{
  uint32_t v_Index_u32 = 0;
  
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    write_u8(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_u8);
    write_u16(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_u16);
    write_u32(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_u32);
    write_u64(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_u64);
    write_s8(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_s8);
    write_s16(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_s16);
    write_s32(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_s32);
    write_s64(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_s64);
    write_f32(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_f32);
  }
  
  return v_Valid_b;
}


#endif
