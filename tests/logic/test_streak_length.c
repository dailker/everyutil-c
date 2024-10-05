#include <stdio.h>
#include "logic/streak_length.h"

int main(void) {
    int array1[] = {0, 1, 1, 1};  // streak of 3 trues
    int array2[] = {1, 1, 0, 0};  // streak of 2 falses
    int array3[] = {1};           // streak of 1
    
    printf("Streak length 3 test: %s\n", streak_length(array1, 4) == 3 ? "PASSED" : "FAILED");
    printf("Streak length 2 test: %s\n", streak_length(array2, 4) == 2 ? "PASSED" : "FAILED");
    printf("Streak length 1 test: %s\n", streak_length(array3, 1) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}