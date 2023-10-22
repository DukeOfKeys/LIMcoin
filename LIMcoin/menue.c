#include "menue.h"
#include <string.h>
void menue(BlockChain* blockchain){
    char input[100];
    puts("Waiting for command.");
    printf("display - shows all bloks in blockchain\n");
    while(1){
        scanf("%s", input);
        if(strcmp(input, "display")==0){
        printBlockchainInfo();
        }
        if(strcmp(input, "exit")==0){
        return;
        }
    }
}
void inputargs(int number, char** argcs, BlockChain* blockChain){
for(int counter = 0; counter<number; counter++){
    printf("%s\n", argcs[number]);
}
}
