#include "file/move_file.h"
#include <stdio.h>

EVERYUTIL_API int move_file(const char* src, const char* dest) {
    if (!src || !dest) return -1;
    return rename(src, dest) == 0 ? 0 : -1;
}