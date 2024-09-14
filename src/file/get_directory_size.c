#include "file/get_directory_size.h"
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

EVERYUTIL_API long get_directory_size(const char* path) {
    if (!path) return -1;
    
    DIR *dir = opendir(path);
    if (!dir) return -1;
    
    long total_size = 0;
    struct dirent *entry;
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        if (!full_path) continue;
        
        sprintf(full_path, "%s/%s", path, entry->d_name);
        
        struct stat st;
        if (stat(full_path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                long dir_size = get_directory_size(full_path);
                if (dir_size >= 0) total_size += dir_size;
            } else if (S_ISREG(st.st_mode)) {
                total_size += st.st_size;
            }
        }
        
        free(full_path);
    }
    
    closedir(dir);
    return total_size;
}