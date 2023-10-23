//
//  PendingTransaction.h
//  LIMcoin
//
//  Created by Kiryl Yasinskiy on 10/22/23.
//

#ifndef PendingTransaction_h
#define PendingTransaction_h
#include <stdio.h>
#include <stdlib.h>
#include "Transaction.h"
struct PendingTransaction{
    Transaction data;
    struct PendingTransaction* next;
    struct PendingTransaction* prev;
};
typedef struct PendingTransaction PendingTransaction;
PendingTransaction* createPendingTransaction(Transaction);

void append(PendingTransaction**, Transaction);

void printPendingTransactions(PendingTransaction*);

void printBackward(PendingTransaction*);

Transaction popFront(PendingTransaction**);

void toArray(PendingTransaction**,Transaction*, int);
#endif /* PendingTransaction_h */
