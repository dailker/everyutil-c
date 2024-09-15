#include "file/compare_files.h"
#include <stdio.h>

EVERYUTIL_API int compare_files(const char* pathA, const char* pathB) {
    if (!pathA || !pathB) return -1;
    
    FILE *fileA = fopen(pathA, "rb");
    FILE *fileB = fopen(pathB, "rb");
    
    if (!fileA || !fileB) {
        if (fileA) fclose(fileA);
        if (fileB) fclose(fileB);
        return -1;
    }
    
    int result = 1;
    int chA, chB;
    
    do {
        chA = fgetc(fileA);
        chB = fgetc(fileB);
        if (chA != chB) {
            result = 0;
            break;
        }
    } while (chA != EOF && chB != EOF);
    
    fclose(fileA);
    fclose(fileB);
    return result;
}