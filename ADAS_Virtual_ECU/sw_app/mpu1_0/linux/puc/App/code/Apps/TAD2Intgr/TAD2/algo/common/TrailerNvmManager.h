//--------------------------------------------------------------------------
/// @file TrailerNvmManager.h
/// @brief Implements NVM API for saving/reading trailer calibration data.
///
/// This class implements the API used to save/read trailer calibration data.
/// The API allows to save/update up to 30 trailers calibration data
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Yaroslav Taran (yaroslav.taran@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef TRAILERNVMMANAGER_H_
#define TRAILERNVMMANAGER_H_
#ifdef __QNX__
    #include <osal/io/File.h>
#else
    #include "osal/io/file.h"
#endif
#include "TADStructures.h"

namespace TAD2
{

    const uint32_t c_PhysicalAddressStart_u32 = 0x01E00000UL;
    const uint64_t c_TrailerValidSign_u64     = 0x5A5A5A5A5A5A5A5AUL;
    const uint64_t c_ValidSign_u64            = 0xA5A5A5A5A5A5A5A5UL;


    const uint32_t c_LookUpMaxSize_u32     = 0x1000UL;
    const uint32_t c_CalibrDataMaxSize_u32 = 0x3F000UL;
    const uint32_t c_FlashInitRetries_u32  = 0xAUL;
    const uint32_t c_FlashRetryPause_u32   = 0x2UL;

    const uint32_t c_MaxNumTrailers_u32 = 5;

    //PRQA S 294 ++
    const char trailerNames[10][26] =
    {
        {"/usr/tradat/trailerImage1"},
        {"/usr/tradat/trailerImage2"},
        {"/usr/tradat/trailerImage3"},
        {"/usr/tradat/trailerImage4"},
        {"/usr/tradat/trailerImage5"},
        {"/usr/tradat/trailerImage6"},
        {"/usr/tradat/trailerImage7"},
        {"/usr/tradat/trailerImage8"},
        {"/usr/tradat/trailerImage9"},
        {"/usr/tradat/trailerImage0"}
    };
    //PRQA S 294 --

    typedef struct LookupEntry_s
    {
        uint32_t trailerID_u32;
        uint32_t startAddr_u32;
        uint32_t dataSize_u32;
        uint32_t crc_u32;
    } TrailerInfo_t;

    typedef struct TrailersLut_s
    {
        uint64_t      validSignature_u64;
        uint32_t      registeredTrailersCounter_u32;
        TrailerInfo_t trailers_as[c_MaxNumTrailers_u32];
    } TrailersLut_t;

    class TrailerNvmManager
    {
    public:

        bool_t init_b( void );

        static bool_t isNewTrailerID_b( uint32_t      i_TrailerID_u32 );

        static bool_t saveCalibData_b( uint32_t       i_TrailerID_u32,
                                       const uint8_t* i_TrailerCalibInfo );

        static bool_t readCalibData_b( uint32_t       i_TrailerID_u32,
                                       uint8_t* o_TrailerCalibInfo );

        static bool_t eraseAll_b( void );

        static bool_t eraseID_b( uint32_t i_TrailerID_u32 );

        TrailerNvmManager();//single ton implementation
    private:

        uint32_t numFlashAccessAttempts_u32;

        uint32_t getTrailerIDIndex_u32( uint32_t i_TrailerID_u32 ) const;

        uint32_t getTrailerIDFreeIndex_u32( void ) const;

        TrailersLut_t lut_s;
        uint32_t lastActiveTrailerID_u32;
        uint8_t calibrData_au8[c_CalibrDataMaxSize_u32];
    };

}
#endif//TRAILERNVMMANAGER_H_

