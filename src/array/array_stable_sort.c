#include "array/array_stable_sort.h"
#include <stdlib.h>

typedef struct {
    double value;
    size_t index;
} indexed_double_t;

static int compare_indexed(const void* a, const void* b, void* cmp_fn) {
    const indexed_double_t* ia = (const indexed_double_t*)a;
    const indexed_double_t* ib = (const indexed_double_t*)b;
    int (*compare)(double, double) = cmp_fn;
    int result = compare(ia->value, ib->value);
    if (result != 0) return result;
    return (int)(ia->index - ib->index);
}

EVERYUTIL_API double* array_stable_sort(
    const double* array,
    size_t length,
    int (*compare)(double a, double b)
) {
    if (!array || !compare || length == 0) return NULL;

    indexed_double_t* indexed = malloc(length * sizeof(indexed_double_t));
    if (!indexed) return NULL;

    for (size_t i = 0; i < length; ++i) {
        indexed[i].value = array[i];
        indexed[i].index = i;
    }

#if defined(_GNU_SOURCE) || (defined(__GLIBC__) && !defined(__APPLE__))
    qsort_r(indexed, length, sizeof(indexed_double_t), compare_indexed, compare);
#elif defined(_WIN32)
    // Windows qsort_s expects: int cmp(void *context, const void *a, const void *b)
    int compare_indexed_win(void *cmp_fn, const void *a, const void *b) {
        const indexed_double_t* ia = (const indexed_double_t*)a;
        const indexed_double_t* ib = (const indexed_double_t*)b;
        int (*compare)(double, double) = cmp_fn;
        int result = compare(ia->value, ib->value);
        if (result != 0) return result;
        return (int)(ia->index - ib->index);
    }
    qsort_s(indexed, length, sizeof(indexed_double_t), compare_indexed_win, compare);
#else
    // fallback: no stable support unless compiler provides qsort_r
    // NOTE: this is not truly stable, but included for portability.
    #warning "qsort_r not available; array_stable_sort may not be stable"
    qsort(indexed, length, sizeof(indexed_double_t),
        (int (*)(const void*, const void*))compare_indexed);
#endif

    double* result = malloc(length * sizeof(double));
    if (!result) {
        free(indexed);
        return NULL;
    }

    for (size_t i = 0; i < length; ++i) {
        result[i] = indexed[i].value;
    }

    free(indexed);
    return result;
}
