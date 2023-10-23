#include "menue.h"
#include <string.h>
//#include <openssl/ssh.h>

void menue(BlockChain* blockchain){
    char input[100];
    puts("Waiting for command.");
    printf("display - shows all bloks in blockchain\nexit - leave\npending - display pending transactions\ntrans -- create transaction\nmine - mine\nacc - balance");
    while(1){
        scanf("%s", input);
        if(strcmp(input, "display")==0){
        printBlockchainInfo();
        }
        if(strcmp(input, "acc")==0){
        puts("Your name:");
        char name[100];
        scanf("%s", name);
        balance(name);
        }
        if(strcmp(input, "exit")==0){
        return;
        }
        if(strcmp(input, "pending")==0){
        printPendingTransactions(blockchain->pendingTransactions);
        }
     if(strcmp(input, "trans")==0){
        char from[100];
        char to[100];
        long howMany = 0;
        puts("From:");
        scanf("%s", from);
        puts("To:");
        scanf("%s", to);
        puts("Ammount:");
        scanf("%ld", &howMany);
        append(&(blockchain->pendingTransactions),createTransaction(from, to, howMany));
        }
        if(strcmp(input, "mine")==0){
        newBlock(blockchain);
        }
    }
}
void inputargs(int number, char** argcs, BlockChain* blockChain){
for(int counter = 0; counter<number; counter++){
    printf("%s\n", argcs[number]);
}
}
