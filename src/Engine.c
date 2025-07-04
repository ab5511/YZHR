#include <vulkan/vulkan.h>
#include <engine/EngineType.h>

#if defined(_WIN32) || defined(_WIN64)
#define __API_EXPORT__ __declspec(dllexport)
#else
#define __API_EXPORT__ __attribute__((visibility("default")))
#endif

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else

#endif

#ifdef __cplusplus
extern "C" {
#endif

sta _n_ (*__log1_funP__)(_log_level_ level, con _c_* who, _h_ hand, con _c_* message) = _N_;
sta _n_ __set_log1_funP__(_n_ (*in_funP)(_log_level_ level, con _c_* who, _h_ hand, con _c_* message)){
    __log1_funP__ = in_funP;
}
sta _n_ __log1__(_log_level_ level, con _c_* who, _h_ hand, con _c_* message){
    if(__log1_funP__){
        __log1_funP__(level, who, hand, message);
    }
}

sta _b_ compare_cs_cs(con _c_* str1, con _c_* str2){
    _u32 i = 0;
    while(str1[i]==str2[i]){
        if(!str1[i]) bak;
        i++;
    }
    ret str1[i]==str2[i];
}

sta _u32 __get_engine_version__(_n_){
    ret __ENGINE_VERSION__;
}

__API_EXPORT__ _h_ __get_engine_func__(con _c_* in_func_name) {
    sta con kev_value_h_ func_kv[] = {
        {"compare_cs_cs", &compare_cs_cs},
        {"__get_engine_func__", &__get_engine_func__},
        {"__set_log1_funP__", &__set_log1_funP__},
        {"__get_engine_version__", &__get_engine_version__}
    };
    sta con _u32 kev_val_count = sizeof(func_kv) /sizeof(kev_value_h_);
    if(in_func_name){
        for(_u32 i = 0; i < kev_val_count; i++){
            if(compare_cs_cs(in_func_name, func_kv[i].kev)){
                __log1__(
                    __E_LEVEL_DEBUG__,
                    in_func_name,
                    func_kv[i].value,
                    "Successfully found this function."
                );
                return func_kv[i].value;
            }
        }
    }
    __log1__(
        __E_LEVEL_ERROR__,
        in_func_name,
        _N_,
        "Failed to find this function."
    );
    ret _N_;
}

#ifdef __cplusplus
}
#endif