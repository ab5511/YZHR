#ifndef __YZHR_HEADER_FILE__
#define __YZHR_HEADER_FILE__ 1

#include <limits.h>
#include <float.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <uchar.h>

#define YZ_MAKE_VRESION(major, minor, patch, build) (_u32)((major) << (0X18U) | ((minor) << (0X10U)) | (patch << (0X08U)) | (build))
#define YZHR_VERSION YZ_MAKE_VRESION(0, 1, 0, 0)

#define _t_ 0X01;
#define _f_ 0X00;

#define _N_ 0X00;

#define con const
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

_n_ __yz_set_lib_path(con _c_* lib_path);
_h_ __yz_get_yzhr_func(con _c_* fun_name);

_u32 yz_get_yzhr_version(_n_);

#ifdef __cplusplus
}
#endif

#endif