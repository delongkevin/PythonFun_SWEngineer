#include "US_MgrHeightAlgoRNN.h"
#include "US_SysMgr_Global.h" /* Included from RNN.h <- US_ComInputBuffer_Global.h <- US_SysMgr_Global.h, but this makes it explicit */

#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_RNN)
                                  
/*
Normal Mode input
# "ROL_dist3", "ROL_w2", "ROL_h2", "ROL_dist2", "ROL_w1", "ROL_h1", "ROL_dist1",
# "RIL_dist3", "RIL_w2", "RIL_h2", "RIL_dist2", "RIL_w1", "RIL_h1", "RIL_dist1",
# "RIR_dist3", "RIR_w2", "RIR_h2", "RIR_dist2", "RIR_w1", "RIR_h1", "RIR_dist1",
# "ROR_dist3", "ROR_w2", "ROR_h2", "ROR_dist2", "ROR_w1", "ROR_h1", "ROR_dist1"
*/

/**********************************************************************************************************************
 * Name:  Rear_height_estimation_RNN 
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/  
static bool_t Rear_height_estimation_RNN(const US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS],
                                         const float32_t f_VehSpdkph,
                                         const float32_t f_AmbTemp)
{
  uint8_t u_colIdx;
  uint8_t u_rowIdx;
  uint8_t u_SnrIdx;
  float32_t f_x = 0.0f;
  float32_t f_reset[REAR_HIDDEN_SIZE_GRU];
  float32_t f_update_gate[REAR_HIDDEN_SIZE_GRU];
  float32_t f_combined[REAR_COMBINED_SIZE];
  float32_t f_new_gate[REAR_HIDDEN_SIZE_GRU];
  float32_t f_z2[REAR_HIDDEN_SIZE_GRU];
  float32_t f_z1[FORWARD_PASS_LAYER_SIZE];
  float32_t f_u[HEIGHT_ALGO_NUM_SENSORS][REAR_INPUT_LAYER_SIZE];
  float32_t f_u_concat[REAR_CONCAT_SIZE];
  float32_t f_tmp;
  float32_t f_out[HEIGHT_ALGO_NUM_CLASSES];
  bool_t b_isHigh;

  /*inner Input network*/
  for (u_SnrIdx = ZERO; u_SnrIdx < HEIGHT_ALGO_NUM_SENSORS; u_SnrIdx++)
  {
    for (u_rowIdx = ZERO; u_rowIdx < REAR_INPUT_LAYER_SIZE; u_rowIdx++)
    {
      f_x = 0.0f;
      if (( DNN_OUTER_RIGHT_ENTRY == u_SnrIdx) || (DNN_OUTER_LEFT_ENTRY == u_SnrIdx))
      {
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist3) * f_Rear_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][ZERO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].uWidth2) * f_Rear_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][ONE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight2) * f_Rear_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][TWO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist2) * f_Rear_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][THREE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].uWidth1) * f_Rear_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][FOUR];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight1) * f_Rear_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][FIVE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist1) * f_Rear_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][SIX];
        f_u[u_SnrIdx][u_rowIdx] = f_x + f_Rear_uss_dnn_outer_input_layer_bias_Normal[u_rowIdx];
      }
      else
      {
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist3) * f_Rear_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][ZERO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].uWidth2) * f_Rear_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][ONE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight2) * f_Rear_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][TWO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist2) * f_Rear_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][THREE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].uWidth1) * f_Rear_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][FOUR];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight1) * f_Rear_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][FIVE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist1) * f_Rear_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][SIX];
        f_u[u_SnrIdx][u_rowIdx] = f_x + f_Rear_uss_dnn_inner_input_layer_bias_Normal[u_rowIdx];
      }
      /*relu*/
      f_u[u_SnrIdx][u_rowIdx] = LEAKY_RELU(f_u[u_SnrIdx][u_rowIdx], f_ReluSlope);
    }
  }

  for (u_SnrIdx = ZERO; u_SnrIdx < HEIGHT_ALGO_NUM_SENSORS; u_SnrIdx++)
  {
    for (u_rowIdx = ZERO; u_rowIdx < HEIGHT_ALGO_NUM_SENSORS; u_rowIdx++)
    {
      f_x = 0.0f;
      for (u_colIdx = ZERO; u_colIdx < REAR_INPUT_LAYER_SIZE; u_colIdx++)
      {
        if ((DNN_OUTER_RIGHT_ENTRY == u_SnrIdx) || (DNN_OUTER_LEFT_ENTRY == u_SnrIdx))
        {
          f_x += f_u[u_SnrIdx][u_colIdx] * f_Rear_uss_dnn_outer_output_layer_weight_Normal[u_rowIdx][u_colIdx];
        }
        else
        {
          f_x += f_u[u_SnrIdx][u_colIdx] * f_Rear_uss_dnn_inner_output_layer_weight_Normal[u_rowIdx][u_colIdx];
        }
      }
      if ((DNN_OUTER_RIGHT_ENTRY == u_SnrIdx) || (DNN_OUTER_LEFT_ENTRY== u_SnrIdx))
      {
        f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)] = f_x + f_Rear_uss_dnn_outer_output_layer_bias_Normal[u_rowIdx];
      }
      else
      {
        f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)] = f_x + f_Rear_uss_dnn_inner_output_layer_bias_Normal[u_rowIdx];
      }
      /*relu*/
      f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)] = LEAKY_RELU((f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)]), f_ReluSlope);
    }
  }
  f_u_concat[SIXTEEN] = LEAKY_RELU(((LEAKY_RELU(((f_VehSpdkph * f_Rear_vel_dnn_input_layer_weight_Normal[ZERO]) +
                                            f_Rear_vel_dnn_input_layer_bias_Normal[ZERO]),
                                           f_ReluSlope) *
                                f_Rear_vel_dnn_output_layer_weight_Normal[ZERO]) +
                               (LEAKY_RELU(((f_VehSpdkph * f_Rear_vel_dnn_input_layer_weight_Normal[ONE]) +
                                            f_Rear_vel_dnn_input_layer_bias_Normal[ONE]),
                                           f_ReluSlope) *
                                f_Rear_vel_dnn_output_layer_weight_Normal[ONE]) +
                               f_Rear_vel_dnn_output_layer_bias_Normal),
                              f_ReluSlope);

  f_u_concat[SEVENTEEN] = LEAKY_RELU(((LEAKY_RELU(((f_AmbTemp * f_Rear_temp_dnn_input_layer_weight_Normal[ZERO]) +
                                            f_Rear_temp_dnn_input_layer_bias_Normal[ZERO]),
                                           f_ReluSlope) *
                                f_Rear_temp_dnn_output_layer_weight_Normal[ZERO]) +
                               (LEAKY_RELU(((f_AmbTemp * f_Rear_temp_dnn_input_layer_weight_Normal[ONE]) +
                                            f_Rear_temp_dnn_input_layer_bias_Normal[ONE]),
                                           f_ReluSlope) *
                                f_Rear_temp_dnn_output_layer_weight_Normal[ONE]) +
                               f_Rear_temp_dnn_output_layer_bias_Normal),
                              f_ReluSlope);

  /*Forward Pass
  dot matrix multiplication of weight and inputs*/
  for (u_rowIdx = ZERO; u_rowIdx < FORWARD_PASS_LAYER_SIZE; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < REAR_CONCAT_SIZE; u_colIdx++)
    {
      f_x += f_u_concat[u_colIdx] * f_Rear_input_layer_weight_Normal[u_rowIdx][u_colIdx];
    }
    f_z1[u_rowIdx] = f_x + f_Rear_input_layer_bias_Normal[u_rowIdx];
    /*relu*/
    f_z1[u_rowIdx] = LEAKY_RELU(f_z1[u_rowIdx], f_ReluSlope);
  }

  for (u_rowIdx = ZERO; u_rowIdx < REAR_INPUT_LAYER_SIZE; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FORWARD_PASS_LAYER_SIZE; u_colIdx++)
    {
      f_x += f_z1[u_colIdx] * f_Rear_hidden_layer_weight_Normal[u_rowIdx][u_colIdx];
    }
    f_combined[u_rowIdx] = f_x + f_Rear_hidden_layer_bias_Normal[u_rowIdx];
    /*relu*/
    f_combined[u_rowIdx] = LEAKY_RELU(f_combined[u_rowIdx], f_ReluSlope);
  }
  /*GRU cell*/
  for (u_rowIdx = REAR_INPUT_LAYER_SIZE; u_rowIdx < REAR_COMBINED_SIZE; u_rowIdx++)
  {
    f_combined[u_rowIdx] = f_rear_hidden_array[u_rowIdx - REAR_INPUT_LAYER_SIZE];
  }

  for (u_rowIdx = ZERO; u_rowIdx < REAR_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < REAR_COMBINED_SIZE; u_colIdx++)
    {
      f_x += (f_combined[u_colIdx] * f_Rear_reset_gate_weight_Normal[u_rowIdx][u_colIdx]);
    }
    f_x += f_Rear_reset_gate_bias_Normal[u_rowIdx];
    f_reset[u_rowIdx] = f_sigmoid(f_x);
  }

  for (u_rowIdx = ZERO; u_rowIdx < REAR_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < REAR_COMBINED_SIZE; u_colIdx++)
    {
      f_x += (f_combined[u_colIdx] * f_Rear_update_gate_weight_Normal[u_rowIdx][u_colIdx]);
    }
    f_x += f_Rear_update_gate_bias_Normal[u_rowIdx];
    f_update_gate[u_rowIdx] = f_sigmoid(f_x);
  }
  /*New combined*/
  for (u_colIdx = REAR_INPUT_LAYER_SIZE; u_colIdx < REAR_COMBINED_SIZE; u_colIdx++)
  {
    f_combined[u_colIdx] = f_reset[u_colIdx - REAR_INPUT_LAYER_SIZE] * f_rear_hidden_array[u_colIdx - REAR_INPUT_LAYER_SIZE];
  }

  /*new gate*/
  for (u_rowIdx = ZERO; u_rowIdx < REAR_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < REAR_COMBINED_SIZE; u_colIdx++)
    {
      f_x += f_combined[u_colIdx] * f_Rear_new_gate_weight_Normal[u_rowIdx][u_colIdx];
    }
    f_new_gate[u_rowIdx] = f_tanh(f_x + f_Rear_new_gate_bias_Normal[u_rowIdx]);
  }

  for (u_rowIdx = ZERO; u_rowIdx < REAR_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_rear_hidden_array[u_rowIdx] = ((1.0f - f_update_gate[u_rowIdx]) * f_rear_hidden_array[u_rowIdx]) + (f_update_gate[u_rowIdx] * f_new_gate[u_rowIdx]);
  }
  /*output layer*/
  for (u_rowIdx = ZERO; u_rowIdx < REAR_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < REAR_HIDDEN_SIZE_GRU; u_colIdx++)
    {
      f_tmp = (f_rear_hidden_array[u_colIdx] * f_Rear_output_layer_weight_Normal[u_rowIdx][u_colIdx]);
      f_x += f_tmp;
    }
    f_z2[u_rowIdx] = f_x + f_Rear_output_layer_bias_Normal[u_rowIdx];
    /*relu*/
    f_z2[u_rowIdx] = LEAKY_RELU(f_z2[u_rowIdx], f_ReluSlope);
  }

  /*class output*/
  for (u_rowIdx = ZERO; u_rowIdx < HEIGHT_ALGO_NUM_CLASSES; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < REAR_HIDDEN_SIZE_GRU; u_colIdx++)
    {
      f_x += f_z2[u_colIdx] * f_Rear_final_layer_weight_Normal[u_rowIdx][u_colIdx];
    }
    f_out[u_rowIdx] = f_x + f_Rear_final_layer_bias_Normal[u_rowIdx];
  }
  f_softMax(f_out, &f_classProb[US_D_PHYS_GRP_REAR][ZERO], HEIGHT_ALGO_NUM_CLASSES);
  g_HeightClass[US_D_PHYS_GRP_REAR] =  u_argMax(f_out, HEIGHT_ALGO_NUM_CLASSES);
  if ((g_HeightClass[US_D_PHYS_GRP_REAR] == HEIGHT_ALGO_WALL_CLASS) || ((f_classProb[US_D_PHYS_GRP_REAR][(uint8_t)HEIGHT_ALGO_POLE_CLASS] + f_classProb[US_D_PHYS_GRP_REAR][(uint8_t) HEIGHT_ALGO_VEHICLE_CLASS]) > f_MIN_CLASS_PROB))
  {
    b_isHigh = (bool_t)ME_TRUE;
  }
  else
  {
    b_isHigh = (bool_t)ME_FALSE;
  }

  return b_isHigh;
}

