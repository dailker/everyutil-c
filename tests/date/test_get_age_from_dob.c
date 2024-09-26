#include <stdio.h>
#include <time.h>
#include "date/get_age_from_dob.h"

int main(void) {
    // Birth date: Jan 1, 1990
    struct tm birth_tm = {0};
    birth_tm.tm_year = 90; // 1990 (tm_year is years since 1900)
    birth_tm.tm_mon = 0;   // January
    birth_tm.tm_mday = 1;
    time_t birth = mktime(&birth_tm);
    
    int age = get_age_from_dob(birth);
    printf("Age calculation test: %s (age: %d)\n", age > 0 ? "PASSED" : "FAILED", age);
    
    return 0;
}