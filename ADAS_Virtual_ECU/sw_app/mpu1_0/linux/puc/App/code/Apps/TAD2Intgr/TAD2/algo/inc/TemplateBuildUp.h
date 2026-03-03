// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Mar-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __TEMPLATE_BUILD_UP_H
#define __TEMPLATE_BUILD_UP_H

#include <mecl/core/MeclTypes.h>
#ifdef __QNX__
    #include "../common/Image.h"
#else
    #include "common/Image.h"
#endif

/*
* Template building module.
*
* Builds a template to be used for template matching.
*/
namespace TemplateBuild
{
    class TemplateBuildUp
    {
    public:
        TemplateBuildUp();
        ~TemplateBuildUp();

        // --- Exposed functions
        bool_t Init( uint32_t i_hitchX, const uint32_t i_hitchYRange[2] );
        bool_t Start();
        void Finish();

        void Run( uint32_t i_frame, image::Image<uint8_t>& i_edges );
        void CreateInitialTemplate( image::Image<uint8_t>& o_template );

        // --- Getters
        bool_t IsTemplateFound() const;

    private:
        bool_t m_initOK;
        bool_t m_isRunning;
        uint32_t m_lastFrameRun;

        // --- Constants
        uint8_t c_potential_max;
        uint8_t c_potential_thresh_low;
        uint8_t c_potential_thresh_high;
        uint8_t c_potential_inc;
        uint8_t c_hitRateSampleSize; // max is 32
        uint8_t c_hitRateThreshold;

        // --- Module specific variables
        bool_t m_bHighPotentialHit;

        image::Image<uint8_t> m_potential_u8;
        image::Image<uint32_t> m_hitBuffer_u32;
        image::Image<uint8_t> m_hitRate_u8;

        _roi::ROI m_roi;

        // --- Private functions
        void _CalculateEdgeHitRate( image::Image<uint8_t>& i_edges, image::Image<uint32_t> io_hitBuffer, image::Image<uint8_t> io_hitRate ) const;
        static void _FilterEdgeHitRate( image::Image<uint8_t> i_hitRate, image::Image<float32_t> o_filteredHitRate );
        void _BuildPotential_BasedOnFilteredHitRate( image::Image<float32_t> i_filteredHitRate, image::Image<uint8_t> io_potential );
        void _BuildPotential_BasedOnRawHitRate( image::Image<uint8_t> i_hitRate, image::Image<uint8_t> io_potential );
        static void _CreateMask( image::Image<uint8_t>& i_potential, image::Image<uint8_t>& o_mask, uint8_t i_thresh, uint8_t i_radius );
        static _roi::ROI _GetProcessingROI( uint32_t i_hitchX, const uint32_t i_hitchYRange[2] );

    };
}
#endif // !__TEMPLATE_BUILD_UP_H
