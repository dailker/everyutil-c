#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logic/random_bool.h"

int main(void) {
    srand((unsigned int)time(NULL));
    
    printf("Random bool 0.0 test: %s\n", random_bool(0.0) == 0 ? "PASSED" : "FAILED");
    printf("Random bool 1.0 test: %s\n", random_bool(1.0) == 1 ? "PASSED" : "FAILED");
    
    // Test probability distribution (should be roughly 50/50)
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (random_bool(0.5)) count++;
    }
    printf("Random bool 0.5 distribution test: %s (got %d/1000)\n", 
           (count > 400 && count < 600) ? "PASSED" : "FAILED", count);
    
    return 0;
}