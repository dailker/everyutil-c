#ifndef LOGIC_RUN_IF_H
#define LOGIC_RUN_IF_H

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

EVERYUTIL_API void run_if(int condition, void (*action)(void));

#ifdef __cplusplus
}
#endif

#endif // LOGIC_RUN_IF_H