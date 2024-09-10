#include "color/average_color.h"
#include <stdlib.h>

EVERYUTIL_API uint8_t* average_color(uint8_t colors[][3], size_t count, size_t* out_count) {
    if (!colors || count == 0 || !out_count) {
        if (out_count) *out_count = 0;
        return NULL;
    }

    uint8_t* result = (uint8_t*)malloc(3 * sizeof(uint8_t));
    if (!result) {
        *out_count = 0;
        return NULL;
    }

    uint32_t sum[3] = {0, 0, 0};
    for (size_t i = 0; i < count; i++) {
        sum[0] += colors[i][0];
        sum[1] += colors[i][1];
        sum[2] += colors[i][2];
    }

    result[0] = (uint8_t)(sum[0] / count);
    result[1] = (uint8_t)(sum[1] / count);
    result[2] = (uint8_t)(sum[2] / count);
    *out_count = count;

    return result;
}