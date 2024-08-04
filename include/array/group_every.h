#ifndef ARRAY_GROUP_EVERY_H
#define ARRAY_GROUP_EVERY_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_EXPORTS
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

/**
 * Groups every `count` elements of a double array, dropping any leftover elements.
 *
 * @param array Input array of doubles.
 * @param length Number of elements in the input array.
 * @param count Number of elements per group.
 * @param out_groups Output pointer to dynamically allocated array of pointers to groups.
 *                   Each group is a dynamically allocated array of doubles of size `count`.
 *                   Caller must free each group and the groups array.
 * @param out_group_count Output number of groups.
 * @return 0 on success, non-zero on failure.
 */
EVERYUTIL_API int group_every(const double* array, size_t length, size_t count,
                              double*** out_groups, size_t* out_group_count);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_GROUP_EVERY_H
