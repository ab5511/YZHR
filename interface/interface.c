#include <engine/Engine.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else//defined(_WIN32) || defined(_WIN64)

#if defined(__APPLE__) && defined(__MACH__)
#elif defined(__linux__)
#endif//defined(__APPLE__) && defined(__MACH__)

#include <dlfcn.h>
#endif//defined(_WIN32) || defined(_WIN64)

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
sta con _c_* __lib_path__ = "./engine.dll";
#elif defined(__APPLE__) && defined(__MACH__)
sta con _c_* __lib_path__ = "./libengine.dylib";
#elif defined(__linux__)
sta con _c_* __lib_path__ = "./libengine.so";
#else
sta con _c_* __lib_path__ = "./libengine.so";
#endif

sta _n_ (*_Elog1_funP_)(Elog1_context_T context) = _N_;
sta _n_ _Elog1_(Elog1_context_T context){
    if(_Elog1_funP_){
        _Elog1_funP_(context);
    }
}
_n_ __Elog1__(_log_level_ level, con _c_* who, _h_ hand, con _c_* message){
    _Elog1_((Elog1_context_T){.level = level, .who = who, .hand = hand, .message = message});
}

_n_ Eset_find_engine_lib_path(con _c_* lib_path){
    __lib_path__ = lib_path;
}

#if defined(_WIN32) || defined(_WIN64)
sta HMODULE Edll = _N_;
#else
sta _h_ Edll = _N_;
#endif
_h_ Efind_engine_func(con _c_* func_name){
#if defined(_WIN32) || defined(_WIN64)
    if(!Edll){
        Edll = LoadLibraryA(__lib_path__);
        if(!Edll){
            _Elog1_((Elog1_context_T){
                .level = __E_LEVEL_CRITICAL__,
                .who = "Engine interface lib",
                .hand = Edll,
                .message = "Failed to load engine library."
            });
            ret _N_;
        }
    }
    ret GetProcAddress(Edll, func_name);
#else
    if(!Edll){
        Edll = dlopen(__lib_path__, RTLD_LAZY);
        if(!Edll){
            _Elog1_((Elog1_context_T){
                .level = __E_LEVEL_CRITICAL__,
                .who = "Engine interface lib",
                .hand = Edll,
                .message = "Failed to load engine library."
            });
            ret _N_;
        }
    }
    ret dlsym(Edll, func_name);
#endif
}

sta _h_ (*__Eget_engine_func__)(con _c_* func_name) = _N_;
_h_ Eget_engine_func(con _c_* func_name){
    if(!__Eget_engine_func__){
        __Eget_engine_func__ = (_h_ (*)(con _c_* func_name))Efind_engine_func("__get_engine_func__");
        if(!__Eget_engine_func__){
            ret _N_;
        }
    }
    ret __Eget_engine_func__(func_name);
}

_b_ Eis_engine_dll_loaded(_n_){
    _b_ result = !(Eget_engine_func("__get_engine_func__") == _N_);
    if(result){
        _Elog1_((Elog1_context_T){
            .level = __E_LEVEL_INFO__,
            .who = "Engine interface lib",
            .hand = (_h_)Edll,
            .message = "Engine dll is loaded"
        });
    } else {
        _Elog1_((Elog1_context_T){
            .level = __E_LEVEL_WARNING__,
            .who = "Engine interface lib",
            .hand = (_h_)Edll,
            .message = "Engine dll is not loaded"
        });
    }
    ret result;
}

sta _u32 (*__E_get_engine_version__funP)(_n_) = _N_;
_u32 E_get_engine_version(_n_){
    if(!__E_get_engine_version__funP){
        __E_get_engine_version__funP = (_u32(*)(_n_))Eget_engine_func("__get_engine_version__");
        if(!__E_get_engine_version__funP){
            ret _N_;
        }
    }
    ret __E_get_engine_version__funP();
}

sta _n_ (*_E_log1_set_funP_)(_n_ (*in_funP)(_log_level_ level, con _c_* who, _h_ hand, con _c_* message)) = _N_;
_b_ Eset_log1(_n_ (*in_funP)(Elog1_context_T context)){
    if(in_funP){
        _Elog1_funP_ = in_funP;
        if(!_E_log1_set_funP_){
            _E_log1_set_funP_ = (_n_ (*)(_n_ (*in_funP)(_log_level_ level, con _c_* who, _h_ hand, con _c_* message)))Eget_engine_func("__set_log1_funP__");
        }
        if(_E_log1_set_funP_){
            _E_log1_set_funP_(&__Elog1__);
            ret _t_;
        }
    }
    _Elog1_((Elog1_context_T){
        .level = __E_LEVEL_ERROR__,
        .who = "Engine interface lib",
        .hand = (_h_)Edll,
        .message = "Failed to set log function."
    });
    ret _f_;
}

sta _b_ (*__E_compare_cs_cs__funP)(con _c_* str1, con _c_* str2) = _N_;
_b_ E_compare_cs_cs(con _c_* str1, con _c_* str2, _b_* is_success){
    if(!__E_compare_cs_cs__funP){
        __E_compare_cs_cs__funP = (_b_(*)(con _c_*, con _c_*))Eget_engine_func("compare_cs_cs");
        if(!__E_compare_cs_cs__funP){
            if(is_success){
                *is_success = _f_;
            }
            _Elog1_((Elog1_context_T){
                .level = __E_LEVEL_ERROR__,
                .who = "Engine interface lib",
                .hand = (_h_)Edll,
                .message = "Failed to get compare_cs_cs function."
            });
            ret _N_;
        }
    }
    if(is_success){
        *is_success = _t_;
    }
    ret __E_compare_cs_cs__funP(str1, str2);
}

const struct dll_set_T dll_set = {
    .get_version = &E_get_engine_version,
    .compare_cs_cs = &E_compare_cs_cs,
    .get_engine_func = &Eget_engine_func
};

#ifdef __cplusplus
}
#endif