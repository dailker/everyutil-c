#include "date/is_weekend.h"

EVERYUTIL_API int is_weekend(time_t timestamp) {
    struct tm *tm_info = localtime(&timestamp);
    if (!tm_info) return 0;
    int day = tm_info->tm_wday;
    return day == 0 || day == 6;
}