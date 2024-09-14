#include "date/is_date_between.h"

EVERYUTIL_API int is_date_between(time_t date, time_t start, time_t end) {
    return date >= start && date <= end;
}