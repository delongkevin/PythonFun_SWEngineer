 // C++ Bridge for C++-11 features to use in C++-0x
// supported features:
//  - function pointers
//  - override
//  - final
// already supported: StaticAssert

#ifndef ME_CPP_BRIDGE_H
#define ME_CPP_BRIDGE_H

#include "platform/PlatformSpecs.h"

// PRQA S 2400 EOF // global scope, this is a header file

typedef void* Dummy_t; // used as default parameter in FunPtr template

/// Helper template to map to either C-Function pointer when not using C++-11 or to std::function when using C++-11.
/// Example: typename FunPtr<void,bool_t>::fp would be mapped to either void(*)(bool_t) or std::function<void(bool_t)>.
template <typename RetType, typename Arg1, typename Arg2=Dummy_t, typename Arg3=Dummy_t, typename Arg4=Dummy_t, typename Arg5=Dummy_t, typename Arg6=Dummy_t>
struct FunPtr;

#ifdef ME_PLATFORM_CPP_11

#include <functional>

// typedef function pointer types as std::function objects
template <typename RetType, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
struct FunPtr
{
  typedef std::function< RetType (Arg1,Arg2,Arg3,Arg4,Arg5,Arg6)> fp;
};
template <typename RetType, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
struct FunPtr<RetType,Arg1,Arg2,Arg3,Arg4,Arg5,Dummy_t>
{
  typedef std::function< RetType (Arg1,Arg2,Arg3,Arg4,Arg5)> fp;
};
template <typename RetType, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
struct FunPtr<RetType,Arg1,Arg2,Arg3,Arg4,Dummy_t,Dummy_t>
{
  typedef std::function< RetType (Arg1,Arg2,Arg3,Arg4)> fp;
};
template <typename RetType, typename Arg1, typename Arg2, typename Arg3>
struct FunPtr<RetType,Arg1,Arg2,Arg3,Dummy_t,Dummy_t,Dummy_t>
{
  typedef std::function< RetType (Arg1,Arg2,Arg3)> fp;
};
template <typename RetType, typename Arg1, typename Arg2>
struct FunPtr<RetType,Arg1,Arg2,Dummy_t,Dummy_t,Dummy_t,Dummy_t>
{
  typedef std::function< RetType (Arg1,Arg2)> fp;
};
template <typename RetType, typename Arg1>
struct FunPtr<RetType,Arg1,Dummy_t,Dummy_t,Dummy_t,Dummy_t,Dummy_t>
{
  typedef std::function< RetType (Arg1)> fp;
};

#else // no cpp11 support

// Typedef function pointer types as C-Funktion pointers
template <typename RetType, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
struct FunPtr
{
  typedef RetType(*fp)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6);
};
template <typename RetType, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
struct FunPtr<RetType,Arg1,Arg2,Arg3,Arg4,Arg5,Dummy_t>
{
  typedef RetType(*fp)(Arg1, Arg2, Arg3, Arg4, Arg5);
};
template <typename RetType, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
struct FunPtr<RetType,Arg1,Arg2,Arg3,Arg4,Dummy_t,Dummy_t>
{
  typedef RetType(*fp)(Arg1, Arg2, Arg3, Arg4);
};
template <typename RetType, typename Arg1, typename Arg2, typename Arg3>
struct FunPtr<RetType,Arg1,Arg2,Arg3,Dummy_t,Dummy_t,Dummy_t>
{
  typedef RetType(*fp)(Arg1, Arg2, Arg3);
};
template <typename RetType, typename Arg1, typename Arg2>
struct FunPtr<RetType,Arg1,Arg2,Dummy_t,Dummy_t,Dummy_t,Dummy_t>
{
  typedef RetType(*fp)(Arg1, Arg2);
};
template <typename RetType, typename Arg1>
struct FunPtr<RetType,Arg1,Dummy_t,Dummy_t,Dummy_t,Dummy_t,Dummy_t>
{
  typedef RetType(*fp)(Arg1);
};

#endif // ME_PLATFORM_CPP_11

#endif // ME_CPP_BRIDGE_H
