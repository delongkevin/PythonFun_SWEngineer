#include "Messages.h"

void readTest(uint8_t* i_Data_pc, uint32_t i_DataLength_u32, RequestScreen_t* b_RequestScreen_ps)
{
  uint32_t v_Index_u32 = 0;

  b_RequestScreen_ps->Version_s32   = read_s32(i_Data_pc, &v_Index_u32);
  b_RequestScreen_ps->ViewID_s32    = read_s32(i_Data_pc, &v_Index_u32);
  b_RequestScreen_ps->ZoomFactor_u8 = read_u8 (i_Data_pc,  &v_Index_u32);

  for (int i = 0; i < 32; ++i)
  {
    b_RequestScreen_ps->Overlays_au8[i]  = read_u8(i_Data_pc, &v_Index_u32);
  }
}

void writeTest2(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, TestAllDataTypes_t* b_SetTest_ps)
{
  uint32_t v_Index_u32 = 0;
  write_u8 (b_Data_pc, &v_Index_u32, b_SetTest_ps->Test_u8 );
  write_u16(b_Data_pc, &v_Index_u32, b_SetTest_ps->Test_u16);
  write_u32(b_Data_pc, &v_Index_u32, b_SetTest_ps->Test_u32);
  write_u64(b_Data_pc, &v_Index_u32, b_SetTest_ps->Test_u64);
  write_s8 (b_Data_pc, &v_Index_u32, b_SetTest_ps->Test_s8 );
  write_s16(b_Data_pc, &v_Index_u32, b_SetTest_ps->Test_s16);
  write_s32(b_Data_pc, &v_Index_u32, b_SetTest_ps->Test_s32);
  write_s64(b_Data_pc, &v_Index_u32, b_SetTest_ps->Test_s64);
}

void readTest2(uint8_t* i_Data_pc, uint32_t i_DataLength_u32, TestAllDataTypes_t* b_RequestScreen_ps)
{
  uint32_t v_Index_u32 = 0;
  b_RequestScreen_ps->Test_u8  = read_u8 (i_Data_pc, &v_Index_u32);
  b_RequestScreen_ps->Test_u16 = read_u16(i_Data_pc, &v_Index_u32);
  b_RequestScreen_ps->Test_u32 = read_u32(i_Data_pc, &v_Index_u32);
  b_RequestScreen_ps->Test_u64 = read_u64(i_Data_pc, &v_Index_u32);
  b_RequestScreen_ps->Test_s8  = read_s8 (i_Data_pc, &v_Index_u32);
  b_RequestScreen_ps->Test_s16 = read_s16(i_Data_pc, &v_Index_u32);
  b_RequestScreen_ps->Test_s32 = read_s32(i_Data_pc, &v_Index_u32);
  b_RequestScreen_ps->Test_s64 = read_s64(i_Data_pc, &v_Index_u32);
  b_RequestScreen_ps->Test_f32 = read_f32(i_Data_pc, &v_Index_u32);
}

#include <iostream>


uint32_t testAddHeaderToMessage_u32(uint8_t* b_Data_pc, MessageID_t i_MessageID_t)
{
  uint32_t v_Index_u32 = 0;

  write_u16(b_Data_pc, &v_Index_u32, (uint16_t)i_MessageID_t);

  return v_Index_u32;
};

typedef struct OverlayGroups_s
{
  uint8_t res17_b                                  : 1;        /* Bit 15 */
  uint8_t res16_b                                  : 1;
  uint8_t res15_b                                  : 1;
  uint8_t res14_b                                  : 1;
  uint8_t res13_b                                  : 1;
  uint8_t res12_b                                  : 1;
  uint8_t res11_b                                  : 1;
  uint8_t res10_b                                  : 1;

  uint8_t res07_b                                  : 1;        /* Bit 07 */
  uint8_t res06_b                                  : 1;
  uint8_t res05_b                                  : 1;
  uint8_t res04_b                                  : 1;
  uint8_t res03_b                                  : 1;
  uint8_t Static_Trajectories_b                    : 1;
  uint8_t Dynamic_Trajectories_b                   : 1;
  uint8_t Vehicle_Icon_b                           : 1;        /* Bit 00 */
} OverlayGroups_t;

