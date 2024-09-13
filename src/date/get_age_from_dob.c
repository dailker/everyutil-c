#include "date/get_age_from_dob.h"

EVERYUTIL_API int get_age_from_dob(time_t dob) {
    time_t now = time(NULL);
    struct tm *tm_dob = localtime(&dob);
    if (!tm_dob) return -1;
    struct tm tm_dob_copy = *tm_dob;
    
    struct tm *tm_now = localtime(&now);
    if (!tm_now) return -1;
    
    int age = tm_now->tm_year - tm_dob_copy.tm_year;
    if (tm_now->tm_mon < tm_dob_copy.tm_mon || 
        (tm_now->tm_mon == tm_dob_copy.tm_mon && tm_now->tm_mday < tm_dob_copy.tm_mday)) {
        age--;
    }
    return age;
}