#ifndef PULSE_COLOR_H
#define PULSE_COLOR_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
#include "color/parse_color_string.h"
#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif
EVERYUTIL_API char *pulse_color(const char *color, double intensity);
#ifdef __cplusplus
}
#endif
#endif