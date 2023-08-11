#include <stdio.h>

int main(){
	printf("Quel nombre est le plus grand des nombres entres dans les deux tableaux\n");
	
	int taille=0;
	int tab1[5];
	int tab2[5];
	
	printf("\nEntrez la taille des tableaux a venir: ");
	scanf("%d", &taille);
	
	printf("\nVoici les valeurs des tableaux\n");
	printf("Premier tableau:\n");
	for(int i=0;i<5;i++){
		printf("[%d]: ",i);
		scanf("%d", tab1[i]);
	}
	printf("\nDeuxieme tableau:\n");
	for(int i=0;i<5;i++){
		printf("[%d]: ",i);
		scanf("%d", tab2[i]);
	}
	
	return 0;
}
    