/*
 * fsdata.h
 *
 *  Created on: 08-Mar-2023
 *      Author: sagasast@magna.global
 */

#ifndef SW_MPU1_0_LINUX_PUC_APP_CODE_FRAMEWORK_CORELIBS_FSDATA_FSDATA_FSDATA_H_
#define SW_MPU1_0_LINUX_PUC_APP_CODE_FRAMEWORK_CORELIBS_FSDATA_FSDATA_FSDATA_H_
namespace fsdata
{
// --------------------------------------------------------------------------
/// @brief Function stores the data at specified path using filename
///
/// Function stores the data at specified path using filename
///
/// @param[in]  filename  	Name of the file including path
/// @param[in]  data     	data to store at filename path
/// @param[in]  size    	size of the datatype to be store
/// @return     bool		return result from function
// --------------------------------------------------------------------------

bool fsdata_store_data(const char *filename,const char *data,int size);

// --------------------------------------------------------------------------
/// @brief Function reads the data at specified path using filename
///
/// Function stores the data at specified path using filename
///
/// @param[in]  filename  	Name of the file including path
/// @param[in]  data     	data to read from filename path
/// @return     bool		return result from function
// --------------------------------------------------------------------------
bool fsdata_read_data(const char *filename,char *data,int size);
}

#endif /* SW_MPU1_0_LINUX_PUC_APP_CODE_FRAMEWORK_CORELIBS_FSDATA_FSDATA_FSDATA_H_ */
