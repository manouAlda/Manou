#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "dateETheure.h"

int main (){
	char heure[30]="20/05/2023  7:12:00";
	char** espace=NULL;
	int* position=NULL;
	char** slash=NULL;
	char* final=malloc(10);
	int ligne=0;
	float jours=0.0;
	///allocation du tableau
	espace=alloue2DChar(3);
	position=(int*)malloc(2*sizeof(int));
	slash=alloue2DChar(4);

	///afficher la separation du slash
	espace=SeparerEspace( heure);
	
	///position Slash
	position=position_Slash(ligne,espace);
	
	
	///separation Slash
	slash=separationSlash(ligne,espace);
		///charTO INt
	CharToInt(ligne,slash);

	///conversion du format heures en nombre de jours
	jours=Conversion_en_jour(ligne,espace);
	
	 ///etape finale
	final=changementDuFormat(jours, espace);
	printf("\nLe nouveau format est %s ",final);
	return 0;
}	

