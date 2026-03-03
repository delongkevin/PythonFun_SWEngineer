//--------------------------------------------------------------------------
/// @file ODData.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_OD_DATA_H
#define CONTAINER_OD_DATA_H

#include <osal/threading/Mutex.h>

#include "container/DataContainer.h"

namespace container
{

/* /// */
/* DNN */
/* /// */
enum TeVBII_e_RAEBState
{
    RAEB_INVALID = 0,
    RAEB_ACTIVE = 1,
    RAEB_STANDBY = 2,
    RAEB_NOTAVAILABLE = 3,
    RAEB_ERROR = 4
};

enum TeEnv_e_ObjClass
{
    OBJ_INVALID = 0,
    OBJ_PASSENGER_CARS = 1,
    OBJ_PEDESTRIAN = 2,
    OBJ_BICYCLIST = 3,
    OBJ_LIGHT_POLES = 4,
    OBJ_PARKING_POLES = 5,
    OBJ_MOTORCYCLES = 6,
    OBJ_BUSES = 7,
    OBJ_TRUCKS = 8,
    OBJ_BINS_CARTS_GARAGE = 9,
    OBJ_WALLS = 10
};

enum e_SensorSource
{
    SVS_INVALID = 0,
    SVS_FRONT = 1,
    SVS_REAR = 2,
    SVS_LEFT = 3,
    SVS_RIGHT = 4
};

struct ObjectBoundingBox
{
  int L;
  int R;
  int T;
  int B;
};

struct IaDNN_e_EnvObjList
{
    uint8_t ObjectID;
    ObjectBoundingBox ObjectBoundingBox_s;
    TeEnv_e_ObjClass ObjClass;
    e_SensorSource SensorSource;
    float32_t ObjectConfidence;
};

enum IaDNN_Model_Status
{
    MODEL_INVALID = 0,
    MODEL_LOADED_SUCCESSFULLY = 1,
    MODEL_ERROR = 2
};

struct DNN_Input
{
    float32_t IeVBII_kph_EgoVehLongSpd;
    uint8_t IeVBII_cnt_CurrentGear;
    TeVBII_e_RAEBState IeVBII_e_RAEBState;
    uint8_t* OD_img_pu8;
};

struct DNN_Output
{
    IaDNN_e_EnvObjList DNN_EnvSignals[20];
    uint8_t IeVBII_cnt_currDetection;
    IaDNN_Model_Status DNNModelStatus;
    float32_t DetectionTimestamp;
};

class ODData : public DataContainer
{
public:
  ODData();
  virtual ~ODData();

  void setDNNOutput_v(DNN_Output i_DNNOutput_s);
  DNN_Output getDNNOutput_v();
  DNN_Output m_DNNOutput_s;

private:
  osal::Mutex mutex_o;
};

} // namespace container

#endif // CONTAINER_OD_DATA_H
