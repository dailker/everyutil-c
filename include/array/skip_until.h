#ifndef ARRAY_SKIP_UNTIL_H
#define ARRAY_SKIP_UNTIL_H

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
 * Predicate callback signature for skip_until.
 * @param element Pointer to element.
 * @param index Index of element.
 * @param array Pointer to full array.
 * @param length Number of elements in array.
 * @param user_data User data pointer passed through.
 * @return nonzero if predicate matched, 0 otherwise.
 */
typedef int (*skip_until_predicate_fn)(const void* element, size_t index, const void* array, size_t length, void* user_data);

/**
 * Skips elements until predicate returns true, returns newly allocated subarray starting at that element.
 * @param array Pointer to input array.
 * @param length Number of elements in array.
 * @param element_size Size of each element in bytes.
 * @param predicate Predicate function.
 * @param user_data User data pointer passed to predicate.
 * @return Newly allocated array starting at first matching element, or NULL if none found or on error.
 *         Caller must free.
 */
EVERYUTIL_API void* skip_until(const void* array, size_t length, size_t element_size, skip_until_predicate_fn predicate, void* user_data);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_SKIP_UNTIL_H
