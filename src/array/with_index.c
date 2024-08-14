#include "array/with_index.h"
#include <stdlib.h>

with_index_item_t* withIndex(void** array, size_t length) {
    if (!array || length == 0) return NULL;

    with_index_item_t* result = (with_index_item_t*)malloc(length * sizeof(with_index_item_t));
    if (!result) return NULL;

    for (size_t i = 0; i < length; i++) {
        result[i].index = i;
        result[i].value = array[i];
    }

    return result;
}
