#include <stdio.h>
#include "file/delete_file.h"
#include "file/file_exists.h"

int main(void) {
    // Create a test file
    FILE *test = fopen("test_delete.txt", "w");
    if (test) {
        fprintf(test, "test");
        fclose(test);
    }
    
    int result = delete_file("test_delete.txt");
    printf("Delete file test: %s\n", (result == 0 && !file_exists("test_delete.txt")) ? "PASSED" : "FAILED");
    
    return 0;
}