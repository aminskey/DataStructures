#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
	char *person;
	char *tlf;

	struct Node *next;
};

extern struct Node *head;
extern struct Node *findNode();
extern struct Node *newNode();

void printList();
void initList();

void deleteNode();
void appendNode();

#endif
