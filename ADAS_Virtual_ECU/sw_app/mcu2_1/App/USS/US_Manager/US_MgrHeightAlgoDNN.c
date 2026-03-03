#include "US_ME_Typedefs_Global.h"
#include "US_MgrHeightAlgo.h"
#include "US_SysMgr_Global.h"

#if (US_D_HEIGHT_ALGO_TYPE_TO_USE == HEIGHT_ALGO_DNN)
const float32_t f_height_algo_hidden_weights_noise[20u][HEIGHT_ALGO_NUM_INPUTS_NOISE*HEIGHT_ALGO_NUM_SENSORS] = { 
         {-1.2103e+00, -9.0409e-02,  9.6303e-02,  1.3768e-01, -9.9823e-02,
          4.2535e-01, -6.5573e-01,  4.7215e-02,  7.5093e-02,  2.0920e-01,
          9.4220e-02, -4.8974e-01, -5.1957e-01, -1.9965e-02, -8.7258e-03,
         -1.6327e-01,  4.3873e-02, -1.3631e+00, -9.5188e-01,  6.5700e-01,
         -1.6741e-01, -6.7732e-02, -6.6291e-02, -2.3439e-01},
        { 3.5243e-01,  4.2240e-01,  4.2778e-03, -1.0539e-01,  9.7878e-05,
          2.3257e-01, -4.2254e-01, -4.0291e-01,  2.8324e-01,  4.0549e-04,
         -1.4534e-02, -3.5684e-02,  2.2196e-01,  8.3140e-02,  6.2568e-03,
         -6.1850e-02, -1.0434e-03,  1.3270e-01, -2.8751e-01,  3.6691e-01,
          7.5328e-02, -1.7347e-01,  4.9370e-02, -3.0897e-01},
        { 1.4002e-01, -5.0475e-01,  3.1500e-01,  8.7116e-02, -8.5461e-02,
          2.0337e-01, -2.5715e-01, -2.4955e-01,  5.8258e-02, -2.1328e-01,
          1.5635e-01, -9.4321e-01,  8.0383e-03,  1.6016e-01,  1.1343e-01,
         -3.9506e-02, -2.2800e-03, -3.6445e-01,  1.9051e+00, -1.0277e+00,
          1.8311e-01, -9.1299e-02,  1.8028e-02,  1.0256e+00},
        {-1.2991e-01,  1.2537e-01, -8.3981e-02, -1.3716e-02, -4.1604e-02,
          1.9135e-01,  3.9560e-01, -8.3764e-02, -1.7207e-01, -3.3572e-01,
          1.3933e-01, -1.1039e+00,  3.0294e-01, -3.5543e-02,  7.8509e-02,
          1.5671e-01, -8.7404e-03, -7.4577e-01,  1.8796e-01, -5.1686e-01,
          7.1818e-02,  1.3520e-01, -6.7270e-02,  5.8712e-02},
        {-6.1511e-01, -3.4906e-01,  1.2945e-01, -4.0048e-01, -6.1168e-02,
          2.6847e-01, -2.2688e-01, -8.0580e-02, -1.6632e-02, -1.8055e-01,
         -1.0658e-01,  2.9088e-01,  1.3047e-02,  2.2538e-01,  1.4468e-01,
          8.8638e-02,  3.6191e-02, -7.5344e-01,  2.7278e-01,  1.4718e-01,
         -5.1664e-02, -3.2774e-01, -6.8047e-02, -7.1335e-01},
        { 5.5086e-01,  5.1815e-01,  2.2066e-01, -1.1601e-01, -4.0726e-02,
         -8.2069e-02, -1.7453e+00, -5.4644e-02,  3.3600e-01, -2.0038e-01,
          1.2752e-01,  3.1306e-01,  3.7260e-01,  1.5659e-01, -6.9890e-02,
          6.6375e-02, -1.0613e-01,  4.9659e-01, -1.6242e+00, -1.7794e-01,
          1.8880e-01, -2.3829e-01,  8.4020e-02,  1.0264e-01},
        { 6.6666e-01, -3.0835e-01, -7.3438e-02,  1.1364e-01,  2.7469e-02,
         -1.2766e-01,  6.7542e-01, -8.1744e-01,  2.2540e-02, -3.2163e-01,
          1.3256e-01, -5.0774e-02,  1.5480e-01,  1.7321e-01, -1.6938e-03,
         -3.0603e-01,  1.0837e-01,  2.6076e-01, -1.2840e-01, -3.3586e-01,
          4.3004e-02, -1.3031e-03,  9.8000e-03,  8.0833e-01},
        { 2.5734e-02, -2.0785e-01, -2.1624e-01,  1.6132e-01,  4.9890e-02,
         -7.5987e-01, -3.3666e-01,  4.5781e-03, -2.8617e-01, -1.6007e-01,
          1.0647e-01,  1.5498e-01,  6.8908e-02,  1.4166e-01,  2.7663e-02,
         -1.9853e-01,  1.2620e-01,  3.2347e-01,  4.9047e-02, -5.1403e-02,
         -3.2008e-03, -2.5749e-02, -1.8318e-03,  1.1598e-01},
        {-1.9006e-02,  3.3177e-01,  1.1689e-02, -4.9495e-02, -6.0461e-02,
         -6.5392e-01, -1.0060e+00,  6.1889e-02,  2.2665e-02, -6.7651e-02,
          2.2822e-02,  1.3239e-01, -9.7681e-02, -1.0046e-01, -1.3322e-02,
         -5.2855e-02, -3.3157e-02, -1.0961e-01, -1.7504e+00,  4.0552e-01,
         -2.8832e-02,  4.9685e-02,  2.8318e-02,  2.2471e-01},
        {-1.5129e-01,  2.9152e-01, -8.2907e-02, -7.3396e-02, -1.5608e-01,
         -1.0004e+00, -1.5814e-01,  1.5814e-02,  3.1506e-02, -9.2990e-02,
          6.0384e-02,  9.1276e-01, -2.3054e-01, -2.6870e-02, -1.8040e-02,
         -2.4124e-01,  7.8574e-02,  1.5156e+00,  5.0202e-01,  2.9266e-01,
         -8.3392e-02, -3.3664e-02, -1.2554e-01, -6.7745e-01},
        {-1.6749e+00,  3.4449e-02, -2.7385e-02,  1.2864e-02, -1.4562e-03,
         -2.2782e-01,  1.4127e-01,  3.0951e-02, -6.8398e-03,  7.6451e-02,
          8.1972e-03, -3.0449e-01, -3.4200e-02,  1.8473e-02, -9.1719e-03,
         -5.1873e-02,  2.0377e-03,  1.2990e-01, -1.2746e+00, -2.5596e-02,
         -1.6841e-02,  5.4427e-02,  2.9238e-02,  4.9020e-01},
        { 1.3910e-01,  5.8621e-02, -1.6876e-01, -2.4293e-01, -2.0317e-02,
          3.3547e-01, -1.0432e-02,  1.3069e-02,  1.1726e-01,  3.0518e-01,
          2.1812e-01,  1.3162e+00, -5.1530e-01,  8.4482e-02,  1.4671e-01,
         -9.4377e-02, -1.1091e-01, -1.3764e-01, -2.4698e-01, -2.2375e-01,
         -1.6295e-01, -3.1655e-01, -2.6365e-01, -7.3129e-02},
        { 9.0340e-01,  5.3632e-01,  3.5582e-03, -1.8835e-01, -5.4537e-02,
          5.7042e-01,  7.0876e-01, -7.7353e-02, -2.0113e-02, -1.2499e-01,
         -5.0274e-02,  8.9499e-01,  5.3685e-01,  7.1493e-02, -2.8953e-02,
         -2.9064e-01, -4.4492e-02,  5.9012e-01, -6.3373e-01,  5.2958e-01,
         -1.2383e-01,  3.3191e-01,  1.0289e-01,  2.3075e+00},
        { 4.5113e-01,  1.7119e-01,  1.6422e-01, -2.1181e-01, -7.2644e-03,
          2.8427e-01, -9.9143e-01,  1.7266e-03, -5.3699e-03, -3.2113e-01,
         -8.7919e-03,  3.8206e-01, -2.6877e-01, -2.6131e-02, -5.5336e-01,
         -9.1736e-02, -7.5255e-02,  1.1633e-01, -6.4288e-02, -4.0544e-01,
         -7.8151e-01,  8.3447e-02,  1.2140e-02,  1.9148e-02},
        { 1.4359e-01,  9.3889e-02, -7.3262e-03,  2.0814e-02,  1.6302e-03,
          1.9326e-01, -3.2690e-01, -2.8570e-01, -3.9487e-01, -4.3987e-01,
          1.6344e-01,  3.9953e-01,  3.5231e-01, -4.3333e-02,  4.1679e-02,
         -1.7054e-01,  3.2684e-02,  5.9452e-02, -3.3135e-01, -3.5253e-01,
          7.2511e-02,  4.1838e-02, -5.6112e-02, -3.7217e-01},
        {-1.0430e-01, -2.1493e-01, -3.2292e-01, -7.2097e-03, -2.3956e-03,
          1.5991e-02, -2.3036e-01, -8.7013e-02, -3.8160e-01, -1.9282e-01,
          7.3098e-02, -2.2622e-01, -6.6030e-01,  1.0932e-01, -6.0423e-02,
          7.6273e-02,  6.1087e-02,  4.2043e-01,  6.6445e-01, -7.5881e-03,
          8.0819e-02,  1.0077e-01, -1.2327e-02, -8.4446e-01},
        { 9.0119e-02,  1.4436e-01, -1.3185e-01, -2.0085e-01, -6.0481e-03,
         -6.9635e-02,  9.3705e-02,  6.5100e-05,  9.9419e-02,  2.5385e-01,
          1.4505e-01,  1.3192e+00, -5.4241e-01,  3.5800e-02,  9.7926e-02,
         -1.5093e-01, -7.3107e-02,  5.6908e-01,  1.4982e-01, -1.9594e-02,
         -1.4176e-01, -2.3187e-01, -1.8152e-01,  4.7306e-02},
        {-8.7384e-01,  4.2893e-02, -1.4969e-01,  9.2864e-02,  8.7628e-03,
         -1.2770e-01, -5.4986e-01, -3.8341e-02, -7.3944e-03,  1.8935e-01,
         -5.5091e-02,  5.0417e-01, -2.0074e-02, -4.8218e-02,  2.2224e-04,
          2.7907e-01,  2.2756e-01,  1.5325e+00,  3.9511e-03,  2.2082e-02,
          1.1358e-03, -3.3346e-03,  6.5586e-03,  2.6830e-01},
        {-1.2198e+00,  1.0582e-02, -1.2247e-01,  7.8598e-02,  6.5579e-03,
         -1.9142e-01, -3.2957e-01,  1.6619e-02,  4.4281e-03,  2.1365e-01,
         -3.6312e-02,  2.8163e-01, -7.8460e-02,  2.1613e-02,  6.9062e-03,
          1.5249e-01,  1.4873e-01,  1.6883e+00,  4.1951e-01,  6.9228e-02,
          5.8179e-03, -2.0889e-02,  3.1036e-03,  2.9381e-01},
        {-7.6176e-01, -2.6631e-01,  1.4219e-01, -4.0648e-01, -8.6739e-02,
         -2.9907e-01, -5.3299e-02, -1.2630e-01, -4.6800e-02, -2.2968e-01,
         -1.8865e-01,  5.2431e-02,  1.0182e-02,  1.1873e-02,  2.5753e-01,
         -2.9849e-01,  6.9824e-02,  1.3862e+00, -4.9759e-01,  1.6120e-01,
         -1.9655e-01, -2.5679e-01, -6.0711e-02,  4.2616e-01}};

