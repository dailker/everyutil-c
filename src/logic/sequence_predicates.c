#include "logic/sequence_predicates.h"
#include <stdlib.h>

static int seq_index = 0;

EVERYUTIL_API int sequence_predicates(int value, predicate_func* predicates, size_t count) {
    if (predicates[seq_index](value)) {
        seq_index = (seq_index + 1) % count;
        return 1;
    }
    return 0;
}