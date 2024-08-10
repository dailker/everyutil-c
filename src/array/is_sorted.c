#include "array/is_sorted.h"

EVERYUTIL_API int is_sorted(const double* array, size_t length, sort_order_t order) {
    if (!array || length < 2) return 1; // trivially sorted

    for (size_t i = 1; i < length; ++i) {
        if (order == SORT_ORDER_ASC) {
            if (array[i - 1] > array[i]) return 0;
        } else {
            if (array[i - 1] < array[i]) return 0;
        }
    }

    return 1;
}
