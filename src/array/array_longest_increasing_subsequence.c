#include "array/array_longest_increasing_subsequence.h"
#include <stdlib.h>

EVERYUTIL_API double* array_longest_increasing_subsequence(
    const double* array,
    size_t length,
    size_t* out_length
) {
    if (!array || length == 0 || !out_length) {
        return NULL;
    }

    int* dp = (int*)malloc(length * sizeof(int));
    int* prev = (int*)malloc(length * sizeof(int));
    if (!dp || !prev) {
        free(dp);
        free(prev);
        return NULL;
    }

    for (size_t i = 0; i < length; ++i) {
        dp[i] = 1;
        prev[i] = -1;
    }

    int max_len = 1;
    size_t max_idx = 0;

    for (size_t i = 1; i < length; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (array[i] > array[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = (int)j;
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            max_idx = i;
        }
    }

    double* result = (double*)malloc(max_len * sizeof(double));
    if (!result) {
        free(dp);
        free(prev);
        return NULL;
    }

    int idx = max_len - 1;
    for (int i = (int)max_idx; i != -1; i = prev[i]) {
        result[idx--] = array[i];
    }

    free(dp);
    free(prev);
    *out_length = (size_t)max_len;
    return result;
}
