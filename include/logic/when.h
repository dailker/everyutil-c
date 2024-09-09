#ifndef LOGIC_WHEN_H
#define LOGIC_WHEN_H

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

EVERYUTIL_API int when(int value, predicate_func predicate, transform_func transform);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_WHEN_H