#ifndef ARRAY_WITH_INDEX_H
#define ARRAY_WITH_INDEX_H

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
 * Struct to hold an item and its index.
 */
typedef struct {
    void* value;   // Pointer to the item
    size_t index;  // Index of the item in the original array
} with_index_item_t;

/**
 * Creates an array of items paired with their indices.
 * @param array Input array of pointers to items.
 * @param length Number of items in the array.
 * @return Array of with_index_item_t structs, or NULL on error.
 * Caller must free the returned array.
 */
EVERYUTIL_API with_index_item_t* withIndex(void** array, size_t length);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_WITH_INDEX_H