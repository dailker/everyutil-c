#include <stdio.h>
#include "logic/toggle_bool.h"

int main(void) {
    printf("Toggle true test: %s\n", toggle_bool(1) == 0 ? "PASSED" : "FAILED");
    printf("Toggle false test: %s\n", toggle_bool(0) == 1 ? "PASSED" : "FAILED");
    return 0;
}