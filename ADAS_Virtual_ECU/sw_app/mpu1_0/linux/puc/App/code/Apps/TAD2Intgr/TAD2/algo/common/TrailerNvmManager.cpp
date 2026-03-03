//--------------------------------------------------------------------------
/// @file TrailerNvmManager.cpp
/// @brief Saves trailer, doesn't really use NVM API on QNX.
///
///
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Yaroslav Taran (cameron.taylor@magna.com)
///
//  --------------------------------------------------------------------------

#include "TrailerNvmManager.h"
#include "string.h"
#include "stdio.h"
#include "common/config.h"

namespace TAD2
{
    TrailerNvmManager::TrailerNvmManager()
        : numFlashAccessAttempts_u32( 0 ),
          lastActiveTrailerID_u32( 99 )

    {
        memset( &lut_s, 0, sizeof( TrailersLut_t ) );
        memset( calibrData_au8, 0, sizeof( calibrData_au8 ) );
    }

    bool_t TrailerNvmManager::eraseAll_b( void )
    {
        return false;
    }

    bool_t TrailerNvmManager::init_b()
    {
        numFlashAccessAttempts_u32 = 10;
        return false;
    }

    bool_t TrailerNvmManager::eraseID_b( uint32_t i_TrailerID_u32 )
    {
#ifndef WIN2015
        bool_t opened = false;
        ME_Debugger_F_Printf_v( "erasing trailer\n" );

        if( ( i_TrailerID_u32 >= 1 ) && ( i_TrailerID_u32 <= 10 ) )
        {
            osal::File trailerFile;
            opened = trailerFile.open_b( trailerNames[i_TrailerID_u32 - 1], e_FomWrite ); //PRQA S 3840

            if( opened )
            {
                uint32_t dummyVariable = 0;
                trailerFile.write_u64( &dummyVariable, 4 );
                trailerFile.close_b();
            }
            else
            {
                ME_Debugger_F_Printf_v( "Failed to open trailer for delete\n" );
            }
        }
        else
        {
            ME_Debugger_F_Printf_v( "Trailer ID invalid for delete\n" );
        }

#endif
        return opened;
    }


    bool_t TrailerNvmManager::isNewTrailerID_b( uint32_t i_TrailerID_u32 )
    {
        osal::File trailerFile;
        bool_t readOk = false;
        //read in LUT to buffer
        bool_t opened = trailerFile.open_b( trailerNames[i_TrailerID_u32 - 1], e_FomRead ); //PRQA S 3840

        if( opened )
        {
            size_t v_MemorySize_t = c_CalibrDataMaxSize_u32;

            if( trailerFile.getSize_u64() >= v_MemorySize_t )
            {
                readOk = true;
            }
            else
            {
                ME_Debugger_F_Printf_v( "File too small\n" );
            }
        }
        else
        {
            ME_Debugger_F_Printf_v( "Failed to open trailer for read\n" );
        }

        return readOk;
    }

    bool_t TrailerNvmManager::saveCalibData_b( uint32_t       i_TrailerID_u32,
            const uint8_t* i_TrailerCalibInfo )
    {
        osal::File trailerFile;
        bool_t opened = trailerFile.open_b( trailerNames[i_TrailerID_u32 - 1], e_FomWrite ); //PRQA S 3840

        if( opened )
        {
            bool_t writeOk = false;
            size_t v_MemorySize_t = c_CalibrDataMaxSize_u32;
            trailerFile.write_u64( reinterpret_cast<const void*>( i_TrailerCalibInfo ), v_MemorySize_t );
            writeOk = trailerFile.close_b();
        }
        else
        {
            ME_Debugger_F_Printf_v( "Failed to open trailer for write\n" );
        }

        return static_cast<bool_t>( i_TrailerID_u32 );
    }

    bool_t TrailerNvmManager::readCalibData_b( uint32_t  i_TrailerID_u32,
            uint8_t* o_TrailerCalibInfo )
    {
        osal::File trailerFile;
        bool_t readOk = static_cast<bool_t>( i_TrailerID_u32 );
        //read in LUT to buffer
        bool_t opened = trailerFile.open_b( trailerNames[i_TrailerID_u32 - 1], e_FomRead ); //PRQA S 3840

        if( opened )
        {
            size_t v_MemorySize_t = c_CalibrDataMaxSize_u32;

            if( trailerFile.getSize_u64() >= v_MemorySize_t )
            {
                trailerFile.read_u64( o_TrailerCalibInfo, v_MemorySize_t );
                readOk = trailerFile.close_b();
            }
            else
            {
                ME_Debugger_F_Printf_v( "File too small\n" );
            }
        }
        else
        {
            ME_Debugger_F_Printf_v( "Failed to open trailer for read\n" );
        }

        return readOk;
    }

} // namespace algm

