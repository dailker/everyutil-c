#include "logic/all_same.h"

EVERYUTIL_API int all_same(const int* array, size_t size) {
    if (!array || size == 0) return 1;
    
    int first = !!array[0];
    for (size_t i = 1; i < size; i++) {
        if (!!array[i] != first) return 0;
    }
    
    return 1;
}