/**
 * -------------------------------------------------------------------------
 *  @file ***.cpp/***.h
 *  @brief Contains
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 *
 *  @author sagar.saste@magna.com
 *  --------------------------------------------------------------------------*/
#ifndef PROXI_TO_IPCSIGNALS_H_
#define PROXI_TO_IPCSIGNALS_H_
#include "BaseReceiver.h"
#include <fstream>

namespace sigm
{
const int VERSION_FILE_LEN = 5;
const int BOOT_UD_SIZE     = 40;
const int BOOT_UD_OFFSET   = 0x70;
const int VERSION_LEN      = 7; // 2xYear + 2xWeek + 1xDay + 2xBuild
typedef struct {
    uint8_t year;
    uint8_t week;
    uint8_t day;
    uint8_t build;
    char part_num[VERSION_FILE_LEN];
} part_info_t;

typedef enum{
	e_VarID_Old_Read_failed = -1,
	e_VarID_No_Error,
	e_VarId_Write_Failed,
	e_VarId_Rcvd_Same_ID,
	e_VarID_Rcvd_Invalid_ID,
	e_VarID_Multiple_Req_Rcvd,
	e_VarID_ETFS_MOUNT_FAILED,
}e_VarIdStoreErrorCode_t;

class Proxi_to_IpcSignals : public BaseReceiver
{
public:
   Proxi_to_IpcSignals();
   virtual ~Proxi_to_IpcSignals();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool is_Prev_Req_Completed;
   bool_t handle_Proxi_to_IpcSignalsReceiver_b();
   e_VarIdStoreErrorCode_t store_rcvd_variant_id(uint8_t var_id,uint8_t radio_b);
   int parsePartitionInfo(char *full_version, part_info_t *part_info);
};
} // namespace sigm
#endif // PROXI_TO_IPCSIGNALS_H_
