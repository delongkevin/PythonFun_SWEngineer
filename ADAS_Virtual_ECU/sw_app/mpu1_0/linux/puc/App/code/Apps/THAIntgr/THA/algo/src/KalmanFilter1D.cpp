// ----------------------------------------------------------------------------
// --- Written by Abdulrahman Elgendy [26-Mar-2021]
// --- Last Updated by Winnie Trandinh [20-Oct-2021]
// --- Copyright (c) Magna Vectrics (MEVC) 2020
// ----------------------------------------------------------------------------

#include "KalmanFilter1D.h"

namespace tha
{
    Kalman_Filter_1D::Kalman_Filter_1D( float32_t i_error_in_measurement,
                                        float32_t i_initial_error_in_estimate,
                                        float32_t i_initial_estimate )
    {
        this->init_error_in_estimate = i_initial_error_in_estimate;
        this->error_in_measurement = i_error_in_measurement;
        this->error_in_estimate = i_initial_error_in_estimate;
        this->previous_estimate = i_initial_estimate;
        this->num_of_data_pts_available = 0;
    }

    Kalman_Filter_1D::~Kalman_Filter_1D( void )
    {
    }

    bool_t Kalman_Filter_1D::is_filter_ready() const
    {
        bool_t v_Ready_b = false;

        if( num_of_data_pts_available < this->num_of_iterations )
        {
            v_Ready_b = false;
        }
        else
        {
            v_Ready_b = true;
        }

        return v_Ready_b;
    }

    void Kalman_Filter_1D::gather_initial_measurements( float32_t confidence )
    {
        this->Data_buffer[num_of_data_pts_available] = confidence;
        this->num_of_data_pts_available = this->num_of_data_pts_available + 1;
    }

    void Kalman_Filter_1D::update_measurements_array( float32_t confidence )
    {
        for( uint8_t i = 0; i < ( this->num_of_iterations - 1 ); i++ )
        {
            this->Data_buffer[i] = this->Data_buffer[ static_cast<int32_t>( i ) + 1 ];
        }

        this->Data_buffer[ static_cast<int32_t>( this->num_of_iterations ) - 1 ] = confidence;
    }

    float32_t Kalman_Filter_1D::calculate_kalman_gain() const
    {
        return this->error_in_estimate / ( this->error_in_estimate + this->error_in_measurement );
    }

    void Kalman_Filter_1D::update_parameters( float32_t kalman_gain, float32_t new_estimate )
    {
        this->previous_estimate = new_estimate;
        this->error_in_estimate = ( 1.0f - kalman_gain ) * this->error_in_estimate;
    }

    void Kalman_Filter_1D::reset_kalman_filter_params( float32_t estimate_for_first_measurement )
    {
        this->error_in_estimate = this->init_error_in_estimate;
        this->previous_estimate = estimate_for_first_measurement;
    }

    float32_t Kalman_Filter_1D::get_filter_estimate( float32_t confidence )
    {
        float32_t KG = calculate_kalman_gain();
        float32_t new_estimate = this->previous_estimate + KG * ( confidence - this->previous_estimate );
        update_parameters( KG, new_estimate );
        return new_estimate;
    }

    void Kalman_Filter_1D::reset_measurements()
    {
        this->previous_estimate = 0;
        this->num_of_data_pts_available = 0;
        memset( this->Data_buffer, 0, sizeof( this->Data_buffer ) ); //PRQA S 3840
    }

    float32_t Kalman_Filter_1D::kalman_process()
    {
        float32_t v_measurement_estimate = 0;
        float32_t v_estimate_for_first_measurement = 0;

        for( uint8_t i = 0; i < this->num_of_iterations; i++ )
        {
            v_measurement_estimate = get_filter_estimate( this->Data_buffer[i] );

            if( i == 0 )
            {
                v_estimate_for_first_measurement = v_measurement_estimate;
            }
        }

        reset_kalman_filter_params( v_estimate_for_first_measurement );
        return v_measurement_estimate;
    }
}
