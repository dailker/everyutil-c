#include "array/find_anomalies.h"

#include <stdlib.h>
#include <math.h>

EVERYUTIL_API double* find_anomalies(const double* array, size_t length,
                                     const find_anomalies_options_t* options,
                                     size_t* out_count) {
    if (!array || length == 0 || !out_count) return NULL;

    *out_count = 0;

    if (options && options->zScore) {
        // Calculate mean
        double sum = 0.0;
        for (size_t i = 0; i < length; i++) {
            sum += array[i];
        }
        double mean = sum / length;

        // Calculate standard deviation
        double sq_sum = 0.0;
        for (size_t i = 0; i < length; i++) {
            double diff = array[i] - mean;
            sq_sum += diff * diff;
        }
        double stddev = sqrt(sq_sum / length);
        if (stddev == 0.0) stddev = 1.0;  // Avoid divide-by-zero

        // Allocate max possible anomalies (all)
        double* anomalies = (double*)malloc(length * sizeof(double));
        if (!anomalies) return NULL;

        size_t count = 0;
        for (size_t i = 0; i < length; i++) {
            double z = (array[i] - mean) / stddev;
            if (fabs(z) > 2.0) {
                anomalies[count++] = array[i];
            }
        }

        if (count == 0) {
            free(anomalies);
            return NULL;
        }

        // Shrink to fit
        double* resized = (double*)realloc(anomalies, count * sizeof(double));
        if (resized) anomalies = resized;

        *out_count = count;
        return anomalies;
    }

    // Fallback: no anomaly detection possible for generic arrays in C.
    // Return NULL.
    return NULL;
}
