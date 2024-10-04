#include <stdio.h>
#include "logic/majority_truthy.h"

int main(void) {
    int values1[] = {1, 2, 0};  // 2/3 truthy
    int values2[] = {0, 0, 1};  // 1/3 truthy
    int values3[] = {5, -1, 3, 0, 0};  // 3/5 truthy
    
    printf("Majority truthy 2/3: %s\n", majority_truthy(values1, 3) == 1 ? "PASSED" : "FAILED");
    printf("Majority truthy 1/3: %s\n", majority_truthy(values2, 3) == 0 ? "PASSED" : "FAILED");
    printf("Majority truthy 3/5: %s\n", majority_truthy(values3, 5) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}