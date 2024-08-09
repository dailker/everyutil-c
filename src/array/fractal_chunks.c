#include "array/fractal_chunks.h"

#include <stdlib.h>
#include <string.h>

EVERYUTIL_API fractal_node_t* fractal_chunks(const double* array, size_t length) {
    if (!array || length == 0) return NULL;

    fractal_node_t* node = (fractal_node_t*)malloc(sizeof(fractal_node_t));
    if (!node) return NULL;

    if (length <= 1) {
        node->type = NODE_LEAF;
        node->leaf.length = length;
        node->leaf.values = (double*)malloc(length * sizeof(double));
        if (!node->leaf.values) {
            free(node);
            return NULL;
        }
        if (length == 1) {
            node->leaf.values[0] = array[0];
        }
        return node;
    }

    size_t mid = length / 2;
    fractal_node_t* left = fractal_chunks(array, mid);
    fractal_node_t* right = fractal_chunks(array + mid, length - mid);
    if (!left || !right) {
        if (left) fractal_free(left);
        if (right) fractal_free(right);
        free(node);
        return NULL;
    }

    node->type = NODE_INTERNAL;
    node->internal.left = left;
    node->internal.right = right;
    return node;
}

EVERYUTIL_API void fractal_free(fractal_node_t* root) {
    if (!root) return;
    if (root->type == NODE_LEAF) {
        free(root->leaf.values);
    } else if (root->type == NODE_INTERNAL) {
        fractal_free(root->internal.left);
        fractal_free(root->internal.right);
    }
    free(root);
}
