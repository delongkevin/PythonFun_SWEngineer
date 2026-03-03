//--------------------------------------------------------------------------                                                                                                           
/// @file PlatformAllocator.h
/// @brief Custom STL allocator using PlatformMemory.
/// 
/// This class acts as a replacement for the STL's standard allocator.
/// It uses the PlatformMemory implementation to allocate memory
/// for our own STL containers (see PlatformStl).
/// We stick to the STL's code convention, else STL's template voodoo won't work.
/// 
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef PLATFORM_ALLOCATOR_H
#define PLATFORM_ALLOCATOR_H

#include "PlatformMemory.h"
#include "platform/stdlib/utils/CppHelpers.h"

namespace mepl
{
  template <typename T> 
  class PlatformAllocator;
  
  // --------------------------------------------------------------------------
  /// @class PlatformAllocator
  /// @brief template specialization for void
  // --------------------------------------------------------------------------
  template <> 
  class PlatformAllocator<void>
  {
  public:
    typedef void*       pointer;
    typedef const void* const_pointer;
    typedef void        value_type; // reference to void members are impossible.
  
    template <class U>
    struct rebind 
    { 
      typedef PlatformAllocator<U> other; 
    };
  };
  
  // --------------------------------------------------------------------------
  /// @class PlatformAllocator
  /// @brief implements a STL allocator utilizing the PlatformMemory implementation to allocate memory
  // --------------------------------------------------------------------------
  template <typename T>
  class PlatformAllocator 
  {
  public:
    typedef size_t    size_type;
    typedef ptrdiff_t difference_type;
    typedef T*        pointer;
    typedef const T*  const_pointer;
    typedef T&        reference;
    typedef const T&  const_reference;
    typedef T         value_type;
  
    // --------------------------------------------------------------------------
    /// @brief Default constructor
    // --------------------------------------------------------------------------
    PlatformAllocator()  
    {
    }
  
    // --------------------------------------------------------------------------
    /// @brief Destructor
    // --------------------------------------------------------------------------
    ~PlatformAllocator() 
    {
    }
  
    // --------------------------------------------------------------------------
    /// @brief Copy constructor
    // --------------------------------------------------------------------------
    template <class U> 
    PlatformAllocator(const PlatformAllocator<U>& i_Alloc_ro) 
    {
      (void)(i_Alloc_ro);
    }
  
    template <class U> 
    struct rebind 
    { 
      typedef PlatformAllocator<U> other; 
    };
  
    // --------------------------------------------------------------------------
    /// @brief return reference address
    ///
    /// @param[in] i_Ref_rx the reference to address
    /// @return    address of the reference
    // --------------------------------------------------------------------------
    pointer address(reference i_Ref_rx) const 
    {
      return &i_Ref_rx;
    }
  
    // --------------------------------------------------------------------------
    /// @brief return const reference address
    ///
    /// @param[in] i_Ref_rx the reference to address
    /// @return    address of the const reference
    // --------------------------------------------------------------------------
    const_pointer address(const_reference i_Ref_rx) const 
    {
      return &i_Ref_rx;
    }
  
    // --------------------------------------------------------------------------
    /// @brief get the maximum size of memory in bytes
    ///
    /// @return get the maximum size of memory in bytes
    // --------------------------------------------------------------------------
    size_type max_size() const
    {
      return size_t(-1) / sizeof(value_type);
    }
  
    // --------------------------------------------------------------------------
    /// @brief uses own malloc implementation to allocate memory
    ///
    /// @param[in] i_Bytes_t amount of bytes to allocate
    /// @param[in] i_Hint_px hint is unused
    /// @return pointer to allocated memory
    // --------------------------------------------------------------------------
    pointer allocate(size_type i_Bytes_t, PlatformAllocator<void>::const_pointer i_Hint_px = 0)
    {
      (void)(i_Hint_px);

      return static_cast<pointer>(lMepl_F_Malloc_pv(i_Bytes_t * sizeof(T)));
    }
  
    // --------------------------------------------------------------------------
    /// @brief Deallocate a previously allocated fixed memory block.
    ///
    /// @param[in] i_Memory_px pointer to memory to deallocated
    /// @param[in] i_Unused_t is unused
    // --------------------------------------------------------------------------
    void deallocate(pointer i_Memory_px, size_type i_Unused_t)
    {
      // get rid of compiler error
      (void)(i_Unused_t);

      // free memory
      lMepl_F_Free_v(i_Memory_px);
    }
  
    // --------------------------------------------------------------------------
    /// @brief Constructs a new instance using placement new.
    ///
    /// @param[in] i_Memory_px the pointer to the memory where the instance is constructed using placement new.
    /// @param[in] i_Val_rx is instance of object to copy construct.
    // --------------------------------------------------------------------------
    void construct(pointer i_Memory_px, const T& i_Val_rx)
    {
      new (static_cast<void*>(i_Memory_px)) T(i_Val_rx); // PRQA S 5118 // false detection - using placement new here
    }
  
    // --------------------------------------------------------------------------
    /// @brief Constructs a new instance using placement new.
    ///
    /// @param[in] i_Pointer_px the pointer to the memory where the instance is constructed using placement new.
    // --------------------------------------------------------------------------
    void construct(pointer i_Pointer_px)
    {
      new (static_cast<void*>(i_Pointer_px)) T(); // PRQA S 5118 // false detection - using placement new here
    }
  
    // --------------------------------------------------------------------------
    /// @brief Destroys an instance. Objects created with placement new must explicitly call the destructor.
    ///
    /// @param[in] i_Pointer_px pointer to object instance.
    // --------------------------------------------------------------------------
    void destroy(pointer i_Pointer_px)
    {
      i_Pointer_px->~T();
    }
  
  };

  // --------------------------------------------------------------------------
  /// @brief equality operator
  ///
  /// @return always true
  // --------------------------------------------------------------------------
  template <typename T, typename U>
  inline bool operator==(const PlatformAllocator<T>&, const PlatformAllocator<U>)
  {
    return true;
  }
  // --------------------------------------------------------------------------
  /// @brief inequality operator
  ///
  /// @return always false
  // --------------------------------------------------------------------------
  template <typename T, typename U>
  inline bool operator!=(const PlatformAllocator<T>&, const PlatformAllocator<U>)
  {
    return false;
  }

} // namespace mepl


// For VC6/STLPort 4-5-3 see /stl/_alloc.h, line 464
// "If custom allocators are being used without member template classes support :
// user (on purpose) is forced to define rebind/get operations !!!"
namespace std 
{
  template <class _Tp1, class _Tp2>
  inline mepl::PlatformAllocator<_Tp2>& ME_CDECL
    __stl_alloc_rebind(mepl::PlatformAllocator<_Tp1>& __a, const _Tp2*)
  {
    return (mepl::PlatformAllocator<_Tp2>&)(__a);
  }

  template <class _Tp1, class _Tp2>
  inline mepl::PlatformAllocator<_Tp2> ME_CDECL
    __stl_alloc_create(const mepl::PlatformAllocator<_Tp1>&, const _Tp2*)
  {
    return mepl::PlatformAllocator<_Tp2>();
  }
}

#endif // PlatformAllocator
