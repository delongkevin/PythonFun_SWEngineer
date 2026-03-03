/// --------------------------------------------------------------------------
/// @file DLDAlgo.cpp
/// @brief Contains DLD algo main
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
/// --------------------------------------------------------------------------

#include "../inc/DLDAlgo.h"
#include "../common/DLDDef.h"

namespace dld 
{
DLDAlgo::DLDAlgo() 
: m_filterOcc{
    {0.3f, 0.2f, 0.5f}, 
    {0.3f, 0.2f, 0.5f}, 
    {0.3f, 0.2f, 0.5f}, 
    {0.3f, 0.2f, 0.5f}
#if ENABLE_DLD_CHMSL_CAMERA
    ,{0.3f, 0.2f, 0.5f}
#endif
  },
  m_filterLum{
    {0.3f, 0.2f, 0.5f}, 
    {0.3f, 0.2f, 0.5f}, 
    {0.3f, 0.2f, 0.5f}, 
    {0.3f, 0.2f, 0.5f}
#if ENABLE_DLD_CHMSL_CAMERA
    ,{0.3f, 0.2f, 0.5f}
#endif
  }
{
#if ENABLE_DLD_DEBUG_DUMP
  ut_fp_dump = fopen( "/ti_sd/dld/DLDOutput.csv", "w+" );
  fprintf(ut_fp_dump, "CamId, Status, O1, O2, O3, O4, O5, O6, O7, O8, O9, Occ%, OccState, L1, L2, L3, L4, L5, L6, L7, L8, L9, LL%, LLState\n");
#endif
}

DLDAlgo::~DLDAlgo() {
#if ENABLE_DLD_DEBUG_DUMP
  fclose(ut_fp_dump);
#endif
}
	/*
	*	Name: init
	*	Remarks: DD-ID: {8FB70F1E-DCB3-4e5f-8209-023B11A416BD}
	*	Remarks: DD-ID: {9ACF2B7E-D8EA-46d1-9AE2-2816ABA8FFCF}
	*	Remarks: DD-ID: {D9589188-403E-4c56-9728-740765C1A843}
	*/
bool_t DLDAlgo::init() {
  /* DLD DL init */
  vx_status v_status_b = tidlAppInit();
  DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] Algo::app_tidl_DLD status=%d\n", v_status_b);
  return (VX_SUCCESS == v_status_b) ? true : false;
}

	/*
	*	Name: deinit
	*	Remarks: DD-ID: {1B1C8B4F-4DBB-43e7-9CC2-0C90F4CAF0E1}
	*	Remarks: DD-ID: {B7128575-8B9A-4f06-9D7F-67B421E3D0C4}
	*	Remarks: DD-ID: {7D50E8DC-6587-4e12-B535-AC0F7E55A08B}
	*/
#if 0
void DLDAlgo::deinit() {
  DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] Algo::deinit()\n");
  app_delete_graph_DLD(&m_TIObj);
  app_deinit_DLD(&m_TIObj);
  m_isInitialised = false;
}
#endif
	/*
	*	Name: ProcessDNN
	*	Remarks: DD-ID: {032438C4-3F40-4cc2-8893-5858441D555D}
	*	Remarks: DD-ID: {7427B2F7-879A-471f-AEBC-07B7AAE04430}
	*	Remarks: DD-ID: {B4EA7409-63AD-428a-9DED-238D692DF7A7}
	*/
