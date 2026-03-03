/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           cogent_api.h
 *  @brief          External API
 *
 *  @version        3.21_tda4_01
 *  @author         Mikhail Vakhrushev & Alexander Ronzhin
 *  @date           12.10.2020
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#include <stdint.h>

#ifndef YUV_DATA_INTERNAL_H
#define YUV_DATA_INTERNAL_H

/*******************************************************************************
 * YUV Embedded Data Format
 ******************************************************************************/

struct isp_yuvdata_with_fields
{
    /**
     * @brief Number of the frame as captured by the sensor.
     *
     * It is useful for:
     *  - locating bayer images that correspond to a particular YUV.
     *  - analysing frame drops
     *  - determining event times and syncronization
     *
     * When embedded data is not available, it is 0.
     */
    uint32_t frame_number;

    /**
     * @brief Lower 32 bits of ISP batch number, used for referencing trace files etc.
     */
    uint32_t batch_number;

    /**
     * @brief CRC32 of all image pixels if available.
     *
     * Black pixels, vblank/hblank, embedded data etc should NOT normally be included.
     */
    uint32_t crc32;

    /**
     * @brief Encoded version of ISP software / firmware.
     */
    uint32_t isp_sw_version;

    /**
     * @brief Exposure time in milliseconds in 10.6 fixed-point format.
     */
    uint16_t exposure_time_ms;

    /**
     * @brief Total sensor gain.
     *
     * This includes all analog, conversion, digital and other gains
     * that are not considered in the @sa exposure_time_ms.
     *
     * It is in 10.6 fixed-point format.
     */
    uint16_t sensor_gain;

    /**
     * @brief AWB color temperature in Kelvin.
     */
    uint16_t awb_kelvin;

    /**
     * @brief AWB tint in relative units in signed 5.11 fixed-point format.
     */
    int16_t awb_tint;

    /**
     * @brief Image sensor temperature in degrees Celsius.
     */
    int8_t die_temperature;

    /**
     * @brief Miscellaneous flags.
     *
     * Meaning of flags is specific to @sa isp_sw_version.
     */
    uint16_t flags;

    /**
     * @brief Total ISP digital gain.
     *
     * It is in 10.6 fixed-point format.
     */
    uint16_t isp_gain;

    /**
     * @brief Average image brightness in normalized units.
     *
     * It is in 0.16 fixed-point format.
     */
    uint16_t average_brightness;

    /**
     * @brief Frame line length (FLL) in microseconds.
     *
     *  It is in 8.8 fixed-point format.
     */
    uint16_t line_length_us;

    /**
     * @brief Estimated scene illumination in lux.
     *
     *  It is in 24.8 fixed-point format.
     */
    uint32_t lux;

    /**
     * @brief Estimated scene SNR in dB.
     *
     * It is in signed 9.6 fixes-point format
     */
    int16_t snr;

    /**
     * @brief Number of valid AWB patches.
     */
    uint16_t awb_patches;

    /**
     * @brief ISP pipeline gamma.
     *
     * It is in unsigned 4.10 fixed-point format.
     */
    uint16_t isp_gamma;

    /**
     * @brief Detected banding frequency in Hz.
     */
    uint8_t banding_frequency;

    /**
     * @brief Correlation coefficient from banding detector.
     *
     * It is in 0.16 fixed-point format.
     */
    uint16_t banding_correlation;

    /**
     * @brief Fraction of saturated pixels before LTM.
     *
     * It is in 0.16 fixed-point format.
     */
    uint16_t white_q;
};

#define YUVDATA_PACKED_BYTES (98u + 4u)

void yuv_data_pack(uint8_t* dst, uint32_t yuv_data_out_sz, struct isp_yuvdata_with_fields* data);

#endif /*YUV_DATA_INTERNAL_H*/
