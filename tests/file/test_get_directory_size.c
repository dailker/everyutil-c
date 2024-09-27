#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include "file/get_directory_size.h"

int main(void) {
    // Create test directory with files
#ifdef _WIN32
    mkdir("test_dir_size");
#else
    mkdir("test_dir_size", 0755);
#endif
    
    FILE *file1 = fopen("test_dir_size/file1.txt", "w");
    FILE *file2 = fopen("test_dir_size/file2.txt", "w");
    if (file1 && file2) {
        fprintf(file1, "test");  // 4 bytes
        fprintf(file2, "data");  // 4 bytes
        fclose(file1);
        fclose(file2);
    }
    
    long size = get_directory_size("test_dir_size");
    printf("Get directory size test: %s (size: %ld)\n", size >= 8 ? "PASSED" : "FAILED", size);
    
    // Cleanup
    remove("test_dir_size/file1.txt");
    remove("test_dir_size/file2.txt");
    rmdir("test_dir_size");
    
    return 0;
}