/*
Noise mode input:
# "ROL_h3", "ROL_h2", "ROL_dist2", "ROL_h1", "ROL_dist1", "ROL_conf1",
# "RIL_h3", "RIL_h2", "RIL_dist2", "RIL_h1", "RIL_dist1", "RIL_conf1",
# "RIR_h3", "RIR_h2", "RIR_dist2", "RIR_h1", "RIR_dist1", "RIR_conf1",
# "ROR_h3", "ROR_h2", "ROR_dist2", "ROR_h1", "ROR_dist1", "ROR_conf1",*/

/**********************************************************************************************************************
 * Name:  Rear_height_estimation_RNN_noise
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/  
static bool_t Rear_height_estimation_RNN_noise(const US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS],
                                               const float32_t f_VehSpdkph,
                                               const float32_t f_AmbTemp)
{
  uint8_t u_colIdx;
  uint8_t u_rowIdx;
  uint8_t u_SnrIdx;
  float32_t f_x = 0.0f;
  float32_t f_reset[REAR_HIDDEN_SIZE_GRU];
  float32_t f_update_gate[REAR_HIDDEN_SIZE_GRU];
  float32_t f_combined[REAR_COMBINED_SIZE];
  float32_t f_new_gate[REAR_HIDDEN_SIZE_GRU];
  float32_t f_z2[REAR_HIDDEN_SIZE_GRU];
  float32_t f_z1[FORWARD_PASS_LAYER_SIZE];
  float32_t f_u[HEIGHT_ALGO_NUM_SENSORS][REAR_INPUT_LAYER_SIZE_NOISE];
  float32_t f_u_concat[REAR_CONCAT_SIZE];
  float32_t f_tmp;
  bool_t b_isHigh;
  float32_t f_out[HEIGHT_ALGO_NUM_CLASSES];
  float32_t f_MinClassProbvar = 0.75f;

  /*inner Input network*/
  for (u_SnrIdx = ZERO; u_SnrIdx < HEIGHT_ALGO_NUM_SENSORS; u_SnrIdx++)
  {
    for (u_rowIdx = ZERO; u_rowIdx < REAR_INPUT_LAYER_SIZE_NOISE; u_rowIdx++)
    {
      f_x = 0.0f;
      if ((DNN_OUTER_RIGHT_ENTRY == u_SnrIdx) || (DNN_OUTER_LEFT_ENTRY == u_SnrIdx))
      {
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight3) * f_Rear_uss_dnn_outer_input_layer_weight_Noise[u_rowIdx][ZERO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight2) * f_Rear_uss_dnn_outer_input_layer_weight_Noise[u_rowIdx][ONE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist2) * f_Rear_uss_dnn_outer_input_layer_weight_Noise[u_rowIdx][TWO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight1) * f_Rear_uss_dnn_outer_input_layer_weight_Noise[u_rowIdx][THREE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist1) * f_Rear_uss_dnn_outer_input_layer_weight_Noise[u_rowIdx][FOUR];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].uConf1) * f_Rear_uss_dnn_outer_input_layer_weight_Noise[u_rowIdx][FIVE];
        f_u[u_SnrIdx][u_rowIdx] = f_x + f_Rear_uss_dnn_outer_input_layer_bias_Noise[u_rowIdx];
      }
      else
      {
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight3) * f_Rear_uss_dnn_inner_input_layer_weight_Noise[u_rowIdx][ZERO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight2) * f_Rear_uss_dnn_inner_input_layer_weight_Noise[u_rowIdx][ONE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist2) * f_Rear_uss_dnn_inner_input_layer_weight_Noise[u_rowIdx][TWO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight1) * f_Rear_uss_dnn_inner_input_layer_weight_Noise[u_rowIdx][THREE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist1) * f_Rear_uss_dnn_inner_input_layer_weight_Noise[u_rowIdx][FOUR];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].uConf1) * f_Rear_uss_dnn_inner_input_layer_weight_Noise[u_rowIdx][FIVE];
        f_u[u_SnrIdx][u_rowIdx] = f_x + f_Rear_uss_dnn_inner_input_layer_bias_Noise[u_rowIdx];
      }
      /*relu*/
      f_u[u_SnrIdx][u_rowIdx] = LEAKY_RELU(f_u[u_SnrIdx][u_rowIdx], f_ReluSlope);
    }
  }

  for (u_SnrIdx = ZERO; u_SnrIdx < HEIGHT_ALGO_NUM_SENSORS; u_SnrIdx++)
  {
    for (u_rowIdx = ZERO; u_rowIdx < HEIGHT_ALGO_NUM_SENSORS; u_rowIdx++)
    {
      f_x = 0.0f;
      for (u_colIdx = ZERO; u_colIdx < REAR_INPUT_LAYER_SIZE_NOISE; u_colIdx++)
      {
        if ((DNN_OUTER_RIGHT_ENTRY == u_SnrIdx) || (DNN_OUTER_LEFT_ENTRY == u_SnrIdx))
        {
          f_x += f_u[u_SnrIdx][u_colIdx] * f_Rear_uss_dnn_outer_output_layer_weight_Noise[u_rowIdx][u_colIdx];
        }
        else
        {
          f_x += f_u[u_SnrIdx][u_colIdx] * f_Rear_uss_dnn_inner_output_layer_weight_Noise[u_rowIdx][u_colIdx];
        }
      }
      if ((DNN_OUTER_RIGHT_ENTRY == u_SnrIdx) || (DNN_OUTER_LEFT_ENTRY == u_SnrIdx))
      {
        f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)] = f_x + f_Rear_uss_dnn_outer_output_layer_bias_Noise[u_rowIdx];
      }
      else
      {
        f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)] = f_x + f_Rear_uss_dnn_inner_output_layer_bias_Noise[u_rowIdx];
      }
      /*relu*/
      f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)] = LEAKY_RELU((f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)]), f_ReluSlope);
    }
  }
  f_u_concat[SIXTEEN] = LEAKY_RELU(((LEAKY_RELU(((f_VehSpdkph * f_Rear_vel_dnn_input_layer_weight_Noise[ZERO]) +
                                            f_Rear_vel_dnn_input_layer_bias_Noise[ZERO]),
                                           f_ReluSlope) *
                                f_Rear_vel_dnn_output_layer_weight_Noise[ZERO]) +
                               (LEAKY_RELU(((f_VehSpdkph * f_Rear_vel_dnn_input_layer_weight_Noise[ONE]) +
                                            f_Rear_vel_dnn_input_layer_bias_Noise[ONE]),
                                           f_ReluSlope) *
                                f_Rear_vel_dnn_output_layer_weight_Noise[ONE]) +
                               f_Rear_vel_dnn_output_layer_bias_Noise),
                              f_ReluSlope);

  f_u_concat[SEVENTEEN] = LEAKY_RELU(((LEAKY_RELU(((f_AmbTemp * f_Rear_temp_dnn_input_layer_weight_Noise[ZERO]) +
                                            f_Rear_temp_dnn_input_layer_bias_Noise[ZERO]),
                                           f_ReluSlope) *
                                f_Rear_temp_dnn_output_layer_weight_Noise[ZERO]) +
                               (LEAKY_RELU(((f_AmbTemp * f_Rear_temp_dnn_input_layer_weight_Noise[ONE]) +
                                            f_Rear_temp_dnn_input_layer_bias_Noise[ONE]),
                                           f_ReluSlope) *
                                f_Rear_temp_dnn_output_layer_weight_Noise[ONE]) +
                               f_Rear_temp_dnn_output_layer_bias_Noise),
                              f_ReluSlope);
  /*Forward Pass
  dot matrix multiplication of weight and inputs*/
  for (u_rowIdx = ZERO; u_rowIdx < FORWARD_PASS_LAYER_SIZE; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < REAR_CONCAT_SIZE; u_colIdx++)
    {
      f_x += f_u_concat[u_colIdx] * f_Rear_input_layer_weight_Noise[u_rowIdx][u_colIdx];
    }
    f_z1[u_rowIdx] = f_x + f_Rear_input_layer_bias_Noise[u_rowIdx];
    /*relu*/
    f_z1[u_rowIdx] = LEAKY_RELU(f_z1[u_rowIdx], f_ReluSlope);
  }

  for (u_rowIdx = ZERO; u_rowIdx < REAR_INPUT_LAYER_SIZE; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FORWARD_PASS_LAYER_SIZE; u_colIdx++)
    {
      f_x += f_z1[u_colIdx] * f_Rear_hidden_layer_weight_Noise[u_rowIdx][(u_colIdx)];
    }
    f_combined[u_rowIdx] = f_x + f_Rear_hidden_layer_bias_Noise[u_rowIdx];
    /*relu*/
    f_combined[u_rowIdx] = LEAKY_RELU(f_combined[u_rowIdx], f_ReluSlope);
  }

  /*GRU cell*/
  for (u_rowIdx = REAR_INPUT_LAYER_SIZE; u_rowIdx < REAR_COMBINED_SIZE; u_rowIdx++)
  {
    f_combined[u_rowIdx] = f_rear_hidden_array_noise[u_rowIdx - REAR_INPUT_LAYER_SIZE];
  }

  for (u_rowIdx = ZERO; u_rowIdx < REAR_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < REAR_COMBINED_SIZE; u_colIdx++)
    {
      f_x += (f_combined[u_colIdx] * f_Rear_reset_gate_weight_Noise[u_rowIdx][u_colIdx]);
    }
    f_x += f_Rear_reset_gate_bias_Noise[u_rowIdx];
    f_reset[u_rowIdx] = f_sigmoid(f_x);
  }

  for (u_rowIdx = ZERO; u_rowIdx < REAR_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < REAR_COMBINED_SIZE; u_colIdx++)
    {
      f_x += (f_combined[u_colIdx] * f_Rear_update_gate_weight_Noise[u_rowIdx][u_colIdx]);
    }
    f_x += f_Rear_update_gate_bias_Noise[u_rowIdx];
    f_update_gate[u_rowIdx] = f_sigmoid(f_x);
  }
  /*New combined*/
  for (u_colIdx = REAR_INPUT_LAYER_SIZE; u_colIdx < REAR_COMBINED_SIZE; u_colIdx++)
  {
    f_combined[u_colIdx] = f_reset[u_colIdx - REAR_INPUT_LAYER_SIZE] * f_rear_hidden_array_noise[u_colIdx - REAR_INPUT_LAYER_SIZE];
  }

  /*new gate*/
  for (u_rowIdx = ZERO; u_rowIdx < REAR_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < REAR_COMBINED_SIZE; u_colIdx++)
    {
      f_x += f_combined[u_colIdx] * f_Rear_new_gate_weight_Noise[u_rowIdx][u_colIdx];
    }
    f_new_gate[u_rowIdx] = f_tanh(f_x + f_Rear_new_gate_bias_Noise[u_rowIdx]);
  }

  for (u_rowIdx = ZERO; u_rowIdx < REAR_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_rear_hidden_array_noise[u_rowIdx] = ((1.0f - f_update_gate[u_rowIdx]) * f_rear_hidden_array_noise[u_rowIdx]) + (f_update_gate[u_rowIdx] * f_new_gate[u_rowIdx]);
  }
  /*output layer*/

  for (u_rowIdx = ZERO; u_rowIdx < REAR_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < REAR_HIDDEN_SIZE_GRU; u_colIdx++)
    {
      f_tmp = (f_rear_hidden_array_noise[u_colIdx] * f_Rear_output_layer_weight_Noise[u_rowIdx][u_colIdx]);
      f_x += f_tmp;
    }
    f_z2[u_rowIdx] = f_x + f_Rear_output_layer_bias_Noise[u_rowIdx];
    /*relu*/
    f_z2[u_rowIdx] = LEAKY_RELU(f_z2[u_rowIdx], f_ReluSlope);
  }

  for (u_rowIdx = ZERO; u_rowIdx < (uint8_t) HEIGHT_ALGO_NUM_CLASSES; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < REAR_HIDDEN_SIZE_GRU; u_colIdx++)
    {
      f_x += f_z2[u_colIdx] * f_Rear_final_layer_weight_Noise[u_rowIdx][u_colIdx];
    }
    f_out[u_rowIdx] = f_x + f_Rear_final_layer_bias_Noise[u_rowIdx];
  }
  f_softMax(f_out, &f_classProb[US_D_PHYS_GRP_REAR][ZERO], HEIGHT_ALGO_NUM_CLASSES);
  g_HeightClass[US_D_PHYS_GRP_REAR] =  u_argMax(f_out, HEIGHT_ALGO_NUM_CLASSES);
  if(f_VehSpdkph < f_VEH_SPD_THRESHOLD)
  {
    f_MinClassProbvar = 0.95f;
  }
  else{/*do nothing*/}

  if ((g_HeightClass[US_D_PHYS_GRP_REAR] == HEIGHT_ALGO_WALL_CLASS) || ((f_classProb[US_D_PHYS_GRP_REAR][(uint8_t)HEIGHT_ALGO_POLE_CLASS] + f_classProb[US_D_PHYS_GRP_REAR][(uint8_t) HEIGHT_ALGO_VEHICLE_CLASS]) > f_MinClassProbvar))
  {
    b_isHigh = (bool_t)ME_TRUE;
  }
  else
  {
    b_isHigh = (bool_t)ME_FALSE;
  }
  return b_isHigh;
}
/*
Normal Mode input
# "FOL_dist3", "FOL_w2", "FOL_h2", "FOL_dist2", "FOL_w1", "FOL_h1", "FOL_dist1",
# "FIL_dist3", "FIL_w2", "FIL_h2", "FIL_dist2", "FIL_w1", "FIL_h1", "FIL_dist1",
# "FIR_dist3", "FIR_w2", "FIR_h2", "FIR_dist2", "FIR_w1", "FIR_h1", "FIR_dist1",
# "FOR_dist3", "FOR_w2", "FOR_h2", "FOR_dist2", "FOR_w1", "FOR_h1", "FOR_dist1"
*/
/**********************************************************************************************************************
 * Name:  Front_height_estimation_RNN 
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/  
static bool_t Front_height_estimation_RNN(const US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS],
                                          const float32_t f_VehSpdkph,
                                          const float32_t f_AmbTemp,
                                          const uint8_t u_veh_var)
{
  uint8_t u_colIdx;
  uint8_t u_rowIdx;
  uint8_t u_SnrIdx;
  float32_t f_x = 0.0f;
  float32_t f_reset[FRONT_HIDDEN_SIZE_GRU];
  float32_t f_update_gate[FRONT_HIDDEN_SIZE_GRU];
  float32_t f_combined[FRONT_COMBINED_SIZE];
  float32_t f_new_gate[FRONT_HIDDEN_SIZE_GRU];
  float32_t f_z2[FRONT_HIDDEN_SIZE_GRU];
  float32_t f_z1[FORWARD_PASS_LAYER_SIZE];
  float32_t f_u[HEIGHT_ALGO_NUM_SENSORS][FRONT_INPUT_LAYER_SIZE];
  float32_t f_u_concat[FRONT_CONCAT_SIZE];
  float32_t f_out[HEIGHT_ALGO_NUM_CLASSES];
  float32_t f_tmp;
  bool_t b_isHigh;
  /* Variants: Laramie Rebel Tungsten */
  static const float32_t f_vehicle_var_FrontNormal[THREE][FOUR] = { {4.5658f, -0.003761f, -0.011009f, -0.0066776f},
                                                    {11.5244f, -0.0380f, -0.0505f, -0.0162f},
                                                    {0.4764f, 2.6031f, 1.2330f, -0.0032f}};            

  /*inner Input network*/
  for (u_SnrIdx = ZERO; u_SnrIdx < HEIGHT_ALGO_NUM_SENSORS; u_SnrIdx++)
  {
    for (u_rowIdx = ZERO; u_rowIdx < FRONT_INPUT_LAYER_SIZE; u_rowIdx++)
    {
      f_x = 0.0f;
      if ((DNN_OUTER_RIGHT_ENTRY == u_SnrIdx) || (DNN_OUTER_LEFT_ENTRY == u_SnrIdx))
      {
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist3) * f_Front_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][ZERO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].uWidth2) * f_Front_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][ONE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight2) * f_Front_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][TWO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist2) * f_Front_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][THREE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].uWidth1) * f_Front_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][FOUR];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight1) * f_Front_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][FIVE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist1) * f_Front_uss_dnn_outer_input_layer_weight_Normal[u_rowIdx][SIX];
        f_u[u_SnrIdx][u_rowIdx] = f_x + f_Front_uss_dnn_outer_input_layer_bias_Normal[u_rowIdx];
      }
      else
      {
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist3) * f_Front_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][ZERO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].uWidth2) * f_Front_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][ONE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight2) * f_Front_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][TWO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist2) * f_Front_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][THREE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].uWidth1) * f_Front_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][FOUR];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight1) * f_Front_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][FIVE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist1) * f_Front_uss_dnn_inner_input_layer_weight_Normal[u_rowIdx][SIX];
        f_u[u_SnrIdx][u_rowIdx] = f_x + f_Front_uss_dnn_inner_input_layer_bias_Normal[u_rowIdx];
      }
      /*relu*/
      f_u[u_SnrIdx][u_rowIdx] = LEAKY_RELU((f_u[u_SnrIdx][u_rowIdx]), f_ReluSlope);
    }
  }

  for (u_SnrIdx = ZERO; u_SnrIdx < HEIGHT_ALGO_NUM_SENSORS; u_SnrIdx++)
  {
    for (u_rowIdx = ZERO; u_rowIdx < HEIGHT_ALGO_NUM_SENSORS; u_rowIdx++)
    {
      f_x = 0.0f;
      for (u_colIdx = ZERO; u_colIdx < FRONT_INPUT_LAYER_SIZE; u_colIdx++)
      {
        if ((DNN_OUTER_RIGHT_ENTRY == u_SnrIdx) || (DNN_OUTER_LEFT_ENTRY == u_SnrIdx))
        {
          f_x += f_u[u_SnrIdx][u_colIdx] * f_Front_uss_dnn_outer_output_layer_weight_Normal[u_rowIdx][u_colIdx];
        }
        else
        {
          f_x += f_u[u_SnrIdx][u_colIdx] * f_Front_uss_dnn_inner_output_layer_weight_Normal[u_rowIdx][u_colIdx];
        }
      }
      if ((DNN_OUTER_RIGHT_ENTRY == u_SnrIdx) || (DNN_OUTER_LEFT_ENTRY == u_SnrIdx))
      {
        f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)] = f_x + f_Front_uss_dnn_outer_output_layer_bias_Normal[u_rowIdx];
      }
      else
      {
        f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)] = f_x + f_Front_uss_dnn_inner_output_layer_bias_Normal[u_rowIdx];
      }
      /*relu*/
      f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)] = LEAKY_RELU((f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)]), f_ReluSlope);
    }
  }

  f_u_concat[SIXTEEN] = LEAKY_RELU(((LEAKY_RELU(((f_VehSpdkph * f_Front_vel_dnn_input_layer_weight_Normal[ZERO]) +
                                            f_Front_vel_dnn_input_layer_bias_Normal[ZERO]),
                                           f_ReluSlope) *
                                f_Front_vel_dnn_output_layer_weight_Normal[ZERO]) +
                               (LEAKY_RELU(((f_VehSpdkph * f_Front_vel_dnn_input_layer_weight_Normal[ONE]) +
                                            f_Front_vel_dnn_input_layer_bias_Normal[ONE]),
                                           f_ReluSlope) *
                                f_Front_vel_dnn_output_layer_weight_Normal[ONE]) +
                               f_Front_vel_dnn_output_layer_bias_Normal),
                              f_ReluSlope);

  f_u_concat[SEVENTEEN] = LEAKY_RELU(((LEAKY_RELU(((f_AmbTemp * f_Front_temp_dnn_input_layer_weight_Normal[ZERO]) +
                                            f_Front_temp_dnn_input_layer_bias_Normal[ZERO]),
                                           f_ReluSlope) *
                                f_Front_temp_dnn_output_layer_weight_Normal[ZERO]) +
                               (LEAKY_RELU(((f_AmbTemp * f_Front_temp_dnn_input_layer_weight_Normal[ONE]) +
                                            f_Front_temp_dnn_input_layer_bias_Normal[ONE]),
                                           f_ReluSlope) *
                                f_Front_temp_dnn_output_layer_weight_Normal[ONE]) +
                               f_Front_temp_dnn_output_layer_bias_Normal),
                              f_ReluSlope);
  f_u_concat[EIGHTEEN] = f_vehicle_var_FrontNormal[u_veh_var][ZERO];
  f_u_concat[NINETEEN] = f_vehicle_var_FrontNormal[u_veh_var][ONE];
  f_u_concat[TWENTY] = f_vehicle_var_FrontNormal[u_veh_var][TWO];
  f_u_concat[TWENTY_ONE] = f_vehicle_var_FrontNormal[u_veh_var][THREE];

  /*Forward Pass
  dot matrix multiplication of weight and inputs*/
  for (u_rowIdx = ZERO; u_rowIdx < FORWARD_PASS_LAYER_SIZE; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FRONT_CONCAT_SIZE; u_colIdx++)
    {
      f_x += f_u_concat[u_colIdx] * f_Front_input_layer_weight_Normal[u_rowIdx][(u_colIdx)];
    }
    f_z1[u_rowIdx] = f_x + f_Front_input_layer_bias_Normal[u_rowIdx];
    /*relu*/
    f_z1[u_rowIdx] = LEAKY_RELU(f_z1[u_rowIdx], f_ReluSlope);
  }

  for (u_rowIdx = ZERO; u_rowIdx < FRONT_INPUT_LAYER_SIZE; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FORWARD_PASS_LAYER_SIZE; u_colIdx++)
    {
      f_x += f_z1[u_colIdx] * f_Front_hidden_layer_weight_Normal[u_rowIdx][(u_colIdx)];
    }
    f_combined[u_rowIdx] = f_x + f_Front_hidden_layer_bias_Normal[u_rowIdx];
    /*relu*/
    f_combined[u_rowIdx] = LEAKY_RELU(f_combined[u_rowIdx], f_ReluSlope);
  }

  /*GRU cell*/
  for (u_rowIdx = FRONT_INPUT_LAYER_SIZE; u_rowIdx < FRONT_COMBINED_SIZE; u_rowIdx++)
  {
    f_combined[u_rowIdx] = f_front_hidden_array[u_rowIdx - FRONT_INPUT_LAYER_SIZE];
  }

  for (u_rowIdx = ZERO; u_rowIdx < FRONT_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FRONT_COMBINED_SIZE; u_colIdx++)
    {
      f_x += (f_combined[u_colIdx] * f_Front_reset_gate_weight_Normal[u_rowIdx][u_colIdx]);
    }
    f_x += f_Front_reset_gate_bias_Normal[u_rowIdx];
    f_reset[u_rowIdx] = f_sigmoid(f_x);
  }

  for (u_rowIdx = ZERO; u_rowIdx < FRONT_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FRONT_COMBINED_SIZE; u_colIdx++)
    {
      f_x += (f_combined[u_colIdx] * f_Front_update_gate_weight_Normal[u_rowIdx][u_colIdx]);
    }
    f_x += f_Front_update_gate_bias_Normal[u_rowIdx];
    f_update_gate[u_rowIdx] = f_sigmoid(f_x);
  }
  /*New combined*/
  for (u_colIdx = FRONT_INPUT_LAYER_SIZE; u_colIdx < FRONT_COMBINED_SIZE; u_colIdx++)
  {
    f_combined[u_colIdx] = f_reset[u_colIdx - FRONT_INPUT_LAYER_SIZE] * f_front_hidden_array[u_colIdx - FRONT_INPUT_LAYER_SIZE];
  }

  /*new gate*/
  for (u_rowIdx = ZERO; u_rowIdx < FRONT_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FRONT_COMBINED_SIZE; u_colIdx++)
    {
      f_x += f_combined[u_colIdx] * f_Front_new_gate_weight_Normal[u_rowIdx][u_colIdx];
    }
    f_new_gate[u_rowIdx] = f_tanh(f_x + f_Front_new_gate_bias_Normal[u_rowIdx]);
  }

  for (u_rowIdx = ZERO; u_rowIdx < FRONT_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_front_hidden_array[u_rowIdx] = ((1.0f - f_update_gate[u_rowIdx]) * f_front_hidden_array[u_rowIdx]) + (f_update_gate[u_rowIdx] * f_new_gate[u_rowIdx]);
  }
  /*output layer*/

  for (u_rowIdx = ZERO; u_rowIdx < FRONT_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FRONT_HIDDEN_SIZE_GRU; u_colIdx++)
    {
      f_tmp = (f_front_hidden_array[u_colIdx] * f_Front_output_layer_weight_Normal[u_rowIdx][u_colIdx]);
      f_x += f_tmp;
    }
    f_z2[u_rowIdx] = f_x + f_Front_output_layer_bias_Normal[u_rowIdx];
    /*Noise*/
    f_z2[u_rowIdx] = LEAKY_RELU(f_z2[u_rowIdx], f_ReluSlope);
  }

  for (u_rowIdx = ZERO; u_rowIdx < (uint8_t) HEIGHT_ALGO_NUM_CLASSES; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FRONT_HIDDEN_SIZE_GRU; u_colIdx++)
    {
      f_x += f_z2[u_colIdx] * f_Front_final_layer_weight_Normal[u_rowIdx][u_colIdx];
    }
    f_out[u_rowIdx] = f_x + f_Front_final_layer_bias_Normal[u_rowIdx];
  }
  f_softMax(f_out, &f_classProb[US_D_PHYS_GRP_FRNT][ZERO], HEIGHT_ALGO_NUM_CLASSES);
  g_HeightClass[US_D_PHYS_GRP_FRNT] =  u_argMax(f_out, HEIGHT_ALGO_NUM_CLASSES);
  if ((g_HeightClass[US_D_PHYS_GRP_FRNT] == HEIGHT_ALGO_WALL_CLASS) || ((f_classProb[US_D_PHYS_GRP_FRNT][(uint8_t)HEIGHT_ALGO_POLE_CLASS] + f_classProb[US_D_PHYS_GRP_FRNT][(uint8_t) HEIGHT_ALGO_VEHICLE_CLASS]) > f_MIN_CLASS_PROB))
  {
    b_isHigh = (bool_t)ME_TRUE;
  }
  else
  {
    b_isHigh = (bool_t)ME_FALSE;
  }
  return b_isHigh;
}

