#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/lighten.h"

int main(void) {
    char *result;
    
    // Test lightening black
    result = lighten("#000000", 0.5);
    if (result && strcmp(result, "#808080") == 0) {
        printf("lighten black 50%%: PASSED\n");
    } else {
        printf("lighten black 50%%: FAILED (got %s)\n", result ? result : "NULL");
    }
    free(result);
    
    // Test no lightening
    result = lighten("#336699", 0.0);
    if (result && strcmp(result, "#336699") == 0) {
        printf("no lightening: PASSED\n");
    } else {
        printf("no lightening: FAILED\n");
    }
    free(result);
    
    // Test full lightening
    result = lighten("#336699", 1.0);
    if (result && strcmp(result, "#ffffff") == 0) {
        printf("full lightening: PASSED\n");
    } else {
        printf("full lightening: FAILED\n");
    }
    free(result);
    
    // Test NULL input
    result = lighten(NULL, 0.5);
    if (result == NULL) {
        printf("null input: PASSED\n");
    } else {
        printf("null input: FAILED\n");
        free(result);
    }
    
    return 0;
}