#ifndef LOGIC_LOGIC_SWITCH_H
#define LOGIC_LOGIC_SWITCH_H

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

EVERYUTIL_API int logic_switch(int condition, int true_val, int false_val);

#ifdef __cplusplus
}
#endif

#endif