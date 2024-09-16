#include "logic/boolean_majority.h"

EVERYUTIL_API int boolean_majority(const int* flags, size_t size) {
    if (!flags || size == 0) return 0;
    
    int count = 0;
    for (size_t i = 0; i < size; i++) {
        if (flags[i]) count++;
    }
    
    return count > (int)(size / 2);
}