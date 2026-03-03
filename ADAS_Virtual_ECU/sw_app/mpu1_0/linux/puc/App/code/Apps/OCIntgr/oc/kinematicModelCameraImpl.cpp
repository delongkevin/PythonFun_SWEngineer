// ----------------------------------------------------------------------------
// --- Written by Hany Kashif [20-Nov-2014]
// --- Copyright (c) Magna Vectrics (MEVC) 2013
// ----------------------------------------------------------------------------
#include "kinematicModel.h"
// ----------------------------------------------------------------------------
using km::KinematicModelCameraImpl;
KinematicModelCameraImpl::KinematicModelCameraImpl():
ModuleImpl()
{
    // Using initialization lists
}

bool_t KinematicModelCameraImpl::loadConfiguration_b(void)
{
  /* DD-ID: {FD180BA6-21D9-4ba6-9DE5-1DC123331D33}*/
  return true;
}

bool_t KinematicModelCameraImpl::Init(tscApi::TSCCtrlInfo* b_TSCCtrlInfo_po, km::KinematicModelInfo* b_Info_po, km::KinematicModelConfig* b_Config_po, km::KinematicModelCameraConfig* b_CameraConfig_po, sint64_t i_Tracer_s64, tscApi::enuCameraID i_CameraID_t)
{
  /* DD-ID: {32911D06-8D6D-46c4-A04B-CFA6A81C1593}*/
    bool_t v_Status_b = true;
    if ( !preInit_b(b_TSCCtrlInfo_po, b_Info_po, b_Config_po, b_CameraConfig_po, i_Tracer_s64, i_CameraID_t) )
    {
        v_Status_b = false;
    }
    
    else
    {    
    initOK_b = true;
    }
    return v_Status_b;
}

void KinematicModelCameraImpl::cleanupLocalData_v(void)
{
  /* DD-ID: {80CD9134-41D2-427e-BD29-42FCB8843C57}*/
}

// ----------------------------------------------------------------------------
bool_t KinematicModelCameraImpl::start_b(void)
{
  /* DD-ID: {1516F32A-B6E1-49c3-B9C9-3418742154F5}*/
    enable_v();
    return true;
}

// ----------------------------------------------------------------------------
bool_t KinematicModelCameraImpl::process_b(void)
{
  /* DD-ID: {4E5A7E53-E702-4cdd-90DC-9C84C5056CC8}*/
    bool_t v_Status_b = true;
    if ( !processImplObjects_b() )
    {
        TRACE_0( m_hTracer, "Failed to process implementation objects");
        v_Status_b = false;
    }    
    // --- process successful
    return v_Status_b;
}

// ----------------------------------------------------------------------------
bool_t KinematicModelCameraImpl::processImplObjects_b(void)
{
  /* DD-ID: {9C72B7FD-0AF3-4a1d-B991-BA9034F72856}*/
    bool_t v_Status_b = true;
    for( ImplObjsItr v_Itr_t = implObjs_x.rwBegin_o(); v_Itr_t != implObjs_x.end_o(); ++v_Itr_t )
    {
        if(!(*v_Itr_t).isEnabled_b())
        {
            continue;
        }
        if(!(*v_Itr_t).process_b())
        {
            TRACE_0( m_hTracer, "Failed to process frame");
            v_Status_b = false;
            break;
        }
    }
    return v_Status_b;
}

// ----------------------------------------------------------------------------
bool_t KinematicModelCameraImpl::unInit_b(void)
{
  /* DD-ID: {F68FF969-7087-4d43-93AA-AB2EAC449617}*/
	reset_v();

    // --- initialize the variables to their reset state
    hTracer_s64 = 0;
    tSCCtrlInfo_po = NULL;
    config_px = NULL;
    cameraConfig_px = NULL;
    info_px = NULL;

    initOK_b = false;

    cameraID_t = tscApi::e_TscFrontCam;

    return true;
}

