#ifndef LOGIC_BOOL_VOTING_SYSTEM_H
#define LOGIC_BOOL_VOTING_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

typedef enum {
    VOTE_MAJORITY,
    VOTE_UNANIMOUS,
    VOTE_PLURALITY
} vote_strategy_t;

/**
 * Voting system for boolean values.
 *
 * @param votes Array of boolean votes.
 * @param size Size of array.
 * @param strategy Voting strategy.
 * @return Voting result.
 */
EVERYUTIL_API int bool_voting_system(const int* votes, size_t size, vote_strategy_t strategy);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_BOOL_VOTING_SYSTEM_H