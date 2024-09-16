#include "logic/bool_gap_lengths.h"

EVERYUTIL_API int bool_gap_lengths(const int* array, size_t size, int* gaps, size_t max_gaps) {
    if (!array || !gaps || size == 0) return 0;
    
    int gap_count = 0;
    int gap = 0;
    int in_cluster = 0;
    
    for (size_t i = 0; i < size; i++) {
        if (array[i]) {
            if (gap > 0 && in_cluster && gap_count < (int)max_gaps) {
                gaps[gap_count++] = gap;
            }
            gap = 0;
            in_cluster = 1;
        } else if (in_cluster) {
            gap++;
        }
    }
    
    return gap_count;
}