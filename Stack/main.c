#include <stdio.h>
#include <stdlib.h>

#include <stack.h>

int main(void){

	initList();
	push("Frieght Train");
	push("Cargo Train");
	push("Hello, World!!");

	printList();

	printf("\n\nAdding Changes!!\n\n");

	clear();
	push("Hello, Again!!");
	peek();

	return 0;
}

