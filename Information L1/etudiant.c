#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "student.h"

int main(){
	student *etudiant = malloc(sizeof(student)*46);
	int choix = 0;
	char* filename = malloc(15);
	strcpy(filename,"etudiant.csv");
	
	choix = choose ();
	
	FILE* file=NULL;
	if (choix == 1){	

		file = fopen (filename,"a+");
		//fputs("Nom\tPrenom\tTel\tEmail\tAdresse\tDate de naissance\tLieu de naissance\tBacc\tGenre\tCIN\tUrl gitHub",file);
		fclose(file);
	
		int final = nombre_pc();
		file = infos_stud (final,etudiant,filename);
		
		file = sort (file,filename);
	}
	else if(choix == 2){
		file = add_url(file,filename);
		file = sort (file,filename);
	}
	
	return 0;
}
