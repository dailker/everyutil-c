#ifndef RGB_TO_HEX_H
#define RGB_TO_HEX_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif
EVERYUTIL_API char *rgb_to_hex(int r, int g, int b);
#ifdef __cplusplus
}
#endif
#endif