const float32_t f_height_algo_biases_noise[HEIGHT_ALGO_NUM_SENSORS*5U] = {
         1.2351,  0.2760, -1.1915,  0.5873, -0.6978, -0.6290,  2.2769, -0.7865,
         2.5039, -0.8497,  5.2325,  0.7235, -0.8829,  1.0870, -1.0291, -0.8106,
        -2.7945,  0.6912, -3.6135,  2.2093};

const float32_t f_height_algo_weight_noise[HEIGHT_ALGO_NUM_SENSORS*5U] = {
         0.1366, -0.2280, -0.0969,  0.3082,  0.1822,  0.1518,  0.4286, -0.1943,
         -0.2100, -0.1164, -0.6072, -0.3731,  0.1787, -0.1234, -0.2384, -0.2439,
          0.5019, -0.3581,  0.6015, -0.1295};

const float32_t f_height_algo_output_bias_noise = -2.3204;

const float32_t f_height_algo_hidden_weights[20u][HEIGHT_ALGO_NUM_INPUTS*HEIGHT_ALGO_NUM_SENSORS] = { 
       { 6.6030e-03,  1.5239e-01,  7.7089e-03,  1.7153e-03,  1.4955e-01,
          2.1253e-01, -2.1626e-01,  1.6053e-01,  2.3923e-01,  2.3142e-02,
          1.3169e-01,  6.1628e-03, -8.1653e-03, -2.2446e-02,  7.0445e-02,
         -3.0090e-02,  1.2180e-01, -3.3918e-02,  7.0520e-02, -1.0706e-02,
         -1.3785e-02, -3.8336e-02, -1.0224e-01,  1.0588e-01, -1.5784e-01,
          1.4379e-01,  2.4369e-02, -5.4750e-02},
        { 3.5300e-02, -7.4010e-02,  6.8222e-02, -1.0706e-02, -1.8237e-01,
          3.3586e-02, -2.0177e-02,  1.3764e-02,  3.8744e-02, -3.8278e-02,
         -5.8621e-03, -9.2823e-02, -6.2145e-03, -8.4304e-02,  7.2798e-03,
         -1.4792e-01,  5.4332e-02,  1.8313e-02,  4.0930e-02, -1.5783e-02,
          7.4144e-02,  3.9292e-03, -2.4016e-01,  6.8108e-02,  1.3220e-02,
         -8.3203e-02, -8.4571e-04,  1.1675e-01},
        { 6.7761e-02,  1.9513e-01, -3.5650e-02,  2.1454e-02, -1.4030e-01,
         -2.6950e-02,  1.4520e-01,  6.4016e-03, -1.1201e-01, -7.3076e-02,
          2.9858e-02,  2.5892e-01, -1.3544e-01, -4.7681e-02, -8.3824e-05,
         -2.2322e-01,  5.1559e-01, -8.8027e-02,  6.0980e-01, -1.8285e-01,
         -1.3406e-02,  2.1419e-02,  5.2395e-01, -1.0326e-01, -8.8232e-03,
         -1.1902e-01, -1.3669e-02, -6.8788e-02},
        { 8.2965e-02, -1.9119e-01,  9.9575e-02, -1.0396e-02, -1.2390e-01,
         -3.0186e-02, -3.2132e-03,  6.0805e-03,  2.5982e-01, -5.1626e-02,
         -9.4969e-02, -1.4200e-01,  7.2741e-02, -2.0770e-02,  1.1122e-02,
         -8.6437e-02,  6.5552e-02,  7.1140e-02,  1.8871e-01,  1.1300e-02,
          6.5891e-02,  1.6505e-03, -2.0037e-01,  3.2653e-02,  6.2254e-03,
         -6.8898e-02,  7.2291e-02,  3.5046e-02},
        { 1.4049e-03, -5.9735e-01, -2.2935e-01,  3.3265e-02, -2.9668e-01,
         -4.3324e-01, -2.1412e-01,  8.1913e-03, -3.9935e-01, -1.8511e-02,
          5.4804e-02, -1.5340e-01, -5.2810e-02, -2.4298e-02, -2.7033e-03,
          9.0360e-02,  6.9498e-02, -9.9842e-03,  1.6002e-01, -1.9950e-02,
         -1.8653e-02,  2.4263e-02, -1.5966e-01, -1.6910e-02,  1.5150e-02,
         -2.2520e-01,  5.7558e-02, -3.4431e-02},
        { 1.1809e-01,  2.6149e-01, -1.1148e-02, -5.3720e-02, -5.3521e-01,
          1.3503e-01, -2.1832e-02,  2.7207e-02, -1.1167e-01, -3.9345e-02,
          1.7961e-01, -4.4390e-01, -6.3972e-02, -6.4603e-02,  5.1241e-02,
         -4.6337e-01,  2.9145e-01,  9.2680e-02,  3.6849e-02,  1.0250e-02,
          5.3012e-02,  2.0729e-02, -1.3434e-01, -2.2531e-01,  3.8366e-02,
         -5.2495e-01, -8.3068e-03,  9.4086e-02},
        { 8.7576e-03,  1.4856e-01, -6.6963e-02,  3.0713e-03,  1.3572e-02,
          1.5932e-02, -2.8482e-02,  1.1193e-02, -8.9535e-02,  2.1001e-02,
          2.3547e-03, -1.6348e-01,  1.1965e-01,  1.3488e-03,  1.3884e-02,
         -4.2039e-02,  6.5082e-03, -4.8051e-03,  1.1575e-01, -5.9966e-02,
         -2.5590e-02, -1.9489e-02, -6.7846e-02,  3.9799e-02, -1.6696e-02,
         -7.4764e-02,  8.0021e-02, -1.5918e-02},
        {-4.3579e-02, -2.8076e-01,  2.1761e-02,  1.2297e-02, -2.4459e-02,
         -4.8200e-02,  1.5919e-01, -9.4323e-03,  7.4886e-01, -5.0531e-01,
          5.6288e-02,  2.0743e-01, -4.0056e-01, -4.6290e-02,  1.7485e-02,
          2.7792e-01, -2.7975e-01, -1.4853e-01, -2.8129e-01,  7.6503e-03,
         -1.4136e-01,  1.5055e-02, -3.1601e-01,  1.9930e-01, -1.9290e-01,
         -3.1139e-02,  2.7185e-02, -9.4689e-02},
        { 3.8131e-03,  8.1046e-02,  1.1140e-01, -8.9284e-03,  1.2573e-01,
          3.2717e-02, -2.0582e-01,  1.4183e-01,  3.6888e-01, -4.5970e-02,
          1.5127e-01,  1.7747e-01, -2.1799e-01, -4.3057e-02,  4.7876e-02,
         -1.0731e-01,  2.3616e-01, -3.3658e-02, -1.5302e-01,  1.8210e-01,
         -9.3284e-03, -5.3399e-03, -2.0577e-01,  8.3457e-02, -1.4494e-01,
          2.6436e-01, -7.3035e-02, -6.4997e-02},
        { 2.5718e-01,  7.8671e-01, -2.0156e-01, -4.2999e-03,  2.2012e-01,
         -9.6446e-02,  6.9612e-02,  1.9092e-02,  4.6384e-01, -2.5375e-02,
          7.1545e-02,  8.8406e-01, -1.4703e-01, -2.1058e-02,  1.4747e-02,
          2.8446e-01,  3.2210e-01, -4.2291e-01,  2.7693e-01, -1.8614e-01,
          8.5546e-02,  8.4523e-02,  1.0604e+00, -2.8996e-01, -8.9677e-02,
          1.8579e-03,  5.2091e-05, -7.4197e-02},
        {-9.9931e-03, -3.5005e-01, -4.0021e-02,  3.3997e-02, -3.1784e-01,
          9.8086e-02, -1.6864e-03, -1.0346e-01,  3.0203e-01,  2.1178e-01,
         -1.0855e-01, -6.4845e-03, -2.0829e-01, -1.8424e-01,  5.9485e-02,
          8.8454e-02, -1.9999e-01,  9.0775e-03, -1.3658e-01, -6.0420e-02,
          9.7768e-02, -6.7725e-02, -9.1999e-01,  4.8416e-01, -1.1664e-01,
          4.6661e-02, -1.7112e-01,  8.7524e-02},
        {-3.8848e-02, -5.8895e-01,  1.0651e-01,  1.8908e-02, -7.8477e-03,
         -1.0139e-01,  1.3847e-01,  4.1302e-04,  5.1853e-01, -2.9115e-01,
          2.0702e-02, -1.7415e-01, -1.9655e-01, -4.2030e-02,  1.7671e-02,
          1.8436e-01, -2.1623e-01, -1.1764e-01, -3.2112e-02, -1.4457e-01,
         -1.4133e-01, -1.2831e-02,  3.3256e-01,  1.6922e-02, -1.7538e-01,
         -2.4343e-01,  5.2151e-02, -8.3537e-02},
        { 3.6535e-02,  3.0437e-01, -2.5534e-01,  2.4593e-02,  1.8238e-01,
         -1.2063e-01, -4.6088e-02, -1.4341e-02,  5.8357e-02, -4.6460e-02,
         -7.1435e-03,  3.8780e-01, -1.3436e-01,  7.1729e-02, -5.3072e-03,
         -6.7559e-02,  8.6975e-02, -8.8648e-03, -4.7307e-02,  3.6186e-02,
          1.7831e-01, -6.8373e-02, -4.3619e-01,  1.3894e-01,  4.1353e-02,
         -1.3562e-02, -3.6591e-02, -4.6595e-02},
        { 4.5893e-03,  1.0603e-01, -7.3431e-02,  5.9004e-03,  9.0378e-03,
         -6.7182e-03,  1.9707e-05, -2.8549e-02,  8.6160e-02,  2.2716e-02,
         -5.3173e-03,  3.2630e-02, -6.0152e-02,  5.4818e-04,  5.7275e-03,
          1.8856e-01, -6.9813e-02,  2.5393e-03,  7.1246e-02, -8.6449e-02,
          1.5197e-03, -6.5344e-02,  6.9809e-02, -3.6470e-02,  6.3988e-03,
          9.6822e-03, -1.3535e-02, -1.5514e-03},
        { 9.5531e-03, -8.5590e-02,  1.0624e-01, -2.5588e-02, -9.3716e-02,
          6.7732e-02,  7.5731e-03,  2.6257e-02,  3.2797e-02,  1.1662e-01,
         -1.4055e-02,  2.0304e-02,  6.3266e-02, -2.0118e-01,  2.6353e-03,
         -1.4194e-01, -1.3073e-01,  2.3107e-02, -2.2279e-01, -2.1742e-02,
          1.7013e-01, -5.4617e-02,  5.9795e-02, -1.2867e-01,  2.4709e-02,
         -8.0180e-02, -2.0794e-02, -6.7227e-02},
        { 5.4508e-03,  1.4948e-01, -1.6041e-01, -5.0914e-03,  1.8745e-01,
         -1.1439e-01, -1.9578e-02, -2.8688e-02,  1.7392e-01,  2.5070e-02,
          2.8321e-02,  2.8102e-01, -2.3912e-01,  3.0175e-02,  2.8076e-03,
          4.8628e-02,  7.0489e-03,  4.1784e-02, -4.6698e-02,  3.4018e-02,
         -1.1392e-01,  1.8643e-02, -9.8492e-02, -4.4702e-02,  4.0837e-02,
          6.9664e-02,  1.0681e-02,  2.0265e-01},
        { 1.2768e-02, -5.7613e-02,  3.2530e-02, -9.5084e-03, -1.6420e-01,
          1.1746e-01,  3.8664e-02, -4.5115e-04,  2.4057e-01, -4.8492e-02,
         -3.1996e-02,  8.7441e-03, -7.6818e-03,  1.0282e-02,  2.3850e-03,
         -3.8736e-01,  4.6788e-02, -3.5613e-02, -1.2461e-01, -1.0703e-01,
          8.6247e-02,  1.3186e-02, -7.1889e-01,  2.4369e-01,  1.6579e-01,
         -4.0005e-02, -4.0681e-02,  3.8920e-02},
        {-1.8460e-02, -2.9236e-01,  9.2892e-02, -4.0833e-03, -1.1799e-01,
          5.9286e-02, -8.1149e-03,  3.1366e-02, -4.9011e-02,  2.4457e-02,
         -1.1232e-02,  1.8783e-01, -2.5221e-02,  7.7151e-02, -3.6474e-03,
          9.3253e-02,  4.0021e-02, -3.3559e-02, -2.1366e-02,  3.4027e-02,
          3.4242e-02,  5.6222e-02,  1.8230e-01, -1.6802e-02,  1.4889e-02,
          2.7957e-02,  1.4121e-01,  6.6048e-02},
        {-9.4732e-03,  2.1057e-01,  5.3520e-02, -1.5652e-02, -5.9174e-02,
          2.8462e-02,  6.6324e-03,  1.4401e-02, -3.5005e-01,  1.1985e-01,
         -5.8952e-04,  6.4807e-02,  1.4237e-01, -8.8156e-02, -2.4463e-03,
         -1.4853e-01,  7.2883e-02, -7.1247e-03, -5.6149e-02,  8.5066e-02,
          1.2114e-01, -1.4055e-01,  2.2845e-01, -8.6817e-02, -1.8231e-02,
         -1.3469e-01,  4.2836e-02, -1.2147e-01},
        {-7.2923e-02, -1.2989e-02,  4.7080e-02, -1.4987e-03,  7.7311e-02,
         -3.1068e-03,  3.3053e-03,  5.0624e-02, -1.2670e-01,  1.1597e-01,
         -4.0560e-03,  1.4406e-01,  6.3030e-02,  9.8137e-02, -9.1469e-04,
          2.5356e-03,  1.8614e-01, -7.6985e-02,  6.6682e-02,  8.2166e-02,
          8.4959e-03,  7.0829e-02, -2.0482e-01,  2.5853e-01, -1.4486e-02,
          1.1499e-01,  3.4831e-01,  1.7245e-01}};

