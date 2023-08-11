#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Diviseur d'un nombre\n");
	int n=0;
	do {
		printf("Entrez un nombre positif = ");
		scanf("%d",&n);
	}while (n<=0);
	//int count=0;  //int* div =(int*) malloc(n*sizeof(int));
	printf("\nLes diviseurs de %d sont : ",n);
	for (int i=1; i<= n; i++){
			if (n%i==0){
				//count++;
				printf("%d\t",i);
			}
	}	

	return 0;
}
