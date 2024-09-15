#include "logic/bool_cluster_count.h"

EVERYUTIL_API int bool_cluster_count(const int* array, size_t size) {
    if (!array || size == 0) return 0;
    
    int count = 0;
    int in_cluster = 0;
    
    for (size_t i = 0; i < size; i++) {
        if (array[i] && !in_cluster) {
            count++;
            in_cluster = 1;
        } else if (!array[i]) {
            in_cluster = 0;
        }
    }
    
    return count;
}