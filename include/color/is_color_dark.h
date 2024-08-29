#ifndef IS_COLOR_DARK_H
#define IS_COLOR_DARK_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>
#include "color/parse_hex_color.h"
#include "color/get_brightness.h"
#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif
EVERYUTIL_API bool is_color_dark(const char *hex_color);
#ifdef __cplusplus
}
#endif
#endif