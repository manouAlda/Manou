#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "triage.h"

int main(){
	int tab[7]={3, 6, 5, 8, 10, 20, 15};
	int taille = 7, n=0;
	int* tmp = malloc(sizeof(int)*taille);
	int* copie = malloc(taille*sizeof(int));
	int count=0;
	
	/*
	for(int k=0;k<taille;k++){
		copie[k]=tab[k];
	}	*/
	for(int i=0; i<taille-1;i++){
		//if(i==taille-2){
			printf("\nRECOPIE\n");
			for(int k=0;k<taille;k++){
				copie[k]=tab[k];
				printf("~ %d\n",copie[k]);
			}
		//}
		tmp = del(copie,taille,i);
		printf("  here  %d :   %d\n",i,tmp[i]);
		n = test(taille-1,tmp);
		if(n==1){
			count++;
			printf("\nCOUNT = %d\n",count);
		}
		else {
			count=0;
			continue;
		}
	}
	for(int i=0;i<taille;i++){
		printf("tab[%d] = %d\n",i,tab[i]);
	}
	if(count>0){
		printf("True");
	}
	else if (count ==0){
		printf("False");
	}
	
	return 0;
}
