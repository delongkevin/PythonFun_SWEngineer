#ifndef _USS_2D_POINT_MAP_H_
#define _USS_2D_POINT_MAP_H_

#include "PlatformDataTypes.h"
#include "LwSpd_SimulinkAdaptation.h"
#if 0
typedef struct ME_US_S_PointOutputBuff_s
{
    sint16_t x;
    sint16_t y;
    uint8_t  height;
    uint8_t  confidence;
    uint8_t  age;
} ME_US_S_PointOutputBuff_t;

typedef struct US_S_PointsMapOutputBuff_s
{
    uint32_t timestamp;
    ME_US_S_PointOutputBuff_t pointMap[96];
} ME_US_PointMapOutputBuff_t;

typedef struct ME_US_ObjectDetOutputBuff_s
{
    sint16_t centerX;
    sint16_t centerY;
    sint16_t closeX;
    sint16_t closeY;
    uint8_t  height;
    uint8_t  confidence;
    uint8_t  age;
    uint8_t  diameter;
} ME_US_ObjectDetOutputBuff_t;

typedef struct US_S_ObjList_s
{
    uint32_t timestamp;
    ME_US_ObjectDetOutputBuff_t objects[48];
} ME_US_ObjectMapOutputBuff_t;

typedef struct ME_US_BlockageBitOutputBuff_s
{
    uint32_t timestamp;
    uint16_t blockageFlagBits;
} ME_US_BlockageBitOutputBuff_t;

typedef struct ME_US_DiagnosticsOutputBuff_s
{
    uint32_t timestamp;
    uint16_t overTempFault;
    uint16_t commFault;
    uint16_t hardwareFault;
} ME_US_DiagnosticsOutputBuff_t;

typedef struct ME_US_FiringSensorsOutputBuff_s
{
    uint32_t timestamp;
    uint16_t firingSensors;
} ME_US_FiringSensorsOutputBuff_t;

typedef struct ME_US_ZoneInfoOutputBuff_s
{
    uint32_t timestamp;
    uint8_t  zoneInfo[16];
} ME_US_ZoneInfoOutputBuff_t;
#endif
#endif //_USS_2D_POINT_MAP_H_
