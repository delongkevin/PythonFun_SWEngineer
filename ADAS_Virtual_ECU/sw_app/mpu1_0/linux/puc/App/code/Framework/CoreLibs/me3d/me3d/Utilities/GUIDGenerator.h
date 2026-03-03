//--------------------------------------------------------------------------                                                                                                           
/// @file GUIDGenerator.h                                                                         
/// @brief Class to generate Global Unique identifiers
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 


#ifndef GUID_GENERATOR_H
#define GUID_GENERATOR_H

#include "Utilities/InOut.h"

namespace me3d
{
  template<uint32_t freeListCapacity_u32 = 256U>
  class GUIDGenerator
  {
  public:
    // Marker for invalid position
    // PRQA S 2890 1 // Negative value implicitly converted to an unsigned type is intended
    static const uint32_t c_InvalidGUID_u32 = -1;

    GUIDGenerator()
      : nextGUID_u32(0U)
      , freeListSize_u32(0U)
    {
      for (uint32_t v_I_u32 = 0U; v_I_u32 < freeListCapacity_u32; ++v_I_u32)
      {
        freeList_au32[v_I_u32] = c_InvalidGUID_u32;
      }

    }

    void serialize_v(InOut& b_IO_ro)
    {
      b_IO_ro.serialize_v(nextGUID_u32);
      b_IO_ro.serialize_v(freeListSize_u32);
      b_IO_ro.serializeArray_v(&freeList_au32[0], freeListCapacity_u32);
    }

    uint32_t getFreeID_u32()
    {
      uint32_t v_NextFreeID_u32 = c_InvalidGUID_u32;

      // check if any free ids are available
      if (freeListSize_u32 > 0U)
      {
        // decrement size, so we can use it as freelist array index
        --freeListSize_u32;

        // save next free id
        v_NextFreeID_u32 = freeList_au32[freeListSize_u32];

        // make sure we have a valid next free id
        Assert(v_NextFreeID_u32 != c_InvalidGUID_u32);

        // reset free list entry
        freeList_au32[freeListSize_u32] = c_InvalidGUID_u32;
      }
      else
      {
        // if no ids are available, just set the id to the next free guid
        v_NextFreeID_u32 = nextGUID_u32;

        // increment next guid for later
        ++nextGUID_u32;
      }

      Assert(v_NextFreeID_u32 != c_InvalidGUID_u32);
      return v_NextFreeID_u32;
    }


    void releaseID_v(uint32_t i_ID_u32)
    {
      Assert(freeListSize_u32 < freeListCapacity_u32);

      freeList_au32[freeListSize_u32] = i_ID_u32;

      ++freeListSize_u32;
    }

  private:
    uint32_t nextGUID_u32;
    uint32_t freeListSize_u32;
    uint32_t freeList_au32[freeListCapacity_u32];
  };

} // namespace me3d

#endif
