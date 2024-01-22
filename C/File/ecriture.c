#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE* file ;
	file = fopen ("list.txt","r");
	
	if (file == NULL){
		exit(1);
	}
	char c;
	while (feof(file)!=1){
		c = fgetc(file);
		printf("%c",c);
	}
	fclose(file);
	file = fopen ("list.txt","a+");
	char* car= malloc (255);
	fgets (car,sizeof(car), stdin);
	
	fputs (car,file);
	
	fclose(file);
	free(car);
	
	return 0;
}