/*
Noise mode input:
# "FOL_h3", "FOL_h2", "FOL_dist2", "FOL_h1", "FOL_dist1", "FOL_conf1",
# "FIL_h3", "FIL_h2", "FIL_dist2", "FIL_h1", "FIL_dist1", "FIL_conf1",
# "FIR_h3", "FIR_h2", "FIR_dist2", "FIR_h1", "FIR_dist1", "FIR_conf1",
# "FOR_h3", "FOR_h2", "FOR_dist2", "FOR_h1", "FOR_dist1", "FOR_conf1",*/
/**********************************************************************************************************************
 * Name:  Front_height_estimation_RNN_noise
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/  
static bool_t Front_height_estimation_RNN_noise(const US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS],
                                                const float32_t f_VehSpdkph,
                                                const float32_t f_AmbTemp,
                                                const uint8_t u_veh_var)
{
  uint8_t u_colIdx;
  uint8_t u_rowIdx;
  uint8_t u_SnrIdx;
  float32_t f_x = 0.0f;
  float32_t f_reset[FRONT_HIDDEN_SIZE_GRU];
  float32_t f_update_gate[FRONT_HIDDEN_SIZE_GRU];
  float32_t f_combined[FRONT_COMBINED_SIZE];
  float32_t f_new_gate[FRONT_HIDDEN_SIZE_GRU];
  float32_t f_z2[FRONT_HIDDEN_SIZE_GRU];
  float32_t f_z1[FORWARD_PASS_LAYER_SIZE];
  float32_t f_u[HEIGHT_ALGO_NUM_SENSORS][FRONT_INPUT_LAYER_SIZE_NOISE];
  float32_t f_u_concat[FRONT_CONCAT_SIZE];
  float32_t f_out[HEIGHT_ALGO_NUM_CLASSES];
  float32_t f_tmp;
  bool_t b_isHigh;
  float32_t f_MinClassProbvar = 0.75f;
  /* Variants: Laramie Rebel Tungsten */
  static const float32_t f_vehicle_var_FrontNoise[THREE][FOUR] = {{1.9384753f, 0.48054662f, -0.7124164f, 0.522415f},
                                                  {-0.11106026f, 0.65668315f, -0.4617337f, -0.9159659f},
                                                  {0.38727522f, 0.6255766f, 0.19718401f, 0.11133595f}};

  /*inner Input network*/

  for (u_SnrIdx = ZERO; u_SnrIdx < HEIGHT_ALGO_NUM_SENSORS; u_SnrIdx++)
  {
    for (u_rowIdx = ZERO; u_rowIdx < FRONT_INPUT_LAYER_SIZE_NOISE; u_rowIdx++)
    {
      f_x = 0.0f;
      if ((DNN_OUTER_RIGHT_ENTRY == u_SnrIdx) || (DNN_OUTER_LEFT_ENTRY == u_SnrIdx))
      {
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight3) * f_Front_uss_dnn_outer_input_layer_weight_Noise[u_rowIdx][ZERO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight2) * f_Front_uss_dnn_outer_input_layer_weight_Noise[u_rowIdx][ONE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist2) * f_Front_uss_dnn_outer_input_layer_weight_Noise[u_rowIdx][TWO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight1) * f_Front_uss_dnn_outer_input_layer_weight_Noise[u_rowIdx][THREE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist1) * f_Front_uss_dnn_outer_input_layer_weight_Noise[u_rowIdx][FOUR];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].uConf1) * f_Front_uss_dnn_outer_input_layer_weight_Noise[u_rowIdx][FIVE];
        f_u[u_SnrIdx][u_rowIdx] = f_x + f_Front_uss_dnn_outer_input_layer_bias_Noise[u_rowIdx];
      }
      else
      {
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight3) * f_Front_uss_dnn_inner_input_layer_weight_Noise[u_rowIdx][ZERO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight2) * f_Front_uss_dnn_inner_input_layer_weight_Noise[u_rowIdx][ONE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist2) * f_Front_uss_dnn_inner_input_layer_weight_Noise[u_rowIdx][TWO];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].fHeight1) * f_Front_uss_dnn_inner_input_layer_weight_Noise[u_rowIdx][THREE];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].sDist1) * f_Front_uss_dnn_inner_input_layer_weight_Noise[u_rowIdx][FOUR];
        f_x += ((float32_t)sHeightInput[u_SnrIdx].uConf1) * f_Front_uss_dnn_inner_input_layer_weight_Noise[u_rowIdx][FIVE];
        f_u[u_SnrIdx][u_rowIdx] = f_x + f_Front_uss_dnn_inner_input_layer_bias_Noise[u_rowIdx];
      }
      /*Noise*/
      f_u[u_SnrIdx][u_rowIdx] = LEAKY_RELU((f_u[u_SnrIdx][u_rowIdx]), f_ReluSlope);
    }
  }

  for (u_SnrIdx = ZERO; u_SnrIdx < HEIGHT_ALGO_NUM_SENSORS; u_SnrIdx++)
  {
    for (u_rowIdx = ZERO; u_rowIdx < HEIGHT_ALGO_NUM_SENSORS; u_rowIdx++)
    {
      f_x = 0.0f;
      for (u_colIdx = ZERO; u_colIdx < FRONT_INPUT_LAYER_SIZE_NOISE; u_colIdx++)
      {
        if ((DNN_OUTER_RIGHT_ENTRY == u_SnrIdx) || (DNN_OUTER_LEFT_ENTRY == u_SnrIdx))
        {
          f_x += f_u[u_SnrIdx][u_colIdx] * f_Front_uss_dnn_outer_output_layer_weight_Noise[u_rowIdx][u_colIdx];
        }
        else
        {
          f_x += f_u[u_SnrIdx][u_colIdx] * f_Front_uss_dnn_inner_output_layer_weight_Noise[u_rowIdx][u_colIdx];
        }
      }
      if ((DNN_OUTER_RIGHT_ENTRY == u_SnrIdx) || (DNN_OUTER_LEFT_ENTRY == u_SnrIdx))
      {
        f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)] = f_x + f_Front_uss_dnn_outer_output_layer_bias_Noise[u_rowIdx];
      }
      else
      {
        f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)] = f_x + f_Front_uss_dnn_inner_output_layer_bias_Noise[u_rowIdx];
      }
      /*Noise*/
      f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)] = LEAKY_RELU((f_u_concat[u_rowIdx + (HEIGHT_ALGO_NUM_SENSORS * u_SnrIdx)]), f_ReluSlope);
    }
  }

  f_u_concat[SIXTEEN] = LEAKY_RELU(((LEAKY_RELU(((f_VehSpdkph * f_Front_vel_dnn_input_layer_weight_Noise[ZERO]) +
                                            f_Front_vel_dnn_input_layer_bias_Noise[ZERO]),
                                           f_ReluSlope) *
                                f_Front_vel_dnn_output_layer_weight_Noise[ZERO]) +
                               (LEAKY_RELU(((f_VehSpdkph * f_Front_vel_dnn_input_layer_weight_Noise[ONE]) +
                                            f_Front_vel_dnn_input_layer_bias_Noise[ONE]),
                                           f_ReluSlope) *
                                f_Front_vel_dnn_output_layer_weight_Noise[ONE]) +
                               f_Front_vel_dnn_output_layer_bias_Noise),
                              f_ReluSlope);
  f_u_concat[SEVENTEEN] = LEAKY_RELU(((LEAKY_RELU(((f_AmbTemp * f_Front_temp_dnn_input_layer_weight_Noise[ZERO]) +
                                            f_Front_temp_dnn_input_layer_bias_Noise[ZERO]),
                                           f_ReluSlope) *
                                f_Front_temp_dnn_output_layer_weight_Noise[ZERO]) +
                               (LEAKY_RELU(((f_AmbTemp * f_Front_temp_dnn_input_layer_weight_Noise[ONE]) +
                                            f_Front_temp_dnn_input_layer_bias_Noise[ONE]),
                                           f_ReluSlope) *
                                f_Front_temp_dnn_output_layer_weight_Noise[ONE]) +
                               f_Front_temp_dnn_output_layer_bias_Noise),
                              f_ReluSlope);
  f_u_concat[EIGHTEEN] = f_vehicle_var_FrontNoise[u_veh_var][ZERO];
  f_u_concat[NINETEEN] = f_vehicle_var_FrontNoise[u_veh_var][ONE];
  f_u_concat[TWENTY] = f_vehicle_var_FrontNoise[u_veh_var][TWO];
  f_u_concat[TWENTY_ONE] = f_vehicle_var_FrontNoise[u_veh_var][THREE];
  /*Forward Pass
  dot matrix multiplication of weight and inputs*/
  for (u_rowIdx = ZERO; u_rowIdx < FORWARD_PASS_LAYER_SIZE; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FRONT_CONCAT_SIZE; u_colIdx++)
    {
      f_x += f_u_concat[u_colIdx] * f_Front_input_layer_weight_Noise[u_rowIdx][(u_colIdx)];
    }
    f_z1[u_rowIdx] = f_x + f_Front_input_layer_bias_Noise[u_rowIdx];
    /*Noise*/
    f_z1[u_rowIdx] = LEAKY_RELU(f_z1[u_rowIdx], f_ReluSlope);
  }

  for (u_rowIdx = ZERO; u_rowIdx < FRONT_INPUT_LAYER_SIZE; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FORWARD_PASS_LAYER_SIZE; u_colIdx++)
    {
      f_x += f_z1[u_colIdx] * f_Front_hidden_layer_weight_Noise[u_rowIdx][(u_colIdx)];
    }
    f_combined[u_rowIdx] = f_x + f_Front_hidden_layer_bias_Noise[u_rowIdx];
    /*Noise*/
    f_combined[u_rowIdx] = LEAKY_RELU(f_combined[u_rowIdx], f_ReluSlope);
  }

  /*GRU cell*/
  for (u_rowIdx = FRONT_INPUT_LAYER_SIZE; u_rowIdx < FRONT_COMBINED_SIZE; u_rowIdx++)
  {
    f_combined[u_rowIdx] = f_front_hidden_array_noise[u_rowIdx - FRONT_INPUT_LAYER_SIZE];
  }

  for (u_rowIdx = ZERO; u_rowIdx < FRONT_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FRONT_COMBINED_SIZE; u_colIdx++)
    {
      f_x += (f_combined[u_colIdx] * f_Front_reset_gate_weight_Noise[u_rowIdx][u_colIdx]);
    }
    f_x += f_Front_reset_gate_bias_Noise[u_rowIdx];
    f_reset[u_rowIdx] = f_sigmoid(f_x);
  }

  for (u_rowIdx = ZERO; u_rowIdx < FRONT_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FRONT_COMBINED_SIZE; u_colIdx++)
    {
      f_x += (f_combined[u_colIdx] * f_Front_update_gate_weight_Noise[u_rowIdx][u_colIdx]);
    }
    f_x += f_Front_update_gate_bias_Noise[u_rowIdx];
    f_update_gate[u_rowIdx] = f_sigmoid(f_x);
  }
  /*New combined*/
  for (u_colIdx = FRONT_INPUT_LAYER_SIZE; u_colIdx < FRONT_COMBINED_SIZE; u_colIdx++)
  {
    f_combined[u_colIdx] = f_reset[u_colIdx - FRONT_INPUT_LAYER_SIZE] * f_front_hidden_array_noise[u_colIdx - FRONT_INPUT_LAYER_SIZE];
  }

  /*new gate*/
  for (u_rowIdx = ZERO; u_rowIdx < FRONT_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FRONT_COMBINED_SIZE; u_colIdx++)
    {
      f_x += f_combined[u_colIdx] * f_Front_new_gate_weight_Noise[u_rowIdx][u_colIdx];
    }
    f_new_gate[u_rowIdx] = f_tanh(f_x + f_Front_new_gate_bias_Noise[u_rowIdx]);
  }

  for (u_rowIdx = ZERO; u_rowIdx < FRONT_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_front_hidden_array_noise[u_rowIdx] = ((1.0f - f_update_gate[u_rowIdx]) * f_front_hidden_array_noise[u_rowIdx]) + (f_update_gate[u_rowIdx] * f_new_gate[u_rowIdx]);
  }
  /*output layer*/

  for (u_rowIdx = ZERO; u_rowIdx < FRONT_HIDDEN_SIZE_GRU; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FRONT_HIDDEN_SIZE_GRU; u_colIdx++)
    {
      f_tmp = (f_front_hidden_array_noise[u_colIdx] * f_Front_output_layer_weight_Noise[u_rowIdx][u_colIdx]);
      f_x += f_tmp;
    }
    f_z2[u_rowIdx] = f_x + f_Front_output_layer_bias_Noise[u_rowIdx];
    /*Noise*/
    f_z2[u_rowIdx] = LEAKY_RELU(f_z2[u_rowIdx], f_ReluSlope);
  }

  for (u_rowIdx = ZERO; u_rowIdx < (uint8_t) HEIGHT_ALGO_NUM_CLASSES; u_rowIdx++)
  {
    f_x = 0.0f;
    for (u_colIdx = ZERO; u_colIdx < FRONT_HIDDEN_SIZE_GRU; u_colIdx++)
    {
      f_x += f_z2[u_colIdx] * f_Front_final_layer_weight_Noise[u_rowIdx][u_colIdx];
    }
    f_out[u_rowIdx] = f_x + f_Front_final_layer_bias_Noise[u_rowIdx];
  }

  f_softMax(f_out, &f_classProb[US_D_PHYS_GRP_FRNT][ZERO], HEIGHT_ALGO_NUM_CLASSES);
  g_HeightClass[US_D_PHYS_GRP_FRNT] =  u_argMax(f_out, HEIGHT_ALGO_NUM_CLASSES);
  if(f_VehSpdkph < f_VEH_SPD_THRESHOLD)
  {
    f_MinClassProbvar = 0.95f;
  }
  if ((g_HeightClass[US_D_PHYS_GRP_FRNT] == HEIGHT_ALGO_WALL_CLASS) || ((f_classProb[US_D_PHYS_GRP_FRNT][(uint8_t)HEIGHT_ALGO_POLE_CLASS] + f_classProb[US_D_PHYS_GRP_FRNT][(uint8_t) HEIGHT_ALGO_VEHICLE_CLASS]) > f_MinClassProbvar))
  {
    b_isHigh = (bool_t)ME_TRUE;
  }
  else
  {
    b_isHigh = (bool_t)ME_FALSE;
  }
  return b_isHigh;
}

