#ifndef __ENGINE_TYPE_HEADER_FILE__
#define __ENGINE_TYPE_HEADER_FILE__ 1

#include <limits.h>
#include <float.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <uchar.h>

#define __E_VRESION__(major, minor, patch) (_u32)((major %0XFFFU) <<(0X14U) |((minor %0XFFFU) <<(0X8U)) |(patch %0XFFU))
#define __ENGINE_VERSION__ __E_VRESION__(0, 1, 0)

#define __E_LEVEL_INFO__     (_log_level_)(0X00U)
#define __E_LEVEL_DEBUG__    (_log_level_)(0X01U)
#define __E_LEVEL_WARNING__  (_log_level_)(0X02U)
#define __E_LEVEL_ERROR__    (_log_level_)(0X03U)
#define __E_LEVEL_CRITICAL__ (_log_level_)(0X04U)

#define _t_ 0X01U
#define _f_ 0X00U

#define _N_ 0X00U

#define con const
#define sta static
#define ext extern
#define bak break
#define ret return

#ifdef __cplusplus
extern "C" {
#endif

typedef void* _h_;
typedef void _n_;

typedef int8_t _i8;
typedef int16_t _i16;
typedef int32_t _i32;
typedef int64_t _i64;

typedef uint8_t _u8;
typedef uint16_t _u16;
typedef uint32_t _u32;
typedef uint64_t _u64;

typedef char _c_;

typedef float _flo;
typedef double _dou;

typedef _u8 _b_;

typedef _u32 _log_level_;

typedef time_t _T_;

typedef struct kev_value_{
    con _c_* kev;
    _u32 value;
} kev_value;

typedef struct kev_value_h_{
    con _c_* kev;
    _h_ value;
} kev_value_h_;

#ifdef __cplusplus
}
#endif

#endif