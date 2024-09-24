#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/animate_color_transition.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

static int callback_count = 0;
static char* last_color = NULL;

EVERYUTIL_API void test_callback(const char* color) {
    callback_count++;
    free(last_color);
    last_color = color ? strdup(color) : NULL;
}

EVERYUTIL_API int strings_equal(const char* a, const char* b) {
    if (a == NULL || b == NULL) return a == b;
    return strcmp(a, b) == 0;
}

void run_test(const char* test_name, const char* start_hex, const char* end_hex, unsigned int duration_ms, int min_callbacks) {
    callback_count = 0;
    free(last_color);
    last_color = NULL;
    void* handle = animate_color_transition(start_hex, end_hex, duration_ms, test_callback);
    if (handle == NULL && (start_hex == NULL || end_hex == NULL || duration_ms == 0 || 
                          (start_hex && strncmp(start_hex, "#", 1) != 0) ||
                          (end_hex && strncmp(end_hex, "#", 1) != 0))) {
        printf("%s: PASSED\n", test_name);
        return;
    }
    if (handle == NULL) {
        printf("%s: FAILED (null handle)\n", test_name);
        return;
    }
#ifdef _WIN32
    Sleep(1000); // Wait for callbacks (Windows, 1 second)
#else
    sleep(1); // Wait for callbacks (POSIX, 1 second)
#endif
    animate_color_transition_stop(handle);
    printf("%s: ", test_name);
    if (callback_count >= min_callbacks && last_color != NULL) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
        printf("  Expected callbacks: >=%d, Got: %d\n", min_callbacks, callback_count);
        printf("  Last color: %s\n", last_color ? last_color : "NULL");
    }
    free(last_color);
    last_color = NULL;
}

int main(void) {
    run_test("valid transition", "#336699", "#ff0080", 500, 2);
    run_test("invalid start color", "invalid", "#ff0080", 500, 0);
    run_test("invalid end color", "#336699", "invalid", 500, 0);
    run_test("zero duration", "#336699", "#ff0080", 0, 0);
    run_test("null start color", NULL, "#ff0080", 500, 0);
    run_test("null end color", "#336699", NULL, 500, 0);
    return 0;
}