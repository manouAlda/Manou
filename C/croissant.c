#include <stdio.h>
#include <stdbool.h>

int main(){
	//int tab[4]={1,3,2};
	int tab [10]= {123, -17, -5, 1, 2, 3, 12, 43, 45};
	
	for(int i=0;i<10-2;i++){
		if(tab[i]<=tab[i+1]){
			printf("True\n");
		}
		else{
			printf("False\n");
		}
	}

	return 0;
}
