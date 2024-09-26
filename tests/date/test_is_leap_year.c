#include <stdio.h>
#include "date/is_leap_year.h"

int main(void) {
    printf("2000 is leap year: %s\n", is_leap_year(2000) ? "PASSED" : "FAILED");
    printf("1900 is not leap year: %s\n", !is_leap_year(1900) ? "PASSED" : "FAILED");
    printf("2004 is leap year: %s\n", is_leap_year(2004) ? "PASSED" : "FAILED");
    printf("2001 is not leap year: %s\n", !is_leap_year(2001) ? "PASSED" : "FAILED");
    return 0;
}