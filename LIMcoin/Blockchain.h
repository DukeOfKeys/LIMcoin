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
    void newBlock(BlockChain*, Block*);


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

    void generateHashHeader(Block* , char*, int );
    void generateHash(char*, char*);
    char* mine(Block* block, long*);
    void createBlockFromData(BlockChain*, char*);
    void verifyBlockchain(void);
#endif

