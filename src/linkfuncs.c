#include<stdio.h>
#include<stdlib.h>

struct node {
	int id;
	char *name;
	struct node *next;
};

int length(struct node*);

struct node *lastNode();
struct node *newNode(int, char *);
struct node *addNode(int, char *);
struct node *searchNode(int);

struct node *head = NULL;

int length(struct node* current){
	int i=0;

	for(i=0; current != NULL; i++){
		current = current -> next;
	}

	return i;
}


struct node *lastNode(){

	struct node *current = head;

	while(current -> next != NULL){
		current = current -> next;
	}

	return current;

}

struct node *newNode(int id, char* name){
	struct node *temp = NULL;
	temp = malloc(sizeof(struct node));
	temp -> id = id;
	temp -> name = name;
	temp -> next = NULL;

	return temp;
}


struct node *addNode(int id, char *name){
	struct node *prevNode = lastNode();
	struct node *thisNode = newNode(id, name);
	prevNode -> next = thisNode;
	thisNode -> next = NULL;
	return thisNode;

}
struct node *searchNode(int nodeId){
        struct node *temp = head;
	extern struct node *newNode();

	while(temp != NULL){
		if(temp -> id == nodeId){
			return temp;
		}
		temp = temp -> next;
	}
	return newNode(-1,"Node not found");
}
int removeNode(int id){
        struct node *temp = head;

        while(temp -> next != NULL){
                if(temp->next->id == id){
                        struct node *mid = temp->next;
                        temp->next = temp->next->next;
                        free(mid);
                        return 0;
                }

                temp = temp -> next;
        }

        return -1;
}
