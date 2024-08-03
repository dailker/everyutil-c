#ifndef ARRAY_FRACTAL_CHUNKS_H
#define ARRAY_FRACTAL_CHUNKS_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_EXPORTS
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

typedef enum {
    NODE_LEAF,
    NODE_INTERNAL
} node_type_t;

typedef struct fractal_node {
    node_type_t type;
    union {
        struct {
            double* values;
            size_t length; // should be 1 for leaf
        } leaf;
        struct {
            struct fractal_node* left;
            struct fractal_node* right;
        } internal;
    };
} fractal_node_t;

/**
 * Recursively chunk array into fractal nested halves.
 *
 * @param array Input array of doubles.
 * @param length Number of elements.
 * @return Pointer to root fractal_node_t (caller must free with fractal_free).
 *         Returns NULL on failure.
 */
EVERYUTIL_API fractal_node_t* fractal_chunks(const double* array, size_t length);

/**
 * Frees a fractal_node_t tree allocated by fractal_chunks.
 *
 * @param root Pointer to fractal_node_t to free.
 */
EVERYUTIL_API void fractal_free(fractal_node_t* root);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_FRACTAL_CHUNKS_H
