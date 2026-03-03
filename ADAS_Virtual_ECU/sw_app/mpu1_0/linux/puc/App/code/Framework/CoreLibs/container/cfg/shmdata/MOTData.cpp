//--------------------------------------------------------------------------
/// @file MOTData.cpp
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Kedar Naphad (Kedar.Naphad@magna.com)
///
//  --------------------------------------------------------------------------

#include "MOTData.h"

namespace container
{

MOTData::MOTData()
  : DataContainer()
  , mutex_o()
  , someData_s32(0)
{

}

MOTData::~MOTData()
{

}

sint32_t MOTData::getSomeData_s32()
{
  sint32_t v_DataCopy_s32 = 0;
  mutex_o.take_b();
  v_DataCopy_s32 = someData_s32;
  mutex_o.give_v();

  return v_DataCopy_s32;
}

void MOTData::setSomeData_v(sint32_t i_SomeData_s32)
{
  mutex_o.take_b();
  someData_s32 = i_SomeData_s32;
  mutex_o.give_v();
}

} // namespace container
