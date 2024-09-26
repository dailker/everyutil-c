#include <stdio.h>
#include <time.h>
#include "date/is_same_day.h"

int main(void) {
    time_t day1 = 946684800; // Jan 1, 2000 00:00:00
    time_t day1_later = day1 + 3600; // Same day, 1 hour later
    time_t day2 = day1 + 86400; // Next day
    
    printf("Same day test: %s\n", is_same_day(day1, day1_later) ? "PASSED" : "FAILED");
    printf("Different day test: %s\n", !is_same_day(day1, day2) ? "PASSED" : "FAILED");
    
    return 0;
}