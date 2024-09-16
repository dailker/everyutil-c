#include "logic/bool_voting_system.h"

EVERYUTIL_API int bool_voting_system(const int* votes, size_t size, vote_strategy_t strategy) {
    if (!votes || size == 0) return 0;
    
    int true_count = 0;
    for (size_t i = 0; i < size; i++) {
        if (votes[i]) true_count++;
    }
    
    switch (strategy) {
        case VOTE_MAJORITY:
            return true_count > (int)(size / 2);
        case VOTE_UNANIMOUS:
            return true_count == (int)size;
        case VOTE_PLURALITY:
            return true_count >= (int)size - true_count;
        default:
            return 0;
    }
}