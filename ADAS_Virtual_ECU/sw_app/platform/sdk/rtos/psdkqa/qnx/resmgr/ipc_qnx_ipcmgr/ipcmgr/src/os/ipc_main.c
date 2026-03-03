/*
 *--------------------------------------------------------------------------
 * @file ipc_mgr.c
 * @brief ipc manager source file
 *
 * inculde basic functionalities like:
 *- frame structure
 *-
 *-
 *--------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 * This document in its entirety is CONFIDENTIAL and may not be disclosed,
 * disseminated or distributed to parties outside MAGNA Electronics
 * without written permission from MAGNA Electronics.

 * --------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <app_init.h>

#include "ipc_main.h"

static int32_t          verbose = 0;
uint8_t  g_taskStackBuf[(D_CORE_IN_TEST+3)*D_ERR_SAT_TASK_STACKSIZE];
uint8_t *p_TaskBuf = g_taskStackBuf;
typedef  void *Task_Handle;

static int32_t ipc_io_devctl(resmgr_context_t *ctp, io_devctl_t *msg, RESMGR_OCB_T *ocb);

int32_t ipc_unblock(resmgr_context_t *ctp, io_pulse_t *msg, RESMGR_OCB_T *ocb)
{
  int32_t status = _RESMGR_NOREPLY;
  struct _msg_info info;
  res_mgr_ocb_t *ipc_ocb = (res_mgr_ocb_t *)ocb;

  if ((status = iofunc_unblock_default(ctp, msg, ocb)) != _RESMGR_DEFAULT)
  {
    return status;
  }

  if (MsgInfo(ctp->rcvid, &info) == -1 ||
            !(info.flags & _NTO_MI_UNBLOCK_REQ))
  {
    return _RESMGR_NOREPLY;
  }

  /* find this rcvid */
  pthread_mutex_lock(&ipc_ocb->lock);

  pthread_mutex_unlock(&ipc_ocb->lock);
  return _RESMGR_NOREPLY;
}


/*
 *  ======== TaskP_sleepInMsecs ========
 */
void Task_sleepInMsecs(uint32_t timeoutInMsecs)
{
    uint32_t ticks;
    uint32_t Clock_tickPeriod = 1000u;

    /* Clock_tickPeriod is in units of usecs */
    ticks = ((uint64_t)timeoutInMsecs * 1000u) / Clock_tickPeriod;

    nap(ticks);
}

void App1()
{
  while(1)
  {
	  IPC_F_IpcManager_v();
	  Task_sleepInMsecs(9U);
  }
}


Task_Handle Task_create(void *taskfxn)
{
	pthread_attr_t attr;
	int            status;
	Task_Handle retVal = (Task_Handle)NULL;
	pthread_t *tid = (pthread_t *)calloc(1, sizeof(pthread_t));

	pthread_attr_init(&attr);


	pthread_attr_setstacksize(&attr, D_ERR_SAT_TASK_STACKSIZE);

	pthread_attr_setstackaddr(&attr, &p_TaskBuf[D_ERR_SAT_TASK_STACKSIZE]);

	status = pthread_create(tid, &attr, taskfxn, (void *) NULL);

	if(status==EOK)
	{
		retVal = ((Task_Handle) tid);
	}

	return retVal;
}

