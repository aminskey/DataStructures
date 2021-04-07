#ifndef __HASH_LIBS__
#define __HASH_LIBS__

#define SIZE 2000

typedef struct Item{
	int key;
	char *s;
} item;

item *hashTable[SIZE];

extern int hash();
extern int insert();
extern int delete();
extern void display();

extern item *search();

#endif
