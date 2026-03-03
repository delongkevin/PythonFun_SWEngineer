#include "US_ComInputBuffer_Global.h"
#include "US_MgrMath.h"

static float32_t F_MAX(const float32_t x, const float32_t y);
static float32_t exp_approx(const float32_t x);
static uint8_t uDecU8LimitedWrap(const uint8_t uNum, const uint8_t uWrapNum);


/**********************************************************************************************************************
 * Name:  exp_approx
 * DD-ID: 
 * Req.-ID: 17597432
 *********************************************************************************************************************/
static float32_t exp_approx(const float32_t x)
{
  float32_t fsum = 1.0f;  /* Initialize sum of series*/
  float32_t fterm = 1.0f; /* Initialize first term of series */
  uint8_t i;
  uint8_t max_terms;
  const float32_t fabsx = fabsf(x);

  /* Determine the number of terms based on the magnitude of x */
  if (fabsx < EXP_SMALL_X_LIMIT)
  {
    max_terms = EXP_SMALL_X_TERMS; /* For small x, fewer terms are needed */
  }
  else if (fabsx < EXP_MODERATE_X_LIMIT)
  {
    max_terms = EXP_MODERATE_X_TERMS; /* For moderate x, use 20 terms */
  }
  else if (fabsx < EXP_MID_X_LIMIT)
  {
    max_terms = EXP_MID_X_TERMS; /* For mid x, use 30 terms */
  }
  else if (fabsx < EXP_LARGE_X_LIMIT)
  {
    max_terms = EXP_LARGE_X_TERMS; /* For large x, use 40 terms */
  }
  else
  {
    max_terms = EXP_VERY_LARGE_X_TERMS; /* For large x, use more terms */
  }

  /* Add terms up to x^max_terms / max_terms! */
  for (i = ONE; i <= max_terms; ++i)
  {
    fterm = fterm * (x / ((float32_t)i)); /* Compute next term */
    fsum += fterm;                        /* Add next term to sum */
  }

  fsum = F_MAX(fsum, 0.0f);

  return fsum;
}

/**********************************************************************************************************************
 * Name:  f_tanh
 * DD-ID: 
 * Req.-ID: 17597432
 *********************************************************************************************************************/
float32_t f_tanh(const float32_t f_x)
{
  float32_t exp_x = 0.0f;
  float32_t exp_neg_x = 0.0f;
  float32_t f_val;
  if (f_x > TANH_UPPER_XLIMIT)
  {
    f_val = TANH_UPPER_Y_LIMIT;
  }
  else if (f_x < TANH_LOWER_XLIMIT)
  {
    f_val = TANH_LOWER_Y_LIMIT;
  }
  else
  {
    exp_x = exp_approx(f_x);
    exp_neg_x = exp_approx(-f_x);
    f_val = (exp_x - exp_neg_x) / (exp_x + exp_neg_x);
  }
  return f_val;
}

/*Approximation: 1/2 + 1/4x - 1/48x^3*/
/**********************************************************************************************************************
 * Name:  f_sigmoid
 * DD-ID: 
 * Req.-ID: 17597432
 *********************************************************************************************************************/
float32_t f_sigmoid(const float32_t f_x)
{
  float32_t f_val;
  if (f_x > SIGMOID_UPPER_X_LIMIT)
  {
    f_val = SIGMOID_UPPER_Y_LIMIT;
  }
  else if (f_x < SIGMOID_LOWER_X_LIMIT)
  {
    f_val = SIGMOID_LOWER_Y_LIMIT;
  }
  else
  {
    f_val = 1.0f / (1.0f + exp_approx(-f_x));
  }
  return f_val;
}

/**********************************************************************************************************************
 * Name:  LEAKY_RELU
 * DD-ID: 
 * Req.-ID: 17597432
 *********************************************************************************************************************/
float32_t LEAKY_RELU(const float32_t x, const float32_t slope)
{
  return ((x >= 0.0f) ? (x) : (x * slope));
}

/**********************************************************************************************************************
 * Name:  F_MAX
 * DD-ID: 
 * Req.-ID: 17597432
 *********************************************************************************************************************/
static float32_t F_MAX(const float32_t x, const float32_t y)
{
  return ((x > y) ? (x) : (y));
}

/**********************************************************************************************************************
 * Name:  uDecU8LimitedWrap
 * DD-ID: 
 * Req.-ID: 17597432
 *********************************************************************************************************************/
