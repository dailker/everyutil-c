#include <stdio.h>
#include <time.h>
#include "date/date_add.h"

int main(void) {
    time_t base = 946684800; // Jan 1, 2000 00:00:00
    
    time_t result1 = date_add(base, 1, 0, 0, 0); // Add 1 day
    printf("Add 1 day: %s\n", result1 == base + 86400 ? "PASSED" : "FAILED");
    
    time_t result2 = date_add(base, 0, 1, 0, 0); // Add 1 hour
    printf("Add 1 hour: %s\n", result2 == base + 3600 ? "PASSED" : "FAILED");
    
    time_t result3 = date_add(base, 1, 2, 30, 45); // Add 1d 2h 30m 45s
    time_t expected = base + 86400 + 7200 + 1800 + 45;
    printf("Add complex: %s\n", result3 == expected ? "PASSED" : "FAILED");
    
    return 0;
}