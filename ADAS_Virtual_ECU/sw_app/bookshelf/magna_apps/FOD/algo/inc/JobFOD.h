#ifndef JOBFOD_H_
#define JOBFOD_H_

#include "PlatformDataTypes.h"
#include "core/MeclTypes.h"
//#include "JobBaseAlgo.h"
#include "../algo/inc/IDataProviderFOD.h"
#include "../../FrontObjectDetection/FrontObjectDetection.h"
#include "../algo/inc/JobFODInput.h"
#include "../algo/inc/JobFODOutput.h"
#include "../algo/common/FODConfig.h"
#include "../algo/inc/FODAlgo.h"
#include "../algo/inc/FODEngine.h"
#if WINDOWS_CODE
    #include "stdafx.h"
#endif

#define FOD_DEBUG_PRINTS    (0u)
#define FOD_TUNNING_PARAMS  (1u)

namespace fod
{
    class JobFOD
    {
    public:

        JobFOD( IDataProviderFOD *i_dataProvider_ro );
        virtual ~JobFOD();

        void init_v( void );

        bool_t hasNext_b( void );

        void start_v( void );

        void execute_v( void );

        void end_v( void );

        void dump_v( void );

        void reset_v( void );

#if WINDOWS_CODE
        // Get Gear Direction text
        static char* getGearDirText( const eVehicleGear_t gearDirection );
        // Get object detection sensor helath text
        static char* getFODHealthText( const FODHealth_t frontSensorDetHealth );
        // Get object confidence text
        static char* getObjConfText( const Confidence_t objConf );
#endif
    private:
        IDataProviderFOD *dataProvider_ro;

        FODState m_FodState;
        FODCONFIGData m_FODCfg;
        TbFOD_VrntTunParam_t m_FodTuningParam;
        FODAlgo m_fodAlgo;
        JobFODOutput_t m_JobFODOutput;
        Job_Inputs_t m_JobFODInput;
        float32_t MeFOD_m_MinXDist;
        float32_t MeFOD_m_MinXDistSide;
        FODHealth_t m_FodHealth_e;
#if WINDOWS_CODE
        // --- KPI Parameters
        FODKPIOutputData FODKpiOutputData;
        // File to dump detection result
        std::ofstream m_KpiFile;
        void InitKPIResult();
        void WriteKPIResult( FODKPIOutputData FODKpiOutputData );
#endif
    };

} // !fod
#endif //! JOBFOD_H_
