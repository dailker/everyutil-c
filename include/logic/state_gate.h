#ifndef LOGIC_STATE_GATE_H
#define LOGIC_STATE_GATE_H

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

EVERYUTIL_API int state_gate(int input, int enable);

#ifdef __cplusplus
}
#endif

#endif