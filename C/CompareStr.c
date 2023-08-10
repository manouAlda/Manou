#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

	char* s1="abca";
	char* s2="xyzbac";
	char car;
	int count=1;
	
	int n=strlen(s1);
	int j=0,k=0;
	
	if(strlen(s1)<strlen(s2))  n =strlen(s2);
	printf("%d\n",n);
	
	for (int i=0;i<strlen(s1);i++){
		car = s1[i];		
		for(j=i+1;j<strlen(s1);j++){
			if(car==s1[j]){
				count++;
				printf("count %c = %d \n",car,count);
			}
		}
		
	}
	printf("m = %d\n\n",count);

    return 0;
}
