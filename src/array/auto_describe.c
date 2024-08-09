#include "array/auto_describe.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static int compare_double(const void* a, const void* b) {
    double da = *(const double*)a;
    double db = *(const double*)b;
    return (da > db) - (da < db);
}

static int compare_string(const void* a, const void* b) {
    const char* sa = *(const char* const*)a;
    const char* sb = *(const char* const*)b;
    return strcmp(sa, sb);
}

static bool is_sorted_numeric(const double* arr, size_t len) {
    for (size_t i = 1; i < len; ++i) {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

static bool is_sorted_string(char* const* arr, size_t len) {
    for (size_t i = 1; i < len; ++i) {
        if (strcmp(arr[i], arr[i-1]) < 0) return false;
    }
    return true;
}

static size_t count_unique_numbers(const double* arr, size_t len) {
    if (len == 0) return 0;
    double* copy = malloc(len * sizeof(double));
    if (!copy) return 0;
    memcpy(copy, arr, len * sizeof(double));
    qsort(copy, len, sizeof(double), compare_double);

    size_t unique_count = 1;
    for (size_t i = 1; i < len; ++i) {
        if (copy[i] != copy[i-1]) unique_count++;
    }
    free(copy);
    return unique_count;
}

static size_t count_unique_strings(char* const* arr, size_t len) {
    if (len == 0) return 0;
    char** copy = malloc(len * sizeof(char*));
    if (!copy) return 0;
    memcpy(copy, arr, len * sizeof(char*));
    qsort(copy, len, sizeof(char*), compare_string);

    size_t unique_count = 1;
    for (size_t i = 1; i < len; ++i) {
        if (strcmp(copy[i], copy[i-1]) != 0) unique_count++;
    }
    free(copy);
    return unique_count;
}

EVERYUTIL_API char* auto_describe(const void* array, size_t length, ArrayType type) {
    if (!array) return NULL;

    // Compose description components
    const char* type_str = (type == ARRAY_TYPE_NUMBER) ? "number" : "string";

    size_t unique = 0;
    char mean_buf[64] = "";
    char sorted_buf[32] = "";

    if (type == ARRAY_TYPE_NUMBER) {
        const double* nums = (const double*)array;
        unique = count_unique_numbers(nums, length);

        // mean
        if (length > 0) {
            double sum = 0;
            for (size_t i = 0; i < length; ++i) sum += nums[i];
            double avg = sum / length;
            snprintf(mean_buf, sizeof(mean_buf), ", mean: %.2f", avg);
        }

        // sorted check
        if (is_sorted_numeric(nums, length)) {
            snprintf(sorted_buf, sizeof(sorted_buf), ", sorted ascending");
        }

    } else { // string
        char* const* strs = (char* const*)array;
        unique = count_unique_strings(strs, length);

        // no mean for strings

        if (is_sorted_string(strs, length)) {
            snprintf(sorted_buf, sizeof(sorted_buf), ", sorted ascending");
        }
    }

    // Allocate and build final string
    char* result = NULL;
    size_t needed = snprintf(NULL, 0,
        "Array of %zu %ss%s, %zu unique values%s",
        length, type_str, mean_buf, unique, sorted_buf);

    result = malloc(needed + 1);
    if (!result) return NULL;

    snprintf(result, needed + 1,
        "Array of %zu %ss%s, %zu unique values%s",
        length, type_str, mean_buf, unique, sorted_buf);

    return result;
}
