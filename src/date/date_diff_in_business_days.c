#include "date/date_diff_in_business_days.h"

EVERYUTIL_API int date_diff_in_business_days(time_t start, time_t end) {
    int count = 0;
    time_t current = start;
    while (current <= end) {
        struct tm *tm_info = localtime(&current);
        if (tm_info && tm_info->tm_wday != 0 && tm_info->tm_wday != 6) {
            count++;
        }
        current += 86400;
    }
    return count;
}