const float32_t f_height_algo_biases[HEIGHT_ALGO_NUM_SENSORS*5U] = {
        3.3430, -1.4165, -2.3596,  2.0529,  1.7895,  2.0049, -5.2697,  1.0418,
        -5.3762,  2.7724,  0.2301, -0.1541, -0.4907,  6.4011, -2.7464,  1.4067,
         1.3443, -3.4685,  2.7550,  1.7697};
const float32_t f_height_algo__weight[HEIGHT_ALGO_NUM_SENSORS*5U] = {
        0.1233, -0.1569, -0.0648,  0.0936,  0.0462,  0.0508, -0.3635, -0.1394,
         -0.1219,  0.0345,  0.0817,  0.1772, -0.0914, -1.0102, -0.1252, -0.0697,
          0.0941, -0.1692,  0.1106,  0.1091};
const float32_t f_height_algo_output_bias = 3.5102;
#define FILTER_SIZE 20
static uint8_t u_HeightFiltered[FILTER_SIZE]={ME_FALSE};
static uint8_t u_HeightFilterIdx=0;
bool_t b_globHeightFlag = ME_FALSE;
bool_t b_globHeightFlagFiltered=ME_FALSE;
bool_t b_NoiseDNNActive = ME_FALSE;

static void height_estimation_dnn(bool_t *isHigh,
                                  const US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS]);
