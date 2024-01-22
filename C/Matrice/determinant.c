#include <stdio.h>
#include <stdlib.h>

int** allouer(int line,int cols){
	int **tab=NULL;
	tab=(int**)malloc(sizeof(int*)*line);
	for(int i=0;i<line;i++){
		*(tab+i)=(void*)calloc(cols,sizeof(int)*cols);
	}
	return tab;
}
int** enter (int line,int cols,int** tab){
	//printf("Entrez les valeurs de la matrice: \n");
	for(int i=0;i<line;i++){
		for(int j=0;j<cols;j++){
			scanf("%d",tab[i][j]);
		//	printf("     erreur");
		}
	}
	return tab;
}
int main(){
	int l=0,c=0;
	printf("Lignes: ");scanf("%d",&l);
	printf("Colonnes: ");scanf("%d",&c);
	
	int** A = allouer (l,c);
	A = enter (l,c,A);
	int** B = allouer (l,c);
	B = enter (l,c,B);
	
	
	return 0;	
}
