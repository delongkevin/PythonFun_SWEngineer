// ----------------------------------------------------------------------------
// --- Written by Abdulrahman Elgendy [26-Mar-2021]
// --- Last Updated by Winnie Trandinh [20-Oct-2021]
// --- Copyright (c) Magna Vectrics (MEVC) 2020
// ----------------------------------------------------------------------------

#ifndef KalmanFilter1D_H
#define KalmanFilter1D_H

#ifdef _WIN32
    #include <MECL/mecl.h>
#else
    #include "mecl/mecl.h"
#endif // _WIN32

namespace tha
{
    class Kalman_Filter_1D
    {
    public:
        Kalman_Filter_1D( float32_t i_error_in_measurement,
                          float32_t i_initial_error_in_estimate,
                          float32_t i_initial_estimate );

        ~Kalman_Filter_1D( void );
        bool_t is_filter_ready() const;
        void gather_initial_measurements( float32_t confidence );
        void update_measurements_array( float32_t confidence );
        void reset_measurements();
        float32_t kalman_process();

    private:
        void update_parameters( float32_t kalman_gain,
                                float32_t new_estimate );

        float32_t get_filter_estimate( float32_t confidence );
        void reset_kalman_filter_params( float32_t estimate_for_first_measurement );
        float32_t calculate_kalman_gain() const;
        float32_t error_in_measurement;
        float32_t error_in_estimate;
        float32_t init_error_in_estimate;
        float32_t previous_estimate;
        uint8_t num_of_data_pts_available;
        float32_t Data_buffer[5] = {};
        const uint8_t num_of_iterations = 5;
    };
} // namespace tha
#endif //KalmanFilter1D_H