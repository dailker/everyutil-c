#include "logic/is_nil.h"
#include <stddef.h>

EVERYUTIL_API int is_nil(void* val) {
    return val == NULL;
}