/*Function to update the window buffer andfind the majority decision */
/**********************************************************************************************************************
 * Name:  Height_Output_Filters
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/  
static bool_t Height_Output_Filter(const bool_t bIsHighFlag, const uint8_t u_phys_grp)
{
  float32_t fSum;
  bool_t b_FiltFlag = (bool_t)ME_FALSE;
  uint8_t avgFilter_size;
  uint8_t sumFilter_size;  
  bool_t b_isSumFilterHigh = (bool_t)ME_FALSE;

  if (u_phys_grp <= US_D_PHYS_GRP_REAR)
  {
    /*Get the corresponding window size for each bumper*/
    avgFilter_size = u_WindowBufferSize;
    sumFilter_size = u_SumBufferSize;    
    /*update Flag buffer*/
    u_HeightWindowFilterBuffer[u_phys_grp][u_HeightFilterIdx[u_phys_grp]] = (uint8_t)bIsHighFlag;
    b_isSumFilterHigh = Sum_Filter(u_HeightWindowFilterBuffer[u_phys_grp], WINDOW_FILTER_SIZE, sumFilter_size, u_HeightFilterIdx[u_phys_grp]);
    fSum = Window_Filter(u_HeightWindowFilterBuffer[u_phys_grp], WINDOW_FILTER_SIZE, avgFilter_size, u_HeightFilterIdx[u_phys_grp]);
    u_HeightFilterIdx[u_phys_grp]++;
    if (u_HeightFilterIdx[u_phys_grp] >= avgFilter_size)
    {
      u_HeightFilterIdx[u_phys_grp] = ZERO;
    }
    else{/*do nothing*/}

    /*apply the logic to the final output*/
    if ((fSum > f_MIN_SUM_FILTER_AVG) || (ME_TRUE == b_isSumFilterHigh) || (g_HeightClass[u_phys_grp] == HEIGHT_ALGO_WALL_CLASS))
    {
      b_FiltFlag = (bool_t)ME_TRUE;
    }
    else
    {
      b_FiltFlag = (bool_t)ME_FALSE;
    }
  }
  else{/*do nothing*/}

  return b_FiltFlag;
}


