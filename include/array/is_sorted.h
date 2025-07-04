#ifndef ARRAY_IS_SORTED_H
#define ARRAY_IS_SORTED_H

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

typedef enum {
    SORT_ORDER_ASC,
    SORT_ORDER_DESC
} sort_order_t;

/**
 * Checks if the array is sorted in ascending or descending order.
 *
 * @param array Input array of doubles.
 * @param length Number of elements in the array.
 * @param order Sort order: SORT_ORDER_ASC or SORT_ORDER_DESC.
 *              Pass SORT_ORDER_ASC if unsure (default).
 * @return 1 if sorted, 0 otherwise.
 */
EVERYUTIL_API int is_sorted(const double* array, size_t length, sort_order_t order);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_IS_SORTED_H
