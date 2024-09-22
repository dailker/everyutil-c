#include "logic/majority_truthy.h"

EVERYUTIL_API int majority_truthy(const int* values, size_t size) {
    if (!values || size == 0) return 0;
    
    int count = 0;
    for (size_t i = 0; i < size; i++) {
        if (values[i]) count++;
    }
    
    return count > (int)(size / 2);
}