/**********************************************************************************************************************
 * Name:  Reset_Front_RNN
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/
static void Reset_Front_RNN(void)
{
  /*Reset Hidden State, Window Buffer States*/
  (void)memset(f_front_hidden_array, 0.0F, FRONT_HIDDEN_SIZE_GRU * sizeof(float32_t));
  (void)memset(f_front_hidden_array_noise, 0.0F, FRONT_HIDDEN_SIZE_GRU_NOISE * sizeof(float32_t));
  (void)memset(u_HeightWindowFilterBuffer[US_D_PHYS_GRP_FRNT], ZERO, WINDOW_FILTER_SIZE * sizeof(uint8_t));
}


/**********************************************************************************************************************
 * Name:  Reset_Rear_RNN
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/
static void Reset_Rear_RNN(void)
{
  /*Reset Hidden State, Window Buffer States*/
  (void)memset(f_rear_hidden_array, 0.0F, REAR_HIDDEN_SIZE_GRU * sizeof(float32_t));
  (void)memset(f_rear_hidden_array_noise, 0.0F, REAR_HIDDEN_SIZE_GRU_NOISE * sizeof(float32_t));
  (void)memset(u_HeightWindowFilterBuffer[US_D_PHYS_GRP_REAR], ZERO, WINDOW_FILTER_SIZE * sizeof(uint8_t));
}

