#include "array/pivot.h"
#include <stdlib.h>
#include <string.h>

EVERYUTIL_API int pivot(const char** keys, const double* values, size_t length,
                        pivot_entry_t** out_entries, size_t* out_count) {
    if (!keys || !values || !out_entries || !out_count) {
        return -1;
    }
    *out_entries = NULL;
    *out_count = 0;
    if (length == 0) return 0;

    // Worst case: all unique keys
    pivot_entry_t* entries = (pivot_entry_t*)malloc(length * sizeof(pivot_entry_t));
    if (!entries) return -1;

    size_t count = 0;

    for (size_t i = 0; i < length; ++i) {
        // Check if key already exists, update value if so
        size_t j;
        for (j = 0; j < count; ++j) {
            if (strcmp(entries[j].key, keys[i]) == 0) {
                entries[j].value = values[i];
                break;
            }
        }
        if (j == count) {
            // New key: allocate and copy key string
            size_t key_len = strlen(keys[i]);
            char* key_copy = (char*)malloc(key_len + 1);
            if (!key_copy) {
                // Free allocated keys before returning error
                for (size_t k = 0; k < count; ++k) {
                    free(entries[k].key);
                }
                free(entries);
                return -1;
            }
            strcpy(key_copy, keys[i]);
            entries[count].key = key_copy;
            entries[count].value = values[i];
            count++;
        }
    }

    *out_entries = entries;
    *out_count = count;
    return 0;
}
