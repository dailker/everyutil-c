#ifndef ARRAY_INTERLEAVE_H
#define ARRAY_INTERLEAVE_H

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
 * Interleaves multiple arrays of doubles in a round-robin manner.
 *
 * @param arrays Array of pointers to double arrays.
 * @param lengths Array of lengths for each array.
 * @param arrays_count Number of arrays.
 * @param out_length Output pointer to store length of the returned array.
 * @return Newly allocated interleaved array (caller must free), or NULL on failure.
 */
EVERYUTIL_API double* interleave(const double** arrays, const size_t* lengths,
                                 size_t arrays_count, size_t* out_length);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_INTERLEAVE_H
