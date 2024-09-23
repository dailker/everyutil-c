#include "logic/select_first_passing.h"

EVERYUTIL_API int select_first_passing(const int* items, size_t size, int (*condition)(int)) {
    if (!items || !condition) return -1;
    
    for (size_t i = 0; i < size; i++) {
        if (condition(items[i])) {
            return (int)i;
        }
    }
    
    return -1;
}