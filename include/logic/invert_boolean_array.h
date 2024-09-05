#ifndef LOGIC_INVERT_BOOLEAN_ARRAY_H
#define LOGIC_INVERT_BOOLEAN_ARRAY_H

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
 * Inverts all boolean values in array (in-place).
 *
 * @param array Array of boolean values to invert.
 * @param size Size of array.
 */
EVERYUTIL_API void invert_boolean_array(int* array, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_INVERT_BOOLEAN_ARRAY_H