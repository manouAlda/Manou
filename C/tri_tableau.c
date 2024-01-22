#include <stdio.h>
void entreeTab( int taille, int *tableau);
void afficheTab( int taille, int *tableau);
void triTab( int taille , int *tableau);
void triTabH (int taille,int  *tableau);

int main(){
	printf("Traitement d'un tableau \n");
///Donnée
	int taille =10; 			//Déclaration de la taille du tableau
	int tableau[10];			//Déclaration du tableau
///Traitement
	printf("Entrée des valeurs du tableau\n");
	entreeTab ( taille, tableau );			
	
	printf("affichage du tableau normale\n");
	
	afficheTab (taille , tableau);            

	//triTab (taille,  tableau);			//Tri en ordre decroissant
	
	triTabH (taille, tableau);
	
	printf("Affichage du tableau avec ordre decroissant\n");
	afficheTab (taille , tableau);			//affichage du tableau avec ordre décroissant
	
	return 0;
}

void entreeTab( int taille, int *tableau){
	printf("Entrez les valeurs du tableau:\n");
	for(int i=0; i < taille ; i++){
		scanf("[%d] : %d", i+1,(tableau+i));
	}
}
void afficheTab( int taille, int *tableau){
	for(int i=0; i < taille ; i++){
		printf("\nTableau[%d]=%d\n", i,*(tableau+i) );
	}
}
void triTab( int taille , int *tableau){
	for(int i=0;i< 10; i ++){
		for(int j=i+1; j<10; j++){
			if (*(tableau+i) < *(tableau+j)){
				int t=0;
				t =*(tableau+j);
				*(tableau+j)=*(tableau+i);
				*(tableau+i)=t ;
		    }
		}	
	}
}
void triTabH (int taille,int  *tableau){
	for (int i=0; i < taille; i++){
		for (int k =0; k < taille-1; k++){
			if(*(tableau+k) > *(tableau+k+1)){
				int t;
				t = *(tableau+k);
				*(tableau+k) = *(tableau+k+1);
				*(tableau+k+1) = t;
			}
		}
	}
}