// ----------------------------------------------------------------------------
void KinematicModelCameraImpl::reset_v(void)
{
  /* DD-ID: {D74F1E8D-F626-4067-A962-7ACD2C25172A}*/
    implObjs_x.clear_v();

    availableFrameNumber_u32 = 0;

    enable_b = false;
}

// ----------------------------------------------------------------------------
uint16_t KinematicModelCameraImpl::getFreeObjectCountfromCollection_u16( void )
{
  /* DD-ID: {EDCF1713-FAD6-479f-95CB-0CB4A785EC34}*/
    uint16_t v_FreeObjects_u16 = 0;
    for( ImplObjsItr v_Itr_t = implObjs_x.rwBegin_o(); v_Itr_t != implObjs_x.end_o(); ++v_Itr_t )
    {
        if( !(*v_Itr_t).isEnabled_b() )
        {
            v_FreeObjects_u16++;
        }
    }
    return v_FreeObjects_u16;
}
// ----------------------------------------------------------------------------
km::KinematicModelImpl* KinematicModelCameraImpl::getFirstFreeObjectfromCollection_po(void)
{
  /* DD-ID: {92DB64AC-5699-490c-9986-A71B9E752A5C}*/
    KinematicModelImpl* v_Pobj_po = NULL;
    for( ImplObjsItr v_Itr_t = implObjs_x.rwBegin_o(); v_Itr_t != implObjs_x.end_o(); ++v_Itr_t )
    {
        if(!(*v_Itr_t).isEnabled_b())
        {
            v_Pobj_po = reinterpret_cast<KinematicModelImpl*>(&(*v_Itr_t));
            break;
        }
    }
    return v_Pobj_po;
}
// ----------------------------------------------------------------------------
km::KinematicModelImpl* KinematicModelCameraImpl::createImplObject_po(void)
{
  /* DD-ID: {8FD89819-F0CD-43e2-800E-AD3715C51119}*/
    KinematicModelImpl* v_Pobj_po = &implObjs_x.addItem_ro();
    return v_Pobj_po;
}
// ----------------------------------------------------------------------------
void KinematicModelCameraImpl::FreeImplObject(km::KinematicModelImpl* b_Pobj_po)   // PRQA S 4212
{   
  /* DD-ID: {9FC9DD7A-DCF7-419c-A9F4-3AE3DB0739EE}*/
    //Recycle object
    if(b_Pobj_po != NULL)
    {
        b_Pobj_po->disable_v();
        TRACE_3(m_hTracer, "Impl Object added to the free pool...Total Impl objects in Collection = %lu, free = %lu, Max = ", implObjs_x.size_u32(), getFreeObjectCountfromCollection_u16(), tsc_cfg::NUM_KM_IMPL_OBJS);
    }
}
// ----------------------------------------------------------------------------
km::KinematicModelImpl* KinematicModelCameraImpl::getImplObject_po(void)
{
  /* DD-ID: {4FF2D64B-C2CD-4ee5-B775-7817A616F3A6}*/
    TRACE_3(m_hTracer, "Total Impl objects in Collection = %lu, free = %lu, Max = %lu", implObjs_x.size_u32(), getFreeObjectCountfromCollection_u16(), tsc_cfg::NUM_KM_IMPL_OBJS);
    KinematicModelImpl* v_Pobj_po = getFirstFreeObjectfromCollection_po();
    if( v_Pobj_po != NULL )
    {
        // reset the object before starting re-use
        TRACE_0(m_hTracer, "Found a free object from the collection - reusing...");
        v_Pobj_po->reset_v();
    }
    else
    {
        // create the impl object
        TRACE_0(m_hTracer, "No free object available in the collection - creating a new object...");
        v_Pobj_po = createImplObject_po();
        v_Pobj_po->Init(tSCCtrlInfo_po, info_px, config_px, cameraConfig_px, hTracer_s64, cameraID_t);
    }
    v_Pobj_po->enable_v();
    return v_Pobj_po;
}

// ----------------------------------------------------------------------------

