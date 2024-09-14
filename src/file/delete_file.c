#include "file/delete_file.h"
#include <stdio.h>

EVERYUTIL_API int delete_file(const char* path) {
    if (!path) return -1;
    return remove(path) == 0 ? 0 : -1;
}