#include "array/semantic_group.h"
#include <stdlib.h>
#include <string.h>

static int grow_items(semantic_group_t* group) {
    size_t new_capacity = group->capacity ? group->capacity * 2 : 4;
    void** new_items = (void**)realloc(group->items, new_capacity * sizeof(void*));
    if (!new_items) return -1;
    group->items = new_items;
    group->capacity = new_capacity;
    return 0;
}

static int grow_groups(semantic_group_result_t* result) {
    size_t new_capacity = result->capacity ? result->capacity * 2 : 4;
    semantic_group_t* new_groups = (semantic_group_t*)realloc(result->groups, new_capacity * sizeof(semantic_group_t));
    if (!new_groups) return -1;
    result->groups = new_groups;
    result->capacity = new_capacity;
    return 0;
}

EVERYUTIL_API int semantic_group(void** array, size_t length,
                                 semantic_type_fn typeFn,
                                 semantic_group_result_t* out_groups) {
    if (!array || !typeFn || !out_groups) return -1;

    out_groups->groups = NULL;
    out_groups->count = 0;
    out_groups->capacity = 0;

    for (size_t i = 0; i < length; ++i) {
        void* item = array[i];
        const char* type_str = typeFn(item);
        if (!type_str) type_str = "unknown";

        // Search for existing group
        size_t g;
        for (g = 0; g < out_groups->count; ++g) {
            if (strcmp(out_groups->groups[g].type, type_str) == 0) break;
        }

        // If not found, add new group
        if (g == out_groups->count) {
            if (grow_groups(out_groups) != 0) goto fail;
            semantic_group_t* group = &out_groups->groups[out_groups->count];
            group->type = strdup(type_str);
            if (!group->type) goto fail;
            group->items = NULL;
            group->count = 0;
            group->capacity = 0;
            out_groups->count++;
        }

        semantic_group_t* group = &out_groups->groups[g];
        if (group->count == group->capacity) {
            if (grow_items(group) != 0) goto fail;
        }
        group->items[group->count++] = item;
    }

    return 0;

fail:
    semantic_group_free(out_groups);
    return -1;
}

EVERYUTIL_API void semantic_group_free(semantic_group_result_t* groups) {
    if (!groups) return;
    for (size_t i = 0; i < groups->count; ++i) {
        free(groups->groups[i].type);
        free(groups->groups[i].items);
    }
    free(groups->groups);
    groups->groups = NULL;
    groups->count = 0;
    groups->capacity = 0;
}
