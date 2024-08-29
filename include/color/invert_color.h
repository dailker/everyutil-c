#ifndef INVERT_COLOR_H
#define INVERT_COLOR_H
#ifdef __cplusplus
extern "C" {
#endif
#include "color/parse_hex_color.h"
#include "color/rgb_to_hex.h"
#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif
EVERYUTIL_API char *invert_color(const char *hex_color);
#ifdef __cplusplus
}
#endif
#endif