#include "logic/index_of_first_true.h"

EVERYUTIL_API int index_of_first_true(const int* array, size_t size) {
    if (!array) return -1;
    
    for (size_t i = 0; i < size; i++) {
        if (array[i]) return (int)i;
    }
    
    return -1;
}