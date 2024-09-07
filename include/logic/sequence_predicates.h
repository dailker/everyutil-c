#ifndef LOGIC_SEQUENCE_PREDICATES_H
#define LOGIC_SEQUENCE_PREDICATES_H

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

EVERYUTIL_API int sequence_predicates(int value, predicate_func* predicates, size_t count);

#ifdef __cplusplus
}
#endif

#endif