#include "file/file_exists.h"
#include <sys/stat.h>

EVERYUTIL_API int file_exists(const char* path) {
    if (!path) return 0;
    struct stat st;
    return stat(path, &st) == 0;
}