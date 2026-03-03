//--------------------------------------------------------------------------
/// @file JobKM.h
/// @brief Contains The KM job definition.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef JOBKM_H_
#define JOBKM_H_

#include "PlatformDataTypes.h"

#ifdef JOBKM_CPP

#include "IDataProviderKM.h"

typedef unsigned char  bool_t;



namespace KM
{
 class JobKM
  {
  public:

    JobKM( IDataProviderKM *);
    virtual ~JobKM();

    virtual bool_t onInit_b();

    virtual void   onVariantChanged_v(bool_t i_FirstTime_b);

    virtual bool_t onRun_b();

    virtual void   onCleanup_v();

  private:
    bool_t initDone_b;
    void start_v();
    bool_t hasNext_b();
    void execute_v();
    void end_v();
    void dump_v();
    void reset_v();
    
	IDataProviderKM *dataProvider_ro;
  };
}

#else
typedef struct {
  boolean potMap_reset_KM;           /* '<Root>/potMap_reset_KM' */
  real32_T RHRWheelSpeedData;          /* '<Root>/RHRWheelSpeedData' */
  real32_T LHRWheelSpeedData;          /* '<Root>/LHRWheelSpeedData' */
  real32_T RHR_FastPulseCounterData;   /* '<Root>/RHR_FastPulseCounterData' */
  real32_T LHR_FastPulseCounterData;   /* '<Root>/LHR_FastPulseCounterData' */
  uint8_T GearEngagedData;             /* '<Root>/GearEngagedData' */
  real32_T LwsAngleData;               /* '<Root>/LwsAngleData' */
  uint8_T IePRX_e_VehWhlBase;          /* '<Root>/IePRX_e_VehWhlBase' */
  uint16_T IePRX_mm_TyreSize;          /* '<Root>/IePRX_mm_TyreSize' */
  uint8_T IePRX_e_StrRatRckPinionTyp;  /* '<Root>/IePRX_e_StrRatRckPinionTyp' */
} KmFeatureComdata;

typedef struct {
  real32_T m_Global_x;                 /* '<Root>/m_Global_x' */
  real32_T m_Global_y;                 /* '<Root>/m_Global_y' */
  real32_T m_Global_yaw_deg;           /* '<Root>/m_Global_yaw_deg' */
  real32_T dx_mps;                     /* '<Root>/dx_mps' */
  real32_T dy_mps;                     /* '<Root>/dy_mps' */
  real32_T dyaw_degps;                 /* '<Root>/dyaw_degps' */
  real32_T ds_mps;                     /* '<Root>/ds_mps' */
} ExtY_Kinematic_T;


typedef struct KinematicData_s
{
    float32_t dx_m;
    float32_t dy_m;
    float32_t dyaw_rad;
    float32_t timestamp_s;

    float32_t m_Global_dx;
    float32_t m_Global_dy;
    float32_t m_Global_dyaw_rad;
    float32_t ds_mps; 
}IKinematicData_t;

void KM_Init();
void KM_onRun();
void KM_SetData();
void KM_GetData( KmFeatureComdata *data);

#endif //JOBKM_CPP

#endif // JOBKM_H_
