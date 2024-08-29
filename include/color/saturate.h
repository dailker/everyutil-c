#ifndef SATURATE_H
#define SATURATE_H
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
EVERYUTIL_API char *saturate(const char *color, double factor);
#ifdef __cplusplus
}
#endif
#endif