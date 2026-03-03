// qacpp_boost.h
//

#ifndef INCLUDED_QACPP_BOOST
#define INCLUDED_QACPP_BOOST

#define BOOST_COMPILER_CONFIG "boost/config/compiler/gcc.hpp"
#define BOOST_NO_EXTERN_TEMPLATE 1
#define BOOST_ASIO_DISABLE_THREAD_KEYWORD_EXTENSION 1

// do not use type trait intrinsics in BOOST
#define __GCCXML__ 1

#endif
