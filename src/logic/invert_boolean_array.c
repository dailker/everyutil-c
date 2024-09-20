#include "logic/invert_boolean_array.h"

EVERYUTIL_API void invert_boolean_array(int* array, size_t size) {
    if (!array) return;
    
    for (size_t i = 0; i < size; i++) {
        array[i] = !array[i];
    }
}