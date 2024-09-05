#ifndef LOGIC_IS_NOT_NIL_H
#define LOGIC_IS_NOT_NIL_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

EVERYUTIL_API int is_not_nil(void* val);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_IS_NOT_NIL_H