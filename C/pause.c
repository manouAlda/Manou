#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mon_sleep( int nbr_seconds );

int main()  {
    int x;
    int wait = 13;
    
    printf("Pause pendant %d secondes\n", wait );
    printf(">");
    for (x=1; x <= wait; x++) {
        printf(".");
        /* affichage d’un point */
        fflush(stdout); /* on force l’affichage du point sur les machines qui utilisent la mémoire tampon*/
        mon_sleep( 1 ); 
    }
    printf( "Fin !\n");

    exit(EXIT_SUCCESS);
} 
    
void mon_sleep( int nbr_seconds ) {
    clock_t goal;
    goal = ( nbr_seconds * CLOCKS_PER_SEC ) + clock();
   /// printf("\nGoal = %ld \nClock = %ld \n", goal, clock());
    while( goal > clock() ) {
        ; /* loop */
    }
}