static void height_estimation_dnn_noise(bool_t *isHigh,
                                  const US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS]);
                                  
static uint8_t Height_Algo_DNN_Input(const US_S_SensorRec_t * sOneSensorRec,                            
                           US_S_SnrCalcRec_t * sOneSensorCalcs,
                           US_S_HeightAlgoInput_t* sHeightInput);
static void Height_Output_Filter(bool_t bIsHigh_Return);
static float32_t f_sigmoid(float32_t f_x);
/*Approximation: 1/2 + 1/4x + 1/48x^3*/
float32_t f_sigmoid(float32_t f_x)
{
    float32_t f_sig;

    f_sig = 0.5f + (0.25f * f_x) ;
    return f_sig;
}

/*
Normal Mode input
# "ROL_dist3", "ROL_w2", "ROL_h2", "ROL_dist2", "ROL_w1", "ROL_h1", "ROL_dist1",
# "RIL_dist3", "RIL_w2", "RIL_h2", "RIL_dist2", "RIL_w1", "RIL_h1", "RIL_dist1",
# "RIR_dist3", "RIR_w2", "RIR_h2", "RIR_dist2", "RIR_w1", "RIR_h1", "RIR_dist1",
# "ROR_dist3", "ROR_w2", "ROR_h2", "ROR_dist2", "ROR_w1", "ROR_h1", "ROR_dist1"
*/

