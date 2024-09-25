#include <stdio.h>
#include <time.h>
#include "date/count_weekdays_between.h"

int main(void) {
    // Jan 1, 2000 (Saturday) to Jan 7, 2000 (Friday) = 5 weekdays
    time_t start = 946684800;
    time_t end = start + 6 * 86400;
    
    int result = count_weekdays_between(start, end);
    printf("Weekdays in one week: %s (got %d, expected 5)\n", 
           result == 5 ? "PASSED" : "FAILED", result);
    
    return 0;
}