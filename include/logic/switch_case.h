#ifndef LOGIC_SWITCH_CASE_H
#define LOGIC_SWITCH_CASE_H

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
typedef int (*transform_func)(int);

EVERYUTIL_API int switch_case(int input, const int* cases, const int* values, size_t count, int default_val);

#ifdef __cplusplus
}
#endif

#endif