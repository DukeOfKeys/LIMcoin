#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "Block.h"
#include "Transaction.h"
#include <stdlib.h>
#include <stdio.h>

#define MINING_REWOARD 10
#define MIN_ZEROS 2
char* SHA256(char* );
struct BlockChain{
    Block block;
    Transaction pendingtransactions[1000];
};
typedef struct BlockChain BlockChain;
    /// @brief  adds given block to the end of blockchain
    /// @param  blockchain where we want to add 
    /// @param  block that we want to add
    void newBlock(BlockChain*, Block*);


    void newtransaction(BlockChain*);


    /// @brief creates Genesis block with hardcoded params 
    /// @return Genesis block
    Block createFirstBlock();

    /// @brief saves block to main file with all blocks
    /// @param  block need to save
    void saveBlock(Block*);

    /// @brief loads blockchain form file to RAM
    /// @param  where to load
    int loadbloks(BlockChain*);

    /// @brief initialises blockchain 
    /// @param  what to init
    void initBlockchain(BlockChain*);

    /// @brief prints blockchain
    /// @param  what to print
    void printBlockchainInfo();

    void generateHashHeader(Block* , char*, int );
    void generateHash(char*, char*);
    char* mine(Block* block, long*);
    void createBlockFromData(BlockChain*, char*);
    void verifyBlockchain();
#endif

