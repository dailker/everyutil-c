#ifndef ARRAY_ARRAY_UNIQUE_BY_KEY_H
#define ARRAY_ARRAY_UNIQUE_BY_KEY_H

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
 * Callback to extract an integer key from a struct item.
 * @param item Pointer to an item in the array.
 * @return Key as an integer.
 */
typedef int (*KeyFnInt)(const void* item);

/**
 * Deduplicates an array of structs by a user-supplied key function.
 *
 * @param array Pointer to input array of structs.
 * @param item_size Size in bytes of one element.
 * @param length Number of elements in array.
 * @param key_fn Function to extract integer key from an element.
 * @param out_len Pointer to size_t to receive result length.
 * @return New array with unique elements (caller must free), or NULL on error.
 */
EVERYUTIL_API void* array_unique_by_key(
    const void* array,
    size_t item_size,
    size_t length,
    KeyFnInt key_fn,
    size_t* out_len
);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ARRAY_UNIQUE_BY_KEY_H
