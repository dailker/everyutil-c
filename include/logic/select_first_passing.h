#ifndef LOGIC_SELECT_FIRST_PASSING_H
#define LOGIC_SELECT_FIRST_PASSING_H

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
 * Returns index of first passing item.
 *
 * @param items Array of integer items.
 * @param size Size of array.
 * @param condition Function pointer for condition check.
 * @return Index of first passing item, -1 if none.
 */
EVERYUTIL_API int select_first_passing(const int* items, size_t size, int (*condition)(int));

#ifdef __cplusplus
}
#endif

#endif // LOGIC_SELECT_FIRST_PASSING_H