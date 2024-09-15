#include "file/ensure_dir.h"
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <direct.h>
#define mkdir(path, mode) _mkdir(path)
#endif

EVERYUTIL_API int ensure_dir(const char* path) {
    if (!path) return -1;
    
    char *path_copy = malloc(strlen(path) + 1);
    if (!path_copy) return -1;
    strcpy(path_copy, path);
    
    for (char *p = path_copy + 1; *p; p++) {
        if (*p == '/' || *p == '\\') {
            *p = '\0';
            mkdir(path_copy, 0755);
            *p = '/';
        }
    }
    
    int result = mkdir(path_copy, 0755);
    free(path_copy);
    return result == 0 ? 0 : -1;
}