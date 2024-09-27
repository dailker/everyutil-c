#include <stdio.h>
#include <time.h>
#include "date/date_is_in_past.h"

int main(void) {
    time_t now = time(NULL);
    time_t future = now + 3600;
    time_t past = now - 3600;
    
    printf("Past date test: %s\n", date_is_in_past(past) ? "PASSED" : "FAILED");
    printf("Future date test: %s\n", !date_is_in_past(future) ? "PASSED" : "FAILED");
    
    return 0;
}