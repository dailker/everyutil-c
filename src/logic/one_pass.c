#include "logic/one_pass.h"

EVERYUTIL_API int one_pass(const int* values, size_t size) {
    if (!values) return 0;
    
    int count = 0;
    for (size_t i = 0; i < size; i++) {
        if (values[i]) count++;
    }
    
    return count == 1;
}