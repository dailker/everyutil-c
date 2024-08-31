#ifndef LOGIC_AND_ALL_H
#define LOGIC_AND_ALL_H

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
 * Returns true if all values are true (logical AND).
 *
 * @param values Array of boolean values.
 * @param size Size of array.
 * @return 1 if all true, 0 otherwise.
 */
EVERYUTIL_API int and_all(const int* values, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_AND_ALL_H