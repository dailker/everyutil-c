#ifndef LOGIC_FIRST_TRUTHY_H
#define LOGIC_FIRST_TRUTHY_H

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

EVERYUTIL_API int first_truthy(const int* values, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_FIRST_TRUTHY_H