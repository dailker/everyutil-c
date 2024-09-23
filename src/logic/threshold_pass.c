#include "logic/threshold_pass.h"

EVERYUTIL_API int threshold_pass(int min, const int* values, size_t size) {
    if (!values || min <= 0) return 0;
    
    int count = 0;
    for (size_t i = 0; i < size; i++) {
        if (values[i]) count++;
    }
    
    return count >= min;
}