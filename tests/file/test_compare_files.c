#include <stdio.h>
#include "file/compare_files.h"

int main(void) {
    // Create identical files
    FILE *file1 = fopen("test1.txt", "w");
    FILE *file2 = fopen("test2.txt", "w");
    if (file1 && file2) {
        fprintf(file1, "same content");
        fprintf(file2, "same content");
        fclose(file1);
        fclose(file2);
    }
    
    int result = compare_files("test1.txt", "test2.txt");
    printf("Compare identical files: %s\n", result == 1 ? "PASSED" : "FAILED");
    
    // Create different file
    FILE *file3 = fopen("test3.txt", "w");
    if (file3) {
        fprintf(file3, "different content");
        fclose(file3);
    }
    
    result = compare_files("test1.txt", "test3.txt");
    printf("Compare different files: %s\n", result == 0 ? "PASSED" : "FAILED");
    
    // Cleanup
    remove("test1.txt");
    remove("test2.txt");
    remove("test3.txt");
    
    return 0;
}