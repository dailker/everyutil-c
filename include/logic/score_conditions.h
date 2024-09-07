#ifndef LOGIC_SCORE_CONDITIONS_H
#define LOGIC_SCORE_CONDITIONS_H

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
 * Weighted scoring of boolean conditions.
 *
 * @param weights Array of weights.
 * @param conditions Array of boolean conditions.
 * @param size Size of arrays.
 * @return Total weighted score.
 */
EVERYUTIL_API double score_conditions(const double* weights, const int* conditions, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_SCORE_CONDITIONS_H