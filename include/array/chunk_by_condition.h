#ifndef ARRAY_CHUNK_BY_CONDITION_H
#define ARRAY_CHUNK_BY_CONDITION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>

#if defined(_WIN32) || defined(_WIN64)
  #ifdef BUILDING_EVERYUTIL
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

/** Structure for a chunk of ints */
typedef struct {
    int* data;
    size_t size;
} IntChunk;

/** Structure for an array of chunks */
typedef struct {
    IntChunk* chunks;
    size_t count;
} IntChunkArray;

/**
 * Condition function pointer for chunking.
 * @param prev previous element
 * @param curr current element
 * @param idx current index in the array
 * @param arr pointer to entire array
 * @param arr_len length of the array
 * @return true to continue current chunk, false to start new chunk
 */
typedef bool (*ChunkCondFunc)(int prev, int curr, size_t idx, const int* arr, size_t arr_len);

/**
 * Splits an integer array into chunks where the condition function returns true for consecutive elements.
 * 
 * @param array input array
 * @param length length of input array
 * @param cond condition function pointer
 * @return IntChunkArray containing chunks (must be freed with free_int_chunk_array)
 */
EVERYUTIL_API IntChunkArray chunk_by_condition(const int* array, size_t length, ChunkCondFunc cond);

/**
 * Frees memory allocated for IntChunkArray and its chunks.
 * 
 * @param chunks IntChunkArray to free
 */
EVERYUTIL_API void free_int_chunk_array(IntChunkArray chunks);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_CHUNK_BY_CONDITION_H
