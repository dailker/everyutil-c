#ifndef ARRAY_SORT_BY_SCHEMA_H
#define ARRAY_SORT_BY_SCHEMA_H

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
 * Function pointer to compare two elements (like strcmp).
 * Should return 0 if equal, non-zero otherwise.
 */
typedef int (*equals_fn)(const void* a, const void* b, void* user_data);

/**
 * Function pointer to hash an element into size_t.
 */
typedef size_t (*hash_fn)(const void* elem, void* user_data);

/**
 * Sorts `array` based on the order defined by `schema`.
 * Elements not in `schema` are considered greater and appear last.
 *
 * @param array Pointer to input array.
 * @param length Number of elements in array.
 * @param element_size Size of each element.
 * @param schema Pointer to schema array.
 * @param schema_length Number of elements in schema.
 * @param equals Function to check equality of elements.
 * @param hash Function to hash elements (not strictly required, can be NULL).
 * @param user_data User data pointer passed to equals/hash.
 * @return Newly allocated sorted array, or NULL on failure.
 *         Caller must free.
 */
EVERYUTIL_API void* sort_by_schema(
    const void* array,
    size_t length,
    size_t element_size,
    const void* schema,
    size_t schema_length,
    equals_fn equals,
    hash_fn hash,
    void* user_data);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_SORT_BY_SCHEMA_H
