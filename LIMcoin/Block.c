//
//  Block.c
//  LIMcoin
//
//  Created by Kiryl Yasinskiy on 10/22/23.
//
#include "Block.h"
#include <stdio.h>
#include <string.h>
#include "Utils.h"
void hashOftransactions(Transaction* transArray, int size, char* str){
    char  sumOfhashes[size*64+1], number[1000];
    sumOfhashes[0] = '\0';
    for(int counter = 0; counter<size; counter++){
        char arrayHash[1000];
        char hash[65];
        strcpy(arrayHash, transArray[counter].to);
        strcat(arrayHash, transArray[counter].from);
        ltoc(transArray[counter].ammount, number);
        strcat(arrayHash, number);
        strcpy(hash, SHA256(arrayHash));
        printf("\n data:  %s\nhash: %s\n", arrayHash, hash);
            strcat(sumOfhashes, hash);
        }
    
    printf("sum of hashes: %s\n", sumOfhashes);
    strcpy(str,SHA256(sumOfhashes));
}
