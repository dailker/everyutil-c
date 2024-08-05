#ifndef ARRAY_PLUCK_UNIQUE_H
#define ARRAY_PLUCK_UNIQUE_H

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
 * Extracts unique strings from an array of strings.
 *
 * @param items Input array of strings (null-terminated char*).
 * @param length Number of items in input array.
 * @param out_unique Output pointer to dynamically allocated array of unique strings.
 *                   Caller must free the array and each string.
 * @param out_count Output number of unique strings found.
 * @return 0 on success, non-zero on failure.
 */
EVERYUTIL_API int pluck_unique_strings(const char** items, size_t length,
                                       char*** out_unique, size_t* out_count);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_PLUCK_UNIQUE_H
