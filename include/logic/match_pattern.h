#ifndef LOGIC_MATCH_PATTERN_H
#define LOGIC_MATCH_PATTERN_H

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

EVERYUTIL_API int match_pattern(const int* input, const int* pattern, size_t size);

#ifdef __cplusplus
}
#endif

#endif