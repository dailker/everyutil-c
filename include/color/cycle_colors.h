#ifndef COLOR_CYCLE_COLORS_H
#define COLOR_CYCLE_COLORS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/**
 * Type for a callback to apply the current color.
 * @param color A color string (e.g., hex like "#336699").
 */
typedef void (*color_apply_callback)(const char *color);

/**
 * Starts cycling through colors repeatedly, calling the callback every interval_ms.
 *
 * @param colors Array of color strings.
 * @param colors_count Number of colors.
 * @param interval_ms Interval in milliseconds.
 * @param apply_callback Callback to apply the color.
 * @return An opaque pointer (handle) to the cycle, used to stop it.
 */
void *cycle_colors_start(const char **colors, size_t colors_count, unsigned int interval_ms, color_apply_callback apply_callback);

/**
 * Stops a previously started color cycle.
 *
 * @param cycle_handle The handle returned by cycle_colors_start.
 */
void cycle_colors_stop(void *cycle_handle);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_CYCLE_COLORS_H */