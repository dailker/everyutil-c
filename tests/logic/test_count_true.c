#include <stdio.h>
#include "logic/count_true.h"

int main(void) {
    int array[] = {1, 0, 1, 1, 0};
    int result = count_true(array, 5);
    printf("Count true test: %s (got %d)\n", result == 3 ? "PASSED" : "FAILED", result);
    return 0;
}