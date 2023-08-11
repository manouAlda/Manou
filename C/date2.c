#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char** alloue2DChar(int taille);
int IndiceEspace(char* heure);
char** alloue2DChar(int taille);
char** SeparerEspace(char* heure);
int* position_Slash(int j,char** espace);
char** separationSlash(int j,char** espace);
int Ascii(char slash);
int CharToInt(int j,char** slash);
float Conversion_en_jour(int j, char** espace);
char* changementDuFormat(float jour,char** espace);
char* fonctionInverse(char* heure);
int main (){
	char heure[30]="5/12/2015 7:12:00";
	char* final=malloc(10);
	
	final=fonctionInverse( heure);
	printf("\nLe nouveau format est %s ",final);
	return 0;
}

char* fonctionInverse(char* heure){
	char* final=calloc(1,20);
	char** espace=NULL;
	int* position=NULL;
	char** slash=NULL;
	int ligne=0;
	float jours=0.0;
	///allocation du tableau
	espace=alloue2DChar(3);
	position=(int*)malloc(2*sizeof(int));
	slash=alloue2DChar(4);

	///afficher la separation du slash
	espace=SeparerEspace( heure);
	
	///position Slash
	position=position_Slash(ligne,espace);
	
	
	///separation Slash
	slash=separationSlash(ligne,espace);
		///charTO INt
	CharToInt(ligne,slash);

	///conversion du format heures en nombre de jours
	jours=Conversion_en_jour(ligne,espace);
	
	 ///etape finale
	
	final=changementDuFormat(jours, espace);
	return final;

	
}	
int IndiceEspace(char* heure){
	int espace=0;
	
	for(int i=0; i<strlen(heure); i++){
		if(heure[i] ==' ')	
			espace=i;
	}
	
	return espace;
}					
char** SeparerEspace(char* heure){    ///utile pour separer les slashs et les deux points
	char** tab=alloue2DChar(3);
	int espace=0;
		espace=IndiceEspace(heure);
	for(int i=0; i<espace;i++){
			tab[0][i]=heure[i];
			
	}
	
	for(int j=espace+1,i=0; j<strlen(heure);i++,j++){
			tab[1][i]=heure[j];
	
	}
		return tab;
}	
	
char** alloue2DChar(int taille){
	char** tab;
	tab=(char**)malloc((taille)*sizeof(char*));
	for(int i=0;i<(taille+1); i++){
		tab[i]=malloc(10);
	}
	return tab;
}		 	

int* position_Slash(int j, char** espace){
	int* indic=(int*)malloc(2*sizeof(int));
	int k=0;

		for(int colonne=0 ;colonne<strlen(espace[0]) ;colonne++){         
			if(espace[j][colonne]== '/' || espace[j][colonne]==':'){
				indic[k]=colonne;
				k++;
			}	
		}
		
		
	return indic;
}		
char** separationSlash(int j,char** espace){
	char** SLash=NULL;
	int* indic=(int*)malloc(3*sizeof(int));
	SLash=alloue2DChar(4);
	indic=position_Slash(j,espace);
	
			for(int col=0 ;col< indic[0];col++)
				SLash[0][col]=espace[j][col];
			for(int col=indic[0]+1,l=0 ; col<indic[1] ; l++,col++)
				 SLash[1][l]=espace[j][col];
			for(int l=0,col=indic[1]+1 ; col<strlen(espace[0]);l++, col++ )
				SLash[2][l]=espace[j][col];
	
	return SLash;
}		 
int Ascii(char slash){
	
	return (slash-'0');
	
}	
int CharToInt(int j ,char** slash){               ///utile pour convertir les caracteres en entiers
	int nbre=0;
	int puiss=-1;
	for(int i=strlen(slash[j])-1; i>=0; i--) {
		puiss+=1;
		
		nbre+=Ascii(slash[j][i])* pow(10,puiss);
		
	}
	return nbre;
}		
///valeurs dans l' espace[0] en entiers simple et les valeurs dans l' espace[1] faut convertir en jours donc en nombre en flottante
float Conversion_en_jour(int j, char** espace){
	char** heure=NULL;
	heure=alloue2DChar(3);
	float jour=0.0;
	int h=0,min=0,seconde=0;
	float conj=24,com=24*60,cos=24*60*60;
	heure=separationSlash(1,espace);
	
	h=CharToInt(0,heure);
	min=CharToInt(1,heure);
	seconde=CharToInt(2,heure);
	jour=(h/conj)+(min/com)+(seconde/cos);
	
	return jour;
		
}
char* changementDuFormat(float jours,char** espace){
	char* format=NULL;
	char** date=NULL;
	int jrs=0;
	float lejou=0.0;
	format=malloc(10);
	
	date=alloue2DChar(3);
	date=separationSlash(0,espace); 
	jrs=CharToInt(0,date);
	lejou=jours+(float)jrs;
	sprintf(format,"%.1f/%s/%s",lejou,date[1],date[2]);
	
	return format;
}	
//efa mety
