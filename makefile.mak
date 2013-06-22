#makefile
CC = gcc
WARNINGS = -Wall

all: LinkedLists.dll

LinkedLists.dll: LinkedList.o linkedlist_ull.o LinkedListString.o
	$(CC) -shared -o LinkedLists.dll LinkedList.o linkedlist_ull.o LinkedListString.o -Wl,--out-implib,libmessage.a
	
LinkedList.o: LinkedList.c LinkedList.h
	$(CC) -c -DBUILD_DLL LinkedList.c

linkedlist_ull.o: linkedlist_ull.c linkedlist_ull.h
	$(CC) -c -DBUILD_DLL linkedlist_ull.c
	
LinkedListString.o: LinkedListString.c LinkedListString.h
	$(CC) -c -DBUILD_DLL LinkedListString.c
	
clean:
	rm -rf *o LinkedLists.dll
