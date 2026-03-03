/*
 * File: FeatureArbiter.c
 *
 * Code generated for Simulink model 'FeatureArbiter'.
 *
 * Model version                  : 1.309
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov  9 17:38:22 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "FeatureArbiter.h"
#include "FeatureArbiter_private.h"
#include "SignalDef.h"

/* Block signals (default storage) */
B_FeatureArbiter_T FeatureArbiter_B;

/* Model step function */
extern "C" void FeatureArbiter_step(void)
{
  /* BusCreator: '<S7>/Bus Creator3' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/Constant6'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   */
  FeatureArbiter_B.MbFA_DefaultChimeData.MeFA_b_ChimeActvLhf = false;
  FeatureArbiter_B.MbFA_DefaultChimeData.MeFA_b_ChimeActvRhf = false;
  FeatureArbiter_B.MbFA_DefaultChimeData.MeFA_b_ChimeActvLhr = false;
  FeatureArbiter_B.MbFA_DefaultChimeData.MeFA_b_ChimeActvRhr = false;
  FeatureArbiter_B.MbFA_DefaultChimeData.MeFA_e_PamChimeRepRateSts =
    TeFA_e_PamChimeRepRateSts_Continuous_0_Hz;
  FeatureArbiter_B.MbFA_DefaultChimeData.MeFA_e_PamChimeTyp =
    TeFA_e_PamChimeTyp_None;
  FeatureArbiter_B.MbFA_DefaultChimeData.MeFA_e_PamVol = TeFA_e_PamVol_None;

  /* DataStoreRead: '<S12>/Data Store Read3' */
  SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Get(&(FeatureArbiter_B.MbFA_FPAWarnOut));

  /* DataTypeConversion: '<S13>/Data Type Conversion17' */
  FeatureArbiter_B.IeFA_b_ChimeActvRhr = (((int32_T)
    FeatureArbiter_B.MbFA_FPAWarnOut.IeAP_b_ChimeActvReqLHF) != 0);

  /* DataTypeConversion: '<S13>/Data Type Conversion15' */
  FeatureArbiter_B.LogicalOperator_lhui = (((int32_T)
    FeatureArbiter_B.MbFA_FPAWarnOut.IeAP_b_ChimeActvReqRHF) != 0);

  /* DataStoreRead: '<S12>/Data Store Read4' */
  SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Get(&(FeatureArbiter_B.MbFA_RPAWarnOut));

  /* DataTypeConversion: '<S13>/Data Type Conversion25' */
  FeatureArbiter_B.MeFA_b_RPAStatus = (((int32_T)
    FeatureArbiter_B.MbFA_RPAWarnOut.IeAP_b_ChimeActvReqLHR) != 0);

  /* DataTypeConversion: '<S13>/Data Type Conversion18' */
  FeatureArbiter_B.MeFA_b_FPAStatus = (((int32_T)
    FeatureArbiter_B.MbFA_RPAWarnOut.IeAP_b_ChimeActvReqRHR) != 0);

  /* DataStoreRead: '<S12>/Data Store Read5' */
  SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Get(&(FeatureArbiter_B.MbFA_PAStateOut));

  /* DataTypeConversion: '<S13>/Data Type Conversion26' */
  FeatureArbiter_B.IeFA_e_PamChimeRepRateSts = (TeFA_e_PamChimeRepRateSts)
    FeatureArbiter_B.MbFA_PAStateOut.IeAP_e_PAMChimeRepnRate;

  /* DataTypeConversion: '<S13>/Data Type Conversion28' */
  FeatureArbiter_B.IeFA_e_PamChimeTyp = (TeFA_e_PamChimeTyp)
    FeatureArbiter_B.MbFA_PAStateOut.IeAP_e_PAMChimeTyp;

  /* DataTypeConversion: '<S13>/Data Type Conversion27' */
  FeatureArbiter_B.IeFA_e_PamVol = (TeFA_e_PamVol)
    FeatureArbiter_B.MbFA_PAStateOut.IeAP_e_PAMVolSig;

  /* BusCreator: '<S13>/Bus Creator2' */
  FeatureArbiter_B.MbFA_APAChimeData.MeFA_b_ChimeActvLhf =
    FeatureArbiter_B.IeFA_b_ChimeActvRhr;
  FeatureArbiter_B.MbFA_APAChimeData.MeFA_b_ChimeActvRhf =
    FeatureArbiter_B.LogicalOperator_lhui;
  FeatureArbiter_B.MbFA_APAChimeData.MeFA_b_ChimeActvLhr =
    FeatureArbiter_B.MeFA_b_RPAStatus;
  FeatureArbiter_B.MbFA_APAChimeData.MeFA_b_ChimeActvRhr =
    FeatureArbiter_B.MeFA_b_FPAStatus;
  FeatureArbiter_B.MbFA_APAChimeData.MeFA_e_PamChimeRepRateSts =
    FeatureArbiter_B.IeFA_e_PamChimeRepRateSts;
  FeatureArbiter_B.MbFA_APAChimeData.MeFA_e_PamChimeTyp =
    FeatureArbiter_B.IeFA_e_PamChimeTyp;
  FeatureArbiter_B.MbFA_APAChimeData.MeFA_e_PamVol =
    FeatureArbiter_B.IeFA_e_PamVol;

  /* DataStoreRead: '<S12>/Data Store Read1' */
  SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(&(FeatureArbiter_B.MbFA_THASmVcOut));

  /* DataTypeConversion: '<S13>/Data Type Conversion3' */
  FeatureArbiter_B.MeFA_b_ChimeActvLhf = (((int32_T)
    FeatureArbiter_B.MbFA_THASmVcOut.IeTHA_b_ChimeActvLhf) != 0);

  /* DataTypeConversion: '<S13>/Data Type Conversion4' */
  FeatureArbiter_B.MeFA_b_ChimeActvRhf = (((int32_T)
    FeatureArbiter_B.MbFA_THASmVcOut.IeTHA_b_ChimeActvRhf) != 0);

  /* DataTypeConversion: '<S13>/Data Type Conversion5' */
  FeatureArbiter_B.MeFA_b_FPAStatus = (((int32_T)
    FeatureArbiter_B.MbFA_THASmVcOut.IeTHA_b_ChimeActvLhr) != 0);

  /* DataTypeConversion: '<S13>/Data Type Conversion12' */
  FeatureArbiter_B.MeFA_b_RPAStatus = (((int32_T)
    FeatureArbiter_B.MbFA_THASmVcOut.IeTHA_b_ChimeActvRhr) != 0);

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  FeatureArbiter_B.IeFA_e_PamChimeRepRateSts = (TeFA_e_PamChimeRepRateSts)
    FeatureArbiter_B.MbFA_THASmVcOut.IeTHA_e_PamChimeRepRateSts;

  /* DataTypeConversion: '<S13>/Data Type Conversion2' */
  FeatureArbiter_B.IeFA_e_PamChimeTyp = (TeFA_e_PamChimeTyp)
    FeatureArbiter_B.MbFA_THASmVcOut.IeTHA_e_PamChimeTyp;

  /* DataTypeConversion: '<S13>/Data Type Conversion13' */
  FeatureArbiter_B.IeFA_e_PamVol = (TeFA_e_PamVol)
    FeatureArbiter_B.MbFA_THASmVcOut.IeTHA_e_PamVol;

  /* BusCreator: '<S13>/Bus Creator1' */
  FeatureArbiter_B.MbFA_THAChimeData.MeFA_b_ChimeActvLhf =
    FeatureArbiter_B.MeFA_b_ChimeActvLhf;
  FeatureArbiter_B.MbFA_THAChimeData.MeFA_b_ChimeActvRhf =
    FeatureArbiter_B.MeFA_b_ChimeActvRhf;
  FeatureArbiter_B.MbFA_THAChimeData.MeFA_b_ChimeActvLhr =
    FeatureArbiter_B.MeFA_b_FPAStatus;
  FeatureArbiter_B.MbFA_THAChimeData.MeFA_b_ChimeActvRhr =
    FeatureArbiter_B.MeFA_b_RPAStatus;
  FeatureArbiter_B.MbFA_THAChimeData.MeFA_e_PamChimeRepRateSts =
    FeatureArbiter_B.IeFA_e_PamChimeRepRateSts;
  FeatureArbiter_B.MbFA_THAChimeData.MeFA_e_PamChimeTyp =
    FeatureArbiter_B.IeFA_e_PamChimeTyp;
  FeatureArbiter_B.MbFA_THAChimeData.MeFA_e_PamVol =
    FeatureArbiter_B.IeFA_e_PamVol;

  /* DataStoreRead: '<S12>/Data Store Read2' */
  SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(&(FeatureArbiter_B.MbFA_DriveAssistStatOut));

  /* DataTypeConversion: '<S13>/Data Type Conversion19' */
  FeatureArbiter_B.MeFA_b_FPAStatus = (((int32_T)
    FeatureArbiter_B.MbFA_DriveAssistStatOut.MeAP_b_ChimeActvReqLHFSVM) != 0);

  /* DataTypeConversion: '<S13>/Data Type Conversion16' */
  FeatureArbiter_B.MeFA_b_RPAStatus = (((int32_T)
    FeatureArbiter_B.MbFA_DriveAssistStatOut.MeAP_b_ChimeActvReqRHFSVM) != 0);

  /* DataTypeConversion: '<S13>/Data Type Conversion21' */
  FeatureArbiter_B.LogicalOperator_lhui = (((int32_T)
    FeatureArbiter_B.MbFA_DriveAssistStatOut.MeAP_b_ChimeActvReqLHRSVM) != 0);

  /* DataTypeConversion: '<S13>/Data Type Conversion20' */
  FeatureArbiter_B.IeFA_b_ChimeActvRhr = (((int32_T)
    FeatureArbiter_B.MbFA_DriveAssistStatOut.MeAP_b_ChimeActvReqRHRSVM) != 0);

  /* DataTypeConversion: '<S13>/Data Type Conversion22' */
  FeatureArbiter_B.IeFA_e_PamChimeRepRateSts = (TeFA_e_PamChimeRepRateSts)
    FeatureArbiter_B.MbFA_DriveAssistStatOut.MeAP_e_PAMChimeRepnRateSVM;

  /* DataTypeConversion: '<S13>/Data Type Conversion24' */
  FeatureArbiter_B.IeFA_e_PamChimeTyp = (TeFA_e_PamChimeTyp)
    FeatureArbiter_B.MbFA_DriveAssistStatOut.MeAP_e_PAMChimeTypSVM;

  /* DataTypeConversion: '<S13>/Data Type Conversion23' */
  FeatureArbiter_B.IeFA_e_PamVol = (TeFA_e_PamVol)
    FeatureArbiter_B.MbFA_DriveAssistStatOut.MeAP_e_PAMVolSigSVM;

  /* BusCreator: '<S13>/Bus Creator3' */
  FeatureArbiter_B.MbFA_SelChimeData.MeFA_b_ChimeActvLhf =
    FeatureArbiter_B.MeFA_b_FPAStatus;
  FeatureArbiter_B.MbFA_SelChimeData.MeFA_b_ChimeActvRhf =
    FeatureArbiter_B.MeFA_b_RPAStatus;
  FeatureArbiter_B.MbFA_SelChimeData.MeFA_b_ChimeActvLhr =
    FeatureArbiter_B.LogicalOperator_lhui;
  FeatureArbiter_B.MbFA_SelChimeData.MeFA_b_ChimeActvRhr =
    FeatureArbiter_B.IeFA_b_ChimeActvRhr;
  FeatureArbiter_B.MbFA_SelChimeData.MeFA_e_PamChimeRepRateSts =
    FeatureArbiter_B.IeFA_e_PamChimeRepRateSts;
  FeatureArbiter_B.MbFA_SelChimeData.MeFA_e_PamChimeTyp =
    FeatureArbiter_B.IeFA_e_PamChimeTyp;
  FeatureArbiter_B.MbFA_SelChimeData.MeFA_e_PamVol =
    FeatureArbiter_B.IeFA_e_PamVol;

  /* Logic: '<S13>/Logical Operator' */
  FeatureArbiter_B.MeFA_b_FPAStatus = ((FeatureArbiter_B.MeFA_b_FPAStatus) ||
    (FeatureArbiter_B.MeFA_b_RPAStatus));

  /* Switch: '<S4>/Switch' */
  if (!FeatureArbiter_B.MeFA_b_FPAStatus) {
    /* Logic: '<S13>/Logical Operator1' */
    FeatureArbiter_B.MeFA_b_THAChimeReq = ((FeatureArbiter_B.MeFA_b_ChimeActvLhf)
      || (FeatureArbiter_B.MeFA_b_ChimeActvRhf));

    /* Switch: '<S4>/Switch1' */
    if (FeatureArbiter_B.MeFA_b_THAChimeReq) {
      FeatureArbiter_B.Switch1 = FeatureArbiter_B.MbFA_THAChimeData;
    } else {
      /* Logic: '<S4>/Logical Operator1' */
      FeatureArbiter_B.LogicalOperator1 =
        ((((FeatureArbiter_B.MbFA_APAChimeData.MeFA_b_ChimeActvLhf) ||
           (FeatureArbiter_B.MbFA_APAChimeData.MeFA_b_ChimeActvRhf)) ||
          (FeatureArbiter_B.MbFA_APAChimeData.MeFA_b_ChimeActvLhr)) ||
         (FeatureArbiter_B.MbFA_APAChimeData.MeFA_b_ChimeActvRhr));

      /* Switch: '<S4>/Switch2' */
      if (FeatureArbiter_B.LogicalOperator1) {
        FeatureArbiter_B.Switch2 = FeatureArbiter_B.MbFA_APAChimeData;
      } else {
        FeatureArbiter_B.Switch2 = FeatureArbiter_B.MbFA_DefaultChimeData;
      }

      /* End of Switch: '<S4>/Switch2' */
      FeatureArbiter_B.Switch1 = FeatureArbiter_B.Switch2;
    }

    /* End of Switch: '<S4>/Switch1' */
    FeatureArbiter_B.MbFA_SelChimeData = FeatureArbiter_B.Switch1;
  }

  /* End of Switch: '<S4>/Switch' */

  /* DataTypeConversion: '<S3>/Data Type Conversion3' */
  FeatureArbiter_B.MeFA_b_FPAStatus =
    FeatureArbiter_B.MbFA_SelChimeData.MeFA_b_ChimeActvLhf;

  /* DataTypeConversion: '<S3>/Data Type Conversion4' */
  FeatureArbiter_B.MeFA_b_RPAStatus =
    FeatureArbiter_B.MbFA_SelChimeData.MeFA_b_ChimeActvRhf;

  /* DataTypeConversion: '<S3>/Data Type Conversion5' */
  FeatureArbiter_B.LogicalOperator_lhui =
    FeatureArbiter_B.MbFA_SelChimeData.MeFA_b_ChimeActvLhr;

  /* DataTypeConversion: '<S3>/Data Type Conversion12' */
  FeatureArbiter_B.IeFA_b_ChimeActvRhr =
    FeatureArbiter_B.MbFA_SelChimeData.MeFA_b_ChimeActvRhr;

  /* DataTypeConversion: '<S3>/Data Type Conversion1' */
  FeatureArbiter_B.IeFA_e_PamChimeRepRateSts =
    FeatureArbiter_B.MbFA_SelChimeData.MeFA_e_PamChimeRepRateSts;

  /* DataTypeConversion: '<S3>/Data Type Conversion2' */
  FeatureArbiter_B.IeFA_e_PamChimeTyp =
    FeatureArbiter_B.MbFA_SelChimeData.MeFA_e_PamChimeTyp;

  /* DataTypeConversion: '<S3>/Data Type Conversion13' */
  FeatureArbiter_B.IeFA_e_PamVol =
    FeatureArbiter_B.MbFA_SelChimeData.MeFA_e_PamVol;

  /* BusCreator: '<S3>/Bus Creator1' */
  FeatureArbiter_B.TbFA_ArbiterOutput_t_bnzj.IeFA_b_ChimeActvLhf =
    FeatureArbiter_B.MeFA_b_FPAStatus;
  FeatureArbiter_B.TbFA_ArbiterOutput_t_bnzj.IeFA_b_ChimeActvRhf =
    FeatureArbiter_B.MeFA_b_RPAStatus;
  FeatureArbiter_B.TbFA_ArbiterOutput_t_bnzj.IeFA_b_ChimeActvLhr =
    FeatureArbiter_B.LogicalOperator_lhui;
  FeatureArbiter_B.TbFA_ArbiterOutput_t_bnzj.IeFA_b_ChimeActvRhr =
    FeatureArbiter_B.IeFA_b_ChimeActvRhr;
  FeatureArbiter_B.TbFA_ArbiterOutput_t_bnzj.IeFA_e_PamChimeRepRateSts =
    FeatureArbiter_B.IeFA_e_PamChimeRepRateSts;
  FeatureArbiter_B.TbFA_ArbiterOutput_t_bnzj.IeFA_e_PamChimeTyp =
    FeatureArbiter_B.IeFA_e_PamChimeTyp;
  FeatureArbiter_B.TbFA_ArbiterOutput_t_bnzj.IeFA_e_PamVol =
    FeatureArbiter_B.IeFA_e_PamVol;

  /* DataStoreWrite: '<S3>/Data Store Write' */
  static TbFA_ArbiterOutput_t PrevArbiterOutput;
  if(0 != memcmp(&FeatureArbiter_B.TbFA_ArbiterOutput_t_bnzj, &PrevArbiterOutput, sizeof(PrevArbiterOutput)))
  {
    SigMgr_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t_Put(&(FeatureArbiter_B.TbFA_ArbiterOutput_t_bnzj));
  }
  PrevArbiterOutput = FeatureArbiter_B.TbFA_ArbiterOutput_t_bnzj;

  /* DataTypeConversion: '<S13>/Data Type Conversion11' */
  FeatureArbiter_B.IeAP_e_AutoParkStatus =
    FeatureArbiter_B.MbFA_DriveAssistStatOut.IeAP_e_AutoParkStatus;

  /* RelationalOperator: '<S5>/Equal' incorporates:
   *  Constant: '<S11>/Constant'
   */
  FeatureArbiter_B.MeFA_b_FPAStatus = (FeatureArbiter_B.IeAP_e_AutoParkStatus ==
    TeAutoPark_e_AutoParkStatus_Active);

  /* DataStoreRead: '<S12>/Data Store Read8' */
  SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Get(&FeatureArbiter_B.MbFA_SMDAInternalOut);

  /* DataTypeConversion: '<S13>/Data Type Conversion10' */
  FeatureArbiter_B.MeFA_b_RPAStatus = (((int32_T)
    FeatureArbiter_B.MbFA_SMDAInternalOut.MeAP_b_ResetKM) != 0);

  /* RelationalOperator: '<S5>/Relational Operator2' incorporates:
   *  Constant: '<S5>/Constant5'
   */
  FeatureArbiter_B.LogicalOperator_lhui = (FeatureArbiter_B.MeFA_b_RPAStatus !=
    false);

  /* Logic: '<S5>/Logical Operator' */
  FeatureArbiter_B.LogicalOperator_lhui =
    ((FeatureArbiter_B.LogicalOperator_lhui) ||
     (FeatureArbiter_B.MeFA_b_FPAStatus));

  /* DataStoreRead: '<S12>/Data Store Read9' */
  SigMgr_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t_Get(&FeatureArbiter_B.FOD_Outputs_Arbitration);

  /* Switch: '<S5>/Switch5' */
  if (!FeatureArbiter_B.LogicalOperator_lhui) {
    /* DataTypeConversion: '<S13>/Data Type Conversion9' */
    FeatureArbiter_B.IeFOD_b_ResetKM = (boolean_T)
      FeatureArbiter_B.FOD_Outputs_Arbitration.IeFOD_b_ResetKM;

    /* RelationalOperator: '<S5>/Relational Operator3' incorporates:
     *  Constant: '<S5>/Constant4'
     */
    FeatureArbiter_B.RelationalOperator3 = (FeatureArbiter_B.IeFOD_b_ResetKM !=
      false);

    /* Switch: '<S5>/Switch6' incorporates:
     *  Constant: '<S5>/Constant6'
     */
    if (FeatureArbiter_B.RelationalOperator3) {
      FeatureArbiter_B.Switch6 = FeatureArbiter_B.IeFOD_b_ResetKM;
    } else {
      FeatureArbiter_B.Switch6 = false;
    }

    /* End of Switch: '<S5>/Switch6' */
    FeatureArbiter_B.MeFA_b_RPAStatus = FeatureArbiter_B.Switch6;
  }

  /* End of Switch: '<S5>/Switch5' */

  /* BusCreator: '<S3>/Bus Creator2' */
  FeatureArbiter_B.BusCreator2.MeFA_b_ResetKM =
    FeatureArbiter_B.MeFA_b_RPAStatus;

  /* DataStoreWrite: '<S3>/Data Store Write1' */
  static TbFA_ResetKM_t PrevResetKM;
  if(0 != memcmp(&FeatureArbiter_B.BusCreator2, &PrevResetKM, sizeof(PrevResetKM)))
  {
    SigMgr_PpTbFAResetKM_TbFA_ResetKM_t_Put(&FeatureArbiter_B.BusCreator2);
  }
  PrevResetKM = FeatureArbiter_B.BusCreator2;

  /* DataStoreRead: '<S12>/Data Store Read7' */
  SigMgr_Data_TbAP_USSStateOut_t_Get(&FeatureArbiter_B.MbFA_USSFiringModeOut);
  
  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  FeatureArbiter_B.IeFA_e_USSFiringMode =
    FeatureArbiter_B.MbFA_USSFiringModeOut.IeAP_e_USSFiringMode;

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  FeatureArbiter_B.MeFA_b_FPAStatus = (FeatureArbiter_B.IeFA_e_USSFiringMode !=
    ((uint8_T)0U));

  /* Switch: '<S6>/Switch3' */
  if (!FeatureArbiter_B.MeFA_b_FPAStatus) {
    /* DataTypeConversion: '<S13>/Data Type Conversion8' */
    FeatureArbiter_B.MeFOD_e_USSFiringMode =
      FeatureArbiter_B.FOD_Outputs_Arbitration.MeFOD_e_USSFiringMode;

    /* RelationalOperator: '<S6>/Relational Operator1' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    FeatureArbiter_B.RelationalOperator1 =
      (FeatureArbiter_B.MeFOD_e_USSFiringMode != ((uint8_T)0U));

    /* Switch: '<S6>/Switch4' incorporates:
     *  Constant: '<S6>/Constant3'
     */
    if (FeatureArbiter_B.RelationalOperator1) {
      FeatureArbiter_B.Switch4 = FeatureArbiter_B.MeFOD_e_USSFiringMode;
    } else {
      FeatureArbiter_B.Switch4 = ((uint8_T)0U);
    }

    /* End of Switch: '<S6>/Switch4' */
    FeatureArbiter_B.IeFA_e_USSFiringMode = FeatureArbiter_B.Switch4;
  }

  /* End of Switch: '<S6>/Switch3' */

  /* BusCreator: '<S3>/Bus Creator' */
  FeatureArbiter_B.BusCreator.IeFA_e_USSFiringMode =
    FeatureArbiter_B.IeFA_e_USSFiringMode;

  /* DataStoreWrite: '<S3>/Data Store Write2' */
  static TbFA_USSStateOutput_t PrevUSSStateOutput;
  if(0 != memcmp(&FeatureArbiter_B.BusCreator, &PrevUSSStateOutput, sizeof(PrevUSSStateOutput)))
  {
    SigMgr_Data_TbFA_USSStateOutput_t_Put(&FeatureArbiter_B.BusCreator);
  }
  PrevUSSStateOutput = FeatureArbiter_B.BusCreator;
  SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Get(&(FeatureArbiter_B.MbFA_SMPAInternalOut));

  /* DataTypeConversion: '<S13>/Data Type Conversion7' */
  FeatureArbiter_B.MeFA_b_FPAStatus = (((int32_T)
    FeatureArbiter_B.MbFA_SMPAInternalOut.MeAP_b_FPAStatus) != 0);

  /* DataTypeConversion: '<S13>/Data Type Conversion6' */
  FeatureArbiter_B.MeFA_b_RPAStatus = (((int32_T)
    FeatureArbiter_B.MbFA_SMPAInternalOut.MeAP_b_RPAStatus) != 0);

  /* Logic: '<S4>/Logical Operator' */
  FeatureArbiter_B.LogicalOperator = ((FeatureArbiter_B.MeFA_b_FPAStatus) ||
    (FeatureArbiter_B.MeFA_b_RPAStatus));
}

/* Model initialize function */
extern "C" void FeatureArbiter_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &FeatureArbiter_B), 0,
                sizeof(B_FeatureArbiter_T));

  {
    FeatureArbiter_B.IeFA_e_PamVol = TeFA_e_PamVol_None;
    FeatureArbiter_B.IeFA_e_PamChimeTyp = TeFA_e_PamChimeTyp_None;
    FeatureArbiter_B.IeFA_e_PamChimeRepRateSts =
      TeFA_e_PamChimeRepRateSts_Continuous_0_Hz;
    FeatureArbiter_B.IeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Off;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
