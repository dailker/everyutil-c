#include "array/sort_by_schema.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    const void* schema;
    size_t schema_length;
    size_t element_size;
    equals_fn equals;
    void* user_data;
} schema_context_t;

// Find index of element in schema, or return SIZE_MAX if not found
static size_t schema_index(const schema_context_t* ctx, const void* elem) {
    for (size_t i = 0; i < ctx->schema_length; i++) {
        const void* s_elem = (const char*)ctx->schema + i * ctx->element_size;
        if (ctx->equals(elem, s_elem, ctx->user_data) == 0) {
            return i;
        }
    }
    return SIZE_MAX;
}

typedef struct {
    void* base;
    size_t element_size;
    size_t length;
    schema_context_t* ctx;
} sort_helper_t;

// Comparator for qsort
static int comparator(const void* a, const void* b, void* arg) {
    sort_helper_t* helper = (sort_helper_t*)arg;
    const void* ea = a;
    const void* eb = b;
    size_t ia = schema_index(helper->ctx, ea);
    size_t ib = schema_index(helper->ctx, eb);

    if (ia == SIZE_MAX && ib == SIZE_MAX) {
        // Neither in schema, keep original order (stable)
        return 0;
    } else if (ia == SIZE_MAX) {
        return 1;
    } else if (ib == SIZE_MAX) {
        return -1;
    } else {
        if (ia < ib) return -1;
        else if (ia > ib) return 1;
        else return 0;
    }
}

// Wrapper for qsort_r or qsort_s if available, else fallback to qsort and global context

#ifdef _WIN32
// Windows has qsort_s
#include <stdlib.h>
static int qsort_comparator(void* context, const void* a, const void* b) {
    return comparator(a, b, context);
}
#endif

EVERYUTIL_API void* sort_by_schema(
    const void* array,
    size_t length,
    size_t element_size,
    const void* schema,
    size_t schema_length,
    equals_fn equals,
    hash_fn hash,
    void* user_data
) {
    if (!array || length == 0 || element_size == 0 || !schema || schema_length == 0 || !equals) {
        return NULL;
    }

    void* arr_copy = malloc(length * element_size);
    if (!arr_copy) return NULL;
    memcpy(arr_copy, array, length * element_size);

    schema_context_t ctx = { schema, schema_length, element_size, equals, user_data };
    sort_helper_t helper = { arr_copy, element_size, length, &ctx };

#if defined(__GLIBC__) || defined(__APPLE__)
    // Use qsort_r with 4 args and context as last argument (glibc style)
    qsort_r(arr_copy, length, element_size, &helper, comparator);
#elif defined(_WIN32)
    // Use qsort_s (Windows)
    qsort_s(arr_copy, length, element_size, qsort_comparator, &helper);
#else
    // fallback: no reentrant qsort, global context hack (not thread safe)
    static sort_helper_t* global_helper = NULL;
    global_helper = &helper;
    int cmp_wrapper(const void* a, const void* b) {
        return comparator(a, b, global_helper);
    }
    qsort(arr_copy, length, element_size, cmp_wrapper);
#endif

    return arr_copy;
}