void height_estimation_dnn(bool_t *isHigh,
                           const US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS])
{
    uint8_t u_snrIdx;
    uint8_t u_widx;
    float32_t f_x=0.0f;
    float32_t f_sum[20];
    
    /*dot matrix multiplication of weights and inputs*/    
    for(u_widx=0; u_widx <20u; u_widx++)
    {
        for(u_snrIdx=0; u_snrIdx < HEIGHT_ALGO_NUM_SENSORS; u_snrIdx++)
        {
            
            f_x+= ((float32_t)sHeightInput[u_snrIdx].sDist3)*f_height_algo_hidden_weights[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS)];
            f_x+= ((float32_t)sHeightInput[u_snrIdx].uWidth2)*f_height_algo_hidden_weights[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS) + 1u];
            f_x+= ((float32_t)sHeightInput[u_snrIdx].fHeight2)*f_height_algo_hidden_weights[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS) + 2u];
            f_x+= ((float32_t)sHeightInput[u_snrIdx].sDist2)*f_height_algo_hidden_weights[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS) + 3u];
            f_x+= ((float32_t)sHeightInput[u_snrIdx].uWidth1)*f_height_algo_hidden_weights[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS) + 4u];
            f_x+= ((float32_t)sHeightInput[u_snrIdx].fHeight1)*f_height_algo_hidden_weights[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS) + 5u];
            f_x+= ((float32_t)sHeightInput[u_snrIdx].sDist1)*f_height_algo_hidden_weights[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS) + 6u];
            
        }
        f_sum[u_widx] = f_x + f_height_algo_biases[u_widx];        
        f_x = 0.0f;
        if(f_sum[u_widx] < 0)
        {
            f_sum[u_widx] =0;
        }
    }    

    f_x=0.0f;
    for(u_snrIdx=0; u_snrIdx < 20u; u_snrIdx++)
    {
        f_x+= f_sum[u_snrIdx]*f_height_algo__weight[u_snrIdx];
    }

    f_x += f_height_algo_output_bias;    
    f_x = f_sigmoid(f_x);

    if(f_x >0.5f)
    {
        *isHigh = ME_TRUE;
    }
    else{
        *isHigh = ME_FALSE;
    }
   
}
   
   /*Noise mode input:
# "ROL_h3", "ROL_h2", "ROL_dist2", "ROL_h1", "ROL_dist1", "ROL_conf1",
# "RIL_h3", "RIL_h2", "RIL_dist2", "RIL_h1", "RIL_dist1", "RIL_conf1",
# "RIR_h3", "RIR_h2", "RIR_dist2", "RIR_h1", "RIR_dist1", "RIR_conf1",
# "ROR_h3", "ROR_h2", "ROR_dist2", "ROR_h1", "ROR_dist1", "ROR_conf1",*/
void height_estimation_dnn_noise(bool_t *isHigh,
                           const US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS])
{
    uint8_t u_snrIdx;
    uint8_t u_widx;
    float32_t f_x=0.0f;
    float32_t f_sum[20];

    /*dot matrix multiplication of weights and inputs*/
    
    for(u_widx=0; u_widx <20u; u_widx++)
    {
        for(u_snrIdx=0; u_snrIdx < HEIGHT_ALGO_NUM_SENSORS; u_snrIdx++)
        {
            
            f_x+= ((float32_t)sHeightInput[u_snrIdx].fHeight3)*f_height_algo_hidden_weights_noise[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS_NOISE)];
            f_x+= ((float32_t)sHeightInput[u_snrIdx].fHeight2)*f_height_algo_hidden_weights_noise[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS_NOISE) + 1u];
            f_x+= ((float32_t)sHeightInput[u_snrIdx].sDist2)*f_height_algo_hidden_weights_noise[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS_NOISE) + 2u];            
            f_x+= ((float32_t)sHeightInput[u_snrIdx].fHeight1)*f_height_algo_hidden_weights_noise[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS_NOISE) + 3u];
            f_x+= ((float32_t)sHeightInput[u_snrIdx].sDist1)*f_height_algo_hidden_weights_noise[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS_NOISE) + 4u];
            f_x+= ((float32_t)sHeightInput[u_snrIdx].uConf1)*f_height_algo_hidden_weights_noise[u_widx][(u_snrIdx * HEIGHT_ALGO_NUM_INPUTS_NOISE) + 5u];

        }
        f_sum[u_widx] = f_x + f_height_algo_biases_noise[u_widx];
		f_x = 0.0f;
        if(f_sum[u_widx] < 0)
        {
            f_sum[u_widx] =0;
        }
    }    

    f_x=0.0f;
    for(u_snrIdx=0; u_snrIdx < 20u; u_snrIdx++)
    {
        f_x+= f_sum[u_snrIdx]*f_height_algo_weight_noise[u_snrIdx];
    }

    f_x += f_height_algo_output_bias_noise;
    f_x = f_sigmoid(f_x);

    if(f_x >0.5f)
    {
        *isHigh = ME_TRUE;
    }
    else{
        *isHigh = ME_FALSE;
    }   
}

