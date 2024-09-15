#include "logic/and_all.h"

EVERYUTIL_API int and_all(const int* values, size_t size) {
    if (!values) return 1;
    
    for (size_t i = 0; i < size; i++) {
        if (!values[i]) return 0;
    }
    
    return 1;
}