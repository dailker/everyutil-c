#ifndef ARRAY_ARRAY_FINGERPRINT_H
#define ARRAY_ARRAY_FINGERPRINT_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef BUILDING_EVERYUTIL
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

/**
 * Hash-style signature of a double array for quick diffing.
 *
 * Simulates JSON.stringify behavior by converting the array
 * into a JSON-like string and hashing it using a DJB2-like hash.
 *
 * @param array Pointer to the input array of doubles.
 * @param length Number of elements in the array.
 * @return Pointer to a dynamically allocated hexadecimal string hash.
 *         Returns NULL on failure. Caller must free the result.
 */
EVERYUTIL_API char* array_fingerprint(const double* array, size_t length);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ARRAY_FINGERPRINT_H
