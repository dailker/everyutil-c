#include <stdio.h>
#include "file/safe_parse_json.h"

int main(void) {
    printf("Valid JSON test: %s\n", safe_parse_json("{\"key\":\"value\"}") ? "PASSED" : "FAILED");
    printf("Invalid JSON test: %s\n", !safe_parse_json("{\"key\":\"value\"") ? "PASSED" : "FAILED");
    return 0;
}