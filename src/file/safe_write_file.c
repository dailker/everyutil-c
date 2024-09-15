#include "file/safe_write_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

EVERYUTIL_API int safe_write_file(const char* path, const void* data, size_t size) {
    if (!path || !data) return -1;
    
    char *temp_path = malloc(strlen(path) + 20);
    if (!temp_path) return -1;
    
    srand((unsigned int)time(NULL));
    sprintf(temp_path, "%s.%d.tmp", path, rand());
    
    FILE *file = fopen(temp_path, "wb");
    if (!file) {
        free(temp_path);
        return -1;
    }
    
    size_t written = fwrite(data, 1, size, file);
    fclose(file);
    
    if (written != size) {
        remove(temp_path);
        free(temp_path);
        return -1;
    }
    
    int result = rename(temp_path, path) == 0 ? 0 : -1;
    free(temp_path);
    return result;
}