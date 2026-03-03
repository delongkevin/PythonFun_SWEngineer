//--------------------------------------------------------------------------
/// @file DataProviderKM.h
/// @brief Contains
///
/// DataProvider is an interface between KM Feature module and the shared memory.
/// It implements the pure virtual interface definition to adapt the
/// module/component to the framework by specifying where the data comes form
/// or goes to. This means, this file contains all the interfaces required
/// to access input and output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef DATAPROVIDERKM_H_
#define DATAPROVIDERKM_H_

#include "IDataProviderKM.h"

namespace KM
{
  class DataProviderKM : public IDataProviderKM
  {
	public:
		explicit DataProviderKM();
		virtual ~DataProviderKM();
		ExtU_KinematicModel_T get_vehicle_signal_input();
		void transmit_kinematic_output(ExtY_KinematicModel_T* km_output);
  };

} // namespace App

#endif // DATAPROVIDERKM_H_