DLDCamStatus_t DLDAlgo::ProcessDNN(DLD_Camera_ID camId, uint8_t* inputImgColor_pu8) {
  APP_ASSERT(inputImgColor_pu8 != NULL);

  // Run DNN model on C7x for RGB image
  vx_status v_status_b = app_run_graph_for_one_frame_sequential_DLD(&m_TIObj, inputImgColor_pu8);

  // Output dumping functionality
  DNN_DLD_out dnnOutput;
  memset(&dnnOutput, 0, sizeof(DNN_DLD_out));
  writeOutput_DLD(&m_TIObj, &dnnOutput);

  DLDCamStatus_t camOutput = processResults(camId, dnnOutput);
  return camOutput;
}

	/*
	*	Name: processResults
	*	Remarks: DD-ID: {A3C018B0-8428-4003-9ECA-7A5D1E69C4C1}
	*	Remarks: DD-ID: {49F24DD9-85E4-4a72-BA69-00DB85A92F0E}
	*	Remarks: DD-ID: {3D66E863-1CDF-49d3-A4B6-48DC5BFEB7ED}
	*/
	DLDCamStatus_t DLDAlgo::processResults(DLD_Camera_ID camId, DNN_DLD_out dnnOutput)
	{
		bool_t occlusionCond = false;
		bool_t lowlightCond = false;
		bool_t backlightCond = false;

  /* Post process OCCLUSION */
  float32_t unoccludedBinProb = 0.0f;
  float32_t occludedBinProb = 0.0f;
  {
#ifdef DLD_GRID_ALGO
  for(uint8_t i = 0; i < DLD_OUTPUT_OCC_WIDTH; i++) {
    occludedBinProb += static_cast<float32_t>(dnnOutput.v_occlusionProb[i]);
  }
  /* 
   * Each grid is evaluated from 0 - 100 in steps fo 25
   * per_dict = {0: 0, 1: 25, 2: 50, 3: 75, 4: 100}
   * occlusion_grid.append(per_dict[v_occlusionProb[i]])
   * occlusion_per = np.mean(occlusion_grid)
   * 
   * As optimization, (v_occlusionProb * 25 / 100) => (v_occlusionProb / 4)
   */
  occludedBinProb = (occludedBinProb / (4.0f * static_cast<float32_t>(DLD_OUTPUT_OCC_WIDTH)));
  unoccludedBinProb = 1.0f - occludedBinProb;
#else
    softmax(dnnOutput.v_occlusionProb, DLD_OUTPUT_OCC_WIDTH);
    
    for(uint8_t i = 0; i < DLD_OUTPUT_OCC_WIDTH; i++) {
      unoccludedBinProb += (i < m_occMedianPos) ? static_cast<float32_t>(dnnOutput.v_occlusionProb[i]) : 0.0f;
      occludedBinProb += (i >= m_occMedianPos) ? static_cast<float32_t>(dnnOutput.v_occlusionProb[i]) : 0.0f;
    }
#endif

#if ENABLE_DLD_DEBUG_PRINT
    DLD_DEBUG_PRINT(DLD_TRACE_MID, "[DLD] Algo: ProcessDNN Occlusion < ");
    for(uint8_t i = 0u ; i < DLD_OUTPUT_OCC_WIDTH; i++) {
      DLD_DEBUG_PRINT(DLD_TRACE_MID, "%f, ", dnnOutput.v_occlusionProb[i]);
    }
    DLD_DEBUG_PRINT(DLD_TRACE_MID, " >\n");
#endif
    if (m_smootheningOutput == 1) {
      /* Occlusion condition */
      if (!m_filterOcc[camId].is_filter_ready()) {
        m_filterOcc[camId].gather_initial_measurements(occludedBinProb);
        if (m_filterOcc[camId].is_filter_ready()) {
          occludedBinProb = m_filterOcc[camId].kalman_process();
          unoccludedBinProb = 1.0f - occludedBinProb;
        }
      }
      else {
        m_filterOcc[camId].update_measurements_array(occludedBinProb);
        occludedBinProb = m_filterOcc[camId].kalman_process();
        unoccludedBinProb = 1.0f - occludedBinProb;
      }
    }

    occlusionCond = (occludedBinProb >= m_occConfidenceThreshold) ? true : false;
  }

  /* Post process LUMINANCE */
  float32_t highLumBinProb = 0.0f;
  float32_t lowLumBinProb = 0.0f;
  {
#ifdef DLD_GRID_ALGO
  /* 
   * Each grid is evaluated from 0 - 100 in steps fo 25
   * per_dict = {0: 0, 1: 25, 2: 50, 3: 75, 4: 100}
   * lowlight_ignore = [0, 1, 2, 7, 8]
   * if i not in lowlight_ignore:
   *   lowlight_grid.append(per_dict[v_luminanceProb[i]])
   * lowlight_per = sum(lowlight_grid) / DLD_OUTPUT_LUM_WIDTH
   * 
   * As optimization, (v_luminanceProb * 25 / 100) => (v_luminanceProb / 4)
   */
                                                            /*   0,     1,     2,    3,    4,    5,    6,     7,     8*/
  static const bool_t llGridSelection[DLD_OUTPUT_LUM_WIDTH] = {false, false, false, true, true, true, true, false, false};
  for(uint8_t i = 0u ; i < DLD_OUTPUT_LUM_WIDTH; i++) {
    if(llGridSelection[i]) {
      lowLumBinProb += static_cast<float32_t>(dnnOutput.v_luminanceProb[i]);
    }
  }
  lowLumBinProb = lowLumBinProb / (4.0f * static_cast<float32_t>(DLD_OUTPUT_LUM_WIDTH));
  highLumBinProb = 1.0f - lowLumBinProb;
#else
    softmax(dnnOutput.v_luminanceProb, DLD_OUTPUT_LUM_WIDTH);
    highLumBinProb = dnnOutput.v_luminanceProb[0];
    lowLumBinProb = dnnOutput.v_luminanceProb[1];
#endif
#if ENABLE_DLD_DEBUG_PRINT
    DLD_DEBUG_PRINT(DLD_TRACE_MID, "[DLD] Algo: ProcessDNN Luminance < ");
    for(uint8_t i = 0u ; i < DLD_OUTPUT_LUM_WIDTH; i++) {
      DLD_DEBUG_PRINT(DLD_TRACE_MID, "%f, ", dnnOutput.v_luminanceProb[i]);
    }
    DLD_DEBUG_PRINT(DLD_TRACE_MID, " >\n");
#endif
    if (m_smootheningOutput == 1) {
      /* Occlusion condition */
      if (!m_filterLum[camId].is_filter_ready()) {
        m_filterLum[camId].gather_initial_measurements(lowLumBinProb);
        if (m_filterLum[camId].is_filter_ready()) {
          lowLumBinProb = m_filterLum[camId].kalman_process();
          highLumBinProb = 1.0f - lowLumBinProb;
        }
      }
      else {
        m_filterLum[camId].update_measurements_array(lowLumBinProb);
        lowLumBinProb = m_filterLum[camId].kalman_process();
        highLumBinProb = 1.0f - lowLumBinProb;
      }
    }

    lowlightCond = (lowLumBinProb >= m_llConfidenceThreshold) ? true : false;
  }

  DLDCamSts_t camStatus = lowlightCond ? DLD_Low_Luminance : 
                                        (occlusionCond ? DLD_Blockage : 
                                                        (backlightCond ? DLD_BackLit : DLD_Normal));

  DLD_DEBUG_PRINT(DLD_TRACE_MID, "[DLD] Algo: processResults out < camId=%d, occProb=%f, occlusion=%d, llProb=%f, lowlight=%d, camStatus=%d >\n",
    camId, occludedBinProb, static_cast<uint8_t>(occlusionCond), lowLumBinProb, static_cast<uint8_t>(lowlightCond), static_cast<uint8_t>(camStatus));

  DLDCamStatus_t DLDCamStatus;
  DLDCamStatus.UnoccludedBinPerc = unoccludedBinProb;
  DLDCamStatus.OccludedBinPerc = occludedBinProb;
  DLDCamStatus.LowlightPerc = lowLumBinProb;
  DLDCamStatus.HighlightPerc = highLumBinProb;
  DLDCamStatus.OcclusionStatus = occlusionCond;
  DLDCamStatus.LowlightStatus = lowlightCond;
  DLDCamStatus.DLD_CamSts_e = camStatus;

#if ENABLE_DLD_DEBUG_DUMP
  // CamId, Status, O1, O2, O3, O4, O5, O6, O7, O8, O9, Occ%, OccState, L1, L2, L3, L4, L5, L6, L7, L8, L9, LL%, LLState
  fprintf(ut_fp_dump, "%d, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %s, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %s\n",
         (uint8_t)camId, (uint8_t)camStatus,
         dnnOutput.v_occlusionProb[0], dnnOutput.v_occlusionProb[1], dnnOutput.v_occlusionProb[2],
         dnnOutput.v_occlusionProb[3], dnnOutput.v_occlusionProb[4], dnnOutput.v_occlusionProb[5],
         dnnOutput.v_occlusionProb[6], dnnOutput.v_occlusionProb[7], dnnOutput.v_occlusionProb[8],
         occludedBinProb, (occlusionCond ? "Occlusion" : "Normal"),
         dnnOutput.v_luminanceProb[0], dnnOutput.v_luminanceProb[1], dnnOutput.v_luminanceProb[2],
         dnnOutput.v_luminanceProb[3], dnnOutput.v_luminanceProb[4], dnnOutput.v_luminanceProb[5],
         dnnOutput.v_luminanceProb[6], dnnOutput.v_luminanceProb[7], dnnOutput.v_luminanceProb[8],
         lowLumBinProb, (lowlightCond ? "Lowlight" : "Normal"));
#endif

  return DLDCamStatus;
}
  /*
	*	Name: tidlAppInit
	*	Remarks: DD-ID: {75212396-13AF-4094-A63A-5BE135C4B6E1}
	*	Remarks: DD-ID: {BC7E6339-AA0F-4886-8ED8-E9F5398C4D68}
	*	Remarks: DD-ID: {29346213-6284-4541-B310-BC0DCAE6C78B}
  */
