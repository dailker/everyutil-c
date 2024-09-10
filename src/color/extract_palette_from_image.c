#include "color/extract_palette_from_image.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    unsigned int r, g, b;
    unsigned int count;
} ColorBin;

#define BIN_SIZE 16
#define MAX_BINS (BIN_SIZE * BIN_SIZE * BIN_SIZE)

static unsigned int hash_color(unsigned char r, unsigned char g, unsigned char b) {
    return ((r >> 4) << 8) | ((g >> 4) << 4) | (b >> 4);
}

static int compare_bins(const void* a, const void* b) {
    return ((ColorBin*)b)->count - ((ColorBin*)a)->count;
}

EVERYUTIL_API char** extract_palette_from_image(const unsigned char* data, size_t width, size_t height, size_t count) {
    if (!data || width == 0 || height == 0 || count == 0) return NULL;

    ColorBin* bins = (ColorBin*)calloc(MAX_BINS, sizeof(ColorBin));
    if (!bins) return NULL;

    size_t pixels = width * height;
    for (size_t i = 0; i < pixels; ++i) {
        unsigned char r = data[i * 3];
        unsigned char g = data[i * 3 + 1];
        unsigned char b = data[i * 3 + 2];
        unsigned int bin = hash_color(r, g, b);

        bins[bin].r = (bins[bin].r * bins[bin].count + r) / (bins[bin].count + 1);
        bins[bin].g = (bins[bin].g * bins[bin].count + g) / (bins[bin].count + 1);
        bins[bin].b = (bins[bin].b * bins[bin].count + b) / (bins[bin].count + 1);
        bins[bin].count += 1;
    }

    size_t used = 0;
    for (size_t i = 0; i < MAX_BINS; ++i) {
        if (bins[i].count > 0) ++used;
    }

    ColorBin* active = (ColorBin*)malloc(used * sizeof(ColorBin));
    if (!active) {
        free(bins);
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < MAX_BINS; ++i) {
        if (bins[i].count > 0) active[j++] = bins[i];
    }

    qsort(active, used, sizeof(ColorBin), compare_bins);

    size_t palette_size = (count < used) ? count : used;
    char** result = (char**)malloc(sizeof(char*) * (palette_size + 1));
    if (!result) {
        free(bins);
        free(active);
        return NULL;
    }

    for (size_t i = 0; i < palette_size; ++i) {
        result[i] = (char*)malloc(8); // "#RRGGBB" + null
        if (!result[i]) {
            for (size_t k = 0; k < i; ++k) free(result[k]);
            free(result);
            free(bins);
            free(active);
            return NULL;
        }
        snprintf(result[i], 8, "#%02X%02X%02X", active[i].r, active[i].g, active[i].b);
    }

    result[palette_size] = NULL;
    free(bins);
    free(active);
    return result;
}
