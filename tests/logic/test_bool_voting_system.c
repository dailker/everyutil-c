#include <stdio.h>
#include "logic/bool_voting_system.h"

int main(void) {
    int votes1[] = {1, 1, 0};  // 2/3 true
    int votes2[] = {1, 1, 1};  // 3/3 true
    int votes3[] = {1, 0, 0};  // 1/3 true
    
    printf("Majority 2/3: %s\n", bool_voting_system(votes1, 3, VOTE_MAJORITY) == 1 ? "PASSED" : "FAILED");
    printf("Unanimous 3/3: %s\n", bool_voting_system(votes2, 3, VOTE_UNANIMOUS) == 1 ? "PASSED" : "FAILED");
    printf("Unanimous 2/3: %s\n", bool_voting_system(votes1, 3, VOTE_UNANIMOUS) == 0 ? "PASSED" : "FAILED");
    printf("Plurality 2/3: %s\n", bool_voting_system(votes1, 3, VOTE_PLURALITY) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}