vx_status DLDAlgo::tidlAppInit() {
  vx_status v_status_b = VX_SUCCESS;

  /* Config parameter reading */
  app_parse_cmd_line_args_DLD(&m_TIObj);
  DLD_DEBUG_PRINT(DLD_TRACE_MID, "[DLD] DLDAlgo: Parsed user params! \n");

  v_status_b = app_init_DLD(&m_TIObj);
  if(v_status_b == VX_SUCCESS) {
    DLD_DEBUG_PRINT(DLD_TRACE_MID, "[DLD] DLDAlgo: App Init Done!\n");

    v_status_b = app_create_graph_DLD(&m_TIObj);
    if(v_status_b == VX_SUCCESS) {
      DLD_DEBUG_PRINT(DLD_TRACE_MID, "[DLD] DLDAlgo: App Create Graph Done!\n");

      v_status_b = app_verify_graph_DLD(&m_TIObj);
      if(v_status_b == VX_SUCCESS) {
        DLD_DEBUG_PRINT(DLD_TRACE_MID, "[DLD] DLDAlgo: App Verify Graph Done!");
      }
      else {
        DLD_DEBUG_PRINT_ERROR("DLDAlgo: App Verify Graph Failed! v_status_b=%d", v_status_b);
      }
    }
    else {
      DLD_DEBUG_PRINT_ERROR("DLDAlgo: App Create Graph Failed! v_status_b=%d", v_status_b);
    }
  }
  else {
    DLD_DEBUG_PRINT_ERROR("DLDAlgo: App Init Failed! v_status_b=%d", v_status_b);
  }
  
  return v_status_b;
}
	/*
	*	Name: getInputPadSizes
	*	Remarks: DD-ID: {69205A49-7EA3-40d6-A5F8-DAF0A242AB70}
	*	Remarks: DD-ID: {BD0CC673-F002-415f-9853-492710C3E511}
	*	Remarks: DD-ID: {F886741E-B491-4d97-83F8-EA2FC2241EFA}
	*/
