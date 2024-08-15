#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "array/array_frequency_map.h"

// Helper: check frequency map contains expected entries
bool frequency_map_matches(FrequencyMap* map, const char* expected_keys[], const int expected_counts[], size_t expected_len) {
    if (map->size != expected_len) return false;

    for (size_t i = 0; i < expected_len; i++) {
        bool found = false;
        for (size_t j = 0; j < map->capacity; j++) {
            FrequencyEntry* entry = &map->entries[j];
            if (entry->key && strcmp(entry->key, expected_keys[i]) == 0 && entry->count == expected_counts[i]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

void test_frequency_map_strings() {
    const char* arr[] = {"a", "b", "a"};
    const char* expected_keys[] = {"a", "b"};
    int expected_counts[] = {2, 1};

    FrequencyMap* map = array_frequency_map(arr, 3);
    if (!map) {
        printf("test_frequency_map_strings: FAILED (null map)\n");
        return;
    }

    if (frequency_map_matches(map, expected_keys, expected_counts, 2)) {
        printf("test_frequency_map_strings: PASSED\n");
    } else {
        printf("test_frequency_map_strings: FAILED\n");
    }
    array_frequency_map_free(map);
}

void test_frequency_map_numbers_as_strings() {
    const char* arr[] = {"1", "2", "2", "3", "3", "3"};
    const char* expected_keys[] = {"1", "2", "3"};
    int expected_counts[] = {1, 2, 3};

    FrequencyMap* map = array_frequency_map(arr, 6);
    if (!map) {
        printf("test_frequency_map_numbers_as_strings: FAILED (null map)\n");
        return;
    }

    if (frequency_map_matches(map, expected_keys, expected_counts, 3)) {
        printf("test_frequency_map_numbers_as_strings: PASSED\n");
    } else {
        printf("test_frequency_map_numbers_as_strings: FAILED\n");
    }
    array_frequency_map_free(map);
}

void test_frequency_map_empty() {
    FrequencyMap* map = array_frequency_map(NULL, 0);
    if (map == NULL || map->size == 0) {
        printf("test_frequency_map_empty: PASSED\n");
    } else {
        printf("test_frequency_map_empty: FAILED\n");
    }
    array_frequency_map_free(map);
}

int main() {
    test_frequency_map_numbers_as_strings();
    test_frequency_map_strings();
    test_frequency_map_empty();
    return 0;
}
