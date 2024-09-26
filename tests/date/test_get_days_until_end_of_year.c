#include <stdio.h>
#include <time.h>
#include "date/get_days_until_end_of_year.h"

int main(void) {
    time_t jan1 = 946684800; // Jan 1, 2000
    int days = get_days_until_end_of_year(jan1);
    
    // Should be positive number of days
    printf("Days until end of year test: %s (got %d)\n", 
           days > 300 ? "PASSED" : "FAILED", days);
    
    return 0;
}