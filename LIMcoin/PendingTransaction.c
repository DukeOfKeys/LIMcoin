#include "PendingTransaction.h"
PendingTransaction* createPendingTransaction(Transaction data) {
    PendingTransaction* newNode = (PendingTransaction*)malloc(sizeof(PendingTransaction));
    if (newNode == NULL) {
        printf("Ошибка при выделении памяти для нового узла\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Функция для добавления элемента в конец списка
void append(PendingTransaction** head, Transaction data) {
    PendingTransaction* newNode = createPendingTransaction(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        PendingTransaction* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Функция для вывода списка в прямом порядке
void printPendingTransactions(PendingTransaction* head) {
    PendingTransaction* current = head;
    if (current == NULL){
        printf("NULL\n");
        return;
    }
    while (current != NULL) {

        printf("\n from: %s\n to:%s\n ammount: %ld\n", current->data.from, current->data.to, current->data.ammount);
        current = current->next;
    }
}

// Функция для вывода списка в обратном порядке
void printBackward(PendingTransaction* head) {
    PendingTransaction* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
      //  printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}
// Функция для считывания и удаления первого элемента списка
Transaction popFront(PendingTransaction** head) {
    if (*head == NULL) {
        printf("Список пуст, невозможно считать и удалить элемент\n");
        exit(1);
    }
    
    PendingTransaction* firstNode = *head;
    Transaction data = firstNode->data;
    
    *head = firstNode->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    
    free(firstNode);
    
    return data;
}
void toArray(PendingTransaction** pendingPtr,Transaction* transactionArray, int size){
    for(int counter = 0; counter < size; counter++){
        transactionArray[counter] = popFront(pendingPtr);
    }
}

