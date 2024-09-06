#ifndef LOGIC_MAJORITY_TRUTHY_H
#define LOGIC_MAJORITY_TRUTHY_H

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
 * Returns true if majority of values are truthy.
 *
 * @param values Array of values to check.
 * @param size Size of array.
 * @return 1 if majority truthy, 0 otherwise.
 */
EVERYUTIL_API int majority_truthy(const int* values, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_MAJORITY_TRUTHY_H