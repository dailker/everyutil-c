#ifndef LOGIC_XOR_PREDICATES_H
#define LOGIC_XOR_PREDICATES_H

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

EVERYUTIL_API int xor_predicates(int value, predicate_func pred1, predicate_func pred2);

#ifdef __cplusplus
}
#endif

#endif