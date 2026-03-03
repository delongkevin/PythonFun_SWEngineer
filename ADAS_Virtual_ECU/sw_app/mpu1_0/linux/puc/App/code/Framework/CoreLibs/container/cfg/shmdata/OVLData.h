//--------------------------------------------------------------------------
/// @file OVLData.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_OVL_DATA_H
#define CONTAINER_OVL_DATA_H

#include <osal/threading/Mutex.h>
#include <mecl/meclcfg.h>

#include "container/DataContainer.h"


namespace container
{
  
  class OvlDebugData
  {
  public:
    enum RetCode_e
    {
      e_Success,
      e_Error,
      e_NoMemoryLeft,
      e_NoElementsLeft,
      e_InvalidIndex,
      e_InvalidItem,
    };

    enum ItemType_e
    {
      e_ItemUndefined,
      e_ItemLine,
      e_ItemRectangle,
      e_ItemEllipse,
      e_ItemPolyline,
      e_ItemPolygon,
      e_ItemText,
      e_ItemImageGray,
      e_ItemImageRGB,  // TODO
      e_ItemImageRGBA, // TODO
      e_ItemGrid3D,
      e_ItemCount
    };



    struct LineDscr_s
    {
      LineDscr_s()
      : posA_o()
      , posB_o()
      , colorStrokeRGBA_u32(0U)
      , strokeWidth_u32(0U)
      {}

      LineDscr_s(float32_t i_StartX_f32, float32_t i_StartY_f32,
                 float32_t i_EndX_f32, float32_t i_EndY_f32, 
                 uint32_t i_ColStr_u32, uint32_t i_StrWidth_u32)
        : posA_o(i_StartX_f32,i_StartY_f32)
        , posB_o(i_EndX_f32,i_EndY_f32)
        , colorStrokeRGBA_u32(i_ColStr_u32)
        , strokeWidth_u32(i_StrWidth_u32)
      {}

      mecl::Point2D_t posA_o;
      mecl::Point2D_t posB_o;
      uint32_t colorStrokeRGBA_u32;
      uint32_t strokeWidth_u32;
    };

    struct RectDscr_s
    {
      RectDscr_s()
      : topLeft_o()
      , size_o()
      , colorFillRGBA_u32(0U)
      , colorStrokeRGBA_u32(0U)
      , strokeWidth_u32(0U)
      {}

      RectDscr_s(float32_t i_ToLeX_f32, float32_t i_ToLeY_f32,
                 float32_t i_Width_f32,float32_t i_Height_f32, 
                 uint32_t i_ColFill_u32, uint32_t i_ColStr_u32, uint32_t i_StrWidth_u32)
        : topLeft_o(i_ToLeX_f32,i_ToLeY_f32)
        , size_o(i_Width_f32,i_Height_f32)
        , colorFillRGBA_u32(i_ColFill_u32)
        , colorStrokeRGBA_u32(i_ColStr_u32)
        , strokeWidth_u32(i_StrWidth_u32)
      {}

      mecl::Point2D_t topLeft_o;
      mecl::Point2D_t size_o;
      uint32_t colorFillRGBA_u32;
      uint32_t colorStrokeRGBA_u32;
      uint32_t strokeWidth_u32;
    };

    struct EllipseDescr_s
    {
      EllipseDescr_s()
      : center_o()
      , radius_o()
      , colorFillRGBA_u32(0U)
      , colorStrokeRGBA_u32(0U)
      , strokeWidth_u32(0U)
      {}

      EllipseDescr_s(float32_t i_CenterX_f32, float32_t i_CenterY_f32,
                     float32_t i_Width_f32,float32_t i_Height_f32, 
                     uint32_t i_ColFill_u32, uint32_t i_ColStr_u32, uint32_t i_StrWidth_u32)
        : center_o(i_CenterX_f32,i_CenterY_f32)
        , radius_o(i_Width_f32,i_Height_f32)
        , colorFillRGBA_u32(i_ColFill_u32)
        , colorStrokeRGBA_u32(i_ColStr_u32)
        , strokeWidth_u32(i_StrWidth_u32)
      {}

      mecl::Point2D_t center_o;
      mecl::Point2D_t radius_o;
      uint32_t colorFillRGBA_u32;
      uint32_t colorStrokeRGBA_u32;
      uint32_t strokeWidth_u32;
    };

    struct PolyLineDescr_s
    {
      PolyLineDescr_s()
      : polyPoints_pao(NULL)
      , numPolyPoints_u32(0)
      , colorStrokeRGBA_u32(0U)
      , strokeWidth_u32(0U)
      {}

      PolyLineDescr_s(mecl::Point2D_t* i_PolyPts_pao,uint32_t i_NumPts_u32, uint32_t i_StrCol_u32, uint32_t i_StrWidth_u32)
        : polyPoints_pao(i_PolyPts_pao)
        , numPolyPoints_u32(i_NumPts_u32)
        , colorStrokeRGBA_u32(i_StrCol_u32)
        , strokeWidth_u32(i_StrWidth_u32)
      {}

      mecl::Point2D_t* polyPoints_pao;
      uint32_t numPolyPoints_u32;
      uint32_t colorStrokeRGBA_u32;
      uint32_t strokeWidth_u32;
    };

