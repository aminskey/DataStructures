#include <stdlib.h>
#include <stdio.h>

#include <hash.h>

int hash(int key){
        return key % SIZE;
}


int insert(int key, char *s){
        item *cell = (item *)malloc(sizeof(item *));
        cell -> key = key;
        cell -> s = s;

        int index = hash(key);

        while(hashTable[index] != NULL && hashTable[index] -> key != -1){
                ++index;
                index %= SIZE;
        }

        hashTable[index] = cell;
        return 0;
}
int delete(int key){
        int index = hash(key);

        while(hashTable[index] != NULL){
                if(hashTable[index] -> key = key){

                        hashTable[index] -> key = -1;
                        free(hashTable[index]);
                        return 0;
                }
                ++index;

                index %= SIZE;
        }
        return -1;
}
void display(){
        int index = hash(1);

        while(hashTable[index] != NULL){

                printf("\t%s\t-\t%d\n", hashTable[index] -> s, hashTable[index] -> key);

                ++index;
                index %= SIZE;
        }
}


item *search(int key){
        int index = hash(key);

        while(hashTable[index] != NULL){
                if(hashTable[index] -> key == key)
                        return hashTable[index];

                index++;
                index %= SIZE;
        }
        return NULL;
}

