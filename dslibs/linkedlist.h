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
