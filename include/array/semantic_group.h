#ifndef ARRAY_SEMANTIC_GROUP_H
#define ARRAY_SEMANTIC_GROUP_H

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

/** Function pointer to get type string from an item */
typedef const char* (*semantic_type_fn)(void* item);

/** Represents a group of items sharing the same semantic type */
typedef struct {
    char* type;       /* dynamically allocated type string */
    void** items;     /* array of pointers to items */
    size_t count;     /* number of items */
    size_t capacity;  /* capacity of items array */
} semantic_group_t;

/** Container holding multiple semantic groups */
typedef struct {
    semantic_group_t* groups;
    size_t count;
    size_t capacity;
} semantic_group_result_t;

/**
 * Groups items by semantic type.
 * 
 * @param array Array of pointers to items.
 * @param length Number of items.
 * @param typeFn Callback returning type string for each item.
 * @param out_groups Pointer to store allocated result (must be freed).
 * @return 0 on success, non-zero on failure.
 */
EVERYUTIL_API int semantic_group(void** array, size_t length,
                                 semantic_type_fn typeFn,
                                 semantic_group_result_t* out_groups);

/**
 * Frees memory allocated by semantic_group.
 * @param groups Pointer returned by semantic_group.
 */
EVERYUTIL_API void semantic_group_free(semantic_group_result_t* groups);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_SEMANTIC_GROUP_H
