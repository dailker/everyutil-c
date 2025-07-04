#ifndef ARRAY_SEMANTIC_GROUP_H
#define ARRAY_SEMANTIC_GROUP_H

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
 * Struct representing a group of items with the same semantic type.
 */
typedef struct {
    char* type;           // Semantic type name (dynamically allocated)
    void** items;         // Array of items in the group
    size_t count;         // Number of items in the group
    size_t capacity;      // Allocated capacity of items array
} semantic_group_t;

/**
 * Struct representing the result of semantic grouping.
 */
typedef struct {
    semantic_group_t* groups; // Array of groups
    size_t count;            // Number of groups
    size_t capacity;         // Allocated capacity of groups array
} semantic_group_result_t;

/**
 * Function pointer type for determining the semantic type of an item.
 * @param item The item to classify.
 * @return A string representing the semantic type (caller retains ownership).
 */
typedef const char* (*semantic_type_fn)(void* item);

/**
 * Groups items in the array by their semantic type.
 * @param array Input array of items.
 * @param length Number of items in the array.
 * @param typeFn Function to determine the semantic type of each item.
 * @param out_groups Output struct containing the groups.
 * @return 0 on success, -1 on failure (e.g., memory allocation error).
 * Caller must free the result using semantic_group_free().
 */
EVERYUTIL_API int semantic_group(void** array, size_t length, semantic_type_fn typeFn, semantic_group_result_t* out_groups);

/**
 * Frees the memory allocated for the semantic group result.
 * @param groups The result struct to free.
 */
EVERYUTIL_API void semantic_group_free(semantic_group_result_t* groups);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_SEMANTIC_GROUP_H