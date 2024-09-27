#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include "file/list_files.h"

static int file_count = 0;

void count_files(const char* filename, void* user_data) {
    (void)filename;
    (void)user_data;
    file_count++;
}

int main(void) {
    // Create test directory with files
#ifdef _WIN32
    mkdir("test_list");
#else
    mkdir("test_list", 0755);
#endif
    
    FILE *file1 = fopen("test_list/file1.txt", "w");
    FILE *file2 = fopen("test_list/file2.txt", "w");
    if (file1 && file2) {
        fclose(file1);
        fclose(file2);
    }
    
    file_count = 0;
    int result = list_files("test_list", count_files, NULL);
    
    printf("List files test: %s (found %d files)\n", 
           (result == 0 && file_count == 2) ? "PASSED" : "FAILED", file_count);
    
    // Cleanup
    remove("test_list/file1.txt");
    remove("test_list/file2.txt");
    rmdir("test_list");
    
    return 0;
}