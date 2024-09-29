#include <stdio.h>
#include "logic/boolean_edge_detector.h"

int main(void) {
    edge_result_t result1 = boolean_edge_detector(1, 0);  // rising edge
    edge_result_t result2 = boolean_edge_detector(0, 1);  // falling edge
    edge_result_t result3 = boolean_edge_detector(1, 1);  // no edge
    
    printf("Rising edge test: %s\n", (result1.rising == 1 && result1.falling == 0) ? "PASSED" : "FAILED");
    printf("Falling edge test: %s\n", (result2.rising == 0 && result2.falling == 1) ? "PASSED" : "FAILED");
    printf("No edge test: %s\n", (result3.rising == 0 && result3.falling == 0) ? "PASSED" : "FAILED");
    
    return 0;
}