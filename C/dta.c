#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int* IndiceSlash(char* car);
char** alloue2DChar(int taille);
char** SeparerSlash(char* car,int* indice);
///enlever le premier tableau d' indice 1 et separer le nombre 

int charToint(char SepVir);
int CharToNb(int j,char** tab);
float  dateTotal(char** tab,char** Tb);
int main (){
	char car[]= "12/02/1";
	char date[]="6/01/1";
	int taille=0;
	int* indice=(int*)malloc(taille*sizeof(int));
	char** tab=NULL;                 //les indices du slash	
	int* ind=(int*)malloc(taille*sizeof(int));
	char** Tb=NULL;
	float nbre=0.0;
///allocation du tableau	
	tab=alloue2DChar(taille);
	
///utile pour separer le Slash	
	indice=IndiceSlash( car);
	ind=IndiceSlash(date);
	tab=SeparerSlash( car,indice);
	Tb=SeparerSlash( date,ind);
	nbre=dateTotal(tab,Tb);
	
	
	
	///affichage final

	printf("\n%f",nbre);
	return 0;
}	
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
	}	
	
	for(int j=indice[0]+1,i=0; j<indice[1];i++,j++){
			tab[1][i]=car[j];

	}
		
	for(int j=indice[1]+1 ,i=0; j<strlen(car); i++,j++){
			tab[2][i]=car[j];
		
	}		
	return tab;	
	
}				
 
int charToint(char SepVir){
	return ( SepVir-'0');
}	
int CharToNb(int j,char** tab){               ///utile pour convertir les caracteres en entiers
	int nbre=0;
	int puiss=-1;

	for(int i=strlen(tab[j])-1; i>=0; i--) {
		puiss+=1;
		
		nbre+=charToint(tab[j][i])* pow(10,puiss);
		
	}
	return nbre;
}	
float dateTotal(char** tab,char** Tb){
	float jour=0,mois=0,ans=0;
	float  jour1=0,mois1=0,ans1=0;
	float j=0,m=0,an=0;
	float nbre=0.0;
	jour=(float)CharToNb(0,tab);					
	mois=(float)(CharToNb(1,tab))*30;
	ans=(float)(CharToNb(2,tab))*365;
	
	
	
	jour1=(float)CharToNb(0,Tb);					
	mois1=(float)(CharToNb(1,Tb))*30;
	ans1=(float)(CharToNb(2,Tb))*365;
	j=jour/jour1;
	m=mois/mois1;
	an=ans/ans1;
	

	nbre=(j+m+an);
	
	
	return nbre;
}
