//--------------------------------------------------------------------------
/// @file OVLData.cpp
/// @brief Contains the data for overlays
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Michael Nees (Michael.Nees@Magna.com)
///
//  --------------------------------------------------------------------------

#include "OVLData.h"
#include "logging/Logger.h"

namespace container
{

OVLData::OVLData()
  : DataContainer()
  , mutex_o()
  , drawDebug_o(reinterpret_cast<uint8_t*>(dbgBuffer_au32),dbgBufferSize_u32)
  , isPlaying_b(false)
{
  memset(dbgBuffer_au32,0U,sizeof(dbgBuffer_au32));
}

OVLData::~OVLData()
{}


OvlDebugData& OVLData::getDbgData_ro()
{
  return drawDebug_o;
}


bool_t OVLData::getIsPlaying_b() const
{
  return isPlaying_b;
}

void OVLData::setIsPlaying_v(bool_t i_Playing_b)
{
  // called by RenderThread (Ovl3D)
  isPlaying_b = i_Playing_b;
}

OvlDebugData::OvlDebugData(uint8_t* i_Buffer_pau8, uint32_t i_BufferSize_u32)
  : mutex_o()
  , buffer_pau8(i_Buffer_pau8)
  , bufferSize_u32(i_BufferSize_u32)
  , itemBufferIdx_u32(0U)
  , itemCount_u32(0U)
  , itemCheckSum_u16(0U)
  , itemLock_b(false)
{
  itemSize_au32[e_ItemUndefined] = 0U;
  itemSize_au32[e_ItemLine]      = sizeof(LineDscr_s);
  itemSize_au32[e_ItemRectangle] = sizeof(RectDscr_s);
  itemSize_au32[e_ItemEllipse]   = sizeof(EllipseDescr_s);
  itemSize_au32[e_ItemPolyline]  = sizeof(PolyLineDescr_s);
  itemSize_au32[e_ItemPolygon]   = sizeof(PolygonDescr_s);
  itemSize_au32[e_ItemText]      = sizeof(TextDescr_s);
  itemSize_au32[e_ItemImageGray] = sizeof(ImageDscr_s);
  itemSize_au32[e_ItemImageRGB]  = sizeof(ImageDscr_s);
  itemSize_au32[e_ItemImageRGBA] = sizeof(ImageDscr_s);
  itemSize_au32[e_ItemGrid3D]    = sizeof(Grid3DDscr_s);


  memset(buffer_pau8,0U,bufferSize_u32);
}

OvlDebugData::~OvlDebugData()
{}

void OvlDebugData::resetItems_v()
{
  itemCheckSum_u16  = 0U;
  itemCount_u32     = 0U;
  itemBufferIdx_u32 = 0U;

  logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskDlt,
    "OvlDebugData::resetItems_v()");
}

OvlDebugData::RetCode_e OvlDebugData::lock_e()
{
  RetCode_e v_RetCode_e = e_Error;

  if(mutex_o.take_b())
  {
    if(false == itemLock_b)
    {
      itemLock_b = true;
      v_RetCode_e = e_Success;
    }
    mutex_o.give_v();
  }

  logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskDlt,
    "OvlDebugData::lock_e() ThreadId: %d Err: %d State: %d",ME_Thread_GetCurrentID_t(),v_RetCode_e,itemLock_b);

  return v_RetCode_e;
}

container::OvlDebugData::RetCode_e OvlDebugData::unlock_e()
{
  RetCode_e v_RetCode_e = e_Error;

  if(mutex_o.take_b())
  {
    if(true == itemLock_b)
    {
      itemLock_b = false;
      v_RetCode_e = e_Success;
    }
    mutex_o.give_v();
  }
  
  logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskDlt,
    "OvlDebugData::unlock_e() ThreadId: %d  Err: %d State: %d",ME_Thread_GetCurrentID_t(),v_RetCode_e,itemLock_b);

  return v_RetCode_e;
}

bool_t OvlDebugData::isLock_b()
{
  return itemLock_b;
}

uint32_t OvlDebugData::getItemCnt_u32()
{
  return itemCount_u32;
}

uint16_t OvlDebugData::getItemCheckSum_u16()
{
  return itemCheckSum_u16;
}

