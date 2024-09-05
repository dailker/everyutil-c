#ifndef LOGIC_IS_EQUAL_TO_H
#define LOGIC_IS_EQUAL_TO_H

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

EVERYUTIL_API int is_equal_to(int value, int target);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_IS_EQUAL_TO_H