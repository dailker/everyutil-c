#include "array/group_every.h"

#include <stdlib.h>
#include <string.h>

EVERYUTIL_API int group_every(const double* array, size_t length, size_t count,
                              double*** out_groups, size_t* out_group_count) {
    if (!array || !out_groups || !out_group_count || count == 0) return -1;

    size_t groups = length / count;
    if (groups == 0) {
        *out_groups = NULL;
        *out_group_count = 0;
        return 0;
    }

    double** result = (double**)malloc(groups * sizeof(double*));
    if (!result) return -1;

    for (size_t i = 0; i < groups; ++i) {
        result[i] = (double*)malloc(count * sizeof(double));
        if (!result[i]) {
            // free previous groups on failure
            for (size_t j = 0; j < i; ++j) free(result[j]);
            free(result);
            return -1;
        }
        memcpy(result[i], array + i * count, count * sizeof(double));
    }

    *out_groups = result;
    *out_group_count = groups;
    return 0;
}