void Height_Output_Filter(bool_t bIsHighFlag)
{
    float32_t fSum;   
    uint8_t uIdx; 
        
    u_HeightFiltered[u_HeightFilterIdx]=(uint8_t)bIsHighFlag;    
    u_HeightFilterIdx++;

    if(u_HeightFilterIdx>=FILTER_SIZE)
    {
        u_HeightFilterIdx = 0;
    }
    fSum = 0.0f;
    
    for(uIdx=0;uIdx<(FILTER_SIZE);uIdx++)
    {
        fSum+=u_HeightFiltered[uIdx];        
    }
    fSum=fSum/(float32_t)FILTER_SIZE;
    if(fSum >=0.5f)
    {
        b_globHeightFlagFiltered = ME_TRUE;
    }
    else
    {
        b_globHeightFlagFiltered = ME_FALSE;
    }    
}

void Height_Algo_DNN(void)   
{
    bool_t bIsHigh_Return;
    uint8_t uSnrIdx;
    const US_S_SensorMeasRecs_t *psSnrMeasRec = UssMgr_psGetCurSensorMeasRec();
    US_S_SnrCalcs_t *psSnrCalcs = UssMgr_psGetCurSnrCalcsRec();
    const US_S_SensorRec_t  *psSensorRec;
    US_S_SnrCalcRec_t *psSnrCalcRec;
    US_S_HeightAlgoInput_t sHeightInput[HEIGHT_ALGO_NUM_SENSORS];
    uint8_t uInit = ME_OK;
    
    /*reset input values every time */   
    memset(&sHeightInput, 0u, HEIGHT_ALGO_NUM_SENSORS* sizeof(US_S_HeightAlgoInput_t) );
    
    /*ONLY 4 Rear sensors for the moment*/
    for (uSnrIdx = SEVEN; uSnrIdx < US_D_MAX_NUM_SENSORS - 1u; uSnrIdx++)     // Scan all sensor positions
    {
        psSensorRec = &psSnrMeasRec->sSensorRec[uSnrIdx];
        psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];           
        /*if no echoes are copied, ME_NOT_OK (1) will be returned*/                       
        uInit += Height_Algo_DNN_Input(psSensorRec, psSnrCalcRec, &sHeightInput[10u-uSnrIdx]);        
    }

    /*if at least a sensor contained echo information, the Init counter will be less
    than FOUR.
    If no sensor information was copied from any sensor, the Init counter will be FOUR
    and DNN state won't be updated including the Filtered output*/
    if(uInit < FOUR)
    {
        /*execute the DNN model and update the Filtered output ONLY if the
        Input data contains at least one valid measurement from a single sensor*/
        if( UssMgr_GetUsedNoiseMitMode(USSCOM_BUMPLOC_REAR) == US_NOISEMIT_NONE ) 
        {
            height_estimation_dnn(&bIsHigh_Return,sHeightInput);
            b_NoiseDNNActive = ME_FALSE;
        }
        else
        {
            height_estimation_dnn_noise(&bIsHigh_Return,sHeightInput);
            b_NoiseDNNActive = ME_TRUE;
        }
        Height_Output_Filter(bIsHigh_Return);
        b_globHeightFlag = bIsHigh_Return;
    }   

    //Save high/low status to echo data
    for (uSnrIdx = SIX; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)     // Scan all sensor positions
    {        
        psSnrCalcRec = &psSnrCalcs->sSnrCalcRec[uSnrIdx];
        psSnrCalcRec->sEchoCalc[ZERO].bLargeObject = b_globHeightFlagFiltered;                        
    }
    
}

