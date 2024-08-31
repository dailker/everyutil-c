#ifndef LOGIC_ALL_SAME_H
#define LOGIC_ALL_SAME_H

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
 * Checks if all boolean values are identical.
 *
 * @param array Array of boolean values.
 * @param size Size of array.
 * @return 1 if all same, 0 otherwise.
 */
EVERYUTIL_API int all_same(const int* array, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_ALL_SAME_H