/**********************************************************************************************************************
 * Name:  Get_VariantID
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/
static uint8_t Get_VariantID(void)
{
  uint8_t variantID_u8;

  switch (uUsed_Cal_Data_Set)
  {
  case 0:
  case 1:
  case 2:
    variantID_u8 = DNN_LARAMIE_VAR;
    break;
  case 3:
    variantID_u8 = DNN_REBEL_VAR;
    break;
  case 4:
    variantID_u8 = DNN_LARAMIE_VAR; 
    break;
  case 5:
    variantID_u8 = DNN_TUNGSTEN_VAR;
    break;
  default:
    variantID_u8 = DNN_LARAMIE_VAR;
   break;
  }

  return variantID_u8;
}

/**********************************************************************************************************************
 * Name:  Front_Height_Algo_RNN 
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/
static void Front_Height_Algo_RNN(void)
{
  bool_t bIsHigh_Return = (bool_t)ME_FALSE;
  bool_t b_Is_NFD = (bool_t)ME_FALSE;
  uint8_t uSnrIdx = ZERO;
  const US_S_SensorMeasRecs_t *const psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
  const US_S_SensorMeasDist_t *psSnrMeasDist = UssMgr_psGetCurSnrMeasRecDist();  
  const US_S_SensorRec_t *psSensorRec;
  const US_S_SignedDist_t *psSnrSignedDist;  
  US_S_HeightAlgoInput_t sFrontHeightInput[HEIGHT_ALGO_NUM_SENSORS];
  float32_t f_VehSpdkph = 0.0f;
  float32_t f_AmbTemp = 0.0f;
  uint8_t PRX_variantID_u8 = ZERO;

  /*reset input values every time */
  (void)memset(&sFrontHeightInput, ZERO, HEIGHT_ALGO_NUM_SENSORS * sizeof(US_S_HeightAlgoInput_t));
  /*
   RNN model input in exact order    :
    "FOL_dist3", "FOL_w2", "FOL_h2", "FOL_dist2", "FOL_w1", "FOL_h1", "FOL_dist1"
    "FIL_dist3", "FIL_w2", "FIL_h2", "FIL_dist2", "FIL_w1", "FIL_h1", "FIL_dist1"
    "FIR_dist3", "FIR_w2", "FIR_h2", "FIR_dist2", "FIR_w1", "FIR_h1", "FIR_dist1"
    "FOR_dist3", "FOR_w2", "FOR_h2", "FOR_dist2", "FOR_w1", "FOR_h1", "FOR_dist1"
    sensor ids are:
    FOL 4
    FIL 3
    FIR 2
    FOR 1
    This loop is designed to reverse the order in order to match what RNN is expecting
   */
  /* Scan all sensor positions*/
  for (uSnrIdx = ONE; uSnrIdx < FIVE; uSnrIdx++)
  {
    psSensorRec = &psSnrMeasRec->sSensorRec[uSnrIdx];
    psSnrSignedDist = &psSnrMeasDist->asSensorRecDist[uSnrIdx];
    
    if (US_E_REQ_SEND_NFD == psSensorRec->eEchoTypeRequested)
    {
      /*Currently all sensors in one physical group (Rear or Front)
      send NFD at the same time*/
      b_Is_NFD = (bool_t)ME_TRUE;
    }
    else{/*do nothing*/}
    /*if no echoes are copied, ME_NOT_OK (1) will be returned*/
    Height_Algo_RNN_Input_Raw(psSensorRec, psSnrSignedDist, &sFrontHeightInput[FOUR - uSnrIdx], US_D_PHYS_GRP_FRNT);
  }
