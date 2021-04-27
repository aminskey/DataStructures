#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <linkedlist.h>

int main(void){
        initList();

        appendNode("Amin", "42 41 46 51");
        appendNode("Ayesha", "12 34 56 78");
        appendNode("Mama", "26 23 33 73");

        printList();

        return 0;
}
