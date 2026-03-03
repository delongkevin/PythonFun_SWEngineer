// qacpp_inttypes.h
//

#ifndef INCLUDED_QACPP_INTTYPES
#define INCLUDED_QACPP_INTTYPES

#define QACPP_8_INT_TYPE signed char
#define QACPP_16_INT_TYPE signed short
#define QACPP_32_INT_TYPE signed int
#define QACPP_64_INT_TYPE signed long long
#define QACPP_8_UINT_TYPE unsigned char
#define QACPP_16_UINT_TYPE unsigned short
#define QACPP_32_UINT_TYPE unsigned int
#define QACPP_64_UINT_TYPE unsigned long long
# define __intN_t(N, MODE) \
 typedef QACPP_##N##_INT_TYPE int##N##_t;
# define __u_intN_t(N, MODE) \
 typedef QACPP_##N##_UINT_TYPE u_int##N##_t;


#endif
