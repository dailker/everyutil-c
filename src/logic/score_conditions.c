#include "logic/score_conditions.h"

EVERYUTIL_API double score_conditions(const double* weights, const int* conditions, size_t size) {
    if (!weights || !conditions) return 0.0;
    
    double sum = 0.0;
    for (size_t i = 0; i < size; i++) {
        if (conditions[i]) {
            sum += weights[i];
        }
    }
    
    return sum;
}