static uint8_t uDecU8LimitedWrap(const uint8_t uNum, const uint8_t uWrapNum)
{
  uint8_t uRetNum;
  if (uNum > ZERO)
  {
    uRetNum = uNum - ONE;
  }
  else
  {
    uRetNum = ((uWrapNum > ZERO) ? (uWrapNum - ONE) : ZERO);
  }
  return uRetNum;
}

/**********************************************************************************************************************
 * Name:  Window_Filter
 * DD-ID: 
 * Req.-ID: 17597432
 *********************************************************************************************************************/
float32_t Window_Filter(const uint8_t *uBuffer, const uint8_t u_Buffer_size, const uint8_t u_avgFilterSize, const uint8_t uStartIdx)
{
  float32_t fSum = 0.0f;
  uint8_t u_idx;
  uint8_t u_tmpIdx = uStartIdx + ONE;
  /*find the window filter average for a round buffer*/
  for (u_idx = ZERO; u_idx < u_avgFilterSize; u_idx++)
  {
    u_tmpIdx = uDecU8LimitedWrap(u_tmpIdx, u_Buffer_size);
    fSum += (float32_t)(uBuffer[u_tmpIdx]);
  }
  fSum = fSum / (float32_t)u_avgFilterSize;
  return fSum;
}

/**********************************************************************************************************************
 * Name:  Sum_Filter
 * DD-ID: 
 * Req.-ID: 17597432
 *********************************************************************************************************************/
bool_t Sum_Filter(const uint8_t *uBuffer, const uint8_t u_Buffer_size, const uint8_t u_sumFilterSize, const uint8_t uStartIdx)
{
  uint8_t uSum = ZERO;
  uint8_t u_idx;
  bool_t b_isSumFilterHigh;
  uint8_t u_tmpIdx = uStartIdx + ONE;
  /*find the window filter sum for consecutive entries in a round buffer*/
  for (u_idx = ZERO; (u_idx < u_sumFilterSize); u_idx++)
  {
    u_tmpIdx = uDecU8LimitedWrap(u_tmpIdx, u_Buffer_size);
    if( (uint8_t)ME_TRUE == uBuffer[u_tmpIdx] )
    {
      uSum++;
    }
    else
    {
      if (uSum > ZERO)
      {
        uSum = uSum - ONE;
      }
      else
      {
        uSum = ZERO;
      }
    }
  }
  b_isSumFilterHigh = ((uSum >= u_sumFilterSize) ? (bool_t)ME_TRUE : (bool_t)ME_FALSE);
  return b_isSumFilterHigh;
}

/**********************************************************************************************************************
 * Name:  u_argMax
 * DD-ID: 
 * Req.-ID: 17597432
 *********************************************************************************************************************/
uint8_t u_argMax(const float32_t *f_array, const uint8_t size)
{
  uint8_t i;
  float32_t f_tmp = f_array[0];
  uint8_t idx = ZERO;

  for (i = 1; i < size; i++)
  {
    if (f_array[i] > f_tmp)
    {
      f_tmp = f_array[i];
      idx = i;
    }
  }
  return idx;
}

/* Function to compute the softf_max of an array*/
/**********************************************************************************************************************
 * Name:  softf_max
 * DD-ID: 
 * Req.-ID: 17597432
 *********************************************************************************************************************/
void f_softMax(const float32_t *f_input, float32_t *f_output, const uint8_t u_length)
{
  float32_t f_min = f_input[0];
  float32_t f_sum = 0.0f;
  uint8_t lower_bound = TEN;
  uint8_t i;

  /* Find the f_minimum value in the f_input array*/
  for (i = ONE; i < u_length; i++)
  {
    if (f_input[i] < f_min)
    {
      f_min = f_input[i];
    }
  }

  /* Compute the exponentials and their f_sum*/
  for (i = ZERO; i < u_length; i++)
  {
    f_output[i] = exp_approx(f_input[i] - f_min - (float32_t)lower_bound);
    f_sum += f_output[i];
  }

  /* Normalize the f_output array*/
  for (i = ZERO; i < u_length; i++)
  {
    f_output[i] /= f_sum;
  }
}

/**********************************************************************************************************************
 * Name:  exp_moving_avg
 * DD-ID: 
 * Req.-ID: 17597432
 *********************************************************************************************************************/
float32_t exp_moving_avg(const float32_t f_prevX, const float32_t f_currX, const float32_t f_alpha)
{
  return (f_alpha * f_prevX) + ((1.0f - f_alpha) * f_currX);
}

