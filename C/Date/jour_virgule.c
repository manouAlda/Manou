#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "j_virgule.h"

int main (){
	char car[]= "12.3/03/2023";
	int taille=0;
	int* indice=(int*)malloc(taille*sizeof(int));
	char** tab=NULL;                 //les indices du slash
	char** SepVir=NULL;
	int v=0;                        ///pour stocker la valeur de l' indice du virgule
	float nbre=0.0;
	char* format=NULL;
	char* date=NULL;
		
///allocation du tableau	
	tab=alloue2DChar(taille);
	format=malloc(150);
	date=malloc(50);
	
///utile pour separer le Slash	
	indice=IndiceSlash( car);
	tab=SeparerSlash( car,indice);
	
///utile pour separer le virgule	
	v=Etvirgule(tab);
	SepVir=SepareVirgule( v, tab);
	nbre=Double( v, SepVir);
	
///conversion en date
	convertirDate( nbre);
	format=affichageFormatDate(indice, car, tab);
	date=convertirDate(nbre);
///Resultat final
	printf("Voici la date : %s\n",format);
	printf("Voici l' heure: %s_\n",date);	
	

	return 0;
}	