int32_t main(int32_t argc, char *argv[])
{
  struct stat             sbuf;
  int32_t                     id;
  int32_t                     option;
  resmgr_connect_funcs_t  connect_funcs;
  resmgr_io_funcs_t       io_funcs;
  dispatch_t             *dpp;
  resmgr_attr_t           rattr;
  dispatch_context_t     *ctp;
  iofunc_attr_t           ioattr;
  iofunc_mount_t          mattr;
  iofunc_funcs_t          ocb_funcs;
  thread_pool_attr_t      tattr;
  thread_pool_t          *tpool;

	uint32_t retVal = D_IPC_NO_ERROR;

	int32_t result =0;

  result = appCommonInit();

  if(result != 0)
  {
    perror("Failed to init app!\n");
    return -1;
  }

  /* Only allow one instance */
  if (-1 != stat(RESMGR_DEVICE_NAME, &sbuf))
  {
    perror("IPC resmgr already running...");
    return (-1);
  }
  /* Get IO priveleges */
  if (ThreadCtl(_NTO_TCTL_IO, NULL) == -1)
  {
    perror("ThreadCtl(_NTO_TCTL_IO");
    return 1;
  }

  retVal = IPC_F_ManagerInit_u32();

  if(retVal != D_IPC_NO_ERROR)
  {
    perror("Failed to init IPC manager!\n");
    return (-1);
  }
  /* Initialize Receiver Buffers with its default values */
  retVal = IPC_F_initializeEventQueue_v();
  if(retVal != D_IPC_NO_ERROR)
  {
#if defined(DEBUG_MSG)
    printf("\n ***************** IPC Queue Init Failed \
    ******************** \n");
#endif
  }
  /* Initialize and Map Virtual Memory as per Shared Memory Region available for A72 */
  result = init_Shmem();

  if(result != 0)
  {
    perror("Failed to init SH mem!\n");
    return (-1);
  }

  /* Initialize the dispatch interface */
  dpp = dispatch_create();
  if (!dpp)
  {
    return (errno);
  }

  /* Initialize the resource manager attributes */
  memset(&rattr, 0, sizeof(rattr));
  rattr.nparts_max = 10;
  rattr.msg_max_size = 2048;

  memset (&tattr, 0x00, sizeof(thread_pool_attr_t));
  tattr.handle = dpp;
  tattr.context_alloc = (void*) dispatch_context_alloc;
  tattr.context_free = (void*) dispatch_context_free;
  tattr.block_func = (void*) dispatch_block;
  tattr.unblock_func = (void*) dispatch_unblock;
  tattr.handler_func = (void*) dispatch_handler;
  tattr.lo_water = 2;
  tattr.hi_water = 8;
  tattr.increment = 1;
  tattr.maximum = 50;

  memset (&mattr, 0, sizeof(iofunc_mount_t));
  mattr.flags = 0;
  mattr.conf = IOFUNC_PC_CHOWN_RESTRICTED | IOFUNC_PC_NO_TRUNC | IOFUNC_PC_SYNC_IO;
  mattr.dev = 0;
  mattr.funcs = &ocb_funcs;
  memset(&ocb_funcs, 0, sizeof(iofunc_funcs_t));
  ocb_funcs.nfuncs = _IOFUNC_NFUNCS;

  /* Initialize the connect functions */
  iofunc_func_init(_RESMGR_CONNECT_NFUNCS, &connect_funcs,
                     _RESMGR_IO_NFUNCS, &io_funcs);
  io_funcs.devctl = ipc_io_devctl;
  io_funcs.unblock = ipc_unblock;
  iofunc_attr_init(&ioattr, S_IFCHR | 0644, NULL, NULL);
  ioattr.mount = &mattr;

  /* Attach the device name */
  id = resmgr_attach(dpp,
                       &rattr,
                       RESMGR_DEVICE_NAME,
                       _FTYPE_ANY,
                       0,
                       &connect_funcs,
                       &io_funcs,
                       &ioattr);
  if (id == -1)
  {
    return (errno);
  }

  if ((tpool = thread_pool_create(&tattr, 0)) == NULL)
  {
    return (errno);
  }


  Task_create(&App1);


  /* Allocate a context structure */
  ctp = dispatch_context_alloc(dpp);

  while ( (option = getopt(argc, argv, "v")) != -1)
  {
    switch (option)
    {
      case 'v':
         verbose++;
         break;
      default:
         fprintf(stderr,"Unsupported option '-%c'\n",option);
         goto fail0;
    }
  }


  /* Run in the background */
  if (procmgr_daemon(EXIT_SUCCESS,
                       PROCMGR_DAEMON_NOCLOSE | PROCMGR_DAEMON_NODEVNULL ) == -1)
  {
    goto fail0;
  }

  thread_pool_start(tpool);

  while (1)
  {
    if ((ctp = dispatch_block(ctp)) == NULL)
    {
      goto fail0;
    }
    dispatch_handler(ctp);
  }

fail0:
  return (-errno);
}

//extern lut_info_t ipc_lut_data[];

