#ifndef ARRAY_WITH_INDEX_H
#define ARRAY_WITH_INDEX_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_EXPORTS
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

/**
 * Struct holding an index and a pointer to a value.
 */
typedef struct {
    size_t index;
    void* value;
} with_index_item_t;

/**
 * Transforms an array of pointers [a, b, c] into an array of {index, value} structs.
 * 
 * @param array Array of pointers to values.
 * @param length Number of elements in the array.
 * @return Dynamically allocated array of with_index_item_t structs (caller must free),
 *         or NULL on failure.
 */
EVERYUTIL_API with_index_item_t* withIndex(void** array, size_t length);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_WITH_INDEX_H
