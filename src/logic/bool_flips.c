#include "logic/bool_flips.h"

EVERYUTIL_API int bool_flips(const int* array, size_t size) {
    if (!array || size < 2) return 0;
    
    int flips = 0;
    for (size_t i = 1; i < size; i++) {
        if (!!array[i] != !!array[i - 1]) {
            flips++;
        }
    }
    
    return flips;
}