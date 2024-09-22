#include "logic/or_any.h"

EVERYUTIL_API int or_any(const int* values, size_t size) {
    if (!values) return 0;
    
    for (size_t i = 0; i < size; i++) {
        if (values[i]) return 1;
    }
    
    return 0;
}