    struct PolygonDescr_s : public PolyLineDescr_s
    {
      PolygonDescr_s() 
      : PolyLineDescr_s()
      , colorFillRGBA_u32(0U)
      {}

      PolygonDescr_s(mecl::Point2D_t* i_PolyPts_pao,uint32_t i_NumPts_u32,uint32_t i_FillCol_u32 ,uint32_t i_StrCol_u32, uint32_t i_StrWidth_u32)
        : PolyLineDescr_s(i_PolyPts_pao,i_NumPts_u32,i_StrCol_u32,i_StrWidth_u32)
        , colorFillRGBA_u32(i_FillCol_u32)
      {}

      uint32_t colorFillRGBA_u32;
    };

    struct TextDescr_s
    {
      TextDescr_s()
      : charStr_pau8(NULL)
      , topLeft_o()
      , scale_f32(0.0F)
      , numChars_u32(0)
      , colorRGBA_u32(0)
      {}

      TextDescr_s(uint8_t* i_CharStr_pau, float32_t i_ToLeX_f32, float32_t i_ToLeY_f32, float32_t i_TxtSize_f32, uint32_t i_NumChars_u32, uint32_t i_Col_u32)
        : charStr_pau8(i_CharStr_pau)
        , topLeft_o(i_ToLeX_f32,i_ToLeY_f32)
        , scale_f32(i_TxtSize_f32)
        , numChars_u32(i_NumChars_u32)
        , colorRGBA_u32(i_Col_u32)
      {}

      const uint8_t* charStr_pau8;
      mecl::Point2D_t topLeft_o;
      float32_t scale_f32;      
      uint32_t numChars_u32;
      uint32_t colorRGBA_u32;
    };

    struct ImageDscr_s
    {
      ImageDscr_s()
      : srcImg_pu8(NULL)
      , srcImgSize_o(0)
      , dstTopLeft_o(0)
      , dstImgSize_o(0)
      {}

      const uint8_t* srcImg_pu8;
      mecl::Point2D_t srcImgSize_o;
      mecl::Point2D_t dstTopLeft_o;
      mecl::Point2D_t dstImgSize_o;
    };


    struct Grid3DDscr_s
    {
      Grid3DDscr_s()
        : posGridX_s16(0)
        , posGridY_s16(0)
        , posGridZ_s16(0)
        , nColums_u8(0)
        , nRows_u8(0)
        , rectWidth_s16(0)
        , rectHeight_s16(0)
        , colorStrokeRGBA_u32(0)
        , strokeWidth_u32(0)
      {}

      sint16_t posGridX_s16;
      sint16_t posGridY_s16;
      sint16_t posGridZ_s16;
      uint8_t  nColums_u8;
      uint8_t  nRows_u8;
      sint16_t rectWidth_s16;
      sint16_t rectHeight_s16;
      uint32_t colorStrokeRGBA_u32;
      uint32_t strokeWidth_u32;
    };



    explicit OvlDebugData(uint8_t* i_Buffer_pau8, uint32_t i_BufferSize_u32);
    virtual ~OvlDebugData();


    void resetItems_v();
    RetCode_e lock_e();
    RetCode_e unlock_e();
    bool_t    isLock_b();


    RetCode_e setItem_e(ItemType_e i_ItemType_e, void* i_Item_pv);

    RetCode_e getItem_e(uint32_t i_Pos_u32, ItemType_e& o_Type_e, void** o_Item_pv);
    uint32_t  getItemCnt_u32();
    uint16_t  getItemCheckSum_u16();



  private:
        
    struct ItemList_s
    {
      OvlDebugData::ItemType_e type_e;
      uint32_t size_u32;
      void* addr_pv;      
    };

    uint16_t calcCrc16_u16(const void* i_DataPtr_pv, uint32_t i_Length_u32,const uint16_t i_StartValue_u16);

    osal::Mutex mutex_o;
    uint8_t*    buffer_pau8;
    uint32_t    bufferSize_u32;
    uint32_t    itemBufferIdx_u32;
    uint32_t    itemCount_u32;
    uint16_t    itemCheckSum_u16;
    bool_t      itemLock_b; 
    uint32_t    itemSize_au32[e_ItemCount];
    
    static const uint32_t itemListMax_u32 = 100;
    ItemList_s  itemList_as[itemListMax_u32];

  };


class OVLData : public DataContainer
{
public:


  OVLData();
  virtual ~OVLData();

  OvlDebugData& getDbgData_ro();    // access to DbgData if not used by another app

  bool_t getIsPlaying_b() const;
  void setIsPlaying_v(bool_t i_Playing_b);

private:
  osal::Mutex mutex_o;
  OvlDebugData drawDebug_o;
  bool_t isPlaying_b;
  

  static const uint32_t dbgBufferSize_u32 = 2*1024*1024; // 2MB dataBuffer
  uint32_t dbgBuffer_au32[dbgBufferSize_u32 / sizeof(uint32_t)]; //U32 because of aligned start address

};



} // namespace container

#endif // CONTAINER_OD_DATA_H

