#include "array/reconstruct_sequence.h"
#include <stdlib.h>
#include <string.h>

static int compare_elements(const void* a, const void* b) {
    const rs_element_t* ea = (const rs_element_t*)a;
    const rs_element_t* eb = (const rs_element_t*)b;

    if (ea->type == eb->type) {
        switch (ea->type) {
            case TYPE_NUMBER:
                if (ea->data.number < eb->data.number) return -1;
                else if (ea->data.number > eb->data.number) return 1;
                else return 0;
            case TYPE_STRING:
                return strcmp(ea->data.string, eb->data.string);
            case TYPE_OTHER:
                // Cannot compare, treat as equal
                return 0;
        }
    }
    // Different types: order numbers < strings < others
    if (ea->type == TYPE_NUMBER) return -1;
    if (eb->type == TYPE_NUMBER) return 1;
    if (ea->type == TYPE_STRING) return -1;
    if (eb->type == TYPE_STRING) return 1;
    return 0;
}

EVERYUTIL_API rs_element_t* reconstruct_sequence(const rs_element_t* input, size_t length) {
    if (!input || length == 0) return NULL;

    rs_element_t* output = (rs_element_t*)malloc(length * sizeof(rs_element_t));
    if (!output) return NULL;

    memcpy(output, input, length * sizeof(rs_element_t));
    qsort(output, length, sizeof(rs_element_t), compare_elements);

    return output;
}
