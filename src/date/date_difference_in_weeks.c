#include "date/date_difference_in_weeks.h"
#include <stdlib.h>

EVERYUTIL_API int date_difference_in_weeks(time_t a, time_t b) {
    double diff = difftime(a, b);
    if (diff < 0) diff = -diff;
    return (int)(diff / (7 * 24 * 60 * 60));
}