typedef struct ScreenTest_s
{
  uint8_t ViewID;
  uint8_t ZoomFactor; /* Range: 0: MaxZoom, 100: NoZoom */
  OverlayGroups_t Overlays; // uint8_t bitfieldArray[2];
} ScreenTest_t;


bool IsBitSet(uint8_t b, uint8_t pos)
{
  return (b & (1 << pos)) != 0;
}

void SetBit(uint8_t* b, uint8_t pos)
{
  *b |= 1UL << pos;
}

void printBits(uint8_t b)
{
  for (size_t i = 0; i < 8; ++i)
  {
    if (IsBitSet(b, i))
    {
      printf("Bit Set = 1 \n");
    }
    else
    {
      printf("Bit Set = 0 \n");
    }
  }
}


void writeScreenTest(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, ScreenTest_t* b_ScreenTest_ps)
{
  uint32_t v_Index_u32 = 0;
  uint8_t v_Byte_u8 = 0;

  write_u8(b_Data_pc, &v_Index_u32, b_ScreenTest_ps->ViewID);
  write_u8(b_Data_pc, &v_Index_u32, b_ScreenTest_ps->ZoomFactor);

  printf("\n\n Write Byte0: \n");
  v_Byte_u8 = 0;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res17_b << 0;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res16_b << 1;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res15_b << 2;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res14_b << 3;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res13_b << 4;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res12_b << 5;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res11_b << 6;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res10_b << 7;
  write_u8(b_Data_pc, &v_Index_u32, v_Byte_u8);

  printBits(v_Byte_u8);


  printf("\n\n Write Byte1: \n");
  v_Byte_u8 = 0;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res07_b                << 0;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res06_b                << 1;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res05_b                << 2;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res04_b                << 3;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.res03_b                << 4;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.Static_Trajectories_b  << 5;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.Dynamic_Trajectories_b << 6;
  v_Byte_u8 |= b_ScreenTest_ps->Overlays.Vehicle_Icon_b         << 7;
  write_u8(b_Data_pc, &v_Index_u32, v_Byte_u8);

  printBits(v_Byte_u8);
}

void readScreenTest(uint8_t* i_Data_pc, uint32_t i_DataLength_u32, ScreenTest_t* b_ScreenTest_ps)
{
  uint32_t v_Index_u32 = 0;
  uint8_t v_Byte_u8 = 0;

  b_ScreenTest_ps->ViewID = read_u8(i_Data_pc, &v_Index_u32);
  b_ScreenTest_ps->ZoomFactor = read_u8(i_Data_pc, &v_Index_u32);

  printf("\n\n Read Byte0: \n");
  v_Byte_u8 = read_u8(i_Data_pc, &v_Index_u32);
  b_ScreenTest_ps->Overlays.res17_b = IsBitSet(v_Byte_u8, 0); // ( (v_Byte_u8 & (1 << 0)) != 0);
  b_ScreenTest_ps->Overlays.res16_b = IsBitSet(v_Byte_u8, 1); // ( (v_Byte_u8 & (1 << 1)) != 0);
  b_ScreenTest_ps->Overlays.res15_b = IsBitSet(v_Byte_u8, 2); // ( (v_Byte_u8 & (1 << 2)) != 0);
  b_ScreenTest_ps->Overlays.res14_b = IsBitSet(v_Byte_u8, 3); // ( (v_Byte_u8 & (1 << 3)) != 0);
  b_ScreenTest_ps->Overlays.res13_b = IsBitSet(v_Byte_u8, 4); // ( (v_Byte_u8 & (1 << 4)) != 0);
  b_ScreenTest_ps->Overlays.res12_b = IsBitSet(v_Byte_u8, 5); // ( (v_Byte_u8 & (1 << 5)) != 0);
  b_ScreenTest_ps->Overlays.res11_b = IsBitSet(v_Byte_u8, 6); // ( (v_Byte_u8 & (1 << 6)) != 0);
  b_ScreenTest_ps->Overlays.res10_b = IsBitSet(v_Byte_u8, 7); // ( (v_Byte_u8 & (1 << 7)) != 0);
  printBits(v_Byte_u8);
  
  printf("\n\n Read Byte1: \n");
  v_Byte_u8 = read_u8(i_Data_pc, &v_Index_u32);
  b_ScreenTest_ps->Overlays.res07_b                 = IsBitSet(v_Byte_u8, 0); // ( (v_Byte_u8 & (1 << 0)) != 0);
  b_ScreenTest_ps->Overlays.res06_b                 = IsBitSet(v_Byte_u8, 1); // ( (v_Byte_u8 & (1 << 1)) != 0);
  b_ScreenTest_ps->Overlays.res05_b                 = IsBitSet(v_Byte_u8, 2); // ( (v_Byte_u8 & (1 << 2)) != 0);
  b_ScreenTest_ps->Overlays.res04_b                 = IsBitSet(v_Byte_u8, 3); // ( (v_Byte_u8 & (1 << 3)) != 0);
  b_ScreenTest_ps->Overlays.res03_b                 = IsBitSet(v_Byte_u8, 4); // ( (v_Byte_u8 & (1 << 4)) != 0);
  b_ScreenTest_ps->Overlays.Static_Trajectories_b   = IsBitSet(v_Byte_u8, 5); // ( (v_Byte_u8 & (1 << 5)) != 0);
  b_ScreenTest_ps->Overlays.Dynamic_Trajectories_b  = IsBitSet(v_Byte_u8, 6); // ( (v_Byte_u8 & (1 << 6)) != 0);
  b_ScreenTest_ps->Overlays.Vehicle_Icon_b          = IsBitSet(v_Byte_u8, 7); // ( (v_Byte_u8 & (1 << 7)) != 0);
  printBits(v_Byte_u8);
}

