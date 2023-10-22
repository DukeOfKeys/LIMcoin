#include "Blockchain.h"
#include <stdio.h>
#include <string.h>
#include "Utils.h"

    Block createFirstBlock(){
        Block firstBlock;
        firstBlock.timeCreated = time(NULL);
        strcpy(firstBlock.data, "first block");
        firstBlock.nonce = 0;
        saveBlock(&firstBlock);
        return firstBlock;
    }

    void newBlock(BlockChain* blockChain, Block* newBlock){
        long nonce;
        char* hash = mine(&blockChain->block, &nonce);
        strcpy(newBlock->prev_hash, hash);
        newBlock->timeCreated = time(NULL);
        newBlock->nonce = nonce;
        free(hash);
        saveBlock(newBlock);
        blockChain->block = *newBlock;
    }
    void initBlockchain(BlockChain* value){
        if(loadbloks(value) == 0)
        value->block = createFirstBlock();
    }
    void saveBlock(Block* blockToSave){
        FILE *blocksFile; 
        if ((blocksFile = fopen("blocks", "ab+")) == NULL){
            puts("there are some problems");
            return;
        }
        fwrite(blockToSave, sizeof(Block), 1, blocksFile);
        fclose(blocksFile);
    }

    int loadbloks(BlockChain* whereToload){
       FILE *blocksFile; 
        if ((blocksFile = fopen("blocks", "rb")) == NULL){
            puts("file Does not exist");
            return 0;
        }
        if(feof(blocksFile))
            return 0;
        
        while(!feof(blocksFile)){
            Block newBlockV;
            int result = fread(&newBlockV, sizeof(Block), 1,blocksFile);
            if(result != 0){
                (*whereToload).block = newBlockV;
            }
        }
        return 1;
    }

    void printBlockchainInfo(){
      FILE *blocksFile; 
        if ((blocksFile = fopen("blocks", "rb")) == NULL){
            puts("file Does not exist");
            return;
        }    
        while(!feof(blocksFile)){
            Block newBlockV;
            int result = fread(&newBlockV, sizeof(Block), 1,blocksFile);
            if(result != 0){
                        printf("\n %s data:%s\n hash: %s\n nonce: %ld\n", ctime(&(newBlockV.timeCreated)), newBlockV.data, newBlockV.prev_hash, newBlockV.nonce);
            }
        }       
    }
    void verifyBlockchain(){
         FILE *blocksFile; 
        if ((blocksFile = fopen("blocks", "rb")) == NULL){
            puts("file Does not exist");
            return;
        }    
        while(!feof(blocksFile)){
            Block newBlockV;
            int result = fread(&newBlockV, sizeof(Block), 1,blocksFile);
            if(result != 0){
                        printf(" %s\n data:%s\n hash: %s\n nonce: %ld\n", ctime(&(newBlockV.timeCreated)), newBlockV.data, newBlockV.prev_hash, newBlockV.nonce);
            }
        } 
    }
    void generateHashHeader(Block* block, char* str, int nonce){
        char data[1000];
        char numberstr[100];
        strcpy(data,block->prev_hash);
        strcat(data, block->data);
        char ctime[20];
        sprintf(ctime, "%ld", (*block).timeCreated);
        strcat(data, ctime);
        itoc(block->nonce, numberstr);
        strcat(data, numberstr);
        itoc(nonce, numberstr);
        strcat(data, numberstr);
        printf("\n %s \n", data);
        generateHash(data, str);
    }
    void generateHash(char* str, char* in){
        strcpy(in, SHA256(str));
    }
    char* mine(Block* block,  long* innonce){
        char* hash = malloc(65);
        long nonce = 0;
        do{
            generateHashHeader(block, hash, nonce);
            *innonce = nonce;
            nonce++;
        } while( compareZeros(hash, MIN_ZEROS) != 1 );
        return hash;
    }
        void createBlockFromData(BlockChain* chain, char* str){
            Block strBlock;
            strcpy(strBlock.data, str);
            newBlock(chain, &strBlock);
        }
