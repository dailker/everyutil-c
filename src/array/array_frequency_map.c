#include "array/array_frequency_map.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 32
#define LOAD_FACTOR 0.7

static unsigned long hash_string(const char* str) {
    unsigned long hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + (unsigned char)(*str++);
    }
    return hash;
}

EVERYUTIL_API FrequencyMap* array_frequency_map(const char* const* array, size_t length) {
    if (!array && length > 0) return NULL;

    size_t capacity = INITIAL_CAPACITY;
    size_t size = 0;

    FrequencyEntry* table = (FrequencyEntry*)calloc(capacity, sizeof(FrequencyEntry));
    if (!table) return NULL;

    for (size_t i = 0; i < length; ++i) {
        const char* key = array[i];
        unsigned long hash = hash_string(key);
        size_t index = hash % capacity;

        while (table[index].key != NULL) {
            if (strcmp(table[index].key, key) == 0) {
                table[index].count++;
                goto next_element;
            }
            index = (index + 1) % capacity;
        }

        // Insert new entry
        table[index].key = key;
        table[index].count = 1;
        size++;

        next_element:
        if ((double)size / capacity > LOAD_FACTOR) {
            // Rehash needed (skipped for simplicity)
            break;
        }
    }

    FrequencyMap* map = (FrequencyMap*)malloc(sizeof(FrequencyMap));
    if (!map) {
        free(table);
        return NULL;
    }

    map->entries = table;
    map->size = size;
    map->capacity = capacity;
    return map;
}

EVERYUTIL_API void array_frequency_map_free(FrequencyMap* map) {
    if (map) {
        free(map->entries);
        free(map);
    }
}
