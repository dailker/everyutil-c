#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logic/simulate_coin_flips.h"

int main(void) {
    srand((unsigned int)time(NULL));
    
    int array[10];
    simulate_coin_flips(array, 10);
    
    // Check that all values are 0 or 1
    int valid = 1;
    for (int i = 0; i < 10; i++) {
        if (array[i] != 0 && array[i] != 1) {
            valid = 0;
            break;
        }
    }
    
    printf("Simulate coin flips test: %s\n", valid ? "PASSED" : "FAILED");
    
    return 0;
}