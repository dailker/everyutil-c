#ifndef LOGIC_INDEX_OF_FIRST_TRUE_H
#define LOGIC_INDEX_OF_FIRST_TRUE_H

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
 * Finds first index of true value.
 *
 * @param array Array of boolean values.
 * @param size Size of array.
 * @return Index of first true value, -1 if none found.
 */
EVERYUTIL_API int index_of_first_true(const int* array, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_INDEX_OF_FIRST_TRUE_H