#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include "file/empty_dir.h"
#include "file/file_exists.h"

int main(void) {
    // Create test directory with files
#ifdef _WIN32
    mkdir("test_empty");
#else
    mkdir("test_empty", 0755);
#endif
    
    FILE *file1 = fopen("test_empty/file1.txt", "w");
    if (file1) {
        fprintf(file1, "test");
        fclose(file1);
    }
    
    int result = empty_dir("test_empty");
    
    printf("Empty dir test: %s\n", 
           (result == 0 && file_exists("test_empty") && !file_exists("test_empty/file1.txt")) ? "PASSED" : "FAILED");
    
    // Cleanup
    rmdir("test_empty");
    
    return 0;
}