#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char *person;
	char *tlf;

	struct Node *next;
};

struct Node *head = NULL;

struct Node *findNode(char *);
struct Node *lastNode();
struct Node *newNode(char *, char *);

void printList(void);
void initList(void);

void deleteNode(char *);
void appendNode(char *, char *);

void printList(void){
	struct Node *tmp = head;

	printf("\x1b[42m---%20c%30s%40c%50s\x1b[0m\n", ' ', "Person", ' ', "Telephone Number");

	for(int i=0; tmp != NULL; i++){
		printf("%03d%20c\x1b[42m \x1b[0m%29s%40c\x1b[42m \x1b[0m%49s\n", i, ' ', tmp -> person, ' ', tmp -> tlf);

		tmp = tmp -> next;
	}
	printf("\x1b[42m   %20c%30s%40c%50s\x1b[0m\n", ' ', "      ", ' ', "                ");
}

void initList(void){
	head = (struct Node*)malloc(sizeof(struct Node));

	head -> next = NULL;
	head -> person = "The Boss";
	head -> tlf = "1084-097-213";
}

struct Node *newNode(char *person, char *tlf){
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));

	node -> next = NULL;
	node -> person = person;
	node -> tlf = tlf;

	return node;
}

void deleteNode(char *tlf){
	struct Node *prev = head;
	struct Node *tmp = NULL;

	while(prev -> next -> next != NULL){
		prev = prev -> next;

		if(!strcmp(prev -> tlf, tlf)){

			tmp = prev -> next;
			prev -> next = tmp -> next;
			tmp -> next = NULL;

			tmp -> person = NULL;
			tmp -> tlf = NULL;

			free(tmp);
		}
	}
}

void appendNode(char *person, char *tlf){

	struct Node *prev = lastNode();
	struct Node *tmp = newNode(person, tlf);

	prev -> next = tmp;
}

struct Node *findNode(char *tlf){
	struct Node *tmp = head;

	while(tmp -> next != NULL){
		tmp = tmp -> next;
		if(!strcmp(tmp -> tlf, tlf))
			break;
	}

	return tmp;
}
struct Node *lastNode(){
	struct Node *tmp = head;
	while(tmp -> next != NULL){
		tmp = tmp -> next;
	}
	return tmp;
}
