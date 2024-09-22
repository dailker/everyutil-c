#include "logic/is_rising_signal.h"

EVERYUTIL_API int is_rising_signal(const int* array, size_t size, int window) {
    if (!array || (int)size < window || window <= 0) return 0;
    
    int count = 0;
    int start = (int)size - window;
    
    for (int i = start; i < (int)size; i++) {
        if (array[i]) count++;
    }
    
    return count > window / 2;
}