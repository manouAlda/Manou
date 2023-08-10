#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>

int EstPoints(char* tab){
	int v=0;	
	for(int j=0;j<strlen(tab); j++)
			if(tab[j]==':' && tab[j+1]!=':')	v++;               							
	return v;
}

int main() {
	srand(time(NULL));
	int i=0,mdp;
	char line[255];
    char* mot = malloc(20);   
    char* user = malloc(20);
    char* rep = malloc(20);
    char* shell = malloc(20);
    int uid=0,j=0,k=0;
    
   FILE* file, *file2;
	file= fopen ("/etc/passwd","r");
	file2= fopen ("copie.txt","w+");
	
	if (file == NULL){
	   exit(1);
	}
	fputs("\t\t		INFOS USER		\t\t\n",file2);
	while(feof(file)!=1){
		mdp =( rand() % (RAND_MAX -1000+1) ) +1000;
		k=EstPoints(line);
		fgets(line,255,file);
			
		mot = strtok(line,":");
		/// 1er champs
		if (mot == NULL)	continue;
		user = mot;
		/// 2em champs
		mot = strtok(NULL,":");
		if (mot == NULL)	continue;
		/// 3em champs
		mot = strtok(NULL,":");
		if (mot == NULL)	continue;
		uid = atoi(mot);
		/// 4em,5em et 6em champs en boucle 
		int fin ;
		if(k==5)	fin=2;
		else if(k==6)	fin=3;
		for (j=0; j<fin;j++){
			mot = strtok(NULL,":");
			if (mot == NULL)	continue;
		}	
		rep = mot;
		/// 7em champs
		mot = strtok(NULL,":");
		if (mot == NULL)	continue;
		shell = mot;
	
		if(uid>=1000 && uid<5000){
			fprintf(file2,"%s	%s@mit.mg	%d	%s	%s\n",user,user,mdp,rep,shell);
		}
		i++;
	}
	
	fclose(file);
	fclose(file2);
	
    return 0;
}
