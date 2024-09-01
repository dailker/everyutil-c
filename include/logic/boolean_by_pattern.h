#ifndef LOGIC_BOOLEAN_BY_PATTERN_H
#define LOGIC_BOOLEAN_BY_PATTERN_H

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

EVERYUTIL_API int boolean_by_pattern(int index, const int* pattern, size_t pattern_size);

#ifdef __cplusplus
}
#endif

#endif