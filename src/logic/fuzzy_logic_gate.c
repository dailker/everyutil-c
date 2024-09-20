#include "logic/fuzzy_logic_gate.h"

static double min_value(const double* values, size_t size) {
    if (!values || size == 0) return 0.0;
    double min = values[0];
    for (size_t i = 1; i < size; i++) {
        if (values[i] < min) min = values[i];
    }
    return min;
}

static double max_value(const double* values, size_t size) {
    if (!values || size == 0) return 0.0;
    double max = values[0];
    for (size_t i = 1; i < size; i++) {
        if (values[i] > max) max = values[i];
    }
    return max;
}

EVERYUTIL_API double fuzzy_logic_gate(fuzzy_gate_type_t type, const double* values, size_t size) {
    if (!values || size == 0) return 0.0;
    
    switch (type) {
        case FUZZY_AND:
            return min_value(values, size);
        case FUZZY_OR:
            return max_value(values, size);
        case FUZZY_NOT:
            return 1.0 - values[0];
        default:
            return 0.0;
    }
}