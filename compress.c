#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hash.h>

int main(void){

	if(insert(1, "hello") == -1)
		printf("Cannot Insert Node\n");

	if(insert(2, "World") == -1)
		printf("Cannot Insert Node\n");

	display();

	if(delete(1) == -1)
		printf("Cannot Delete Node\n");

	printf("\n\n\n\n");
	display();

	printf("%d\n", hash(0));

	return 0;
}
