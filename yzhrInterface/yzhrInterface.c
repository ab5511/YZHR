#include <yzhr/yzhr.h>
#include <stdio.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else//defined(_WIN32) || defined(_WIN64)

#if defined(__APPLE__) && defined(__MACH__)
#elif defined(__linux__)
#endif//defined(__APPLE__) && defined(__MACH__)

#include <dlfcn.h>
#endif//defined(_WIN32) || defined(_WIN64)

#if defined(_WIN32) || defined(_WIN64)
con _c_* __lib_path__ = "./yzhr.dll";
#elif defined(__APPLE__) && defined(__MACH__)
con _c_* __lib_path__ = "./libyzhr.dylib";
#elif defined(__linux__)
con _c_* __lib_path__ = "./libyzhr.so";
#else
con _c_* __lib_path__ = "./libyzhr.so";
#endif

_n_ __yz_set_lib_path(con _c_* lib_path){
    __lib_path__ = lib_path;
}

#if defined(_WIN32) || defined(_WIN64)
HMODULE y_dll = _N_;
#else
_h_ y_dll = _N_;
#endif
_h_ __yz_get_yzhr_func(con _c_* fun_name){
#if defined(_WIN32) || defined(_WIN64)
    if(!y_dll){
        y_dll = LoadLibraryA(__lib_path__);
        if(!y_dll){
            ret _N_;
        }
    }
    ret GetProcAddress(y_dll, fun_name);
#else
    if(!y_dll){
        y_dll = dlopen(__lib_path__, RTLD_LAZY);
        if(!y_dll){
            ret _N_;
        }
    }
    ret dlsym(y_dll, fun_name);
#endif
}

_u32 (*__yz_get_yzhr_version_pfun__)(_n_) = _N_;
_u32 yz_get_yzhr_version(_n_){
    if(!__yz_get_yzhr_version_pfun__){
        __yz_get_yzhr_version_pfun__ = (_u32(*)(_n_))__yz_get_yzhr_func("get_yzhr_version");
        if(!__yz_get_yzhr_version_pfun__){
            ret _N_;
        }
    }
    ret __yz_get_yzhr_version_pfun__();
}