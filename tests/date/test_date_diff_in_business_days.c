#include <stdio.h>
#include <time.h>
#include "date/date_diff_in_business_days.h"

int main(void) {
    time_t start = 946684800; // Jan 1, 2000 (Saturday)
    time_t end = start + 6 * 86400; // Jan 7, 2000 (Friday)
    
    int result = date_diff_in_business_days(start, end);
    printf("Business days in week test: %s (got %d, expected 5)\n", 
           result == 5 ? "PASSED" : "FAILED", result);
    
    return 0;
}