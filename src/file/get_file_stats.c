#include "file/get_file_stats.h"

EVERYUTIL_API int get_file_stats(const char* path, struct stat* stats) {
    if (!path || !stats) return -1;
    return stat(path, stats) == 0 ? 0 : -1;
}