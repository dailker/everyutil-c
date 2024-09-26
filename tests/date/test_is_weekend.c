#include <stdio.h>
#include <time.h>
#include "date/is_weekend.h"

int main(void) {
    // Jan 1, 2000 is Friday (day 5), so add 1 day to get Saturday
    time_t friday = 946684800; // Jan 1, 2000 (Friday)
    time_t saturday = friday + 86400; // Jan 2, 2000 (Saturday)
    
    printf("Weekend test: %s\n", is_weekend(saturday) ? "PASSED" : "FAILED");
    printf("Weekday test: %s\n", !is_weekend(friday) ? "PASSED" : "FAILED");
    
    return 0;
}