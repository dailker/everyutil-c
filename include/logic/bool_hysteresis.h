#ifndef LOGIC_BOOL_HYSTERESIS_H
#define LOGIC_BOOL_HYSTERESIS_H

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

EVERYUTIL_API int bool_hysteresis(int input, int high_thresh, int low_thresh);

#ifdef __cplusplus
}
#endif

#endif