#include <string>
#include <vector>
#include  <stdint.h>

class DemCallBackLogData
{
public:
	std::string DtcHigh;
	uint16_t DtcLow;
	uint8 FaultStatus;
	uint16_t ExtendedId;
	ldef_ErrorMgr_stAddData AddData;
};

extern std::vector<DemCallBackLogData> DemCallLogInfo;
