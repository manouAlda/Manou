#include <stdio.h>
#include <stdlib.h>

int** allouer(int line,int col);
int** enter (int line,int cols,int** tab);
int** print (int line,int cols,int** tab);
int** multiple (int line,int cols,int inter,int** A,int** B);

int main(){
	printf("Produit de matrices\n");
	int a,b,c,d;
	printf("Soit donc la matrices A et B.\nEntrez le nombre de lignes et de colonnes se la matrice A: ");
	scanf("%d\t%d",&a,&b);
	int** A = allouer (a,b);
	A = enter (a,b,A);   
	A = print (a,b,A);
	printf("\nEntrez le nombre de lignes et de colonnes se la matrice B: ");
	scanf("%d\t%d",&c,&d);
	int** B = allouer (c,d);
	B = enter (c,d,B);
	B = print (c,d,B);
	
	if (b!=c) printf("\nErreur, le produit est impossible.");
	else if (b==c){	
		int** C= allouer (a,d);
		C = multiple (a,d,b,A,B);
		printf("\nLe produit matriciel AB est : \n");
		C = print (a,d,C);
	}	

	return 0;
}
int** allouer(int line, int col){
	int** tab = NULL;
	tab=(int**)malloc(line*sizeof(int*));
	for (int i=0; i<line; i++){
		tab[i] = (int*)malloc(col*sizeof(int));
	}
	return tab;
}
int** enter (int line,int cols,int** tab){
	printf("\nEntrez les valeurs de la matrice: \n");
	for(int i=0; i<line; i++){
		for(int j=0; j<cols; j++){
			scanf("%d",&tab[i][j]);
		}
		printf("\n");	
	}
	return tab;
}
int** print (int line,int cols,int** tab){
	for(int i=0; i<line; i++){
		for(int j=0; j<cols; j++){
			printf("%d\t",tab[i][j]);
		}
		printf("\n");	
	}
	return tab;
} 
int** multiple (int line,int cols,int inter,int** A,int** B){
	int p=0;
	int** C= allouer(line,cols);
	for(int i=0; i<line;i++){
		for (int j=0; j<cols; j++){
			for(int k=0; k<inter;k++){
				p=p+A[i][k]*B[k][j];
			}
			C[i][j]=p;
			p=0;
		}
	}
	return C;
}