#include <assert.h>

int main()
{
  // ARM R7, A53 area little endian, windows is little endian, so no need for conversion of read/write right now
  int endianTester = 1;
  bool littleEndian = (*(char*)&endianTester == 1);
  if (littleEndian)
  {
    printf("\nLittle-Endian\n");
  }
  else
  {
    printf("Big-Endian\n");
  }

  // Test Request Screen
  RequestScreen_t setReqScreen;
  for (int i = 0; i < 32; ++i)
  {
    setReqScreen.Overlays_au8[i] = i;
  }
  setReqScreen.Version_s32 = 12;
  setReqScreen.ViewID_s32  = 2;
  setReqScreen.ZoomFactor_u8 = 0;

  uint8_t* dataPrt = (uint8_t*)&setReqScreen;

  RequestScreen_t getReqScreen;
  readTest(dataPrt, sizeof(RequestScreen_t), &getReqScreen);


  // Test All Data Types
  TestAllDataTypes_t setTest;
  setTest.Test_u8 =    8;
  setTest.Test_s8 =   -8;
  setTest.Test_u16 =  16;
  setTest.Test_s16 = -16;
  setTest.Test_u32 =  32;
  setTest.Test_s32 = -32;
  setTest.Test_u64 =  64;
  setTest.Test_s64 = -64;
  setTest.Test_f32 = -32.0F;

  const uint32_t c_TestLength_u32 = sizeof(TestAllDataTypes_t) + 2; // + 2 for msg id
  uint8_t v_TestAllDataTypes_au8[c_TestLength_u32];
  
  uint32_t v_Index_u32 = 0;
  uint8_t* v_DataPtr_u8 = &v_TestAllDataTypes_au8[0];
  v_Index_u32 += testAddHeaderToMessage_u32(v_DataPtr_u8, e_TestAllDataTypes);
  v_DataPtr_u8 += v_Index_u32;

  writeTestAllDataTypes_b(v_DataPtr_u8, c_TestLength_u32, &setTest);

  TestAllDataTypes_t getTest;
  uint8_t* v_GetDataPtr_u8 = &v_TestAllDataTypes_au8[0];
  MessageID_t v_MsgId_e = getMessageId_e(&v_GetDataPtr_u8);
  readTestAllDataTypes_b(v_GetDataPtr_u8, c_TestLength_u32, &getTest);



  const uint32_t c_ScreenTestLength_u32 = sizeof(ScreenTest_t) + 2;
  uint8_t v_ScreenWriteTestData[c_ScreenTestLength_u32];
  ScreenTest_t v_ScreenTestWrite_s;
  v_ScreenTestWrite_s.ViewID = 1;
  v_ScreenTestWrite_s.ZoomFactor = 2;

  memset(&v_ScreenTestWrite_s.Overlays, 0, sizeof(v_ScreenTestWrite_s.Overlays));


  v_ScreenTestWrite_s.Overlays.res17_b                = 1;        /* Bit 15 */
  v_ScreenTestWrite_s.Overlays.res16_b                = 1;
  v_ScreenTestWrite_s.Overlays.res15_b                = 0;
  v_ScreenTestWrite_s.Overlays.res14_b                = 0;
  v_ScreenTestWrite_s.Overlays.res13_b                = 1;
  v_ScreenTestWrite_s.Overlays.res12_b                = 1;
  v_ScreenTestWrite_s.Overlays.res11_b                = 1;
  v_ScreenTestWrite_s.Overlays.res10_b                = 0;

  v_ScreenTestWrite_s.Overlays.res07_b                = 0;        /* Bit 07 */
  v_ScreenTestWrite_s.Overlays.res06_b                = 0;
  v_ScreenTestWrite_s.Overlays.res05_b                = 1;
  v_ScreenTestWrite_s.Overlays.res04_b                = 1;
  v_ScreenTestWrite_s.Overlays.res03_b                = 0;
  v_ScreenTestWrite_s.Overlays.Static_Trajectories_b  = 0;
  v_ScreenTestWrite_s.Overlays.Dynamic_Trajectories_b = 0;
  v_ScreenTestWrite_s.Overlays.Vehicle_Icon_b         = 1;        /* Bit 00 */


  writeScreenTest(&v_ScreenWriteTestData[0], c_ScreenTestLength_u32, &v_ScreenTestWrite_s);

  
  for (size_t currByte = 0; currByte < sizeof(OverlayGroups_t); ++currByte)
  {
    uint8_t* ovlBits = (uint8_t*)&v_ScreenTestWrite_s.Overlays;
    ovlBits += currByte;

    printf("\n\nByte%d: \n", currByte);

    printBits(*ovlBits);
  }

  ScreenTest_t v_ReadTest_s;
  readScreenTest(&v_ScreenWriteTestData[0], c_ScreenTestLength_u32, &v_ReadTest_s);

  assert(v_ReadTest_s.Overlays.res17_b                 ==  v_ScreenTestWrite_s.Overlays.res17_b                );        /* Bit 15 */
  assert(v_ReadTest_s.Overlays.res16_b                 ==  v_ScreenTestWrite_s.Overlays.res16_b                );
  assert(v_ReadTest_s.Overlays.res15_b                 ==  v_ScreenTestWrite_s.Overlays.res15_b                );
  assert(v_ReadTest_s.Overlays.res14_b                 ==  v_ScreenTestWrite_s.Overlays.res14_b                );
  assert(v_ReadTest_s.Overlays.res13_b                 ==  v_ScreenTestWrite_s.Overlays.res13_b                );
  assert(v_ReadTest_s.Overlays.res12_b                 ==  v_ScreenTestWrite_s.Overlays.res12_b                );
  assert(v_ReadTest_s.Overlays.res11_b                 ==  v_ScreenTestWrite_s.Overlays.res11_b                );
  assert(v_ReadTest_s.Overlays.res10_b                 ==  v_ScreenTestWrite_s.Overlays.res10_b                );

  assert(v_ReadTest_s.Overlays.res07_b                 ==  v_ScreenTestWrite_s.Overlays.res07_b                );        /* Bit 07 */
  assert(v_ReadTest_s.Overlays.res06_b                 ==  v_ScreenTestWrite_s.Overlays.res06_b                );
  assert(v_ReadTest_s.Overlays.res05_b                 ==  v_ScreenTestWrite_s.Overlays.res05_b                );
  assert(v_ReadTest_s.Overlays.res04_b                 ==  v_ScreenTestWrite_s.Overlays.res04_b                );
  assert(v_ReadTest_s.Overlays.res03_b                 ==  v_ScreenTestWrite_s.Overlays.res03_b                );
  assert(v_ReadTest_s.Overlays.Static_Trajectories_b   ==  v_ScreenTestWrite_s.Overlays.Static_Trajectories_b  );
  assert(v_ReadTest_s.Overlays.Dynamic_Trajectories_b  ==  v_ScreenTestWrite_s.Overlays.Dynamic_Trajectories_b );
  assert(v_ReadTest_s.Overlays.Vehicle_Icon_b          ==  v_ScreenTestWrite_s.Overlays.Vehicle_Icon_b         );        /* Bit 00 */

  return 0;
}



