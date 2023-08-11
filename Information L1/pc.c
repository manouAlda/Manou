#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main(){
	pc *etudiant = malloc(sizeof(pc)*50);
	int nbr=0;
	
	FILE *file ;
	FILE* new_file;

	nbr = nombre_pc();
	file = infos_pc(nbr, etudiant, "pc.csv");
	
	new_file = trier_pc (file,"pc.csv");
	
	return 0;
}
