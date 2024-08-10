CC=gcc
DEPS = Blockchain.h PendingTransaction.h Utils.h Transaction.h Block.h menue.h
main: main.c Block.c Blockchain.c menue.c PendingTransaction.c sha-256.c Transaction.c Utils.c
	$(CC) main.c Block.c Blockchain.c menue.c PendingTransaction.c sha-256.c Transaction.c Utils.c -o main 