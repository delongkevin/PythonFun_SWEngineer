/// --------------------------------------------------------------------------
/// @file DLDKalmanFilter1D.cpp
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

#include "../inc/DLDKalmanFilter1D.h"

namespace kalman
{
	DLD_Kalman_Filter_1D::DLD_Kalman_Filter_1D(float32_t i_error_in_measurement, float32_t i_init_error_in_estimate, float32_t i_initial_estimate): 
		init_error_in_estimate(i_init_error_in_estimate),
		error_in_measurement(i_error_in_measurement),
		error_in_estimate(i_init_error_in_estimate),
		previous_estimate(i_initial_estimate),
		num_of_data_pts_available(0)
	{
	}

DLD_Kalman_Filter_1D::~DLD_Kalman_Filter_1D(void)
{
}
	/*
	*	Name: is_filter_ready
	*	Remarks: DD-ID: {49AACA5D-5D1B-4ccc-80C6-96330E7DB34C}
	*	Remarks: DD-ID: {07EBB15F-C8B6-4d6c-839F-F944211E1FA1}
	*	Remarks: DD-ID: {71B8320B-2A06-4954-A55A-51B7DFB7EB89}
	*/
	bool_t DLD_Kalman_Filter_1D::is_filter_ready() const 
	{
		bool_t retBool;
		if (num_of_data_pts_available < num_of_iterations) 
		{
			retBool = false;
		}
		else 
		{
			retBool = true;
		}
			return retBool;
	}
	/*
	*	Name: gather_initial_measurements
	*	Remarks: DD-ID: {AACA73FB-1D21-49e4-AD8B-9B83BC2CEAFC}
	*	Remarks: DD-ID: {77F469A7-A763-4a78-A910-ABB3E67D6A9E}
	*	Remarks: DD-ID: {D99A3983-8334-43a1-94B7-7FB82B4E8D27}
	*/
	void DLD_Kalman_Filter_1D::gather_initial_measurements(float32_t occ_confidence) 
	{
		occ_confidence_buffer[num_of_data_pts_available] = occ_confidence;
		num_of_data_pts_available = num_of_data_pts_available + 1;
	}
	/*
	*	Name: update_measurements_array
	*	Remarks: DD-ID: {2EBB1BFA-293B-4939-8241-BFDBBCE47009}
	*	Remarks: DD-ID: {627FF4AA-C283-417a-B6B2-2AC9BFF34667}
	*	Remarks: DD-ID: {116EC6F3-3924-456a-A148-A62A4AE8DCF8}
	*/
	void DLD_Kalman_Filter_1D::update_measurements_array(float32_t occ_confidence) 
	{
		for(int32_t i = 0; i < ( num_of_iterations - 1 ); i++) 
		{
			occ_confidence_buffer[i] = occ_confidence_buffer[i + 1];
		}
		
		occ_confidence_buffer[num_of_iterations - 1] = occ_confidence;
	}
	/*
	*	Name: calculate_kalman_gain
	*	Remarks: DD-ID: {E1343B7B-8AFA-4c81-91BD-F75F9007169B}
	*	Remarks: DD-ID: {D5F97455-5631-4562-B26E-8CF1B6F8A6CC}
	*	Remarks: DD-ID: {135D2F3F-B56E-4285-A74D-5094CA2CBD2E}
	*/
	float32_t DLD_Kalman_Filter_1D::calculate_kalman_gain() const 
	{
		return error_in_estimate / ( error_in_estimate + error_in_measurement );
	}
	/*
	*	Name: update_parameters
	*	Remarks: DD-ID: {1DB447E4-6605-4b66-B9BC-E25919F5C1DC}
	*	Remarks: DD-ID: {721B45FA-BF82-4ad1-A312-065BE9059C04}
	*	Remarks: DD-ID: {4B3341DA-6357-4b21-B06D-926107C042A1}
	*/
	void DLD_Kalman_Filter_1D::update_parameters(float32_t kalman_gain, float32_t new_estimate) 
	{
		previous_estimate = new_estimate;
		error_in_estimate = ( 1.0f - kalman_gain ) * error_in_estimate;
	}
	/*
	*	Name: reset_kalman_filter_params
	*	Remarks: DD-ID: {D9600DB7-31C9-48c5-B3A0-05F3E4062FF9}
	*	Remarks: DD-ID: {F1E54BC3-DB91-4097-93BA-942C5667777C}
	*	Remarks: DD-ID: {C02D743F-86EF-4915-B061-0AEE2D6852FA}
	*/
	void DLD_Kalman_Filter_1D::reset_kalman_filter_params(float32_t estimate_for_first_measurement) 
	{
		error_in_estimate = init_error_in_estimate;
		previous_estimate = estimate_for_first_measurement;
	}
	/*
	*	Name: get_filter_estimate
	*	Remarks: DD-ID: {6E1F9074-4D0C-4a97-B2A8-0F6D1CD06794}
	*	Remarks: DD-ID: {98D977F0-3A2E-4860-8893-38CEF74D85B7}
	*	Remarks: DD-ID: {2DE01B2A-1035-423c-9F39-A082770D1D2B}
	*/
	float32_t DLD_Kalman_Filter_1D::get_filter_estimate(float32_t occ_confidence) 
	{
		float32_t KG = calculate_kalman_gain();
		float32_t new_estimate = previous_estimate + KG * (occ_confidence - previous_estimate);
		update_parameters(KG, new_estimate);
		return new_estimate;
	}
	/*
	*	Name: reset_measurements
	*	Remarks: DD-ID: {5821EB1A-EBC3-4512-A33B-26F558D91677}
	*	Remarks: DD-ID: {6FACC369-2A64-4019-8428-107165C8814A}
	*	Remarks: DD-ID: {F2ECEA12-52A2-4782-ABAA-8CFA4857B946}
	*/
	void DLD_Kalman_Filter_1D::reset_measurements() 
	{
		num_of_data_pts_available = 0;
	}
	/*
	*	Name: kalman_process
	*	Remarks: DD-ID: {F845279A-AEE2-4f47-913C-28B806401091}
	*	Remarks: DD-ID: {B8F40106-A575-4726-B79E-EC6849B8E9A4}
	*	Remarks: DD-ID: {04DA2020-1415-4fa3-B1E1-BEDBDED38E8E}
	*/
	float32_t DLD_Kalman_Filter_1D::kalman_process() 
	{
		float32_t measurement_estimate = 0;
		float32_t estimate_for_first_measurement = 0;

		for(int32_t i = 0; i < num_of_iterations; i++) 
		{
			measurement_estimate = get_filter_estimate(occ_confidence_buffer[i]);

			if(i == 0) 
			{
				estimate_for_first_measurement = measurement_estimate;
			}
		}

		reset_kalman_filter_params(estimate_for_first_measurement);
		return measurement_estimate;
	}
} // namespace kalman
