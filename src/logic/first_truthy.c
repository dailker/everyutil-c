#include "logic/first_truthy.h"

EVERYUTIL_API int first_truthy(const int* values, size_t size) {
    if (!values) return 0;
    
    for (size_t i = 0; i < size; i++) {
        if (values[i]) return values[i];
    }
    
    return 0;
}