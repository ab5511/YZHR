#ifndef __ENGINE_HEADER_FILE__
#define __ENGINE_HEADER_FILE__ 1

#include <engine/EngineType.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Elog1_context_T{
    _log_level_ level;
    con _c_* who;
    _h_ hand;
    con _c_* message;
} Elog1_context_T;

struct dll_set_T{
    _u32 (*get_version)(_n_);
    _b_ (*compare_cs_cs)(con _c_* str1, con _c_* str2, _b_* is_success);
    _h_ (*get_engine_func)(con _c_* func_name);
} ext const dll_set;

_b_ Eis_engine_dll_loaded(_n_);
_n_ Eset_find_engine_lib_path(con _c_* lib_path);
_h_ Efind_engine_func(con _c_* func_name);
_h_ Eget_engine_func(con _c_* func_name);
_u32 E_get_engine_version(_n_);
_b_ E_compare_cs_cs(con _c_* str1, con _c_* str2, _b_* is_success);
_b_ Eset_log1(_n_ (*in_funP)(Elog1_context_T context));

#ifdef __cplusplus
}
#endif

#endif