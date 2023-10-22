#ifndef BLOCK_H
#define BLOCK_H
#include <time.h>
#include "Transaction.h"
struct Block{
    time_t timeCreated;
    char data[20];
    char prev_hash[65];
    Transaction transactions[1000];
    long nonce;
};
typedef struct Block Block;

#endif