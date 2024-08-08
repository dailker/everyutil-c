#include "array/chunk_by_condition.h"
#include <stdlib.h>
#include <string.h>

EVERYUTIL_API IntChunkArray chunk_by_condition(const int* array, size_t length, ChunkCondFunc cond) {
    IntChunkArray result = { NULL, 0 };
    if (length == 0) return result;

    // Allocate initial chunk array with capacity guess (max length)
    size_t max_chunks = length;
    IntChunk* chunks = malloc(max_chunks * sizeof(IntChunk));
    if (!chunks) return result;

    size_t chunk_count = 0;
    // Temporary buffer for current chunk elements
    int* temp_chunk = malloc(length * sizeof(int)); // worst case all elements separate chunks
    if (!temp_chunk) {
        free(chunks);
        return result;
    }
    size_t temp_size = 0;

    temp_chunk[temp_size++] = array[0];

    for (size_t i = 1; i < length; ++i) {
        if (cond(array[i - 1], array[i], i, array, length)) {
            temp_chunk[temp_size++] = array[i];
        } else {
            // finalize current chunk
            int* chunk_data = malloc(temp_size * sizeof(int));
            if (!chunk_data) goto fail;
            memcpy(chunk_data, temp_chunk, temp_size * sizeof(int));
            chunks[chunk_count++] = (IntChunk){ chunk_data, temp_size };
            temp_size = 0;
            temp_chunk[temp_size++] = array[i];
        }
    }

    // finalize last chunk
    if (temp_size > 0) {
        int* chunk_data = malloc(temp_size * sizeof(int));
        if (!chunk_data) goto fail;
        memcpy(chunk_data, temp_chunk, temp_size * sizeof(int));
        chunks[chunk_count++] = (IntChunk){ chunk_data, temp_size };
    }

    free(temp_chunk);

    // shrink chunks array to used size
    if (chunk_count < max_chunks) {
        IntChunk* shrunk = realloc(chunks, chunk_count * sizeof(IntChunk));
        if (shrunk) chunks = shrunk;
    }

    result.chunks = chunks;
    result.count = chunk_count;
    return result;

fail:
    // free all allocated memory on failure
    for (size_t j = 0; j < chunk_count; ++j) {
        free(chunks[j].data);
    }
    free(chunks);
    free(temp_chunk);
    result.chunks = NULL;
    result.count = 0;
    return result;
}

EVERYUTIL_API void free_int_chunk_array(IntChunkArray chunks) {
    if (!chunks.chunks) return;
    for (size_t i = 0; i < chunks.count; ++i) {
        free(chunks.chunks[i].data);
    }
    free(chunks.chunks);
}
