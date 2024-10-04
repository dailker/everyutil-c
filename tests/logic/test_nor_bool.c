#include <stdio.h>
#include "logic/nor_bool.h"

int main(void) {
    printf("NOR 0,0 test: %s\n", nor_bool(0, 0) == 1 ? "PASSED" : "FAILED");
    printf("NOR 0,1 test: %s\n", nor_bool(0, 1) == 0 ? "PASSED" : "FAILED");
    printf("NOR 1,0 test: %s\n", nor_bool(1, 0) == 0 ? "PASSED" : "FAILED");
    printf("NOR 1,1 test: %s\n", nor_bool(1, 1) == 0 ? "PASSED" : "FAILED");
    return 0;
}