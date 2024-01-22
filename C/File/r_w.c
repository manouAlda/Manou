#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE* file;
	
	file = fopen ("test.txt","r");
	
	if (file == NULL){
		exit(1);
	}
//	int i=0,j=0;
//	char chaine[256];
	char c;
	int s =0, car=0, l=0, tab = 0;
	while (feof(file)!=1){
		c = fgetc(file);
		printf("%c",c);
		car++;
		if(c ==' ') s++;
		if(c == '\n') l++;
		if(c =='\t') tab++;
	}
	/*
	while(feof(file)!=1){
		fgets(chaine,255,file);
		if(!feof(file)){
			printf("%s",chaine);
		}
	}
	while(feof(file)!=1){
		printf("%s",chaine);
		fgets(chaine,255,file);
	}
	for(i=0;feof(file)!=1;i++){
		chaine[i]=fgetc(file);
	}
	for (j=0;j<strlen(chaine)-1;j++){
		printf("%c",chaine[j]);
	}
	char contenu[10][255];
	for(i=0;feof(file)!=1;i++){
		fgets(contenu[i],255,file);
	}
	for(j=0;j<=i-2;j++){
		printf("%s",contenu[j]);
	}*/
	fclose (file);
	file = fopen ("test.txt","a+");
	char chaine [255];
	fgets (chaine,sizeof(chaine), stdin);
	fputs(chaine,file);
	fclose(file);
	
	printf("\nNombre de caractere: %d\nNombre d'espace: %d\nNombre de tabulation: %d\nNombre de lignes: %d\n",car,s,tab,l);
	
	
	return 0;
}
