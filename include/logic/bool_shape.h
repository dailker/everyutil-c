#ifndef LOGIC_BOOL_SHAPE_H
#define LOGIC_BOOL_SHAPE_H

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

EVERYUTIL_API int bool_shape(const int* values, size_t size, const int* shape, size_t shape_size);

#ifdef __cplusplus
}
#endif

#endif