#include "array/array_unique_by_key.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int key;
    bool used;
} KeySetEntry;

// Simple linear set to track keys (no hashing)
static bool key_seen(KeySetEntry* seen, size_t used, int key) {
    for (size_t i = 0; i < used; ++i) {
        if (seen[i].used && seen[i].key == key) {
            return true;
        }
    }
    return false;
}

EVERYUTIL_API void* array_unique_by_key(
    const void* array,
    size_t item_size,
    size_t length,
    KeyFnInt key_fn,
    size_t* out_len
) {
    if (!array || !key_fn || !out_len) return NULL;

    const char* items = (const char*)array;
    void* result = malloc(length * item_size);
    if (!result) return NULL;

    KeySetEntry* seen_keys = malloc(length * sizeof(KeySetEntry));
    if (!seen_keys) {
        free(result);
        return NULL;
    }

    size_t seen_count = 0;
    size_t out_count = 0;
    for (size_t i = 0; i < length; ++i) {
        const void* item_ptr = items + i * item_size;
        int key = key_fn(item_ptr);

        if (!key_seen(seen_keys, seen_count, key)) {
            memcpy((char*)result + out_count * item_size, item_ptr, item_size);
            seen_keys[seen_count++] = (KeySetEntry){ .key = key, .used = true };
            out_count++;
        }
    }

    free(seen_keys);

    *out_len = out_count;
    return result;
}
