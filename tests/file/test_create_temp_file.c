#include <stdio.h>
#include <stdlib.h>
#include "file/create_temp_file.h"
#include "file/file_exists.h"

int main(void) {
    char *temp_path = create_temp_file("test");
    printf("Create temp file test: %s\n", (temp_path && file_exists(temp_path)) ? "PASSED" : "FAILED");
    
    if (temp_path) {
        remove(temp_path);
        free(temp_path);
    }
    
    return 0;
}