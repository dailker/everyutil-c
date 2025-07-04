#include "array/semantic_group.h"
#include <stdlib.h>
#include <string.h>

static semantic_group_t* find_group(semantic_group_result_t* result, const char* type) {
    for (size_t i = 0; i < result->count; i++) {
        if (strcmp(result->groups[i].type, type) == 0) {
            return &result->groups[i];
        }
    }
    return NULL;
}

static int add_group(semantic_group_result_t* result, const char* type) {
    if (result->count >= result->capacity) {
        size_t new_capacity = result->capacity == 0 ? 4 : result->capacity * 2;
        semantic_group_t* new_groups = (semantic_group_t*)realloc(result->groups, new_capacity * sizeof(semantic_group_t));
        if (!new_groups) return -1;
        result->groups = new_groups;
        result->capacity = new_capacity;
    }

    semantic_group_t* group = &result->groups[result->count];
    group->type = strdup(type);
    if (!group->type) return -1;
    group->items = NULL;
    group->count = 0;
    group->capacity = 0;
    result->count++;
    return 0;
}

static int add_item_to_group(semantic_group_t* group, void* item) {
    if (group->count >= group->capacity) {
        size_t new_capacity = group->capacity == 0 ? 4 : group->capacity * 2;
        void** new_items = (void**)realloc(group->items, new_capacity * sizeof(void*));
        if (!new_items) return -1;
        group->items = new_items;
        group->capacity = new_capacity;
    }
    group->items[group->count++] = item;
    return 0;
}

EVERYUTIL_API int semantic_group(void** array, size_t length, semantic_type_fn typeFn, semantic_group_result_t* out_groups) {
    if (!array || !typeFn || !out_groups) return -1;

    out_groups->groups = NULL;
    out_groups->count = 0;
    out_groups->capacity = 0;

    for (size_t i = 0; i < length; i++) {
        const char* type = typeFn(array[i]);
        if (!type) continue;

        semantic_group_t* group = find_group(out_groups, type);
        if (!group) {
            if (add_group(out_groups, type) != 0) {
                semantic_group_free(out_groups);
                return -1;
            }
            group = &out_groups->groups[out_groups->count - 1];
        }
        if (add_item_to_group(group, array[i]) != 0) {
            semantic_group_free(out_groups);
            return -1;
        }
    }
    return 0;
}

EVERYUTIL_API void semantic_group_free(semantic_group_result_t* groups) {
    if (!groups || !groups->groups) return;
    for (size_t i = 0; i < groups->count; i++) {
        free(groups->groups[i].type);
        free(groups->groups[i].items);
    }
    free(groups->groups);
    groups->groups = NULL;
    groups->count = 0;
    groups->capacity = 0;
}