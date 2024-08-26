#ifndef COLOR_COLOR_HASH_H
#define COLOR_COLOR_HASH_H

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

/**
 * Generates a consistent hex color string from an input string.
 *
 * @param inputString Null-terminated input string.
 * @return Newly allocated hex color string (e.g. "#a1b2c3").
 *         Caller must free. Returns NULL on failure.
 */
EVERYUTIL_API char *color_hash(const char *inputString);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_COLOR_HASH_H */