OvlDebugData::RetCode_e OvlDebugData::setItem_e(ItemType_e i_DbgItmeType_e, void* i_DbgItem_pv)
{
  RetCode_e v_RetCode_e = e_Success;

  uint32_t v_TypeSize_u32 = sizeof(uint32_t);
  uint32_t v_ItemSize_u32 = itemSize_au32[i_DbgItmeType_e];
  uint32_t v_AttachSize_u32 = 0U;
  const void*    v_Attachment_pv = NULL;
  
  switch (i_DbgItmeType_e)
  {
    case e_ItemUndefined:
    case e_ItemCount:
    {
      v_RetCode_e = e_InvalidItem;
      break;
    }
    case e_ItemPolyline:
    case e_ItemPolygon:
    {  
      PolygonDescr_s* v_Polygon_ps = static_cast<PolygonDescr_s*>(i_DbgItem_pv);
      v_AttachSize_u32 = v_Polygon_ps->numPolyPoints_u32 * sizeof(mecl::Point2D_t);
      v_Attachment_pv  = static_cast<const void*>(v_Polygon_ps->polyPoints_pao);
      // Update points pointer to shared memory
      v_Polygon_ps->polyPoints_pao = reinterpret_cast<mecl::Point2D_t*>(&buffer_pau8[itemBufferIdx_u32 + v_TypeSize_u32 + v_ItemSize_u32]);

      break;
    }
    case e_ItemText:
    {
      TextDescr_s* v_Text_ps = static_cast<TextDescr_s*>(i_DbgItem_pv);
      v_AttachSize_u32 = v_Text_ps->numChars_u32 * sizeof(uint8_t);
      v_Attachment_pv  = static_cast<const void*>(v_Text_ps->charStr_pau8);
      // Update points pointer to shared memory
      v_Text_ps->charStr_pau8 = reinterpret_cast<const uint8_t*>(&buffer_pau8[itemBufferIdx_u32 + v_TypeSize_u32 + v_ItemSize_u32]);
      break;
    }
    case e_ItemImageGray:
    {
      ImageDscr_s* v_Img_ps = static_cast<ImageDscr_s*>(i_DbgItem_pv);
      v_AttachSize_u32 = static_cast<uint32_t>(v_Img_ps->srcImgSize_o.getPosX() * v_Img_ps->srcImgSize_o.getPosY()) * sizeof(uint8_t);
      v_Attachment_pv  = static_cast<const void*>(v_Img_ps->srcImg_pu8);
      // Update points pointer to shared memory
      v_Img_ps->srcImg_pu8 = reinterpret_cast<const uint8_t*>(&buffer_pau8[itemBufferIdx_u32 + v_TypeSize_u32 + v_ItemSize_u32]);
      break;
    }
    case e_ItemImageRGB:
    {
      ImageDscr_s* v_Img_ps = static_cast<ImageDscr_s*>(i_DbgItem_pv);
      v_AttachSize_u32 = static_cast<uint32_t>(v_Img_ps->srcImgSize_o.getPosX() * v_Img_ps->srcImgSize_o.getPosY()) * sizeof(uint8_t) * 3U;
      v_Attachment_pv  = static_cast<const void*>(v_Img_ps->srcImg_pu8);
      // Update points pointer to shared memory
      v_Img_ps->srcImg_pu8 = reinterpret_cast<const uint8_t*>(&buffer_pau8[itemBufferIdx_u32 + v_TypeSize_u32 + v_ItemSize_u32]);
      break;
    }
    case e_ItemImageRGBA:
    {
      ImageDscr_s* v_Img_ps = static_cast<ImageDscr_s*>(i_DbgItem_pv);
      v_AttachSize_u32 = static_cast<uint32_t>(v_Img_ps->srcImgSize_o.getPosX() * v_Img_ps->srcImgSize_o.getPosY()) * sizeof(uint8_t) * 4U;
      v_Attachment_pv  = static_cast<const void*>(v_Img_ps->srcImg_pu8);
      // Update points pointer to shared memory
      v_Img_ps->srcImg_pu8 = reinterpret_cast<const uint8_t*>(&buffer_pau8[itemBufferIdx_u32 + v_TypeSize_u32 + v_ItemSize_u32]);
      break;
    }
    default:
    {}
  };

  if(e_Success == v_RetCode_e)
  {
    if((itemBufferIdx_u32 + v_TypeSize_u32 + v_ItemSize_u32 + v_AttachSize_u32) > bufferSize_u32)
    {
      v_RetCode_e = e_NoMemoryLeft;
    }
    else if(itemCount_u32 > itemListMax_u32)
    {
       v_RetCode_e = e_NoElementsLeft;
    }
    else
    {
      // Update ItemList
      itemList_as[itemCount_u32].type_e   = i_DbgItmeType_e;
      itemList_as[itemCount_u32].size_u32 = v_TypeSize_u32 + v_ItemSize_u32 + v_AttachSize_u32;
      itemList_as[itemCount_u32].addr_pv  = static_cast<void*>(&buffer_pau8[itemBufferIdx_u32 + v_TypeSize_u32]);
      itemCount_u32++;

      // Copy to buffer
      buffer_pau8[itemBufferIdx_u32] = static_cast<uint32_t>(i_DbgItmeType_e);      
      memcpy(&buffer_pau8[itemBufferIdx_u32 + v_TypeSize_u32], i_DbgItem_pv, v_ItemSize_u32);
      memcpy(&buffer_pau8[itemBufferIdx_u32 + v_TypeSize_u32 + v_ItemSize_u32], v_Attachment_pv,v_AttachSize_u32);

      itemCheckSum_u16 += calcCrc16_u16(&buffer_pau8[itemBufferIdx_u32], (v_TypeSize_u32 + v_ItemSize_u32 + v_AttachSize_u32), itemCheckSum_u16);
      itemBufferIdx_u32 += (v_TypeSize_u32 + v_ItemSize_u32 + v_AttachSize_u32);  

      //Check U32 Alignment
      const uint32_t v_AlignSize_u32 = sizeof(uint32_t);
      itemBufferIdx_u32 +=  v_AlignSize_u32 - (itemBufferIdx_u32 % v_AlignSize_u32);
    }
  }

  logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskDlt,
    "OvlDebugData::setItem_e ItemType: %d ItemSize: %d ItemAddr: 0x%p CrC: %d ItemCnt: %d Err: %d",
    itemList_as[itemCount_u32-1].type_e, itemList_as[itemCount_u32-1].size_u32, itemList_as[itemCount_u32-1].addr_pv,
    itemCheckSum_u16,itemCount_u32,v_RetCode_e);

  return v_RetCode_e;
}


