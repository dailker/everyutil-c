#include "logic/is_not_nil.h"
#include <stddef.h>

EVERYUTIL_API int is_not_nil(void* val) {
    return val != NULL;
}