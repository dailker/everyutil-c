#ifndef ARRAY_ARRAY_FREQUENCY_MAP_H
#define ARRAY_ARRAY_FREQUENCY_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

typedef struct {
    const char* key;
    int count;
} FrequencyEntry;

typedef struct {
    FrequencyEntry* entries;
    size_t size;
    size_t capacity;
} FrequencyMap;

/**
 * Calculates a frequency map of string elements in an array.
 *
 * @param array Input array of strings.
 * @param length Number of elements in the array.
 * @return Pointer to a dynamically allocated frequency map.
 *         NULL on failure. Caller must free the result using array_frequency_map_free().
 */
EVERYUTIL_API FrequencyMap* array_frequency_map(const char* const* array, size_t length);

/**
 * Frees memory allocated by array_frequency_map.
 * @param map Frequency map to free.
 */
EVERYUTIL_API void array_frequency_map_free(FrequencyMap* map);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ARRAY_FREQUENCY_MAP_H
