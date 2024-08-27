#ifndef COLOR_FIND_NEAREST_NAMED_COLOR_H
#define COLOR_FIND_NEAREST_NAMED_COLOR_H

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
 * Finds the nearest named CSS color to the given color.
 *
 * @param hex_color A hex color string (e.g., "#87ceeb").
 * @return          A dynamically allocated hex string (e.g., "#87ceeb") matching the closest named color.
 *                  Caller must free the returned string. Returns NULL on error or parse failure.
 */
EVERYUTIL_API char* find_nearest_named_color(const char* hex_color);

#ifdef __cplusplus
}
#endif

#endif // COLOR_FIND_NEAREST_NAMED_COLOR_H
