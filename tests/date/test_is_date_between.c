#include <stdio.h>
#include <time.h>
#include "date/is_date_between.h"

int main(void) {
    time_t start = 946684800; // Jan 1, 2000
    time_t middle = start + 86400; // Jan 2, 2000
    time_t end = start + 2 * 86400; // Jan 3, 2000
    time_t outside = start - 86400; // Dec 31, 1999
    
    printf("Date between test: %s\n", is_date_between(middle, start, end) ? "PASSED" : "FAILED");
    printf("Date outside test: %s\n", !is_date_between(outside, start, end) ? "PASSED" : "FAILED");
    
    return 0;
}