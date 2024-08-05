#ifndef ARRAY_MODE_H
#define ARRAY_MODE_H

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
 * Finds the mode(s) of a numeric array.
 *
 * @param array Input array of doubles.
 * @param length Number of elements in the array.
 * @param out_modes Output pointer to dynamically allocated array of modes.
 *                  Caller must free this.
 * @param out_mode_count Output number of modes found.
 * @return 0 on success, non-zero on failure.
 */
EVERYUTIL_API int mode(const double* array, size_t length,
                       double** out_modes, size_t* out_mode_count);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_MODE_H
