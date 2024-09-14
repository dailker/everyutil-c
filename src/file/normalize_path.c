#include "file/normalize_path.h"
#include <stdlib.h>
#include <string.h>

EVERYUTIL_API char* normalize_path(const char* path) {
    if (!path) return NULL;
    
    size_t len = strlen(path);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (path[i] == '/' || path[i] == '\\') {
            if (j == 0 || result[j-1] != '/') {
                result[j++] = '/';
            }
        } else {
            result[j++] = path[i];
        }
    }
    result[j] = '\0';
    
    return result;
}