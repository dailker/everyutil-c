#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/darken.h"

int main(void) {
    char *result;
    
    // Test darkening white
    result = darken("#ffffff", 0.5);
    if (result && strcmp(result, "#808080") == 0) {
        printf("darken white 50%%: PASSED\n");
    } else {
        printf("darken white 50%%: FAILED (got %s)\n", result ? result : "NULL");
    }
    free(result);
    
    // Test no darkening
    result = darken("#336699", 0.0);
    if (result && strcmp(result, "#336699") == 0) {
        printf("no darkening: PASSED\n");
    } else {
        printf("no darkening: FAILED\n");
    }
    free(result);
    
    // Test full darkening
    result = darken("#336699", 1.0);
    if (result && strcmp(result, "#000000") == 0) {
        printf("full darkening: PASSED\n");
    } else {
        printf("full darkening: FAILED\n");
    }
    free(result);
    
    // Test NULL input
    result = darken(NULL, 0.5);
    if (result == NULL) {
        printf("null input: PASSED\n");
    } else {
        printf("null input: FAILED\n");
        free(result);
    }
    
    return 0;
}