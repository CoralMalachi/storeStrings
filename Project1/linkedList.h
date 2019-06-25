#include <stdlib.h>
#include <stdio.h>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct nodes {
	char* str;
	struct nodes* next;

}node;

void push(node** head, char* s, size_t n);
void printList(node* head);
void freeList(node* head);

#endif