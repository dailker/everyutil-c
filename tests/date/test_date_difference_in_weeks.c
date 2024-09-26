#include <stdio.h>
#include <time.h>
#include "date/date_difference_in_weeks.h"

int main(void) {
    time_t start = 946684800; // Jan 1, 2000
    time_t one_week = start + 7 * 24 * 3600;
    time_t two_weeks = start + 14 * 24 * 3600;
    
    printf("One week difference: %s\n", date_difference_in_weeks(one_week, start) == 1 ? "PASSED" : "FAILED");
    printf("Two weeks difference: %s\n", date_difference_in_weeks(two_weeks, start) == 2 ? "PASSED" : "FAILED");
    
    return 0;
}