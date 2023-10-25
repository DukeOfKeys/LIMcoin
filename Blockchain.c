#include "Blockchain.h"
#include <stdio.h>
#include <string.h>
#include "Utils.h"

Block createFirstBlock(void){
        Block firstBlock;
        strcpy(firstBlock.prev_hash, "nan");
        firstBlock.timeCreated = time(NULL);
        strcpy(firstBlock.data, "first block");
        firstBlock.nonce = 0;
        saveBlock(&firstBlock);
        return firstBlock;
    }

    void newBlock(BlockChain* blockChain){
        Block newBlockWithtrans;
        toArray(&(*blockChain).pendingTransactions, newBlockWithtrans.transactions, 3);
        strcpy(newBlockWithtrans.data, "transactions");
        long nonce;
        char* hash = mine(&blockChain->block, &nonce);
        strcpy(newBlockWithtrans.prev_hash, hash);
        newBlockWithtrans.timeCreated = time(NULL);
        newBlockWithtrans.nonce = nonce;
        free(hash);
        saveBlock(&newBlockWithtrans);
        blockChain->block = newBlockWithtrans;
    }
    void initBlockchain(BlockChain* value){
        if(loadbloks(value) == 0)
        value->block = createFirstBlock();
        value->pendingTransactions = NULL;
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
            unsigned long result = fread(&newBlockV, sizeof(Block), 1,blocksFile);
            if(result != 0){
                (*whereToload).block = newBlockV;
            }
        }
        return 1;
    }

void printBlockchainInfo(void){
      FILE *blocksFile; 
        if ((blocksFile = fopen("blocks", "rb")) == NULL){
            puts("file Does not exist");
            return;
        }
        while(!feof(blocksFile)){
            Block newBlockV;
            unsigned long result = fread(&newBlockV, sizeof(Block), 1,blocksFile);
            if(result != 0){
                        printf("\n %s data:%s\n hash: %s\n nonce: %ld\n", ctime(&(newBlockV.timeCreated)), newBlockV.data, newBlockV.prev_hash, newBlockV.nonce);
            }
        }    
    }
void balance(char* account){
         FILE *blocksFile;
        if ((blocksFile = fopen("blocks", "rb")) == NULL){
            puts("file Does not exist");
            return;
        }
    long balance = 0;
        while(!feof(blocksFile)){
            Block newBlockV;
            unsigned long result = fread(&newBlockV, sizeof(Block), 1,blocksFile);
            if(result != 0){
                for(int counter = 0; counter < sizeof(newBlockV.transactions)/sizeof(Transaction); counter++)
                {
                    if(strcmp(newBlockV.transactions[counter].to, account) == 0){
                        balance += newBlockV.transactions[counter].ammount;
                    }
                    if(strcmp(newBlockV.transactions[counter].from, account) == 0){
                        balance -= newBlockV.transactions[counter].ammount;
                    }
                }
                
            }
        } 
        printf("Your balance: %ld\n", balance);
    }
    void generateHashHeader(Block* block, char* str, long nonce){
        char data[1000];
        char numberstr[100];
        strcpy(data,block->prev_hash);
        strcat(data, block->data);
        char ctime[20];
        sprintf(ctime, "%ld", (*block).timeCreated);
        strcat(data, ctime);
        ltoc(block->nonce, numberstr);
        strcat(data, numberstr);
        hashOftransactions((*block).transactions, 3, numberstr);
        strcat(data,numberstr);
        ltoc(nonce, numberstr);
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
