#include "color/closest_color.h"
#include "color/color_distance.h"

EVERYUTIL_API const uint8_t* closest_color(const uint8_t target[3], const uint8_t palette[][3], size_t palette_size) {
    if (!target || !palette || palette_size == 0) return NULL;

    const uint8_t* closest = palette[0];
    double min_distance = color_distance(target, palette[0]);
    if (min_distance < 0) return NULL;

    for (size_t i = 1; i < palette_size; i++) {
        double distance = color_distance(target, palette[i]);
        if (distance < 0) return NULL;
        if (distance < min_distance) {
            min_distance = distance;
            closest = palette[i];
        }
    }

    return closest;
}