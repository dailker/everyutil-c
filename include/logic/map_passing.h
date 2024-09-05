#ifndef LOGIC_MAP_PASSING_H
#define LOGIC_MAP_PASSING_H

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

EVERYUTIL_API int map_passing(const int* values, size_t count, predicate_func predicate, int* result);

#ifdef __cplusplus
}
#endif

#endif