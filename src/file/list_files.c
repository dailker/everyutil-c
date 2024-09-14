#include "file/list_files.h"
#include <dirent.h>
#include <string.h>

EVERYUTIL_API int list_files(const char* dir_path, void (*callback)(const char* filename, void* user_data), void* user_data) {
    if (!dir_path || !callback) return -1;
    
    DIR *dir = opendir(dir_path);
    if (!dir) return -1;
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            callback(entry->d_name, user_data);
        }
    }
    
    closedir(dir);
    return 0;
}