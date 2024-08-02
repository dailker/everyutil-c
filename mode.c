#include "array/mode.h"
#include <stdlib.h>
#include <string.h>

/*
 * Helper struct for frequency table entry.
 */
typedef struct {
    double value;
    size_t count;
} freq_entry_t;

EVERYUTIL_API int mode(const double* array, size_t length,
                       double** out_modes, size_t* out_mode_count) {
    if (!array || !out_modes || !out_mode_count || length == 0) {
        if (out_modes) *out_modes = NULL;
        if (out_mode_count) *out_mode_count = 0;
        return 0; // empty input, no modes
    }

    // Allocate worst-case freq table (all distinct)
    freq_entry_t* freq = (freq_entry_t*)malloc(length * sizeof(freq_entry_t));
    if (!freq) return -1;

    size_t freq_size = 0;
    size_t max_count = 0;

    // Build frequency table (O(n^2))
    for (size_t i = 0; i < length; ++i) {
        double val = array[i];
        size_t j;
        for (j = 0; j < freq_size; ++j) {
            if (freq[j].value == val) {
                freq[j].count++;
                if (freq[j].count > max_count) max_count = freq[j].count;
                break;
            }
        }
        if (j == freq_size) {
            freq[freq_size].value = val;
            freq[freq_size].count = 1;
            if (1 > max_count) max_count = 1;
            freq_size++;
        }
    }

    // Count how many have max_count
    size_t mode_count = 0;
    for (size_t i = 0; i < freq_size; ++i) {
        if (freq[i].count == max_count) mode_count++;
    }

    double* modes = (double*)malloc(mode_count * sizeof(double));
    if (!modes) {
        free(freq);
        return -1;
    }

    size_t idx = 0;
    for (size_t i = 0; i < freq_size; ++i) {
        if (freq[i].count == max_count) {
            modes[idx++] = freq[i].value;
        }
    }

    free(freq);

    *out_modes = modes;
    *out_mode_count = mode_count;
    return 0;
}
