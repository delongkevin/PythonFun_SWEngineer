//--------------------------------------------------------------------------                                                                                                           
/// @file PlatformStl.h
/// @brief Wrapper for STL classes.
/// 
/// Defines all STL containers with our custom PlatformAllocator as default allocator as template argument.
/// Make sure to define ME_PLATFORM_CPP_11 before including this file if you want to use c++11 containers.
/// see Effective STL book http://ptgmedia.pearsoncmg.com/images/9780201749625/samplepages/0201749629.pdf for further details.
/// We stick to the standard STL code convention here for easier find/replace (e.g. replace std::vector -> mepl::vector)
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

#ifndef PLATFORM_STL_H
#define PLATFORM_STL_H

// Always Disable STL exceptions
#if 0
#define _HAS_EXCEPTIONS 0
#endif

// In general, STL is very slow in debug mode. 
// it detects incorrect iterator use and asserts and displays a dialog at run time.
// _ITERATOR_DEBUG_LEVEL defines whether the iterator debugging feature is enabled in a debug build
#if 0
#define _ITERATOR_DEBUG_LEVEL 0
#endif


// include our own STL allocator
#include <algorithm>      // used for algorithm features like sort, find, etc
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>

#include "platform/PlatformSpecs.h"
#include "PlatformAllocator.h"

#ifdef ME_PLATFORM_CPP_11
  #include <array>
  #include <unordered_set>
  #include <unordered_map>
#endif

namespace mepl
{
  // --- string and wide string---
  // just typedef with own allocator
  typedef std::basic_string<char, std::char_traits<char> > string;
  typedef std::basic_string<wchar_t, std::char_traits<wchar_t> > wstring;

  // --- sequential containers: vector, list, forward_list, deque ---

  // --------------------------------------------------------------------------
  /// @class vector
  /// @brief inherits from std::vector and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template <class _Ty>
  class vector : public std::vector<_Ty> { };

  // --------------------------------------------------------------------------
  /// @class deque
  /// @brief inherits from std::deque and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Ty>
  class deque : public std::deque<_Ty> { };

  // --------------------------------------------------------------------------
  /// @class list
  /// @brief inherits from std::list and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Ty>
  class list : public std::list<_Ty> { };

  // --- container adapters ---
  
  // --------------------------------------------------------------------------
  /// @class stack (Last In First Out)
  /// @brief inherits from std::stack and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Ty,
  class _Container = deque<_Ty> > // use our dequeue
  class stack : public std::stack<_Ty, _Container> { };

  // --------------------------------------------------------------------------
  /// @class queue (First In First Out)
  /// @brief inherits from std::queue and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Ty,
  class _Container = deque<_Ty> > // use our dequeue
  class queue : public std::queue<_Ty, _Container> { };

  // --------------------------------------------------------------------------
  /// @class priority queue
  /// @brief inherits from std::priority_queue and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Ty,
  class _Container = vector<_Ty>, // use our vector
  class _Pr = std::less<typename _Container::value_type> >
  class priority_queue : public std::priority_queue<_Ty, _Container, _Pr> { };

  // --- associative containers ---

  // --------------------------------------------------------------------------
  /// @class set
  /// @brief inherits from std::set and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Kty,
  class _Pr = std::less<_Kty> >
  class set : public std::set<_Kty, _Pr> { };

  // --------------------------------------------------------------------------
  /// @class multiset
  /// @brief inherits from std::multiset and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Kty,
  class _Pr = std::less<_Kty> >
  class multiset : public std::multiset<_Kty, _Pr> { };

  // --------------------------------------------------------------------------
  /// @class map
  /// @brief inherits from std::map and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Kty,
  class _Ty,
  class _Pr = std::less<_Kty> >
  class map : public std::map<_Kty, _Ty, _Pr> { };

  // --------------------------------------------------------------------------
  /// @class multimap
  /// @brief inherits from std::multimap and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Kty,
  class _Ty,
  class _Pr = std::less<_Kty> >
  class multimap : public std::multimap<_Kty, _Ty, _Pr> { };


  // --- c++ 11 containers (array + unordered associative containers) ---
#ifdef ME_PLATFORM_CPP_11

  // --------------------------------------------------------------------------
  /// @class array (c++ 11)
  /// @brief inherits from std::array, no allocator is used here because arrays are always fixed size
  // --------------------------------------------------------------------------
  template<class _Ty, size_t _Size>
  class array : public std::array<_Ty, _Size> { };

  // --------------------------------------------------------------------------
  /// @class unordered set
  /// @brief inherits from std::unordered_set and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Kty,
  class _Hasher = std::hash<_Kty>,
  class _Keyeq = std::equal_to<_Kty> >
  class unordered_set : public std::unordered_set<_Kty, _Hasher, _Keyeq> { };

  // --------------------------------------------------------------------------
  /// @class unordered multiset
  /// @brief inherits from std::unordered_multiset and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Kty,
  class _Hasher = std::hash<_Kty>,
  class _Keyeq = std::equal_to<_Kty> >
  class unordered_multiset : public std::unordered_multiset<_Kty, _Hasher, _Keyeq> { };

  // --------------------------------------------------------------------------
  /// @class unordered map
  /// @brief inherits from std::unordered_map and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Kty,
  class _Ty,
  class _Hasher = std::hash<_Kty>,
  class _Keyeq = std::equal_to<_Kty> >
  class unordered_map : public std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq> { };

  // --------------------------------------------------------------------------
  /// @class unordered multimap
  /// @brief inherits from std::unordered_multimap and specifies our own allocator as default allocator template argument
  // --------------------------------------------------------------------------
  template<class _Kty,
  class _Ty,
  class _Hasher = std::hash<_Kty>,
  class _Keyeq = std::equal_to<_Kty> >
  class unordered_multimap : public std::unordered_multimap<_Kty, _Ty, _Hasher, _Keyeq> { };
#endif

} // namespace mepl

#endif // PLATFORM_STL_H
