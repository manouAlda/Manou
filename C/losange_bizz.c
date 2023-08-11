#include <stdio.h>

int main(){
	int l=0;
	printf("Entrez la longueur : ");
	scanf("%d",&l);
	
	for (int i=1;i<=l;i++){
		for(int j=1; j<= l-i;j++){
			printf("  ");
		}
		for(int j=1; j<= l;j++){
			printf("* ");
		}
		printf("\n");
	}
	
	return 0;
}
