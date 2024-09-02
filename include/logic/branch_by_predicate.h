#ifndef LOGIC_BRANCH_BY_PREDICATE_H
#define LOGIC_BRANCH_BY_PREDICATE_H

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

EVERYUTIL_API int branch_by_predicate(int value, predicate_func predicate, int true_val, int false_val);

#ifdef __cplusplus
}
#endif

#endif