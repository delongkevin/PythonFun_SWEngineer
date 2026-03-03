// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Jun-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __HOUGH_LINES__H_
#define __HOUGH_LINES__H_

#ifdef _WINDOWS_ // _WINDOWS_
#include "Image.h"
#include "mecl.h"
#include <queue>

namespace TAD2
{
    /*
    * Line output by HoughLines.
    */
    struct Line
    {
        Point2i p1;
        Point2i p2;
        uint32_t score;

        Line() {};
        Line( Point2i i_p1, Point2i i_p2, uint32_t i_score = 0 ) :
            p1( i_p1 ),
            p2( i_p2 ),
            score( i_score ) {};
    };

    /*
    * Hough lines algorithm.
    */
    template<uint32_t max_lines_returned>
    class HoughLines
    {
    public:
        explicit HoughLines( const image::Image<uint8_t>& i_edges, const image::Image<uint8_t>& i_edgeDir, uint32_t i_threshold, uint32_t i_lineSep, mecl::core::ArrayList<TAD2::Line, max_lines_returned>& o_lines );
        //explicit HoughLines( const Image<uint8_t>& i_image, uint32_t i_threshold, uint32_t i_lineSep, std::vector<TAD2::ParameterizedLine>& o_lines );
        ~HoughLines();

    private:
        // --- Constants
        static const uint32_t c_maxImageWidth = 640;
        static const uint32_t c_maxImageHeight = 400;
        static const uint32_t c_maxRho = ( ( c_maxImageWidth > c_maxImageHeight ) ? c_maxImageWidth : c_maxImageHeight ) / 0.71;
        static const uint32_t c_maxTheta = 360;

        /** Node used to connect the edges of a parameterized line. **/
        struct EdgeNode
        {
            struct EdgeNode* next;
        };

        /** Defines a parameterized line using edge nodes. **/
        struct LineDef
        {
            struct EdgeNode* head;
            struct EdgeNode* tail;
        };

        /** The parameterization of a line, using rho and theta. **/
        struct ParameterizedLine
        {
            uint32_t rho;
            uint16_t theta;
            uint16_t score;

            ParameterizedLine() = default;
            ParameterizedLine( uint32_t i_rho, uint16_t i_theta, uint32_t i_score = 0.0f ) :
                rho( i_rho ),
                theta( i_theta ),
                score( i_score ) {};

            bool_t operator<( ParameterizedLine const& other ) const;
            bool_t operator>( ParameterizedLine const& other ) const;
            //bool_t operator<( const ParameterizedLine& lhs, const ParameterizedLine& rhs ) const;
            //bool_t operator>( const ParameterizedLine& lhs, const ParameterizedLine& rhs ) const;
        };

        // --- Variables used throughout algorithm
        //uint16_t m_accumulator[c_maxRho][c_maxTheta];
        uint16_t m_accumulator[901][360];
        EdgeNode* m_nodes;
        LineDef* m_lineDefs;

        // --- Helper functions
        void Accumulate( const image::Image<uint8_t>& i_edges, const image::Image<uint8_t>& i_edgeDir );
        void Decumulate( const image::Image<uint8_t>& i_edges, const image::Image<uint8_t>& i_edgeDir );
        void NonMaximaSuppresssionUsingMask( std::priority_queue<ParameterizedLine>& i_orderedLines, ParameterizedLine o_filteredLines[max_lines_returned], uint32_t& o_numLines );
        void GetLineEndPoints( ParameterizedLine i_lines[max_lines_returned], uint32_t i_numLines, uint32_t imgWidth, uint32_t imgHeight, mecl::core::ArrayList<TAD2::Line, max_lines_returned>& o_lines );
        void GetLineEndPoints2( ParameterizedLine i_lines[max_lines_returned], uint32_t i_numLines, uint32_t i_threshold, uint32_t i_lineSep, mecl::core::ArrayList<TAD2::Line, max_lines_returned>& o_lines );
    };
} // TAD2

#include "HoughLines.hpp"
#endif //_WINDOWS_

#endif // __HOUGH_LINES__H_
