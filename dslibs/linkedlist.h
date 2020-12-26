#ifndef LINKEDLIST_LIB_H
#define LINKEDLIST_LIB_H

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

struct node {
	int id;
	char *name;
	struct node *next;
};

extern struct node *head;
extern struct node *lastNode();
extern struct node *newNode();
extern struct node *addNode();
extern struct node *searchNode();

extern int length();
extern int removeNode();

extern void printList();

#endif
