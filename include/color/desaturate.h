#ifndef COLOR_DESATURATE_H
#define COLOR_DESATURATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef struct {
    unsigned char r, g, b;
} ColorRGB;

typedef struct {
    double h; // 0-360
    double s; // 0-1
    double l; // 0-1
} ColorHSL;

/**
 * Decreases the saturation of a color.
 *
 * @param color A hex string like "#336699".
 * @param amount Amount to decrease saturation (0-1).
 * @return A newly allocated hex string with desaturated color (caller must free), or NULL on failure.
 */
EVERYUTIL_API char* desaturate(const char* color, double amount);

#ifdef __cplusplus
}
#endif

#endif // COLOR_DESATURATE_H
