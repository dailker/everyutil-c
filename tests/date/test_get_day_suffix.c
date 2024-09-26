#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date/get_day_suffix.h"

int main(void) {
    char *result1 = get_day_suffix(1);
    printf("1st test: %s\n", (result1 && strcmp(result1, "1st") == 0) ? "PASSED" : "FAILED");
    free(result1);
    
    char *result2 = get_day_suffix(2);
    printf("2nd test: %s\n", (result2 && strcmp(result2, "2nd") == 0) ? "PASSED" : "FAILED");
    free(result2);
    
    char *result11 = get_day_suffix(11);
    printf("11th test: %s\n", (result11 && strcmp(result11, "11th") == 0) ? "PASSED" : "FAILED");
    free(result11);
    
    return 0;
}