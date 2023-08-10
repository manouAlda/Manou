#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int* ConvertToTab(int nbre);
int isanJavatra(int nbre);
char* caractere(int nbre);
int ascii(char car);
int CharTOInt (int nbre);
int CharToNb(int ligne,int nbre);
char** alloue2DChar(int taille);
int main (){
int nbre=543;	
	
	 ConvertToTab(nbre);
	
}
///int to int* 
int* ConvertToTab(int nbre){
	int ind=isanJavatra( nbre);	
	
	printf("\n%d",ind); //printf
	int* tab=(int*)malloc(ind*sizeof(int));
	int fin=0;
	fin=CharToNb(0, nbre);
	
	return tab;
	
}
int isanJavatra(int nbre){
	char* ind=malloc(60);
	int nbr=0;
	
	sprintf(ind,"%d",nbre);
	nbr=strlen(ind);   //compter le nombre du chiffre
	return nbr;
}		
 char* caractere(int nbre){
	char* car=malloc(60);
	sprintf(car,"%d",nbre);
	return car;

}
int ascii(char car){
	return (car-'0');
}
int CharToNb(int ligne,int nbre){               ///utile pour convertir les caracteres en entiers
	int be=0;
	int puiss=-1;
	char* tab=malloc(30);
	tab=caractere(nbre);
	char** carc=alloue2DChar(1);
	tab=caractere(nbre);
	
	sprintf(carc[0],"%s",tab);
	for(int i=strlen(carc[0]); i>=0; i--) {
		puiss+=1;
		
		be+=ascii(carc[0][i])* pow(10,puiss);
		
	}
	return nbre;
}
char** alloue2DChar(int taille){
	char** tab;
	tab=(char**)malloc((taille)*sizeof(char*));
	for(int i=0;i<(taille+1); i++){
		tab[i]=malloc(10);
	}
	return tab;
}
