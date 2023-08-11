#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int test (int taille,int* tab){
	int n=0;
	for(int i=taille-1;i>0; i--){
		if(tab[i]>tab[i-1]){
			n=1;
			printf("%d 		%d\n",tab[i],tab[i-1]);
		}
		else{
			break;
		}
	}
	return n;
}
int* del (int* tab,int taille,int pos){
	for(int j=pos;j<taille-1;j++){
		tab[j]=tab[j+1];
		printf("	%d		%d 		\n",j,tab[j]);
		
	}
	return tab;
}

int main(){
	int tab[5]={1,3,2,1};
	int taille = 4, n=0;
	int* tmp = malloc(sizeof(int)*taille);
	int* copie = malloc(taille*sizeof(int));
	int count=0;
	
	for(int k=0;k<taille;k++){
		copie[k]=tab[k];
	}	
	for(int i=0; i<taille-1;i++){
		if(i==taille-2){
			printf("\nRECOPIE\n");
			for(int k=0;k<taille;k++){
				copie[k]=tab[k];
				printf("~ %d\n",copie[k]);
			}
		}
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
