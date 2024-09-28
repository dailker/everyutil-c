#include <stdio.h>
#include "logic/bool_cluster_count.h"

int main(void) {
    int array1[] = {1, 1, 0, 1, 1, 1, 0, 1};  // 3 clusters
    int array2[] = {0, 0, 0, 0};               // 0 clusters
    int array3[] = {1, 1, 1, 1};               // 1 cluster
    
    printf("Bool cluster count 3: %s\n", bool_cluster_count(array1, 8) == 3 ? "PASSED" : "FAILED");
    printf("Bool cluster count 0: %s\n", bool_cluster_count(array2, 4) == 0 ? "PASSED" : "FAILED");
    printf("Bool cluster count 1: %s\n", bool_cluster_count(array3, 4) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}