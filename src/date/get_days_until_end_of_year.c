#include "date/get_days_until_end_of_year.h"

EVERYUTIL_API int get_days_until_end_of_year(time_t timestamp) {
    struct tm *tm_info = localtime(&timestamp);
    if (!tm_info) return -1;
    
    struct tm end_year = {0};
    end_year.tm_year = tm_info->tm_year;
    end_year.tm_mon = 11; // December
    end_year.tm_mday = 31;
    end_year.tm_hour = 23;
    end_year.tm_min = 59;
    end_year.tm_sec = 59;
    
    time_t end_time = mktime(&end_year);
    return (int)((end_time - timestamp) / 86400);
}