// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           vp1_ackermann_model.h
 *  @brief          Ackermann model implementation
 *
 *  @version        1.01
 *  @author         Alex Orlov & Pavel Gaenko
 *  @date           09.08.2019
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#ifndef VP1_ACKERMANN_MODEL
#define VP1_ACKERMANN_MODEL

//#include "vp1_internal_types.h"
//#include "vp1_geometry_math.h"

typedef enum _Positions
{
    POS_REAR_CENTER = 0,
    POS_REAR_LEFT = 1,
    POS_REAR_RIGHT = 2,
    POS_FORWARD_LEFT = 3,
    POS_FORWARD_RIGHT = 4,
    POS_NUM
} Positions;


/**
 * @brief WheelMessage
 */
typedef struct _WheelMessage
{
    int16_t         cnt;
    uint64_t timeStamp;
} WheelMessage;

extern WheelMessage WheelMessage_createDefault(void);

extern WheelMessage WheelMessage_create(uint64_t timeStamp, int cnt);

// /**
//  * @brief SlidingWindFilter
//  */
// typedef struct _SlidingWindFilter
// {
//     int16_t pos;
//     vector* elems; // float32_t
//     size_t size;
//     float32_t sum;
// } SlidingWindFilter;

/**
 * @brief AckermannModel
 */
typedef struct _AckermannModel { 
    float32_t wheelBase;
    float32_t rearLRBase;
    float32_t forwardLRBase;
} AckermannModel;


extern AckermannModel AckermannModel_create(float32_t wheelBase, float32_t rearLRBase, float32_t forwardLRBase);

extern void AckermannModel_copy(const AckermannModel * src, AckermannModel * dst);

extern float32_t AckermannModel_getRadius(const AckermannModel* self, float32_t steerAng, Positions pz);

extern void AckermannModel_getRatios(const AckermannModel* self, float32_t steerAng, float32_t* ratios);

extern mat33f_t AckermannModel_affine_delta_poz(const AckermannModel * self, float32_t steerAng, float32_t dist);

#endif
