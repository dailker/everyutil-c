#include "date/count_weekdays_between.h"

EVERYUTIL_API int count_weekdays_between(time_t start, time_t end) {
    int count = 0;
    time_t current = start;
    while (current <= end) {
        struct tm *tm_info = localtime(&current);
        if (tm_info && tm_info->tm_wday != 0 && tm_info->tm_wday != 6) {
            count++;
        }
        current += 86400; // Add one day
    }
    return count;
}