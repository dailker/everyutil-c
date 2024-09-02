#ifndef LOGIC_BOOLEAN_RATE_LIMITER_H
#define LOGIC_BOOLEAN_RATE_LIMITER_H

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
#include <stdlib.h>
typedef int (*predicate_func)(int);

EVERYUTIL_API int boolean_rate_limiter(int input, int current_time, int rate_limit);

#ifdef __cplusplus
}
#endif

#endif