#include "Utils.h"
#include "Blockchain.h"
#include "menue.h"
int main(int count,char** arcs){
    struct BlockChain a;
    initBlockchain(&a);
    if(count > 1)
    inputargs(count, arcs, &a);
    printf("%lu\n", sizeof(a.block.transactions));
    char lol[4040000];
    menue(&a);
    return 0;
}