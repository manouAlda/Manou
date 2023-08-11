#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "student.h"

char** allouer2D(int ligne,int colonne){
	char **tab=NULL;
	tab=(char**)malloc(sizeof(char*)*ligne);
	for(int i=0;i<ligne;i++){
		*(tab+i)=(void*)calloc(colonne,sizeof(char)*colonne);
	}
	return tab;
}

int nombre_pc (){
	char* n=malloc(5);
	printf("Combien allez-vous enregistrer ? \n");
	fgets(n,5,stdin);
	int p = atoi(n);
	return p;
}

FILE* infos_pc (int nbr,pc* etudiant,char* filename){
	FILE* fichier;
	fichier = fopen(filename,"a");
	for(int i=0;i<nbr;i++){
		printf("Marque : "); scanf("%s",etudiant[i].marque);	
		printf("Etiquette : "); scanf("%s",etudiant[i].etiquette);
		printf("Mac : "); scanf("%s",etudiant[i].mac);
		printf("\n");
		fprintf(fichier,"%s\t%s\t%s\n",etudiant[i].mac,etudiant[i].etiquette,etudiant[i].marque);
	}
	fclose(fichier);
	return fichier;
}

FILE* trier_pc (FILE* file,char* filename){
	FILE* copy;
	
	int n=0;
	pc *copie = malloc(sizeof(pc)*100);
	copie = recupere_3_object(file,filename);
	n = end_file(file,filename);
	copie = compare_2_thing(copie,n);
	copy = add_3_thing_file(n,copie);
	
	return copy;
}


int end_file(FILE* file,char* filename){
	int i=0,n=0;
	char contenu[60][255];
	file = fopen(filename,"r");
	for( i=0;feof(file)!=1;i++)
		fgets(contenu[i],255,file);
	n=i;
	fclose(file);
	return n;
}
pc* recupere_3_object (FILE* file,char* filename){
	char** contenu = allouer2D(60,255);
	pc *copie = malloc(sizeof(pc)*100);
	file = fopen(filename,"r");
	
	for(int i=0;feof(file)!=1;i++){
		fgets(contenu[i],255,file);
		printf("%s",contenu[i]);
		sscanf(contenu[i],"%[^,\t]%*[,\t]%[^,\t]%*[,\t]%[^\n]",copie[i].marque,copie[i].etiquette,copie[i].mac);
	}
	
	fclose(file);
	return copie;
}

pc* compare_2_thing (pc* copie,int n){	
	for(int j=1;j<n-1;j++){
		for(int k=j+1;k<n;k++){
			if(strcmp(copie[j].etiquette,copie[k].etiquette)>0){
				pc temp = copie[k];
				copie[k] = copie[j];
				copie[j] = temp;
			}
		}
		printf(" tri : %s\n",copie[j].etiquette);
	}
	return copie;
}

FILE* add_3_thing_file (int n,pc* copie){
	FILE* cp;
	cp = fopen("pc_trier.csv","w");
	for(int j=0;j<n;j++){
		printf("\n%s\n",copie[j].etiquette);
		fprintf(cp,"%s\t%s\t%s\n",copie[j].etiquette,copie[j].mac,copie[j].marque);
	}
	fclose(cp);
	return cp;
}


int choose (){
	char* n = malloc(5);
	printf("Vous avez 2 choix actuellement\n->1- Ajouter un étudiant\n->2- Ajouter juste l'url de GitHUb\n\n Entrez ce que vous voulez faire (1/2) : ");
	fgets(n,5,stdin);
	int p = atoi(n);
	return p;
}

