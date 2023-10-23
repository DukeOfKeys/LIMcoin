#include "Utils.h"
#include "Blockchain.h"
#include "menue.h"
#include "Transaction.h"
int main(int count,char** arcs){
    struct BlockChain a;
    initBlockchain(&a);
    if(count > 1)
    inputargs(count, arcs, &a);
    printBlockchainInfo();
    menue(&a);
    return 0;
}

