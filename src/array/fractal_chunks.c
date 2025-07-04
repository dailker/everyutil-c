#include "array/fractal_chunks.h"
#include <stdlib.h>
#include <string.h>

static fractal_node_t* create_leaf(const double* array, size_t length) {
    if (!array || length == 0) return NULL;

    fractal_node_t* node = (fractal_node_t*)malloc(sizeof(fractal_node_t));
    if (!node) return NULL;

    node->type = NODE_LEAF;
    node->leaf.values = (double*)malloc(length * sizeof(double));
    if (!node->leaf.values) {
        free(node);
        return NULL;
    }
    memcpy(node->leaf.values, array, length * sizeof(double));
    node->leaf.length = length;

    return node;
}

static fractal_node_t* create_internal(fractal_node_t* left, fractal_node_t* right) {
    if (!left || !right) return NULL;

    fractal_node_t* node = (fractal_node_t*)malloc(sizeof(fractal_node_t));
    if (!node) return NULL;

    node->type = NODE_INTERNAL;
    node->internal.left = left;
    node->internal.right = right;

    return node;
}

EVERYUTIL_API fractal_node_t* fractal_chunks(const double* array, size_t length) {
    if (!array || length == 0) return NULL;

    // Base case: create a leaf node for small arrays (e.g., length <= 1)
    if (length <= 1) {
        return create_leaf(array, length);
    }

    // Split array into two halves
    size_t mid = length / 2;
    fractal_node_t* left = fractal_chunks(array, mid);
    fractal_node_t* right = fractal_chunks(array + mid, length - mid);

    if (!left || !right) {
        fractal_free(left);
        fractal_free(right);
        return NULL;
    }

    // Create internal node to connect left and right subtrees
    fractal_node_t* node = create_internal(left, right);
    if (!node) {
        fractal_free(left);
        fractal_free(right);
        return NULL;
    }

    return node;
}

EVERYUTIL_API void fractal_free(fractal_node_t* root) {
    if (!root) return;

    if (root->type == NODE_LEAF) {
        free(root->leaf.values);
    } else {
        fractal_free(root->internal.left);
        fractal_free(root->internal.right);
    }
    free(root);
}