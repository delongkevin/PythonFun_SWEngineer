/// @file FODDef.h
/// @brief Parameter structure is defined
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author
///
//--------------------------------------------------------------------------

#ifndef FOD_DEF_H
#define FOD_DEF_H
// #include <string>
// #include "Point.h"
#include "CrossplatformCommon.h"
#include "FOD_Input_Output.h"
//#include "VehicleData.h"
typedef m_GearValues_t eVehicleGear_t;

// For testing
#define WINDOWS_IMG (0)              // Enable image
#define WINDOWS_DEBUG_CODE (0)       // Enable debug result
#define WINDOWS_CODE (0)             // Enable code to run FOD in windows
#define WINDOWS_NOTINUSE_CODE (0)    // Code for future use, currently not in use
#define PRINT_OUTPUT_FOD (0)         // Enable to store FOD output in KPI sheet

// For object detecion list count
#define FOD_MAX_DETECTION_OBJECTS (6)

#if WINDOWS_CODE
    // For file length
    #define MAX_PATH_LEN (260)

    #include <opencv2/highgui.hpp>
#endif


namespace fod
{
    //**************** FOD Inputs **********************/

    //For Autonomy Level
    typedef enum ProxiAutonomyLevel_e
    {
        NoneOrLevel1 = 0,
        Level2,
        Level2Plus
    } ProxiAutonomyLevel_t;


    // FOD FIDs from Degradation Manager
    typedef enum FODFID_e
    {
        FID_NotActive = 0,
        FID_Active
    } FODFID_t;


    //**************** FOD Outputs **********************/

    // For FOD state machine status
    typedef enum FOD_SMStatus_e
    {
        ST_IDLE = 0,
        ST_ACTIVE,
        ST_FAULT,
        ST_MAX_STATES
    } FOD_SMStatus_t;


    // For FOD algorithm status
    enum FOD_Status
    {
        FOD_Idle = 0,
        FOD_Active = 1,
        FOD_NotActive = 2,
        FOD_Failure = 3
    };


#if WINDOWS_CODE
    struct FODKPIOutputData
    {
        eVehicleGear_t gearDir;
        FODHealth_t frontSensorDetHealth;
        Confidence_t objConf;

        FODKPIOutputData()
        {
            Reset();
        }

        void Reset()
        {
            gearDir = eVehicleGear_t::GearValues_E_GEAR_NEUTRAL;
            frontSensorDetHealth = FODHealth_t::Faulted;
            objConf = Confidence_t::Not_Detected;
        }
    };
#endif

}
#endif // !FOD_DEF_H
