#include <stdio.h>
#include <sys/stat.h>
#include "file/get_file_stats.h"

int main(void) {
    // Create test file
    FILE *test = fopen("test_stats.txt", "w");
    if (test) {
        fprintf(test, "test");
        fclose(test);
    }
    
    struct stat stats;
    int result = get_file_stats("test_stats.txt", &stats);
    printf("Get file stats test: %s\n", (result == 0 && stats.st_size > 0) ? "PASSED" : "FAILED");
    
    // Cleanup
    remove("test_stats.txt");
    
    return 0;
}