#include "logic/boolean_consensus.h"

EVERYUTIL_API int boolean_consensus(const int* flags, size_t size) {
    if (!flags || size == 0) return 1;
    
    int first = !!flags[0];
    for (size_t i = 1; i < size; i++) {
        if (!!flags[i] != first) return 0;
    }
    
    return 1;
}