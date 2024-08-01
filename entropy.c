#include "array/entropy.h"

#include <stdlib.h>
#include <math.h>

typedef struct {
    double value;
    size_t count;
} freq_entry_t;

EVERYUTIL_API double entropy(const double* array, size_t length) {
    if (!array || length == 0) return 0.0;

    // Dynamic array for frequency entries
    size_t capacity = 16;
    size_t size = 0;
    freq_entry_t* freq = (freq_entry_t*)malloc(capacity * sizeof(freq_entry_t));
    if (!freq) return 0.0;

    // Count frequencies (simple linear search)
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
            // New value, add entry
            if (size == capacity) {
                capacity *= 2;
                freq_entry_t* temp = (freq_entry_t*)realloc(freq, capacity * sizeof(freq_entry_t));
                if (!temp) {
                    free(freq);
                    return 0.0;
                }
                freq = temp;
            }
            freq[size].value = val;
            freq[size].count = 1;
            size++;
        }
    }

    double ent = 0.0;
    double n = (double)length;

    for (size_t i = 0; i < size; ++i) {
        double p = freq[i].count / n;
        ent -= p * log2(p);
    }

    free(freq);
    return ent;
}
