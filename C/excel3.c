#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

char** allouer(int line,int cols){
	srand(time(NULL));
	char **tab=NULL;
	tab=(char**)malloc(sizeof(char*)*line);
	for(int i=0;i<line;i++){
		*(tab+i)=(void*)calloc(cols,sizeof(char)*cols);
	}
	return tab;
}

int main(){
	char user[10][50];
	int uid=13, i, j;
	int gid;
	char rep[20],shell[20];
	char** contenu=allouer(100,255);
	char mail[100];
	int mdp =0;
	
	FILE* file ,*file2;
	file= fopen ("/etc/passwd","r");
	file2= fopen ("file2.csv","w+");
	
	if (file == NULL){
		printf("Erreur d'ouverture du fichier\n");
		sleep(5);   exit(1);
	}
	if (file2 == NULL)	exit(1);
	
	for(i=0;feof(file)!=1;i++){
		fgets(contenu[i],255,file);	
		sscanf(contenu[i],"%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%[^:]",user[10],&uid,&gid,rep,shell);
		if (uid >= 1000 && gid >= 1000  && gid < 2000 && uid < 2000){
			if(feof(file)!=1){
				strcpy(mail,user[10]);
				strcat(mail,"@mit.mg");
				fprintf(file2,"%s\t%s\t%s",user[10],rep,shell);
				
			}
		}	
		
		
	}
/*
	for(j=0;j<=i-2;j++){
		printf("%s",contenu[j]);		
	}
*/		
	fclose(file);
	fclose (file2);
	
	file= fopen ("/etc/passwd","r");
	file2= fopen ("file2.csv","a+");
	if (file2 == NULL)	exit(1);
	
	fputs("\t  INFOS USER	\t\n",file2);
	for(i=0;feof(file)!=1;i++){
		mdp = ( rand() % (RAND_MAX - 1000 +1)) + 1000;
		if (uid >= 1000 && gid >= 1000  && gid < 2000 && uid < 2000)
			if(feof(file)!=1)	fprintf(file2,"%s\t%s@mit.mg\t%d\n",user[10],user[10],mdp);
		fgets(contenu[i],255,file);	
		sscanf(contenu[i],"%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%[^:]",user[10],&uid,&gid,rep,shell);
	}
	
	fclose(file2);
	fclose(file);

	return 0;
}
