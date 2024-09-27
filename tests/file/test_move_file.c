#include <stdio.h>
#include "file/move_file.h"
#include "file/file_exists.h"

int main(void) {
    // Create a test file
    FILE *test = fopen("test_move_src.txt", "w");
    if (test) {
        fprintf(test, "test");
        fclose(test);
    }
    
    int result = move_file("test_move_src.txt", "test_move_dest.txt");
    printf("Move file test: %s\n", (result == 0 && file_exists("test_move_dest.txt") && !file_exists("test_move_src.txt")) ? "PASSED" : "FAILED");
    
    // Cleanup
    remove("test_move_dest.txt");
    
    return 0;
}