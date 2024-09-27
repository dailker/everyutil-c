#include <stdio.h>
#include "file/file_exists.h"

int main(void) {
    printf("Current directory exists: %s\n", file_exists(".") ? "PASSED" : "FAILED");
    printf("Non-existent file: %s\n", !file_exists("non_existent_file_xyz") ? "PASSED" : "FAILED");
    return 0;
}