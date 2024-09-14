#include "file/create_temp_file.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

EVERYUTIL_API char* create_temp_file(const char* prefix) {
    char *result = malloc(256);
    if (!result) return NULL;
    
    const char *tmp_dir = getenv("TEMP");
    if (!tmp_dir) tmp_dir = getenv("TMP");
    if (!tmp_dir) tmp_dir = "/tmp";
    
    srand((unsigned int)time(NULL));
    snprintf(result, 256, "%s/%s%d.tmp", tmp_dir, prefix ? prefix : "tmp", rand());
    
    FILE *file = fopen(result, "w");
    if (file) {
        fclose(file);
        return result;
    }
    
    free(result);
    return NULL;
}