uint8_t Height_Algo_DNN_Input(const US_S_SensorRec_t * sOneSensorRec,                            
                           US_S_SnrCalcRec_t * sOneSensorCalcs,
                           US_S_HeightAlgoInput_t* sHeightInput)
{
    float32_t f_height_scale = 1.0f;
    uint8_t u_retVal;

    if( UssMgr_GetUsedNoiseMitMode(USSCOM_BUMPLOC_REAR) == US_NOISEMIT_NONE ) 
    {
        f_height_scale = 1.0f;
    }
    else
    {
        /*scale the echo height only in Noise mode*/
        f_height_scale = 100.0f;
    }

    sHeightInput->echo1Idx = sOneSensorCalcs->sEchoCalc[ZERO].uRecEchoIndex;
    sHeightInput->echo2Idx = sOneSensorCalcs->sEchoCalc[ONE].uRecEchoIndex;
    sHeightInput->echo3Idx = sOneSensorCalcs->sEchoCalc[TWO].uRecEchoIndex;
    sHeightInput->numEchoes = sOneSensorCalcs->uNumEchoes;
    /* if echo is deleted, uRecEchoIndex goes out of bounds - big bug if not handled like this */        
    if( ( sOneSensorCalcs->sEchoCalc[ZERO].uRecEchoIndex < HEIGHT_ALGO_NUM_ECHOES)  &&//bound check
        ( sOneSensorCalcs->uNumEchoes > ZERO ) )
    {                
        sHeightInput->fHeight1 = (float32_t)sOneSensorRec->sEcho[sOneSensorCalcs->sEchoCalc[ZERO].uRecEchoIndex].uEchoHeight/f_height_scale;
        sHeightInput->uWidth1 = sOneSensorRec->sEcho[sOneSensorCalcs->sEchoCalc[ZERO].uRecEchoIndex].uWidth/10u;
        sHeightInput->uConf1 = sOneSensorRec->sEcho[sOneSensorCalcs->sEchoCalc[ZERO].uRecEchoIndex].uConf;
        u_retVal = ME_OK;
        if ( sOneSensorCalcs->eEchoClass == US_E_DIRECT )        
        {
            sHeightInput->sDist1 = sOneSensorCalcs->sEchoCalc[ZERO].uTotalDist_cm;        
        }
        else
        {
           sHeightInput->sDist1 =  ((sint16_t)sOneSensorCalcs->sEchoCalc[ZERO].uTotalDist_cm * -1);         
        }
        /*copy 2nd echo*/
        if( ( sOneSensorCalcs->sEchoCalc[ONE].uRecEchoIndex < HEIGHT_ALGO_NUM_ECHOES) &&//bound check
            ( sOneSensorCalcs->uNumEchoes > ONE ) )
        {        
            sHeightInput->fHeight2 = (float32_t)sOneSensorRec->sEcho[sOneSensorCalcs->sEchoCalc[ONE].uRecEchoIndex].uEchoHeight/f_height_scale;  
            sHeightInput->uWidth2 = sOneSensorRec->sEcho[sOneSensorCalcs->sEchoCalc[ONE].uRecEchoIndex].uWidth/10u;
            /*DNN was trained with positive 2nd echo distances*/
            sHeightInput->sDist2 = sOneSensorCalcs->sEchoCalc[ONE].uTotalDist_cm;                       
        }
        /*copy 3rd echo*/
        if( ( sOneSensorCalcs->sEchoCalc[TWO].uRecEchoIndex < HEIGHT_ALGO_NUM_ECHOES) &&//bound check
            ( sOneSensorCalcs->uNumEchoes > TWO ) )
        { 
            sHeightInput->sDist3 = sOneSensorCalcs->sEchoCalc[TWO].uTotalDist_cm;                       
            sHeightInput->fHeight3 = (float32_t)sOneSensorRec->sEcho[sOneSensorCalcs->sEchoCalc[TWO].uRecEchoIndex].uEchoHeight/f_height_scale;            
        }
    }
    else
    {            
        /*no echoes to be copied*/      
        u_retVal = ME_NOT_OK;
    }
    return u_retVal;
}
#endif