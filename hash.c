#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hash.h>

char *fgetline(FILE *fp);

int fgetsize(FILE *fp);

int main(int argc, char *argv[]){

	int ln=0;
	int i=0;
	char buff[200];
	char *file[10280];

	FILE *fp = fopen(argv[1],"rb");
	if(fp == NULL)
		printf("Cannot Find File :-(\n");

	while(!feof(fp)){
		insert(i++, fgetline(fp));
	}

	ln = fgetsize(fp);

	fclose(fp);

	for(int j=0;j<ln;j++){
		item *cell = search(j);
		printf("%s", cell -> s);
	}


	return 0;
}

int fgetsize(FILE *fp){
	fseek(fp, 0, SEEK_END);
	return ftell(fp);
}

char *fgetline(FILE *fp){

	char *p;
	char buff[fgetsize(fp)];
	int i=0;

	while(!feof(fp)){
		buff[i++] = fgetc(fp);
	}

	p=buff;
	return p;
}
