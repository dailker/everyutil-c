#include "array/array_rotate_chunks.h"
#include <stdlib.h>
#include <string.h>

EVERYUTIL_API double* array_rotate_chunks(
    const double* array,
    size_t length,
    size_t chunk_size,
    int count
) {
    if (!array || chunk_size == 0 || length == 0) {
        return NULL;
    }

    size_t chunk_count = (length + chunk_size - 1) / chunk_size;
    double** chunks = (double**)malloc(chunk_count * sizeof(double*));
    size_t* chunk_lengths = (size_t*)malloc(chunk_count * sizeof(size_t));

    if (!chunks || !chunk_lengths) {
        free(chunks);
        free(chunk_lengths);
        return NULL;
    }

    // Split into chunks
    for (size_t i = 0; i < chunk_count; ++i) {
        size_t start = i * chunk_size;
        size_t len = (start + chunk_size <= length) ? chunk_size : (length - start);
        chunk_lengths[i] = len;
        chunks[i] = (double*)malloc(len * sizeof(double));
        if (!chunks[i]) {
            for (size_t j = 0; j < i; ++j) free(chunks[j]);
            free(chunks);
            free(chunk_lengths);
            return NULL;
        }
        memcpy(chunks[i], array + start, len * sizeof(double));
    }

    // Normalize rotation count
    int rot = count % (int)chunk_count;
    if (rot < 0) rot += (int)chunk_count;

    // Flatten into result array
    double* result = (double*)malloc(length * sizeof(double));
    if (!result) {
        for (size_t i = 0; i < chunk_count; ++i) free(chunks[i]);
        free(chunks);
        free(chunk_lengths);
        return NULL;
    }

    size_t pos = 0;
    for (size_t i = 0; i < chunk_count; ++i) {
        size_t src_idx = (chunk_count + i - rot) % chunk_count;
        memcpy(result + pos, chunks[src_idx], chunk_lengths[src_idx] * sizeof(double));
        pos += chunk_lengths[src_idx];
    }

    for (size_t i = 0; i < chunk_count; ++i) free(chunks[i]);
    free(chunks);
    free(chunk_lengths);

    return result;
}
