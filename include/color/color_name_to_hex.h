#ifndef COLOR_COLOR_NAME_TO_HEX_H
#define COLOR_COLOR_NAME_TO_HEX_H

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

/**
 * Converts a named CSS color to its hex string.
 *
 * @param name Null-terminated CSS color name (case-insensitive).
 * @return Pointer to a static hex string (e.g. "#87ceeb"), or NULL if not found.
 */
EVERYUTIL_API const char *color_name_to_hex(const char *name);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_COLOR_NAME_TO_HEX_H */
