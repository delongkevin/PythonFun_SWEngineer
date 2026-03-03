#ifndef VAR_SCALES_H
#define VAR_SCALES_H

#include "mecl/core/MeclTypes.h"

#define REAR_SCALE_SIZE 800

extern float32_t g__Rear_Scale[REAR_SCALE_SIZE];

void loadRearScale();

#endif // !VAR_SCALES_H
