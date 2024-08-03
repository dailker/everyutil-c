#ifndef ARRAY_FLATTEN_UNTIL_H
#define ARRAY_FLATTEN_UNTIL_H

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
    ITEM_VALUE,
    ITEM_ARRAY
} ItemType;

typedef struct Item {
    ItemType type;
    union {
        double value;
        struct {
            struct Item* items;
            size_t length;
        } array;
    };
} Item;

/**
 * Prototype for the depth function callback.
 * @param item Pointer to current Item.
 * @param depth Current depth level.
 * @return Non-zero to flatten further, zero to stop flattening here.
 */
typedef int (*depth_fn_t)(const Item* item, int depth);

/**
 * Flattens nested arrays until depthFn returns false for an item.
 *
 * @param input Pointer to input array of Items.
 * @param length Number of elements in input array.
 * @param depthFn Callback to decide if flattening continues on an item.
 * @param depth Current recursion depth (should be 0 when first called).
 * @param out_length Pointer to size_t to store output length.
 * @return Dynamically allocated array of flattened Items (type ITEM_VALUE only).
 *         Caller must free the returned array.
 *         Returns NULL on failure.
 */
EVERYUTIL_API Item* flatten_until(const Item* input, size_t length,
                                  depth_fn_t depthFn, int depth,
                                  size_t* out_length);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_FLATTEN_UNTIL_H