#if UNIT_TEST_FRONT_LIVE
  uint8_t i = ZERO;
  for (i = 0; i < 4; i++)
  {
    sFrontHeightInput[i].echo1Idx = test_echo1Idx[globalcounter + i];
    sFrontHeightInput[i].echo2Idx = test_echo2Idx[globalcounter + i];
    sFrontHeightInput[i].echo3Idx = test_echo3Idx[globalcounter + i];
    sFrontHeightInput[i].fHeight1 = test_fHeight1[globalcounter + i];
    sFrontHeightInput[i].fHeight2 = test_fHeight2[globalcounter + i];
    sFrontHeightInput[i].fHeight3 = test_fHeight3[globalcounter + i];
    sFrontHeightInput[i].numEchoes = test_numEchoes[globalcounter + i];
    sFrontHeightInput[i].sDist1 = test_sDist1[globalcounter + i];
    sFrontHeightInput[i].sDist2 = test_sDist2[globalcounter + i];
    sFrontHeightInput[i].sDist3 = test_sDist3[globalcounter + i];
    sFrontHeightInput[i].uConf1 = test_uConf1[globalcounter + i];
    sFrontHeightInput[i].uWidth1 = test_uWidth1[globalcounter + i];
    sFrontHeightInput[i].uWidth2 = test_uWidth2[globalcounter + i];
  }
  f_VehSpdkph = test_vehspd[vehspd_globalcounter];
  f_AmbTemp = test_Ambtemp[vehspd_globalcounter];
  globalcounter += 4;
  vehspd_globalcounter++;

  if (globalcounter >= 696)
  {
    globalcounter = 0;
  }
  if (vehspd_globalcounter >= 174)
  {
    vehspd_globalcounter = 0;
#if UNIT_TEST_FRONT_LIVE
    UART_printf("\n Front Log end");
#endif
  }
#endif
  /*if at least a sensor contained echo information, the Init counter will be less
    than FOUR.
    If no sensor information was copied from any sensor, the Init counter will be FOUR
    and RNN state won't be updated. A low output will be pushed into the Filtered buffer */

#if !UNIT_TEST_FRONT_LIVE
  f_VehSpdkph = UssCom_F_GetVehSpeed();
  PRX_variantID_u8 = Get_VariantID();

  if (US_TEMPVALID_VALID == UssCom_F_GetAmbientTempValidity())
  {
    f_AmbTemp = UssCom_F_GetAmbientTemp();
  }
  else
  {
    f_AmbTemp = US_D_TOF_TEMP_DEFAULT;
  }
#endif
  /*execute the RNN model and update the Filtered output ONLY if the
    Input data contains at least one valid measurement from a single sensor*/
  if (UssMgr_GetUsedNoiseMitMode(US_D_PHYS_GRP_FRNT) == US_NOISEMIT_NONE)
  {
    if ((bool_t)ME_TRUE == b_prevNoiseRNNActive[US_D_PHYS_GRP_FRNT])
    {
      /*previous execution was noise mode model*/
      Reset_Front_RNN();
      b_prevNoiseRNNActive[US_D_PHYS_GRP_FRNT] = (bool_t)ME_FALSE;
    }
    else{/*DO NOTHING*/}

    bIsHigh_Return = Front_height_estimation_RNN(sFrontHeightInput, f_VehSpdkph, f_AmbTemp, PRX_variantID_u8);
  }
  else
  {
    if ((bool_t)ME_FALSE == b_prevNoiseRNNActive[US_D_PHYS_GRP_FRNT])
    {
      /*previous execution was normal mode model*/
      Reset_Front_RNN();
      b_prevNoiseRNNActive[US_D_PHYS_GRP_FRNT] = (bool_t)ME_TRUE;
    }
    else{/*DO NOTHING*/}
    if ((sFrontHeightInput[ZERO].uWidth1 == ZERO ) && (sFrontHeightInput[ONE].uWidth1 == ZERO ) &&
        (sFrontHeightInput[TWO].uWidth1 == ZERO ) && (sFrontHeightInput[THREE].uWidth1 == ZERO ))
    {
      bIsHigh_Return = Front_height_estimation_RNN_noise(sFrontHeightInput, f_VehSpdkph, f_AmbTemp, PRX_variantID_u8);
    }
    else{/*DO NOTHING*/}
  }

    /*If the Echo sent is NFD do not update the decision*/
     if ((bool_t)ME_FALSE == b_Is_NFD)
    {
      b_globHeightFlagFiltered[US_D_PHYS_GRP_FRNT] = Height_Output_Filter(bIsHigh_Return, US_D_PHYS_GRP_FRNT);
      b_globHeightFlag[US_D_PHYS_GRP_FRNT] = bIsHigh_Return;
    }
    else{/*DO NOTHING*/}
#if UNIT_TEST_FRONT_LIVE
    UART_printf("\n%d:%d:%d, ", vehspd_globalcounter, b_globHeightFlagFiltered[US_D_PHYS_GRP_FRNT], sFrontHeightInput[1].sDist1);
#endif

  }

  /**********************************************************************************************************************
 * Name:  Rear_Height_Algo_RNN 
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/
static void Rear_Height_Algo_RNN(void)
{
  bool_t bIsHigh_Return = (bool_t)ME_FALSE;
  bool_t b_Is_NFD = (bool_t)ME_FALSE;
  uint8_t uSnrIdx = ZERO ;
  const US_S_SensorMeasRecs_t  *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
  const US_S_SensorMeasDist_t  *psSnrMeasDist = UssMgr_psGetCurSnrMeasRecDist();
  const US_S_SignedDist_t *psSnrSignedDist;    
  const US_S_SensorRec_t *psSensorRec;
  US_S_HeightAlgoInput_t sRearHeightInput[HEIGHT_ALGO_NUM_SENSORS];
  float32_t f_VehSpdkph = 0.0f;
  float32_t f_AmbTemp = 0.0f;

  /*reset input values every time */
  (void)memset(&sRearHeightInput, ZERO, HEIGHT_ALGO_NUM_SENSORS * sizeof(US_S_HeightAlgoInput_t));
  /*
   RNN model input in exact order    :
    "ROL_dist3", "ROL_w2", "ROL_h2", "ROL_dist2", "ROL_w1", "ROL_h1", "ROL_dist1"
    "RIL_dist3", "RIL_w2", "RIL_h2", "RIL_dist2", "RIL_w1", "RIL_h1", "RIL_dist1"
    "RIR_dist3", "RIR_w2", "RIR_h2", "RIR_dist2", "RIR_w1", "RIR_h1", "RIR_dist1"
    "ROR_dist3", "ROR_w2", "ROR_h2", "ROR_dist2", "ROR_w1", "ROR_h1", "ROR_dist1"
    sensor ids are:
    ROL 10
    RIL 9
    RIR 8
    ROR 7
    This loop is designed to reverse the order in order to match what RNN is expecting
  */
  /* Scan all sensor positions */
  for (uSnrIdx = SEVEN; uSnrIdx < (US_D_MAX_NUM_SENSORS - ONE); uSnrIdx++)
  {
    psSensorRec = &psSnrMeasRec->sSensorRec[uSnrIdx];
    psSnrSignedDist = &psSnrMeasDist->asSensorRecDist[uSnrIdx];
      
    if (US_E_REQ_SEND_NFD == psSensorRec->eEchoTypeRequested)
    {
      /*Currently all sensors in one physical group (Rear or Front)
      send NFD at the same time*/
      b_Is_NFD = (bool_t)ME_TRUE;
    }
    else{/*DO NOTHING*/}
    /*if no echoes are copied, ME_NOT_OK (1) will be returned*/
    Height_Algo_RNN_Input_Raw(psSensorRec, psSnrSignedDist, &sRearHeightInput[10u - uSnrIdx], US_D_PHYS_GRP_REAR);
  }
