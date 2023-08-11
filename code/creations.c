#include "actions.c"
#include <stdio.h>
#include <stdlib.h>

//Pour faire un nouveau projet
void makeNewProject(){
	char* projectname = (char*) malloc(255*sizeof(char));
	char* makeproj = (char*) malloc(255*sizeof(char));
	
	present();
	printf("Creation de nouveau projet\n");
	printf("--------------------------\n");
	
	printf("\nEnter le nom de votre projet: ");
	scanf("%s",projectname);
	sprintf(makeproj,"mkdir -p EditProjects/%s/src/  EditProjects/%s/bin 2> EditErrorLogs.txt",projectname,projectname);
	
	system(makeproj);
	printf("Projet créé avec succès!\n");
}

//Pou lister les projets déjà créés
void listProjects(){
	char* proj = (char*) malloc(255*sizeof(char));
	char *ls = (char*) malloc(255*sizeof(char));
	int choix=0;
	
	present();
	
	printf("Projets: \n");
	printf("********\n");
	system("ls EditProjects");
	
	printf("-------------------------------\n");
	printf("====> ");
	
	scanf("%s",proj);

	present();
		
	printf("Projet: %s",proj);
	printf("\n***********************\n\n");
		
	printf("\nFichiers sources : \n############################################\n\n");
	sprintf(ls,"ls EditProjects/%s/src/",proj);
	system(ls);
		
	printf("\nFichiers  binaires : \n############################################\n\n");
	sprintf(ls,"ls EditProjects/%s/bin/",proj);
	
	printf("Options: ");
	printf("\n********");
	printf("\n\t1 - Nouveau fichier source\n\t2 - Fichier source existant\n\n");
	printf("\n===> ");
	scanf("%d",&choix);
	switch(choix){
		case 1:
			edit(proj);
			break;
		default:
			break;
	}
	
	system(ls);
	
	free(ls);
	free(proj);
}
