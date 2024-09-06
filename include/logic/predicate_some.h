#ifndef LOGIC_PREDICATE_SOME_H
#define LOGIC_PREDICATE_SOME_H

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

EVERYUTIL_API int predicate_some(const int* values, size_t count, predicate_func predicate);

#ifdef __cplusplus
}
#endif

#endif