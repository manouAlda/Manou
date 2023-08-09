#include <stdio.h>
#include <stdlib.h>

int main (){
	printf(" \e[35mYour old\n\e[m");
	int annee=0;
	printf("Quelle année êtes-vous née?\n");
	scanf("%d",&annee);
	system("date > date.txt");
	FILE* file = fopen ("date.txt","r");
	if(file==NULL) exit(1);
	fseek (file,0,SEEK_END);
	long taille = ftell (file);     /// recuperer la position actuelle dans le fichier ou sa taille proprement dite
	rewind(file);					/// remet le curseur au debut du fichier
	char* date = malloc (taille+1);    /// +1 por le \0
	fread (date,1,taille,file);    printf("\n%s\n",date);
	date[taille-1]='\0';
	int ans=0;
	sscanf(date,"%*s %*d %*s %d %*d:%*d:%*d %*s",&ans); 
	int age =0;
	age = ans - annee;
	printf("-> Vous avez %d ans .\n",age);
	
	fclose(file);
	free(date);
	return 0;
}	
