#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char* test=malloc(15);
	strcpy(test,"26.0");
	
	int a ='z';
	
	if(isdigit(a))	printf("Digit\n");
	else { printf("NOt digit\n");  }
	
	int res =0;
	res = atoi(test);
	
	printf("%d\n",res);
	
	return 0;
}