OvlDebugData::RetCode_e OvlDebugData::getItem_e(uint32_t i_Pos_u32, ItemType_e& o_Type_e, void** o_Item_pv)
{
  RetCode_e v_RetCode_e = e_InvalidIndex;

  for(uint32_t v_I_u32 = 0; v_I_u32 < itemCount_u32;v_I_u32++ )
  {
    if(i_Pos_u32 == v_I_u32)
    {
      o_Type_e = itemList_as[v_I_u32].type_e;
      *o_Item_pv = itemList_as[v_I_u32].addr_pv;
      v_RetCode_e = e_Success;
      break; //Object found
    }
  }
  return v_RetCode_e;
}


// TODO: Replace by mecl CRC function
uint16_t OvlDebugData::calcCrc16_u16(const void* i_DataPtr_pv, uint32_t i_Length_u32,const uint16_t i_StartValue_u16)
{
  const uint16_t c_Crc16BitPoly_u16    = 0x1021U;
  const uint16_t c_Crc16BitXorVal_u16  = 0x0000U;
  uint16_t v_CRC_u16 = i_StartValue_u16;
  mecl::core::MemArray<const uint8_t> v_Data_o(static_cast<const uint8_t*>(i_DataPtr_pv),i_Length_u32);

  if(NULL != i_DataPtr_pv)
  {
    for(uint32_t v_I_u32=0; v_I_u32 < v_Data_o.size_u32(); v_I_u32++)
    {
      uint8_t v_CB_u8 = v_Data_o[v_I_u32];
      for(uint8_t v_J_u8 = 0; v_J_u8 < 8; v_J_u8++)
      {
        if(( (0x8000 == (v_CRC_u16 & 0x8000))? 0x80 : 0) != (v_CB_u8 & 0x80))
        {
          v_CRC_u16 = (v_CRC_u16 << 1) ^ c_Crc16BitPoly_u16;
        }
        else
        {
          v_CRC_u16 <<= 1;
        }
        v_CB_u8 <<= 1;
      }
    }

  }
  else{/*do nothing*/}
  return v_CRC_u16 ^ c_Crc16BitXorVal_u16;
}


} // namespace container
