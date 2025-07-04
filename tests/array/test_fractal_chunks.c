#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array/fractal_chunks.h"

// Helper to count nodes in the tree
size_t count_nodes(fractal_node_t* root) {
    if (!root) return 0;
    if (root->type == NODE_LEAF) return 1;
    return 1 + count_nodes(root->internal.left) + count_nodes(root->internal.right);
}

// Helper to verify leaf values
bool check_leaf_values(fractal_node_t* node, const double* expected, size_t length) {
    if (!node || node->type != NODE_LEAF || node->leaf.length != length) return false;
    for (size_t i = 0; i < length; i++) {
        if (node->leaf.values[i] != expected[i]) return false;
    }
    return true;
}

void test_fractal_chunks_basic() {
    double input[] = {1.0, 2.0, 3.0, 4.0};
    fractal_node_t* root = fractal_chunks(input, 4);

    if (!root) {
        printf("test_fractal_chunks_basic: FAILED (null root)\n");
        return;
    }

    // Expect a tree with 7 nodes: 3 internal, 4 leaves
    size_t node_count = count_nodes(root);
    if (node_count == 7) {
        printf("test_fractal_chunks_basic: PASSED\n");
    } else {
        printf("test_fractal_chunks_basic: FAILED (expected 7 nodes, got %zu)\n", node_count);
    }

    fractal_free(root);
}

void test_fractal_chunks_single() {
    double input[] = {1.0};
    fractal_node_t* root = fractal_chunks(input, 1);

    if (root && root->type == NODE_LEAF && check_leaf_values(root, input, 1)) {
        printf("test_fractal_chunks_single: PASSED\n");
    } else {
        printf("test_fractal_chunks_single: FAILED\n");
    }

    fractal_free(root);
}

void test_fractal_chunks_empty() {
    fractal_node_t* root = fractal_chunks(NULL, 0);
    if (!root) {
        printf("test_fractal_chunks_empty: PASSED\n");
    } else {
        printf("test_fractal_chunks_empty: FAILED\n");
        fractal_free(root);
    }
}

int main(void) {
    test_fractal_chunks_basic();
    test_fractal_chunks_single();
    test_fractal_chunks_empty();
    return 0;
}