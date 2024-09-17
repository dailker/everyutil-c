#include "logic/boolean_weighted_average.h"

EVERYUTIL_API double boolean_weighted_average(const int* results, const double* weights, size_t size) {
    if (!results || !weights || size == 0) return 0.0;
    
    double sum = 0.0;
    double total = 0.0;
    
    for (size_t i = 0; i < size; i++) {
        if (results[i]) sum += weights[i];
        total += weights[i];
    }
    
    return total > 0.0 ? sum / total : 0.0;
}