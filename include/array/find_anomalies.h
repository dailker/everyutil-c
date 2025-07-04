#ifndef ARRAY_FIND_ANOMALIES_H
#define ARRAY_FIND_ANOMALIES_H

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

typedef struct {
    int zScore; ///< Set non-zero to enable z-score anomaly detection
} find_anomalies_options_t;

/**
 * Finds anomalies in a double array using z-score method.
 *
 * @param array Pointer to input array of doubles.
 * @param length Number of elements in array.
 * @param options Pointer to options struct (may be NULL).
 * @param out_count Pointer to size_t where the count of anomalies will be stored.
 * @return Dynamically allocated array of anomalies (caller must free), or NULL if none/failure.
 */
EVERYUTIL_API double* find_anomalies(const double* array, size_t length,
                                     const find_anomalies_options_t* options,
                                     size_t* out_count);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_FIND_ANOMALIES_H
