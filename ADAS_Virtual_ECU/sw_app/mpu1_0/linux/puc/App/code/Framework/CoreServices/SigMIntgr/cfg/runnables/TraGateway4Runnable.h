
#ifndef TRA_GATEWAY4_RUNNABLE_H_
#define TRA_GATEWAY4_RUNNABLE_H_

#include <platform/PlatformAPI.h>

#include <osal/threading/Thread.h>

namespace sigm
{

namespace sigmconsts
{
const uint64_t c_TRAGateway4ThresholdMS_u64 = 24;
} //namespace sigmconsts


class TRAGateway4Runnable : public osal::IRunnable
{
public:

  explicit TRAGateway4Runnable(IDataProviderSigM* i_DataProviderSigM_po)
    : osal::IRunnable()
    , dataProvider_po(i_DataProviderSigM_po)
    , isRunning_b(true)
    , network_po(NULL)
  { }

  virtual ~TRAGateway4Runnable() { }

  virtual void registerNetwork_v(osal::INetwork* i_Network_po)
  {
    network_po = i_Network_po;
  }

  virtual void init_v()  { }

  virtual bool_t run_b()
  {
    if (NULL != network_po)
    {
      MCU_TRAGateway4Response_t v_Response_t = dataProvider_po->getMCU_TRAGateway4Response_t();
#if 0
      v_Response_t.Response_Code_MCU_TRAGateway4_u8 = static_cast<uint8_t>(variants::e_ResponseCodePositive);
      v_Response_t.TadState_u8 = dataProvider_po->getTRAState();
      sint16_t tempTRATSA = static_cast<sint16_t>(dataProvider_po->getTRAresponse_t().IeTRIA_deg_TrgtStrAng_f32/ 1.5f);
      v_Response_t.TRATSA_u16 = tempTRATSA << 4;

      ME_MsgTx_s v_TRAGateway4Message_o;

      v_TRAGateway4Message_o.msgSize_u32 = BaseRequest::getMessageSize_u32<MCU_TRAGateway4Response_t>();
      uint32_t v_Index_u32 = addHeaderToMessage_u32(&v_TRAGateway4Message_o.data_t[0], e_MCU_TRAGateway4Response);
      writeMCU_TRAGateway4Response_b(&v_TRAGateway4Message_o.data_t[v_Index_u32], v_TRAGateway4Message_o.msgSize_u32, &v_Response_t);

      network_po->send_b(&v_TRAGateway4Message_o.data_t[0], v_TRAGateway4Message_o.msgSize_u32);
#endif
    }

    ME_Thread_Sleep_t(sigmconsts::c_TRAGateway4ThresholdMS_u64);

    return false;
  }

  virtual void cleanup_v() { }

  void terminate_v()
  {
    isRunning_b = false;
  }

private:

  IDataProviderSigM* dataProvider_po;

  bool_t             isRunning_b;

  osal::INetwork*    network_po;
};


} // namespace sigm

#endif // TRA_GATEWAY4_RUNNABLE_H_
