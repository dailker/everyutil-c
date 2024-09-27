#include <stdio.h>
#include <string.h>
#include "file/safe_write_file.h"

int main(void) {
    const char *data = "test data";
    int result = safe_write_file("test_safe.txt", data, strlen(data));
    
    // Verify file contents
    FILE *file = fopen("test_safe.txt", "r");
    char buffer[100] = {0};
    if (file) {
        fread(buffer, 1, sizeof(buffer), file);
        fclose(file);
    }
    
    printf("Safe write file test: %s\n", 
           (result == 0 && strcmp(buffer, data) == 0) ? "PASSED" : "FAILED");
    
    // Cleanup
    remove("test_safe.txt");
    
    return 0;
}