#ifndef ARRAY_FIND_MOST_FREQUENT_H
#define ARRAY_FIND_MOST_FREQUENT_H

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
 * Finds the most frequently occurring element(s) in a double array.
 *
 * @param array Pointer to input array of doubles.
 * @param length Number of elements in the array.
 * @param out_count Pointer to size_t where number of results will be stored.
 * @return Dynamically allocated array of most frequent values (caller must free),
 *         or NULL if input is empty or on failure.
 */
EVERYUTIL_API double* find_most_frequent(const double* array, size_t length, size_t* out_count);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_FIND_MOST_FREQUENT_H
