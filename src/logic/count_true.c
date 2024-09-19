#include "logic/count_true.h"

EVERYUTIL_API int count_true(const int* array, size_t size) {
    if (!array) return 0;
    
    int count = 0;
    for (size_t i = 0; i < size; i++) {
        if (array[i]) count++;
    }
    return count;
}