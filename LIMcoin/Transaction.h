#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TRANSACTION_H
#define TRANSACTION_H
    struct Transaction{
        char from[200];
        char to[200];
        long ammount;
    };
    typedef struct Transaction Transaction;
    Transaction createTransaction(char*, char*, long);
#endif
