#include "date/date_is_in_future.h"

EVERYUTIL_API int date_is_in_future(time_t timestamp) {
    return timestamp > time(NULL);
}