#include "logic/all_pass.h"

EVERYUTIL_API int all_pass(int value, predicate_func* predicates, size_t count) {
    if (!predicates) return 0;
    
    for (size_t i = 0; i < count; i++) {
        if (!predicates[i](value)) return 0;
    }
    
    return 1;
}