#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


/*
int compterSlash(char* car){
	int taille = 0;
	for(int i=0; i<strlen(car); i++){
		if(car[i] == '/'){	
			taille++;
		}	
			
	}
	return taille;
}
*/
int* IndiceSlash(char* car){
	int* indice=malloc(2*sizeof(int));
	int j=0;
	for(int i=0; i<strlen(car); i++){
		if(car[i] == '/'){	
			indice[j]=i;
			j++;
		}	
	}
	
	return indice;
}					
char** alloue2DChar(int taille){
	char** tab;
	tab=(char**)malloc((taille+1)*sizeof(char*));
	for(int i=0;i<(taille+1); i++){
		tab[i]=malloc(10);
	}
	return tab;
}		 	
char** SeparerSlash(char* car,int* indice){
	char** tab=NULL;
	tab=alloue2DChar(2);
	for(int i=0; i<indice[0];i++){
			tab[0][i]=car[i];
			///printf("%c",tab[0][i]);
	}	
	
	for(int j=indice[0]+1,i=0; j<indice[1];i++,j++){
			tab[1][i]=car[j];
			///printf("%c",tab[1][i]);
	}
		
	for(int j=indice[1]+1 ,i=0; j<strlen(car); i++,j++){
			tab[2][i]=car[j];
			///printf("%c",tab[2][i]);
	}		
	return tab;	
	
}				
int Etvirgule(char** tab){
	int v=0;	
	for(int j=0;j<strlen(tab[0]); j++){
			if(tab[0][j]=='.'){
				v=j;               	
			}
	}				
	return v;
}
char** SepareVirgule(int v,char** tab){
	char** SepVir=NULL;
	int dim=strlen(tab[0]);
	SepVir= alloue2DChar(2);
	for(int i=0;i<v; i++){
		SepVir[0][i]=tab[0][i];
	}
	
	for(int j=v+1,i=0; j<dim; i++,j++){
		SepVir[1][i]=tab[0][j];      ///eto le 0.3 avadika heure,minute,seconde
	}	
	
				

	return SepVir;
} 
int charToint(char SepVir){
	return ( SepVir-'0');
}	
float Double(int v,char** SepVir){
	float nbreFlot=0.0;
	int x=0;
	int puiss=-1;
	for(int j=strlen(SepVir[1])-1,i=0; j>=0; i++,j--){
		puiss++;
		x+=(charToint(SepVir[1][j])*pow(10,puiss)); 
	}	
	nbreFlot=(float)(x* pow(10,-v));	
	return nbreFlot;
}	
float ENseconde(float nbre){
	return (nbre*24*60*60);
}
char* convertirDate(float nbre){
	float sec=0;
	int heure=0,minute=0,seconde=0;
    char* date=malloc(20);
  
	sec=ENseconde( nbre);
	heure=(int)sec/3600;
	sec=(int)sec%3600;
	minute=((int)sec%3600)/60;
	sec=((int)sec%3600)/3600;
	seconde=sec;

	sprintf(date,"%02d:%02d:%02d",heure,minute,seconde);  ///misy tiret ao aorian seconde
	return date;
}	
char* affichageFormatDate(int* indice,char* car,char** tab){
	char *date=malloc(100);
	char **a=SeparerSlash(car,indice);   
	int b[3];
	
	for(int i=0; i<3; i++){
		b[i] = atoi(a[i]);		
	}
	sprintf(date,"%d/%d/%d\n",b[0],b[1],b[2]);
	return date;
}	                       
