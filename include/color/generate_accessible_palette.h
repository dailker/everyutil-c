#ifndef COLOR_GENERATE_ACCESSIBLE_PALETTE_H
#define COLOR_GENERATE_ACCESSIBLE_PALETTE_H

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

#include <stddef.h>

/**
 * Generates a palette of colors that meet accessibility contrast standards.
 *
 * @param base_color A base color as a hex string (e.g., "#336699").
 * @return           NULL-terminated array of dynamically allocated hex strings.
 *                   Each is an accessible color (contrast ≥ 4.5).
 *                   Caller must free each string and the array.
 */
EVERYUTIL_API char** generate_accessible_palette(const char* base_color);

#ifdef __cplusplus
}
#endif

#endif // COLOR_GENERATE_ACCESSIBLE_PALETTE_H