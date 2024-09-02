#ifndef LOGIC_BOOLEAN_WEIGHTED_AVERAGE_H
#define LOGIC_BOOLEAN_WEIGHTED_AVERAGE_H

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
 * Calculates weighted average of boolean results.
 *
 * @param results Array of boolean results.
 * @param weights Array of weights.
 * @param size Size of arrays.
 * @return Weighted average (0.0 to 1.0).
 */
EVERYUTIL_API double boolean_weighted_average(const int* results, const double* weights, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_BOOLEAN_WEIGHTED_AVERAGE_H