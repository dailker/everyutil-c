#ifndef LOGIC_COUNT_TRUTHY_H
#define LOGIC_COUNT_TRUTHY_H

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
 * Count how many values are truthy (non-zero).
 *
 * @param values Array of integer values.
 * @param size Size of array.
 * @return Number of truthy values.
 */
EVERYUTIL_API int count_truthy(const int* values, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_COUNT_TRUTHY_H