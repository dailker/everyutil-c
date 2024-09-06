#ifndef LOGIC_ONCE_H
#define LOGIC_ONCE_H

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

#include <stddef.h>

typedef int (*predicate_func)(int);

EVERYUTIL_API int once(void (*fn)(void));

#ifdef __cplusplus
}
#endif

#endif // LOGIC_ONCE_H