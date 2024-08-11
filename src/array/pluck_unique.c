#include "array/pluck_unique.h"
#include <stdlib.h>
#include <string.h>

EVERYUTIL_API int pluck_unique_strings(const char** items, size_t length,
                                       char*** out_unique, size_t* out_count) {
    if (!items || !out_unique || !out_count) return -1;
    *out_unique = NULL;
    *out_count = 0;
    if (length == 0) return 0;

    // Worst case: all unique
    char** uniques = (char**)malloc(length * sizeof(char*));
    if (!uniques) return -1;

    size_t count = 0;

    for (size_t i = 0; i < length; ++i) {
        const char* current = items[i];
        int found = 0;
        for (size_t j = 0; j < count; ++j) {
            if (strcmp(uniques[j], current) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            // Copy string
            size_t len = strlen(current);
            char* copy = (char*)malloc(len + 1);
            if (!copy) {
                for (size_t k = 0; k < count; ++k) free(uniques[k]);
                free(uniques);
                return -1;
            }
            strcpy(copy, current);
            uniques[count++] = copy;
        }
    }

    *out_unique = uniques;
    *out_count = count;
    return 0;
}
