#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file/normalize_path.h"

int main(void) {
    char *result = normalize_path("path//to\\\\file");
    printf("Normalize path test: %s\n", 
           (result && strcmp(result, "path/to/file") == 0) ? "PASSED" : "FAILED");
    free(result);
    
    return 0;
}