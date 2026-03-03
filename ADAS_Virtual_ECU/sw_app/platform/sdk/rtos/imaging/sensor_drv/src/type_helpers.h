#ifndef _TYPE_HELPERS_H_
#define _TYPE_HELPERS_H_

typedef    uint8_t      u8;
typedef    uint16_t     u16;
typedef    uint32_t     u32;
typedef    uint64_t  	u64;

typedef    int8_t		s8;
typedef    int16_t		s16;
typedef    int32_t		s32;
typedef    int64_t  	s64;

#define ARRAY_SIZE(a)	(sizeof(a) / sizeof(*(a)))
#define BIT(x)			(1 << (x))

#define hweight8(w)			\
	((unsigned int)			\
	 ((!!((w) & (1ULL << 0))) +	\
	  (!!((w) & (1ULL << 1))) +	\
	  (!!((w) & (1ULL << 2))) +	\
	  (!!((w) & (1ULL << 3))) +	\
	  (!!((w) & (1ULL << 4))) +	\
	  (!!((w) & (1ULL << 5))) +	\
	  (!!((w) & (1ULL << 6))) +	\
	  (!!((w) & (1ULL << 7)))))


#endif /* _TYPE_HELPERS_H_ */
