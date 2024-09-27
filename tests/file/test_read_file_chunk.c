#include <stdio.h>
#include <string.h>
#include "file/read_file_chunk.h"

int main(void) {
    // Create test file
    FILE *test = fopen("test_chunk.txt", "w");
    if (test) {
        fprintf(test, "0123456789");
        fclose(test);
    }
    
    char buffer[5] = {0};
    int bytes_read = read_file_chunk("test_chunk.txt", 2, 4, buffer);
    
    printf("Read file chunk test: %s\n", 
           (bytes_read == 4 && strncmp(buffer, "2345", 4) == 0) ? "PASSED" : "FAILED");
    
    // Cleanup
    remove("test_chunk.txt");
    
    return 0;
}