FILE* infos_stud (int number,student *etudiant,char* filename){
	FILE *file;
	file = fopen (filename,"a+");
	for(int i=1;i<=number;i++){
		printf("Nom : ");  fgets(etudiant[i].nom,100,stdin);
		etudiant[i].nom[strlen(etudiant[i].nom)-1] ='\0';
		
		printf("Prenom : "); 	fgets(etudiant[i].prenom,100,stdin);
		etudiant[i].prenom[strlen(etudiant[i].prenom)-1] ='\0';
		
		printf("Tel : ");	fgets(etudiant[i].tel,100,stdin);
		etudiant[i].tel[strlen(etudiant[i].tel)-1] ='\0';
		
		printf("Email : ");	fgets(etudiant[i].email,100,stdin);
		etudiant[i].email[strlen(etudiant[i].email)-1] ='\0';
		
		printf("Adresse : "); fgets(etudiant[i].adresse,100,stdin);
		etudiant[i].adresse[strlen(etudiant[i].adresse)-1] ='\0';
		
		printf("Naissance : ");	fgets(etudiant[i].naissance,100,stdin);
		etudiant[i].naissance[strlen(etudiant[i].naissance)-1] ='\0';
		
		printf("Lieu de naissance : ");	fgets(etudiant[i].lieu,100,stdin);
		etudiant[i].lieu[strlen(etudiant[i].lieu)-1] ='\0';
		
		printf("Bac : "); fgets(etudiant[i].bacc,100,stdin);
		etudiant[i].bacc[strlen(etudiant[i].bacc)-1] ='\0';
		
		printf("Genre : "); fgets(etudiant[i].genre,100,stdin);
		etudiant[i].genre[strlen(etudiant[i].genre)-1] ='\0';
		
		printf("CIN : "); fgets(etudiant[i].cin,100,stdin);
		etudiant[i].cin[strlen(etudiant[i].cin)-1] ='\0';
		
		printf("URL gitHUb : "); fgets(etudiant[i].url,100,stdin);
		etudiant[i].url[strlen(etudiant[i].url)-1] ='\0';
		printf("\n");
		fprintf(file,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",etudiant[i].nom,etudiant[i].prenom,etudiant[i].tel,etudiant[i].email,etudiant[i].adresse,etudiant[i].naissance,etudiant[i].lieu,etudiant[i].bacc,etudiant[i].genre,etudiant[i].cin,etudiant[i].url);
	}
	fclose(file);
	return file;
}
char** in_tab (FILE* file,char* filename,int n){
	int i=0;
	char **contenu = allouer2D(100,255);
	file = fopen(filename,"r");
	for( i=0;feof(file)!=1;i++)
		fgets(contenu[i],255,file);
	fclose(file);
	return contenu;
}
char** compare_tab (char** tab,int n){
	char* tmp =malloc(255);
	for(int j=1;j<n-1;j++){
		for(int k=j+1;k<n;k++){
			if(strcmp(tab[j],tab[k])>0){
				strcpy(tmp,tab[j]);
				strcpy(tab[j],tab[k]);
				strcpy(tab[k],tmp);
			}
		}
		printf(" tri : %s\n",tab[j]);
	}
	return tab;
}

FILE* sort (FILE*file,char* filename){
	int nbr = end_file(file,filename);
	char **contenu = allouer2D(100,255);
	contenu = in_tab (file,filename,nbr);
	contenu = compare_tab(contenu,nbr);
	FILE* copie;
	copie = fopen("etudiant_trier.csv","w");
	for(int i=0;i<nbr;i++){
		fprintf(copie,"%s",contenu[i]);
	}
	
	return copie;
}
FILE* add_url(FILE* file, char* filename) {
    char* anarana = malloc(100);
    int final = end_file(file, filename);
   char** contents = allouer2D(100, 255);
    char* url = malloc(100);
    student *tmp = malloc(sizeof(student)*60);
    int nbr = 0;
    int check = nombre_pc();

    FILE* fic;
	
	while(nbr<check){
		printf("\nQuel est le nom (sans prenom) : ");
		fgets(anarana, 100, stdin);
		anarana[strlen(anarana) - 1] = '\0';
		
		for (int i = 0; anarana[i]!='\0' ; i++) {
			anarana[i] = toupper(anarana[i]);
		}
		
		printf("\n%s\nEntrez l'URL gitHub : ",anarana);
		fgets(url, 100, stdin);
		url[strlen(url) - 1] = '\0';
	  
	   contents = in_tab(file, filename, final);
		
		fic = fopen(filename, "w+");
		
		for (int i = 0; i < final; i++) {
			
			if(strlen(contents[i])>0 && contents[i][strlen(contents[i])-1]=='\n')	contents[i][strlen(contents[i])-1]='\0';
			
			sscanf(contents[i],"%[^,\t]%*[,\t]%[^,\t]%*[,\t]%[^,\t]%*[,\t]%[^,\t]%*[,\t]%[^,\t]%*[,\t]%[^,\t]%*[,\t]%[^,\t]%*[,\t]%[^,\t]%*[,\t]%[^,\t]%*[,\t]%[^,\t]%*[,\t]%[^,\n]",tmp[i].nom,tmp[i].prenom,tmp[i].tel,tmp[i].email,tmp[i].adresse,tmp[i].naissance,tmp[i].lieu,tmp[i].bacc,tmp[i].genre,tmp[i].cin,tmp[i].url);
			
			if (strcmp(tmp[i].nom, anarana) == 0) {
				strcat(contents[i],url);
			}
		  
			fprintf(fic,"%s\n",contents[i]);
		}
	 
		fclose(fic);
		nbr++; 
	}
	return fic;
}

