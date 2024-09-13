#include "date/date_is_in_past.h"

EVERYUTIL_API int date_is_in_past(time_t timestamp) {
    return timestamp < time(NULL);
}