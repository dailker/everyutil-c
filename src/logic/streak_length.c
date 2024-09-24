#include "logic/streak_length.h"

EVERYUTIL_API int streak_length(const int* array, size_t size) {
    if (!array || size == 0) return 0;
    
    int last = !!array[size - 1];
    int len = 1;
    
    for (int i = (int)size - 2; i >= 0; i--) {
        if (!!array[i] == last) {
            len++;
        } else {
            break;
        }
    }
    
    return len;
}