#include <stdio.h>
#include "date/days_in_month.h"

int main(void) {
    printf("January 2000: %s\n", days_in_month(2000, 0) == 31 ? "PASSED" : "FAILED");
    printf("February 2000 (leap): %s\n", days_in_month(2000, 1) == 29 ? "PASSED" : "FAILED");
    printf("February 2001 (not leap): %s\n", days_in_month(2001, 1) == 28 ? "PASSED" : "FAILED");
    printf("April 2000: %s\n", days_in_month(2000, 3) == 30 ? "PASSED" : "FAILED");
    return 0;
}