#include <stdio.h>
#include "logic/case_switch.h"

int main(void) {
    case_pair cases[] = {{1, 10}, {2, 20}, {3, 30}};
    
    printf("Case switch 2: %s\n", case_switch(2, cases, 3, 0) == 20 ? "PASSED" : "FAILED");
    printf("Case switch 5: %s\n", case_switch(5, cases, 3, 99) == 99 ? "PASSED" : "FAILED");
    
    return 0;
}