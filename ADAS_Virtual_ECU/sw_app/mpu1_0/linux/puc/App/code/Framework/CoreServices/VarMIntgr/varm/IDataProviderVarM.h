//--------------------------------------------------------------------------
/// @file IDataProviderVarM.h
/// @brief Contains
///
/// IDataProvider is an interface used by the algorithm to define what data
/// is actually needed. Implementation is delegated to a derived data provider
/// that is component/module specific and belongs to the framework implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef IDATAPROVIDERVARM_H_
#define IDATAPROVIDERVARM_H_

#include <platform/PlatformSpecs.h>
#include <variants/Enums.h>

namespace varm
{


class IDataProviderVarM
{
public:
  explicit IDataProviderVarM()
  {}

  virtual ~IDataProviderVarM()
  {}

  //----------------------------------------------------------------------------------------
  // // Data Input (only getter)
  //---------------------------------------------------------------------------------------

  virtual uint32_t              getLanguageID_u32() const = 0;

  //----------------------------------------------------------------------------------------
  // Data Output (only setter)
  //----------------------------------------------------------------------------------------

  virtual void                  setLanguageID_v(uint32_t i_Data_u32) = 0;

};


} // namespace varm

#endif // IDATAPROVIDERVARM_H_
