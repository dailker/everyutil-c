#ifndef COLOR_DESATURATE_H
#define COLOR_DESATURATE_H

#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include "color/rgb_to_hsl.h"  // Include this to get ColorHSL

#ifdef __cplusplus
extern "C" {
#endif

EVERYUTIL_API char* desaturate(const char* color, double amount);

#ifdef __cplusplus
}
#endif

#endif // COLOR_DESATURATE_H