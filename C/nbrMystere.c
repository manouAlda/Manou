#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int nombreMystere=0,
		nombreEntre=1;
	int nombreCoups ;
	const int	 max=100,
				 min=1;
/// Generation du nombre aleatoire
    srand(time(NULL));
	nombreMystere= (rand() % ( max - min +1)) +min ;
	
/* La boucle du programmme, elle se repete tant que l'utilisateur n'a pas trouve le nombreMystere. */
	
	do
	{
/// On demande le nombre a entrer	
	printf (" Quel est Le nombre ? \n ");
	scanf ("%d", &nombreEntre);
	nombreCoups ++;
	
/// On compare le nombreEntre avec le nombreMystere
	
			if(nombreEntre < nombreMystere)
				printf(" C'est plus!\n\n");
		
			else if (nombreEntre > nombreMystere)
				printf(" C'est moins!\n\n");
	
			else
				printf("Bravo, vous avez trouve le nombreMystere %d en %d coups !!!!\n\n", nombreMystere, nombreCoups);
		}while(nombreEntre != nombreMystere);
	
	return 0;
}

    