#ifndef LOGIC_BOOL_GAP_LENGTHS_H
#define LOGIC_BOOL_GAP_LENGTHS_H

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
 * Returns lengths of gaps between true clusters.
 *
 * @param array Array of boolean values.
 * @param size Size of array.
 * @param gaps Output array for gap lengths.
 * @param max_gaps Maximum number of gaps to store.
 * @return Number of gaps found.
 */
EVERYUTIL_API int bool_gap_lengths(const int* array, size_t size, int* gaps, size_t max_gaps);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_BOOL_GAP_LENGTHS_H