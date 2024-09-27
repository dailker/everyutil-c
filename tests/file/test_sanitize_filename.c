#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file/sanitize_filename.h"

int main(void) {
    char *result = sanitize_filename("file<>:name.txt");
    printf("Sanitize filename test: %s\n", 
           (result && strcmp(result, "file___name.txt") == 0) ? "PASSED" : "FAILED");
    free(result);
    
    return 0;
}