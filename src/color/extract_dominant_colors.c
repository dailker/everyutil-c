#include "color/extract_dominant_colors.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    unsigned int r, g, b;
    unsigned int count;
} ColorBin;

// Reduce color depth to group similar colors (4 bits per channel)
#define BIN_SIZE 16
#define MAX_BINS (BIN_SIZE * BIN_SIZE * BIN_SIZE)

static unsigned int hash_color(unsigned char r, unsigned char g, unsigned char b) {
    return ((r >> 4) << 8) | ((g >> 4) << 4) | (b >> 4);
}



static int compare_bins(const void* a, const void* b) {
    return ((ColorBin*)b)->count - ((ColorBin*)a)->count;
}

EVERYUTIL_API char** extract_dominant_colors(const unsigned char* data, size_t width, size_t height, size_t count) {
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

    // Count non-zero bins
    size_t bin_count = 0;
    for (size_t i = 0; i < MAX_BINS; ++i) {
        if (bins[i].count > 0) bin_count++;
    }

    ColorBin* active_bins = (ColorBin*)malloc(sizeof(ColorBin) * bin_count);
    if (!active_bins) {
        free(bins);
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < MAX_BINS; ++i) {
        if (bins[i].count > 0) {
            active_bins[j++] = bins[i];
        }
    }

    qsort(active_bins, bin_count, sizeof(ColorBin), compare_bins);

    size_t result_count = (count < bin_count) ? count : bin_count;
    char** result = (char**)malloc(sizeof(char*) * (result_count + 1));
    if (!result) {
        free(bins);
        free(active_bins);
        return NULL;
    }

    for (size_t i = 0; i < result_count; ++i) {
        result[i] = (char*)malloc(8); // "#RRGGBB" + null
        if (!result[i]) {
            // Clean up previous
            for (size_t k = 0; k < i; ++k) free(result[k]);
            free(result);
            free(bins);
            free(active_bins);
            return NULL;
        }
        snprintf(result[i], 8, "#%02X%02X%02X", active_bins[i].r, active_bins[i].g, active_bins[i].b);
    }
    result[result_count] = NULL;

    free(bins);
    free(active_bins);
    return result;
}