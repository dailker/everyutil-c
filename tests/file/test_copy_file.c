#include <stdio.h>
#include <stdlib.h>
#include "file/copy_file.h"
#include "file/file_exists.h"

int main(void) {
    // Create a test file
    FILE *test = fopen("test_src.txt", "w");
    if (test) {
        fprintf(test, "test content");
        fclose(test);
    }
    
    int result = copy_file("test_src.txt", "test_dest.txt");
    printf("Copy file test: %s\n", (result == 0 && file_exists("test_dest.txt")) ? "PASSED" : "FAILED");
    
    // Cleanup
    remove("test_src.txt");
    remove("test_dest.txt");
    
    return 0;
}