#ifndef LOGIC_UNLESS_H
#define LOGIC_UNLESS_H

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

EVERYUTIL_API int unless(int value, predicate_func predicate, transform_func transform);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_UNLESS_H