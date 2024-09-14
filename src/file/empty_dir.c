#include "file/empty_dir.h"
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

static int remove_recursive(const char* path) {
    struct stat st;
    if (stat(path, &st) != 0) return -1;
    
    if (S_ISDIR(st.st_mode)) {
        DIR *dir = opendir(path);
        if (!dir) return -1;
        
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            
            char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
            if (full_path) {
                sprintf(full_path, "%s/%s", path, entry->d_name);
                remove_recursive(full_path);
                free(full_path);
            }
        }
        closedir(dir);
        return rmdir(path);
    } else {
        return remove(path);
    }
}

EVERYUTIL_API int empty_dir(const char* path) {
    if (!path) return -1;
    
    DIR *dir = opendir(path);
    if (!dir) return -1;
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        if (full_path) {
            sprintf(full_path, "%s/%s", path, entry->d_name);
            remove_recursive(full_path);
            free(full_path);
        }
    }
    
    closedir(dir);
    return 0;
}