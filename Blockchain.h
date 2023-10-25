#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "Block.h"
#include "Transaction.h"
#include <stdlib.h>
#include <stdio.h>
#include "PendingTransaction.h"
#define MINING_REWOARD 10
#define MIN_ZEROS 2
struct BlockChain{
    Block block;
    PendingTransaction* pendingTransactions;
};
typedef struct BlockChain BlockChain;
    /// @brief  adds given block to the end of blockchain
    void newBlock(BlockChain*);


    void newtransaction(BlockChain*);
    /// @brief creates Genesis block with hardcoded params 
    /// @return Genesis block
    Block createFirstBlock(void);

    /// @brief saves block to main file with all blocks
    void saveBlock(Block*);

    /// @brief loads blockchain form file to RAM
    int loadbloks(BlockChain*);

    /// @brief initialises blockchain
    void initBlockchain(BlockChain*);

    /// @brief prints blockchain
    void printBlockchainInfo(void);

    void generateHashHeader(Block* , char*, long );
    void generateHash(char*, char*);
    char* mine(Block* block, long*);
    void balance(char*);
#endif

