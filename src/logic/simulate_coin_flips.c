#include "logic/simulate_coin_flips.h"
#include <stdlib.h>

EVERYUTIL_API void simulate_coin_flips(int* array, size_t size) {
    if (!array) return;
    
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 2;
    }
}