static int32_t ipc_io_devctl(resmgr_context_t *ctp, io_devctl_t *msg, RESMGR_OCB_T *ocb)
{
  int32_t     status, nbytes;
  int32_t     err = EOK;
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#if (D_NUMBER_OF_TX_MESSAGES > D_ZERO)
  uint32_t status_e = NO_ERROR;
  IPCMessage_Params_t ipcParams_s;
#endif
#if (D_NUMBER_OF_RX_MESSAGES > D_ZERO)
  uint8_t v_retVal_u8 = 0U;
#endif

  ResMgr_CmdArgs *cargs = (ResMgr_CmdArgs *)(_DEVCTL_DATA (msg->i));

  if ((status = iofunc_devctl_default(ctp, msg, ocb)) != _RESMGR_DEFAULT)
  {
    return status;
  }

  status = nbytes = 0;
  switch(msg->i.dcmd)
  {
    case DCMD_RESMGR_MSG_SEND:
    {
    	void *buf = (void *)(cargs+1);
    	if(buf != NULL)
    	{
    	uint32_t v_status_u32 = D_IPC_NO_ERROR;
    	IPCMessage_Params_t ipcParams_s;
    	if(IPC_f_IsSizeMatch(cargs->args.send.msgID,cargs->args.send.len))
    	{
    		uint8_t v_tx_msgData_u8[cargs->args.send.len];

    		memcpy(&v_tx_msgData_u8[0U], (uint8_t *)buf, cargs->args.send.len);

    		ipcParams_s.IpcMsgData_v = &v_tx_msgData_u8[0U];
    		ipcParams_s.IpcMsgID_u16 = cargs->args.send.msgID;
    		ipcParams_s.IpcMsgSize_u16 = cargs->args.send.len;

    		if (err == EOK)
    		{
    			pthread_mutex_lock( &mutex);
    			v_status_u32 =  IPC_F_WrapperSend_u32(&ipcParams_s);
    			pthread_mutex_unlock( &mutex );

    			if( v_status_u32 != D_IPC_NO_ERROR)
    			{
    				//printf("MsgId : [ %d ] Not Sent Status : %d ! \n",ipcParams_s.IpcMsgID_u16, status);
    				v_status_u32 = TX_ERR_RPMSGSEND;
    			}
    		}
    	}
    	else
    	{
    		#if defined(DEBUG_MSG)
    		printf("\n*************************** IPC_MAIN.c :: Data Can not be Sent! \
          \tMsgId: %d\tSize MisMatch %d\n",cargs->args.send.msgID,cargs->args.send.len);
    		#endif
    	}
    	}
    	break;
    }
    case DCMD_RESMGR_MSG_RECV:
    {
    	void *buf = (void *)(cargs+1);
    	if(buf != NULL)
    	{
        /* this call can block. need to unlock the ocb default */
        iofunc_unlock_ocb_default(ctp, msg, ocb);
        /* Take Available Data from Receiver Buffers */
         v_retVal_u8 = IPC_F_getEvent_b(buf, &cargs->args.recv.msgID, &cargs->args.recv.len);
         /* Check for Errors while Taking Data from Available Buffers */
        if(D_IPC_MSG_ID_IDX == v_retVal_u8 && cargs->args.recv.len >= D_MIN_MESSAGE_PDU_SIZE)
        {
#if defined(DEBUG_MSG)
          printf("\n****************************** IPC_MAIN.C :: Receiving Data : %d \
          ************************* \n",cargs->args.recv.msgID);
#endif
          /* No Operation*/
        }
        else
        {
#if defined(DEBUG_MSG)
            printf("\n****************************** IPC_MAIN.C :: Receiving Data Failed! \
            MsgID: %d\tLen: %d\n",cargs->args.recv.msgID,cargs->args.recv.len);
#endif
	        /* If Extracted msgId is not proper, Share Error Msg to PUC via Resource Manager */
	// Providing Responce to App in Error Scenario 
	cargs->args.recv.msgID = 0x0;
        cargs->args.recv.len = D_MIN_MESSAGE_PDU_SIZE;
      }
      iofunc_lock_ocb_default(ctp, msg, ocb);
      SETIOV(&ctp->iov[0], &msg->o, sizeof(msg->o) + sizeof(ResMgr_CmdArgs));
      SETIOV(&ctp->iov[1], buf, cargs->args.recv.len);

      return _RESMGR_NPARTS(2);
}
      break;
    }

    default:
    err = EINVAL;
  }

  if (err != EOK)
  {
    return (err);
  }

  msg->o.ret_val = 0;

  return (_RESMGR_PTR(ctp, &msg->o, sizeof(msg->o) + sizeof(ResMgr_CmdArgs)));
}
