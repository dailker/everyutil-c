#ifndef LOGIC_COMPILE_PREDICATE_CHAIN_H
#define LOGIC_COMPILE_PREDICATE_CHAIN_H

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

EVERYUTIL_API int compile_predicate_chain(int value, predicate_func* predicates, size_t count);

#ifdef __cplusplus
}
#endif

#endif