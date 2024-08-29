#ifndef SIMULATE_COLOR_BLINDNESS_H
#define SIMULATE_COLOR_BLINDNESS_H
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
typedef enum { PROTANOPIA, DEUTERANOPIA, TRITANOPIA } ColorBlindnessType;
EVERYUTIL_API char *simulate_color_blindness(const char *color, ColorBlindnessType type);
#ifdef __cplusplus
}
#endif
#endif