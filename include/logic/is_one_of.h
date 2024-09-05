#ifndef LOGIC_IS_ONE_OF_H
#define LOGIC_IS_ONE_OF_H

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

EVERYUTIL_API int is_one_of(int value, const int* values, size_t count);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_IS_ONE_OF_H