#if UNIT_TEST_REAR_LIVE
  uint8_t i = ZERO;
  for (i = 0; i < 4; i++)
  {
    sRearHeightInput[i].echo1Idx = test_echo1Idx[globalcounter + i];
    sRearHeightInput[i].echo2Idx = test_echo2Idx[globalcounter + i];
    sRearHeightInput[i].echo3Idx = test_echo3Idx[globalcounter + i];
    sRearHeightInput[i].fHeight1 = test_fHeight1[globalcounter + i];
    sRearHeightInput[i].fHeight2 = test_fHeight2[globalcounter + i];
    sRearHeightInput[i].fHeight3 = test_fHeight3[globalcounter + i];
    sRearHeightInput[i].numEchoes = test_numEchoes[globalcounter + i];
    sRearHeightInput[i].sDist1 = test_sDist1[globalcounter + i];
    sRearHeightInput[i].sDist2 = test_sDist2[globalcounter + i];
    sRearHeightInput[i].sDist3 = test_sDist3[globalcounter + i];
    sRearHeightInput[i].uConf1 = test_uConf1[globalcounter + i];
    sRearHeightInput[i].uWidth1 = test_uWidth1[globalcounter + i];
    sRearHeightInput[i].uWidth2 = test_uWidth2[globalcounter + i];
  }
  f_VehSpdkph = test_vehspd[vehspd_globalcounter];
  f_AmbTemp = test_Ambtemp[vehspd_globalcounter];

  globalcounter += 4;
  vehspd_globalcounter++;

  if (globalcounter >= 716)
  {
    globalcounter = 0;
  }
  if (vehspd_globalcounter >= 179)
  {
    vehspd_globalcounter = 0;
#if UNIT_TEST_REAR_LIVE
    UART_printf("\n Rear Log end \n");
#endif
  }
#endif

#if !UNIT_TEST_REAR_LIVE
  f_VehSpdkph = UssCom_F_GetVehSpeed();
  if (US_TEMPVALID_VALID == UssCom_F_GetAmbientTempValidity())
  {
    f_AmbTemp = UssCom_F_GetAmbientTemp();
  }
  else
  {
    f_AmbTemp = US_D_TOF_TEMP_DEFAULT;
  }
#endif
  /*execute the RNN model and update the Filtered output ONLY if the
    Input data contains at least one valid measurement from a single sensor*/
  if (UssMgr_GetUsedNoiseMitMode(US_D_PHYS_GRP_REAR) == US_NOISEMIT_NONE)
  {
    if ((bool_t)ME_TRUE == b_prevNoiseRNNActive[US_D_PHYS_GRP_REAR])
    {
      /*previous execution was noise mode model*/
      Reset_Rear_RNN();
      b_prevNoiseRNNActive[US_D_PHYS_GRP_REAR] =  (bool_t)ME_FALSE;
    }
    else{/*DO NOTHING*/}
    bIsHigh_Return = Rear_height_estimation_RNN(sRearHeightInput, f_VehSpdkph, f_AmbTemp);
  }
  else
  {
    if ((bool_t)ME_FALSE == b_prevNoiseRNNActive[US_D_PHYS_GRP_REAR])
    {
      /*previous execution was normal mode model*/
      Reset_Rear_RNN();
      b_prevNoiseRNNActive[US_D_PHYS_GRP_REAR] = (bool_t)ME_TRUE;
    }
    else{/*DO NOTHING*/}
    if ((sRearHeightInput[ZERO].uWidth1 == ZERO ) && (sRearHeightInput[ONE].uWidth1 == ZERO ) &&
        (sRearHeightInput[TWO].uWidth1 == ZERO ) && (sRearHeightInput[THREE].uWidth1 == ZERO ))
    {
      bIsHigh_Return = Rear_height_estimation_RNN_noise(sRearHeightInput, f_VehSpdkph, f_AmbTemp);
    }
    else{/*DO NOTHING*/}
  }

  /*If the Echo sent is NFD do not update the decision*/
  if ((bool_t)ME_FALSE == b_Is_NFD)
  {
    b_globHeightFlagFiltered[US_D_PHYS_GRP_REAR] = Height_Output_Filter(bIsHigh_Return, US_D_PHYS_GRP_REAR);
    b_globHeightFlag[US_D_PHYS_GRP_REAR] = bIsHigh_Return;
  }
  else{/*DO NOTHING*/}
#if UNIT_TEST_REAR_LIVE
  /*UART_printf("\n%d:%d :H1 :%f,H2 :%f ,H3: %f,W1: %d,W2: %d,W3: %d, ",vehspd_globalcounter,b_globHeightFlagFiltered[USSCOM_BUMPLOC_REAR],fHeight1,);*/
    UART_printf("\n%d:%d:%d, ", vehspd_globalcounter, b_globHeightFlagFiltered[US_D_PHYS_GRP_REAR], sRearHeightInput[1].sDist1);
#endif
  }

  /**********************************************************************************************************************
 * Name:  Height_Algo_RNN_Input_Raw 
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/
static void Height_Algo_RNN_Input_Raw(const US_S_SensorRec_t *const sOneSensorRec,
                                 const US_S_SignedDist_t *const sOneSensorRecDist,
                                 US_S_HeightAlgoInput_t *const sHeightInput,
                                 const uint8_t u_phys_group)
{
  float32_t f_height_scale = 1.0f;

  if (UssMgr_GetUsedNoiseMitMode(u_phys_group) == US_NOISEMIT_NONE)
  {
    f_height_scale = HEIGHT_ALGO_NORMAL_EH_SCALE;
  }
  else
  {
    /*scale the echo height only in Noise mode*/
    f_height_scale = HEIGHT_ALGO_NOISE_EH_SCALE;
  }

  sHeightInput->uWidth1 = sOneSensorRec->sEcho[ZERO].uWidth / TEN;
  sHeightInput->sDist1 = sOneSensorRecDist->aiEchoTotalDist[ZERO];
  sHeightInput->uWidth2 = sOneSensorRec->sEcho[ONE].uWidth / TEN;
  sHeightInput->sDist2 = sOneSensorRecDist->aiEchoTotalDist[ONE];
  sHeightInput->sDist3 = sOneSensorRecDist->aiEchoTotalDist[TWO];
  sHeightInput->uConf1 = sOneSensorRec->sEcho[ZERO].uConf;
  if (sOneSensorRecDist->aiEchoTotalDist[ZERO] < 0)
  {
    sHeightInput->fHeight1 = -1.0f *(((float32_t)sOneSensorRec->sEcho[ZERO].uEchoHeight) / f_height_scale);
    sHeightInput->fHeight2 = -1.0f * (((float32_t)sOneSensorRec->sEcho[ONE].uEchoHeight) / f_height_scale);
    sHeightInput->fHeight3 = -1.0f * (((float32_t)sOneSensorRec->sEcho[TWO].uEchoHeight) / f_height_scale);
  }
  else
  {
    sHeightInput->fHeight1 = (float32_t)(sOneSensorRec->sEcho[ZERO].uEchoHeight) / f_height_scale;
    sHeightInput->fHeight2 = (float32_t)(sOneSensorRec->sEcho[ONE].uEchoHeight) / f_height_scale;
    sHeightInput->fHeight3 = (float32_t)(sOneSensorRec->sEcho[TWO].uEchoHeight) / f_height_scale;
  }
}

/**********************************************************************************************************************
 * Name:  USSMgr_HeightEstimationRNN
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/
void USSMgr_HeightEstimationRNN(void)
{
  US_E_App_Prndl_Status_e ePrndl = UssCom_F_GetVehPrndl();
#if UNIT_TEST_FRONT_LIVE || UNIT_TEST_REAR_LIVE
  ePrndl = (US_E_App_Prndl_Status_e)test_ePrndl[gearcounter];
  gearcounter++;
  if (gearcounter >= 179)
  {
    gearcounter = 0;
  }
#endif
  if (ePrndl == US_PRNDL_REVERSE)
  {
    Rear_Height_Algo_RNN();
  }
  else{/*DO NOTHING*/}
  if (ePrndl == US_PRNDL_DRIVE)
  {
    Front_Height_Algo_RNN();
  }
  else{/*DO NOTHING*/}
}

/**********************************************************************************************************************
 * Name:  USSMgr_Height_GetHeightClass
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/
uint8_t USSMgr_Height_GetHeightClass(const uint8_t uPhys_Grp)
{
  return g_HeightClass[uPhys_Grp];
}


/**********************************************************************************************************************
 * Name:  USSMgr_Height_GetFilteredHeightFlag
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/
bool_t USSMgr_Height_GetFilteredHeightFlag(const uint8_t uPhys_Grp)
{
  return b_globHeightFlagFiltered[uPhys_Grp];
}


/**********************************************************************************************************************
 * Name:  USSMgr_Height_GetUnfilteredHeightFlag
 * Req.-ID: 15590667
 * Req.-ID: 15590687
 * Req.-ID: 15590689
 * Req.-ID: 15590673
 *********************************************************************************************************************/
uint8_t USSMgr_Height_GetUnfilteredHeightFlag(const uint8_t uPhys_Grp)
{
  return b_globHeightFlag[uPhys_Grp];
}

#endif
