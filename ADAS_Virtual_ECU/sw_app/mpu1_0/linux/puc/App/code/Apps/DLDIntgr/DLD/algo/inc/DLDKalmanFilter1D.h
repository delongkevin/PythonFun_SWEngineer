/// --------------------------------------------------------------------------
/// @file DLDKalmanFilter1D.h
/// @brief Contains implementation for 1D Kalrman Filter
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Abdulrahman Elgendy
/// @author Winnie Trandinh
/// --------------------------------------------------------------------------

#ifndef DLD_Kalman_Filter_1D_H
#define DLD_Kalman_Filter_1D_H

#include "mecl/mecl.h"
namespace kalman
{
class DLD_Kalman_Filter_1D
{
public:
		DLD_Kalman_Filter_1D(float32_t i_error_in_measurement, float32_t i_init_error_in_estimate, float32_t i_initial_estimate);
		~DLD_Kalman_Filter_1D();
		bool_t is_filter_ready() const;
		void gather_initial_measurements(float32_t occ_confidence);
		void update_measurements_array(float32_t occ_confidence);
		void reset_measurements();
		float32_t kalman_process();

	private:
		void update_parameters(float32_t kalman_gain, float32_t new_estimate);
		float32_t get_filter_estimate(float32_t occ_confidence);
		void reset_kalman_filter_params(float32_t estimate_for_first_measurement);
		float32_t calculate_kalman_gain() const;

	    float32_t init_error_in_estimate;	    
		float32_t error_in_measurement;
	    float32_t error_in_estimate;
	    float32_t previous_estimate;
	    int32_t num_of_data_pts_available;

	    static const int32_t num_of_iterations = 5;
	    float32_t occ_confidence_buffer[num_of_iterations] = {};
	};
} // namespace kalman
#endif // DLD_Kalman_Filter_1D_H