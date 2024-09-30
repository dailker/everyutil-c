#include <stdio.h>
#include "logic/boolean_pulse.h"

int main(void) {
    pulse_state_t pulse = boolean_pulse_create(2, 5);  // 2 on, 3 off, repeat
    
    int pattern[10];
    for (int i = 0; i < 10; i++) {
        pattern[i] = boolean_pulse_next(&pulse);
    }
    
    // Expected: 1,1,0,0,0,1,1,0,0,0
    int expected[] = {1,1,0,0,0,1,1,0,0,0};
    int match = 1;
    for (int i = 0; i < 10; i++) {
        if (pattern[i] != expected[i]) {
            match = 0;
            break;
        }
    }
    
    printf("Boolean pulse pattern test: %s\n", match ? "PASSED" : "FAILED");
    
    return 0;
}