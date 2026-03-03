
#include "JobKM.h"
#include "../algo/include/KM.h"


/* External inputs (root inport signals with default storage) */
extern ExtU_KM_T KM_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_KM_T KM_Y;

void KM_Init(void)
{
    KM_initialize();
}


void KM_onRun(void)
{
    KmFeatureComdata VCANData;
    KM_GetData(&VCANData);   /*Get data from Com*/
    /* Map received can data to Algorithm*/
    KM_U.RHRWheelSpeedData = (real32_T)VCANData.RHRWheelSpeedData * 0.0625f;        /* '<Root>/RHRWheelSpeedData' */
    KM_U.LHRWheelSpeedData = (real32_T)VCANData.LHRWheelSpeedData * 0.0625f;        /* '<Root>/LHRWheelSpeedData' */
    KM_U.RHR_FastPulseCounterData = (real32_T)VCANData.RHR_FastPulseCounterData; /* '<Root>/RHR_FastPulseCounterData' */
    KM_U.LHR_FastPulseCounterData = (real32_T)VCANData.LHR_FastPulseCounterData; /* '<Root>/LHR_FastPulseCounterData' */
    KM_U.GearEngagedData = VCANData.GearEngagedData;           /* '<Root>/GearEngagedData' */
    KM_U.LwsAngleData = (real32_T)((VCANData.LwsAngleData * 0.1f) - 720.0f);             /* '<Root>/LwsAngleData' */
    KM_U.potMap_reset_KM = VCANData.potMap_reset_KM;
    KM_U.IePRX_mm_TyreSize = VCANData.IePRX_mm_TyreSize;
    KM_U.IePRX_e_VehWhlBase = VCANData.IePRX_e_VehWhlBase;
    KM_U.IePRX_e_StrRatRckPinionTyp = VCANData.IePRX_e_StrRatRckPinionTyp;
	
    KM_step();

    ExtY_Kinematic_T Kinematic_T;
 
    Kinematic_T.m_Global_x = KM_Y.m_Global_x;       /* '<Root>/X_MABx' */
    Kinematic_T.m_Global_y = KM_Y.m_Global_y;       /* '<Root>/Y_MABx' */
    Kinematic_T.m_Global_yaw_deg = KM_Y.heading_MABx; /* '<Root>/heading_MABx' */
    Kinematic_T.dx_mps = KM_Y.dx_m;         // '<Root>/dx//dt'
    Kinematic_T.dy_mps = KM_Y.dy_m;         // '<Root>/dy//dt'
    Kinematic_T.dyaw_degps = KM_Y.dyaw;         /* '<Root>/dyaw' */
    Kinematic_T.ds_mps = KM_Y.ds;           /* '<Root>/ds' */

    KM_SetData(&Kinematic_T); /*Set data to IPC*/
}

