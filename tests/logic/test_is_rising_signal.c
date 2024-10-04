#include <stdio.h>
#include "logic/is_rising_signal.h"

int main(void) {
    int array1[] = {0, 0, 1, 1, 1};  // rising in last 3
    int array2[] = {1, 1, 0, 0, 0};  // falling in last 3
    int array3[] = {0, 1, 0, 1};     // mixed in last 3
    
    printf("Rising signal test 1: %s\n", is_rising_signal(array1, 5, 3) == 1 ? "PASSED" : "FAILED");
    printf("Rising signal test 2: %s\n", is_rising_signal(array2, 5, 3) == 0 ? "PASSED" : "FAILED");
    printf("Rising signal test 3: %s\n", is_rising_signal(array3, 4, 3) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}