#include <stdio.h>
#include <time.h>
#include "date/date_is_in_future.h"

int main(void) {
    time_t now = time(NULL);
    time_t future = now + 3600;
    time_t past = now - 3600;
    
    printf("Future date test: %s\n", date_is_in_future(future) ? "PASSED" : "FAILED");
    printf("Past date test: %s\n", !date_is_in_future(past) ? "PASSED" : "FAILED");
    
    return 0;
}