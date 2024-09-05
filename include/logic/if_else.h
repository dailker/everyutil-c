#ifndef LOGIC_IF_ELSE_H
#define LOGIC_IF_ELSE_H

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

typedef int (*predicate_func)(int);
typedef int (*transform_func)(int);

EVERYUTIL_API int if_else(int value, predicate_func predicate, transform_func if_fn, transform_func else_fn);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_IF_ELSE_H