#ifndef COLOR_GENERATE_PALETTE_H
#define COLOR_GENERATE_PALETTE_H

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
 * Generates a color palette based on a color scheme type.
 *
 * @param base_hex The base color in hex format (e.g., "#336699").
 * @param scheme_type The scheme type: "complementary", "triadic", "analogous", or other.
 * @return Dynamically allocated NULL-terminated array of hex strings. Caller must free each string and the array.
 */
EVERYUTIL_API char** generate_palette(const char* base_hex, const char* scheme_type);

#ifdef __cplusplus
}
#endif

#endif // COLOR_GENERATE_PALETTE_H