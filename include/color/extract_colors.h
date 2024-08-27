#ifndef COLOR_EXTRACT_COLORS_H
#define COLOR_EXTRACT_COLORS_H

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
 * Extracts CSS color values from a CSS string.
 *
 * @param cssString Input CSS string.
 * @param outCount Pointer to size_t to receive number of extracted colors.
 * @return Dynamically allocated array of dynamically allocated strings representing colors.
 *         The caller must free each string and then free the array.
 *         Returns NULL on failure or if no colors found.
 */
EVERYUTIL_API char **extractColorsFromCss(const char *cssString, size_t *outCount);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_EXTRACT_COLORS_H */
