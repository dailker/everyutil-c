#ifndef ARRAY_PIVOT_H
#define ARRAY_PIVOT_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

/**
 * Represents a key-value pair: key is string, value is double.
 */
typedef struct {
    char* key;    // dynamically allocated string, must be freed by caller
    double value;
} pivot_entry_t;

/**
 * Pivots an array of key-value structs into a unique key-value map.
 *
 * @param keys Array of null-terminated strings (keys).
 * @param values Array of doubles (values).
 * @param length Number of elements in keys and values.
 * @param out_entries Output pointer to dynamically allocated array of pivot_entry_t.
 *                    Caller must free the array and each entry's key string.
 * @param out_count Output count of unique keys.
 * @return 0 on success, non-zero on failure.
 */
EVERYUTIL_API int pivot(const char** keys, const double* values, size_t length,
                        pivot_entry_t** out_entries, size_t* out_count);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_PIVOT_H
