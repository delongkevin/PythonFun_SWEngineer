//--------------------------------------------------------------------------                                                                                                           
/// @file ConstantPool.h                                                                         
/// @brief Provides a collection of Constants
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 


#ifndef CONSTANT_POOL_H
#define CONSTANT_POOL_H

#include "RenderEngineCfg.h"
#include "Common/Resources/Constant.h"
#include "MeclTypeDefs.h"
#include "ITextureConstantData.h"

namespace me3d
{
//   class Texture;
// 
//   class ConstantPool
//   {
//   public:
//     ConstantPool() { }
//     ~ConstantPool() { } 
// 
//     template<typename T, uint32_t size_u32>
//     Constant<T, size_u32>* getConstant_po(const MEString& i_Name_ro)
//     {
//       Constant<T, size_u32>* v_Constant_po = findArrayConstant_po<T, size_u32>(i_Name_ro);
// 
//       // if nothing was found, create a new constant
//       if (NULL == v_Constant_po)
//       {
//         v_Constant_po = createArrayConstant_po<T, size_u32>();
//         Assert(NULL != v_Constant_po);
// 
//         v_Constant_po->create_v(i_Name_ro);
//       }
// 
//       Assert(NULL != v_Constant_po);
//       return v_Constant_po;
//     }
// 
//     template<typename T>
//     Constant<T, 1U>* getConstant_po(const MEString& i_Name_ro)
//     {
//       Constant<T, 1U>* v_Constant_po = findConstant_po<T>(i_Name_ro);
// 
//       // if nothing was found, create a new constant
//       if (NULL == v_Constant_po)
//       {
//         v_Constant_po = createConstant_po<T>();
//         Assert(NULL != v_Constant_po);
// 
//         v_Constant_po->create_v(i_Name_ro);
//       }
// 
//       Assert(NULL != v_Constant_po);
//       return v_Constant_po;
//     }
// 
//     template<typename T, uint32_t size_u32>
//     Constant<T, size_u32>* createArrayConstant_po()
//     {
//       return createArrayConstant_po<T, size_u32>();
//     }
// 
//     template<typename T>
//     Constant<T>* createConstant_po()
//     {
//       return createConstant_po<T>();
//     }
// 
//     template<typename T>
//     static Constant<T>* createConstant_po(Constant<T>* b_List_po, uint32_t i_Size_u32)
//     {
//       Constant<T>* v_NewConstant_po = NULL;
// 
//       for (uint32_t v_I_u32 = 0U; v_I_u32 < i_Size_u32; ++v_I_u32)
//       {
//         // PRQA S 3706 1 // size parameter ensures valid memory allocation
//         if (false == b_List_po[v_I_u32].isUsed_b())
//         {
//           // PRQA S 3706 1 // size parameter ensures valid memory allocation
//           v_NewConstant_po = &b_List_po[v_I_u32];
//           v_NewConstant_po->setUsed_v(true);
//           break;
//         }
//       }
// 
//       Assert(NULL != v_NewConstant_po);
//       return v_NewConstant_po;
//     }
// 
//     template<typename T>
//     Constant<T, 1U>* findConstant_po(const MEString& i_Name_ro)
//     {
//     	findConstant_po<T, 1U>(i_Name_ro);
//     }
// 
//     template<typename T, uint32_t size_u32>
//     Constant<T, size_u32>* findArrayConstant_po(const MEString& i_Name_ro)
//     {
//       return findArrayConstant_po<T, size_u32>(i_Name_ro);
//     }
// 
//     template<typename T>
//     static Constant<T, 1U>* findConstant_po(const MEString& i_Name_ro, Constant<T>* b_List_po, uint32_t i_Size_u32)
//     {
//       Constant<T>* v_FoundConstant_po = NULL;
// 
//       for (uint32_t v_I_u32 = 0U; v_I_u32 < i_Size_u32; ++v_I_u32)
//       {
//         // PRQA S 3706 1 // size parameter ensures valid memory allocation
//         Constant<T>* v_Current_po = &b_List_po[v_I_u32];
// 
//         if (v_Current_po->getName_ro() == i_Name_ro)
//         {
//           v_FoundConstant_po = v_Current_po;
//           break;
//         }
//       }
// 
//       return v_FoundConstant_po;
//     }
// 
//   private:
//     Constant<float32_t>              float32_o[c_MaxFloat32Constants_u32];
//     Constant<Matrix4f>               matrix4x4_o[c_MaxMatrix4x4Constants_u32];
//     Constant<Matrix3f>               matrix3x3_o[c_MaxMatrix3x3Constants_u32];
//     Constant<Vector3f>               vector3f_o[c_MaxVector3fConstants_u32];
//     Constant<Vector4f>               vector4f_o[c_MaxVector4fConstants_u32];
//     Constant<sint32_t>               sint32_o[c_MaxSint32Constants_u32];
//     Constant<uint32_t>               uint32_o[c_MaxUint32Constants_u32];
//     Constant<TextureConstant_s>      textures_o[c_MaxTextureConstants_u32];
//     Constant<bool>                   bools_o[c_MaxBoolConstants_u32];
// 
//     Constant<Matrix4f, c_MaxMatrix4x4ArrayConstants_u32> matrixArrays_o;
//   };
// 
//   // create
// 
//   template <>
//   inline Constant<float32_t>* ConstantPool::createConstant_po()
//   {
//     return createConstant_po<float32_t>(&float32_o[0], c_MaxFloat32Constants_u32);
//   }
// 
//   template <>
//   inline Constant<Matrix4f>* ConstantPool::createConstant_po()
//   {
//     return createConstant_po<Matrix4f>(&matrix4x4_o[0], c_MaxMatrix4x4Constants_u32);
//   }
// 
//   template <>
//   inline Constant<Matrix3f>* ConstantPool::createConstant_po()
//   {
//     return createConstant_po<Matrix3f>(&matrix3x3_o[0], c_MaxMatrix3x3Constants_u32);
//   }
// 
//   template <>
//   inline Constant<Vector3f>* ConstantPool::createConstant_po()
//   {
//     return createConstant_po<Vector3f>(&vector3f_o[0], c_MaxVector3fConstants_u32);
//   }
// 
//   template <>
//   inline Constant<Vector4f>* ConstantPool::createConstant_po()
//   {
//     return createConstant_po<Vector4f>(&vector4f_o[0], c_MaxVector4fConstants_u32);
//   }
// 
//   template <>
//   inline Constant<sint32_t>* ConstantPool::createConstant_po()
//   {
//     return createConstant_po<sint32_t>(&sint32_o[0], c_MaxSint32Constants_u32);
//   }
// 
//   template <>
//   inline Constant<uint32_t>* ConstantPool::createConstant_po()
//   {
//     return createConstant_po<uint32_t>(&uint32_o[0], c_MaxUint32Constants_u32);
//   }
// 
//   template <>
//   inline Constant<TextureConstant_s>* ConstantPool::createConstant_po()
//   {
//     return createConstant_po<TextureConstant_s>(&textures_o[0], c_MaxTextureConstants_u32);
//   }
// 
//   template <>
//   inline Constant<bool>* ConstantPool::createConstant_po()
//   {
//     return createConstant_po<bool>(&bools_o[0], c_MaxBoolConstants_u32);
//   }
// 
//   // Create Array
//   template<>
//   inline Constant<Matrix4f, c_MaxMatrix4x4ArrayConstants_u32>* ConstantPool::createArrayConstant_po()
//   {
//     return &matrixArrays_o;
//   }
// 
//   // Find Array
//   template <>
//   inline Constant<Matrix4f, c_MaxMatrix4x4ArrayConstants_u32>* ConstantPool::findArrayConstant_po(const MEString& i_Name_ro)
//   {
//     return &matrixArrays_o;
//   }
// 
//   // find
//   template <>
//   inline Constant<float32_t>* ConstantPool::findConstant_po(const MEString& i_Name_ro)
//   {
//     return findConstant_po<float32_t>(i_Name_ro, &float32_o[0], c_MaxFloat32Constants_u32);
//   }
// 
//   template <>
//   inline Constant<Matrix4f>* ConstantPool::findConstant_po(const MEString& i_Name_ro)
//   {
//     return findConstant_po<Matrix4f>(i_Name_ro, &matrix4x4_o[0], c_MaxMatrix4x4Constants_u32);
//   }
// 
//   template <>
//   inline Constant<Matrix3f>* ConstantPool::findConstant_po(const MEString& i_Name_ro)
//   {
//     return findConstant_po<Matrix3f>(i_Name_ro, &matrix3x3_o[0], c_MaxMatrix3x3Constants_u32);
//   }
// 
//   template <>
//   inline Constant<Vector3f>* ConstantPool::findConstant_po(const MEString& i_Name_ro)
//   {
//     return findConstant_po<Vector3f>(i_Name_ro, &vector3f_o[0], c_MaxVector3fConstants_u32);
//   }
// 
//   template <>
//   inline Constant<Vector4f>* ConstantPool::findConstant_po(const MEString& i_Name_ro)
//   {
//     return findConstant_po<Vector4f>(i_Name_ro, &vector4f_o[0], c_MaxVector4fConstants_u32);
//   }
// 
//   template <>
//   inline Constant<sint32_t>* ConstantPool::findConstant_po(const MEString& i_Name_ro)
//   {
//     return findConstant_po<sint32_t>(i_Name_ro, &sint32_o[0], c_MaxSint32Constants_u32);
//   }
// 
//   template <>
//   inline Constant<uint32_t>* ConstantPool::findConstant_po(const MEString& i_Name_ro)
//   {
//     return findConstant_po<uint32_t>(i_Name_ro, &uint32_o[0], c_MaxUint32Constants_u32);
//   }
// 
//   template <>
//   inline Constant<TextureConstant_s>* ConstantPool::findConstant_po(const MEString& i_Name_ro)
//   {
//     return findConstant_po<TextureConstant_s>(i_Name_ro, &textures_o[0], c_MaxTextureConstants_u32);
//   }
// 
//   template <>
//   inline Constant<bool>* ConstantPool::findConstant_po(const MEString& i_Name_ro)
//   {
//     return findConstant_po<bool>(i_Name_ro, &bools_o[0], c_MaxBoolConstants_u32);
//   }

} // namespace ol3d

#endif