void DLDAlgo::getInputPadSizes(uint32_t &inPadL, uint32_t &inPadT, uint32_t &inPadR, uint32_t &inPadB) {
  sTIDL_IOBufDesc_t *ioBufDesc = &m_TIObj.ioBufDesc;
  inPadL = ioBufDesc->inPadL[0];
  inPadT = ioBufDesc->inPadT[0];
  inPadR = ioBufDesc->inPadR[0];
  inPadB = ioBufDesc->inPadB[0];
}

	/*
	*	Name: softmax
	*	Remarks: DD-ID: {9157BCA0-2D20-478b-92C0-B689137061D4}
	*	Remarks: DD-ID: {C7582BDF-AC80-47bd-9CFF-BE25EA7E4E89}
	*	Remarks: DD-ID: {3CE4514B-3340-41de-BCBC-D3ACF5ED6363}
	*/
void DLDAlgo::softmax(float32_t * scores, const uint32_t number_of_scores)
{
  float32_t m = -INFINITY;
  for (uint32_t i = 0; i < number_of_scores; ++i) {
    if (m < scores[i]) {
      m = scores[i];
    }
  }

  float32_t sum = 0.0f;
  for (uint32_t i = 0; i < number_of_scores; ++i) {
    sum += exp(scores[i] - m);
  }

  float32_t constant = m + log(sum);
  for (uint32_t i = 0; i < number_of_scores; ++i) {
    scores[i] = exp(scores[i] - constant);
  }
}

} // namespace dld
