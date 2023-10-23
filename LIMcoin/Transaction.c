#include "Transaction.h"
    Transaction createTransaction(char* from, char* to, long amount){
        Transaction created;
        strcpy(created.from, from);
        strcpy(created.to, to);
        created.ammount = amount;
        return created;
    }
