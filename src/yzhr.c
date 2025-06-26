#include <yzhr/yzhr.h>

#if defined(_WIN32) || defined(_WIN64)
#define API_EXPORT __declspec(dllexport)
#else
#define API_EXPORT __attribute__((visibility("default")))
#endif

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else

#endif

#ifdef __cplusplus
extern "C" {
#endif

API_EXPORT _u32 get_yzhr_version(){
    return YZHR_VERSION;
}

#ifdef __cplusplus
}
#endif