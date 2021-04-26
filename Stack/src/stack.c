#include <stdio.h>
#include <stdlib.h>

struct Stack {
	char *item;
	struct Stack *next;
};

struct Stack *head = NULL;


struct Stack *lastNode(void);

void push(char *);
void pop(void);
void clear(void);
void initList(void);
void peek(void);
void printList(void);

int stackLength(void);

struct Stack *lastNode(){
        struct Stack *tmp = head;
        while(tmp -> next != NULL){
                tmp = tmp -> next;
        }
	return tmp;
}

void push(char *item){
        struct Stack *node = (struct Stack *)malloc(sizeof(struct Stack));
        struct Stack *prev = lastNode();

        node -> item = item;
        node -> next = NULL;
        prev -> next = node;
}

void pop(void){
        struct Stack *prev = head;
        struct Stack *tmp = NULL;

        while(1){
                prev = prev -> next;
                if(prev -> next -> next == NULL){
                        tmp = prev -> next;
                        tmp -> item = NULL;
                        tmp = NULL;

                        prev -> next = NULL;
                        free(tmp);
                        break;
                }
        }
}

void clear(void){
        for(int i=0; i<stackLength() - 1; i++)
                pop();
}

void initList(void){
        head = (struct Stack *)malloc(sizeof(struct Stack));
        head -> item = "Head Node!";
        head -> next = NULL;
}

void peek(void){
        struct Stack *tmp = lastNode();

        printf("%03d%50s\n", stackLength(), tmp -> item);
}

void printList(void){
        struct Stack *tmp = head;
        for(int i=0; tmp != NULL; i++){
                printf("%03d%50s\n", i, tmp -> item);
                tmp = tmp -> next;
        }
}

int stackLength(void){
        struct Stack *tmp = head;
        int i=0;

        for(i=0; tmp != NULL; i++){
                tmp = tmp -> next;
        }

	return i;
}

