#include <stdio.h>
#include <string.h>
#include "file/append_to_file.h"

int main(void) {
    const char *data = "test data";
    int result = append_to_file("test_append.txt", data, strlen(data));
    
    // Check if file contains the data
    FILE *file = fopen("test_append.txt", "r");
    char buffer[100] = {0};
    if (file) {
        fread(buffer, 1, sizeof(buffer), file);
        fclose(file);
    }
    
    printf("Append to file test: %s\n", (result == 0 && strstr(buffer, data)) ? "PASSED" : "FAILED");
    
    // Cleanup
    remove("test_append.txt");
    
    return 0;
}