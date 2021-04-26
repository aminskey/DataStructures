#ifndef STACK_LIB_H
#define STACK_LIB_H

#include <stdio.h>
#include <stdlib.h>

struct Stack {
	char *item;
	struct Stack *next;
};

extern struct Stack *head;
extern struct Stack *lastNode();

extern void initList();
extern void peek();
extern void printList();
extern void push();
extern void pop();
extern void clear();

extern int stackLength();

#endif
