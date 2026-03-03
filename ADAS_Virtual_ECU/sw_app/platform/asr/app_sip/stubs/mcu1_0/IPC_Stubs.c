
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "Os.h"

#include <ti/osal/osal.h>
#include <ti/drv/ipc/ipc.h>
#include <ti/drv/ipc/soc/ipc_soc.h>
#include <ti/csl/csl_mailbox.h>

#include "Cdd_Ipc.h"
#include "Cdd_IpcIrq.h"
#include "PlatformDataTypes.h"

volatile sint32_t new_msg_arrived = 0;

void Cdd_IpcNewMessageNotify(uint32 comId)
{
	(void)comId;
	new_msg_arrived = 1;
}

void Cdd_IpcNewCtrlMessageNotify(uint32 remoteProcId)
{
	(void)remoteProcId;
}

