#ifndef COLOR_IS_VALID_COLOR_STRING_H
#define COLOR_IS_VALID_COLOR_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stdbool.h>

/**
 * Validates if a string is a valid color string.
 * Supports:
 * - Hex: #RGB or #RRGGBB
 * - rgb(r,g,b)
 * - rgba(r,g,b,a)
 *
 * @param str Null-terminated color string.
 * @return true if valid, false otherwise.
 */
EVERYUTIL_API bool is_valid_color_string(const char* str);

#ifdef __cplusplus
}
#endif

#endif // COLOR_IS_VALID_COLOR_STRING_H
