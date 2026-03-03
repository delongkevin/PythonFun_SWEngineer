#ifndef US_MGR_MATH_H
#define US_MGR_MATH_H

#define TANH_UPPER_XLIMIT          (7.0f)
#define TANH_LOWER_XLIMIT          (-7.0f)
#define TANH_UPPER_Y_LIMIT         (1.0f)
#define TANH_LOWER_Y_LIMIT         (-1.0f)
#define SIGMOID_LOWER_Y_LIMIT      (0.0f)
#define SIGMOID_UPPER_Y_LIMIT      (1.0f)
#define SIGMOID_LOWER_X_LIMIT      (-7.0f)
#define SIGMOID_UPPER_X_LIMIT      (7.0f)
#define EXP_SMALL_X_LIMIT          (1.5f)
#define EXP_SMALL_X_TERMS          (10u)
#define EXP_MODERATE_X_LIMIT       (3.0f)
#define EXP_MODERATE_X_TERMS       (20u)
#define EXP_MID_X_LIMIT            (7.0f)
#define EXP_MID_X_TERMS            (30u)
#define EXP_LARGE_X_LIMIT          (10.0f)
#define EXP_LARGE_X_TERMS          (40u)
#define EXP_VERY_LARGE_X_TERMS     (50u)


float32_t f_tanh(const float32_t f_x);
float32_t f_sigmoid(const float32_t f_x);
float32_t LEAKY_RELU(const float32_t x,  const float32_t slope);
bool_t Sum_Filter(const uint8_t* uBuffer, const uint8_t u_Buffer_size, const uint8_t u_sumFilterSize, const uint8_t uStartIdx);
float32_t Window_Filter(const uint8_t* uBuffer, const uint8_t u_Buffer_size, const uint8_t u_avgFilterSize, const uint8_t uStartIdx);
uint8_t u_argMax(const float32_t *f_array, const uint8_t size);
void f_softMax(const float32_t* f_input, float32_t* f_output, const uint8_t u_length);
float32_t exp_moving_avg(const float32_t f_prevX, const float32_t f_currX, const float32_t f_alpha) ;
#endif
