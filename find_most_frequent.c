#include "array/find_most_frequent.h"

#include <stdlib.h>

typedef struct {
    double value;
    size_t count;
} freq_entry_t;

EVERYUTIL_API double* find_most_frequent(const double* array, size_t length, size_t* out_count) {
    if (!array || length == 0 || !out_count) return NULL;
    *out_count = 0;

    size_t capacity = 16;
    size_t size = 0;
    freq_entry_t* freq = (freq_entry_t*)malloc(capacity * sizeof(freq_entry_t));
    if (!freq) return NULL;

    // Count frequencies
    for (size_t i = 0; i < length; ++i) {
        double val = array[i];
        size_t j;
        for (j = 0; j < size; ++j) {
            if (freq[j].value == val) {
                freq[j].count++;
                break;
            }
        }
        if (j == size) {
            if (size == capacity) {
                capacity *= 2;
                freq_entry_t* tmp = (freq_entry_t*)realloc(freq, capacity * sizeof(freq_entry_t));
                if (!tmp) {
                    free(freq);
                    return NULL;
                }
                freq = tmp;
            }
            freq[size].value = val;
            freq[size].count = 1;
            size++;
        }
    }

    // Find max frequency
    size_t max_count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (freq[i].count > max_count) {
            max_count = freq[i].count;
        }
    }

    // Count how many have max frequency
    size_t result_count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (freq[i].count == max_count) {
            result_count++;
        }
    }

    if (result_count == 0) {
        free(freq);
        return NULL;
    }

    double* result = (double*)malloc(result_count * sizeof(double));
    if (!result) {
        free(freq);
        return NULL;
    }

    size_t idx = 0;
    for (size_t i = 0; i < size; ++i) {
        if (freq[i].count == max_count) {
            result[idx++] = freq[i].value;
        }
    }

    free(freq);
    *out_count = result_count;
    return result;
}
