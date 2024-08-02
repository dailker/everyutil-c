#include "array/flatten_until.h"

#include <stdlib.h>

typedef struct {
    Item* data;
    size_t size;
    size_t capacity;
} dynamic_array_t;

static int dyn_array_init(dynamic_array_t* arr) {
    arr->capacity = 16;
    arr->size = 0;
    arr->data = (Item*)malloc(arr->capacity * sizeof(Item));
    return arr->data != NULL ? 0 : -1;
}

static int dyn_array_append(dynamic_array_t* arr, Item item) {
    if (arr->size == arr->capacity) {
        size_t new_cap = arr->capacity * 2;
        Item* tmp = (Item*)realloc(arr->data, new_cap * sizeof(Item));
        if (!tmp) return -1;
        arr->data = tmp;
        arr->capacity = new_cap;
    }
    arr->data[arr->size++] = item;
    return 0;
}

static void dyn_array_free(dynamic_array_t* arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

static int flatten_recursive(const Item* input, size_t length,
                             depth_fn_t depthFn, int depth,
                             dynamic_array_t* output) {
    for (size_t i = 0; i < length; ++i) {
        const Item* item = &input[i];
        if (item->type == ITEM_ARRAY && depthFn(item, depth)) {
            if (flatten_recursive(item->array.items, item->array.length, depthFn, depth + 1, output) != 0) {
                return -1;
            }
        } else {
            // Push only ITEM_VALUE items
            if (item->type == ITEM_VALUE) {
                if (dyn_array_append(output, *item) != 0) return -1;
            } else {
                // If item is ITEM_ARRAY but depthFn says no flatten, just treat as ITEM_VALUE?
                // But type mismatch: in original code we push the item as-is (non-array).
                // Here we skip arrays where depthFn is false (flattening stops), so push array as is?
                // Let's push arrays as is.
                if (dyn_array_append(output, *item) != 0) return -1;
            }
        }
    }
    return 0;
}

EVERYUTIL_API Item* flatten_until(const Item* input, size_t length,
                                  depth_fn_t depthFn, int depth,
                                  size_t* out_length) {
    if (!input || !depthFn || !out_length) return NULL;
    *out_length = 0;

    dynamic_array_t output;
    if (dyn_array_init(&output) != 0) return NULL;

    if (flatten_recursive(input, length, depthFn, depth, &output) != 0) {
        dyn_array_free(&output);
        return NULL;
    }

    *out_length = output.size;
    return output.data;
}
